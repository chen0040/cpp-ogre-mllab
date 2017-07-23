#ifndef _H_FIRE_SHOT_H
#define _H_FIRE_SHOT_H

#include "Projectile.h"

class FireShot : public Projectile
{
public:
	FireShot();
	virtual ~FireShot();

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