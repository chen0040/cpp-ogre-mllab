#include "GameSimulationFrame.h"
#include "../GameEngine/Application.h"
#include "../OSEnvironment/OSEnvironment.h"
#include "../CIAgents/CIAgentManager.h"
#include "../Widgets/GUIManager.h"
#include "../Widgets/MsgBox.h"
#include "../CIAgents/CIGameAgent.h"

GameSimulationFrame::GameSimulationFrame(Application* app, std::string frameName)
: AppFrame(app, frameName)
{
	mMouseDrag.setCamera(mApp->getCamera());
	mMousePicker.setCamera(mApp->getCamera());
}

void GameSimulationFrame::onBrowserJSEventCallback(const NaviLibrary::NaviData& data)
{
	if(data.exists("command"))
	{
		std::string command=data["command"].str();
	}
}

void GameSimulationFrame::unload()
{
	removeAllAgents();
}

void GameSimulationFrame::unselectAgents()
{
	CIGameAgent::SetIterator aiter=mCurrentCIAgents.begin();
	CIGameAgent::SetIterator aiter_end=mCurrentCIAgents.end();
	for(; aiter != aiter_end; ++aiter)
	{
		(*aiter)->deactivate();
	}
	mCurrentCIAgents.clear();
}

void GameSimulationFrame::removeAgent(CIGameAgent* agent)
{
	if(agent->isActive())
	{
		agent->deactivate();
	}

	CIAgentManager* cim=CIAgentManager::getSingletonPtr();
	cim->removeCIAgent(agent);
	mAgentPool.erase(mAgentPool.find(agent));
}

void GameSimulationFrame::removeAllAgents()
{
	CIAgentManager* cim=CIAgentManager::getSingletonPtr();
	CIGameAgent::SetIterator iter=mAgentPool.begin();
	CIGameAgent::SetIterator iter_end=mAgentPool.end();
	CIGameAgent* agent=NULL;
	for(; iter != iter_end; ++iter)
	{
		agent=*iter;
		if(agent->isActive())
		{
			agent->deactivate();
		}
		cim->removeCIAgent(agent);
	}
	mAgentPool.clear();
}
	
CIGameAgent* GameSimulationFrame::getAgent(MovableObject* mo)
{
	CIGameAgent::SetIterator agiter=mAgentPool.begin();
	CIGameAgent::SetIterator agiter_end=mAgentPool.end();
	CIGameAgent* agent=NULL; 
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

void GameSimulationFrame::selectAgent(MovableObject* mo)
{
	if(mo==NULL)
	{
		return;
	}

	CIGameAgent* agent=getAgent(mo); 
	if(agent != NULL)
	{
		agent->activate();
		mCurrentCIAgents.insert(agent);
	}
}

GameSimulationFrame::~GameSimulationFrame()
{

}

bool GameSimulationFrame::frameExited()
{
	mApp->getBrowser()->unbind("InvokeAgent");

	backupAgents();

	return AppFrame::frameExited();
}

void GameSimulationFrame::backupAgents()
{
	CIGameAgent::SetIterator agiter=mCurrentCIAgents.begin();
	CIGameAgent::SetIterator agiter_end=mCurrentCIAgents.end();
	for(; agiter != agiter_end; ++agiter)
	{
		(*agiter)->deactivate();
	}
	
	agiter=mAgentPool.begin();
	agiter_end=mAgentPool.end();
	for(; agiter != agiter_end; ++agiter)
	{
		(*agiter)->hide();
	}
}

void GameSimulationFrame::restoreAgents()
{
	CIGameAgent::SetIterator agiter=mAgentPool.begin();
	CIGameAgent::SetIterator agiter_end=mAgentPool.end();
	for(; agiter != agiter_end; ++agiter)
	{
		(*agiter)->show();
	}
	agiter=mCurrentCIAgents.begin();
	agiter_end=mCurrentCIAgents.end();
	for(; agiter != agiter_end; ++agiter)
	{
		(*agiter)->activate();
	}
}

void GameSimulationFrame::subscribeEvents()
{
	mEventDragClear=mMouseDrag.subscribeEvent_onUnSelect(boost::bind(&GameSimulationFrame::unselectAgents, this));
	mEventDragSelect=mMouseDrag.subscribeEvent_onSelect(boost::bind(&GameSimulationFrame::selectAgent, this, _1));
}

void GameSimulationFrame::unsubscribeEvents()
{
	mEventDragClear.disconnect();
	mEventDragSelect.disconnect();
}

bool GameSimulationFrame::frameEntered()
{
	if(!AppFrame::frameEntered())
	{
		return false;
	}

	mApp->getBrowser()->bind("InvokeAgent", NaviLibrary::NaviDelegate(this, &GameSimulationFrame::onBrowserJSEventCallback));
	mApp->getBrowser()->navigateTo("default");

	restoreAgents();

	return true;
}

bool GameSimulationFrame::frameStarted(const FrameEvent& evt)
{
	if(!Application::getSingletonPtr()->getWindow()->isActive())
	{
		return mContinue;
	}

	if(!AppFrame::frameStarted(evt))
	{
		return false;
	}

	CIGameAgent* agent=NULL;
	CIGameAgent::SetIterator giter=mAgentPool.begin();
	CIGameAgent::SetIterator giter_end=mAgentPool.end();
	for(; giter != giter_end; ++giter)
	{
		agent=*giter;
		if(agent->isActive())
		{
			if(isKeyDown(OIS::KC_LEFT))
			{
				agent->run("act: turnLeft", evt.timeSinceLastFrame);
			}
			else if(isKeyDown(OIS::KC_RIGHT))
			{
				agent->run("act: turnRight", evt.timeSinceLastFrame);
			}

			if(isKeyDown(OIS::KC_UP))
			{
				agent->run("act: walk", evt.timeSinceLastFrame);
			}

			if(! (isKeyDown(OIS::KC_UP) || isKeyDown(OIS::KC_LEFT) || isKeyDown(OIS::KC_RIGHT)))
			{
				agent->run("act: idle", evt.timeSinceLastFrame);
			}
		}
		else
		{
			agent->run("act: idle", evt.timeSinceLastFrame);
		}
	}

	if(mCurrentCIAgents.empty())
	{
		FrameManager::getSingletonPtr()->updateCamera(evt.timeSinceLastFrame);
	}
	
	return mContinue;
}

bool GameSimulationFrame::mouseReleased(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
{
	if(!AppFrame::mouseReleased(evt, id))
	{
		if(mLeftButtonDown == false)
		{
			mMouseDrag.dragEnded(evt);
		}
	}
	return true;
}

bool GameSimulationFrame::mouseMoved(const OIS::MouseEvent& evt)
{
	if(!AppFrame::mouseMoved(evt))
	{
		if(mLeftButtonDown)
		{
			if(mCurrentCIAgents.size()==1)
			{
				CIGameAgent::SetIterator aiter=mCurrentCIAgents.begin();
				(*aiter)->setPosition(mMousePicker.getTerrainIntersection(evt));
			}
			else
			{
				mMouseDrag.drag(evt);
			}
		}
		if(mRightButtonDown)
		{
			FrameManager::getSingletonPtr()->onRightMouseDrag(evt.state.X.rel, evt.state.Y.rel);
		}
	}

	return true;
}

bool GameSimulationFrame::mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
{
	if(!AppFrame::mousePressed(evt, id))
	{
		if(mLeftButtonDown == true)
		{
			mMouseDrag.dragStarted(evt);	
		}
	}
	return true;
}
