#ifndef _H_MLLAB_GAME_SIMULATION_CONTROL_BOX_H
#define _H_MLLAB_GAME_SIMULATION_CONTROL_BOX_H


#include "../../Widgets/CIWidget.h"
#include "GameSimulationOptionDlg.h"

class GameSimulationControlBox : public CIWidget
{
public:
	GameSimulationControlBox(const std::string& rootId, CEGUI::Window* parentWindow=NULL);
	virtual ~GameSimulationControlBox();

protected:
	virtual void create();
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

private:
	CEGUI::Event::Connection mEventSimulationOption;

private:
	CEGUI::PushButton* mBtnStartSimulation;
	CEGUI::PushButton* mBtnStopSimulation;
	CEGUI::PushButton* mBtnSimulationDisplay;
	CEGUI::PushButton* mBtnSimulationOption;
	CEGUI::PushButton* mBtnRemoveAgents;
public:
	CEGUI::PushButton* getStartSimulationButton() { return mBtnStartSimulation; }
	CEGUI::PushButton* getStopSimulationButton() { return mBtnStopSimulation; }
	CEGUI::PushButton* getSimulationDisplayButton() { return mBtnSimulationDisplay; }
	CEGUI::PushButton* getRemoveAgentsButton() { return mBtnRemoveAgents; }

private:
	bool onCloseClicked(const CEGUI::EventArgs& evt);
	bool onClicked_SimulationOption(const CEGUI::EventArgs& evt);

public:
	void inSimulation(bool simulated);
	bool inSimulation() const;
	bool isVisible() const;

public:
	void hide();
	void show();

private:
	bool mSimulation;
public:
	const std::vector<std::string>& getSimulationScripts() const;
	bool isAllAgentsRemovedOnStarted() const { return mGameSimulationOptionDlg->isAllAgentsRemovedOnStarted(); }
	int getSimulationCount() const { return mGameSimulationOptionDlg->getSimulationCount(); }
	void setSimulationCount(int count) { mGameSimulationOptionDlg->setSimulationCount(count); }
	void decrementSimulationCount() { mGameSimulationOptionDlg->decrementSimulationCount(); }
	void resetSimulationCount() { mGameSimulationOptionDlg->resetSimulationCount(); }
	bool isInitializationCellBased() const { return mGameSimulationOptionDlg->isInitializationCellBased(); }
	bool isRandomAuraColorEnabled() const { return mGameSimulationOptionDlg->isRandomAuraColorEnabled(); }
	bool recordLastEntry() const { return mGameSimulationOptionDlg->recordLastEntry(); }
	bool isSoundEnabled() const { return mGameSimulationOptionDlg->isSoundEnabled(); }

public:
	void setCaptionDetail(const std::string& detail);

public:
	bool isTerminationOnSecondsReached() const { return mGameSimulationOptionDlg->isTerminationOnSecondsReached(); }
	bool isTerminationOnLivesRemained() const { return mGameSimulationOptionDlg->isTerminationOnLivesRemained(); }
	int getLivesRemainedOnTermination() const { return mGameSimulationOptionDlg->getLivesRemainedOnTermination(); }
	Real getSecondsOnTermination() const { return mGameSimulationOptionDlg->getSecondsOnTermination(); }

public:
	bool isExpertMode() const { return mGameSimulationOptionDlg->isExpertMode(); }

public:
	Real getMaxX() const { return mGameSimulationOptionDlg->getMaxX(); }
	Real getMinX() const { return mGameSimulationOptionDlg->getMinX(); }
	Real getMaxZ() const { return mGameSimulationOptionDlg->getMaxZ(); }
	Real getMinZ() const { return mGameSimulationOptionDlg->getMinZ(); }

private:
	GameSimulationOptionDlg* mGameSimulationOptionDlg;
public:
	GameSimulationOptionDlg* getGameSimulationOptionDlg() { return mGameSimulationOptionDlg; }
};

#endif