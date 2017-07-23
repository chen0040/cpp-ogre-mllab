#ifndef _H_STATIC_AGENT_MANAGER_H
#define _H_STATIC_AGENT_MANAGER_H

#include <Ogre.h>
#include <map>
#include <vector>
#include "CIGameAgent.h"

using namespace Ogre;

class StaticAgentManager
{
public:
	typedef std::set<CIAgent*> StaticAgentSet;
	typedef StaticAgentSet::iterator StaticAgentSetIter;
	typedef StaticAgentSet::const_iterator StaticAgentSetConstIter;

public:
	virtual ~StaticAgentManager();

private:
	StaticAgentManager();
	StaticAgentManager(const StaticAgentManager& rhs) { }
	StaticAgentManager& operator=(const StaticAgentManager& rhs) { return *this; }

public:
	static StaticAgentManager* getSingletonPtr();

private:
	std::vector<std::string> mStaticAgentModels;
	StaticAgentSet mCurrentStaticAgents;
	StaticAgentSet mSelectedCurrentStaticAgents;
	std::string mSelectedStaticAgentModel;

public:
	void setSelectedStaticAgentModel(const std::string& StaticObj) { mSelectedStaticAgentModel=StaticObj; }
	StaticAgentSet& getCurrentStaticAgents() { return mCurrentStaticAgents; }
	StaticAgentSet& getSelectedCurrentStaticAgents() { return mSelectedCurrentStaticAgents; }
	const std::vector<std::string>& getStaticAgentModels() const { return mStaticAgentModels; }
	CIAgent* createStaticAgent(const Vector3& pos);
	void unselectAgents();
	void removeAgent(CIAgent* agent);
	void removeAllAgents();
	CIAgent* getAgent(MovableObject* mo);
	void selectAgent(MovableObject* mo);
	void removeSelectedAgents();
	void scaleSelectedAgents(const Vector3& scale);
	void yawSelectedAgents(const Real& radian);
	void translateSelectedAgents(const Vector3& vec);
	bool frameStarted(const Ogre::FrameEvent& evt);

public:
	const std::string& getSelectedStaticAgentModel() const { return mSelectedStaticAgentModel; }
};
#endif