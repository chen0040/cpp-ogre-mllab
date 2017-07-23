#ifndef _H_ML_LAB_GUN_H
#define _H_ML_LAB_GUN_H

#include <set>
#include "Projectile.h"

class CIGameAgent;

class Gun
{
public:
	Gun(CIGameAgent* holder);
	virtual ~Gun();

public:
	void shoot(CIGameAgent* target, Real dt);
	void setWeaponImpact(Real impact) { mWeaponImpact=impact; }
	void setWeaponPenetration(Real p) { mWeaponPenetration=p; }
	void setWeaponSpeed(Real s) { mWeaponSpeed=s; }
	void setWeaponChargingRate(Real rate) { mWeaponChargingRate=rate; }
	Real getWeaponImpact() const { return mWeaponImpact; }
	Real getWeaponPenetration() const { return mWeaponPenetration; }
	Real getWeaponSpeed() const { return mWeaponSpeed; }
	Real getWeaponChargingRate() const { return mWeaponChargingRate; }
	bool hasBullets() const { return getBulletCount() > 0; }
	size_t getBulletCount() const { return static_cast<size_t>(mBulletCount); }
	size_t getMaxBulletCount() const { return mMaxBulletCount; }
	void setMaxBulletCount(size_t count) { mMaxBulletCount=count; }
	bool isWithinShootingDistance(const CIGameAgent* enemy) const;
	void setBulletCount(size_t count) { mBulletCount=count; }

	void update(Real dt);
	void clearProjectiles();
	void shutdown();

protected:
	void fire(CIGameAgent* target);
	
public:
	void setWeaponType(const std::string& type) { mType=type; }

protected:
	CIGameAgent* mHolder;
	Real mTimeSinceLastWeaponFired;
	std::set<Projectile*> mProjectiles;
	Real mWeaponImpact;
	Real mWeaponPenetration;
	Real mWeaponSpeed;
	Real mWeaponChargingRate;
	Real mBulletCount;
	size_t mMaxBulletCount;
	std::string mType;
};
#endif