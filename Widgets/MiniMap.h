#ifndef _H_ML_LAB_MINIMAP_H
#define _H_ML_LAB_MINIMAP_H

#include <string>
#include <CEGUI/CEGUI.h>
#include <Ogre.h>
#include <OgreCEGUIRenderer.h>
#include "CIWidget.h"

using namespace Ogre;

class MiniMap
{
public:
	MiniMap(const std::string& id, RenderWindow* rw, SceneManager* sm, CEGUI::OgreCEGUIRenderer* renderer);
	virtual ~MiniMap();

public:
	virtual void show();
	virtual void hide();
	bool isVisible() const { return mEnabled; }
	virtual CEGUI::FrameWindow* getMinimapWindow() { return mRootWindow; }
	CEGUI::DefaultWindow* getMap() { return mMap; }

protected:
	virtual void enable(bool enabled);
	virtual std::string getUIId(const std::string localId);

public:
	CEGUI::Point getMapDim() const;
	CEGUI::Point getMapTopLeft() const;
	CEGUI::Point PtInMap(const float& mx, const float& my) const;

protected:
	std::string mRootId;
	std::string mId;
	bool mEnabled;

public:
	virtual void setAlpha(float alpha);
	virtual void setPosition(float x, float y);
	virtual void setSize(float w, float h);

protected:
	CEGUI::FrameWindow* mRootWindow;
	CEGUI::Window* mParentWindow;
	CEGUI::DefaultWindow* mMap;
	CEGUI::Scrollbar* mAlphaScroller;
	CEGUI::Scrollbar* mHeightScroller;

protected:
	bool onScroll_Alpha(const CEGUI::EventArgs& evt);
	bool onScroll_Height(const CEGUI::EventArgs& evt);

protected:
	SceneManager* mSceneMgr;
	RenderWindow* mWindow;
	Camera* mCam;
	CEGUI::OgreCEGUIRenderer* mGUIRenderer;

protected:
	CEGUI::Event::Connection mEventAlphaScroll;
	CEGUI::Event::Connection mEventHeightScroll;
};
#endif