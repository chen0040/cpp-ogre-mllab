/***************************************************************************
	OgreIPLTexture_Image.h  -  description
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

#ifndef __IPLTEXTURE_IMAGE_H__
#define __IPLTEXTURE_IMAGE_H__

#include "OgreIPLPrerequisites.h"
#include "OgreIPLTexture.h"

namespace Ogre
{

class IPLTexture_Image : public IPLTexture
{
public:
	IPLTexture_Image( IPLPage* p );

	~IPLTexture_Image( void );

	virtual void setupMaterial( int pageCount, IPLVirtualPageWindow* vw );

	static void preLoad( void );

protected:

	virtual void _loadMaterial( void );
	virtual void _unloadMaterial( void );

};

}

#endif
