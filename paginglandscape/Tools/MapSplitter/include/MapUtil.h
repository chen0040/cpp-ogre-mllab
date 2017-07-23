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
MapUtil.h
@brief
Utility that split big map in tiles, pre-calculate splatting by
pre-calculating coverage map and pre-calculate normals.
*/
#ifndef MapUtil_H
#define MapUtil_H

#define LOGTHIS(A)  {Ogre::LogManager::getSingleton().logMessage(A);}

#ifdef _DEBUG
	#define DEBUG_PROGRESS_OUTPUT(iter, A) {if (iter%64){std::cout << String(A);}}
	#define DEBUG_END_SECTION_OUTPUT(A) {std::cout << String(A);}
#else
	#define DEBUG_PROGRESS_OUTPUT(iter, A)
	#define DEBUG_END_SECTION_OUTPUT(A) 
#endif 

#define DEBUG_OUTPUT(A) { LOGTHIS(A);}

#include "Ogre.h"
#include "OgreRoot.h"
#include "OgreImage.h"
#include "OgreString.h"
#include "OgreSingleton.h"
#include "OgreDefaultHardwareBufferManager.h"
#include "OgreMaterialManager.h"


#ifndef _MAPEDITOR
    #include "OgrePagingLandScapeOptions.h"
    #include "OgrePagingLandScapeData2D.h"
#endif //_MAPEDITOR

#include "OgrePagingLandScapePrerequisites.h"
#include "MapNormaler.h"


namespace Ogre
{

	class MapSplitter;
	class MapMergeModulater;
	class MapLighter;
	class MapSplatter;
	/**
	 * \ingroup Tool_MapSplitter
	 *
	 *
	 * \par 
	 *
	 * \version 0.5
	 * fifth version
	 *
	 * \date 06-07-2006
	 *
	 * \author tuan.kuranes@free.fr
	 *
	 * \todo 
	 * Add New methods, faster, smaller. 
	 * Add DXT5 compression to maps.
	 * Add Real-time methods to modify part of a map
	 *     (SubNormalCalc, SubCoverageCalc, subPvs, sublight)
	 * adds unlimited number of splat maps ?
	 * Zip all maps at the end 
	 * 
	 *
	 * \bug 
	 */
		class MapUtil : public Singleton<MapUtil>
		{
		public :
			static MapUtil& getSingleton(void);
			/** Override standard Singleton retrieval.
				@remarks
				Why do we do this? Well, it's because the Singleton
				implementation is in a .h file, which means it gets compiled
				into anybody who includes it. This is needed for the
				Singleton template to work, but we actually only want it
					compiled into the implementation of the class based on the
					Singleton, not all of them. If we don't change this, we get
					link errors when trying to use the Singleton-based class from
					an outside dll.
					@par
					This method just delegates to the template version anyway,
					but the implementation stays in this single compilation unit,
					preventing link errors.
			*/
			static MapUtil* getSingletonPtr(void);
	        

			MapUtil();
			~MapUtil();
			/**
			*  @rem if launched on its own load options...
			*/
            void Load();
            /**
            *  @rem if launched on its own load Ogre, log, etc...
            */
            void init();
			/**
			*  @rem does process one or more maps
			*/
			void process(); 
			/**
			*  @remarks 
			* Does what it should. (depending on option file)
			*/
			void processOneMap ();
			/**
			 *  @remarks 
			 * no scaling here.
			 * \param x position in width
			 * \param z position in height
			 * \return height at this point
			 */
			const Real getHeight (const Real x, const Real z) const ; 
			/**
			 *  @remarks 
			 *  
			 */
			Real *getHeightData ();
			/**
			*  @remarks 
			* no scaling here. Value comes from the pre-calculated map.
			* \param x position in width
			* \param z position in height
			* \return Normal at this point
			*/
			const Vector3 getNormalAt(const Real x, const Real z)  ;
			/**
			 *  @remarks 
			 *  
			 */
			Vector3 *getNormalData();
			/**
			*
			* \return Max height
			*/
			Real getMaxHeight () const {return mMax;}       
			/**
			*
			* \return total Width of HeightMap
			*/
			uint getMapWidth () const {return mWidth;}
			/**
			*
			* \return total Height of HeightMap
			*/
			uint getMapHeight () const {return mHeight;}
			/**
			*
			* \return total Width of HeightMap
			*/
			uint getMapTileWidthNumber () const {return mPageX;}
			/**
			*
			* \return total Height of HeightMap
			*/
			uint getMapTileHeightNumber () const {return mPageZ;}      
			/**
			*
			* \param Filename of image to load as Map 
			* \param *ImageMap Where to load image
			* \return 
			*/
			void load (const String &filename, Image *ImageMap);
	     
			/**
			* save and split maps
			* \param extension of filename name under which file must be saved
			*/
			void saveAndSplitHeightMap (const String &filename);
			/**
			* save and split Normal maps
			* \param extension of filename name under which file must be saved
			*/
			void saveAndSplitNormalMap (const String &filename);
			/**
			* save and split Base maps
			* \param extension of filename name under which file must be saved
			*/
			void saveAndSplitBaseMap (const String &filename);
			/**
			* save and split Color maps
			* \param extension of filename name under which file must be saved
			*/
			void saveAndSplitColorMap (const String &filename);
			/**
			* save and split Coverage maps
			* \param extension of filename name under which file must be saved
			*/
			void saveAndSplitCoverageMap (const String &filename);
			/**
			* save and split Alpha maps
			* \param extension of filename name under which file must be saved
			*/
			void saveAndSplitAlphaMaps (const String &filename, int i);
			/**
			* save and split Light maps
			* \param extension of filename name under which file must be saved
			*/
			void saveAndSplitLightMap (const String &filename);
			/**
			* save and split Shadow maps
			* \param extension of filename name under which file must be saved
			*/
			void saveAndSplitShadowMap (const String &filename);
			/**
			* get theoretical maximum height (depend on source data type, not on data)
			*/
			const Real getMaxTheoHeight () const;

			void LoadDataFromMemory(uint mapWidth, 
										uint mapHeight, 
										Real *heightData,
										Real max);

			void LoadDataFromSource();
			void LoadOptions();
			 void setMap (const String &mapName, 
						const String &extension, 
						const String &texture_extension, 
						const uint pageSize,
						const String &OutDirectory,
						const String &groupname,
						const Real textureFactor);

			void setMapColoring (const ColourValue *colors, 
									   const Real *heights,
									   const uint numColors);
	 

            void LoadSingleMap(const String &cfgFile, const String &cfgGroupName = StringUtil::BLANK);

			bool initOneMap();
			void unInitOneMap();

			void splitHeightMap();
			void splitUserColorMap();
			void splitUserAlphaMap();
			void generateMiniMap();
			void generateAndSplitNormalMap();
			void generateAndSplitHeightNormalMap();
			void stretchHeightMap();
			void generateLitUserColorMap();
			void generateAndSplitHorizonMap();


			String mFileName;
			String mPureFilename;
			String mExt;
			String mTextureExt;

			String mColorMapName; 
            String mColorMapNameExtension;
            String mColorMapNameExportExtension;

            bool b_SaveAsRaw;
            bool b_SaveAsTerrain;
			bool b_SaveAsPng;
			bool b_SaveBigFile;

			uint mPageSize;
			uint mPageSpacing;

			uint mPageX;
			uint mPageZ;

			uint mp2Height;
			uint mp2Width;

			uint mHeight;
			uint mWidth;
			Real mMax;

			bool mGenHeightMap;
			bool mGenMiniMap;
			uint mGenMiniMapWidth;
			uint mGenMiniMapHeight;
			bool mGenCoverageMap;
			bool mGenBaseMap;
			bool mGenAlphaMaps;
			bool mGenLightMap;

			bool mGenColorMapGenerate;
			bool mGenColorMapSplit;
			bool mGenElevationMap;

			bool mGenNormalMap;
			bool mGenEqualize;
			bool mGenInfiniteMap;

			bool mGenHeightNormalMap;
			bool mGenShadowMap;

			bool mGenLitColorMapGenerate;
			bool mGenLitColorMapSplit;
			bool mGenLitBaseMap;

			bool mGenZHorizon;

			Real mHeightMapBlurFactor;

			bool mPaged;			
			String mOutDirectory;

			uint mNumSplatMapToSplit;
			std::vector<String> *mSplatMapNames;


	#ifndef _MAPEDITOR
			PagingLandScapeData2DManager *mData2dManager;
			PagingLandScapeData2D *mHeightdata;
			PagingLandScapeOptions *mOptions;
	#endif //_MAPEDITOR

			Image *mNormalMap;
			Image *mAlphaMap[4];
			size_t  mNormalMapBpp;
			uint  mNormalMapDataSize;
			uchar *mNormalMapData;

			 MapNormaler NormalMapper; 

			 Vector3 mSun;
			 Real    mAmb;
			 Real    mDiff;
			 int     mBlur;

			Vector3 scale;
			String mGroupName;

			uint mBpp;


			uint NumMatHeightSplat;
			std::vector <ColourValue>   matColor;
			std::vector <Real>          matHeight;
			std::vector<String>			SplatDetailMapNames;
	        
	        
			Real          mTextureStretchFactor;

	private :

			MapSplitter			*mSplitter;
			MapMergeModulater	*mMergeModulater;
			MapLighter			*mLightMapper;
			MapSplatter			*mSplatMapper;

			 Root *mRoot;      
			 Real *mData;
			 Real maxHeight;

			/**
			 * Loads the Big heightMap to split and pre-calculate
			 *
			 */
			void loadHeightMap();

	};
}
#endif //MapUtil_H
