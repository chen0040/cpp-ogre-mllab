/***************************************************************************
	OgreIPLVirtualPageWindow.h  

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

#ifndef __IPLVIRTUALPAGEWINDOW_H__
#define __IPLVIRTUALPAGEWINDOW_H__

#include "OgreIPLPage.h"

#include <OgreSceneNode.h>

namespace Ogre
{

class IPLSceneManager;

/** This is a virtual window page manager for organizing Pages into a visible landscape.
*/
class IPLVirtualPageWindow
{
public:
	IPLVirtualPageWindow( IPLSceneManager* sm );
	virtual ~IPLVirtualPageWindow( );

	/**  setup page windows by initializing both page vector containers
			to the required size and fill with pages in active window and NULL 
			in old window

		@param xcount number of pages in window on x axis
		@param zcount number of pages in window on z axis
	*/
	void setPageWindowSize( const int xcount, const int zcount );

	/** update the window view based on the new position
		@remarks
			the window manager will shift the window view if
			the view position is outside the view boundaries
			if the view position is still in the view boundaries then nothing is done
	*/
	void updateViewPosition( const float x, const float z );

	/** change the parameters that define how big the world map is

		@param PageXCount number of pages that are along the X axis in the Map
		@param PageZCount number of pages that are along the Z axis in the Map
		@param PagePixelSize is the width and height in pixel of the height map data that defines the page
	*/	
	void setWorldMapSize( const int PageXCount, const int PageZCount, const int PagePixelSize );

	/** change the wold scale - values must be > 0
	*/
	void setWorldScale( const float x, const float z );

	/** get the height of the terrain at the world coordinates x,z
		@remarks
			if the world coordinates are within the virtual page window then the actual world height
			is returned.  If outside the virtual window then -1 is returned

		@param worldx real world position on x axis
		@param worldz real world position on z axis
	*/
	float getWorldHeight( float worldx, float worldz );

	IPLSceneManager* getSceneManager( void ) const;

	SceneNode* getRootSceneNode( void ) const;

private:

	void _preLoad( void );

	/** swap ActiveWindow and OldWindow.  Normally done after the pages have been shuffled in the window.
	*/
	void _switchWindow( void ); // TODO: Not implemented

	/** shift the pages in the active window into the Old window
		after the shift each page is informed of its new map index and new position for the scene node
		Swap Active window with old window so the shuffled windows become the active view

		@param ShiftX number of pages to shift on the x axis
		@param SHiftY number of pages to shift on the z axis
	*/
	void _shufflePages( const int ShiftX, const int ShiftY );

	/** notify pages in window of what map indexes and scene node position they should have
		this method would be called after calling shufflePages
		It is up to the pages to decide if they need to unload and reload.  Moving the scene node is upto them.
	*/
	void _updatePageMapIndexes( void ); // TODO: Not implemented

	/** checks if the world coordinates are within the window center region
		returns true if the view is within the boundaries
	
		@param worldx position on x axis in the world
		@param worldz position on z axis in the world	
	*/
	bool _isViewCentered( const float worldx, const float worldz ) const ;

	/** using the world coordinates as the new center view position calculate
		min x,max x, min v and max v that define the center boundaries.  These boundaries are
		used by isVeiwCentered to determine if the view position is still within
		the center boundaries

		@param x world position on world x axis
		@param z world position on world y axis
	*/
	void _setCenterAreaBoundries( const float worldx, const float worldz );

	/** convert world coordinates into page map index
		assumes the map repeats in x and z direction in the world
		works for negative coordinates also
		normally used to find the center page in the window
		
		@param x world coordinate on x axis
		@param z world coordinate on z axis
		@param PageX reference to page index on x axis that will receive converted value
		@param PageZ reference to page index on z axis that will receive converted value
	*/
	void _getPageMapIdxFromWorldPosition( float x, float z, int & PageX, int & PageZ );

	/** get the Map Page offsets using absolute page indexes
		@remarks the method assumes that the map is repeating in both x and z coordinates and that the map
				has a size equal or greater to one on both axis
	
		@param AbsolutePage_x page index on x axis
		@param AbsolutePage_z page index on z axis
		@param MapPageOffestX reference that will receive the page offset in relation to the map on the x axis
		@param MapPageOffestZ reference that will receive the page offset in relation to the map on the z axis
	*/
	void _getMapPageOffset( const int AbsolutePage_x, const int AbsolutePage_z, int & MapPageOffsetX, int & MapPageOffsetZ );

	/** Get the Page absolute indices from a world position vector
		@remarks
			Method is used to find the Page indices using a world position.
			Beats having to iterate through the Page list to find a page at a particular
			position in the world.
			The page indices returned are not clamped to the map page count.
			
		@param worldx position on x axis
		@param worldz position on z axis
		@param x	result placed in reference to the x index of the page
		@param z	result placed in reference to the z index of the page
	*/
	void _getWorldPageIndices( const float worldx, const float worldz, int& x, int& z );

	float	mWorldScale_x;
	float	mWorldScale_z;
	int		mPagePixelSize;
	float	mBoundryExtent;

	int		mWindowPageCount_x;		// number of pages that make up the window along the x axis
	int		mWindowPageCount_z;		// number of pages that make up the window along the z axis

	int		mWorldMap_PageCount_x;	// number of pages that make up the map along x axis
	int		mWorldMap_PageCount_z;	// number of pages that make up the map along z axis
	int		mAbsolutePageOffset_x;  // position of window in absolute page index from origin on x axis
	int		mAbsolutePageOffset_z;  // position of window in absolute page index from origin on z axis

	int		mMapPageOffset_x;		// relative Map page index for bottom left corner of Window on x axis
	int		mMapPageOffset_z;		// relative Map page index for bottom left corner of Window on z axis

	// center area boundary
	float	mBoundryMinX; 
	float	mBoundryMinZ;
	float	mBoundryMaxX;
	float	mBoundryMaxZ;

	IPLSceneManager* mSceneManager;
	SceneNode* mRootSceneNode;

	typedef std::vector < IPLPage * > IPLPageRow;
	typedef std::vector < IPLPageRow > IPLPages;

	IPLPages mActiveWindow;
	IPLPages mOldWindow;
};

}

#endif
