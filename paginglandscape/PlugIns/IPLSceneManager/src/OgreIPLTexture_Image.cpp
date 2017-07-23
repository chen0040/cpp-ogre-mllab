/***************************************************************************
OgreIPLTexture_Image.cpp  -  description
-------------------
begin                : Fri Apr 16 2004
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

#include "OgreIPLTexture_Image.h"

#include "OgreIPLOptions.h"
#include "OgreIPLSceneManager.h"

#include <OgreStringConverter.h>
#include <OgreMaterialManager.h>
#include <OgreTextureManager.h>
#include <OgreTechnique.h>
#include <OgrePass.h>

namespace Ogre
{

IPLTexture_Image::IPLTexture_Image( IPLPage* p )
	: IPLTexture( p )
{
}

//-----------------------------------------------------------------------
IPLTexture_Image::~IPLTexture_Image( void )
{
}

//-----------------------------------------------------------------------
void IPLTexture_Image::setupMaterial( int pageCount, IPLVirtualPageWindow* vw )
{
	if ( mMaterial->getName() == "BaseWhite" )
	{
		mMaterial = reinterpret_cast<Material *>(MaterialManager::getSingleton().getByName("IPLSM_Image"));

		// build a single technique/pass material that has a base map texture and one detail texture
		// create material name based on page count
		String baseName = "IPLSM_Image." + StringConverter::toString( pageCount );
		mMaterial = mMaterial->clone(baseName);
	}

	mMaterial->setLightingEnabled( IPLOptions::getSingleton( ).lit );
	mMaterial->load( );
}

//-----------------------------------------------------------------------
void IPLTexture_Image::preLoad( void )
{
	Image newImage;
	for ( int z = 0; z < IPLOptions::getSingleton( ).virtual_window_height; z++ )
	{
		for ( int x = 0; x < IPLOptions::getSingleton( ).virtual_window_width; x++ )
		{
			// preload terrain base texture
			TextureManager::getSingleton( ).load( IPLOptions::getSingleton( ).mMapTextureName + "." + StringConverter::toString( z ) + "." +
				StringConverter::toString( x ) + "." + IPLOptions::getSingleton( ).mMapTextureExt, TEX_TYPE_2D );
		}
	}
}

//-----------------------------------------------------------------------
void IPLTexture_Image::_loadMaterial( void )
{
	// load page map texture into TUS 0
	mMaterial->getTechnique( 0 )->getPass( 0 )->getTextureUnitState( 0 )->setTextureName( 
		IPLOptions::getSingleton( ).mMapTextureName + "." + StringConverter::toString( mDataZ ) +
		"."	+ StringConverter::toString( mDataX ) + "." + IPLOptions::getSingleton( ).mMapTextureExt );
}

//-----------------------------------------------------------------------
void IPLTexture_Image::_unloadMaterial( void )
{
	if ( mMaterial != 0 )
	{
		mMaterial->unload( );
		// We can´t destroy de material here.
		//mMaterial->destroy( );
		//delete mMaterial;
		//mMaterial = 0;
	}
}

} //namespace
