#include "Projectile.h"
#include "../CIAgents/CIGameAgent.h"
#include "../GameEngine/Application.h"
#include "../CIAgents/CIAgentManager.h"
#include <sstream>
#include "Gun.h"

size_t Projectile::mProjectileCount=0;

Projectile::Projectile()
: mInitiator(NULL)
, mTarget(NULL)
, mVisible(true)
, mState(MOVING)
, mExplosionCounter(0)
, mExplosionDuration(0.3)
{
	
}

void Projectile::initSystem()
{
	mProjectileCount++;

	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
	std::ostringstream oss1;
	oss1 << "ProjPS" << mProjectileCount;
#if PROJECTILE_MODEL == PROJECTILE_MODEL_ENTITY
	mProj=this->createEntity(oss1.str());
#else
	mProj=this->createPS(oss1.str());
#endif

	std::ostringstream oss2;
	oss2 << "ProjectileNode" << mProjectileCount;
	mProjectileNode=sm->getRootSceneNode()->createChildSceneNode(oss2.str());
	mProjectileNode->attachObject(mProj);

	initProj();

	std::ostringstream oss3;
	oss3 << "ExpPS" << mProjectileCount;
	mExpPS=createExplosion(oss3.str());

	std::ostringstream oss4;
	oss4 << "ExplosionNode" << mProjectileCount;
	mExplosionNode=sm->getRootSceneNode()->createChildSceneNode(oss4.str());
	mExplosionNode->attachObject(mExpPS);

	initExplosion();
}

ParticleSystem* Projectile::createExplosion(const std::string& name)
{
	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
	return sm->createParticleSystem(name, "chen0040/Smoke");
}

Projectile::~Projectile()
{
	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
	mProjectileNode->detachAllObjects();
	mExplosionNode->detachAllObjects();

	sm->getRootSceneNode()->removeAndDestroyChild(mProjectileNode->getName());
	sm->getRootSceneNode()->removeAndDestroyChild(mExplosionNode->getName());

#if PROJECTILE_MODEL == PROJECTILE_MODEL_ENTITY
	sm->destroyEntity(mProj->getName());
#else
	sm->destroyParticleSystem(mProj);
#endif
	sm->destroyParticleSystem(mExpPS);
}

void Projectile::setPosition(const Vector3& pos)
{
	mProjectileNode->setPosition(pos);
}

void Projectile::update(Real dt)
{
	CIAgentManager* cim=CIAgentManager::getSingletonPtr();
	if(mTarget == NULL || (!cim->exists(mTarget)) || !mTarget->isAlive() || mTarget->getDistance(mInitiator) > mInitiator->getSenseRange())
	{
		mVisible=false;
		mExplosionNode->setVisible(false);
		mProjectileNode->setVisible(false);
		return;
	}

	mExplosionNode->setPosition(mTarget->getWeaponCenter());

	switch(mState)
	{
	case EXPLODED:
		doExplosion(dt);
		break;
	case MOVING:
		doMove(dt);
		break;
	default:
		break;
	}
}

void Projectile::doExplosion(Real dt)
{
	mExplosionCounter+=dt;
	if(mExplosionCounter > mExplosionDuration)
	{
		mVisible=false;
		mExplosionNode->setVisible(false);
	}
}

void Projectile::doMove(Real dt)
{
	const Vector3& pos1=mProjectileNode->getPosition();
	const Vector3& pos2=mTarget->getWeaponCenter();
	Real r=mTarget->getRadius();

	Vector3 direction=pos2-pos1;
	Real distance=direction.normalise();

	if(distance < r)
	{
		explode();
		doExplosion(dt);
		Real hit=mTarget->getHit(this);
		Real score=hit;
		mInitiator->topupScore(score);
	}
	else
	{
		//only required for projectile object that need to be oriented
		/*
		Vector3 src=mProjectileNode->getOrientation() * Vector3::UNIT_X;
		if(1.0 + src.dotProduct(direction) < 0.001f)
		{
			mProjectileNode->yaw(Degree(180));
		}
		else
		{
			mProjectileNode->rotate(src.getRotationTo(direction));
		}
		*/

		mProjectileNode->translate(direction * (dt * mSpeed));
	}
}

void Projectile::shutdown()
{
	mVisible=false;
	mProjectileNode->setVisible(false);
	mExplosionNode->setVisible(false);
}

bool Projectile::isVisible() const
{
	return mVisible;
}

void Projectile::explode()
{
	mExplosionCounter=0;
	mProjectileNode->setVisible(false);
	mExplosionNode->setVisible(true);
	mState=EXPLODED;
}

void Projectile::reset()
{
	mVisible=true;
	mProjectileNode->setPosition(mInitiator->getWeaponCenter());
	mProjectileNode->setVisible(true);
	mExplosionNode->setVisible(false);
	mState=MOVING;
}

void Projectile::initialize(CIGameAgent *initiator, CIGameAgent* target)
{
	mInitiator=initiator; 
	mTarget=target;
	Gun* g=mInitiator->getGun();
	mImpact=g->getWeaponImpact();
	mPenetration=g->getWeaponPenetration();
	mSpeed=g->getWeaponSpeed();
	reset();
}