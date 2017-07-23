
#include <CEGUI/Cegui.h>
#include <OgreCEGUIRenderer.h>
#include "OgreCEGUIResourceProvider.h"

#include "MapEditorListener.h"

#define PI 3.14159265f
#define DEG2RAD(x) (x * (PI / 180.0f))
#define RAD2DEG(x) (x * (180.0f / PI))

using namespace std;
using namespace OIS;

//-----------------------------------------------------------------------
CEGUI::MouseButton convertOgreButtonToCegui(const int button)
{
	switch (button) 
	{
	case OIS::MB_Left:
		return CEGUI::LeftButton;
	case OIS::MB_Right:
		return CEGUI::RightButton;
	case OIS::MB_Middle:
		return CEGUI::MiddleButton;

		//case OIS:: :
		//	return CEGUI::X1Button;

	default:
		return CEGUI::LeftButton;
	}
}
//------------------------------------------------------------------------------------------------
MapEditorListener::MapEditorListener (RenderWindow* win, 
									  Camera* cam, 
									  CEGUI::Renderer* renderer, 
									  const Ogre::String &terrainPath,
									  bool useBufferedInputKeys, 
									  bool useBufferedInputMouse) : 
        //FrameListener () // not using base class ctor, overriding
        KeyListener (),
        MouseListener(),
        mCamera(cam), 
        mWindow(win), 
        mKeyboard(0), 
        mUseBufferedInputKeys(useBufferedInputKeys), 
        mUseBufferedInputMouse(useBufferedInputMouse), 
        mGuiRenderer(renderer),
        
	    mAmountMovedX(0.0f),
	    mAamountMovedY(0.0f),
		mTerrainPath (terrainPath)
{
	mScnMgr = cam->getSceneManager();

	mMainSceneNode = mScnMgr->getRootSceneNode()->createChildSceneNode();
	mCursorNode = mMainSceneNode->createChildSceneNode();

	mRayQuery = mScnMgr->createRayQuery(Ray(Vector3::ZERO, Vector3::NEGATIVE_UNIT_Y));
	mRayCursorQuery = mScnMgr->createRayQuery(Ray(Vector3::ZERO, Vector3::NEGATIVE_UNIT_Y));


	size_t windowHnd = 0;
	std::ostringstream windowHndStr;
	OIS::ParamList pl;

#if defined OIS_WIN32_PLATFORM
	mWindow->getCustomAttribute("WINDOW", &windowHnd);
#elif defined OIS_LINUX_PLATFORM
	mWindow->getCustomAttribute( "GLXWINDOW", &windowHnd );
#endif    

	// Fill parameter list
	windowHndStr << (unsigned int) windowHnd;
	pl.insert( std::make_pair( std::string( "WINDOW" ), windowHndStr.str() ) );

	// Uncomment these two lines to allow users to switch keyboards via the language bar
	//paramList.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_FOREGROUND") ));
	//paramList.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_NONEXCLUSIVE") ));

	mInputSystem  = OIS::InputManager::createInputSystem( pl );

	//Create all devices (We only catch joystick exceptions here, as, most people have Key/Mouse)
	mKeyboard = static_cast<OIS::Keyboard*>(mInputSystem->createInputObject(OIS::OISKeyboard,  true ));
	mMouse = static_cast<OIS::Mouse*>(mInputSystem->createInputObject( OIS::OISMouse, true ));

	unsigned int width, height, depth;
	int left, top;
	mWindow->getMetrics(width, height, depth, left, top);

	const OIS::MouseState &ms = mMouse->getMouseState();
	ms.width = width;
	ms.height = height;

	mKeyboard->setEventCallback (this);
	mMouse->setEventCallback (this);

	mUseBufferedInputKeys = true;
	mUseBufferedInputMouse = true;
	mKeyboard->setBuffered(mUseBufferedInputKeys);
	mMouse->setBuffered (mUseBufferedInputMouse);

	mDebugOverlay = new DebugTextOverlay("Core/DebugOverlay");

	mRotateSpeed = 4;
	rMouseDown = false;
	endProgram = false;
	morphMode = false;

	mTimeElapsed=0;
	mKeyRate = 0.5f;
	mTimeUntilNextToggle=mKeyRate;

	mCursorSize = 1;
	mCursor = NULL;

	mRotateSpeed = 36;
	mMoveSpeed = 10000;
	mMoveScale = 100;
	mRotScale = 0.1;
	mRotX = 0;
	mRotY = 0;
	mTranslateVector = Vector3::ZERO;
	mKeyClickedNum = 0;

    setBrushSize (10);
	mBrushStrength = 0.02f;
	mScnMgr->setOption("BrushScale", &mBrushStrength);

	setEditMode(EditNothing);
}
//-----------------------------------------------------------------------
MapEditorListener::~MapEditorListener()
{
	mCursorNode->detachAllObjects();
	mMainSceneNode->removeAndDestroyAllChildren();

	delete mDebugOverlay;

	if(mCursor)
		delete mCursor;

	mScnMgr->destroyQuery(mRayQuery);
	mScnMgr->destroyQuery(mRayCursorQuery);


	mInputSystem->destroyInputObject(mKeyboard);
	mInputSystem->destroyInputObject(mMouse);
	OIS::InputManager::destroyInputSystem(mInputSystem);
}
//-----------------------------------------------------------------------
bool MapEditorListener::frameStarted(const FrameEvent& evt)
{
	mTimeElapsed += evt.timeSinceLastFrame;
	return true;
}
//-----------------------------------------------------------------------
bool MapEditorListener::frameEnded(const FrameEvent& evt)
{
	if (!mUseBufferedInputKeys)
		handleKeyboardInput(evt);

	// Move about 100 units per second,
	mMoveScale = mMoveSpeed * evt.timeSinceLastFrame;
	// Take about 10 seconds for full rotation
	mRotScale = mRotateSpeed * evt.timeSinceLastFrame;

	mCamera->yaw(mRotX);
	mCamera->pitch(mRotY);
	mCamera->moveRelative(mTranslateVector);

	if (mClickActive)
    {
        switch (mEditMode)
        {
        case EditDeformTerrain:
	        mScnMgr->setOption( "DeformationCenter", &mCursorPos);
            break;

        case EditPaintAlphaTerrain:
	        mScnMgr->setOption( "PaintAlphaCenter", &mCursorPos);
            break;

        case EditPaintColorTerrain:
	        mScnMgr->setOption( "PaintColorCenter", &mCursorPos);
            break;

        default:
            break;
        }
    }

	updateStats();

	if(endProgram)
		return false;
	else
		return FrameListener::frameEnded(evt);

	return true;
}
//-----------------------------------------------------------------------
void MapEditorListener::setMorphMode(const bool value) 
{ 
	morphMode=value; 
}
//-----------------------------------------------------------------------
void MapEditorListener::setEditMode (const EditMode editMode)
{
    mEditMode = editMode;
}
//-----------------------------------------------------------------------
bool MapEditorListener::keyReleased(const OIS::KeyEvent& e) 
{
	if (mKeyClickedNum != 0)
	{
		if (mKeyClickedNum == 1)
		{
			mTranslateVector = Vector3::ZERO;
			mRotX = 0.0f;
		}
		mKeyClickedNum -= 1;
	}

	CEGUI::System::getSingleton().injectKeyUp(e.key);
	return true;
}
//-----------------------------------------------------------------------
bool MapEditorListener::keyPressed(const OIS::KeyEvent& e) 
{
	mTranslateVector = Vector3::ZERO;
	mRotX = 0.0f;

	mKeyClickedNum += 1;
	assert (mKeyClickedNum < 2);

	bool handled = false;
	handled = CEGUI::System::getSingleton().injectKeyDown(e.key);
	if (!handled)
		handled = CEGUI::System::getSingleton().injectChar(e.key);


	if (!handled)
	{
		/*
			Real moveScale = mMoveScale;

			if ((e.key == KC_RCONTROL) || (e.key == KC_LCONTROL))
			{
				moveScale = moveScale * 30;
			}

			// use CTRL key for mega boost
			if ((e.key == KC_RSHIFT) || (e.key == KC_SPACE))
			{
				moveScale = moveScale * 300;
			}
			mMoveScale = moveScale;
		*/
		if((e.key == KC_A) || (e.key == KC_Q))
		{
			// Move camera left
			mTranslateVector.x = -mMoveScale;
		}

		if ((e.key == KC_D))
		{
			// Move camera RIGHT
			mTranslateVector.x = mMoveScale;
		}

		/* Move camera forward by key press. */
		if ((e.key == KC_UP) || (e.key == KC_W) || (e.key == KC_Z))
		{
			mTranslateVector.z = -mMoveScale;
		}

		/* Move camera backward by key press. */
		if ((e.key == KC_DOWN) || (e.key == KC_S))
		{
			mTranslateVector.z = mMoveScale;
		}

		if ((e.key == KC_PGUP))
		{
			// Move camera up
			mTranslateVector.y = mMoveScale;
		}

		if ((e.key == KC_PGDOWN))
		{
			// Move camera down
			mTranslateVector.y = -mMoveScale;
		}

		if ((e.key == KC_RIGHT))
		{
			mRotX -= mRotScale;
		}

		if ((e.key == KC_LEFT))
		{
			mRotX += mRotScale;
		}

		if(e.key == KC_ESCAPE)
		{
			endProgram = true;
		}

		if (e.key == KC_T)
		{
			if (mCamera->getPolygonMode() == PM_SOLID)
			{
				mCamera->setPolygonMode(PM_WIREFRAME);
			}
			else
			{
				mCamera->setPolygonMode(PM_SOLID);
            }
		}

		// Capture the screen to a PNG graphics file
		if (e.key == KC_SYSRQ)
		{
			char tmp[35];
			sprintf (tmp, "Screenshot%d.png", 001);
			mWindow->writeContentsToFile(tmp);
		}		
	}

	return true;
}
//-----------------------------------------------------------------------
bool MapEditorListener::mouseMoved(const OIS::MouseEvent& e) 
{
	//CEGUI::System::getSingleton().injectMouseMove(e.state.X.rel * mGuiRenderer->getWidth(), 
	//	e.state.Y.rel * mGuiRenderer->getHeight());
	CEGUI::System::getSingleton().injectMouseMove(
			e.state.X.rel * 1000, 
			e.state.Y.rel * 1000);

    if (!rMouseDown && mEditMode!=EditNothing)
    {
		/*
			mAmountMovedY+=e.state.Y.rel;
			mAmountMovedX+=e.state.X.rel;
		*/
		if(mTimeElapsed > 0.05)
		{
			mTimeElapsed=0;

			const Ray pickRay = mCamera->getCameraToViewportRay(e.state.X.rel, e.state.Y.rel);

			mRayCursorQuery->setRay (pickRay);
			mRayQuery->setQueryTypeMask(Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
			mRayQuery->setWorldFragmentType(SceneQuery::WFT_SINGLE_INTERSECTION); 
    		
			RaySceneQueryResult& qryResult = mRayCursorQuery->execute();
			RaySceneQueryResult::iterator it = qryResult.begin();
			if (it != qryResult.end() && it->worldFragment)
			{
				mCursorPos = it->worldFragment->singleIntersection;
			}

            bool doattach = false;
            if (!mCursor)
            {
                mCursor = new Line3D (AMOUNT_CURSOR_POINTS);
                doattach = true;

            } // if (!mCursor)

			//Define the position of the points that form the cursor
			Ray cameraRay( Vector3::ZERO,  Vector3::UNIT_Y );
            RaySceneQueryResult result;
			RaySceneQueryResult::iterator itr;
			mRayQuery->setQueryTypeMask(Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
			mRayQuery->setWorldFragmentType(SceneQuery::WFT_SINGLE_INTERSECTION); 
			for(unsigned int i = 0; i <= AMOUNT_CURSOR_POINTS; i++)
			{
                cameraRay.setOrigin(Vector3(mCursorPos.x + mCursorPoints[i].x, 
											0.0f, 
											mCursorPos.z + mCursorPoints[i].z));
				mRayCursorQuery->setRay( cameraRay );
				// Perform the scene query
				result = mRayCursorQuery->execute();
				if (!result.empty())
				{
					itr = result.begin( );
					if ( itr != result.end() && itr->worldFragment )
					{
						const Real terrainHeight = itr->worldFragment->singleIntersection.y;

						mCursorPoints[i].y = terrainHeight;
					} 
					else
					{
						mCursorPoints[i].y = 0.0f;
					}
				}
			}
		
			mCursor->updateLine (mCursorPoints);
            if (doattach)
            {
			    mCursorNode->detachAllObjects();
			    mCursorNode->attachObject(mCursor);
            }
			mCursorNode->setPosition(Vector3(mCursorPos.x, 0.0f, mCursorPos.z));
		}	
	}
	return true;
}
//-----------------------------------------------------------------------
bool MapEditorListener::mousePressed(const OIS::MouseEvent& e, OIS::MouseButtonID id)
{
	bool handled = false;
	handled = CEGUI::System::getSingleton().injectMouseButtonDown(convertOgreButtonToCegui(id));
	if (!handled)
	{
		//Mouse not on a GUI element
		if (id == OIS::MB_Right)
		{
			rMouseDown = true;
			//Rotate camera
			mCamera->yaw(Radian( -e.state.X.rel * mRotateSpeed ));
			mCamera->pitch(Radian( -e.state.Y.rel * mRotateSpeed ));
		}
		else if (id == OIS::MB_Left)
		{
		   lMouseDown = true;
		}

		const Real clickX = static_cast <Real> (e.state.X.abs);
		const Real clickY = static_cast <Real> (e.state.Y.abs);

		if (id == OIS::MB_Middle)
		{
			mClickActive = true;
			mClickX = clickX;
			mClickY = clickY;
		}
		
	}
   return true;
}
//-----------------------------------------------------------------------
bool MapEditorListener::mouseReleased(const OIS::MouseEvent& e, OIS::MouseButtonID id)
{          
	CEGUI::System::getSingleton().injectMouseButtonUp(convertOgreButtonToCegui(id));

	lMouseDown = false;
	mClickActive = false;          

	/*if(morphMode && rMouseDown)
	{
		Ray pickRay = mCamera->getCameraToViewportRay(0.5, 0.5);

		mRayCursorQuery->setRay (pickRay);
		//mRayCursorQuery->setQueryMask (RSQ_FirstTerrain); //PLSM2 only
		mRayQuery->setQueryTypeMask(Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
		mRayQuery->setWorldFragmentType(SceneQuery::WFT_SINGLE_INTERSECTION); 
		
		RaySceneQueryResult& qryResult = mRayCursorQuery->execute();
		RaySceneQueryResult::iterator it = qryResult.begin();
		if (it != qryResult.end() && it->worldFragment)
		{
			mCursorPos = it->worldFragment->singleIntersection;
		}
	}*/
	rMouseDown = false;

	return true;
}
//-----------------------------------------------------------------------
void MapEditorListener::updateStats(void)
{
    static String currFps = "Current FPS: ";
    static String tris = "Triangle Count: ";

    // update stats when necessary
    try {
        const RenderTarget::FrameStats& stats = mWindow->getStatistics();

        OverlayManager::getSingleton().getOverlayElement("FPS")->setCaption(currFps + StringConverter::toString(stats.lastFPS));
        OverlayManager::getSingleton().getOverlayElement("TriangleCount")->setCaption(tris + StringConverter::toString((unsigned int)stats.triangleCount));

		int locX, locZ;
		mScnMgr->getOption("CurrentCameraPageX", &locX);
		mScnMgr->getOption("CurrentCameraPageZ", &locZ);
		//OverlayManager::getSingleton().getOverlayElement("PlayerLocation")->setCaption("Location: " + StringConverter::toString((unsigned int)locX) + " - " + StringConverter::toString((unsigned int)locZ));
    }
    catch(...)
    {
        // ignore
    }
}
//-----------------------------------------------------------------------
void MapEditorListener::deform()
{
	//mCursorPos.y=0;
	/*Ray pickRay = mCamera->getCameraToViewportRay(mClickX, mClickY);

    mRayQuery->setRay (pickRay);
	//mRayQuery->setQueryMask (RSQ_FirstTerrain); //PLSM2 only
	mRayQuery->setQueryTypeMask(Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
	mRayQuery->setWorldFragmentType(SceneQuery::WFT_SINGLE_INTERSECTION); 
	mRayQuery->execute ();
    RaySceneQueryResult& qryResult = mRayQuery->execute();
    RaySceneQueryResult::iterator it = qryResult.begin();
    if (it != qryResult.end() && it->worldFragment)
    {
        mScnMgr->setOption( "DeformationCenter", 
            &(it->worldFragment->singleIntersection) );
    }*/
}
//-----------------------------------------------------------------------
void MapEditorListener::handleKeyboardInput(const FrameEvent& evt)
{
	const Real t = evt.timeSinceLastFrame;
	// Move about 100 units per second,
	Real moveScale = 50.0 * t;
	// Take about 10 seconds for full rotation
	Real rotScale = 36 * t;

	mKeyboard->capture();

	// use CTRL key for boost
	if (mKeyboard->isKeyDown(KC_RCONTROL) || mKeyboard->isKeyDown(KC_LCONTROL))
    {
        moveScale = moveScale * 30;
    }

    // use CTRL key for mega boost
    if (mKeyboard->isKeyDown(KC_RSHIFT) || mKeyboard->isKeyDown(KC_SPACE))
	{
		moveScale = moveScale * 300;
	}

	Vector3 vec = Vector3::ZERO;
	if (mKeyboard->isKeyDown(KC_LEFT) || mKeyboard->isKeyDown(KC_A) || mKeyboard->isKeyDown(KC_Q))
	{
		// Move camera left
		vec.x = -moveScale;
	}

	if (mKeyboard->isKeyDown(KC_RIGHT) || mKeyboard->isKeyDown(KC_D))
	{
		// Move camera RIGHT
		vec.x = moveScale;
	}

	if (mKeyboard->isKeyDown(KC_UP) || mKeyboard->isKeyDown(KC_Z) || mKeyboard->isKeyDown(KC_W))
	{
		// Move camera forward
		vec.z = -moveScale;
	}

	if (mKeyboard->isKeyDown(KC_DOWN) || mKeyboard->isKeyDown(KC_S))
	{
		// Move camera backward
		vec.z = moveScale;
	}

	mCamera->moveRelative(vec);
}
//-----------------------------------------------------------------------
void MapEditorListener::setBrushSize(const int value)
{
    mBrushSize = value;
    // beware only works with crater predefined modifications
	mScnMgr->setOption("BrushSize", &mBrushSize);

    // for user height array of modif 
    // use 
	//mScnMgr->setOption("BrushArrayHeight", &mBrushSize);
	//mScnMgr->setOption("BrushArrayWidth", &mBrushSize);

	//Initialise the "cursorPoints"
	mCursorPoints[0] = Vector3(mBrushSize*8, 0.0f, 0.0f);
    const float pointsangle = 360.0 / AMOUNT_CURSOR_POINTS;
    const Real x = mCursorPoints[0].x;
    const Real z = mCursorPoints[0].z;
	for(int i=2; i <= AMOUNT_CURSOR_POINTS; i++)
	{
        const float radAngle = DEG2RAD((i-1)*(pointsangle));
        const float cosAngle = cos(radAngle);
        const float sinAngle = sin(radAngle);

		mCursorPoints[i-1].x =  x*cosAngle + z*sinAngle;
		mCursorPoints[i-1].z = -x*sinAngle + z*cosAngle;
	}
	mCursorPoints[AMOUNT_CURSOR_POINTS] = mCursorPoints[0];
}
