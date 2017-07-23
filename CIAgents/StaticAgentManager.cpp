#include "StaticAgentManager.h"
#include "../OSEnvironment/OSEnvironment.h"
#include "CIAgentManager.h"
#include "ModelManager.h"

StaticAgentManager::StaticAgentManager()
{
	ModelManager* mm=ModelManager::getSingletonPtr();
	const std::vector<std::string>& models=mm->getConstModelNames();
	std::vector<std::string>::const_iterator miter=models.begin();
	std::vector<std::string>::const_iterator miter_end=models.end();
	
	for(; miter != miter_end; ++miter)
	{
		const std::string& model_name=*miter;
		ModelManager::EnvironmentType type=mm->getEnvironmentType(model_name);
		if(type==ModelManager::ENVIRONMENTTYPE_STATIC)
		{
			mStaticAgentModels.push_back(model_name);
		}
	}
	if(!mStaticAgentModels.empty())
	{
		mSelectedStaticAgentModel=mStaticAgentModels[0];
	}
}

StaticAgentManager::~StaticAgentManager()
{

}

StaticAgentManager* StaticAgentManager::getSingletonPtr()
{
	static StaticAgentManager theInstance;
	return &theInstance;
}

CIAgent* StaticAgentManager::createStaticAgent(const Ogre::Vector3& pos)
{
	if(this->mStaticAgentModels.empty())
	{
		return NULL;
	}
	CIGameAgent* agent=CIAgentManager::getSingletonPtr()->createGameAgent(pos);
	agent->changeModel(this->getSelectedStaticAgentModel());
	mCurrentStaticAgents.insert(agent);
	//mSelectedCurrentStaticAgents.insert(agent);
	//agent->activate();
	return agent;
}

void StaticAgentManager::unselectAgents()
{
	StaticAgentSetIter aiter=mSelectedCurrentStaticAgents.begin();
	StaticAgentSetIter aiter_end=mSelectedCurrentStaticAgents.end();
	for(; aiter != aiter_end; ++aiter)
	{
		(*aiter)->deactivate();
	}
	mSelectedCurrentStaticAgents.clear();
}

void StaticAgentManager::removeAgent(CIAgent* agent)
{
	if(agent->isActive())
	{
		agent->deactivate();
		mSelectedCurrentStaticAgents.erase(mSelectedCurrentStaticAgents.find(agent));
	}

	CIAgentManager* cim=CIAgentManager::getSingletonPtr();
	cim->removeCIAgent(agent);
	StaticAgentSetIter aiter=mCurrentStaticAgents.find(agent);
	if(aiter != mCurrentStaticAgents.end())
	{
		mCurrentStaticAgents.erase(aiter);
	}
}

void StaticAgentManager::removeAllAgents()
{
	CIAgentManager* cim=CIAgentManager::getSingletonPtr();
	StaticAgentSetIter iter=mCurrentStaticAgents.begin();
	StaticAgentSetIter iter_end=mCurrentStaticAgents.end();
	CIAgent* agent=NULL;
	for(; iter != iter_end; ++iter)
	{
		agent=*iter;
		if(agent->isActive())
		{
			agent->deactivate();
		}
		cim->removeCIAgent(agent);
	}
	mCurrentStaticAgents.clear();
	mSelectedCurrentStaticAgents.clear();
}

CIAgent* StaticAgentManager::getAgent(MovableObject* mo)
{
	StaticAgentSetIter agiter=mCurrentStaticAgents.begin();
	StaticAgentSetIter agiter_end=mCurrentStaticAgents.end();
	CIAgent* agent=NULL; 
	for(; agiter != agiter_end; ++agiter)
	{
		agent=(*agiter);
		if(agent->getEntity() == mo)
		{
			return agent;
		}
	}

	return NULL;
}

void StaticAgentManager::selectAgent(MovableObject* mo)
{
	if(mo==NULL)
	{
		return;
	}

	CIAgent* agent=getAgent(mo); 
	if(agent != NULL)
	{
		agent->activate();
		mSelectedCurrentStaticAgents.insert(agent);
	}
}

void StaticAgentManager::removeSelectedAgents()
{
	if(!mSelectedCurrentStaticAgents.empty())
	{
		StaticAgentSetIter aiter=mSelectedCurrentStaticAgents.begin();
		StaticAgentSetIter aiter_end=mSelectedCurrentStaticAgents.end();
		CIAgent* agent=NULL;
		CIAgentManager* cim=CIAgentManager::getSingletonPtr();
		for(; aiter != aiter_end; ++aiter)
		{
			agent=*aiter;
			if(agent->isActive())
			{
				agent->deactivate();
			}

			cim->removeCIAgent(agent);
			StaticAgentSetIter fnd=mCurrentStaticAgents.find(agent);
			if(fnd != mCurrentStaticAgents.end())
			{
				mCurrentStaticAgents.erase(fnd);
			}
		}
		mSelectedCurrentStaticAgents.clear();
	}
}

void StaticAgentManager::scaleSelectedAgents(const Vector3& scale)
{
	StaticAgentSetIter aiter=mSelectedCurrentStaticAgents.begin();
	StaticAgentSetIter aiter_end=mSelectedCurrentStaticAgents.end();
	CIAgent* agent=NULL;
	for(; aiter != aiter_end; ++aiter)
	{
		agent=*aiter;
		SceneNode* node=agent->getEntityNode();
		node->setScale(node->getScale()+scale);
	}
}

void StaticAgentManager::yawSelectedAgents(const Real& radian)
{
	StaticAgentSetIter aiter=mSelectedCurrentStaticAgents.begin();
	StaticAgentSetIter aiter_end=mSelectedCurrentStaticAgents.end();
	CIAgent* agent=NULL;
	for(; aiter != aiter_end; ++aiter)
	{
		agent=*aiter;
		agent->getEntityNode()->yaw(Ogre::Radian(radian));
	}
}

void StaticAgentManager::translateSelectedAgents(const Vector3& vec)
{
	StaticAgentSetIter aiter=mSelectedCurrentStaticAgents.begin();
	StaticAgentSetIter aiter_end=mSelectedCurrentStaticAgents.end();
	CIAgent* agent=NULL;
	for(; aiter != aiter_end; ++aiter)
	{
		agent=*aiter;
		agent->getEntityNode()->setPosition(agent->getEntityNode()->getPosition()+vec);
	}
}

bool StaticAgentManager::frameStarted(const Ogre::FrameEvent &evt)
{
	CIAgent* agent=NULL;
	StaticAgentSetIter giter=mCurrentStaticAgents.begin();
	CIAgentManager* cim=CIAgentManager::getSingletonPtr();
	while(giter != mCurrentStaticAgents.end())
	{
		agent=*giter;
		if(agent->isDead())
		{
			if(agent->isActive())
			{
				mSelectedCurrentStaticAgents.erase(mSelectedCurrentStaticAgents.find(agent));
			}

			cim->removeCIAgent(agent);
			giter=mCurrentStaticAgents.erase(giter);
			continue;
		}
		
		if(agent->isDying())
		{
			agent->run("act: die", evt.timeSinceLastFrame);
		}
		giter++;
	}
	return true;
}