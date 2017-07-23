#ifndef FOG_EDITOR_H_ 
#define FOG_EDITOR_H_

#include "MapEditorListener.h"

class FogEditor
{
private:
	const static short	FOG_LIN=0;
	const static short	FOG_EXPONENTIAL=1;
	const static short	FOG_EXPONENTIAL2=2;
	short				mTypeOfFog;
	bool				mFogEnabled;
	float				mFogDensity;				
	float				mFogStart;
	float				mFogEnd;

	MapEditorListener*	mListener;
	CEGUI::Window*		mWindow;
	CEGUI::Combobox*	mTypeOfFogCombobox;
	CEGUI::Scrollbar*	mRedSlider;
	CEGUI::Scrollbar*	mGreenSlider;
	CEGUI::Scrollbar*	mBlueSlider;
	CEGUI::PushButton*	mOkButton;
	CEGUI::PushButton*	mCancelButton;
	CEGUI::Window* mPreview;
	CEGUI::Checkbox*	mFogEnabledCheckbox;
	CEGUI::Editbox*		mDensityEditbox;
	CEGUI::Editbox*		mStartEditbox;
	CEGUI::Editbox*		mEndEditbox;
	
public:
						FogEditor(FrameListener* listener);
						~FogEditor(void);
	CEGUI::Window*		getWindow() { return mWindow; } 
	bool				handleColorChanged(const CEGUI::EventArgs& e);
	bool				handleOkClicked(const CEGUI::EventArgs& e);
	bool				handleCancelClicked(const CEGUI::EventArgs& e);
	bool				handleFogTypeChanged(const CEGUI::EventArgs& e);
	void				showWindow();
	void				hideWindow();
	void				addListener(FrameListener* listener) { mListener=static_cast<MapEditorListener*>(listener); }
};

#endif