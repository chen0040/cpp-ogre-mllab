#ifndef _H_MLLAB_HYDRAX_MANAGER_H
#define _H_MLLAB_HYDRAX_MANAGER_H

#include <Ogre.h>
#include "../Hydrax/Hydrax/include/Hydrax.h"
#include "../Hydrax/Hydrax/include/Noise/Perlin/Perlin.h"
#include "../Hydrax/Hydrax/include/Modules/ProjectedGrid/ProjectedGrid.h"

using namespace Ogre;

class HydraxManager
{
public:
	HydraxManager();
	virtual ~HydraxManager();

private:
	HydraxManager(const HydraxManager& rhs) { }
	HydraxManager& operator=(const HydraxManager& rhs) { return *this; }

protected:
	static HydraxManager* mSingleton;

public:
	static HydraxManager* getSingletonPtr();
	static HydraxManager& getSingleton();
	Hydrax::Hydrax* getHydrax() { return mHydrax; }

public:
	void loadHydrax();
	void unloadHydrax();
	bool isHydraxLoaded() const;

public:
	void loadOgreOcean();
	void unloadOgreOcean();
	bool isOgreOceanCreated() const;
	bool isOgreOceanLoaded() const { return mOceanLoaded; }
	void setOgreOceanHeight(int height);
	void setOgreOceanSize(int width, int height);
	int getOgreOceanHeight() const { return mOgreOceanHeight; }
	int getOgreOceanSizeX() const { return mOgreOceanWidthX; }
	int getOgreOceanSizeZ() const { return mOgreOceanWidthZ; }
private:
	void createOgreOcean();
	void destroyOgreOcean();

public:
	void update(const float& dt);
	Real getHeight(const Real& x, const Real& z);

private:
	Hydrax::Hydrax* mHydrax;
	bool mHydraxLoaded;

public:
	void enableHydrax(bool enabled);
	bool isHydraxEnabled() const { return mHydraxEnabled; }
private:
	bool mHydraxEnabled;

private:
	Entity* mOceanSurfaceEnt;
	SceneNode* mOceanSurfaceNode;
	int mOgreOceanHeight;
	int mOgreOceanWidthX; 
	int mOgreOceanWidthZ;
	bool mOceanLoaded;
};
#endif