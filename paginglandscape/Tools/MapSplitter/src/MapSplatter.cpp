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
MapSplatter.cpp
@brief
Utility that pre-calculate splating by
pre-calculating coverage map, A Color Map and a Base Map.
*/
#include "MapUtil.h"
#include "MapSplatter.h"
#include "MapBlurrer.h"

#include <iostream>

namespace Ogre
{
//----------------------------------------------------------------------
MapSplatter::MapSplatter()
{
    reset();
}
//----------------------------------------------------------------------
MapSplatter::~MapSplatter()
{
   
}
//----------------------------------------------------------------------
Image *MapSplatter::getBaseMap()
{
    CalcMapSplats ();
    return &BaseMap;
}
//----------------------------------------------------------------------
Image *MapSplatter::getCoverageMap()
{
    CalcMapSplats ();
    return &CoverageMap;
}
//----------------------------------------------------------------------
Image *MapSplatter::getColorMap()
{
    CalcMapSplats ();
    return &ColorMap;
}
//----------------------------------------------------------------------
Image *MapSplatter::getAlphaMap(uint i)
{
    CalcMapSplats ();
    return &destAlphaMap[i];
}
//----------------------------------------------------------------------
void MapSplatter::reset()
{
    mAlreadyComputed = false;  

	SplatMap.clear (); // source Splats Maps
	destAlphaMap.clear (); //destination Alpha Maps
	matColor.clear ();// average color value of splats map
	matHeight.clear (); // Height value upon which splat is chosen
}

//----------------------------------------------------------------------
void MapSplatter::CalcMapSplats()
{
    if (mAlreadyComputed)
        return;
	
	MapUtil * const mapUtil = MapUtil::getSingletonPtr();	
    const bool b_Base = mapUtil->mGenBaseMap || 
        mapUtil->mGenLitColorMapGenerate;    
    const bool b_Color = mapUtil->mGenColorMapGenerate || 
        mapUtil->mGenLitColorMapGenerate;
    const bool b_Alpha = mapUtil->mGenAlphaMaps;
    const bool b_Coverage = mapUtil->mGenCoverageMap;    
    const uint numMatHeightSplat = mapUtil->NumMatHeightSplat;
	
    
    /// Generates ColorMap using splatting textures.
    // each splatting texture can have different 
    // height, width and pixel size
    std::vector<uchar * ogre_restrict> SplatMapData;
    std::vector<uint> SplatMapWidth;
    std::vector<uint> SplatMapHeight;
    std::vector<uint> SplatMapbpp;
    std::vector<uint> SplatMap_index_pixel;    
    if (b_Color)
    {
        DEBUG_OUTPUT ("Loading Splats Maps ");
        
		SplatMap.reserve (numMatHeightSplat);
		SplatMap.resize (numMatHeightSplat);
		SplatMapData.reserve (numMatHeightSplat);
		SplatMapData.resize (numMatHeightSplat);
		SplatMapWidth.reserve (numMatHeightSplat);
		SplatMapWidth.resize (numMatHeightSplat);
		SplatMapHeight.reserve (numMatHeightSplat);
		SplatMapHeight.resize (numMatHeightSplat);
		SplatMapbpp.reserve (numMatHeightSplat);
		SplatMapbpp.resize (numMatHeightSplat);
		SplatMap_index_pixel.reserve (numMatHeightSplat);
		SplatMap_index_pixel.resize (numMatHeightSplat);
		
		for (uint i = 0; i < numMatHeightSplat; i++) 
		{
			mapUtil->load(mapUtil->SplatDetailMapNames[i], 
							&SplatMap[i]);
			SplatMapData[i] = SplatMap[i].getData();
			SplatMapWidth[i] = static_cast <uint> (SplatMap[i].getWidth ());
			SplatMapHeight[i] = static_cast <uint> (SplatMap[i].getHeight ());
			SplatMapbpp[i] = static_cast <uint> (PixelUtil::getNumElemBytes (SplatMap[i].getFormat ()));
			SplatMap_index_pixel[i] = 0;
		}
    }
     
    const uint terrain_height = mapUtil->getMapHeight ();
    const uint terrain_width = mapUtil->getMapWidth ();

    const uint size1 = terrain_height * terrain_width;
    const uint size3 = size1 + size1 + size1;
    const uint size4 = size3 + size1;

    uchar * ogre_restrict BaseData;
    if (b_Base) 
    {
        //DEBUG_OUTPUT ( "Base ");
         // Create the base image 
        //uchar *dataRGB = new uchar[size3];
		uchar *dataRGB = OGRE_ALLOC_T(uchar, size3, MEMCATEGORY_GENERAL);

        BaseMap.loadDynamicImage (dataRGB, (terrain_width), 
            (terrain_height), 1, PF_R8G8B8, true);
        BaseData = BaseMap.getData();
    }    
    
    uchar * ogre_restrict ColorData;   
    if (b_Color) 
    {
        //DEBUG_OUTPUT ( "Color ");
        // Create the color texture
		//uchar *dataRGB = new uchar[size3];
		uchar *dataRGB = OGRE_ALLOC_T(uchar, size3, MEMCATEGORY_GENERAL);

        ColorMap.loadDynamicImage (dataRGB, (terrain_width), 
            (terrain_height), 1, PF_R8G8B8, true);
        ColorData = ColorMap.getData();
    }
    
    uchar * ogre_restrict CoverageData;
    if (b_Coverage) 
    {  
        //DEBUG_OUTPUT ( "Coverage ");
		//uchar *dataRGBA = new uchar[size4];  
		uchar *dataRGBA = OGRE_ALLOC_T(uchar, size4, MEMCATEGORY_GENERAL);

        CoverageMap.loadDynamicImage (dataRGBA, (terrain_width), 
            (terrain_height), 1, PF_R8G8B8A8, true);
        CoverageData = CoverageMap.getData();
    } 

    // alpha maps for splatting using fixed blending techniques
    std::vector<uchar * ogre_restrict> destAlphaMapData;
    if (b_Alpha) 
    {      
        //std::cout << "Alpha ";
        
		destAlphaMapData.reserve (numMatHeightSplat);
		destAlphaMapData.resize (numMatHeightSplat);
		
		destAlphaMap.reserve (numMatHeightSplat);
		destAlphaMap.resize (numMatHeightSplat);		

        // create transparent Alpha images
        // loadDynamicImage  does not allocate and Cpu::memCpy data
        for (uint i = 0; i < numMatHeightSplat; i++) 
        {        
			//uchar *dataGray = new uchar[size1];
			uchar *dataGray = OGRE_ALLOC_T(uchar, size1, MEMCATEGORY_GENERAL);
			memset (dataGray, 0, size1);
			destAlphaMap[i].loadDynamicImage (dataGray, 
												(terrain_width), 
												(terrain_height), 
												1, 
												PF_A8, 
												true);
			destAlphaMapData[i] = destAlphaMap[i].getData ();			
        }
    }
    
    uint index_1pixel = 0;
    uint index_3pixel = 0;
    uint index_4pixel = 0;

    mScale  = mapUtil->scale;
	matColor.reserve (numMatHeightSplat);
	matColor.resize (numMatHeightSplat);
    for (uint iColors = 0; iColors < numMatHeightSplat; iColors++) 
    {    
		matColor[iColors] = mapUtil->matColor[iColors];
	}
	matHeight.reserve (numMatHeightSplat);
	matHeight.resize (numMatHeightSplat);
    for (uint iHeight = 0; iHeight < numMatHeightSplat; iHeight++) 
    {    
		matHeight[iHeight] = mapUtil->matHeight[iHeight];
	}
    const Real maxHeight = mapUtil->getMaxHeight ();
	if (numMatHeightSplat > 0 && matHeight[numMatHeightSplat - 1] == 0.0f)
		matHeight[numMatHeightSplat - 1] = maxHeight; 
		
	std::vector<Real> dividers; 
	dividers.reserve (numMatHeightSplat);
	dividers.resize (numMatHeightSplat);
	if (numMatHeightSplat)
	{
		dividers[0] = 1.0f;
		
		for (uint idividers = 1; idividers < numMatHeightSplat; idividers++) 
		{   
			if ((matHeight[idividers]  - matHeight[idividers - 1])  > 0)
				dividers[idividers] = 1 / (matHeight[idividers]  - matHeight[idividers - 1]);
			else 
				dividers[idividers] = 0.0f;
		}		
	}

	std::vector<Real> alpha; 
	alpha.reserve (numMatHeightSplat);
	alpha.resize (numMatHeightSplat);

	std::vector<Real> splat; 
	splat.reserve (numMatHeightSplat);
	splat.resize (numMatHeightSplat);
    // This texture will be used as a base color for the terrain, 
    // it will fake the splat for distant renderables.
    DEBUG_OUTPUT ( "Map Calc ");
    uint j = 0;
    
    const Real *  const ogre_restrict heightmap = mapUtil->getHeightData ();
    const Vector3 *  const ogre_restrict normal = mapUtil->getNormalData ();
    const uchar bScale = 255;


    uint curr_row = 0;
    while (j < terrain_height)
    { 
        DEBUG_PROGRESS_OUTPUT(j, ".")
        uint i = 0;
        while (i < terrain_width)
       {
            // calculate value using height and slope

            const Real height = heightmap[i + curr_row];

            uint indx = 1;
            while (indx < (numMatHeightSplat - 1) && height > matHeight[indx])
                indx++;    

            const Real interpol = (height  - matHeight[indx - 1]) * dividers[indx];  
            //slope of current point (the y value of the normal)
            const Real Slope = 1.0f - normal[i + curr_row].y; 
            

            //ColourValue color;
			for (uint ialpha = 0; ialpha < numMatHeightSplat; ialpha++) 
			{    
				alpha[ialpha] = 0.0f;
			}

            if (Slope < 0.05f)// speed-up as it's invisible
            {
                const Real B = (1.0f - interpol);
                const Real C = interpol;

                alpha[indx - 1] = B;
                alpha[indx] = C; 

                if (b_Base)
                { 
                    BaseData[ index_3pixel     ] = static_cast <uchar> ((matColor[indx - 1].r * B + matColor[indx].r * C)* bScale);
                    BaseData[ index_3pixel + 1 ] = static_cast <uchar> ((matColor[indx - 1].g * B + matColor[indx].g * C)* bScale);
                    BaseData[ index_3pixel + 2 ] = static_cast <uchar> ((matColor[indx - 1].b * B + matColor[indx].b * C)* bScale);
                }
            }
            else 
            {
                const Real A = (1.0f - Slope);
                const Real B = A * (1.0f - interpol);
                const Real C = A * interpol;
                const Real D = Slope;
                
                alpha[indx - 1] = B;
                alpha[indx] = C; 

                alpha[ 2 ] = alpha[ 2 ] + Slope;
                alpha[ 2 ] = alpha[ 2 ] > 1.0f ? 1.0f : alpha[ 2 ];
                
                if (b_Base)
                { 
                    BaseData[ index_3pixel    ] = static_cast <uchar> ((matColor[indx - 1].r * B + matColor[indx].r * C + matColor[2].r * D)* bScale);
                    BaseData[ index_3pixel + 1] = static_cast <uchar> ((matColor[indx - 1].g * B + matColor[indx].g * C + matColor[2].g * D)* bScale);
                    BaseData[ index_3pixel + 2] = static_cast <uchar> ((matColor[indx - 1].b * B + matColor[indx].b * C + matColor[2].b * D)* bScale);            
                }
            }

            if (b_Color)
            {
                //const uchar inv_alpha = static_cast <uchar>(( 1.0 - ( alpha0 + alpha1 + alpha2 + alpha3 ) ) * Bscale);
            
				Real colorResult;
                //Red, Green, Blue                
				for (uint icolorIdx = 0; icolorIdx < 3; icolorIdx++) 
				{
					colorResult = 0;
					for (uint icolorResult = 0; icolorResult < numMatHeightSplat; icolorResult++) 
					{    
						colorResult += 
							SplatMapData[icolorResult][SplatMap_index_pixel[icolorResult] + icolorIdx] 
							* 
							alpha[icolorResult];
					}
					ColorData[index_3pixel + icolorIdx] = static_cast <uchar>(colorResult);
				}
            }

			for (uint isplat = 0; isplat < numMatHeightSplat; isplat++) 
			{    
				splat[isplat] = static_cast <uchar> (alpha[isplat] * bScale);
			}
                
            if (b_Coverage && numMatHeightSplat > 3)
            {
                CoverageData[index_4pixel] = splat[0];// stored as Red
                CoverageData[index_4pixel + 1] = splat[1];// stored as Green
                CoverageData[index_4pixel + 2] = splat[2];// stored as Blue
                CoverageData[index_4pixel + 3] = splat[3];// stored as Alpha
                
            }
            if (b_Alpha)
            {
				for (uint ialphadest = 0; ialphadest < numMatHeightSplat; ialphadest++) 
				{    
					destAlphaMapData[ialphadest][index_1pixel] = splat[ialphadest];
				}
            }
            // don't move it a the end 
            // it will false following computation
            // of position in splats maps
            i++;
            index_1pixel ++;
            index_3pixel += 3;
            index_4pixel += 4;

            ///
            if (b_Color)
            {
				for (uint ipxl = 0; ipxl < numMatHeightSplat; ipxl++) 
				{    
					SplatMap_index_pixel[ipxl] = SplatMapbpp[ipxl];
					if ((i % SplatMapWidth[ipxl]) == 0)
						SplatMap_index_pixel[ipxl] -= SplatMapWidth[ipxl]*SplatMapbpp[ipxl];
				}
            }
        }
        curr_row += terrain_width;
        j++;
        if (b_Color)
        {
			for (uint ipxl = 0; ipxl < numMatHeightSplat; ipxl++) 
			{    
				SplatMap_index_pixel[ipxl] = (j % SplatMapHeight[ipxl]) 
												* SplatMapWidth[ipxl] 
												* SplatMapbpp[ipxl];
			}
        }
    }
    // use bAlphaNotUsed to change coverage from 4 channel to less...
   
    DEBUG_END_SECTION_OUTPUT ("\n");

    mAlreadyComputed = true;
}
//-----------------------------------------------------------------------
void MapSplatter::BuildPoint(ColourValue& out, int x, int z, Real& alpha1, 
                           Real& alpha2, Real& alpha3, Real& alpha4)
{
    // Init the colour
    
    alpha1 = 0.0f;
    alpha2 = 0.0f;
    alpha3 = 0.0f;
    alpha4 = 0.0f;


#define SNOW  0
#define SAND  1
#define GRASS 2
#define ROCK  3
    // Ask for the current height value and the 8 surrounding values
    if ( x == 0 )
    {
        x = 1;
    }
    else if (x == int (mWidth))
    {
        x = mWidth - 1;
    }
    if ( z == 0 )
    {
        z = 1;
    }
    else if (z == int (mHeight))
    {
        z = mHeight - 1;
    }
//    /*
//            h1
//      h0*---*---*h2
//        |0 /|2 /|
//        | / | / |
//        |/ 1|/ 3|
//      h3*---h4--*h5
//        |7 /|4 /|
//        | / | / |
//        |/ 6|/ 5|
//      h6*---*--*h8
//            h7
//            */  
	const MapUtil * const mapUtil = MapUtil::getSingletonPtr ();
	const Real height[] =
	{
		mapUtil->getHeight( x - 1, z - 1 ),		// Top-Left
		mapUtil->getHeight( x, z - 1 ),			// Top-Center
		mapUtil->getHeight( x + 1, z - 1 ),		// Top-Right
		mapUtil->getHeight( x - 1, z ),			// Left
		mapUtil->getHeight( x, z ),				// Current Point
		mapUtil->getHeight( x + 1, z ),			// Right
		mapUtil->getHeight( x - 1, z + 1 ),		// Bottom-Left
		mapUtil->getHeight( x, z + 1 ),			// Bottom-Center
		mapUtil->getHeight( x + 1, z + 1 )		// Bottom-Right
    };
    
    // Weight( pt1 , pt2 ) = 1 - DistanceSquared(pt1,pt2) / (1.75)^2
    
    //The sloppy test
    
    const Real dx = mapUtil->scale.x;
	const Real dz = mapUtil->scale.z;
    const Real inv_dxdz = 1.0 / (dx+dz);
    const Real inv_dx = 1.0 / dx;
    const Real inv_dz = 1.0 / dz;

	const Real sloppy[] =
	{
		Math::Abs ( height[0] - height[4] ) * inv_dxdz,
		Math::Abs ( height[1] - height[4] ) * inv_dz,
		Math::Abs ( height[2] - height[4] ) * inv_dxdz,
		Math::Abs ( height[3] - height[4] ) * inv_dx,
		Math::Abs ( height[5] - height[4] ) * inv_dx,
		Math::Abs ( height[6] - height[4] ) * inv_dxdz,
		Math::Abs ( height[7] - height[4] ) * inv_dz,
		Math::Abs ( height[8] - height[4] ) * inv_dxdz
    };
    out = ColourValue(0.0f, 0.0f, 0.0f, 0.0f);

	alpha1 = 0.0f;
	alpha2 = 0.0f;
	alpha3 = 0.0f;
	alpha4 = 0.0f;

    for ( uint i = 0; i < 7; i++ )
    {    
        if ( height[i] < matHeight[0] )
         {
            if ( sloppy[i] < 0.2f )
            {
                // grass-grass
                InterpolateColour( out, 1.0f, GRASS, GRASS );
                InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 1.0f, GRASS, GRASS );
            }
            if ( sloppy[i] >= 0.15f && sloppy[i] < 0.4f )
            {
                // sand-grass
                InterpolateColour( out, 0.25f, SAND, GRASS );
                InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 0.25f, SAND, GRASS );
            }
            if ( sloppy[i] >= 0.3f && sloppy[i] < 0.65f )
            {
                // sand-sand
                InterpolateColour( out, 1.0f, SAND, SAND );
                InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 1.0f, SAND, SAND );
            }
            if ( sloppy[i] >= 0.55f && sloppy[i] < 0.75f )
            {
                // sand-rock
                InterpolateColour( out, 0.75f, SAND, ROCK );
                InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 0.75f, SAND, ROCK );
            }
            if ( sloppy[i] >= 0.70 )
            {
                // rock-rock
                InterpolateColour( out, 1.0, ROCK, ROCK );
                InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 1.0f, ROCK, ROCK );
            }
        }
        else if ( height[i] < matHeight[1] )
        {
            if ( sloppy[i] < 0.15 )
            {
                // grass-snow
                InterpolateColour( out, 0.25f, GRASS, SNOW );
                InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 0.25f, GRASS, SNOW );
            }
            if ( sloppy[i] >= 0.10 && sloppy[i] < 0.45 )
            {
                // snow-sand
                InterpolateColour( out, 0.65f, SNOW, SAND );
                InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 0.65f, SNOW, SAND );
            }
            if ( sloppy[i] >= 0.25f && sloppy[i] < 0.65f )
            {
                // snow-rock
                InterpolateColour( out, 0.5, SNOW, ROCK );
                InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 0.5f, SNOW, ROCK );
            }
            if ( sloppy[i] >= 0.50f && sloppy[i] < 0.75f )
            {
                // snow-rock
                InterpolateColour( out, 0.75f, SNOW, ROCK );
                InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 0.75f, SNOW, ROCK );
            }
            if ( sloppy[i] >= 0.70 )
             {
                // rock-rock
                InterpolateColour( out, 1.0f, ROCK, ROCK );
                InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 1.0f, ROCK, ROCK );
            }
        }
        else
        {
            if ( sloppy[i] < 0.15f )
            {
                // snow-snow
                InterpolateColour( out, 1.0f, SNOW, SNOW );
                InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 1.0f, 0, 0 );
            }
            if ( sloppy[i] >= 0.1f && sloppy[i] < 0.45f )
            {
                // snow-sand
                InterpolateColour( out, 0.35f, SNOW, SAND );
                InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 0.35f, 0, 1 );
            }
            if ( sloppy[i] >= 0.25f && sloppy[i] < 0.65f )
            {
                // snow-rock
                InterpolateColour( out, 0.5f, SNOW, ROCK );
                InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 0.5f, 0, 3 );
            }
            if ( sloppy[i] >= 0.5f && sloppy[i] < 0.75f )
            {
                // snow-rock
                InterpolateColour( out, 0.75f, SNOW, ROCK );
                InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 0.75f, 0, 3 );
            }
            if ( sloppy[i] >= 0.7f )
            {
                // rock-rock
                InterpolateColour( out, 1.0f, ROCK, ROCK );
                InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 1.0f, 3, 3 );
            }
        }
     }
 }

//-----------------------------------------------------------------------
void MapSplatter::InterpolateColour(ColourValue& out, const Real percentaje, 
                                const int index1, const int index2)
{
    if (percentaje < 1.0)
    {   
        const Real tmp = 1 - percentaje;
        out.r = ( out.r + ( percentaje * matColor[index1].r + tmp * matColor[index2].r ) ) * 0.5f;
        out.g = ( out.g + ( percentaje * matColor[index1].g + tmp * matColor[index2].g ) ) * 0.5f;
        out.b = ( out.b + ( percentaje * matColor[index1].b + tmp * matColor[index2].b ) ) * 0.5f;
    }
    else if (index1 == index2)
    {
        out.r = matColor[index1].r;
        out.g = matColor[index1].g;
        out.b = matColor[index1].b;
    }
}

//-----------------------------------------------------------------------
void MapSplatter::InterpolateAlpha(Real& alpha1, Real& alpha2, Real& alpha3, 
                                 Real& alpha4, const Real percentaje, 
                                const int index1, const int index2)
{
    if ( index1 == index2 )
     {
        if ( index1 == 0 )
            alpha1 += 1;
        else if ( index1 == 1 )
            alpha2 += 1;
        else if ( index1 == 2 )
            alpha3 += 1;
        else
            alpha4 += 1;
    }
    else
    {
        if ( index2 == 0 )
            alpha1 += percentaje;
        else if ( index2 == 1 )
            alpha2 += percentaje;
        else if ( index2 == 2 )
            alpha3 += percentaje;
        else
            alpha4 += percentaje;

        if ( index1 == 0 )
            alpha1 += 1 - percentaje;
        else if ( index1 == 1 )
            alpha2 += 1 - percentaje;
        else if ( index1 == 2 )
            alpha3 += 1 - percentaje;
        else
            alpha4 += 1 - percentaje;
    }
    //snow  = 0
    //sand  = 1
    //grass = 2
    //rock  = 3
    const Real oneonfive = 0.2f;
    alpha1 *= ( 4 * oneonfive);
    alpha2 *= ( 3 * oneonfive);
    alpha3 *= ( 4 * oneonfive);
    alpha4 *= ( 2 * oneonfive);
    // Normalize
    const Real total = 1 / (( alpha1 + alpha2 + alpha3 + alpha4 ) * 2);
    alpha1 = alpha1 * total;
    alpha2 = alpha2 * total;
    alpha3 = alpha3 * total;
    alpha4 = alpha4 * total;
}
}//namespace Ogre
