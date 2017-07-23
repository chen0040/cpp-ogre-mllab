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

****************************************************************************/

#include "OgreIPLSceneManager.h"

#include "OgreIPLOptions.h"
#include "OgreIPLIndexBuffer.h"

#include "OgreIPLIntersectionSceneQuery.h"
#include "OgreIPLRaySceneQuery.h"

#include <OgreCamera.h>
#include <OgreException.h>
#include <OgreStringConverter.h>
#include <OgreRenderSystem.h>

namespace Ogre
{

//-----------------------------------------------------------------------
IPLSceneManager::IPLSceneManager( )
	: SceneManager( )
{
//	showBoundingBoxes( true );
//	setDisplaySceneNodes( true );
	mLastCameraPos = Vector3( -999999, 9999999, -999999 );
	mWorldGeomIsSetup = false;
}

//-----------------------------------------------------------------------
IPLSceneManager::~IPLSceneManager( )
{
	clearScene( );
}

//-----------------------------------------------------------------------
void IPLSceneManager::setWorldGeometry( const String& filename )
{
	if ( mWorldGeomIsSetup == true )
	{
		clearScene( );
	}
	// Load the configuration file
	new IPLOptions( );
	IPLOptions::getSingleton( ).load( filename );
	
	// initialize vertex index buffer
	new IPLIndexBuffer( );

	// Create VirtualPageWindow Manager
	mVirtualPageWindow = new IPLVirtualPageWindow( this );

	mWorldGeomIsSetup = true;
}

//-----------------------------------------------------------------------
void IPLSceneManager::clearScene( void )
{
	if ( mWorldGeomIsSetup == true )
	{
		mWorldGeomIsSetup = false;

		if ( mVirtualPageWindow != NULL )
		{
			delete mVirtualPageWindow;
			mVirtualPageWindow = NULL;
		}

		if ( IPLIndexBuffer::getSingletonPtr( ) != NULL )
		{
			delete IPLIndexBuffer::getSingletonPtr( );
		}

		if ( IPLOptions::getSingletonPtr( ) != NULL )
		{
			delete IPLOptions::getSingletonPtr( );
		}
	}
	//Call the default
	SceneManager::clearScene( );
}

//-----------------------------------------------------------------------
void IPLSceneManager::_updateSceneGraph( Camera * cam )
{

	// entry into here could come before setWorldGeometry got called which could be disastrous
	// so check for init

	if ( mWorldGeomIsSetup )
	{
		Vector3 pos = cam->getDerivedPosition( );

		// Update only if the camera was moved
		if ( IPLOptions::getSingleton( ).cameraThreshold <= ( mLastCameraPos - pos ).squaredLength( ) )
		{
			mLastCameraPos = pos;
			mVirtualPageWindow->updateViewPosition( pos.x, pos.z );
		}
	}

	SceneManager::_updateSceneGraph( cam );
}

//----------------------------------------------------------------------------

IntersectionSceneQuery* IPLSceneManager::createIntersectionQuery( unsigned long mask )
{
	IPLIntersectionSceneQuery* q = new IPLIntersectionSceneQuery( this );
	q->setQueryMask( mask );
	return q;
}

//----------------------------------------------------------------------------
RaySceneQuery* IPLSceneManager::createRayQuery( const Ray& ray, unsigned long mask )
{
	IPLRaySceneQuery* q = new IPLRaySceneQuery( this );
	q->setRay( ray );
	q->setQueryMask( mask );
	return q;
}

//----------------------------------------------------------------------------
float IPLSceneManager::getRealWorldHeight( float x, float z )
{
	return mVirtualPageWindow->getWorldHeight( x, z );
}

} //namespace
