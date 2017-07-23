#ifndef _H_ML_LAB_USER_BOT_ACTION_WIDGET_H
#define _H_ML_LAB_USER_BOT_ACTION_WIDGET_H

#include "../../Widgets/CIWidget.h"
#include "../../CIAgents/CIGameAgentActionState.h"
#include "../../CIAgents/CIGameAgentTargetChoice.h"
#include "../../CIAgents/CIGameAgent.h"

enum GameDesignCaptureState
{
	CAPTURE_STATE_ACTIVE,
	CAPTURE_STATE_PAUSE
};

class UserBotActionWidget : public CIWidget
{
public:
	UserBotActionWidget(const std::string rootId, CEGUI::Window* parent=NULL);
	virtual ~UserBotActionWidget();

public:
	bool isVisible() const;

protected:
	virtual void create();
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

public:
	GameDesignCaptureState GetCaptureState() const;
	bool inCaptureState(GameDesignCaptureState state) const;

protected:
	void createBotConfigUI();

public:
	void update(const float& dt);
	void setUserBot(CIGameAgent* userBot) { mUserBot=userBot; }
	CIGameAgent* getUserBot() { return mUserBot; }

public:
	CIGameAgentActionState getActionState() const;
	//CIGameAgentTargetChoice getEnemyChoice() const;

protected:
	CEGUI::RadioButton* mRadioApproachEnemy;
	CEGUI::RadioButton* mRadioAttackEnemy;
	CEGUI::RadioButton* mRadioEscapeEnemy;
	CEGUI::RadioButton* mRadioWander;
	CEGUI::RadioButton* mRadioIdle;

protected:
	CEGUI::Window* mLabelActionSelection;
	//CEGUI::Window* mLabelEnemySelection;

protected:
	CEGUI::PushButton* mBtnPause;
	CEGUI::PushButton* mBtnContinue;
	CEGUI::PushButton* mBtnCaptureData;
	CEGUI::PushButton* mBtnClearData;
	CEGUI::PushButton* mBtnSaveData;

/*
protected:
	CEGUI::RadioButton* mRadioLockRandomEnemy;
	CEGUI::RadioButton* mRadioLockStrongestEnemy;
	CEGUI::RadioButton* mRadioLockAttackingEnemy;
	CEGUI::RadioButton* mRadioLockClosestEnemy;
	CEGUI::RadioButton* mRadioLockDefaultEnemy;
	CEGUI::RadioButton* mRadioLockWeakestEnemy;
*/

protected:
	CEGUI::Event::Connection mEventCaptureContinue;
	CEGUI::Event::Connection mEventCapturePause;
	CEGUI::Event::Connection mEventCaptureData;
	CEGUI::Event::Connection mEventClearData;
	CEGUI::Event::Connection mEventSaveData;

protected:
	CEGUI::Checkbox* mChkCaptureOnActionChanged;

private:
	CIGameAgentActionState mCurrentAgentAction;

public:
	bool onClicked_ToggleCaptureState(const CEGUI::EventArgs& evt);
	bool onClicked_CaptureData(const CEGUI::EventArgs& evt);
	bool onClicked_ClearData(const CEGUI::EventArgs& evt);
	bool onClicked_SaveData(const CEGUI::EventArgs& evt);

private:
	CIGameAgent* mUserBot;
	CEGUI::MultiLineEditbox* mEditBox;
};

#endif