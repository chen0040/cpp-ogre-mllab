#ifndef _H_ML_LAB_WEATHER_MANAGER_H
#define _H_ML_LAB_WEATHER_MANAGER_H

#include <Ogre.h>
#include <vector>

using namespace Ogre;

class WeatherManager
{
public:
	WeatherManager();
	virtual ~WeatherManager();

public:
	static WeatherManager* getSingletonPtr() { return mSingleton; }
	static WeatherManager& getSingleton() { return *mSingleton; }

protected:
	virtual void createRain();
	virtual void createSnow(size_t count);

public:
	void shutdown();
	void showRain(bool shown);
	void showSnow(bool shown);

protected:
	ParticleSystem* mRainPS;
	std::vector<ParticleSystem*> mSnowPS;
	SceneNode* mRainNode;
	std::vector<SceneNode*> mSnowNode;
	static WeatherManager* mSingleton;
};
#endif