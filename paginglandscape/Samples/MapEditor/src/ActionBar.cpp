
#include <CEGUI/Cegui.h>
#include <OgreCEGUIRenderer.h>
#include "OgreCEGUIResourceProvider.h"

#include "ActionBar.h"
#include "MapEditorListener.h"
 

//------------------------------------------------------------------------------------------------
ActionBar::ActionBar(FrameListener* listener)
{
	mWindow = CEGUI::WindowManager::getSingleton().loadWindowLayout((CEGUI::utf8*)"MapEditorActionBar.layout");

	mButtonNew = CEGUI::WindowManager::getSingleton().getWindow((CEGUI::utf8*)"NewButton");
	mButtonLoad = CEGUI::WindowManager::getSingleton().getWindow((CEGUI::utf8*)"LoadButton");
	mButtonClose = CEGUI::WindowManager::getSingleton().getWindow((CEGUI::utf8*)"QuitButton");

	
	mListener = static_cast < MapEditorListener* > (listener);

	mButtonNew->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ActionBar::handleNew, this));
	mButtonLoad->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ActionBar::handleLoad, this));
	mButtonClose->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ActionBar::handleQuit, this));

	mNewTerrainWindow = new NewTerrainWindow(mListener);
	CEGUI::WindowManager::getSingleton().getWindow("MainWindow")->addChildWindow(mNewTerrainWindow->getWindow());

	mLoadTerrainWindow = new LoadTerrainWindow(mListener);
	CEGUI::WindowManager::getSingleton().getWindow("MainWindow")->addChildWindow(mLoadTerrainWindow->getWindow());
}
//------------------------------------------------------------------------------------------------
ActionBar::~ActionBar()
{
	delete mNewTerrainWindow;
	delete mLoadTerrainWindow;
}
//------------------------------------------------------------------------------------------------
bool ActionBar::handleNew(const CEGUI::EventArgs& e)
{
	mNewTerrainWindow->addListener(mListener);
	mNewTerrainWindow->showWindow();
	return true;
}
//------------------------------------------------------------------------------------------------
bool ActionBar::handleLoad(const CEGUI::EventArgs& e)
{
	mLoadTerrainWindow->addListener(mListener);
	mLoadTerrainWindow->showWindow();
	return true;
}
//------------------------------------------------------------------------------------------------
bool ActionBar::handleQuit(const CEGUI::EventArgs& e)
{
	mListener->requestShutDown();
	return true;
}


