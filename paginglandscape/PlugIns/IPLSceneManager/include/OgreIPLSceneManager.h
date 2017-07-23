/***************************************************************************
	OgreIPLSceneManager.h  -  description: a very basic terrain scenemanager that can handle any size terrain

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

#ifndef __IPLSCENEMANAGER_H__
#define __IPLSCENEMANAGER_H__

#include "OgreIPLPage.h"
#include "OgreIPLVirtualPageWindow.h"

#include <OgreSceneManager.h>

namespace Ogre
{

class Image;
class IPLIntersectionSceneQuery;
class IPLRaySceneQuery;


/** This is a basic SceneManager for organizing IPLRenderables into a total landscape.
	It loads a LandScape from a .cfg file that specifices what textures/scale/virtual window/etc to use.
*/
class IPLSceneManager : public SceneManager
{
	friend class IPLIntersectionSceneQuery;
	friend class IPLRaySceneQuery;

public:
	IPLSceneManager( );
	~IPLSceneManager( );

	/** Loads the LandScape using parameters int he given configuration file.
	*/
	void setWorldGeometry( const String& filename );

	/** Empties the entire scene, including all SceneNodes, Cameras, Entities and Lights etc.
	*/
	void clearScene( void );

	/** Internal method for updating the scene graph ie the tree of SceneNode instances managed by this class.
		@remarks
			This must be done before issuing objects to the rendering pipeline, since derived transformations from
			parent nodes are not updated until required. This SceneManager is a basic implementation which simply
			updates all nodes from the root. This ensures the scene is up to date but requires all the nodes
			to be updated even if they are not visible. Subclasses could trim this such that only potentially visible
			nodes are updated.
	*/
	void _updateSceneGraph( Camera * cam );

	/** Creates a RaySceneQuery for this scene manager. 
		@remarks
			This method creates a new instance of a query object for this scene manager, 
			looking for objects which fall along a ray. See SceneQuery and RaySceneQuery 
			for full details.
		@par
			The instance returned from this method must be destroyed by calling
			SceneManager::destroyQuery when it is no longer required.
		@param ray Details of the ray which describes the region for this query.
		@param mask The query mask to apply to this query; can be used to filter out
			certain objects; see SceneQuery for details.
	*/
	RaySceneQuery* createRayQuery( const Ray& ray, unsigned long mask = 0xFFFFFFFF );

	/** Creates an IntersectionSceneQuery for this scene manager. 
		@remarks
			This method creates a new instance of a query object for locating
			intersecting objects. See SceneQuery and IntersectionSceneQuery
			for full details.
		@par
			The instance returned from this method must be destroyed by calling
			SceneManager::destroyQuery when it is no longer required.
		@param mask The query mask to apply to this query; can be used to filter out
			certain objects; see SceneQuery for details.
	*/
	IntersectionSceneQuery* createIntersectionQuery( unsigned long mask );

	/** Get the real world height at a particular position
		@remarks
			Method is used to get the terrain height at a world position based on x and z.
			This method just figures out what page the position is on and then asks the page node
			to do the dirty work of getting the height.

		@par
			the float returned is the real world height based on the scale of the world.  If the height could
			not be determined then -1 is returned and this would only occur if the page was not preloaded or loaded

		@param x  x world position
		@param z  z world position
	*/
	float getRealWorldHeight( const float x, const float z );

private:
	EntityList& getEntities( )
	{
		return mEntities;
	}

	/** LandScape pages for the terrain held in the virtual window.
	*/
	IPLVirtualPageWindow * mVirtualPageWindow;

	Vector3 mLastCameraPos;

	//flag to indicate if the world geometry was setup
	bool mWorldGeomIsSetup;
};

}

#endif
