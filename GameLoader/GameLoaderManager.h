#ifndef _H_GAME_LOADER_MANAGER_H
#define _H_GAME_LOADER_MANAGER_H

#include <map>
#include "GameLoader.h"

class GameLoaderManager
{
public:
	virtual ~GameLoaderManager();
	
private:
	GameLoaderManager();
	GameLoaderManager(const GameLoaderManager& rhs) { }
	GameLoaderManager& operator=(const GameLoaderManager& rhs) { return *this; }

public:
	static GameLoaderManager* getSingletonPtr();

private:
	GameLoader* mCurrentGameLoader;
	std::string mDefaultGameLoaderName;
private:
	void removeGameLoaders();
	void createGameLoaders();
public:
	GameLoader* setCurrentGameLoader(const std::string& gameId);
	GameLoader* getCurrentGameLoader();
	GameLoader* getGameLoaderByName(const std::string& gameId);
	GameLoader* setDefaultCurrentGameLoader();
	std::map<std::string, GameLoader*>& getGameLoaders() { return mGameLoaders; }
	void addGameLoader(const std::string& gameId, GameLoader* loader);

private:
	std::map<std::string, GameLoader*> mGameLoaders;

};
#endif