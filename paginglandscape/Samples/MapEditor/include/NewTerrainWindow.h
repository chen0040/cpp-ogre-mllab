#ifndef NEW_TERRAIN_WINDOW_H_
#define NEW_TERRAIN_WINDOW_H_

#include "MapEditorListener.h"

#include "MapUtil.h"
#include "MapEqualizer.h"
#include "LibnoiseWindow.h"
#include "LibnoiseGenerator.h"


class NewTerrainWindow
{
private:
	MapEditorListener*	mListener;
	CEGUI::Window*		mWindow;
	CEGUI::RadioButton* m256WidthRadioButton;
	CEGUI::RadioButton* m512WidthRadioButton;
	CEGUI::RadioButton* m1024WidthRadioButton;
	CEGUI::RadioButton* m2048WidthRadioButton;
	CEGUI::RadioButton* m4096WidthRadioButton;
	CEGUI::RadioButton* m256HeightRadioButton;
	CEGUI::RadioButton* m512HeightRadioButton;
	CEGUI::RadioButton* m1024HeightRadioButton;
	CEGUI::RadioButton* m2048HeightRadioButton;
	CEGUI::RadioButton* m4096HeightRadioButton;

    CEGUI::RadioButton* mGenerateTerrainPlasmaRadioButton;
	CEGUI::RadioButton* mGenerateTerrainFaultRadioButton;
	CEGUI::RadioButton* mGenerateTerrainParticleRadioButton;
    CEGUI::RadioButton* mGenerateTerrainBlankRadioButton;
	CEGUI::RadioButton* mGenerateTerrainLibnoiseRadioButton;

	CEGUI::Editbox*		mMapNameEditbox;

	CEGUI::PushButton*	mOkButton;
	CEGUI::PushButton*	mCancelButton;

	LibnoiseWindow*		mLibnoiseWindow;
	LibnoiseGenerator*	mLibnoise;
public:
						NewTerrainWindow(FrameListener* listener);
						~NewTerrainWindow(void);

	CEGUI::Window*		getWindow() { return mWindow; } 	
	bool				handleOkClicked(const CEGUI::EventArgs& e);
	bool				handleCancelClicked(const CEGUI::EventArgs& e);
	bool				handleRadiobuttonSelectionChanged(const CEGUI::EventArgs& e);

	void				showWindow();
	void				hideWindow();
	void				writeCfgFile(const char* name, int w, int h, int pageSize, int tileSize);
	void				addListener(FrameListener* listener) { mListener=static_cast<MapEditorListener*>(listener); mLibnoiseWindow->addListener(listener); }

    MapUtil				*mMapTool;
    ErodeFault			*mMapCreate;


};

#endif