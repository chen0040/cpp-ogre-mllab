#include "LuaAPI.h"
#include "../CIAgents/CIAgentManager.h"
#include "../Widgets/GUIManager.h"
#include "../GameEngine/Application.h"
#include "../OSEnvironment/OSEnvironment.h"
#include "../HTTPEngine/HTTPManager.h"
#include "../GameEngine/Application.h"
#include "../Weapons/WeaponManager.h"
#include "../CIAgents/StaticAgentManager.h"
#include "../GameLoader/GameLoaderManager.h"
#include <Ogre.h>
#include <sstream>

void alert(const char* text, const char* title)
{
	GUIManager::getSingletonPtr()->showMsgBox(title, text);
}
/*
void unloadBuildings()
{
	StaticAgentManager::getSingletonPtr()->removeAllAgents();
}

void loadBuilding(const std::string& buildId, const Vector3& pos, const Vector3& scale, const Vector3& rotation)
{
	CIAgent* agent=StaticAgentManager::getSingletonPtr()->createStaticAgent(pos);
	agent->changeModel(buildId);
	agent->getEntityNode()->setScale(scale);
	agent->getEntityNode()->setDirection(rotation);
}
*/

void showConsole(bool shown)
{
	if(shown)
	{
		Application::getSingletonPtr()->getConsole()->show();
	}
	else
	{
		Application::getSingletonPtr()->getConsole()->hide();
	}
}

void print2Console(const char* text)
{
	Application::getSingletonPtr()->getConsole()->setText(text);
}

void print2File(const char* text)
{
	LogManager::getSingletonPtr()->getDefaultLog()->logMessage(text);
}

void repaint()
{
	Application::getSingletonPtr()->render();
}

clock_t getTime()
{
	return clock();
}

bool fileExists(const char* fileName)
{
	return OSEnvironment::exists(fileName);
}

std::string getDefaultScriptPath()
{
	return OSEnvironment::getFullPath("..\\script_classes");
}

void httpAddField(const std::string& name, const std::string& value)
{
	HTTPManager::getSingletonPtr()->add2Buffer(name, value);
}

void loadTerrain(const std::string& groupName)
{
	TerrainInfoManager::getSingletonPtr()->loadTerrain(groupName);
}

void unloadTerrain()
{
	TerrainInfoManager::getSingletonPtr()->unloadTerrain();
}

void loadSkyDome(const std::string& skyDomeName)
{
	Application* app=Application::getSingletonPtr();

	app->getSceneMgr()->setSkyDome(true, skyDomeName.c_str());
	
	GameLoader* loader=GameLoaderManager::getSingletonPtr()->getCurrentGameLoader();
	if(loader != NULL)
	{
		loader->setSkyType("SkyDome");
		loader->setSkyTypeUri(skyDomeName);
	}
}

void unloadSkyDome(const std::string& skyDomeName)
{
	Application::getSingletonPtr()->getSceneMgr()->setSkyDome(false, skyDomeName.c_str());
}

void loadSkyBox(const std::string& skyBoxName)
{
	Application* app=Application::getSingletonPtr();

	app->getSceneMgr()->setSkyBox(true, skyBoxName.c_str());

	GameLoader* loader=GameLoaderManager::getSingletonPtr()->getCurrentGameLoader();
	if(loader != NULL)
	{
		loader->setSkyType("SkyBox");
		loader->setSkyTypeUri(skyBoxName);
	}
}

void unloadSkyBox(const std::string& skyBoxName)
{
	Application::getSingletonPtr()->getSceneMgr()->setSkyBox(false, skyBoxName.c_str());
}

void loadSkyPlane(const std::string& skyPlaneName)
{
	Application* app=Application::getSingletonPtr();

	Plane plane;
	plane.d = 1000;
	plane.normal = Vector3::NEGATIVE_UNIT_Y;

	app->getSceneMgr()->setSkyPlane(true, plane, skyPlaneName.c_str());
	GameLoader* loader=GameLoaderManager::getSingletonPtr()->getCurrentGameLoader();
	if(loader != NULL)
	{
		loader->setSkyType("SkyPlane");
		loader->setSkyTypeUri(skyPlaneName);
	}
}

void unloadSkyPlane(const std::string& skyPlaneName)
{
	Plane plane;
	plane.d = 1000;
	plane.normal = Vector3::NEGATIVE_UNIT_Y;

	Application::getSingletonPtr()->getSceneMgr()->setSkyPlane(false, plane, skyPlaneName.c_str());
}

void loadCaelum()
{
	CaelumManager::getSingletonPtr()->loadCaelum();

	GameLoader* loader=GameLoaderManager::getSingletonPtr()->getCurrentGameLoader();
	if(loader != NULL)
	{
		loader->setSkyType("SkyCaelum");
		loader->setSkyTypeUri("");
	}
}

void unloadCaelum()
{
	CaelumManager::getSingletonPtr()->unloadCaelum();
}

void setCaelumTimeScale(float timeScale)
{
	CaelumManager::getSingletonPtr()->setTimeScale(timeScale);
}

void setCaelumDateTime(int year, int month, int day, int hour, int minute, int second)
{
	CaelumManager::getSingletonPtr()->setDateTime(year, month, day, hour, minute, second);
}

void setCaelumCloudSpeed(float x, float y)
{
	CaelumManager::getSingletonPtr()->setCloudSpeed(Vector2(x, y));
}

void enableCaelumLighting()
{
	CaelumManager::getSingletonPtr()->enableLighting();
}

void disableCaelumLighting()
{
	CaelumManager::getSingletonPtr()->disableLighting();
}

void loadHydrax()
{
	HydraxManager::getSingletonPtr()->loadHydrax();
}

void unloadHydrax()
{
	HydraxManager::getSingletonPtr()->unloadHydrax();
}

void loadOcean()
{
	HydraxManager::getSingletonPtr()->loadOgreOcean();
}

void unloadOcean()
{
	HydraxManager::getSingletonPtr()->unloadOgreOcean();
}

std::string getApplicationDir()
{
	return OSEnvironment::getApplicationDir();
}

std::string getGameId() 
{
	return GameLoaderManager::getSingletonPtr()->getCurrentGameLoader()->getId();
}

std::string getGameDir()
{
	std::ostringstream oss;
	oss << getApplicationDir() << "..\\games\\" << GameLoaderManager::getSingletonPtr()->getCurrentGameLoader()->getId();
	return oss.str();
}

void setOceanHeight(int height)
{
	HydraxManager::getSingletonPtr()->setOgreOceanHeight(height);
}

void setOceanSize(int widthX, int widthZ)
{
	HydraxManager::getSingletonPtr()->setOgreOceanSize(widthX, widthZ);
}

void loadTree1(const Vector3& pos)
{
	PGManager::getSingletonPtr()->loadTree1(pos, Degree(Math::RangeRandom(0, 360)), Math::RangeRandom(0.5f, 0.6f));
}

void loadBush(const Vector3& pos)
{
	PGManager::getSingletonPtr()->loadBush(pos, 1, 1);
}

void unloadForest()
{
	PGManager::getSingletonPtr()->unloadForest();
}

void loadGrass(int left, int top, int right, int bottom)
{
	PGManager::getSingletonPtr()->loadGrass(left, top, right, bottom);
}

void setBlastImpactTextureId(CEGUI::uint id)
{
	WeaponManager::getSingletonPtr()->setBlastImpactTextureId(id);
}