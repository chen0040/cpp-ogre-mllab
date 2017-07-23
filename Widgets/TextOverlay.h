#ifndef _H_ML_LAB_TEXT_OVERLAY_H
#define _H_ML_LAB_TEXT_OVERLAY_H

#include <Ogre.h>
#include <CEGUI/CEGUI.h>
#include "CIWidget.h"

using namespace Ogre;

class TextOverlay
{
public:
	TextOverlay(const CEGUI::String& overlayName);
	virtual ~TextOverlay();

public:
	void setText(const String& text);
	void setSize(Real w, Real h);
	void setPosition(Real x, Real y);
	void setAlpha(Real alpha);
	void setTitle(const String& title);

public:
	void enable(bool enbled);
	bool isEnabled() const { return mEnabled; }

public:
	void show() { enable(true); }
	void hide() { enable(false); }

private:
	CEGUI::Window* mRootWindow;
	CEGUI::Window* mParentWindow;
	CEGUI::MultiLineEditbox* mEditbox;
	bool mEnabled;
	CEGUI::String mOverlayName;
};
#endif