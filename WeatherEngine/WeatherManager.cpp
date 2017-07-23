#include "WeatherManager.h"
#include "../GameEngine/Application.h"
#include <sstream>

WeatherManager* WeatherManager::mSingleton=NULL;

WeatherManager::WeatherManager()
{
	if(mSingleton==NULL)
	{
		mSingleton=this;
	}
	else
	{
		throw Exception(42, "multiple instances not allowed!", "WeatherManager::WeatherManager()");
	}

	createRain();
	createSnow(1);
	const Real x1=300;
	const Real x2=1200;
	const Real z1=300;
	const Real z2=1200;
	const Real y=310;
	mSnowNode[0]->setScale(3, 1, 3);
	mSnowNode[0]->translate(750, y, 750);
}

WeatherManager::~WeatherManager()
{

}

void WeatherManager::createRain()
{
	Application* app=Application::getSingletonPtr();
	SceneManager* sm=app->getSceneMgr();

	mRainPS = sm->createParticleSystem("WeatherSystem/Rain", "Examples/Rain");
    mRainNode= sm->getRootSceneNode()->createChildSceneNode();
    mRainNode->translate(750, 500, 750);
    mRainNode->attachObject(mRainPS);
    // Fast-forward the rain so it looks more natural
    mRainPS->fastForward(5);

	mRainNode->setVisible(false);
}

void WeatherManager::createSnow(size_t count)
{
	Application* app=Application::getSingletonPtr();
	SceneManager* sm=app->getSceneMgr();

	ParticleSystem* snowPS=NULL;
	SceneNode* snowNode=NULL;
	for(size_t k=0; k != count; ++k)
	{
		std::ostringstream oss;
		oss << "WeatherSystem/Snow" << k; 
		snowPS = sm->createParticleSystem(oss.str(), "Examples/Snow");
		snowNode= sm->getRootSceneNode()->createChildSceneNode();
		snowNode->attachObject(snowPS);
		snowNode->setVisible(false);

		mSnowPS.push_back(snowPS);
		mSnowNode.push_back(snowNode);
	}
}

void WeatherManager::shutdown()
{
	showRain(false);
	showSnow(false);
}
	
void WeatherManager::showRain(bool shown)
{
	mRainNode->setVisible(shown);
}
	
void WeatherManager::showSnow(bool shown)
{
	std::vector<SceneNode*>::iterator iter=mSnowNode.begin();
	std::vector<SceneNode*>::iterator iter_end=mSnowNode.end();
	for(; iter != iter_end; ++iter)
	{
		(*iter)->setVisible(shown);
	}
}
