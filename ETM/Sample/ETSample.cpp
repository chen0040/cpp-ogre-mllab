//#include <OgreNoMemoryMacros.h>
#include <CEGUI/CEGUISystem.h>
#include <CEGUI/CEGUISchemeManager.h>
#include <OgreCEGUIRenderer.h>

#include "ExampleApplication.h"

#include "ETTerrainManager.h"
#include "ETTerrainInfo.h"
#include "ETBrush.h"
#include "ETSplattingManager.h"

using namespace std;
using Ogre::uint;

class DemoListener : public ExampleFrameListener, public OIS::MouseListener, public OIS::KeyListener
{
public:

  DemoListener(RenderWindow* win, Camera* cam, SceneManager *sceneManager, CEGUI::Renderer *renderer, ET::TerrainManager* terrainMgr, ET::SplattingManager* splatMgr)
    : ExampleFrameListener(win, cam, true, true), mGUIRenderer(renderer), mTerrainMgr(terrainMgr), mTerrainInfo(&terrainMgr->getTerrainInfo()), mSplatMgr(splatMgr)
    {
      // Setup default variables
      mPointer = NULL;
      mLMouseDown = false;
      mRMouseDown = false;
      mMMouseDown = false;
      mSceneMgr = sceneManager;

      // Reduce move speed
      mMoveSpeed = 320;
      mRotateSpeed *= 0.008;

      // Register this so that we get events.
      mMouse->setEventCallback( this );
      mKeyboard->setEventCallback(this);

      // Create RaySceneQuery
      mRaySceneQuery = mSceneMgr->createRayQuery( Ray() );

      // Create a "pointer" for use on the terrain
      Entity* pointer = mSceneMgr->createEntity("Pointer", "ogrehead.mesh");
      mPointer = mSceneMgr->getRootSceneNode()->createChildSceneNode();
      mPointer->attachObject(pointer);

      // initialise CEGUI mouse cursor position
      CEGUI::MouseCursor::getSingleton().setPosition(CEGUI::Point(CEGUI::Vector2(0,0)));

      createEditBrush();
      mDeform = true;
      mChosenTexture = 0;

      mDirection = Vector3::ZERO;

      mContinue = true;

      mCamNode = mCamera->getParentSceneNode();
    }

    ~DemoListener( )
    {
      delete mRaySceneQuery;
    }


    void createEditBrush()
    {
      // load the edit brush for terrain editing
      Image image;
      image.load("brush.png", "ET");
      image.resize(16, 16);
      mEditBrush = ET::loadBrushFromImage(image);
    }


    bool frameStarted(const FrameEvent &evt)
    {
      if (!ExampleFrameListener::frameStarted( evt ))
        return false;

      // handle movement
      mCamNode->translate(mCamera->getOrientation()*mDirection*mMoveSpeed*evt.timeSinceLastFrame);

      // Ensure we stay above terrain (somehow buggy still, doesn't work reliably)
      Vector3 camPos = mCamNode->getPosition( );
      // get terrain height at camPos
      float terrainHeight = mTerrainInfo->getHeightAt(camPos.x, camPos.z);
      if ((terrainHeight + 30.0f) > camPos.y)
        mCamNode->setPosition(camPos.x, terrainHeight+30.0f, camPos.z);

      if (mLMouseDown || mRMouseDown)
      {
        // deform or paint terrain on mouse down
        // left button raises, right button lowers
        if (mDeform)
        {
          // choose a brush intensity, this determines
          // how extreme our brush works on the terrain
          float brushIntensity = evt.timeSinceLastFrame * 0.4 * (mLMouseDown? 1 : -1);
          // translate our cursor position to vertex indexes
          Vector3 deformPos = mPointer->getPosition();
          int x = mTerrainInfo->posToVertexX(deformPos.x);
          int z = mTerrainInfo->posToVertexZ(deformPos.z);
          // now tell the ETM to deform the terrain
          mTerrainMgr->deform(x, z, mEditBrush, brushIntensity);
        }
        else
        {
          // need to set our brush intensity larger for painting.
          // for painting, all texture channels are only 1 byte
          // large, so with a small intensity you won't get any
          // effect at all.
          float brushIntensity = evt.timeSinceLastFrame * 5.0 * (mLMouseDown? 1 : -1);
          // retrieve edit points
          Vector3 paintPos = mPointer->getPosition();
          int x = mTerrainInfo->posToVertexX(paintPos.x);
          int z = mTerrainInfo->posToVertexZ(paintPos.z);
          // now use the splatting manager to update the coverage maps
          mSplatMgr->paint(mChosenTexture, x, z, mEditBrush, brushIntensity);
        }
      }
      return mContinue;
    }


   virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
   {
     // Left mouse button down
     if ( id == OIS::MB_Left )
     {
       mLMouseDown = true;
     }
     // Middle mouse button down
     else if ( id == OIS::MB_Middle )
     {
       CEGUI::MouseCursor::getSingleton().hide( );
       mMMouseDown = true;
     }

     else if (id == OIS::MB_Right)
     {
       mRMouseDown = true;
     }

     return true;
   }

   virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
   {
     // Left mouse button up
     if ( id == OIS::MB_Left )
     {
       mLMouseDown = false;
       // after completed deformation steps, recalculate the lightmap
       if (mDeform)
         updateLightmap();
     }

     // Middle mouse button up
     else if ( id == OIS::MB_Middle )
     {
       CEGUI::MouseCursor::getSingleton().show( );
       mMMouseDown = false;
     }

     else if (id == OIS::MB_Right)
     {
       mRMouseDown = false;
       // after completed deformation steps, recalculate the lightmap
       if (mDeform)
         updateLightmap();
     }

     return true;
   }

   virtual bool mouseMoved( const OIS::MouseEvent &arg )
   {
     // Update CEGUI with the mouse motion
     CEGUI::System::getSingleton().injectMouseMove( arg.state.X.rel, arg.state.Y.rel );

     // whenever the mouse is moved, we update the position on the
     // terrain to which the mouse is currently pointing
     Ray mouseRay = mCamera->getCameraToViewportRay(arg.state.X.abs/float(arg.state.width), arg.state.Y.abs/float(arg.state.height));
     // since ETM is no longer a scene manager, we don't use a ray scene query,
     // but instead query the terrain info directly
     std::pair<bool, Vector3> result = mTerrainInfo->rayIntersects(mouseRay);
     if (result.first)
     {
       // update pointer's position
       mPointer->setPosition(result.second);
     }

     // If we are dragging the middle mouse button.
     if ( mMMouseDown )
     {
       mCamera->yaw( Degree(-arg.state.X.rel * mRotateSpeed) );
       mCamera->pitch( Degree(-arg.state.Y.rel * mRotateSpeed) );
     }

     return true;
   }


   virtual bool keyPressed(const OIS::KeyEvent& arg)
   {
     // we'll use the keys 1, 2, 3, 4 and E to switch between
     // edit modes and select a paint texture
     // WSAD is used for movement
     // O will save the changes to disk
     switch (arg.key)
     {
     case OIS::KC_1:
       mDeform = false;
       mChosenTexture = 0;
       return true;
     case OIS::KC_2:
       mDeform = false;
       mChosenTexture = 1;
       return true;
     case OIS::KC_3:
       mDeform = false;
       mChosenTexture = 2;
       return true;
     case OIS::KC_4:
       mDeform = false;
       mChosenTexture = 3;
       return true;
     case OIS::KC_5:
       mDeform = false;
       mChosenTexture = 4;
       return true;
     case OIS::KC_6:
       mDeform = false;
       mChosenTexture = 5;
       return true;
     case OIS::KC_E:
       mDeform = true;
       return true;

     case OIS::KC_W:
       mDirection.z += -1;
       return true;
     case OIS::KC_S:
       mDirection.z += 1;
       return true;
     case OIS::KC_A:
       mDirection.x += -1;
       return true;
     case OIS::KC_D:
       mDirection.x += 1;
       return true;

     case OIS::KC_O:
       saveTerrain();
       return true;

     case OIS::KC_P:
       loadTerrain();
       return true;

     case OIS::KC_ESCAPE:
       mContinue = false;
       return true;

     default:
       return false;
     }
   }

   virtual bool keyReleased(const OIS::KeyEvent& arg)
   {
     // not interested in this
     switch (arg.key)
     {
     case OIS::KC_W:
       mDirection.z -= -1;
       return true;
     case OIS::KC_S:
       mDirection.z -= 1;
       return true;
     case OIS::KC_A:
       mDirection.x -= -1;
       return true;
     case OIS::KC_D:
       mDirection.x -= 1;
       return true;

     default:
       return false;
     }
   }


   void saveTerrain()
   {
     // just for demonstration, we'll save anything we can
     // start with the terrain
     Image image;
     ET::saveHeightmapToImage(*mTerrainInfo, image);
     image.save("../../Media/ET/ETterrain.png");

     // now save the splatting maps
     for (uint i = 0; i < mSplatMgr->getNumMaps(); ++i)
     {
       mSplatMgr->saveMapToImage(i, image);
       image.save("../../Media/ET/ETcoverage."+StringConverter::toString(i)+".png");
     }

     // now the lightmap
     Image lightmap;
     ET::createTerrainLightmap(*mTerrainInfo, lightmap, 512, 512, Vector3(1, -1, 1), ColourValue(1,1,1),
       ColourValue(0.3, 0.3,  0.3));
     lightmap.save("../../Media/ET/ETlightmap.png");

     // generate a base texture for this terrain (could be used for older hardware instead of splatting)
     // create an ImageList of our splatting textures.
     ET::ImageList textures (6);
     for (int i = 0; i < 6; ++i)
       textures[i].load("splatting"+StringConverter::toString(i)+".png", "ET");
     // create the base texture
     Image baseTexture;
     mSplatMgr->createBaseTexture(baseTexture, 512, 512, textures, 20, 20);
     baseTexture.save("../../Media/ET/ETbase.png");

     // finally create a minimap using the lightmap and the generated base texture
     Image minimap = ET::createMinimap(baseTexture, lightmap);
     minimap.save("../../Media/ET/ETminimap.png");
   }


   void loadTerrain()
   {
     // now we revert the process and load the data back from disk
     // recreate terrain...
     mTerrainMgr->destroyTerrain();
     Image image;
     image.load("ETterrain.png", "ET");
     ET::TerrainInfo info;
     ET::loadHeightmapFromImage(info, image);
     info.setExtents(AxisAlignedBox(0, 0, 0, 1500, 300, 1500));
     mTerrainMgr->createTerrain(info);
     mTerrainInfo = & mTerrainMgr->getTerrainInfo();

     // now load the splatting maps
     for (uint i = 0; i < mSplatMgr->getNumMaps(); ++i)
     {
       image.load("ETcoverage."+StringConverter::toString(i)+".png", "ET");
       mSplatMgr->loadMapFromImage(i, image);
     }

     // update the lightmap
     updateLightmap();
   }


   void updateLightmap()
   {
     Image lightmap;
     ET::createTerrainLightmap(*mTerrainInfo, lightmap, 128, 128, Vector3(1, -1, 1), ColourValue(1,1,1),
       ColourValue(0.3, 0.3,  0.3));

     // get our dynamic texture and update its contents
     TexturePtr tex = TextureManager::getSingleton().getByName("ETLightmap");
     tex->getBuffer(0, 0)->blitFromMemory(lightmap.getPixelBox(0, 0));
   }


protected:
    RaySceneQuery *mRaySceneQuery;     // The ray scene query pointer
    bool mLMouseDown, mRMouseDown;     // True if the mouse buttons are down
    bool mMMouseDown;
    SceneManager *mSceneMgr;           // A pointer to the scene manager
    SceneNode *mPointer;               // Our "pointer" on the terrain
    CEGUI::Renderer *mGUIRenderer;     // cegui renderer
    ET::Brush mEditBrush;              // Brush for terrain editing
    bool mDeform;                      // stores which mode we are in (deform or paint)
    uint mChosenTexture;                // which of the four splatting textures is to be used?

    // movement
    Vector3 mDirection;
    bool mMove;

    SceneNode* mCamNode;

    bool mContinue;

    ET::TerrainManager* mTerrainMgr;
    const ET::TerrainInfo* mTerrainInfo;
    ET::SplattingManager* mSplatMgr;
};


class DemoETSM : public ExampleApplication
{
private:
    ET::TerrainManager* mTerrainMgr;
    ET::SplattingManager* mSplatMgr;
protected:
    CEGUI::OgreCEGUIRenderer *mGUIRenderer;
    CEGUI::System *mGUISystem;         // cegui system
public:
    DemoETSM()
    {
      mTerrainMgr = 0;
      mSplatMgr = 0;
    }

    ~DemoETSM()
    {
      delete mTerrainMgr;
      delete mSplatMgr;
    }
protected:
    void chooseSceneManager(void)
    {
      // Create instance of the Editable Terrain Scene Manager
      mSceneMgr = mRoot->createSceneManager("OctreeSceneManager", "ETInstance");
    }

    void createScene(void)
    {
      mSceneMgr->setAmbientLight(ColourValue(0.5, 0.5, 0.5));
      //mSceneMgr->setSkyDome(true, "Examples/CloudySky", 5, 8);

      // create terrain manager
      mTerrainMgr = new ET::TerrainManager(mSceneMgr);
      mTerrainMgr->setLODErrorMargin(2, mCamera->getViewport()->getActualHeight());
      mTerrainMgr->setUseLODMorphing(true, 0.2, "morphFactor");

      // create a fresh, mid-high terrain for editing
      ET::TerrainInfo terrainInfo (129, 129, vector<float>(129*129, 0.5f));
      // set position and size of the terrain
      terrainInfo.setExtents(AxisAlignedBox(0, 0, 0, 1500, 300, 1500));
      // now render it
      mTerrainMgr->createTerrain(terrainInfo);

      // create the splatting manager
      mSplatMgr = new ET::SplattingManager("ETSplatting", "ET", 128, 128, 3);
      // specify number of splatting textures we need to handle
      mSplatMgr->setNumTextures(6);

      // create a manual lightmap texture
      TexturePtr lightmapTex = TextureManager::getSingleton().createManual(
        "ETLightmap", "ET", TEX_TYPE_2D, 128, 128, 1, PF_BYTE_RGB);
      Image lightmap;
      ET::createTerrainLightmap(terrainInfo, lightmap, 128, 128, Vector3(1, -1, 1), ColourValue::White,
        ColourValue(0.3, 0.3, 0.3));
      lightmapTex->getBuffer(0, 0)->blitFromMemory(lightmap.getPixelBox(0, 0));

      // load the terrain material and assign it
      MaterialPtr material (MaterialManager::getSingleton().getByName("ETTerrainMaterial"));
      mTerrainMgr->setMaterial(material);

      // Set camera look point
      SceneNode* camNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
      camNode->setPosition( 40, 300, 580 );
      camNode->attachObject(mCamera);
      mCamera->pitch( Degree(-30) );
      mCamera->yaw( Degree(-45) );

      // CEGUI setup
      mGUIRenderer = new CEGUI::OgreCEGUIRenderer(mWindow, Ogre::RENDER_QUEUE_OVERLAY, false, 3000, mSceneMgr);
      mGUISystem = new CEGUI::System(mGUIRenderer);
      CEGUI::SchemeManager::getSingleton().loadScheme((CEGUI::utf8*)"TaharezLookSkin.scheme");
      CEGUI::MouseCursor::getSingleton().setImage("TaharezLook", "MouseArrow");
    }

    void createFrameListener(void)
    {
      mFrameListener= new DemoListener(mWindow, mCamera, mSceneMgr, mGUIRenderer, mTerrainMgr, mSplatMgr);
      mFrameListener->showDebugOverlay(true);
      mRoot->addFrameListener(mFrameListener);
    }

};


#if OGRE_PLATFORM == PLATFORM_WIN32 || OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"

INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
int main(int argc, char **argv)
#endif
{
    // Create application object
    DemoETSM app;

    try {
        app.go();
    } catch( Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
        MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
        fprintf(stderr, "An exception has occured: %s\n",
                e.getFullDescription().c_str());
#endif
    }

    return 0;
}
