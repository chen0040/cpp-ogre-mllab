#ifndef _H_ML_LAB_GUI_MANAGER_H
#define _H_ML_LAB_GUI_MANAGER_H

#include <CEGUI/CEGUI.h>
#include <Ogre.h>
#include <OgreCEGUIRenderer.h>
#include <vector>
#include <stack>
#include "CIWidget.h"
#include "TextOverlay.h"
#include "WebBrowser.h"
#include "MiniMap.h"
#include "MsgBox.h"
#include "WebPage.h"
#include "WebConnectLogin.h"

using namespace Ogre;

class GUIManager
{
private:
	GUIManager(const GUIManager& rhs) { }
	GUIManager& operator=(const GUIManager& rhs) { return *this; }

public:
	GUIManager(RenderWindow* rw, SceneManager* sm);
	virtual ~GUIManager();
	static GUIManager* getSingletonPtr();
	static GUIManager& getSingleton();

protected:
	void loadWebSettings();
	void setupNaviLibrary();

public:
	void setModalState(bool modal, CIWidget* source);
	bool getModalState() const { return hasModalWidgets(); }
	bool hasFocus() const;
protected:
	void popModalWidget() { mModalWidgetStack.pop(); }
	void pushModalWidget(CIWidget* widget) { mModalWidgetStack.push(widget); }
	CIWidget* getTopModalWidget();
	bool hasModalWidgets() const { return !mModalWidgetStack.empty(); }

public:
	TextOverlay* getOverlay(const std::string& overlayName);
	WebBrowser* getBrowser(const std::string& browserName);
	MiniMap* getMiniMap(const std::string& minimapName);
public:
	TextOverlay* createOverlay(const std::string& overlayName);
	MiniMap* createMiniMap(const std::string& minimapName);
	WebBrowser* createBrowser(const std::string& browserName, unsigned int width, unsigned int height);
	WebConnectLogin* createWebConnectLogin(const std::string& name);
public:
	void removeMinimap(const std::string& minimapName);
	void removeOverlay(const std::string& overlayName);
	void removeBrowser(const std::string& browserName);
	void removeWebConnectLogin(const std::string& name);
public:
	bool isMiniMapPresent(const std::string& minimapName) const;
	bool isOverlayPresent(const std::string& overlayName) const;
	bool isBrowserPresent(const std::string& browserName) const;
	bool isWebConnectLoginPresent(const std::string& name) const;

public:
	void showMsgBox(const std::string& title="", const std::string& msg="");
	void hideMsgBox(MsgBox* mb);

public:
	void injectWindowResized(unsigned int width, unsigned int height);

public:
	static CEGUI::DefaultWindow* createLabel(const CEGUI::String& id, const CEGUI::String& text, float left, float top, float width, float height);
	static CEGUI::Editbox* createEdit(const CEGUI::String& id, const CEGUI::String& value, float left, float top, float width, float height);	
	static CEGUI::Combobox* createCombo(const CEGUI::String& id,  float left, float top, float width, float height);	
	static CEGUI::Editbox* createTextField(CEGUI::Window* container, const CEGUI::String& id, float left, float top, float width, float height, const CEGUI::String& labelText, const CEGUI::String& editValue="", float labelWidth=0.3f);
	static CEGUI::Combobox* createCombobox(CEGUI::Window* container, const CEGUI::String& id, float left, float top, float width, float height, const CEGUI::String& labelText,  float labelWidth=0.3f);

public:
	WebPage* getDefaultWebPage() const { return mWebPages.find(mDefaultWebPageName)->second; }
	const std::string& getWebFolder() const { return mWebFolder; }
	WebPage* getWebPage(const std::string& pageName);

private:
	std::stack<CIWidget*> mModalWidgetStack;
	std::map<std::string, TextOverlay*> mOverlays;
	std::map<std::string, WebBrowser*> mBrowsers;
	std::map<std::string, MiniMap*> mMiniMaps;
	std::map<std::string, MsgBox*> mMsgBoxes;
	std::map<std::string, WebConnectLogin*> mWebConnectLogins;
	std::set<MsgBox*> mVisibleMsgBoxSet;
	std::set<MsgBox*> mHiddenMsgBoxSet;
	std::map<std::string, WebPage*> mWebPages;
	std::string mDefaultWebPageName;
	std::string mWebFolder;
	std::string mGUITheme;
	size_t MAX_VISIBLE_MSG_BOXES;
	static GUIManager* mSingleton;

public:
	const std::string& getGUITheme() const { return mGUITheme; }

protected:
	CEGUI::OgreCEGUIRenderer* mGUIRenderer;
	CEGUI::System* mGUISystem;
	Ogre::RenderWindow* mWindow;
	Ogre::SceneManager* mSceneMgr;

public:
	CEGUI::OgreCEGUIRenderer* getGUIRenderer() { return mGUIRenderer; }
	CEGUI::System* getGUISystem() { return mGUISystem; }

public:
	CEGUI::Window* getGUISheet() { return mGUISystem->getGUISheet(); }
};
#endif