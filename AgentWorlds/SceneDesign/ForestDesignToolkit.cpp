#include "ForestDesignToolkit.h"
#include "../../SceneAssets/PGManager.h"
#include "../../OSEnvironment/OSEnvironment.h"

ForestDesignToolkit::ForestDesignToolkit(const std::string& rootId)
: CIWidget(NULL, NULL)
{
	initializeComponents(rootId);
}

ForestDesignToolkit::~ForestDesignToolkit()
{
	if(mRadius != NULL)
	{
		delete mRadius;
		mRadius=NULL;
	}

	if(mCount != NULL)
	{
		delete mCount;
		mCount=NULL;
	}
}

void ForestDesignToolkit::subscribeEvents()
{
	mEventPopulateGrass=mBtnPopulateGrass->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ForestDesignToolkit::onButtonClicked_PopulateGrass, this));
	mEventPopulateTree=mBtnPopulateTree->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ForestDesignToolkit::onButtonClicked_PopulateTree, this));
	mEventPopulateBush=mBtnPopulateBush->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ForestDesignToolkit::onButtonClicked_PopulateBush, this));

	mEventClearGrass=mBtnClearGrass->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ForestDesignToolkit::onButtonClicked_ClearGrass, this));
	mEventClearTree=mBtnClearTree->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ForestDesignToolkit::onButtonClicked_ClearTree, this));
	mEventClearBush=mBtnClearBush->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ForestDesignToolkit::onButtonClicked_ClearBush, this));
}

bool ForestDesignToolkit::onButtonClicked_PopulateGrass(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnPopulateGrass->disable();
	mForestDesignAction=FD_POPULATEGRASS;

	PGManager* pgm=PGManager::getSingletonPtr();
	

	return true;
}

bool ForestDesignToolkit::onButtonClicked_PopulateTree(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnPopulateTree->disable();

	mForestDesignAction=FD_POPULATETREE;

	return true;
}

bool ForestDesignToolkit::onButtonClicked_PopulateBush(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnPopulateBush->disable();

	mForestDesignAction=FD_POPULATEBUSH;

	PGManager* pgm=PGManager::getSingletonPtr();

	return true;
}

bool ForestDesignToolkit::onButtonClicked_ClearGrass(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnClearGrass->disable();
	mForestDesignAction=FD_CLEARGRASS;

	PGManager* pgm=PGManager::getSingletonPtr();
	

	return true;
}

bool ForestDesignToolkit::onButtonClicked_ClearTree(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnClearTree->disable();

	mForestDesignAction=FD_CLEARTREE;

	return true;
}

bool ForestDesignToolkit::onButtonClicked_ClearBush(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnClearBush->disable();

	mForestDesignAction=FD_CLEARBUSH;

	PGManager* pgm=PGManager::getSingletonPtr();

	return true;
}


void ForestDesignToolkit::enableAllButtons()
{
	std::vector<CEGUI::PushButton*>::iterator biter=mButtons.begin();
	std::vector<CEGUI::PushButton*>::iterator biter_end=mButtons.end();
	CEGUI::PushButton* btn=NULL;
	for(; biter != biter_end; ++biter)
	{
		btn=*biter;
		if(btn->isDisabled())
		{
			btn->enable();
		}
	}
}

void ForestDesignToolkit::show()
{
	//PGManager* pgm=PGManager::getSingletonPtr();
	
	CIWidget::show();
}

void ForestDesignToolkit::hide()
{
	CIWidget::hide();
}

void ForestDesignToolkit::unsubscribeEvents()
{
	mEventPopulateGrass->disconnect();
	mEventPopulateTree->disconnect();
	mEventPopulateBush->disconnect();

	mEventClearGrass->disconnect();
	mEventClearTree->disconnect();
	mEventClearBush->disconnect();
}

int ForestDesignToolkit::getCount() const
{
	return OSEnvironment::parseInt(mCount->getText());
}

float ForestDesignToolkit::getRadius() const
{
	return OSEnvironment::parseFloat(mRadius->getText());
}

void ForestDesignToolkit::create()
{
	mForestDesignAction=FD_POPULATETREE;

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	const float panelHeight=0.7f;
	const float panelWidth=0.25f;

	mRootWindow=wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId());
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(panelWidth), cegui_reldim(panelHeight)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0), cegui_reldim(0.1f)));
	mRootWindow->setAlpha(0.5);
	mRootWindow->setText((CEGUI::utf8*)"Forest Design Toolkit");
	mRootWindow->hide();

	const float buttonHeight=0.1f;
	const float buttonWidth=0.9f;
	const float left=0.05f;
	const float top=0.1f;
	const float vgap=0.01f;

	float x=left;
	float y=top;
	mBtnPopulateGrass=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnPopulateGrass")));
	mBtnPopulateGrass->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnPopulateGrass->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnPopulateGrass->setText((CEGUI::utf8*)"Populate Grass");
	mButtons.push_back(mBtnPopulateGrass);
	mRootWindow->addChildWindow(mBtnPopulateGrass);

	y+=(buttonHeight+vgap);
	mBtnPopulateTree=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnPopulateTree")));
	mBtnPopulateTree->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnPopulateTree->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnPopulateTree->setText((CEGUI::utf8*)"Populate Tree");
	mBtnPopulateTree->disable();
	mButtons.push_back(mBtnPopulateTree);
	mRootWindow->addChildWindow(mBtnPopulateTree);

	y+=(buttonHeight+vgap);
	mBtnPopulateBush=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnPopulateBush")));
	mBtnPopulateBush->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnPopulateBush->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnPopulateBush->setText((CEGUI::utf8*)"Populate Bush");
	mButtons.push_back(mBtnPopulateBush);
	mRootWindow->addChildWindow(mBtnPopulateBush);

	y+=(buttonHeight+vgap);
	mBtnClearGrass=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnClearGrass")));
	mBtnClearGrass->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnClearGrass->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnClearGrass->setText((CEGUI::utf8*)"Clear Grass");
	mButtons.push_back(mBtnClearGrass);
	mRootWindow->addChildWindow(mBtnClearGrass);

	y+=(buttonHeight+vgap);
	mBtnClearTree=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnClearTree")));
	mBtnClearTree->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnClearTree->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnClearTree->setText((CEGUI::utf8*)"Clear Tree");
	mButtons.push_back(mBtnClearTree);
	mRootWindow->addChildWindow(mBtnClearTree);

	y+=(buttonHeight+vgap);
	mBtnClearBush=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnClearBush")));
	mBtnClearBush->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnClearBush->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnClearBush->setText((CEGUI::utf8*)"Clear Bush");
	mButtons.push_back(mBtnClearBush);
	mRootWindow->addChildWindow(mBtnClearBush);

	const float txtHeight=0.06f;
	y+=(buttonHeight+vgap);
	this->mRadius=new CITextFieldWidget(getUIId("txtRadius"), this, mRootWindow, buttonWidth, txtHeight, 0.3f);
	this->mRadius->setPosition(x, y);
	this->mRadius->setText("1");
	this->mRadius->setLabel("Radius:");

	y+=(txtHeight+vgap);
	this->mCount=new CITextFieldWidget(getUIId("txtCount"), this, mRootWindow, buttonWidth, txtHeight, 0.3f);
	this->mCount->setPosition(x, y);
	this->mCount->setText("1");
	this->mCount->setLabel("Count:");

	y+=(txtHeight+vgap);
	mChkAutoPopulate=static_cast<CEGUI::Checkbox*>(wm->createWindow(CIWidget::getGUIType("Checkbox"), getUIId("chkAutoPopulate")));
	mChkAutoPopulate->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mChkAutoPopulate->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(txtHeight)));
	mChkAutoPopulate->setText("Auto Populate");
	mChkAutoPopulate->setSelected(false);
	mRootWindow->addChildWindow(mChkAutoPopulate);

	mParentWindow->addChildWindow(mRootWindow);
}
