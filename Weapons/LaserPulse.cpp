#include "LaserPulse.h"
#include "../GameEngine/Application.h"

LaserPulse::LaserPulse()
: Projectile()
{
	mType="laser_pulse";
}

LaserPulse::~LaserPulse()
{

}

#if PROJECTILE_MODEL == PROJECTILE_MODEL_ENTITY
Entity* LaserPulse::createEntity(const std::string& name)
{
	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
	return sm->createEntity(name, "bullet.mesh");
}
#else
ParticleSystem* LaserPulse::createPS(const std::string& name)
{
	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
	return sm->createParticleSystem(name, "chen0040/LaserPulse");
}
#endif

void LaserPulse::initProj()
{
	mProjectileNode->setScale(0.05f, 0.05f, 0.05f);
}