#ifndef _H_OGRE_MESH_UTIL_H
#define _H_OGRE_MESH_UTIL_H

#include <Ogre.h>

using namespace Ogre;

class OgreMeshUtil
{
public:
	virtual ~OgreMeshUtil() { }
private:
	OgreMeshUtil() { }
	
public:
	static void GetMeshInformation(const Ogre::MeshPtr mesh,
                                size_t &vertex_count,
                                Ogre::Vector3* &vertices,
                                size_t &index_count,
                                unsigned long* &indices,
                                const Ogre::Vector3 &position,
                                const Ogre::Quaternion &orient,
                                const Ogre::Vector3 &scale);
};

#endif
