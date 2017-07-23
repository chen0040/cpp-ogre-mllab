/***************************************************************************
  OgreIPLRenderable.h

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

#ifndef __IPLRENDERABLE_H__
#define __IPLRENDERABLE_H__

#include <vector>

#include <OgreRenderable.h>
#include <OgreMovableObject.h>
#include <OgreString.h>
#include <OgreVertexIndexData.h>
#include <OgreNode.h>

namespace Ogre
{

class IPLTile;

/** Represents a landscape page.
	@remarks
		A LandScapeRenderable represents a page used to render a block of landscape using the procedural terrain approach for LOD.
*/

class IPLRenderable : public Renderable,
					  public MovableObject
{
public:

	/** Initializes the LandScapeRenderable with the given options and the starting coordinates of this block.
	*/
	IPLRenderable( IPLTile* tile, const int x, const int z );

	~IPLRenderable( void );

	void release( void );

	//movable object methods
	/** Returns the name of the LandScapeRenderable 
	*/
	const String& getName( void ) const;

	/** Returns the type of the movable. 
	*/
	const String& getMovableType( void ) const;

	/** Returns the bounding box of this LandScapeRenderable 
	*/
	const AxisAlignedBox& getBoundingBox( void ) const;

	/** Updates the level of detail to be used for rendering this IPLRenderable based on the passed in Camera 
	*/
	void _notifyCurrentCamera( Camera* cam );

	void _updateRenderQueue( RenderQueue* queue );

	virtual Technique* getTechnique(void) const;

	/** Overridden from MovableObject */
	Real getBoundingRadius( void ) const;

	/** Constructs a RenderOperation to render the LandScapeRenderable.
		@remarks
			Each LandScapeRenderable has a block of vertices that represent the landscape.
	*/
	void getRenderOperation( RenderOperation& rend );

	// provide method for renderable abstract method
	Material* IPLRenderable::getMaterial( void ) const;

	void getWorldTransforms( Matrix4* xform ) const;

	const Quaternion& getWorldOrientation( void ) const;

	const Vector3& getWorldPosition( void ) const;

	/** Overridden, see Renderable */
	Real getSquaredViewDepth( const Camera* cam ) const;

	/** @copydoc Renderable::getLights */
	const LightList& getLights( void ) const;

	SceneDetailLevel getRenderDetail( void );

	int getRenderLevel( void ) const;
	
	int getRenderSize( void ) const;
	
	Real getViewDepth( const Camera* cam ) const;

	static int mRenderedTris;

private:
	void _init( void );

	// build vertex data into pre allocated buffer
	void _buildVertexData( void );

	// build a vertex buffer to hold the vertex data
	void _buildVertexBuffer( void );

	//movable object variables
	String mName;
	static String mType;

	IPLTile* mTile;

	float mMax;
	float mMin;
    int mRenderLevel;
	int mBuildStep;
	int mLOD;
	int mMaterialLODIndex;
	int mOffsetX;
	int mOffsetZ;
	int mSize;
	RenderOperation mRend;
	AxisAlignedBox mPatchAABB;
	// ID of page when patch was last updated
	unsigned int mID;
};

}

#endif
