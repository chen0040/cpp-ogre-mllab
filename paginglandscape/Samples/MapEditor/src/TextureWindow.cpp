
#include <CEGUI/Cegui.h>
#include <OgreCEGUIRenderer.h>
#include "OgreCEGUIResourceProvider.h"

#include "MapEditorListener.h"
#include "TextureWindow.h"

//------------------------------------------------------------------------------------------------
TextureWindow::TextureWindow(FrameListener* listener)
{
	mListener=static_cast<MapEditorListener*>(listener);

	mWindow = CEGUI::WindowManager::getSingleton().loadWindowLayout((CEGUI::utf8*)"MapEditorTextureWindow.layout");
	mWindow->subscribeEvent(CEGUI::Window::EventRenderingStarted,CEGUI::Event::Subscriber(&TextureWindow::handleShowTextureWindow, this));

	//Combobox1
	mTextureTypeCombobox = (CEGUI::Combobox*)mWindow->getChild("TextureFormatList");
    CEGUI::ListboxTextItem* item = new CEGUI::ListboxTextItem((CEGUI::utf8*)"InstantBase", 0);
	item->setTextColours(CEGUI::colour(0.5,0.5,0.5));//Change color of the listbox items (color isn't right in WindowsLook mode)
    mTextureTypeCombobox->addItem(item);
    item = new CEGUI::ListboxTextItem((CEGUI::utf8*)"Splatting", 1);
	item->setTextColours(CEGUI::colour(0.5,0.5,0.5));//Change color of the listbox items (color isn't right in WindowsLook mode)
    mTextureTypeCombobox->addItem(item);
    item = new CEGUI::ListboxTextItem((CEGUI::utf8*)"Splatting2", 2);
	item->setTextColours(CEGUI::colour(0.5,0.5,0.5));//Change color of the listbox items (color isn't right in WindowsLook mode)
    mTextureTypeCombobox->addItem(item);
    item = new CEGUI::ListboxTextItem((CEGUI::utf8*)"Splatting3", 3);
	item->setTextColours(CEGUI::colour(0.5,0.5,0.5));//Change color of the listbox items (color isn't right in WindowsLook mode)
    mTextureTypeCombobox->addItem(item);
    item = new CEGUI::ListboxTextItem((CEGUI::utf8*)"Splatting4", 4);
	item->setTextColours(CEGUI::colour(0.5,0.5,0.5));//Change color of the listbox items (color isn't right in WindowsLook mode)
    mTextureTypeCombobox->addItem(item);
    item = new CEGUI::ListboxTextItem((CEGUI::utf8*)"Splatting5", 5);
	item->setTextColours(CEGUI::colour(0.5,0.5,0.5));//Change color of the listbox items (color isn't right in WindowsLook mode)
    mTextureTypeCombobox->addItem(item);
	item = new CEGUI::ListboxTextItem((CEGUI::utf8*)"Splatting6", 6);
	item->setTextColours(CEGUI::colour(0.5,0.5,0.5));//Change color of the listbox items (color isn't right in WindowsLook mode)
    mTextureTypeCombobox->addItem(item);
	item = new CEGUI::ListboxTextItem((CEGUI::utf8*)"Splatting7", 7);
	item->setTextColours(CEGUI::colour(0.5,0.5,0.5));//Change color of the listbox items (color isn't right in WindowsLook mode)
    mTextureTypeCombobox->addItem(item);

	mTextureTypeCombobox->subscribeEvent(CEGUI::Combobox::EventListSelectionAccepted, CEGUI::Event::Subscriber(&TextureWindow::handleTextureTypeChange, this));

	//Combobox2
	mTextureActionCombobox = (CEGUI::Combobox*)mWindow->getChild("TextureActionList");
    item = new CEGUI::ListboxTextItem((CEGUI::utf8*)"Paint Color", 0);
	item->setTextColours(CEGUI::colour(0.5,0.5,0.5));//Change color of the listbox items (color isn't right in WindowsLook mode)
    mTextureActionCombobox->addItem(item);
    item = new CEGUI::ListboxTextItem((CEGUI::utf8*)"Paint Alpha", 1);
	item->setTextColours(CEGUI::colour(0.5,0.5,0.5));//Change color of the listbox items (color isn't right in WindowsLook mode)
    mTextureActionCombobox->addItem(item);
    item = new CEGUI::ListboxTextItem((CEGUI::utf8*)"Paint Texture", 2);
	item->setTextColours(CEGUI::colour(0.5,0.5,0.5));//Change color of the listbox items (color isn't right in WindowsLook mode)
    mTextureActionCombobox->addItem(item);

	mTextureActionCombobox->subscribeEvent(CEGUI::Combobox::EventListSelectionAccepted, CEGUI::Event::Subscriber(&TextureWindow::handleTextureActionChange, this));


	mPaintColorAlphaSlider = (CEGUI::Scrollbar*)mWindow->getChild("PaintColorAlphaSlider");
	mPaintColorAlphaSlider->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,CEGUI::Event::Subscriber(&TextureWindow::handleAlphaSliderChanged, this));
	mPaintColorAlphaWindow = (CEGUI::Window*)mWindow->getChild("PaintColorAlphaWindow");
	mPaintColorAlphaSlider->setScrollPosition(1.0); 
	CEGUI::EventArgs p;
	handleAlphaSliderChanged(p);

	mPaintColorBrushSizeSlider = (CEGUI::Scrollbar*)mWindow->getChild("PaintColorBrushSizeSlider"); 
	mPaintColorBrushSizeSlider->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,CEGUI::Event::Subscriber(&TextureWindow::handleCursorSizeChanged, this));
	mPaintColorBrushSizeWindow = (CEGUI::Window*)mWindow->getChild("PaintColorBrushSizeWindow");


	//Paint color menu-items
	mPaintColorWindowStaticText = (CEGUI::Window*)mWindow->getChild("PaintColorWindow"); PaintColorMenu.push_back(mPaintColorWindowStaticText);
	mPaintColorRedSlider = (CEGUI::Scrollbar*)mWindow->getChild("PaintColorRedSlider"); PaintColorMenu.push_back(mPaintColorRedSlider);
	mPaintColorGreenSlider = (CEGUI::Scrollbar*)mWindow->getChild("PaintColorGreenSlider"); PaintColorMenu.push_back(mPaintColorGreenSlider);
	mPaintColorBlueSlider = (CEGUI::Scrollbar*)mWindow->getChild("PaintColorBlueSlider"); PaintColorMenu.push_back(mPaintColorBlueSlider);
	
	mPaintColorRedSlider->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,CEGUI::Event::Subscriber(&TextureWindow::handleColorChanged, this));
	mPaintColorGreenSlider->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,CEGUI::Event::Subscriber(&TextureWindow::handleColorChanged, this));
	mPaintColorBlueSlider->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,CEGUI::Event::Subscriber(&TextureWindow::handleColorChanged, this));
	mPaintColorRedSlider->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,CEGUI::Event::Subscriber(&TextureWindow::doneChangingColorSlider, this));
	mPaintColorGreenSlider->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,CEGUI::Event::Subscriber(&TextureWindow::doneChangingColorSlider, this));
	mPaintColorBlueSlider->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,CEGUI::Event::Subscriber(&TextureWindow::doneChangingColorSlider, this));

	mPaintColorWindowStaticText = (CEGUI::Window*)mWindow->getChild("PaintColorWindow"); PaintColorMenu.push_back(mPaintColorWindowStaticText);
	
	//Paint texture menu-items
	mPaintTextureLayer0RadioButton = (CEGUI::RadioButton*)mWindow->getChild("PaintTextureLayer0Radiobutton"); PaintTextureMenu.push_back(mPaintTextureLayer0RadioButton);
	mPaintTextureLayer0Button = (CEGUI::PushButton*)mWindow->getChild("PaintTextureLayer0ImportButton"); PaintTextureMenu.push_back(mPaintTextureLayer0Button);
	mPaintTextureLayer0Window = (CEGUI::Window*)mWindow->getChild("PaintTextureLayer0Window"); PaintTextureMenu.push_back(mPaintTextureLayer0Window);
	TextureWindows.push_back(mPaintTextureLayer0Window);
	mPaintTextureLayer1RadioButton = (CEGUI::RadioButton*)mWindow->getChild("PaintTextureLayer1Radiobutton"); PaintTextureMenu.push_back(mPaintTextureLayer1RadioButton);
	mPaintTextureLayer1Button = (CEGUI::PushButton*)mWindow->getChild("PaintTextureLayer1ImportButton"); PaintTextureMenu.push_back(mPaintTextureLayer1Button);
	mPaintTextureLayer1Window = (CEGUI::Window*)mWindow->getChild("PaintTextureLayer1Window"); PaintTextureMenu.push_back(mPaintTextureLayer1Window);
	TextureWindows.push_back(mPaintTextureLayer1Window);
	mPaintTextureLayer2RadioButton = (CEGUI::RadioButton*)mWindow->getChild("PaintTextureLayer2Radiobutton"); PaintTextureMenu.push_back(mPaintTextureLayer2RadioButton);
	mPaintTextureLayer2Button = (CEGUI::PushButton*)mWindow->getChild("PaintTextureLayer2ImportButton"); PaintTextureMenu.push_back(mPaintTextureLayer2Button);
	mPaintTextureLayer2Window = (CEGUI::Window*)mWindow->getChild("PaintTextureLayer2Window"); PaintTextureMenu.push_back(mPaintTextureLayer2Window);
	TextureWindows.push_back(mPaintTextureLayer2Window);
	mPaintTextureLayer3RadioButton = (CEGUI::RadioButton*)mWindow->getChild("PaintTextureLayer3Radiobutton"); PaintTextureMenu.push_back(mPaintTextureLayer3RadioButton);
	mPaintTextureLayer3Button = (CEGUI::PushButton*)mWindow->getChild("PaintTextureLayer3ImportButton"); PaintTextureMenu.push_back(mPaintTextureLayer3Button);
	mPaintTextureLayer3Window = (CEGUI::Window*)mWindow->getChild("PaintTextureLayer3Window"); PaintTextureMenu.push_back(mPaintTextureLayer3Window);
	TextureWindows.push_back(mPaintTextureLayer3Window);


	CEGUI::Renderer* mGUIRenderer = CEGUI::System::getSingleton().getRenderer();

	
	CEGUI::Texture* tex;
	CEGUI::Imageset* imageSet;
	
	String textName;
	for(int i=0; i<4; i++)
	{
		textName = "";
		char buffer[32];
		sprintf(buffer, "TextureNameLayer%i", i);

		mListener->getSceneManager()->getOption(buffer, &textName);
	
		tex = mGUIRenderer->createTexture(textName, "PLSM2");
		sprintf(buffer, "texture%i", i);
		imageSet = CEGUI::ImagesetManager::getSingleton().createImageset(buffer, tex);
		imageSet->setAutoScalingEnabled (true);
		imageSet->defineImage (buffer, CEGUI::Point(0, 0), CEGUI::Size(tex->getWidth(), tex->getHeight()), CEGUI::Point(0, 0));
		TextureWindows.at(i)->setProperty("Image", 
			"set:" + imageSet->getName() + " image:" + imageSet->getImage((CEGUI::utf8*)buffer).getName());
	}

	mPaintTextureLayer0RadioButton->subscribeEvent(CEGUI::RadioButton::EventMouseClick,CEGUI::Event::Subscriber(&TextureWindow::handleChangeTextureLayer, this));
	mPaintTextureLayer1RadioButton->subscribeEvent(CEGUI::RadioButton::EventMouseClick,CEGUI::Event::Subscriber(&TextureWindow::handleChangeTextureLayer, this));
	mPaintTextureLayer2RadioButton->subscribeEvent(CEGUI::RadioButton::EventMouseClick,CEGUI::Event::Subscriber(&TextureWindow::handleChangeTextureLayer, this));
	mPaintTextureLayer3RadioButton->subscribeEvent(CEGUI::RadioButton::EventMouseClick,CEGUI::Event::Subscriber(&TextureWindow::handleChangeTextureLayer, this));

	mPaintColorBrushSizeSlider->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,CEGUI::Event::Subscriber(&TextureWindow::doneChangingCursorSizeSlider, this));
	mPaintColorAlphaSlider->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,CEGUI::Event::Subscriber(&TextureWindow::doneChangingAlphaSlider, this));

	showCorrectMenu();

}
//------------------------------------------------------------------------------------------------
TextureWindow::~TextureWindow()
{

}
//------------------------------------------------------------------------------------------------
bool TextureWindow::handleTextureTypeChange(const CEGUI::EventArgs& e)
{
	const CEGUI::WindowEventArgs& windowEventArgs = static_cast<const CEGUI::WindowEventArgs&>(e);
    CEGUI::ListboxItem* item = static_cast<CEGUI::Combobox*>(windowEventArgs.window)->getSelectedItem();

    String CurrentTextureFormat;

	mListener->getSceneManager()->getOption("CurrentTextureFormat", &CurrentTextureFormat);
    String selectedItem;
	if(item->getText()=="InstantBase")
	{
	    selectedItem = "InstantBase";
	}
	else if(item->getText()=="Splatting")
	{
	    selectedItem = "Splatting";
	}
	else if(item->getText()=="Splatting2")
	{
	    selectedItem = "Splatting2";
    }
	else if(item->getText()=="Splatting3")
	{
	    selectedItem = "Splatting3";
	}
	else if(item->getText()=="Splatting4")
	{
	    selectedItem = "Splatting4";	
	}
	else if(item->getText()=="Splatting5")
	{
	    selectedItem = "Splatting5";
	}
	else if(item->getText()=="Splatting6")
	{
	    selectedItem = "Splatting6";
	}
	else if(item->getText()=="Splatting7")
	{
	    selectedItem = "Splatting7";
	}

    // load only if modified.
    if (selectedItem != CurrentTextureFormat)
    { 
        try {
			mListener->getSceneManager()->setOption("CurrentTextureFormat", &selectedItem);
			mListener->getSceneManager()->setOption("LoadMap", 0);
        } 
        catch(...)
        {
            // ignore but should create an info window in CEGUI
        }
    }
	return true;
}
//------------------------------------------------------------------------------------------------
bool TextureWindow::handleChangeTextureLayer(const CEGUI::EventArgs& e)
{
    unsigned int value;
	if(mPaintTextureLayer0RadioButton->isSelected())
	{
		value = 0;
	}
	else if(mPaintTextureLayer1RadioButton->isSelected())
	{
		value = 1;
	}
	else if(mPaintTextureLayer2RadioButton->isSelected())
	{
		value = 2;
	}
	else if(mPaintTextureLayer3RadioButton->isSelected())
	{
		value = 3;
	}    
    mListener->getSceneManager()->setOption("PaintChannel", &value);
	return true;
}
//------------------------------------------------------------------------------------------------
bool TextureWindow::handleTextureActionChange(const CEGUI::EventArgs& e)
{
	const CEGUI::WindowEventArgs& windowEventArgs = static_cast<const CEGUI::WindowEventArgs&>(e);
    CEGUI::ListboxItem* item = static_cast<CEGUI::Combobox*>(windowEventArgs.window)->getSelectedItem();

	if(item->getText()=="Paint Color")
	{
		mListener->setEditMode(EditPaintColorTerrain);
		showCorrectMenu();

		if(mListener->getCursor()!= NULL)
				mListener->getCursor()->setMaterial("PaintColorCircle");

	}
	else if(item->getText()=="Paint Alpha")
	{
		mListener->setEditMode(EditPaintAlphaTerrain);
		showCorrectMenu();
		
		if(mListener->getCursor()!= NULL)
				mListener->getCursor()->setMaterial("PaintTextureCircle");
	}
//    else if(item->getText()=="Paint Texture")
//	{
//		mListener->setEditMode(EditPaintAlphaTerrain);
//		showCorrectMenu();
//		
//		if(mListener->getCursor()!= NULL)
//				mListener->getCursor()->setMaterial("PaintTextureCircle");
//	}
	return true;
}
//------------------------------------------------------------------------------------------------
bool TextureWindow::handleColorChanged(const CEGUI::EventArgs& e)
{
// 	mPaintColorWindowStaticText->setImageColours(CEGUI::colour(
// 				mPaintColorRedSlider->getScrollPosition() / 255.0f,
// 				mPaintColorGreenSlider->getScrollPosition() / 255.0f,
// 				mPaintColorBlueSlider->getScrollPosition() / 255.0f));

	return true;
}
//------------------------------------------------------------------------------------------------
bool TextureWindow::handleAlphaSliderChanged(const CEGUI::EventArgs& e)
{
	Real amount = (Real)mPaintColorAlphaSlider->getScrollPosition();
	
	char buffer[32];
	sprintf(buffer, "Brush strength: %.2f", amount);

	mPaintColorAlphaWindow->setText(buffer);
		
	return true;
}
//------------------------------------------------------------------------------------------------
bool TextureWindow::doneChangingColorSlider(const CEGUI::EventArgs& e)
{
	ColourValue value=ColourValue(mPaintColorRedSlider->getScrollPosition() / 255.0f,
								  mPaintColorGreenSlider->getScrollPosition() / 255.0f,
								  mPaintColorBlueSlider->getScrollPosition() / 255.0f,
								  0.01);
	
	mListener->getSceneManager()->setOption("PaintColor", &value);

	return true;
}
//------------------------------------------------------------------------------------------------
bool TextureWindow::doneChangingAlphaSlider(const CEGUI::EventArgs& e)
{
	Real value = (Real)mPaintColorAlphaSlider->getScrollPosition();

	mListener->getSceneManager()->setOption("BrushStrength", &value);

	return true;
}
//------------------------------------------------------------------------------------------------
bool TextureWindow::handleCursorSizeChanged(const CEGUI::EventArgs& e)
{
	int amount = (int)mPaintColorBrushSizeSlider->getScrollPosition();
	

	char buffer[32];
	sprintf(buffer, "Brush size: %i", amount);

	mPaintColorBrushSizeWindow->setText(buffer);
		
	return true;
}
//------------------------------------------------------------------------------------------------
bool TextureWindow::doneChangingCursorSizeSlider(const CEGUI::EventArgs& e)
{
	const int size = (int)mPaintColorBrushSizeSlider->getScrollPosition();
	mListener->setBrushSize(size);
	return true;
}
//------------------------------------------------------------------------------------------------
bool TextureWindow::handleShowTextureWindow(const CEGUI::EventArgs& e)
{
	//Pick correct brushsize
	mListener->setBrushSize(mPaintColorBrushSizeSlider->getScrollPosition());

	if(mListener->getEditMode()==EditPaintColorTerrain)
	{
		if(mListener->getCursor()!= NULL)
			mListener->getCursor()->setMaterial("PaintColorCircle");

	}
	if(mListener->getEditMode()==EditPaintAlphaTerrain)
	{
		
		if(mListener->getCursor()!= NULL)
			mListener->getCursor()->setMaterial("PaintTextureCircle");
	}

	return true;
}
//------------------------------------------------------------------------------------------------
void TextureWindow::showCorrectMenu()
{
	if(mListener->getEditMode()==EditPaintColorTerrain)
	{
		for(uint i=0; i<PaintColorMenu.size(); i++)
		{
			PaintColorMenu.at(i)->enable();
			PaintColorMenu.at(i)->setVisible(true);
		}
		for(uint i=0; i<PaintTextureMenu.size(); i++)
		{
			PaintTextureMenu.at(i)->disable();
			PaintTextureMenu.at(i)->setVisible(false);
			
		}
	}
	else if(mListener->getEditMode()==EditPaintAlphaTerrain)
	{
		for(uint i=0; i<PaintColorMenu.size(); i++)
		{
			PaintColorMenu.at(i)->disable();
			PaintColorMenu.at(i)->setVisible(false);
		}
		for(uint i=0; i<PaintTextureMenu.size(); i++)
		{
			PaintTextureMenu.at(i)->enable();
			PaintTextureMenu.at(i)->setVisible(true);
			
		}
	}
	else
	{
		for(uint i=0; i<PaintColorMenu.size(); i++)
		{
			PaintColorMenu.at(i)->disable();
			PaintColorMenu.at(i)->setVisible(false);
		}
		for(uint i=0; i<PaintTextureMenu.size(); i++)
		{
			PaintTextureMenu.at(i)->disable();
			PaintTextureMenu.at(i)->setVisible(false);
			
		}
	}
}