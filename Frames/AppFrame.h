#ifndef _H_MLLAB_APP_FRAME_H
#define _H_MLLAB_APP_FRAME_H

#include <string>
#include <Ogre.h>
#include <OIS/OIS.h>
#include <CEGUI/CEGUI.h>
#include "Navi.h"
#include "../Widgets/GUIManager.h"
#include "../Camera/SphericalCamera.h"
#include "../Camera/FirstPersonCamera.h"

using namespace Ogre;

class Application;

class AppFrame
{
public:
	enum AppFrameState {	SELECT,	CREATE,	SIMULATE, UNKNOWN };

public:
	AppFrame(Application* app, const std::string& frameName);
	virtual ~AppFrame();

protected:
	Application* mApp;

public:
	bool onFrameSelected(const CEGUI::EventArgs& evt);

protected:
	bool mLeftButtonDown;
	bool mRightButtonDown;
	bool mContinue;

public:
	virtual void unload() { }

protected:
	bool isKeyDown(OIS::KeyCode keyCode) const;

protected:
	OIS::Mouse* mMouse;
	OIS::Keyboard* mKeyboard;

protected:
	virtual AppFrameState getFrameState() const;
	virtual AppFrameState getPrevFrameState() const { return mPrevState; }
	bool inFrameState(AppFrameState state) const { return mCurrState==state; }
private:
	AppFrameState mPrevState;
	AppFrameState mCurrState;
private:
	void updateState();
protected:
	virtual bool onStateChanged(AppFrameState prevState, AppFrameState currState);

protected:
	SceneManager* mSceneMgr;
	GUIManager* mGUIMgr;

protected:
	std::string mFrameName;
public:
	const std::string& getName() const { return mFrameName; }

protected:
	std::string getUIId(const std::string& localId) const;
private:
	void resetMouse();

public:
	virtual void quit();
	virtual void open();
	virtual void save();
	virtual void saveAs();

protected:
	CEGUI::MouseButton convertButton(OIS::MouseButtonID id)
	{
		switch(id)
		{
		case OIS::MB_Left:
			return CEGUI::LeftButton;
		case OIS::MB_Right:
			return CEGUI::RightButton;
		case OIS::MB_Middle:
			return CEGUI::MiddleButton;
		default:
			return CEGUI::LeftButton;
		}
	}

protected:
	virtual void subscribeEvents() { }
	virtual void unsubscribeEvents() { }
	
protected:
	bool isMouseWithinWindow() const;
	void switchWindowMouse();

public:
	virtual bool frameStarted(const FrameEvent& evt);
	virtual bool frameEntered();
	virtual bool frameExited();

public:
	virtual void windowResized(RenderWindow* window);

public:
	virtual bool keyPressed(const OIS::KeyEvent& evt);
	virtual bool keyReleased(const OIS::KeyEvent& evt);
	virtual bool mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id);
	virtual bool mouseReleased(const OIS::MouseEvent& evt, OIS::MouseButtonID id);
	virtual bool mouseMoved(const OIS::MouseEvent& evt);
};
#endif