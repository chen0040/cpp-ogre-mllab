#include "CIMethod.h"
#include "CIManager.h"
#include <sstream>
#include "../OSEnvironment/OSEnvironment.h"

CIMethod::CIMethod(const std::string& name, const std::string& src)
: mName(name)
{
	TiXmlDocument doc;
	mSrc=OSEnvironment::getFullPath(src);
	if(!doc.LoadFile(mSrc.c_str()))
	{
		std::ostringstream oss;
		oss << "Failed to load " << mSrc;
		throw Ogre::Exception(42, oss.str().c_str(), "CIMethod::CIMethod(const std::string& name, const std::string& src)");
	}

	TiXmlElement* xmlRoot=doc.RootElement();

	for(TiXmlElement* xmlLevel1=xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1=xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "class")==0)
		{
			std::string name=xmlLevel1->Attribute("name");
			CIClass* stc=new CIClass(xmlLevel1);
			mClasses[name]=stc;
		}
		else if(strcmp(xmlLevel1->Value(), "packages")==0)
		{
			for(TiXmlElement* xmlLevel2=xmlLevel1->FirstChildElement(); xmlLevel2 != NULL; xmlLevel2=xmlLevel2->NextSiblingElement())
			{
				if(strcmp(xmlLevel2->Value(), "package")==0)
				{
					std::string packname=xmlLevel2->Attribute("name");
					mPackageNames.push_back(packname);
				}
			}
		}
		else if(strcmp(xmlLevel1->Value(), "configuration")==0)
		{
			for(TiXmlElement* xmlLevel2=xmlLevel1->FirstChildElement(); xmlLevel2 != NULL; xmlLevel2=xmlLevel2->NextSiblingElement())
			{
				if(strcmp(xmlLevel2->Value(), "section")==0)
				{
					std::string name=xmlLevel2->Attribute("name");
					mSectionNames.push_back(name);
					mConfigSections[name]=new CIConfigNode(xmlLevel2);
				}
			}
		}
	}
}

CIMethod::~CIMethod()
{
	std::map<std::string, CIClass*>::iterator citer=mClasses.begin();
	std::map<std::string, CIClass*>::iterator citer_end=mClasses.end();
	for(; citer != citer_end; ++citer)
	{
		delete citer->second;
	}
	mClasses.clear();

	std::map<std::string, CIConfigNode*>::iterator siter=mConfigSections.begin();
	std::map<std::string, CIConfigNode*>::iterator siter_end=mConfigSections.end();
	for(; siter != siter_end; ++siter)
	{
		delete siter->second;
	}
	mConfigSections.clear();
}

void CIMethod::generateCode(const std::string& destinationFolderPath, const std::string& fileType, const ConfigDlg* config)
{
	std::map<std::string, CIClass*>::iterator iter=mClasses.begin();
	std::map<std::string, CIClass*>::iterator iter_end=mClasses.end();
	CIClass* cls=NULL;
	for(; iter != iter_end; ++iter)
	{
		cls=iter->second;
		cls->generateCode(destinationFolderPath, fileType, config);
	}

	std::vector<std::string>::iterator piter=mPackageNames.begin();
	std::vector<std::string>::iterator piter_end=mPackageNames.end();
	for(; piter != piter_end; ++piter)
	{
		CIManager::getSingletonPtr()->getCIPackage(*piter)->generateCode(destinationFolderPath, fileType, config);
	}
}

CIConfigNode* CIMethod::getSection(const std::string& name)
{
	std::map<std::string, CIConfigNode*>::iterator fnd=mConfigSections.find(name);
	return fnd->second;
}

const CIConfigNode* CIMethod::getConstSection(const std::string& name) const
{
	std::map<std::string, CIConfigNode*>::const_iterator fnd=mConfigSections.find(name);
	return fnd->second;
}
