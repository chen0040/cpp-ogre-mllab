#include "HydraxDesignToolkit.h"
#include "../../SceneAssets/HydraxManager.h"

HydraxDesignToolkit::HydraxDesignToolkit(const std::string& rootId)
: CIWidget(NULL, NULL)
{
	initializeComponents(rootId);
}

HydraxDesignToolkit::~HydraxDesignToolkit()
{
	if(mOceanDesignToolkit != NULL)
	{
		delete mOceanDesignToolkit;
		mOceanDesignToolkit=NULL;
	}
}

void HydraxDesignToolkit::subscribeEvents()
{
	mEventDisable=mBtnDisable->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&HydraxDesignToolkit::onButtonClicked_Disable, this));
	mEventHydrax=mBtnHydrax->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&HydraxDesignToolkit::onButtonClicked_Hydrax, this));
	mEventOcean=mBtnOcean->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&HydraxDesignToolkit::onButtonClicked_Ocean, this));
}

bool HydraxDesignToolkit::onButtonClicked_Disable(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnDisable->disable();
	mHydraxDesignAction=HD_DISABLE;

	HydraxManager* hm=HydraxManager::getSingletonPtr();
	hm->unloadHydrax();
	hm->unloadOgreOcean();

	return true;
}

bool HydraxDesignToolkit::onButtonClicked_Hydrax(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnHydrax->disable();
	mHydraxDesignAction=HD_HYDRAX;

	HydraxManager* hm=HydraxManager::getSingletonPtr();

	if(hm->isOgreOceanLoaded())
	{
		hm->unloadOgreOcean();
	}

	hm->loadHydrax();

	return true;
}

bool HydraxDesignToolkit::onButtonClicked_Ocean(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnOcean->disable();
	mHydraxDesignAction=HD_OCEAN;

	HydraxManager* hm=HydraxManager::getSingletonPtr();

	if(hm->isHydraxLoaded())
	{
		hm->unloadHydrax();
	}

	hm->loadOgreOcean();

	mOceanDesignToolkit->show();

	return true;
}


void HydraxDesignToolkit::enableAllButtons()
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
	mOceanDesignToolkit->hide();
}

void HydraxDesignToolkit::show()
{
	HydraxManager* hm=HydraxManager::getSingletonPtr();
	if(hm->isHydraxLoaded())
	{
		enableAllButtons();
		mBtnHydrax->disable();
		mHydraxDesignAction=HD_HYDRAX;
	}
	else if(hm->isOgreOceanLoaded())
	{
		enableAllButtons();
		mBtnOcean->disable();
		mOceanDesignToolkit->show();
		mHydraxDesignAction=HD_OCEAN;
	}
	else
	{
		enableAllButtons();
		mBtnDisable->disable();
		mHydraxDesignAction=HD_DISABLE;
	}
	CIWidget::show();
}

void HydraxDesignToolkit::hide()
{
	mOceanDesignToolkit->hide();
	CIWidget::hide();
}

void HydraxDesignToolkit::unsubscribeEvents()
{
	mEventDisable->disconnect();
	mEventHydrax->disconnect();
	mEventOcean->disconnect();
}

void HydraxDesignToolkit::create()
{
	mHydraxDesignAction=HD_DISABLE;

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	const float panelHeight=0.7f;
	const float panelWidth=0.25f;

	mRootWindow=wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId());
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(panelWidth), cegui_reldim(panelHeight)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0), cegui_reldim(0.1f)));
	mRootWindow->setAlpha(0.5);
	mRootWindow->setText((CEGUI::utf8*)"Hydrax Design Toolkit");
	mRootWindow->hide();

	const float buttonHeight=0.1f;
	const float buttonWidth=0.9f;
	const float left=0.05f;
	const float top=0.1f;
	const float vgap=0.01f;

	float x=left;
	float y=top;
	mBtnDisable=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnDisable")));
	mBtnDisable->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnDisable->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnDisable->setText((CEGUI::utf8*)"Disable");
	mBtnDisable->disable();
	mButtons.push_back(mBtnDisable);
	mRootWindow->addChildWindow(mBtnDisable);

	y+=(buttonHeight+vgap);
	mBtnHydrax=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnHydrax")));
	mBtnHydrax->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnHydrax->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnHydrax->setText((CEGUI::utf8*)"Hydrax");
	mButtons.push_back(mBtnHydrax);
	mRootWindow->addChildWindow(mBtnHydrax);

	y+=(buttonHeight+vgap);
	mBtnOcean=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnOcean")));
	mBtnOcean->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnOcean->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnOcean->setText((CEGUI::utf8*)"Ocean");
	mButtons.push_back(mBtnOcean);
	mRootWindow->addChildWindow(mBtnOcean);

	mParentWindow->addChildWindow(mRootWindow);

	mOceanDesignToolkit=new OceanDesignToolkit(getUIId("OceanDesignToolkit"));
}
