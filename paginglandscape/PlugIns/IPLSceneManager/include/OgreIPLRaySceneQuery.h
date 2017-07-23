/***************************************************************************
OgreIPLRaySceneQuery.h  

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

#ifndef __IPLRAYSCENEQUERY_H__
#define __IPLRAYSCENEQUERY_H__

#include "OgreIPLSceneManager.h"

#include <vector>

namespace Ogre
{

enum
{
	// Height will return the height at the origin
	// Distance will always be 0
	RSQ_Height       = 1<<0,

	// AllTerrain will return all terrain contacts
	// along the ray
	RSQ_AllTerrain   = 1<<1,

	// FirstTerrain will return only the first
	// contact along the ray
	RSQ_FirstTerrain = 1<<2,

	// Entities will return all entity contacts along the ray
	RSQ_Entities     = 1<<3,

	// Different resolution scales.  It defaults to 1 unit
	// resolution.  2x resolution tests every 0.5 units
	// 4x tests every 0.25 and 8x every 0.125
	RSQ_8xRes        = 1<<4,
	RSQ_4xRes        = 1<<5,
	RSQ_2xRes        = 1<<6,
	RSQ_1xRes        = 1<<7
};

/** IPL's specialisation of RaySceneQuery.
	if RSQ_Height bit mask is set, RSQ_Terrain and RSQ_Entity bits will be ignored
	Otherwise data will be returned based on the mask
*/
class IPLRaySceneQuery : public DefaultRaySceneQuery
{
public:
	IPLRaySceneQuery( SceneManager* creator );

	~IPLRaySceneQuery( );

	/** See RaySceneQuery. */
	void execute( RaySceneQueryListener * listener );

protected: 
	inline Vector3 getHeightAt( const Vector3& origin );

	std::vector< SceneQuery::WorldFragment* > fragmentList;
	void clearFragmentList( void );

private:

};

} // namespace Ogre


#endif
