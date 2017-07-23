#include "Bomb.h"
#include "../GameEngine/Application.h"

Bomb::Bomb()
: Projectile()
{
	mType="bomb";
}

Bomb::~Bomb()
{

}

#if PROJECTILE_MODEL == PROJECTILE_MODEL_ENTITY
Entity* Bomb::createEntity(const std::string& name)
{
	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
	return sm->createEntity(name, "bullet.mesh");
}
#else
ParticleSystem* Bomb::createPS(const std::string& name)
{
	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
	return sm->createParticleSystem(name, "chen0040/Bomb");
}
#endif

void Bomb::initProj()
{
	mProjectileNode->setScale(0.05f, 0.05f, 0.05f);
}

ParticleSystem* Bomb::createExplosion(const std::string& name)
{
	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
	return sm->createParticleSystem(name, "chen0040/BombExplosion");
}

void Bomb::initExplosion()
{

}