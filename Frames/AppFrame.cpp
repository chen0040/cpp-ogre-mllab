#include "AppFrame.h"
#include "../GameEngine/Application.h"
#include "../OSEnvironment/OSEnvironment.h"

AppFrame::AppFrame(Application* app, const std::string& frameName)
: mApp(app)
, mSceneMgr(app->getSceneMgr())
, mGUIMgr(app->getGUIMgr())
, mKeyboard(app->getKeyboard())
, mMouse(app->getMouse())
, mFrameName(frameName)
, mLeftButtonDown(false)
, mRightButtonDown(false)
, mContinue(true)
, mCurrState(UNKNOWN)
, mPrevState(UNKNOWN)
{
	
}

AppFrame::AppFrameState AppFrame::getFrameState() const
{
	return UNKNOWN;
}

std::string AppFrame::getUIId(const std::string& localId) const
{
	return mFrameName+std::string("/")+localId;
}

bool AppFrame::onFrameSelected(const CEGUI::EventArgs& evt)
{
	mApp->setCurrentFrame(this->getName());

	return true;
}

bool AppFrame::frameEntered()
{
	mLeftButtonDown=false;
	mRightButtonDown=false;

	//initialize CEGUI::MouseCursor to align with OIS::Mouse
	resetMouse();

	subscribeEvents();

	FrameManager::getSingletonPtr()->updateCamera();

	return true;
}
	
bool AppFrame::frameExited()
{
	mLeftButtonDown=false;
	mRightButtonDown=false;

	unsubscribeEvents();

	return true;
}

void AppFrame::windowResized(RenderWindow* window)
{
	//resetMouse();
}

AppFrame::~AppFrame()
{
	
}

bool AppFrame::isKeyDown(OIS::KeyCode keyCode) const
{
	return mKeyboard->isKeyDown(keyCode);
}

void AppFrame::updateState()
{
	AppFrameState state=getFrameState();
	if(mCurrState != state)
	{
		mPrevState=mCurrState;
		mCurrState=state;
		onStateChanged(mPrevState, mCurrState);
	}
}

bool AppFrame::onStateChanged(AppFrameState prevState, AppFrameState currState)
{
	return true;
}

bool AppFrame::frameStarted(const FrameEvent &evt)
{
	updateState();

	return mContinue;
}

bool AppFrame::keyPressed(const OIS::KeyEvent& evt)
{
	switch(evt.key)
	{
	case OIS::KC_ESCAPE:
		mContinue=false;
		break;
	default:
		break;
	}

	CEGUI::System::getSingletonPtr()->injectChar(evt.text);
	return CEGUI::System::getSingletonPtr()->injectKeyDown(evt.key);
}

void AppFrame::resetMouse()
{
	const OIS::MouseState& ms=mMouse->getMouseState();

	CEGUI::Point& pos=CEGUI::MouseCursor::getSingletonPtr()->getPosition();

	float offsetX=ms.X.abs-pos.d_x;
	float offsetY=ms.Y.abs-pos.d_y;
	CEGUI::System::getSingletonPtr()->injectMouseMove(offsetX, offsetY);

	NaviLibrary::NaviManager* nm=NaviLibrary::NaviManager::GetPointer();
	nm->injectMouseMove(offsetX, offsetY);

}

void AppFrame::quit()
{
	mContinue=false;
}

void AppFrame::open()
{

}

void AppFrame::save()
{

}

void AppFrame::saveAs()
{
	save();
}

bool AppFrame::keyReleased(const OIS::KeyEvent& evt)
{
	CEGUI::System::getSingletonPtr()->injectChar(evt.text);
	return CEGUI::System::getSingletonPtr()->injectKeyUp(evt.key);
}

bool AppFrame::mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
{
	if(!isMouseWithinWindow())
	{
		return true;
	}
	
	if(NaviLibrary::NaviManager::GetPointer()->injectMouseDown(id))
	{
		return true;
	}

	if(CEGUI::System::getSingletonPtr()->injectMouseButtonDown(convertButton(id)))
	{		
		return true;
	}

	if(id==OIS::MB_Left)
	{
		mLeftButtonDown=true;
	}
	else if(id==OIS::MB_Right)
	{
		mRightButtonDown=true;
	}

	return false;
}

bool AppFrame::mouseReleased(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
{
	if(!isMouseWithinWindow())
	{
		return true;
	}

	if(NaviLibrary::NaviManager::GetPointer()->injectMouseUp(id))
	{
		return true;
	}

	if(CEGUI::System::getSingletonPtr()->injectMouseButtonUp(convertButton(id)))
	{
		return true;
	}

	if(id==OIS::MB_Left)
	{
		mLeftButtonDown=false;
	}
	else if(id==OIS::MB_Right)
	{
		mRightButtonDown=false;
	}

	return false;
}
	
bool AppFrame::mouseMoved(const OIS::MouseEvent& evt)
{
	int xPos=evt.state.X.abs;
	int yPos=evt.state.Y.abs;

	if(evt.state.Z.rel != 0)
	{
		NaviLibrary::NaviManager::GetPointer()->injectMouseWheel(evt.state.Z.rel);
		CEGUI::System::getSingletonPtr()->injectMouseWheelChange(evt.state.Z.rel);
	}

	switchWindowMouse();

	NaviLibrary::NaviManager::GetPointer()->injectMouseMove(xPos, yPos);

	//Xianshun: this is where i finally solve the problem with mouse position for foreground and nonexclusive mouse :D
	return CEGUI::System::getSingletonPtr()->injectMousePosition(xPos, yPos); 

	//Xianshun: the following commented line causes the problem with the mouse position for foreground and nonexclusive mouse 
	//return CEGUI::System::getSingletonPtr()->injectMouseMove(evt.state.X.rel, evt.state.Y.rel); 
}

bool AppFrame::isMouseWithinWindow() const
{
	return Application::getSingletonPtr()->isMouseWithinWindow();
}

void AppFrame::switchWindowMouse()
{
	Application* app=Application::getSingletonPtr();
	if(app->isMouseWithinWindow())
	{
		app->showWindowMouse(false);
	}
	else
	{
		app->showWindowMouse(true);
	}
}

