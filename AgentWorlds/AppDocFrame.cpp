#include "AppDocFrame.h"
#include "../GameEngine/Application.h"
#include "../OSEnvironment/OSEnvironment.h"
#include "../CIAgents/CIAgentManager.h"

AppDocFrame::AppDocFrame(Application* app, std::string frameName)
: AppFrame(app, frameName)
, mWebBrowser(mApp->getBrowser())
{
	mCodeDesignWidget=new CICodeDesignWidget(getUIId("CIForm"));
	
	mCodeGenDlg=new CodeGenDlg(getUIId("CodeGenDlg"));

	if(mGUIMgr->isOverlayPresent(getUIId("Overlay/CIData")))
	{
		mBoard=mGUIMgr->getOverlay(getUIId("Overlay/CIData"));
	}
	else
	{
		mBoard=mGUIMgr->createOverlay(getUIId("Overlay/CIData"));
		mBoard->setText("");
		mBoard->setTitle("Message Board");
		mBoard->setAlpha(0.5f);
		mBoard->setPosition(0.75f, 0.59f);
		mBoard->setSize(0.25f, 0.2f);
	}

	setupCommands();

	mMouseDrag.setCamera(mApp->getCamera());
	mMousePicker.setCamera(mApp->getCamera());

	mCodeDesignWidget->hide();
	mBoard->hide();
	mCodeGenDlg->hide();
}

void AppDocFrame::unload()
{
	removeAllAgents();
}

void AppDocFrame::onBrowserJSEventCallback(const NaviLibrary::NaviData& data)
{
	if(data.exists("command"))
	{
		std::string command=data["command"].str();
		if(command.compare("Config CI")==0)
		{
			mWebBrowser->hide();
			if(mCurrentCIAgents.empty())
			{
				mGUIMgr->showMsgBox("No Agent Selected", "Please select an agent first!");
			}
			else
			{
				CICodeAgent::SetIterator aiter=mCurrentCIAgents.begin();
				CICodeAgent::SetIterator aiter_end=mCurrentCIAgents.end();
				for(; aiter != aiter_end; ++aiter)
				{
					(*aiter)->run("act: config");
				}
			}
		}
		else if(command.compare("Generate Code")==0)
		{
			mWebBrowser->hide();
			if(mCurrentCIAgents.empty())
			{
				mGUIMgr->showMsgBox("No Agent Selected", "Please select an agent first!");
			}
			else
			{
				CICodeAgent::SetIterator aiter=mCurrentCIAgents.begin();
				CICodeAgent::SetIterator aiter_end=mCurrentCIAgents.end();
				mCodeGenDlg->clearAgents();
				for(; aiter != aiter_end; ++aiter)
				{
					mCodeGenDlg->addAgent(*aiter);
				}
				mCodeGenDlg->showWindow();
			}
		}
		else if(command.compare("Close Browser")==0)
		{
			mWebBrowser->hide();
		}
	}
}

void AppDocFrame::setupCommands()
{
	CEGUI::String strConfig= getUIId("CIConfig");
	CEGUI::String strGenerate=getUIId("btnGenerate");

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();
	CEGUI::Menubar* statusBar=mApp->getStatusBar();
	if(wm->isWindowPresent(strConfig))
	{
		mCmdConfig=static_cast<CEGUI::MenuItem*>(wm->getWindow(strConfig));
	}
	else
	{
		mCmdConfig=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), strConfig));
		mCmdConfig->setText((CEGUI::utf8*)" Configure ");
	}

	if(wm->isWindowPresent(strGenerate))
	{
		mCmdGenerate=static_cast<CEGUI::MenuItem*>(wm->getWindow(strGenerate));
	}
	else
	{
		mCmdGenerate=static_cast<CEGUI::MenuItem*>(wm->createWindow(CIWidget::getGUIType("MenuItem"), strGenerate));
		mCmdGenerate->setText((CEGUI::utf8*)" Generate Code ");
	}
}

bool AppDocFrame::onClicked_ShowPS(const CEGUI::EventArgs& evt)
{
	CICodeAgent::SetIterator aiter=mCurrentCIAgents.begin();
	CICodeAgent::SetIterator aiter_end=mCurrentCIAgents.end();
	for(; aiter != aiter_end; ++aiter)
	{
		(*aiter)->activate(mCodeDesignWidget->isAgentPSVisible());
	}
	return true;
}

void AppDocFrame::open()
{
	std::string filename=OSEnvironment::getWinOpenFileDialog("CDF Files", "cdf");

	if(filename.compare("")==0)
	{
		return;
	}

	removeAllAgents();

	TiXmlDocument doc;
	if(!doc.LoadFile(filename.c_str()))
	{
		mGUIMgr->showMsgBox("Failed to load file", OSEnvironment::append("Failed to load ", filename).c_str());
		return;
	}

	TiXmlElement* xmlRoot=doc.RootElement();

	for(TiXmlElement* xmlLevel1=xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1=xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "agent")==0)
		{
			std::string citype;
			std::string mAgentMgrethod;
			float x, y, z;
			bool active=false;
			TiXmlElement* xmlConfig=NULL;
			if(strcmp(xmlLevel1->Attribute("active"), "true")==0)
			{
				active=true;
			}
			for(TiXmlElement* xmlLevel2=xmlLevel1->FirstChildElement(); xmlLevel2 != NULL; xmlLevel2=xmlLevel2->NextSiblingElement())
			{
				if(strcmp(xmlLevel2->Value(), "position")==0)
				{
					xmlLevel2->QueryFloatAttribute("x", &x);
					xmlLevel2->QueryFloatAttribute("y", &y);
					xmlLevel2->QueryFloatAttribute("z", &z);
				}
				else if(strcmp(xmlLevel2->Value(), "ci")==0)
				{
					citype=xmlLevel2->Attribute("type");
					mAgentMgrethod=xmlLevel2->Attribute("method");
					xmlConfig=xmlLevel2;
				}
			}
			CICodeAgent* agent=CIAgentManager::getSingletonPtr()->createCodeAgent(Vector3(x, y, z), citype, mAgentMgrethod);
			if(xmlConfig != NULL)
			{
				agent->loadConfigXml(xmlConfig);
			}
			if(active)
			{
				agent->activate(mCodeDesignWidget->isAgentPSVisible());
				mCurrentCIAgents.insert(agent);
			}
			mAgentPool.insert(agent);
		}
	}

}
	
void AppDocFrame::save()
{
	std::string filename=OSEnvironment::getWinSaveFileDialog("CDF Files", "cdf"); 

	if(filename.compare("")==0)
	{
		return;
	}

	TiXmlDocument doc;
	doc.LinkEndChild(new TiXmlDeclaration("1.0", "", ""));
	
	TiXmlElement* xmlRoot=new TiXmlElement("cdf");
	doc.LinkEndChild(xmlRoot);

	CICodeAgent::SetIterator aiter=mAgentPool.begin();
	CICodeAgent::SetIterator aiter_end=mAgentPool.end();
	CICodeAgent* agent=NULL;
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
		

		TiXmlElement* xmlPosition=new TiXmlElement("position");
		const Vector3& pos=agent->getPosition();
		xmlPosition->SetDoubleAttribute("x", pos.x);
		xmlPosition->SetDoubleAttribute("y", pos.y);
		xmlPosition->SetDoubleAttribute("z", pos.z);
		TiXmlElement* xmlCI=new TiXmlElement("ci");
		xmlCI->SetAttribute("type", agent->getCIType().c_str());
		xmlCI->SetAttribute("method", agent->getCIMethod().c_str());
		agent->saveConfigXml(xmlCI);

		xmlLevel1->LinkEndChild(xmlPosition);
		xmlLevel1->LinkEndChild(xmlCI);

		xmlRoot->LinkEndChild(xmlLevel1);
	}

	doc.SaveFile(filename.c_str());
}

void AppDocFrame::unselectAgents()
{
	CICodeAgent::SetIterator aiter=mCurrentCIAgents.begin();
	CICodeAgent::SetIterator aiter_end=mCurrentCIAgents.end();
	for(; aiter != aiter_end; ++aiter)
	{
		(*aiter)->deactivate();
	}
	mCurrentCIAgents.clear();
}

void AppDocFrame::removeAgent(CICodeAgent* agent)
{
	if(agent->isActive())
	{
		agent->deactivate();
	}

	CIAgentManager::getSingletonPtr()->removeCIAgent(agent);
	mAgentPool.erase(mAgentPool.find(agent));
}

void AppDocFrame::removeAllAgents()
{
	CICodeAgent::SetIterator iter=mAgentPool.begin();
	CICodeAgent::SetIterator iter_end=mAgentPool.end();
	CICodeAgent* agent=NULL;
	for(; iter != iter_end; ++iter)
	{
		agent=*iter;
		if(agent->isActive())
		{
			agent->deactivate();
		}
		CIAgentManager::getSingletonPtr()->removeCIAgent(agent);
	}
	mAgentPool.clear();
}
	
CICodeAgent* AppDocFrame::getCodeAgent(MovableObject* mo)
{
	CICodeAgent::SetIterator agiter=mAgentPool.begin();
	CICodeAgent::SetIterator agiter_end=mAgentPool.end();
	CICodeAgent* agent=NULL; 
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

void AppDocFrame::selectAgent(MovableObject* mo)
{
	if(mo==NULL)
	{
		return;
	}

	CICodeAgent* agent=getCodeAgent(mo); 
	if(agent != NULL)
	{
		agent->activate(mCodeDesignWidget->isAgentPSVisible());
		mCurrentCIAgents.insert(agent);
	}
}

AppDocFrame::~AppDocFrame()
{
	if(mCodeDesignWidget != NULL)
	{
		delete mCodeDesignWidget;
		mCodeDesignWidget=NULL;
	}

	if(mCodeGenDlg != NULL)
	{
		delete mCodeGenDlg;
		mCodeGenDlg=NULL;
	}

}

bool AppDocFrame::frameExited()
{
	mCodeDesignWidget->hide();
	mBoard->hide();

	CEGUI::Menubar* statusBar=mApp->getStatusBar();
	statusBar->removeChildWindow(mCmdConfig);
	statusBar->removeChildWindow(mCmdGenerate);

	mWebBrowser->unbind("InvokeAgent");

	backupAgents();

	return AppFrame::frameExited();
}

void AppDocFrame::backupAgents()
{
	CICodeAgent::SetIterator agiter=mCurrentCIAgents.begin();
	CICodeAgent::SetIterator agiter_end=mCurrentCIAgents.end();
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

void AppDocFrame::restoreAgents()
{
	CICodeAgent::SetIterator agiter=mAgentPool.begin();
	CICodeAgent::SetIterator agiter_end=mAgentPool.end();
	for(; agiter != agiter_end; ++agiter)
	{
		(*agiter)->show();
		(*agiter)->setPosition((*agiter)->getPosition());
	}

	agiter=mCurrentCIAgents.begin();
	agiter_end=mCurrentCIAgents.end();
	for(; agiter != agiter_end; ++agiter)
	{
		(*agiter)->activate(mCodeDesignWidget->isAgentPSVisible());
	}
}

void AppDocFrame::subscribeEvents()
{
	mEventShowConfig=mCmdConfig->subscribeEvent(CEGUI::MenuItem::EventClicked, CEGUI::Event::Subscriber(&AppDocFrame::onClicked_ConfigCI, this));
	mEventGenerateCode=mCmdGenerate->subscribeEvent(CEGUI::MenuItem::EventClicked, CEGUI::Event::Subscriber(&AppDocFrame::onClicked_GenerateCode, this));
	mEventShowPS=mCodeDesignWidget->getChkShowPS()->subscribeEvent(CEGUI::Checkbox::EventCheckStateChanged, CEGUI::Event::Subscriber(&AppDocFrame::onClicked_ShowPS, this));

	mEventDragClear=mMouseDrag.subscribeEvent_onUnSelect(boost::bind(&AppDocFrame::unselectAgents, this));
	mEventDragSelect=mMouseDrag.subscribeEvent_onSelect(boost::bind(&AppDocFrame::selectAgent, this, _1));
}

void AppDocFrame::unsubscribeEvents()
{
	mEventShowConfig->disconnect();
	mEventGenerateCode->disconnect();
	mEventShowPS->disconnect();

	mEventDragClear.disconnect();
	mEventDragSelect.disconnect();
}

bool AppDocFrame::frameEntered()
{
	if(!AppFrame::frameEntered())
	{
		return false;
	}

	mCodeDesignWidget->show();
	mBoard->show();

	CEGUI::Menubar* statusBar=mApp->getStatusBar();
	statusBar->addChildWindow(mCmdConfig);
	statusBar->addChildWindow(mCmdGenerate);

	mWebBrowser->bind("InvokeAgent", NaviLibrary::NaviDelegate(this, &AppDocFrame::onBrowserJSEventCallback));
	mWebBrowser->navigateTo("default");

	restoreAgents();

	return true;
}

bool AppDocFrame::frameStarted(const FrameEvent& evt)
{
	if(!Application::getSingletonPtr()->getWindow()->isActive())
	{
		return mContinue;
	}

	if(!AppFrame::frameStarted(evt))
	{
		return false;
	}

	CICodeAgent* agent=NULL;
	CICodeAgent::SetIterator giter=mAgentPool.begin();
	CICodeAgent::SetIterator giter_end=mAgentPool.end();
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

	std::ostringstream oss;
	oss << "\n>>\nAgent Count: " << mAgentPool.size();
	oss << "\n>>\nSelected Agent Count: " << mCurrentCIAgents.size();
	if(mCurrentCIAgents.size()==1)
	{
		oss << "\n>>\nCurrent Agent: \n";
		CICodeAgent::ConstSetIterator aiter=mCurrentCIAgents.begin();
		oss << (*aiter)->toString();
	}
	mBoard->setText(oss.str());
	
	return mContinue;
}

bool AppDocFrame::keyPressed(const OIS::KeyEvent& evt)
{
	if(!AppFrame::keyPressed(evt))
	{
		if(!mGUIMgr->getModalState())
		{
			switch(evt.key)
			{
			case OIS::KC_DELETE:
				if(!mCurrentCIAgents.empty())
				{
					CICodeAgent::SetIterator aiter=mCurrentCIAgents.begin();
					CICodeAgent::SetIterator aiter_end=mCurrentCIAgents.end();
					for(; aiter != aiter_end; ++aiter)
					{
						removeAgent(*aiter);
					}
					mCurrentCIAgents.clear();
				}
				break;
			default:
				break;
			}
		}
	}

	return true;
}

AppFrame::AppFrameState AppDocFrame::getFrameState() const
{
	if(mCodeDesignWidget->isSelecting())
	{
		return SELECT;
	}
	else if(mCodeDesignWidget->isCreating())
	{
		return CREATE;
	}
	
	return UNKNOWN;
}

bool AppDocFrame::mouseReleased(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
{
	if(!AppFrame::mouseReleased(evt, id))
	{
		if(mLeftButtonDown == false && inFrameState(SELECT))
		{
			mMouseDrag.dragEnded(evt);
		}
	}
	return true;
}

bool AppDocFrame::mouseMoved(const OIS::MouseEvent& evt)
{
	if(!AppFrame::mouseMoved(evt))
	{
		if(mLeftButtonDown && inFrameState(SELECT))
		{
			if(mCurrentCIAgents.size()==1)
			{
				CICodeAgent::SetIterator aiter=mCurrentCIAgents.begin();
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

CICodeAgent* AppDocFrame::createCodeAgent(const Vector3& pos)
{
	CICodeAgent* agent=CIAgentManager::getSingletonPtr()->createCodeAgent(pos, mCodeDesignWidget->getType(), mCodeDesignWidget->getMethod());
	mAgentPool.insert(agent);
	return agent;
}

void AppDocFrame::updateCodeDesignWidget()
{
	if(inFrameState(SELECT))
	{
		if(mCurrentCIAgents.size()==1)
		{
			CICodeAgent::SetIterator aiter=mCurrentCIAgents.begin();
			CICodeAgent* agent=*aiter;
			mCodeDesignWidget->setMethod(agent->getCIMethod());
			mCodeDesignWidget->setType(agent->getCIType());
		}
	}
}

bool AppDocFrame::mousePressed(const OIS::MouseEvent& evt, OIS::MouseButtonID id)
{
	if(!AppFrame::mousePressed(evt, id))
	{
		if(!mGUIMgr->hasFocus() & mLeftButtonDown)
		{
			unselectAgents();
			if(inFrameState(SELECT))
			{
				MovableObject* mo=mMousePicker.pick(evt);
				selectAgent(mo);

				mMouseDrag.dragStarted(evt);
			}
			else if(inFrameState(CREATE))
			{
				CICodeAgent* agent=createCodeAgent(mMousePicker.getTerrainIntersection(evt));
				agent->activate(mCodeDesignWidget->isAgentPSVisible());
				mCurrentCIAgents.insert(agent);
			}

			updateCodeDesignWidget();
		}
	}

	return true;
}

bool AppDocFrame::onClicked_ConfigCI(const CEGUI::EventArgs& evt)
{
	if(!mCurrentCIAgents.empty())
	{
		CICodeAgent::SetIterator aiter=mCurrentCIAgents.begin();
		CICodeAgent::SetIterator aiter_end=mCurrentCIAgents.end();
		CICodeAgent* agent=NULL;
		for(; aiter != aiter_end; ++aiter)
		{
			agent=*aiter;
			agent->run("act: config");
		}
	}
	else
	{
		mGUIMgr->showMsgBox("No CIAgent Selected!", "Please Select a CIAgent before continuing");
	}
	return true;
}

bool AppDocFrame::onClicked_GenerateCode(const CEGUI::EventArgs& evt)
{
	if(!mCurrentCIAgents.empty())
	{
		mCodeGenDlg->clearAgents();
		CICodeAgent::SetIterator aiter=mCurrentCIAgents.begin();
		CICodeAgent::SetIterator aiter_end=mCurrentCIAgents.end();
		for(; aiter != aiter_end; ++aiter)
		{
			mCodeGenDlg->addAgent(*aiter);
		}
		mCodeGenDlg->showWindow();
	}
	else
	{
		mGUIMgr->showMsgBox("No CIAgent Selected!", "Please Select a CIAgent before continuing");
	}
	return true;
}