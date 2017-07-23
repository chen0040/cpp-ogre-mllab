/***************************************************************************
	OgreIPLIntersectionSceneQuery.cpp 

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

#include "OgreIPLIntersectionSceneQuery.h"

#include <OgreEntity.h>

namespace Ogre
{
//----------------------------------------------------------------------------
IPLIntersectionSceneQuery::IPLIntersectionSceneQuery( SceneManager* creator )
	: DefaultIntersectionSceneQuery( creator )
{ 
	mSupportedWorldFragments.insert( SceneQuery::WFT_RENDER_OPERATION );
}

//----------------------------------------------------------------------------
IPLIntersectionSceneQuery::~IPLIntersectionSceneQuery( )
{
}

//----------------------------------------------------------------------------
// ******* THIS CODE DOES NOT WORK - NOT COMPLETED
void IPLIntersectionSceneQuery::execute( IntersectionSceneQueryListener* listener )
{
    // Do movables to movables as before
    DefaultIntersectionSceneQuery::execute( listener );
    SceneQuery::WorldFragment frag;

    // Do entities to world
	SceneManager::EntityList::const_iterator a, theEnd;
    IPLSceneManager *sceneMgr = static_cast< IPLSceneManager* >( mParentSceneMgr );
    theEnd = sceneMgr->getEntities( ).end( );
    for ( a = sceneMgr->getEntities( ).begin( );a != theEnd; ++a )
    {
        // Apply mask 
        if ( a->second->getQueryFlags( ) & mQueryMask)
        {
            const AxisAlignedBox& box = a->second->getWorldBoundingBox( );
            std::list< RenderOperation > opList;

/*
			for ( int j = 0; j < mOptions->world_height; j++ )
			{
				for ( int i = 0; i < mOptions->world_width; i++ )
				{
//					if ( sceneMgr->mPages[ i ][ j ]->isLoaded( ) == true )
//					{
//						sceneMgr->mPages[ i ][ j ]->getIPLRenderOpsInBox( box, opList );
//					}
				}
			}						
*/          
			std::list<RenderOperation>::iterator i, iend;
			iend = opList.end( );
			for ( i = opList.begin( ); i != iend; ++i )
			{
				frag.fragmentType = SceneQuery::WFT_RENDER_OPERATION;
				frag.renderOp = &( *i );
				listener->queryResult( a->second, &frag );
			}
		}
	}
}

} // namespace Ogre

