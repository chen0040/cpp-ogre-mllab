#include "FrameManager.h"
#include "../GameEngine/Application.h"
#include "../SceneAssets/HydraxManager.h"

FrameManager* FrameManager::mSingleton=NULL;

FrameManager::FrameManager(Application* app)
: mApp(app)
, mPrevFrame(NULL)
, mCurrentFrame(NULL)
, mKeyboard(app->getKeyboard())
, mMouse(app->getMouse())
, mIsFrameChangeNotified(false)
, mAppCamType(APPCAM_SPHERICAL)
{
	if(mSingleton==NULL)
	{
		mSingleton=this;
	}
	else
	{
		throw Ogre::Exception(52, "Singleton Pattern violated!", "FrameManager::FrameManager()");
	}

	mKeyboard->setEventCallback(this);
	mMouse->setEventCallback(this);

	Camera* cam=app->getCamera();
	mFirstPersonCamera.setActualCamera(cam);
	mSphericalCamera.setActualCamera(cam);
}

void FrameManager::windowResized(RenderWindow* window)
{
	mCurrentFrame->windowResized(window);
}

FrameManager::~FrameManager()
{
	std::map<std::string, AppFrame*>::iterator iter=mFrames.begin();
	std::map<std::string, AppFrame*>::iterator iter_end=mFrames.end();
	for(; iter != iter_end; ++iter)
	{
		delete iter->second;
	}
	mFrames.clear();

	mCurrentFrame=NULL;
	mPrevFrame=NULL;
}

void FrameManager::addFrame(const std::string& frameName, AppFrame* frame)
{
	if(isFramePresent(frameName))
	{
		std::ostringstream oss;
		oss << "isFramePresent(" << frameName << ")==true";
		throw Ogre::Exception(42, oss.str().c_str(), "FrameManager::createFrame(const std::string& frameType, const std::string& frameName)");
	}

	mFrames[frameName]=frame;
}

AppFrame* FrameManager::getFrame(const std::string& frameName)
{
	std::map<std::string, AppFrame*>::iterator fnd=mFrames.find(frameName);
	if(fnd == mFrames.end())
	{
		throw Ogre::Exception(42, "fnd == mFrames.end()", "FrameManager::getFrame(const std::string& frameName)");
	}
	return fnd->second;
}

void FrameManager::unload()
{
	std::map<std::string, AppFrame*>::iterator fiter=mFrames.begin();
	std::map<std::string, AppFrame*>::iterator fiter_end=mFrames.end();
	for(; fiter != fiter_end; ++fiter)
	{
		(fiter->second)->unload();
	}
}

bool FrameManager::isFramePresent(const std::string& frameName) const
{
	std::map<std::string, AppFrame*>::const_iterator fnd=mFrames.find(frameName);
	if(fnd == mFrames.end())
	{
		return false;
	}
	return true;
}

FrameManager& FrameManager::getSingleton()
{
	return *mSingleton;
}

FrameManager* FrameManager::getSingletonPtr()
{
	return mSingleton;
}

void FrameManager::updateCamera(const Real& dt)
{
	if(mAppCamType==APPCAM_SPHERICAL)
	{
		mSphericalCamera.frameStarted(
		mKeyboard->isKeyDown(OIS::KC_LEFT), 
		mKeyboard->isKeyDown(OIS::KC_RIGHT), 
		mKeyboard->isKeyDown(OIS::KC_UP), 
		mKeyboard->isKeyDown(OIS::KC_DOWN), 
		mKeyboard->isKeyDown(OIS::KC_A), 
		mKeyboard->isKeyDown(OIS::KC_S), 
		dt);
	}
	else if(mAppCamType==APPCAM_FIRSTPERSON)
	{
		mFirstPersonCamera.frameStarted(
		mKeyboard->isKeyDown(OIS::KC_LEFT), 
		mKeyboard->isKeyDown(OIS::KC_RIGHT), 
		mKeyboard->isKeyDown(OIS::KC_UP), 
		mKeyboard->isKeyDown(OIS::KC_DOWN), 
		mKeyboard->isKeyDown(OIS::KC_A), 
		mKeyboard->isKeyDown(OIS::KC_S), 
		dt);
	}
}

void FrameManager::updateCamera()
{
	if(mAppCamType==APPCAM_SPHERICAL)
	{
		mSphericalCamera.update();
	}
	else if(mAppCamType==APPCAM_FIRSTPERSON)
	{
		mFirstPersonCamera.update();
	}
}

void FrameManager::setCameraType(AppCameraType type)
{
	 mAppCamType=type; 
	 if(mAppCamType==APPCAM_SPHERICAL)
	 {
		mSphericalCamera.update();
	 }
	 else if(mAppCamType==APPCAM_FIRSTPERSON)
	 {
		 mFirstPersonCamera.update();
	 }
}

bool FrameManager::keyPressed(const OIS::KeyEvent& evt)
{
	return mCurrentFrame->keyPressed(evt);
}

bool FrameManager::keyReleased(const OIS::KeyEvent& evt)
{
	return mCurrentFrame->keyReleased(evt);
}

bool FrameManager::mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
{
	return mCurrentFrame->mousePressed(evt, id);
}

bool FrameManager::mouseReleased(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
{
	return mCurrentFrame->mouseReleased(evt, id);
}

bool FrameManager::mouseMoved(const OIS::MouseEvent& evt)
{
	return mCurrentFrame->mouseMoved(evt);
}

void FrameManager::setCurrentFrame(const std::string& frameName)
{
	setCurrentFrame(getFrame(frameName));
}

void FrameManager::setCurrentFrame(AppFrame* frame)
{
	if(mCurrentFrame != frame)
	{
		changeFrame(frame);
	}
}

bool FrameManager::frameStarted(const FrameEvent& evt)
{
	HydraxManager::getSingletonPtr()->update(evt.timeSinceLastFrame);

	mKeyboard->capture();
	mMouse->capture();

	if(mIsFrameChangeNotified)
	{
		if(mPrevFrame != NULL)
		{
			mPrevFrame->frameExited();
		}
		
		mCurrentFrame->frameEntered();

		mIsFrameChangeNotified=false;
	}

	return mCurrentFrame->frameStarted(evt);
}

void FrameManager::open()
{
	mCurrentFrame->open();
}

void FrameManager::save()
{
	mCurrentFrame->save();
}

void FrameManager::saveAs()
{
	mCurrentFrame->saveAs();
}

void FrameManager::quit()
{
	mCurrentFrame->quit();
}

void FrameManager::changeFrame(const std::string& frameName)
{
	changeFrame(getFrame(frameName));
}

void FrameManager::changeFrame(AppFrame* frame)
{
	mIsFrameChangeNotified=true;

	AppFrame* tf=mCurrentFrame;
	mCurrentFrame=frame;
	mPrevFrame=tf;
}

void FrameManager::reverseFrame()
{
	if(mPrevFrame != NULL)
	{
		changeFrame(mPrevFrame);
	}
}

void FrameManager::resetCamera()
{
	if(mAppCamType==APPCAM_SPHERICAL)
	{
		mSphericalCamera.reset();
	}
	else if(mAppCamType==APPCAM_FIRSTPERSON)
	{
		mFirstPersonCamera.reset();
	}
}

void FrameManager::setCameraPOI(const Vector3& pos)
{
	if(mAppCamType==APPCAM_SPHERICAL)
	{
		mSphericalCamera.setFocus(pos); //tm->getHeight(tX, tZ)
	}
	else if(mAppCamType==APPCAM_FIRSTPERSON)
	{
		mFirstPersonCamera.setPosition(pos);
	}
}

void FrameManager::onRightMouseDrag(const float& Xrel, const float& Yrel)
{
	if(mAppCamType==APPCAM_SPHERICAL)
	{
		mSphericalCamera.onMouseDrag(Xrel, Yrel);
	}
	else if(mAppCamType==APPCAM_FIRSTPERSON)
	{
		mFirstPersonCamera.onMouseDrag(Xrel, Yrel);
	}
}