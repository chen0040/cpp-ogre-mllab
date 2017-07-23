#ifndef _H_ML_LAB_WEAPON_MANAGER_H
#define _H_ML_LAB_WEAPON_MANAGER_H

#include <stack>
#include <map>
#include "Projectile.h"
#include <queue>
#include <CEGUI/CEGUI.h>

class WeaponManager
{
public:
	WeaponManager();
	virtual ~WeaponManager();

private:
	WeaponManager(const WeaponManager& rhs) { }
	WeaponManager operator=(const WeaponManager& rhs) { return *this; }

public:
	static WeaponManager* getSingletonPtr() { return mSingleton; }
	static WeaponManager& getSingleton() { return *mSingleton; }

public:
	Projectile* popProjectile(const std::string& type);
	void pushProjectile(Projectile* p);

protected:
	std::map<std::string, std::stack<Projectile*> > mProjectiles;
	int mProjectileCount;

public:
	Vector3 openStarGate(const Vector3& start);
	void closeStarGate();
	void closeDeathBlast();
	void monitorStarGate(Real dt);
protected:
	void createStarGate();

protected:
	static WeaponManager* mSingleton;
	SceneNode* mStarGate1;
	SceneNode* mStarGate2;
	SceneNode* mDeathBlast;
	Real mStarGateOpenDuration;
	Real mStarGateOpenCounter;

protected:
	std::queue<Vector3> mDeathSites;
	Real mDeathSiteCounter;
	Real mDeathSiteDuration;
	CEGUI::uint mBlastImpactTextureId;
public:
	void createDeathSite(const Vector3& site, const Real& landImpact);
	void setBlastImpactTextureId(CEGUI::uint id) { mBlastImpactTextureId=id; }
	CEGUI::uint getBlastImpactTextureId() const { return mBlastImpactTextureId; }
};
#endif