#include "SkyDesignToolkit.h"
#include "../../GameEngine/Application.h"
#include "../../tinyxml/tinyxml.h"
#include "../../OSEnvironment/OSEnvironment.h"
#include "../../GameLoader/GameLoaderManager.h"

SkyDesignToolkit::SkyDesignToolkit(const std::string& rootId)
: CIWidget(NULL, NULL)
{
	initializeComponents(rootId);
}

SkyDesignToolkit::~SkyDesignToolkit()
{
	if(mCaelumDesignToolkit != NULL)
	{
		delete mCaelumDesignToolkit;
		mCaelumDesignToolkit=NULL;
	}
}

void SkyDesignToolkit::subscribeEvents()
{
	mEventSkyBox=mBtnSkyBox->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&SkyDesignToolkit::onButtonClicked_SkyBox, this));
	mEventSkyDome=mBtnSkyDome->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&SkyDesignToolkit::onButtonClicked_SkyDome, this));
	mEventSkyPlane=mBtnSkyPlane->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&SkyDesignToolkit::onButtonClicked_SkyPlane, this));
	mEventSkyCaelum=mBtnSkyCaelum->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&SkyDesignToolkit::onButtonClicked_SkyCaelum, this));
	mEventSkyDisable=mBtnSkyDisable->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&SkyDesignToolkit::onButtonClicked_SkyDisable, this));

	mEventListSelectionChanged=mSkyTypeUriListBox->subscribeEvent(CEGUI::Listbox::EventSelectionChanged, CEGUI::Event::Subscriber(&SkyDesignToolkit::onSelectionChanged_SkyTypeUri, this));

}

bool SkyDesignToolkit::onButtonClicked_SkyBox(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnSkyBox->disable();
	mSkyDesignAction=SKYD_BOX;
	updateSkyTypeUriUI();
	return true;
}

bool SkyDesignToolkit::onButtonClicked_SkyDome(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnSkyDome->disable();
	mSkyDesignAction=SKYD_DOME;
	updateSkyTypeUriUI();
	return true;
}

bool SkyDesignToolkit::onButtonClicked_SkyPlane(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnSkyPlane->disable();
	mSkyDesignAction=SKYD_PLANE;
	updateSkyTypeUriUI();
	return true;
}

bool SkyDesignToolkit::onButtonClicked_SkyCaelum(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnSkyCaelum->disable();
	mSkyDesignAction=SKYD_CAELUM;
	updateSkyTypeUriUI();

	GameLoader* loader=GameLoaderManager::getSingletonPtr()->getCurrentGameLoader();
	if(loader != NULL)
	{
		loader->loadSky("SkyCaelum", "");
	}
	return true;
}

bool SkyDesignToolkit::onButtonClicked_SkyDisable(const CEGUI::EventArgs& evt)
{
	enableAllButtons();
	mBtnSkyDisable->disable();
	mSkyDesignAction=SKYD_DISABLE;
	updateSkyTypeUriUI();
	GameLoader* loader=GameLoaderManager::getSingletonPtr()->getCurrentGameLoader();
	if(loader != NULL)
	{
		loader->loadSky("", "");
	}
	return true;
}

void SkyDesignToolkit::enableAllButtons()
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
void SkyDesignToolkit::unsubscribeEvents()
{
	mEventSkyBox->disconnect();
	mEventSkyDome->disconnect();
	mEventSkyPlane->disconnect();
	mEventSkyCaelum->disconnect();
	mEventSkyDisable->disconnect();

	mEventListSelectionChanged->disconnect();
}

void SkyDesignToolkit::create()
{
	mSkyDesignAction=SKYD_DOME;

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	const float panelHeight=0.7f;
	const float panelWidth=0.25f;

	mRootWindow=wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId());
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(panelWidth), cegui_reldim(panelHeight)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0), cegui_reldim(0.1f)));
	mRootWindow->setAlpha(0.5);
	mRootWindow->setText((CEGUI::utf8*)"Sky Design Toolkit");
	mRootWindow->hide();

	const float buttonHeight=0.1f;
	const float buttonWidth=0.9f;
	const float left=0.05f;
	const float top=0.1f;
	const float vgap=0.01f;

	float x=left;
	float y=top;
	mBtnSkyBox=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnSkyBox")));
	mBtnSkyBox->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnSkyBox->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnSkyBox->setText((CEGUI::utf8*)"SkyBox");
	mButtons.push_back(mBtnSkyBox);
	mRootWindow->addChildWindow(mBtnSkyBox);

	y+=(buttonHeight+vgap);
	mBtnSkyDome=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnSkyDome")));
	mBtnSkyDome->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnSkyDome->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnSkyDome->setText((CEGUI::utf8*)"SkyDome");
	mBtnSkyDome->disable();
	mButtons.push_back(mBtnSkyDome);
	mRootWindow->addChildWindow(mBtnSkyDome);

	y+=(buttonHeight+vgap);
	mBtnSkyPlane=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnSkyPlane")));
	mBtnSkyPlane->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnSkyPlane->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnSkyPlane->setText((CEGUI::utf8*)"SkyPlane");
	mButtons.push_back(mBtnSkyPlane);
	mRootWindow->addChildWindow(mBtnSkyPlane);

	y+=(buttonHeight+vgap);
	mBtnSkyCaelum=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnSkyCaelum")));
	mBtnSkyCaelum->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnSkyCaelum->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnSkyCaelum->setText((CEGUI::utf8*)"SkyCaelum");
	mButtons.push_back(mBtnSkyCaelum);
	mRootWindow->addChildWindow(mBtnSkyCaelum);

	y+=(buttonHeight+vgap);
	mBtnSkyDisable=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnSkyDisable")));
	mBtnSkyDisable->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnSkyDisable->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnSkyDisable->setText((CEGUI::utf8*)"Disable");
	mButtons.push_back(mBtnSkyDisable);
	mRootWindow->addChildWindow(mBtnSkyDisable);

	y+=(buttonHeight+vgap);
	float listBoxHeight=(1-y-0.05f);
	mSkyTypeUriListBox=static_cast<CEGUI::Listbox*>(wm->createWindow(CIWidget::getGUIType("Listbox"), getUIId("SkyTypeUriListBox")));
	mSkyTypeUriListBox->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(listBoxHeight)));
	mSkyTypeUriListBox->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mSkyTypeUriListBox->setMultiselectEnabled(false);
	mRootWindow->addChildWindow(mSkyTypeUriListBox);

	mParentWindow->addChildWindow(mRootWindow);

	mCaelumDesignToolkit=new CaelumDesignToolkit(getUIId("CaelumDesignToolkit"));

	TiXmlDocument doc;
	if(!doc.LoadFile(OSEnvironment::getFullPath("..\\config\\Sky.xml").c_str()))
	{
		throw Ogre::Exception(42, "Failed to Load Sky.xml", "SkyDesignToolkit::create()");
	}

	TiXmlElement* xmlRoot=doc.RootElement();
	for(TiXmlElement* xmlLevel1=xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1 = xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "skybox")==0)
		{
			for(TiXmlElement* xmlLevel2=xmlLevel1->FirstChildElement(); xmlLevel2 != NULL; xmlLevel2=xmlLevel2->NextSiblingElement())
			{
				if(strcmp(xmlLevel2->Value(), "skybox_type")==0)
				{
					std::string skybox_type=xmlLevel2->Attribute("uri");
					mSkyBoxes.push_back(skybox_type);
				}
			}
		}
		else if(strcmp(xmlLevel1->Value(), "skydome")==0)
		{
			for(TiXmlElement* xmlLevel2=xmlLevel1->FirstChildElement(); xmlLevel2 != NULL; xmlLevel2=xmlLevel2->NextSiblingElement())
			{
				if(strcmp(xmlLevel2->Value(), "skydome_type")==0)
				{
					std::string skydome_type=xmlLevel2->Attribute("uri");
					mSkyDomes.push_back(skydome_type);
				}
			}
		}
		else if(strcmp(xmlLevel1->Value(), "skyplane")==0)
		{
			for(TiXmlElement* xmlLevel2=xmlLevel1->FirstChildElement(); xmlLevel2 != NULL; xmlLevel2=xmlLevel2->NextSiblingElement())
			{
				if(strcmp(xmlLevel2->Value(), "skyplane_type")==0)
				{
					std::string skyplane_type=xmlLevel2->Attribute("uri");
					mSkyPlanes.push_back(skyplane_type);
				}
			}
		}
	}
}

void SkyDesignToolkit::hide()
{
	mCaelumDesignToolkit->hide();
	CIWidget::hide();
}

void SkyDesignToolkit::show()
{
	GameLoader* loader=GameLoaderManager::getSingletonPtr()->getCurrentGameLoader();

	if(loader != NULL)
	{
		const std::string skyType=loader->getSkyType();
		const std::string skyTypeUri=loader->getSkyTypeUri();

		enableAllButtons();
		if(skyType.compare("SkyBox")==0)
		{
			mBtnSkyBox->disable();
			mSkyDesignAction=SKYD_BOX;
		}
		else if(skyType.compare("SkyDome")==0)
		{
			mBtnSkyDome->disable();
			mSkyDesignAction=SKYD_DOME;
		}
		else if(skyType.compare("SkyPlane")==0)
		{
			mBtnSkyPlane->disable();
			mSkyDesignAction=SKYD_PLANE;
		}
		else if(skyType.compare("SkyCaelum")==0)
		{
			mBtnSkyCaelum->disable();
			mSkyDesignAction=SKYD_CAELUM;
		}
		else
		{
			mBtnSkyDisable->disable();
			mSkyDesignAction=SKYD_DISABLE;
		}
	}

	updateSkyTypeUriUI();

	CIWidget::show();
}

void SkyDesignToolkit::updateSkyTypeUriUI()
{
	std::vector<std::string>* lists=NULL;
	switch(mSkyDesignAction)
	{
	case SKYD_BOX:
		lists=&mSkyBoxes;
		break;
	case SKYD_PLANE:
		lists=&mSkyPlanes;
		break;
	case SKYD_DOME:
		lists=&mSkyDomes;
		break;
	case SKYD_CAELUM:
		mSkyTypeUriListBox->hide();
		mCaelumDesignToolkit->show();
		return;
	case SKYD_DISABLE:
		mSkyTypeUriListBox->hide();
		return;
	default:
		break;
	}

	mCaelumDesignToolkit->hide();
	if(!mSkyTypeUriListBox->isVisible())
	{
		mSkyTypeUriListBox->show();
	}

	std::string currentSkyTypeUri="";
	GameLoader* loader=GameLoaderManager::getSingletonPtr()->getCurrentGameLoader();
	if(loader != NULL)
	{
		currentSkyTypeUri=loader->getSkyTypeUri();
	}

	mSkyTypeUriListBox->resetList();
	if(lists != NULL)
	{
		std::vector<std::string>::const_iterator iter=lists->begin();
		std::vector<std::string>::const_iterator iter_end=lists->end();
		CEGUI::uint k=0;
		for(; iter != iter_end; ++iter)
		{
			CEGUI::ListboxTextItem* item=new CEGUI::ListboxTextItem(*iter, static_cast<CEGUI::uint>(k++));
			item->setTooltipText(*iter);
			item->setSelectionBrushImage((CEGUI::utf8*)GUIManager::getSingletonPtr()->getGUITheme().c_str(), (CEGUI::utf8*)"MultiListSelectionBrush");

			if((*iter).compare(currentSkyTypeUri)==0)
			{
				item->setSelected(true);
			}
			mSkyTypeUriListBox->addItem(item);
		}
	}
}

bool SkyDesignToolkit::onSelectionChanged_SkyTypeUri(const CEGUI::EventArgs& evt)
{
	GameLoader* loader=GameLoaderManager::getSingletonPtr()->getCurrentGameLoader();
	if(loader == NULL)
	{
		return true;
	}

	size_t itemCount=mSkyTypeUriListBox->getItemCount();
	if(mSkyTypeUriListBox->getSelectedCount() == 0 && itemCount > 0)
	{
		return true;
	}

	std::string skyTypeUri="";
	std::string skyType="SkyBox";
	switch(mSkyDesignAction)
	{
	case SKYD_BOX:
		skyType="SkyBox";
		break;
	case SKYD_DOME:
		skyType="SkyDome";
		break;
	case SKYD_PLANE:
		skyType="SkyPlane";
		break;
	default:
		break;
	}

	for(size_t i=0; i!=itemCount; ++i)
	{
		CEGUI::ListboxItem* item=mSkyTypeUriListBox->getListboxItemFromIndex(i);
		if(item->isSelected())
		{
			skyTypeUri=item->getText().c_str();
			break;
		}
	}

	loader->loadSky(skyType, skyTypeUri);

	return true;
}

