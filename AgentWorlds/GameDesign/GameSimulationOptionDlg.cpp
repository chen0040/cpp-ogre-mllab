#include "GameSimulationOptionDlg.h"
#include "../../tinyxml/tinyxml.h"
#include "../../OSEnvironment/OSEnvironment.h"
#include "../../ScriptEngine/ScriptManager.h"
#include "../../Widgets/GUIManager.h"

GameSimulationOptionDlg::GameSimulationOptionDlg(const std::string& rootId, CEGUI::Window* parentWindow)
: CIWidget(NULL, parentWindow)
{
	this->initializeComponents(rootId);
}

const std::vector<std::string>& GameSimulationOptionDlg::getSimulationScripts() const
{
	return mSimulationScripts;
}

GameSimulationOptionDlg::~GameSimulationOptionDlg()
{
	if(mEditTerminatePeriod != NULL)
	{
		delete mEditTerminatePeriod;
		mEditTerminatePeriod=NULL;
	}

	if(mEditTerminateLives != NULL)
	{
		delete mEditTerminateLives;
		mEditTerminateLives=NULL;
	}

	if(mEditSimulationCount != NULL)
	{
		delete mEditSimulationCount;
		mEditSimulationCount=NULL;
	}

	if(mEditMaxX != NULL)
	{
		delete mEditMaxX;
		mEditMaxX= NULL;
	}

	if(mEditMinZ != NULL)
	{
		delete mEditMinZ;
		mEditMinZ= NULL;
	}

	if(mEditMinX != NULL)
	{
		delete mEditMinX;
		mEditMinX= NULL;
	}

	if(mEditMaxZ != NULL)
	{
		delete mEditMaxZ;
		mEditMaxZ= NULL;
	}

	mParentWindow->removeChildWindow(mRootWindow);

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	wm->destroyWindow(mRootWindow);
}

void GameSimulationOptionDlg::create()
{
	load();

	const float txtWidth=1.0f;
	const float txtHeight=0.1f;
	const float labelWidth=0.6f;
	const float labelWidth2=0.45f;
	const float chkWidth=0.91f;
	const float vgap=0.01f;
	const float hgap=0.01f;
	const float left=0.1f;
	const float top=0.3f;
	float x=left;
	float y=top;

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	CEGUI::FrameWindow* frame=static_cast<CEGUI::FrameWindow*>(wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId()));
	//frame->toggleRollup();
	mRootWindow=frame;
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.4f), cegui_reldim(0.5f)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0.3f), cegui_reldim(0.25f)));
	mRootWindow->setAlpha(0.6f);
	mRootWindow->setText((CEGUI::utf8*)"Game Simulation Options");

	CEGUI::TabControl* tc=static_cast<CEGUI::TabControl*>(wm->createWindow(CIWidget::getGUIType("TabControl"), this->getUIId("TabControl")));
	tc->setSize(CEGUI::UVector2(cegui_reldim(0.9f), cegui_reldim(0.82f)));
	tc->setPosition(CEGUI::UVector2(cegui_reldim(0.05f), cegui_reldim(0.07f)));
	mRootWindow->addChildWindow(tc);

	CEGUI::Window* tabMode =wm->createWindow(CIWidget::getGUIType("ScrollablePane"), getUIId("tabMode"));
	tabMode->setText("Mode");
	tabMode->setPosition(CEGUI::UVector2(cegui_reldim(0.05f), cegui_reldim(0.05f)));
	tabMode->setSize(CEGUI::UVector2(cegui_reldim(0.9f), cegui_reldim(0.95f)));
	//tabMode->setProperty((CEGUI::utf8*)"Font", (CEGUI::utf8*)"Commonwealth-8");
	tc->addTab(tabMode);

	x=left;
	y=top;
	mChkExpertMode=static_cast<CEGUI::Checkbox*>(wm->createWindow(CIWidget::getGUIType("Checkbox"), this->getUIId("chkExpertMode")));
	mChkExpertMode->setSize(CEGUI::UVector2(cegui_reldim(chkWidth), cegui_reldim(txtHeight)));
	mChkExpertMode->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mChkExpertMode->setText("Expert Mode");
	tabMode->addChildWindow(mChkExpertMode);

	y+=(txtHeight+vgap);
	mScrollableText=static_cast<CEGUI::MultiLineEditbox*>(wm->createWindow(CIWidget::getGUIType("MultiLineEditbox"), getUIId("scrollPane")));
	mScrollableText->setSize(CEGUI::UVector2(cegui_reldim(0.9f), cegui_reldim(0.7f)));
	mScrollableText->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mScrollableText->setText(OSEnvironment::readFile(OSEnvironment::getFullPath("..\\config\\SimulationOption.txt").c_str()));
	mScrollableText->setReadOnly(true);
	tabMode->addChildWindow(mScrollableText);

	CEGUI::Window* tabInit =wm->createWindow(CIWidget::getGUIType("ScrollablePane"), getUIId("tabInit"));
	tabInit->setText("Initialization");
	tabInit->setPosition(CEGUI::UVector2(cegui_reldim(0.05f), cegui_reldim(0.05f)));
	tabInit->setSize(CEGUI::UVector2(cegui_reldim(0.9f), cegui_reldim(0.95f)));
	//tabInit->setProperty((CEGUI::utf8*)"Font", (CEGUI::utf8*)"Commonwealth-8");
	tc->addTab(tabInit);

	x=left;
	y=top;
	mEditMaxX=new CITextFieldWidget(getUIId("editMaxX"), this, tabInit, txtWidth, txtHeight, labelWidth);
	mEditMaxX->setLabel("Max region X (limit: 1250): ");
	mEditMaxX->setPosition(x, y);

	y+=(txtHeight+vgap);
	mEditMinX=new CITextFieldWidget(getUIId("editMinX"), this, tabInit, txtWidth, txtHeight, labelWidth);
	mEditMinX->setLabel("Min region X (limit: 250): ");
	mEditMinX->setPosition(x, y);

	y+=(txtHeight+vgap);
	mEditMaxZ=new CITextFieldWidget(getUIId("editMaxZ"), this, tabInit, txtWidth, txtHeight, labelWidth);
	mEditMaxZ->setLabel("Max region Z (limit: 1250): ");
	mEditMaxZ->setPosition(x, y);

	y+=(txtHeight+vgap);
	mEditMinZ=new CITextFieldWidget(getUIId("editMinZ"), this, tabInit, txtWidth, txtHeight, labelWidth);
	mEditMinZ->setLabel("Min region Z (limit: 250): ");
	mEditMinZ->setPosition(x, y);

	y+=(txtHeight+vgap);
	mChkCellInit=static_cast<CEGUI::Checkbox*>(wm->createWindow(CIWidget::getGUIType("Checkbox"), this->getUIId("chkCellInit")));
	mChkCellInit->setSize(CEGUI::UVector2(cegui_reldim(chkWidth), cegui_reldim(txtHeight)));
	mChkCellInit->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mChkCellInit->setText("Initialization with cell confinement");
	tabInit->addChildWindow(mChkCellInit);

	y+=(txtHeight+vgap);
	mChkRandomAuraColor=static_cast<CEGUI::Checkbox*>(wm->createWindow(CIWidget::getGUIType("Checkbox"), this->getUIId("chkRandomAuraColor")));
	mChkRandomAuraColor->setSize(CEGUI::UVector2(cegui_reldim(chkWidth), cegui_reldim(txtHeight)));
	mChkRandomAuraColor->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mChkRandomAuraColor->setText("Randomize agent aura at new simulation");
	tabInit->addChildWindow(mChkRandomAuraColor);

	y+=(txtHeight+vgap);
	mChkRemoveAgentsOnStart=static_cast<CEGUI::Checkbox*>(wm->createWindow(CIWidget::getGUIType("Checkbox"), this->getUIId("chkRemoveAgentsOnStart")));
	mChkRemoveAgentsOnStart->setSize(CEGUI::UVector2(cegui_reldim(0.9f), cegui_reldim(txtHeight)));
	mChkRemoveAgentsOnStart->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mChkRemoveAgentsOnStart->setText("Remove all agents at new simulation");
	tabInit->addChildWindow(mChkRemoveAgentsOnStart);

	y+=(txtHeight+vgap);
	mChkSoundEnabled=static_cast<CEGUI::Checkbox*>(wm->createWindow(CIWidget::getGUIType("Checkbox"), this->getUIId("khkSoundEnabled")));
	mChkSoundEnabled->setSize(CEGUI::UVector2(cegui_reldim(0.9f), cegui_reldim(txtHeight)));
	mChkSoundEnabled->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mChkSoundEnabled->setText("Enable sound at new simulation");
	tabInit->addChildWindow(mChkSoundEnabled);
	

	CEGUI::Window* tabTerminate =wm->createWindow(CIWidget::getGUIType("ScrollablePane"), getUIId("tabTerminate"));
	tabTerminate->setText("Termination");
	tabTerminate->setPosition(CEGUI::UVector2(cegui_reldim(0.05f), cegui_reldim(0.05f)));
	tabTerminate->setSize(CEGUI::UVector2(cegui_reldim(chkWidth), cegui_reldim(0.95f)));
	//tabTerminate->setProperty((CEGUI::utf8*)"Font", (CEGUI::utf8*)"Commonwealth-8");
	tc->addTab(tabTerminate);

	x=left;
	y=top;
	mEditTerminatePeriod=new CITextFieldWidget(getUIId("editTerminatePeriod"), this, tabTerminate, txtWidth, txtHeight, labelWidth2);
	mEditTerminatePeriod->setLabel("Period (secs): ");
	mEditTerminatePeriod->setPosition(x, y);

	y+=(txtHeight+vgap);
	mEditTerminateLives=new CITextFieldWidget(getUIId("editTerminateLives"), this, tabTerminate, txtWidth, txtHeight, labelWidth2);
	mEditTerminateLives->setLabel("Lives to remain: ");
	mEditTerminateLives->setPosition(x, y);

	y+=(txtHeight+vgap);
	mEditSimulationCount=new CITextFieldWidget(getUIId("editSimulationCount"), this, tabTerminate, txtWidth, txtHeight, labelWidth2);
	mEditSimulationCount->setLabel("Simulation Count: ");
	mEditSimulationCount->setPosition(x, y);

	y+=(txtHeight+vgap);
	mChkTerminateOnLives=static_cast<CEGUI::Checkbox*>(wm->createWindow(CIWidget::getGUIType("Checkbox"), this->getUIId("chkTerminateOnLives")));
	mChkTerminateOnLives->setSize(CEGUI::UVector2(cegui_reldim(chkWidth), cegui_reldim(txtHeight)));
	mChkTerminateOnLives->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mChkTerminateOnLives->setText("Terminate on limited survivers");
	tabTerminate->addChildWindow(mChkTerminateOnLives);

	y+=(txtHeight+vgap);
	mChkTerminateOnPeriod=static_cast<CEGUI::Checkbox*>(wm->createWindow(CIWidget::getGUIType("Checkbox"), this->getUIId("chkTerminateOnPeriod")));
	mChkTerminateOnPeriod->setSize(CEGUI::UVector2(cegui_reldim(chkWidth), cegui_reldim(txtHeight)));
	mChkTerminateOnPeriod->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mChkTerminateOnPeriod->setText("Terminate after limited seconds");
	tabTerminate->addChildWindow(mChkTerminateOnPeriod);

	y+=(txtHeight+vgap);
	mChkRecordLastEntry=static_cast<CEGUI::Checkbox*>(wm->createWindow(CIWidget::getGUIType("Checkbox"), this->getUIId("chkRecordLastEntry")));
	mChkRecordLastEntry->setSize(CEGUI::UVector2(cegui_reldim(chkWidth), cegui_reldim(txtHeight)));
	mChkRecordLastEntry->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mChkRecordLastEntry->setText("Record only the final entry");
	tabTerminate->addChildWindow(mChkRecordLastEntry);

	CEGUI::Window* tabAgents =wm->createWindow(CIWidget::getGUIType("ScrollablePane"), getUIId("tabAgents"));
	tabAgents->setText("Agents");
	tabAgents->setPosition(CEGUI::UVector2(cegui_reldim(0.05f), cegui_reldim(0.05f)));
	tabAgents->setSize(CEGUI::UVector2(cegui_reldim(0.9f), cegui_reldim(0.95f)));
	//tabAgents->setProperty((CEGUI::utf8*)"Font", (CEGUI::utf8*)"Commonwealth-8");
	tc->addTab(tabAgents);

	const float listingWidth=0.47f;
	const float listingHeight=0.7f;
	y=top;
	x=left;
	CEGUI::Window* lblScriptListing=wm->createWindow(CIWidget::getGUIType("StaticText"), getUIId("lblScriptListing"));
	lblScriptListing->setText("Available Scripts");
	lblScriptListing->setSize(CEGUI::UVector2(cegui_reldim(listingWidth), cegui_reldim(txtHeight)));
	lblScriptListing->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	lblScriptListing->setProperty((CEGUI::utf8*)"FrameEnabled", (CEGUI::utf8*)"false");
	tabAgents->addChildWindow(lblScriptListing);

	x+=(listingWidth+hgap);
	lblScriptListing=wm->createWindow(CIWidget::getGUIType("StaticText"), getUIId("lblSimulationScriptListing"));
	lblScriptListing->setText("Simulation Scripts");
	lblScriptListing->setSize(CEGUI::UVector2(cegui_reldim(listingWidth), cegui_reldim(txtHeight)));
	lblScriptListing->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	lblScriptListing->setProperty((CEGUI::utf8*)"FrameEnabled", (CEGUI::utf8*)"false");
	tabAgents->addChildWindow(lblScriptListing);

	y+=(txtHeight+vgap);
	x=left;
	mScriptListing=static_cast<CEGUI::Listbox*>(wm->createWindow(CIWidget::getGUIType("Listbox"), getUIId("ScriptListing")));
	mScriptListing->setSize(CEGUI::UVector2(cegui_reldim(listingWidth), cegui_reldim(listingHeight)));
	mScriptListing->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mScriptListing->setMultiselectEnabled(true);
	tabAgents->addChildWindow(mScriptListing);

	x+=(listingWidth+hgap);
	mSimulationScriptListing=static_cast<CEGUI::Listbox*>(wm->createWindow(CIWidget::getGUIType("Listbox"), getUIId("SimulationScriptListing")));
	mSimulationScriptListing->setSize(CEGUI::UVector2(cegui_reldim(listingWidth), cegui_reldim(listingHeight)));
	mSimulationScriptListing->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mSimulationScriptListing->setMultiselectEnabled(true);
	tabAgents->addChildWindow(mSimulationScriptListing);

	x=left;
	y+=(listingHeight+vgap);
	const float btnWidth=0.3f;
	mBtnAddScript=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnAddScript")));
	mBtnAddScript->setText((CEGUI::utf8*)"Add");
	mBtnAddScript->setSize(CEGUI::UVector2(cegui_reldim(btnWidth), cegui_reldim(txtHeight)));
	mBtnAddScript->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	tabAgents->addChildWindow(mBtnAddScript);

	x+=(btnWidth+hgap);
	mBtnRemoveScript=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnRemoveScript")));
	mBtnRemoveScript->setText((CEGUI::utf8*)"Remove");
	mBtnRemoveScript->setSize(CEGUI::UVector2(cegui_reldim(btnWidth), cegui_reldim(txtHeight)));
	mBtnRemoveScript->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	tabAgents->addChildWindow(mBtnRemoveScript);

	x+=(btnWidth+hgap);
	mBtnClearScripts=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnClearScripts")));
	mBtnClearScripts->setText((CEGUI::utf8*)"Remove All");
	mBtnClearScripts->setSize(CEGUI::UVector2(cegui_reldim(btnWidth), cegui_reldim(txtHeight)));
	mBtnClearScripts->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	tabAgents->addChildWindow(mBtnClearScripts);


	const float normalizedButtonHeight=0.08f;

	x=0.54f;
	mBtnOK=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), this->getUIId("OK")));
	mBtnOK->setText((CEGUI::utf8*)"OK");
	mBtnOK->setSize(CEGUI::UVector2(cegui_reldim(0.20f), cegui_reldim(normalizedButtonHeight)));
	mBtnOK->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(0.9f)));
	mRootWindow->addChildWindow(mBtnOK);	

	x+=(0.20f+hgap);
	mBtnApply=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), this->getUIId("btnApply")));
	mBtnApply->setText((CEGUI::utf8*)"Apply");
	mBtnApply->setSize(CEGUI::UVector2(cegui_reldim(0.20f), cegui_reldim(normalizedButtonHeight)));
	mBtnApply->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(0.9f)));
	mRootWindow->addChildWindow(mBtnApply);	

	mParentWindow->addChildWindow(mRootWindow);
	mRootWindow->hide();
}

void GameSimulationOptionDlg::subscribeEvents()
{
	mEventWindowClosed=mRootWindow->subscribeEvent(CEGUI::FrameWindow::EventCloseClicked, CEGUI::Event::Subscriber(&GameSimulationOptionDlg::onCloseClicked, this));
	mEventOK=mBtnOK->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameSimulationOptionDlg::onOK, this));
	mEventApply=mBtnApply->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameSimulationOptionDlg::onApply, this));

	mEventAddScript=mBtnAddScript->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameSimulationOptionDlg::onClicked_AddScript, this));
	mEventRemoveScript=mBtnRemoveScript->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameSimulationOptionDlg::onClicked_RemoveScript, this));
	mEventClearScripts=mBtnClearScripts->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameSimulationOptionDlg::onClicked_ClearScripts, this));
}

void GameSimulationOptionDlg::unsubscribeEvents()
{
	mEventWindowClosed->disconnect();
	mEventOK->disconnect();
	mEventApply->disconnect();

	mEventAddScript->disconnect();
	mEventRemoveScript->disconnect();
	mEventClearScripts->disconnect();
}

bool GameSimulationOptionDlg::onClicked_AddScript(const CEGUI::EventArgs& evt)
{
	size_t selectedItemCount=mScriptListing->getSelectedCount();

	if(selectedItemCount == 0)
	{
		GUIManager::getSingletonPtr()->showMsgBox("No script selected", "Please select scripts from the available scripts first");
		return true;
	}

	size_t itemCount=mScriptListing->getItemCount();
	for(size_t i=0; i != itemCount; ++i)
	{
		CEGUI::ListboxTextItem* item=static_cast<CEGUI::ListboxTextItem*>(mScriptListing->getListboxItemFromIndex(i));
		if(item->isSelected())
		{
			CEGUI::ListboxTextItem* newItem=new CEGUI::ListboxTextItem(item->getText(), static_cast<CEGUI::uint>(mSimulationScriptListing->getItemCount()));
			newItem->setTooltipText(item->getTooltipText());
			newItem->setSelectionBrushImage((CEGUI::utf8*)GUIManager::getSingletonPtr()->getGUITheme().c_str(), (CEGUI::utf8*)"MultiListSelectionBrush");
			mSimulationScriptListing->addItem(newItem);
		}
	}
	return true;
}

bool GameSimulationOptionDlg::onClicked_RemoveScript(const CEGUI::EventArgs& evt)
{
	size_t selectedItemCount=mSimulationScriptListing->getSelectedCount();

	if(selectedItemCount == 0)
	{
		GUIManager::getSingletonPtr()->showMsgBox("No script selected", "Please select scripts from the simulation scripts first");
		return true;
	}

	size_t itemCount=mSimulationScriptListing->getItemCount();
	std::vector<CEGUI::ListboxTextItem*> removedItems;
	for(size_t i=0; i != itemCount; ++i)
	{
		CEGUI::ListboxTextItem* item=static_cast<CEGUI::ListboxTextItem*>(mSimulationScriptListing->getListboxItemFromIndex(i));
		if(item->isSelected())
		{
			removedItems.push_back(item);
		}
	}

	for(size_t i=0; i != selectedItemCount; ++i)
	{
		mSimulationScriptListing->removeItem(removedItems[i]);
	}
	return true;
}

bool GameSimulationOptionDlg::onClicked_ClearScripts(const CEGUI::EventArgs& evt)
{
	mSimulationScriptListing->resetList();
	return true;
}

bool GameSimulationOptionDlg::onOK(const CEGUI::EventArgs& evt)
{
	updateData(true);
	save();

	this->hideWindow();
	return true;
}

bool GameSimulationOptionDlg::onApply(const CEGUI::EventArgs& evt)
{
	updateData(true);
	save();

	return true;
}

void GameSimulationOptionDlg::updateData(bool validateAndSaved)
{
	if(validateAndSaved)
	{
		this->mDefaultSimulationCount=atoi(this->mEditSimulationCount->getText().c_str());
		this->mSimulationCount=mDefaultSimulationCount;
		this->mLivesRemained2OnTermination=atoi(this->mEditTerminateLives->getText().c_str());
		this->mSecondsOnTermination=static_cast<float>(atof(this->mEditTerminatePeriod->getText().c_str()));

		this->mExpertMode=mChkExpertMode->isSelected();
		this->mTerminationOnLivesRemained=mChkTerminateOnLives->isSelected();
		this->mTerminationOnSecondsReached=mChkTerminateOnPeriod->isSelected();
		this->mRecordLastEntry=mChkRecordLastEntry->isSelected();

		this->mMaxX=atoi(this->mEditMaxX->getText().c_str());
		this->mMinX=atoi(this->mEditMinX->getText().c_str());
		this->mMaxZ=atoi(this->mEditMaxZ->getText().c_str());
		this->mMinZ=atoi(this->mEditMinZ->getText().c_str());

		this->mCellInit=mChkCellInit->isSelected();
		this->mRemoveAllAgentsOnStarted=mChkRemoveAgentsOnStart->isSelected();
		this->mRandomAuraColor=mChkRandomAuraColor->isSelected();
		this->mSoundEnabled=mChkSoundEnabled->isSelected();

		this->mSimulationScripts.clear();
		size_t itemCount=mSimulationScriptListing->getItemCount();
		for(size_t i=0; i != itemCount; ++i)
		{
			CEGUI::ListboxTextItem* item=static_cast<CEGUI::ListboxTextItem*>(mSimulationScriptListing->getListboxItemFromIndex(i));
			mSimulationScripts.push_back(item->getTooltipText().c_str());
		}
	}
	else
	{
		mEditTerminatePeriod->setText(OSEnvironment::toString(this->mSecondsOnTermination));
		mEditTerminateLives->setText(OSEnvironment::toString(this->mLivesRemained2OnTermination));
		mEditSimulationCount->setText(OSEnvironment::toString(this->mDefaultSimulationCount));

		mChkExpertMode->setSelected(this->mExpertMode);
		mChkTerminateOnLives->setSelected(this->mTerminationOnLivesRemained);
		mChkTerminateOnPeriod->setSelected(this->mTerminationOnSecondsReached);
		mChkRecordLastEntry->setSelected(this->mRecordLastEntry);

		mEditMaxX->setText(OSEnvironment::toString(this->mMaxX));
		mEditMaxZ->setText(OSEnvironment::toString(this->mMaxZ));
		mEditMinX->setText(OSEnvironment::toString(this->mMinX));
		mEditMinZ->setText(OSEnvironment::toString(this->mMinZ));

		mChkCellInit->setSelected(this->mCellInit);
		mChkRemoveAgentsOnStart->setSelected(this->mRemoveAllAgentsOnStarted);
		mChkRandomAuraColor->setSelected(this->mRandomAuraColor);
		mChkSoundEnabled->setSelected(this->mSoundEnabled);

		mScriptListing->resetList();
		ScriptManager* sm=ScriptManager::getSingletonPtr();
		const std::vector<std::string>& scriptListings=sm->getScriptListings();
		size_t scriptListingSize=scriptListings.size();
		for(size_t k=0; k != scriptListingSize; k++)
		{
			CEGUI::ListboxTextItem* item=new CEGUI::ListboxTextItem(sm->getNickname(scriptListings[k]), static_cast<CEGUI::uint>(k));
			item->setTooltipText(scriptListings[k]);
			item->setSelectionBrushImage((CEGUI::utf8*)GUIManager::getSingletonPtr()->getGUITheme().c_str(), (CEGUI::utf8*)"MultiListSelectionBrush");

			if(k==0)
			{
				item->setSelected(true);
			}
			mScriptListing->addItem(item);
		}

		mSimulationScriptListing->resetList();
		std::vector<std::string>::iterator siter=mSimulationScripts.begin();
		std::vector<std::string>::iterator siter_end=mSimulationScripts.end();
		CEGUI::uint k=0;
		while(siter != siter_end)
		{
			if(isValidScript(*siter))
			{
				CEGUI::ListboxTextItem* item=new CEGUI::ListboxTextItem(sm->getNickname(*siter), k++);
				item->setTooltipText(*siter);
				item->setSelectionBrushImage((CEGUI::utf8*)GUIManager::getSingletonPtr()->getGUITheme().c_str(), (CEGUI::utf8*)"MultiListSelectionBrush");

				mSimulationScriptListing->addItem(item);
				++siter;
			}
			else
			{
				siter=mSimulationScripts.erase(siter);
			}
		}
		mSimulationScriptListing->setSortingEnabled(true);
	}
}

bool GameSimulationOptionDlg::isValidScript(const std::string& scriptId) const
{
	return OSEnvironment::exists(OSEnvironment::getFullPath(OSEnvironment::append("..\\scripts\\", scriptId)));
}

void GameSimulationOptionDlg::show()
{	
	updateData(false);
	this->showWindow();
}

bool GameSimulationOptionDlg::onCloseClicked(const CEGUI::EventArgs& evt)
{
	this->hideWindow();
	return true;
}

bool GameSimulationOptionDlg::isExpertMode() const
{
	return mExpertMode;
}

std::string GameSimulationOptionDlg::getSimulationModel() const
{
	float r=Ogre::Math::RangeRandom(0, 1);
	
	std::map<std::string, float>::const_iterator miter_begin=mSimulationModels.begin();
	std::map<std::string, float>::const_iterator miter=miter_begin;

	std::map<std::string, float>::const_iterator miter_end=mSimulationModels.end();
	for(; miter != miter_end; ++miter)
	{
		if(r < miter->second)
		{
			return miter->first;
		}
	}

	return "";
}

void GameSimulationOptionDlg::load()
{
	TiXmlDocument doc;
	if(!doc.LoadFile(OSEnvironment::getFullPath("..\\config\\simulation.xml").c_str()))
	{
		throw Ogre::Exception(42, "Failed to load simulation.xml", "GameSimulationControlBox::load()");
	}

	TiXmlElement* xmlRoot=doc.RootElement();

	if(strcmp(xmlRoot->Attribute("remove_agents_on_start"), "true")==0)
	{
		mRemoveAllAgentsOnStarted=true;
	}
	else
	{
		mRemoveAllAgentsOnStarted=false;
	}

	if(strcmp(xmlRoot->Attribute("record_last_entry"), "true")==0)
	{
		mRecordLastEntry=true;
	}
	else
	{
		mRecordLastEntry=false;
	}

	if(strcmp(xmlRoot->Attribute("sound_enabled"), "true")==0)
	{
		mSoundEnabled=true;
	}
	else
	{
		mSoundEnabled=false;
	}

	if(strcmp(xmlRoot->Attribute("expert_mode"), "true")==0)
	{
		mExpertMode=true;
	}
	else
	{
		mExpertMode=false;
	}

	if(strcmp(xmlRoot->Attribute("cell_initialization"), "true")==0)
	{
		mCellInit=true;
	}
	else
	{
		mCellInit=false;
	}

	if(strcmp(xmlRoot->Attribute("random_aura_color"), "true")==0)
	{
		mRandomAuraColor=true;
	}
	else
	{
		mRandomAuraColor=false;
	}

	xmlRoot->QueryIntAttribute("simulation_count", &mDefaultSimulationCount);
	mSimulationCount=mDefaultSimulationCount;

	for(TiXmlElement* xmlLevel1=xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1 = xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "agents")==0)
		{
			for(TiXmlElement* xmlLevel2=xmlLevel1->FirstChildElement(); xmlLevel2 != NULL; xmlLevel2 = xmlLevel2->NextSiblingElement())
			{
				if(strcmp(xmlLevel2->Value(), "agent")==0)
				{
					std::string scriptId=xmlLevel2->Attribute("scriptId");
					if(isValidScript(scriptId))
					{
						mSimulationScripts.push_back(scriptId);
					}
				}
			}
		}
		else if(strcmp(xmlLevel1->Value(), "models")==0)
		{
			float frequency=0;
			float accum_frequency=0;
			std::string model_name="";
			for(TiXmlElement* xmlLevel2=xmlLevel1->FirstChildElement(); xmlLevel2 != NULL; xmlLevel2=xmlLevel2->NextSiblingElement())
			{
				if(strcmp(xmlLevel2->Value(), "model")==0)
				{
					xmlLevel2->QueryFloatAttribute("frequency", &frequency);
					accum_frequency+=frequency;
					model_name=xmlLevel2->Attribute("name");
					mSimulationModelFrequency[model_name]=frequency;
					mSimulationModels[model_name]=accum_frequency;
				}
			}
		}
		else if(strcmp(xmlLevel1->Value(), "region")==0)
		{
			xmlLevel1->QueryFloatAttribute("minX", &mMinX);
			xmlLevel1->QueryFloatAttribute("maxX", &mMaxX);
			xmlLevel1->QueryFloatAttribute("minZ", &mMinZ);
			xmlLevel1->QueryFloatAttribute("maxZ", &mMaxZ);
		}
		else if(strcmp(xmlLevel1->Value(), "stop_after_seconds")==0)
		{
			if(strcmp(xmlLevel1->Attribute("enabled"), "true")==0)
			{
				mTerminationOnSecondsReached=true;
			}
			else
			{
				mTerminationOnSecondsReached=false;
			}
			xmlLevel1->QueryFloatAttribute("seconds", &mSecondsOnTermination);
		}
		else if(strcmp(xmlLevel1->Value(), "stop_after_lifes")==0)
		{
			if(strcmp(xmlLevel1->Attribute("enabled"), "true")==0)
			{
				mTerminationOnLivesRemained=true;
			}
			else
			{
				mTerminationOnLivesRemained=false;
			}
			xmlLevel1->QueryIntAttribute("lives_remained", &mLivesRemained2OnTermination);
		}
	}
}

void GameSimulationOptionDlg::save()
{
	TiXmlDocument doc;

	doc.LinkEndChild(new TiXmlDeclaration("1.0", "", ""));

	TiXmlElement* xmlRoot=new TiXmlElement("simulation");
	doc.LinkEndChild(xmlRoot);

	if(this->mExpertMode)
	{
		xmlRoot->SetAttribute("expert_mode", "true");
	}
	else
	{
		xmlRoot->SetAttribute("expert_mode", "false");
	}

	if(this->isAllAgentsRemovedOnStarted())
	{
		xmlRoot->SetAttribute("remove_agents_on_start", "true");
	}
	else
	{
		xmlRoot->SetAttribute("remove_agents_on_start", "false");
	}

	if(this->mRecordLastEntry)
	{
		xmlRoot->SetAttribute("record_last_entry", "true");
	}
	else
	{
		xmlRoot->SetAttribute("record_last_entry", "false");
	}

	if(this->mSoundEnabled)
	{
		xmlRoot->SetAttribute("sound_enabled", "true");
	}
	else
	{
		xmlRoot->SetAttribute("sound_enabled", "false");
	}

	if(this->isInitializationCellBased())
	{
		xmlRoot->SetAttribute("cell_initialization", "true");
	}
	else
	{
		xmlRoot->SetAttribute("cell_initialization", "false");
	}

	if(this->mRandomAuraColor)
	{
		xmlRoot->SetAttribute("random_aura_color", "true");
	}
	else
	{
		xmlRoot->SetAttribute("random_aura_color", "false");
	}

	xmlRoot->SetAttribute("simulation_count", this->mDefaultSimulationCount);

	TiXmlElement* xmlLevel1=new TiXmlElement("stop_after_seconds");
	xmlRoot->LinkEndChild(xmlLevel1);

	if(this->isTerminationOnSecondsReached())
	{
		xmlLevel1->SetAttribute("enabled", "true");
	}
	else
	{
		xmlLevel1->SetAttribute("enabled", "false");
	}

	xmlLevel1->SetDoubleAttribute("seconds", this->getSecondsOnTermination());
	
	xmlLevel1=new TiXmlElement("stop_after_lifes");
	xmlRoot->LinkEndChild(xmlLevel1);

	if(this->isTerminationOnLivesRemained())
	{
		xmlLevel1->SetAttribute("enabled", "true");
	}
	else
	{
		xmlLevel1->SetAttribute("enabled", "false");
	}
	xmlLevel1->SetAttribute("lives_remained", this->getLivesRemainedOnTermination());

	xmlLevel1=new TiXmlElement("region");
	xmlRoot->LinkEndChild(xmlLevel1);
	xmlLevel1->SetDoubleAttribute("minX", this->getMinX());
	xmlLevel1->SetDoubleAttribute("maxX", this->getMaxX());
	xmlLevel1->SetDoubleAttribute("minZ", this->getMinZ());
	xmlLevel1->SetDoubleAttribute("maxZ", this->getMaxZ());

	xmlLevel1=new TiXmlElement("models");
	xmlRoot->LinkEndChild(xmlLevel1);
	std::map<std::string, float>::const_iterator miter=mSimulationModelFrequency.begin();
	std::map<std::string, float>::const_iterator miter_end=mSimulationModelFrequency.end();
	for(;miter != miter_end; ++miter)
	{
		TiXmlElement* xmlLevel2=new TiXmlElement("model");
		xmlLevel1->LinkEndChild(xmlLevel2);

		xmlLevel2->SetAttribute("name", (miter->first).c_str());
		xmlLevel2->SetDoubleAttribute("frequency", (miter->second));
	}

	xmlLevel1=new TiXmlElement("agents");
	xmlRoot->LinkEndChild(xmlLevel1);
	std::vector<std::string>::const_iterator siter=mSimulationScripts.begin();
	std::vector<std::string>::const_iterator siter_end=mSimulationScripts.end();
	for(;siter != siter_end; ++siter)
	{
		TiXmlElement* xmlLevel2=new TiXmlElement("agent");
		xmlLevel1->LinkEndChild(xmlLevel2);

		xmlLevel2->SetAttribute("scriptId", (*siter).c_str());
	}

	doc.SaveFile(OSEnvironment::getFullPath("..\\config\\simulation.xml").c_str());
}