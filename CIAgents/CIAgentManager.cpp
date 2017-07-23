#include "CIAgentManager.h"
#include "../GameEngine/Application.h"
#include "CICodeAgent.h"
#include "CIGameAgent.h"
#include "../Weapons/WeaponManager.h"
#include <sstream>

CIAgentManager* CIAgentManager::mSingleton=NULL;

CIAgentManager::~CIAgentManager()
{
	removeAllAgents();
	if(mWeaponManager != NULL)
	{
		delete mWeaponManager;
		mWeaponManager=NULL;
	}

	if(mModelManager != NULL)
	{
		delete mModelManager;
		mModelManager=NULL;
	}
}

void CIAgentManager::removeAllAgents()
{
	CIAgentManager::CIAgentListIterator iter=mCIAgents.begin();
	CIAgentManager::CIAgentListIterator iter_end=mCIAgents.end();
	for(; iter != iter_end; ++iter)
	{
		delete (*iter);
	}
	mCIAgents.clear();
}

ParticleSystem* CIAgentManager::popAlphaPS()
{
	if(mAlphaParticleSystems.empty())
	{
		std::ostringstream oss;
		oss << "CIAgentPS" << mAlphaParticleSystemCount++;
		SceneManager* sm=mApp->getSceneMgr();
		mAlphaParticleSystems.push(sm->createParticleSystem(oss.str().c_str(), "Examples/GreenyNimbus"));
	}
	ParticleSystem* ps=mAlphaParticleSystems.top();
	mAlphaParticleSystems.pop();
	return ps;
}

CICodeAgent* CIAgentManager::createCodeAgent(const Vector3& posAgent, const std::string& type, const std::string& method)
{
	std::ostringstream oss;
	oss << "CIAgent" << mAgentCounter;
	CICodeAgent* agent=new CICodeAgent(posAgent, oss.str().c_str(), type, method);
	mCIAgents.insert(agent);

	mAgentCounter++;
	return agent;
}

CIGameAgent* CIAgentManager::createGameAgent(const Vector3& pos, const std::string& scriptId)
{
	std::ostringstream oss;
	oss << "CIAgent" << mAgentCounter;

	CIGameAgent* agent=new CIGameAgent(pos, oss.str().c_str(), scriptId);
	mCIAgents.insert(agent);

	mAgentCounter++;

	return agent;
}

CIGameAgent* CIAgentManager::createGameAgent(const Vector3& posAgent)
{
	std::ostringstream oss;
	oss << "CIAgent" << mAgentCounter;

	CIGameAgent* agent=new CIGameAgent(posAgent, oss.str().c_str());
	mCIAgents.insert(agent);

	mAgentCounter++;

	return agent;
}

CIGameAgent* CIAgentManager::createGameAgent(const Vector3& pos, const std::string& scriptId, const ColourValue& c)
{
	std::ostringstream oss;
	oss << "CIAgent" << mAgentCounter;

	CIGameAgent* agent=new CIGameAgent(pos, oss.str().c_str(), scriptId, c);
	mCIAgents.insert(agent);

	mAgentCounter++;

	return agent;
}

void CIAgentManager::removeCIAgent(CIAgent* agent)
{
	CIAgentManager::CIAgentListIterator iter=mCIAgents.begin();
	while(iter != mCIAgents.end())
	{
		if((*iter)==agent)
		{
			iter=mCIAgents.erase(iter);
			delete agent;
			break;
		}
		else
		{
			iter++;
		}
	}
}
	
CIAgent* CIAgentManager::getCIAgent(SceneNode* agentNode)
{
	CIAgentManager::CIAgentListIterator iter=mCIAgents.begin();
	CIAgentManager::CIAgentListIterator iter_end=mCIAgents.end();
	CIAgent* agent=NULL;
	for(; iter != iter_end; ++iter)
	{
		agent=*iter;
		if(agent->getEntityNode()==agentNode)
		{
			return agent;
		}
	}
	return NULL;
}

CIAgent* CIAgentManager::getCIAgent(const std::string& agentId)
{
	CIAgentManager::CIAgentListIterator iter=mCIAgents.begin();
	CIAgentManager::CIAgentListIterator iter_end=mCIAgents.end();
	CIAgent* agent=NULL;
	for(; iter != iter_end; ++iter)
	{
		agent=*iter;
		if(agent->getAgentName().compare(agentId)==0)
		{
			return agent;
		}
	}
	return NULL;
}

void CIAgentManager::pushAlphaPS(ParticleSystem* ps)
{
	mAlphaParticleSystems.push(ps);
}

bool CIAgentManager::exists(CIAgent* agent) const
{
	CIAgentManager::CIAgentListConstIterator fnd=mCIAgents.find(agent);

	if(fnd == mCIAgents.end())
	{
		return false;
	}

	return true;
}

CIAgentManager::CIAgentManager(Application* app, size_t initialEntityCount)
: mApp(app)
, mAlphaParticleSystemCount(initialEntityCount)
, mInitialParticleSystemCount(initialEntityCount)
, mAgentCounter(0)
{
	if(mSingleton == NULL)
	{
		mSingleton=this;
	}
	else
	{
		throw Ogre::Exception(42, "multple instances not allow in a singleton pattern", "CIAgentManager::CIAgentManager(size_t expanded)");
	}

	mModelManager=new ModelManager(initialEntityCount);

	Ogre::SceneManager* sm=mApp->getSceneMgr();
	for(size_t i=0; i != initialEntityCount; ++i)
	{
		std::ostringstream oss1, oss2;
		oss2 << "CIAgentPS" << i;
	
		ParticleSystem* ps=sm->createParticleSystem(String(oss2.str().c_str()), "Examples/GreenyNimbus");
		mAlphaParticleSystems.push(ps);
	}

	mWeaponManager=new WeaponManager();
}