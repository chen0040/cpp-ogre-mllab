#include "CIManager.h"
#include <Ogre.h>
#include "../tinyxml/tinyxml.h"
#include "../OSEnvironment/OSEnvironment.h"

CIManager* CIManager::getSingletonPtr()
{
	static CIManager theInstance;
	return &theInstance;
}

CIType* CIManager::getCIType(std::string type)
{
	std::map<std::string, CIType*>::iterator fnd=mCITypes.find(type);
	if(fnd == mCITypes.end())
	{
		throw Ogre::Exception(42, "mCITypes.find(type)==mCITypes.end()", "CIManager::getCIType(std::string type) const");
	}
	
	return fnd->second;
}

CIPackage* CIManager::getCIPackage(const std::string& packName)
{
	std::map<std::string, CIPackage*>::iterator fnd=mCIPackages.find(packName);
	if(fnd == mCIPackages.end())
	{
		throw Ogre::Exception(42, "mCIPackages.find(type)==mCIPackages.end()", "CIManager::getCIPackage(std::string type) const");
	}
	return fnd->second;
}

CIManager::CIManager()
{
	TiXmlDocument doc;
	if(!doc.LoadFile(OSEnvironment::getFullPath("..\\config\\mllab_ci.xml").c_str()))
	{
		throw Ogre::Exception(42, "failed to load mllab_ci.xml", "CIManager::CIManager()");
	}

	TiXmlElement* xmlRoot=doc.RootElement();

	for(TiXmlElement* xmlLevel1=xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1=xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "methodology")==0)
		{
			std::string methodology=xmlLevel1->Attribute("name");
			mCITypeNames.push_back(methodology);
			CIType* type=new CIType(xmlLevel1);
			mCITypes[methodology]=type;
		}
		else if(strcmp(xmlLevel1->Value(), "package")==0)
		{
			std::string packname=xmlLevel1->Attribute("name");
			std::string packsrc=xmlLevel1->Attribute("src");
			mCIPackages[packname]=new CIPackage(packname, packsrc);
		}
		else if(strcmp(xmlLevel1->Value(), "languages")==0)
		{
			for(TiXmlElement* xmlLevel2=xmlLevel1->FirstChildElement(); xmlLevel2 != NULL; xmlLevel2 = xmlLevel2->NextSiblingElement())
			{
				if(strcmp(xmlLevel2->Value(), "lang")==0)
				{
					std::string langname=xmlLevel2->Attribute("name");
					mLangs.push_back(langname);
				}
			}
		}
	}
}
	
const CITypeNameList& CIManager::getCITypeNames() const
{
	return mCITypeNames;
}

CIManager::~CIManager()
{
	std::map<std::string, CIType*>::iterator iter=mCITypes.begin();
	std::map<std::string, CIType*>::iterator iter_end=mCITypes.end();
	for(; iter != iter_end; ++iter)
	{
		delete (iter->second);
	}
	mCITypes.clear();

	std::map<std::string, CIPackage*>::iterator piter=mCIPackages.begin();
	std::map<std::string, CIPackage*>::iterator piter_end=mCIPackages.end();
	for(; piter != piter_end; ++piter)
	{
		delete (piter->second);
	}
	mCIPackages.clear();
}