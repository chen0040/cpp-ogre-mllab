#include "UserBotActionWidget.h"
#include "../../Recorder/GameAgentRecorder.h"
#include "../../OSEnvironment/OSEnvironment.h"

UserBotActionWidget::UserBotActionWidget(const std::string rootId, CEGUI::Window* parentWindow)
: CIWidget(NULL, parentWindow)
, mUserBot(NULL)
{
	this->initializeComponents(rootId);
}
	
UserBotActionWidget::~UserBotActionWidget()
{
	mRootWindow->removeChildWindow(mRadioApproachEnemy);
	mRootWindow->removeChildWindow(mRadioAttackEnemy);
	mRootWindow->removeChildWindow(mRadioEscapeEnemy);
	mRootWindow->removeChildWindow(mRadioIdle);
	mRootWindow->removeChildWindow(mRadioWander);

	mRootWindow->removeChildWindow(mBtnPause);
	mRootWindow->removeChildWindow(mBtnContinue);
	mRootWindow->removeChildWindow(mBtnCaptureData);
	mRootWindow->removeChildWindow(mBtnClearData);
	mRootWindow->removeChildWindow(mBtnSaveData);

	/*
	mRootWindow->removeChildWindow(mRadioLockDefaultEnemy);
	mRootWindow->removeChildWindow(mRadioLockClosestEnemy);
	mRootWindow->removeChildWindow(mRadioLockStrongestEnemy);
	mRootWindow->removeChildWindow(mRadioLockRandomEnemy);
	mRootWindow->removeChildWindow(mRadioLockWeakestEnemy);
	mRootWindow->removeChildWindow(mRadioLockAttackingEnemy);
	*/

	mRootWindow->removeChildWindow(mLabelActionSelection);
	//mRootWindow->removeChildWindow(mLabelEnemySelection);

	mRootWindow->removeChildWindow(mEditBox);
	mRootWindow->removeChildWindow(mChkCaptureOnActionChanged);

	mParentWindow->removeChildWindow(mRootWindow);

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	wm->destroyWindow(mRadioApproachEnemy);
	wm->destroyWindow(mRadioAttackEnemy);
	wm->destroyWindow(mRadioEscapeEnemy);
	wm->destroyWindow(mRadioIdle);
	wm->destroyWindow(mRadioWander);

	wm->destroyWindow(mBtnPause);
	wm->destroyWindow(mBtnContinue);
	wm->destroyWindow(mBtnCaptureData);
	wm->destroyWindow(mBtnClearData);
	wm->destroyWindow(mBtnSaveData);

	/*
	wm->destroyWindow(mRadioLockDefaultEnemy);
	wm->destroyWindow(mRadioLockClosestEnemy);
	wm->destroyWindow(mRadioLockStrongestEnemy);
	wm->destroyWindow(mRadioLockRandomEnemy);
	wm->destroyWindow(mRadioLockWeakestEnemy);
	wm->destroyWindow(mRadioLockAttackingEnemy);
	*/

	wm->destroyWindow(mLabelActionSelection);
	//wm->destroyWindow(mLabelEnemySelection);

	wm->destroyWindow(mEditBox);
	wm->destroyWindow(mChkCaptureOnActionChanged);

	wm->destroyWindow(mRootWindow);
}

void UserBotActionWidget::create()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	CEGUI::FrameWindow* frame=static_cast<CEGUI::FrameWindow*>(wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId()));
	mRootWindow=frame;
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.6f), cegui_reldim(0.4f)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0.0f), cegui_reldim(0.12f)));
	mRootWindow->setAlpha(0.6f);
	frame->setCloseButtonEnabled(false);
	mRootWindow->setText((CEGUI::utf8*)"Action State: Paused");

	const float radioButtonWidth=0.4f;
	const float radioButtonHeight=0.1f;
	const float buttonWidth=0.19f;
	const float vgap=0.01f;
	const float hgap=0.05f;
	float left=0.05f;
	float top=0.1f;
	float x=left;
	float y=top;

	mBtnPause=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnPause")));
	mBtnPause->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(radioButtonHeight)));
	mBtnPause->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnPause->setText((CEGUI::utf8*)"Pause");
	mBtnPause->setEnabled(false);
	mRootWindow->addChildWindow(mBtnPause);

	x+=(buttonWidth+0.01f);
	mBtnContinue=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnContinue")));
	mBtnContinue->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(radioButtonHeight)));
	mBtnContinue->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnContinue->setText((CEGUI::utf8*)"Continue");
	mBtnContinue->setEnabled(true);
	mRootWindow->addChildWindow(mBtnContinue);

	x+=(buttonWidth+0.03f);
	y=0.05f;
	mChkCaptureOnActionChanged=static_cast<CEGUI::Checkbox*>(wm->createWindow(CIWidget::getGUIType("Checkbox"), getUIId("chkCaptureOnActionChange")));
	mChkCaptureOnActionChanged->setSize(CEGUI::UVector2(cegui_reldim(radioButtonWidth), cegui_reldim(0.19f)));
	mChkCaptureOnActionChanged->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mChkCaptureOnActionChanged->setText((CEGUI::utf8*)"Auto-capture on action changed");
	mChkCaptureOnActionChanged->setSelected(false);
	mRootWindow->addChildWindow(mChkCaptureOnActionChanged);

	x=0.03f;
	y=(top+radioButtonHeight+vgap);
	mLabelActionSelection=static_cast<CEGUI::Window*>(wm->createWindow(CIWidget::getGUIType("StaticText"), getUIId("lblActionSelection")));
	mLabelActionSelection->setSize(CEGUI::UVector2(cegui_reldim(radioButtonWidth), cegui_reldim(radioButtonHeight)));
	mLabelActionSelection->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mLabelActionSelection->setText((CEGUI::utf8*)"Action:");
	mLabelActionSelection->setProperty((CEGUI::utf8*)"FrameEnabled", (CEGUI::utf8*)"false");
	mLabelActionSelection->setProperty((CEGUI::utf8*)"BackgroundEnabled", (CEGUI::utf8*)"false");
	mRootWindow->addChildWindow(mLabelActionSelection);

	y+=(radioButtonHeight+vgap);
	mRadioApproachEnemy=static_cast<CEGUI::RadioButton*>(wm->createWindow(CIWidget::getGUIType("RadioButton"), getUIId("rdoApproachEnemy")));
	mRadioApproachEnemy->setSize(CEGUI::UVector2(cegui_reldim(radioButtonWidth), cegui_reldim(radioButtonHeight)));
	mRadioApproachEnemy->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mRadioApproachEnemy->setText((CEGUI::utf8*)"Approach");
	mRadioApproachEnemy->setGroupID(1);
	mRootWindow->addChildWindow(mRadioApproachEnemy);

	y+=(radioButtonHeight+vgap);
	mRadioAttackEnemy=static_cast<CEGUI::RadioButton*>(wm->createWindow(CIWidget::getGUIType("RadioButton"), getUIId("rdoAttackEnemy")));
	mRadioAttackEnemy->setSize(CEGUI::UVector2(cegui_reldim(radioButtonWidth), cegui_reldim(radioButtonHeight)));
	mRadioAttackEnemy->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mRadioAttackEnemy->setText((CEGUI::utf8*)"Attack");
	mRadioAttackEnemy->setGroupID(1);
	mRootWindow->addChildWindow(mRadioAttackEnemy);

	y+=(radioButtonHeight+vgap);
	mRadioEscapeEnemy=static_cast<CEGUI::RadioButton*>(wm->createWindow(CIWidget::getGUIType("RadioButton"), getUIId("rdoEscapeEnemy")));
	mRadioEscapeEnemy->setSize(CEGUI::UVector2(cegui_reldim(radioButtonWidth), cegui_reldim(radioButtonHeight)));
	mRadioEscapeEnemy->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mRadioEscapeEnemy->setText((CEGUI::utf8*)"Escape");
	mRadioEscapeEnemy->setGroupID(1);
	mRootWindow->addChildWindow(mRadioEscapeEnemy);

	y+=(radioButtonHeight+vgap);
	mRadioWander=static_cast<CEGUI::RadioButton*>(wm->createWindow(CIWidget::getGUIType("RadioButton"), getUIId("rdoWander")));
	mRadioWander->setSize(CEGUI::UVector2(cegui_reldim(radioButtonWidth), cegui_reldim(radioButtonHeight)));
	mRadioWander->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mRadioWander->setText((CEGUI::utf8*)"Wander");
	mRadioWander->setGroupID(1);
	mRootWindow->addChildWindow(mRadioWander);

	y+=(radioButtonHeight+vgap);
	mRadioIdle=static_cast<CEGUI::RadioButton*>(wm->createWindow(CIWidget::getGUIType("RadioButton"), getUIId("rdoIdle")));
	mRadioIdle->setSize(CEGUI::UVector2(cegui_reldim(radioButtonWidth), cegui_reldim(radioButtonHeight)));
	mRadioIdle->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mRadioIdle->setText((CEGUI::utf8*)"Idle");
	mRadioIdle->setSelected(true);
	mRadioIdle->setGroupID(1);
	mRootWindow->addChildWindow(mRadioIdle);

	mCurrentAgentAction=this->getActionState();

	y=(top+radioButtonHeight+vgap);
	x=0.2f;
	mEditBox=static_cast<CEGUI::MultiLineEditbox*>(wm->createWindow(CIWidget::getGUIType("MultiLineEditbox"), getUIId("editBox")));
	mEditBox->setSize(CEGUI::UVector2(cegui_reldim(0.75f), cegui_reldim(0.65f)));
	mEditBox->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	//mEditBox->setReadOnly(true);
	
	mRootWindow->addChildWindow(mEditBox);

	y=0.87f;
	float buttonWidth2=(0.73f / 3);
	mBtnCaptureData=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnCaptureData")));
	mBtnCaptureData->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth2), cegui_reldim(radioButtonHeight)));
	mBtnCaptureData->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnCaptureData->setText((CEGUI::utf8*)"Capture");
	mBtnCaptureData->setEnabled(true);
	mRootWindow->addChildWindow(mBtnCaptureData);

	x+=(buttonWidth2+0.01f);
	mBtnClearData=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnClearData")));
	mBtnClearData->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth2), cegui_reldim(radioButtonHeight)));
	mBtnClearData->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnClearData->setText((CEGUI::utf8*)"Reload Records");
	mBtnClearData->setEnabled(true);
	mRootWindow->addChildWindow(mBtnClearData);

	x+=(buttonWidth2+0.01f);
	mBtnSaveData=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnSaveData")));
	mBtnSaveData->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth2), cegui_reldim(radioButtonHeight)));
	mBtnSaveData->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnSaveData->setText((CEGUI::utf8*)"Save Records");
	mBtnSaveData->setEnabled(false);
	mRootWindow->addChildWindow(mBtnSaveData);

	mRootWindow->hide();
	mParentWindow->addChildWindow(mRootWindow);
}


bool UserBotActionWidget::isVisible() const
{
	return mRootWindow->isVisible();
}

void UserBotActionWidget::subscribeEvents()
{
	mEventCaptureContinue=mBtnContinue->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&UserBotActionWidget::onClicked_ToggleCaptureState, this));
	mEventCapturePause=mBtnPause->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&UserBotActionWidget::onClicked_ToggleCaptureState, this));
	mEventCaptureData=mBtnCaptureData->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&UserBotActionWidget::onClicked_CaptureData, this));
	mEventClearData=mBtnClearData->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&UserBotActionWidget::onClicked_ClearData, this));
	mEventSaveData=mBtnSaveData->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&UserBotActionWidget::onClicked_SaveData, this));
}
	
void UserBotActionWidget::unsubscribeEvents()
{
	mEventCaptureContinue->disconnect();
	mEventCapturePause->disconnect();
	mEventCaptureData->disconnect();
	mEventClearData->disconnect();
	mEventSaveData->disconnect();
}

CIGameAgentActionState UserBotActionWidget::getActionState() const
{
	if(mRadioApproachEnemy->isSelected())
	{
		return APPROACH;
	}
	else if(mRadioAttackEnemy->isSelected())
	{
		return ATTACK;
	}
	else if(mRadioEscapeEnemy->isSelected())
	{
		return ESCAPE;
	}
	else if(mRadioIdle->isSelected())
	{
		return IDLE;
	}
	else if(mRadioWander->isSelected())
	{
		return WANDER;
	}

	return UNKNOWN_ACTION_STATE;
}

/*
CIGameAgentTargetChoice UserBotActionWidget::getEnemyChoice() const
{
	if(mRadioLockClosestEnemy->isSelected())
	{
		return CLOSEST_ENEMY;
	}
	else if(mRadioLockDefaultEnemy->isSelected())
	{
		return DEFAULT_ENEMY;
	}
	else if(mRadioLockStrongestEnemy->isSelected())
	{
		return STRONGEST_ENEMY;
	}
	else if(mRadioLockWeakestEnemy->isSelected())
	{
		return WEAKEST_ENEMY;
	}
	else if(mRadioLockRandomEnemy->isSelected())
	{
		return RANDOM_ENEMY;
	}
	else if(mRadioLockAttackingEnemy->isSelected())
	{
		return ATTACKER_ENEMY;
	}

	return UNKOWN_ENEMY_CHOICE;
}
*/

GameDesignCaptureState UserBotActionWidget::GetCaptureState() const
{
	if(mBtnContinue->isDisabled())
	{
		return CAPTURE_STATE_ACTIVE;
	}
	return CAPTURE_STATE_PAUSE;
}

bool UserBotActionWidget::inCaptureState(GameDesignCaptureState state) const
{
	return GetCaptureState()==state; 
}

bool UserBotActionWidget::onClicked_ToggleCaptureState(const CEGUI::EventArgs& evt)
{
	if(mBtnContinue->isDisabled())
	{
		mBtnContinue->setEnabled(true);
		mBtnPause->setEnabled(false);
		mRootWindow->setText((CEGUI::utf8*)"Action State: Paused");
	}
	else
	{
		mBtnPause->setEnabled(true);
		mBtnContinue->setEnabled(false);
		mRootWindow->setText((CEGUI::utf8*)"Action State: Active");
	}
	return true;
}

bool UserBotActionWidget::onClicked_CaptureData(const CEGUI::EventArgs& evt)
{
	if(mUserBot != NULL)
	{
		GameAgentRecorder::getSingletonPtr()->capture(mUserBot, this->getActionState());
		GameAgentRecorder::getSingletonPtr()->setModified(true);
		mBtnSaveData->setEnabled(true);
	}
	return true;
}
	
bool UserBotActionWidget::onClicked_ClearData(const CEGUI::EventArgs& evt)
{
	GameAgentRecorder::getSingletonPtr()->clear();
	GameAgentRecorder::getSingletonPtr()->setModified(true);
	mBtnSaveData->setEnabled(true);
	return true;
}

bool UserBotActionWidget::onClicked_SaveData(const CEGUI::EventArgs& evt)
{
	GameAgentRecorder::getSingletonPtr()->save(OSEnvironment::getFullPath("..\\records"));
	GameAgentRecorder::getSingletonPtr()->setModified(false);
	mBtnSaveData->setEnabled(false);
	return true;
}

void UserBotActionWidget::update(const float& dt)
{
	if(mUserBot==NULL)
	{
		return;
	}
	std::ostringstream oss;

	if(mUserBot->isTargetAttackable()==0)
	{
		oss << "state[1] = " << "0 > enemy attackable = false";
	}
	else
	{
		oss << "state[1] = " << "1 > enemy attackable = true";
	}

	oss << "\n";

	size_t attackerCount=mUserBot->getSightedAttackerCount();
	oss << "state[2] = " << attackerCount << " > number of enemies insight = " << attackerCount << "\n";

	double relativeDistance=mUserBot->getTargetRelativeDistance();
	oss << "state[3] = " << relativeDistance << " > enemy distance / player shooting range = " << relativeDistance << "\n";

	double relativeLife=mUserBot->getTargetRelativeLife();
	oss << "state[4] = " << relativeLife << " > enemy health / player health = " << relativeLife << "\n";

	size_t bulletCount=mUserBot->getGun()->getBulletCount();
	oss << "state[5] = " << bulletCount << " > current bullets = " << bulletCount << "\n";

	size_t life = mUserBot->getLife();
	oss << "state[6] = " << life << " > current health condition= " << life << "\n";

	size_t score=mUserBot->getScore();
	oss << "state[7] = " << score << " > current score = " << score << "\n";

	if(mRadioApproachEnemy->isSelected())
	{
		oss << "output[1] = " <<  APPROACH << " > action = GameAgentAction.APPROACH";
	}
	else if(mRadioAttackEnemy->isSelected())
	{
		oss << "output[1] = " <<  ATTACK << " > action = GameAgentAction.ATTACK";
	}
	else if(mRadioEscapeEnemy->isSelected())
	{
		oss << "output[1] = " <<  ESCAPE << " > action = GameAgentAction.ESCAPE";
	}
	else if(mRadioIdle->isSelected())
	{
		oss << "output[1] = " <<  IDLE << " > action = GameAgentAction.IDLE";
	}
	else if(mRadioWander->isSelected())
	{
		oss << "output[1] = " <<  WANDER << " > action = GameAgentAction.WANDER";
	}

	oss << "\ncurrent available training data: " << GameAgentRecorder::getSingletonPtr()->getRecordCount() << " records";
	
	if(GameAgentRecorder::getSingletonPtr()->isModified())
	{
		oss << "\ncaptured data modified: please save your captured data by pressing the \"Save Record\" button";
	}
	else
	{
		oss << "\ncaptured data saved";
	}

	CIGameAgentActionState new_state=this->getActionState();
	if(this->mCurrentAgentAction != new_state)
	{
		mCurrentAgentAction=new_state;
		if(this->mChkCaptureOnActionChanged->isSelected())
		{
				if(mUserBot != NULL)
				{
					GameAgentRecorder::getSingletonPtr()->capture(mUserBot, this->getActionState());
					GameAgentRecorder::getSingletonPtr()->setModified(true);
					mBtnSaveData->setEnabled(true);
				}
		}
	}

	mEditBox->setText(oss.str().c_str());
}



