/***************************************************************************
	OgreIPLPage.cpp  

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

#include "OgreIPLPage.h"

#include "OgreIPLOptions.h"
#include "OgreIPLSceneManager.h"

// specialized data loaders
#include "OgreIPLData2D_HeightField.h"
#include "OgreIPLData2D_HeightFieldTC.h"
#include "OgreIPLData2D_Spline.h"

// specialized texture loaders
#include "OgreIPLTexture_Image.h"
#include "OgreIPLTexture_BaseTexture.h"
#include "OgreIPLTexture_BaseTexture2.h"
#include "OgreIPLTexture_Splatting1.h"

#include <OgreStringConverter.h>
#include <OgreMaterialManager.h>
#include <OgreSceneNode.h>
#include <OgreTechnique.h>
#include <OgrePass.h>
#include <OgreTextureUnitState.h>
#include <OgreException.h>

namespace Ogre
{
//-----------------------------------------------------------------------
// initialize static members
int IPLPage::mPageCount = 0;

//-----------------------------------------------------------------------
IPLPage::IPLPage( IPLVirtualPageWindow* vw )
{
	// keep track of how many pages are created
	// used for unique name generation
	mPageCount++;

	// default position
	mX = -1;
	mZ = -1;
	mPageNode = NULL;

	mVirtualWindow = vw;

	_loadData2D( );

	_loadTexture( );

	// setup page with scene node and tiles if not already done	
	// only happens once during lifetime of page
	mPageNode = mVirtualWindow->getRootSceneNode( )->createChildSceneNode( );

	// build tiles
	const int tile_size = 1 << IPLOptions::getSingleton( ).mTileLOD;
	const size_t num_tiles = ( IPLOptions::getSingleton( ).PageSize ) / tile_size;

	// start off with mID at a low value of one
	// assume patches will start their ID at 0 so that they must update
	mID = 1;

	// create all the tiles within the page
	for ( int i = 0; i < ( int )num_tiles; i++ )
	{
		mTileContainer.push_back( IPLTileRow( ) );

		for ( int j = 0; j < ( int )num_tiles; j++ )
		{
			mTileContainer[ i ].push_back( new IPLTile( this, i, j ) );
		}
	}
}

//-----------------------------------------------------------------------
IPLPage::~IPLPage( void )
{
	unload( );
	mPageCount--;
}

//-----------------------------------------------------------------------
void IPLPage::load( void )
{
	// load the height data
	mData->load( mX, mZ );

	mTexture->load( mX, mZ );
}

//-----------------------------------------------------------------------
void IPLPage::unload( void )
{
	// Unload the pages

	if ( mPageNode != NULL )
	{
		// Unload the nodes
		// detach the tile from the scene node
		mPageNode->detachAllObjects( );
		// get rid of child scene nodes
		mPageNode->removeAndDestroyAllChildren( );

		static_cast< SceneNode* >( mPageNode -> getParent( ) )->removeAndDestroyChild( mPageNode->getName( ) );
		mPageNode = NULL;
	}

	if ( mData != 0 )
	{
		delete mData;
		mData = 0;
	}

	if ( mTexture != 0 )
	{
		delete mTexture;
		mTexture = 0;
	}

	const int size = ( int )mTileContainer.size( );
	for ( int i = 0; i < size; i++ )
	{
		for ( int j = 0; j < size; j++ )
		{
			if ( mTileContainer[ i ][ j ] != NULL )
			{
				delete mTileContainer[ i ][ j ];
			}
		}
	}
}

//-----------------------------------------------------------------------
void IPLPage::setWorldPosition( const float startx, const float startz )
{
	mIniX = startx;
	mIniZ = startz;

	mPageNode->setPosition( ( Real )mIniX , 0.0, ( Real )mIniZ );
}

//-----------------------------------------------------------------------
void IPLPage::setPageMapIndexes( const int x, const int z )
{
	// if map indexes are changing then unload the page and reload
	if ( ( x != mX ) || ( z != mZ ) )
	{
		// x and z should never be negative
		assert( x >= 0 );
		assert( z >= 0 );

		mX = x;
		mZ = z;

		// load the page data from the cache
		load( );
		// change the page ID to force patches to update when they become visible
		mID++;
	}
}

//-----------------------------------------------------------------------
int IPLPage::_getHeight( int x, int z )
{
	return mData->getHeight( x, z );
}

//-----------------------------------------------------------------------
Real IPLPage::_getWorldHeight( int x, int z )
{
	return mData->getHeight( ( abs( x ) - abs( mIniX ) ) / IPLOptions::getSingleton( ).scale.x, ( abs( z ) - abs( mIniZ ) ) / IPLOptions::getSingleton( ).scale.z ) * IPLOptions::getSingleton( ).scale.y;
}

//-----------------------------------------------------------------------
float IPLPage::getRealWorldHeight( float x, float z )
{
	return mData->getInterpolatedHeight( x, z ) * IPLOptions::getSingleton( ).scale.y;
}

//-----------------------------------------------------------------------
SceneNode* IPLPage::getPageNode( void ) const
{
	return mPageNode;
}

//-----------------------------------------------------------------------
IPLData2D* IPLPage::getHeightData (void ) const
{
	return mData;
}

//-----------------------------------------------------------------------
IPLTexture* IPLPage::getTexture( void ) const
{
	return mTexture;
}

//-----------------------------------------------------------------------
unsigned int IPLPage::getID( void ) const
{
	return mID;
}

//-----------------------------------------------------------------------
void IPLPage::_loadData2D( void )
{
	// set the specialized to the data loader
	if ( IPLOptions::getSingleton( ).mData2DFormat == "HeightField" )
	{
		mData = new IPLData2D_HeightField( );
	}
	else if ( IPLOptions::getSingleton( ).mData2DFormat == "HeightFieldTC" )
	{
		mData = new IPLData2D_HeightFieldTC( );
	}
	else if ( IPLOptions::getSingleton( ).mData2DFormat == "SplineField" )
	{
		mData = new IPLData2D_Spline( );
	}
	else
	{
		mData = 0;
		Except( Exception::ERR_INVALIDPARAMS, "IPLData2D not supplied!", "IPLTextureManager::_loadData2D" );
	}
}

//-----------------------------------------------------------------------
void IPLPage::_loadTexture( void )
{
	// set the specialized texture loader
	if ( IPLOptions::getSingleton( ).mTextureFormat == "Image" )
	{
		mTexture = new IPLTexture_Image( this );
	}
	else if ( IPLOptions::getSingleton( ).mTextureFormat == "BaseTexture" )
	{
		mTexture = new IPLTexture_BaseTexture( this );
	}
	else if ( IPLOptions::getSingleton( ).mTextureFormat == "BaseTexture2" )
	{
		mTexture = new IPLTexture_BaseTexture2( this );
	}
	else if ( IPLOptions::getSingleton( ).mTextureFormat == "Splatting1" )
	{
		mTexture = new IPLTexture_Splatting1( this );
	}
	else
	{
		mTexture = 0;
		Except( Exception::ERR_INVALIDPARAMS, "IPLTexture not supplied!", "IPLTextureManager::_loadTexture" );
	}
	mTexture->setupMaterial( mPageCount, mVirtualWindow );
}

} //namespace
