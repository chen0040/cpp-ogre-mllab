#include "TerrainDesignToolkit.h"

TerrainDesignToolkit::TerrainDesignToolkit(const std::string& rootId)
: CIWidget(NULL, NULL)
{
	initializeComponents(rootId);
}

TerrainDesignToolkit::~TerrainDesignToolkit()
{
	
}

void TerrainDesignToolkit::subscribeEvents()
{
	mEventDig=mBtnDig->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&TerrainDesignToolkit::onButtonClicked_Dig, this));
	mEventElevate=mBtnElevate->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&TerrainDesignToolkit::onButtonClicked_Elevate, this));
	mEventPaint0=mBtnPaint0->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&TerrainDesignToolkit::onButtonClicked_Paint0, this));
	mEventPaint1=mBtnPaint1->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&TerrainDesignToolkit::onButtonClicked_Paint1, this));
	mEventPaint2=mBtnPaint2->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&TerrainDesignToolkit::onButtonClicked_Paint2, this));
	mEventPaint3=mBtnPaint3->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&TerrainDesignToolkit::onButtonClicked_Paint3, this));
	mEventPaint4=mBtnPaint4->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&TerrainDesignToolkit::onButtonClicked_Paint4, this));
	mEventPaint5=mBtnPaint5->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&TerrainDesignToolkit::onButtonClicked_Paint5, this));
}

bool TerrainDesignToolkit::onButtonClicked_Dig(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnDig->disable();
	mTerrainDesignAction=TD_DIG;
	return true;
}

bool TerrainDesignToolkit::onButtonClicked_Elevate(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnElevate->disable();
	mTerrainDesignAction=TD_ELEVATE;
	return true;
}

bool TerrainDesignToolkit::onButtonClicked_Paint0(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnPaint0->disable();
	mTerrainDesignAction=TD_PAINT0;
	return true;
}

bool TerrainDesignToolkit::onButtonClicked_Paint1(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnPaint1->disable();
	mTerrainDesignAction=TD_PAINT1;
	return true;
}

bool TerrainDesignToolkit::onButtonClicked_Paint2(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnPaint2->disable();
	mTerrainDesignAction=TD_PAINT2;
	return true;
}

bool TerrainDesignToolkit::onButtonClicked_Paint3(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnPaint3->disable();
	mTerrainDesignAction=TD_PAINT3;
	return true;
}

bool TerrainDesignToolkit::onButtonClicked_Paint4(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnPaint4->disable();
	mTerrainDesignAction=TD_PAINT4;
	return true;
}

bool TerrainDesignToolkit::onButtonClicked_Paint5(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnPaint5->disable();
	mTerrainDesignAction=TD_PAINT5;
	return true;
}

void TerrainDesignToolkit::enableAllButtons()
{
	std::vector<CEGUI::PushButton*>::iterator biter=mButtons.begin();
	std::vector<CEGUI::PushButton*>::iterator biter_end=mButtons.end();
	for(; biter != biter_end; ++biter)
	{
		if((*biter)->isDisabled())
		{
			(*biter)->enable();
		}
	}
}
void TerrainDesignToolkit::unsubscribeEvents()
{
	mEventDig->disconnect();
	mEventElevate->disconnect();
	mEventPaint0->disconnect();
	mEventPaint1->disconnect();
	mEventPaint2->disconnect();
	mEventPaint3->disconnect();
	mEventPaint4->disconnect();
	mEventPaint5->disconnect();
}

void TerrainDesignToolkit::create()
{
	mTerrainDesignAction=TD_ELEVATE;

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	const float panelHeight=0.7f;
	const float panelWidth=0.25f;

	mRootWindow=wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId());
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(panelWidth), cegui_reldim(panelHeight)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0), cegui_reldim(0.1f)));
	mRootWindow->setAlpha(0.5);
	mRootWindow->setText((CEGUI::utf8*)"Terrain Design Toolkit");
	mRootWindow->hide();

	const float buttonHeight=0.1f;
	const float buttonWidth=0.9f;
	const float left=0.05f;
	const float top=0.1f;
	const float vgap=0.01f;

	float x=left;
	float y=top;
	mBtnDig=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnDig")));
	mBtnDig->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnDig->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnDig->setText((CEGUI::utf8*)"Dig");
	mButtons.push_back(mBtnDig);
	mRootWindow->addChildWindow(mBtnDig);

	y+=(buttonHeight+vgap);
	mBtnElevate=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnElevate")));
	mBtnElevate->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnElevate->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnElevate->setText((CEGUI::utf8*)"Elevate");
	mBtnElevate->disable();
	mButtons.push_back(mBtnElevate);
	mRootWindow->addChildWindow(mBtnElevate);

	y+=(buttonHeight+vgap);
	mBtnPaint0=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnPaint0")));
	mBtnPaint0->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnPaint0->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnPaint0->setText((CEGUI::utf8*)"Paint0");
	mButtons.push_back(mBtnPaint0);
	mRootWindow->addChildWindow(mBtnPaint0);

	y+=(buttonHeight+vgap);
	mBtnPaint1=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnPaint1")));
	mBtnPaint1->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnPaint1->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnPaint1->setText((CEGUI::utf8*)"Paint1");
	mButtons.push_back(mBtnPaint1);
	mRootWindow->addChildWindow(mBtnPaint1);

	y+=(buttonHeight+vgap);
	mBtnPaint2=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnPaint2")));
	mBtnPaint2->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnPaint2->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnPaint2->setText((CEGUI::utf8*)"Paint2");
	mButtons.push_back(mBtnPaint2);
	mRootWindow->addChildWindow(mBtnPaint2);

	y+=(buttonHeight+vgap);
	mBtnPaint3=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnPaint3")));
	mBtnPaint3->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnPaint3->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnPaint3->setText((CEGUI::utf8*)"Paint3");
	mButtons.push_back(mBtnPaint3);
	mRootWindow->addChildWindow(mBtnPaint3);

	y+=(buttonHeight+vgap);
	mBtnPaint4=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnPaint4")));
	mBtnPaint4->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnPaint4->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnPaint4->setText((CEGUI::utf8*)"Paint4");
	mButtons.push_back(mBtnPaint4);
	mRootWindow->addChildWindow(mBtnPaint4);

	y+=(buttonHeight+vgap);
	mBtnPaint5=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnPaint5")));
	mBtnPaint5->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnPaint5->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnPaint5->setText((CEGUI::utf8*)"Paint5");
	mButtons.push_back(mBtnPaint5);
	mRootWindow->addChildWindow(mBtnPaint5);

	mParentWindow->addChildWindow(mRootWindow);
}
