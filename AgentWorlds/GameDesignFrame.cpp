#include "GameDesignFrame.h"
#include "../GameEngine/Application.h"
#include "../Weapons/WeaponManager.h"
#include <sstream>
#include "../SoundEngine/SoundManager.h"
#include "../OSEnvironment/OSEnvironment.h"
#include "../WeatherEngine/WeatherManager.h"
#include "../HTTPEngine/HTTPManager.h"
#include "../Recorder/GameAgentRecorder.h"
#include "../CIAgents/StaticAgentManager.h"
#include "../CIAgents/CIAgentManager.h"
#include "../ScriptEngine/ScriptManager.h"

GameDesignFrame::GameDesignFrame(Application* app, const std::string& frameName)
: AppFrame(app, frameName)
, mCurrentCIAgent(NULL)
, mScoreboardTimer(0)
, mScoreboardRecordInterval(0.1f)
, mScoreboardCriteria_bulletCount(20)
, mScoreboardCriteria_life(300)
, mScoreboardCriteria_armor(10)
, mScoreboardCriteria_walkSpeed(40)
, mScoreboardCriteria_senseRange(250)
, mScoreboardDoc(NULL)
, mWebBrowser(app->getBrowser())
{
	mWeatherDlg=new WeatherDlg(getUIId("WeatherDlg"));
	mIDBlock=new IDBlockWidget(getUIId("IDBlock"));
	mUserBotActionWidget=new UserBotActionWidget(getUIId("UserBotActionWidget"));
	mBotScriptWidget=new BotScriptWidget(getUIId("BotScriptWidget"));

	if(mGUIMgr->isOverlayPresent(getUIId("CIData")))
	{
		mBoard=mGUIMgr->getOverlay(getUIId("CIData"));
	}
	else
	{
		mBoard=mGUIMgr->createOverlay(getUIId("CIData"));
		mBoard->setText("");
		mBoard->setTitle("Message Board");
		mBoard->setAlpha(0.5f);
		mBoard->setPosition(0.75f, 0.59f);
		mBoard->setSize(0.25f, 0.2f);
	}


	mGameDesignWidget=new CIGameDesignWidget(getUIId("GameDesignDlg"));

	mGameSimulationControlBox=new GameSimulationControlBox(getUIId("GameSimulationControlBox"));

	setupCommands();

	mMousePicker.setCamera(mApp->getCamera());

	TiXmlDocument config;
	if(!config.LoadFile(OSEnvironment::getFullPath("..\\config\\scoreboard.xml").c_str()))
	{
		throw Exception(42, "Failed to load scoreboard.xml", "GameDesignFrame::createScoreboardDoc()");
	}
	
	TiXmlElement* xmlRoot=config.RootElement();
	for(TiXmlElement* xmlLevel1=xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1=xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "param")==0)
		{
			if(strcmp(xmlLevel1->Attribute("name"), "record_interval")==0)
			{
				xmlLevel1->QueryFloatAttribute("value", &mScoreboardRecordInterval);
			}
		}
	}

	createScoreboardDoc();

	mGameSimulationControlBox->hide();
	mGameDesignWidget->hide();
	mBoard->hide();
	mBotScriptWidget->hide();
}

void GameDesignFrame::createScoreboardDoc()
{
	if(mScoreboardDoc != NULL)
	{
		delete mScoreboardDoc;
		mScoreboardDoc=NULL;
	}
	mScoreboardDoc=new TiXmlDocument();

	mScoreboardDoc->LinkEndChild(new TiXmlDeclaration("1.0", "", ""));

	TiXmlElement* xmlRoot=new TiXmlElement("scoreboard");

	mScoreboardDoc->LinkEndChild(xmlRoot);

	xmlRoot->SetAttribute("time", OSEnvironment::getCurrentTime().c_str());

	mScoreboardDocSaved=true;
}

void GameDesignFrame::unselectAgents()
{
	if(mCurrentCIAgent != NULL)
	{
		mCurrentCIAgent->deactivate();
	}
	mCurrentCIAgent=NULL;
}

void GameDesignFrame::removeAllAgents()
{
	if(mCurrentCIAgent != NULL)
	{
		mCurrentCIAgent->deactivate();
		mCurrentCIAgent=NULL;
	}

	CIGameAgent::SetIterator agiter=mAgentPool.begin();
	CIGameAgent::SetIterator agiter_end=mAgentPool.end();
	for(; agiter != agiter_end; ++agiter)
	{
		CIAgentManager::getSingletonPtr()->removeCIAgent(*agiter);
	}
	mAgentPool.clear();
}

void GameDesignFrame::save()
{
	std::string filename=OSEnvironment::getWinSaveFileDialog("XML Files", "xml"); 

	if(filename.compare("")==0)
	{
		return;
	}

	TiXmlDocument doc;
	doc.LinkEndChild(new TiXmlDeclaration("1.0", "", ""));
	
	TiXmlElement* xmlRoot=new TiXmlElement("records");
	doc.LinkEndChild(xmlRoot);

	CIGameAgent::SetIterator aiter=mAgentPool.begin();
	CIGameAgent::SetIterator aiter_end=mAgentPool.end();
	CIGameAgent* agent=NULL;
	for(; aiter != aiter_end; ++aiter)
	{
		agent=*aiter;
		TiXmlElement* xmlLevel1=new TiXmlElement("agent");
		xmlLevel1->SetAttribute("name", agent->getAgentName().c_str());
		if(agent->isActive())
		{
			xmlLevel1->SetAttribute("active", "true");
		}
		else
		{
			xmlLevel1->SetAttribute("active", "false");
		}
		xmlLevel1->SetAttribute("scriptId", agent->getScriptId().c_str());
		

		TiXmlElement* xmlPosition=new TiXmlElement("position");
		const Vector3& pos=agent->getPosition();
		xmlPosition->SetDoubleAttribute("x", pos.x);
		xmlPosition->SetDoubleAttribute("y", pos.y);
		xmlPosition->SetDoubleAttribute("z", pos.z);
		xmlLevel1->LinkEndChild(xmlPosition);

		TiXmlElement* xmlCI=new TiXmlElement("state");
		xmlCI->SetAttribute("life", agent->getLife());
		xmlCI->SetDoubleAttribute("score", agent->getScore());
		xmlLevel1->LinkEndChild(xmlCI);

		xmlRoot->LinkEndChild(xmlLevel1);
	}

	doc.SaveFile(filename.c_str());
}
	
void GameDesignFrame::selectAgent(MovableObject* mo)
{
	if(mo == NULL)
	{
		return;
	}
	
	mCurrentCIAgent=getGameAgent(mo);
	if(mCurrentCIAgent != NULL)
	{
		mCurrentCIAgent->activate();

		if(inFrameState(SIMULATE))
		{
			if(mCurrentCIAgent->isUserBot())
			{	
				SoundManager::getSingletonPtr()->play("replycmd");
				mUserBotActionWidget->setUserBot(mCurrentCIAgent);
			}
		}
	}
}

void GameDesignFrame::removeAgent(CIGameAgent* agent)
{
	if(mUserBotActionWidget->getUserBot()==agent)
	{
		mUserBotActionWidget->setUserBot(NULL);
	}

	CIAgentManager::getSingletonPtr()->removeCIAgent(agent);
	mAgentPool.erase(mAgentPool.find(agent));
}

CIGameAgent* GameDesignFrame::getGameAgent(MovableObject* mo)
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

void GameDesignFrame::saveScoreboardDoc()
{
	if(mScoreboardDocSaved==false)
	{
		std::ostringstream oss;
		std::string filename=OSEnvironment::getFileNameUsingCurrentTime() ;
		oss << OSEnvironment::getFullPath("..\\simulations") << "\\" << filename << ".xml";
		mScoreboardDoc->SaveFile(oss.str().c_str());

		std::ofstream fout;
		oss.str("");
		oss << OSEnvironment::getFullPath("..\\simulations") << "\\" << filename << ".csv";

		fout.open(oss.str().c_str());
		fout << "name, scriptId, tag, life, score, senseRange, walkSpeed, armor, current_target, action_id, action, cheating, cheat_reason\n";
		
		bool record=false;
		TiXmlElement* xmlRoot=mScoreboardDoc->RootElement();
		for(TiXmlElement* xmlLevel1=xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1=xmlLevel1->NextSiblingElement())
		{
			if(mGameSimulationControlBox->recordLastEntry() && xmlLevel1->NextSiblingElement() == NULL)
			{
				record=true;
			}
			else
			{
				if(mGameSimulationControlBox->recordLastEntry()==false)
				{
					record=true;
				}
				else
				{
					record=false;
				}
			}
			if(strcmp(xmlLevel1->Value(), "simulation")==0 && record)
			{
				fout << "time(" << xmlLevel1->Attribute("time") << "), elapsed_time(" << xmlLevel1->Attribute("elapsed_time") << ")\n";
				for(TiXmlElement* xmlLevel2=xmlLevel1->FirstChildElement(); xmlLevel2 != NULL; xmlLevel2=xmlLevel2->NextSiblingElement())
				{
					if(strcmp(xmlLevel2->Value(), "agent")==0)
					{
						fout << xmlLevel2->Attribute("name") << ", ";
						fout << "=\"" << xmlLevel2->Attribute("scriptId") << "\", ";
						fout << xmlLevel2->Attribute("tag") << ", ";
						fout << xmlLevel2->Attribute("life") << ", ";
						fout << xmlLevel2->Attribute("score") << ", ";
						fout << xmlLevel2->Attribute("senseRange") << ", ";
						fout << xmlLevel2->Attribute("walkSpeed") << ", ";
						fout << xmlLevel2->Attribute("armor") << ", ";
						fout << xmlLevel2->Attribute("current_target") << ", ";
						fout << xmlLevel2->Attribute("action_id") << ", ";
						fout << xmlLevel2->Attribute("action") << ",";
						fout << xmlLevel2->Attribute("cheating") << ", ";
						fout << xmlLevel2->Attribute("cheat_reason")  << "\n";
					}
				}
			}
		}
		fout.close();
		mScoreboardDocSaved=true;
	}
}

void GameDesignFrame::setupCommands()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mCmdClimate=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), getUIId("mnuClimate")));
	mCmdClimate->setText((CEGUI::utf8*)"Climate");
}

bool GameDesignFrame::onClicked_NavigateMiniMap(const CEGUI::EventArgs& evt)
{
	CEGUI::Point pt=CEGUI::MouseCursor::getSingletonPtr()->getPosition();

	MiniMap* mm=Application::getSingletonPtr()->getMiniMap();

	const OIS::MouseState& ms=mMouse->getMouseState();

	CEGUI::Point mpt=mm->PtInMap(pt.d_x / ms.width, pt.d_y / ms.height);
	
	TerrainInfoManager* tm=TerrainInfoManager::getSingletonPtr();
	Real minX= tm->getMinX();
	Real minZ=tm->getMinZ();
	Real maxX=tm->getMaxX();
	Real maxZ=tm->getMaxZ();
	Real tX=minX + mpt.d_x * (maxX - minX);
	Real tZ=minZ + (1-mpt.d_y) * (maxZ - minZ);

	FrameManager::getSingletonPtr()->setCameraPOI(Vector3(tZ, 0, tX));
	
	return true;
}

void GameDesignFrame::subscribeEvents()
{
	mEventClimate=mCmdClimate->subscribeEvent(CEGUI::MenuItem::EventClicked, CEGUI::Event::Subscriber(&GameDesignFrame::onClicked_Climate, this));
	mEventTrainAgent=mIDBlock->getTrainingButton()->subscribeEvent(CEGUI::MenuItem::EventClicked, CEGUI::Event::Subscriber(&GameDesignFrame::onClicked_TrainAgent, this));
	mEventUploadConfig=mIDBlock->getUploadConfigButton()->subscribeEvent(CEGUI::MenuItem::EventClicked, CEGUI::Event::Subscriber(&GameDesignFrame::onClicked_UploadConfig, this));

	mEventScriptDeleted=mBotScriptWidget->subscribeEvent_onScriptDeleted(boost::bind(&GameDesignFrame::onScriptDeleted, this));
	mEventScriptsRefreshed=mBotScriptWidget->subscribeEvent_onScriptsRefreshed(boost::bind(&GameDesignFrame::onScriptsRefreshed, this));

	mEventModelSelected=mIDBlock->getModelDlg()->getOKButton()->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameDesignFrame::onSelected_Model, this));

	mEventStartSimulation=mGameSimulationControlBox->getStartSimulationButton()->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameDesignFrame::onClicked_StartSimulation, this));
	mEventStopSimulation=mGameSimulationControlBox->getStopSimulationButton()->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameDesignFrame::onClicked_StopSimulation, this));
	mEventShowAgents=mGameSimulationControlBox->getSimulationDisplayButton()->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameDesignFrame::onClicked_ShowAgents, this));
	mEventRemoveAgents=mGameSimulationControlBox->getRemoveAgentsButton()->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameDesignFrame::onClicked_RemoveAgents, this));

	CEGUI::DefaultWindow* map=Application::getSingletonPtr()->getMiniMap()->getMap();
	mEventNavigateMiniMap=map->subscribeEvent(CEGUI::DefaultWindow::EventMouseClick, CEGUI::Event::Subscriber(&GameDesignFrame::onClicked_NavigateMiniMap, this));
}

void GameDesignFrame::unsubscribeEvents()
{
	mEventClimate->disconnect();
	mEventTrainAgent->disconnect();
	mEventUploadConfig->disconnect();
	mEventModelSelected->disconnect();

	mEventScriptDeleted.disconnect();
	mEventScriptsRefreshed.disconnect();

	mEventStartSimulation->disconnect();
	mEventStopSimulation->disconnect();
	mEventShowAgents->disconnect();
	mEventRemoveAgents->disconnect();

	mEventNavigateMiniMap->disconnect();
}

AppFrame::AppFrameState GameDesignFrame::getFrameState() const
{
	if(!mGameDesignWidget->isVisible())
	{
		return UNKNOWN;
	}

	if(mGameDesignWidget->isSelecting())
	{
		return SELECT;
	}
	else if(mGameDesignWidget->isCreating())
	{
		return CREATE;
	}
	else if(mGameDesignWidget->isSimulating())
	{
		return SIMULATE;
	}

	return UNKNOWN;
}

GameDesignFrame::~GameDesignFrame()
{
	if(mGameDesignWidget != NULL)
	{
		delete mGameDesignWidget; 
		mGameDesignWidget=NULL;
	}

	if(mWeatherDlg != NULL)
	{
		delete mWeatherDlg;
		mWeatherDlg=NULL;
	}

	if(mIDBlock != NULL)
	{
		delete mIDBlock;
		mIDBlock=NULL;
	}

	if(mUserBotActionWidget != NULL)
	{
		delete mUserBotActionWidget;
		mUserBotActionWidget=NULL;
	}

	if(mBotScriptWidget != NULL)
	{
		delete mBotScriptWidget;
		mBotScriptWidget=NULL;
	}

	if(mGameSimulationControlBox != NULL)
	{
		delete mGameSimulationControlBox;
		mGameSimulationControlBox=NULL;
	}
}

bool GameDesignFrame::frameExited()
{
	mBoard->hide();
	mGameDesignWidget->hide();
	mBotScriptWidget->hide();
	mIDBlock->hide();
	mGameSimulationControlBox->hide();
	mUserBotActionWidget->hide();
	
	mApp->getStatusBar()->removeChildWindow(mCmdClimate);

	WeaponManager::getSingletonPtr()->closeStarGate();
	WeaponManager::getSingletonPtr()->closeDeathBlast();
	mWebBrowser->unbind("InvokeAgent");

	backupAgents();

	return AppFrame::frameExited();
}

void GameDesignFrame::restoreAgents()
{
	CIGameAgent::SetIterator agiter=mAgentPool.begin();
	CIGameAgent::SetIterator agiter_end=mAgentPool.end();
	for(; agiter != agiter_end; ++agiter)
	{
		(*agiter)->show();
		(*agiter)->setPosition((*agiter)->getPosition());
	}
	if(mCurrentCIAgent != NULL)
	{
		mCurrentCIAgent->activate();
	}
}

void GameDesignFrame::backupAgents()
{
	if(mCurrentCIAgent != NULL)
	{
		mCurrentCIAgent->deactivate();
	}

	CIGameAgent::SetIterator agiter=mAgentPool.begin();
	CIGameAgent::SetIterator agiter_end=mAgentPool.end();
	for(; agiter != agiter_end; ++agiter)
	{
		(*agiter)->hide();
	}
}

bool GameDesignFrame::frameEntered()
{
	if(!AppFrame::frameEntered())
	{
		return false;
	}

	mBoard->show();
	mGameDesignWidget->show();
	mBotScriptWidget->show();
	mApp->getStatusBar()->addChildWindow(mCmdClimate);

	mWebBrowser->bind("InvokeAgent", NaviLibrary::NaviDelegate(this, &GameDesignFrame::onBrowserJSEventCallback));
	mWebBrowser->navigateTo("gameboard");

	restoreAgents();

	return true;
}

void GameDesignFrame::unload()
{
	this->removeAllAgents();
}

bool GameDesignFrame::frameStarted(const Ogre::FrameEvent &evt)
{
	Real dt=evt.timeSinceLastFrame;
	if(!AppFrame::frameStarted(evt))
	{
		return false;
	}

	CIAgent* agent=NULL;
	CIGameAgent::SetIterator giter=mAgentPool.begin();
	CIGameAgent::SetIterator giter_end=mAgentPool.end();
	for(; giter != giter_end; ++giter)
	{
		agent=*giter;
		if(agent->isDead())
		{
			continue;
		}
		else if(agent->isDying())
		{
			agent->run("act: die", evt.timeSinceLastFrame);
			continue;
		}
		if(agent != mCurrentCIAgent)
		{
			if(inFrameState(SIMULATE))
			{
				if(mUserBotActionWidget->isVisible())
				{
					if(mUserBotActionWidget->inCaptureState(CAPTURE_STATE_ACTIVE))
					{
						agent->run("act: script", evt.timeSinceLastFrame);
					}
					else
					{
						agent->run("act: idle", evt.timeSinceLastFrame);
					}
				}
				else 
				{
					if(mGameSimulationControlBox->inSimulation())
					{
						agent->run("act: script", evt.timeSinceLastFrame);
					}
					else
					{
						agent->run("act: idle", evt.timeSinceLastFrame);
					}
				}
			}
			else
			{
				agent->run("act: idle", evt.timeSinceLastFrame);
			}
		}
		else
		{
			if(inFrameState(SIMULATE))
			{
				if(mCurrentCIAgent->isUserBot())
				{
					if(mUserBotActionWidget->inCaptureState(CAPTURE_STATE_ACTIVE))
					{
						//mCurrentCIAgent->registerTargetType(mUserBotActionWidget->getEnemyChoice());
						mCurrentCIAgent->registerAction(mUserBotActionWidget->getActionState());
						mCurrentCIAgent->run("act: capture", evt.timeSinceLastFrame);
					}
					else
					{
						mCurrentCIAgent->run("act: idle", evt.timeSinceLastFrame);
					}
				}
				else
				{
					if(mGameSimulationControlBox->inSimulation())
					{
						agent->run("act: script", evt.timeSinceLastFrame);
					}
					else
					{
						agent->run("act: idle", evt.timeSinceLastFrame);
					}
				}
			}
			else
			{
				mCurrentCIAgent->run("act: idle", evt.timeSinceLastFrame);
			}
		}
	}

	StaticAgentManager::getSingletonPtr()->frameStarted(evt);

	FrameManager::getSingletonPtr()->updateCamera(evt.timeSinceLastFrame);

	if(mCurrentCIAgent != NULL && inFrameState(SIMULATE) && mCurrentCIAgent->isUserBot())
	{
		FrameManager::getSingletonPtr()->setCameraPOI(mCurrentCIAgent->getPosition());
	}

	updateBoard();

	mScoreboardTimer+=dt;

	updateGameSimulationControlBox(dt);
	if(mScoreboardTimer >= mScoreboardRecordInterval)
	{
		updateScoreBoard(mScoreboardTimer);
		recordScoreboardDoc(mScoreboardTimer);
		mScoreboardTimer=0;
	}
	uploadScoreBoard(dt);
	mUserBotActionWidget->update(dt);
	
	WeaponManager::getSingletonPtr()->monitorStarGate(dt);

	if(mIDBlock->isVisible())
	{
		if(mCurrentCIAgent != NULL)
		{
			mIDBlock->setBlockIDEntity(mCurrentCIAgent->getAgentName());
			mIDBlock->setBlockIDTag(mCurrentCIAgent->getTag());
			mIDBlock->setBlockIDScript(mCurrentCIAgent->getScriptId());
			mIDBlock->setBlockIDLife(static_cast<float>(mCurrentCIAgent->getLife()) / mCurrentCIAgent->getMaxLife());
			mIDBlock->setBlockIDAction(mCurrentCIAgent->stateToString(mCurrentCIAgent->getRegisteredAction()));

			Gun* gun=mCurrentCIAgent->getGun();
			mIDBlock->setBlockIDWeaponGrade(static_cast<float>(gun->getBulletCount()) / gun->getMaxBulletCount());

			if(mCurrentCIAgent->isUserBot() || inFrameState(SIMULATE))
			{
				mIDBlock->getTrainingButton()->hide();
			}
			else
			{
				mIDBlock->getTrainingButton()->show();
			}

			if(!HTTPManager::getSingletonPtr()->enabled())
			{
				mIDBlock->getUploadConfigButton()->hide();
			}
			else
			{
				mIDBlock->getUploadConfigButton()->show();
			}
		}
		else
		{
			mIDBlock->hide();
		}
	}

	return mContinue;
}

void GameDesignFrame::recordScoreboardDoc(const Real& dt)
{
	size_t agentCount=mAgentPool.size();

	if(agentCount > 0 && inFrameState(SIMULATE))
	{		
		TiXmlElement* xmlSimulation=new TiXmlElement("simulation");
		xmlSimulation->SetAttribute("time", OSEnvironment::getCurrentTime().c_str());
		xmlSimulation->SetDoubleAttribute("elapsed_time", mSimulationTimer);

		CIGameAgent* gagent=NULL;
		CIGameAgent::SetIterator giter=mAgentPool.begin();
		CIGameAgent::SetIterator giter_end=mAgentPool.end();
		CIGameAgentActionState actionId;
		for(; giter != giter_end; ++giter)
		{
			TiXmlElement* xmlAgent=new TiXmlElement("agent");
			gagent=*giter;
			actionId=gagent->getRegisteredAction();
			
			xmlAgent->SetAttribute("name", gagent->getAgentName().c_str());
			xmlAgent->SetAttribute("scriptId", gagent->getScriptId().c_str());
			xmlAgent->SetAttribute("tag", gagent->getTag().c_str());
			xmlAgent->SetAttribute("life", gagent->getLife());
			xmlAgent->SetDoubleAttribute("score", gagent->getScore());
			xmlAgent->SetDoubleAttribute("senseRange", gagent->getSenseRange());
			xmlAgent->SetDoubleAttribute("walkSpeed", gagent->getWalkSpeed());
			xmlAgent->SetDoubleAttribute("armor", gagent->getArmor());
			
			xmlAgent->SetAttribute("current_target", "null");
			if(gagent->getCurrentTarget() != NULL)
			{
				xmlAgent->SetAttribute("current_target", gagent->getCurrentTarget()->getAgentName().c_str());
			}
			
			xmlAgent->SetAttribute("action_id", actionId);
			xmlAgent->SetAttribute("action", CIGameAgent::stateToString(actionId).c_str());

			xmlAgent->SetAttribute("cheating", "false");
			xmlAgent->SetAttribute("cheat_reason", "");

			if(gagent->getLife() > mScoreboardCriteria_life)
			{
				xmlAgent->SetAttribute("cheating", "true");
				xmlAgent->SetAttribute("cheat_reason", "life");
			}
			else if(gagent->getGun()->getBulletCount() > mScoreboardCriteria_bulletCount)
			{
				xmlAgent->SetAttribute("cheating", "true");
				xmlAgent->SetAttribute("cheat_reaon", "bulletCount");
			}
			else if(gagent->getArmor() > mScoreboardCriteria_armor)
			{
				xmlAgent->SetAttribute("cheating", "true");
				xmlAgent->SetAttribute("cheat_reason", "armor");
			}
			else if(gagent->getWalkSpeed() > mScoreboardCriteria_walkSpeed)
			{
				xmlAgent->SetAttribute("cheating", "true");
				xmlAgent->SetAttribute("cheat_reason", "walkSpeed");
			}
			else if(gagent->getSenseRange() > mScoreboardCriteria_senseRange)
			{
				xmlAgent->SetAttribute("cheating", "true");
				xmlAgent->SetAttribute("cheat_reason", "senseRange");
			}
			xmlSimulation->LinkEndChild(xmlAgent);
		}
		mScoreboardDoc->RootElement()->LinkEndChild(xmlSimulation);
		mScoreboardDocSaved=false;
	}
}

void GameDesignFrame::updateBoard()
{
	CIAgentManager::CIAgentList& agents=CIAgentManager::getSingletonPtr()->getCIAgents();
	std::ostringstream oss;
	oss << "\n>>\nAgent Count: " << agents.size();
	if(mCurrentCIAgent != NULL)
	{
		oss << "\n>>\nCurrent Agent: \n";
		oss << mCurrentCIAgent->toString();
	}
	mBoard->setText(oss.str());
}

bool GameDesignFrame::keyPressed(const OIS::KeyEvent& evt)
{
	if(!AppFrame::keyPressed(evt))
	{
		if( !mGUIMgr->getModalState())
		{
			switch(evt.key)
			{
			case OIS::KC_DELETE:
				if(mCurrentCIAgent != NULL && (!inFrameState(SIMULATE)))
				{
					mCurrentCIAgent->deactivate();
					removeAgent(mCurrentCIAgent);
					mCurrentCIAgent=NULL;
				}
				break;
			default:
				break;
			}
		}
	}

	return true;
}

bool GameDesignFrame::mouseMoved(const OIS::MouseEvent& evt)
{
	if(!AppFrame::mouseMoved(evt))
	{
		if(mLeftButtonDown && inFrameState(SELECT) && mCurrentCIAgent != NULL)
		{
			mCurrentCIAgent->setPosition(mMousePicker.getTerrainIntersection(evt));
			if(mIDBlock->isVisible())
			{
				mIDBlock->setPosition((float)(evt.state.X.abs+1) / evt.state.width, (float)(evt.state.Y.abs+1) / evt.state.height);
			}
		}
		
		if(mRightButtonDown)
		{
			FrameManager::getSingletonPtr()->onRightMouseDrag(evt.state.X.rel, evt.state.Y.rel);
		}
	}

	return true;
}

void GameDesignFrame::updateUI()
{
	AppFrameState currState=getFrameState();
	AppFrameState prevState=getPrevFrameState();


	if(inFrameState(SIMULATE))
	{
		if(mCurrentCIAgent != NULL && mCurrentCIAgent->isUserBot())
		{
			if(!mUserBotActionWidget->isVisible())
			{
				mUserBotActionWidget->show();
				mGameSimulationControlBox->hide();
			}
		}
		else
		{
			if(!mGameSimulationControlBox->isVisible())
			{
				mUserBotActionWidget->hide();
				mGameSimulationControlBox->show();
			}
		}
	}
}

bool GameDesignFrame::onStateChanged(AppFrameState prevState, AppFrameState currState)
{
	switch(prevState)
	{
	case CREATE:
		mBotScriptWidget->hide();
		break;
	case SIMULATE:
		if(mUserBotActionWidget->isVisible())
		{
			mUserBotActionWidget->hide();
		}
		if(mGameSimulationControlBox->isVisible())
		{
			mGameSimulationControlBox->hide();
		}
		break;
	default:
		break;
	}

	switch(currState)
	{
	case CREATE:
		mBotScriptWidget->show();
		break;
	case SIMULATE:
		if(mCurrentCIAgent != NULL && mCurrentCIAgent->isUserBot())
		{
			mUserBotActionWidget->show();
		}
		else
		{
			mGameSimulationControlBox->show();
			mGameSimulationControlBox->inSimulation(false);
		}
		break;
	default:
		break;
	}

	return true;
}

CIGameAgent* GameDesignFrame::createScriptedGameAgent(const Vector3& pos)
{
	CIGameAgent* agent=CIAgentManager::getSingletonPtr()->createGameAgent(pos, mBotScriptWidget->getScriptId());
	agent->setTag(mBotScriptWidget->getTag());
	mAgentPool.insert(agent);

	if(agent->isUserBot())
	{
		mUserBotActionWidget->setUserBot(agent);
	}

	return agent;
}

CIGameAgent* GameDesignFrame::createScriptedGameAgent(const std::string& scriptId, const Vector3& pos)
{
	CIGameAgent* agent=CIAgentManager::getSingletonPtr()->createGameAgent(pos, scriptId);
	mAgentPool.insert(agent);

	if(agent->isUserBot())
	{
		mUserBotActionWidget->setUserBot(agent);
	}

	return agent;
}

CIGameAgent* GameDesignFrame::createScriptedGameAgent(const std::string& scriptId, const Vector3& pos, Ogre::ColourValue& c)
{
	CIGameAgent* agent=CIAgentManager::getSingletonPtr()->createGameAgent(pos, scriptId, c);
	mAgentPool.insert(agent);

	if(agent->isUserBot())
	{
		mUserBotActionWidget->setUserBot(agent);
	}

	return agent;
}


bool GameDesignFrame::mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
{
	if(!AppFrame::mousePressed(evt, id))
	{
		if(mGUIMgr->hasFocus())
		{
			return true;
		}

		if(mLeftButtonDown)
		{
			unselectAgents();

			if(inFrameState(SELECT) || inFrameState(SIMULATE))
			{
				MovableObject* mo=mMousePicker.pick(evt);
				selectAgent(mo);
			}
			else if(inFrameState(CREATE))
			{
				if(mBotScriptWidget->hasScripts()==false)
				{
					mGUIMgr->showMsgBox("Failed to create game agents", "Failed to create game agents as no game scripts found!");
				}
				else
				{
					mCurrentCIAgent=createScriptedGameAgent(mMousePicker.getTerrainIntersection(evt));
					mCurrentCIAgent->activate();
				}
			}
		}
		else if(mRightButtonDown)
		{
			CIGameAgent* prevSelected=mCurrentCIAgent;

			unselectAgents();

			MovableObject* mo=mMousePicker.pick(evt);
			selectAgent(mo);

			if(mCurrentCIAgent != NULL)
			{
				if(prevSelected==mCurrentCIAgent)
				{
					if(mIDBlock->isVisible())
					{
						mIDBlock->hide();
					}
					else
					{
						mIDBlock->show();
					}
				}
				else
				{
					mIDBlock->show();
				}
			}
		}

		this->updateUI();

		if(mIDBlock->isVisible())
		{
			mIDBlock->setPosition((float)(evt.state.X.abs+1) / evt.state.width, (float)(evt.state.Y.abs+1) / evt.state.height);
		}
	}

	return true;
}

bool GameDesignFrame::onClicked_Climate(const CEGUI::EventArgs& evt)
{
	mWeatherDlg->showModal();
	return true;
}

bool GameDesignFrame::onClicked_TrainAgent(const CEGUI::EventArgs& evt)
{
	if(mCurrentCIAgent != NULL)
	{
		mCurrentCIAgent->train();
	}
	return true;
}

void GameDesignFrame::doNewSimulation()
{
	mSimulationTimer=0;
	this->createScoreboardDoc();

	if(mGameSimulationControlBox->isSoundEnabled())
	{
		SoundManager::getSingletonPtr()->enable();
	}
	else
	{
		SoundManager::getSingletonPtr()->disable();
	}

	if(mGameSimulationControlBox->isExpertMode())
	{
		if(mGameSimulationControlBox->isAllAgentsRemovedOnStarted())
		{
			this->unselectAgents();

			this->removeAllAgents();
			mAgentPool.clear();
		}

		const std::vector<std::string>& simulationScriptIds=mGameSimulationControlBox->getSimulationScripts();

		TerrainInfoManager* tm=TerrainInfoManager::getSingletonPtr();
		Real minX=mGameSimulationControlBox->getMinX();
		Real maxX=mGameSimulationControlBox->getMaxX();
		Real minZ=mGameSimulationControlBox->getMinZ();
		Real maxZ=mGameSimulationControlBox->getMaxZ();


		size_t count=simulationScriptIds.size();
		bool randomAuraColor=mGameSimulationControlBox->isRandomAuraColorEnabled();
		
		CIGameAgent*  agnt;
		if(mGameSimulationControlBox->isInitializationCellBased())
		{
			std::vector<size_t> orders;
			for(size_t i=0; i != count; ++i)
			{
				orders.push_back(i);
			}
			std::random_shuffle(orders.begin(), orders.end());

			int ci=static_cast<int>(ceil(sqrt(static_cast<float>(count))));
			Real dX=(maxX-minX) / ci;
			Real dZ=(maxZ-minZ) / ci;
			
			for(size_t i=0; i != count; ++i)
			{
				Real x1=minX+dX * i / ci;
				Real z1=minZ+dZ * (i % ci);
				Real x=Math::RangeRandom(x1, x1+dX);
				Real z=Math::RangeRandom(z1, z1+dZ);
				
				if(randomAuraColor)
				{
					agnt=this->createScriptedGameAgent(simulationScriptIds[orders[i]], Vector3(x, tm->getHeight(x, z), z), ColourValue(Math::RangeRandom(0, 1), Math::RangeRandom(0, 1), Math::RangeRandom(0, 1)));
				}
				else
				{
					agnt=this->createScriptedGameAgent(simulationScriptIds[orders[i]], Vector3(x, tm->getHeight(x, z), z));
				}

				if(agnt->isInitialized())
				{
					agnt->initialize();
				}
				agnt->setLife(this->mScoreboardCriteria_life);
				agnt->setArmor(this->mScoreboardCriteria_armor);
				agnt->getGun()->setBulletCount(this->mScoreboardCriteria_bulletCount);
				agnt->setSenseRange(this->mScoreboardCriteria_senseRange);
				agnt->setWalkSpeed(this->mScoreboardCriteria_walkSpeed);

				std::string model_name=this->mGameSimulationControlBox->getGameSimulationOptionDlg()->getSimulationModel();
				if(model_name.compare("") != 0)
				{
					agnt->changeModel(model_name);
				}
			}
		}
		else
		{
			for(size_t i=0; i != count; ++i)
			{
				Real x=Math::RangeRandom(minX, maxX);
				Real z=Math::RangeRandom(minZ, maxZ);
				
				if(randomAuraColor)
				{
					agnt=this->createScriptedGameAgent(simulationScriptIds[i], Vector3(x, tm->getHeight(x, z), z), ColourValue(Math::RangeRandom(0, 1), Math::RangeRandom(0, 1), Math::RangeRandom(0, 1)));
				}
				else
				{
					agnt=this->createScriptedGameAgent(simulationScriptIds[i], Vector3(x, tm->getHeight(x, z), z));
				}

				std::string model_name=this->mGameSimulationControlBox->getGameSimulationOptionDlg()->getSimulationModel();
				if(model_name.compare("") != 0)
				{
					agnt->changeModel(model_name);
				}
			}
		}

		Real cX=(maxX+minX) / 2;
		Real cZ=(maxZ+minZ) / 2;
		Real cY=0; //tm->getHeight(cX, cZ);

		FrameManager::getSingletonPtr()->setCameraPOI(Vector3(cX, cY, cZ));
	}

	mGameSimulationControlBox->inSimulation(true);
}

void GameDesignFrame::updateGameSimulationControlBox(const Real& dt)
{
	size_t agentCount=mAgentPool.size();
	CIGameAgent::Set::iterator giter=mAgentPool.begin();
	CIGameAgent::Set::iterator gend=mAgentPool.end();

	int lives=0;
	for(;giter != gend; ++giter)
	{
		if((*giter)->isAlive())
		{
			lives++;
		}
	}
	

	if(agentCount > 0 && inFrameState(SIMULATE))
	{
		mSimulationTimer+=dt;
		if(mScoreboardDocSaved==true)
		{
			mSimulationTimer=0;
		}

		if(mGameSimulationControlBox->isVisible() && mGameSimulationControlBox->inSimulation())
		{
			if(mGameSimulationControlBox->isTerminationOnSecondsReached())
			{
				if(mSimulationTimer >= mGameSimulationControlBox->getSecondsOnTermination())
				{
					mGameSimulationControlBox->inSimulation(false);
					this->saveScoreboardDoc();
				}
			}
			if(mGameSimulationControlBox->isTerminationOnLivesRemained())
			{
				if(lives <= mGameSimulationControlBox->getLivesRemainedOnTermination())
				{
					mGameSimulationControlBox->inSimulation(false);
					this->saveScoreboardDoc();
				}
			}

			if(!mGameSimulationControlBox->inSimulation() && mGameSimulationControlBox->isExpertMode())
			{
				mGameSimulationControlBox->decrementSimulationCount();

				if(mGameSimulationControlBox->getSimulationCount() > 0)
				{
					doNewSimulation();
				}
			}

			if(mGameSimulationControlBox->inSimulation())
			{
				std::ostringstream oss_st;
				if(mGameSimulationControlBox->isExpertMode())
				{
					oss_st << "#" << mGameSimulationControlBox->getSimulationCount() << " (" << mSimulationTimer << " sec,\t " << lives << " alive) ";	
				}
				else
				{
					oss_st << mSimulationTimer << " sec, \t" << lives << " alive)";
				}

				mGameSimulationControlBox->setCaptionDetail(oss_st.str());
			}
		}
		
	}
}

bool GameDesignFrame::onClicked_StartSimulation(const CEGUI::EventArgs& evt)
{
	mGameSimulationControlBox->resetSimulationCount();

	doNewSimulation();

	return true;
}

bool GameDesignFrame::onClicked_RemoveAgents(const CEGUI::EventArgs& evt)
{
	removeAllAgents();
	return true;
}

bool GameDesignFrame::onClicked_ShowAgents(const CEGUI::EventArgs& evt)
{
	mGameSimulationControlBox->inSimulation(false);
	
	this->unselectAgents();

	removeAllAgents();

	const std::vector<std::string>& simulationScriptIds=mGameSimulationControlBox->getSimulationScripts();

	TerrainInfoManager* tm=TerrainInfoManager::getSingletonPtr();
	Real minX=mGameSimulationControlBox->getMinX();
	Real maxX=mGameSimulationControlBox->getMaxX();
	Real minZ=mGameSimulationControlBox->getMinZ();
	Real maxZ=mGameSimulationControlBox->getMaxZ();

	CIGameAgent* agnt=NULL;

	size_t count=simulationScriptIds.size();
	if(mGameSimulationControlBox->isInitializationCellBased())
	{
		int ci=static_cast<int>(ceil(sqrt(static_cast<float>(count))));
		Real dX=(maxX-minX) / ci;
		Real dZ=(maxZ-minZ) / ci;
		for(size_t i=0; i != count; ++i)
		{
			Real x1=minX+dX * i / ci;
			Real z1=minZ+dZ * (i % ci);
			Real x=Math::RangeRandom(x1, x1+dX);
			Real z=Math::RangeRandom(z1, z1+dZ);
			agnt=this->createScriptedGameAgent(simulationScriptIds[i], Vector3(x, tm->getHeight(x, z), z));
			std::string model_name=this->mGameSimulationControlBox->getGameSimulationOptionDlg()->getSimulationModel();
			if(model_name.compare("") != 0)
			{
				agnt->changeModel(model_name);
			}
		}
	}
	else
	{
		for(size_t i=0; i != count; ++i)
		{
			Real x=Math::RangeRandom(minX, maxX);
			Real z=Math::RangeRandom(minZ, maxZ);
			agnt=this->createScriptedGameAgent(simulationScriptIds[i], Vector3(x, tm->getHeight(x, z), z));
			std::string model_name=this->mGameSimulationControlBox->getGameSimulationOptionDlg()->getSimulationModel();
			if(model_name.compare("") != 0)
			{
				agnt->changeModel(model_name);
			}
		}
	}

	Real cX=(maxX+minX) / 2;
	Real cZ=(maxZ+minZ) / 2;
	Real cY=0; //tm->getHeight(cX, cZ);

	FrameManager::getSingletonPtr()->setCameraPOI(Vector3(cX, cY, cZ));

	return true;
}
	
bool GameDesignFrame::onClicked_StopSimulation(const CEGUI::EventArgs& evt)
{
	this->saveScoreboardDoc();

	mGameSimulationControlBox->inSimulation(false);
	return true;
}

bool GameDesignFrame::onClicked_UploadConfig(const CEGUI::EventArgs& evt)
{
	if(mCurrentCIAgent != NULL)
	{
		if(HTTPManager::getSingletonPtr()->enabled())
		{
			HTTPManager::getSingletonPtr()->clearBuffer();
			HTTPManager::getSingletonPtr()->add2Buffer("username", Application::getSingletonPtr()->getWebConnectLogin()->getUsername());
			HTTPManager::getSingletonPtr()->add2Buffer("scriptId", mCurrentCIAgent->getScriptId());
			mCurrentCIAgent->uploadConfig();
			std::string result;
			HTTPManager::getSingletonPtr()->postBuffer("config", result);
			if(result.compare("POST SUCCESSFUL")==0)
			{
				mGUIMgr->showMsgBox("Configuration Posted", result);
			}
			else
			{
				mGUIMgr->showMsgBox("Configuration Question", result);
			}
		}
		else
		{
			mGUIMgr->showMsgBox("No Web Connection available", "Please login to the web before attempting to uploading your configuration");
		}
		
	}
	return true;
}

void GameDesignFrame::uploadScoreBoard(Real dt)
{
	static Real UpdateCounter=0;
	UpdateCounter += dt;

	HTTPManager* httpManager = HTTPManager::getSingletonPtr();
	CURLEasyHandler* handler=httpManager->getHandler("scoreboard");

	if(UpdateCounter > handler->get_min_interval_in_seconds())
	{
		UpdateCounter=0;
	}
	else
	{
		return;
	}

	if(inFrameState(SIMULATE))
	{
		if(httpManager->enabled())
		{
			CIGameAgent* gagent=NULL;
			std::string milliSecond;
			std::string dateTime = OSEnvironment::createSQLDateTimeString(milliSecond);
			LogManager::getSingletonPtr()->getDefaultLog()->logMessage(OSEnvironment::append("DateTimeH: ", dateTime).c_str());
			CIGameAgent::SetIterator giter=mAgentPool.begin();
			CIGameAgent::SetIterator giter_end=mAgentPool.end();
			for(; giter != giter_end; ++giter)
			{
				std::map<std::string, std::string> msg;
				gagent=*giter;
				msg["username"]=Application::getSingletonPtr()->getWebConnectLogin()->getUsername();
				msg["AgentId"]=gagent->getAgentName().c_str();
				msg["AgentLife"]=OSEnvironment::toString(gagent->getLife());
				msg["AgentScore"]=OSEnvironment::toString(gagent->getScore());
				CIGameAgent* target=gagent->getCurrentTarget();
				if(target==NULL)
				{
					msg["AgentEnemy"]="";
				}
				else
				{
					msg["AgentEnemy"]=target->getAgentName().c_str();
				}
				msg["AgentState"]=gagent->stateToString(gagent->getRegisteredAction());
				msg["AgentScriptId"]=gagent->getScriptId();
				msg["AgentTag"]=gagent->getTag();
				msg["AgentDateTime"]=dateTime;
				msg["AgentMilliSecond"]=milliSecond;
				std::string result;
				if(httpManager->post("scoreboard", msg, result))
				{
					if(result.compare("POST SUCCESSFUL")!=0)
					{
						std::ostringstream oss;
						oss << "Web disconnected due to failure in posting data\n";
						oss << "Error: " << result << "\n";
						oss << "Please reactivate web connect and try again";
						mGUIMgr->showMsgBox("Failed to web post data",  oss.str().c_str());
						httpManager->enable(false);
					}
				}
				if(!httpManager->enabled())
				{
					break;
				}
			}
		}
	}
}

void GameDesignFrame::updateScoreBoard(Real dt)
{	
	WebBrowser* browser=mWebBrowser;
	NaviLibrary::Navi* browserNavi=browser->getBrowserWindow();

	if(browserNavi->getVisibility() && browser->isLoaded("gameboard"))
	{
		std::ostringstream oss;
		size_t agentCount=mAgentPool.size();

		if(agentCount > 0)
		{
			if(mGameSimulationControlBox->isVisible() && mGameSimulationControlBox->inSimulation())
			{
				oss << "Simulation Time: " << mSimulationTimer << "<br />";
			}
			if(inFrameState(SIMULATE) && (mCurrentCIAgent !=NULL && mCurrentCIAgent->isUserBot()))
			{
				oss << "User-controlled Agent: " << mCurrentCIAgent->getAgentName() << "<br />";
				oss << GameAgentRecorder::getGameAgentHTMLTable(mCurrentCIAgent);
				oss << "<hr />";

				CIGameAgent* target=mCurrentCIAgent->getCandidateTarget_Closest();
				if(target != NULL)
				{
					oss << "Closet Enemy: ";
					if(mCurrentCIAgent->isAttackable(target))
					{
						oss << "[attackable]";
					}
					if(target->isAttacking(mCurrentCIAgent))
					{
						oss << "{attacking me}";
					}
					oss << "<br />";
					oss << GameAgentRecorder::getGameAgentHTMLTable(target);
					oss << "<hr />";
				}

				target=mCurrentCIAgent->getCandidateTarget_Strongest();
				if(target != NULL)
				{
					oss << "Strongest Enemy: ";
					if(mCurrentCIAgent->isAttackable(target))
					{
						oss << "[attackable]";
					}
					if(target->isAttacking(mCurrentCIAgent))
					{
						oss << "{attacking me}";
					}
					oss << "<br />";
					oss << GameAgentRecorder::getGameAgentHTMLTable(target);
					oss << "<hr />";
				}

				target=mCurrentCIAgent->getCandidateTarget_Weakest();
				if(target != NULL)
				{
					oss << "Weakest Enemy: ";
					if(mCurrentCIAgent->isAttackable(target))
					{
						oss << "[attackable]";
					}
					if(target->isAttacking(mCurrentCIAgent))
					{
						oss << "{attacking me}";
					}
					oss << "<br />";
					oss << GameAgentRecorder::getGameAgentHTMLTable(target);
					oss << "<hr />";
				}

				target=mCurrentCIAgent->getCandidateTarget_Attacker();
				if(target != NULL)
				{
					oss << "Attacker Enemy: ";
					if(mCurrentCIAgent->isAttackable(target))
					{
						oss << "[attackable]";
					}
					if(target->isAttacking(mCurrentCIAgent))
					{
						oss << "{attacking me}";
					}
					oss << "<br />";
					oss << GameAgentRecorder::getGameAgentHTMLTable(target);
					oss << "<hr />";
				}
			}
			else
			{
				oss << "<table style=\"color:#00FF00; background-color: #000000; \">";
				oss << "<tr><td>Entity</td><td>ScriptId</td><td>Tag</td><td>Life</td><td>Score</td><td>Enemy</td><td>State</td><td>comments</td></tr>";
				CIGameAgent* gagent=NULL;
				CIGameAgentActionState actionId;
				CIGameAgent::SetIterator giter=mAgentPool.begin();
				CIGameAgent::SetIterator giter_end=mAgentPool.end();
				for(; giter != giter_end; ++giter)
				{
					gagent=*giter;
					actionId=gagent->getRegisteredAction();
					oss << "<tr>";
					oss << "<td>";
					oss << gagent->getAgentName();
					oss << "</td>";
					oss << "<td>";
					oss << ScriptManager::getSingletonPtr()->getNickname(gagent->getScriptId());
					oss << "</td>";
					oss << "<td>";
					oss << gagent->getTag();
					oss << "</td>";
					oss << "<td>";
					oss << gagent->getLife();
					oss << "</td>";
					oss << "<td>";
					oss << gagent->getScore();
					oss << "</td>";
					oss << "<td>";
					if(gagent->getCurrentTarget() != NULL)
					{
						oss << gagent->getCurrentTarget()->getAgentName();
					}
					oss << "</td>";
					oss << "<td>";
					oss << actionId << ": " << CIGameAgent::stateToString(actionId);
					oss << "</td>";

					if(gagent->getLife() > mScoreboardCriteria_life)
					{
						oss << "<td>cheating: life</td>";
					}
					else if(gagent->getGun()->getBulletCount() > mScoreboardCriteria_bulletCount)
					{
						oss << "<td>cheating: bulletCount</td>";
					}
					else if(gagent->getArmor() > mScoreboardCriteria_armor)
					{
						oss << "<td>cheating: armor</td>";
					}
					else if(gagent->getWalkSpeed() > mScoreboardCriteria_walkSpeed)
					{
						oss << "<td>cheating: walkSpeed</td>";
					}
					else if(gagent->getSenseRange() > mScoreboardCriteria_senseRange)
					{
						oss << "<td>cheating: senseRange</td>";
					}
					else
					{
						oss << "<td></td>";
					}
					oss << "</tr>";
				}
				oss << "</table>";
			}
		}

		oss << "Game Agents : " << agentCount << "<br />";

		std::string scoreHTML=oss.str();
		mWebBrowser->getBrowserWindow()->evaluateJS("$('divScoreBoard').setHTML('?')", NaviLibrary::NaviUtilities::Args(scoreHTML));
	}
}

void GameDesignFrame::onBrowserJSEventCallback(const NaviLibrary::NaviData& data)
{
	if(data.exists("command"))
	{
		std::string command=data["command"].str();
		if(command.compare("Load Score")==0)
		{
			updateScoreBoard(10);
		}
		else if(command.compare("Close Browser")==0)
		{
			mWebBrowser->hide();
		}
	}
}

void GameDesignFrame::onScriptDeleted()
{
	filterInvalidAgents();
}

void GameDesignFrame::onScriptsRefreshed()
{
	filterInvalidAgents();
}

bool GameDesignFrame::onSelected_Model(const CEGUI::EventArgs& evt)
{
	if(this->mCurrentCIAgent != NULL)
	{
		mCurrentCIAgent->changeModel(mIDBlock->getModelDlg()->getSelectedModel());
	}
	return true;
}

void GameDesignFrame::filterInvalidAgents()
{
	CIGameAgent* agent=NULL;
	CIGameAgent::Set deletedAgents;
	CIGameAgent::SetIterator aiter=mAgentPool.begin();
	CIGameAgent::SetIterator aiter_end=mAgentPool.end();
	for(; aiter != aiter_end; ++aiter)
	{
		agent=*aiter;
		if(!agent->hasValidScript())
		{
			if(agent==mCurrentCIAgent)
			{
				agent->deactivate();
				mCurrentCIAgent=NULL;
			}
			deletedAgents.insert(agent); 
		}
	}

	aiter=deletedAgents.begin();
	aiter_end=deletedAgents.end();
	for(; aiter != aiter_end; ++aiter)
	{
		removeAgent(*aiter);
	}
}
