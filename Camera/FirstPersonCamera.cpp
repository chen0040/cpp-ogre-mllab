#include "FirstPersonCamera.h"
#include "../SceneAssets/HeightFunction.h"

FirstPersonCamera::FirstPersonCamera()
: mCameraRotateSpeed(15.0f)
, mInitCamYawValue(-0.0f)
, mInitCamPitchValue(-0.0f)
, mMinCamHeight(-50)
, mMaxCamHeight(300)
, mInitCamHeight(10)
, mCamMoveSpeed(30)
{
	mCamPitchValue=mInitCamPitchValue;
	mCamYawValue=mInitCamYawValue;
	mCamHeight=mInitCamHeight;

	mCamNodePosition=Vector3(750, TerrainInfoManager::getSingletonPtr()->getHeight(750, 750), 750);
}

FirstPersonCamera::~FirstPersonCamera()
{

}

void FirstPersonCamera::setActualCamera(Camera* cam)
{
	mCamera=cam;
}

void FirstPersonCamera::update()
{
	mCamera->setOrientation(Ogre::Quaternion::IDENTITY);
	mCamera->yaw(Ogre::Degree(mCamYawValue));
	mCamera->pitch(Ogre::Degree(mCamPitchValue));
	mCamera->setPosition(0.0f, mCamHeight,0.0f);

	mCamNodePosition.y=HeightFunction::getTerrainHeight(mCamNodePosition.x, mCamNodePosition.z);

	SceneNode* camNode=mCamera->getParentSceneNode();
	camNode->setPosition(mCamNodePosition);
}

bool FirstPersonCamera::frameStarted(bool rotateLeft, bool rotateRight, bool moveForward, bool moveBackward, bool moveUp, bool moveDown, const Real& dt)
{
	if(!(rotateLeft || rotateRight || moveForward || moveBackward || moveUp || moveDown))
	{
		return true;
	}

	SceneNode* camNode=mCamera->getParentSceneNode();

	if(rotateLeft || rotateRight)
	{
		mCamera->setOrientation(Ogre::Quaternion::IDENTITY);
		if(rotateLeft)
		{
			mCamYawValue+=dt*mCameraRotateSpeed;
		}
		else if(rotateRight)
		{
			mCamYawValue-=dt*mCameraRotateSpeed;
		}
		mCamera->yaw(Degree(mCamYawValue));
		mCamera->pitch(Degree(mCamPitchValue));
		mCamera->setPosition(0.0f, mCamHeight,0.0f);
	}

	if(moveDown || moveUp)
	{
		if(moveDown)
		{
			if(mCamHeight > mMinCamHeight)
			{
				mCamHeight-=dt*mCamMoveSpeed;
			}
			else
			{
				mCamHeight=mMinCamHeight;
			}
		}
		else if(moveUp)
		{
			if(mCamHeight < mMaxCamHeight)
			{
				mCamHeight+=dt*mCamMoveSpeed;
			}
			else
			{
				mCamHeight=mMaxCamHeight;
			}
		}

		mCamera->setPosition(0.0f, mCamHeight,0.0f);
	}

	if(moveForward || moveBackward)
	{
		if(moveForward)
		{	
			mCamNodePosition+=mCamera->getDirection() * (dt*mCamMoveSpeed);
		}
		else if(moveBackward)
		{
			mCamNodePosition-=mCamera->getDirection() * (dt*mCamMoveSpeed);
		}
		mCamNodePosition.y=TerrainInfoManager::getSingletonPtr()->getHeight(mCamNodePosition.x, mCamNodePosition.z);
		camNode->setPosition(mCamNodePosition);
	}

	return true;
}


void FirstPersonCamera::reset()
{
	mCamPitchValue=mInitCamPitchValue;
	mCamYawValue=mInitCamYawValue;
	mCamHeight=mInitCamHeight;
	
    mCamera->setOrientation(Ogre::Quaternion::IDENTITY);
	mCamera->setPosition(0.0f, mCamHeight,0.0f);
	mCamera->yaw(Degree(mCamYawValue));
	mCamera->pitch(Degree(mCamPitchValue));

	mCamNodePosition=Vector3(750, TerrainInfoManager::getSingletonPtr()->getHeight(750, 750), 750);
	mCamera->getParentSceneNode()->setPosition(mCamNodePosition);
}

void FirstPersonCamera::setPosition(const Vector3& pos)
{
	mCamera->getParentSceneNode()->setPosition(pos.x, TerrainInfoManager::getSingletonPtr()->getHeight(pos.x, pos.z), pos.z);
}

std::string FirstPersonCamera::toString() const
{
	std::ostringstream oss;
	oss << "Yaw: " << mCamYawValue << "\nHeight: " << mCamHeight;
	return oss.str();
}

void FirstPersonCamera::onMouseDrag(const float &Xrel, const float &Yrel)
{
	mCamPitchValue-=Yrel * this->mCameraRotateSpeed * 0.05f;
	mCamYawValue-=Xrel * this->mCameraRotateSpeed * 0.05f;
	if(mCamPitchValue < -90)
	{
		mCamPitchValue=-90;
	}
	else if(mCamPitchValue > 90)
	{
		mCamPitchValue=90;
	}
	
	
	mCamera->setOrientation(Ogre::Quaternion::IDENTITY);
	mCamera->yaw(Ogre::Degree(mCamYawValue));
	mCamera->pitch(Ogre::Degree(mCamPitchValue));
	mCamera->setPosition(0.0f, mCamHeight,0.0f);
}