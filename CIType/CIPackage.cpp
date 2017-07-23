#include "CIPackage.h"
#include <sstream>
#include "../OSEnvironment/OSEnvironment.h"

CIPackage::CIPackage(const std::string& name, const std::string& src)
: mName(name)
{
	TiXmlDocument doc;
	mSrc=OSEnvironment::getFullPath(src);
	if(!doc.LoadFile(mSrc.c_str()))
	{
		std::ostringstream oss;
		oss << "Failed to load " << mSrc;
		throw Ogre::Exception(42, oss.str().c_str(), "CIPackage::CIPackage(const std::string& name, const std::string& src)");
	}

	TiXmlElement* xmlRoot=doc.RootElement();
	for(TiXmlElement* xmlLevel1=xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1=xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "file")==0)
		{
			std::string name=xmlLevel1->Attribute("name");
			CIFile* file=new CIFile(xmlLevel1);
			mFiles[name]=file;
		}
	}
}

CIPackage::~CIPackage()
{
	std::map<std::string, CIFile*>::iterator iter=mFiles.begin();
	std::map<std::string, CIFile*>::iterator iter_end=mFiles.end();
	for(; iter != iter_end; ++iter)
	{
		delete (iter->second);
	}
	mFiles.clear();
}

void CIPackage::generateCode(const std::string &destinationFile, const std::string &fileType, const ConfigDlg* config)
{
	std::map<std::string, CIFile*>::iterator iter=mFiles.begin();
	std::map<std::string, CIFile*>::iterator iter_end=mFiles.end();
	for(; iter !=iter_end; ++iter)
	{
		(iter->second)->generateCode(destinationFile, fileType, config);
	}
}