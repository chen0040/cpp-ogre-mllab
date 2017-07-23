#ifndef _H_ML_LAB_PROJECTILE_H
#define _H_ML_LAB_PROJECTILE_H

#include <Ogre.h>

#define PROJECTILE_MODEL_PS 1
#define PROJECTILE_MODEL_ENTITY 2

#define PROJECTILE_MODEL PROJECTILE_MODEL_PS

class CIGameAgent;

using namespace Ogre;

enum ProjectileState
{
	EXPLODED,
	MOVING
};

class Projectile
{
public:
	Projectile();
	virtual ~Projectile();

public:
	void initSystem();

public:
	virtual void update(Real dt);
	virtual void setPosition(const Vector3& pos);
	virtual void initialize(CIGameAgent* initiator, CIGameAgent* target); 
	Real getImpact() const { return mImpact; }
	Real getPenetration() const { return mPenetration; }
	virtual bool isVisible() const;
	void shutdown();

protected:
#if PROJECTILE_MODEL == PROJECTILE_MODEL_ENTITY
	virtual Entity* createEntity(const std::string& name)=0;
#else
	virtual ParticleSystem* createPS(const std::string& name)=0;
#endif
	virtual ParticleSystem* createExplosion(const std::string& name);
	virtual void initProj() { }
	virtual void initExplosion() { }

protected:
	void doExplosion(Real dt);
	void doMove(Real dt);
	virtual void explode();
	virtual void reset();

protected:
#if PROJECTILE_MODEL == PROJECTILE_MODEL_ENTITY
	Entity* mProj;
#else
	ParticleSystem* mProj;
#endif
	ParticleSystem* mExpPS;
	SceneNode* mProjectileNode;
	SceneNode* mExplosionNode;

protected:
	CIGameAgent* mInitiator;
	CIGameAgent* mTarget;
	static size_t mProjectileCount;
	Real mImpact;
	Real mPenetration;
	Real mSpeed;
	bool mVisible;
	ProjectileState mState;

protected:
	Real mExplosionDuration;
	Real mExplosionCounter;

protected:
	std::string mType;
public:
	const std::string& getType() const { return mType; }
};
#endif