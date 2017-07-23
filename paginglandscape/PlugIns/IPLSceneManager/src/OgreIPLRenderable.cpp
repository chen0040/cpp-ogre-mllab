/***************************************************************************
  OgreIPLRenderable.cpp 

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

#include "OgreIPLRenderable.h"

#include "OgreIPLPrerequisites.h"
#include "OgreIPLOptions.h"
#include "OgreIPLIndexBuffer.h"
#include "OgreIPLPage.h"
#include "OgreIPLData2D.h"

#include <OgreSceneNode.h>
#include <OgreStringConverter.h>
#include <OgreRenderOperation.h>
#include <OgreCamera.h>
#include <OgreRoot.h>
#include <OgreMath.h>
#include <OgreHardwareBufferManager.h>
#include <OgreHardwareVertexBuffer.h>
#include <OgreHardwareIndexBuffer.h>

namespace Ogre
{
//-----------------------------------------------------------------------
int IPLRenderable::mRenderedTris = 0;
String IPLRenderable::mType = "IPLRenderable";

//-----------------------------------------------------------------------
IPLRenderable::IPLRenderable( IPLTile* tile, const int x, const int z )
{
	mTile		 = tile;
	mName		 = "Patch." + StringConverter::toString( x ) + "." + StringConverter::toString( z );
	mRenderLevel = 0;
	mLOD		 = IPLOptions::getSingleton( ).mPatchLOD;
	mMaterialLODIndex = 0;
	mSize		 = 1 << mLOD;
	mOffsetX	 = x * mSize;
	mOffsetZ	 = z * mSize;
	// start ID at 0; page should start at 1 which will force an update
	mID			 = 0;

	// attach a new scene node to the tile scene node
	SceneNode* patchNode = mTile->getTileNode( )->createChildSceneNode( );

	// set the new node position relative to the tile node position
	const Vector3 scale	= IPLOptions::getSingleton( ).scale;
	patchNode->setPosition( mOffsetX * scale.x, 0, mOffsetZ * scale.z );
	patchNode->attachObject( this );

	// initialize the vertex buffer only once
	_buildVertexBuffer( );
	// force init so that the patch has a bounding box and will get triggered when visible
	_init( );
}

//-----------------------------------------------------------------------
IPLRenderable::~IPLRenderable( void )
{
	release( );
}

//-----------------------------------------------------------------------
void IPLRenderable::release( void )
{
	if ( mRend.indexData != 0 )
	{
		mRend.indexData = 0;
	}

	if ( mRend.vertexData != 0 )
	{
		delete mRend.vertexData;
		mRend.vertexData = 0;
	}
}

//-----------------------------------------------------------------------
const String& IPLRenderable::getName( void ) const
{
	return mName;
}

//-----------------------------------------------------------------------
const String& IPLRenderable::getMovableType( void ) const
{
	return mType;
}

//-----------------------------------------------------------------------
const AxisAlignedBox& IPLRenderable::getBoundingBox( void ) const
{
	return mPatchAABB;
}

//-----------------------------------------------------------------------
void IPLRenderable::_notifyCurrentCamera( Camera* cam )
{

	// Material LOD
	if ( getMaterial()->getNumLodLevels() > 1 )
	{
		mMaterialLODIndex = getMaterial()->getLodIndexSquaredDepth( getSquaredViewDepth( cam ) );
	}

	// check to see if within radius visibility
	// use distance from camera to renderable centre position < radius
	float viewRatio = getSquaredViewDepth( cam ) / IPLOptions::getSingleton( ).visibilityRadiusSquared;

	// don't let view ratio get to large or it will screw up the visibility level calculation
	if ( viewRatio > 1.1f )
	{
		viewRatio = 1.1f;
	}

	// renderable is only visible if view ratio is less than 1 meaning its in the view radius
	setVisible( viewRatio < 1.0f );
	// LOD decreases as renderable gets closer to edge of view radius which means render Level increases

	// partition the chunk data build process
	// start building hopefully just before renderable comes into view
	if ( viewRatio < 1.1f )
	{
		// check to see if the patch needs to be rebuilt because the page changed
		// only do a rebuild if the last rebuild is complete
		if ( ( mBuildStep < 1 ) && ( mID != mTile->getPage( )->getID( ) ) )
		{
			_init( );
			// adjust build step count based on distance from the camera
			// the farther away the patch is when it first comes into view the longer it takes to build
			mBuildStep = 2 + viewRatio * 2;
		};

		if ( mBuildStep > 0 )
		{
			mBuildStep--;
			// since vertex data not ready then don't make renderable visible
			setVisible( false );
			switch ( mBuildStep ) 
			{
			case 0:
				mPatchAABB.setExtents( 0, mMin, 0, ( Real )( mSize * IPLOptions::getSingleton( ).scale.x ), mMax, ( Real )( mSize * IPLOptions::getSingleton( ).scale.z ) );
				mParentNode->needUpdate( );
				mRend.indexData = IPLIndexBuffer::getSingleton( ).getIndexData( this );
				break;

			case 1:
				_buildVertexData( );
				break;
			}
		}
	}
}

//-----------------------------------------------------------------------
void IPLRenderable::_updateRenderQueue( RenderQueue* queue )
{
	queue->addRenderable( this );
}

//-----------------------------------------------------------------------
Technique* IPLRenderable::getTechnique(void) const
{
	return getMaterial( )->getBestTechnique(mMaterialLODIndex);
}

//-----------------------------------------------------------------------
Real IPLRenderable::getBoundingRadius( void ) const
{
	return 0; /* not needed */
}

//-----------------------------------------------------------------------
void IPLRenderable::getRenderOperation( RenderOperation& rend )
{
	rend = mRend;
}

//-----------------------------------------------------------------------
Material* IPLRenderable::getMaterial( void ) const
{
	return mTile->getPage( )->getTexture( )->getMaterial( );
}

//-----------------------------------------------------------------------
void IPLRenderable::getWorldTransforms( Matrix4* xform ) const
{
	*xform = mParentNode->_getFullTransform( );
}

//-----------------------------------------------------------------------
const Quaternion& IPLRenderable::getWorldOrientation( void ) const
{
	return mParentNode->_getDerivedOrientation( );
}

//-----------------------------------------------------------------------
const Vector3& IPLRenderable::getWorldPosition( void ) const
{
	return mParentNode->_getDerivedPosition( );
}

//-----------------------------------------------------------------------
Real IPLRenderable::getSquaredViewDepth( const Camera* cam ) const
{
	//	return mParentNode->getSquaredViewDepth( cam );
	Vector3 diff = cam->getDerivedPosition( ) - mParentNode->getWorldPosition( );
	return ( diff.x * diff.x + diff.z * diff.z );
}

//-----------------------------------------------------------------------
const LightList& IPLRenderable::getLights( void ) const
{
	return mParentNode->getLights( );
}

//-----------------------------------------------------------------------
SceneDetailLevel IPLRenderable::getRenderDetail( void )
{
	return SDL_SOLID;
}

//-----------------------------------------------------------------------
int IPLRenderable::getRenderLevel( void ) const
{
	return mRenderLevel;
}

//-----------------------------------------------------------------------
int IPLRenderable::getRenderSize( void ) const
{
	return mSize;
}

//-----------------------------------------------------------------------
Real IPLRenderable::getViewDepth( const Camera* cam ) const
{
	Vector3 diff = cam->getDerivedPosition( ) - mParentNode->getWorldPosition( );
	return sqrt( diff.x * diff.x + diff.z * diff.z );
}

//-----------------------------------------------------------------------
void  IPLRenderable::_init( void )
{
	// new build required
	mBuildStep = -1;

	const Vector3 scale	= IPLOptions::getSingleton( ).scale;
	mPatchAABB.setExtents( 0, 0, 0, ( Real )( mSize * scale.x ), 100 * scale.y, ( Real )( mSize * scale.z ) );
	mParentNode->needUpdate( );
}

//-----------------------------------------------------------------------
void IPLRenderable::_buildVertexBuffer( void )
{
	mRend.vertexData = new VertexData( );
	mRend.vertexData->vertexStart = 0;
	mRend.vertexData->vertexCount = ( mSize + 1 ) * ( mSize + 1 ); 

	// Vertex declaration
	VertexDeclaration* decl = mRend.vertexData->vertexDeclaration;
	VertexBufferBinding* binding = binding = mRend.vertexData->vertexBufferBinding;

	size_t offset = 0;

	decl->addElement( POSITION_BINDING, 0, VET_FLOAT3, VES_POSITION, 0 );
	offset += VertexElement::getTypeSize( VET_FLOAT3 );

	// Normal 
	decl->addElement( POSITION_BINDING, offset, VET_FLOAT3, VES_NORMAL,0 );
	offset += VertexElement::getTypeSize( VET_FLOAT3 );

	// texture coordinate sets
	decl->addElement( POSITION_BINDING, offset, VET_FLOAT2, VES_TEXTURE_COORDINATES, 0 );
	offset += VertexElement::getTypeSize( VET_FLOAT2 );
	decl->addElement( POSITION_BINDING, offset, VET_FLOAT2, VES_TEXTURE_COORDINATES, 1 );

	// Vertex buffer #1: position
	HardwareVertexBufferSharedPtr vbuf = HardwareBufferManager::getSingleton( ).createVertexBuffer(
			decl->getVertexSize( POSITION_BINDING ), 
			mRend.vertexData->vertexCount,
			HardwareBuffer::HBU_STATIC_WRITE_ONLY, false );

	binding->setBinding( POSITION_BINDING, vbuf );

	//No need to set the indexData since it is shared from LandScapeIndexBuffer class
	mRend.operationType = RenderOperation::OT_TRIANGLE_STRIP;
	mRend.useIndexes = true;
}

//-----------------------------------------------------------------------
void IPLRenderable::_buildVertexData( void )
{
	struct UVSplat 
	{
		float startU;
		float startV;
		float endU;
		float endV;
	};

	static UVSplat splatUVTable[ ] = 
	{
		//// bottom left
		{0, 0, 1, 1},
		//{0, 1, 1, 0},
		//{1, 0, 0, 1},
		//{1, 1, 0, 0},

		//{0, 0, 0.5, 0.5},
		//{0, 0.5, 0.5, 0},
		//{0.5, 0, 0, 0.5},
		//{0.5, 0.5, 0, 0},

		//// bottom right
		//{0.5, 0.0, 1.0, 0.5},
		//{1.0, 0.0, 0.5, 0.5},
		//{0.5, 0.5, 1.00, 0.0},
		//{1.0, 0.5, 0.5, 0.0},

		//// top left
		//{0.0, 1.0, 0.5, 0.5},
		//{0.5, 0.5, 0.0, 1.0},
		//{0.0, 0.5, 0.5, 1.0},
		//{0.5, 1.0, 0.0, 0.5},

		//// top right
		//{0.5, 0.5, 1.0, 1.0},
		//{1.0, 1.0, 0.5, 0.5},
		//{0.5, 1.0, 1.0, 0.5},
		//{1.0, 0.5, 0.5, 1.0},

	};

	VertexBufferBinding* binding = mRend.vertexData->vertexBufferBinding; 

	//calculate min and max heights;
	mMin = 256000, mMax = 0;
	// randomly pick texture coordinates for splat
	// currently disabled
	int splatIndex = 0;//rand()%16;
	float baseSplatU = splatUVTable[ splatIndex ].startU;
	float baseSplatV = splatUVTable[ splatIndex ].startV;
	float splat_dU = splatUVTable[ splatIndex ].endU - baseSplatU;
	float splat_dV = splatUVTable[ splatIndex ].endV - baseSplatV;

	const int startx = mTile->getOffsetX( ) + mOffsetX;
	const int startz = mTile->getOffsetZ( )+ mOffsetZ;
	const int endx = startx + mSize;
	const int endz = startz + mSize;
	const Real Aux1 = IPLOptions::getSingleton( ).PageSize - 1;

	// This allow to reuse the variables in the loop
	Real height, baseTex_V, splatTex_V;

	Vector3 norm;

	// Lock the Vertices
	HardwareVertexBufferSharedPtr vVertices = binding->getBuffer( POSITION_BINDING );
	Real *pVertices = static_cast<Real*>( vVertices->lock( HardwareBuffer::HBL_DISCARD ) );

	IPLData2D* heightData = mTile->getPage( )->getHeightData( );
	const Vector3 scale	= IPLOptions::getSingleton( ).scale;
	const float detailRepeat = IPLOptions::getSingleton( ).mPatchDetailRepeat;

	for ( int k = startz; k <= endz; k++ )
	{
		baseTex_V = ( ( Real )k ) / Aux1;
		splatTex_V = ( baseSplatV + splat_dV * ( ( Real )k - startz ) / mSize ) * detailRepeat;
		for ( int i = startx; i <= endx; i++ )
		{
			height = heightData->getHeight( i, k ) * scale.y;
			// vertices are relative to the scene node
			*pVertices++ = ( Real )( ( i - startx ) * scale.x );	//X
			*pVertices++ = height;									//Y
			*pVertices++ = ( Real )( ( k - startz ) * scale.z );	//Z

			// place the normal vector in the buffer
			heightData->getNormalAt( i, k, &norm );
			*pVertices++ = norm.x;
			*pVertices++ = norm.y;
			*pVertices++ = norm.z;

			// place the first texture coordinate in the buffer
			*pVertices++ = ( ( Real )i ) / Aux1;	
			*pVertices++ = baseTex_V;

			// place the splat texture coordinate in the buffer
			*pVertices++ = ( baseSplatU + splat_dU * ( ( Real )i - startx ) / mSize ) * detailRepeat;	
			*pVertices++ = splatTex_V; 

			if ( height < mMin )
			{
				mMin = ( Real )height;
			}
			if ( height > mMax )
			{
				mMax = ( Real )height;
			}
		}
	}

	// Unlock the buffers
	vVertices->unlock( );

	// buffer is up to date with page setting
	mID = mTile->getPage( )->getID( );
}

} //namespace
