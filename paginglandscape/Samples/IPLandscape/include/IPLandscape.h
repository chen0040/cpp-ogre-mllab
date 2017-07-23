/*
-----------------------------------------------------------------------------
This source file is part of OGRE
    (Object-oriented Graphics Rendering Engine)
For the latest info, see http://ogre.sourceforge.net/

Copyright © 2000-2002 The OGRE Team
Also see acknowledgements in Readme.html

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
-----------------------------------------------------------------------------
*/

/**
    @file 
        LandScape.h
    @brief
        Specialisation of OGRE's framework application to show the
        LandScape rendering plugin 
*/
#include "ExampleApplication.h"
#include "OgreStringConverter.h"
#include "OgreSphere.h"

#define FOG_Value 0.00005

RaySceneQuery* raySceneQuery = 0;

class PagingLandScapeListener : public ExampleFrameListener
{
public:
	PagingLandScapeListener(RenderWindow* win, Camera* cam) :ExampleFrameListener(win, cam) { };

	float mSplitFactor;
	int mMaxNumTilesMergesProcess;
	int mMaxNumTilesSplitsProcess;
	int mMaxNumRenderablesMorphProcess;
	int mMaxNumRenderablesDeMorphProcess;
	int mNumVisibleRenderables;

	// Override frameStarted event to process that (don't care about frameEnded)
	bool frameStarted(const FrameEvent& evt)
	{
		float moveScale;
		Radian rotScale;
		// local just to stop toggles flipping too fast
		static bool bWireframe = false;
		static bool bFog = true;
		static bool bNodes = false;
		static bool bBoxes = false;
		static Real timeUntilNextToggle = 0;

		static Ray updateRay;
		float height = 0;
		updateRay.setOrigin(mCamera->getPosition());
		updateRay.setDirection(Vector3::NEGATIVE_UNIT_Y);
		raySceneQuery->setRay(updateRay);
		RaySceneQueryResult& qryResult = raySceneQuery->execute();
		RaySceneQueryResult::iterator i = qryResult.begin();
		if (i != qryResult.end() && i->worldFragment)
		{
			SceneQuery::WorldFragment* wf = i->worldFragment;
			height = i->worldFragment->singleIntersection.y;
			mCamera->setPosition(mCamera->getPosition().x, 
				height + 10, 
				mCamera->getPosition().z);
		}

		// Recover the Configuration options for the landScape plug-in
		mCamera->getSceneManager()->getOption( "SplitFactor", &mSplitFactor );
		mCamera->getSceneManager()->getOption( "MaxNumTilesMergesProcess", &mMaxNumTilesMergesProcess );
		mCamera->getSceneManager()->getOption( "MaxNumTilesSplitsProcess", &mMaxNumTilesSplitsProcess );
		mCamera->getSceneManager()->getOption( "MaxNumRenderablesMorphProcess", &mMaxNumRenderablesMorphProcess );
		mCamera->getSceneManager()->getOption( "MaxNumRenderablesDeMorphProcess", &mMaxNumRenderablesDeMorphProcess );
		mCamera->getSceneManager()->getOption( "VisibleRenderables", &mNumVisibleRenderables );

		Vector3 pos = mCamera->getPosition();

		//Debug Overlay
		if ( mCamera->getSceneManager()->getOverlay( "PagingLandScape/DebugOverlay" ) -> isVisible() == true )
		{
			// Show pulgin Status
			int Aux1, Aux2, Aux3, Aux4;
			mCamera->getSceneManager()->getOption( "CurrentCameraPageX", &Aux1 );
			mCamera->getSceneManager()->getOption( "CurrentCameraPageZ", &Aux2 );
			mCamera->getSceneManager()->getOption( "", &Aux3 );
			mCamera->getSceneManager()->getOption( "", &Aux4 );
			GuiManager::getSingleton().getOverlayElement("PagingLandScape/Page")->setCaption( "Page (X, Z): (" + 
				StringConverter::toString(Aux1) + ", " + 
				StringConverter::toString(Aux2) + ")" );

			mCamera->getSceneManager()->getOption( "TileFree", &Aux1 );
			mCamera->getSceneManager()->getOption( "MaxNumTiles", &Aux2 );
			GuiManager::getSingleton().getOverlayElement("PagingLandScape/FreeTiles")->setCaption( "Tiles (Used, Free): (" + 
				StringConverter::toString(Aux2 - Aux1) + ", " + 
				StringConverter::toString(Aux1) + ")" );

			mCamera->getSceneManager()->getOption( "RenderableFree", &Aux1 );
			mCamera->getSceneManager()->getOption( "MaxNumRenderables", &Aux2 );
			mCamera->getSceneManager()->getOption( "RenderableLoading", &Aux3 );
			GuiManager::getSingleton().getOverlayElement("PagingLandScape/FreeRenderables")->setCaption( "Renderables (Used, Free, Loading, Visibles): (" + 
				StringConverter::toString(Aux2 - Aux1) + ", " + 
				StringConverter::toString(Aux1) + ", " +
				StringConverter::toString(Aux3) + ", " +
				StringConverter::toString(mNumVisibleRenderables) + ")" );

			GuiManager::getSingleton().getOverlayElement("PagingLandScape/Player")->setCaption( "Player (X, Y, Z): (" + 
				StringConverter::toString(pos.x) + ", " + 
				StringConverter::toString(pos.y) + ", " +
				StringConverter::toString(pos.z) + ")" );

			mCamera->getSceneManager()->getOption( "PagePreloadQueue", &Aux1 );
			mCamera->getSceneManager()->getOption( "PageLoadQueue", &Aux2 );
			mCamera->getSceneManager()->getOption( "PageUnloadQueue", &Aux3 );
			mCamera->getSceneManager()->getOption( "PagePostUnloadQueue", &Aux4 );
			GuiManager::getSingleton().getOverlayElement("PagingLandScape/MainQueue")->setCaption( "Queues (PreLoad, Load, Unload, PostUnload): (" + 
				StringConverter::toString(Aux1) + ", " + 
				StringConverter::toString(Aux2) + ", " +
				StringConverter::toString(Aux3) + ", " +
				StringConverter::toString(Aux4) + ")" );
		}

		if (timeUntilNextToggle >= 0)
		{
			timeUntilNextToggle -= evt.timeSinceLastFrame;
		}

		// If this is the first frame, pick a speed
		if (evt.timeSinceLastFrame == 0)
		{
			moveScale = 1;
			rotScale = Degree(0.1);
		}
		// Otherwise scale movement units by time passed since last frame
		else
		{
			// Move about 100 units per second,
			moveScale = 50.0 * evt.timeSinceLastFrame;
			// Take about 10 seconds for full rotation
			rotScale = Degree(36 * evt.timeSinceLastFrame);
		}

		// Grab input device state
		mInputDevice->capture();

		static Vector3 vec;

		vec = Vector3::ZERO;

		if ( mInputDevice->isKeyDown(KC_F2) && timeUntilNextToggle <= 0 )
		{
			mWindow->setDebugText("Terrain Height = " + StringConverter::toString(height));

			timeUntilNextToggle = 0.5;
		}

		if ( mInputDevice->isKeyDown(KC_F3) && timeUntilNextToggle <= 0 )
		{
			Sphere newHeight = Sphere(pos, 100);
			if ( mCamera->getSceneManager()->getOption( "AddNewHeight", &newHeight ) == true )
			{
				mWindow->setDebugText(String("Add New Height"));						
			}
			timeUntilNextToggle = 0.5;
		}
		if ( mInputDevice->isKeyDown(KC_F4) && timeUntilNextToggle <= 0 )
		{
			Sphere newHeight = Sphere(pos, 100);
			if ( mCamera->getSceneManager()->getOption( "RemoveNewHeight", &newHeight ) == true )
			{
				mWindow->setDebugText(String("Remove New Height"));
			}
			timeUntilNextToggle = 0.5;
		}
		if ( mInputDevice->isKeyDown(KC_F5) && timeUntilNextToggle <= 0 )
		{
			if ( bFog )
			{
				mCamera->getSceneManager()->setFog( FOG_NONE );
			}
			else
			{
				mCamera->getSceneManager()->setFog( FOG_EXP2, ColourValue(), FOG_Value );
			}
			bFog = !bFog;
			timeUntilNextToggle = 0.5;
		}
		if ( mInputDevice->isKeyDown(KC_F11) && timeUntilNextToggle <= 0 )
		{
			mNumVisibleRenderables--;
			mCamera->getSceneManager()->setOption( "VisibleRenderables", &mNumVisibleRenderables );
			timeUntilNextToggle = 0.5;
		}
		if ( mInputDevice->isKeyDown(KC_F12) && timeUntilNextToggle <= 0 )
		{
			mNumVisibleRenderables++;
			mCamera->getSceneManager()->setOption( "VisibleRenderables", &mNumVisibleRenderables );
			timeUntilNextToggle = 0.5;
		}
		// use CTRL key for boost
		if (mInputDevice->isKeyDown(KC_LCONTROL) || mInputDevice->isKeyDown(KC_SPACE))
		{
			moveScale = moveScale * 30;
		}

		if (mInputDevice->isKeyDown(KC_A))
		{
			// Move camera left
			vec.x = -moveScale;
		}

		if (mInputDevice->isKeyDown(KC_D))
		{
			// Move camera RIGHT
			vec.x = moveScale;
		}

		if (mInputDevice->isKeyDown(KC_UP) || mInputDevice->isKeyDown(KC_W))
		{
			// Move camera forward
			vec.z = -moveScale;
		}

		if (mInputDevice->isKeyDown(KC_DOWN) || mInputDevice->isKeyDown(KC_S))
		{
			// Move camera backward
			vec.z = moveScale;
		}

		if (mInputDevice->isKeyDown(KC_PGUP))
		{
			// Move camera up
			vec.y = moveScale;
		}

		if (mInputDevice->isKeyDown(KC_PGDOWN))
		{
			// Move camera down
			vec.y = -moveScale;
		}

		if (mInputDevice->isKeyDown(KC_RIGHT))
		{
			mCamera->yaw(-rotScale);
		}
		if (mInputDevice->isKeyDown(KC_LEFT))
		{
			mCamera->yaw(rotScale);
		}

		if (mInputDevice->isKeyDown(KC_1))
		{
			mSplitFactor += 0.1;
			mCamera->getSceneManager()->setOption( "SplitFactor", (float*)&mSplitFactor );
		}
		if (mInputDevice->isKeyDown(KC_2))
		{
			mSplitFactor -= 0.1;
			mCamera->getSceneManager()->setOption( "SplitFactor", (float*)&mSplitFactor );
		}

		if (mInputDevice->isKeyDown(KC_3))
		{
			mMaxNumTilesMergesProcess += 1;
			mCamera->getSceneManager()->setOption( "MaxNumTilesMergesProcess", (int*)&mMaxNumTilesMergesProcess );
		}
		if (mInputDevice->isKeyDown(KC_4))
		{
			mMaxNumTilesMergesProcess -= 1;
			mCamera->getSceneManager()->setOption( "MaxNumTilesMergesProcess", (int*)&mMaxNumTilesMergesProcess );
		}

		if (mInputDevice->isKeyDown(KC_5))
		{
			mMaxNumTilesSplitsProcess += 1;
			mCamera->getSceneManager()->setOption( "MaxNumTilesSplitsProcess", (int*)&mMaxNumTilesSplitsProcess );
		}
		if (mInputDevice->isKeyDown(KC_6))
		{
			mMaxNumTilesSplitsProcess -= 1;
			mCamera->getSceneManager()->setOption( "MaxNumTilesSplitsProcess", (int*)&mMaxNumTilesSplitsProcess );
		}

		if (mInputDevice->isKeyDown(KC_7))
		{
			mMaxNumRenderablesMorphProcess += 1;
			mCamera->getSceneManager()->setOption( "MaxNumRenderablesMorphProcess", (int*)&mMaxNumRenderablesMorphProcess );
		}
		if (mInputDevice->isKeyDown(KC_8))
		{
			mMaxNumRenderablesMorphProcess -= 1;
			mCamera->getSceneManager()->setOption( "MaxNumRenderablesMorphProcess", (int*)&mMaxNumRenderablesMorphProcess );
		}

		if (mInputDevice->isKeyDown(KC_9))
		{
			mMaxNumRenderablesDeMorphProcess += 1;
			mCamera->getSceneManager()->setOption( "MaxNumRenderablesDeMorphProcess", (int*)&mMaxNumRenderablesDeMorphProcess );
		}
		if (mInputDevice->isKeyDown(KC_0))
		{
			mMaxNumRenderablesDeMorphProcess -= 1;
			mCamera->getSceneManager()->setOption( "MaxNumRenderablesDeMorphProcess", (int*)&mMaxNumRenderablesDeMorphProcess );
		}

		if( mInputDevice->isKeyDown(KC_ESCAPE) )
		{            
			return false;
		}

		// Rotate view by mouse relative position
		Radian rotX, rotY;
		rotX = Degree(-mInputDevice->getMouseRelativeX() * 0.13);
		rotY = Degree(-mInputDevice->getMouseRelativeY() * 0.13);


		// Make all the changes to the camera
		// Note that YAW direction is around a fixed axis (freelook stylee) rather than a natural YAW (e.g. airplane)
		mCamera->yaw(rotX);
		mCamera->pitch(rotY);
		mCamera->moveRelative(vec);

		// Rotate scene node if required
		SceneNode* node = mCamera->getSceneManager()->getRootSceneNode();
		if (mInputDevice->isKeyDown(KC_O))
		{
			node->yaw(rotScale);
		}
		if (mInputDevice->isKeyDown(KC_P))
		{
			node->yaw(-rotScale);
		}
		if (mInputDevice->isKeyDown(KC_I))
		{
			node->pitch(rotScale);
		}
		if (mInputDevice->isKeyDown(KC_K))
		{
			node->pitch(-rotScale);
		}

		if (mInputDevice->isKeyDown(KC_F) && timeUntilNextToggle <= 0)
		{
			mStatsOn = !mStatsOn;
			showDebugOverlay(mStatsOn);

			timeUntilNextToggle = 1;
		}

		// Toggle between Wireframe and Solid rendering
		if (mInputDevice->isKeyDown(KC_T) && timeUntilNextToggle <= 0)
		{
			bWireframe = !bWireframe;
			if (bWireframe)
			{
				mCamera->setDetailLevel(SDL_WIREFRAME);
				showDebugOverlay(false);
				mCamera->getSceneManager()->getOverlay( "PagingLandScape/DebugOverlay" ) -> hide();
			}
			else
			{
				mCamera->setDetailLevel(SDL_SOLID);
				showDebugOverlay(true);
				mCamera->getSceneManager()->getOverlay( "PagingLandScape/DebugOverlay" ) -> show();
			}
			timeUntilNextToggle = 0.5;
		}				

		// Capture the screen to a png graphics file
		if (mInputDevice->isKeyDown(KC_SYSRQ) && timeUntilNextToggle <= 0)
		{
			char tmp[35];
			sprintf(tmp, "Demo_IPLandscape_%d.png", ++mNumScreenShots);
			mWindow->writeContentsToFile(tmp);
			mWindow->setDebugText(String("Wrote ") + tmp);
			timeUntilNextToggle = 0.5;
		}

		// Show or hide Debug Overlay
		if (mInputDevice->isKeyDown(KC_F1) && timeUntilNextToggle <= 0)
		{
			if ( mCamera->getSceneManager()->getOverlay( "PagingLandScape/DebugOverlay" ) -> isVisible() == true )
			{
				mCamera->getSceneManager()->getOverlay( "PagingLandScape/DebugOverlay" ) -> hide();
			}
			else
			{
				mCamera->getSceneManager()->getOverlay( "PagingLandScape/DebugOverlay" ) -> show();
			}
			timeUntilNextToggle = 0.5;
		}

		// Return true to continue rendering
		return true;
	}

};


class PagingLandScapeApplication : public ExampleApplication
{
public:
	PagingLandScapeApplication()
	{
		//Naranja
		//mDayColor = ColourValue(0.9375, 0.72265625, 0.41015625);
		//Azul
		//mDayColor = ColourValue(0.57421875, 0.640625, 0.9921875);
		// Blanca
		mDayColor = ColourValue();
	}

protected:

	unsigned int mNumScreenShots;
	ColourValue mDayColor;

	virtual void createFrameListener(void)
	{
		mFrameListener= new PagingLandScapeListener(mWindow, mCamera);
		mRoot->addFrameListener(mFrameListener);
	}


	virtual void chooseSceneManager(void)
	{
		// Get the SceneManager, in this case the Paging LandScape specialization
		mSceneMgr = mRoot->getSceneManager( ST_EXTERIOR_REAL_FAR );
		mSceneMgr->setWorldGeometry( "IPLSceneManager.cfg" );
	}

	virtual void createCamera(void)
	{
		// Create the camera
		mCamera = mSceneMgr->createCamera( "PlayerCam" );

		Vector3 pos = Vector3(85, 0, 85);
/*
		RaySceneQuery* mRayQuery = mSceneMgr->createRayQuery( Ray(pos, Vector3::UNIT_Y) );
		RaySceneQueryResult& results = mRayQuery->execute();
		// Get the height
		pos.y = (*results.begin()).worldFragment->singleIntersection.y;
		// Destroy the query
		mCamera->getSceneManager()->destroyQuery(mRayQuery);
		// Look back along -Z
*/
		mCamera->lookAt( pos );
		// Place the camera a little over the terrain
		pos.y += 100;//3100;
		// Position it at 500 in Z direction
		mCamera->setPosition( pos );
		mCamera->setNearClipDistance( 1 );
		mCamera->setFarClipDistance( 100000 );
	}

	virtual void createViewports(void)
	{
		// Create one viewport, entire window
		Viewport* vp = mWindow->addViewport(mCamera);
		vp->setBackgroundColour( mDayColor );
	}

	// Just override the mandatory create scene method
	void createScene(void)
	{
		// Debug Overlay
		//mSceneMgr->getOverlay( "PagingLandScape/DebugOverlay" ) -> show();
		// Set ambient light
		mSceneMgr->setAmbientLight( mDayColor );

		Light* l = mSceneMgr->createLight("MainLight");		
		l->setPosition(0,800,0);
//		l->setDiffuseColour(0.93, 0.93, 0.93);
//		l->setAttenuation(10000, 1.0, 1.0, 0);

		// Create a light
		//Light* l = mSceneMgr->createLight("MainLight");
		// Accept default settings: point light, white diffuse, just set position
		// NB I could attach the light to a SceneNode if I wanted it to move automatically with
		//  other objects, but I don't
		//l->setPosition(20,800,50);

		// Tipo de niebla, Color, zona limpia(cuanto menor el numero mayor zona sin niebla, densidad inicial, densidad final
		//mSceneMgr->setFog( FOG_EXP2, ColourValue::White, .002, .1, 0.7 );
		//mSceneMgr->setFog( FOG_LINEAR, ColourValue(1,0.98,0.94), 1, 200, 500 );
		float tmp;
		mSceneMgr->getOption( "VisibleDistance", &tmp);
		//mSceneMgr->setFog( FOG_LINEAR, ColourValue(1.0, 0.98, 0.94), 0.0005, tmp - 1000, tmp - 500 );
		//mSceneMgr->setFog( FOG_LINEAR, ColourValue(0.9375, 0.72265625, 0.41015625), 0.0005, tmp - 1000, tmp - 500 );
		mSceneMgr->setFog( FOG_EXP2, mDayColor, FOG_Value );
		//mSceneMgr->setFog( FOG_LINEAR, ColourValue(0.57421875, 0.640625, 0.9921875), 0, tmp - 1000, tmp - 600 );


		// Define the required curve sky plane 
		Plane plane; 
		// 3000 world units from the camera 
		plane.d = 3000;
		// Above the camera, facing down 
		plane.normal = -Vector3::UNIT_Y; 
		// Create a curved sky plane 10000 units wide, tile the texture 3 
		// times, and curve height is 0.5 of the sky plane's width. 
		mSceneMgr->setSkyPlane( true, plane, "Examples/CloudySky", 3000, 27, true, 0.35f);
		mSceneMgr->getMaterial("Examples/CloudySky")->setFog( true, FOG_NONE );//FOG_EXP, mDayColor, 0.00005 );

		//showDebugOverlay( true );
		mSceneMgr->getOverlay( "PagingLandScape/DebugOverlay" )->show();

		raySceneQuery = mSceneMgr->createRayQuery(Ray(mCamera->getPosition(), Vector3::NEGATIVE_UNIT_Y));

		// Add the water
/*
		Entity *ent; 

		Plane p; 
		p.normal = Vector3::UNIT_Y; 
		p.d = 50.0;
		MeshManager::getSingleton().createPlane("WaterPlane",p,400,400,20,20,true,1,50,50,Vector3::UNIT_Z); 

		// Create an entity (the floor) 
		ent = mSceneMgr->createEntity("water", "WaterPlane"); 
		ent->setMaterialName("Examples/TransparentTest"); 

		static_cast<SceneNode*>(mSceneMgr->getRootSceneNode()->createChild())->attachObject(ent);
*/
	}

};
