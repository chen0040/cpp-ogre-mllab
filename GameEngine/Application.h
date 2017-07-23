#ifndef _H_MLLAB_APPLICATION_H
#define _H_MLLAB_APPLICATION_H

#include <Ogre.h>
#include <CEGUI/CEGUI.h>
#include <OgreCEGUIRenderer.h>
#include "../Frames/FrameManager.h"
#include "../Terrain/TerrainInfoManager.h"
#include "../WeatherEngine/WeatherManager.h"
#include "../Widgets/GUIManager.h"
#include "../Widgets/AboutDlg.h"
#include "../Widgets/WebConnectLogin.h"
#include "Navi.h"
#include "../Widgets/NicknameDlg.h"
#include "../HTTPEngine/HTTPManager.h"
#include "../GameLoader/GameLoader.h"
#include "../SceneAssets/CaelumManager.h"
#include "../SceneAssets/HydraxManager.h"
#include "../SceneAssets/PGManager.h"

using namespace Ogre;

class Application : public WindowEventListener
{
protected:
	Root* mRoot;
	RenderWindow* mWindow;
	SceneManager* mSceneMgr;
	RenderSystem* mSystem;
	Camera* mCamera;

protected:
	FrameManager* mFrameManager;
	TerrainInfoManager* mTerrainInfoManager;
	HTTPManager* mHTTPManager;
	WeatherManager* mWeatherManager;
	GUIManager* mGUIManager;
	AboutDlg* mAboutDlg;
	WebBrowser* mWebBrowser;
	TextOverlay* mConsole;
	MiniMap* mMiniMap;
	WebConnectLogin* mWebConnectLogin;
	NicknameDlg* mNicknameDlg;
	CaelumManager* mCaelumManager;
	HydraxManager* mHydraxManager;
	PGManager* mPGManager;

private:
	std::string mRenderingSystemName;
public:
	const std::string& getRenderSystemName() const { return mRenderingSystemName; }
	bool isOpenGLRendering() const { return mRenderingSystemName.compare("OpenGL Rendering Subsystem")==0; }

private:
	CEGUI::MenuItem* mItemFile;
	CEGUI::MenuItem* mItemHelp;
	CEGUI::MenuItem* mItemPages;
	CEGUI::MenuItem* mItemWindow;

private:
	CEGUI::MenuItem* mItemMiniMap;
	CEGUI::MenuItem* mItemWebBrowser;
	CEGUI::MenuItem* mItemWebConnect;
	CEGUI::MenuItem* mItemNickname;

private:
	CEGUI::MenuItem* mItemFirstPersonCamera;
	CEGUI::MenuItem* mItemSphericalCamera;

protected:
	OIS::Keyboard* mKeyboard;
	OIS::Mouse* mMouse;
	OIS::InputManager* mInputManager;

public:
	OIS::Keyboard* getKeyboard() { return mKeyboard; }
	OIS::Mouse* getMouse() { return mMouse; }

private:
	bool mRunning;
	bool isRunning() const { return mRunning; }

public:
	virtual void windowMoved(RenderWindow* rw);
	virtual void windowResized(RenderWindow* rw);
	virtual bool windowClosing(RenderWindow* rw);
	virtual void windowClosed(RenderWindow* rw) { }
	virtual void windowFocusChange(RenderWindow* rw);
public:
	bool isMouseWithinWindow() const;
	void showWindowMouse(bool shown);
private:
	bool mWindowsMouseShown;

public:
	Application();
	virtual ~Application();

public:
	void init(const std::string& title);
	void cleanup();
	void startRenderLoop();

public:
	void setCurrentFrame(const std::string& frameName);
	void addFrame(const std::string& display_name, AppFrame* frame);
private:
	std::map<std::string, std::string> mFrameDisplayNames;

private:
	void setFrameCaption(const std::string& caption);

public:
	bool onClicked_Quit(const CEGUI::EventArgs & evt);
	bool onClicked_Open(const CEGUI::EventArgs & evt);
	bool onClicked_Save(const CEGUI::EventArgs & evt);
	bool onClicked_SaveAs(const CEGUI::EventArgs & evt);
	bool onClicked_About(const CEGUI::EventArgs& evt);	
	bool onClicked_WebBrowser(const CEGUI::EventArgs& evt);
	bool onClicked_MiniMap(const CEGUI::EventArgs& evt);
	bool onClicked_WebConnect(const CEGUI::EventArgs& evt);
	bool onClicked_Nickname(const CEGUI::EventArgs& evt);
	bool onClicked_ResetCamera(const CEGUI::EventArgs& evt);
	bool onClicked_FirstPersonCamera(const CEGUI::EventArgs& evt);
	bool onClicked_SphericalCamera(const CEGUI::EventArgs& evt);


protected:
	void createCURL();
	void createRoot();
	void defineResources();
	void setupRenderSystem();
	void createRenderWindow(const std::string& title);
	void initializeResources();
	void setupScene();
	void setupInput();
	void setupGUI();
	void createWebBrowser();
	void createConsole();
	void createNicknameDlg();
	void setupFrameListener();
	void createMinimap();
	void createWebConnectLogin();
	void createCaelum();
	void createHydrax();
	void createPagedGeometry();

protected:
	virtual CEGUI::Window* createMenu();
	virtual CEGUI::Window* createPopupMenuFile();
	virtual CEGUI::Window* createPopupMenuHelp();
	virtual CEGUI::Window* createPopupMenuScenes();
	virtual CEGUI::Window* createPopupMenuWindow();

protected:
	bool onMinimapClosed(const CEGUI::EventArgs& evt);
	void onHTTPManagerEnabled(bool enabled);

protected:
	CEGUI::Menubar* mStatusBar;
	virtual CEGUI::Window* createStatusBar();

public:
	RenderWindow* getWindow() { return mWindow; }
	SceneManager* getSceneMgr() { return mSceneMgr; }
	GUIManager* getGUIMgr() { return mGUIManager; }
	Camera* getCamera() { return mCamera; }
	WebBrowser* getBrowser() { return mWebBrowser; }
	CEGUI::Menubar* getStatusBar() { return mStatusBar; }
	WebConnectLogin* getWebConnectLogin() { return mWebConnectLogin; }
	TextOverlay* getConsole();
	MiniMap* getMiniMap() { return mMiniMap; }

public:
	bool render();

public:
	static Application* getSingletonPtr() { return mSingleton; }
	static Application& getSingleton() { return *mSingleton; }

protected:
	boost::signals::connection mEventHTTPManagerEnabled;

protected:
	static Application* mSingleton;
};

#endif
