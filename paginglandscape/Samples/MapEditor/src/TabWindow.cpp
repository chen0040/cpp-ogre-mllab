
#include <CEGUI/Cegui.h>
#include <OgreCEGUIRenderer.h>
#include "OgreCEGUIResourceProvider.h"

#include "TabWindow.h"
#include "MapEditorListener.h"

//------------------------------------------------------------------------------------------------
TabWindow::TabWindow(FrameListener* listener)
{
	mListener=static_cast<MapEditorListener*>(listener);

	mWindow = CEGUI::WindowManager::getSingleton().loadWindowLayout((CEGUI::utf8*)"MapEditorTabWindow.layout");

	mMorphWindow=NULL;
	mTextureWindow=NULL;
	mObjectWindow=NULL;

	mMorphWindow = new MorphWindow(listener);
	CEGUI::WindowManager::getSingleton().getWindow("TabPage1")->addChildWindow(mMorphWindow->getWindow());

	mTextureWindow = new TextureWindow(listener);
	CEGUI::WindowManager::getSingleton().getWindow("TabPage2")->addChildWindow(mTextureWindow->getWindow());
}
//------------------------------------------------------------------------------------------------
TabWindow::~TabWindow()
{
	delete mMorphWindow;
	delete mTextureWindow;
}


