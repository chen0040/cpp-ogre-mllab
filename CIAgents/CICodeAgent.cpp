#include "CICodeAgent.h"
#include "../CIType/CIManager.h"
#include "../Widgets/GUIManager.h"
#include "../GameEngine/Application.h"
#include "../OSEnvironment/OSEnvironment.h"
#include "../Recorder/GameAgentRecorder.h"
#include "CIAgentManager.h"

CICodeAgent::CICodeAgent(const Ogre::Vector3& pos, const std::string& agentName, const std::string& type, const std::string& method)
: CIAgent(pos, agentName)
{
	mAgentType="CICodeAgent";
	SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();

	mAlphaParticleSystem=CIAgentManager::getSingletonPtr()->popAlphaPS();
	mAlphaParticleSystem->setVisible(false);

	mPSNode=sm->getRootSceneNode()->createChildSceneNode(mAlphaParticleSystem->getName()+"Node", pos);
	mPSNode->setScale(0.5, 0.5, 0.5);
	mPSNode->attachObject(mAlphaParticleSystem);

	mCIType=type;
	mCIMethod=method;
	std::ostringstream oss;
	oss << getAgentName() << "Config";
	mConfig=new ConfigDlg(oss.str(), mCIType, mCIMethod);

	createText(method);
}

CICodeAgent::~CICodeAgent()
{
	if(mConfig != NULL)
	{
		delete mConfig;
		mConfig=NULL;
	}

	Application* app=Application::getSingletonPtr();
	mPSNode->detachObject(mAlphaParticleSystem);
	app->getSceneMgr()->getRootSceneNode()->removeAndDestroyChild(mPSNode->getName());

	CIAgentManager* am=CIAgentManager::getSingletonPtr();
	am->pushAlphaPS(mAlphaParticleSystem);
}

void CICodeAgent::setPosition(const Vector3& pos)
{
	CIAgent::setPosition(pos);
	mPSNode->setPosition(mEntityNode->getPosition());
}

void CICodeAgent::saveConfigXml(TiXmlElement* xmlConfig)
{
	mConfig->saveXml(xmlConfig);
}

void CICodeAgent::loadConfigXml(TiXmlElement* xmlConfig)
{
	mConfig->loadXml(xmlConfig);
}

bool CICodeAgent::run(const std::string& cmd, Ogre::Real dt)
{
	if(CIAgent::run(cmd, dt))
	{
		return true;
	}
	else if(cmd.compare("act: config")==0)
	{
		this->config();
		return true;
	}
	else
	{
		std::ostringstream oss;
		oss << "Failed to interpret command \"" << cmd << "\"";
		throw Ogre::Exception(42, oss.str().c_str(), "CICodeAgent::run(const std::string& cmd, Ogre::Real dt)");
	}
	return false;
}

void CICodeAgent::deactivate()
{
	CIAgent::deactivate();
	mAlphaParticleSystem->setVisible(false);
}

void CICodeAgent::activate(bool showPS)
{
	CIAgent::activate(showPS);
	mAlphaParticleSystem->setVisible(showPS);
}

void CICodeAgent::config()
{
	mConfig->showModal();
}

void CICodeAgent::generateCode(const std::string& destinationFolderPath, const std::string& lang, const std::string& codeName)
{
	std::ostringstream oss1;
	std::string fname;
	if(codeName.compare("")==0)
	{
		fname=this->getAgentName();
	}
	else
	{
		fname=codeName;
	}
	oss1 << destinationFolderPath << "\\" << fname;
	CIManager::getSingletonPtr()->getCIType(mCIType)->getMethod(mCIMethod)->generateCode(oss1.str(), lang, mConfig);

	std::ostringstream oss2;
	oss2 << "[" << this->getAgentName() << "]: Code generated in folder \"";
	oss2 << destinationFolderPath << "\"";

	if(lang.compare("lua")==0)
	{
		if(!OSEnvironment::copyFile2Folder("GameWorld.lua", OSEnvironment::getFullPath("..\\script_classes"), oss1.str()))
		{
			oss2 << "Failed to copy GameWorld.lua\n";
		}
		if(!OSEnvironment::copyFile2Folder("GameAgent.lua", OSEnvironment::getFullPath("..\\script_classes"), oss1.str()))
		{
			oss2 << "Failed to copy GameAgent.lua\n";
		}
		if(!OSEnvironment::copyFile2Folder("GameUtil.lua", OSEnvironment::getFullPath("..\\script_classes"), oss1.str()))
		{
			oss2 << "Failed to copy GameUtil.lua\n";
		}
		if(!OSEnvironment::copyFile2Folder("GameWeapon.lua", OSEnvironment::getFullPath("..\\script_classes"), oss1.str()))
		{
			oss2 << "Failed to copy GameWeapon.lua\n";
		}
		if(!OSEnvironment::copyFile2Folder("GameLogger.lua", OSEnvironment::getFullPath("..\\script_classes"), oss1.str()))
		{
			oss2 << "Failed to copy GameLogger.lua\n";
		}
		GameAgentRecorder::getSingletonPtr()->save(oss1.str());
	}
	GUIManager::getSingletonPtr()->showMsgBox("Code Generation Complete!", oss2.str());
}

std::string CICodeAgent::toString() const
{
	std::ostringstream oss;
	oss << "ID: " << getAgentName();
	oss << "\nType: Code Agent";
	oss << "\nCI: " << this->mCIType;
	oss << "\nMethod: " << this->mCIMethod;
	oss << "\n" << mConfig->toString();

	return oss.str();
}

