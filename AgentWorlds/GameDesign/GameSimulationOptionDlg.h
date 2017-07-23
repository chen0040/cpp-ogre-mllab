#ifndef _H_MLLAB_GAME_SIMULATION_OPTION_DLG_H
#define _H_MLLAB_GAME_SIMULATION_OPTION_DLG_H

#include "../../Widgets/CIWidget.h"
#include "../../Widgets/CITextFieldWidget.h"
#include <Ogre.h>

using namespace Ogre;

class GameSimulationOptionDlg : public CIWidget
{
public:
	GameSimulationOptionDlg(const std::string& rootId, CEGUI::Window* parentWindow=NULL);
	virtual ~GameSimulationOptionDlg();

protected:
	virtual void create();
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

private:
	bool isValidScript(const std::string& scriptId) const;

private:
	void updateData(bool validateAndSaved=true);

private:
	CEGUI::Event::Connection mEventWindowClosed;

private:
	CEGUI::PushButton* mBtnOK;
	CEGUI::PushButton* mBtnApply;
private:
	CEGUI::Event::Connection mEventOK;
	CEGUI::Event::Connection mEventApply;
protected:
	bool onOK(const CEGUI::EventArgs& evt);
	bool onApply(const CEGUI::EventArgs& evt);

public:
	CEGUI::PushButton* getOKButton() { return mBtnOK; }

private:
	bool onCloseClicked(const CEGUI::EventArgs& evt);
	bool onClicked_AddScript(const CEGUI::EventArgs& evt);
	bool onClicked_RemoveScript(const CEGUI::EventArgs& evt);
	bool onClicked_ClearScripts(const CEGUI::EventArgs& evt);
public:
	void hide() { this->hideWindow(); }
	void show();
	bool isVisible() const { return mRootWindow->isVisible(); }

private:
	bool mExpertMode;
public:
	bool isExpertMode() const;

private:
	std::vector<std::string> mSimulationScripts;
	std::map<std::string, float> mSimulationModels;
	std::map<std::string, float> mSimulationModelFrequency;
	bool mRemoveAllAgentsOnStarted;
	int mSimulationCount;
	int mDefaultSimulationCount;
	bool mCellInit;
	bool mRandomAuraColor;
	bool mRecordLastEntry;
	bool mSoundEnabled;
public:
	const std::vector<std::string>& getSimulationScripts() const;
	bool isAllAgentsRemovedOnStarted() const { return mRemoveAllAgentsOnStarted; }
	int getSimulationCount() const { return mSimulationCount; }
	void setSimulationCount(int count) { mSimulationCount; }
	void decrementSimulationCount() { mSimulationCount--; }
	void resetSimulationCount() { mSimulationCount=mDefaultSimulationCount; }
	bool isInitializationCellBased() const { return mCellInit; }
	bool isRandomAuraColorEnabled() const { return mRandomAuraColor; }
	bool recordLastEntry() const { return mRecordLastEntry; }
	bool isSoundEnabled() const { return mSoundEnabled; }
	std::string getSimulationModel() const;

private:
	bool mTerminationOnSecondsReached;
	bool mTerminationOnLivesRemained;
	int mLivesRemained2OnTermination;
	Real mSecondsOnTermination;
public:
	bool isTerminationOnSecondsReached() const { return mTerminationOnSecondsReached; }
	bool isTerminationOnLivesRemained() const { return mTerminationOnLivesRemained; }
	int getLivesRemainedOnTermination() const { return mLivesRemained2OnTermination; }
	Real getSecondsOnTermination() const { return mSecondsOnTermination; }

private:
	Real mMaxX;
	Real mMaxZ;
	Real mMinX;
	Real mMinZ;
public:
	Real getMaxX() const { return mMaxX; }
	Real getMinX() const { return mMinX; }
	Real getMaxZ() const { return mMaxZ; }
	Real getMinZ() const { return mMinZ; }


private:
	CEGUI::MultiLineEditbox* mScrollableText;
	CEGUI::Listbox* mScriptListing;
	CEGUI::Listbox* mSimulationScriptListing;

private:
	CEGUI::PushButton* mBtnAddScript;
	CEGUI::PushButton* mBtnRemoveScript;
	CEGUI::PushButton* mBtnClearScripts;
private:
	CEGUI::Event::Connection mEventAddScript;
	CEGUI::Event::Connection mEventRemoveScript;
	CEGUI::Event::Connection mEventClearScripts;

private:
	void load();
	void save();

private:
	CITextFieldWidget* mEditTerminatePeriod;
	CITextFieldWidget* mEditTerminateLives;
	CITextFieldWidget* mEditSimulationCount;
	CEGUI::Checkbox* mChkExpertMode;
	CEGUI::Checkbox* mChkTerminateOnLives;
	CEGUI::Checkbox* mChkTerminateOnPeriod;
	CEGUI::Checkbox* mChkRecordLastEntry;
	CITextFieldWidget* mEditMaxX;
	CITextFieldWidget* mEditMaxZ;
	CITextFieldWidget* mEditMinX;
	CITextFieldWidget* mEditMinZ;
	CEGUI::Checkbox* mChkCellInit;
	CEGUI::Checkbox* mChkRemoveAgentsOnStart;
	CEGUI::Checkbox* mChkRandomAuraColor;
	CEGUI::Checkbox* mChkSoundEnabled;
};
#endif