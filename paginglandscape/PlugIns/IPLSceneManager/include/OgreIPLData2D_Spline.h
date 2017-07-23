/***************************************************************************
	OgreIPLData2D_Spline.h
	Header for a NURBS-based heightfield generator
	-------------------
	begin                : Sat Nov 9 2003
	copyright            : (C) 2003 Chris "Antiarc" Heald
	email                : antiarc@captionthis.com
***************************************************************************/

/***************************************************************************
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU Lesser General Public License as        *
*   published by the Free Software Foundation; either version 2 of the    *
*   License, or (at your option) any later version.                       *
*                                                                         *
***************************************************************************/

#ifndef __IPLDATA2D_SPLINE_H__
#define __IPLDATA2D_SPLINE_H__

#include <OgrePrerequisites.h>
#include "OgreIPLData2D.h"
#include "DRGNURBSSurface.h"

namespace Ogre
{

/**
  * A specialized class for loading 2D Data from a Spline file.
  */

class IPLData2D_Spline : public IPLData2D
{
public:
	IPLData2D_Spline( );

	~IPLData2D_Spline( );

	virtual float getHeight( const float x, const float z );

	virtual float getMaxHeight( void );

	static void preLoad( void );

protected:

	virtual void _load( float x, float  z);

	virtual void _load( void );

	virtual void _unload( void );

private:

	bool _checkSize( int s )
	{
		for ( int i = 0; i < 16; i++ )
		{
			printf( "Checking...%d\n", ( 1 << i ) + 1 );
			if ( s == ( 1 << i ) + 1 )
			{
				return true;
			}
		}
		return false;
	}

	inline float _Max( float a, float b )
	{
		return ( ( a > b ) ? a : b );
	};

	int mSize;
	int mMax;
	int degree;
	int mResolution;
	bool mLoaded;

	Point4D *mPoints;
	CDRGNURBSSurface *mSurface;
};

}

#endif
