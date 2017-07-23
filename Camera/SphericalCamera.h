#ifndef _H_ML_LAB_SPHERICAL_CAMERA_H
#define _H_ML_LAB_SPHERICAL_CAMERA_H

#include <Ogre.h>

using namespace Ogre;

class SphericalCamera
{
public:
	SphericalCamera();
	virtual ~SphericalCamera();

public:
	void setActualCamera(Camera* cam);
	void setRotateSpeed(Real speed) { mCameraRotateSpeed=speed; }
	void setZoomSpeed(Real speed) { mCameraZoomSpeed=speed; }
	bool frameStarted(bool rotateLeft, bool rotateRight, bool rotateUp, bool rotateDown, bool zoomIn, bool zoomOut, const Real& dt);
	std::string toString() const;
	void reset();
	void setFocus(const Vector3& pos);
	void update();
	
protected:
	Camera* mCamera;
	Vector3 mCamNodePosition;

public:
	void onMouseDrag(const float& Xrel, const float& Yrel);

protected:
	Real mCameraRotateSpeed;
	Real mCameraZoomSpeed;
	Real mCamPitchValue;
	Real mCamYawValue;
	Real mCamRadius;
	Real mInitCamPitchValue;
	Real mInitCamYawValue;
	Real mInitCamRadius;
	Real mMinCamRadius;
	Real mMaxCamRadius;
	Real mMinCamPitchValue;
	Real mMaxCamPitchValue;
};
#endif