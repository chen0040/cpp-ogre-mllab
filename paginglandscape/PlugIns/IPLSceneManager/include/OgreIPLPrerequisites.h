/***************************************************************************
  OgreIPLPrerequisites.h  

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

#ifndef __IPLPREREQUISITES_H__
#define __IPLPREREQUISITES_H__

#include "OgrePrerequisites.h"

//-----------------------------------------------------------------------
// Windows Settings
//-----------------------------------------------------------------------

#if OGRE_PLATFORM == PLATFORM_WIN32 
#   ifdef PLUGIN_IPLSM_EXPORTS 
#       define _OgreIPLSMExport __declspec(dllexport) 
#   else 
#       define _OgreIPLSMExport __declspec(dllimport) 
#   endif 
#else 
#   define _OgreIPLSMExport 
#endif 

#define POSITION_BINDING	0
#define NORMAL_BINDING		1
#define TEXCOORD_BINDING	2
#define COLOR_BINDING		3

#define TILE_NORTH  0x00000001
#define TILE_SOUTH  0x00000002
#define TILE_WEST   0x00000004
#define TILE_EAST   0x00000008

#endif