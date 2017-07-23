#ifndef PagingLandScapeFrameListener_H
#define PagingLandScapeFrameListener_H

#define OIS_DYNAMIC_LIB
#include <OIS/OIS.h>

class PagingLandScapeFrameListener : 
    public FrameListener,
    public OIS::MouseListener, public OIS::KeyListener
{

    public:

         
        //---------------------------------------------------------------------
        PagingLandScapeFrameListener(RenderWindow* win, 
            Camera* cam, 
            bool useBufferedInputKeys = false, 
			bool useBufferedInputMouse = false)
            : 
            mCurrentCamera (cam),
            mWindow (win),

			mShouldShutdown(false),
			mShouldRotate(false), 
			mShouldTranslate(false),

            mUseBufferedInputKeys (useBufferedInputKeys), 
            mUseBufferedInputMouse (useBufferedInputMouse),

            mAniso (1), 
            mFiltering (TFO_BILINEAR),
            mTimeUntilNextToggle (0.0f),
            mNumScreenShots (0),
            paginglandScapeevents (0),
            mCursor (0)
        {

			assert (cam);
			mCurrentCamera = cam;
			mScnMgr = cam->getSceneManager ();
			assert (mScnMgr);

			mRay.setDirection (Vector3::UNIT_Y);
			mRayQuery = mScnMgr->createRayQuery(mRay);
			mRayQuery->setQueryTypeMask(Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
			mRayQuery->setWorldFragmentType(SceneQuery::WFT_SINGLE_INTERSECTION); 


            ////////////////////////////////
            size_t windowHnd = 0;
            std::ostringstream windowHndStr;
            OIS::ParamList pl;

            mWindow->getCustomAttribute("WINDOW", &windowHnd);

            // Fill parameter list
            windowHndStr << (unsigned int) windowHnd;
            pl.insert( std::make_pair( std::string( "WINDOW" ), windowHndStr.str() ) );

            // Uncomment these two lines to allow users to switch keyboards via the language bar
            //paramList.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_FOREGROUND") ));
            //paramList.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_NONEXCLUSIVE") ));

            mInputSystem  = OIS::InputManager::createInputSystem( pl );

            //Create all devices (We only catch joystick exceptions here, as, most people have Key/Mouse)
            mInput = static_cast<OIS::Keyboard*>(mInputSystem->createInputObject( OIS::OISKeyboard, true ));
            mMouse = static_cast<OIS::Mouse*>(mInputSystem->createInputObject( OIS::OISMouse, true ));

            unsigned int width, height, depth;
            int left, top;
            mWindow->getMetrics(width, height, depth, left, top);

            const OIS::MouseState &ms = mMouse->getMouseState();
            ms.width = width;
            ms.height = height;

            mInput->setEventCallback (this);
            mMouse->setEventCallback (this);
			//mInputTypeSwitchingOn = useBufferedInputKeys || useBufferedInputKeys;
			mInputTypeSwitchingOn = false;//useBufferedInputKeys || useBufferedInputKeys;
            ////////////////////////////////


			mMouseMoved = true;
            mClickActive = false;
            vec = Vector3::ZERO;

            mScnMgr->setShadowTechnique (SHADOWTYPE_NONE);
            //mScnMgr->setShadowTechnique (SHADOWTYPE_TEXTURE_MODULATIVE);	

            mScnMgr->setOption ("ConfigGroupName", &String("PLSM2"));
            ////////

            Overlay *OverCursor = OverlayManager::getSingleton().create ("myCursor");

			mCursor = new PanelOverlayElement ("myCursor");
            mCursor->initialise();
            mCursor->setMaterialName ("Cursor/default");
			MaterialPtr m = MaterialManager::getSingleton().getByName("Cursor/default");
			m->getTechnique(0)->getPass(0)->setAlphaRejectValue(127);

            mCursor->setDimensions (32.0/win->getWidth(), 32.0/win->getHeight());
            OverCursor->add2D (mCursor);
            OverCursor->show ();
            mCursor->show ();

			// show FPS
			showDebugOverlay(true);
			mKeyClickedNum = 0;
			mMoveScale = 1000;
        };
        //---------------------------------------------------------------------
        ~PagingLandScapeFrameListener()
        {
           // if (mInputTypeSwitchingOn)
            {

                mInputSystem->destroyInputObject(mInput);
                mInputSystem->destroyInputObject(mMouse);
                OIS::InputManager::destroyInputSystem(mInputSystem);

                delete mCursor;
            }
            //delete mInputDevice;
            // Destroy the query
            mScnMgr->destroyQuery (mRayQuery); 

        };
        
        //---------------------------------------------------------------------
        virtual bool  mouseMoved(const OIS::MouseEvent& e) 
		{ 
			const Real clickX = static_cast <Real> (e.state.X.abs) / mWindow->getWidth();
			const Real clickY = static_cast <Real> (e.state.Y.abs) / mWindow->getHeight();

			mClickX = clickX;
			mClickY = clickY;
		
			//mCursor->mouseMoved(e);
			mCursor->setLeft(clickX);
			mCursor->setTop(clickY);

			mMouseMoved = true;
            return true;
        }
        //---------------------------------------------------------------------
        virtual bool  mouseDragged(const OIS::MouseEvent& e)
        {
            
            //if (buttonid == OIS::MB_Left)
            //{
                mClickX = static_cast <Real> (e.state.X.abs) / mWindow->getWidth();
                mClickY = static_cast <Real> (e.state.Y.abs) / mWindow->getHeight();
                //mClickActive = true;
            //}
            return mouseMoved (e);
        };
        //---------------------------------------------------------------------
        virtual bool  mousePressed(const OIS::MouseEvent& e, OIS::MouseButtonID buttonid)
		{
 			if (buttonid == OIS::MB_Left)
 			{
 				mClickActive = true;
 			}
            return true;
        };
        //---------------------------------------------------------------------
        virtual bool  mouseReleased(const OIS::MouseEvent& e, OIS::MouseButtonID buttonid)
        {          
            mClickActive = false;    
            return true;
        };
        //---------------------------------------------------------------------
        // Override frameStarted event to process that (don't care about frameEnded)
	    virtual bool frameStarted(const FrameEvent& evt)
        {

			if (mWindow->isClosed() || mShouldShutdown)
				return false;


            const Real t = evt.timeSinceLastFrame;
		    // Move about 100 units per second,
		    Real moveScale = 50.0 * t;
		    // Take about 10 seconds for full rotation
		    Real rotScale = 36 * t;
                                    

            if (mTimeUntilNextToggle >= 0.0f)
            {
                mTimeUntilNextToggle -= t;
            }

            if (paginglandScapeevents && paginglandScapeevents->hasEvent())
            {
                mDebugText = (paginglandScapeevents->getEventString());
                paginglandScapeevents->clearEventString();
            }
        
		    // Grab input device state
            //if (!mInputTypeSwitchingOn)
				//(!mUseBufferedInputKeys || !mUseBufferedInputMouse)
    	    {
                ////////////////////////////////
                mMouse->capture();
                mInput->capture();
                ////////////////////////////////
            }


            if (!mUseBufferedInputKeys)
			{
				if( mInput->isKeyDown(OIS::KC_ESCAPE) )
				{
					return false;
				}  


		        // use CTRL key for boost
		        if (mInput->isKeyDown(OIS::KC_LCONTROL))
                {
                    moveScale = moveScale * 30;
                }

                // use CTRL key for mega boost
                if (mInput->isKeyDown(OIS::KC_SPACE))
		        {
			        moveScale = moveScale * 300;
		        }


                vec = Vector3::ZERO;

		        if (mInput->isKeyDown(OIS::KC_A) || 
                    mInput->isKeyDown(OIS::KC_Q))
		        {
			        // Move camera left
			        vec.x = -moveScale;
		        }

		        if (mInput->isKeyDown(OIS::KC_D))
		        {
			        // Move camera RIGHT
			        vec.x = moveScale;
		        }

		        if (mInput->isKeyDown(OIS::KC_UP) || 
                    mInput->isKeyDown(OIS::KC_W)  ||
                    mInput->isKeyDown(OIS::KC_Z))
		        {
			        // Move camera forward
			        vec.z = -moveScale;
		        }

		        if (mInput->isKeyDown(OIS::KC_DOWN) || mInput->isKeyDown(OIS::KC_S))
		        {
			        // Move camera backward
			        vec.z = moveScale;
		        }

		        if (mInput->isKeyDown(OIS::KC_PGUP))
		        {
			        // Move camera up
			        vec.y = moveScale;
		        }

		        if (mInput->isKeyDown(OIS::KC_PGDOWN))
		        {
			        // Move camera down
			        vec.y = -moveScale;
		        }

		        if (mInput->isKeyDown(OIS::KC_RIGHT))
		        {
                    mCurrentCamera->yaw(Degree (-rotScale));
		        }
		        if (mInput->isKeyDown(OIS::KC_LEFT))
		        {
			        mCurrentCamera->yaw(Degree (rotScale));
		        }

				if(mTimeUntilNextToggle < 0.0f)
				{
					const Real Keyrate = 1.5f;

// 					if (mInputTypeSwitchingOn && 
// 						(mInput->isKeyDown(OIS::KC_M) || mInput->isKeyDown(OIS::KC_COMMA)))
// 					{
// 						switchMouseMode();
// 						mTimeUntilNextToggle = Keyrate;
// 					}
					if (mInput->isKeyDown(OIS::KC_F))
					{
						showDebugOverlay(true);
						mTimeUntilNextToggle = Keyrate;
					}

					// Toggle between WireFrame and Solid rendering
					if (mInput->isKeyDown(OIS::KC_T))
					{
						if (mCurrentCamera->getPolygonMode() == PM_SOLID)
						{
							mCurrentCamera->setPolygonMode(PM_WIREFRAME);
							//showDebugOverlay(false);
							//OverlayManager::getSingleton().getByName( "PagingLandScape2/DebugOverlay" ) -> hide();
						}
						else
						{
							mCurrentCamera->setPolygonMode(PM_SOLID);
							//showDebugOverlay(true);
							//OverlayManager::getSingleton().getByName( "PagingLandScape2/DebugOverlay" ) -> show();
						}
						mTimeUntilNextToggle = Keyrate;
					}

					// Capture the screen to a PNG graphics file
					if (mInput->isKeyDown(OIS::KC_SYSRQ))
					{
						char tmp[35];
						sprintf (tmp, "Demo_PagingLandScape_%d.png", ++mNumScreenShots);
						mWindow->writeContentsToFile(tmp);
						mDebugText = (String("Wrote ") + tmp);
						mTimeUntilNextToggle = Keyrate;
					}
					// Change Shadow Modes
					if (mInput->isKeyDown(OIS::KC_C))
					{
						static Ogre::uint shadowtype = 0;
						shadowtype += 1;
						if (shadowtype > 3)
							shadowtype = 0;
						switch (shadowtype)
						{
						case 1:
							mScnMgr->setShadowTechnique (SHADOWTYPE_TEXTURE_MODULATIVE);	
							mScnMgr->setShadowColour(Ogre::ColourValue(0.5, 0.5, 0.5));//config
							mScnMgr->setShadowFarDistance(60);//config
							mScnMgr->setShadowTextureSettings(512, 2);//config
							//mSceneMgr->setShadowTextureSettings(ShadowSize, 2);
							break;
						case 2:
							mScnMgr->setShadowTechnique (SHADOWTYPE_STENCIL_ADDITIVE);	
							break;
						case 3:
							mScnMgr->setShadowTechnique (SHADOWTYPE_STENCIL_MODULATIVE );	
							break;
						default:
							mScnMgr->setShadowTechnique (SHADOWTYPE_NONE);	
							break;
						}
						mTimeUntilNextToggle = Keyrate;
					} 

					if (mInput->isKeyDown(OIS::KC_Y))
					{
						switch(mFiltering)
						{
						case TFO_BILINEAR:
							mFiltering = TFO_TRILINEAR;
							mAniso = 1;
							break;
						case TFO_TRILINEAR:
							mFiltering = TFO_ANISOTROPIC;
							mAniso = 8;
							break;
						case TFO_ANISOTROPIC:
							mFiltering = TFO_BILINEAR;
							mAniso = 1;
							break;
						default:
							break;
						}
						MaterialManager::getSingleton().setDefaultTextureFiltering(mFiltering);
						MaterialManager::getSingleton().setDefaultAnisotropy(mAniso);
						showDebugOverlay(false);
						showDebugOverlay(true);
						mTimeUntilNextToggle = Keyrate;
					}

				}
            }

			
            if (!mUseBufferedInputMouse)
             {
          
                // Rotate view by mouse relative position
		        Radian rotX = Degree(-mMouse->getMouseState().X.rel * 0.13);
		        Radian rotY = Degree(-mMouse->getMouseState().Y.rel * 0.13);

		        // Make all the changes to the camera
		        // Note that YAW direction is around a fixed axis (free look style) rather than a natural YAW (e.g. airplane)
		        mCurrentCamera->yaw(rotX);
		        mCurrentCamera->pitch(rotY);

		        mCurrentCamera->moveRelative(vec);
            }
			else
			{
				mCurrentCamera->yaw(mRotX);
				mCurrentCamera->pitch(mRotY);
				mCurrentCamera->moveRelative(mTranslateVector);
			}
			{
				String debugText;
				if (mScnMgr->getOption("DebugText", &debugText))
					mDebugText = debugText;
			}
           updateStats();
		    // Return true to continue rendering
		    return true;
	    }
        //---------------------------------------------------------------------
        virtual bool frameEnded(const FrameEvent& evt)
		{		   
			mRotX = 0;
			mRotY = 0;
			mTranslateVector = Vector3::ZERO;
            return true;
        };
        //---------------------------------------------------------------------
        //handles Changes in input mode
        void switchMouseMode()
	    {
            mUseBufferedInputMouse = !mUseBufferedInputMouse;
            if (mUseBufferedInputMouse)
                mCursor->show ();
            else
                mCursor->hide ();

		    mMouse->setBuffered (mUseBufferedInputMouse);
	    }
        //---------------------------------------------------------------------
        void switchKeyMode()
	    {
            mUseBufferedInputKeys = !mUseBufferedInputKeys;
		    mInput->setBuffered (mUseBufferedInputKeys);
	    }
        //---------------------------------------------------------------------
        // FROM LISTENERS
	    virtual bool  keyClicked(const OIS::KeyEvent& e)
		{
			mTranslateVector = Vector3::ZERO;
			mKeyClickedNum += 1;

            return true;
	    }
        //---------------------------------------------------------------------
		virtual bool  keyPressed(const OIS::KeyEvent& e) 
		{
			switch (e.key)
            {
            case OIS::KC_M:
            case OIS::KC_COMMA:
                switchMouseMode(); 
                break;
            case OIS::KC_J:
                switchKeyMode(); 
                break;


            case OIS::KC_ESCAPE:
                mShouldShutdown = true; 
                break;

            case OIS::KC_A:
            case OIS::KC_Q:
                // Move camera left
                mTranslateVector.x = -mMoveScale; 
                break;

            case OIS::KC_D:
                // Move camera RIGHT
                mTranslateVector.x = mMoveScale;
                break;

            case OIS::KC_UP:
            case OIS::KC_W: 
            case OIS::KC_Z:
                /* Move camera forward by key press. */
                mTranslateVector.z = -mMoveScale;
                break;

            case OIS::KC_DOWN:
            case OIS::KC_S: 
                /* Move camera backward by key press. */
                mTranslateVector.z = mMoveScale;
                break;

            case OIS::KC_PGUP:
                // Move camera up
                mTranslateVector.y = mMoveScale;
                break;

            case OIS::KC_PGDOWN:
                // Move camera down
                mTranslateVector.y = -mMoveScale;
                break;

            case OIS::KC_RIGHT:
                mCurrentCamera->yaw(-mRotScale);
                break;


            case OIS::KC_LEFT:
                mCurrentCamera->yaw(mRotScale);
                break;
            }
            return true;
            

            return true;
		}
        //---------------------------------------------------------------------
		virtual bool  keyReleased(const OIS::KeyEvent& e) 
		{ 
			mKeyClickedNum -= 1;
			if (mKeyClickedNum == 0)
                mTranslateVector = Vector3::ZERO;

            return true;
		}
    

    protected:

        //---------------------------------------------------------------------
        void showDebugOverlay(bool show)
        {
            Overlay* o = (Overlay*)OverlayManager::getSingleton().getByName("Core/DebugOverlay");
            if (!o)
                OGRE_EXCEPT( Exception::ERR_ITEM_NOT_FOUND, "Could not find overlay Core/DebugOverlay",
                    "showDebugOverlay" );
            if (o->isVisible() && show)
			{
				o->hide();
            }
            else if (show)
			{
				o->show();
            }
        };
        //---------------------------------------------------------------------
        void updateStats(void)
        {
            static String currFps = "Current FPS: ";
            static String avgFps = "Average FPS: ";
            static String bestFps = "Best FPS: ";
            static String worstFps = "Worst FPS: ";
            static String tris = "Triangle Count: ";

            // update stats when necessary
            OverlayElement* guiAvg = OverlayManager::getSingleton().getOverlayElement("Core/AverageFps");
            OverlayElement* guiCurr = OverlayManager::getSingleton().getOverlayElement("Core/CurrFps");
            OverlayElement* guiBest = OverlayManager::getSingleton().getOverlayElement("Core/BestFps");
            OverlayElement* guiWorst = OverlayManager::getSingleton().getOverlayElement("Core/WorstFps");

            const RenderTarget::FrameStats& stats = mWindow->getStatistics();

            guiAvg->setCaption(avgFps + StringConverter::toString(stats.avgFPS));
            guiCurr->setCaption(currFps + StringConverter::toString(stats.lastFPS));
            guiBest->setCaption(bestFps + StringConverter::toString(stats.bestFPS)
                +" "+StringConverter::toString(stats.bestFrameTime)+" ms");
            guiWorst->setCaption(worstFps + StringConverter::toString(stats.worstFPS)
                +" "+StringConverter::toString(stats.worstFrameTime)+" ms");

            OverlayElement* guiTris = OverlayManager::getSingleton().getOverlayElement("Core/NumTris");
            guiTris->setCaption(tris + StringConverter::toString((Ogre::uint)stats.triangleCount));

            OverlayElement* guiDbg = OverlayManager::getSingleton().getOverlayElement("Core/DebugText");
            guiDbg->setCaption(mDebugText);
        };

		//---------------------------------------------------------------------
		void getHeight(Vector3 &pos, const Real heightAbove = 0)
		{
			// A RayQuery with the direction set to Vector3::UNIT_Y will always return
			// one and only one result.  Distance will always be 0 for a UNIT_Y 
			// and you can access the intersection point via worldFragment->singleIntersection
			mRay.setOrigin (pos);
			mRayQuery->setRay (mRay); 

			mRayQuery->setQueryTypeMask(Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
			mRayQuery->setWorldFragmentType(SceneQuery::WFT_SINGLE_INTERSECTION); 

			RaySceneQueryResult& qryResult = mRayQuery->execute();
			if (!qryResult.empty ())
			{
				RaySceneQueryResult::iterator it = qryResult.begin();
				if (it != qryResult.end() && it->worldFragment)
				{
					pos.y = it->worldFragment->singleIntersection.y + heightAbove;
				}
			}
		}

		//---------------------------------------------------------------------
		bool getIntersection(Vector3 &intersectPoint, const Real ClickX, const Real clickY)
		{
			Ray pickRay = mCurrentCamera->getCameraToViewportRay(ClickX, clickY);

			mRayQuery->setRay (pickRay);
			//mRayQuery->setSortByDistance (true, 1); not useful on only one result shot
			//mRayQuery->setQueryMask (RSQ_FirstTerrain); //PLSM2 only
			mRayQuery->setQueryTypeMask(Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
			mRayQuery->setWorldFragmentType(SceneQuery::WFT_SINGLE_INTERSECTION); 

			mRayQuery->execute ();
			RaySceneQueryResult& qryResult = mRayQuery->execute();
			RaySceneQueryResult::iterator it = qryResult.begin();
			if (it != qryResult.end() && it->worldFragment)
			{
				intersectPoint = it->worldFragment->singleIntersection;
				return true;
			}
			return false;
		}

    protected:

        OIS::Keyboard       *mInput;
        OIS::Mouse          *mMouse;
        OIS::InputManager   *mInputSystem;

        String mDebugText;

		Camera* mCurrentCamera;
        SceneManager *mScnMgr;
        RenderWindow* mWindow;

		bool mMouseMoved;
        bool mUseBufferedInputKeys, mUseBufferedInputMouse, mInputTypeSwitchingOn;

        unsigned int mNumScreenShots;

        // just to stop toggles flipping too fast
        Real mTimeUntilNextToggle;

        TextureFilterOptions mFiltering;
        int mAniso;

		bool                 mShouldRotate; 
		bool                 mShouldTranslate;
		bool                 mShouldShutdown;

		Vector3              mTranslateVector;
		unsigned int         mKeyClickedNum;

        RaySceneQuery* mRayQuery;
		Ray mRay;
        bool mClickActive;
        Real mClickX, mClickY;

		Real mMoveScale;

		Radian mRotScale;
		Radian mRotX;
		Radian mRotY;

		Vector3 vec;
		
		
        CustomPagingLandScapeListener *paginglandScapeevents;
        PanelOverlayElement *mCursor;
};

#endif
