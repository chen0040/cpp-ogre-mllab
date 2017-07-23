/*
	This file is part of Astral, a wrapper for Mozilla Gecko, designed explicitly for NaviLibrary.

	The contents of this file are subject to the Mozilla Public License
	Version 1.1 (the "MPL License"); you may not use this file except in
	compliance with the License. You may obtain a copy of the License at
	http://www.mozilla.org/MPL/

	Software distributed under the License is distributed on an "AS IS"
	basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
	License for the specific language governing rights and limitations
	under the License.

	The Original Code is Copyright (C) 2008 Adam J. Simmons.

	The Initial Developer of the Original Code is Adam J. Simmons.
	Portions created by the Initial Developer are Copyright (C) 2008
	by the Initial Developer. All Rights Reserved.
*/

#ifndef __BrowserWindow_H__
#define __BrowserWindow_H__

#include <string>

namespace Astral {

class BrowserWindowListener;

class BrowserWindow
{
public:
	virtual ~BrowserWindow() {}
	
	virtual void destroy() = 0;

	virtual void navigateTo(const std::string& url) = 0;
	virtual void navigateStop() = 0;
	virtual void navigateReload() = 0;
	virtual void navigateForward() = 0;
	virtual void navigateBack() = 0;
	
	virtual bool canNavigateForward() const = 0;
	virtual bool canNavigateBack() const = 0;

	virtual std::string evaluateJS(const std::string& script) = 0;

	virtual void focus() = 0;
	virtual void defocus() = 0;

	virtual void injectMouseMove(short x, short y) = 0;
	virtual void injectMouseDown(short x, short y) = 0;
	virtual void injectMouseUp(short x, short y) = 0;
	virtual void injectMouseDblClick(short x, short y) = 0;
	virtual void injectKeyPress(int keyCode) = 0;
	virtual void injectKeyUnicode(int unicodeChar) = 0;
	virtual void injectScroll(short numLines) = 0;

	virtual void addListener(BrowserWindowListener* listener) = 0;
	virtual void removeListener(BrowserWindowListener* listener) = 0;

	virtual bool isLoading() const = 0;
	virtual bool isDirty() = 0;

	virtual bool render(unsigned char* destination, int destRowSpan, int destDepth, bool force = false) = 0;

	virtual std::string getCurrentURL() const = 0;

	virtual std::pair<int,int> getDimensions() const = 0;

	virtual void resize(short width, short height) = 0;
};

class BrowserWindowListener
{
public:
	virtual void onNavigateBegin(BrowserWindow* caller, const std::string& url, bool &shouldContinue) = 0;
	virtual void onNavigateComplete(BrowserWindow* caller, const std::string& url, int responseCode) = 0;
	virtual void onUpdateProgress(BrowserWindow* caller, short percentComplete) = 0;
	virtual void onStatusTextChange(BrowserWindow* caller, const std::string& statusText) = 0;
	virtual void onLocationChange(BrowserWindow* caller, const std::string& url) = 0;
};

}

#endif