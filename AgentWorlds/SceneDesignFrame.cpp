#include "SceneDesignFrame.h"
#include "../GameEngine/Application.h"
#include "../OSEnvironment/OSEnvironment.h"
#include "../CIAgents/StaticAgentManager.h"
#include "../GameLoader/GameLoaderManager.h"

SceneDesignFrame::SceneDesignFrame(Application* app, std::string frameName)
: AppFrame(app, frameName)
{
	mMouseDrag.setCamera(mApp->getCamera());
	mMousePicker.setCamera(mApp->getCamera());

	mSceneDesignToolkit=new SceneDesignToolkit(getUIId("SceneDesignToolkit"));
	mSaveAsDlg=new GameLoaderSaveAsDlg(getUIId("GameLoaderSaveAsDlg"));

	mPointer=mSceneMgr->getRootSceneNode()->createChildSceneNode();
}

void SceneDesignFrame::unselectAgents()
{
	StaticAgentManager::getSingletonPtr()->unselectAgents();
}

void SceneDesignFrame::removeAgent(CIAgent* agent)
{
	StaticAgentManager::getSingletonPtr()->removeAgent(agent);
}

void SceneDesignFrame::removeAllAgents()
{
	StaticAgentManager::getSingletonPtr()->removeAllAgents();
}

bool SceneDesignFrame::onButtonClicked_GameLoaderSaveAs(const CEGUI::EventArgs& evt)
{
	std::string name=mSaveAsDlg->getGameLoaderName();
	
	if(name.compare("")==0)
	{
		GUIManager::getSingletonPtr()->showMsgBox("Invalid GameLoader Name", "Empty Name");
	}
	else
	{
		GameLoader* loader=GameLoaderManager::getSingletonPtr()->getGameLoaderByName(name);
		if(loader != NULL)
		{
			GUIManager::getSingletonPtr()->showMsgBox("Invalid GameLoader Name", "GameLoader Exists");
		}
		else
		{
			GameLoaderManager::getSingletonPtr()->addGameLoader(name, GameLoaderManager::getSingletonPtr()->getCurrentGameLoader()->saveAs(name));
			mSaveAsDlg->hide();
		}
	}

	return true;
}
	
CIAgent* SceneDesignFrame::getAgent(MovableObject* mo)
{
	return StaticAgentManager::getSingletonPtr()->getAgent(mo);
}

void SceneDesignFrame::selectAgent(MovableObject* mo)
{
	return StaticAgentManager::getSingletonPtr()->selectAgent(mo);
}

SceneDesignFrame::~SceneDesignFrame()
{
	if(mSceneDesignToolkit != NULL)
	{
		delete mSceneDesignToolkit;
		mSceneDesignToolkit=NULL;
	}

	if(mSaveAsDlg != NULL)
	{
		delete mSaveAsDlg;
		mSaveAsDlg=NULL;
	}
}

void SceneDesignFrame::save()
{
	GameLoaderManager::getSingletonPtr()->getCurrentGameLoader()->save();
}

void SceneDesignFrame::saveAs()
{
	mSaveAsDlg->show();
}

bool SceneDesignFrame::frameExited()
{
	mSceneDesignToolkit->hide();
	backupAgents();

	mSceneMgr->getRootSceneNode()->removeAndDestroyChild(mPointer->getName());
	return AppFrame::frameExited();
}

void SceneDesignFrame::backupAgents()
{
	StaticAgentManager::getSingletonPtr()->unselectAgents();
}

void SceneDesignFrame::restoreAgents()
{
	
}

void SceneDesignFrame::subscribeEvents()
{
	mEventDragClear=mMouseDrag.subscribeEvent_onUnSelect(boost::bind(&SceneDesignFrame::unselectAgents, this));
	mEventDragSelect=mMouseDrag.subscribeEvent_onSelect(boost::bind(&SceneDesignFrame::selectAgent, this, _1));
	mEventGameLoaderSaveAs=mSaveAsDlg->getBtnSave()->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&SceneDesignFrame::onButtonClicked_GameLoaderSaveAs, this));
}

void SceneDesignFrame::unsubscribeEvents()
{
	mEventDragClear.disconnect();
	mEventDragSelect.disconnect();
	mEventGameLoaderSaveAs->disconnect();
}

bool SceneDesignFrame::frameEntered()
{
	if(!AppFrame::frameEntered())
	{
		return false;
	}

	restoreAgents();

	mSceneDesignToolkit->show();

	return true;
}

bool SceneDesignFrame::frameStarted(const FrameEvent& evt)
{
	if(!Application::getSingletonPtr()->getWindow()->isActive())
	{
		return mContinue;
	}

	if(!AppFrame::frameStarted(evt))
	{
		return false;
	}

	if(this->mLeftButtonDown)
	{
		SceneDesignToolkit::SceneDesignAction action=mSceneDesignToolkit->getDesignAction();
		switch(action)
		{
		case SceneDesignToolkit::SD_TERRAIN:
			{
				Vector3 pos=mPointer->getPosition();
				TerrainDesignToolkit::TerrainDesignAction tAction=mSceneDesignToolkit->getTerrainDesignAction();
				switch(tAction)
				{
				case TerrainDesignToolkit::TD_DIG:
					TerrainInfoManager::getSingletonPtr()->deform(pos.x, pos.z, -evt.timeSinceLastFrame * 0.4);
					break;
				case TerrainDesignToolkit::TD_ELEVATE:
					TerrainInfoManager::getSingletonPtr()->deform(pos.x, pos.z, evt.timeSinceLastFrame * 0.4);
					break;
				case TerrainDesignToolkit::TD_PAINT0:
					TerrainInfoManager::getSingletonPtr()->paint(pos.x, pos.z, evt.timeSinceLastFrame * 5.0f, 0);
					break;
				case TerrainDesignToolkit::TD_PAINT1:
					TerrainInfoManager::getSingletonPtr()->paint(pos.x, pos.z, evt.timeSinceLastFrame * 5.0f, 1);
					break;
				case TerrainDesignToolkit::TD_PAINT2:
					TerrainInfoManager::getSingletonPtr()->paint(pos.x, pos.z, evt.timeSinceLastFrame * 5.0f, 2);
					break;
				case TerrainDesignToolkit::TD_PAINT3:
					TerrainInfoManager::getSingletonPtr()->paint(pos.x, pos.z, evt.timeSinceLastFrame * 5.0f, 3);
					break;
				case TerrainDesignToolkit::TD_PAINT4:
					TerrainInfoManager::getSingletonPtr()->paint(pos.x, pos.z, evt.timeSinceLastFrame * 5.0f, 4);
					break;
				case TerrainDesignToolkit::TD_PAINT5:
					TerrainInfoManager::getSingletonPtr()->paint(pos.x, pos.z, evt.timeSinceLastFrame * 5.0f, 5);
					break;
				default:
					break;
				}
			}
			break;
		default:
			break;
		}
	}
	else if(this->mRightButtonDown)
	{
		SceneDesignToolkit::SceneDesignAction action=mSceneDesignToolkit->getDesignAction();
		switch(action)
		{
		case SceneDesignToolkit::SD_TERRAIN:
			{
				Vector3 pos=mPointer->getPosition();
				TerrainDesignToolkit::TerrainDesignAction tAction=mSceneDesignToolkit->getTerrainDesignAction();
				switch(tAction)
				{
				case TerrainDesignToolkit::TD_PAINT0:
					TerrainInfoManager::getSingletonPtr()->paint(pos.x, pos.z, -evt.timeSinceLastFrame * 5.0f, 0);
					break;
				case TerrainDesignToolkit::TD_PAINT1:
					TerrainInfoManager::getSingletonPtr()->paint(pos.x, pos.z, -evt.timeSinceLastFrame * 5.0f, 1);
					break;
				case TerrainDesignToolkit::TD_PAINT2:
					TerrainInfoManager::getSingletonPtr()->paint(pos.x, pos.z, -evt.timeSinceLastFrame * 5.0f, 2);
					break;
				case TerrainDesignToolkit::TD_PAINT3:
					TerrainInfoManager::getSingletonPtr()->paint(pos.x, pos.z, -evt.timeSinceLastFrame * 5.0f, 3);
					break;
				case TerrainDesignToolkit::TD_PAINT4:
					TerrainInfoManager::getSingletonPtr()->paint(pos.x, pos.z, -evt.timeSinceLastFrame * 5.0f, 4);
					break;
				case TerrainDesignToolkit::TD_PAINT5:
					TerrainInfoManager::getSingletonPtr()->paint(pos.x, pos.z, -evt.timeSinceLastFrame * 5.0f, 5);
					break;
				default:
					break;
				}
			}
			break;
		default:
			break;
		}
	}

	if(StaticAgentManager::getSingletonPtr()->getSelectedCurrentStaticAgents().empty())
	{
		FrameManager::getSingletonPtr()->updateCamera(evt.timeSinceLastFrame);
	}
	
	return mContinue;
}

bool SceneDesignFrame::keyReleased(const OIS::KeyEvent& evt)
{
	if(!AppFrame::keyReleased(evt))
	{
		if( !GUIManager::getSingletonPtr()->getModalState())
		{
			switch(evt.key)
			{
			case OIS::KC_DELETE:
				StaticAgentManager::getSingletonPtr()->removeSelectedAgents();
				break;
			default:
				break;
			}
		}
		return true;
	}

	return true;
}

bool SceneDesignFrame::keyPressed(const OIS::KeyEvent& evt)
{
	if(!AppFrame::keyPressed(evt))
	{
		if( !GUIManager::getSingletonPtr()->getModalState())
		{
			switch(evt.key)
			{
			case OIS::KC_UP:
				StaticAgentManager::getSingletonPtr()->scaleSelectedAgents(Vector3(0.1f, 0.1f, 0.1f));
				break;
			case OIS::KC_DOWN:
				StaticAgentManager::getSingletonPtr()->scaleSelectedAgents(Vector3(-0.1f, -0.1f, -0.1f));
				break;
			case OIS::KC_LEFT:
				StaticAgentManager::getSingletonPtr()->yawSelectedAgents(0.1f);
				break;
			case OIS::KC_RIGHT:
				StaticAgentManager::getSingletonPtr()->yawSelectedAgents(-0.1f);
				break;
			case OIS::KC_U:
				StaticAgentManager::getSingletonPtr()->translateSelectedAgents(Vector3(0, 0.5f, 0));
				break;
			case OIS::KC_D:
				StaticAgentManager::getSingletonPtr()->translateSelectedAgents(Vector3(0, -0.5f, 0));
				break;
			default:
				break;
			}
		}
		return true;
	}

	return true;
}

bool SceneDesignFrame::mouseReleased(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
{
	if(!AppFrame::mouseReleased(evt, id))
	{
		if(this->mLeftButtonDown)
		{
			SceneDesignToolkit::SceneDesignAction action=mSceneDesignToolkit->getDesignAction();
			switch(action)
			{
			case SceneDesignToolkit::SD_TERRAIN:
				{
					TerrainDesignToolkit::TerrainDesignAction tAction=mSceneDesignToolkit->getTerrainDesignAction();
					switch(tAction)
					{
					case TerrainDesignToolkit::TD_DIG:
					case TerrainDesignToolkit::TD_ELEVATE:
						TerrainInfoManager::getSingletonPtr()->updateLightmap();
						break;
					default:
						break;
					}
				}
				break;
			default:
				break;
			}
		}
		
		if(mLeftButtonDown==false && !mSceneDesignToolkit->isBuilding() && SceneDesignToolkit::SD_STATICAGENT==mSceneDesignToolkit->getDesignAction())
		{
			mMouseDrag.dragEnded(evt);
		}
		return true;
	}
	return true;
}

bool SceneDesignFrame::mouseMoved(const OIS::MouseEvent& evt)
{
	if(!AppFrame::mouseMoved(evt))
	{
		if(mLeftButtonDown || mRightButtonDown)
		{
			mPointer->setPosition(mMousePicker.getTerrainIntersection(evt));
		}

		if(mLeftButtonDown && !mSceneDesignToolkit->isBuilding() && SceneDesignToolkit::SD_STATICAGENT==mSceneDesignToolkit->getDesignAction())
		{
			StaticAgentManager::StaticAgentSet& currentAgents=StaticAgentManager::getSingletonPtr()->getSelectedCurrentStaticAgents();
			if(currentAgents.size()==1)
			{
				StaticAgentManager::StaticAgentSetIter aiter=currentAgents.begin();
				(*aiter)->setPosition(mMousePicker.getTerrainIntersection(evt));
			}
			else
			{
				mMouseDrag.drag(evt);
			}
		}
		else if(mRightButtonDown)
		{
			
			FrameManager::getSingletonPtr()->onRightMouseDrag(evt.state.X.rel, evt.state.Y.rel);
		}
		return true;
	}

	return true;
}

bool SceneDesignFrame::mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
{
	if(!AppFrame::mousePressed(evt, id))
	{
		mPointer->setPosition(mMousePicker.getTerrainIntersection(evt));
		if(!GUIManager::getSingletonPtr()->hasFocus())
		{
				doSceneDesignAction(evt);
				if(mLeftButtonDown && !mSceneDesignToolkit->isBuilding() && SceneDesignToolkit::SD_STATICAGENT==mSceneDesignToolkit->getDesignAction())
				{
					mMouseDrag.dragStarted(evt);
				}
		}
	}

	return true;
}

void SceneDesignFrame::doSceneDesignAction(const OIS::MouseEvent& evt)
{
	SceneDesignToolkit::SceneDesignAction action=mSceneDesignToolkit->getDesignAction();
	switch(action)
	{
	case SceneDesignToolkit::SD_STATICAGENT:
		{
			if(mLeftButtonDown)
			{
				if(mSceneDesignToolkit->isBuilding())
				{
					StaticAgentManager::getSingletonPtr()->createStaticAgent(mPointer->getPosition());
				}
				else
				{
					unselectAgents();
					MovableObject* mo=mMousePicker.pick(evt);
					selectAgent(mo);
				}
			}
			break;
		}
	case SceneDesignToolkit::SD_FOREST:
		{
			if(mLeftButtonDown)
			{
				ForestDesignToolkit::ForestDesignAction faction=mSceneDesignToolkit->getForestDesignAction();
				float radius=mSceneDesignToolkit->getForestEditRadius();
				int count=mSceneDesignToolkit->getForestEditCount();
				PGManager* pgm=PGManager::getSingletonPtr();
				bool autoPopulate=mSceneDesignToolkit->isForestEditAutoPopulateEnabled();
				switch(faction)
				{
					case ForestDesignToolkit::FD_CLEARBUSH:
						if(autoPopulate)
						{
							pgm->unloadBush();
						}
						else
						{
							pgm->unloadBush(mPointer->getPosition(), radius);
						}
						break;
					case ForestDesignToolkit::FD_CLEARTREE:
						if(autoPopulate)
						{
							pgm->unloadTree1();
						}
						else
						{
							pgm->unloadTree1(mPointer->getPosition(), radius);
						}
						break;
					case ForestDesignToolkit::FD_CLEARGRASS:
						if(autoPopulate)
						{
							pgm->unloadGrass();
						}
						else
						{
							pgm->unloadGrass(mPointer->getPosition(), radius);
						}
						break;
					case ForestDesignToolkit::FD_POPULATEBUSH:
						if(autoPopulate)
						{
							pgm->loadBush();
						}
						else
						{
							pgm->loadBush(mPointer->getPosition(), radius, count);
						}
						break;
					case ForestDesignToolkit::FD_POPULATETREE:
						if(autoPopulate)
						{
							pgm->loadTree1();
						}
						else
						{
							pgm->loadTree1(mPointer->getPosition(), radius, count);
						}
						break;
					case ForestDesignToolkit::FD_POPULATEGRASS:
						if(autoPopulate)
						{
							pgm->loadGrass();
						}
						else
						{
							pgm->loadGrass(mPointer->getPosition(), radius);
						}
						break;
					default:
						break;
				}
			}
			
			break;
		}
	default:
		break;
	}
}
