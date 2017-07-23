#ifndef _H_MLLAB_SCENE_DESIGN_FRAME_H
#define _H_MLLAB_SCENE_DESIGN_FRAME_H

#include <set>
#include "../Frames/AppFrame.h"
#include "../Camera/SphericalCamera.h"
#include "../InputSystem/MouseDrag.h"
#include "../InputSystem/MousePicker.h"
#include "../CIAgents/CIAgent.h"
#include "SceneDesign/SceneDesignToolkit.h"
#include "SceneDesign/GameLoaderSaveAsDlg.h"

class SceneDesignFrame : public AppFrame
{
public:
	SceneDesignFrame(Application* app, std::string frameName);
	virtual ~SceneDesignFrame();

public:
	virtual bool mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id);
	virtual bool mouseMoved(const OIS::MouseEvent& evt);
	virtual bool mouseReleased(const OIS::MouseEvent& evt, OIS::MouseButtonID id);
	virtual bool keyPressed(const OIS::KeyEvent& evt);
	virtual bool keyReleased(const OIS::KeyEvent& evt);

private:
	SceneNode* mPointer;

public:
	virtual bool frameStarted(const FrameEvent& evt);
	virtual bool frameEntered();
	virtual bool frameExited();

public:
	void save();
	void saveAs();

protected:
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

protected:
	void backupAgents();
	void restoreAgents();

protected:
	MouseDrag mMouseDrag;
	boost::signals::connection mEventDragClear;
	boost::signals::connection mEventDragSelect;
	MousePicker mMousePicker;

protected:
	void unselectAgents();
	void selectAgent(MovableObject* mo);

private:
	void doSceneDesignAction(const OIS::MouseEvent& evt);

protected:
	bool onButtonClicked_GameLoaderSaveAs(const CEGUI::EventArgs& evt);
private:
	CEGUI::Event::Connection mEventGameLoaderSaveAs;

protected:
	CIAgent* getAgent(MovableObject* mo);
	void removeAgent(CIAgent* agent);
	void removeAllAgents();

private:
	SceneDesignToolkit* mSceneDesignToolkit;
	GameLoaderSaveAsDlg* mSaveAsDlg;
};

#endif
