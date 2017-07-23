/***************************************************************************
	OgreIPLSceneManager.cpp  

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

#include "OgreIPLVirtualPageWindow.h"

#include "OgreIPLSceneManager.h"
#include "OgreIPLOptions.h"
#include "OgreIPLPage.h"

// specialized data loaders
#include "OgreIPLData2D_HeightField.h"
#include "OgreIPLData2D_HeightFieldTC.h"
#include "OgreIPLData2D_Spline.h"

// specialized texture loaders
#include "OgreIPLTexture_Image.h"

#include <OgreStringConverter.h>
#include <OgreImage.h>

namespace Ogre
{

//-----------------------------------------------------------------------
IPLVirtualPageWindow::IPLVirtualPageWindow( IPLSceneManager* sm )
{
	// initialize members to default settings

	mBoundryExtent = 0.10f;
	mSceneManager = sm;
	mRootSceneNode = sm->getRootSceneNode();
	setWorldScale( IPLOptions::getSingleton( ).scale.x, IPLOptions::getSingleton( ).scale.z );
	setWorldMapSize( IPLOptions::getSingleton( ).world_height, IPLOptions::getSingleton( ).world_width, IPLOptions::getSingleton( ).PageSize );
	setPageWindowSize( IPLOptions::getSingleton( ).virtual_window_width, IPLOptions::getSingleton( ).virtual_window_height );

	_preLoad( );

	// force update view;
	mBoundryMaxX = -1.0;
	updateViewPosition( 0, 0 );
}

//-----------------------------------------------------------------------
IPLVirtualPageWindow::~IPLVirtualPageWindow( )
{
	for ( int z = 0; z < mWindowPageCount_z; z++ )
	{
		for ( int x = 0; x < mWindowPageCount_x; x++ )
		{
			if ( mActiveWindow[ z ][ x ] != NULL )
			{
				delete mActiveWindow[ z ][ x ];
				mActiveWindow[ z ][ x ] = NULL;
			}
		}
	}
}

//-----------------------------------------------------------------------
void IPLVirtualPageWindow::setPageWindowSize( const int xcount, const int zcount )
{
	// check window is getting bigger or smaller
	// would be nice to be able to resize at any time
	// there is a lot more to this so stay simple for now

	// for now assume no size to window
	// resize both mWindowPages1 and mWindowPages2 at the same time
	mWindowPageCount_x = xcount; 
	mWindowPageCount_z = zcount;

    for ( int z = 0; z < zcount; z++ )
    {
        mActiveWindow.push_back( IPLPageRow( ) );
        mOldWindow.push_back( IPLPageRow( ) );

        for (int x = 0; x < xcount; x++ )
        {
			// populate Active Window with pages
            mActiveWindow[ z ].push_back( new IPLPage( this ) );
			// populate old window with NULLs
            mOldWindow[ z ].push_back( NULL );

			// pages will be seeded later
        }
    }
}

//-----------------------------------------------------------------------
void IPLVirtualPageWindow::updateViewPosition( const float x, const float z )
{
	// if the new view is outside the center area of the window then update
	if ( _isViewCentered( x, z ) == false )
	{
		// calculate new center area in world coordinates for the window
		// figure out the new page for the 0,0 position in the window

		// figure out shift of pages in window by (old page - new page) at 0,0 window position
		const int oldMapPageOffset_x = mMapPageOffset_x;
		const int oldMapPageOffset_z = mMapPageOffset_z;

		_setCenterAreaBoundries( x, z );

		int firstShiftX = oldMapPageOffset_x - mMapPageOffset_x;
		int firstShiftZ = oldMapPageOffset_z - mMapPageOffset_z;

		// need to find the smallest shift so that we minimize the pages that must reload

		// calculate second shift for X
		// if first shift is less than 0 then add X page count
		// else subtract X page count
		int secondShiftX = firstShiftX + ( ( firstShiftX < 0 ) ?  mWorldMap_PageCount_x : -mWorldMap_PageCount_x );
		// chose smallest absolute shift
		firstShiftX = ( abs( firstShiftX ) < abs( secondShiftX ) ) ? firstShiftX : secondShiftX;

		// calculate second shift for Z
		// if first shift is less than 0 then add Z page count
		// else subtract Z page count
		int secondShiftZ = firstShiftZ + ( ( firstShiftZ < 0 ) ?  mWorldMap_PageCount_z : -mWorldMap_PageCount_z );
		// chose smallest absolute shift
		firstShiftZ = ( abs( firstShiftZ ) < abs( secondShiftZ ) ) ? firstShiftZ : secondShiftZ;

		_shufflePages( firstShiftX, firstShiftZ );
	}
}

//-----------------------------------------------------------------------
void IPLVirtualPageWindow::setWorldMapSize( const int PageXCount, const int PageZCount, const int PagePixelSize )
{
	mWorldMap_PageCount_x = PageXCount;
	mWorldMap_PageCount_z = PageZCount;
	mPagePixelSize = PagePixelSize;
	// need to update window position
}

//-----------------------------------------------------------------------
void IPLVirtualPageWindow::setWorldScale( const float x, const float z )
{
	mWorldScale_x = x;
	mWorldScale_z = z;
}

//-----------------------------------------------------------------------
float IPLVirtualPageWindow::getWorldHeight( float worldx, float worldz )
{
	int pageX;
	int pageZ;
	// determine the page within the virtual page window that the world coordinates refer to
	// calculate the absolute page indexes
	_getWorldPageIndices( worldx, worldz, pageX, pageZ );

	// scale down world coordinates to 1::1 scale
	worldx /= mWorldScale_x;
	worldz /= mWorldScale_z;

	// subtract page offsets to get point within page
	// make sure not below zero - negative numbers don't work good for indexes
	worldx -= ( float )( pageX * ( mPagePixelSize - 1.0f ) );
	if ( worldx < 0 )
	{
		worldx += ( float )( mPagePixelSize - 1.0f );
		// when negative must compensate page index offset
		pageX--;
	}

	// make sure not below zero
	worldz -= ( float )( pageZ * ( mPagePixelSize - 1.0f ) );
	if ( worldz < 0 )
	{
		worldz += ( float )( mPagePixelSize - 1.0f );
		// when negative must compensate page index offset
		pageZ--;
	}

	// make page index relative to virtual window
	pageX -= mAbsolutePageOffset_x;
	pageZ -= mAbsolutePageOffset_z;

	// if page indices are not int the window then height is -1
	if ( pageX < 0 )
	{
		return -1;
	}
	if ( pageX >= mWindowPageCount_x )
	{
		return -1;
	}
	if ( pageZ < 0 )
	{
		return -1;
	}
	if ( pageZ >= mWindowPageCount_z )
	{
		return -1;
	}

	// no value should be below zero
	assert( ( pageZ >= 0 ) && ( pageX >= 0 ) );
	assert( ( worldx >= 0 ) && ( worldz >= 0 ) );

	// get the page to calculate the height
	return mActiveWindow[ pageZ ][ pageX ]->getRealWorldHeight( worldx, worldz );
}

//-----------------------------------------------------------------------
IPLSceneManager* IPLVirtualPageWindow::getSceneManager( void ) const
{
	return mSceneManager;
}

//-----------------------------------------------------------------------
SceneNode* IPLVirtualPageWindow::getRootSceneNode( void ) const
{
	return mRootSceneNode;
}

//-----------------------------------------------------------------------
void IPLVirtualPageWindow::_preLoad( void )
{
	// if cache enabled load all the height maps and textures
	// - this is to dirty the cache to make page loading faster since the data is now paged by the OS
	// this is not the best way to implement a cache but its simple, cheap and works in windows XP
	if ( IPLOptions::getSingleton( ).mPreloadCache == true )
	{
		// Preload the height fields
		if ( IPLOptions::getSingleton( ).mData2DFormat == "HeightField" )
		{
			IPLData2D_HeightField::preLoad( );
		}
		else if ( IPLOptions::getSingleton( ).mData2DFormat == "HeightFieldTC" )
		{
			IPLData2D_HeightFieldTC::preLoad( );
		}
		else if ( IPLOptions::getSingleton( ).mData2DFormat == "SplineField" )
		{
			IPLData2D_Spline::preLoad( );
		}
		// Preload the textures
		if ( IPLOptions::getSingleton( ).mTextureFormat == "Image" )
		{
			IPLTexture_Image::preLoad( );
		}
	}
}

//-----------------------------------------------------------------------
void IPLVirtualPageWindow::_shufflePages( int ShiftX, int ShiftZ )
{
	// shuffle pages in active window to old window using ShiftX and ShiftZ as offsets
	// loop through window pages on z axis
	int newPos_x;
	int newPos_z;
	// flip old and active window references
	mActiveWindow.swap( mOldWindow );

	// if shift is greater than window size than make shift 0
	if ( ( ShiftX >= mWindowPageCount_x ) || ( ShiftX <= -mWindowPageCount_x ) )
	{
		ShiftX = 0;
	}
	if ( ( ShiftZ >= mWindowPageCount_z ) || ( ShiftZ <= -mWindowPageCount_z ) )
	{
		ShiftZ = 0;
	}

	for ( int z = 0; z < mWindowPageCount_z; z++ )
	{

		newPos_z = z + ShiftZ;
		if ( newPos_z < 0 )
		{
			newPos_z += mWindowPageCount_z;
		}
		else if ( newPos_z >=  mWindowPageCount_z )
		{
			newPos_z -= mWindowPageCount_z;
		}
		assert( newPos_z >= 0 );
		assert( newPos_z < mWindowPageCount_z );

		// loop through window pages on x axis
		for( int x = 0; x < mWindowPageCount_x; x++ )
		{
			// calculate new window pane position
			newPos_x = x + ShiftX;
			if ( newPos_x < 0 )
			{
				newPos_x += mWindowPageCount_x;
			}
			else if ( newPos_x >=  mWindowPageCount_x )
			{
				newPos_x -= mWindowPageCount_x;
			}

			assert( newPos_x >= 0 );
			assert( newPos_x < mWindowPageCount_x );

			// transfer page pointer from old window to active window
			mActiveWindow[ newPos_z ][ newPos_x ] = mOldWindow[ z ][ x ];

			// tell page about page index and position change
			mActiveWindow[ newPos_z ][ newPos_x ]->setWorldPosition( ( mAbsolutePageOffset_x + newPos_x ) * ( mPagePixelSize - 1 ) * mWorldScale_x,
																	 ( mAbsolutePageOffset_z + newPos_z ) * ( mPagePixelSize - 1 ) * mWorldScale_z );

			mActiveWindow[ newPos_z ][ newPos_x ]->setPageMapIndexes( ( mMapPageOffset_x + newPos_x ) % mWorldMap_PageCount_x,
																	  ( mMapPageOffset_z + newPos_z ) % mWorldMap_PageCount_z );
		}
	}
}

//-----------------------------------------------------------------------
bool IPLVirtualPageWindow::_isViewCentered(const float worldx, const float worldz) const 
{
	// check if world x is within x boundaries
	// check if world z is within z boundaries
	if( ((worldx <= mBoundryMaxX) && (worldx >= mBoundryMinX)) &&
		((worldz <= mBoundryMaxZ) && (worldz >= mBoundryMinZ)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//-----------------------------------------------------------------------
void IPLVirtualPageWindow::_setCenterAreaBoundries(const float worldx, const float worldz)
{
/*
	// center area must be slightly larger than the page size
	// this is so that when the window shifts the world view position will
	// be within in the center boundaries
	// if the boundaries are smaller than a page then a race condition develops
	// and the window keep shifting to try and position the view in the center area

	// use page coordinate in
	// given a world position need to center window based on page size
	// get window as close as page size possible
	// not sure how to do this
	// what formula is required
	// a page offset to position 0,0 of window is a start
	// once 0,0 calculated then rest is easy
	// world position is within a center area
	// center areas always the same position
	// so figure out root center position and go from there
	// so x page = worldposX / page size
	// this would give the absolute page count
	// to get the relative page index in the map use x page % map page count
	// to get map page index to window 0,0 position it would be to the left and down from the center
	// know window size 
	// divide by 2 to get the middle then take whole number ie (3-1)/2 = 1; (5-1)/2 = 2; (6-1)/2 = 2

*/
	// calculate new center area in world coordinates for the window

	const float WorldHalfPosition_x = (worldx * 2.0f) / (mPagePixelSize - 1) / mWorldScale_x;
	const float WorldHalfPosition_z = (worldz * 2.0f) / (mPagePixelSize - 1) / mWorldScale_z;

	// calculate the bottom left corner of the window position in absolute page indexes

	mAbsolutePageOffset_x = (int)floor((WorldHalfPosition_x - (mWindowPageCount_x - 1.0f))/2.0f);
	mAbsolutePageOffset_z = (int)floor((WorldHalfPosition_z - (mWindowPageCount_z - 1.0f))/2.0f);

	// calculate the center area boundaries
	mBoundryMinX = (((float)mAbsolutePageOffset_x  + (float)mWindowPageCount_x / 2.0f) - (0.5f + mBoundryExtent)) * mPagePixelSize * mWorldScale_x;
	mBoundryMaxX = mBoundryMinX + (2.0f * (0.5f + mBoundryExtent)) * mPagePixelSize * mWorldScale_x;

	mBoundryMinZ = (((float)mAbsolutePageOffset_z  + (float)mWindowPageCount_z / 2.0f) - (0.5f + mBoundryExtent)) * mPagePixelSize * mWorldScale_z;
	mBoundryMaxZ = mBoundryMinZ + (2.0f * (0.5f + mBoundryExtent)) * mPagePixelSize * mWorldScale_z;

	// set up map page offset indexes for bottom left corner of window at 0,0 within the map
	_getMapPageOffset(mAbsolutePageOffset_x, mAbsolutePageOffset_z, mMapPageOffset_x, mMapPageOffset_z);
}

//-----------------------------------------------------------------------
void IPLVirtualPageWindow::_getPageMapIdxFromWorldPosition(float x, float z, int & PageX, int & PageZ)
{
	_getWorldPageIndices( x, z, PageX, PageZ);
	_getMapPageOffset( PageX, PageZ, PageX, PageZ );
}

//-----------------------------------------------------------------------
void IPLVirtualPageWindow::_getMapPageOffset(const int AbsolutePage_x, const int AbsolutePage_z, int & MapPageOffsetX, int & MapPageOffsetZ)
{
	// calculate remainder of absolute page index / map size to get the page offset within the map
	MapPageOffsetX = AbsolutePage_x % mWorldMap_PageCount_x ;
	// if the remainder is less than zero then add the map size to get the relative page index into the map
	if (MapPageOffsetX < 0)
	{
		MapPageOffsetX += mWorldMap_PageCount_x;
	}
	MapPageOffsetZ = AbsolutePage_z % mWorldMap_PageCount_z ;
	if (MapPageOffsetZ < 0)
	{
		MapPageOffsetZ += mWorldMap_PageCount_z;
	}
}

//-----------------------------------------------------------------------
void IPLVirtualPageWindow::_getWorldPageIndices(const float worldx, const float worldz, int& PageX, int& PageZ)
{
	// find world page indexes as if the map had an infinite number of pages
	PageX = (int)(worldx / mWorldScale_x / (mPagePixelSize - 1.0 ) );
	PageZ = (int)(worldz / mWorldScale_z / (mPagePixelSize - 1.0 ) );
}

} // end of Ogre namespace