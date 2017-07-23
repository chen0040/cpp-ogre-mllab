#include "MapUtil.h"
#include "MapNormaler.h"


namespace Ogre
{

//----------------------------------------------------------------------
MapNormaler::MapNormaler()
{
    mAlreadyComputed = false;   
    Normals = 0;
}
//----------------------------------------------------------------------
MapNormaler::~MapNormaler()
{
    delete[] Normals;
}

//----------------------------------------------------------------------
Vector3 *MapNormaler::getNormalData()
{
    return Normals;
}
//----------------------------------------------------------------------
Image *MapNormaler::getNormalMap()
{ 
    if (mAlreadyComputed == false)
    {
        CalcNormalMap();
        mAlreadyComputed = true;
    }
    return &NormalMap;
}
//----------------------------------------------------------------------
void MapNormaler::reset()
{
    mAlreadyComputed = false;    
    delete [] Normals;
    Normals = 0;
}

//----------------------------------------------------------------------
const Vector3 MapNormaler::getNormalAt (const uint x, const uint z)
{      
    if (mAlreadyComputed == false)
    {
        CalcNormalMap();
        mAlreadyComputed = true;
    }
    return Normals[( z * mWidth) + x];
}

	
#ifndef _TESTNORLM 
//----------------------------------------------------------------------
void MapNormaler::CalcNormalMap()
{
	MapUtil * const mapUtil = MapUtil::getSingletonPtr();
	
    const int  height = mapUtil->getMapHeight ();
    const int  width = mapUtil->getMapWidth ();

    mHeight = height;
    mWidth = width;

    const int size = height * width;

	//uchar * ogre_restrict NormalData = new uchar[size * 3];
	uchar * ogre_restrict NormalData = OGRE_ALLOC_T(uchar, size * 3, MEMCATEGORY_GENERAL);
    Normals = new Vector3 [size];

    DEBUG_OUTPUT ( "normal Map Calc  ");

    Vector3 * const ogre_restrict normal = Normals;
    const Real * const ogre_restrict vert = mapUtil->getHeightData ();
    
    const Real invStretch = Real(0.5) / mapUtil->mTextureStretchFactor;
    const Real invStretchSQ = invStretch * invStretch;

    const Real ucharMultilpier = 127.5f;
	#define MakeUchar(X) (static_cast <uchar> ((X + 1.0f) * ucharMultilpier))
    

    uint pixel_pos = 0;
    int vert_index = 0;
    int normal_index = 0;
    
    for (int k = 0; k < height; k++)
    {
      DEBUG_PROGRESS_OUTPUT(k, ".")
      const int i = k;
      for (int p = 0; p < width; p++)
      {
			const int j = p;
			const int currVertIdx = vert_index;

			Real x = 0.0f;
			Real z = 0.0f;

			//Above
			if (i != 0)
			{
				if (j != 0)
				{
					x += -vert[currVertIdx-width-1];
					z += -vert[currVertIdx-width-1];
				}
				else
				{
					x += -vert[currVertIdx-width];
					z += -vert[currVertIdx-width];
				}

				x += -vert[currVertIdx-width]*2.0f;

				if (j != width-1)
				{
					x += -vert[currVertIdx-width+1];
					z += vert[currVertIdx-width+1];
				}
				else
				{
					x += -vert[currVertIdx-width];
					z += vert[currVertIdx-width];
				}
			}
			else
			{
				x += -vert[currVertIdx];
				x += -vert[currVertIdx] * 2.0f;
				x += -vert[currVertIdx];

				z += -vert[currVertIdx];
				z += vert[currVertIdx];
			}

			//Current line
			if (j != 0)
				z += -vert[currVertIdx-1] * 2.0f;
			else
				z += -vert[currVertIdx] * 2.0f;

			if (j != width-1)
				z += vert[currVertIdx + 1] * 2.0f;
			else
				z += vert[currVertIdx] * 2.0f;

			//Below
			if (i != height-1)
			{
				if (j != 0)
				{
				   x += vert[currVertIdx+width-1];
				   z += -vert[currVertIdx+width-1];
				}
				else
				{
				   x += vert[currVertIdx+width];
				   z += -vert[currVertIdx+width];
				}

				x += vert[currVertIdx+width] * 2.0f;

				if (j != width-1)
				{
				   x += vert[currVertIdx+width+1];
				   z += vert[currVertIdx+width+1];
				}
				else
				{
				   x += vert[currVertIdx+width];
				   z += vert[currVertIdx+width];
				}
			}
			else
			{
				x += vert[currVertIdx];
				x += vert[currVertIdx] * 2.0f; 
				x += vert[currVertIdx];

				z += -vert[currVertIdx];
				z += vert[currVertIdx];
			}
			//Normalize
			const Real tmpf = Real(1.0) / Math::Sqrt(x*x  + z*z + invStretchSQ);

			normal[normal_index].x = x*tmpf;
			normal[normal_index].z = z*tmpf;
			
			normal[normal_index].y = invStretch*tmpf;
			
			//assert ((Real (1.0) - normal[normal_index].x - normal[normal_index].z) == invStretch*tmpf);
			

			NormalData[pixel_pos++] = MakeUchar (normal[normal_index].x);
			NormalData[pixel_pos++] = MakeUchar (normal[normal_index].z);// Beware of the swizzle
			
			NormalData[pixel_pos++] = MakeUchar (normal[normal_index].y);// Beware of the swizzle
			
			vert_index ++;
			normal_index ++;

         }
      }

    NormalMap.loadDynamicImage(NormalData, static_cast <size_t> (width),
                                static_cast <size_t> (height), 1, PF_R8G8B8, true);
    DEBUG_END_SECTION_OUTPUT ("\n");
}
#else //_TESTNORLM

//----------------------------------------------------------------------
void MapNormaler::CalcNormalMap()
{
	MapUtil * const mapUtil = MapUtil::getSingletonPtr();
	
    const uint  height = mapUtil->getMapHeight ();
    const uint  width = mapUtil->getMapWidth ();

    mHeight = height;
    mWidth = width;

    const int size = height * width;

	//uchar * ogre_restrict NormalData = new uchar[size * 3];
	uchar * ogre_restrict NormalData = = OGRE_ALLOC_T(uchar, size * 3, MEMCATEGORY_GENERAL);
    Normals = new Vector3 [size];

    DEBUG_OUTPUT ( "normal Map Calc ");

    Vector3 * const ogre_restrict normal = Normals;
    
    const Real ucharMultilpier = 127.5f;
	#define MakeUchar(X) (static_cast <uchar> ((X + 1.0f) * ucharMultilpier))
    
    DEBUG_OUTPUT ( "normal Map Calc ");

    // First General method : (9 adds and 6 muls + a normalization)
    //        *---v3--*
    //        |   |   |
    //        |   |   |
    //        v1--X--v2
    //        |   |   |
    //        |   |   |
    //        *---v4--*
    //
    //        U = v2 - v1;
    //        V = v4 - v3;
    //        N = Cross(U, V);
    //        N.normalise;
    //
    // BUT IN CASE OF A HEIGHTMAP : 
    //
    //   if you do some math by hand before you code, 
    //   you can see that N is immediately given by 
    //  Approximation (2 adds and a normalization)
    // 
    //        N = Vector3(z[x-1][y] - z[x+1][y], z[x][y-1] - z[x][y+1], 2); 
    //        N.normalise();
    //
    // or even using SOBEL operator VERY accurate! 
    // (14 adds and a normalization)
    //
    //       N = Vector3 (z[x-1][y-1] + z[x-1][y] + z[x-1][y] + z[x-1][y+1] - z[x+1][y-1] - z[x+1][y] - z[x+1][y] - z[x+1][y+1], 
    //                     z[x-1][y-1] + z[x][y-1] + z[x][y-1] + z[x+1][y-1] - z[x-1][y+1] - z[x][y+1] - z[x][y+1] - z[x+1][y+1], 
    //                     8);
    //       N.normalize();



    // the divider make sure we do respect proportion  (height and width proportional to y )
    const Real Dividery = static_cast <Real> (256) / mapUtil->scale.y;
    const Real Dividerx = static_cast <Real> (256) / mapUtil->scale.x;
    const Real Dividerz = static_cast <Real> (256) / mapUtil->scale.z;

    const Real *heightmap = mapUtil->getHeightData ();
    
    uint j = width*3; 
    uint k = width;
    uint curr_row = width;
    for (uint h = 1; h < height - 1; h++)
    {
        DEBUG_PROGRESS_OUTPUT(h, ".")
        j += 3;
        k++;
        for (uint w = 1; w < width - 1; w++)
        {
            // Fast SOBEL filter and mathematically correct
            const Real x =   (heightmap[w-1 + curr_row-width] + heightmap[w-1 + curr_row]
                            + heightmap[w-1 + curr_row]       + heightmap[w-1 + curr_row+width]
                            - heightmap[w+1 + curr_row-width] - heightmap[w+1 + curr_row] 
                            - heightmap[w+1 + curr_row]       - heightmap[w+1 + curr_row+width])
                            ;//* Dividery; 

            const Real z =   ( heightmap[w-1 + curr_row-width] + heightmap[w +   curr_row-width]
                            + heightmap[w +   curr_row-width] + heightmap[w+1 + curr_row-width]
                            - heightmap[w-1 + curr_row+width] - heightmap[w +   curr_row+width]
                            - heightmap[w +   curr_row+width] - heightmap[w+1 + curr_row+width])
                            ;//* Dividery;

            const Real y = 8.0f; 

            // very Fast SOBEL filter
            // (not mathematically correct + approximation)
            // But gives same result as above 
            //Normals[k].x = heightmap[x - 1  + z)   - heightmap[x + 1 + z);
            //Normals[k].z = heightmap[x +      z-1) - heightmap[x     + z + 1);
            //Normals[k].y = 2.0f; 
            
            const Real fInvLength = 1.0 / Math::Sqrt( x * x + y * y + z * z );

            normal[k].x *= x*fInvLength;
            normal[k].y *= y*fInvLength;
            normal[k].z *= z*fInvLength;
           

            NormalData[j]     = MakeUchar (normal[k].x);
            NormalData[j + 1] = MakeUchar (normal[k].y);
            NormalData[j + 2] = MakeUchar (normal[k].z);

            j += 3;
            k ++;
        }
        curr_row += width;
        j += 3;
        k ++;
    }
    NormalMap.loadDynamicImage(NormalData, static_cast <size_t> (width),
                                static_cast <size_t> (height), 1, PF_R8G8B8, true);
    DEBUG_PROGRESS_OUTPUT ("\n");
    }
#endif //_TESTNORLM

}//namespace Ogre
