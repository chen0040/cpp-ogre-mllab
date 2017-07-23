#include "GameSimulationControlBox.h"
#include "../../OSEnvironment/OSEnvironment.h"

GameSimulationControlBox::GameSimulationControlBox(const std::string& rootId, CEGUI::Window* parentWindow)
: CIWidget(NULL, parentWindow)
{
	this->initializeComponents(rootId);
}

GameSimulationControlBox::~GameSimulationControlBox()
{
	if(mGameSimulationOptionDlg != NULL)
	{
		delete mGameSimulationOptionDlg;
		mGameSimulationOptionDlg=NULL;
	}

	mParentWindow->removeChildWindow(mRootWindow);

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	wm->destroyWindow(mRootWindow);
}

const std::vector<std::string>& GameSimulationControlBox::getSimulationScripts() const
{
	return this->mGameSimulationOptionDlg->getSimulationScripts();
}

void GameSimulationControlBox::setCaptionDetail(const std::string& detail)
{
	mRootWindow->setText(OSEnvironment::append("Simulation", detail).c_str());
}

void GameSimulationControlBox::create()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	const float windowWidth=0.4f;
	const float windowHeight=0.2f;
	const float windowLeft=0.0f;
	const float windowTop=0.05f;
	float top= 0.2f;
	const float left=0.04f;
	const float hgap=0.01f;
	const float vgap=0.02f;
	float btnWidth=(1-left*2-hgap) / 2;
	float btnHeight=(1-top - vgap*3) / 3;
	float x=left;
	float y=top;

	CEGUI::FrameWindow* frame=static_cast<CEGUI::FrameWindow*>(wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId()));
	//frame->toggleRollup();
	frame->setCloseButtonEnabled(false);
	mRootWindow=frame;
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(windowWidth), cegui_reldim(windowHeight)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(windowLeft), cegui_reldim(windowTop)));
	mRootWindow->setAlpha(0.6f);
	mRootWindow->setText((CEGUI::utf8*)"Simulation");

	mBtnStartSimulation=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnStartSimulation")));
	mBtnStartSimulation->setSize(CEGUI::UVector2(cegui_reldim(btnWidth), cegui_reldim(btnHeight)));
	mBtnStartSimulation->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnStartSimulation->setText((CEGUI::utf8*)"Start Simulation");
	mRootWindow->addChildWindow(mBtnStartSimulation);

	x+=(btnWidth+hgap);
	mBtnStopSimulation=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnStopSimulation")));
	mBtnStopSimulation->setSize(CEGUI::UVector2(cegui_reldim(btnWidth), cegui_reldim(btnHeight)));
	mBtnStopSimulation->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnStopSimulation->setText((CEGUI::utf8*)"Stop Simulation");
	mRootWindow->addChildWindow(mBtnStopSimulation);

	y+=(btnHeight+vgap);
	x=left;
	mBtnSimulationDisplay=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnSimulationDisplay")));
	mBtnSimulationDisplay->setSize(CEGUI::UVector2(cegui_reldim(btnWidth), cegui_reldim(btnHeight)));
	mBtnSimulationDisplay->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnSimulationDisplay->setText((CEGUI::utf8*)"Show Agents");
	mRootWindow->addChildWindow(mBtnSimulationDisplay);

	x+=(btnWidth+hgap);
	mBtnRemoveAgents=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnRemoveAgents")));
	mBtnRemoveAgents->setSize(CEGUI::UVector2(cegui_reldim(btnWidth), cegui_reldim(btnHeight)));
	mBtnRemoveAgents->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnRemoveAgents->setText((CEGUI::utf8*)"Remove Agents");
	mRootWindow->addChildWindow(mBtnRemoveAgents);

	y+=(btnHeight+vgap);
	x=left;
	mBtnSimulationOption=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnSimulationOption")));
	mBtnSimulationOption->setSize(CEGUI::UVector2(cegui_reldim(btnWidth), cegui_reldim(btnHeight)));
	mBtnSimulationOption->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnSimulationOption->setText((CEGUI::utf8*)"Simulation Option");
	mRootWindow->addChildWindow(mBtnSimulationOption);

	mGameSimulationOptionDlg=new GameSimulationOptionDlg(getUIId("GameSimulationOptionDlg"));

	inSimulation(false);
	

	mParentWindow->addChildWindow(mRootWindow);
	mRootWindow->hide();
}

void GameSimulationControlBox::subscribeEvents()
{
	//mEventStartSimulation=mBtnStartSimulation->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameSimulationControlBox::onClicked_StartSimulation, this));
	//mEventStopSimulation=mBtnStopSimulation->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameSimulationControlBox::onClicked_StopSimulation, this));
	mEventSimulationOption=mBtnSimulationOption->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameSimulationControlBox::onClicked_SimulationOption, this));
}

void GameSimulationControlBox::unsubscribeEvents()
{
	//mEventStartSimulation->disconnect();
	//mEventStopSimulation->disconnect();
	mEventSimulationOption->disconnect();
}

bool GameSimulationControlBox::onClicked_SimulationOption(const CEGUI::EventArgs& evt)
{
	mGameSimulationOptionDlg->show();
	return true;
}

/*
bool GameSimulationControlBox::onClicked_StartSimulation(const CEGUI::EventArgs& evt)
{
	inSimulation(true);
	return true;
}

bool GameSimulationControlBox::onClicked_StopSimulation(const CEGUI::EventArgs& evt)
{
	inSimulation(false);
	return true;
}
*/

void GameSimulationControlBox::show()
{
	this->showWindow();
}

void GameSimulationControlBox::hide()
{
	this->hideWindow();
	if(this->mGameSimulationOptionDlg->isVisible())
	{
		this->mGameSimulationOptionDlg->hide();
	}
}

bool GameSimulationControlBox::isVisible() const
{
	return mRootWindow->isVisible();
}

void GameSimulationControlBox::inSimulation(bool simulation)
{
	mSimulation=simulation;
	if(mSimulation)
	{
		mBtnStartSimulation->setEnabled(false);
		mBtnStopSimulation->setEnabled(true);
	}
	else
	{
		mBtnStartSimulation->setEnabled(true);
		mBtnStopSimulation->setEnabled(false);
		setCaptionDetail("");
	}
}

bool GameSimulationControlBox::inSimulation() const
{
	return mSimulation;
}