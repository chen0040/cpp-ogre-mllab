#ifndef _H_MLLAB_GAME_LOADER_H
#define _H_MLLAB_GAME_LOADER_H

#include <string>
#include "../tinyxml/tinyxml.h"

class GameLoader
{
public:
	GameLoader(TiXmlElement* xmlLevel);
	GameLoader(const std::string& id);
	virtual ~GameLoader();

public:
	void load();
	void unload();
	void save();
	GameLoader* saveAs(const std::string& gameId);
	TiXmlElement* toXml() const;

public:
	void setResourceUrl(const std::string& url) { mResourceUrl=url; }
	void setResourceLocType(const std::string& locType) { mResourceLocType=locType; }
	void setSkyType(const std::string& type) { mSkyType=type; }
	void setSkyTypeUri(const std::string& uri) { mSkyTypeUri=uri; }

public:
	const std::string getSkyType() const { return mSkyType; }
	const std::string getSkyTypeUri() const { return mSkyTypeUri; }

public:
	void loadSky(const std::string& skyType, const std::string& skyTypeUri);
	const std::string& getAbstract() const { return mAbstract; }

public:
	const std::string& getId() const { return mId; }
	
private:
	std::string mId;
	std::string mResourceUrl;
	std::string mResourceLocType;
	std::string mSetupUrl;
	std::string mSkyType;
	std::string mSkyTypeUri;
	std::string mAbstract;
};
#endif