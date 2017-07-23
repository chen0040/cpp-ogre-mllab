/***************************************************************************
	OgreIPLData2D_HeightFieldTC.h  -  description
  -------------------
  begin                : Mon Oct 13 2003
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

#ifndef __IPLDATA2D_HEIGHTFIELDTC_H__
#define __IPLDATA2D_HEIGHTFIELDTC_H__

#include <OgrePrerequisites.h>
#include <OgreImage.h>

#include "OgreIPLData2D.h"

namespace Ogre
{

/**
  * A specialized class for loading 2D Data from a compressed HeightField file.
  */

class IPLData2D_HeightFieldTC : public IPLData2D
{
public:
	IPLData2D_HeightFieldTC( );

	~IPLData2D_HeightFieldTC( );

    virtual float getHeight( const float x, const float z );

	virtual float getMaxHeight( void );

    virtual Vector3 getNormalAt( const float mX, const float mZ );

    virtual ColourValue getBase( const float mX, const float mZ );
    virtual ColourValue getCoverage( const float mX, const float mZ );

	static void preLoad( void );

protected:

	virtual void _load( float x, float z );

	virtual void _load( void );

	virtual void _unload( void );

private:

	bool _checkSize( int s )
	{
		for ( int i = 0; i < 16; i++ )
		{
			//printf( "Checking...%d\n", ( 1 << i ) + 1 );
			if ( s == ( 1 << i ) + 1 )
			{
				return true;
			}
		}
		return false;
	}

	float _decodeTC( int encoded );

	float input_max, input_min;

	inline float _Max( float a, float b )
	{
		return ( ( a > b ) ? a : b );
	};

	Image *mImage;
	uint mSize;
	uint mMax;
	uint mBpp;// should be 4 bytes (mImage is RGBA)
};

}

#endif
