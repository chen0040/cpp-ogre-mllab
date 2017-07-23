#ifndef _H_ML_LAB_GAME_DESIGN_FRAME_H
#define _H_ML_LAB_GAME_DESIGN_FRAME_H

#include "../Frames/AppFrame.h"
#include "../Camera/SphericalCamera.h"
#include "../InputSystem/MousePicker.h"
#include "../CIAgents/CIGameAgent.h"
#include "GameDesign/CIGameDesignWidget.h"
#include "../Widgets/WeatherDlg.h"
#include "GameDesign/UserBotActionWidget.h"
#include "GameDesign/IDBlockWidget.h"
#include "GameDesign/BotScriptWidget.h"
#include "GameDesign/GameSimulationControlBox.h"
#include "../tinyxml/tinyxml.h"

class GameDesignFrame : public AppFrame
{
public:
	GameDesignFrame(Application* app, const std::string& name);
	virtual ~GameDesignFrame();

public:
	virtual bool mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id);
	virtual bool mouseMoved(const OIS::MouseEvent& evt);
	virtual bool keyPressed(const OIS::KeyEvent& evt);

public:
	void unload();

public:
	virtual bool frameStarted(const FrameEvent& evt);
	virtual bool frameEntered();
	virtual bool frameExited();

protected:
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();
	virtual AppFrameState getFrameState() const;

protected:
	void restoreAgents();
	void backupAgents();
	void removeAllAgents();

public:
	virtual void save();

protected:
	bool onClicked_Climate(const CEGUI::EventArgs& evt);
	bool onClicked_ResetCamera(const CEGUI::EventArgs& evt);
	bool onClicked_TrainAgent(const CEGUI::EventArgs& evt);
	bool onClicked_UploadConfig(const CEGUI::EventArgs& evt);
	bool onClicked_StartSimulation(const CEGUI::EventArgs& evt);
	bool onClicked_StopSimulation(const CEGUI::EventArgs& evt);
	bool onClicked_ShowAgents(const CEGUI::EventArgs& evt);
	bool onClicked_RemoveAgents(const CEGUI::EventArgs& evt);
	bool onSelected_Model(const CEGUI::EventArgs& evt);
	bool onClicked_NavigateMiniMap(const CEGUI::EventArgs& evt);

protected:
	void onBrowserJSEventCallback(const NaviLibrary::NaviData& data);

protected:
	boost::signals::connection mEventScriptDeleted;
	boost::signals::connection mEventScriptsRefreshed;

protected:
	void onScriptDeleted();
	void onScriptsRefreshed();

protected:
	virtual bool onStateChanged(AppFrameState prevState, AppFrameState currState);
protected:
	void setupCommands();
	CIGameAgent* createScriptedGameAgent(const Vector3& pos);
	CIGameAgent* createScriptedGameAgent(const std::string& scriptId, const Vector3& pos);
	CIGameAgent* createScriptedGameAgent(const std::string& scriptId, const Vector3& pos, Ogre::ColourValue& c);
	void updateUI();
	void updateGameSimulationControlBox(const Real& dt);
	void updateBoard();
	void updateScoreBoard(Real dt);
	void uploadScoreBoard(Real dt);

private:
	void doNewSimulation();

protected:
	CIGameAgent* mCurrentCIAgent;

protected:
	MousePicker mMousePicker;

protected:
	TextOverlay* mBoard;
	CIGameDesignWidget* mGameDesignWidget;
	WeatherDlg* mWeatherDlg;
	IDBlockWidget* mIDBlock;
	UserBotActionWidget* mUserBotActionWidget;
	BotScriptWidget* mBotScriptWidget;
	GameSimulationControlBox* mGameSimulationControlBox;
	WebBrowser* mWebBrowser;

protected:
	CEGUI::Event::Connection mEventClimate;
	CEGUI::Event::Connection mEventTrainAgent;
	CEGUI::Event::Connection mEventUploadConfig;
	CEGUI::Event::Connection mEventModelSelected;
	CEGUI::Event::Connection mEventStartSimulation;
	CEGUI::Event::Connection mEventStopSimulation;
	CEGUI::Event::Connection mEventShowAgents;
	CEGUI::Event::Connection mEventRemoveAgents;
	CEGUI::Event::Connection mEventNavigateMiniMap;

private:
	Real mScoreboardTimer;
	Real mSimulationTimer;
	Real mScoreboardRecordInterval;
	size_t mScoreboardCriteria_bulletCount;
	int mScoreboardCriteria_life;
	Real mScoreboardCriteria_armor;
	Real mScoreboardCriteria_walkSpeed;
	Real mScoreboardCriteria_senseRange;
	TiXmlDocument* mScoreboardDoc;
	bool mScoreboardDocSaved;
private:
	void recordScoreboardDoc(const Real& dt);
	void createScoreboardDoc();
	void saveScoreboardDoc();

protected:
	CEGUI::MenuItem* mCmdClimate;
	CEGUI::MenuItem* mCmdTrainAgent;

protected:
	CIGameAgent::Set mAgentPool;
protected:
	CIGameAgent* getGameAgent(MovableObject* mo);
	void removeAgent(CIGameAgent* agent);
	void unselectAgents();
	void selectAgent(MovableObject* mo);
	void filterInvalidAgents();
};
#endif