#include "Application.h"
#include "../tinyxml/tinyxml.h"
#include "../OSEnvironment/OSEnvironment.h"
#include "../CIType/CIManager.h"
#include "../Widgets/GUIManager.h"

Application* Application::mSingleton=NULL;

Application::Application()
: mRoot(NULL)
, mSceneMgr(NULL)
, mWindow(NULL)
, mSystem(NULL)
, mCamera(NULL)
, mFrameManager(NULL)
, mTerrainInfoManager(NULL)
, mAboutDlg(NULL)
, mNicknameDlg(NULL)
, mKeyboard(NULL)
, mMouse(NULL)
, mInputManager(NULL)
, mHTTPManager(NULL)
, mGUIManager(NULL)
, mWebConnectLogin(NULL)
, mWindowsMouseShown(true)
, mRunning(false)
{
	if(mSingleton==NULL)
	{
		mSingleton=this;
	}
	else
	{
		throw Exception(42, "multiple instances not allowed", "Application::Application()");
	}
}

Application::~Application()
{
	
}

void Application::setFrameCaption(const std::string& caption)
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();
	CEGUI::MenuItem* item=static_cast<CEGUI::MenuItem*>(wm->getWindow((CEGUI::utf8*)"Application/StatusBar/FrameCaption"));

	std::ostringstream oss;
	oss << "Scene: " << caption;
	item->setText(oss.str());
}

void Application::init(const std::string& title)
{
	OSEnvironment::setCurrentDir2ExecutableDir();
	createCURL();
	createRoot();
	defineResources();
	setupRenderSystem();
	
	createRenderWindow(title);
	initializeResources();
	setupScene();
	createCaelum();
	createHydrax();
	createPagedGeometry();
	setupInput();
	setupGUI();
	setupFrameListener();
	showWindowMouse(false);
}

void Application::setCurrentFrame(const std::string& frameName)
{
	AppFrame* frame=mFrameManager->getFrame(frameName);
	mFrameManager->setCurrentFrame(frame);

	std::string display_frame_name=mFrameDisplayNames[frameName];
	setFrameCaption(display_frame_name);
}

void Application::addFrame(const std::string& display_frame_name, AppFrame* frame)
{
	std::string frameName=frame->getName();
	mFrameDisplayNames[frameName]=display_frame_name;

	mFrameManager->addFrame(frameName, frame);

	std::ostringstream oss;
	oss << "Application/MenuBar/Scenes/" << frameName;

	CEGUI::MenuItem* mitem=static_cast<CEGUI::MenuItem*>(CEGUI::WindowManager::getSingletonPtr()->createWindow(CIWidget::getGUIType("MenuItem"), oss.str().c_str()));
	
	oss.str("");
	oss << "  " << display_frame_name << " ";
	mitem->setText(oss.str().c_str());

	CEGUI::PopupMenu* pmenu=mItemPages->getPopupMenu();
	pmenu->addItem(mitem);
	mitem->subscribeEvent(CEGUI::MenuItem::EventClicked, CEGUI::Event::Subscriber(&AppFrame::onFrameSelected, frame));
}

void Application::createCURL()
{
	mHTTPManager=new HTTPManager();
	mEventHTTPManagerEnabled=mHTTPManager->subscribeEvent_onEnabled(boost::bind(&Application::onHTTPManagerEnabled, this, _1));
}

void Application::onHTTPManagerEnabled(bool enabled)
{
	if(mGUIManager==NULL) return;
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	CEGUI::Window* item=wm->getWindow((CEGUI::utf8*)"Application/StatusBar/btnWebConnect");

	if(enabled)
	{
		item->setText((CEGUI::utf8*)"> Web Connect ");
	}
	else
	{
		item->setText((CEGUI::utf8*)"  Web Connect ");
	}
}

void Application::createRoot()
{
	mRoot=new Root();
}

void Application::defineResources()
{
	ResourceGroupManager* mgr=ResourceGroupManager::getSingletonPtr();

	String typeName, archName, sectName;
	ConfigFile config;
	config.load("resources.cfg");
	ConfigFile::SectionIterator si=config.getSectionIterator();
	while(si.hasMoreElements())
	{
		sectName=si.peekNextKey();
		ConfigFile::SettingsMultiMap* smm=si.getNext();
		ConfigFile::SettingsMultiMap::iterator smmi=smm->begin();
		ConfigFile::SettingsMultiMap::iterator smmi_end=smm->end();
		for(; smmi != smmi_end; ++smmi)
		{
			typeName=smmi->first;
			archName=smmi->second;
			mgr->addResourceLocation(archName, typeName, sectName);
		}
	}

	mgr->addResourceLocation("../media2/NaviLocal", "FileSystem");
	mgr->addResourceLocation("../media2/particle", "FileSystem");

	TiXmlDocument doc;
	if(!doc.LoadFile(OSEnvironment::getFullPath("..\\config\\Resources.xml").c_str()))
	{
		throw Exception(42, "Failed to load Resources.xml", "Application::defineResources()");
	}

	TiXmlElement* xmlRoot=doc.RootElement();
	for(TiXmlElement* xmlLevel1=xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1=xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "resource")==0)
		{
			mgr->addResourceLocation(xmlLevel1->Attribute("url"), xmlLevel1->Attribute("loc_type"), xmlLevel1->Attribute("group"));
		}
	}
}

void Application::setupRenderSystem()
{
	TiXmlDocument doc;
	if(!doc.LoadFile(OSEnvironment::getFullPath("..\\config\\mllab_ogre.xml").c_str()))
	{
		throw Exception(52, "Failed to load mllab_ogre.xml", "Application::setupRenderSystem()");
	}

	TiXmlElement* xmlRoot=doc.RootElement();
	if(strcmp(xmlRoot->Attribute("ogre_config"), "true")==0)
	{
		//!mRoot->restoreConfig() && 
		if(!mRoot->showConfigDialog())
		{
			exit(0);
			//throw Exception(52, "Failed to load config", "Application::setupRenderSystem()");
		}
		mSystem=mRoot->getRenderSystem();
	}
	else
	{
		
		for(TiXmlElement* xmlLevel1=xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1=xmlLevel1->NextSiblingElement())
		{
			if(strcmp(xmlLevel1->Attribute("id"), xmlRoot->Attribute("RenderSystem"))==0)
			{
				mSystem=mRoot->getRenderSystemByName(xmlLevel1->Attribute("name"));
				for(TiXmlElement* xmlLevel2=xmlLevel1->FirstChildElement(); xmlLevel2 != NULL; xmlLevel2=xmlLevel2->NextSiblingElement())
				{
					if(strcmp(xmlLevel2->Value(), "Config")==0)
					{
						mSystem->setConfigOption(xmlLevel2->Attribute("name"), xmlLevel2->Attribute("value"));
					}
				}
				mRoot->setRenderSystem(mSystem);
				break;
			}
		}
	}

	mRenderingSystemName=mSystem->getName().c_str();

	if(mSystem==NULL)
	{
		throw Exception(42, "mSystem==NULL", "Application::setupRenderSystem()");
	}

}

void Application::createRenderWindow(const std::string& title)
{
	/*
	bool fullscreen=true;

	ConfigOptionMap& com=mSystem->getConfigOptions();

	for(ConfigOptionMap::const_iterator comi=com.begin(); comi != com.end(); ++comi)
	{
		const ConfigOption& co=comi->second;
		if(co.name.compare("Full Screen")==0 && co.currentValue.compare("No")==0)
		{
			fullscreen=false;
		}
	}

	if(fullscreen==false)
	{
		mRoot->initialise(false, "MLLab");
		NameValuePairList miscParams;
		miscParams["border"]="fixed";
		mWindow=mRoot->createRenderWindow("MLLab", 800, 600, false, &miscParams);
	}
	else
	{
		mRoot->initialise(true, "MLLab");
		mWindow=mRoot->getAutoCreatedWindow();
	}
	*/

	mRoot->initialise(true, title);
	mWindow=mRoot->getAutoCreatedWindow();

	WindowEventUtilities::addWindowEventListener(mWindow, this);
}

void Application::initializeResources()
{
	TextureManager::getSingletonPtr()->setDefaultNumMipmaps(5);
	ResourceGroupManager::getSingletonPtr()->initialiseAllResourceGroups();
}

void Application::createCaelum()
{
	mCaelumManager=new CaelumManager();
}

void Application::createHydrax()
{
	mHydraxManager=new HydraxManager();
	if(this->mRenderingSystemName.compare("OpenGL Rendering Subsystem")==0)
	{
		mHydraxManager->enableHydrax(false);
	}
	else
	{
		mHydraxManager->enableHydrax(true);
	}
}

void Application::createPagedGeometry()
{
	mPGManager=new PGManager();
}

void Application::setupScene()
{
	//mSceneMgr=mRoot->createSceneManager(ST_EXTERIOR_CLOSE, "DefaultManager");
	mSceneMgr=mRoot->createSceneManager("OctreeSceneManager", "ETManager");
	
	//mSceneMgr->setWorldGeometry("terrain.cfg");
	//mSceneMgr->setSkyDome(true, "Examples/CloudySky", 5, 8);

	Light* light = mSceneMgr->createLight("Light3");
	light->setType(Light::LT_DIRECTIONAL);
	light->setDiffuseColour(ColourValue(.25, .25, 0.25));
	light->setSpecularColour(ColourValue(.25, .25, 0.25));
	light->setDirection(Vector3( 0, -1, 1 )); 

	mCamera=mSceneMgr->createCamera("DefaultCamera");
	mCamera->setNearClipDistance(5);
	mCamera->setFarClipDistance(9999*6);

	// create & configure Camera
    Ogre::SceneNode * camNode= mSceneMgr->getRootSceneNode()->createChildSceneNode("CamNode");
    camNode->setPosition(750, 0.0, 750);  
    camNode->attachObject(mCamera);

	Viewport* vp=mWindow->addViewport(mCamera);
	vp->setBackgroundColour(ColourValue(0, 0, 0));

	mTerrainInfoManager=new TerrainInfoManager(this);
	mWeatherManager=new WeatherManager();
}

void Application::createMinimap()
{
	MiniMap* mm=GUIManager::getSingletonPtr()->createMiniMap("DefaultMiniMap");
	mm->setAlpha(0.5f);
	mm->setSize(0.25f, mWindow->getWidth() * 0.25f / mWindow->getHeight());
	mm->setPosition(0.75f, 0.25f);
	mm->getMinimapWindow()->subscribeEvent(CEGUI::FrameWindow::EventCloseClicked, CEGUI::Event::Subscriber(&Application::onMinimapClosed, this));
	mMiniMap=mm;
}

void Application::createWebConnectLogin()
{
	mWebConnectLogin=GUIManager::getSingletonPtr()->createWebConnectLogin("Application/WebConnectLogin");
}

bool Application::onMinimapClosed(const CEGUI::EventArgs& evt)
{
	mMiniMap->hide();
	mItemMiniMap->setText((CEGUI::utf8*)"  Mini Map ");

	/*
	if(mMiniMap->isVisible())
	{
		mMiniMap->hide();
		item->setText((CEGUI::utf8*)"  Mini Map ");
	}
	else
	{
		mMiniMap->show();
		item->setText((CEGUI::utf8*)"> Mini Map ");
	}
	*/

	return true;
}

void Application::setupInput()
{
	OIS::ParamList pl;
	size_t hwnd;
	mWindow->getCustomAttribute("WINDOW", &hwnd);
	std::ostringstream oss;
	oss << hwnd;
	pl.insert(std::make_pair<std::string, std::string>(std::string("WINDOW"), oss.str()));
	if(!mWindow->isFullScreen())
	{
		#if defined OIS_WIN32_PLATFORM
		pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_FOREGROUND" )));
		pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_NONEXCLUSIVE")));
		pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_FOREGROUND")));
		pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_NONEXCLUSIVE")));
		#elif defined OIS_LINUX_PLATFORM
		pl.insert(std::make_pair(std::string("x11_mouse_grab"), std::string("false")));
		pl.insert(std::make_pair(std::string("x11_mouse_hide"), std::string("false")));
		pl.insert(std::make_pair(std::string("x11_keyboard_grab"), std::string("false")));
		pl.insert(std::make_pair(std::string("XAutoRepeatOn"), std::string("true")));
		#endif
	}
	mInputManager=OIS::InputManager::createInputSystem(pl);

	try{
		mMouse=static_cast<OIS::Mouse*>(mInputManager->createInputObject(OIS::OISMouse, true));
		mKeyboard=static_cast<OIS::Keyboard*>(mInputManager->createInputObject(OIS::OISKeyboard, true));

		unsigned int width, height, depth;
		int left, top;
		mWindow->getMetrics(width, height, depth, left, top);

		const OIS::MouseState& ms=mMouse->getMouseState();
		ms.width=width;
		ms.height=height;

	}catch(OIS::Exception& e)
	{
		throw Exception(42, e.eText, "Application::setupInput()");
	}
}

void Application::setupGUI()
{
	mGUIManager=new GUIManager(mWindow, mSceneMgr);

	CEGUI::Window* sheet=mGUIManager->getGUISheet();
	sheet->addChildWindow(createMenu());
	sheet->addChildWindow(createStatusBar());

	mAboutDlg=new AboutDlg("Application/About");

	createMinimap();
	createWebBrowser();
	createWebConnectLogin();
	createConsole();
	createNicknameDlg();
}

void Application::createNicknameDlg()
{
	mNicknameDlg=new NicknameDlg("Application/NicknameSetter");
}

void Application::createConsole()
{
	mConsole=GUIManager::getSingletonPtr()->createOverlay("Application/Console");
	mConsole->setTitle("Console");
	mConsole->setPosition(0.3f, 0.2f);
	mConsole->setSize(0.5f, 0.4f);
	mConsole->hide();
	mConsole->setAlpha(0.5f);
}

TextOverlay* Application::getConsole()
{
	return mConsole;
}

void Application::createWebBrowser()
{
	unsigned int width, height, depth;
	int left, top;
	mWindow->getMetrics(width, height, depth, left, top);
	width=static_cast<unsigned int>(width * 0.7f);
	height=static_cast<unsigned int>(height * 0.6f);
	mWebBrowser=GUIManager::getSingletonPtr()->createBrowser("WebBrowser/Default", width, height);

	NaviLibrary::Navi* bw=mWebBrowser->getBrowserWindow();
	bw->setPosition(NaviLibrary::Center);

	CEGUI::Window* bc=mWebBrowser->getBrowserController();
	bc->setAlpha(0.5f);
	bc->setSize(CEGUI::UVector2(cegui_reldim(0.7f), cegui_reldim(0.15f)));
	bc->setPosition(CEGUI::UVector2(cegui_reldim(0.15f), cegui_reldim(0.80f)));

	mWebBrowser->hide();
}

CEGUI::Window* Application::createMenu()
{
	unsigned int height=mWindow->getHeight();

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();
	CEGUI::Menubar* mbar=static_cast<CEGUI::Menubar*>(wm->createWindow(CIWidget::getGUIType("Menubar"), (CEGUI::utf8*)"Application/MenuBar"));
	mbar->setSize(CEGUI::UVector2(cegui_reldim(0.3),cegui_reldim(32.0f / height)));
	mbar->setAlpha(0.5);

	mbar->addChildWindow(createPopupMenuFile());	
	mbar->addChildWindow(createPopupMenuScenes());
	mbar->addChildWindow(createPopupMenuWindow());
	mbar->addChildWindow(createPopupMenuHelp());

	return mbar;
}

CEGUI::Window* Application::createStatusBar()
{
	unsigned int height=mWindow->getHeight();
	float normalizedBarHeight=32.0f / height;

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();
	CEGUI::Menubar* mbar=static_cast<CEGUI::Menubar*>(wm->createWindow(CIWidget::getGUIType("Menubar"), (CEGUI::utf8*)"Application/StatusBar"));
	mbar->setSize(CEGUI::UVector2(cegui_reldim(1),cegui_reldim(normalizedBarHeight)));
	mbar->setPosition(CEGUI::UVector2(cegui_reldim(0), cegui_reldim(1-normalizedBarHeight)));
	mbar->setAlpha(0.5);

	CEGUI::MenuItem* item=NULL;

	item=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), (CEGUI::utf8*)"Application/StatusBar/FrameCaption"));
	mbar->addChildWindow(item);	

	item=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), (CEGUI::utf8*)"Application/StatusBar/ResetCamera"));
	item->setText((CEGUI::utf8*)"Reset Camera");
	item->subscribeEvent(CEGUI::MenuItem::EventClicked, CEGUI::Event::Subscriber(&Application::onClicked_ResetCamera, this));
	mbar->addChildWindow(item);	

	mItemFirstPersonCamera=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), (CEGUI::utf8*)"Application/StatusBar/FirstPersonCamera"));
	mItemFirstPersonCamera->setText((CEGUI::utf8*)"First Person Camera");
	mItemFirstPersonCamera->subscribeEvent(CEGUI::MenuItem::EventClicked, CEGUI::Event::Subscriber(&Application::onClicked_FirstPersonCamera, this));
	mbar->addChildWindow(mItemFirstPersonCamera);	

	mItemSphericalCamera=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), (CEGUI::utf8*)"Application/StatusBar/SphericalCamera"));
	mItemSphericalCamera->setText((CEGUI::utf8*)"Spherical Camera");
	mItemSphericalCamera->subscribeEvent(CEGUI::MenuItem::EventClicked, CEGUI::Event::Subscriber(&Application::onClicked_SphericalCamera, this));
	mbar->addChildWindow(mItemSphericalCamera);	

	mStatusBar=mbar;

	return mbar;
} 

bool Application::onClicked_WebBrowser(const CEGUI::EventArgs& evt)
{
	if(mWebBrowser->isVisible())
	{
		mWebBrowser->hide();
		mItemWebBrowser->setText((CEGUI::utf8*)"  Web Browser ");
	}
	else
	{
		mWebBrowser->show();
		mItemWebBrowser->setText((CEGUI::utf8*)"> Web Browser ");
	}
	return true;
}

CEGUI::Window* Application::createPopupMenuFile()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mItemFile=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), (CEGUI::utf8*)"Application/MenuBar/MenuItem[File]"));
	mItemFile->setText((CEGUI::utf8*)" File ");

	CEGUI::PopupMenu* pmenu=static_cast<CEGUI::PopupMenu*>(wm->createWindow(CIWidget::getGUIType("PopupMenu"), (CEGUI::utf8*)"Application/MenuBar/File"));
	mItemFile->setPopupMenu(pmenu);

	CEGUI::MenuItem* mitem=NULL;
	mitem=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), (CEGUI::utf8*)"Application/MenuBar/File/Open"));
	mitem->setText((CEGUI::utf8*)" Open ");
	mitem->subscribeEvent(CEGUI::MenuItem::EventClicked, CEGUI::Event::Subscriber(&Application::onClicked_Open, this));
	pmenu->addItem(mitem);

	mitem=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), (CEGUI::utf8*)"Application/MenuBar/File/Save"));
	mitem->setText((CEGUI::utf8*)" Save ");
	mitem->subscribeEvent(CEGUI::MenuItem::EventClicked, CEGUI::Event::Subscriber(&Application::onClicked_Save, this));
	pmenu->addItem(mitem);

	mitem=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), (CEGUI::utf8*)"Application/MenuBar/File/SaveAs"));
	mitem->setText((CEGUI::utf8*)" Save As ");
	mitem->subscribeEvent(CEGUI::MenuItem::EventClicked, CEGUI::Event::Subscriber(&Application::onClicked_SaveAs, this));
	pmenu->addItem(mitem);

	mitem=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), (CEGUI::utf8*)"Application/MenuBar/File/Exit"));
	mitem->setText((CEGUI::utf8*)" Exit ");
	mitem->subscribeEvent(CEGUI::MenuItem::EventClicked, CEGUI::Event::Subscriber(&Application::onClicked_Quit, this));
	pmenu->addItem(mitem);

	return mItemFile;
}

CEGUI::Window* Application::createPopupMenuHelp()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mItemHelp=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), (CEGUI::utf8*)"Application/MenuBar/MenuItem[Help]"));
	mItemHelp->setText((CEGUI::utf8*)" Help ");
	//mItemHelp->setFont((CEGUI::utf8*)"BlueHighway-10");

	CEGUI::PopupMenu* pmenu=static_cast<CEGUI::PopupMenu*>(wm->createWindow(CIWidget::getGUIType("PopupMenu"), (CEGUI::utf8*)"Application/MenuBar/Help"));
	mItemHelp->setPopupMenu(pmenu);

	CEGUI::MenuItem* mitem=NULL;
	mitem=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), (CEGUI::utf8*)"Application/MenuBar/Help/About"));
	mitem->setText((CEGUI::utf8*)" About ");
	pmenu->addItem(mitem);
	//mitem->setFont((CEGUI::utf8*)"BlueHighway-10");

	mitem->subscribeEvent(CEGUI::MenuItem::EventClicked, CEGUI::Event::Subscriber(&Application::onClicked_About, this));

	return mItemHelp;
}

CEGUI::Window* Application::createPopupMenuScenes()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mItemPages=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), (CEGUI::utf8*)"Application/MenuBar/MenuItem[Scenes]"));
	mItemPages->setText((CEGUI::utf8*)" Scenes ");
	//mItemPages->setFont((CEGUI::utf8*)"BlueHighway-10");

	CEGUI::PopupMenu* pmenu=static_cast<CEGUI::PopupMenu*>(wm->createWindow(CIWidget::getGUIType("PopupMenu"), (CEGUI::utf8*)"Application/MenuBar/Scenes"));
	mItemPages->setPopupMenu(pmenu);

	return mItemPages;
}

CEGUI::Window* Application::createPopupMenuWindow()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mItemWindow=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), (CEGUI::utf8*)"Application/MenuBar/MenuItem[Window]"));
	mItemWindow->setText((CEGUI::utf8*)" Toolkits ");
	//mItemWindow->setFont((CEGUI::utf8*)"BlueHighway-10");

	CEGUI::PopupMenu* pmenu=static_cast<CEGUI::PopupMenu*>(wm->createWindow(CIWidget::getGUIType("PopupMenu"), (CEGUI::utf8*)"Application/MenuBar/Window"));
	mItemWindow->setPopupMenu(pmenu);

	mItemWebBrowser=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), (CEGUI::utf8*)"Application/StatusBar/btnWebBrowser"));
	mItemWebBrowser->setText((CEGUI::utf8*)"  Web Browser ");
	mItemWebBrowser->subscribeEvent(CEGUI::MenuItem::EventClicked, CEGUI::Event::Subscriber(&Application::onClicked_WebBrowser, this));
	pmenu->addItem(mItemWebBrowser);

	mItemMiniMap=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), (CEGUI::utf8*)"Application/StatusBar/btnMiniMap"));
	mItemMiniMap->setText((CEGUI::utf8*)"> Mini Map ");
	mItemMiniMap->subscribeEvent(CEGUI::MenuItem::EventClicked, CEGUI::Event::Subscriber(&Application::onClicked_MiniMap, this));
	pmenu->addItem(mItemMiniMap);
	//item->setFont((CEGUI::utf8*)"BlueHighway-10");

	mItemWebConnect=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), (CEGUI::utf8*)"Application/StatusBar/btnWebConnect"));
	mItemWebConnect->setText((CEGUI::utf8*)" Web Connect ");
	mItemWebConnect->subscribeEvent(CEGUI::MenuItem::EventClicked, CEGUI::Event::Subscriber(&Application::onClicked_WebConnect, this));
	pmenu->addItem(mItemWebConnect);
	//item->setFont((CEGUI::utf8*)"BlueHighway-10");

	mItemNickname=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), (CEGUI::utf8*)"Application/StatusBar/btnNickname"));
	mItemNickname->setText((CEGUI::utf8*)" Nickname Setter ");
	mItemNickname->subscribeEvent(CEGUI::MenuItem::EventClicked, CEGUI::Event::Subscriber(&Application::onClicked_Nickname, this));
	pmenu->addItem(mItemNickname);

	return mItemWindow;
}

bool Application::onClicked_Nickname(const CEGUI::EventArgs& evt)
{
	mNicknameDlg->showModal();
	return true;
}

bool Application::onClicked_WebConnect(const CEGUI::EventArgs& evt)
{
	if(mHTTPManager->enabled())
	{
		mHTTPManager->post("logout");
		mHTTPManager->enable(false);
	}
	else
	{
		mWebConnectLogin->showModal();
	}
	return true;
}

bool Application::onClicked_MiniMap(const CEGUI::EventArgs& evt)
{
	if(mMiniMap->isVisible())
	{
		mMiniMap->hide();
		mItemMiniMap->setText((CEGUI::utf8*)"  Mini Map ");
	}
	else
	{
		mMiniMap->show();
		mItemMiniMap->setText((CEGUI::utf8*)"> Mini Map ");
	}
	return true;
}

bool Application::onClicked_Quit(const CEGUI::EventArgs & evt)
{
	mFrameManager->quit();
	return true;
}

bool Application::onClicked_Open(const CEGUI::EventArgs& evt)
{
	mFrameManager->open();
	return true;
}


bool Application::onClicked_Save(const CEGUI::EventArgs& evt)
{
	mFrameManager->save();
	return true;
}

bool Application::onClicked_SaveAs(const CEGUI::EventArgs& evt)
{
	mFrameManager->saveAs();
	return true;
}

bool Application::onClicked_About(const CEGUI::EventArgs& evt)
{
	mAboutDlg->showModal();
	return true;
}

void Application::setupFrameListener()
{
	mFrameManager=new FrameManager(this);
	const FrameManager::AppCameraType& camType = mFrameManager->getCameraType();
	if(camType==FrameManager::APPCAM_FIRSTPERSON)
	{
		mItemFirstPersonCamera->setEnabled(false);
		mItemSphericalCamera->setEnabled(true);
	}
	else if(camType==FrameManager::APPCAM_SPHERICAL)
	{
		mItemFirstPersonCamera->setEnabled(true);
		mItemSphericalCamera->setEnabled(false);
	}

	mRoot->addFrameListener(mFrameManager);
}

void Application::startRenderLoop()
{
	mRunning=true;
	while(mRunning)
	{
		render();
	}
}	

bool Application::render()
{
	
	NaviLibrary::NaviManager::GetPointer()->Update();

	WindowEventUtilities::messagePump();

	if(mRunning)
	{
		mPGManager->update();
		mRunning=mRoot->renderOneFrame();
		if(mRunning)
		{
			this->mWindow->update();
		}
	}
	
	
	return mRunning;
}

void Application::cleanup()
{
	if(mAboutDlg != NULL)
	{
		delete mAboutDlg;
		mAboutDlg=NULL;
	}

	if(mNicknameDlg != NULL)
	{
		delete mNicknameDlg;
		mNicknameDlg=NULL;
	}

	if(mFrameManager != NULL)
	{
		delete mFrameManager;
		mFrameManager=NULL;
	}

	if(mWeatherManager != NULL)
	{
		delete mWeatherManager;
		mWeatherManager=NULL;
	}

	if(mTerrainInfoManager != NULL)
	{
		delete mTerrainInfoManager;
		mTerrainInfoManager=NULL;
	}

	if(mGUIManager != NULL)
	{
		delete mGUIManager;
		mGUIManager = NULL;
	}

	if(mCaelumManager != NULL)
	{
		delete mCaelumManager;
		mCaelumManager=NULL;
	}

	if(mHydraxManager != NULL)
	{
		delete mHydraxManager;
		mHydraxManager=NULL;
	}

	if(mPGManager != NULL)
	{
		delete mPGManager;
		mPGManager=NULL;
	}

	if(mRoot != NULL)
	{
		if(mKeyboard)
		{
			mInputManager->destroyInputObject(mKeyboard);
			mKeyboard=NULL;
		}
		if(mMouse)
		{
			mInputManager->destroyInputObject(mMouse);
			mMouse=NULL;
		}
		if(mInputManager)
		{
			OIS::InputManager::destroyInputSystem(mInputManager);
			mInputManager=NULL;
		}

		WindowEventUtilities::removeWindowEventListener(mWindow, this);
		mRoot->shutdown();
		delete mRoot;
		mRoot=NULL;
		mWindow=NULL;
		mSystem=NULL;
		mCamera=NULL;
		mSceneMgr=NULL;
	}

	if(mHTTPManager != NULL)
	{
		mEventHTTPManagerEnabled.disconnect();
		delete mHTTPManager;
		mHTTPManager=NULL;
	}
}

void Application::windowResized(Ogre::RenderWindow* rw)
{
	const OIS::MouseState & ms = this->mMouse->getMouseState();
	ms.width = mWindow->getWidth();
	ms.height = mWindow->getHeight();
	mFrameManager->windowResized(rw);

	GUIManager::getSingletonPtr()->injectWindowResized(mWindow->getWidth(), mWindow->getHeight()); 
	mItemFile->getPopupMenu()->sizeToContent();
	mItemHelp->getPopupMenu()->sizeToContent();
	mItemPages->getPopupMenu()->sizeToContent();
	mItemWindow->getPopupMenu()->sizeToContent();
}

void Application::windowFocusChange(Ogre::RenderWindow *rw)
{
	//only call when another window is active, for example, when the user press "Ctrl+Alt+Del"
}

bool Application::windowClosing(RenderWindow* rw)
{
	mFrameManager->quit();
	mRunning=false;
	return true;
}

void Application::windowMoved(RenderWindow* rw)
{
	
}

bool Application::isMouseWithinWindow() const
{
	HWND ogreHwnd = NULL;
	mWindow->getCustomAttribute("WINDOW", &ogreHwnd);
	if (ogreHwnd == NULL) return false;

	POINT p;
	::GetCursorPos(&p);
	::ScreenToClient(ogreHwnd,&p);

	RECT r;
	::GetClientRect(ogreHwnd,&r);

	int width = r.right - r.left;
	int height = r.bottom - r.top;

	bool inWindow = (p.x >= 0  && p.x < width && p.y >= 0 && p.y < height);
 
	return inWindow;
}

void Application::showWindowMouse(bool shown)
{
	if ((!shown) && mWindowsMouseShown)
	{
	  mWindowsMouseShown = false;
	  // Show your custom cursor here
	  ::ShowCursor(FALSE);

	}
	else if (shown && (!mWindowsMouseShown))
	{
	  mWindowsMouseShown = true;
	  // Hide your custom cursor here
	  ::ShowCursor(TRUE);
	}
}

bool Application::onClicked_ResetCamera(const CEGUI::EventArgs& evt)
{
	mFrameManager->resetCamera();
	return true;
}

bool Application::onClicked_FirstPersonCamera(const CEGUI::EventArgs& evt)
{
	mFrameManager->setCameraType(FrameManager::APPCAM_FIRSTPERSON);
	//mFrameManager->updateCamera();
	mItemSphericalCamera->setEnabled(true);
	mItemFirstPersonCamera->setEnabled(false);
	return true;
}

bool Application::onClicked_SphericalCamera(const CEGUI::EventArgs& evt)
{
	mFrameManager->setCameraType(FrameManager::APPCAM_SPHERICAL);
	//mFrameManager->updateCamera();

	mItemFirstPersonCamera->setEnabled(true);
	mItemSphericalCamera->setEnabled(false);
	return true;
}

