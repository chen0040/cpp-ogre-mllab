/***************************************************************************
	OgreIPLTexture_BaseTexture2.cpp  -  description
-------------------
begin                : Mon Apr 26 2004
copyright            : (C) 2003 by Jose A Milan
email                : spoke@supercable.es
***************************************************************************/

/***************************************************************************
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU Lesser General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
***************************************************************************/

#include "OgreIPLTexture_BaseTexture2.h"

#include "OgreIPLOptions.h"
#include "OgreIPLSceneManager.h"

#include <OgreStringConverter.h>
#include <OgreMaterialManager.h>
#include <OgreTechnique.h>
#include <OgrePass.h>

namespace Ogre
{

//-----------------------------------------------------------------------
IPLTexture_BaseTexture2::IPLTexture_BaseTexture2( IPLPage* p )
	: IPLTexture( p )
{
	tex = 0;
}

//-----------------------------------------------------------------------
IPLTexture_BaseTexture2::~IPLTexture_BaseTexture2( void )
{
	tex = 0;
}

//-----------------------------------------------------------------------
void IPLTexture_BaseTexture2::setupMaterial( int pageCount, IPLVirtualPageWindow* vw )
{
	if ( mMaterial->getName() == "BaseWhite" )
	{
		mMaterial = reinterpret_cast<Material *>(MaterialManager::getSingleton().getByName("IPLSM_BaseTexture"));

		// build a single technique/pass material that has a base map texture and one detail texture
		// create material name based on page count
		String baseName = "IPLSM_BaseTexture." + StringConverter::toString( pageCount );
		mMaterial = mMaterial->clone(baseName);
	}

	// Create the base image
	DataChunk dc;
	dc.allocate(256 * 256 * 4);

	BaseImage.loadRawData(dc, 256, 256, PF_A8R8G8B8);
	dc.clear();

	// Set the file in the material
	String texname = String("SplattingBase.") + StringConverter::toString( pageCount );
	tex = TextureManager::getSingleton().loadImage(texname, BaseImage, TEX_TYPE_2D, 0, 1.0, 1 + 2);
	// assing this texture to the material
	mMaterial->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureName(texname);
	mMaterial->getTechnique(1)->getPass(0)->getTextureUnitState(0)->setTextureName(texname);

	mMaterial->setLightingEnabled( IPLOptions::getSingleton( ).lit );
	mMaterial->load( );
}

//-----------------------------------------------------------------------
void IPLTexture_BaseTexture2::preLoad( void )
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
void IPLTexture_BaseTexture2::_loadMaterial( void )
{
	ColourValue color;

	// This texture will be used as a base color for the terrain, it will fake the splat for distant renderables.
	uchar *BaseData = BaseImage.getData();

	Real alpha1, alpha2, alpha3, alpha4;
	for (int j = 0; j < 256 * 256; j++)
	{
		// Generate the base texture
		_BuildPoint( color, j, alpha1, alpha2, alpha3, alpha4 );
		// R G B A is the format to add the colours
		BaseData[j*4+0] = color.r * 255;
		BaseData[j*4+1] = color.g * 255;
		BaseData[j*4+2] = color.b * 255;
		BaseData[j*4+3] = ( 1.0 - ( alpha1 + alpha2 + alpha3 + alpha4 ) ) * 255 ; // Opaque
	}
	tex->loadImage( BaseImage );
}

//-----------------------------------------------------------------------
void IPLTexture_BaseTexture2::_unloadMaterial( void )
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
void IPLTexture_BaseTexture2::_BuildPoint(ColourValue& out, const int j, Real& alpha1, Real& alpha2, Real& alpha3, Real& alpha4)
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
	height[6] = mPage->getHeightData( )->getHeight( x - 1, z + 1 ) * scale.y;		// Botton-Left
	height[7] = mPage->getHeightData( )->getHeight( x, z + 1 ) * scale.y;			// Botton-Center
	height[8] = mPage->getHeightData( )->getHeight( x + 1, z + 1 ) * scale.y;		// Botton-Right

	// Weight( pt1 , pt2 ) = 1 - DistanceSquared(pt1,pt2) / (1.75)^2

	//The scope test
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
void IPLTexture_BaseTexture2::_InterpolateColour(ColourValue& out, const Real percentaje, const int index1, const int index2)
{
	Real tmp = 1 - percentaje;
	out.r = ( out.r + ( percentaje * IPLOptions::getSingleton().matColor[index1].r + tmp * IPLOptions::getSingleton().matColor[index2].r ) ) / 2;
	out.g = ( out.g + ( percentaje * IPLOptions::getSingleton().matColor[index1].g + tmp * IPLOptions::getSingleton().matColor[index2].g ) ) / 2;
	out.b = ( out.b + ( percentaje * IPLOptions::getSingleton().matColor[index1].b + tmp * IPLOptions::getSingleton().matColor[index2].b ) ) / 2;
}

//-----------------------------------------------------------------------
void IPLTexture_BaseTexture2::_InterpolateAlpha(Real& alpha1, Real& alpha2, Real& alpha3, Real& alpha4, const Real percentaje, const int index1, const int index2)
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
