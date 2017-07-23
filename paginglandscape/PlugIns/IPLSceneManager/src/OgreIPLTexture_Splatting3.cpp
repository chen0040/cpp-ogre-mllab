/***************************************************************************
	OgreIPLTexture_Splatting3.cpp  -  description
	-------------------
	begin                : Mon Apr 16 2004
	copyright            : (C) 2003 by Jose A Milan
	email                : spoke@supercable.es
***************************************************************************/

/***************************************************************************
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU Lesser General Public License as        *
*   published by the Free Software Foundation; either version 2 of the    *
*   License, or (at your option) any later version.                       *
*                                                                         *
***************************************************************************/


#include "OgreIPLTexture_Splatting3.h"

#include "OgreIPLOptions.h"
#include "OgreIPLSceneManager.h"

#include <OgreStringConverter.h>
#include <OgreMaterialManager.h>
#include <OgreTextureManager.h>
#include <OgreTechnique.h>
#include <OgrePass.h>

namespace Ogre
{

IPLTexture_Splatting3::IPLTexture_Splatting3( IPLPage* p )
	: IPLTexture( p )
{
}

//-----------------------------------------------------------------------
IPLTexture_Splatting3::~IPLTexture_Splatting3( void )
{
}

//-----------------------------------------------------------------------
void IPLTexture_Splatting3::setupMaterial( int pageCount, IPLVirtualPageWindow* vw )
{
	// create material name based on page count
}

//-----------------------------------------------------------------------
void IPLTexture_Splatting3::preLoad( void )
{
	//	Image newImage;
	//	for ( int z = 0; z < IPLOptions::getSingleton( ).virtual_window_height; z++ )
	//	{
	//		for ( int x = 0; x < IPLOptions::getSingleton( ).virtual_window_width; x++ )
	//		{
	//			// preload terrain base texture
	//			TextureManager::getSingleton( ).load( IPLOptions::getSingleton( ).mMapTextureName + "." + StringConverter::toString( z ) + "." +
	//				StringConverter::toString( x ) + "." + IPLOptions::getSingleton( ).mMapTextureExt, TEX_TYPE_2D );
	//		}
	//	}
}

//-----------------------------------------------------------------------
void IPLTexture_Splatting3::_loadMaterial( void )
{
	if (mMaterial->getName() == "BaseWhite" )
	{

        // Create a new texture using the base image
        String commonName = StringConverter::toString(mDataZ) + String(".") + StringConverter::toString(mDataX);

        mMaterial = reinterpret_cast<Material *>(MaterialManager::getSingleton().getByName("SplattingMaterial3"));
        // Now that we have all the resources in place, we load the material
        String matname2 = String("SplattingMaterial3.") + commonName;
        mMaterial = mMaterial->clone(matname2);

        Image LightImage;
        LightImage.load (IPLOptions::getSingleton().landscape_filename + ".light." + 
            commonName + "." + IPLOptions::getSingleton().landscape_extension);

        String texname2 = String("SplattingLight.") + commonName;
        Texture *tex2 = TextureManager::getSingleton().loadImage (texname2, 
            LightImage, 
            TEX_TYPE_2D,
            0, 1.0, 1 + 2);

        mMaterial->getTechnique(0)->getPass(0)->getTextureUnitState(3)->setTextureName(texname2);
    
        // Create the base image 
        Image BaseImage;
        BaseImage.load (IPLOptions::getSingleton().landscape_filename + ".Color." + 
            commonName + "." + IPLOptions::getSingleton().landscape_extension);

        String texname = String("SplattingBase.") + commonName;
        Texture *tex = TextureManager::getSingleton().loadImage (texname, 
            BaseImage, 
            TEX_TYPE_2D,
            0, 1.0, 1 + 2);

        // assign this texture to the material
        mMaterial->getTechnique(1)->getPass(0)->getTextureUnitState(0)->setTextureName(texname);
        mMaterial->getTechnique(1)->getPass(0)->setLightingEnabled( IPLOptions::getSingleton().lit );



        mMaterial->load();  
	}
	else
	{
		mMaterial->load();
	}
	mMaterial->setLightingEnabled( IPLOptions::getSingleton().lit );
}

//-----------------------------------------------------------------------
void IPLTexture_Splatting3::_unloadMaterial( void )
{
	if ( mMaterial != 0 )
	{
		mMaterial->unload();
		// We can´t destroy de material here.
		//mMaterial -> destroy();
		//delete mMaterial;
		//mMaterial = 0;
	}
}

//-----------------------------------------------------------------------
void IPLTexture_Splatting3::_BuildPoint( ColourValue& out, const int j, Real& alpha1, Real& alpha2, Real& alpha3, Real& alpha4 )
{
	// Init the colour
	out = ColourValue(0,0,0,0);
	alpha1 = 0;
	alpha2 = 0;
	alpha3 = 0;
	alpha4 = 0;
	// Calculate the current Point position
	int x = j % 256;
	int z = j / 256;
	// Ask for the current height value and the 8 surrounding values
	Real height[9];
	//TODO: optimize this so it takes into account the neighbour page height too
	if ( x == 0 )
	{
		x = 1;
	}
	else if ( x == 255 )
	{
		x = 254;
	}
	if ( z == 0 )
	{
		z = 1;
	}
	else if ( z == 255 )
	{
		z = 254;
	}


	Vector3 scale = IPLOptions::getSingleton().scale;

 	height[0] = mPage->getHeightData( )->getHeight( x - 1, z - 1 ) * scale.y;		// Top-Left
 	height[1] = mPage->getHeightData( )->getHeight( x, z - 1 ) * scale.y;			// Top-Center
	height[2] = mPage->getHeightData( )->getHeight( x + 1, z - 1 ) * scale.y;		// Top-Right
 	height[3] = mPage->getHeightData( )->getHeight( x - 1, z ) * scale.y;			// Left
	height[4] = mPage->getHeightData( )->getHeight( x, z ) * scale.y;				// Current Point
	height[5] = mPage->getHeightData( )->getHeight( x + 1, z ) * scale.y;			// Right
 	height[6] = mPage->getHeightData( )->getHeight( x - 1, z + 1 ) * scale.y;		// Bottom-Left
    height[7] = mPage->getHeightData( )->getHeight( x, z + 1 ) * scale.y;			// Bottom-Center
 	height[8] = mPage->getHeightData( )->getHeight( x + 1, z + 1 ) * scale.y;		// Bottom-Right

	// Weight( pt1 , pt2 ) = 1 - DistanceSquared(pt1,pt2) / (1.75)^2

	//The slope test
	Real max = 0.0;
	Real min = 9999999.9;
	Real sloppy[8];
	Real dx = IPLOptions::getSingleton().scale.x;
	Real dz = IPLOptions::getSingleton().scale.z;
	sloppy[0] = abs( height[0] - height[4] ) / ( dx + dz );
	sloppy[1] = abs( height[1] - height[4] ) / ( dz );
	sloppy[2] = abs( height[2] - height[4] ) / ( dx + dz );
	sloppy[3] = abs( height[3] - height[4] ) / ( dx );
	sloppy[4] = abs( height[5] - height[4] ) / ( dx );
	sloppy[5] = abs( height[6] - height[4] ) / ( dx + dz );
	sloppy[6] = abs( height[7] - height[4] ) / ( dz );
	sloppy[7] = abs( height[8] - height[4] ) / ( dx + dz );

	//snow  = 0
	//sand  = 1
	//grass = 2
	//rock  = 3
	for ( int i = 0; i < 7; i++ )
	{
		if ( height[4] < IPLOptions::getSingleton().matHeight[0] )
		{
			if ( sloppy[i] < 0.20 )
			{
				// grass-grass
				_InterpolateColour( out, 1.0, 2, 2 );
				_InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 1.0, 2, 2 );
			}
			if ( sloppy[i] >= 0.15 && sloppy[i] < 0.40 )
			{
				// sand-grass
				_InterpolateColour( out, 0.25, 1, 2 );
				_InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 0.25, 1, 2 );
			}
			if ( sloppy[i] >= 0.30 && sloppy[i] < 0.65 )
			{
				// sand-sand
				_InterpolateColour( out, 1.0, 1, 1 );
				_InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 1.0, 1, 1 );
			}
			if ( sloppy[i] >= 0.55 && sloppy[i] < 0.75 )
			{
				// sand-rock
				_InterpolateColour( out, 0.75, 1, 3 );
				_InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 0.75, 1, 3 );
			}
			if ( sloppy[i] >= 0.70 )
			{
				// rock-rock
				_InterpolateColour( out, 1.0, 3, 3 );
				_InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 1.0, 3, 3 );
			}
		}
		else if ( height[4] >= IPLOptions::getSingleton().matHeight[0] && height[4] < IPLOptions::getSingleton().matHeight[1] )
		{
			if ( sloppy[i] < 0.15 )
			{
				// grass-snow
				_InterpolateColour( out, 0.25, 2, 0 );
				_InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 0.25, 2, 0 );
			}
			if ( sloppy[i] >= 0.10 && sloppy[i] < 0.45 )
			{
				// snow-sand
				_InterpolateColour( out, 0.65, 0, 1 );
				_InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 0.65, 0, 1 );
			}
			if ( sloppy[i] >= 0.25 && sloppy[i] < 0.65 )
			{
				// snow-rock
				_InterpolateColour( out, 0.5, 0, 3 );
				_InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 0.5, 0, 3 );
			}
			if ( sloppy[i] >= 0.50 && sloppy[i] < 0.75 )
			{
				// snow-rock
				_InterpolateColour( out, 0.75, 0, 3 );
				_InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 0.75, 0, 3 );
			}
			if ( sloppy[i] >= 0.70 )
			{
				// rock-rock
				_InterpolateColour( out, 1.0, 3, 3 );
				_InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 1.0, 3, 3 );
			}
		}
		else
		{
			if ( sloppy[i] < 0.15 )
			{
				// snow-snow
				_InterpolateColour( out, 1.0, 0, 0 );
				_InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 1.0, 0, 0 );
			}
			if ( sloppy[i] >= 0.10 && sloppy[i] < 0.45 )
			{
				// snow-sand
				_InterpolateColour( out, 0.35, 0, 1 );
				_InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 0.35, 0, 1 );
			}
			if ( sloppy[i] >= 0.25 && sloppy[i] < 0.65 )
			{
				// snow-rock
				_InterpolateColour( out, 0.5, 0, 3 );
				_InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 0.5, 0, 3 );
			}
			if ( sloppy[i] >= 0.50 && sloppy[i] < 0.75 )
			{
				// snow-rock
				_InterpolateColour( out, 0.75, 0, 3 );
				_InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 0.75, 0, 3 );
			}
			if ( sloppy[i] >= 0.70 )
			{
				// rock-rock
				_InterpolateColour( out, 1.0, 3, 3 );
				_InterpolateAlpha( alpha1, alpha2, alpha3, alpha4, 1.0, 3, 3 );
			}
		}
	}
}

//-----------------------------------------------------------------------
void IPLTexture_Splatting3::_InterpolateColour( ColourValue& out, const Real percentaje, const int index1, const int index2 )
{
    // D3DTOP_LERP GL_INTERPOLATE
	Real tmp = 1 - percentaje;
    if (percentaje < 1.0)
    {
	    out.r = ( out.r + ( percentaje * IPLOptions::getSingleton().matColor[index1].r + tmp * IPLOptions::getSingleton().matColor[index2].r ) ) / 2;
	    out.g = ( out.g + ( percentaje * IPLOptions::getSingleton().matColor[index1].g + tmp * IPLOptions::getSingleton().matColor[index2].g ) ) / 2;
	    out.b = ( out.b + ( percentaje * IPLOptions::getSingleton().matColor[index1].b + tmp * IPLOptions::getSingleton().matColor[index2].b ) ) / 2;
    }
}

//-----------------------------------------------------------------------
void IPLTexture_Splatting3::_InterpolateAlpha( Real& alpha1, Real& alpha2, Real& alpha3, Real& alpha4, const Real percentaje, const int index1, const int index2 )
{
	if ( index1 == index2 )
	{
		if ( index1 == 0 )
		{
			alpha1 += 1.0;
		}
		else if ( index1 == 1 )
		{
			alpha2 += 1.0;
		}
		else if ( index1 == 2 )
		{
			alpha3 += 1.0;
		}
		else
		{
			alpha4 += 1.0;
		}
	}
	else
	{
		if ( index2 == 0 )
		{
			alpha1 += percentaje;
		}
		else if ( index2 == 1 )
		{
			alpha2 += percentaje;
		}
		else if ( index2 == 2 )
		{
			alpha3 += percentaje;
		}
		else
		{
			alpha4 += percentaje;
		}

		if ( index1 == 0 )
		{
			alpha1 += 1.0 - percentaje;
		}
		else if ( index1 == 1 )
		{
			alpha2 += 1.0 - percentaje;
		}
		else if ( index1 == 2 )
		{
			alpha3 += 1.0 - percentaje;
		}
		else
		{
			alpha4 += 1.0 - percentaje;
		}
	}
	//snow  = 0
	//sand  = 1
	//grass = 2
	//rock  = 3
	alpha1 *= ( 4.0 / 5.0 );
	alpha2 *= ( 3.0 / 5.0 );
	alpha3 *= ( 4.0 / 5.0 );
	alpha4 *= ( 2.0 / 5.0 );
	// Normalize
	Real total = ( alpha1 + alpha2 + alpha3 + alpha4 ) * 2.0;
	alpha1 = alpha1 / total;
	alpha2 = alpha2 / total;
	alpha3 = alpha3 / total;
	alpha4 = alpha4 / total;
}

} //namespace
