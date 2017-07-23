#ifndef _H_MLLAB_FRAME_MANAGER_H
#define _H_MLLAB_FRAME_MANAGER_H

#include <Ogre.h>
#include <string>
#include <map>
#include <OIS/OIS.h>
#include <CEGUI/CEGUI.h>
#include "AppFrame.h"

using namespace Ogre;

class Application;

class FrameManager : public FrameListener, public OIS::MouseListener, public OIS::KeyListener
{
public:
	enum AppCameraType { APPCAM_SPHERICAL, APPCAM_FIRSTPERSON };

public:
	virtual ~FrameManager();
	FrameManager(Application* app);

public:
	static FrameManager& getSingleton();
	static FrameManager* getSingletonPtr();

private:
	FrameManager(const FrameManager& rhs) { }
	FrameManager& operator=(const FrameManager& rhs) { return *this; }

public:
	void onRightMouseDrag(const float& Xrel, const float& Yrel);

public:
	void addFrame(const std::string& frameName, AppFrame* frame);
	AppFrame* getFrame(const std::string& frameName);
	bool isFramePresent(const std::string& frameName) const;

public:
	void unload();

protected:
	SphericalCamera mSphericalCamera;
	FirstPersonCamera mFirstPersonCamera;
	AppCameraType mAppCamType;
public:
	void setCameraType(AppCameraType type);
	const AppCameraType& getCameraType() const { return mAppCamType; }
	void resetCamera();
	void setCameraPOI(const Vector3& pos);
	void updateCamera(const Real& dt);
	void updateCamera();

public:
	virtual bool keyPressed(const OIS::KeyEvent& evt);
	virtual bool keyReleased(const OIS::KeyEvent& evt);
	virtual bool mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id);
	virtual bool mouseReleased(const OIS::MouseEvent& evt, OIS::MouseButtonID id);
	virtual bool mouseMoved(const OIS::MouseEvent& evt);
public:
	virtual bool frameStarted(const FrameEvent& evt);

protected:
	std::map<std::string, AppFrame*> mFrames;
	static FrameManager* mSingleton;
	Application* mApp;

public:
	void changeFrame(AppFrame* frame);
	void changeFrame(const std::string& frameName);
	void reverseFrame();
	void setCurrentFrame(AppFrame* frame);
	void setCurrentFrame(const std::string& frameName);

public:
	void windowResized(RenderWindow* window);

private:
	bool mIsFrameChangeNotified;

public:
	void open();
	void save();
	void saveAs();
	void quit();

private:
	OIS::Keyboard* mKeyboard;
	OIS::Mouse* mMouse;

private:
	AppFrame* mCurrentFrame;
	AppFrame* mPrevFrame;
};
#endif