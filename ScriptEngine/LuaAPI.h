#ifndef _H_ML_LAB_LUA_API_H
#define _H_ML_LAB_LUA_API_H

#include <luabind/luabind.hpp>
#include <luabind/operator.hpp>
#include <ctime>

#include "../CIAgents/CIGameAgent.h"

using namespace luabind;

void alert(const char* text, const char* title);

clock_t getTime();

bool fileExists(const char* fileName);

std::string getDefaultScriptPath();

void print2Console(const char* text);
void print2File(const char* text);

void showConsole(bool shown);

void httpAddField(const std::string& name, const std::string& value);

void repaint();

void loadTerrain(const std::string& groupName);
void unloadTerrain();

void loadSkyDome(const std::string& skyDomeName);
void unloadSkyDome(const std::string& skyDomeName);

void loadSkyBox(const std::string& skyBoxName);
void unloadSkyBox(const std::string& skyBoxName);

void loadSkyPlane(const std::string& skyPlaneName);
void unloadSkyPlane(const std::string& skyPlaneName);

void loadCaelum();
void unloadCaelum();
void setCaelumTimeScale(float timeScale);
void setCaelumDateTime(int year, int month, int day, int hour, int minute, int second);
void setCaelumCloudSpeed(float x, float y);
void enableCaelumLighting();
void disableCaelumLighting();

void loadOcean();
void unloadOcean();
void setOceanHeight(int height);
void setOceanSize(int widthX, int widthZ);

void loadHydrax();
void unloadHydrax();

std::string getApplicationDir();

void loadTree1(const Vector3& pos);
void loadBush(const Vector3& pos);
void loadGrass(int left, int top, int right, int bottom);

void setBlastImpactTextureId(CEGUI::uint id);

std::string getGameDir();
std::string getGameId();

void unloadForest();

//void unloadBuildings();
//void loadBuilding(const std::string& buildId, const Vector3& pos, const Vector3& scale, const Vector3& rotation);

#endif
