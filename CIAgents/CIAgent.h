#ifndef _H_MLLAB_CI_AGENT_H
#define _H_MLLAB_CI_AGENT_H

#include <Ogre.h>
#include <CEGUI/CEGUI.h>
#include "../OgreUtil/MovableText.h"

using namespace Ogre;

class CIAgent
{
public:
	typedef std::set<CIAgent*> Set;
	typedef std::set<CIAgent*>::iterator SetIterator;
	typedef std::set<CIAgent*>::const_iterator ConstSetIterator;

public:
	CIAgent(const Vector3& pos, const std::string& agentName);
	virtual ~CIAgent();

public:
	SceneNode* getEntityNode() { return mEntityNode; }
	Entity* getEntity() { return mEntity; }
	const String& getAgentName() const { return mAgentName; }

protected:
	virtual bool setAnimation(const String& animationName);
	AnimationState* mAnimationState;
	std::string mModelName;
	String mAgentName;

public:
	const std::string& getModelName() const { return mModelName; }
	virtual void setPosition(const Vector3& pos);
	virtual Vector3 getPosition() const { return mEntityNode->getPosition(); }
	//virtual Vector3 getCenter() const;
	virtual Real getRadius() const;
	virtual bool run(const std::string& cmd, Real dt=0);
	virtual void generateCode(const std::string& destinationFolderPath, const std::string& lang, const std::string& codeName);
	virtual void deactivate();
	virtual void activate(bool showPS=false);
	virtual bool isActive() const;
	virtual std::string toString() const;
	Real getHeight() const;

public:
	virtual void idle(Real dt);
	virtual void shoot(Real dt);
	virtual void slump(Real dt);
	virtual void walk(Real dt);
	virtual void turnLeft(Real dt);
	virtual void turnRight(Real dt);
	virtual void die(Real dt);
	virtual void changeModel(const std::string& name);

public:
	virtual void setLife(int life) { mLife=life; }
	void setMaxLife(int life) { mMaxLife=life; }
	int getLife() const { return mLife; }
	int getMaxLife() const { return mMaxLife; }
	const std::string& getTag() const { return mTag; }
	void setTag(const std::string& tag) { mTag=tag; }
	void setRotationSpeed(Real rate) { mRotationSpeed=rate; }
	void setWalkSpeed(Real rate) { mWalkSpeed=rate; }
	Real getWalkSpeed() const { return mWalkSpeed; }

public:
	bool isAlive() const { return mLife >= 0; }
	bool isDying() const { return mLife==0; }
	bool isDead() const { return mLife < 0; } 

public:
	virtual void hide();
	virtual void show();
	virtual bool isVisible() const { return mVisible; } 

public:
	const std::string& getAgentType() const { return mAgentType; }

protected:
	Entity* mEntity;
	SceneNode* mEntityNode;
	Real mRotationSpeed;
	Real mWalkSpeed;
	int mLife;
	int mMaxLife;
	std::string mTag;
	Real mRadius;
	std::string mAgentType;
	bool mVisible;
	bool mActivated;
	Real mHeight;
	bool mFloatable;

public:
	void createText(const std::string& caption);

protected:
	MovableText* mText;
	SceneNode* mTextNode;
};
#endif