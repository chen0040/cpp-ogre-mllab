#ifndef TEXTURE_WINDOW_H_
#define TEXTURE_WINDOW_H_

#include "ExampleFrameListener.h"

#include <vector>

using namespace std;

class TextureWindow
{
private:
protected:
	CEGUI::Window*		mWindow;
	MapEditorListener*	mListener;
	CEGUI::Combobox*	mTextureTypeCombobox;
	CEGUI::Combobox*	mTextureActionCombobox;
	CEGUI::Window*  mPaintColorAlphaWindow;
	CEGUI::Scrollbar*	mPaintColorAlphaSlider;
	CEGUI::Window*  mPaintColorBrushSizeWindow;
	CEGUI::Scrollbar*	mPaintColorBrushSizeSlider;

	CEGUI::Scrollbar*	mPaintColorRedSlider;
	CEGUI::Scrollbar*	mPaintColorGreenSlider;
	CEGUI::Scrollbar*	mPaintColorBlueSlider;
	CEGUI::Window*		mPaintColorWindowStaticText;
	CEGUI::Window*		mPaintColorWindowStaticImage;

	CEGUI::RadioButton*	mPaintTextureLayer0RadioButton;
	CEGUI::PushButton*	mPaintTextureLayer0Button;
	CEGUI::Window*	mPaintTextureLayer0Window;
	CEGUI::RadioButton*	mPaintTextureLayer1RadioButton;
	CEGUI::PushButton*	mPaintTextureLayer1Button;
	CEGUI::Window*	mPaintTextureLayer1Window;
	CEGUI::RadioButton*	mPaintTextureLayer2RadioButton;
	CEGUI::PushButton*	mPaintTextureLayer2Button;
	CEGUI::Window*	mPaintTextureLayer2Window;
	CEGUI::RadioButton*	mPaintTextureLayer3RadioButton;
	CEGUI::PushButton*	mPaintTextureLayer3Button;
	CEGUI::Window*	mPaintTextureLayer3Window;
	
	vector<CEGUI::Window*> PaintColorMenu;
	vector<CEGUI::Window*> PaintTextureMenu;
	vector<CEGUI::Window*> TextureWindows;
public:
	TextureWindow(FrameListener* listener);
	~TextureWindow();

	CEGUI::Window*		getWindow() { return mWindow; }
	void				addListener(FrameListener* listener) { mListener=static_cast<MapEditorListener*>(listener); }

	void				showCorrectMenu();
		
	bool				handleTextureTypeChange(const CEGUI::EventArgs& e);
	bool				handleTextureActionChange(const CEGUI::EventArgs& e);
	bool				handleAlphaSliderChanged(const CEGUI::EventArgs& e);
	bool				handleColorChanged(const CEGUI::EventArgs& e);
	bool				doneChangingColorSlider(const CEGUI::EventArgs& e);
	bool				doneChangingAlphaSlider(const CEGUI::EventArgs& e);
	bool				handleCursorSizeChanged(const CEGUI::EventArgs& e);
	bool				doneChangingCursorSizeSlider(const CEGUI::EventArgs& e);
	bool				handleShowTextureWindow(const CEGUI::EventArgs& e);
	bool				handleChangeTextureLayer(const CEGUI::EventArgs& e);
};

#endif //TEXTURE_WINDOW_H_