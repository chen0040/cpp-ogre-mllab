#include "Gun.h"
#include "WeaponManager.h"
#include "../CIAgents/CIGameAgent.h"
#include "../SoundEngine/SoundManager.h"
#include "../CIAgents/CIAgentManager.h"

Gun::Gun(CIGameAgent *holder)
: mHolder(holder)
, mWeaponImpact(20)
, mWeaponPenetration(0.1)
, mWeaponSpeed(200)
, mTimeSinceLastWeaponFired(0)
, mMaxBulletCount(20)
, mWeaponChargingRate(0.2) //add a bullet per second
, mType("laser_pulse")
{
	mBulletCount=mMaxBulletCount;
}

Gun::~Gun()
{
	clearProjectiles();
}

bool Gun::isWithinShootingDistance(const CIGameAgent* target) const
{
	return mHolder->getDistance(target) < mHolder->getSenseRange();
}

void Gun::shoot(CIGameAgent *target, Real dt)
{
	if(mBulletCount <= 0)
	{
		return;
	}

	CIAgentManager* cim=CIAgentManager::getSingletonPtr();
	mTimeSinceLastWeaponFired+=dt;
	if(mTimeSinceLastWeaponFired > mHolder->getFireInterval() && target != NULL)
	{
		if(cim->exists(target) && (!target->isDead()) && isWithinShootingDistance(target))
		{
			fire(target);
		}
		mTimeSinceLastWeaponFired=0;
	}
}

void Gun::fire(CIGameAgent *target)
{
	SoundManager::getSingletonPtr()->play("laser_pulse");
	Projectile* p=WeaponManager::getSingletonPtr()->popProjectile(mType);
	p->initialize(mHolder, target);
	mProjectiles.insert(p);
	mBulletCount-=1;
}

void Gun::shutdown()
{
	std::set<Projectile*>::iterator iter=mProjectiles.begin();
	std::set<Projectile*>::iterator iter_end=mProjectiles.end();
	for(; iter != iter_end; ++iter)
	{
		(*iter)->shutdown();
	}
}

void Gun::clearProjectiles()
{
	Projectile* p=NULL;
	WeaponManager* wm=WeaponManager::getSingletonPtr();
	std::set<Projectile*>::iterator iter=mProjectiles.begin();
	std::set<Projectile*>::iterator iter_end=mProjectiles.end();
	for(; iter != iter_end; ++iter)
	{
		p=*iter;
		wm->pushProjectile(*iter);
	}
	mProjectiles.clear();
}

void Gun::update(Real dt)
{
	WeaponManager* wm=WeaponManager::getSingletonPtr();
	std::set<Projectile*>::iterator iter=mProjectiles.begin(); 
	Projectile* p=NULL;
	while(iter != mProjectiles.end())
	{
		p=(*iter);
		p->update(dt);
		if(!p->isVisible())
		{
			wm->pushProjectile(p);
			iter=mProjectiles.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	//charging up the weapon
	mBulletCount+=(mWeaponChargingRate * dt);
	if(mBulletCount > mMaxBulletCount)
	{
		mBulletCount=mMaxBulletCount;
	}
}