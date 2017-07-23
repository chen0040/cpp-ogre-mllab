/*
	This file is part of Navi, a library that allows developers to embed movable 
	'Navis' (Dynamic, HTML/JS/CSS-Driven GUI Overlays) within an Ogre3D application.

	Copyright (C) 2007 Adam J. Simmons
	http://www.agelessanime.com/Navi/

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef __NaviManager_H__
#define __NaviManager_H__
#if _MSC_VER > 1000
#pragma once
#endif

#include "NaviPlatform.h"
#include "NaviData.h"
#include "NaviEventListener.h"
#include "NaviMouse.h"
#include "NaviDelegate.h"
#include "NaviUtilities.h"
#include "NaviSingleton.h"
#include "Astral.h"
#include <OgrePanelOverlayElement.h>

/**
* Global namespace 'NaviLibrary' encapsulates all NaviLibrary-specific stuff.
*/
namespace NaviLibrary
{
	/**
	* Enumerates relative positions. Used by NaviManager::NaviPosition
	*/
	enum RelativePosition
	{
		Left,
		TopLeft,
		TopCenter,
		TopRight,
		Right,
		BottomRight,
		BottomCenter,
		BottomLeft,
		Center
	};

	/**
	* An object that holds position-data for a Navi. Used by NaviManager::createNavi and NaviManager::setNaviPosition.
	*/
	class _NaviExport NaviPosition
	{
		bool usingRelative;
		union {
			struct { RelativePosition position; short x; short y; } rel;
			struct { short left; short top; } abs;
		} data;

		friend class Navi;
		NaviPosition();
	public:
		/**
		* Creates a relatively-positioned NaviPosition object.
		*
		* @param	relPosition		The position of the Navi in relation to the Render Window
		*
		* @param	offsetLeft	How many pixels from the left to offset the Navi from the relative position.
		*
		* @param	offsetTop	How many pixels from the top to offset the Navi from the relative position.
		*/
		NaviPosition(const RelativePosition &relPosition, short offsetLeft = 0, short offsetTop = 0);

		/**
		* Creates an absolutely-positioned NaviPosition object.
		*
		* @param	absoluteLeft	The number of pixels from the left of the Render Window.
		*
		* @param	absoluteTop		The number of pixels from the top of the Render Window.
		*/
		NaviPosition(short absoluteLeft, short absoluteTop);
	};

	/**
	* Enumerates internal mouse button IDs. Used by NaviManager::injectMouseDown, NaviManager::injectMouseUp
	*/
	enum MouseButtonID
	{
		LeftMouseButton = 0,
		RightMouseButton, 
		MiddleMouseButton
	};
 
	/**
	* Supreme dictator and Singleton: NaviManager
	*
	* The class you will need to go to for all your Navi-related needs.
	*/
	class _NaviExport NaviManager : public Singleton<NaviManager>
	{
		friend class Navi; // Our very close friend <3
		friend void NaviUtilities::translateLocalProtocols(std::string &strToTranslate);

		std::string localNaviDirectory;
		Astral::AstralManager* astralMgr;
		std::map<std::string,Navi*> activeNavis;
		Navi* focusedNavi;
		std::map<std::string,Navi*>::iterator iter;
		Ogre::RenderWindow* renderWindow;
		int mouseXPos, mouseYPos;
		bool mouseButtonRDown;
		unsigned short zOrderCounter;

		bool focusNavi(int x, int y, Navi* selection = 0);
		Navi* getTopNavi(int x, int y);
	public:
		int getMouseXPos() const { return mouseXPos; }
		int getMouseYPos() const { return mouseYPos; }
	public:
		/**
		* Creates the NaviManager and loads the internal LLMozLib library.
		*
		* @param	renderWindow	The Ogre::RenderWindow to render Navis to
		*
		* @param	localNaviDirectory		The directory that will be referred to when using the "local://" specifier.
		*									Default is "NaviLocal".
		*
		* @param	geckoRuntimeDirectory	The directory that contains the Gecko runtime folders: chrome, components,
		*									greprefs, plugins, and res. Default is "GeckoRuntime".
		*
		* @note
		*	Both directories should be specified as relative to the executable's working directory. For example:
		*	\verbatim "..\\..\\SomeFolder" \endverbatim
		*
		* @throws	Ogre::Exception::ERR_INTERNAL_ERROR		Throws this when LLMozLib fails initialization
		*/
		NaviManager(Ogre::RenderWindow* _renderWindow, const std::string &localNaviDirectory = "NaviLocal",
			const std::string &geckoRuntimeDirectory = "GeckoRuntime");

		/**
		* Destroys any active Navis, the NaviMouse singleton (if instantiated), and shuts down LLMozLib.
		*/
		~NaviManager();

		/**
		* Gets the NaviManager Singleton.
		*
		* @return	A reference to the NaviManager Singleton.
		*
		* @throws	Ogre::Exception::ERR_RT_ASSERTION_FAILED	Throws this if NaviManager has not been instantiated yet.
		*/
		static NaviManager& Get();

		/**
		* Gets the NaviManager Singleton as a pointer.
		*
		* @return	If the NaviManager has been instantiated, returns a pointer to the NaviManager Singleton,
		*			otherwise this returns 0.
		*/
		static NaviManager* GetPointer();

		/**
		* Gives each active Navi a chance to update, each may or may not update their internal textures
		* based on various conditions.
		*/
		void Update();

		/**
		* Creates a Navi.
		*
		* @param	naviName	The name of the Navi, used to refer to a specific Navi in subsequent calls.
		*
		* @param	homepage	The default starting page for a Navi. You may use local:// here to refer to
		*						the local Navi directory (See NaviManager::Startup)
		*
		* @param	naviPosition	The unified position (either relative or absolute) of a Navi.
		*							See NaviManager::NaviPosition for more information.
		*
		* @param	width	The width of the Navi.
		*
		* @param	height	The height of the Navi.
		*
		* @param	zOrder		Sets the starting Z-Order for this Navi; Navis with higher Z-Orders will be on top of other
		*						Navis. To auto-increment this value for every successive Navi, leave this parameter as '0'.
		*
		* @throws	Ogre::Exception::ERR_RT_ASSERTION_FAILED	Throws this if a Navi by the same name already exists.
		*/
		Navi* createNavi(const std::string &naviName, const std::string &homepage, const NaviPosition &naviPosition,
			unsigned short width, unsigned short height, unsigned short zOrder = 0);

		/**
		* Creates a NaviMaterial. NaviMaterials are just like Navis except that they lack a movable overlay element. 
		* Instead, you handle the material and apply it to anything you like. Mouse input for NaviMaterials should be 
		* injected via the Navi::injectMouse_____ API calls instead of the global NaviManager::injectMouse_____ calls.
		*
		* @param	naviName	The name of the NaviMaterial, used to refer to this specific Navi in subsequent calls.
		*
		* @param	homepage	The default starting page for a Navi. You may use local:// here to refer to
		*						the local Navi directory (See NaviManager::Startup)
		*
		* @param	width	The width of the NaviMaterial.
		*
		* @param	height	The height of the NaviMaterial.
		*
		* @param	texFiltering	The texture filtering to use for this material. (see Ogre::FilterOptions) If the NaviMaterial is
		*							applied to a 3D object, FO_ANISOTROPIC is the best (and default) choice, otherwise set this to
		*							FO_NONE for use in other overlays/GUI elements.
		*
		* @throws	Ogre::Exception::ERR_RT_ASSERTION_FAILED	Throws this if a Navi by the same name already exists.
		*/
		Navi* createNaviMaterial(const std::string &naviName, const std::string &homepage, unsigned short width, unsigned short height,
			Ogre::FilterOptions texFiltering = Ogre::FO_ANISOTROPIC);

		/**
		* Retrieve a pointer to a Navi by name.
		*
		* @param	naviName	The name of the Navi to retrieve.
		*
		* @return	If the Navi is found, returns a pointer to the Navi, otherwise returns 0.
		*/
		Navi* getNavi(const std::string &naviName);

		/**
		* Destroys a Navi.
		*
		* @param	naviName	The name of the Navi to destroy.
		*/
		void destroyNavi(const std::string &naviName);

		/**
		* Destroys a Navi.
		*
		* @param	naviName	A pointer to the Navi to destroy.
		*/
		void destroyNavi(Navi* naviToDestroy);

		/**
		* Resets the positions of all Navis to their default positions. (not applicable to NaviMaterials)
		*/
		void resetAllPositions();

		/**
		* Configures the network proxy settings for all Navis.
		*
		* @param	isEnabled	Whether or not the network proxy should be enabled.
		*
		* @param	host	The hostname or IP address of the proxy server.
		* @param	port	The port of the proxy server.
		*/
		void setProxy(bool isEnabled, const std::string& host, int port);

		/**
		* Sets a global Mozilla preference with a boolean value.
		* For more info: http://preferential.mozdev.org/preferences.html
		*
		* @param	prefName	the name of the preference
		* @param	value		the value of the preference
		*/
		void setBooleanPref(const std::string& prefName, bool value);

		/**
		* Sets a global Mozilla preference with an integer value.
		* For more info: http://preferential.mozdev.org/preferences.html
		*
		* @param	prefName	the name of the preference
		* @param	value		the value of the preference
		*/
		void setIntegerPref(const std::string& prefName, int value);

		/**
		* Sets a global Mozilla preference with a string value.
		* For more info: http://preferential.mozdev.org/preferences.html
		*
		* @param	prefName	the name of the preference
		* @param	value		the value of the preference
		*/
		void setStringPref(const std::string& prefName, const std::string& value);

		/**
		* Checks whether or not a Navi is focused/selected. (not applicable to NaviMaterials)
		*
		* @return	True if a Navi is focused, False otherwise.
		*/
		bool isAnyNaviFocused();

		/**
		* Gets the currently focused/selected Navi. (not applicable to NaviMaterials)
		*
		* @return	A pointer to the Navi that is currently focused, returns 0 if none are focused.
		*/
		Navi* getFocusedNavi();

		/**
		* Injects the mouse's current position into NaviManager. Used to generally keep track of where the mouse 
		* is for things like moving Navis around, telling the internal pages of each Navi where the mouse is and
		* where the user has clicked, etc. (not applicable to NaviMaterials)
		*
		* @param	xPos	The current X-coordinate of the mouse.
		* @param	yPos	The current Y-coordinate of the mouse.
		*
		* @return	Returns True if the injected coordinate is over a Navi, False otherwise.
		*/
		bool injectMouseMove(int xPos, int yPos);

		/**
		* Injects mouse wheel events into NaviManager. Used to scroll the focused Navi. (not applicable to NaviMaterials)
		*
		* @param	relScroll	The relative Scroll-Value of the mouse.
		*
		* @note
		*	To inject this using OIS: on a OIS::MouseListener::MouseMoved event, simply 
		*	inject "arg.state.Z.rel" of the "MouseEvent".
		*
		* @return	Returns True if the mouse wheel was scrolled while a Navi was focused, False otherwise.
		*/
		bool injectMouseWheel(int relScroll);

		/**
		* Injects mouse down events into NaviManager. Used to know when the user has pressed a mouse button
		* and which button they used. (not applicable to NaviMaterials)
		*
		* @param	buttonID	The ID of the button that was pressed. Left = 0, Right = 1, Middle = 2.
		*
		* @return	Returns True if the mouse went down over a Navi, False otherwise.
		*/
		bool injectMouseDown(int buttonID);

		/**
		* Injects mouse up events into NaviManager. Used to know when the user has released a mouse button 
		* and which button they used. (not applicable to NaviMaterials)
		*
		* @param	buttonID	The ID of the button that was released. Left = 0, Right = 1, Middle = 2.
		*
		* @return	Returns True if the mouse went up while a Navi was focused, False otherwise.
		*/
		bool injectMouseUp(int buttonID);

		/**
		* De-Focuses any currently-focused Navis. This would be useful if you need to disable any auto-key-injection
		* (and subsequent display in a focused textbox of a focused Navi) done internally by Gecko.
		*/
		void deFocusAllNavis();
	};

}

#endif
