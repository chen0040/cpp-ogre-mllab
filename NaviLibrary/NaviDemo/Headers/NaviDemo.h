#ifndef __NaviDemo_H__
#define __NaviDemo_H__
#if _MSC_VER > 1000
#pragma once
#endif

#include "Ogre.h"
#include "InputManager.h"
#include "NaviManager.h"
#include "Navi.h"

class NaviDemo : public OIS::MouseListener, public OIS::KeyListener, public Ogre::WindowEventListener
{
	Ogre::RenderWindow* renderWin;
	Ogre::SceneManager* sceneMgr;
	NaviLibrary::NaviManager* naviMgr;
	NaviLibrary::Navi* menubar, *status, *chat, *equip;
	InputManager* inputMgr;
	void parseResources();
	void loadInputSystem();
public:
	bool shouldQuit;
	NaviDemo();
	~NaviDemo();

	void createScene();
	void setupNavis();

	void Update();

	void turnOn(const NaviLibrary::NaviData &naviData);
	void turnOff(const NaviLibrary::NaviData &naviData);
	void hpChange(const NaviLibrary::NaviData &naviData);
	void messageSent(const NaviLibrary::NaviData &naviData);
	void itemEquipped(const NaviLibrary::NaviData &naviData);
	void levelChanged(const NaviLibrary::NaviData &naviData);
	
	bool mouseMoved(const OIS::MouseEvent &arg);
	bool mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id);
	bool mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id);

	bool keyPressed( const OIS::KeyEvent &arg );
	bool keyReleased( const OIS::KeyEvent &arg );	

	void windowMoved(Ogre::RenderWindow* rw);
	void windowResized(Ogre::RenderWindow* rw);
	void windowClosed(Ogre::RenderWindow* rw);
	void windowFocusChange(Ogre::RenderWindow* rw);
};

#endif