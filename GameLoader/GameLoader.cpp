#include "GameLoader.h"
#include "../Terrain/TerrainInfoManager.h"
#include "../ScriptEngine/ScriptManager.h"
#include "../OSEnvironment/OSEnvironment.h"
#include "../GameEngine/Application.h"
#include "../Weapons/WeaponManager.h"
#include "../CIAgents/StaticAgentManager.h"

GameLoader::GameLoader(const std::string& id)
: mId(id)
, mSkyType("")
, mSkyTypeUri("")
{

}

GameLoader::GameLoader(TiXmlElement* xmlLevel)
{
	mId=xmlLevel->Attribute("name");

	for(TiXmlElement* xmlLevel1=xmlLevel->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1=xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "resource")==0)
		{
			mResourceUrl=xmlLevel1->Attribute("url");
			mResourceLocType=xmlLevel1->Attribute("loc_type");
		}
	}

	std::ostringstream oss;
	oss << "..\\games\\" << mId << "\\GameSetup.lua";
	mSetupUrl=oss.str();

	oss.str("");
	oss << "..\\games\\" << mId << "\\ReadMe.txt";
	mAbstract=OSEnvironment::readFile(OSEnvironment::getFullPath(oss.str()));
}

GameLoader::~GameLoader()
{
	
}

void GameLoader::unload()
{
	using namespace luabind;
	lua_State* L=ScriptManager::getSingletonPtr()->getLuaState();

	std::string setupScript=OSEnvironment::getFullPath(mSetupUrl);
	if(luaL_dofile(L, setupScript.c_str())!=0)
	{
		std::ostringstream oss;
		oss << "dofile(" << setupScript << ")" << std::endl;
		ScriptManager::exception("GameLoader::load()", oss.str().c_str());
	}

	object g=globals(L);
	object onGameUnload=g["onGameUnload"];
	
	if(onGameUnload)
	{
		onGameUnload(mId);
	}
	else
	{
		ScriptManager::getSingletonPtr()->exception("GameLoader::unload()", mId.c_str());
	}

	PGManager::getSingletonPtr()->unloadForest();

	ResourceGroupManager::getSingleton().destroyResourceGroup(mId.c_str());
}

void GameLoader::load()
{
	StaticAgentManager* sas=StaticAgentManager::getSingletonPtr();
	sas->removeAllAgents();

	std::ostringstream oss;
	oss << "..\\games\\" << mId;

	std::string gameFolder=OSEnvironment::getFullPath(oss.str());
	std::string building_doc=OSEnvironment::append(gameFolder, "\\buildings.xml");

	if(OSEnvironment::exists(building_doc))
	{
		TiXmlDocument doc;
		if(doc.LoadFile(building_doc.c_str()))
		{
			TiXmlElement* doc_root=doc.RootElement();
			for(TiXmlElement* doc_level1=doc_root->FirstChildElement(); doc_level1 != NULL; doc_level1= doc_level1->NextSiblingElement())
			{
				if(strcmp(doc_level1->Value(), "building")==0)
				{
					Real pos_x, pos_y, pos_z, scale_x, scale_y, scale_z, x, y, z, w;
					doc_level1->QueryFloatAttribute("pos_x", &pos_x);
					doc_level1->QueryFloatAttribute("pos_y", &pos_y);
					doc_level1->QueryFloatAttribute("pos_z", &pos_z);
					doc_level1->QueryFloatAttribute("scale_x", &scale_x);
					doc_level1->QueryFloatAttribute("scale_y", &scale_y);
					doc_level1->QueryFloatAttribute("scale_z", &scale_z);
					doc_level1->QueryFloatAttribute("w", &w);
					doc_level1->QueryFloatAttribute("x", &x);
					doc_level1->QueryFloatAttribute("y", &y);
					doc_level1->QueryFloatAttribute("z", &z);
					CIAgent* agent=sas->createStaticAgent(Vector3(pos_x, pos_y, pos_z));
					agent->changeModel(doc_level1->Attribute("id"));
					SceneNode* sn=agent->getEntityNode();
					sn->setPosition(Vector3(pos_x, pos_y, pos_z));
					sn->setScale(Vector3(scale_x, scale_y, scale_z));
					sn->setOrientation(Quaternion(w, x, y, z));
				}
			}
		}
	}

	ResourceGroupManager::getSingleton().addResourceLocation(mResourceUrl.c_str(), mResourceLocType.c_str(), mId.c_str());
	ResourceGroupManager::getSingleton().initialiseResourceGroup(mId.c_str());

	using namespace luabind;
	lua_State* L=ScriptManager::getSingletonPtr()->getLuaState();

	std::string setupScript=OSEnvironment::getFullPath(mSetupUrl);
	if(luaL_dofile(L, setupScript.c_str())!=0)
	{
		std::ostringstream oss;
		oss << "dofile(" << setupScript << ")" << std::endl;
		ScriptManager::exception("GameLoader::load()", oss.str().c_str());
	}

	object g=globals(L);
	object onGameLoad=g["onGameLoad"];
	
	if(onGameLoad)
	{
		onGameLoad(mId);
	}
	else
	{
		ScriptManager::getSingletonPtr()->exception("GameLoader::load()", mId.c_str());
	}
}

void GameLoader::loadSky(const std::string& skyType, const std::string& skyTypeUri)
{
	Application* app=Application::getSingletonPtr();
	SceneManager* sm=app->getSceneMgr();

	if(mSkyType.compare("SkyBox")==0)
	{
		sm->setSkyBox(false, skyTypeUri.c_str());
	}
	else if(mSkyType.compare("SkyPlane")==0)
	{
		Plane plane;
		plane.d=1000;
		plane.normal=Vector3::NEGATIVE_UNIT_Y;
		sm->setSkyPlane(false, plane, skyTypeUri.c_str());
	}
	else if(mSkyType.compare("SkyDome")==0)
	{
		sm->setSkyDome(false, skyTypeUri.c_str());
	}
	else if(mSkyType.compare("SkyCaelum")==0)
	{
		CaelumManager::getSingletonPtr()->unloadCaelum();
	}

	if(skyType.compare("SkyBox")==0)
	{
		sm->setSkyBox(true, skyTypeUri.c_str());
	}
	else if(skyType.compare("SkyPlane")==0)
	{
		Plane plane;
		plane.d=1000;
		plane.normal=Vector3::NEGATIVE_UNIT_Y;
		sm->setSkyPlane(true, plane, skyTypeUri.c_str());
	}
	else if(skyType.compare("SkyDome")==0)
	{
		sm->setSkyDome(true, skyTypeUri.c_str());
	}
	else if(skyType.compare("SkyCaelum")==0)
	{
		CaelumManager::getSingletonPtr()->loadCaelum();
	}

	mSkyType=skyType;
	mSkyTypeUri=skyTypeUri;
}

void GameLoader::save()
{
	std::ostringstream oss;
	oss << "..\\games\\" << mId;

	std::string gameFolder=OSEnvironment::getFullPath(oss.str());

	TerrainInfoManager* tm=TerrainInfoManager::getSingletonPtr();
	tm->saveTerrain(gameFolder);

	std::string gameSetupScriptPath=OSEnvironment::append(gameFolder, "\\GameSetup.lua");

	std::ofstream fout;
	fout.open(gameSetupScriptPath.c_str());

	fout << "function onGameLoad(gameId)" << "\n";

	//save loadTerrain
	if(tm->isTerrainLoaded())
	{
		fout << "\t" << "loadTerrain(gameId);" << "\n";
	}

	//save loadSky
	if(mSkyType.compare("SkyDome")==0)
	{
		fout << "\t" << "loadSkyDome(\"" << mSkyTypeUri << "\");\n";
	}
	else if(mSkyType.compare("SkyBox")==0)
	{
		fout << "\t" << "loadSkyBox(\"" << mSkyTypeUri << "\");\n";
	}
	else if(mSkyType.compare("SkyPlane")==0)
	{
		fout << "\t" << "loadSkyPlane(\"" << mSkyTypeUri << "\");\n";
	}
	else if(mSkyType.compare("SkyCaelum")==0)
	{
		CaelumManager* cm=CaelumManager::getSingletonPtr();
		fout << "\t" << "loadCaelum();\n";
		fout << "\t" << "setCaelumCloudSpeed(" << cm->getCloudSpeedX() << ", " << cm->getCloudSpeedY() << ");\n";
		fout << "\t" << "setCaelumTimeScale(" << cm->getTimeScale() << ");\n";
		if(cm->isLightingEnabled())
		{
			fout << "\t" << "enableCaelumLighting();\n";
		}
		else
		{
			fout << "\t" << "disableCaelumLighting();\n";
		}
		fout << "\t--caelum starts run at " << cm->getDateTimeText() << "\n";
		int year, month, day, hour, minute, second;
		cm->getDateTime(year, month, day, hour, minute, second);
		fout << "\tsetCaelumDateTime(" << year << ", " << month << ", " << day << ", " << hour << ", " << minute << ", " << second << ");\n";
	}

	//save loadHydrax
	HydraxManager* hm=HydraxManager::getSingletonPtr();
	if(hm->isHydraxLoaded())
	{
		fout << "\tloadHydrax();\n";
	}
	else if(hm->isOgreOceanLoaded())
	{
		fout << "\tsetOceanHeight(" << hm->getOgreOceanHeight() << ");\n";
		fout << "\tsetOceanSize(" << hm->getOgreOceanSizeX() << ", " << hm->getOgreOceanSizeZ() << ");\n";
		fout << "\tloadOcean();\n";
	}

	PGManager* pgm=PGManager::getSingletonPtr();

	bool forest_exists=pgm->isForestLoaded();
	if(forest_exists)
	{
		fout << "\tdofile(getApplicationDir() .. " << "\"" << "\\\\..\\\\games\\\\" << this->mId << "\\\\forests.lua" << "\");\n";

		std::ofstream fout_forest;
		fout_forest.open(OSEnvironment::append(gameFolder, "\\forests.lua").c_str());

		if(pgm->isTreeLoaded())
		{
#if TREE_MODEL == TREE_MODEL_3D
			Forests::TreeIterator3D titer=pgm->getTreeLoader()->getTrees();
#else
			Forests::TreeIterator2D titer=pgm->getTreeLoader()->getTrees();
#endif

			bool hasTrees=false;
			while(titer.hasMoreElements())
			{
				Forests::TreeRef ref=titer.getNext();
				Vector3& pos=ref.getPosition();
				fout_forest << "loadTree1(Vector3(" << pos.x << ", " << pos.y << ", " << pos.z << "));\n";
				hasTrees=true;
			}
			//pickup the last tree
			if(hasTrees)
			{
				Forests::TreeRef ref=titer.peekNext();
				Vector3& pos=ref.getPosition();
				fout_forest << "loadTree1(Vector3(" << pos.x << ", " << pos.y << ", " << pos.z << "));\n";
			}
		}
		
		if(pgm->isBushLoaded())
		{
			Forests::TreeLoader2D* bushLoader=pgm->getBushLoader();
			Forests::TreeIterator2D biter=bushLoader->getTrees();

			while(biter.hasMoreElements())
			{
				Forests::TreeRef ref=biter.getNext();
				Vector3& pos=ref.getPosition();
				fout_forest << "loadBush(Vector3(" << pos.x << ", " << pos.y << ", " << pos.z << "));\n";
			}
		}		

		if(pgm->isGrassLoaded())
		{
			Forests::GrassLoader* grassLoader=pgm->getGrassLoader();
			std::list<Forests::GrassLayer*>& glst=grassLoader->getLayerList();
			std::list<Forests::GrassLayer*>::iterator giter=glst.begin();
			std::list<Forests::GrassLayer*>::iterator giter_end=glst.end();
			Forests::GrassLayer* l=NULL;
			for(; giter!=giter_end; ++giter)
			{
				l=*giter;
				const TBounds& tb=l->getMapBounds();
				fout_forest << "loadGrass(" << tb.left << ", " << tb.top << ", " << tb.right << ", " << tb.bottom << ");\n";
			}
		}
		fout_forest.close();
	}

	StaticAgentManager::StaticAgentSet& sas=StaticAgentManager::getSingletonPtr()->getCurrentStaticAgents();
	if(!sas.empty())
	{
		std::string building_doc=OSEnvironment::append(gameFolder, "\\buildings.xml");
		TiXmlDocument doc;
		doc.LinkEndChild(new TiXmlDeclaration("1.0", "", ""));
		TiXmlElement* doc_root=new TiXmlElement("buildings");
		doc.LinkEndChild(doc_root);

		StaticAgentManager::StaticAgentSetIter si=sas.begin();
		StaticAgentManager::StaticAgentSetIter si_end=sas.end();
		CIAgent* agent=NULL;
		for(; si != si_end; ++si)
		{
			agent=*si;

			const std::string& model_name=agent->getModelName();
			const Vector3& pos=agent->getPosition();
			const Vector3& scale=agent->getEntityNode()->getScale();
			const Quaternion& orientation=agent->getEntityNode()->getOrientation();

			TiXmlElement* doc_level=new TiXmlElement("building");
			doc_level->SetAttribute("id", model_name.c_str());
			doc_level->SetDoubleAttribute("pos_x", pos.x);
			doc_level->SetDoubleAttribute("pos_y", pos.y);
			doc_level->SetDoubleAttribute("pos_z", pos.z);
			doc_level->SetDoubleAttribute("scale_x", scale.x);
			doc_level->SetDoubleAttribute("scale_y", scale.y);
			doc_level->SetDoubleAttribute("scale_z", scale.z);
			doc_level->SetDoubleAttribute("w", orientation.w);
			doc_level->SetDoubleAttribute("x", orientation.x);
			doc_level->SetDoubleAttribute("y", orientation.y);
			doc_level->SetDoubleAttribute("z", orientation.z);
			doc_root->LinkEndChild(doc_level);
		}

		doc.SaveFile(building_doc.c_str());
	}

	fout << "\tsetBlastImpactTextureId(" << WeaponManager::getSingletonPtr()->getBlastImpactTextureId() << ");\n";
	fout << "end" << "\n";
	fout << "\n";
	fout << "function onGameUnload(gameId)" << "\n";

	//save unloadHydrax
	if(hm->isHydraxLoaded())
	{
		fout << "\tunloadHydrax();\n";
	}
	else if(hm->isOgreOceanLoaded())
	{
		fout << "\tunloadOcean();\n";
	}


	//save unloadSky
	if(mSkyType.compare("SkyCaelum")==0)
	{
		fout << "\tunloadCaelum();\n";
	}
	else if(mSkyType.compare("SkyDome")==0)
	{
		fout << "\tunloadSkyDome(\"" << mSkyTypeUri << "\");" << "\n";
	}
	else if(mSkyType.compare("SkyBox")==0)
	{
		fout << "\tunloadSkyBox(\"" << mSkyTypeUri << "\");" << "\n";
	}
	else if(mSkyType.compare("SkyPlane")==0)
	{
		fout << "\tunloadSkyPlane(\"" << mSkyTypeUri << "\");" << "\n";
	}

	if(forest_exists)
	{
		fout << "\tunloadForest();\n";
	}

	/*
	if(!sas.empty())
	{
		fout << "\tunloadBuildings();\n";
	}
	*/

	//save unloadTerrain
	if(tm->isTerrainLoaded())
	{
		fout << "\tunloadTerrain();\n";
	}
	
	fout << "end" << "\n";

	fout.close();

}

TiXmlElement* GameLoader::toXml() const
{
	TiXmlElement* xmlLoader=new TiXmlElement("game");

	xmlLoader->SetAttribute("name", mId.c_str());
	TiXmlElement* xmlResource=new TiXmlElement("resource");

	std::ostringstream oss;
	oss << "../games/" << mId;
	xmlResource->SetAttribute("url", oss.str().c_str());
	xmlResource->SetAttribute("loc_type", "FileSystem");
	xmlLoader->LinkEndChild(xmlResource);

	return xmlLoader;
}

GameLoader* GameLoader::saveAs(const std::string& gameId)
{
	std::ostringstream oss;

	oss << "..\\games\\" << mId;
	std::string src=OSEnvironment::getFullPath(oss.str());

	oss.str("");
	oss << "..\\games\\" << gameId;
	std::string dest=OSEnvironment::getFullPath(oss.str());

	OSEnvironment::copyFolder(src, dest);

	TerrainInfoManager::getSingletonPtr()->saveTerrain(dest);

	GameLoader* loader=new GameLoader(gameId);
	loader->setResourceLocType("FileSystem");

	oss.str("");
	oss << "../games/" << gameId;
	loader->setResourceUrl(oss.str());

	return loader;

}