#ifndef _H_MLLAB_APP_DOC_FRAME_H
#define _H_MLLAB_APP_DOC_FRAME_H

#include "../Frames/AppFrame.h"
#include "CodeDesign/CodeGenDlg.h"
#include "CodeDesign/CICodeDesignWidget.h"
#include "../InputSystem/MouseDrag.h"
#include "../InputSystem/MousePicker.h"
#include "../CIAgents/CICodeAgent.h"

class AppDocFrame : public AppFrame
{
public:
	AppDocFrame(Application* app, std::string frameName);
	virtual ~AppDocFrame();

public:
	virtual bool mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id);
	virtual bool mouseMoved(const OIS::MouseEvent& evt);
	virtual bool mouseReleased(const OIS::MouseEvent& evt, OIS::MouseButtonID id);
	virtual bool keyPressed(const OIS::KeyEvent& evt);

protected:
	virtual AppFrameState getFrameState() const;

public:
	void unload();

public:
	virtual bool frameStarted(const FrameEvent& evt);
	virtual bool frameEntered();
	virtual bool frameExited();

protected:
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();
	virtual void setupCommands();

protected:
	void backupAgents();
	void restoreAgents();

protected:
	bool onClicked_ConfigCI(const CEGUI::EventArgs& evt);
	bool onClicked_GenerateCode(const CEGUI::EventArgs& evt);
	bool onClicked_ShowPS(const CEGUI::EventArgs& evt);

public:
	virtual void open();
	virtual void save();

protected:
	CICodeAgent::Set mCurrentCIAgents;

protected:
	CodeGenDlg* mCodeGenDlg;
	CICodeDesignWidget* mCodeDesignWidget;
	TextOverlay* mBoard;

protected:
	void onBrowserJSEventCallback(const NaviLibrary::NaviData& data);
	void updateCodeDesignWidget();

protected:
	CEGUI::Event::Connection mEventShowPS;
	CEGUI::Event::Connection mEventShowConfig;
	CEGUI::Event::Connection mEventGenerateCode;

protected:
	WebBrowser* mWebBrowser;
	
protected:
	CEGUI::MenuItem* mCmdConfig;
	CEGUI::MenuItem* mCmdGenerate;

protected:
	MouseDrag mMouseDrag;
	boost::signals::connection mEventDragClear;
	boost::signals::connection mEventDragSelect;

protected:
	MousePicker mMousePicker;

protected:
	void unselectAgents();
	void selectAgent(MovableObject* mo);

protected:
	CICodeAgent::Set mAgentPool;
protected:
	CICodeAgent* getCodeAgent(MovableObject* mo);
	CICodeAgent* createCodeAgent(const Vector3& pos);
	void removeAgent(CICodeAgent* agent);
	void removeAllAgents();
};
#endif