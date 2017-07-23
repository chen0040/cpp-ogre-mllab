#include "OgrePagingLandScapeRaySceneQuery.h" 
#include "TileObjectLoader.h" 

//constructors and destructors are blanks for the moment :( 
TileObjectLoader::TileObjectLoader() 
{ } 
TileObjectLoader::~TileObjectLoader() 
{ } 

void TileObjectLoader::loadEntities(Camera *mCamera)//defines the array of entity types we will load 
{ 
	//some examples of entities 
	type[001]= mCamera->getSceneManager()->createEntity("type001", "rocher.mesh"); 
	
	type[100]= mCamera->getSceneManager()->createEntity("type100", "fish.mesh"); 
	type[101]= mCamera->getSceneManager()->createEntity("type101", "herbe.mesh"); 
} 

//Loads the Level Meshes. 
//Todo: rework it as soon as I've the 1.0.0 compiled :) to use geometry batcher. 
/*Description of parameters : 
	-Platypus is referring to the LevelMap we are working on. 
	I've made it a parameter in order to load several different levels wich entities' base names are different. 
	-Objnode is the "Big" node wich is the father of all the "little" node, for all Level. So it is easy to 
	clear the level: just to do "Objnode->removeAndDestroyAllChildren();" 
	-mCamera is the used Camera(yes! :D). 
	-nom is the char array wich contains the base name of all entities loaded in this program. 
*/ 
void TileObjectLoader::loadObjects(Image *data, 
								   SceneNode *TileNode) 


{ 
	//defines the entities. 
	entTypes (mCamera);    
	//I use A raySceneQuerry to calculate the terrain Height 
	RaySceneQuery	*mRayQuery;           
	mRayQuery = mCamera->getSceneManager()->createRayQuery (Ray (Vector3::ZERO, Vector3::UNIT_Y)); 
	//the "little" node 
	objnode;              
	//the position of the object. 
	Vector3 objPos;                      
	//the definitive entity name. 
	char cloneEntName[21];       
	
	size_t k = 0;
	const uchar *imagedata = data->getData();
	for (size_t x = 0; x < data->getWidth(); ++x)
	{ 
		for (size_t z = 0; z < data->getHeight(); ++z)   
		{                              
			//Analyses the color of the scanned pixel; The color is stocked in "couleur" Vector3 
			 const Entity * const templateEnt = type[imagedata[k++]];
			if (type[imagedata[0]] != 0	)//if the pixel correspong to a type			
			{ 
				
				objPos.x = x*67-66666;//this are my own settings, calculated for my own needs, so do what you want :) ; 
				objPos.z = z*67-66666; 
				
				////Part Calculating the height of the terrain 
				mRayQuery->setRay (Ray(objPos, Vector3::UNIT_Y)); 				
				mRayQuery->setQueryMask (RSQ_Height); 
				RaySceneQueryResult& qryResult = mRayQuery->execute(); 
				RaySceneQueryResult::iterator it = qryResult.begin(); 
				if (it != qryResult.end() && it->worldFragment) 
				{ 
					objPos.y =  it->worldFragment->singleIntersection.y; 
				} 
				////End of Part Calculating the height of the terrain 
				
				SceneNode	* const objnode = TileNode->createChildSceneNode(); 
				//We position the object at world coordinates wich are corresponding to pixel position 
				//objnode->setPosition( objPos.x,objPos.y+2.5,objPos.z); 
				objnode->setPosition (objPos);  
				// generate the name of the cloned Entity.The name is XentNameZ formatted to have different name in all cases. 
				sprintf(cloneEntName, nom, x, z);
				 //we clone the entity wich type is the same as the red color value. 
				cloneEnt = templateEnt->clone(templateEnt->getName() + x + y);  
				//this is the more important part of the program. 
				// Attach to new node 
				objnode->attachObject(cloneEnt);  //we attach the entity 			
			}
		} 			
	} 	
}