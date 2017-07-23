#ifndef _H_OGRE_RAY_UTIL_H
#define _H_OGRE_RAY_UTIL_H

#include <Ogre.h>

using namespace Ogre;

class OgreRayUtil
{
public:
	virtual ~OgreRayUtil() { }

private:
	OgreRayUtil() { }

public:
	static bool RaycastFromPoint(RaySceneQuery* raySceneQuery, const Vector3 &point,
                                        const Vector3 &normal,
                                        Vector3 &result);
	static MovableObject* RaycastFromPoint(RaySceneQuery* raySceneQuery, const Vector3& point, const Vector3& normal);
};

#endif
