#ifndef MAP_EDITOR_H
#define MAP_EDITOR_H

#include "ExampleApplication.h"
#include "MapEditorListener.h"
#include "ActionBar.h"
#include "TabWindow.h"

class MapEditor : public ExampleApplication
{

private:
	MapEditorListener* mMapEditorListener;
	CEGUI::Renderer* mMapGuiRenderer;
    CEGUI::System*	mGuiSystem;
	CEGUI::Window*	mMainWindow;
	ActionBar*		mActionBar;
	TabWindow*		mTabWindow;
	String			mTerrainPath;

protected:
	bool	setup(void);
	void	createScene(void);
	void	createFrameListener(void);
	void	chooseSceneManager(void);
	void	createCamera(void);
	void	createViewports(void);
	void	setupResources(void);
	void	loadResources(void);

public:
					MapEditor();
					~MapEditor();
};

#endif