
class myPagingLandScapeFrameListener : 
    public PagingLandScapeFrameListener 
{

    public:
        //---------------------------------------------------------------------
        myPagingLandScapeFrameListener(RenderWindow* win, 
            Camera* cam, Light *l, SceneNode *LightNode,
            bool useBufferedInputKeys = false, bool useBufferedInputMouse = false)
            : 
			PagingLandScapeFrameListener (win, cam,  useBufferedInputKeys, useBufferedInputMouse),

			mLight (l), 
			mLightNode (LightNode),

            mBallCount (0),

            mVis (false),

            mLandScapeCameraMode (false),
            mLandScapeDeformationMode (true),
			mLandScapeDecalMode (false),

			mCamera (cam),
			mNode (0)
        {
            paginglandScapeevents = new CustomPagingLandScapeListener (mScnMgr);
           
            Overlay *o = OverlayManager::getSingleton().getByName( "PagingLandScape2/DebugOverlay" );
            o-> show();
     
            mScnMgr->getOption( "CurrentMap", &mCurrentMap );
            mScnMgr->getOption( "CurrentTextureFormat", &mCurrentTexture );
            
            AxisAlignedBox bbox;
            mScnMgr->getOption(  "MapBoundaries", &bbox);

            const Real newscale =  - 10 * (1.0 / bbox.getMaximum().y);
            mScnMgr->setOption( "BrushScale", &newscale );   

            
            const RenderSystem *renderer = Root::getSingleton().getRenderSystem();          
            const RenderSystemCapabilities* caps = renderer->getCapabilities();
            if (caps->hasCapability(RSC_FRAGMENT_PROGRAM))
            {
                mSunTimeAdd = 0.0005f;
                mNextLightMove = 0.01f;

                //mTimeUntilNextLightMove = 0.0f;
                //sunTime += 0.001f; 
            } 
            else
            {
                mSunTimeAdd = 0.0125f;
                mNextLightMove = 0.5f;
            }  
            mSunTime =  0.5f;

			mCamera2 = mScnMgr->createCamera("MyNewCamera2");
			
            Vector3 cameraParams;
            mScnMgr->getOption ( "BaseCameraViewpoint", &cameraParams);
		    mCurrentCamera->setPosition (cameraParams);
            mScnMgr->getOption ("Baselookat", &cameraParams);
		    mCurrentCamera->lookAt (cameraParams);
		    
            //mScnMgr->setOption ("LoadNow", mCurrentCamera);
		    
		    //mScnMgr->setDisplaySceneNodes(true);
		    //mScnMgr->showBoundingBoxes (true);
        };
        //---------------------------------------------------------------------
        ~myPagingLandScapeFrameListener()
		{
			if (paginglandScapeevents)
			{
				delete paginglandScapeevents;
				paginglandScapeevents = 0;
			}
        };
        
		//---------------------------------------------------------------------
		virtual bool  mousePressed(const OIS::MouseEvent& e, OIS::MouseButtonID buttonid)
        {        
            const int id = buttonid;

            const Real clickX = static_cast <Real> (e.state.X.abs) / mWindow->getWidth();
            const Real clickY = static_cast <Real> (e.state.Y.abs) / mWindow->getHeight();

            if ((id == OIS::MB_Left))
            {
                if (mLandScapeDeformationMode)
                {
                    mClickActive = true;
                    mClickX = clickX;
                    mClickY = clickY;
                } 
                if (mLandScapeDecalMode)
                {
                    Ray pickRay = mCurrentCamera->getCameraToViewportRay(clickX, clickY);

                    mRayQuery->setRay (pickRay);
                    //mRayQuery->setSortByDistance (true, 1); not useful on only one result shot
                    //mRayQuery->setQueryMask (RSQ_FirstTerrain); //PLSM2 only
					mRayQuery->setQueryTypeMask(Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
					mRayQuery->setWorldFragmentType(Ogre::SceneQuery::WFT_SINGLE_INTERSECTION); 
	                mRayQuery->execute ();
                    RaySceneQueryResult& qryResult = mRayQuery->execute();
                    RaySceneQueryResult::iterator it = qryResult.begin();
                    
                    if (it == qryResult.end() || it->worldFragment == 0)
                    {
                        return true;
                    } 
                    const Vector3 &Squarecenter = it->worldFragment->singleIntersection;

                    Vector3 vertices_array[5];

                    // define area square
                    vertices_array[0] = Squarecenter + Vector3(0.0f, 0.0f, 100.0f);//leftupsquarecornerpos;
                    vertices_array[1] = Squarecenter + Vector3(100.0f, 0.0f, 100.0f);//rightupsquarecornerpos;
                    vertices_array[2] = Squarecenter + Vector3(0.0f, 0.0f, 0.0f);//leftdownsquarecornerpos;
                    vertices_array[3] = Squarecenter + Vector3(100.0f, 0.0f, 0.0f);//righdownsquarecornerpos;
                    vertices_array[4] = Vector3::ZERO; // to be filled

                    mScnMgr->getOption("getAreaSize", vertices_array);

                    Vector3 *vertices2 = new Vector3[static_cast <size_t> (vertices_array[4].x)];

                    // define area square
                    memcpy(vertices2, vertices_array, 4 * sizeof (Vector3 ));

                    // Let Scene Manager Fill It
                    mScnMgr->getOption("getArea", vertices2);

                    // In vertices2 you should have the Data needed for the decal...

                    //  could create a custom renderable decal 
                    // with those vertices and map with some material that has a DepthBias
                    // parameter Set.
                }
            }
            if (mTimeUntilNextToggle <= 0.0f)
            {       
                if (id == OIS::MB_Right )
                {
                    //cast a ray into scene and get intersection point, drop a ball there 
                    Ray pickRay = mCurrentCamera->getCameraToViewportRay(clickX, clickY); 
                    

                    mRayQuery->setRay(pickRay); 
					//mRayQuery->setQueryMask ( RSQ_FirstTerrain  ); //PLSM2 only
					mRayQuery->setQueryTypeMask(Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
					mRayQuery->setWorldFragmentType(SceneQuery::WFT_SINGLE_INTERSECTION); 
                    mRayQuery->execute (); 
                        
                    RaySceneQueryResult& result = mRayQuery->execute(); 
                    RaySceneQueryResult::iterator i = result.begin(); 
                    if (i != result.end() && i->worldFragment) 
                    { 
                        const Vector3 position = i->worldFragment->singleIntersection; 

                        //create a new ball 
                        const String typeName = "Ball"; 
                        const String name = typeName + StringConverter::toString(mBallCount); 

                        Entity* entity = mScnMgr->createEntity(name, "sphere.mesh"); 

						if (mNode)
						{
							mNode->removeAndDestroyAllChildren ();
							mScnMgr->getRootSceneNode()->removeAndDestroyChild (mNode->getName ());
						}
					    mNode = mScnMgr->getRootSceneNode()->createChildSceneNode(name); 
                        SceneNode* node = mNode;

                        node->attachObject(entity); 
                        node->setPosition(position); 
                        node->setScale(0.1f, 0.1f, 0.1f); 
                        
                        node->showBoundingBox(true);

                        mBallCount++; 
					} 
					mTimeUntilNextToggle = 0.4f;
                }
                if (id == OIS::MB_Middle )
                {                    
                    //cast a ray into scene and get intersection point, drop a ball there 
                    Ray pickRay (mCurrentCamera->getDerivedPosition(), Vector3::NEGATIVE_UNIT_Y);   
                    mRayQuery->setRay(pickRay); 
					//mRayQuery->setQueryMask(RSQ_Height);// | RSQ_Height_no_interpolation);  //PLSM2 only
					mRayQuery->setQueryTypeMask(Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
					mRayQuery->setWorldFragmentType(SceneQuery::WFT_SINGLE_INTERSECTION); 
                    mRayQuery->execute ();                         
                    RaySceneQueryResult& result = mRayQuery->execute(); 
                    RaySceneQueryResult::iterator i = result.begin(); 
                    if (i != result.end() && i->worldFragment) 
                    { 
                        const Vector3 position = i->worldFragment->singleIntersection; 

                        //create a new ball 
                        const String typeName = "Ball"; 
                        const String name = typeName + StringConverter::toString(mBallCount); 

						Entity* entity = mScnMgr->createEntity(name, "sphere.mesh"); 

						if (mNode)
						{
							mNode->removeAndDestroyAllChildren ();
							mScnMgr->getRootSceneNode()->removeAndDestroyChild (mNode->getName ());
						}
						mNode = mScnMgr->getRootSceneNode()->createChildSceneNode(name); 
                        SceneNode* node = mNode;

                        node->attachObject(entity); 
                        node->setPosition(position); 
                        node->setScale(0.1f, 0.1f, 0.1f); 

                        node->showBoundingBox(true);
                        
                        mBallCount++; 
					} 
					mTimeUntilNextToggle = 0.4f;
                }
            }
            return true;
        };       
        //---------------------------------------------------------------------
        void deform ()
        {
            Ray pickRay = mCurrentCamera->getCameraToViewportRay(mClickX, mClickY);

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
                //mScnMgr->setOption( "DeformationCenter", 
				//	&(it->worldFragment->singleIntersection) );

				{
					std::vector<Real> rgba;
					unsigned int width=10, height=10;

					Ogre::Real *brush = new Ogre::Real[100];
					rgba.reserve(4);
					rgba.resize(4);

					rgba[0] = 1.0f;
					rgba[1] = 0.0f;
					rgba[2] = 0.0f;
					rgba[3] = 1.0f;

					mScnMgr->setOption("setPaintChannelValues", &rgba);

					for (int i=0; i<100; i++)
					{
						brush[i]=1.0f;
					}

					mScnMgr->setOption("BrushArrayHeight", &height);
					mScnMgr->setOption("BrushArrayWidth", &width);
					mScnMgr->setOption("BrushArray", brush);

					Ogre::Real scale = 1.0f;
					mScnMgr->setOption("BrushScale", brush);

					mScnMgr->setOption( "PaintCenter", 
						&(it->worldFragment->singleIntersection) );
				}

            }
        }
        //---------------------------------------------------------------------
        // Override frameStarted event to process that (don't care about frameEnded)
	    bool frameStarted(const FrameEvent& evt)
	    {
			bool returnValue = PagingLandScapeFrameListener::frameStarted(evt);

            const Real t = evt.timeSinceLastFrame;
              
			// sun updates
            if (mTimeUntilNextLightMove > 0.0f)
            {
                mTimeUntilNextLightMove -= t;
            }
            else 
            {  
                static const Real rightAngle = Degree(270).valueRadians();
                static const Real invRightAngle = Degree(90).valueRadians();

                Real theta, phi;
                if (mSunTime < 0.5f) 
            		
                {
	                // East direction
	                phi = rightAngle;
	                // time 0.5 maps to zenith (theta = 0 degrees) and time 0 maps to east horizon (theta = 90 degrees)
	                theta = 2*(0.5f - mSunTime)*invRightAngle;
                }
                else
                {
	                // West direction
	                phi = invRightAngle;

	                // time 0.5 maps to zenith (theta = 0 degrees) and time 1.0 maps to west horizon (theta = 90 degrees)
	                theta = (mSunTime - 0.5f)*2*invRightAngle;
                }



                mTimeUntilNextLightMove = mNextLightMove;
                mSunTime += mSunTimeAdd; 

                if (mSunTime > 1.0f)
                    mSunTime = 0.0f;

                const Real cosTheta = Math::Cos(theta);
                const Real sinTheta = Math::Sin(theta);

                const Real y = cosTheta;
                const Real x = sinTheta * Math::Cos(phi);
                const Real z = sinTheta * Math::Sin(phi);

                /* this one when using normal map as the up direction is in z coordinate.
                const Real z = cosTheta;
                const Real x = sinTheta * cos(phi);
                const Real y = sinTheta * sin(phi); */


                // Interchange y & z because normal map uses z as up while in our world (for sun too), y direction is up.
                const Vector3 SunDir (x, z, y);
                const Real SunAngle = z;

                mScnMgr->setOption( "Sun", &SunDir );
                mScnMgr->setOption( "SunAngle", &SunAngle );

                //mLightNode->rotate(Vector3(1.0f, 0.0f, 0.0f), 
                //                Radian (t * 15));
                //Vector3 sun = mLight->getDerivedDirection ();
                //sun.normalise ();
                //Real SunAngle = sun.dotProduct(Vector3::UNIT_Y);

                //mScnMgr->setOption( "Sun", &sun );
                //mScnMgr->setOption( "SunAngle", &SunAngle );

//                    mWindow->setDebugText("SunAngle = " + StringConverter::toString(SunAngle)
//                                            // +   "SunDir=" + StringConverter::toString(sun) 
//                                            );

            }
         
            if (mClickActive)
            {
                deform ();
            }

        
		    // Grab input device state
            if (!mInputTypeSwitchingOn)
				//(!mUseBufferedInputKeys || !mUseBufferedInputMouse)
    	    {
                mInput->capture();
            }

            //if (!mUseBufferedInputKeys)
            {
                if(mTimeUntilNextToggle < 0.0f)
                {
                    const Real Keyrate = 1.5f;
                    bool b_viewingDistance = false;

                    // Show or hide Debug Overlay
                    if (mInput->isKeyDown(OIS::KC_F1))
                    {
                        if ( OverlayManager::getSingleton().getByName( "PagingLandScape2/DebugOverlay" ) -> isVisible())
                        {
                            OverlayManager::getSingleton().getByName( "PagingLandScape2/DebugOverlay" ) -> hide();
                            OverlayManager::getSingleton().getByName( "PagingLandScape2/HelpOverlay" ) -> show();
                        }
                        else
                        { 
                            if ( OverlayManager::getSingleton().getByName( "PagingLandScape2/HelpOverlay" ) -> isVisible())
                            {
                                OverlayManager::getSingleton().getByName( "PagingLandScape2/HelpOverlay" ) -> hide();
                            }
                            else
                            {
                                OverlayManager::getSingleton().getByName( "PagingLandScape2/DebugOverlay" ) -> show();
                            }                        
                        }
                        mTimeUntilNextToggle = Keyrate;
                    }

		            if ( mInput->isKeyDown(OIS::KC_F2))
                    {
                        Vector3 pos = mCurrentCamera->getDerivedPosition();
    	    
		                pos.y = 0.0f;
		                // use the pos for both variables, since we don´t care for the orientation
		                // using vertical ray
		                // A RayQuery with the direction set to Vector3::UNIT_Y will always return
		                // one and only one result.  Distance will always be 0 for a UNIT_Y 
		                // and you can access the intersection point via worldFragment->singleIntersection
                		
                        mRayQuery->setRay (Ray(pos, Vector3::NEGATIVE_UNIT_Y)); 

                        //mRayQuery->setSortByDistance (true, 1); not useful on only one result shot
						//mRayQuery->setQueryMask (RSQ_Height); //PLSM2 only
						//mRayQuery->setQueryMask (RSQ_FirstTerrain); //PLSM2 only
						mRayQuery->setQueryTypeMask(Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
						mRayQuery->setWorldFragmentType(SceneQuery::WFT_SINGLE_INTERSECTION); 
                        RaySceneQueryResult& qryResult = mRayQuery->execute();
                        RaySceneQueryResult::iterator it = qryResult.begin();
                        if (it != qryResult.end() && it->worldFragment)
                        {
                            const Real height =  it->worldFragment->singleIntersection.y;
                            mDebugText = ("Terrain Height = " + StringConverter::toString(height));
                        } // if (it != qryResult.end() && it->worldFragment)

                        mTimeUntilNextToggle = Keyrate;
			        }

                    // Change LOD
                    if ( mInput->isKeyDown(OIS::KC_F3))
                    {

                        mCurrentCamera->setLodBias ( mCurrentCamera->getLodBias() + 0.5f);
                        mTimeUntilNextToggle = Keyrate;
                    }
                    if ( mInput->isKeyDown(OIS::KC_F4))
                    {
                        if (mCurrentCamera->getLodBias() - 0.5f > 0.0f)
                        mCurrentCamera->setLodBias ( mCurrentCamera->getLodBias() - 0.5f);
                        mTimeUntilNextToggle = Keyrate;
                    }

                    // Change Distance LOD
                    if ( mInput->isKeyDown(OIS::KC_F5))
                    {
                        Real change;
                        mScnMgr->getOption( "DistanceLOD", &change );
                        change -= 0.5f;
                        mScnMgr->setOption( "DistanceLOD", &change );
                        mTimeUntilNextToggle = Keyrate;
                        b_viewingDistance = true;

		            }
                    if ( mInput->isKeyDown(OIS::KC_F6))
		            {
                        Real change;
                        mScnMgr->getOption( "DistanceLOD", &change );
                        change += 0.5f;
			            mScnMgr->setOption( "DistanceLOD", &change );
                        mTimeUntilNextToggle = Keyrate;
                        b_viewingDistance = true;
		            }
                    // Change crater size
                    if ( mInput->isKeyDown(OIS::KC_F7))
                    {
			            Ogre::uint change;
                        mScnMgr->getOption( "BrushSize", &change );
                        if (change != 0)
                        {
                            change -= 1;
                            mScnMgr->setOption( "BrushSize", &change );   
                            mTimeUntilNextToggle = Keyrate;       
                        }
		            }
		            if ( mInput->isKeyDown(OIS::KC_F8))
		            {
				        Ogre::uint change;
                        mScnMgr->getOption( "BrushSize", &change );
                        change += 1;
			            mScnMgr->setOption( "BrushSize", &change );
                        mTimeUntilNextToggle = Keyrate;
		            }
                    // Change Max visible Renderables
		            if ( mInput->isKeyDown(OIS::KC_F9))
		            {
                        int change;
                        mScnMgr->getOption( "VisibleRenderables", &change );
                        change -= 1;
                        mScnMgr->setOption( "VisibleRenderables", &change );
                        mTimeUntilNextToggle = Keyrate;

		            }
		            if ( mInput->isKeyDown(OIS::KC_F10))
		            {
                        int change;
                        mScnMgr->getOption( "VisibleRenderables", &change );
                        change += 1;
                        mScnMgr->setOption( "VisibleRenderables", &change );
                        mTimeUntilNextToggle = Keyrate;
		            }


                    if (mInput->isKeyDown(OIS::KC_V))
                    {
                        if (!mVis)
                        {
                            MaterialPtr VisMat;
                            
                            if (mCurrentCamera->getSceneManager()->getOption( "VisibilityMaterial" , &VisMat ))
                            {
                                Overlay *MapOverlay = OverlayManager::getSingleton().getByName ("myVis");
                                if (MapOverlay == 0)
                                {
                                    MapOverlay = OverlayManager::getSingleton().create ("myVis");
                                    OverlayElement *MapOverlayelement = 
                                        OverlayManager::getSingleton ().createOverlayElement ("Panel", "myMapElem", false);
                                    MapOverlayelement->setMaterialName (VisMat->getName());
                                    MapOverlayelement->setDimensions (200.0 / mWindow->getWidth(), 
                                                                      100.0 / mWindow->getHeight());
                                    MapOverlayelement->setPosition (0, 0.21);
                                    MapOverlay->add2D ((OverlayContainer *)MapOverlayelement);
                                }
                                else
                                {
                                    OverlayElement *MapOverlayelement = 
                                        OverlayManager::getSingleton ().getOverlayElement("myMapElem");
                                    MapOverlayelement->setMaterialName (VisMat->getName());
                                }
                                MapOverlay->show ();
                            }
                            mVis = true;
                        }
                        else
                        {
                            Overlay *MapOverlay = OverlayManager::getSingleton().getByName ("myVis");
                            if (MapOverlay)
                                MapOverlay->hide ();
                            mVis = false;
                        }
                    }
					if(mInput->isKeyDown(OIS::KC_O)) 
					{     
						String currCullMode ("");
						mScnMgr->setOption("CurrentOptionCamera", mCurrentCamera);
						mScnMgr->getOption("getCullingMode", &currCullMode);  
						Viewport * const vp = mWindow->getViewport(0);
						if (mCurrentCamera ==  mCamera) 
						{
							vp->setCamera(mCamera2);
							mCamera2->_notifyViewport(vp);
							mCurrentCamera = mCamera2;
						}
						else
						{
							vp->setCamera(mCamera);
							mCamera->_notifyViewport(vp);
							mCurrentCamera = mCamera;
						}

						//vp->setBackgroundColour(ColourValue::Black);
						//vp->setBackgroundColour( ColourValue(0.35, 0.43, 0.5) );
						vp->setBackgroundColour( g_DayColor );
						mCurrentCamera->setAspectRatio(
							(Real)vp->getActualWidth() /  vp->getActualHeight());
						// stick the current culling mode with the new Camera.
						// If you want to set a new Mode you must precise it anyway.
						mScnMgr->setOption("CurrentOptionCamera", mCurrentCamera);
                        mScnMgr->getOption("setCullingMode", &currCullMode);  
						mTimeUntilNextToggle = Keyrate;
					}

                    bool bTerrainChanged = false;

                    if (mInput->isKeyDown(OIS::KC_K))
                    {
                        String nextTextureFormat, CurrentTextureFormat;
						mScnMgr->getOption( "CurrentTextureFormat", &CurrentTextureFormat );
                        if (mScnMgr->getOption( "NextTextureFormat", &nextTextureFormat ))
						{
                            if (nextTextureFormat != CurrentTextureFormat)
                            {
                                mScnMgr->setOption( "CurrentTextureFormat", &nextTextureFormat );
                                mCurrentTexture = nextTextureFormat;
								bTerrainChanged = true;                               
							}
						}
                        mTimeUntilNextToggle = Keyrate;
                    }
                    if (mInput->isKeyDown(OIS::KC_N))
                    {
                        String nextMap, currentMap;

                        if (mScnMgr->getOption( "NextMap", &nextMap ))
						{
                            if (nextMap != mCurrentMap)
                            {
			                    mScnMgr->setOption( "CurrentMap", &nextMap );
                                mScnMgr->getOption( "CurrentTextureFormat", &mCurrentTexture );
                                
                                
                                mCurrentMap = nextMap;
                                bTerrainChanged = true;
							}
						}
                        mTimeUntilNextToggle = Keyrate;
                    }

                    if (mInput->isKeyDown(OIS::KC_B))
                    {
                        mLandScapeCameraMode = !mLandScapeCameraMode;
                        mTimeUntilNextToggle = Keyrate;
                    }
                    if (mInput->isKeyDown(OIS::KC_G))
                    {
                        mLandScapeDecalMode = !mLandScapeDecalMode;
                        mTimeUntilNextToggle = Keyrate;
                    } // if (mInput->isKeyDown(KC_B))

                    if (mInput->isKeyDown(OIS::KC_H))
                    {
                        mLandScapeDeformationMode = !mLandScapeDeformationMode;
                        mTimeUntilNextToggle = Keyrate;
                    } // if
                    if (mInput->isKeyDown(OIS::KC_P))
                    {
                        String previousMap, currentMap;

                        if (mScnMgr->getOption( "PreviousMap", &previousMap ))
                            if (previousMap != mCurrentMap)
                            {
			                    mScnMgr->setOption( "CurrentMap", &previousMap );
                                mScnMgr->getOption( "CurrentTextureFormat", &mCurrentTexture );
                                mCurrentMap = previousMap;
                                bTerrainChanged = true;
                            }
                        mTimeUntilNextToggle = Keyrate;
                    }
                    if (mInput->isKeyDown(OIS::KC_L))
                    {
			            mScnMgr->setOption( "CurrentMap", &mCurrentMap );
                        mScnMgr->getOption( "CurrentTextureFormat", &mCurrentTexture );
                        bTerrainChanged = true;
                        
                        mTimeUntilNextToggle = Keyrate;         
                    }
                    if( mInput->isKeyDown(OIS::KC_END) )
		            {
                        mScnMgr->setOption("NextCullMode", mCurrentCamera);   
                        mTimeUntilNextToggle = Keyrate;
		            }
                    if( mInput->isKeyDown(OIS::KC_HOME) )
		            {
                        bool currentmode; 
                        mScnMgr->getOption("CullDebug", &currentmode);
                        currentmode = !currentmode;
                        mScnMgr->setOption("CullDebug", &currentmode);   
                        mTimeUntilNextToggle = Keyrate;
		            }
                    if (bTerrainChanged)
					{
						mScnMgr->setOption( "LoadMap", 0 ); 
                        if (mVis)
                        {                                   
                            Overlay *MapOverlay = OverlayManager::getSingleton().getByName ("myVis");
                            if (MapOverlay)
								MapOverlay->hide ();
                            mVis = false;
                        }
                        
						Vector3 cameraParams;
						
						mScnMgr->getOption(  "BaseCameraViewpoint", &cameraParams);
						mCurrentCamera->setPosition( cameraParams );
						mScnMgr->getOption(  "Baselookat", &cameraParams);
						mCurrentCamera->lookAt( cameraParams );
						b_viewingDistance = true;
                    }
                    if (b_viewingDistance)
					{
						{
							Real tmp, tmp2;

							mScnMgr->getOption( "VisibleDistance", &tmp);
							mScnMgr->getOption( "DistanceLOD", &tmp2);
	        
							//mScnMgr->setFog( FOG_LINEAR , g_DayColor, 0.0003, tmp2, tmp);
	                         
							// Infinite far plane? 
							if (Root::getSingleton().getRenderSystem()->getCapabilities()->hasCapability(RSC_INFINITE_FAR_PLANE)) 
							{ 
								mCurrentCamera->setFarClipDistance (0); 
							}
							else
							{ 
								mCurrentCamera->setFarClipDistance( tmp );
							}
						}
						mTimeUntilNextToggle = Keyrate;
                    }                
                }
            }

			// stick camera to the ground
		 	if (mLandScapeCameraMode)
            {
                const Vector3 pos = mCurrentCamera->getDerivedPosition();
    
		        // use the pos for both variables, since we don´t care for the orientation
		        // using vertical ray
		        // A RayQuery with the direction set to Vector3::UNIT_Y will always return
		        // one and only one result.  Distance will always be 0 for a UNIT_Y 
		        // and you can access the intersection point via worldFragment->singleIntersection
                
                mRayQuery->setRay (Ray(pos, Vector3::NEGATIVE_UNIT_Y)); 

                //mRayQuery->setSortByDistance (true, 1); not useful on only one result shot
                //mRayQuery->setQueryMask (RSQ_Height); //PLSM2 only
				//mRayQuery->setQueryMask (RSQ_FirstTerrain); //PLSM2 only
				mRayQuery->setQueryTypeMask(Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
				mRayQuery->setWorldFragmentType(SceneQuery::WFT_SINGLE_INTERSECTION); 
                RaySceneQueryResult& qryResult = mRayQuery->execute();
                RaySceneQueryResult::iterator it = qryResult.begin();
                if (it != qryResult.end() && it->worldFragment)
                {
                    const Real height =  it->worldFragment->singleIntersection.y;
                    mCurrentCamera->setPosition (pos.x, height + 10.0f, pos.z);
                }
			}


            const Vector3 pos = mCurrentCamera->getDerivedPosition();
		    //Debug Overlay
            // Recover the Configuration options for the landScape plug-in
		    if ( OverlayManager::getSingleton().getByName( "PagingLandScape2/DebugOverlay" ) -> isVisible())
		    {
			    // Show plugin Status
           
		        {
                    OverlayManager::getSingleton().getOverlayElement("PagingLandScape2/Title")->setCaption( "Map: " +
                        mCurrentMap + " TextureFormat:" + mCurrentTexture);
                }

                {
                    int Aux1, Aux2, Aux3, Aux4;

                    mScnMgr->getOption( "CurrentCameraPageX", &Aux1 );
                    mScnMgr->getOption( "CurrentCameraPageZ", &Aux2 );
                    mScnMgr->getOption( "CurrentCameraTileX", &Aux3 );
                    mScnMgr->getOption( "CurrentCameraTileZ", &Aux4 );

                    OverlayManager::getSingleton().getOverlayElement("PagingLandScape2/Page")->setCaption( "Page (X, Z),: (" +
                        StringConverter::toString(Aux1) + ", " +
                        StringConverter::toString(Aux2) + ")" +
                        " Tile (X, Z),: (" +
                        StringConverter::toString(Aux3) + ", " +
                        StringConverter::toString(Aux4) + ")"
                        );
                }

                {
                    int Aux1, Aux2, Aux3, Aux4, Aux5, Aux6;

                    mScnMgr->getOption( "TileFree", &Aux1 );
                    mScnMgr->getOption( "MaxNumTiles", &Aux2 );

                    mScnMgr->getOption( "UnloadedPages", &Aux3);
                    mScnMgr->getOption( "PreLoadedPages", &Aux4 );
                    mScnMgr->getOption( "TextureLoadedPages", &Aux5 );
                    mScnMgr->getOption( "LoadedPages", &Aux6 );

                    OverlayManager::getSingleton().getOverlayElement("PagingLandScape2/FreeTiles")->setCaption( 
                        +" Pages (free, filed, textured, loaded): (" +
                        StringConverter::toString(Aux3) + ", " +
                        StringConverter::toString(Aux4) + ", " +
                        StringConverter::toString(Aux5) + ", " +
                        StringConverter::toString(Aux6) + ") " 

                        + "Tiles (Used, Free): (" +
                        StringConverter::toString(Aux2 - Aux1) + ", " +
                        StringConverter::toString(Aux1) + ")" );
                }


                {
                    int Aux1, Aux2, Aux3, Aux4;

                    mScnMgr->getOption( "RenderableFree", &Aux1 );
                    mScnMgr->getOption( "MaxNumRenderables", &Aux2 );
                    mScnMgr->getOption( "RenderableLoading", &Aux3 );
                    mScnMgr->getOption( "VisibleRenderables", &Aux4 );

                    OverlayManager::getSingleton().getOverlayElement("PagingLandScape2/FreeRenderables")->setCaption( 
                        "Renderables (Used, Free, Loading, Visibles): (" +
                        StringConverter::toString(Aux2 - Aux1) + ", " +
                        StringConverter::toString(Aux1) + ", " +
                        StringConverter::toString(Aux3) + ", " +
                        StringConverter::toString(Aux4) + ")" );

                }

                {
                    OverlayManager::getSingleton().getOverlayElement("PagingLandScape2/Player")->setCaption( 
                        "Player (X, Y, Z): (" +
                        StringConverter::toString(pos.x) + ", " +
                        StringConverter::toString(pos.y) + ", " +
                        StringConverter::toString(pos.z) + ")" );
                }

                {

                OverlayManager::getSingleton().getOverlayElement("PagingLandScape2/Impact")->setCaption(
                  "F1:Help, Debug" );

                }

                {
                    int Aux1, Aux2, Aux3;


                    			mScnMgr->getOption( "PagePreloadQueue", &Aux1 );
                    			mScnMgr->getOption( "PageTextureloadQueue", &Aux2 );
                    			mScnMgr->getOption( "PageLoadQueue", &Aux3 );
                    			OverlayManager::getSingleton().getOverlayElement("PagingLandScape2/Queue")->setCaption( 
                                    "Queues (PreLoad, TextureLoad, Load): (" +
                    				StringConverter::toString(Aux1) + ", " +
                    				StringConverter::toString(Aux2) + ", " +
                    				StringConverter::toString(Aux3) +  ")" );
                    OverlayManager::getSingleton().getOverlayElement("PagingLandScape2/MainQueue")->hide ();
                    //OverlayManager::getSingleton().getOverlayElement("PagingLandScape2/Queue")->hide();
                }
		    }
		    // Return true to continue rendering
		    return returnValue;
	    }

    protected:


    private:
		Camera* mCamera;
		Camera * mCamera2;

        Real mTimeUntilNextLightMove ;

        Overlay* mDebugOverlay;

		Ogre::uint mBallCount;
		SceneNode* mNode; 
        bool mVis;

        String mCurrentMap, mCurrentTexture;


        bool mLandScapeDecalMode;
        bool mLandScapeDeformationMode;
        bool mLandScapeCameraMode;

        Real mSunTimeAdd;
        Real mNextLightMove;

		Real mSunTime;

		Light *mLight;
		SceneNode *mLightNode;

};
