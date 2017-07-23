/***************************************************************************
	OgreIPLPage.h  

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

#ifndef __IPLPAGE_H__
#define __IPLPAGE_H__

#include "OgreIPLTile.h"
#include "OgreIPLData2D.h"
#include "OgreIPLTexture.h"

#include <vector>

namespace Ogre
{

class Image;
class IPLVirtualPageWindow;

typedef std::vector < IPLTile * > IPLTileRow;
typedef std::vector < IPLTileRow > IPLTileContainer;

class IPLPage
{
public:
	
	IPLPage( IPLVirtualPageWindow* vw );
    
	virtual ~IPLPage( void );

	/** loads the landscape data and base texture from the cache */
	void load( void );

	/** Unloads the landscape data, and destroys the landscape tiles within the page. */
	void unload( void );

	/** set the real world position of the page
		@remarks the page will modify the position of its scene node
					page indexes are not modified so all that is happening is
					the terrain will shift position in the world
		
		@param startx position in world on x axis that top left corner of page sits
		@param startz position in world on z axis that top left corner of page sits
	*/
	void setWorldPosition( const float startx, const float startz );

	/** set the page indexes within the map
		@remarks the page will reload itself with the proper height data
					if the new indexes are different than the current
		
		@param x index into Map on x axis for page
		@param z index into Map on z axis for page
	*/
	void setPageMapIndexes( const int x, const int z );

    int _getHeight( int x, int z );

	Real _getWorldHeight( int x, int z );

	/** Get the real world height at a particular position within the page
		@remarks
			Method is used to get the terrain height at a position based on x and z that is local to the page.
			This method just figures out what tile the position is on and then asks the tile node
			to do the dirty work of getting the height. Again passing the buck.
		@par
			the float returned is the real world height based on the scale of the world.  If the height could
			not be determined then -1 is returned and this would only occur if the page was not preloaded or loaded
		
		@param x  x position relative to page and in page scale
		@param z  z position relative to page and in page scale
	*/
	float getRealWorldHeight( float x, float z );

	Material* getMaterial( void ) const;

	SceneNode* getPageNode( void ) const;

	IPLData2D* getHeightData( void ) const;

	IPLTexture* getTexture( void ) const;

	unsigned int getID( void ) const;

private:
	void _loadData2D( void );

	void _loadTexture( void );

	SceneNode*				mPageNode;
	IPLData2D*				mData;
	IPLTexture*				mTexture;

	IPLVirtualPageWindow*	mVirtualWindow; // the virtual window taking care of the page

	int						mX;				// Position of this Terrain Page in the Terrain Page Array
	int						mZ;

	float					mIniX;			// real world location on x axis
	float					mIniZ;			// real world location on z axis
	unsigned int			mID;			// ID key used by patches to tell them if page changed
		
	// container holding the tiles that make up the page
	IPLTileContainer mTileContainer;

	//
	static int mPageCount;
};

}

#endif
