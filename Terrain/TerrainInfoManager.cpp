#include "TerrainInfoManager.h"
#include "../GameEngine/Application.h"
#include "../OSEnvironment/OSEnvironment.h"

TerrainInfoManager* TerrainInfoManager::mSingleton=NULL;

TerrainInfoManager::~TerrainInfoManager()
{
	//mSceneMgr->destroyQuery(mRaySceneQuery);

	delete mTerrainMgr;
	delete mSplatMgr;

	mTerrainMgr=NULL;
	mTerrainInfo=NULL;
	mSplatMgr=NULL;
}

void TerrainInfoManager::createEditBrush(const String& resourceName)
{
	Image image;
	image.load(resourceName, "TET");
	image.resize(16, 16);
	mEditBrush=ET::loadBrushFromImage(image);
}

void TerrainInfoManager::deform(const Real& x, const Real& z, const Real& intensity)
{
	if(mTerrainLoaded)
	{
		int ix=mTerrainInfo->posToVertexX(x);
		int iz=mTerrainInfo->posToVertexZ(z);

		mTerrainMgr->deform(ix, iz, mEditBrush, intensity);
	}
}

void TerrainInfoManager::paint(const Real& x, const Real& z, const Real& intensity, uint textureId)
{
	if(mTerrainLoaded)
	{
		int ix=mTerrainInfo->posToVertexX(x);
		int iz=mTerrainInfo->posToVertexZ(z);

		mSplatMgr->paint(textureId, ix, iz, mEditBrush, intensity);
	}
}

void TerrainInfoManager::createTerrainMgr(const String& resourceGroupName)
{
	if(mTerrainMgr != NULL)
	{
		delete mTerrainMgr;
		mTerrainMgr=NULL;
	}

	mTerrainMgr=new ET::TerrainManager(mSceneMgr);

	//OSEnvironment::showWinMsgBox(OSEnvironment::toString(mCamera->getViewport()->getActualHeight()).c_str());
	mTerrainMgr->setLODErrorMargin(2, Application::getSingletonPtr()->getWindow()->getHeight());
	mTerrainMgr->setUseLODMorphing(true, 0.2f, "morphFactor");

	Image image;
	image.load("ETterrain.png", resourceGroupName);
	ET::TerrainInfo terrainInfo;
	ET::loadHeightmapFromImage(terrainInfo, image);
	terrainInfo.setExtents(AxisAlignedBox(0, 0, 0, 1500, 300, 1500));

	mTerrainMgr->createTerrain(terrainInfo);

	MaterialPtr material(MaterialManager::getSingletonPtr()->getByName("ETTerrainMaterial"));
	mTerrainMgr->setMaterial(material);
	
	mTerrainInfo=&mTerrainMgr->getTerrainInfo();
}

void TerrainInfoManager::createSplatMgr(const String& resourceGroupName)
{
	if(mTerrainMgr != NULL)
	{
		delete mSplatMgr;
	}

	mSplatMgr=new ET::SplattingManager("ETSplatting", resourceGroupName, 128, 128, 3);
	mSplatMgr->setNumTextures(6);
}

void TerrainInfoManager::createLightmap(const String& resourceGroupName)
{
	TextureManager* tm=TextureManager::getSingletonPtr();
	
	TexturePtr lightmapTex=TextureManager::getSingletonPtr()->createManual("ETLightmap", resourceGroupName, TEX_TYPE_2D, 128, 128, 1, PF_BYTE_RGB);
	Image lightmap;
	ET::createTerrainLightmap(*mTerrainInfo, lightmap, 128, 128, Vector3(1, -1, 1), ColourValue::White, ColourValue(0.3f, 0.3f, 0.3f));
	lightmapTex->getBuffer(0, 0)->blitFromMemory(lightmap.getPixelBox(0, 0));

	uint numMaps=mSplatMgr->getNumMaps();
	Image image;
	for(uint i=0; i<numMaps; ++i)
	{
		image.load("ETcoverage."+StringConverter::toString(i)+".png", resourceGroupName);
		mSplatMgr->loadMapFromImage(i, image);
	}
}

void TerrainInfoManager::loadTerrain(const String& resourceGroupName)
{
	createTerrainMgr(resourceGroupName);
	createSplatMgr(resourceGroupName);
	createLightmap(resourceGroupName);

	mTerrainCenter=Vector3(750, getHeight(750, 750), 750);

	mResourceGroupName=resourceGroupName;

	/*
	Hydrax::Hydrax* hydrax=HydraxManager::getSingletonPtr()->getHydrax();
	hydrax->getMaterialManager()->addDepthTechnique(
         static_cast<Ogre::MaterialPtr>(Ogre::MaterialManager::getSingleton().getByName("ETTerrainMaterial"))->createTechnique());
	*/

	mTerrainLoaded=true;
}

Vector3 TerrainInfoManager::getIntersection(const Ray& ray)
{
	if(mTerrainLoaded)
	{
		std::pair<bool, Vector3> result1=mTerrainInfo->rayIntersects(ray);

		if(result1.first)
		{
			return result1.second;
		}

		std::pair<bool, Real> result2=ray.intersects(mPlane);

		if(result2.first)
		{
			return ray.getPoint(result2.second);
		}

		return Vector3(0, 0, 0);
	}

	std::pair<bool, Real> result2=ray.intersects(mPlane);

	if(result2.first)
	{
		return ray.getPoint(result2.second);
	}

	return Vector3(0, 0, 0);
}

void TerrainInfoManager::unloadTerrain()
{
	if(mTerrainMgr != NULL)
	{
		delete mTerrainMgr;
		mTerrainMgr=NULL;
	}
	if(mSplatMgr != NULL)
	{
		delete mSplatMgr;
		mSplatMgr=NULL;
	}
	mTerrainLoaded = false;
}

void TerrainInfoManager::saveTerrain(const String& src)
{
	if(mTerrainLoaded==false)
	{
		return;
	}

	Image image;
	ET::saveHeightmapToImage(*mTerrainInfo, image);

	String path=src+"/ETterrain.png";
	image.save(path);

	uint numMaps=mSplatMgr->getNumMaps(); 
	for(uint i=0; i< numMaps; ++i)
	{
		mSplatMgr->saveMapToImage(i, image);
		path=src+"/ETcoverage."+StringConverter::toString(i)+".png";
		image.save(path);
	}

	Image lightmap;
	ET::createTerrainLightmap(*mTerrainInfo, lightmap, 512, 512, Vector3(1, -1, 1), ColourValue(1, 1, 1), ColourValue(0.3f, 0.3f, 0.3f));
	path=src+"/ETlightmap.png";
	lightmap.save(path);

	ET::ImageList textures(6);
	for(int i=0; i<6; ++i)
	{
		textures[i].load("splatting"+StringConverter::toString(i)+".png", mResourceGroupName);
	}

	Image baseTexture;
	mSplatMgr->createBaseTexture(baseTexture, 512, 512, textures, 20, 20);
	path=src+"/ETbase.png";
	baseTexture.save(path);

	Image minimap=ET::createMinimap(baseTexture, lightmap);
	path=src+"/ETminimap.png";
	minimap.save(path);
}

Real TerrainInfoManager::getHeight(const Real& x, const Real& z)
{
	/*
	Ray ray(Vector3(x, 1000, z), Vector3::NEGATIVE_UNIT_Y);

	std::pair<bool, Vector3> result=mTerrainInfo->rayIntersects(ray);

	if(result.first)
	{
		return result.second.y;
	}
	*/

	/*
	mRaySceneQuery->setRay(ray);
	mRaySceneQuery->setSortByDistance(true);

	Real y=0;
	RaySceneQueryResult& result=mRaySceneQuery->execute();
	RaySceneQueryResult::iterator ri=result.begin();
	RaySceneQueryResult::iterator ri_end=result.end();
	for(; ri != ri_end; ++ri)
	{
		if(ri->worldFragment)
		{
			y=ri->worldFragment->singleIntersection.y;
			break;
		}
	}
	return y;
	*/

	if(mTerrainLoaded==false)
	{
		return 0;
	}

	return mTerrainInfo->getHeightAt(x, z);
}

void TerrainInfoManager::updateLightmap()
{
	if(mTerrainLoaded)
	{
		Image lightmap;
		ET::createTerrainLightmap(*mTerrainInfo, lightmap, 128, 128, Vector3(1, -1, 1), ColourValue(1, 1, 1), ColourValue(0.3f, 0.3f, 0.3f));

		TexturePtr tex=TextureManager::getSingletonPtr()->getByName("ETLightmap");
		tex->getBuffer(0, 0)->blitFromMemory(lightmap.getPixelBox(0, 0));
	}
}

const ET::TerrainInfo* TerrainInfoManager::getTerrainInfo()
{
	return mTerrainInfo;
}

TerrainInfoManager::TerrainInfoManager(Application* app)
: mApp(app)
, mSceneMgr(app->getSceneMgr())
, mCamera(app->getCamera())
, mTerrainMgr(NULL)
, mTerrainInfo(NULL)
, mSplatMgr(NULL)
, mTerrainLoaded(false)
, mPlane(Vector3::UNIT_Y, Vector3(0, 0, 0))
{
	if(mSingleton==NULL)
	{
		mSingleton=this;
	}
	else
	{
		throw Exception(42, "Multiple instances of TerrainInfoManager not allow", "TerrainInfoManager::TerrainInfoManager(SceneManager* mgr)");
	}

	createEditBrush("brush.png");

	//mRaySceneQuery=mSceneMgr->createRayQuery(Ray());
}