#ifndef _CEGUI_fix_h_
#define _CEGUI_fix_h_
#pragma warning (push)
#pragma warning( disable : 4267 )
/** This file eases an issue CEGUI has with OGRE's memory manager. Simply include this in
	any files that are going to be doing 'CEGUI stuff', rather than CEGUI.h, OgreCEGUIRender.h, 
	OgreCEGUIResourceProvider.h, and OgreCEGUITexture.h (etc). You will be in for smooth(er) 
	sailing.
**/ 

#include <OgreNoMemoryMacros.h>
#include <CEGUI/CEGUI.h>
#include <../CEGUIRenderer/include/OgreCEGUIRenderer.h>
#include <../CEGUIRenderer/include/OgreCEGUIResourceProvider.h>
#include <../CEGUIRenderer/include/OgreCEGUITexture.h>
#include <OgreMemoryMacros.h>
#pragma warning (pop)
#endif