#ifndef _H_MLLAB_CI_AGENT_MANAGER_H
#define _H_MLLAB_CI_AGENT_MANAGER_H

#include <stack>
#include <set>
#include <Ogre.h>
#include "CIAgent.h"
#include "ModelManager.h"

using namespace Ogre;

class Application;
class WeaponManager;
class CICodeAgent;
class CIGameAgent;

class CIAgentManager
{
public:
	typedef std::set<CIAgent*> CIAgentList;
	typedef CIAgentList::iterator CIAgentListIterator;
	typedef CIAgentList::const_iterator CIAgentListConstIterator;

public:
	virtual ~CIAgentManager();

private:
	CIAgentManager(const CIAgentManager& rhs) { }
	CIAgentManager& operator=(const CIAgentManager& rhs) { return *this; }

public:
	CIAgentManager(Application* app, size_t expanded=10);

public:
	static CIAgentManager& getSingleton()
	{
		return *mSingleton;
	}
	static CIAgentManager* getSingletonPtr()
	{
		return mSingleton;
	}

public:
	CICodeAgent* createCodeAgent(const Vector3& posAgent, const std::string& type, const std::string& method);
	CIGameAgent* createGameAgent(const Vector3& posAgent);
	CIGameAgent* createGameAgent(const Vector3& posAgent, const std::string& scriptId);
	CIGameAgent* createGameAgent(const Vector3& pos, const std::string& scriptId, const ColourValue& c);
	void removeCIAgent(CIAgent* agent);
	CIAgent* getCIAgent(SceneNode* agentNode);
	CIAgent* getCIAgent(const std::string& agentId);
	CIAgentList& getCIAgents() { return mCIAgents; }
	void removeAllAgents();

public:
	ParticleSystem* popAlphaPS();
	void pushAlphaPS(ParticleSystem* ps);
	bool exists(CIAgent* agent) const;

protected:
	static CIAgentManager* mSingleton;
	std::stack<ParticleSystem*> mAlphaParticleSystems;
	Application* mApp;
	size_t mAlphaParticleSystemCount;
	size_t mInitialParticleSystemCount;
	CIAgentList mCIAgents;
	WeaponManager* mWeaponManager;
	size_t mAgentCounter;

private:
	ModelManager* mModelManager;
};
#endif
