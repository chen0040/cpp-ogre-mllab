/***************************************************************************
	OgreIPLTile.h 

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

#ifndef __IPLTILE_H__
#define __IPLTILE_H__

#include "OgreIPLRenderable.h"

#include <OgreSceneNode.h>

namespace Ogre
{
class IPLPage;

class IPLTile 
{
public:
	IPLTile( IPLPage* page, const int indexX, const int indexZ );

	~IPLTile( );

	void release( void );

	IPLPage* getPage( void ) const;

	int getOffsetX( void ) const;

	int getOffsetZ( void ) const;

	SceneNode* getTileNode( void ) const;

private:
	typedef std::vector < IPLRenderable* > IPLPatchRow;
	typedef std::vector < IPLPatchRow > IPLPatches;

	int mLOD;
	int mSize;

	IPLPage* mPage;

	SceneNode* mTileSceneNode;

	// container for the renderable patches
	IPLPatches mPatches;

	float mX;			// Position of this Terrain Tile in the Terrain Page Array
	float mZ;
};

} //namespace

#endif