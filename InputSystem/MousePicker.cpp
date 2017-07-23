#include "MousePicker.h"
#include "../GameEngine/Application.h"
#include "../OSEnvironment/OSEnvironment.h"
#include "../CIAgents/CIAgentManager.h"
#include "../OgreRayUtil/OgreRayUtil.h"

MousePicker::MousePicker()
: mCamera(NULL)
{
	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
	mRaySceneQuery=sm->createRayQuery(Ray());	
	mRaySceneQuery->setSortByDistance(true);
}

MousePicker::~MousePicker()
{
	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
	sm->destroyQuery(mRaySceneQuery);
}

Vector3 MousePicker::getTerrainIntersection(const OIS::MouseEvent& evt)
{
	CEGUI::Point& mousePoint=CEGUI::MouseCursor::getSingletonPtr()->getPosition(); 

	Ray mouseRay=mCamera->getCameraToViewportRay(mousePoint.d_x / float(evt.state.width), mousePoint.d_y / float(evt.state.height));
	return TerrainInfoManager::getSingletonPtr()->getIntersection(mouseRay);

	
	/*
	mRaySceneQuery->setRay(mouseRay);
	mRaySceneQuery->setSortByDistance(true);

	RaySceneQueryResult& result=mRaySceneQuery->execute();
	
	Vector3 pos;
	RaySceneQueryResult::iterator ri=result.begin();
	RaySceneQueryResult::iterator ri_end=result.end();
	for(; ri != ri_end; ++ri)
	{
		if(!(ri->movable && ri->movable->getName().substr(0, 5)!="tile[") && ri->worldFragment)
		{
			pos = ri->worldFragment->singleIntersection;
			break;
		}
	}
	return pos;
	*/
}

MovableObject* MousePicker::pick(const OIS::MouseEvent& evt)
{
	CIAgentManager* cim=CIAgentManager::getSingletonPtr();

	CEGUI::Point& mousePoint=CEGUI::MouseCursor::getSingletonPtr()->getPosition();
	Ray mouseRay=mCamera->getCameraToViewportRay(mousePoint.d_x / float(evt.state.width), mousePoint.d_y / float(evt.state.height));
	
	/*
	mRaySceneQuery->setRay(mouseRay);
	RaySceneQueryResult& result=mRaySceneQuery->execute();
	RaySceneQueryResult::iterator ri=result.begin();
	RaySceneQueryResult::iterator ri_end=result.end();
	for(; ri != ri_end; ++ri)
	{
		if(ri->movable)
		{
			const String& entityName = ri->movable->getName();
			if(entityName.substr(0, 5)!="tile[" && entityName.substr(0, prefix.length()) == prefix)
			{
				return ri->movable;
				break;
			}
		}
	}
	*/

	Vector3 direction=mouseRay.getDirection();
	direction.normalise();
	return OgreRayUtil::RaycastFromPoint(mRaySceneQuery, mouseRay.getOrigin(), direction);
}

