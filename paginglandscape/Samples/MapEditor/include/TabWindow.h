
#ifndef TAB_WINDOW_H_
#define TAB_WINDOW_H_

#include "MapEditorListener.h"
#include "MorphWindow.h"
#include "TextureWindow.h"
#include "ObjectWindow.h"

class TabWindow
{
private:
protected:
	CEGUI::Window*	mWindow;
	MapEditorListener*	mListener;
	MorphWindow*	mMorphWindow;
	TextureWindow*	mTextureWindow;
	ObjectWindow*	mObjectWindow;
public:
					TabWindow(FrameListener* listener);
					~TabWindow();
	CEGUI::Window*	getWindow() { return mWindow; } 
	void			addListener(FrameListener* listener) { mListener=static_cast<MapEditorListener*>(listener); mMorphWindow->addListener(listener); mTextureWindow->addListener(listener); }
};

#endif