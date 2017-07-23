
#ifndef ACTION_BAR_H_
#define ACTION_BAR_H_

#include "NewTerrainWindow.h"
#include "LoadTerrainWindow.h"
#include "MapEditorListener.h"

class ActionBar
{
private:
protected:
	CEGUI::Window*	mWindow;
	CEGUI::Window*	mBackground;
	CEGUI::Window*	mButtonNew;
	CEGUI::Window*	mButtonLoad;
	CEGUI::Window*	mButtonClose;
	MapEditorListener*	mListener;

	NewTerrainWindow*	mNewTerrainWindow;
	LoadTerrainWindow*	mLoadTerrainWindow;
public:
					ActionBar(FrameListener* listener);
					~ActionBar();
	CEGUI::Window*	getWindow() { return mWindow; } 
	bool			handleNew(const CEGUI::EventArgs& e);
	bool			handleLoad(const CEGUI::EventArgs& e);
	bool			handleQuit(const CEGUI::EventArgs& e);
	void			addListener(FrameListener* listener) { mListener=static_cast<MapEditorListener*>(listener); }
};

#endif