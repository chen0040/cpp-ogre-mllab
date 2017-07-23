/***************************************************************************
	OgreIPLTexture.h  -  description
  -------------------
  begin                : Fri Apr 16 2004
  copyright            : (C) 2002 by Jose A Milan
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

#ifndef __IPLTEXTURE_H__
#define __IPLTEXTURE_H__

#include "OgreIPLPrerequisites.h"

#include <OgreColourValue.h>
#include <OgreImage.h>
#include <vector>

namespace Ogre
{

class IPLVirtualPageWindow;
class IPLPage;

/**
  * A simple class for encapsulating Texture generation.
  */
class IPLTexture
{
public:
	IPLTexture( IPLPage* p );

	virtual ~IPLTexture( void );

	void load( const float mX, const float mZ );
	void unload( void );

	bool isLoaded( void ) const;

	Material* getMaterial( void ) const;

	/** This will create the template material so we can reuse it
	*/
	virtual void setupMaterial( int pageCount, IPLVirtualPageWindow* vw ) = 0;

	/** This will preload the required files
		@remarks Should be called just once, and Every subclass must implement this
	*/
	//static void preLoad( void ) = 0;

protected:
	virtual void _loadMaterial( void ) = 0;
	virtual void _unloadMaterial( void ) = 0;

	bool mIsLoaded;

	Material *mMaterial;

	float mDataX, mDataZ;

	IPLPage* mPage;

};

}

#endif
