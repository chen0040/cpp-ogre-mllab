/***************************************************************************
	OgreIPLData2D.h 

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

#ifndef __IPLDATA2D_H__
#define __IPLDATA2D_H__

#include <OgrePrerequisites.h>
#include <OgreColourValue.h>
#include <OgreVector3.h>

namespace Ogre
{

/**
  * A simple class for encapsulating 2D Data reading.
  */

class IPLData2D
{
public:
	IPLData2D( );

	virtual ~IPLData2D( );

	void load( int mX, int mZ );

	void load( void );

	void unload( void );

	virtual float getHeight( const float x, const float z ) = 0;

	/** Get the real world height at a particular position within the renderable data
		@remarks
			Method is used to get the terrain height at a position based on x and z that is local to this renderable.
			This method figures out the height using bilinear interpretation between three heights that form a triangle around the point.
		@par
			the float returned is the height based on the data passed.  If the height could
			not be determined then -1 is returned and this would only occur if the page was not loaded.
			The height value must be scaled to the world value by the caller since the method has no access to the world scale
		@param x  x position within the height data
		@param z  z position within the height data
	*/
	float getInterpolatedHeight( const float x, const float  z );
	virtual float getMaxHeight( void ) = 0;

	virtual void getNormalAt( const float x, const float z, Vector3* result );

	virtual void getBase( const float x, const float z, ColourValue* result );

	virtual void getCoverage( const float x, const float z, ColourValue* result );

	bool isLoaded( void ) const;

	/** This will preload the required files
		@remarks Should be called just once, and Every subclass must implement this
	*/
	//static void preLoad( void ) = 0;

protected:

	/** This load is used at runtime
	*/
	virtual void _load( float x, float z ) = 0;

	/** This load is used by the map splitter tool
	*/
	virtual void _load( void ) = 0;

	virtual void _unload( void ) = 0;

	bool mIsLoaded;

};

}

#endif
