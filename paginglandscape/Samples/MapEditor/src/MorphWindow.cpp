
#include <CEGUI/Cegui.h>
#include <OgreCEGUIRenderer.h>
#include "OgreCEGUIResourceProvider.h"

#include "MapEditorListener.h"
#include "MorphWindow.h"

#define PI 3.14159265f
#define DEG2RAD(x) (x * (PI / 180.0f))
#define RAD2DEG(x) (x * (180.0f / PI))

//------------------------------------------------------------------------------------------------
MorphWindow::MorphWindow(FrameListener* listener)
{
	mListener=static_cast<MapEditorListener*>(listener);

	fogEditor=NULL;

	mWindow = CEGUI::WindowManager::getSingleton().loadWindowLayout((CEGUI::utf8*)"MapEditorMorphWindow.layout");
	mWindow->subscribeEvent(CEGUI::Window::EventRenderingStarted,CEGUI::Event::Subscriber(&MorphWindow::handleShowMorphWindow, this));

	mCursorType = NOTHING;

	mCursorSizeSlider = (CEGUI::Scrollbar*)mWindow->getChild("CursorSizeSlider");
	mCursorStrengthSlider = (CEGUI::Scrollbar*)mWindow->getChild("CursorStrengthSlider");
	mFogSettingsButton = (CEGUI::PushButton*)mWindow->getChild("FogButton");
	mCursorSizeWindow = (CEGUI::Window*)mWindow->getChild("WindowSize");
	mCursorStrengthWindow = (CEGUI::Window*)mWindow->getChild("WindowStrength");
	mCursorTypeCombobox = (CEGUI::Combobox*)mWindow->getChild("MorphTypeList");
    CEGUI::ListboxTextItem* item = new CEGUI::ListboxTextItem((CEGUI::utf8*)"Raise", 0);
	item->setTextColours(CEGUI::colour(0.5,0.5,0.5));//Change color of the listbox items (color isn't right in WindowsLook mode)
    mCursorTypeCombobox->addItem(item);
    item = new CEGUI::ListboxTextItem((CEGUI::utf8*)"Lower", 1);
	item->setTextColours(CEGUI::colour(0.5,0.5,0.5));//Change color of the listbox items (color isn't right in WindowsLook mode)
    mCursorTypeCombobox->addItem(item);
    item = new CEGUI::ListboxTextItem((CEGUI::utf8*)"Flatten", 2);
	item->setTextColours(CEGUI::colour(0.5,0.5,0.5));//Change color of the listbox items (color isn't right in WindowsLook mode)
    mCursorTypeCombobox->addItem(item);
    item = new CEGUI::ListboxTextItem((CEGUI::utf8*)"Smooth", 3);
	item->setTextColours(CEGUI::colour(0.5,0.5,0.5));//Change color of the listbox items (color isn't right in WindowsLook mode)
    mCursorTypeCombobox->addItem(item);

	mCursorTypeCombobox->subscribeEvent(CEGUI::Combobox::EventListSelectionAccepted, CEGUI::Event::Subscriber(&MorphWindow::handleMorph, this));

	mCursorSizeSlider->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,CEGUI::Event::Subscriber(&MorphWindow::handleCursorSizeChanged, this));
	mCursorStrengthSlider->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged,CEGUI::Event::Subscriber(&MorphWindow::handleCursorStrengthChanged, this));
	
	//When the user stops influencing the slider, this event is fired...
	mCursorSizeSlider->subscribeEvent(CEGUI::Scrollbar::EventThumbTrackEnded,CEGUI::Event::Subscriber(&MorphWindow::doneChangingCursorSizeSlider, this));
	mCursorStrengthSlider->subscribeEvent(CEGUI::Scrollbar::EventThumbTrackEnded,CEGUI::Event::Subscriber(&MorphWindow::doneChangingCursorStrengthSlider, this));
	
	mFogSettingsButton->subscribeEvent(CEGUI::PushButton::EventClicked,CEGUI::Event::Subscriber(&MorphWindow::handleFogButtonClicked, this));

	char buffer[32];

	sprintf(buffer, "Brush size: %i", 5);
	mCursorSizeWindow->setText(buffer);
	mCursorSizeSlider->setScrollPosition(5);

	sprintf(buffer, "Brush strength: %d", 0.1f);
	mCursorStrengthWindow->setText(buffer);
	mCursorStrengthSlider->setScrollPosition(1);

	//Init fog-editor
	fogEditor = new FogEditor(listener);
	CEGUI::WindowManager::getSingleton().getWindow("MainWindow")->addChildWindow(fogEditor->getWindow());
}
//------------------------------------------------------------------------------------------------
MorphWindow::~MorphWindow()
{
	if(fogEditor!=NULL)
		delete fogEditor;

	//static_cast<MapEditorListener*>(mListener)->setMorphMode(false);
}
//------------------------------------------------------------------------------------------------
bool MorphWindow::handleMorph(const CEGUI::EventArgs& e)
{
	/*RaySceneQuery* query = static_cast<MapEditorListener*>(mListener)->getCursorRay();
	Ray pickRay = static_cast<MapEditorListener*>(mListener)->getSceneManager()->getCamera("PlayerCam")->getCameraToViewportRay(0.5, 0.5);
	query->setRay (pickRay);
	//query->setQueryMask (RSQ_FirstTerrain); //PLSM2 only
	mRayQuery->setQueryTypeMask(Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
	mRayQuery->setWorldFragmentType(SceneQuery::WFT_SINGLE_INTERSECTION); 
	
	RaySceneQueryResult& qryResult = query->execute();
	RaySceneQueryResult::iterator it = qryResult.begin();
	if (it != qryResult.end() && it->worldFragment)
	{
		static_cast<MapEditorListener*>(mListener)->mCursorPos = it->worldFragment->singleIntersection;
	}*/

	const CEGUI::WindowEventArgs& windowEventArgs = static_cast<const CEGUI::WindowEventArgs&>(e);
    CEGUI::ListboxItem* item = static_cast<CEGUI::Combobox*>(windowEventArgs.window)->getSelectedItem();

	if(item->getText()=="Lower") //Lower terrain
	{
	    mListener->setEditMode(EditDeformTerrain);
		mCursorType = LOWER;
		doneChangingCursorStrengthSlider(e);
	}
	else if(item->getText()=="Raise")
	{
        mListener->setEditMode(EditDeformTerrain);
		mCursorType = RAISE;
		doneChangingCursorStrengthSlider(e);
	}
    /*else if(item->getText()=="PaintAlpha")
	{
        mListener->setEditMode(EditPaintAlphaTerrain);
		mCursorType = PAINT;
	}
    else if(item->getText()=="PaintColor")
	{
        mListener->setEditMode(EditPaintColorTerrain);
		mCursorType = PAINT;
	}*/
	else
	{
		mListener->setEditMode(EditNothing);
	}
	

	return true;
}
//------------------------------------------------------------------------------------------------
bool MorphWindow::handleCloseWindow(const CEGUI::EventArgs& e)
{
	mListener->setEditMode(EditNothing);
	
	return true;

}
//------------------------------------------------------------------------------------------------
bool MorphWindow::handleCursorSizeChanged(const CEGUI::EventArgs& e)
{
	int amount = (int)mCursorSizeSlider->getScrollPosition();
	

	char buffer[32];
	sprintf(buffer, "Brush size: %i", amount);

	mCursorSizeWindow->setText(buffer);
		
	return true;
}
//------------------------------------------------------------------------------------------------
bool MorphWindow::doneChangingCursorSizeSlider(const CEGUI::EventArgs& e)
{
	const int size = (int)mCursorSizeSlider->getScrollPosition();
	mListener->setBrushSize(size);
	return true;
}
//------------------------------------------------------------------------------------------------
bool MorphWindow::handleCursorStrengthChanged(const CEGUI::EventArgs& e)
{
	const float amount = (float)mCursorStrengthSlider->getScrollPosition()/190;

	char buffer[32];
	sprintf(buffer, "Brush str: %.2f", amount);

	mCursorStrengthWindow->setText(buffer);
		
	return true;
}
//------------------------------------------------------------------------------------------------
bool MorphWindow::doneChangingCursorStrengthSlider(const CEGUI::EventArgs& e)
{
	float scale = (float)mCursorStrengthSlider->getScrollPosition()/190;
	mListener->setBrushStrength((float)scale);

//	handleMorph(e);
    switch (mCursorType)
    {
    case LOWER:
		scale = -scale;
		mListener->getSceneManager()->setOption("BrushScale", &scale);
        break;
    case RAISE:
		mListener->getSceneManager()->setOption("BrushScale", &scale);
        break;
    default :
        break;
    }

	return true;
}
//------------------------------------------------------------------------------------------------
bool MorphWindow::handleFogButtonClicked(const CEGUI::EventArgs& e)
{
	fogEditor->addListener(mListener);
	fogEditor->showWindow();

	return true;
}

//------------------------------------------------------------------------------------------------
bool MorphWindow::handleShowMorphWindow(const CEGUI::EventArgs& e)
{
	//Pick correct brushsize
	mListener->setBrushSize((int)mCursorSizeSlider->getScrollPosition());

	if(mListener->getCursor()!= NULL)
		mListener->getCursor()->setMaterial("MorphCircle");

	return true;
}
