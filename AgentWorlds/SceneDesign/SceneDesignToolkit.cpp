#include "SceneDesignToolkit.h"

SceneDesignToolkit::SceneDesignToolkit(const std::string& rootId)
: CIWidget(NULL, NULL)
{
	initializeComponents(rootId);
}

SceneDesignToolkit::~SceneDesignToolkit()
{
	if(mTerrainDesignToolkit != NULL)
	{
		delete mTerrainDesignToolkit;
		mTerrainDesignToolkit= NULL;
	}

	if(mSkyDesignToolkit != NULL)
	{
		delete mSkyDesignToolkit;
		mSkyDesignToolkit=NULL;
	}

	if(mHydraxDesignToolkit != NULL)
	{
		delete mHydraxDesignToolkit;
		mHydraxDesignToolkit=NULL;
	}

	if(mForestDesignToolkit != NULL)
	{
		delete mForestDesignToolkit;
		mForestDesignToolkit=NULL;
	}

	if(mBuildingDesignToolkit != NULL)
	{
		delete mBuildingDesignToolkit;
		mBuildingDesignToolkit=NULL;
	}
}

void SceneDesignToolkit::subscribeEvents()
{
	mEventTerrain=mBtnTerrain->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&SceneDesignToolkit::onButtonClicked_Terrain, this));
	mEventSky=mBtnSky->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&SceneDesignToolkit::onButtonClicked_Sky, this));
	mEventHydrax=mBtnHydrax->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&SceneDesignToolkit::onButtonClicked_Hydrax, this));
	mEventForest=mBtnForest->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&SceneDesignToolkit::onButtonClicked_Forest, this));
	mEventBuilding=mBtnBuilding->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&SceneDesignToolkit::onButtonClicked_Building, this));
}

	
void SceneDesignToolkit::unsubscribeEvents()
{
	mEventTerrain->disconnect();
	mEventSky->disconnect();
	mEventHydrax->disconnect();
	mEventForest->disconnect();
	mEventBuilding->disconnect();
}

bool SceneDesignToolkit::onButtonClicked_Terrain(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnTerrain->disable();
	mTerrainDesignToolkit->show();
	mSceneDesignAction=SD_TERRAIN;
	return true;
}

bool SceneDesignToolkit::onButtonClicked_Sky(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnSky->disable();
	mSkyDesignToolkit->show();
	mSceneDesignAction=SD_SKY;
	return true;
}

bool SceneDesignToolkit::onButtonClicked_Hydrax(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnHydrax->disable();
	mHydraxDesignToolkit->show();
	mSceneDesignAction=SD_HYDRAX;
	return true;
}

bool SceneDesignToolkit::onButtonClicked_Forest(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnForest->disable();

	mForestDesignToolkit->show();
	
	mSceneDesignAction=SD_FOREST;
	return true;
}

bool SceneDesignToolkit::onButtonClicked_Building(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnBuilding->disable();

	mBuildingDesignToolkit->show();
	
	mSceneDesignAction=SD_STATICAGENT;
	return true;
}

void SceneDesignToolkit::enableAllButtons()
{
	std::vector<CEGUI::PushButton*>::iterator biter=mButtons.begin();
	std::vector<CEGUI::PushButton*>::iterator biter_end=mButtons.end();
	CEGUI::PushButton* button;
	for(; biter != biter_end; ++biter)
	{
		button=*biter;
		if(button->isDisabled())
		{
			button->enable();
			if(button==mBtnTerrain)
			{
				mTerrainDesignToolkit->hide();
			}
			else if(button==mBtnSky)
			{
				mSkyDesignToolkit->hide();
			}
			else if(button==mBtnHydrax)
			{
				mHydraxDesignToolkit->hide();
			}
			else if(button==mBtnForest)
			{
				mForestDesignToolkit->hide();
			}
			else if(button==mBtnBuilding)
			{
				mBuildingDesignToolkit->hide();
			}
		}
	}
}

void SceneDesignToolkit::create()
{
	mSceneDesignAction=SD_TERRAIN;

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	const float normalizedPanelWidth=0.6f;
	const float normalizedPanelHeight=0.2f;

	mRootWindow=wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId());
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(normalizedPanelWidth), cegui_reldim(normalizedPanelHeight)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(1-normalizedPanelWidth), cegui_reldim(0)));
	mRootWindow->setAlpha(0.5);
	mRootWindow->setText((CEGUI::utf8*)"Scene Design Toolkit");
	mRootWindow->hide();

	const float buttonWidth=0.2f;
	const float buttonHeight=0.28f;
	const float buttongap=0.1f;
	const float top=0.2f;
	const float left=0.05f;
	const float hgap=0.01f;
	float x=left;
	float y=top;
	mBtnTerrain=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnTerrain")));
	mBtnTerrain->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnTerrain->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnTerrain->setText((CEGUI::utf8*)"Terrain");
	mBtnTerrain->disable();
	mRootWindow->addChildWindow(mBtnTerrain);
	mButtons.push_back(mBtnTerrain);

	x+=(buttonWidth+hgap);
	mBtnSky=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnSky")));
	mBtnSky->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnSky->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnSky->setText((CEGUI::utf8*)"Sky");
	mRootWindow->addChildWindow(mBtnSky);
	mButtons.push_back(mBtnSky);

	x+=(buttonWidth+hgap);
	mBtnHydrax=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnWater")));
	mBtnHydrax->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnHydrax->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnHydrax->setText((CEGUI::utf8*)"Water");
	mRootWindow->addChildWindow(mBtnHydrax);
	mButtons.push_back(mBtnHydrax);

	x+=(buttonWidth+hgap);
	mBtnForest=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnForest")));
	mBtnForest->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnForest->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnForest->setText((CEGUI::utf8*)"Forest");
	mRootWindow->addChildWindow(mBtnForest);
	mButtons.push_back(mBtnForest);

	y+=(buttonHeight+hgap);
	x=left;
	mBtnBuilding=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnBuilding")));
	mBtnBuilding->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnBuilding->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnBuilding->setText((CEGUI::utf8*)"Building");
	mRootWindow->addChildWindow(mBtnBuilding);
	mButtons.push_back(mBtnBuilding);

	mParentWindow->addChildWindow(mRootWindow);

	mTerrainDesignToolkit=new TerrainDesignToolkit(getUIId("TerrainDesignToolkit"));
	mSkyDesignToolkit=new SkyDesignToolkit(getUIId("SkyDesignToolkit"));
	mHydraxDesignToolkit=new HydraxDesignToolkit(getUIId("HydraxDesignToolkit"));
	mForestDesignToolkit=new ForestDesignToolkit(getUIId("ForestDesignToolkit"));
	mBuildingDesignToolkit=new BuildingDesignToolkit(getUIId("BuildingDesignToolkit"));
}

void SceneDesignToolkit::show()
{
	switch(mSceneDesignAction)
	{
	case SD_TERRAIN:
		mTerrainDesignToolkit->show();
		break;
	case SD_SKY:
		mSkyDesignToolkit->show();
		break;
	case SD_HYDRAX:
		mHydraxDesignToolkit->show();
		break;
	case SD_FOREST:
		mForestDesignToolkit->show();
		break;
	case SD_STATICAGENT:
		mBuildingDesignToolkit->show();
		break;
	default:
		break;
	}
	this->showWindow();
}

void SceneDesignToolkit::hide()
{
	mTerrainDesignToolkit->hide();
	mSkyDesignToolkit->hide();
	mHydraxDesignToolkit->hide();
	mForestDesignToolkit->hide();
	mBuildingDesignToolkit->hide();
	this->hideWindow();
}
