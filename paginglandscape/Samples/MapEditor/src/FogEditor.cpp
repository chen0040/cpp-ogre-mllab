
#include <CEGUI/Cegui.h>
#include <OgreCEGUIRenderer.h>
#include "OgreCEGUIResourceProvider.h"

#include "FogEditor.h"
//------------------------------------------------------------------------------------------------
FogEditor::FogEditor(FrameListener* listener)
{
	//Random position for the window
	Real posX = Math::RangeRandom(0, 800); 
    Real posY = Math::RangeRandom(0, 500); 

	mFogEnabled=false;
	mFogDensity=0.0001;				
	mFogStart=5000;
	mFogEnd=10000;

	mListener=static_cast<MapEditorListener*>(listener);

	mWindow = CEGUI::WindowManager::getSingleton().loadWindowLayout((CEGUI::utf8*)"MapEditorFogSettingsDialog.layout");
	mWindow->deactivate();
	mWindow->hide();

	mRedSlider = (CEGUI::Scrollbar*)mWindow->getChild("RedSlider");
	mGreenSlider = (CEGUI::Scrollbar*)mWindow->getChild("GreenSlider");
	mBlueSlider = (CEGUI::Scrollbar*)mWindow->getChild("BlueSlider");

	mOkButton = (CEGUI::PushButton*)mWindow->getChild("FogOkButton");
	mCancelButton = (CEGUI::PushButton*)mWindow->getChild("FogCancelButton");

	mFogEnabledCheckbox = (CEGUI::Checkbox*)mWindow->getChild("EnableFogCheckbox");
	mFogEnabledCheckbox->setSelected(mFogEnabled);

	mDensityEditbox = (CEGUI::Editbox*)mWindow->getChild("DensityEditbox");
	mStartEditbox = (CEGUI::Editbox*)mWindow->getChild("StartEditbox");
	mEndEditbox = (CEGUI::Editbox*)mWindow->getChild("EndEditbox");

	mPreview = (CEGUI::Window*)mWindow->getChild("FogColorWindow");
	
	mTypeOfFogCombobox = (CEGUI::Combobox*)mWindow->getChild("TypeOfFogDropdownMenu");
    CEGUI::ListboxTextItem* item = new CEGUI::ListboxTextItem((CEGUI::utf8*)"Linear", 0);
	item->setTextColours(CEGUI::colour(0.5,0.5,0.5));//Change color of the listbox items (color isn't right in WindowsLook mode)
    mTypeOfFogCombobox->addItem(item);
    item = new CEGUI::ListboxTextItem((CEGUI::utf8*)"Exponential", 1);
	item->setTextColours(CEGUI::colour(0.5,0.5,0.5));//Change color of the listbox items (color isn't right in WindowsLook mode)
    mTypeOfFogCombobox->addItem(item);
    item = new CEGUI::ListboxTextItem((CEGUI::utf8*)"Exponential 2", 2);
	item->setTextColours(CEGUI::colour(0.5,0.5,0.5));//Change color of the listbox items (color isn't right in WindowsLook mode)
    mTypeOfFogCombobox->addItem(item);

	mRedSlider->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,CEGUI::Event::Subscriber(&FogEditor::handleColorChanged, this));
	mGreenSlider->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,CEGUI::Event::Subscriber(&FogEditor::handleColorChanged, this));
	mBlueSlider->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,CEGUI::Event::Subscriber(&FogEditor::handleColorChanged, this));
	mRedSlider->setScrollPosition(0.0);
	mGreenSlider->setScrollPosition(0.0);
	mBlueSlider->setScrollPosition(0.0);

	mTypeOfFogCombobox->subscribeEvent(CEGUI::Combobox::EventListSelectionAccepted, CEGUI::Event::Subscriber(&FogEditor::handleFogTypeChanged, this));
	mOkButton->subscribeEvent(CEGUI::PushButton::EventMouseClick, CEGUI::Event::Subscriber(&FogEditor::handleOkClicked, this));
	mCancelButton->subscribeEvent(CEGUI::PushButton::EventMouseClick, CEGUI::Event::Subscriber(&FogEditor::handleCancelClicked, this));

	mWindow->setPosition(CEGUI::UVector2(CEGUI::UDim(1.0f, posX), CEGUI::UDim(1.0f, posY)));
}
//------------------------------------------------------------------------------------------------
FogEditor::~FogEditor(void)
{
}
//------------------------------------------------------------------------------------------------
bool FogEditor::handleColorChanged(const CEGUI::EventArgs& e)
{
	//mPreview->setColours(CEGUI::colour(
	//mRedSlider->getScrollPosition() / 255.0f,
 	//mGreenSlider->getScrollPosition() / 255.0f,
 	//mBlueSlider->getScrollPosition() / 255.0f));

	return true;
}
//------------------------------------------------------------------------------------------------
bool FogEditor::handleFogTypeChanged(const CEGUI::EventArgs& e)
{
	const CEGUI::WindowEventArgs& windowEventArgs = static_cast<const CEGUI::WindowEventArgs&>(e);
    CEGUI::ListboxItem* item = static_cast<CEGUI::Combobox*>(windowEventArgs.window)->getSelectedItem();

	if(item->getText()=="Exponential") //Lower terrain
	{
		mTypeOfFog=FOG_EXPONENTIAL;
		mDensityEditbox->enable();
		char buffer[16];
		sprintf(buffer, "%f", mFogDensity);
		mDensityEditbox->setText(buffer);

		mStartEditbox->disable();
		mStartEditbox->setText("");

		mEndEditbox->disable();
		mEndEditbox->setText("");

	}
	else if(item->getText()=="Exponential 2")
	{
		mTypeOfFog=FOG_EXPONENTIAL2;
		mDensityEditbox->enable();

		char buffer[16];
		sprintf(buffer, "%f", mFogDensity);
		mDensityEditbox->setText(buffer);

		mStartEditbox->disable();
		mStartEditbox->setText("");

		mEndEditbox->disable();
		mEndEditbox->setText("");
	}	
	else if(item->getText()=="Linear")
	{
		mTypeOfFog=FOG_LIN;
		mDensityEditbox->disable();
		mDensityEditbox->setText("");

		char buffer[16];
		mStartEditbox->enable();
		sprintf(buffer, "%f", mFogStart);
		mStartEditbox->setText(buffer);

		mEndEditbox->enable();
		sprintf(buffer, "%f", mFogEnd);
		mEndEditbox->setText(buffer);
	}


	return true;
}
//------------------------------------------------------------------------------------------------
bool FogEditor::handleOkClicked(const CEGUI::EventArgs& e)
{
	hideWindow();
	
	mFogEnabled = mFogEnabledCheckbox->isSelected();
	
	if(mFogEnabled==true)
	{
		if(mTypeOfFog==FOG_EXPONENTIAL) //Lower terrain
		{
			ColourValue fadeColour = ColourValue( mRedSlider->getScrollPosition() / 255.0f, mGreenSlider->getScrollPosition() / 255.0f, mBlueSlider->getScrollPosition() / 255.0f );
			mListener->getSceneManager()->setFog( FOG_EXP, fadeColour, mFogDensity);	
		}
		else if(mTypeOfFog==FOG_EXPONENTIAL2)
		{
			ColourValue fadeColour = ColourValue( mRedSlider->getScrollPosition() / 255.0f, mGreenSlider->getScrollPosition() / 255.0f, mBlueSlider->getScrollPosition() / 255.0f );
			mListener->getSceneManager()->setFog( FOG_EXP2, fadeColour, mFogDensity);	
		}
		else if(mTypeOfFog==FOG_LIN)
		{
			ColourValue fadeColour = ColourValue( mRedSlider->getScrollPosition() / 255.0f, mGreenSlider->getScrollPosition() / 255.0f, mBlueSlider->getScrollPosition() / 255.0f );
			mListener->getSceneManager()->setFog( FOG_LINEAR, fadeColour, mFogStart, mFogEnd);	
		}
	}
	else if(mFogEnabled==false)
	{
		//setFog without parameters uses default parameters (FOG DISABLED);
		mListener->getSceneManager()->setFog();
	}

	return true;
}
//------------------------------------------------------------------------------------------------
bool FogEditor::handleCancelClicked(const CEGUI::EventArgs& e)
{
	hideWindow();
	return true;
}
//------------------------------------------------------------------------------------------------
void FogEditor::showWindow()
{
	mWindow->activate(); 
	mWindow->show(); 
}
//------------------------------------------------------------------------------------------------	
void FogEditor::hideWindow() 
{ 
	mWindow->deactivate(); 
	mWindow->hide(); 
}

