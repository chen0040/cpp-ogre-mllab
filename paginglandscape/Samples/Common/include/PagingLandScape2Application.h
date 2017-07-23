
/**
    @file
        LandScape.h
    @brief
        Specialisation of OGRE's framework application to show the
        LandScape rendering plugin
*/
#ifndef PagingLandScapeApplication_H
#define PagingLandScapeApplication_H

#include "ExampleApplication.h"

#include "OgreStringConverter.h"
#include "OgreSphere.h"
#include "OgrePanelOverlayElement.h"

using namespace Ogre;

#include "OgrePagingLandScapeRaySceneQuery.h"
#include "OgrePagingLandScapeListenerManager.h"


#include "PagingLandScape2Terrainlistener.h"
#include "PagingLandScape2Overlay.h"
#include "PagingLandScape2FrameListener.h"


class PagingLandScapeApplication : public ExampleApplication
{
    public:
        //-----------------------------------------------------------------------
    	PagingLandScapeApplication()
	    {
            mPagingFrameListener = 0;
	    }
        //-----------------------------------------------------------------------
    	~PagingLandScapeApplication()
        {
            if (mPagingFrameListener)
                delete mPagingFrameListener;
        }

protected:

		// These internal methods package up the stages in the startup process
		/** Sets up the application - returns false if the user chooses to abandon configuration. */
		virtual bool setup(void)
		{
			mRoot = new Root("plugins.cfg", "plsm2_display.cfg", "plsm2.log");

// Linux plugin is created as Plugin_PagingLandScape2.so and set up to run
// via the plugins.cfg config file
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32     
#ifdef _DEBUG
			Root::getSingleton().loadPlugin("Plugin_PagingLandScapeSceneManager2_d");
#else
			Root::getSingleton().loadPlugin("Plugin_PagingLandScapeSceneManager2");
#endif
#endif

			setupResources();

			bool carryOn = configure();
			if (!carryOn) return false;

			chooseSceneManager();
			createCamera();
			createViewports();

			// Set default mipmap level (NB some APIs ignore this)
			TextureManager::getSingleton().setDefaultNumMipmaps(20);

			// Create any resource listeners (for loading screens)
			createResourceListener();
			// Load resources
			loadResources();

			// Create the scene
			createScene();

			createFrameListener();

			return true;

		}
		/// Method which will define the source of resources (other than current folder)
		void setupResources(void)
		{
			// Load resource paths from config file
			ConfigFile cf;
			cf.load("resources.cfg");

			// Go through all sections & settings in the file
			ConfigFile::SectionIterator seci = cf.getSectionIterator();

			String secName, typeName, archName;
			while (seci.hasMoreElements())
			{
				secName = seci.peekNextKey();
				ConfigFile::SettingsMultiMap *settings = seci.getNext();
				ConfigFile::SettingsMultiMap::iterator i;
				for (i = settings->begin(); i != settings->end(); ++i)
				{
					typeName = i->first;
					archName = i->second;
					ResourceGroupManager::getSingleton().addResourceLocation(
						archName, typeName, secName);
				}
			}
	
			// if folders aren't in the resources.cfg try some others as well
		    ResourceGroupManager *rsm = ResourceGroupManager::getSingletonPtr();
		    StringVector groups = rsm->getResourceGroups();        
		    if (std::find(groups.begin(), groups.end(), String("PLSM2")) == groups.end())
            {
                FileInfoListPtr finfo =  ResourceGroupManager::getSingleton().findResourceFileInfo (
                "Bootstrap", "axes.mesh");
                const bool isSDK =  (!finfo->empty()) && 
                StringUtil::startsWith (finfo->begin()->archive->getName(), "../../media/packs/ogrecore.zip", true);


				rsm->createResourceGroup("PLSM2");
				if (isSDK)
                {
                    rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2","FileSystem", "PLSM2");

                    rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/models","FileSystem", "PLSM2");
                    rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/overlays","FileSystem", "PLSM2");
                    rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/materials","FileSystem", "PLSM2");

                    rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/materials/scripts","FileSystem", "PLSM2");
                    rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/materials/textures","FileSystem", "PLSM2");
                    rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/materials/programs","FileSystem", "PLSM2");

                    rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/datasrcs","FileSystem", "PLSM2");
                    rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/terrains","FileSystem", "PLSM2");
                }
                else
                {
                    rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2","FileSystem", "PLSM2");

                    rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/models","FileSystem", "PLSM2");
                    rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/overlays","FileSystem", "PLSM2");
                    rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/materials","FileSystem", "PLSM2");

                    rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/materials/scripts","FileSystem", "PLSM2");
                    rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/materials/textures","FileSystem", "PLSM2");
                    rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/materials/programs","FileSystem", "PLSM2");

                    rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/datasrcs","FileSystem", "PLSM2");
                    rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/terrains","FileSystem", "PLSM2");
                }
		    }
		}
        //-----------------------------------------------------------------------
    	virtual void createFrameListener(void)
	    {
		    mPagingFrameListener= new PagingLandScapeFrameListener(mWindow,
                                    mCamera, false, true);

		    mRoot->addFrameListener(mPagingFrameListener);
	    }
        //-----------------------------------------------------------------------
    	virtual void chooseSceneManager(void)
	    {
            bool notFound = true;
		    // Get the SceneManager, in this case the Paging LandScape specialization
            SceneManagerEnumerator::MetaDataIterator it = mRoot->getSceneManagerMetaDataIterator();
            while (it.hasMoreElements ())
            {
                const SceneManagerMetaData* metaData = it.getNext ();

                /// A mask describing which sorts of scenes this manager can handle
                if (metaData->sceneTypeMask == ST_EXTERIOR_REAL_FAR && 
                    metaData->worldGeometrySupported == true &&
                    metaData->typeName == "PagingLandScapeSceneManager")
                {
                    notFound = false;
                    break;
                }
            }
            if (notFound)
            {
                OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, "Could not find Paging Landscape plugin. Check if it's in plugins.cfg.",
                                               "chooseSceneManager");
            }

		    mSceneMgr = mRoot->createSceneManager("PagingLandScapeSceneManager", "PagingLandScapeDemo" );
	    }
        //-----------------------------------------------------------------------
    	virtual void createCamera(void)
	    {
		    // Create the camera
		    mCamera = mSceneMgr->createCamera( "PlayerCam" );

		    Vector3 pos(128,25,128);
            //Vector3 pos(3085, 0, 3085);

		    mCamera->lookAt( pos );
		    // Place the camera a little over the terrain
		    pos.y += 38700;
		    // Position it at 500 in Z direction
		    mCamera->setPosition( pos );
			mCamera->setNearClipDistance(5);
	    }
        //-----------------------------------------------------------------------
    	virtual void createViewports(void)
	    {
		    // Create one viewport, entire window
		    Viewport* vp = mWindow->addViewport(mCamera);
		    vp->setBackgroundColour(ColourValue::Blue);
			mCamera->setAspectRatio(
				(Real)vp->getActualWidth() /  vp->getActualHeight());
		}
		//-----------------------------------------------------------------------
		/// Optional override method where you can perform resource group loading
		/// Must at least do ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
		virtual void loadResources(void)
		{
			// Initialise, parse scripts etc
			//ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
			ResourceGroupManager::getSingleton().initialiseResourceGroup(ResourceGroupManager::BOOTSTRAP_RESOURCE_GROUP_NAME);
			ResourceGroupManager::getSingleton().initialiseResourceGroup("General");
			ResourceGroupManager::getSingleton().initialiseResourceGroup("PLSM2");

		}
        //-----------------------------------------------------------------------
    	// Just override the mandatory create scene method
	    void createScene(void)
	    {
			mSceneMgr->setWorldGeometry( Ogre::String("paginglandscape2.cfg") );
		    // Set ambient light
            mSceneMgr->setAmbientLight( ColourValue (0.7f, 0.7f, 0.7f));//g_DayColor );
  
			//lights
			Vector3 LightPos(0.0f, 0.0f, 0.0f);

			mLight = mSceneMgr->createLight("MainLight");

			mLight->setPosition(LightPos);

			mLight->setDiffuseColour(0.93f, 0.93f, 0.93f);
			mLight->setAttenuation(10000.0f, 1.0f, 1.0f, 0.0f);

			mLight->setType (Light::LT_DIRECTIONAL);
			mLight->setDirection (Vector3( -1, -1, 0 ));

			SceneNode *BaseNode = mSceneMgr->getRootSceneNode()->createChildSceneNode ("LightHandler");
			BaseNode->setPosition (-3500.0f, 0.0f, -2600.0f);
			mLightNode = BaseNode->createChildSceneNode ("LightHandlerSon");
			mLightNode->setPosition (0.0f, 15000.0f, 0.0f);
			mLightNode->attachObject (mLight);

			BillboardSet* LightSet = mSceneMgr->createBillboardSet("RedYellowLights");
			LightSet->setMaterialName("Examples/Flare");
			mLightNode->attachObject(LightSet);

			Billboard* LightBoard = LightSet->createBillboard(LightPos);
			//LightBoard->setDimensions(10.0f, 10.0f);
			LightBoard->setColour(ColourValue(1.0f, 1.0f, 0.2f, 1.0f));
		}

	protected:
		Light*                      		mLight;
		SceneNode*                  		mLightNode;
		PagingLandScapeFrameListener*    	mPagingFrameListener;
};



#endif
