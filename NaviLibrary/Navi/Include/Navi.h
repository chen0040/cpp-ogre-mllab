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

#ifndef __Navi_H__
#define __Navi_H__
#if _MSC_VER > 1000
#pragma once
#endif

#include "NaviPlatform.h"
#include "NaviManager.h"

namespace NaviLibrary
{
	/**
	* The core class of NaviLibrary, a browser window rendered to a dynamic texture.
	*/
	class _NaviExport Navi : public Astral::BrowserWindowListener, public Ogre::WindowEventListener, public Ogre::ManualResourceLoader
	{
		friend class NaviManager;

		Astral::BrowserWindow* browserWin;
		std::string naviName;
		unsigned short naviWidth;
		unsigned short naviHeight;
		unsigned int winWidth;
		unsigned int winHeight;
		Ogre::RenderWindow* renderWindow;
		bool isWinFocused;
		NaviPosition position;
		bool movable;
		Ogre::Overlay* overlay;
		Ogre::PanelOverlayElement* panel;
		unsigned int maxUpdatePS;
		bool forceMax;
		Ogre::Timer timer;
		unsigned long lastUpdateTime;
		float opacity;
		bool usingMask;
		unsigned char* maskCache;
		size_t maskPitch;
		Ogre::Pass* matPass;
		Ogre::TextureUnitState* baseTexUnit;
		Ogre::TextureUnitState* maskTexUnit;
		bool ignoringTrans;
		float transparent;
		bool ignoringBounds;
		bool isMaterial;
		std::vector<NaviEventListener*> eventListeners;
		std::multimap<std::string, NaviDelegate> delegateMap;
		std::multimap<std::string, NaviDelegate>::iterator delegateIter;
		std::pair<std::multimap<std::string, NaviDelegate>::iterator, std::multimap<std::string, NaviDelegate>::iterator> dmBounds;
		std::map<std::string, std::vector<std::string> > ensureKeysMap;
		std::map<std::string, std::vector<std::string> >::iterator ensureKeysMapIter;
		bool okayToDelete;
		bool isVisible;
		bool fadingOut;
		unsigned long fadingOutStart;
		unsigned long fadingOutEnd;
		bool fadingIn;
		unsigned long fadingInStart;
		unsigned long fadingInEnd;
		bool compensateNPOT;
		unsigned short texWidth;
		unsigned short texHeight;
		size_t texDepth;
		size_t texPitch;

		Navi(Ogre::RenderWindow* renderWin, std::string name, std::string homepage, const NaviPosition &naviPosition,
			unsigned short width, unsigned short height, unsigned short zOrder);

		Navi(Ogre::RenderWindow* renderWin, std::string name, std::string homepage, unsigned short width, unsigned short height, 
			Ogre::FilterOptions texFiltering);

		~Navi();

		void createOverlay(unsigned short zOrder);

		void createBrowser(const std::string& homepage);

		void createMaterial(Ogre::FilterOptions texFiltering = Ogre::FO_NONE);

		void loadResource(Ogre::Resource* resource);

		void update();

		bool isPointOverMe(int x, int y);

		void onNavigateBegin(Astral::BrowserWindow* caller, const std::string& url, bool &shouldContinue);
		void onNavigateComplete(Astral::BrowserWindow* caller, const std::string& url, int responseCode);
		void onUpdateProgress(Astral::BrowserWindow* caller, short percentComplete);
		void onStatusTextChange(Astral::BrowserWindow* caller, const std::string& statusText);
		void onLocationChange(Astral::BrowserWindow* caller, const std::string& url);

		void windowMoved(Ogre::RenderWindow* rw);
		void windowResized(Ogre::RenderWindow* rw);
		void windowClosed(Ogre::RenderWindow* rw);
		void windowFocusChange(Ogre::RenderWindow* rw);
	public:

		/**
		* Navigates this Navi to a certain URL.
		*
		* @param	url		The URL (Web Address) to navigate to.
		*
		* @note	You may use local:// and resource:// specifiers for the URL.
		*/
		void navigateTo(const std::string& url);

		/**
		* Navigates this Navi to a certain URL along with encoded NaviData.
		*
		* @param	url		The URL (Web Address) to navigate to.
		*
		* @param	naviData	The NaviData to send to the page.
		*
		* @note	You may use local:// and resource:// specifiers for the URL.
		*
		* @note	This method of sending NaviData has been deprecated, use JS evaluation instead.
		*/
		void navigateTo(const std::string& url, const NaviData &naviData);

		/**
		* Navigates this Navi backwards through its page history, if possible.
		*/
		void navigateBack();

		/**
		* Navigates this Navi forwards through its page history, if possible.
		*/
		void navigateForward();

		/**
		* Immediately halts the loading of the current page, if one is loading.
		*/
		void navigateStop();

		/**
		* Reloads the page that this Navi has been navigated to.
		*/
		void navigateRefresh();

		/**
		* Returns whether or not this Navi can navigate further backwards through its page history.
		*/
		bool canNavigateBack();

		/**
		* Returns whether or not this Navi can navigate further forwards through its page history.
		*/
		bool canNavigateForward();

		/**
		* Evaluates Javascript in the context of the current page and returns the result.
		*
		* @param	script	The Javascript to evaluate/execute.
		*
		* @param	args	An optional vector of MultiValues that will be used in the translation
		*					of a templated string of Javascript.
		*
		* @return	If the action succeeds, this will return the result as a string (regardless
		*			of internal Javascript datatype), otherwise this returns an empty string.
		*
		* @note
		*	For example:
		*	\code
		*	myNavi->evaluateJS("$('myElement').setHTML('<b>Hello!</b>')");
		*
		*	// The following are examples of templated evaluation:
		*	myNavi->evaluateJS("newCharacter(?, ?, ?)", Args(name)(age)(naviData["motto"]));
		*	myNavi->evaluateJS("addChatMessage(?, ?)", Args(nickname)(someWideString));
		*	myNavi->evaluateJS("$(?).setHTML(?)", Args("helloLabel")("Hello world!"));
		*	myNavi->evaluateJS("?(?, ?)", Args("myFunction")(firstVar)(secondVar));
		*	myNavi->evaluateJS("$(?).SetVariable(?, ?)", Args("myFlashID")("flashVariable")(favoriteColor));
		*	\endcode
		*
		* @note	
		*	Strings in the Args of templated evaluation will automatically be quoted/escaped.
		*	Wide Strings will be encoded with NaviUtilities::encodeURIComponent and then wrapped in
		*	the Javascript decoding function: "decodeURIComponent(xxx)".
		*/
		std::string evaluateJS(std::string script, const NaviUtilities::Args &args = NaviUtilities::Args());

		/**
		* Subscribes a NaviEventListener to listen for events from this Navi.
		*
		* @param	newListener	The NaviEventListener to add.
		*/
		Navi* addEventListener(NaviEventListener* newListener);

		/**
		* Un-subscribes a NaviEventListener from this Navi.
		*
		* @param	removeListener	The NaviEventListener to remove.
		*/
		Navi* removeEventListener(NaviEventListener* removeListener);

		/**
		* Binds the reception of a NaviData object to a delegate function (callback).
		*
		* @param	naviDataName	The name of the NaviData to bind the callback to.
		*
		* @param	callback	The NaviDelegate to bind to. Functions must return a 'void' 
		*						and have one argument: 'const NaviData &naviData'
		*	\code
		*	// Example declaration of a compatible function (static function):
		*	void myStaticFunction(const NaviData& naviData)
		*	{
		*		// Handle the naviData here
		*	}
		*
		*	// Example declaration of a compatible function (member function):
		*	void MyClass::myMemberFunction(const NaviData& naviData)
		*	{
		*		// Handle the naviData here
		*	}
		*
		*	// NaviDelegate (member function) instantiation:
		*	NaviDelegate callback(this, &MyClass::myMemberFunction); // within a class
		*	NaviDelegate callback2(pointerToClassInstance, &MyClass::myMemberFunction);
		*
		*	// NaviDelegate (static function) instantiation:
		*	NaviDelegate callback(&myStaticFunction);
		*	\endcode
		*
		* @param	keys	An optional string vector containing the keys to ensure. See NaviData::ensure (second overload).
		* @note		It is highly advised to use NaviUtilities::Strings to invoke the 'keys' parameter.
		*
		* @par
		*	An example of usage:
		*	\code
		*	chatNavi->bind("messageSent", NaviDelegate(this, &NaviDemo::messageSent), Strings("nick")("message"));
		*	\endcode
		*/
		Navi* bind(const std::string &naviDataName, const NaviDelegate &callback, const NaviUtilities::Strings &keys = NaviUtilities::Strings());

		/**
		* Un-binds a certain NaviDelegate from a certain NaviData.
		*
		* @param	naviDataName	The name of the NaviData to unbind.
		*
		* @param	callback	The specific NaviDelegate to unbind. This is optional, if it is
		*						left blank, all bindings to 'naviDataName' will be released.
		*/
		Navi* unbind(const std::string &naviDataName, const NaviDelegate &callback = NaviDelegate());

		/**
		* Toggles between auto-updating and force-updating.
		*
		* @param	forceMaxUpdate		Navis normally only update when the page has changed, to override this functionality
		*								set this parameter to 'True' to make this Navi 'force update' using the value of the 
		*								parameter 'maxUpdatesPerSec'. This is useful as a work-around for rendering embedded 
		*								Flash applications. Note: if 'maxUpdatesPerSec' is 0, this Navi will try to 'force update'
		*								every single chance it gets (not recommended). Set this to 'False' to make this Navi update
		*								only when the page changes (auto-updating).
		*/
		Navi* setForceMaxUpdate(bool forceMaxUpdate);

		/**
		* Normally, mouse movement is only injected into a specific Navi from NaviManager if the mouse is within the boundaries of
		* a Navi and over an opaque area (not transparent). This behavior may be detrimental to certain Navis, for
		* example an animated 'dock' with floating icons on a transparent background: the mouse-out event would never
		* be invoked on each icon because the Navi only received mouse movement input over opaque areas. Use this function
		* to makes this Navi always inject mouse movement, regardless of boundaries or transparency.
		*
		* @param	ignoreBounds	Whether or not this Navi should ignore bounds/transparency when injecting mouse movement.
		*
		* @note
		*	The occlusivity of each Navi will still be respected, mouse movement will not be injected 
		*	if another Navi is occluding this Navi.
		*/
		Navi* setIgnoreBounds(bool ignoreBounds = true);

		/**
		* Using alpha-masking/color-keying doesn't just affect the visuals of a Navi; by default, Navis 'ignore'
		* mouse movement/clicks over 'transparent' areas of a Navi (Areas with opacity less than 5%). You may
		* disable this behavior or redefine the 'transparent' threshold of opacity to something else other 
		* than 5%.
		*
		* @param	ignoreTrans		Whether or not this Navi should ignore 'transparent' areas when mouse-picking.
		*
		* @param	defineThreshold		Areas with opacity less than this percent will be ignored
		*								(if ignoreTrans is true, of course). Default is 5% (0.05).
		*/
		Navi* setIgnoreTransparent(bool ignoreTrans, float threshold = 0.05);

		/**
		* Masks the alpha channel of this Navi with that of a provided image.
		*
		* @param	maskFileName	The filename of the Alpha Mask Image. The Alpha Mask Image MUST have a
		*							width greater than or equal to the Navi width and it MUST have a height
		*							greater than or equal to the Navi height. Alpha Mask Images larger than
		*							the Navi will not be stretched, instead Navi will take Alpha values starting
		*							from the Top-Left corner of the Alpha Mask Image. To reset Navi to use no
		*							Alpha Mask Image, simply provide an empty String ("").
		*
		* @param	groupName		The Resource Group to find the Alpha Mask Image filename.
		*
		* @throws	Ogre::Exception::ERR_INVALIDPARAMS	Throws this if the width or height of the Alpha Mask Image is
		*												less than the width or height of the Navi it is applied to.
		*/
		Navi* setMask(std::string maskFileName, std::string groupName = Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);

		/**
		* Adjusts the number of times per second this Navi may update.
		*
		* @param	maxUPS		The maximum number of times per second this Navi can update. Set this to '0' to 
		*						use no update limiting. If this Navi is force-updating (see Navi::setForceMaxUpdate), this
		*						value is used as the number of updates per second to actually do.
		*/
		Navi* setMaxUPS(unsigned int maxUPS = 0);

		/**
		* Toggles whether or not this Navi is movable. (not applicable to NaviMaterials)
		*
		* @param	isMovable	Whether or not this Navi should be movable.
		*/
		Navi* setMovable(bool isMovable = true);

		/**
		* Changes the overall opacity of this Navi to a certain percentage.
		*
		* @param	opacity		The opacity percentage as a float. 
		*						Fully Opaque = 1.0, Fully Transparent = 0.0.
		*/
		Navi* setOpacity(float opacity);

		/** 
		* Sets the default position of this Navi to a new position and then moves
		* the Navi to that position. (not applicable to NaviMaterials)
		*
		* @param	naviPosition	The new NaviPosition to set the Navi to.
		*/
		Navi* setPosition(const NaviPosition &naviPosition);

		/**
		* Resets the position of this Navi to its default position. (not applicable to NaviMaterials)
		*/
		Navi* resetPosition();

		/**
		* Hides this Navi.
		*
		* @param	fade	Whether or not to fade this Navi down. (Optional, default is false)
		*
		* @param	fadeDurationMS	If fading, the number of milliseconds to fade for.
		*/
		Navi* hide(bool fade = false, unsigned short fadeDurationMS = 300);

		/**
		* Shows this Navi.
		*
		* @param	fade	Whether or not to fade the Navi up. (Optional, default is false)
		*
		* @param	fadeDurationMS	If fading, the number of milliseconds to fade for.
		*/
		Navi* show(bool fade = false, unsigned short fadeDurationMS = 300);

		/**
		* 'Focuses' this Navi by popping it to the front of all other Navis. (not applicable to NaviMaterials)
		*/
		Navi* focus();

		/**
		* Moves this Navi by relative amounts. (not applicable to NaviMaterials or non-movable Navis)
		*
		* @param	deltaX	The relative X amount to move this Navi by. Positive amounts move it right.
		*
		* @param	deltaY	The relative Y amount to move this Navi by. Positive amounts move it down.
		*/
		Navi* moveNavi(int deltaX, int deltaY);

		/**
		* Retrieves the width and height that this Navi was created with.
		*
		* @param[out]	width	The unsigned short that will be used to store the retrieved width.
		*
		* @param[out]	height	The unsigned short that will be used to store the retrieved height.
		*/
		void getExtents(unsigned short &width, unsigned short &height);

		/**
		* Transforms an X-coordinate in screen-space to that of this Navi's relative space.
		*
		* @param	absX	The X-coordinate in screen-space to transform.
		*
		* @return	The X-coordinate in this Navi's relative space.
		*/
		int getRelativeX(int absX);

		/**
		* Transforms a Y-coordinate in screen-space to that of this Navi's relative space.
		*
		* @param	absX	The Y-coordinate in screen-space to transform.
		*
		* @return	The Y-coordinate in this Navi's relative space.
		*/
		int getRelativeY(int absY);

		/**
		* Returns whether or not this Navi was created as a NaviMaterial.
		*/
		bool isMaterialOnly();

		/**
		* Gets a pointer to the Ogre::OverlayContainer (Panel) that is used internally for this Navi.
		* (not applicable to NaviMaterials)
		*
		* @return	If the Navi is found and it is NOT a NaviMaterial, returns a pointer to the Panel, otherwise 0 is returned.
		*/
		Ogre::PanelOverlayElement* getInternalPanel();

		/**
		* Returns the name of this Navi.
		*/
		std::string getName();

		/**
		* Returns the name of the Ogre::Material used internally by this Navi.
		*/
		std::string getMaterialName();

		/**
		* Returns whether or not this Navi is currently visible. (See Navi::hide and Navi::show)
		*/
		bool getVisibility();

		/**
		* Gets the derived UV's of this Navi's internal texture. On certain systems we must compensate for lack of
		* NPOT-support on the videocard by using the next-highest POT texture. Normal Navi's compensate their UV's accordingly
		* however NaviMaterials will need to adjust their own by use of this function.
		*
		* @param[out]	u1	The Ogre::Real that will be used to store the retrieved u1-coordinate.
		* @param[out]	v1	The Ogre::Real that will be used to store the retrieved v1-coordinate.
		* @param[out]	u2	The Ogre::Real that will be used to store the retrieved u2-coordinate.
		* @param[out]	v2	The Ogre::Real that will be used to store the retrieved v2-coordinate.
		*/
		void getDerivedUV(Ogre::Real& u1, Ogre::Real& v1, Ogre::Real& u2, Ogre::Real& v2);

		/**
		* Injects the mouse's current coordinates (in this Navi's own local coordinate space, see Navi::getRelativeX and 
		* Navi::getRelativeY) into this Navi.
		*
		* @param	xPos	The X-coordinate of the mouse, relative to this Navi's origin.
		* @param	yPos	The Y-coordinate of the mouse, relative to this Navi's origin.
		*/
		void injectMouseMove(int xPos, int yPos);

		/**
		* Injects mouse wheel events into this Navi.
		*
		* @param	relScroll	The relative Scroll-Value of the mouse.
		*
		* @note
		*	To inject this using OIS: on a OIS::MouseListener::MouseMoved event, simply 
		*	inject "arg.state.Z.rel" of the "MouseEvent".
		*/
		void injectMouseWheel(int relScroll);

		/**
		* Injects mouse down events into this Navi. You must supply the current coordinates of the mouse in this
		* Navi's own local coordinate space. (see Navi::getRelativeX and Navi::getRelativeY)
		*
		* @param	xPos	The absolute X-Value of the mouse, relative to this Navi's origin.
		* @param	yPos	The absolute Y-Value of the mouse, relative to this Navi's origin.
		*/
		void injectMouseDown(int xPos, int yPos);

		/**
		* Injects mouse up events into this Navi. You must supply the current coordinates of the mouse in this
		* Navi's own local coordinate space. (see Navi::getRelativeX and Navi::getRelativeY)
		*
		* @param	xPos	The absolute X-Value of the mouse, relative to this Navi's origin.
		* @param	yPos	The absolute Y-Value of the mouse, relative to this Navi's origin.
		*/
		void injectMouseUp(int xPos, int yPos);
	};

}

#endif