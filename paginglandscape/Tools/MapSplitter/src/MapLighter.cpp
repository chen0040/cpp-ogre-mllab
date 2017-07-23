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
MapLighter.cpp
@brief
Utility that pre-calculate light map.
*/
#include "MapUtil.h"
#include "MapLighter.h"
#include "MapBlurrer.h"
#include "OgrePagingLandScapeOptions.h"

#include <iostream>

namespace Ogre
{
//----------------------------------------------------------------------
MapLighter::MapLighter()
{
    reset();
}
//----------------------------------------------------------------------
MapLighter::~MapLighter()
{
   
}
//----------------------------------------------------------------------
void MapLighter::reset()
{
    mAlreadyComputed = false;
}
//----------------------------------------------------------------------
Image *MapLighter::getShadowMap(const Vector3 &sun, float amb, float diff, 
                                int Blur)
{
    if (mAlreadyComputed)
        return &mShadowMap;

    CalcMapShadow (sun);
    CalcMapLight (sun, amb, diff, Blur);
    mAlreadyComputed = true;

    return &mShadowMap;
}
//----------------------------------------------------------------------
Image *MapLighter::getLightMap(const Vector3 &sun, float amb, float diff, 
                               int Blur)
{
    if (mAlreadyComputed)
        return &mLightMap;

    CalcMapShadow (sun);
    CalcMapLight (sun, amb, diff, Blur);

    mAlreadyComputed = true;
    return &mLightMap;
}



//----------------------------------------------------------------------
void MapLighter::CalcMapShadow (const Vector3 &sun)
{
    const uint  height = MapUtil::getSingleton().getMapHeight ();
    const uint  width = MapUtil::getSingleton().getMapWidth ();
    Real * const ogre_restrict heightMap = MapUtil::getSingleton().getHeightData ();


    /* Allocate space for the shadow map */
    const uint size = width * height;
    //uchar * ogre_restrict ShadowMap = new uchar[size];
	uchar * ogre_restrict ShadowMap = OGRE_ALLOC_T(uchar, size, MEMCATEGORY_GENERAL);

    memset (ShadowMap, 0, size * sizeof (uchar));

    /* Make sure the light source is normalised */
    Vector3 LightDirection = sun.normalisedCopy();

    //LightDirection.x /= MapUtil::getSingleton().scale.x;
    //LightDirection.y /= MapUtil::getSingleton().scale.y;
    //LightDirection.z /= MapUtil::getSingleton().scale.z;

    //LightDirection.normalise();

    if (LightDirection.y != 0.0f ) 
    {  
       DEBUG_OUTPUT ( "Shadow Map Calc  ");
        
        const bool xbelowZ = fabs(LightDirection.x) < fabs(LightDirection.z);
        
        const bool xNegative = LightDirection.x < 0; 
        const float baseindex_zx = (xNegative)? - LightDirection.z / LightDirection.x : LightDirection.z / LightDirection.x ;
        const float baseindex_yx = (xNegative)? - LightDirection.y / LightDirection.x : LightDirection.y / LightDirection.x;
        const int index_xx = (xNegative)? - 1 : 1;
       
        const bool zNegative = LightDirection.z < 0;
        const float baseindex_xz = (zNegative)? - LightDirection.x / LightDirection.z : LightDirection.x / LightDirection.z;
        const float baseindex_yz = (zNegative)? - LightDirection.y / LightDirection.z : LightDirection.y / LightDirection.z;
        const int index_zz = (zNegative)? - 1 : 1;
         
        /* For each heightmap location */ 
        uint index_pixel = 0;
        for (uint j = 0; j < height; j++) 
         { 
            DEBUG_PROGRESS_OUTPUT(j, ".")
            for (uint i = 0; i < width; i++) 
            {
                /* If already in shadow no need to compute again ?
                 what if we store precise height at which it is not shadowed ?*/
                if (ShadowMap[index_pixel] == 0)
                {
                    /* a line passing starting from heightmap point 
                        and following light direction*/
                    Real terrain_height = heightMap[ index_pixel ];
                        
                    if (xbelowZ)
                    { 
                        int z = j + index_zz;
                        float x = i + baseindex_xz;
                        terrain_height += baseindex_yz;
                        uint zmap = ((uint)z);
                        uint xmap = ((uint)x);
                        while  (terrain_height >= 0.0f &&
                                xmap < width &&
                                zmap < height)
                        {        
                            const uint heightpos = xmap + zmap*width;
                            if (heightMap[heightpos] <= terrain_height)
                                 ShadowMap[heightpos] = 255; 
                            x += baseindex_xz;
                            z += index_zz;
                            terrain_height += baseindex_yz;
                            zmap = ((uint)z);
                            xmap = ((uint)x);
                         }
                    }
                    else 
                    {
                        float z = j + baseindex_zx;
                        int x = i + index_xx;
                        terrain_height += baseindex_yx;
                        uint zmap = ((uint)z);
                        uint xmap = ((uint)x);
                        while (terrain_height >= 0.0f &&
                                xmap < width &&
                                zmap < height)
                        {
                            const uint heightpos = xmap + zmap*width;
                            if (heightMap[heightpos] <= terrain_height)
                                 ShadowMap[heightpos] = 255; 
                            x += index_xx; 
                            z += baseindex_zx;
                            terrain_height += baseindex_yx;
                            zmap = ((uint)z);
                            xmap = ((uint)x);
                        }
                     }
                }
                index_pixel++;
            }
        }
    }
    
    // Assign the color texture
    mShadowMap.loadDynamicImage  (ShadowMap, 
                                static_cast <size_t> (width), 
                                static_cast <size_t> (height), 1, 
                                PF_L8, true);

    DEBUG_END_SECTION_OUTPUT ("\n");
}


//----------------------------------------------------------------------
void MapLighter::CalcMapLight(const Vector3 &sun, float amb, float diff, 
                              int Blur)
{
    MapUtil * const mapUtil = MapUtil::getSingletonPtr ();
    uchar * ogre_restrict ShadowMap = mShadowMap.getData ();
    assert (ShadowMap);
    const uint  height = mapUtil->getMapHeight ();
    const uint  width = mapUtil->getMapWidth ();

    // Create the base image
    const uint size = width * height;
	//uchar * ogre_restrict LightMapData = new uchar[size];
	uchar * ogre_restrict LightMapData = OGRE_ALLOC_T(uchar, size, MEMCATEGORY_GENERAL);
    memset (LightMapData, 0, size * sizeof (uchar));   
    
    /* Make sure the light source is normalised */
    Vector3 LightDirection (sun.normalisedCopy());
    
    //LightDirection.x /= MapUtil::getSingleton().scale.x;
    //LightDirection.y /= MapUtil::getSingleton().scale.y;
    //LightDirection.z /= MapUtil::getSingleton().scale.z;
    
    if (LightDirection.y != 0.0f ) 
    {  
        DEBUG_OUTPUT ( "light Map Calc  ");
        const uchar pixelfactor = 255;
        const Real scaleShadow = 1.0f / 255;
        uint index_pixel = 0;
        /* For each point */
        for (uint j = 0; j < height; ++j) 
         {
            /* Show progress */
            DEBUG_PROGRESS_OUTPUT(j, ".")
            for (uint i = 0; i < width; ++i) 
            {
                /* Calculate illumination model (ambient plus diffuse) */
                const float s = 1.0f - scaleShadow * ShadowMap[index_pixel] * 0.25f;
                
                /* Get the dot product with the light source direction */
                const Vector3 normal = mapUtil->getNormalAt (i, j);
                float d = LightDirection.dotProduct (normal) * 0.5f + 0.5f;
                float l;
                if (d < 0.0f)
                {
                    l = amb;
                }
                else
                {
                    l = amb + s * d * diff;
                    if (l < 0.0f)
                        l = 0.0f;
                    else 
                        if (l > 1.0f)
                        l = 1.0f;
                }
                /* Save in light map */
                LightMapData[index_pixel] = static_cast <uchar> (l * pixelfactor);
                
                index_pixel++;
            }
         }
    }

    // Assign the color texture
    mLightMap.loadDynamicImage (LightMapData, 
        static_cast <size_t> (width), 
        static_cast <size_t> (height), 
        1, 
        PF_L8, true);

    /* Blur the light map */  
    if (Blur > 0)
    {
        MapBlurrer Blurrer;
        Blurrer.gaussianBlur(&mLightMap, Blur);
    } 
    DEBUG_END_SECTION_OUTPUT ("\n");

}

void fastblurredlight()
{
    ///////////////
    /* Variables */
    ///////////////

    // Tells if there is a shadow.
    bool Shadow;
    // Holds the coordinates for the shadow greyscale.
    int ShadowOriginX;
    int ShadowY;
    // Hold the values for the rays' height and the terrain-maps' height.
    float RayY;
    // Coordinate positions variables.
    int RayOriginX, MapX, z, MapY;
    // The angle in which the rays intersect the x-axis.
    int Angle = 45;
    // The max height on the terrain-map.
    int MaxMapHeight = 255;
    // The max shadow brightness and.
    int MaxShadowBrightness = 255;
    // The size of the terrain
    int MapSize = 128;
    /* Pre-calculations */
    // Get the tan value for the angle that is used.
    float TanAngle = float( tan(Angle*3.14159/180) );
    // Calculate the maxHeightExtension
    int MaxHeightExtension = int(MaxMapHeight/TanAngle);

    uchar **HeightMap = new uchar* [MapSize];   
    for (z = 0; z < MapSize; z++)
    {
        HeightMap [z] = new uchar [MapSize];
    }

    // Set all points on the light map MaxShadowBrightness
    uchar ** LightMap = new uchar* [MapSize]; 

    //memset (LightMap, MaxShadowBrightness, MapSize *MapSize);
    for (z = 0; z < MapSize; z++)
    {
        LightMap [z] = new uchar [MapSize];
        for ( MapX = 0; MapX < MapSize; MapX ++)
        {
            LightMap[MapX][z] = MaxShadowBrightness;
        }
    }

    /////////////////////////
    /* Shadow Calculations */
    /////////////////////////

    /* Ray Lighting */

    // Loop through the z-axis.
    for ( z = 0; z < MapSize-1; z++ )
    {

        // Loop through the x-axis.
        for ( RayOriginX = MapSize-1; RayOriginX > -(MaxHeightExtension); RayOriginX-- )
        {

            // Reset the shadow values.
            ShadowOriginX = 0;
            Shadow = false;

            // If the shadow's maximum width exceeds the mapsize set MapX to mapsize.
            if (RayOriginX + MaxHeightExtension +1 > MapSize)
            {
                MapX = MapSize;
            }
            // Else set MapX the shadow's maximum width.
            else
            {
                MapX = RayOriginX + MaxHeightExtension +1;
            }

            // Loop through the ray from the shadows maximum width until it
            // reaches the rays' origin.
            while( MapX > RayOriginX && MapX > 0)
            {

                // Get the height values.
                RayY = float( MapX-RayOriginX * TanAngle );
                MapY = HeightMap[MapX][z];

                // If the MapY intersect the Ray there will be a shadow.
                if ( RayY <= MapY)
                {

                    // Set the shadows' origin X coordinate.
                    ShadowOriginX = MapX;

                    // There will be a shadow.
                    Shadow = true;

                }
                // Else if MapY is lower than RayY and there is a shadow.
                else if ( Shadow )
                {

                    // Get the shadow greyscales height.
                    ShadowY = HeightMap[ShadowOriginX][z];

                    // Calculate and set the brightness.
                    LightMap[MapX][z] = (unsigned char)( 255 * (float(ShadowOriginX-MapX)/
                                        (ShadowOriginX-RayOriginX) + MapY/(float)ShadowY) );

                }
                MapX--;
            }
        }
    }

    /* Blurring */

    // Loop through the z-axis.
    for ( z = 0; z < MapSize-1; z++)
    {

        // Loop through the x-axis.
        for ( RayOriginX = 0; RayOriginX < MapSize-1; RayOriginX++)
        {

            // If the point isn't already lighted.
            if (LightMap[RayOriginX][z] != MaxShadowBrightness)
            {

                // Get the mean value of vertex and set the brightness.

                LightMap[RayOriginX][z] = ( LightMap[RayOriginX-1][z+1]  +
                LightMap[RayOriginX][z+1] + LightMap[RayOriginX-1][z]    +
                LightMap[RayOriginX][z]   + LightMap[RayOriginX-1][z-1]  +
                LightMap[RayOriginX][z-1] ) /6;

            }
        }
    }
}

}//namespace Ogre
