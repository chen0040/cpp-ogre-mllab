#ifndef MORPH_WINDOW_H_
#define MORPH_WINDOW_H_

#include "MapEditorListener.h"
#include "FogEditor.h"

enum CursorType
{
    NOTHING = 0,
    LOWER,
    RAISE,
    PAINT,
};


class MorphWindow
{
private:
protected:

	CursorType			mCursorType;
	CEGUI::Window*		mWindow;
	CEGUI::Combobox*	mCursorTypeCombobox;
	CEGUI::Scrollbar*	mCursorSizeSlider;
	CEGUI::Scrollbar*	mCursorStrengthSlider;
	CEGUI::PushButton*	mFogSettingsButton;
	CEGUI::Window*	mCursorSizeWindow;
	CEGUI::Window*	mCursorStrengthWindow;
	MapEditorListener*	mListener;

	FogEditor*			fogEditor;

public:
						MorphWindow(FrameListener* listener);
						~MorphWindow();
	CEGUI::Window*		getWindow() { return mWindow; }
	bool				handleMorph(const CEGUI::EventArgs& e);
	bool				handleCloseWindow(const CEGUI::EventArgs& e);
	bool				handleCursorSizeChanged(const CEGUI::EventArgs& e);
	bool				handleCursorStrengthChanged(const CEGUI::EventArgs& e);
	bool				handleFogButtonClicked(const CEGUI::EventArgs& e);
	bool				doneChangingCursorSizeSlider(const CEGUI::EventArgs& e);
	bool				doneChangingCursorStrengthSlider(const CEGUI::EventArgs& e);
	void				addListener(FrameListener* listener) { mListener=static_cast<MapEditorListener*>(listener); }

	bool				handleShowMorphWindow(const CEGUI::EventArgs& e);
};

#endif