#include "ModelManager.h"
#include "../GameEngine/Application.h"
#include "../OSEnvironment/OSEnvironment.h"
#include "../tinyxml/tinyxml.h"
#include <sstream>

ModelManager* ModelManager::mSingleton=NULL;

ModelManager::ModelManager(size_t expanded)
: mZeroText("")
{
	if(mSingleton == NULL)
	{
		mSingleton=this;
	}
	else
	{
		throw Ogre::Exception(42, "multple instances not allow in a singleton pattern", "ModelManager::ModelManager(size_t expanded)");
	}

	Ogre::SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();

	TiXmlDocument doc;
	if(! doc.LoadFile(OSEnvironment::getFullPath("..\\config\\agent.xml").c_str()))
	{
		throw Ogre::Exception(42, "agent.xml cannot be loaded", "ModelManager::ModelManager(size_t expanded)");
	}

	TiXmlElement* xmlRoot=doc.RootElement();
	mDefaultModelType=xmlRoot->Attribute("default_type");

	for(TiXmlElement* xmlLevel1=xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1 = xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "type")==0)
		{
			std::string name=xmlLevel1->Attribute("name");
			mModels.push_back(name);
			if(strcmp(xmlLevel1->Attribute("environment"), "LAND")==0)
			{
				mEnvironmentType[name]=ENVIRONMENTTYPE_LAND;
			}
			else if(strcmp(xmlLevel1->Attribute("environment"), "AIR")==0)
			{
				mEnvironmentType[name]=ENVIRONMENTTYPE_AIR;
			}
			else if(strcmp(xmlLevel1->Attribute("environment"), "STATIC")==0)
			{
				mEnvironmentType[name]=ENVIRONMENTTYPE_STATIC;
			}
			else
			{
				mEnvironmentType[name]=ENVIRONMENTTYPE_LAND;
			}
			for(TiXmlElement* xmlLevel2=xmlLevel1->FirstChildElement(); xmlLevel2 != NULL; xmlLevel2=xmlLevel2->NextSiblingElement())
			{
				if(strcmp(xmlLevel2->Value(), "animation")==0)
				{
					mDie[name]=xmlLevel2->Attribute("die");
					mShoot[name]=xmlLevel2->Attribute("shoot");
					mSlump[name]=xmlLevel2->Attribute("slump");
					mWalk[name]=xmlLevel2->Attribute("walk");
					mIdle[name]=xmlLevel2->Attribute("idle");
				}
				else if(strcmp(xmlLevel2->Value(), "model")==0)
				{
					mEntityCount[name]=expanded;
					std::ostringstream oss1;
					std::stack<Entity*> entities;
					mMesh[name]=xmlLevel2->Attribute("mesh");
					for(size_t i=0; i<expanded; ++i)
					{
						oss1.str("");
						oss1 << name << i;
						Entity* entity=sm->createEntity(String(oss1.str().c_str()), xmlLevel2->Attribute("mesh"));
						entities.push(entity);
					}
					mEntities[name]=entities;
				}
				else if(strcmp(xmlLevel2->Value(), "scale")==0)
				{
					Real x, y, z;
					xmlLevel2->QueryFloatAttribute("x", &x);
					xmlLevel2->QueryFloatAttribute("y", &y);
					xmlLevel2->QueryFloatAttribute("z", &z);

					mScale[name]=Vector3(x, y, z);
				}
				else if(strcmp(xmlLevel2->Value(), "offset")==0)
				{
					Real x, y, z;
					xmlLevel2->QueryFloatAttribute("x", &x);
					xmlLevel2->QueryFloatAttribute("y", &y);
					xmlLevel2->QueryFloatAttribute("z", &z);

					mOffset[name]=Vector3(x, y, z);
				}
				else if(strcmp(xmlLevel2->Value(), "rotation")==0)
				{
					Real x, y, z;
					xmlLevel2->QueryFloatAttribute("x", &x);
					xmlLevel2->QueryFloatAttribute("y", &y);
					xmlLevel2->QueryFloatAttribute("z", &z);

					mRotation[name]=Vector3(x, y, z);
				}
				else if(strcmp(xmlLevel2->Value(), "weapon")==0)
				{
					mWeaponName[name]=xmlLevel2->Attribute("name");
					
					Real x=0, y=0, z=0;
					xmlLevel2->QueryFloatAttribute("offset_x", &x);
					xmlLevel2->QueryFloatAttribute("offset_y", &y);
					xmlLevel2->QueryFloatAttribute("offset_z", &z);

					mWeaponOffset[name]=Vector3(x, y, z);
				}
			}
		}
	}
	
}

ModelManager::~ModelManager()
{

}

void ModelManager::pushEntity(const std::string& name, Entity* entity)
{
	//Xianshun: this is a temporary solution... to the slanted entity shape when popEntity()
	Ogre::SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
	sm->destroyEntity(entity->getName());
	/*
	std::map<std::string, std::stack<Entity*> >::iterator fnd=mEntities.find(name);
	std::stack<Entity*>& entities=fnd->second;

	entities.push(entity);
	*/
}

Entity* ModelManager::popEntity(const std::string& name)
{
	std::map<std::string, std::stack<Entity*> >::iterator fnd=mEntities.find(name);
	std::stack<Entity*>& entities=fnd->second;

	if(entities.empty())
	{
		std::ostringstream oss;

		std::map<std::string, size_t>::iterator ecfnd=mEntityCount.find(name);

		ecfnd->second++;

		oss << name << "h" << ecfnd->second;
		

		SceneManager* sm=Application::getSingletonPtr()->getSceneMgr();
		entities.push(sm->createEntity(String(oss.str().c_str()), getMesh(name)));
	}

	Entity* ent=entities.top();
	entities.pop();
	return ent;
}

size_t ModelManager::getEntityCount(const std::string& name) const
{
	std::map<std::string, size_t>::const_iterator fnd=mEntityCount.find(name); 
	if(fnd != mEntityCount.end())
	{
		return fnd->second;
	}
	return 0;
}

Vector3 ModelManager::getScale(const std::string& name) const
{
	std::map<std::string, Vector3>::const_iterator fnd=mScale.find(name);
	return fnd->second;
}

const Vector3& ModelManager::getOffset(const std::string& name) const
{
	std::map<std::string, Vector3>::const_iterator fnd=mOffset.find(name);
	if(fnd != mOffset.end())
	{
		return fnd->second;
	}
	
	return mZeroVec;
}

Vector3 ModelManager::getRotation(const std::string& name) const
{
	std::map<std::string, Vector3>::const_iterator fnd=mRotation.find(name);
	if(fnd != mRotation.end())
	{
		return fnd->second;
	}
	return mZeroVec;
}

ModelManager::EnvironmentType ModelManager::getEnvironmentType(const std::string& name) const
{
	std::map<std::string, EnvironmentType>::const_iterator fnd=mEnvironmentType.find(name);
	if(fnd != mEnvironmentType.end())
	{
		return fnd->second;
	}
	return ENVIRONMENTTYPE_LAND;
}

std::string ModelManager::getAnimationName_Die(const std::string& name) const
{
	std::map<std::string, std::string>::const_iterator fnd=mDie.find(name);
	if(fnd != mDie.end())
	{
		return fnd->second;
	}
	return "";
}

std::string ModelManager::getAnimationName_Slump(const std::string& name) const
{
	std::map<std::string, std::string>::const_iterator fnd=mSlump.find(name);
	if(fnd != mSlump.end())
	{
		return fnd->second;
	}
	return "";
}

std::string ModelManager::getAnimationName_Shoot(const std::string& name) const
{
	std::map<std::string, std::string>::const_iterator fnd=mShoot.find(name);
	if(fnd != mShoot.end())
	{
		return fnd->second;
	}
	return "";
}

std::string ModelManager::getAnimationName_Idle(const std::string& name) const
{
	std::map<std::string, std::string>::const_iterator fnd=mIdle.find(name);
	if(fnd != mIdle.end())
	{
		return fnd->second;
	}
	return "";
}

std::string ModelManager::getAnimationName_Walk(const std::string& name) const
{
	std::map<std::string, std::string>::const_iterator fnd=mWalk.find(name);
	if(fnd != mWalk.end())
	{
		return fnd->second;
	}
	return "";
}

std::string ModelManager::getMesh(const std::string& name) const
{
	std::map<std::string, std::string>::const_iterator fnd=mMesh.find(name);
	if(fnd != mMesh.end())
	{
		return fnd->second;
	}
	return "";
}

const std::vector<std::string>& ModelManager::getConstModelNames() const
{
	return mModels;
}

const Vector3& ModelManager::getWeaponOffset(const std::string& name) const
{
	std::map<std::string, Vector3>::const_iterator fnd=mWeaponOffset.find(name);
	if(fnd != mWeaponOffset.end())
	{
		return fnd->second;
	}
	return mZeroVec;
}
	
const std::string& ModelManager::getWeaponName(const std::string& name) const
{
	std::map<std::string, std::string>::const_iterator fnd=mWeaponName.find(name);
	if(fnd != mWeaponName.end())
	{
		return fnd->second;
	}
	return mZeroText;
}

