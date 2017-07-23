#ifndef _H_MLLAB_GAME_SIMULATION_FRAME_H
#define _H_MLLAB_GAME_SIMULATION_FRAME_H

#include "../CIAgents/CIGameAgent.h"
#include "../Frames/AppFrame.h"
#include "../InputSystem/MouseDrag.h"
#include "../InputSystem/MousePicker.h"

class GameSimulationFrame : public AppFrame
{
public:
	GameSimulationFrame(Application* app, std::string frameName);
	virtual ~GameSimulationFrame();

public:
	virtual bool mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id);
	virtual bool mouseMoved(const OIS::MouseEvent& evt);
	virtual bool mouseReleased(const OIS::MouseEvent& evt, OIS::MouseButtonID id);

public:
	virtual bool frameStarted(const FrameEvent& evt);
	virtual bool frameEntered();
	virtual bool frameExited();

protected:
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

protected:
	void backupAgents();
	void restoreAgents();

protected:
	CIGameAgent::Set mCurrentCIAgents;

protected:
	void onBrowserJSEventCallback(const NaviLibrary::NaviData& data);

protected:
	MouseDrag mMouseDrag;
	MousePicker mMousePicker;
	boost::signals::connection mEventDragClear;
	boost::signals::connection mEventDragSelect;

protected:
	void unselectAgents();
	void selectAgent(MovableObject* mo);

public:
	void unload();

protected:
	CIGameAgent::Set mAgentPool;
protected:
	CIGameAgent* getAgent(MovableObject* mo);
	void removeAgent(CIGameAgent* agent);
	void removeAllAgents();
};
#endif