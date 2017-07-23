/***************************************************************************
	OgreIPLData2D_HeightField.h  

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.

***************************************************************************/

#ifndef __IPLDATA2D_HEIGHTFIELD_H__
#define __IPLDATA2D_HEIGHTFIELD_H__

#include <OgrePrerequisites.h>
#include <OgreImage.h>

#include "OgreIPLData2D.h"

namespace Ogre
{

/**
  * A specialized class for loading 2D Data from a HeightField file.
  */

class IPLData2D_HeightField : public IPLData2D
{
public:
	IPLData2D_HeightField( );

	~IPLData2D_HeightField( );

	virtual float getHeight( const float x, const float z );
	
	virtual float getMaxHeight( void );

	virtual void getNormalAt( const float x, const float z, Vector3* result );

	static void preLoad( void );

protected:

	virtual void _load( float x, float z );

	virtual void _load( void );

	virtual void _unload( void );

	bool _checkSize( int s ) const;

	inline float _Max( int a, int b ) const;

	Image *mImage;
	int mSize;
	int mMax;
};

}

#endif
