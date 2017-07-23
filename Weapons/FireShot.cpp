#include "FireShot.h"
#include "../GameEngine/Application.h"

FireShot::FireShot()
: Projectile()
{
	mType="fire_shot";
}

FireShot::~FireShot()
{

}

#if PROJECTILE_MODEL == PROJECTILE_MODEL_ENTITY
Entity* FireShot::createEntity(const std::string& name)
{
	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
	return sm->createEntity(name, "bullet.mesh");
}
#else
ParticleSystem* FireShot::createPS(const std::string& name)
{
	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
	return sm->createParticleSystem(name, "chen0040/FireShot");
}
#endif

void FireShot::initProj()
{
	mProjectileNode->setScale(0.05f, 0.05f, 0.05f);
	mProjectileNode->pitch(Degree(90));
}

ParticleSystem* FireShot::createExplosion(const std::string& name)
{
	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
	return sm->createParticleSystem(name, "chen0040/FireShotExplosion");
}

void FireShot::initExplosion()
{

}