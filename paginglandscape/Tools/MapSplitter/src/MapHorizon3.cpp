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
MapHorizon3.cpp
@brief
Utility that pre-calculate horizon mapping for real-time
light mapping of terrain
*/

#include "MapUtil.h"
#include "MapHorizon3.h"
#include "MapBlurrer.h"



namespace Ogre
{
	//-----------------------------------------------------------------------
	MapHorizon3::MapHorizon3()
    {   
        mHorizonImage = 0;
        mLightImage = 0;
        mPosHorizonImage = 0;
        mNegHorizonImage = 0;
	}
	//-----------------------------------------------------------------------
	MapHorizon3::~MapHorizon3()
    {
        if (mHorizonImage)
            delete mHorizonImage;  

        if (mLightImage)
            delete mLightImage;   
         
        if (mPosHorizonImage)
            delete mPosHorizonImage;
          
        if (mNegHorizonImage)
            delete mNegHorizonImage;
	}
	//-----------------------------------------------------------------------
	Image *MapHorizon3::getHorizonMap()
    {
        return mHorizonImage;
	}
	//-----------------------------------------------------------------------
	Image *MapHorizon3::getLightMap()
    {
        return mLightImage;
	}
	//-----------------------------------------------------------------------
	Image *MapHorizon3::getPositiveHorizonMap()
    {
        return mPosHorizonImage;
	}
	//-----------------------------------------------------------------------
	Image *MapHorizon3::getNegativeHorizonMap()
    {
        return mNegHorizonImage;
	}
	//-----------------------------------------------------------------------
	void MapHorizon3::calcLightMap()
    {
        const uint W = MapUtil::getSingleton().getMapWidth ();
        const uint H  = MapUtil::getSingleton().getMapHeight ();

	    // Create the base image
        //uchar *BaseData = new uchar[ W * H ];
		uchar *BaseData = OGRE_ALLOC_T(uchar, W * H, MEMCATEGORY_GENERAL);

        //        mSun = MapUtil::getSingleton().Sun;
        //        mAmb = MapUtil::getSingleton().Amb;
        //        mDiff = MapUtil::getSingleton().Diff;
        //        mBlur = MapUtil::getSingleton().Blur;

        //double rotationAmount = 2 * Math::PI / 16.0f;
        //rotationAmount = 4 * rotationAmount;
        //Real LightAngle = rotationAmount;
        //    Vector3 LightDir (1.0f,
        //                      Math::Cos (rotationAmount),
        //	                  0.0f);

        //(float)Math::Sin(0.7f * 300.0f) * 1.55f;
        //1.531; //all shadow
        //0.49; //all shadow

        Real LightAngle = 0.49f;
        Vector3 LightDir(0,
	                    (float) - Math::Cos(LightAngle),
	                    (float) Math::Sin(LightAngle));
        
        //assert(LightDir.y > 0.0f);
      
        LightDir.normalise ();
 
        uchar *HorizonAngle;
        if (LightAngle >= 0) 
        {
	        LightAngle = LightAngle;
            HorizonAngle = mPosHorizonImage->getData();
	    } 
        else 
        {
	        LightAngle = - LightAngle;
            HorizonAngle = mNegHorizonImage->getData();
	    }
	

		uint curr_row = 0;
        const uchar BScale = 255;
        for(uint nZ = 0; nZ < H ; nZ++) 
        {
            DEBUG_PROGRESS_OUTPUT(nZ, ".")
            for(uint nX = 0; nX < W; nX++)
            {            
                const uint nVert = curr_row + nX;   
                const Real hAngle = HorizonAngle[nVert] / 255;
                Real intensity;
                if (hAngle < LightAngle) 
                {           
                    intensity =  1 - (LightAngle - hAngle);
                    if (intensity > 0.0f) 
                    {                       
                        intensity = intensity;
                        
					}
                    else
                    {
                        // totally in shadow    
                       intensity = 0.0f;  
                    }
                }
                else             
                {
                    // Vertex is lighted
                    intensity = 1.0f;
                 }                 
                BaseData[nVert] = static_cast <uchar> (intensity * BScale);
                //curr_image_pos += 1;
            }
            curr_row += W;
        }  
        mLightImage = new Image();        
        mLightImage->loadDynamicImage (BaseData, 
            static_cast <size_t> (W), 
            static_cast <size_t> (H), 1, PF_L8, true);
	}
	//-----------------------------------------------------------------------
	void MapHorizon3::calcHorizonMap()
    {
        mHeightMapData = MapUtil::getSingleton().getHeightData ();
        const Real *  const ogre_restrict heightmap = mHeightMapData;

        const uint W = MapUtil::getSingleton().getMapWidth ();
        const uint H  = MapUtil::getSingleton().getMapHeight ();

        size_t size = W*H;

		//uchar *shadowMapDatapos = new uchar[size];
		uchar *shadowMapDatapos = OGRE_ALLOC_T(uchar, size, MEMCATEGORY_GENERAL);
        memset (shadowMapDatapos, 255, size * sizeof (uchar));

		//uchar *shadowMapDataneg = new uchar[size];
		uchar *shadowMapDataneg = OGRE_ALLOC_T(uchar, size, MEMCATEGORY_GENERAL);
        memset (shadowMapDataneg , 255, size * sizeof (uchar));

        size *= 3;
		//uchar *horizonmap2d = new uchar[size];
		uchar *horizonmap2d = OGRE_ALLOC_T(uchar, size, MEMCATEGORY_GENERAL);
        memset (horizonmap2d, 255, size * sizeof (uchar));

        DEBUG_OUTPUT ( "Horizon Map Calc ");
        const uchar BScale = 255;

#ifndef _testinghrizo
        //const Real Zscale = 1.0 / H;
        const Real Zscale = 1.0;// / H;
		const Real Yscale = 0.1666;// / H;
#endif //_testinghrizo

        const uint lastColpos = (H - 1)*W;

        const Real Epsilon = 1e-08;//
        const Real angleUcharEpsilon = 1.0f / 255;//1e-08

        uchar * const ogre_restrict mapHeights = new uchar [H];

        for(uint nX = 0; nX < W; nX++)
        {

            const uint originX = nX;

            DEBUG_PROGRESS_OUTPUT(nX, ".")
            uint pos = 0;

#ifndef _testinghrizo
            uchar maxHeightCol = 0;
            for(uint nZ = 0; nZ < H ; nZ++) 
            {
                mapHeights[nZ] = heightmap[originX + pos] * BScale;
                maxHeightCol = std::max (maxHeightCol, mapHeights[nZ]);
                pos += W;
			}
			const uchar * const heightMapCol = mapHeights;
            pos = 0;
            Real maxAngle;
            uint curr_pos;
            uint curr_nZ;
            for(uint nZ = 0; nZ < H ; nZ++) 
            {
                const uint originPos = originX + pos;
                const uint originZ = nZ;
                const Real origin = heightMapCol[ originZ ];
                maxAngle = 0;
                curr_pos = pos;
                for(curr_nZ = originZ; curr_nZ > 0 ; curr_nZ--) 
                {
                    // Height of the current sample point:
                    const uchar curH = heightMapCol[ curr_nZ ];

                    // If the current sample point is lower than the ray origin, 
                    // it can't affect our horizon, so skip it. 
                    if (curH > origin) 
                    {
                        const uchar diffheight = curH - origin;
                        const uint lengthZ = (originZ - curr_nZ) * Yscale;
                        
                        // Calculate the elevation angle of the current sample point:
                        //Vector3 flat  (0, pos, 0);
                        //flat.normalise ();
                        //Vector3 elev (0,  pos,  diffheight);
                        //elev.normalise ();
                        //const Real ShadowAngle = 1.0f - flat.dotProduct (elev);
                        // that simplify itself nicely and exactly (perhaps even more) in
                        
                        // Output: [0=horizontal, 1=vertical].
                        const Real SunAngleShadow = 1.0f - lengthZ / Math::Sqrt(lengthZ*lengthZ + diffheight*diffheight);
                       
                        //assert (Math::Abs(SunAngleShadow - ShadowAngle) < Epsilon);

                        maxAngle = std::max (SunAngleShadow, maxAngle);

                        // if it's the highest point of this colon, stop there. 
						if (curH == maxHeightCol  ||
							lengthZ  > static_cast <uint> (BScale)) 
                            break;
                    }
                    curr_pos -= W;
                }
                if (maxAngle - angleUcharEpsilon > 0.0f)
                {
					const uchar elevationAngle = static_cast <uchar>(
						BScale *(static_cast <Real> (1.0f) - 
								std::min(static_cast <Real> (1.0f),static_cast <Real> (maxAngle*1.5f))));
                    horizonmap2d[originPos*3 + 1] = elevationAngle;
                    shadowMapDatapos[ originPos ] =  elevationAngle;
                }
                maxAngle = 0;
                curr_pos = pos;
                for(curr_nZ = originZ; curr_nZ < H - 1 ; curr_nZ++) 
                {
                    // Height of the current sample point:
                    const uchar curH = heightMapCol[ curr_nZ ];

                    // If the current sample point is lower than the ray origin, 
                    // it can't affect our horizon, so skip it. 
                    if (curH > origin) 
                    {
                        const uchar diffheight = curH - origin;
                        const uint lengthZ = (curr_nZ - originZ) * Yscale;
                        
                        // Calculate the elevation angle of the current sample point:
                        //Vector3 flat  (0, pos, 0);
                        //flat.normalise ();
                        //Vector3 elev (0,  pos,  diffheight);
                        //elev.normalise ();
                        // Output: [0=horizontal, 1=vertical].
                        //const Real ShadowAngle = 1.0f - flat.dotProduct (elev);
                        // that simplify itself nicely and exactly in

                        // Output: [0=horizontal, 1=vertical].
                        const Real SunAngleShadow = 1.0f - lengthZ / Math::Sqrt(lengthZ*lengthZ + diffheight*diffheight);
                       
                        maxAngle = std::max (SunAngleShadow, maxAngle);

                        // if it's the highest point of this colon, stop there. 
						if (curH == maxHeightCol  ||
							lengthZ  > static_cast <uint> (BScale)) 
                            break;
                    }
                    curr_pos += W;
                }
                if (maxAngle - angleUcharEpsilon > 0.0f)
                {
                    const uchar elevationAngle = static_cast <uchar>(
						BScale *(static_cast <Real> (1.0f) - 
								std::min(static_cast <Real> (1.0f), 
										 static_cast <Real> (maxAngle*1.5f))));
                    horizonmap2d[originPos*3 + 0] = elevationAngle;
                    shadowMapDataneg[ originPos ] =  elevationAngle;
                }
           

#else //_test
                Real LastElevation = 0;
                Real LastElevationinv = 0;

                uint lastelevation_pos = 0;
                uint lastelevationinv_pos = H - 1;

                for(uint nZ = 0; nZ < H ; nZ++) 
                {
                    // positive Z axis shadow
                    {
                        if (LastElevation - Epsilon > 0.0f)
                            LastElevation -= Yscale;
                        else
                            LastElevation = 0.0f;

                        const uint nVert = originX + pos;//nZ * W;
                        const Real height = heightmap[nVert]*256;
                        if ( LastElevation - Epsilon > 0.0f
                            && height - LastElevation - Epsilon < 0.0f)
                        {   
                            const Real diffheight = (LastElevation - height);
                            const Real lengthZ = (nZ - lastelevation_pos) * Zscale;
                            
                            // Calculate the elevation angle of the current sample point:
                            //Vector3 flat  (0, pos, 0);
                            //flat.normalise ();
                            //Vector3 elev (0,  pos,  diffheight);
                            //elev.normalise ();
                            // Output: [0=horizontal, 1=vertical].
                            //const Real ShadowAngle = 1.0f - flat.dotProduct (elev);
                            
                            // that simplify itself exactly in
                            const Real SunAngleShadow = 1.0f - lengthZ / Math::Sqrt(lengthZ*lengthZ + diffheight*diffheight);



                            //const Real SunAngleShadow = diffheight / pos;
                            //const Real SunAngleShadow = 1 - Math::Cos (Math::ATan (diffheight/pos));
                            if (SunAngleShadow - Epsilon <  0.0f)
                            {
                                LastElevation = height; 
                                lastelevation_pos = nZ;
                            }   
                            else
                            {
                                //store it
                                //const uchar Hangle = 255 - static_cast <uchar>(SunAngleShadow * SunAngleShadow * BScale); 
                                //const uchar Hangle = 255 - static_cast <uchar>(std::max(SunAngleShadow, 1.0f) * BScale); 
                                const uchar Hangle = static_cast <uchar>(SunAngleShadow * BScale); 
                                horizonmap2d[nVert*3 + 0] = 255 - Hangle;
                                shadowMapDatapos[nVert] =  255 - Hangle;
                                //shadowMapDatapos[nVert] =  std::max (0, shadowMapDatapos[nVert] - Hangle);
    //                            const uchar HangleBlur = static_cast <uchar>(SunAngleShadow * 0.5f * BScale);
    //                            if (nX < W)
    //                                shadowMapDatapos[ nVert + 1 ] =  std::max (0, shadowMapDatapos[ nVert + 1 ] - HangleBlur);
    //                            if (nX > 0)
    //                                shadowMapDatapos[ nVert - 1 ] =  std::max (0, shadowMapDatapos[ nVert - 1 ] - HangleBlur);
                            }
                        }
                        else
                        {
                            LastElevation = height;
                            lastelevation_pos = nZ;
                        }
                    }

                    // negative Z axis shadow
                    {
                        
                        if (LastElevationinv - Epsilon > 0.0f)
                            LastElevationinv -= Yscale;
                        else
                            LastElevationinv = 0.0f;

                        const uint nVert = nX + lastColpos - pos;
                        const Real height = heightmap[nVert]*256;
                        if (LastElevationinv - Epsilon > 0.0f
                            && height - LastElevationinv - Epsilon < 0.0f)
                        {   
                            const Real diffheight = (LastElevationinv - height);
                            const Real lengthZ = (lastelevationinv_pos - (H - nZ)) * Zscale;
                            const Real SunAngleShadow = 1 - lengthZ / Math::Sqrt(lengthZ*lengthZ + diffheight*diffheight);
                            
                            if (SunAngleShadow - Epsilon <  0.0f)
                            {
                                LastElevationinv = height;
                                lastelevationinv_pos = H - nZ;
                            }
                            else
                            {
                                //store it
                                const uchar Hangle = static_cast <uchar>(SunAngleShadow * BScale);
                                horizonmap2d[nVert*3 + 1] = 255 - Hangle;
                                shadowMapDataneg[nVert] =  255 - Hangle;
                                //shadowMapDataneg[nVert] =  std::max (0, shadowMapDataneg[nVert] - Hangle);
    //                            const uchar HangleBlur = static_cast <uchar>(SunAngleShadow * 0.5f * BScale);
    //                            if (nX < W)
    //                                shadowMapDataneg[ nVert + 1 ] =  std::max (0, shadowMapDataneg[nVert+1] - HangleBlur);
    //                            if (nX > 0)
    //                                shadowMapDataneg[ nVert - 1 ] =  std::max (0, shadowMapDataneg[nVert - 1] - HangleBlur);
                            }
                        }
                        else
                        {
                            LastElevationinv = height;
                            lastelevationinv_pos = H - nZ;
                        }
                    }
#endif //_test 
                    pos += W;
                } // for nZ
            }// for nX

			delete [] mapHeights;

			mHorizonImage = new Image();
			mHorizonImage->loadDynamicImage (horizonmap2d, static_cast <size_t> (W), 
				static_cast <size_t> (H), 1, PF_R8G8B8, true);

			mPosHorizonImage = new Image();
			mPosHorizonImage->loadDynamicImage (shadowMapDataneg, static_cast <size_t> (W), 
				static_cast <size_t> (H), 1, PF_L8, true);

			mNegHorizonImage = new Image();
			mNegHorizonImage->loadDynamicImage (shadowMapDatapos, static_cast <size_t> (W), 
				static_cast <size_t> (H), 1, PF_L8, true);

	}
}//ogre namespace
