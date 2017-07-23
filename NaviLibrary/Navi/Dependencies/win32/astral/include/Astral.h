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

#ifndef __Astral_H__
#define __Astral_H__

#include "BrowserWindow.h"
#include <vector>

namespace Astral {

namespace Impl {
	class BrowserWindowImpl;
}

class AstralManager
{
public:
	AstralManager(const std::string& runtimeDir, void* windowHandle);
	~AstralManager();

	static AstralManager& Get();
	static AstralManager* GetPointer();

	BrowserWindow* createBrowserWindow(int width, int height);

	bool setBooleanPref(const std::string& prefName, bool value);
	bool setIntegerPref(const std::string& prefName, int value);
	bool setStringPref(const std::string& prefName, const std::string& value);

	void defocusAll();

	void clearCache();
	
protected:
	static AstralManager* instance;
	std::vector<BrowserWindow*> windows;
	typedef std::vector<BrowserWindow*>::iterator WindowIter;
	friend class Impl::BrowserWindowImpl;
	void* windowHandle;
};

}

#endif