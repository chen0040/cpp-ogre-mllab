/***************************************************************************
	OgreIPLData2D.cpp  

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

#include "OgreIPLData2D.h"

namespace Ogre
{

//-----------------------------------------------------------------------
IPLData2D::IPLData2D( )
{
	mIsLoaded = false;
}

//-----------------------------------------------------------------------
IPLData2D::~IPLData2D( )
{
	if ( mIsLoaded )
	{
		unload( );
	}
}

//-----------------------------------------------------------------------
void IPLData2D::load( int mX, int mZ )
{
	mIsLoaded = true;
	_load( mX, mZ );
}

//-----------------------------------------------------------------------
void IPLData2D::load( void )
{
	mIsLoaded = true;
	_load( );
}

//-----------------------------------------------------------------------
void IPLData2D::unload( void )
{
	mIsLoaded = false;
	_unload( );
}

//-----------------------------------------------------------------------
float IPLData2D::getInterpolatedHeight( const float x, const float z )
{
	if ( !mIsLoaded )
	{
		return 0.0f;
	}

	// find the 4 vertices that surround the point
	// use LOD info to determine vertex spacing - this is passed into the method
	// determine vertices on left and right of point and top and bottom
	// don't access VBO since a big performance hit when only 4 vertices are needed

	const int vertex_spread = 1;//render_size / 4;

	// find the vertex to the bottom left of the point
	const int bottom_left_x = ( ( int )( x / vertex_spread ) ) * vertex_spread;
	const int bottom_left_z = ( ( int )( z / vertex_spread ) ) * vertex_spread;

	// find the 4 heights around the point
	const float bottom_left_y = getHeight( bottom_left_x, bottom_left_z );

	const float bottom_right_y = getHeight( bottom_left_x + vertex_spread, bottom_left_z );

	const float top_left_y = getHeight( bottom_left_x, bottom_left_z + vertex_spread );

	const float top_right_y = getHeight( bottom_left_x + vertex_spread, bottom_left_z + vertex_spread );

	const float x_pct = ( x - ( float )bottom_left_x ) / ( float )vertex_spread;
	const float z_pct = ( z - ( float )bottom_left_z ) / ( float )vertex_spread;

	//bilinear interpolate to find the height.

	// figure out which 3 vertices are closest to the point and use those to form triangle plane for intersection
	// Triangle strip has diagonal going from bottom left to top right
	if ( ( x_pct - z_pct ) >= 0 )
	{
		return ( ( bottom_left_y  + ( bottom_right_y - bottom_left_y ) *  x_pct + ( top_right_y - bottom_right_y ) * z_pct ) );
	}
	else
	{
		return ( ( top_left_y  + ( top_right_y - top_left_y ) *  x_pct + ( bottom_left_y - top_left_y ) * ( 1 - z_pct ) ) );
	}
}

//-----------------------------------------------------------------------
void IPLData2D::getNormalAt( const float x, const float z, Vector3* result )
{
	result->x = 0;
	result->y = 1;
	result->z = 0;
}

//-----------------------------------------------------------------------
void IPLData2D::getBase( const float x, const float z, ColourValue* result )
{
	result = &ColourValue::White;
}

//-----------------------------------------------------------------------
void IPLData2D::getCoverage( const float x, const float z, ColourValue* result )
{
	result = &ColourValue::White;
}

//-----------------------------------------------------------------------
bool IPLData2D::isLoaded( void ) const
{
	return mIsLoaded;
}

} //namespace
