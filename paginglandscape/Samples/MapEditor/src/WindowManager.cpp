
#include <CEGUI/Cegui.h>
#include <OgreCEGUIRenderer.h>

#include "WindowManager.h"

GUIWindowManager::GUIWindowManager(void)
{
}

GUIWindowManager::~GUIWindowManager(void)
{
}

void GUIWindowManager::addWindow(std::string name, CEGUI::Window* window)
{
	mWindows[name] = window;
}

void GUIWindowManager::removeWindow(std::string name)
{
	CEGUI::WindowManager::getSingleton().destroyWindow(name);
	mWindows.erase(name);
}