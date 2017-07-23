#include "PGManager.h"
#include "../GameEngine/Application.h"
#include "../OSEnvironment/OSEnvironment.h"
#include "HeightFunction.h"
#include <list>
#include <sstream>

PGManager* PGManager::mSingleton=NULL;

PGManager::PGManager()
: mTreeLoaded(false)
, mBushLoaded(false)
, mTreeLoader(NULL)
, mGrassLoader(NULL)
, mBushLoader(NULL)
, mWindFactorX(15)
, mWindFactorY(0.01f)
{
	if(mSingleton==NULL)
	{
		mSingleton=this;
	}
	else
	{
		throw Exception(42, "only one instance allowed", "PGManager::PGManager()");
	}

	Application* app=Application::getSingletonPtr();
	SceneManager* sm=app->getSceneMgr();
	Camera* cam=app->getCamera();

	//-------------------------------------- LOAD GRASS --------------------------------------
	//Create and configure a new PagedGeometry instance for grass
	mGrass = new PagedGeometry(cam, 30);
	createGrassLoader();

	//-------------------------------------- LOAD TREES --------------------------------------
	//Create and configure a new PagedGeometry instance
	mTrees = new PagedGeometry();
	mTrees->setCamera(cam);	//Set the camera so PagedGeometry knows how to calculate LODs
	mTrees->setPageSize(50);	//Set the size of each page of geometry
	mTrees->setInfinite();		//Use infinite paging mode

	createTreeLoader();

	//-------------------------------------- LOAD BUSHES --------------------------------------
	//Create and configure a new PagedGeometry instance for bushes
	mBushes = new PagedGeometry(cam, 50);

	createBushLoader();
}

void PGManager::createTreeLoader()
{
	if(mTreeLoader != NULL)
	{
		destroyTreeLoader();
	}

#ifdef PG_WIND
   //WindBatchPage is a variation of BatchPage which includes a wind animation shader
   mTrees->addDetailLevel<WindBatchPage>(90, 30);      //Use batches up to 150 units away, and fade for 30 more units
#else
   trees->addDetailLevel<BatchPage>(90, 30);      //Use batches up to 150 units away, and fade for 30 more units
#endif

	mTrees->addDetailLevel<ImpostorPage>(1000, 50);	//Use impostors up to 1000 units, and for for 50 more units
	//Xianshun: increase the imposter units to higher than 1000 if you want to see more of the tree at distant locations

#if TREE_MODEL==TREE_MODEL_3D
	//Create a new TreeLoader2D object
	mTreeLoader = new TreeLoader3D(mTrees, TBounds(0, 0, 1500, 1500));
#else
	//Create a new TreeLoader2D object
	mTreeLoader = new TreeLoader2D(mTrees, TBounds(0, 0, 1500, 1500));

	//Supply a height function to TreeLoader2D so it can calculate tree Y values
	mTreeLoader->setHeightFunction(&HeightFunction::getTerrainHeight);
#endif
	
	mTrees->setPageLoader(mTreeLoader);	//Assign the "treeLoader" to be used to load geometry for the PagedGeometry instance

	

	//Load a tree entity
	mTree1 = Application::getSingletonPtr()->getSceneMgr()->createEntity("PGTree1", "fir05_30.mesh");

	mTrees->setCustomParam(mTree1->getName(), "windFactorX", mWindFactorX); 
	mTrees->setCustomParam(mTree1->getName(), "windFactorY", mWindFactorY); //0.01
	/*mTrees->setCustomParam(tree2->getName(), "windFactorX", 22);
	mTrees->setCustomParam(tree2->getName(), "windFactorY", 0.015);
	mTrees->setCustomParam(tree3->getName(), "windFactorX", 8);
	mTrees->setCustomParam(tree3->getName(), "windFactorY", 0.02);*/
}

void PGManager::createBushLoader()
{
	if(mBushLoader != NULL)
	{
		destroyBushLoader();
	}
	mBushes->addDetailLevel<BatchPage>(80, 50);

	//Create a new TreeLoader2D object for the bushes
	mBushLoader = new TreeLoader2D(mBushes, TBounds(0, 0, 1500, 1500));
	mBushes->setPageLoader(mBushLoader);

	//Supply the height function to TreeLoader2D so it can calculate tree Y values
	mBushLoader->setHeightFunction(&HeightFunction::getTerrainHeight);

	//bushLoader->setColorMap("terrain_lightmap.jpg");

	//Load a bush entity
	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
	mFern = sm->createEntity("Fern", "farn1.mesh");
	mPlant = sm->createEntity("Plant", "plant2.mesh");
	mMushroom = sm->createEntity("Mushroom", "shroom1_1.mesh");
}

void PGManager::createGrassLoader()
{
	if(mGrassLoader != NULL)
	{
		destroyGrassLoader();
	}
	mGrass->addDetailLevel<GrassPage>(60);

	//Create a GrassLoader object
	mGrassLoader = new GrassLoader(mGrass);
	mGrass->setPageLoader(mGrassLoader);	//Assign the "treeLoader" to be used to load geometry for the PagedGeometry instance

	//Supply a height function to GrassLoader so it can calculate grass Y values
	mGrassLoader->setHeightFunction(&HeightFunction::getTerrainHeight);
}

void PGManager::destroyBushLoader()
{
	if(mBushLoader != NULL)
	{
		delete mBushLoader;
		mBushes->setPageLoader(NULL);
		mBushes->removeDetailLevels();
		mBushLoader=NULL;

		SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
		sm->destroyEntity("Fern");
		sm->destroyEntity("Plant");
		sm->destroyEntity("Mushroom");
	}
}

void PGManager::destroyGrassLoader()
{
	if(mGrassLoader != NULL)
	{
		delete mGrassLoader;
		mGrass->setPageLoader(NULL);
		mGrass->removeDetailLevels();
		mGrassLoader=NULL;
	}
}

void PGManager::destroyTreeLoader()
{
	if(mTreeLoader != NULL)
	{
		delete mTreeLoader;
		mTrees->setPageLoader(NULL);
		mTrees->removeDetailLevels();
		mTreeLoader=NULL;

		//Also delete the entities
		Application::getSingletonPtr()->getSceneMgr()->destroyEntity("PGTree1");
	}
}

void PGManager::update()
{
	if(isGrassLoaded())
	{
		mGrass->update();
	}
	if(isTreeLoaded())
	{
		mTrees->update();
	}
	if(isBushLoaded())
	{
		mBushes->update();
	}
}

PGManager::~PGManager()
{
	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
	//Delete the PageLoader's
	delete mGrass->getPageLoader();
	delete mTrees->getPageLoader();
	delete mBushes->getPageLoader();

	//Delete the PagedGeometry instances
	delete mGrass;
	delete mTrees;
	delete mBushes;

	//Also delete the entities
	sm->destroyEntity("PGTree1");
	sm->destroyEntity("Fern");
	sm->destroyEntity("Plant");
	sm->destroyEntity("Mushroom");
}


PGManager* PGManager::getSingletonPtr()
{
	return mSingleton;
}

PGManager& PGManager::getSingleton()
{
	return *mSingleton;
}

void PGManager::loadTree1(const Ogre::Vector3 &pos, const Degree& yaw, const Real& scale)
{
	if(mTreeLoader == NULL)
	{
		createTreeLoader();
	}
	mTreeLoader->addTree(mTree1, pos, yaw, scale);
	mTreeLoaded=true;
}

void PGManager::loadTree1()
{
	if(mTreeLoader == NULL)
	{
		createTreeLoader();
	}

	Vector3 position;
	Degree yaw;
	Real scale;
	for (int i = 0; i < 400; i++){
		yaw = Degree(Math::RangeRandom(0, 360));
		position.x = Math::RangeRandom(0, 1500);
		position.z = Math::RangeRandom(0, 1500);

		position.y=HeightFunction::getTerrainHeight(position.x, position.z);
		scale = Math::RangeRandom(0.5f, 0.6f);
		mTreeLoader->addTree(mTree1, position, yaw, scale);
	}
	mTreeLoaded=true;
}

#if TREE_MODEL == TREE_MODEL_3D
TreeLoader3D* PGManager::getTreeLoader()
{
	return mTreeLoader;
}
#else 
TreeLoader2D* PGManager::getTreeLoader()
{
	return mTreeLoader;
}
#endif

TreeLoader2D* PGManager::getBushLoader()
{
	return mBushLoader;
}

GrassLoader* PGManager::getGrassLoader()
{
	return mGrassLoader;
}

void PGManager::loadTree1(const Ogre::Vector3& pos, const Real& radius, int count)
{
	if(mTreeLoader == NULL)
	{
		createTreeLoader();
	}

	if(count <= 0)
	{
		return;
	}

	Vector3 pos1;
	if(count==1)
	{
		loadTree1(pos, Degree(Ogre::Math::RangeRandom(0, 360)), Math::RangeRandom(0.5f, 0.6f));
	}
	else
	{
		for(int i=0; i<count; ++i)
		{
			pos1.x=Math::UnitRandom();
			pos1.z=Math::UnitRandom();
			pos1.y=0;
			pos1.normalise();
			pos1=pos1 * Math::RangeRandom(0, radius);
			pos1+=pos;
			
			loadTree1(pos1, Degree(Ogre::Math::RangeRandom(0, 360)), Math::RangeRandom(0.5f, 0.6f));
		}
	}
	mTreeLoaded=true;
}

void PGManager::unloadTree1(const Ogre::Vector3& pos, const Real& radius)
{
	if(mTreeLoaded)
	{
		mTreeLoader->deleteTrees(pos, radius);
	}
}

void PGManager::unloadTree1()
{
	destroyTreeLoader();
	mTreeLoaded=false;
	/*if(mTreeLoaded)
	{
		mTreeLoader->deleteTrees(TBounds(0, 0, 1500, 1500));
		mTreeLoaded=false;
	}*/
}

void PGManager::unloadBush(const Vector3& pos, const Real& radius)
{
	if(mBushLoaded)
	{
		mBushLoader->deleteTrees(pos, radius);
	}
}

void PGManager::unloadGrass()
{
	destroyGrassLoader();
	/*std::list<GrassLayer*>& lst=mGrassLoader->getLayerList();
	if(lst.empty())
	{
		return;
	}
	GrassLayer* l=lst.back();
	mGrassLoader->deleteLayer(l);*/
}

void PGManager::unloadForest()
{
	unloadTree1();
	unloadBush();
	unloadGrass();
	/*if(mBushLoaded)
	{
		mBushLoader->deleteTrees(TBounds(0, 0, 1500, 1500));
		mBushLoaded=false;
	}

	if(mTreeLoaded)
	{
		mTreeLoader->deleteTrees(TBounds(0, 0, 1500, 1500));
		mTreeLoaded=false;
	}

	std::list<GrassLayer*> lst=mGrassLoader->getLayerList();
	std::list<GrassLayer*>::iterator iter=lst.begin();
	std::list<GrassLayer*>::iterator iter_end=lst.end();
	GrassLayer* l=NULL;
	for(; iter != iter_end; ++iter)
	{
		l=*iter;
		mGrassLoader->deleteLayer(l);
	}*/
}

void PGManager::unloadGrass(const Vector3& pos, const Real& radius)
{
	std::list<GrassLayer*>& lst=mGrassLoader->getLayerList();
	if(lst.empty())
	{
		return;
	}
	GrassLayer* layerToDelete=NULL;
	GrassLayer* l=NULL;
	std::list<GrassLayer*>::iterator iter=lst.begin();
	std::list<GrassLayer*>::iterator iter_end=lst.end();
	for(; iter != iter_end; ++iter)
	{
		l=*iter;

		const TBounds& tb=l->getMapBounds();
		if(tb.left < pos.x && tb.right > pos.x && tb.top < pos.z && tb.bottom > pos.z)
		{
			if(layerToDelete==NULL)
			{
				layerToDelete=l;
			}
			else
			{
				const TBounds& tb2=layerToDelete->getMapBounds();
				if(tb.width() < tb2.width())
				{
					layerToDelete=l;
				}
			}
		}
		
		mGrassLoader->deleteLayer(layerToDelete);
		
	}
}

void PGManager::loadGrass(int left, int top, int right, int bottom)
{
	loadGrass(TBounds(left, top, right, bottom));
}

void PGManager::loadGrass(const TBounds& tb)
{
	if(mGrassLoader == NULL)
	{
		createGrassLoader();
	}

	//Add some grass to the scene with GrassLoader::addLayer()
	GrassLayer *l = mGrassLoader->addLayer("3D-Diggers/plant1sprite");

	//Configure the grass layer properties (size, density, animation properties, fade settings, etc.)
	l->setMinimumSize(0.7f, 0.7f);
	l->setMaximumSize(0.9f, 0.9f);
	l->setAnimationEnabled(true);		//Enable animations
	l->setSwayDistribution(7.0f);		//Sway fairly unsynchronized
	l->setSwayLength(0.1f);				//Sway back and forth 0.5 units in length
	l->setSwaySpeed(0.4f);				//Sway 1/2 a cycle every second
	l->setDensity(3.0f);				//Relatively dense grass
	l->setRenderTechnique(GRASSTECH_SPRITE);
	l->setFadeTechnique(FADETECH_GROW);	//Distant grass should slowly raise out of the ground when coming in range

	//[NOTE] This sets the color map, or lightmap to be used for grass. All grass will be colored according
	//to this texture. In this case, the colors of the terrain is used so grass will be shadowed/colored
	//just as the terrain is (this usually makes the grass fit in very well).
	//l->setColorMap("terrain_texture2.jpg");

	//This sets the density map that will be used to determine the density levels of grass all over the
	//terrain. This can be used to make grass grow anywhere you want to; in this case it's used to make
	//grass grow only on fairly level ground (see densitymap.png to see how this works).
	//l->setDensityMap("densitymap.png");

	//setMapBounds() must be called for the density and color maps to work (otherwise GrassLoader wouldn't
	//have any knowledge of where you want the maps to be applied). In this case, the maps are applied
	//to the same boundaries as the terrain.
	
	
	l->setMapBounds(tb);	//(0,0)-(1500,1500) is the full boundaries of the terrain
}

void PGManager::loadGrass(const Vector3& pos, const Real& radius)
{
	Real left=pos.x-radius;
	Real top=pos.z-radius;
	Real right=pos.x+radius;
	Real bottom=pos.z+radius;
	if(left < 0) left=0;
	if(right > 1500) right=1500;
	if(top < 0) top=0;
	if(bottom > 1500) bottom=1500;
	if(right - left < 0.1f) return;
	if(bottom-top < 0.1f) return;

	loadGrass(TBounds(left, top, right, bottom));
}

void PGManager::loadGrass()
{
	if(mGrassLoader==NULL)
	{
		createGrassLoader();
	}
	//Add some grass to the scene with GrassLoader::addLayer()
	GrassLayer *l = mGrassLoader->addLayer("3D-Diggers/plant1sprite");

	//Configure the grass layer properties (size, density, animation properties, fade settings, etc.)
	l->setMinimumSize(0.7f, 0.7f);
	l->setMaximumSize(0.9f, 0.9f);
	l->setAnimationEnabled(true);		//Enable animations
	l->setSwayDistribution(7.0f);		//Sway fairly unsynchronized
	l->setSwayLength(0.1f);				//Sway back and forth 0.5 units in length
	l->setSwaySpeed(0.4f);				//Sway 1/2 a cycle every second
	l->setDensity(3.0f);				//Relatively dense grass
	l->setRenderTechnique(GRASSTECH_SPRITE);
	l->setFadeTechnique(FADETECH_GROW);	//Distant grass should slowly raise out of the ground when coming in range

	//[NOTE] This sets the color map, or lightmap to be used for grass. All grass will be colored according
	//to this texture. In this case, the colors of the terrain is used so grass will be shadowed/colored
	//just as the terrain is (this usually makes the grass fit in very well).
	//l->setColorMap("terrain_texture2.jpg");

	//This sets the density map that will be used to determine the density levels of grass all over the
	//terrain. This can be used to make grass grow anywhere you want to; in this case it's used to make
	//grass grow only on fairly level ground (see densitymap.png to see how this works).
	//l->setDensityMap("densitymap.png");

	//setMapBounds() must be called for the density and color maps to work (otherwise GrassLoader wouldn't
	//have any knowledge of where you want the maps to be applied). In this case, the maps are applied
	//to the same boundaries as the terrain.
	l->setMapBounds(TBounds(0, 0, 1500, 1500));	//(0,0)-(1500,1500) is the full boundaries of the terrain
}

void PGManager::loadBush()
{
	if(mBushLoader==NULL)
	{
		createBushLoader();
	}
	Vector3 position;
	Degree yaw;
	Real scale;
	for (int i = 0; i < 20000; i++){
		yaw = Degree(Math::RangeRandom(0, 360));
		position.x = Math::RangeRandom(0, 1500);
		position.z = Math::RangeRandom(0, 1500);

		float rnd = Math::UnitRandom();
		if (rnd < 0.8f) {
			scale = Math::RangeRandom(0.3f, 0.4f);
			mBushLoader->addTree(mFern, position, yaw, scale);
		} else if (rnd < 0.9) {
			scale = Math::RangeRandom(0.2f, 0.6f);
			mBushLoader->addTree(mMushroom, position, yaw, scale);
		} else {
			scale = Math::RangeRandom(0.3f, 0.5f);
			mBushLoader->addTree(mPlant, position, yaw, scale);
		}
	}
	mBushLoaded=true;
}

void PGManager::unloadBush()
{
	destroyBushLoader();
	mBushLoaded=false;
	/*if(mBushLoaded)
	{
		mBushLoader->deleteTrees(TBounds(0, 0, 1500, 1500));
		mBushLoaded=false;
	}*/
}

void PGManager::loadBush(const Vector3& pos, const Real& radius, int count)
{
	if(mBushLoader==NULL)
	{
		createBushLoader();
	}
	if(count <= 0)
	{
		return;
	}

	Vector3 position;
	Degree yaw;
	Real scale;
	if(count==1)
	{
		yaw = Degree(Math::RangeRandom(0, 360));

		float rnd = Math::UnitRandom();
		if (rnd < 0.8f) {
			scale = Math::RangeRandom(0.3f, 0.4f);
			mBushLoader->addTree(mFern, pos, yaw, scale);
		} else if (rnd < 0.9) {
			scale = Math::RangeRandom(0.2f, 0.6f);
			mBushLoader->addTree(mMushroom, pos, yaw, scale);
		} else {
			scale = Math::RangeRandom(0.3f, 0.5f);
			mBushLoader->addTree(mPlant, pos, yaw, scale);
		}
	}
	else
	{
		for (int i = 0; i < count; i++){
			yaw = Degree(Math::RangeRandom(0, 360));
			position.x = Math::UnitRandom();
			position.z = Math::UnitRandom();
			position.normalise();
			position=position * Math::RangeRandom(0, radius);
			position+=pos;

			float rnd = Math::UnitRandom();
			if (rnd < 0.8f) {
				scale = Math::RangeRandom(0.3f, 0.4f);
				mBushLoader->addTree(mFern, position, yaw, scale);
			} else if (rnd < 0.9) {
				scale = Math::RangeRandom(0.2f, 0.6f);
				mBushLoader->addTree(mMushroom, position, yaw, scale);
			} else {
				scale = Math::RangeRandom(0.3f, 0.5f);
				mBushLoader->addTree(mPlant, position, yaw, scale);
			}
		}
	}
	mBushLoaded=true;
}