/***************************************************************************
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU Lesser General Public License as        *
*   published by the Free Software Foundation; either version 2 of the    *
*   License, or (at your option) any later version.                       *
*                                                                         *
***************************************************************************/
/**
@file 
MapUtil.cpp
@brief
Utility that split big map in tiles, pre-calculate splatting by
pre-calculating coverage map and pre-calculate normals.
*/

#include "MapUtil.h"

#ifndef _MAPEDITOR

#include "OgrePagingLandScapeData2D.h"
#include "OgrePagingLandScapeData2DManager.h"
#include "OgrePagingLandScapeData2D_HeightField.h"
#include "OgrePagingLandScapeData2D_HeightFieldTC.h"
#include "OgrePagingLandScapeData2D_HeightFieldRaw.h" 
#include "OgrePagingLandScapeData2D_HeightFieldRawTC.h"
#include "OgrePagingLandScapeData2D_Spline.h"

#endif //_MAPEDITOR

#include <iostream>
#include <fstream>
#include <vector>

#include "fileutils.h"

#include "OgreCommon.h"

#include "OgreVector3.h"
#ifndef PLSM2_EIHORT
#include "OgreILImageCodec.h"
#include "OgreILCodecs.h"
#endif

#include "OgreDynLibManager.h"
#include "OgreDynLib.h"
#include "OgreZip.h"

#include "MapNormaler.h"
#include "MapSplatter.h"

#include "MapLighter.h"
#include "MapHorizon3.h"

#include "MapBlender.h"
#include "MapBlurrer.h"
#include "MapSplitter.h"
#include "MapInfinitizer.h"
#include "MapEqualizer.h"
#include "MapMergeModulater.h"

namespace Ogre
{
    
    static inline uint computePageSize(const uint w, const uint h,  
                                       const uint x, const uint z)
   {
        size_t pageh = h / z;
        size_t pagew = w / x;
        int pageSize = (int) ((pagew < pageh)? pagew : pageh);
        int i = 0;
        while ( i < 65536 )
        {
            if ( pageSize < ( 1 << i ))
            {
                break;
            }
            i++;
        }
        return ( 1 << (i - 1));
   }
    static inline int nearestpowerof2 (int size)
    {
        int i = 0;
        while ( i < 65536 )
        {
            if ( size < ( 1 << i ))
            {
                break;
            }
            i++;
        }
        return  ( 1 << i);
    }

    static inline uint umin (const uint a, const uint b)
    {return a < b? a: b;}

	static Real *stretchandExtendHeightmap (
							const Real *  const ogre_restrict HeightMap, 
							const Real *  const ogre_restrict BumpMap,
                            const Real stretchFactor,
                            const uint W, const uint H,
                            const uint pageSize,
                            const uint pagex, const uint pagez,
                            Real &maxH, 
                            Real scaley)
    {

        const uint Size = W * H;
        const uint w = W * stretchFactor - stretchFactor + 1;
        const uint h = H * stretchFactor - stretchFactor + 1;

        //const uint p = pageSize * stretchFactor;
        //const uint p2w = p * pagex + 1; //(unsigned int)nearestpowerof2 ((int)h) + 1; 
        //const uint p2h = p * pagez + 1; //(unsigned int)nearestpowerof2 ((int)h) + 1; 


        const double inv_stretchFactor = 1.0 / stretchFactor;
        const uint size = w * h;
        Real * ogre_restrict stretched = new Real [size];

        uint zWidth = 0;
        for (uint z = 0; z < h; z++)
        {
	        const Real Z = z * inv_stretchFactor;
	        const uint Z0 = umin (Z, H - 1);
	        const uint Z1 = umin (Z0 + 1, H - 1);
            const uint Z0Width = Z0*W;
            const uint Z1Width = Z1*W;
            assert (Z0Width < Size && Z1Width < Size);
            // distance to real point in (0,1) range
            const Real distz = Z - Z0;
            assert (distz >= 0.0f && distz <= 1.0f);


            for (uint x = 0; x < w; x++)
            {
                const Real X = x * inv_stretchFactor;
	            const uint X0 = umin (X, W - 1);
	            const uint X1 = umin (X0 + 1, W - 1);

                assert (X0 < W && X1 < W);
                assert (X0 + Z0Width < Size && X1 + Z0Width < Size &&
                        X0 + Z1Width < Size && X1 + Z1Width < Size);

                // distance to real point in (0,1) range
                const Real distx = X - X0;
                assert (distx >= 0.0f && distx <= 1.0f);

	            // read 4 map values
	            const Real h0 = HeightMap[X0 + Z0Width];
	            const Real h1 = HeightMap[X1 + Z0Width];
	            const Real h2 = HeightMap[X0 + Z1Width];
	            const Real h3 = HeightMap[X1 + Z1Width];

	            const double avgLo = (h1*distx) + (h0*(1.0f-distx));
	            const double avgHi = (h3*distx) + (h2*(1.0f-distx));

                 // interpolate and store.
                const Real newH = (avgHi*distz) + (avgLo*(1.0f-distz));
                assert (newH <= scaley);
                const uint curr_vertex = x + zWidth;
                assert (curr_vertex < size);
				stretched[curr_vertex] = std::max ( static_cast <Real> (0.0f), 
					std::min (scaley, newH + BumpMap[curr_vertex]*0.1f*newH));        
                maxH = std::max (stretched[curr_vertex], maxH);
            }
            zWidth  += w;
        }
        return stretched;
    }
   
    template<> MapUtil* Singleton<MapUtil>::ms_Singleton = 0;
    //-----------------------------------------------------------------------
    MapUtil* MapUtil::getSingletonPtr(void)
    {
        return ms_Singleton;
    }
    //-----------------------------------------------------------------------
    MapUtil& MapUtil::getSingleton(void)
    {  
        assert( ms_Singleton );  return ( *ms_Singleton );  
    }
    //-----------------------------------------------------------------------
    MapUtil::MapUtil() :
        mGenHeightMap (true),  
        mGenMiniMap (true),
        mGenCoverageMap (true),
        mGenBaseMap (true),
        mGenAlphaMaps (true),
        mGenLightMap (true),
     
        mGenColorMapGenerate (false),
        mGenColorMapSplit (false),
        mGenElevationMap (false),                               
        mGenNormalMap (false),
        mGenEqualize (false),
        mGenInfiniteMap (false),
        mGenHeightNormalMap (false),
        mGenShadowMap (false),
        mGenLitColorMapGenerate (false),
        mGenLitColorMapSplit (false),
        mGenLitBaseMap (false),
        mGenZHorizon (false),
        mHeightMapBlurFactor(0.0f),
        mGenMiniMapWidth(256),
        mGenMiniMapHeight(256),
        mColorMapName (StringUtil::BLANK),
        scale(Vector3::UNIT_SCALE),
        mGroupName ("PLSM2"),
        mPaged (true),
        mOutDirectory (StringUtil::BLANK),
        mTextureStretchFactor (2.0f),
        mBpp(2),
        mData (0),
        mExt(""),
        mTextureExt(""),
        mRoot(0)
#ifndef _MAPEDITOR
        , mData2dManager(0)
#endif //_MAPEDITOR
    {    
		mSplitter		= new MapSplitter ();
		mMergeModulater = new MapMergeModulater();
		mLightMapper	= new MapLighter();
		mSplatMapper	= new MapSplatter();
	}

    //-----------------------------------------------------------------------
    void MapUtil::init()
    {
#ifndef _MAPEDITOR     
        if (mRoot == 0)
        {

			mRoot = new Root("plugins.cfg", "ogre.cfg", "MapSplitter.log");

// Linux plugin is created as Plugin_PagingLandScape2.so and set up to run
// via the plugins.cfg config file
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32     
#ifdef _DEBUG
			Root::getSingleton().loadPlugin("Plugin_PagingLandScapeSceneManager2_d");
#else
			Root::getSingleton().loadPlugin("Plugin_PagingLandScapeSceneManager2");
#endif
#endif

            // Load resource paths from config file      
            ConfigFile cf;
            cf.load("resources.cfg");
            // Go through all sections & settings in the file
            ConfigFile::SectionIterator seci = cf.getSectionIterator();

            const String testedType("Filesystem");

            while (seci.hasMoreElements())
            {
                const String &secName = seci.peekNextKey();
                ConfigFile::SettingsMultiMap *settings = seci.getNext();
                ConfigFile::SettingsMultiMap::iterator i;
                for (i = settings->begin(); i != settings->end(); ++i)
                {
                    const String &typeName = i->first;
                    const String &archName = i->second;

                    if (typeName == testedType)
                    {
                        if (DirExists(archName.c_str ()))
                            ResourceGroupManager::getSingleton().addResourceLocation(
                            archName, typeName, secName);
                    }
                    else
                    {
                        ResourceGroupManager::getSingleton().addResourceLocation(
                            archName, typeName, secName);
                    }
                }
            }


            ResourceGroupManager *rsm = ResourceGroupManager::getSingletonPtr();
            StringVector groups = rsm->getResourceGroups();        
            if (std::find(groups.begin(), groups.end(), String("PLSM2")) == groups.end())
			{
				FileInfoListPtr finfo =  ResourceGroupManager::getSingleton().findResourceFileInfo (
					"Bootstrap", "axes.mesh");
				const bool isSDK =  (!finfo->empty()) && 
					StringUtil::startsWith (finfo->begin()->archive->getName(), "../../media/packs/ogrecore.zip", true);



				rsm->createResourceGroup("PLSM2");
				if (isSDK)
				{
					rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2","FileSystem", "PLSM2");

					rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/models","FileSystem", "PLSM2");
					rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/overlays","FileSystem", "PLSM2");
					rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/materials","FileSystem", "PLSM2");

					rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/materials/scripts","FileSystem", "PLSM2");
					rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/materials/textures","FileSystem", "PLSM2");
					rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/materials/programs","FileSystem", "PLSM2");

					rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/datasrcs","FileSystem", "PLSM2");
					rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/terrains","FileSystem", "PLSM2");
				}
				else
				{
					rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2","FileSystem", "PLSM2");

					rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/models","FileSystem", "PLSM2");
					rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/overlays","FileSystem", "PLSM2");
					rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/materials","FileSystem", "PLSM2");

					rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/materials/scripts","FileSystem", "PLSM2");
					rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/materials/textures","FileSystem", "PLSM2");
					rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/materials/programs","FileSystem", "PLSM2");

					rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/datasrcs","FileSystem", "PLSM2");
					rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/terrains","FileSystem", "PLSM2");
				}
            }
        }
#endif //_MAPEDITOR
    }
    //-----------------------------------------------------------------------
    void MapUtil::Load()
    {
#ifndef _MAPEDITOR    
        init();
        mOptions = new PagingLandScapeOptions(0);
        mOptions->cfgGroupName = String("PLSM2");
        mOptions->load(String("maptool.cfg"));
#endif //_MAPEDITOR
    }
    //-----------------------------------------------------------------------
    void MapUtil::LoadSingleMap(const String &cfgFile, const String &cfgGroupName)
    {
#ifndef _MAPEDITOR    
        init();
        if (mOptions == 0)
            mOptions = new PagingLandScapeOptions(0);
        mOptions->cfgGroupName = cfgGroupName;
        mOptions->load(cfgFile);
#endif //_MAPEDITOR
    }
    //-----------------------------------------------------------------------
    MapUtil::~MapUtil()
    {          
#ifndef _MAPEDITOR
        delete mData2dManager;
        delete mOptions;
        delete mRoot;
#endif //_MAPEDITOR

		delete mSplitter;
		delete mMergeModulater;
		delete mLightMapper;
		delete mSplatMapper;
    }
    //-----------------------------------------------------------------------
    const Real MapUtil::getMaxTheoHeight () const 
    {
        return maxHeight;

    } 
    //-----------------------------------------------------------------------
    Real *MapUtil::getHeightData ()
    {
        return mData;
    }
    //-----------------------------------------------------------------------
    const Real MapUtil::getHeight (const Real x, const Real z) const 
    {
        assert( mData );
        assert( z < mHeight&& x < mWidth );
        const uint Pos = z * mHeight + x;
        return mData[ Pos ];  
    }

    //-----------------------------------------------------------------------
    void MapUtil::load(const String &filename, Image *ImageMap)
    {
        ImageMap->load (filename, mGroupName);
    }
    //-----------------------------------------------------------------------
    const Vector3 MapUtil::getNormalAt(const Real x, const Real z)  
    {  
        return NormalMapper.getNormalAt (uint (x), uint (z));
    }
    //-----------------------------------------------------------------------
    Vector3 *MapUtil::getNormalData()
    {  
        return NormalMapper.getNormalData ();
    }
    //-----------------------------------------------------------------------
    void MapUtil::process()
    {  
#ifndef _MAPEDITOR
        if (mOptions->mBatchMode)
        {
            LandScapeFileNames *_map = mOptions->getLandScapeFileNames();
            LandScapeFileNames::iterator i = _map->begin();
	        LandScapeFileNames::iterator i_end = _map->end();
	        for(;i != i_end; ++i)
	        {	
				mOptions->setDefault();
                mOptions->loadMap(i->second + ".cfg");  
                processOneMap ();
            }
        }
        else
		{            
            processOneMap ();
        }
#endif// _MAPEDITOR
    }
    //-----------------------------------------------------------------------
    void MapUtil::LoadOptions()
    {
#ifndef _MAPEDITOR
        mFileName = mOptions->LandScape_filename + 
                    "." +
                    mOptions->LandScape_extension;

        // set codec using file extension
        mPureFilename = mOptions->LandScape_export_filename;
        mExt = mOptions->LandScape_export_extension;
        mTextureExt = mOptions->TextureExtension;


        mPageSize = mOptions->PageSize - 1;
 

        mSun = mOptions->Sun;
        mAmb = mOptions->Amb;
        mDiff = mOptions->Diff;
        mBlur = mOptions->Blur;
        mHeightMapBlurFactor = mOptions->HeightMapBlurFactor;

        mGenHeightMap =             mOptions->HeightMap;  
        mGenMiniMap =               mOptions->MiniMap;
        mGenCoverageMap =           mOptions->CoverageMap;
        mGenBaseMap =               mOptions->BaseMap;
        mGenAlphaMaps =             mOptions->AlphaMaps;
        mGenLightMap =              mOptions->LightMap;
                                 
        mGenColorMapGenerate =      mOptions->ColorMapGenerate;
        mGenColorMapSplit =         mOptions->ColorMapSplit;                        
        mGenNormalMap  =            mOptions->NormalMap;
        mGenEqualize =              mOptions->Equalize;
        mGenInfiniteMap =           mOptions->InfiniteMap;
        mGenHeightNormalMap =       mOptions->HeightNormalMap;
        mGenLitColorMapGenerate =   mOptions->LitColorMapGenerate;
        mGenLitColorMapSplit =      mOptions->LitColorMapSplit;
        mGenLitBaseMap =            mOptions->LitBaseMap;
        mGenZHorizon =              mOptions->ZHorizon;

        
        mGenMiniMapWidth  =         mOptions->MiniMapWidth;
        mGenMiniMapHeight  =        mOptions->MiniMapHeight;

        mColorMapName = mOptions->ColorMapName;
        mColorMapNameExtension = mOptions->TextureExtension;
        mColorMapNameExportExtension = mOptions->TextureExportExtension;

        scale  = mOptions->scale;
        mGroupName  = mOptions->groupName;


        uint i;
		NumMatHeightSplat = mOptions->NumMatHeightSplat;
		SplatDetailMapNames.reserve (NumMatHeightSplat);
		SplatDetailMapNames.resize (NumMatHeightSplat);		
        for (i = 0; i < NumMatHeightSplat; i ++)
        {
            SplatDetailMapNames[i] = mOptions->SplatDetailMapNames[i];
        }           
		matColor.reserve (NumMatHeightSplat);
		matColor.resize (NumMatHeightSplat);	
        for (i = 0; i < NumMatHeightSplat; i ++)
        {
            matColor[i] = mOptions->matColor[i];
        }     
		matHeight.reserve (NumMatHeightSplat);
		matHeight.resize (NumMatHeightSplat);	
        for (i = 0; i < NumMatHeightSplat; i ++)
        {
            matHeight[i] = mOptions->matHeight[i];
        }
        mTextureStretchFactor = mOptions->TextureStretchFactor;
        mPaged = mOptions->Paged;	
        mOutDirectory  = mOptions->OutDirectory;


		mNumSplatMapToSplit = mOptions->NumSplatMapToSplit;	
		mSplatMapNames = &mOptions->SplatMapNames;	

#endif // _MAPEDITOR
    }
    //-----------------------------------------------------------------------
    void MapUtil::setMap (const String &mapName, 
        const String &extension, 
        const String &texture_extension, 
        const uint pageSize,
        const String &OutDirectory,
        const String &groupname,
        const Real textureFactor)
    {
       mFileName = mapName + 
                    "." +
                    extension;   
       mPureFilename = mapName;
       mExt = extension;
       mTextureExt = texture_extension;
       mPageSize = pageSize - 1;
       mOutDirectory = OutDirectory;
       mGroupName = groupname;
       mTextureStretchFactor = textureFactor;
    }
    //-----------------------------------------------------------------------
    void MapUtil::setMapColoring (const ColourValue *colors, 
                                   const Real *heights,
                                   const uint numColors)
	{
		uint i;

		matColor.reserve(numColors);
		matColor.resize(numColors);
        for (i = 0; i < numColors; i ++)
        {
            matColor[i] = colors[i];
		}   

		matHeight.reserve(numColors);
		matHeight.resize(numColors); 
        for (i = 0; i < numColors; i ++)
        {
            matHeight[i] = heights[i];
        }
		NumMatHeightSplat = numColors;
    }
    //-----------------------------------------------------------------------
    void MapUtil::LoadDataFromMemory(uint mapWidth, 
        uint mapHeight, 
        Real *heightData,
        Real max)
    {  
        maxHeight = max;// get theoretic max height (before loading)
        mHeight = mapHeight;
        mWidth = mapWidth;
        mMax = max;
        mData = heightData;
    }
    //-----------------------------------------------------------------------
    void MapUtil::LoadDataFromSource()
    {
#ifndef _MAPEDITOR
        mData2dManager = new PagingLandScapeData2DManager(0, mOptions);
        // 
        // Load Heightmap data according to specialized loader 
        // 
        if (StringUtil::endsWith (mOptions->data2DFormat, "heightfield", true))
        {
            mHeightdata	= new PagingLandScapeData2D_HeightField (mData2dManager);
        } 
        else if (StringUtil::endsWith (mOptions->data2DFormat, "heightfieldraw", true))
        {
            mHeightdata	= new PagingLandScapeData2D_HeightFieldRaw (mData2dManager);
        }
        else if (StringUtil::endsWith (mOptions->data2DFormat, "heightfieldtc", true))
        {
            mHeightdata	= new PagingLandScapeData2D_HeightFieldTC (mData2dManager);
        }
        else if (StringUtil::endsWith (mOptions->data2DFormat, "heightfieldrawtc", true))
        {
            mHeightdata	= new PagingLandScapeData2D_HeightFieldRawTC (mData2dManager);
        }
        else if (StringUtil::endsWith (mOptions->data2DFormat, "splinefield", true))
        {
            // needs to store spline value ???
            // why spline values can't come from image instead of Rand ?
            //mHeightdata = new PagingLandScapeData2D_Spline();
            OGRE_EXCEPT( Exception::ERR_INVALIDPARAMS,
                "SplineField not supported!", 
                "MapUtil::MapUtil" );
        }
        else 
        {
            OGRE_EXCEPT( Exception::ERR_INVALIDPARAMS,
                "PageData2D not supplied!", 
                "MapUtil::MapUtil" );
        }

        maxHeight = mHeightdata->getMaxHeight ();// get theoretic max height (before loading)

        mHeightdata->load ();
        mHeight = static_cast <uint> (mHeightdata->getZDimension ());
        mWidth = static_cast <uint> (mHeightdata->getXDimension ());
        mMax = mHeightdata->getMaxHeight ();
        mData = mHeightdata->getHeightData ();

#endif // _MAPEDITOR
    }
    
	//-----------------------------------------------------------------------
	bool MapUtil::initOneMap()
	{   
		LoadOptions ();

#ifndef _MAPEDITOR

		if (!ResourceGroupManager::getSingletonPtr() || 
			!ResourceGroupManager::getSingletonPtr()->resourceExists(mGroupName, mFileName))
		{
			LOGTHIS("ERROR: cannot Find" + mFileName + " in resource goup " + mGroupName + "splitting aborted for this map");
			return false;
		}

		LoadDataFromSource();
#endif // _MAPEDITOR

		mPageX = mWidth / mPageSize;
		mPageZ = mHeight / mPageSize;  
		mPageSize = computePageSize (mWidth, mHeight, mPageX, mPageZ);
		mSplitter->init (mPaged, mPageSize, mBpp, mOutDirectory);

#ifndef _MAPEDITOR

		mSplatMapper->reset();
		mLightMapper->reset ();

		// do user texture split here to avoid 
		// some heavy memory concurrent use
		if (mGenColorMapSplit || mNumSplatMapToSplit > 0)
		{
			mHeightdata->unload ();
		}
#endif // _MAPEDITOR
		return true;
	}
	//-----------------------------------------------------------------------
	void MapUtil::unInitOneMap()
	{   
#ifndef _MAPEDITOR
		mHeightdata->unload();
		delete mHeightdata;
#endif // _MAPEDITOR
	}
	//-----------------------------------------------------------------------
    void MapUtil::processOneMap()
	{   
		if (false == initOneMap())
			return;
		// 
		// If user want to use its Own Color  or Coverage Maps
		//
		if (mGenColorMapSplit && !mColorMapName.empty ())
			splitUserColorMap();

		// 
		// If user want to use its Own Alpha Maps
		//
		if (mNumSplatMapToSplit > 0)
			splitUserAlphaMap();
		

#ifndef _MAPEDITOR
		if (mGenColorMapSplit || mNumSplatMapToSplit > 0)
		{
            mHeightdata->load ();
            mHeight = static_cast <uint> (mHeightdata->getZDimension ());
            mWidth = static_cast <uint> (mHeightdata->getXDimension ());
            mMax = mHeightdata->getMaxHeight ();
            mData = mHeightdata->getHeightData ();
		}
#endif // _MAPEDITOR


		// 
		// Some cosmetic map changes  
		// 
        if (mGenEqualize)
        { 
            ErodeFault e;
            e.normalize (mData, mWidth, mHeight, 1.0);
        }

        if (mGenInfiniteMap)
        { 
            MapInfinitizer Infinitizer;
            Infinitizer.Infinitize (static_cast <uint> (mHeight / 10), 
                                    0.0f, 
                                    0);
                    
        }

        const Real Blur = mHeightMapBlurFactor;
        if (Blur > 0.0f)
        {
            Convolver *c = new Convolver (int (Blur));
            c->blurReal (mData, mWidth, mHeight);
        }

		// 
		// Split Heightmap in 2^n + 1 part  
		// 
		if (mGenHeightMap)
			splitHeightMap();
       
		// make sure we're not saving in raw format all following maps.
        mSplitter->setRawSave (StringUtil::match(mTextureExt, "raw", false));

		// 
		// a small version of the whole map.  
		// 
        if (mGenMiniMap)
			generateMiniMap();
        // 
        // Split Normal Map in 2^n  part  
        // 
        if (mGenNormalMap)
           generateAndSplitNormalMap();

        // 
        // Split Normal Map + HeightMap in alpha channel in 2^n + 1 part  
        // 
        if (mGenHeightNormalMap)
			generateAndSplitHeightNormalMap();

        //Now make height map goes to final texture size
        if (mTextureStretchFactor != 1.0f)
			stretchHeightMap ();

        // 
        // If we does calculate Light or slope We need Normals.
        // 
        if (mGenCoverageMap ||
            mGenBaseMap || 
            mGenAlphaMaps ||  
            mGenLightMap || 
            mGenShadowMap ||
            mGenLitColorMapGenerate ||
            mGenLitColorMapSplit ||
            mGenLitBaseMap)
        {
            mNormalMap = NormalMapper.getNormalMap ();
            mNormalMapBpp = PixelUtil::getNumElemBytes (mNormalMap->getFormat ());
            mNormalMapData = mNormalMap->getData();
            mNormalMapDataSize = static_cast <uint> (mNormalMap->getSize());
        }

        // 
        // Split Normal Map in 2^n  part  
        // 
        if (mGenNormalMap)
        {
            Image normalcopy (*mNormalMap);
            mSplitter->saveAndSplitMap (mPureFilename + String(".N.") + mTextureExt,
                                                &normalcopy);
        } // if (mGenNormalMap)

        // 
        // Split Light Map in 2^n  part  
        // 
        if (mGenLightMap)
            mSplitter->saveAndSplitMap (mPureFilename + String(".Light.") + mTextureExt,
                                    mLightMapper->getLightMap (mSun, mAmb, mDiff, mBlur));
        // 
        // Split Shadow Map in 2^n  part (shadow is light map inverted.)
        // 
        if (mGenShadowMap)
            mSplitter->saveAndSplitMap (mPureFilename + String(".Shadow.") + mTextureExt,
                                    mLightMapper->getShadowMap (mSun, mAmb, mDiff, mBlur));

        // 
        // Generate a Color Map in 2^n  part 
        // 
        if (mGenColorMapGenerate)
            mSplitter->saveAndSplitMap (mPureFilename + String(".Color.") + mTextureExt,
                                    mSplatMapper->getColorMap ());

        // 
        // Lit Generated Color Map in 2^n  part 
        // 
        if (mGenLitColorMapGenerate)
        { 
            // does modify color map.
            mMergeModulater->ModulateGrayAndRgbInRgb (mLightMapper->getLightMap (mSun, mAmb, mDiff, mBlur),
                                                    mSplatMapper->getColorMap (),
                                                    2);
            mSplitter->saveAndSplitMap (mPureFilename + String(".LitColor.") + mTextureExt,
                                    mSplatMapper->getColorMap ());
        }


        // 
        // If user want to use its Own Color Map
        //
        if (mGenLitColorMapSplit)
			generateLitUserColorMap();

        // 
        // Split Base Map in 2^n  part 
        // 
        if (mGenBaseMap)
            mSplitter->saveAndSplitMap (mPureFilename + String(".Base.") + mTextureExt,
                                    mSplatMapper->getBaseMap ());
        // 
        // Split Coverage Map in 2^n  part 
        // 
        if (mGenCoverageMap)
        {
            //MapBlurrer Blurrer;

            // blur.
            //Blurrer.gaussianBlur (mSplatMapper->getCoverageMap (), 2);

            mSplitter->saveAndSplitMap (mPureFilename + String(".Coverage.0.") + mTextureExt,
                                    mSplatMapper->getCoverageMap ());
        }
        // 
        // Split Lit Base Map in 2^n  part 
        // 
        if (mGenLitBaseMap)
        { 
                // does modify Base Map.
                mMergeModulater->ModulateGrayAndRgbInRgb  (mLightMapper->getLightMap (mSun, mAmb, mDiff, mBlur),
                                                    mSplatMapper->getBaseMap (),
                                                    2);

                mSplitter->saveAndSplitMap (mPureFilename + String(".LitBase.") + mTextureExt,
                                            mSplatMapper->getBaseMap ());
        }

       

        // 
        // Split Alpha Map in 2^n  part 
        // (each alpha is a color channel of coverage Map)
        //
        if (mGenAlphaMaps)
		{
            for (uint i = 0; i < NumMatHeightSplat; i++)
			{
				const String alphaname =  mPureFilename + String(".Alpha.") + 
											StringConverter::toString(i) + 
											String(".") + mTextureExt;
				mSplitter->saveAndSplitMap (alphaname, 
										mSplatMapper->getAlphaMap (i));
			}
		}
       

		//
		////  let us calculate mountains shadows in RT
		////    
        if (mGenZHorizon)
			generateAndSplitHorizonMap();

        NormalMapper.reset();
        
        if (mTextureStretchFactor != 1.0f)
            delete [] mData;//only if resized

		unInitOneMap ();
    }
	//-----------------------------------------------------------------------
    void MapUtil::splitHeightMap()
    {
         mSplitter->setTerrainSave(true);
        mSplitter->setRawSave (StringUtil::match(mExt, "raw", false));
        mSplitter->saveAndSpaceAndSplitHeightData (mPureFilename, 
            mData, 
            mWidth, 
            mHeight); 
        mSplitter->setTerrainSave(false);
        mSplitter->setRawSave (StringUtil::match(mTextureExt, "raw", false));
    }
	//-----------------------------------------------------------------------
	void MapUtil::splitUserColorMap()
	{   
		const String MapName = mColorMapName;
		if (MapName == mFileName)
			OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS, 
			"HeightMap File and ColorMap file cannot be the same file", 
			"MapUtil::ProcessOneFile");

		const uint oldheight = mHeight;
		const uint oldwidth = mWidth;
		const uint oldpagesize = mPageSize;
		const uint oldbpp = mBpp;


        // set codec according to filename extension or cfg file parameter
        String colormPureFilename;
        std::vector< String > partofname = StringUtil::split (MapName, ".");
        Image ExistingColorMap;
        if (partofname.size() <= 1)
        {
            colormPureFilename = MapName;
            ExistingColorMap.load (colormPureFilename + "." + mColorMapNameExtension, mGroupName);
        }
        else
        {
            String load_ext_name = partofname[partofname.size() - 1];
            for (uint i = 0; i < partofname.size() - 1; i++)
                colormPureFilename += partofname[i];
            ExistingColorMap.load (colormPureFilename + "." + load_ext_name, mGroupName);

        }
        mBpp = ExistingColorMap.getBPP() / 8;
		//ExistingColorMap.resize(static_cast <ushort> (ExistingColorMap.getWidth ()+1), 
		//	static_cast <ushort> (ExistingColorMap.getHeight ()+1));
		mHeight = static_cast <uint> (ExistingColorMap.getHeight ());
		mWidth = static_cast <uint> (ExistingColorMap.getWidth ());

//ExistingColorMap.save("est.png");

		//mSplitter->init ();
		mPageSize = computePageSize (mWidth, mHeight, mPageX, mPageZ);
		mSplitter->init (mPaged, oldpagesize,  mBpp, mOutDirectory);

		mSplitter->setRawSave (false);
		// 
		// Split User Color Map in 2^n  part 
		// 	
		mSplitter->saveAndSplitMap (colormPureFilename + "." + 
			//mOptions->getMapFilename (mOptions->getCurrentMapName ()) + "." + 
			mColorMapNameExportExtension,
			&ExistingColorMap);
		mHeight = oldheight;
		mWidth = oldwidth;
		mPageSize = oldpagesize;
		mBpp = oldbpp;
		mSplitter->init (mPaged, oldpagesize,  mBpp, mOutDirectory);

		mSplitter->setRawSave (StringUtil::match(mTextureExt, "raw", false));

	}

	//-----------------------------------------------------------------------
	void MapUtil::splitUserAlphaMap()
	{   	
		const uint oldheight = mHeight;
		const uint oldwidth = mWidth;
		const uint oldpagesize = mPageSize;
		mSplitter->setRawSave (StringUtil::match(mTextureExt, "raw", false));

		for (uint l = 0; l < mNumSplatMapToSplit; l++)
		{
			Image ExistingSplatMap;
			const String MapName = (*mSplatMapNames)[l];
			ExistingSplatMap.load (MapName, mGroupName);
			ExistingSplatMap.resize(static_cast <ushort> (ExistingSplatMap.getWidth ()+1), 
				static_cast <ushort> (ExistingSplatMap.getHeight ()+1)); 
			mHeight = static_cast <uint> (ExistingSplatMap.getHeight ());
			mWidth = static_cast <uint> (ExistingSplatMap.getWidth ());

			mPageSize = computePageSize (mWidth, mHeight, mPageX, mPageZ);
			mSplitter->init (mPaged, oldpagesize,  mBpp, mOutDirectory);
			// 
			// Split User Color Map in 2^n  part 
			// 
			const String splitmPureFilename = MapName.substr(0, MapName.find_last_of(".") + 1);
			mSplitter->saveAndSplitMap (splitmPureFilename + "." + mTextureExt, &ExistingSplatMap);

		}
		mHeight = oldheight;
		mWidth = oldwidth;
		mPageSize = oldpagesize;
		mSplitter->init (mPaged , oldpagesize, mBpp, mOutDirectory);
		mSplitter->setRawSave (StringUtil::match(mTextureExt, "raw", false));
	}

	//-----------------------------------------------------------------------
	void MapUtil::generateMiniMap()
	{
		const uint W = MapUtil::getSingleton().getMapWidth ();
		const uint H  = MapUtil::getSingleton().getMapHeight ();
		const uint hn_map_size = W*H;

		//uchar *data =  new uchar[hn_map_size];  
		uchar *data = OGRE_ALLOC_T(uchar, hn_map_size, Ogre::MEMCATEGORY_GENERAL);    
  

		const Real divider = 1.0f / getMaxTheoHeight() * 256;
		Real *hdata = mData;
		for ( uint i = 0; i < hn_map_size; i++ )            
		{ 
			data[i] = static_cast <uchar>  (hdata[i] * divider);
		}
		Image grayheightmap;

		grayheightmap.loadDynamicImage (data, 
			static_cast <size_t> (W),
			static_cast <size_t> (H), 
			1, PF_L8, true);


		const ushort wtiles = mGenMiniMapWidth;
		const ushort htiles = mGenMiniMapHeight; 

		grayheightmap.resize (wtiles, htiles);

		const String OutDirectory = mOutDirectory;



		char *olddir;
		if (!OutDirectory.empty())
		{
			olddir = ChangeToDir (const_cast< char * > (OutDirectory.c_str ()));
		}

		mSplitter->saveExt (mPureFilename + ".Small." + mTextureExt, grayheightmap.getData(), 
			static_cast <uint> (wtiles), 
			static_cast <uint> (htiles),
			1);

		if (!OutDirectory.empty())
		{
			RetablishDir (olddir); 
		}  

		String MapName = mColorMapName;
		if (MapName != StringUtil::BLANK && MapName != "none")    
		{
			if (MapName == mFileName)
				OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS, 
				"HeightMap File and ColorMap file cannot be the same file", 
				"MapUtil::ProcessOneFile");

            // set codec according to filename extension or cfg file parameter
            String colormPureFilename;
            std::vector< String > partofname = StringUtil::split (MapName, ".");
            Image ExistingColorMap;
            if (partofname.size() <= 1)
            {
                colormPureFilename = MapName;
                ExistingColorMap.load (colormPureFilename + "." + mTextureExt, mGroupName);
            }
            else
            {
                String load_ext_name = partofname[partofname.size() - 1];
                for (uint i = 0; i < partofname.size() - 1; i++)
                    colormPureFilename += partofname[i];
                ExistingColorMap.load (colormPureFilename + "." + load_ext_name, mGroupName);

            }

			ExistingColorMap.resize (wtiles,htiles);

			char *olddir;
			if (!OutDirectory.empty())
			{
				olddir = ChangeToDir (const_cast< char * > (OutDirectory.c_str ()));
			}

			mSplitter->saveExt (colormPureFilename + ".Small." + mColorMapNameExportExtension, ExistingColorMap.getData(), 
				static_cast <uint> (wtiles), 
				static_cast <uint> (htiles),
				3);

			if (!OutDirectory.empty())
			{
				RetablishDir (olddir); 
			}
		}
	}

	//-----------------------------------------------------------------------
	void MapUtil::generateAndSplitNormalMap()
	{
		// 
		// Split Normal Map in 2^n  part  
		// 
		mNormalMap = NormalMapper.getNormalMap ();
		mNormalMapBpp = PixelUtil::getNumElemBytes (mNormalMap->getFormat ());
		mNormalMapData = mNormalMap->getData();
		mNormalMapDataSize = static_cast <uint> (mNormalMap->getSize());

		Image normalcopy (*mNormalMap);
		mSplitter->saveAndSplitMap (mPureFilename + String(".Nsmall.") + mTextureExt,
			&normalcopy);
	}
	//-----------------------------------------------------------------------
	void MapUtil::generateAndSplitHeightNormalMap()
	{
		const uint W = mWidth;
		const uint H  = mHeight;
		const uint hn_map_size = W*H;
		//uchar *data = new uchar[hn_map_size];  
		uchar *data = OGRE_ALLOC_T(uchar, hn_map_size, MEMCATEGORY_GENERAL);          
		const Real divider = 1.0f / maxHeight * 256;
		Real *hdata = mData;
		for ( uint i = 0; i < hn_map_size; i++ )            
		{ 
			data[i] = static_cast <uchar>  (hdata[i] * divider);
		}
		Image grayheightmap;

		grayheightmap.loadDynamicImage (data, static_cast <size_t> (W),
			static_cast <size_t> (H), 1, PF_L8, true);

		Image *NormalMap = mMergeModulater->MergeGrayAndRgbInRgba (&grayheightmap,
			NormalMapper.getNormalMap ());

		mSplitter->saveAndSpaceAndSplitMap (mPureFilename + ".HN." + mExt,
			NormalMap);
		delete NormalMap;
	}
	//-----------------------------------------------------------------------
	void MapUtil::stretchHeightMap()
	{
		const Real stretchFactor = mTextureStretchFactor;
		DEBUG_OUTPUT (String("stretchFactor : ") + StringConverter::toString(stretchFactor));
		const uint newWidth = mWidth* stretchFactor - stretchFactor + 1; 
		const uint newHeight = mHeight* stretchFactor - stretchFactor + 1;
		Real *bump = new Real[newWidth*newHeight];
		ErodeFault eroder;
		eroder.MakeTerrainPlasma (bump, 
			newWidth, newHeight, 
			0.001f,
			scale.y);  

		Real *Stretched = stretchandExtendHeightmap(mData, bump,
			stretchFactor, 
			mWidth, mHeight, 
			mPageSize, 
			mPageX, mPageZ,
			mMax, scale.y);

		delete [] bump;

		mWidth = newWidth; 
		mHeight = newHeight;
		mPageSize *= stretchFactor;

		mData = Stretched; 

		// saves in bin dir a debugged image
		//mSplitter->saveHeightData ("bigheight.png", Stretched, mWidth, mHeight);

		NormalMapper.reset();
	}
	//-----------------------------------------------------------------------
	void MapUtil::generateLitUserColorMap()
	{
		const String MapName = mColorMapName;
		if (MapName == mFileName)
			OGRE_EXCEPT(Exception::ERR_INVALIDPARAMS, 
			"HeightMap File and ColorMap file cannot be the same file", 
			"MapUtil::ProcessOneFile");

		const uint oldheight = mHeight;
		const uint oldwidth = mWidth;
		const uint oldpagesize = mPageSize;

		Image ExistingColorMap;
		ExistingColorMap.load (MapName, mGroupName);
		ExistingColorMap.resize(static_cast <ushort> (ExistingColorMap.getWidth ()+1), 
			static_cast <ushort> (ExistingColorMap.getHeight ()+1));

		mHeight = static_cast <uint> (ExistingColorMap.getHeight ());
		mWidth = static_cast <uint> (ExistingColorMap.getWidth ());
		mPageSize = computePageSize (mWidth, mHeight, mPageX, mPageZ);
		//mSplitter->init ();

		mSplitter->setRawSave (StringUtil::match(mTextureExt, "raw", false));
		// 
		// Split User Color Map in 2^n  part 
		// 
		// Get codec according to filename extension
		String colormPureFilename = MapName.substr(0, MapName.find_last_of(".") + 1);
		// 
		// Lit User Color Map  in 2^n  part 
		// 

		// does modify colormap.
		mMergeModulater->ModulateGrayAndRgbInRgb (mLightMapper->getLightMap (mSun, mAmb, mDiff, mBlur),
			&ExistingColorMap,
			2);
		mSplitter->saveAndSplitMap (colormPureFilename + String(".Lit.") + mTextureExt,
			&ExistingColorMap);


		mHeight = oldheight;
		mWidth = oldwidth;
		mPageSize = oldpagesize;
		mSplitter->init (mPaged, oldpagesize,  mBpp, mOutDirectory);

		mSplitter->setRawSave (StringUtil::match(mTextureExt, "raw", false));
	}
	//-----------------------------------------------------------------------
	void MapUtil::generateAndSplitHorizonMap()
	{
		MapHorizon3 HorizonMapper3;

		HorizonMapper3.calcHorizonMap ();
		const String hname = mPureFilename + String(".HS.") + mTextureExt;
		mSplitter->saveAndSplitMap (hname, HorizonMapper3.getHorizonMap ());

		//            HorizonMapper3.calcLightMap ();
		//            const String lname = mPureFilename + String(".Light.") + mTextureExt;
		//            mSplitter->saveAndSplitMap (lname, HorizonMapper3.getLightMap ());


		//            const String pname = mPureFilename + String(".HSP.") + mTextureExt;
		//            mSplitter->saveAndSplitMap (pname, HorizonMapper3.getPositiveHorizonMap ());

		Image *NormalMap = mMergeModulater->MergeGrayAndRgbInRgba (HorizonMapper3.getPositiveHorizonMap (),
			NormalMapper.getNormalMap ());

		mSplitter->saveAndSplitMap (mPureFilename + ".HSP." + mExt,
			NormalMap);
		delete NormalMap;

		//            const String nname = mPureFilename + String(".HSN.") + mTextureExt;
		//            mSplitter->saveAndSplitMap (nname, HorizonMapper3.getNegativeHorizonMap ());

		NormalMap = mMergeModulater->MergeGrayAndRgbInRgba (HorizonMapper3.getNegativeHorizonMap (),
			NormalMapper.getNormalMap ());

		mSplitter->saveAndSplitMap (mPureFilename + ".HSN." + mExt,
			NormalMap);
		delete NormalMap;
	}

}//namespace Ogre
