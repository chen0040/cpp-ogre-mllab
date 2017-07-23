
#ifndef LIBNOISE_WINDOW_H_
#define LIBNOISE_WINDOW_H_

#include "MapEditorListener.h"
#include "LibnoiseGenerator.h"

#include <stdio.h>

class LibnoiseWindow
{
private:
	LibnoiseGenerator*	mLibnoise;

	CEGUI::PushButton*	mPreviewButton;
	CEGUI::Window*	mPreviewImage;

	CEGUI::RadioButton* mBillow;
	CEGUI::RadioButton* mCheckerboard;
	CEGUI::RadioButton* mPerlin;
	CEGUI::RadioButton* mRidgedMulti;
	CEGUI::RadioButton* mVoronoi;

	CEGUI::Editbox*		mFrequencyEditbox;
	CEGUI::Editbox*		mLacunarityEditbox;
	CEGUI::Editbox*		mOctaveCountEditbox;
	CEGUI::Editbox*		mPersistanceEditbox;
	CEGUI::Editbox*		mSeedEditbox;

	CEGUI::Editbox*		mLocationXEditbox;
	CEGUI::Editbox*		mLocationYEditbox;
	CEGUI::Editbox*		mWidthEditbox;
	CEGUI::Editbox*		mHeightEditbox;

	CEGUI::Texture* tex;
	CEGUI::Imageset* imageSet;
	CEGUI::Renderer* mGUIRenderer;

	noise::utils::NoiseMap heightMap;
	noise::utils::NoiseMapBuilderPlane heightMapBuilder;
protected:
	CEGUI::Window*	mWindow;
	MapEditorListener*	mListener;
	
public:
					LibnoiseWindow(FrameListener* listener);
					~LibnoiseWindow();
	CEGUI::Window*	getWindow() { return mWindow; } 
	void			addListener(FrameListener* listener) { mListener=static_cast<MapEditorListener*>(listener); }

	bool			handlePreviewClicked(const CEGUI::EventArgs& e);
	double			getLocX();
	double			getLocY();
	double			getSizeWidth();
	double			getSizeHeight();
	int				getGeneratorType();

	double			getFrequency();
	double			getLacunarity();
	double			getOctaveCount();
	double			getPersistance();
	double			getSeed();


	void			showWindow();
	void			hideWindow();
};

#endif