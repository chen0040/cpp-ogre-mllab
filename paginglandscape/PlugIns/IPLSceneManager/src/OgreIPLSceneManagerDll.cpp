/***************************************************************************
	OgreIPLSceneManagerDll.cpp  

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

#include <OgreRoot.h>

#include "OgreIPLSceneManager.h"

namespace Ogre
{
IPLSceneManager* IPLPlugin;

extern "C" void dllStartPlugin( void )
{
	// Create new scene manager
	IPLPlugin = new IPLSceneManager( );

	// Register
	Root::getSingleton( ).setSceneManager( ST_EXTERIOR_REAL_FAR, IPLPlugin );
}

extern "C" void dllStopPlugin( void )
{
	delete IPLPlugin;
}
}
