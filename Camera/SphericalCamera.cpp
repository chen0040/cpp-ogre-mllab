#include "SphericalCamera.h"
#include <sstream>

SphericalCamera::SphericalCamera()
: mCameraRotateSpeed(15.0f)
, mInitCamPitchValue(-10.0f) //-14.83f
, mInitCamYawValue(-57.0698f)
, mMinCamPitchValue(-90.0f)
, mMaxCamPitchValue(-10.0f)
, mMinCamRadius(100)
, mMaxCamRadius(1200)
, mInitCamRadius(600)
, mCameraZoomSpeed(30)
{
	mCamPitchValue=mInitCamPitchValue;
	mCamYawValue=mInitCamYawValue;
	mCamRadius=mInitCamRadius;

	mCamNodePosition=Vector3(750, 0, 750);
}

SphericalCamera::~SphericalCamera()
{

}

void SphericalCamera::update()
{
	mCamera->getParentSceneNode()->setPosition(mCamNodePosition);

	mCamera->setPosition(0.0f,150.0f,0.0f);
    mCamera->setOrientation(Ogre::Quaternion::IDENTITY);
    mCamera->yaw(Ogre::Degree(mCamYawValue));
    mCamera->pitch(Ogre::Degree(mCamPitchValue));
    mCamera->moveRelative(Ogre::Vector3(0.0f,0.0f,mCamRadius));
}

bool SphericalCamera::frameStarted(bool rotateLeft, bool rotateRight, bool rotateUp, bool rotateDown, bool zoomIn, bool zoomOut, const Real& dt)
{
	if(!(rotateLeft || rotateRight || rotateUp || rotateDown || zoomIn || zoomOut))
	{
		return true;
	}

	if(rotateLeft)
	{
		mCamYawValue-=dt*mCameraRotateSpeed;
	}
	else if(rotateRight)
	{
		mCamYawValue+=dt*mCameraRotateSpeed;
	}

	if(rotateUp)
	{
		if(mCamPitchValue > mMinCamPitchValue)
		{
			mCamPitchValue-=dt*mCameraRotateSpeed;
		}
		else
		{
			mCamPitchValue=mMinCamPitchValue;
		}
	}
	else if(rotateDown)
	{
		if(mCamPitchValue < mMaxCamPitchValue)
		{
			mCamPitchValue+=dt*mCameraRotateSpeed;
		}
		else
		{
			mCamPitchValue=mMaxCamPitchValue;
		}
	}

	if(zoomIn)
	{
		if(mCamRadius > mMinCamRadius)
		{
			mCamRadius-=dt*mCameraZoomSpeed;
		}
		else
		{
			mCamRadius=mMinCamRadius;
		}
	}
	else if(zoomOut)
	{
		if(mCamRadius < mMaxCamRadius)
		{
			mCamRadius+=dt*mCameraZoomSpeed;
		}
		else
		{
			mCamRadius=mMaxCamRadius;
		}
	}

	mCamera->setPosition(0.0f,150.0f,0.0f);
    mCamera->setOrientation(Ogre::Quaternion::IDENTITY);
    mCamera->yaw(Ogre::Degree(mCamYawValue));
    mCamera->pitch(Ogre::Degree(mCamPitchValue));
    mCamera->moveRelative(Ogre::Vector3(0.0f,0.0f,mCamRadius));

	return true;
}

void SphericalCamera::setActualCamera(Camera* cam)
{
	mCamera=cam;
}

void SphericalCamera::reset()
{
	mCamNodePosition=Vector3(750, 0, 750);

	mCamPitchValue=mInitCamPitchValue;
	mCamYawValue=mInitCamYawValue;
	mCamRadius=mInitCamRadius;

	mCamera->getParentSceneNode()->setPosition(mCamNodePosition);

	mCamera->setPosition(0.0f,150.0f,0.0f);
    mCamera->setOrientation(Ogre::Quaternion::IDENTITY);
    mCamera->yaw(Ogre::Degree(mCamYawValue));
    mCamera->pitch(Ogre::Degree(mCamPitchValue));
    mCamera->moveRelative(Ogre::Vector3(0.0f,0.0f,mCamRadius));
}

void SphericalCamera::setFocus(const Vector3& pos)
{
	mCamNodePosition=pos;
	mCamera->getParentSceneNode()->setPosition(mCamNodePosition);
}

std::string SphericalCamera::toString() const
{
	std::ostringstream oss;
	oss << "Yaw: " << mCamYawValue << "\nPitch: " << mCamPitchValue << "\nRadius: " << mCamRadius;
	return oss.str();
}

void SphericalCamera::onMouseDrag(const float &Xrel, const float &Yrel)
{
	Vector3 camDir=mCamera->getDirection();
	camDir.y=0;
	camDir.normalise();
	Vector3 dir1=camDir * Yrel;

	Vector3 dir2(camDir.z, 0, -camDir.x);
	dir2=dir2 * Xrel;
	Real x=dir1.x+dir2.x;
	Real z=dir1.z+dir2.z;

	mCamera->getParentSceneNode()->translate(x, 0, z);	
}