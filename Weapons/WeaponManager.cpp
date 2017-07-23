#include "WeaponManager.h"
#include "../Terrain/TerrainInfoManager.h"
#include "../SceneAssets/PGManager.h"
#include "../GameEngine/Application.h"
#include "LaserPulse.h"
#include "FireShot.h"
#include "Bomb.h"
#include <Ogre.h>

WeaponManager* WeaponManager::mSingleton=NULL;

WeaponManager::WeaponManager()
: mProjectileCount(10)
, mStarGateOpenDuration(1)
, mDeathSiteDuration(0.5)
, mStarGateOpenCounter(0)
, mDeathSiteCounter(0)
, mBlastImpactTextureId(5)
{
	if(mSingleton==NULL)
	{
		mSingleton=this;
	}
	else
	{
		throw new Ogre::Exception(42, "multiple instances not allowed!", "WeaponManager::WeaponManager()");
	}

	mProjectiles["laser_pulse"]=std::stack<Projectile*>();
	mProjectiles["fire_shot"]=std::stack<Projectile*>();

	createStarGate();
}

void WeaponManager::createStarGate()
{
	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();

	ParticleSystem* StarGatePS11=sm->createParticleSystem("WeaponManager/DeathBlast", "chen0040/DeathBlast");
	mDeathBlast=sm->getRootSceneNode()->createChildSceneNode("WeaponManager/DeathBlastNode");
	mDeathBlast->attachObject(StarGatePS11);
	mDeathBlast->setVisible(false);

	ParticleSystem* StarGatePS12=sm->createParticleSystem("WeaponManager/StarGatePS12", "Examples/GreenyNimbus"); 
	//ParticleSystem* StarGatePS21=sm->createParticleSystem("WeaponManager/StarGatePS21", "chen0040/DeathBlast");
	ParticleSystem* StarGatePS22=sm->createParticleSystem("WeaponManager/StarGatePS22", "Examples/GreenyNimbus"); 

	mStarGate1=sm->getRootSceneNode()->createChildSceneNode("WeaponManager/StarGateNode1");
	//mStarGate1->attachObject(StarGatePS1);
	mStarGate1->attachObject(StarGatePS12);
	mStarGate1->setVisible(false);

	
	mStarGate2=sm->getRootSceneNode()->createChildSceneNode("WeaponManager/StarGateNode2");
	//mStarGate2->attachObject(StarGatePS1);
	mStarGate2->attachObject(StarGatePS22);
	mStarGate2->setVisible(false);
}

WeaponManager::~WeaponManager()
{
	Projectile* p=NULL;
	std::map<std::string, std::stack<Projectile*> >::iterator iter=mProjectiles.begin();
	std::map<std::string, std::stack<Projectile*> >::iterator iter_end=mProjectiles.end();
	for(; iter != iter_end; ++iter)
	{

		while(!(iter->second).empty())
		{
			p=(iter->second).top();
			delete p;
			(iter->second).pop();
		}
	}

	mStarGate1->detachAllObjects();
	mStarGate2->detachAllObjects();
	mDeathBlast->detachAllObjects();
}

Projectile* WeaponManager::popProjectile(const std::string& type)
{
	Projectile* p=NULL;
	if(mProjectiles[type].empty())
	{
		mProjectileCount++;
		if(type.compare("laser_pulse")==0)
		{
			p=new LaserPulse();
		}
		else if(type.compare("fire_shot")==0)
		{
			p=new FireShot();
		}
		else if(type.compare("bomb")==0)
		{
			p=new Bomb();
		}
		else 
		{
			p=new FireShot();
		}
		p->initSystem();
	}
	else
	{
		p=mProjectiles[type].top();
		mProjectiles[type].pop();
	}
	return p;
}

void WeaponManager::createDeathSite(const Vector3& deathSite, const Real& landImpact)
{
	mDeathSites.push(deathSite); 
	
	Real impact=landImpact;
	if(landImpact < 0)
	{
		impact=0.0001f;
	}
	impact=landImpact > 0.1f ? 0.1f : landImpact;
	if(TerrainInfoManager::getSingletonPtr()->isTerrainLoaded())
	{
		TerrainInfoManager::getSingletonPtr()->deform(deathSite.x, deathSite.z, -impact * 0.4);
		TerrainInfoManager::getSingletonPtr()->paint(deathSite.x, deathSite.z, impact * 5.0f, mBlastImpactTextureId);
	}
	PGManager* pgm=PGManager::getSingletonPtr();
	pgm->unloadTree1(deathSite, impact * 300.0f);
	pgm->unloadBush(deathSite, impact * 300.0f);
}

void WeaponManager::pushProjectile(Projectile *p)
{
	p->shutdown();
	mProjectiles[p->getType()].push(p);
}

Vector3 WeaponManager::openStarGate(const Vector3& start)
{
	mStarGateOpenCounter=0;
	
	mStarGate1->setPosition(start);
	mStarGate1->setVisible(true);
	
	TerrainInfoManager* tim=TerrainInfoManager::getSingletonPtr();
	Real x=tim->getCenterX()+Ogre::Math::RangeRandom(-50, 50);
	Real z=tim->getCenterZ()+Ogre::Math::RangeRandom(-50, 50);
	
	Vector3 end(x, tim->getHeight(x, z), z);

	mStarGate2->setPosition(end);
	mStarGate2->setVisible(true);

	return end;
}

void WeaponManager::closeStarGate()
{
	mStarGate1->setVisible(false);
	mStarGate2->setVisible(false);
}

void WeaponManager::closeDeathBlast()
{
	mDeathBlast->setPosition(Vector3(-1500, -1000, 0));
	mDeathBlast->setVisible(false);
}

void WeaponManager::monitorStarGate(Real dt)
{
	mStarGateOpenCounter+=dt;
	if(mStarGateOpenCounter > mStarGateOpenDuration)
	{
		closeStarGate();
		mStarGateOpenCounter=0;
	}
	mDeathSiteCounter+=dt;
	if(mDeathSiteCounter > mDeathSiteDuration)
	{
		if(mDeathSites.empty())
		{
			closeDeathBlast();
		}
		else
		{
			Vector3 deathSite=mDeathSites.front();
			
			mDeathSites.pop();
			mDeathBlast->setPosition(deathSite);
			mDeathBlast->setVisible(true);
		}
		
		mDeathSiteCounter=0;
	}
}