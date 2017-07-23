#ifndef _H_ML_LAB_TERRAIN_INFO_MANAGER_H
#define _H_ML_LAB_TERRAIN_INFO_MANAGER_H

#include <Ogre.h>
#include "../ETM/include/ETTerrainManager.h"
#include "../ETM/include/ETTerrainInfo.h"
#include "../ETM/include/ETBrush.h"
#include "../ETM/include/ETSplattingManager.h"

using namespace Ogre;

class Application;

class TerrainInfoManager 
{
protected:
	static TerrainInfoManager* mSingleton;
	SceneManager* mSceneMgr;
	//RaySceneQuery* mRaySceneQuery;
	Application* mApp;
	Camera* mCamera;
	Vector3 mTerrainCenter;

public:
	TerrainInfoManager(Application* app);
	virtual ~TerrainInfoManager();

	static TerrainInfoManager* getSingletonPtr()
	{
		return mSingleton;
	}

	static TerrainInfoManager& getSingleton()
	{
		return *mSingleton;
	}

private:
	void createTerrainMgr(const String& resourceGroupName);
	void createEditBrush(const String& resourceName);
	void createSplatMgr(const String& resourceGroupName);
	void createLightmap(const String& resourceGroupName);

private:
	TerrainInfoManager(const TerrainInfoManager& rhs) { }
	TerrainInfoManager& operator=(const TerrainInfoManager& rhs) { return *this; }

public:
	Real getHeight(const Real& x, const Real& z);
	void deform(const Real& x, const Real& z, const Real& intensity);
	void paint(const Real& x, const Real& z, const Real& intensity, uint textureId);
	void updateLightmap();
	void loadTerrain(const String& loc_type);
	void unloadTerrain();
	Vector3 getIntersection(const Ray& ray);
	bool isTerrainLoaded() const { return mTerrainLoaded; }
	void saveTerrain(const String& src);
	const ET::TerrainInfo* getTerrainInfo();

public:
	//x: [0, 1500]
	//y: [0, 1500]
	Real getMaxX() const { return 1250; }
	Real getMinX() const { return 250; }
	Real getMaxZ() const { return 1250; }
	Real getMinZ() const { return 250; }
	Real getCenterX() const { return 750; }
	Real getCenterZ() const { return 750; }
	Real getCenterY() const { return mTerrainCenter.y; }
	const Vector3& getCenter() const { return mTerrainCenter; }

protected:
	ET::TerrainManager* mTerrainMgr;
	ET::SplattingManager* mSplatMgr;
	ET::Brush mEditBrush;
	const ET::TerrainInfo* mTerrainInfo;
	Plane mPlane;
	bool mTerrainLoaded;

private:
	Ogre::String mResourceGroupName;
};

#endif