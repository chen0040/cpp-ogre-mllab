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

#ifndef __NaviEventListener_H__
#define __NaviEventListener_H__
#if _MSC_VER > 1000
#pragma once
#endif

#include "NaviPlatform.h"
#include "NaviData.h"

namespace NaviLibrary
{
	class Navi;

	/**
	* To receive event notifications about your Navis from the NaviManager, inherit from
	* this abstract class and invoke NaviManager::addNaviEventListener.
	*/
	class _NaviExport NaviEventListener
	{
	public:
		virtual ~NaviEventListener() {}

		/**
		* This is invoked when a NaviData-capable page sends NaviData
		*
		* @param	caller		The Navi that invoked this event.
		*
		* @param	naviData	The sent NaviData.
		*/
		virtual void onNaviDataEvent(Navi* caller, const NaviData &naviData) = 0;

		/**
		* This is invoked when a Navi begins to navigate to a certain URL. You may stop or redirect
		* the load by setting "shouldContinue" to false.
		*
		* @param	caller	The Navi that invoked this event.
		*
		* @param	url		The URL (Web Address) that the browser is about to navigate to.
		*
		* @param	shouldContinue	Set this out parameter to false if you wish to abort the navigation.
		*
		* @note	You may use this event to implement custom whitelisting/blacklisting or redirection.
		*/
		virtual void onNavigateBegin(Navi* caller, const std::string& url, bool &shouldContinue) = 0;

		/**
		* This is invoked when the internal browser of a Navi begins to navigate to a location.
		*
		* @param	caller		The Navi that invoked this event.
		*
		* @param	uri			The URL (Web Address) that the browser is navigating to.
		*/
		virtual void onLocationChange(Navi* caller, const std::string &url) = 0;

		/**
		* This is invoked when the internal browser of a Navi completes navigation to a location.
		*
		* @param	caller		The Navi that invoked this event.
		*
		* @param	uri			The URL (Web Address) that the browser has finished navigating to.
		*
		* @param	responseCode	The response code given by the server (for local pages, this will always be 0).
		*
		* @note	See http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html for common response code definitions.
		*/
		virtual void onNavigateComplete(Navi* caller, const std::string &url, int responseCode) = 0;
	};
}

#endif