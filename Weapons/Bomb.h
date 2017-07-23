#ifndef _H_BOMB_H
#define _H_BOMB_H

#include "Projectile.h"

class Bomb : public Projectile
{
public:
	Bomb();
	virtual ~Bomb();

protected:
#if PROJECTILE_MODEL == PROJECTILE_MODEL_ENTITY
	virtual Entity* createEntity(const std::string& name);
#else
	virtual ParticleSystem* createPS(const std::string& name);
#endif
	virtual void initProj();
	virtual void initExplosion();
	virtual ParticleSystem* createExplosion(const std::string& name);
};

#endif