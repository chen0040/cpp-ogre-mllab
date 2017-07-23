#ifndef _H_ML_LAB_FIRST_PERSON_CAMERA_H
#define _H_ML_LAB_FIRST_PERSON_CAMERA_H

#include <Ogre.h>

using namespace Ogre;

class FirstPersonCamera
{
public:
	FirstPersonCamera();
	virtual ~FirstPersonCamera();

private:
	FirstPersonCamera(const FirstPersonCamera& rhs) { }
	FirstPersonCamera& operator=(const FirstPersonCamera& rhs) { return *this; }

public:
	void setActualCamera(Camera* cam);
	void setRotateSpeed(Real speed) { mCameraRotateSpeed=speed; }
	void setMoveSpeed(Real speed) { mCamMoveSpeed=speed; }
	void setPosition(const Vector3& pos);
	bool frameStarted(bool rotateLeft, bool rotateRight, bool rotateUp, bool rotateDown, bool zoomIn, bool zoomOut, const Real& dt);
	std::string toString() const;
	void reset();
	void update();

public:
	void onMouseDrag(const float &Xrel, const float &Yrel);

protected:
	Camera* mCamera;
	Vector3 mCamNodePosition;

protected:
	Real mCameraRotateSpeed;
	Real mCamMoveSpeed;
	Real mCamPitchValue;
	Real mCamYawValue;
	Real mCamHeight;
	Real mInitCamPitchValue;
	Real mInitCamYawValue;
	Real mInitCamHeight;
	Real mMinCamHeight;
	Real mMaxCamHeight;
};
#endif