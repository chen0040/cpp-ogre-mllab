#include "HydraxManager.h"
#include "../GameEngine/Application.h"
#include "../OSEnvironment/OSEnvironment.h"

HydraxManager* HydraxManager::mSingleton=NULL;

HydraxManager::HydraxManager()
: mHydrax(NULL)
, mHydraxLoaded(false)
, mOgreOceanHeight(150)
, mOgreOceanWidthX(2000)
, mOgreOceanWidthZ(2000)
, mHydraxEnabled(true)
, mOceanLoaded(false)
{
	if(mSingleton == NULL)
	{
		mSingleton=this;
	}
	else
	{
		throw Ogre::Exception(42, "only one instance allowed", "HydraxManager::HydraxManager()");
	}
}

HydraxManager::~HydraxManager()
{
	if(mHydrax != NULL)
	{
		delete mHydrax;
		mHydrax=NULL;
	}
}

HydraxManager* HydraxManager::getSingletonPtr()
{
	return mSingleton;
}

HydraxManager& HydraxManager::getSingleton()
{
	return *mSingleton;
}

void HydraxManager::update(const float& dt)
{
	if(mHydraxEnabled && mHydraxLoaded)
	{
		mHydrax->update(dt);
	}
}

Real HydraxManager::getHeight(const Real& x, const Real& z)
{
	if(mHydraxEnabled && mHydraxLoaded)
	{
		return mHydrax->getHeigth(Vector2(x, z));
	}
	return mOgreOceanHeight;
}

void HydraxManager::loadOgreOcean()
{
	Application* app=Application::getSingletonPtr();
	SceneManager* sm=app->getSceneMgr();
	if(this->isOgreOceanCreated())
	{
		mOceanSurfaceNode->setVisible(true);
		 
	}
	else
	{
		createOgreOcean();
	}
	mOceanLoaded=true;
}

void HydraxManager::unloadOgreOcean()
{
	if(this->isOgreOceanLoaded())
	{
		mOceanSurfaceNode->setVisible(false);
	}
	mOceanLoaded=false;
}

bool HydraxManager::isOgreOceanCreated() const
{
	Application* app=Application::getSingletonPtr();
	SceneManager* sm=app->getSceneMgr();
	return sm->hasEntity("OceanSurface");
}

void HydraxManager::setOgreOceanHeight(int height)
{
	if(mOgreOceanHeight != height)
	{
		mOgreOceanHeight=height;
		if(this->isOgreOceanCreated())
		{
			mOceanSurfaceNode->setPosition(750, mOgreOceanHeight, 750);
		}
	}
	mOgreOceanHeight=height;
}

void HydraxManager::setOgreOceanSize(int width, int height)
{
	if(mOgreOceanWidthX != width || mOgreOceanWidthZ != height)
	{
		mOgreOceanWidthX=width;
		mOgreOceanWidthZ=height;
		
		if(this->isOgreOceanCreated())
		{
			destroyOgreOcean();
			createOgreOcean();	
		}
	}
	mOgreOceanWidthX=width;
	mOgreOceanWidthZ=height;
}

void HydraxManager::createOgreOcean()
{
	Application* app=Application::getSingletonPtr();
	SceneManager* sm=app->getSceneMgr();
	if(!sm->hasEntity("OceanSurface"))
	{
		// Define a plane mesh that will be used for the ocean surface
		 Ogre::Plane oceanSurface;
		oceanSurface.normal = Ogre::Vector3::UNIT_Y;
		oceanSurface.d = 20;
		Ogre::MeshManager::getSingleton().createPlane("OceanSurface",
		 Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		 oceanSurface,
		 mOgreOceanWidthX, mOgreOceanWidthZ, 50, 50, true, 1, 1, 1, Ogre::Vector3::UNIT_Z);


		Entity* mOceanSurfaceEnt = sm->createEntity( "OceanSurface", "OceanSurface" );
		mOceanSurfaceNode=sm->getRootSceneNode()->createChildSceneNode("OgreOceanSurfaceNode", Vector3(750, mOgreOceanHeight, 750));
		mOceanSurfaceNode->attachObject(mOceanSurfaceEnt);
		mOceanSurfaceEnt->setMaterialName("Ocean2_HLSL_GLSL");
	}
}

void HydraxManager::destroyOgreOcean()
{
	Application* app=Application::getSingletonPtr();
	SceneManager* sm=app->getSceneMgr();
	if(sm->hasEntity("OceanSurface"))
	{
		mOceanSurfaceNode->detachAllObjects();
		sm->getRootSceneNode()->removeAndDestroyChild("OgreOceanSurfaceNode");
		sm->destroyEntity("OceanSurface");
	}
}

void HydraxManager::loadHydrax()
{
	if(!mHydraxLoaded)
	{
		if(mHydraxEnabled)
		{
			Application* app=Application::getSingletonPtr();
			Camera* cam=app->getCamera();
			SceneManager* sm=app->getSceneMgr();
			RenderWindow* win=app->getWindow();

			mHydrax=new Hydrax::Hydrax(sm, cam, win->getViewport(0));

			Hydrax::Module::ProjectedGrid* module=new Hydrax::Module::ProjectedGrid(
				mHydrax,
				new Hydrax::Noise::Perlin(),
				Ogre::Plane(Vector3::UNIT_Y, Ogre::Vector3(0, 0, 0)),
				Hydrax::MaterialManager::NM_VERTEX,
				Hydrax::Module::ProjectedGrid::Options()
				);
			mHydrax->setModule(static_cast<Hydrax::Module::Module*>(module));
			
			mHydrax->loadCfg("HydraxDemo.hdx");

			mHydrax->create();
			mHydraxLoaded=true;
		}
		else
		{
			loadOgreOcean();
		}
	}
}

void HydraxManager::enableHydrax(bool enabled)
{
	this->mHydraxEnabled=enabled;
}

void HydraxManager::unloadHydrax()
{
	if(mHydraxLoaded)
	{
		if(mHydraxEnabled)
		{
			if(mHydrax != NULL)
			{
				delete mHydrax;
				mHydrax=NULL;
			}
		}
		else
		{
			unloadOgreOcean();
		}
		mHydraxLoaded=false;
	}
}

bool HydraxManager::isHydraxLoaded() const
{
	return mHydraxLoaded;
}