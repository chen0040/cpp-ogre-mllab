/***************************************************************************
	OgreIPLTile.cpp  

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

#include "OgreIPLTile.h"

#include "OgreIPLOptions.h"
#include "OgreIPLPage.h"

namespace Ogre
{

//-----------------------------------------------------------------------
IPLTile::IPLTile( IPLPage* page, const int indexX, const int indexZ )
{
	mPage = page;
	mX = indexX;
	mZ = indexZ;
	mLOD = IPLOptions::getSingleton( ).mTileLOD;
	mSize = 1 << mLOD;

	const Vector3 Scale = IPLOptions::getSingleton( ).scale;
	const int patch_size = 1 << IPLOptions::getSingleton( ).mPatchLOD;
	const size_t num_Patches = mSize / patch_size;

	mTileSceneNode = page->getPageNode( )->createChildSceneNode( );

	mTileSceneNode->setPosition( mX * mSize * Scale.x, 0, mZ * mSize * Scale.z );

	// set up all the little patches
	for ( size_t i = 0; i < num_Patches; i++ )
	{
		mPatches.push_back( IPLPatchRow( ) );

		for ( size_t j = 0; j < num_Patches; j++ )
		{
			mPatches[ i ].push_back( new IPLRenderable( this, ( int )i, ( int )j ) );
		}
	}
}

//-----------------------------------------------------------------------
IPLTile::~IPLTile( )
{
	release( );
}

//-----------------------------------------------------------------------
void IPLTile::release( void )
{
	// release the patch renderables 
	const size_t num_Patches = mPatches.size( );

	for ( size_t i = 0; i < num_Patches; i++ )
	{
		for ( size_t j = 0; j < num_Patches; j++ )
		{
			if(mPatches[ i ][ j ] != NULL)
			{
				delete mPatches[ i ][ j ];
				mPatches[ i ][ j ] = NULL;
			}
		}
	}
}

//-----------------------------------------------------------------------
IPLPage* IPLTile::getPage( void ) const
{
	return mPage;
}

//-----------------------------------------------------------------------
int IPLTile::getOffsetX( void ) const
{
	return mX * mSize;
}

//-----------------------------------------------------------------------
int IPLTile::getOffsetZ( void ) const
{
	return mZ * mSize;
}

//-----------------------------------------------------------------------
SceneNode* IPLTile::getTileNode( void ) const
{
	return mTileSceneNode;
}

} //namespace