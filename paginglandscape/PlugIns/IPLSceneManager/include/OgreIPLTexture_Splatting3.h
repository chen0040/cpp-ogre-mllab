/***************************************************************************
	OgreIPLTexture_Splatting3.h  -  description
	-------------------
	begin                : Mon Apr 16 2004
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

#ifndef __IPLTexture_Splatting3_H_
#define __IPLTexture_Splatting3_H_

#include "OgreIPLPrerequisites.h"
#include "OgreIPLTexture.h"

namespace Ogre
{


class IPLTexture_Splatting3 : public IPLTexture
{
public:
	IPLTexture_Splatting3( IPLPage* p );

	~IPLTexture_Splatting3( void );

	virtual void setupMaterial( int pageCount, IPLVirtualPageWindow* vw );

	static void preLoad( void );

protected:

	virtual void _loadMaterial( void );

	virtual void _unloadMaterial( void );

private:

	void _BuildPoint( ColourValue& out, const int j, Real& alpha1, Real& alpha2, Real& alpha3, Real& alpha4 );

	inline void _InterpolateColour( ColourValue& out, const Real percentaje, const int index1, const int index2 );

	inline void _InterpolateAlpha( Real& alpha1, Real& alpha2, Real& alpha3, Real& alpha4, const Real percentaje, const int index1, const int index2 );

};

}

#endif
