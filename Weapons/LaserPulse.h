#ifndef _H_LASER_PULSE_H
#define _H_LASER_PULSE_H

#include "Projectile.h"

class LaserPulse : public Projectile
{
public:
	LaserPulse();
	virtual ~LaserPulse();

protected:
#if PROJECTILE_MODEL == PROJECTILE_MODEL_ENTITY
	virtual Entity* createEntity(const std::string& name);
#else
	virtual ParticleSystem* createPS(const std::string& name);
#endif
	virtual void initProj();
};

#endif