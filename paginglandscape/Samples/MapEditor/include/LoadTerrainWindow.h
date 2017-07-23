#ifndef LOAD_TERRAIN_WINDOW_H_
#define LOAD_TERRAIN_WINDOW_H_

#include "MapEditorListener.h"
#include "MapUtil.h"

class LoadTerrainWindow
{
private:
	MapEditorListener*	mListener;
	CEGUI::Window*		mWindow;

	CEGUI::Editbox*		mCfgEditbox;
	CEGUI::Editbox*		mRawEditbox;
	CEGUI::PushButton*	mCfgOkButton;
	CEGUI::PushButton*	mRawOkButton;
	CEGUI::PushButton*	mCloseButton;

	MapUtil*			mMapTool;

public:
						LoadTerrainWindow(FrameListener* listener);
						~LoadTerrainWindow(void);

	CEGUI::Window*		getWindow() { return mWindow; } 	
	void				showWindow();
	void				hideWindow();
	void				addListener(FrameListener* listener) { mListener=static_cast<MapEditorListener*>(listener); }

	bool				handleCfgOkClicked(const CEGUI::EventArgs& e);
	bool				handleRawOkClicked(const CEGUI::EventArgs& e);
	bool				handleCloseClicked(const CEGUI::EventArgs& e);
};

#endif