/***************************************************************************
OgreIPLTexture.cpp  -  description
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

#include "OgreIPLTexture.h"

#include "OgreIPLOptions.h"

#include <OgreStringConverter.h>
#include <OgreMaterialManager.h>
#include <OgreTextureManager.h>
#include <OgreTechnique.h>
#include <OgrePass.h>

namespace Ogre
{

//-----------------------------------------------------------------------
IPLTexture::IPLTexture( IPLPage* p )
{
	mPage = p;
	mIsLoaded = false;
	mDataX = -1;
	mDataZ = -1;
	// get default material
	mMaterial = reinterpret_cast<Material *>(MaterialManager::getSingleton().getByName("BaseWhite"));
}

//-----------------------------------------------------------------------
IPLTexture::~IPLTexture( void )
{
	mIsLoaded = false;
	if ( mMaterial != 0 )
	{
		//TODO: Check this
/*
		if ( mMaterial->isLoaded( ) )
		{
			mMaterial->unload( );
		}
*/
		mMaterial = 0;
	}
	mPage = 0;
}

//-----------------------------------------------------------------------
void IPLTexture::load( const float mX, const float mZ )
{
	mDataX = mX;
	mDataZ = mZ;
	_loadMaterial( );
	mIsLoaded = true;
}

//-----------------------------------------------------------------------
void IPLTexture::unload( void )
{
	mIsLoaded = false;
	_unloadMaterial( );
}

//-----------------------------------------------------------------------
bool IPLTexture::isLoaded( void ) const
{
	return mIsLoaded;
}

//-----------------------------------------------------------------------
Material* IPLTexture::getMaterial( void ) const
{
	return mMaterial;
}

} //namespace
