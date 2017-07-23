/***************************************************************************
	OgreIPLIntersectionSceneQuery.h  

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

#ifndef __IPLINTERSECTIONSCENEQUERY_H__
#define __IPLINTERSECTIONSCENEQUERY_H__

#include "OgreIPLSceneManager.h"

namespace Ogre
{

/** IPL's specialisation of IntersectionSceneQuery. */
class IPLIntersectionSceneQuery : public DefaultIntersectionSceneQuery
{
public:
	IPLIntersectionSceneQuery( SceneManager* creator );

	~IPLIntersectionSceneQuery( );

	/** See IntersectionSceneQuery. */
	void execute( IntersectionSceneQueryListener* listener );

private:

};

} // namespace Ogre


#endif
