class TileObjectLoader { 
	public: 
	   TileObjectLoader(); 
	   ~TileObjectLoader(); 
	   
	   void loadEntities(Entity*type[],Camera*mCamera); 
	
	
	   void loadObjects(LevelMap*Platypus, 
						   SceneNode* Objnode, 
						   Camera*mCamera, 
						   char nom[]); 
   protected: 

	   char 	NewLevel; 
	   Entity	*type[256]; 
	   void 	entTypes(Camera*); 
	   Entity	*cloneEnt; 
    
};