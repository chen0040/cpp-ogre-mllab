#ifndef _H_ML_LAB_CI_GAME_AGENT_H
#define _H_ML_LAB_CI_GAME_AGENT_H

#include <vector>
#include <set>
#include <map>
#include <queue>
#include "CIAgent.h"
#include "../ScriptEngine/Scriptlet.h"
#include "../Weapons/Gun.h"
#include "CIGameAgentActionState.h"
#include "CIGameAgentTargetChoice.h"

typedef std::vector<CIGameAgent*> CIGameAgentVector;

class CIGameAgent : public CIAgent
{
public:
	typedef std::set<CIGameAgent*> CIGameAgent::Set;
	typedef std::set<CIGameAgent*>::iterator CIGameAgent::SetIterator;

public:
	CIGameAgent(const Vector3& pos, const std::string& agentName);
	CIGameAgent(const Vector3& pos, const std::string& agentName, const std::string& scriptId);
	CIGameAgent(const Vector3& pos, const std::string& agentName, const std::string& scriptId, const ColourValue& c);
	virtual ~CIGameAgent();

public:
	virtual bool run(const std::string& cmd, Ogre::Real dt=0);
	virtual void generateCode(const std::string& destinationFolderPath, const std::string& lang);
	virtual std::string toString() const;

public:
	virtual void deactivate();
	virtual void activate(bool showPS=false);

public:
	void topupScore(Real s) { mScore+=s; }
	Real getScore() const { return mScore; }

public:
	virtual void changeModel(const std::string& name);

public:
	bool isUserBot() const;

protected:
	Real mSenseDistance;
	Real mArmor;
	Real mScore;
	Real mFiringDelay;

public:
	virtual void setLife(int life);
	virtual bool isAttacking(const CIGameAgent* agent) const;
	virtual bool isAttackable(const CIGameAgent* agent) const;

public:
	void setSenseRange(Real distance) { mSenseDistance=distance; }
	Real getSenseRange() const { return mSenseDistance; }
	void setArmor(Real armor) { mArmor=armor; }
	Real getArmor() const { return mArmor; }
	void setFiringDelay(Real delay) { mFiringDelay=delay; }
	Real getFiringDelay() const { return mFiringDelay; }
	Gun* getGun() const { return mGun; }
	bool hasValidScript() const;
	const std::string& getScriptClassPath() const;

public:
	size_t isTargetAttackable() const;
	float getTargetRelativeDistance() const;
	float getTargetRelativeLife() const;

public:
	virtual void hide();
	virtual void show();

public:
	static std::string stateToString(CIGameAgentActionState state);
	static void createOrRetrieveAuraColor(const Ogre::String& matName, Real Red, Real Green, Real Blue);

public:
	virtual void think();
	virtual void train();
	virtual void uploadConfig();

public:
	virtual void addEnemy(const std::string& enemyTag);
	virtual bool isEnemy(CIGameAgent* agent) const;
	const std::string& getScriptId() const;

	Real getDistance(const CIGameAgent* const agent) const;
	Real getHit(const Projectile* const p);
	Real getFireInterval() const;

public:
	void initialize();
	bool isInitialized() const { return mInitialized; }

protected:
	void createAura();
	void createAura(const ColourValue& c);
	void createField();
	void confrontEnemy(Real dt);
	void evadeEnemy(Real dt);
	void resolveCollision();
	void resolveCollision(CIGameAgent* agent);
public:
	virtual void shoot(Real dt);
	virtual void walk(Real dt);
	virtual void die(Real dt);
	virtual void wander(Real dt);

public:
	void registerState(CIGameAgentActionState state) { mRegisteredAction=state; }
	void registerAttack() { registerState(ATTACK); }
	void registerApproach() { registerState(APPROACH); }
	void registerEscape() { registerState(ESCAPE); }
	void registerWander() { registerState(WANDER); }
	void registerIdle() { registerState(IDLE); }
	void registerSlump() { registerState(SLUMP); }
	void registerWalk() { registerState(WALK); }
	void registerDie() { registerState(DIE); }
	void registerShoot() { registerState(SHOOT); }
	void doNothing() { }

public:
	const CIGameAgentActionState getRegisteredAction() const { return mRegisteredAction; }
	const CIGameAgentTargetChoice getRegisteredTargetChoice() const { return mRegisteredEnemyChoice; }
	void registerAction(CIGameAgentActionState action) { mRegisteredAction=action; }
	void registerTargetType(CIGameAgentTargetChoice choice) { mRegisteredEnemyChoice=choice; }

protected:
	void updateEnvironment();
	void update(Real dt);
	void updateTarget();

public:
	size_t getSightedAllyCount() const { return mSightedAllyVector.size(); }
	size_t getSightedTargetCount() const { return mSightedTargetVector.size(); }
	size_t getSightedAttackerCount() const;
	CIGameAgent* getSightedAlly(size_t index) const { return mSightedAllyVector[index]; }
	CIGameAgent* getSightedTarget(size_t index) const { return mSightedTargetVector[index]; }

protected:
	CIGameAgent* mCandidateTarget_Closest;
	CIGameAgent* mCandidateTarget_Strongest;
	CIGameAgent* mCandidateTarget_Weakest;
	CIGameAgent* mCandidateTarget_Attacker;
	CIGameAgent* mCandidateTarget_Random;

public:
	CIGameAgent* getCandidateTarget_Closest() { return mCandidateTarget_Closest; }
	CIGameAgent* getCandidateTarget_Strongest() { return mCandidateTarget_Strongest; }
	CIGameAgent* getCandidateTarget_Weakest() { return mCandidateTarget_Weakest; }
	CIGameAgent* getCandidateTarget_Random() { return mCandidateTarget_Random; }
	CIGameAgent* getCandidateTarget_Attacker() { return mCandidateTarget_Attacker; }

public:
	void registerTargetType_Closest() { registerTargetType(CLOSEST_ENEMY); }
	void registerTargetType_Weakest() { registerTargetType(WEAKEST_ENEMY); }
	void registerTargetType_Strongest() { registerTargetType(STRONGEST_ENEMY); }
	void registerTargetType_Random() { registerTargetType(RANDOM_ENEMY); }
	void registerTargetType_Attacker() { registerTargetType(ATTACKER_ENEMY); }

protected:
	std::string mScriptId;
	std::set<std::string> mEnemyScriptIds;
	ManualObject* mAura;
	ManualObject* mField;
	SceneNode* mAuraNode;
	SceneNode* mFieldNode;

public:
	Vector3 getWeaponCenter();

protected:
	Gun* mGun; 
	bool mInitialized;
	CIGameAgent* mCurrentTarget;
	Ogre::String mMatName;
protected:
	CIGameAgentVector mSightedAllyVector;
	CIGameAgentVector mSightedTargetVector;

protected:
	CIGameAgentTargetChoice mRegisteredEnemyChoice;
	CIGameAgentActionState mRegisteredAction;

public:
	CIGameAgent* getCurrentTarget() const { return mCurrentTarget; }
};
#endif