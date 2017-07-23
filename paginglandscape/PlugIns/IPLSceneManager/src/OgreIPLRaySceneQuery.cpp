/***************************************************************************
OgreIPLRaySceneQuery.cpp  

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

#include <OgreEntity.h>

#include "OgreIPLRaySceneQuery.h"
#include "OgreIPLPrerequisites.h"

namespace Ogre
{
//----------------------------------------------------------------------------
IPLRaySceneQuery::IPLRaySceneQuery( SceneManager* creator )
	: DefaultRaySceneQuery( creator )
{ 
	mSupportedWorldFragments.insert( SceneQuery::WFT_SINGLE_INTERSECTION );
}

//----------------------------------------------------------------------------
IPLRaySceneQuery::~IPLRaySceneQuery( )
{
	clearFragmentList( );
}

//----------------------------------------------------------------------------
// This function return the vertex interpolated height.
// Supplied by Praetor. Thanks a lot. ]:)
void IPLRaySceneQuery::execute( RaySceneQueryListener* listener ) 
{ 
	clearFragmentList( );

	unsigned long mask = getQueryMask( );
	SceneQuery::WorldFragment* frag;

	if ( mask & RSQ_Height )
	{
		// we don't want to bother checking for entities because a 
		// UNIT_Y ray is assumed to be a height test, not a ray test
		frag = new SceneQuery::WorldFragment( );
		fragmentList.push_back( frag );

		frag->fragmentType = SceneQuery::WFT_SINGLE_INTERSECTION; 
		Vector3 origin = mRay.getOrigin();
		origin.y = 0; // ensure that it's within bounds
		frag->singleIntersection = getHeightAt( origin );
		listener->queryResult( frag, 0 );
	}
	else
	{
		// Check for entity contacts
		if ( mask & RSQ_Entities )
		{
			DefaultRaySceneQuery::execute( listener );
		}

		if ( mask & RSQ_AllTerrain || mask & RSQ_FirstTerrain )
		{
			Vector3 ray = mRay.getOrigin( );
			Vector3 land = getHeightAt( ray );
			Real dist = 0, resFactor = 1;

			// Only bother if the non-default mask has been set
			if ( ( mask & RSQ_1xRes ) == 0 )
			{
				if ( mask & RSQ_2xRes )
				{
					resFactor = 0.5;
				}
				else if ( mask & RSQ_4xRes )
				{
					resFactor = 0.25;
				}
				else if ( mask & RSQ_8xRes )
				{
					resFactor = 0.125;
				}
			}

			while ( land.y != -1 )
			{
				ray += mRay.getDirection( ) * resFactor;
				dist += 1 * resFactor;

				land = getHeightAt( ray );
				if ( ray.y < land.y )
				{
					frag = new SceneQuery::WorldFragment( );
					fragmentList.push_back( frag );

					frag->fragmentType = SceneQuery::WFT_SINGLE_INTERSECTION; 
					frag->singleIntersection = land;
					listener->queryResult( frag, dist );

					if ( mask & RSQ_FirstTerrain )
					{
						return;
					}
				}
			} 
		}
	}             
} 

//----------------------------------------------------------------------------
Vector3 IPLRaySceneQuery::getHeightAt( const Vector3& origin )
{
	return Vector3( origin.x, static_cast< IPLSceneManager* >( mParentSceneMgr )->getRealWorldHeight( origin.x, origin.z ), origin.z );
}

//----------------------------------------------------------------------------
void IPLRaySceneQuery::clearFragmentList( void )
{
	std::vector<SceneQuery::WorldFragment*>::iterator cur, end = fragmentList.end( );
	for ( cur = fragmentList.begin( ); cur < end; cur++ )
	{
		SceneQuery::WorldFragment* frag = ( *cur );
		if ( frag )
		{
			delete frag;
		}
	}
	fragmentList.clear( );
}

} // namespace Ogre
