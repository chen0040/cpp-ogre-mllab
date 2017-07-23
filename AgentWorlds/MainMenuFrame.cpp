#include "MainMenuFrame.h"
#include "../GameEngine/Application.h"
#include "../OSEnvironment/OSEnvironment.h"
#include "../GameLoader/GameLoaderManager.h"

MainMenuFrame::MainMenuFrame(Application* app, std::string frameName)
: AppFrame(app, frameName)
, mCamera(app->getCamera())
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	std::ostringstream bgname_oss;
	bgname_oss << frameName << "_" << "CEGUIMenuBG";
	CEGUI::String bgname(bgname_oss.str());
	CEGUI::ImagesetManager::getSingletonPtr()->createImagesetFromImageFile(bgname, "loading.jpg", "XSIMG");

	mMenuBackground=static_cast<CEGUI::DefaultWindow*>(CEGUI::WindowManager::getSingletonPtr()->createWindow(CIWidget::getGUIType("StaticImage"), getUIId("GUIBackground")));
	mMenuBackground->setProperty((CEGUI::utf8*)"Image", "set:"+bgname+" image:full_image");
	mMenuBackground->setSize(CEGUI::UVector2(cegui_reldim(1), cegui_reldim(1)));
	mMenuBackground->setPosition(CEGUI::UVector2(cegui_reldim(0), cegui_reldim(0)));

	const float listingWidth=0.4f;
	const float listingHeight=0.25f; //0.7f;
	const float txtWidth=1.0f;
	const float txtHeight=0.04f;
	const float labelWidth=0.6f;
	const float labelWidth2=0.45f;
	const float chkWidth=0.91f;
	const float vgap=0.001f; 
	const float hgap=0.01f;
	const float left=0.05f;
	const float top=0.1f;
	const float btnWidth=0.43f;
	const float alpha=0.75f;
	const float buttonWidth=0.3f;
	float x=left;
	float y=top;

	y=top;
	x=left;
	CEGUI::Window* label=wm->createWindow(CIWidget::getGUIType("StaticText"), getUIId("lblScriptListing"));
	label->setText("Stored Map");
	label->setSize(CEGUI::UVector2(cegui_reldim(listingWidth), cegui_reldim(txtHeight)));
	label->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	label->setProperty((CEGUI::utf8*)"FrameEnabled", (CEGUI::utf8*)"false");
	label->setProperty((CEGUI::utf8*)"BackgroundEnabled", (CEGUI::utf8*)"false");
	label->setAlpha(alpha);
	mMenuBackground->addChildWindow(label);

	y+=txtHeight;
	mGameListing=static_cast<CEGUI::Listbox*>(wm->createWindow(CIWidget::getGUIType("Listbox"), getUIId("ScriptListing")));
	mGameListing->setSize(CEGUI::UVector2(cegui_reldim(listingWidth+0.15f), cegui_reldim(listingHeight)));
	mGameListing->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mGameListing->setMultiselectEnabled(true);
	mGameListing->setAlpha(alpha);
	mMenuBackground->addChildWindow(mGameListing);

	y+=(listingHeight+0.02f);
	TexturePtr pText=TextureManager::getSingletonPtr()->createManual(getUIId("R2Tex"), ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, TEX_TYPE_2D, 512, 512, 0, PF_R8G8B8, TU_RENDERTARGET);
	RenderTarget* rt=pText->getBuffer()->getRenderTarget();

	Viewport* vp=rt->addViewport(mCamera);
	vp->setBackgroundColour(ColourValue::Black);
	vp->setOverlaysEnabled(false);
	vp->setClearEveryFrame(true);

	CEGUI::Texture* tex=GUIManager::getSingletonPtr()->getGUIRenderer()->createTexture(pText);
	CEGUI::Imageset* is=CEGUI::ImagesetManager::getSingletonPtr()->createImageset(getUIId("R2tImageSet"), tex);
	is->defineImage(getUIId("R2tImage"), CEGUI::Point(0, 0), CEGUI::Size(pText->getWidth(), pText->getHeight()), CEGUI::Point(0, 0));

	mMap=static_cast<CEGUI::DefaultWindow*>(wm->createWindow(CIWidget::getGUIType("StaticImage"), getUIId("StaticIMage")));
	mMap->setSize(CEGUI::UVector2(cegui_reldim(listingWidth+0.15f), cegui_reldim(listingHeight+0.2f)));
	mMap->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mMap->setProperty((CEGUI::utf8*)"Image", CEGUI::PropertyHelper::imageToString(&(is->getImage(getUIId("R2tImage")))));
	mMenuBackground->addChildWindow(mMap);

	x+=(listingWidth+0.2f);
	y=top;
	label=wm->createWindow(CIWidget::getGUIType("StaticText"), getUIId("lblScenes"));
	label->setText("Scenes");
	label->setSize(CEGUI::UVector2(cegui_reldim(listingWidth), cegui_reldim(txtHeight)));
	label->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	label->setProperty((CEGUI::utf8*)"FrameEnabled", (CEGUI::utf8*)"false");
	label->setProperty((CEGUI::utf8*)"BackgroundEnabled", (CEGUI::utf8*)"false");
	label->setAlpha(alpha);
	mMenuBackground->addChildWindow(label);

	y+=txtHeight;
	mSceneListing=static_cast<CEGUI::Listbox*>(wm->createWindow(CIWidget::getGUIType("Listbox"), getUIId("SceneListing")));
	mSceneListing->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(0.3f)));
	mSceneListing->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mSceneListing->setMultiselectEnabled(true);
	mSceneListing->setAlpha(alpha);
	mMenuBackground->addChildWindow(mSceneListing);

	y+=(0.3f);
	label=wm->createWindow(CIWidget::getGUIType("StaticText"), getUIId("lblGameAbstract"));
	label->setText("Description");
	label->setSize(CEGUI::UVector2(cegui_reldim(listingWidth-0.01f), cegui_reldim(txtHeight-0.004f)));
	label->setPosition(CEGUI::UVector2(cegui_reldim(x+0.005f), cegui_reldim(y+0.002f)));
	label->setProperty((CEGUI::utf8*)"FrameEnabled", (CEGUI::utf8*)"false");
	label->setProperty((CEGUI::utf8*)"BackgroundEnabled", (CEGUI::utf8*)"false");
	label->setAlpha(alpha);
	mMenuBackground->addChildWindow(label);
	
	y+=txtHeight;
	mGameAbstract=static_cast<CEGUI::MultiLineEditbox*>(wm->createWindow(CIWidget::getGUIType("MultiLineEditbox"), getUIId("txtGameAbstract")));
	mGameAbstract->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(0.3f)));
	mGameAbstract->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mGameAbstract->setAlpha(alpha);
	mGameAbstract->setEnabled(false);
	mMenuBackground->addChildWindow(mGameAbstract);

	y+=(0.305f);
	mBtnActivate=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnActivate")));
	mBtnActivate->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(0.05f)));
	mBtnActivate->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnActivate->setAlpha(alpha);
	mBtnActivate->setText("Go!");
	mMenuBackground->addChildWindow(mBtnActivate);

	mGUIMgr->getGUISheet()->addChildWindow(mMenuBackground);

	mMenuBackground->hide();
}

MainMenuFrame::~MainMenuFrame()
{
	
}

void MainMenuFrame::addFrame(const std::string& display_name, const std::string& frame_name)
{
	size_t k=mFrameNames.size();
	mFrameNames[display_name]=frame_name;

	CEGUI::ListboxTextItem* item=new CEGUI::ListboxTextItem(display_name.c_str(), static_cast<CEGUI::uint>(k));
	item->setTooltipText(display_name.c_str());
	item->setSelectionBrushImage((CEGUI::utf8*)GUIManager::getSingletonPtr()->getGUITheme().c_str(), (CEGUI::utf8*)"MultiListSelectionBrush");

	if(k==0)
	{
		item->setSelected(true);
	}
	
	mSceneListing->addItem(item);
}

bool MainMenuFrame::frameExited()
{
	mMenuBackground->setModalState(false);
	mMenuBackground->hide();

	return AppFrame::frameExited();
}

void MainMenuFrame::subscribeEvents()
{
	mEventActivate=mBtnActivate->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&MainMenuFrame::onButtonClicked_Activate, this));
	mEventGameSelectionChanged=mGameListing->subscribeEvent(CEGUI::Listbox::EventSelectionChanged, CEGUI::Event::Subscriber(&MainMenuFrame::onSelectionChanged_Games, this));
}

bool MainMenuFrame::onSelectionChanged_Games(const CEGUI::EventArgs& evt)
{
	size_t itemCount=mGameListing->getItemCount();
	if(mGameListing->getSelectedCount() == 0 && itemCount > 0)
	{
		for(size_t i=0; i!=itemCount; ++i)
		{
			CEGUI::ListboxItem* item=mGameListing->getListboxItemFromIndex(i);
			if(item->getUserData()==GameLoaderManager::getSingletonPtr()->getCurrentGameLoader())
			{
				item->setSelected(true);
				break;
			}
		}	
		return true;
	}

	for(size_t i=0; i!=itemCount; ++i)
	{
		CEGUI::ListboxItem* item=mGameListing->getListboxItemFromIndex(i);
		if(item->isSelected())
		{
			std::string gameId=item->getText().c_str();
			GameLoader* loader=static_cast<GameLoader*>(item->getUserData());
			mGameAbstract->setText(loader->getAbstract().c_str());
			GameLoaderManager::getSingletonPtr()->setCurrentGameLoader(gameId);
			break;
		}
	}	
	
	return true;
}

void MainMenuFrame::unsubscribeEvents()
{
	mEventActivate->disconnect();

	mEventGameSelectionChanged->disconnect();
}

bool MainMenuFrame::onButtonClicked_Activate(const CEGUI::EventArgs& evt)
{
	size_t itemCount=mSceneListing->getItemCount();
	if(mSceneListing->getSelectedCount() == 0 && itemCount > 0)
	{
		return true;
	}

	itemCount=mGameListing->getItemCount();
	if(mGameListing->getSelectedCount() == 0 && itemCount > 0)
	{
		return true;
	}


	for(size_t i=0; i!=itemCount; ++i)
	{
		CEGUI::ListboxItem* item=mSceneListing->getListboxItemFromIndex(i);
		if(item->isSelected())
		{
			std::string display_name=item->getText().c_str();
			mApp->setCurrentFrame(mFrameNames[display_name]);
			break;
		}
	}	

	return true;
}

bool MainMenuFrame::frameEntered()
{
	if(!AppFrame::frameEntered())
	{
		return false;
	}

	mGameListing->resetList();
	
	std::map<std::string, GameLoader*>& gameloaders=GameLoaderManager::getSingletonPtr()->getGameLoaders();
	std::map<std::string, GameLoader*>::iterator giter=gameloaders.begin();
	std::map<std::string, GameLoader*>::iterator giter_end=gameloaders.end();
	CEGUI::uint k=0;
	std::string gameId;
	for(; giter != giter_end; ++giter)
	{
		gameId=giter->first;
		CEGUI::ListboxTextItem* item=new CEGUI::ListboxTextItem(gameId.c_str(), static_cast<CEGUI::uint>(k));
		item->setTooltipText(gameId.c_str());
		item->setSelectionBrushImage((CEGUI::utf8*)GUIManager::getSingletonPtr()->getGUITheme().c_str(), (CEGUI::utf8*)"MultiListSelectionBrush");

		GameLoader* loader=giter->second;
		item->setUserData(loader);
		if(loader==GameLoaderManager::getSingletonPtr()->getCurrentGameLoader())
		{
			item->setSelected(true);
			mGameAbstract->setText(loader->getAbstract().c_str());
		}
		
		mGameListing->addItem(item);
		++k;
	}

	mMenuBackground->setModalState(true);
	mMenuBackground->show();

	//Application::getSingletonPtr()->getConsole()->hide();

	return true;
}

bool MainMenuFrame::frameStarted(const FrameEvent& evt)
{
	if(!Application::getSingletonPtr()->getWindow()->isActive())
	{
		return mContinue;
	}

	if(!AppFrame::frameStarted(evt))
	{
		return false;
	}
	
	return mContinue;
}



