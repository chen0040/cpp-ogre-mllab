#include "CIType.h"
#include <Ogre.h>

CIType::CIType(TiXmlElement *xmlElement)
{
	for(TiXmlElement* xmlLevel1=xmlElement->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1=xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "method")==0)
		{
			std::string name=xmlLevel1->Attribute("name");
			std::string src=xmlLevel1->Attribute("src");
			CIMethod* st=new CIMethod(name, src);
			mMethods[name]=st;
			mMethodNames.push_back(name);
		}
	}
}

CIType::~CIType()
{
	std::map<std::string, CIMethod*>::iterator iter=mMethods.begin();
	std::map<std::string, CIMethod*>::iterator iter_end=mMethods.end();
	for(; iter != iter_end; ++iter)
	{
		delete iter->second;
	}
	mMethods.clear();
}

const std::vector<std::string>& CIType::getMethodNames() const
{
	return mMethodNames;
}

CIMethod* CIType::getMethod(const std::string& methodName)
{
	std::map<std::string, CIMethod*>::iterator fnd=mMethods.find(methodName);
	if(fnd == mMethods.end())
	{
		throw Ogre::Exception(42, "fnd==mMethods.end()", "CIType::getMethod(const std::string& methodName)");
	}
	return fnd->second;
}

const CIMethod* CIType::getConstMethod(const std::string& methodName) const
{
	std::map<std::string, CIMethod*>::const_iterator fnd=mMethods.find(methodName);
	if(fnd == mMethods.end())
	{
		throw Ogre::Exception(42, "fnd==mMethods.end()", "CIType::getMethod(const std::string& methodName)");
	}
	return fnd->second;
}
