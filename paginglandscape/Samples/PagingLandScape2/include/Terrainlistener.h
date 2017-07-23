

//-----------------------------------------------------------------------
class myCustomPagingLandScapeListener : public CustomPagingLandScapeListener
{
    private:

		RenderWindow* mWindow;
        String EventString;
             
    public:
        
        //---------------------------------------------------------------------
		myCustomPagingLandScapeListener (RenderWindow* win, SceneManager *scn) :

		  CustomPagingLandScapeListener(scn),
			mWindow (win)
        {
			    
        }
        //---------------------------------------------------------------------
        ~myCustomPagingLandScapeListener ()
        {

            StaticGeometryList::iterator i = mStaticGeometryList.begin ();
            while (i != mStaticGeometryList.end())
            {
                mSceneMgr->destroyStaticGeometry(i->second);
				//   mStaticGeometryList.erase(i++); 
				//    i = mStaticGeometryList.erase(i); 
				++i; 
			} 
			mStaticGeometryList.clear();
		}
        //---------------------------------------------------------------------
        void pagePreloaded(PagingLandscapeEvent *p) 
        {
			CustomPagingLandScapeListener::pagePreloaded(p);


            const String currPage =
                StringConverter::toString(static_cast <Ogre::uint> (p->mPagex)) + ", " 
                + StringConverter::toString(static_cast <Ogre::uint> (p->mPagez));

         
            if (0)
            {
                const Vector3 min = p->mBbox.getMinimum ();
                const Vector3 max = p->mBbox.getMaximum ();
			    Quaternion orientation;
                Entity* e;
                Ray pickRay;
				pickRay.setDirection (Vector3::UNIT_Y);
				mRayQuery->setQueryTypeMask(Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
				mRayQuery->setWorldFragmentType(SceneQuery::WFT_SINGLE_INTERSECTION); 

                RaySceneQuery *rayQuery = mSceneMgr->createRayQuery (pickRay);


                const bool Tree = true;
                const bool Grass = false;

                    // 2500, 5000, 10000
                    // 375, 750, 1500
                    #ifndef _DEBUG
                        //const Real boxsize = 15000; 
                        //const Ogre::uint interval = 1000;
                        const Real boxsize = 15000; 
                        const Ogre::uint interval = 3000;
                    #else
                        const Real boxsize = 45000; 
                        const Ogre::uint interval = 6000;
                    #endif
                    
                    
                //#define _BATCHED
                #ifdef _BATCHED
                {

                    StaticGeometry* s;
                    
                    if (Grass)
                    {
                        s = mSceneMgr->createStaticGeometry("Static" + currPage + "_GrassPage");
		                s->setRegionDimensions(Vector3(boxsize, boxsize, boxsize));
		                // Set the region origin so the centre is at 0 world
		                s->setOrigin(p->mBbox.getCenter ());
                       
                        // Grass		
                        if (!grassEnt)
                        {
                            const String grassEntName = "Static" + currPage + "_GrassEnt";
                            grassEnt = mSceneMgr->createEntity(grassEntName, GRASS_MESH_NAME);
                            grassEnt->setRenderingDistance (300);
                        }
                        e = grassEnt;
		                for (Real x = min.x; x < max.x; x += interval)
		                {
			                for (Real z = min.z; z < max.z; z += interval)
			                {
				                Vector3 pos(
					                x + Math::RangeRandom(-250, 250), 
					                0, 
					                z + Math::RangeRandom(-250, 250));

				                orientation.FromAngleAxis(
					                Degree(Math::RangeRandom(0, 359)),
					                Vector3::UNIT_Y);

				                const Vector3 scale(Math::RangeRandom(0.01, 0.25), Math::RangeRandom(0.01, 0.25), Math::RangeRandom(0.01, 0.25));

                                //cast a ray into scene and get intersection point, drop a ball there 
                                pickRay.setOrigin (pos);   
                                rayQuery->setRay (pickRay); 
								//rayQuery->setQueryMask (RSQ_Height);  //PLSM2 only
								rayQuery->setQueryTypeMask(Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
								rayQuery->setWorldFragmentType(SceneQuery::WFT_SINGLE_INTERSECTION); 

                                rayQuery->execute ();                         
                                RaySceneQueryResult& result = rayQuery->execute(); 
                                RaySceneQueryResult::iterator i = result.begin(); 
                                if (i != result.end() && i->worldFragment) 
                                { 
                                    pos = i->worldFragment->singleIntersection; 
                                }
                            
				                s->addEntity(e, pos, orientation, scale);
			                }
		                }
		                s->build();
                        mStaticGeometryList[s->getName ()] = s;
                    }
                    // Trees    

                    //"MyTree.mesh"
                    //"MySecondTree.mesh"
                    //"MyPineTree.mesh"
                    if (Tree)
                    {	
                        s = mSceneMgr->createStaticGeometry("Static" + currPage + "_TreePage");
		                s->setRegionDimensions(Vector3(boxsize, boxsize, boxsize));
		                // Set the region origin so the center is at 0 world
		                s->setOrigin(p->mBbox.getCenter ());

                        if (!treeEnt)
                        {
                            const String treeEntName = "Static" + currPage + "_TreeEnt";
                            treeEnt = mSceneMgr->createEntity(treeEntName, "MySecondTree.mesh");
                            treeEnt->setRenderingDistance (1000);
                        }
                        e = treeEnt;

                        for (Real x = min.x; x < max.x; x += interval)
		                {
			                for (Real z = min.z; z < max.z; z += interval)
			                {
				                Vector3 pos(
					                x + Math::RangeRandom(-250*4, 250*4), 
					                0, 
					                z + Math::RangeRandom(-250*4, 250*4));

				                orientation.FromAngleAxis(
					                Degree(Math::RangeRandom(0, 359)),
					                Vector3::UNIT_Y);

				                orientation.FromAngleAxis(
					                Degree(-90),
					                Vector3::UNIT_X);

				                const Vector3 scale(Math::RangeRandom(1.25, 4.25), 
                                                    Math::RangeRandom(1.25, 4.25), 
                                                    Math::RangeRandom(1.25, 4.25));

                                //cast a ray into scene and get intersection point, drop a ball there 
                                pickRay.setOrigin (pos);   
                                rayQuery->setRay (pickRay); 
								//rayQuery->setQueryMask (RSQ_Height);  //PLSM2 only
								rayQuery->setQueryTypeMask(Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
								rayQuery->setWorldFragmentType(SceneQuery::WFT_SINGLE_INTERSECTION); 
                                rayQuery->execute ();                         
                                RaySceneQueryResult& result = rayQuery->execute(); 
                                RaySceneQueryResult::iterator i = result.begin(); 
                                if (i != result.end() && i->worldFragment) 
                                { 
                                    pos = i->worldFragment->singleIntersection; 
                                }
				                s->addEntity(e, pos, orientation, scale);
			                }
		                }

		                s->build();
                        mStaticGeometryList[s->getName ()] = s;
                    }
                }
                
                #else // _BATCHED

                {
                    // Grass
                    if (Grass)
                    {   

                        // Grass		
                        if (!grassEnt)
                        {
                            const String grassEntName = "Static" + currPage + "_GrassEnt";
                            grassEnt = mSceneMgr->createEntity(grassEntName, GRASS_MESH_NAME);
                            grassEnt->setRenderingDistance (300);
                        }
                        e = grassEnt;

		                for (Real x = min.x; x < max.x; x += interval)
		                {
			                for (Real z = min.z; z < max.z; z += interval)
			                {
				                Vector3 pos(
					                x + Math::RangeRandom(-250, 250), 
					                0, 
					                z + Math::RangeRandom(-250, 250));

				                orientation.FromAngleAxis(
					                Degree(Math::RangeRandom(0, 359)),
					                Vector3::UNIT_Y);

				                const Vector3 scale(Math::RangeRandom(0.01, 0.25), Math::RangeRandom(0.01, 0.25), Math::RangeRandom(0.01, 0.25));

                                //cast a ray into scene and get intersection point, drop a ball there 
                                pickRay.setOrigin (pos);   
                                rayQuery->setRay (pickRay); 
								//rayQuery->setQueryMask (RSQ_Height);  //PLSM2 only
								rayQuery->setQueryTypeMask(Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
								rayQuery->setWorldFragmentType(SceneQuery::WFT_SINGLE_INTERSECTION); 
                                rayQuery->execute ();                         
                                RaySceneQueryResult& result = rayQuery->execute(); 
                                RaySceneQueryResult::iterator i = result.begin(); 
                                if (i != result.end() && i->worldFragment) 
                                { 
                                    pos = i->worldFragment->singleIntersection; 
                                }
								const String nameed ("Static" + StringConverter::toString (x) + " " + StringConverter::toString (z) + "_GrassPageStatic" + currPage);

                                SceneNode *sn = mSceneMgr->getRootSceneNode ()->createChildSceneNode (nameed);
                                Entity *eclone = e->clone(nameed);

				                sn->attachObject (eclone);
                                sn->setPosition (pos);
                                sn->setOrientation (orientation);
                                sn->setScale (scale);
			                }
		                }
                    }
                    // Trees    
                    if (Tree)
                    {
                        //"MyTree.mesh"
                        //"MySecondTree.mesh"
                        //"MyPineTree.mesh"
                        if (!treeEnt)
                        {
                            const String treeEntName = "Static" + currPage + "_TreeEnt";
                            treeEnt = mSceneMgr->createEntity(treeEntName, "MySecondTree.mesh");
                            treeEnt->setRenderingDistance (1000);
                        }
                        e = treeEnt;

                        for (Real x = min.x; x < max.x; x += interval)
		                {
			                for (Real z = min.z; z < max.z; z += interval)
			                {
				                Vector3 pos(
					                x + Math::RangeRandom(-250*4, 250*4), 
					                0, 
					                z + Math::RangeRandom(-250*4, 250*4));

				                orientation.FromAngleAxis(
					                Degree(Math::RangeRandom(0, 359)),
					                Vector3::UNIT_Y);

				                orientation.FromAngleAxis(
					                Degree(-90),
					                Vector3::UNIT_X);

				                const Vector3 scale(Math::RangeRandom(1.25, 4.25), 
                                                    Math::RangeRandom(1.25, 4.25), 
                                                    Math::RangeRandom(1.25, 4.25));

                                //cast a ray into scene and get intersection point, drop a ball there 
                                pickRay.setOrigin (pos);   
                                rayQuery->setRay (pickRay); 
								//rayQuery->setQueryMask (RSQ_Height);  //PLSM2 only
								rayQuery->setQueryTypeMask(Ogre::SceneManager::WORLD_GEOMETRY_TYPE_MASK);
								rayQuery->setWorldFragmentType(SceneQuery::WFT_SINGLE_INTERSECTION); 
                                rayQuery->execute ();                         
                                RaySceneQueryResult& result = rayQuery->execute(); 
                                RaySceneQueryResult::iterator i = result.begin(); 
                                if (i != result.end() && i->worldFragment) 
                                { 
                                    pos = i->worldFragment->singleIntersection; 
                                }
								const String nameed ("Static" + currPage + "_TreeEnt" + StringConverter::toString (x) + StringConverter::toString (z));
								SceneNode *sn = mSceneMgr->getRootSceneNode ()->createChildSceneNode (nameed);
                                Entity *eclone = e->clone(nameed);

				                sn->attachObject (eclone);
                                sn->setPosition (pos);
                                sn->setOrientation (orientation);
                                sn->setScale (scale);
			                }
		                }
                    }
                }
                #endif //_BATCHED
                mSceneMgr->destroyQuery (rayQuery);
            }
        }
        //---------------------------------------------------------------------
        void pagePostunloaded(PagingLandscapeEvent *p) 
		{
			CustomPagingLandScapeListener::pagePostunloaded(p);

            const String currPage = 
                StringConverter::toString(static_cast <Ogre::uint> (p->mPagex)) + ", " 
                + StringConverter::toString(static_cast <Ogre::uint> (p->mPagez));

            const String currPageName = "Static" + currPage + "_GrassPage";


                #ifdef _BATCHED

               
                    StaticGeometryList::iterator i = mStaticGeometryList.find(currPageName);
                    if (i != mStaticGeometryList.end())
                    {
                        mSceneMgr->destroyStaticGeometry(currPageName);
	                    mStaticGeometryList.erase(i);
                    }


                    const String currPageName2 = "Static" + currPage + "_TreePage";
                   
                    i = mStaticGeometryList.find(currPageName2);
                    if (i != mStaticGeometryList.end())
                    {
                        mSceneMgr->destroyStaticGeometry(currPageName2);
	                    mStaticGeometryList.erase(i);
                    }

                #else //_BATCHED

                #endif //_BATCHED
           
        }

};

