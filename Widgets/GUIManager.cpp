#include "GUIManager.h"
#include "../tinyxml/tinyxml.h"
#include "MsgBox.h"
#include "../OSEnvironment/OSEnvironment.h"
#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
#include "FileDIalog/CEGUICommonFileDialog.h"
#endif

GUIManager* GUIManager::mSingleton=NULL;

GUIManager::GUIManager(RenderWindow* rw, SceneManager* sm)
: mWindow(rw)
, mSceneMgr(sm)
, MAX_VISIBLE_MSG_BOXES(30)
{
	if(mSingleton==NULL)
	{
		mSingleton=this;
	}
	else
	{
		throw Ogre::Exception(42, "Multiple instances not allowed!", "GUIManager::GUIManager(RenderWindow* rw, SceneManager* sm)");
	}

	TiXmlDocument doc;
	if(!doc.LoadFile(OSEnvironment::getFullPath("..\\config\\GUI.xml").c_str()))
	{
		throw Ogre::Exception(42, "Failed to load GUI.xml", "GUIManager::GUIManager(RenderWindow* rw, SceneManager* sm)");
	}

	TiXmlElement* xmlRoot=doc.RootElement();
	
	CEGUI::String scheme="TaharezLookSkin.scheme";
	CEGUI::String font="BlueHighway-12";
	mGUITheme=xmlRoot->Attribute("theme");
	for(TiXmlElement* xmlLevel1=xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1 = xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "theme")==0 && mGUITheme.compare(xmlLevel1->Attribute("name"))==0)
		{
			scheme=xmlLevel1->Attribute("scheme");
			font=xmlLevel1->Attribute("font");
			break;
		}
	}

	mGUIRenderer=new CEGUI::OgreCEGUIRenderer(mWindow, RENDER_QUEUE_OVERLAY, false, 3000, mSceneMgr);
	mGUISystem=new CEGUI::System(mGUIRenderer);

	CEGUI::SchemeManager::getSingletonPtr()->loadScheme(scheme);

	if(font.compare("")!=0)
	{
		mGUISystem->setDefaultFont(font);
	}

	///*
	mGUISystem->setDefaultMouseCursor((CEGUI::utf8*)mGUITheme.c_str(), (CEGUI::utf8*)"MouseArrow");
	CEGUI::MouseCursor::getSingletonPtr()->setImage(mGUISystem->getDefaultMouseCursor());
	//*/

	CEGUI::Window* sheet=CEGUI::WindowManager::getSingletonPtr()->createWindow((CEGUI::utf8*)"DefaultGUISheet", (CEGUI::utf8*)"Application/GUISheet");
	mGUISystem->setGUISheet(sheet);

	setupNaviLibrary();

#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
	/****************************************************************************************************
	Step 1: Add the common file dialog window to the main window
	        Calling CommonFileDialog::getSingleton() instantiates the common file dialog
	*****************************************************************************************************/
	sheet->addChildWindow(CEGUI::CommonFileDialog::getSingleton().getWindow());
#endif
}

void GUIManager::setupNaviLibrary()
{
	loadWebSettings();
	NaviLibrary::NaviManager* nm=new NaviLibrary::NaviManager(mWindow, this->getWebFolder());

	/*
	NaviLibrary::NaviMouse* nmouse=new NaviLibrary::NaviMouse(64, 64);
	nmouse->createCursor("defaultCursor", 3, 2)->addFrame(0, "cursorMouse.png");
	nmouse->setDefaultCursor("defaultCursor");

	NaviLibrary::NaviCursor* nc=nmouse->createCursor("move", 19, 19);
	nc->addFrame(0, "cursorMove.png");
	*/
}

CEGUI::DefaultWindow* GUIManager::createLabel(const CEGUI::String& id, const CEGUI::String& text, float left, float top, float width, float height)
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	CEGUI::DefaultWindow* label=static_cast<CEGUI::DefaultWindow*>(wm->createWindow(CIWidget::getGUIType("StaticText"), id));
	label->setSize((CEGUI::UVector2(cegui_reldim(width), cegui_reldim(height))));
	label->setPosition((CEGUI::UVector2(cegui_reldim(left), cegui_reldim(top))));
	label->setText(text);
	label->setProperty((CEGUI::utf8*)"FrameEnabled", (CEGUI::utf8*)"false");
	label->setProperty((CEGUI::utf8*)"BackgroundEnabled", (CEGUI::utf8*)"false");

	return label;
}

CEGUI::Editbox* GUIManager::createEdit(const CEGUI::String &id, const CEGUI::String &value, float left, float top, float width, float height)
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	CEGUI::Editbox* edit=static_cast<CEGUI::Editbox*>(wm->createWindow(CIWidget::getGUIType("Editbox"), id));
	edit->setSize(CEGUI::UVector2(cegui_reldim(width), cegui_reldim(height)));
	edit->setPosition(CEGUI::UVector2(cegui_reldim(left), cegui_reldim(top)));
	edit->setText(value);

	return edit;
}

CEGUI::Editbox* GUIManager::createTextField(CEGUI::Window* container, const CEGUI::String& id, float left, float top, float width, float height, const CEGUI::String& labelText, const CEGUI::String& editValue, float labelWidth)
{
	container->addChildWindow(createLabel(id+(CEGUI::utf8*)"/Label", labelText, left, top, width * labelWidth, height));
	CEGUI::Editbox* edit=createEdit(id, editValue, left+width * labelWidth, top, width * (1-labelWidth), height);
	container->addChildWindow(edit);
	return edit;
}

CEGUI::Combobox* GUIManager::createCombo(const CEGUI::String& id,  float left, float top, float width, float height)
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();
	CEGUI::Combobox* cb=static_cast<CEGUI::Combobox*>(wm->createWindow(CIWidget::getGUIType("Combobox"), id));
	cb->setClippedByParent(false);
	cb->setSize(CEGUI::UVector2(cegui_reldim(width), cegui_reldim(height*4)));
	cb->setPosition(CEGUI::UVector2(cegui_reldim(left), cegui_reldim(top)));

	return cb;
}

CEGUI::Combobox* GUIManager::createCombobox(CEGUI::Window* container, const CEGUI::String& id, float left, float top, float width, float height, const CEGUI::String& labelText, float labelWidth)
{
	container->addChildWindow(createLabel(id+(CEGUI::utf8*)"[Label]", labelText, left, top, width * labelWidth, height));
	CEGUI::Combobox* cb=createCombo(id, left+width * labelWidth, top, width * (1-labelWidth), height);
	container->addChildWindow(cb);
	return cb;
}

GUIManager* GUIManager::getSingletonPtr()
{
	return mSingleton;
}

GUIManager& GUIManager::getSingleton()
{
	return *mSingleton;
}

void GUIManager::setModalState(bool modal, CIWidget* source)
{
	if(modal)
	{
		this->pushModalWidget(source);
	}
	else 
	{
		if(this->getTopModalWidget() != source)
		{
			throw Ogre::Exception(42, "this->getTopModalWidget() != source", "GUIManager::setModalState(bool modal, Widget* source)");
		}
		while(this->getTopModalWidget()==source)
		{
			GUIManager::getSingletonPtr()->popModalWidget();
		}
		if(this->hasModalWidgets())
		{
			CEGUI::Window* wd=GUIManager::getSingletonPtr()->getTopModalWidget()->getRootWindow();
			wd->setModalState(true);
			wd->show();
		}
	}
}

CIWidget* GUIManager::getTopModalWidget()
{
	if(!mModalWidgetStack.empty())
	{
		return mModalWidgetStack.top(); 
	}
	else
	{
		return NULL;
	}
}

bool GUIManager::hasFocus() const
{
	if(!mModalWidgetStack.empty())
	{
		return true;
	}

	CEGUI::System* sys=CEGUI::System::getSingletonPtr();
	CEGUI::Window* wd=sys->getWindowContainingMouse();
	if(wd== NULL || wd==sys->getGUISheet())
	{
		return false;
	}
	return true;
}

void GUIManager::loadWebSettings()
{
	TiXmlDocument doc;
	if(!doc.LoadFile(OSEnvironment::getFullPath("..\\config\\WebBrowser.xml").c_str()))
	{
		throw Ogre::Exception(42, "Failed to load WebBrowser.xml", "GUIManager::loadWebSettings()");
	}

	TiXmlElement* xmlRoot=doc.RootElement();
	this->mDefaultWebPageName=xmlRoot->Attribute("default_page");
	this->mWebFolder=xmlRoot->Attribute("folder");

	mDefaultWebPageName=xmlRoot->Attribute("default_page");

	for(TiXmlElement* xmlLevel1 = xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1=xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "page")==0)
		{
			std::string name=xmlLevel1->Attribute("name");
			WebPage* page=new WebPage(xmlLevel1);
			mWebPages[name]=page;
		}
	}
}

GUIManager::~GUIManager()
{
	std::map<std::string, TextOverlay*>::iterator iter=mOverlays.begin();
	std::map<std::string, TextOverlay*>::iterator iter_end=mOverlays.end();
	for(; iter != iter_end; ++iter)
	{
		delete iter->second;
	}
	mOverlays.clear();

	std::map<std::string, WebBrowser*>::iterator biter=mBrowsers.begin();
	std::map<std::string, WebBrowser*>::iterator biter_end=mBrowsers.end();
	for(; biter != biter_end; ++biter)
	{
		delete biter->second;
	}
	mBrowsers.clear();

	std::map<std::string, MiniMap*>::iterator miter=mMiniMaps.begin();
	std::map<std::string, MiniMap*>::iterator miter_end=mMiniMaps.end();
	for(; miter != miter_end; ++miter)
	{
		delete miter->second;
	}
	mMiniMaps.clear();

	std::map<std::string, WebConnectLogin*>::iterator wciter=mWebConnectLogins.begin();
	std::map<std::string, WebConnectLogin*>::iterator wciter_end=mWebConnectLogins.end();
	for(; wciter != wciter_end; ++wciter)
	{
		delete wciter->second;
	}
	mWebConnectLogins.clear();

	std::map<std::string, MsgBox*>::iterator mbiter=mMsgBoxes.begin();
	std::map<std::string, MsgBox*>::iterator mbiter_end=mMsgBoxes.end();
	for(; mbiter != mbiter_end; ++mbiter)
	{
		delete mbiter->second;
	}
	mMsgBoxes.clear();

	//temporarily uncomment the following line for debug mode as Astral debug mode has problem in destructor
#ifndef _DEBUG
		delete NaviLibrary::NaviManager::GetPointer();
#endif

	std::map<std::string, WebPage*>::iterator witer=mWebPages.begin();
	std::map<std::string, WebPage*>::iterator witer_end=mWebPages.end();
	for(; witer != witer_end; ++witer)
	{
		delete (witer->second);
	}
	mWebPages.clear();
		
	if(mGUISystem != NULL)
	{
		delete mGUISystem;
		mGUISystem=NULL;
	}

	if(mGUIRenderer != NULL)
	{
		delete mGUIRenderer;
		mGUIRenderer=NULL;
	}
}

TextOverlay* GUIManager::getOverlay(const std::string& overlayName)
{
	std::map<std::string, TextOverlay*>::iterator fnd=mOverlays.find(overlayName);
	if(fnd == mOverlays.end())
	{
		throw Exception(42, "fnd == mOverlays.end()", "GUIManager::getOverlay(const std::string& overlayName)");
	}
	else
	{
		return fnd->second;
	}
}

bool GUIManager::isOverlayPresent(const std::string& overlayName) const
{
	std::map<std::string, TextOverlay*>::const_iterator fnd=mOverlays.find(overlayName);
	if(fnd == mOverlays.end())
	{
		return false;
	}
	return true;
}

WebBrowser* GUIManager::getBrowser(const std::string& browserName)
{
	std::map<std::string, WebBrowser*>::iterator fnd=mBrowsers.find(browserName);
	if(fnd == mBrowsers.end())
	{
		throw Exception(42, "fnd == mBrowsers.end()", "GUIManager::getBrowser(const std::string& browserName)");
	}
	else
	{
		return fnd->second;
	}
}

bool GUIManager::isBrowserPresent(const std::string& browserName) const
{
	std::map<std::string, WebBrowser*>::const_iterator fnd=mBrowsers.find(browserName);
	if(fnd == mBrowsers.end())
	{
		return false;
	}
	return true;
}

bool GUIManager::isWebConnectLoginPresent(const std::string& name) const
{
	std::map<std::string, WebConnectLogin*>::const_iterator fnd=mWebConnectLogins.find(name);
	if(fnd==mWebConnectLogins.end())
	{
		return false;
	}
	return true;
}

void GUIManager::showMsgBox(const std::string& title, const std::string& msg)
{
	if(mHiddenMsgBoxSet.empty())
	{
		if(mVisibleMsgBoxSet.size() < MAX_VISIBLE_MSG_BOXES)
		{
			size_t mbCount=mMsgBoxes.size();
			std::ostringstream oss;
			oss << "MsgBox[" << mbCount << "]";
			std::string name=oss.str();
			MsgBox* mb=new MsgBox(name);
			mMsgBoxes[name]=mb;
			mVisibleMsgBoxSet.insert(mb);

			mb->showModal(title, msg);
		}
	}
	else
	{
		std::set<MsgBox*>::iterator mbiter=mHiddenMsgBoxSet.begin();
		MsgBox* mb=(*mbiter);
		
		mb->showModal(title, msg);
		mVisibleMsgBoxSet.insert(mb);
		mHiddenMsgBoxSet.erase(mbiter);
	}
}

void GUIManager::hideMsgBox(MsgBox* mb)
{
	mVisibleMsgBoxSet.erase(mVisibleMsgBoxSet.find(mb));
	mHiddenMsgBoxSet.insert(mb);
}


void GUIManager::removeOverlay(const std::string& overlayName)
{
	std::map<std::string, TextOverlay*>::iterator fnd=mOverlays.find(overlayName);
	if(fnd == mOverlays.end())
	{
		return;
	}

	delete fnd->second;
	mOverlays.erase(fnd);
}	

void GUIManager::removeBrowser(const std::string& browserName)
{
	std::map<std::string, WebBrowser*>::iterator fnd=mBrowsers.find(browserName);
	if(fnd == mBrowsers.end())
	{
		return;
	}

	delete fnd->second;
	mBrowsers.erase(fnd);
}	

void GUIManager::removeWebConnectLogin(const std::string& name)
{
	std::map<std::string, WebConnectLogin*>::iterator fnd=mWebConnectLogins.find(name);
	if(fnd == mWebConnectLogins.end())
	{
		return;
	}

	delete fnd->second;
	mWebConnectLogins.erase(fnd);
}

TextOverlay* GUIManager::createOverlay(const std::string& overlayName)
{
	if(isOverlayPresent(overlayName))
	{
		std::ostringstream oss;
		oss << "isOverlayPresent(" << overlayName << ")==true";
		throw Exception(42, oss.str().c_str(), "GUIManager::createOverlay(const std::string& overlayName)");
	}
	TextOverlay* overlay=new TextOverlay(overlayName);
	mOverlays[overlayName]=overlay;
	return overlay;
}

WebBrowser* GUIManager::createBrowser(const std::string& browserName, unsigned int width, unsigned int height)
{
	if(isBrowserPresent(browserName))
	{
		std::ostringstream oss;
		oss << "isBrowserPresent(" << browserName << ")==true";
		throw Exception(42, oss.str().c_str(), "GUIManager::createBrowser(const std::string& browserName, unsigned int width, unsigned int height)");
	}
	WebBrowser* browser=new WebBrowser(browserName, width, height);
	browser->setAlpha(0.5);
	mBrowsers[browserName]=browser;
	return browser;
}


WebConnectLogin* GUIManager::createWebConnectLogin(const std::string& name)
{
	if(isWebConnectLoginPresent(name))
	{
		std::ostringstream oss;
		oss << "isWebConnectLoginPresent(" << name << ")==true";
		throw Exception(42, oss.str().c_str(), "GUIManager::createWebConnectLogin(const std::string& name)");
	}

	WebConnectLogin* login=new WebConnectLogin(name);
	mWebConnectLogins[name]=login;
	return login;
}

MiniMap* GUIManager::createMiniMap(const std::string& minimapName)
{
	if(isMiniMapPresent(minimapName))
	{
		std::ostringstream oss;
		oss << "isMiniMapPresent(" << minimapName << ")==true";
		throw Exception(42, oss.str().c_str(), "GUIManager::createMiniMap(const std::string& minimapName, RenderWindow* rw, SceneManager* sm, CEGUI::OgreCEGUIRenderer* renderer)");
	}
	MiniMap* mm=new MiniMap(minimapName, mWindow, mSceneMgr, mGUIRenderer);
	mMiniMaps[minimapName]=mm;
	return mm;
}

MiniMap* GUIManager::getMiniMap(const std::string &minimapName)
{
	std::map<std::string, MiniMap*>::iterator fnd=mMiniMaps.find(minimapName);
	if(fnd == mMiniMaps.end())
	{
		throw Exception(42, "fnd==mMiniMaps.end()", "GUIManager::getMiniMap(const std::string& minimapName)");
	}
	return fnd->second;
}

bool GUIManager::isMiniMapPresent(const std::string& minimapName) const
{
	if(mMiniMaps.size()==0) return false;
	std::map<std::string, MiniMap*>::const_iterator fnd=mMiniMaps.find(minimapName);
	if(fnd == mMiniMaps.end())
	{
		return false;
	}
	return true;
}

void GUIManager::removeMinimap(const std::string &minimapName)
{
	std::map<std::string, MiniMap*>::iterator fnd=mMiniMaps.find(minimapName);
	if(fnd==mMiniMaps.end())
	{
		return;
	}
	delete fnd->second;
	mMiniMaps.erase(fnd);
}

WebPage* GUIManager::getWebPage(const std::string& pageName)
{
	std::map<std::string, WebPage*>::iterator fnd=mWebPages.find(pageName);
	if(fnd==mWebPages.end())
	{
		return NULL;
	}
	else
	{
		return fnd->second;
	}
}

void GUIManager::injectWindowResized(unsigned int width, unsigned int height)
{
	 this->mGUIRenderer->setDisplaySize(CEGUI::Size(Ogre::Real(width), Ogre::Real(height)));

	 /*
	TWindows::iterator it = m_winNames.begin();
	TWindows::iterator it_end = m_winNames.end();
	for( ; it != it_end; it++ )
	{
	  CEGUI::Window *pW = CEGUI::WindowManager::getSingleton().getWindow( (*it).second ); 
	  pW->setMaxSize( CEGUI::UVector2( CEGUI::UDim(0, Ogre::Real(width)), CEGUI::UDim(0, Ogre::Real(height))));
	  pW->setSize( CEGUI::UVector2( CEGUI::UDim(0, Ogre::Real(width)), CEGUI::UDim(0, Ogre::Real(height))));
	}
	*/

	CEGUI::MouseCursor::getSingleton().setConstraintArea(NULL);
}

