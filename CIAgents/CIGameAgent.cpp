#include "CIGameAgent.h"
#include "../CIType/CIManager.h"
#include "../Widgets/GUIManager.h"
#include "../GameEngine/Application.h"
#include "../ScriptEngine/ScriptManager.h"
#include "../OSEnvironment/OSEnvironment.h"
#include "../Terrain/TerrainInfoManager.h"
#include "../Weapons/WeaponManager.h"
#include "CIAgentManager.h"
#include "ModelManager.h"

CIGameAgent::CIGameAgent(const Ogre::Vector3& pos, const std::string& agentName)
: CIAgent(pos, agentName)
, mCurrentTarget(NULL)
, mScore(0)
, mSenseDistance(100)
, mArmor(10)
, mFiringDelay(1)
, mInitialized(false)
, mRegisteredAction(IDLE)
, mRegisteredEnemyChoice(DEFAULT_ENEMY)
, mCandidateTarget_Closest(NULL)
, mCandidateTarget_Strongest(NULL)
, mCandidateTarget_Weakest(NULL)
, mCandidateTarget_Random(NULL)
, mCandidateTarget_Attacker(NULL)
, mFieldNode(NULL)
, mField(NULL)
, mAuraNode(NULL)
, mAura(NULL)
, mScriptId("")
{
	mAgentType="CIGameAgent";
	mGun=new Gun(this);
	mGun->setWeaponType(ModelManager::getSingletonPtr()->getWeaponName(mModelName));

	//createText(ScriptManager::getSingletonPtr()->getNickname(scriptId));
}

CIGameAgent::CIGameAgent(const Ogre::Vector3& pos, const std::string& agentName, const std::string& scriptId)
: CIAgent(pos, agentName)
, mCurrentTarget(NULL)
, mScore(0)
, mSenseDistance(100)
, mArmor(10)
, mFiringDelay(1)
, mInitialized(false)
, mRegisteredAction(IDLE)
, mRegisteredEnemyChoice(DEFAULT_ENEMY)
, mCandidateTarget_Closest(NULL)
, mCandidateTarget_Strongest(NULL)
, mCandidateTarget_Weakest(NULL)
, mCandidateTarget_Random(NULL)
, mCandidateTarget_Attacker(NULL)
, mFieldNode(NULL)
, mField(NULL)
, mAuraNode(NULL)
, mAura(NULL)
, mScriptId(scriptId)
{
	mAgentType="CIGameAgent";
	mMatName=OSEnvironment::append(mScriptId, "Material").c_str();
	mGun=new Gun(this);
	mGun->setWeaponType(ModelManager::getSingletonPtr()->getWeaponName(mModelName));

	createAura();
	createText(ScriptManager::getSingletonPtr()->getNickname(scriptId));

	if(this->isUserBot())
	{
		if(mInitialized==false)
		{
			initialize();
		}
	}
}

CIGameAgent::CIGameAgent(const Ogre::Vector3& pos, const std::string& agentName, const std::string& scriptId, const ColourValue& c)
: CIAgent(pos, agentName)
, mCurrentTarget(NULL)
, mScore(0)
, mSenseDistance(100)
, mArmor(10)
, mFiringDelay(1)
, mInitialized(false)
, mRegisteredAction(IDLE)
, mRegisteredEnemyChoice(DEFAULT_ENEMY)
, mCandidateTarget_Closest(NULL)
, mCandidateTarget_Strongest(NULL)
, mCandidateTarget_Weakest(NULL)
, mCandidateTarget_Random(NULL)
, mCandidateTarget_Attacker(NULL)
, mFieldNode(NULL)
, mField(NULL)
, mAuraNode(NULL)
, mAura(NULL)
, mScriptId(scriptId)
{
	mAgentType="CIGameAgent";
	mMatName=OSEnvironment::append(mScriptId, "Material").c_str();
	mGun=new Gun(this);
	createAura(c);

	createText(ScriptManager::getSingletonPtr()->getNickname(scriptId));

	if(this->isUserBot())
	{
		if(mInitialized==false)
		{
			initialize();
		}
	}
}

void CIGameAgent::changeModel(const std::string& name)
{
	if(mModelName.compare(name)==0)
	{
		return;
	}

	if(mAuraNode != NULL)
	{
		mAuraNode->translate(0, -this->getHeight(), 0);
	}
	if(mFieldNode != NULL)
	{
		mFieldNode->translate(0, -this->getHeight() / 2, 0);
	}

	CIAgent::changeModel(name);

	if(mAuraNode != NULL)
	{
		mAuraNode->translate(0, this->getHeight(), 0);
	}

	float scale=1.0f / this->mEntityNode->getScale().x;
	if(mFieldNode != NULL)
	{
		mFieldNode->setScale(Vector3(scale, scale, scale));
		mFieldNode->translate(0, this->getHeight() / 2, 0);
	}
	if(mAuraNode != NULL)
	{
		mAuraNode->setScale(Vector3(scale, scale, scale));
	}
	mGun->setWeaponType(ModelManager::getSingletonPtr()->getWeaponName(mModelName));
}

Vector3 CIGameAgent::getWeaponCenter()
{
	return getPosition()+ModelManager::getSingletonPtr()->getWeaponOffset(mModelName); 
}

CIGameAgent::~CIGameAgent()
{
	if(mGun != NULL)
	{
		delete mGun;
		mGun=NULL;
	}

	if(mAura != NULL)
	{
		Application::getSingletonPtr()->getSceneMgr()->destroyManualObject(this->getAgentName() + "Aura");
		mAura=NULL;
	}

	if(mField != NULL)
	{
		Application::getSingletonPtr()->getSceneMgr()->destroyManualObject(this->getAgentName() + "Field");
		mField=NULL;
	}
}

void CIGameAgent::createOrRetrieveAuraColor(const Ogre::String& matName, Real Red, Real Green, Real Blue)
{
	MaterialManager* mm= MaterialManager::getSingletonPtr();
	Ogre::ResourceManager::ResourceCreateOrRetrieveResult result = mm->createOrRetrieve(matName, ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	Ogre::MaterialPtr mp = result.first;
	if ((bool)result.second) {
		//if first time created, do initialization
		mp->setReceiveShadows(false); 
		mp->getTechnique(0)->setLightingEnabled(true); 	
    }
	
	mp->getTechnique(0)->getPass(0)->setDiffuse(Red,Green, Blue,0); 
	mp->getTechnique(0)->getPass(0)->setAmbient(Red, Green, Blue); 
	mp->getTechnique(0)->getPass(0)->setSelfIllumination(Red, Green, Blue); 
}

void CIGameAgent::createField()
{
	Scriptlet* scriptlet=ScriptManager::getSingletonPtr()->getScriptlet(this->mScriptId);
	Real r=scriptlet->getRed() / 255.0f;
	Real g=scriptlet->getGreen() / 255.0f;
	Real b=scriptlet->getBlue() / 255.0f;;
	CIGameAgent::createOrRetrieveAuraColor(mMatName, r, g, b);

	mField=Application::getSingletonPtr()->getSceneMgr()->createManualObject(this->getAgentName() + "Field");

	float radius=this->getSenseRange();
     const float thickness = 2; // Of course this must be less than the radius value.
     const float accuracy = 35;
	 const float height=2;

    mField->begin(mMatName, RenderOperation::OT_TRIANGLE_LIST);

    unsigned point_index = 0;
	static float deltaTheta=Math::PI / accuracy;
    for(float theta = 0; theta <= 2 * Math::PI; theta += deltaTheta) 
	{
        mField->position(radius * cos(theta),
                         0,
                         radius * sin(theta));
        mField->position(radius * cos(theta - Math::PI / accuracy),
                         0,
                         radius * sin(theta - Math::PI / accuracy));
        mField->position((radius - thickness) * cos(theta - Math::PI / accuracy),
                         0,
                         (radius - thickness) * sin(theta - Math::PI / accuracy));
        mField->position((radius - thickness) * cos(theta),
                         0,
                         (radius - thickness) * sin(theta));

		mField->position(radius * cos(theta),
                         height,
                         radius * sin(theta));
        mField->position(radius * cos(theta - Math::PI / accuracy),
                         height,
                         radius * sin(theta - Math::PI / accuracy));
        mField->position((radius - thickness) * cos(theta - Math::PI / accuracy),
                         height,
                         (radius - thickness) * sin(theta - Math::PI / accuracy));
        mField->position((radius - thickness) * cos(theta),
                         height,
                         (radius - thickness) * sin(theta));
        // Join the 4 vertices created above to form a quad.
        mField->quad(point_index, point_index + 1, point_index + 2, point_index + 3);
		mField->quad(point_index+4, point_index + 5, point_index + 6, point_index + 7);
		mField->quad(point_index, point_index+1, point_index+5, point_index+4);
		mField->quad(point_index+2, point_index+3, point_index+7, point_index+6);
        point_index += 8;
    }

    mField->end();
    
	mFieldNode=this->mEntityNode->createChildSceneNode(this->getAgentName() + "FieldNode");

	float scale=1.0f / this->mEntityNode->getScale().x;
	mFieldNode->setScale(Vector3(scale, scale, scale));
	mFieldNode->translate(0, this->getHeight() / 2, 0);
	mFieldNode->attachObject(mField);
}

void CIGameAgent::createAura()
{
	Scriptlet* scriptlet=ScriptManager::getSingletonPtr()->getScriptlet(this->mScriptId);
	Real r=scriptlet->getRed() / 255.0f;
	Real g=scriptlet->getGreen() / 255.0f;
	Real b=scriptlet->getBlue() / 255.0f;
	CIGameAgent::createOrRetrieveAuraColor(mMatName, r, g, b);

	mAura=Application::getSingletonPtr()->getSceneMgr()->createManualObject(this->getAgentName() + "Aura");

	float radius = 6.0f ; //this->getRadius() * 0.5f;
     const float thickness = 2.0f; // Of course this must be less than the radius value.
     const float accuracy = 35;

    mAura->begin(mMatName, RenderOperation::OT_TRIANGLE_LIST);

    unsigned point_index = 0;
	static float deltaTheta=Math::PI / accuracy;
    for(float theta = 0; theta <= 2 * Math::PI; theta += deltaTheta) 
	{
        mAura->position(radius * cos(theta),
                         0,
                         radius * sin(theta));
        mAura->position(radius * cos(theta - Math::PI / accuracy),
                         0,
                         radius * sin(theta - Math::PI / accuracy));
        mAura->position((radius - thickness) * cos(theta - Math::PI / accuracy),
                         0,
                         (radius - thickness) * sin(theta - Math::PI / accuracy));
        mAura->position((radius - thickness) * cos(theta),
                         0,
                         (radius - thickness) * sin(theta));

		mAura->position(radius * cos(theta),
                         3,
                         radius * sin(theta));
        mAura->position(radius * cos(theta - Math::PI / accuracy),
                         3,
                         radius * sin(theta - Math::PI / accuracy));
        mAura->position((radius - thickness) * cos(theta - Math::PI / accuracy),
                         3,
                         (radius - thickness) * sin(theta - Math::PI / accuracy));
        mAura->position((radius - thickness) * cos(theta),
                         3,
                         (radius - thickness) * sin(theta));
        // Join the 4 vertices created above to form a quad.
        mAura->quad(point_index, point_index + 1, point_index + 2, point_index + 3);
		mAura->quad(point_index+4, point_index + 5, point_index + 6, point_index + 7);
		mAura->quad(point_index, point_index+1, point_index+5, point_index+4);
		mAura->quad(point_index+2, point_index+3, point_index+7, point_index+6);
        point_index += 8;
    }

    mAura->end();
    
	mAuraNode=this->mEntityNode->createChildSceneNode(this->getAgentName() + "AuronNode");
	float scale=1.0f / this->mEntityNode->getScale().x;
	mAuraNode->setScale(Vector3(scale, scale, scale));
	mAuraNode->translate(0, this->getHeight(), 0);
	mAuraNode->attachObject(mAura);
}

void CIGameAgent::createAura(const ColourValue& c)
{
	Scriptlet* scriptlet=ScriptManager::getSingletonPtr()->getScriptlet(this->mScriptId);
	Real r=scriptlet->getRed() / 255.0f;
	Real g=scriptlet->getGreen() / 255.0f;
	Real b=scriptlet->getBlue() / 255.0f;;
	CIGameAgent::createOrRetrieveAuraColor(mMatName, c.r, c.g, c.b);

	mAura=Application::getSingletonPtr()->getSceneMgr()->createManualObject(this->getAgentName() + "Aura");

	float radius = 6.0f; //this->getRadius();
     const float thickness = 2; // Of course this must be less than the radius value.
     const float accuracy = 35;

    mAura->begin(mMatName, RenderOperation::OT_TRIANGLE_LIST);

    unsigned point_index = 0;
	static float deltaTheta=Math::PI / accuracy;
    for(float theta = 0; theta <= 2 * Math::PI; theta += deltaTheta) 
	{
        mAura->position(radius * cos(theta),
                         0,
                         radius * sin(theta));
        mAura->position(radius * cos(theta - Math::PI / accuracy),
                         0,
                         radius * sin(theta - Math::PI / accuracy));
        mAura->position((radius - thickness) * cos(theta - Math::PI / accuracy),
                         0,
                         (radius - thickness) * sin(theta - Math::PI / accuracy));
        mAura->position((radius - thickness) * cos(theta),
                         0,
                         (radius - thickness) * sin(theta));

		mAura->position(radius * cos(theta),
                         3,
                         radius * sin(theta));
        mAura->position(radius * cos(theta - Math::PI / accuracy),
                         3,
                         radius * sin(theta - Math::PI / accuracy));
        mAura->position((radius - thickness) * cos(theta - Math::PI / accuracy),
                         3,
                         (radius - thickness) * sin(theta - Math::PI / accuracy));
        mAura->position((radius - thickness) * cos(theta),
                         3,
                         (radius - thickness) * sin(theta));
        // Join the 4 vertices created above to form a quad.
        mAura->quad(point_index, point_index + 1, point_index + 2, point_index + 3);
		mAura->quad(point_index+4, point_index + 5, point_index + 6, point_index + 7);
		mAura->quad(point_index, point_index+1, point_index+5, point_index+4);
		mAura->quad(point_index+2, point_index+3, point_index+7, point_index+6);
        point_index += 8;
    }

    mAura->end();
    
	mAuraNode=this->mEntityNode->createChildSceneNode(this->getAgentName() + "AuronNode");	
	float scale=1.0f / this->mEntityNode->getScale().x;
	mAuraNode->setScale(Vector3(scale, scale, scale));
	mAuraNode->translate(0, this->getHeight(), 0);
	mAuraNode->attachObject(mAura);
}

const std::string& CIGameAgent::getScriptClassPath() const
{
	Scriptlet* script=ScriptManager::getSingletonPtr()->getScriptlet(mScriptId);
	return script->getScriptClassPath();
}

bool CIGameAgent::run(const std::string& cmd, Ogre::Real dt)
{
	CIAgentManager* cim=CIAgentManager::getSingletonPtr();
	if(!cim->exists(mCurrentTarget))
	{
		mCurrentTarget=NULL;
	}

	if(CIAgent::run(cmd, dt))
	{
		return true;
	}
	else if(cmd.compare("act: script")==0)
	{
		updateEnvironment();
		think();
		update(dt);
		return true;
	}
	else if(cmd.compare("act: capture")==0)
	{
		updateEnvironment();
		update(dt);
		return true;
	}
	else
	{
		std::ostringstream oss;
		oss << "Failed to interpret command \"" << cmd << "\"";
		throw Ogre::Exception(42, oss.str().c_str(), "CIGameAgent::run(const std::string& cmd, Ogre::Real dt)");
	}

	return false;
}

void CIGameAgent::generateCode(const std::string& destinationFolderPath, const std::string& lang)
{
	
}

bool CIGameAgent::isAttacking(const CIGameAgent* agent) const
{
	if(mCurrentTarget == NULL)
	{
		return false;
	}

	if(mCurrentTarget != agent)
	{
		return false;
	}

	if(mRegisteredAction!=ATTACK)
	{
		return false;
	}

	if(!mGun->hasBullets())
	{
		return false;
	}

	if(mGun->isWithinShootingDistance(agent))
	{
		return true;
	}

	return false;
}

bool CIGameAgent::isAttackable(const CIGameAgent* agent) const
{
	if(agent==NULL)
	{
		return false;
	}

	if(!mGun->hasBullets())
	{
		return false;
	}

	if(mGun->isWithinShootingDistance(agent))
	{
		return true;
	}

	return false;
}

std::string CIGameAgent::toString() const
{
	std::ostringstream oss;
	oss << "ID: " << getAgentName();
	oss << "\nType: Game Agent";
	oss << "\nScript: " << mScriptId;
	oss << "\nSpeed: " << mWalkSpeed;
	oss << "\nTag: " << mTag;
	oss << "\nAction: " << stateToString(mRegisteredAction);
	oss << "\nEnemies: [";
	std::set<std::string>::const_iterator eiter=mEnemyScriptIds.begin();
	std::set<std::string>::const_iterator eiter_end=mEnemyScriptIds.end();
	for(; eiter != eiter_end; ++eiter)
	{
		if(eiter != eiter_end)
		{
			oss << ", ";
		}
		oss << (*eiter);
	}
	oss << "]";
	oss << "\nLife: " << mLife;
	const Vector3& pos= mEntityNode->getPosition();
	oss << "\nPosition: (X: " << pos.x << " Y: " << pos.y << " Z: " << pos.z << ")";

	return oss.str();
}

size_t CIGameAgent::getSightedAttackerCount() const
{
	size_t attacker_count=0;
	size_t sightedTargetCount=mSightedTargetVector.size();
	for(size_t i=0; i != sightedTargetCount; ++i)
	{
		if(getSightedTarget(i)->isAttacking(this))
		{
			attacker_count++;
		}
	}
	return attacker_count;
}

void CIGameAgent::updateTarget()
{
	switch(mRegisteredEnemyChoice)
	{
	case DEFAULT_ENEMY:
		if(mCurrentTarget == NULL || mCurrentTarget->isDead() || mCurrentTarget->isDying())
		{
			mCurrentTarget=mCandidateTarget_Closest;
		}
		break;
	case CLOSEST_ENEMY:
		mCurrentTarget=mCandidateTarget_Closest;
		break;
	case STRONGEST_ENEMY:
		mCurrentTarget=mCandidateTarget_Strongest;
		break;
	case WEAKEST_ENEMY:
		mCurrentTarget=mCandidateTarget_Weakest;
		break;
	case RANDOM_ENEMY:
		mCurrentTarget=mCandidateTarget_Random;
		break;
	case ATTACKER_ENEMY:
		mCurrentTarget=mCandidateTarget_Attacker;
		break;
	default:
		mCurrentTarget=NULL;
		break;
	}
}

void CIGameAgent::shoot(Real dt)
{
	CIAgent::shoot(dt / mFiringDelay);
	mGun->shoot(mCurrentTarget, dt / mFiringDelay);
}

void CIGameAgent::die(Real dt)
{
	CIAgent::die(dt);
	if(mRegisteredAction != DEAD)
	{
		Vector3 pos=getPosition();
		Real vdist=pos.y +1 - TerrainInfoManager::getSingletonPtr()->getHeight(pos.x, pos.z);
		Real landImpact=1.0 / vdist;
		WeaponManager::getSingletonPtr()->createDeathSite(this->getPosition(), landImpact);
		registerState(DEAD);
	}

	mGun->clearProjectiles();
}

void CIGameAgent::setLife(int life)
{
	CIAgent::setLife(life);
	setMaxLife(life);
}

void CIGameAgent::walk(Real dt)
{
	ModelManager* mm=ModelManager::getSingletonPtr();
	Vector3 prev_pos=mEntityNode->getPosition();

	Vector3 direction=mEntityNode->getOrientation() * mm->getRotation(mModelName);
	direction.y=0;
	direction.normalise();
	mEntityNode->translate(direction * (dt * mWalkSpeed));
	const Vector3& pos=mEntityNode->getPosition();
	this->setPosition(pos);

	resolveCollision();

	const Vector3& posCurr=this->getPosition();
	direction=posCurr - prev_pos;
	Real dtReal=direction.length() / mWalkSpeed;

	setAnimation(mm->getAnimationName_Walk(mModelName));
	if(mAnimationState != NULL)
	{
		mAnimationState->addTime(dtReal);	
	}

	Real x=posCurr.x;
	Real z=posCurr.z;
	TerrainInfoManager* tim=TerrainInfoManager::getSingletonPtr();
	Real vacuumWidth=30;
	if(x > tim->getMaxX() || x < tim->getMinX() || z > tim->getMaxZ() || z < tim->getMinZ())
	{
		this->setPosition(WeaponManager::getSingletonPtr()->openStarGate(Vector3(pos.x, TerrainInfoManager::getSingletonPtr()->getHeight(pos.x, pos.z), pos.z))); //teleport to the center;
	}
}

void CIGameAgent::updateEnvironment()
{
	mSightedAllyVector.clear();
	mSightedTargetVector.clear();

	CIAgentManager* cim=CIAgentManager::getSingletonPtr();
	CIAgentManager::CIAgentList& agents=cim->getCIAgents();

	CIGameAgent* agent=NULL;
	Real shortest_distance=10000000000.0f;
	Real shortest_attacker_distance=shortest_distance;
	int min_life=INT_MAX-2;
	int max_life=-1;

	mCandidateTarget_Closest=NULL;
	mCandidateTarget_Strongest=NULL;
	mCandidateTarget_Weakest=NULL;
	mCandidateTarget_Random=NULL;
	mCandidateTarget_Attacker=NULL;
 
	CIAgentManager::CIAgentListIterator giter=agents.begin();
	CIAgentManager::CIAgentListIterator giter_end=agents.end();
	for(; giter != giter_end; ++giter)
	{
		if(!(*giter)->isVisible()) continue;
		agent=static_cast<CIGameAgent*>(*giter);
		if(agent==this) continue;
		if(!agent->isAlive()) continue;

		Real distance=this->getDistance(agent);
		bool isEnemy=this->isEnemy(agent);

		if(distance < mSenseDistance)
		{
			if(isEnemy)
			{
				mSightedTargetVector.push_back(agent);
			}
			else
			{
				mSightedAllyVector.push_back(agent);
			}
		}

		if(isEnemy)
		{
			if(distance < shortest_distance)
			{
				mCandidateTarget_Closest=agent;
				shortest_distance=distance;
			}
			if(agent->isAttacking(this) && distance < shortest_attacker_distance)
			{
				shortest_attacker_distance=distance;
				mCandidateTarget_Attacker=agent;
			}

			int life=agent->getLife();
			if(life < min_life)
			{
				mCandidateTarget_Weakest=agent;
				min_life=life;
			}
			if(life > max_life)
			{
				mCandidateTarget_Strongest=agent;
				max_life=life;
			}
		}
	}

	if(mSightedTargetVector.empty())
	{
		//select a random target from the predefined other candidate targets
		if(mCandidateTarget_Attacker != NULL)
		{
			mCandidateTarget_Random=mCandidateTarget_Attacker;
		}
		else if(mCandidateTarget_Closest != NULL)
		{
			mCandidateTarget_Random=mCandidateTarget_Closest;
		}
		else if(mCandidateTarget_Strongest != NULL)
		{
			mCandidateTarget_Random=mCandidateTarget_Strongest;
		}
		else if(mCandidateTarget_Weakest != NULL)
		{
			mCandidateTarget_Random=mCandidateTarget_Weakest;
		}
	}
	else
	{
		//select strongest and weakest candidate targets within the sighted targets
		size_t sightedTargetCount=mSightedTargetVector.size();
		for(size_t i=0; i != sightedTargetCount; ++i)
		{
			agent=mSightedTargetVector[i];
			int life=agent->getLife();
			if(life < min_life)
			{
				mCandidateTarget_Weakest=agent;
				min_life=life;
			}
			if(life > max_life)
			{
				mCandidateTarget_Strongest=agent;
				max_life=life;
			}
		}

		//select a random target from the sighted targets
		mCandidateTarget_Random=mSightedTargetVector[rand() % mSightedTargetVector.size()];
	}
}

void CIGameAgent::initialize()
{
	using namespace luabind;
	lua_State* L=ScriptManager::getSingletonPtr()->getLuaState();
	object g=globals(L);
	object initializeAgent=g["initializeAgent"];
	
	if(initializeAgent)
	{
		initializeAgent(this);
	}
	else
	{
		ScriptManager::getSingletonPtr()->exception("CIGameAgent::initialize()", mScriptId.c_str());
	}

	mInitialized=true;

	if(this->isUserBot() && mField == NULL)
	{
		createField();
		
		if(isActive())
		{
			mFieldNode->setVisible(true);
			mAuraNode->setVisible(false);
		}
		else
		{
			mFieldNode->setVisible(false);
		}
	}
}

void CIGameAgent::train()
{
	Scriptlet* script=ScriptManager::getSingletonPtr()->getScriptlet(mScriptId);

	if(script==NULL) //not valid script, then die
	{
		return;
	}

	if(mInitialized==false)
	{
		initialize();
	}

	using namespace luabind;
	lua_State* L=ScriptManager::getSingletonPtr()->getLuaState();
	object g=globals(L);
	object processAgent=g["trainAgent"];
	
	try{
		processAgent(this);
	}catch(luabind::error& er)
	{
		std::ostringstream oss;
		oss << "scriptId: " << mScriptId << "\n";
		oss << "error: " << er.what(); 
		throw Ogre::Exception(42, oss.str().c_str(), "CIGameAgent::train()");
	}
}

void CIGameAgent::uploadConfig()
{
	Scriptlet* script=ScriptManager::getSingletonPtr()->getScriptlet(mScriptId);

	if(script==NULL)
	{
		return; 
	}

	if(mInitialized==false)
	{
		initialize();
	}

	using namespace luabind;
	lua_State* L=ScriptManager::getSingletonPtr()->getLuaState();
	object g=globals(L);
	object processAgent=g["uploadAgentConfig"];
	
	try{
		processAgent(this);
	}catch(luabind::error& er)
	{
		std::ostringstream oss;
		oss << "scriptId: " << mScriptId << "\n";
		oss << "error: " << er.what(); 
		throw Ogre::Exception(42, oss.str().c_str(), "CIGameAgent::uploadConfig()");
	}
}

void CIGameAgent::think()
{	
	Scriptlet* script=ScriptManager::getSingletonPtr()->getScriptlet(mScriptId);

	if(script==NULL) //not valid script, then die
	{
		return;
	}

	if(mInitialized==false)
	{
		initialize();
	}

	using namespace luabind;
	lua_State* L=ScriptManager::getSingletonPtr()->getLuaState();
	object g=globals(L);
	object processAgent=g["processAgent"];
	
	try{
		processAgent(this);
	}catch(luabind::error& er)
	{
		std::ostringstream oss;
		oss << "scriptId: " << mScriptId << "\n";
		oss << "error: " << er.what(); 
		throw Ogre::Exception(42, oss.str().c_str(), "CIGameAgent::think()");
	}
}

bool CIGameAgent::isEnemy(CIGameAgent* agent) const
{
	if(agent->isDead() || agent->isDying())
	{
		return false;
	}

	if(mEnemyScriptIds.empty()) // && mScriptId.compare(agent->getScriptId()) != 0)
	{
		return true;
	}
	return mEnemyScriptIds.find(agent->getScriptId()) != mEnemyScriptIds.end();
}

void CIGameAgent::addEnemy(const std::string& enemyScriptId)
{
	mEnemyScriptIds.insert(enemyScriptId);
}

const std::string& CIGameAgent::getScriptId() const
{
	return mScriptId;
}

Real CIGameAgent::getDistance(const CIGameAgent* const agent) const
{
	if(agent==this)
	{
		return 0;
	}
	
	Vector3 pos1=this->getPosition();
	Vector3 pos2=agent->getPosition();
	pos1.y=pos2.y;

	return pos1.distance(pos2);
}

Real CIGameAgent::getHit(const Projectile* const p)
{
	Real armor=this->getArmor();
	Real weapon_impact=p->getImpact();
	Real weapon_penetration=p->getPenetration();
	Real hit=weapon_impact - armor * (1-weapon_penetration);
	mLife-=hit;
	if(mLife < 0) mLife=0;
	this->setArmor(armor * weapon_penetration);

	return hit;
}

Real CIGameAgent::getFireInterval() const
{
	ModelManager* mm=ModelManager::getSingletonPtr();
	std::string shoot=mm->getAnimationName_Shoot(mModelName);
	if(shoot.compare("")==0)
	{
		return 0.5f;
	}
	else
	{
		return mEntity->getAnimationState(shoot.c_str())->getLength();
	}
}

void CIGameAgent::confrontEnemy(Real dt)
{
	if(mCurrentTarget != NULL)
	{
		const Vector3& posTarget=mCurrentTarget->getPosition();
		const Vector3& pos=this->getPosition();
		Vector3 direction=posTarget-pos;
		direction.y=0;
		direction.normalise();
		Vector3 src=this->getEntityNode()->getOrientation() * ModelManager::getSingletonPtr()->getRotation(mModelName);
		if(1.0f + src.dotProduct(direction) < 0.0001f)
		{
			this->getEntityNode()->yaw(Degree(180));
		}
		else
		{
			this->getEntityNode()->rotate(src.getRotationTo(direction));
		}
	}
}

void CIGameAgent::resolveCollision()
{
	/*
	bool check=false;
	if(mAnimationState != NULL)
	{
		if(mAnimationState->getAnimationName().compare("Walk")==0)
		{
			check=true;
		}		
	}
	else
	{
		if(mRegisteredAction==APPROACH || mRegisteredAction==ESCAPE || mRegisteredAction==WALK || mRegisteredAction==WANDER)
		{
			check=true;
		}
	}
	*/

	if(mRegisteredAction==APPROACH || mRegisteredAction==ESCAPE || mRegisteredAction==WALK || mRegisteredAction==WANDER)
	{
		CIGameAgentVector::iterator giter=mSightedTargetVector.begin();
		CIGameAgentVector::iterator giter_end=mSightedTargetVector.end();
		for(; giter != giter_end; ++giter)
		{
			resolveCollision(*giter);
		}
		giter=mSightedAllyVector.begin();
		giter_end=mSightedAllyVector.end();
		for(; giter != giter_end; ++giter)
		{
			resolveCollision(*giter);
		}
	}
}

void CIGameAgent::resolveCollision(CIGameAgent* agent)
{
	if(agent->isDead())
	{
		return;
	}

	Real r1=this->getRadius();
	Real r2=agent->getRadius();
	Real distance=this->getDistance(agent);
	if(distance < (r1+r2))
	{
		Vector3 direction=mEntityNode->getPosition() - agent->getPosition();
		direction.y=0;
		direction.normalise();

		Real required_distance=r1+r2-distance;
		if(required_distance > r2 / 2)
		{
			Vector3 src=mEntityNode->getOrientation() * ModelManager::getSingletonPtr()->getRotation(mModelName);
			if(1.0f + src.dotProduct(direction) < 0.0001f)
			{
				mEntityNode->yaw(Degree(180));
			}
			else
			{
				mEntityNode->rotate(src.getRotationTo(direction));
			}
		}
		
		mEntityNode->translate(direction * required_distance);
	}
}

void CIGameAgent::evadeEnemy(Real dt)
{
	if(mCurrentTarget != NULL)
	{
		const Vector3& posTarget=mCurrentTarget->getPosition();
		const Vector3& pos=this->getPosition();
		Vector3 direction=pos-posTarget;
		direction.y=0;
		direction.normalise();
		Vector3 src=this->getEntityNode()->getOrientation() * Vector3::UNIT_X;
		if(1.0f + src.dotProduct(direction) < 0.0001f)
		{
			this->getEntityNode()->yaw(Degree(180));
		}
		else
		{
			this->getEntityNode()->rotate(src.getRotationTo(direction));
		}
	}
}

void CIGameAgent::wander(Real dt)
{
	Real r = Ogre::Math::UnitRandom();
	if(r < 0.2f)
	{
		this->turnLeft(dt);
	}
	else if(r < 0.4f)
	{
		this->turnRight(dt);
	}
	this->walk(dt);
}

void CIGameAgent::update(Real dt)
{
	updateTarget();

	switch(mRegisteredAction)
	{
	case ATTACK:
		confrontEnemy(dt);
		shoot(dt);
		break;
	case APPROACH:
		confrontEnemy(dt);
		walk(dt);
		break;
	case ESCAPE:
		evadeEnemy(dt);
		walk(dt);
		break;
	case IDLE:
		idle(dt);
		break;
	case DIE:
		die(dt);
		break;
	case WALK:
		walk(dt);
		break;
	case SHOOT:
		shoot(dt);
		break;
	case WANDER:
		wander(dt);
		break;
	default:
		break;
	}

	mGun->update(dt);
}

bool CIGameAgent::hasValidScript() const
{
	Scriptlet* script=ScriptManager::getSingletonPtr()->getScriptlet(mScriptId);
	return script != NULL;
}

std::string CIGameAgent::stateToString(CIGameAgentActionState state)
{
	switch(state)
	{
	case ATTACK:
		return "Attack";
	case IDLE:
		return "Idle";
	case APPROACH:
		return "Approach";
	case WANDER:
		return "Wander";
	case ESCAPE:
		return "Escape";
	case DIE:
		return "Die";
	case SHOOT:
		return "Shoot";
	case WALK:
		return "Walk";
	case SLUMP:
		return "Slump";
	case DEAD:
		return "Dead";
	default:
		return "Unknown Action State";
	}
}

void CIGameAgent::hide()
{
	if(mAuraNode != NULL)
	{
		mAuraNode->setVisible(false);
	}

	this->mGun->clearProjectiles();
	CIAgent::hide();
}

void CIGameAgent::show()
{
	if(mAuraNode != NULL)
	{
		mAuraNode->setVisible(false);
	}
	CIAgent::show();
}

size_t CIGameAgent::isTargetAttackable() const
{
	if(mCurrentTarget == NULL)
	{
		return 0;
	}
	if(this->isAttackable(mCurrentTarget))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

float CIGameAgent::getTargetRelativeDistance() const
{
	if(mCurrentTarget==NULL)
	{
		return 1;
	}

	float relativeDistance=this->getDistance(mCurrentTarget) / this->getSenseRange();
	if(relativeDistance > 1)
	{
		relativeDistance=1;
	}
	return relativeDistance;
}

float CIGameAgent::getTargetRelativeLife() const
{
	if(mCurrentTarget==NULL)
	{
		return 0;
	}

	if(this->mLife <= 0)
	{
		return 100000000000;
	}

	float relativeLife = (float)mCurrentTarget->getLife()  / this->mLife;

	return relativeLife;
}

void CIGameAgent::deactivate()
{
	if(this->isUserBot() && mField != NULL)
	{
		mFieldNode->setVisible(false);
		mAuraNode->setVisible(true);
	}
	CIAgent::deactivate();
}

void CIGameAgent::activate(bool showPS)
{
	CIAgent::activate(showPS);
	if(this->isUserBot() && mField != NULL)
	{
		mFieldNode->setVisible(true);
		mAuraNode->setVisible(false);
	}
}

bool CIGameAgent::isUserBot() const
{
	return this->getScriptId().compare("UserBot")==0;
}