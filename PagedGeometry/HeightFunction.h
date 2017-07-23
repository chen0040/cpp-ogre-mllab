//This provides functions that can be used to easily get the height of Ogre's terrain at any x/z point.
//Simply call HeightFunction::initialize(), then use HeightFunction::getTerrainHeight() as needed.

//This file is used by the PagedGeometry examples to place trees on the terrain.

#include "../Terrain/TerrainInfoManager.h"
#include "../Hydrax/HydraxManager.h"

namespace HeightFunction
{
	//Gets the height of the terrain at the specified x/z coordinate
	//The userData parameter isn't used in this implementation of a height function, since
	//there's no need for extra data other than the x/z coordinates.
	inline float getTerrainHeight(const float x, const float z, void *userData = NULL){
		TerrainInfoManager* tim=TerrainInfoManager::getSingletonPtr();
		HydraxManager* hm=HydraxManager::getSingletonPtr();

		if(tim->isTerrainLoaded())
		{
			return tim->getHeight(x, z);
		}
		else if(hm->isHydraxLoaded() || hm->isOgreOceanLoaded())
		{
			return hm->getHeight(x, z);
		}
		
		return 0;
	}
}