#include "GameLoaderManager.h"
#include "../OSEnvironment/OSEnvironment.h"
#include <Ogre.h>

GameLoaderManager::GameLoaderManager()
: mCurrentGameLoader(NULL)
, mDefaultGameLoaderName("")
{
	createGameLoaders();
}

GameLoaderManager::~GameLoaderManager()
{
	removeGameLoaders();
}

GameLoaderManager* GameLoaderManager::getSingletonPtr()
{
	static GameLoaderManager theInstance;
	return &theInstance;
}


void GameLoaderManager::removeGameLoaders()
{
	TiXmlDocument doc;
	doc.LinkEndChild(new TiXmlDeclaration("1.0", "", ""));
	
	TiXmlElement* xmlRoot=new TiXmlElement("games");
	xmlRoot->SetAttribute("default", mDefaultGameLoaderName.c_str());
	doc.LinkEndChild(xmlRoot);

	std::map<std::string, GameLoader*>::iterator miter=mGameLoaders.begin();
	std::map<std::string, GameLoader*>::iterator miter_end=mGameLoaders.end();
	for(; miter != miter_end; ++miter)
	{
		xmlRoot->LinkEndChild(miter->second->toXml());
		delete miter->second;
	}
	mGameLoaders.clear();

	doc.SaveFile(OSEnvironment::getFullPath("..\\games\\games.xml").c_str());
}



GameLoader* GameLoaderManager::getCurrentGameLoader()
{
	return mCurrentGameLoader;
}

GameLoader* GameLoaderManager::setDefaultCurrentGameLoader()
{
	return setCurrentGameLoader(mDefaultGameLoaderName);
}

GameLoader* GameLoaderManager::getGameLoaderByName(const std::string &gameId)
{
	std::map<std::string, GameLoader*>::iterator fnd=mGameLoaders.find(gameId);
	if(fnd != mGameLoaders.end())
	{
		return fnd->second;
	}
	return NULL;
}

void GameLoaderManager::addGameLoader(const std::string& gameId, GameLoader* loader)
{
	mGameLoaders[gameId]=loader;
}

GameLoader* GameLoaderManager::setCurrentGameLoader(const std::string& gameId)
{
	std::map<std::string, GameLoader*>::iterator fnd=mGameLoaders.find(gameId);
	if(fnd == mGameLoaders.end())
	{
		return NULL;
	}

	GameLoader* loader=fnd->second;

	if(loader != mCurrentGameLoader)
	{
		if(mCurrentGameLoader != NULL)
		{
			mCurrentGameLoader->unload();
		}
		mCurrentGameLoader=loader;
		loader->load();
	}

	return loader;
}

void GameLoaderManager::createGameLoaders()
{
	TiXmlDocument doc;
	if(!doc.LoadFile(OSEnvironment::getFullPath("..\\games\\games.xml").c_str()))
	{
		throw Ogre::Exception(42, "Failed to load games.xml", "MainMenuFrame::createGameLoaders()");
	}

	TiXmlElement* xmlRoot=doc.RootElement();
	mDefaultGameLoaderName=xmlRoot->Attribute("default");
	for(TiXmlElement* xmlLevel1=xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1=xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "game")==0)
		{
			std::string id=xmlLevel1->Attribute("name");
			GameLoader* loader=new GameLoader(xmlLevel1);
			mGameLoaders[id]=loader;
		}
	}
}