#ifndef _H_ML_LAB_MOUSE_PICKER_H
#define _H_ML_LAB_MOUSE_PICKER_H

#include <Ogre.h>
#include <OIS/OIS.h>
#include <CEGUI/CEGUI.h>

using namespace Ogre;

class MousePicker
{
public:
	MousePicker();
	virtual ~MousePicker();

private:
	MousePicker(const MousePicker& rhs) { }
	MousePicker& operator=(const MousePicker& rhs) { return *this; }

public:
	MovableObject* pick(const OIS::MouseEvent& evt);
	Vector3 getTerrainIntersection(const OIS::MouseEvent& evt);
	void setCamera(Camera* cam) { mCamera=cam; }

protected:
	RaySceneQuery* mRaySceneQuery;
	Camera* mCamera;
};
#endif