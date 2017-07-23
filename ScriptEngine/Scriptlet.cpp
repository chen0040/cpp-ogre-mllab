#include "Scriptlet.h"
#include "../tinyxml/tinyxml.h"
#include <Ogre.h>
#include <sstream>
#include "ScriptManager.h"
#include "../OSEnvironment/OSEnvironment.h"

Scriptlet::Scriptlet(const std::string& scriptId, const std::string& src)
{
	mScriptDirectory=src;
	mScriptId=scriptId;

	parse();
}

Scriptlet::~Scriptlet()
{
	
}

std::string Scriptlet::getFullPath(const std::string& relpath) const
{
	return mScriptDirectory+std::string("\\")+relpath;
}

std::string Scriptlet::toString() const
{
	return OSEnvironment::readFile(getFullPath("About.txt"));
}

void Scriptlet::parse()
{
	std::string configPath=mScriptDirectory+std::string("\\config.xml");
	TiXmlDocument doc;
	if(! doc.LoadFile(configPath.c_str()))
	{
		std::ostringstream oss; 
		oss << "Failed to load " << configPath;
		throw Ogre::Exception(42, oss.str().c_str(), "Scriptlet::parse()");
	}

	TiXmlElement* xmlRoot=doc.RootElement();
	mSystemType=xmlRoot->Attribute("system");

	for(TiXmlElement* xmlLevel1=xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1 = xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "system")==0 && mSystemType.compare(xmlLevel1->Attribute("name"))==0)
		{
			for(TiXmlElement* xmlLevel2=xmlLevel1->FirstChildElement(); xmlLevel2 != NULL; xmlLevel2= xmlLevel2->NextSiblingElement())
			{
				if(strcmp(xmlLevel2->Value(), "aura")==0)
				{
					
					xmlLevel2->QueryIntAttribute("r", &mRed);
					xmlLevel2->QueryIntAttribute("g", &mGreen);
					xmlLevel2->QueryIntAttribute("b", &mBlue);
				}
			}
			break;
		}
	}

	mLuaScriptClassPath=mScriptDirectory;
	size_t fnd=mLuaScriptClassPath.find("\\");
	while(fnd != std::string::npos)
	{
		mLuaScriptClassPath.replace(fnd, 1, "\\\\");
		fnd=mLuaScriptClassPath.find("\\", fnd+2);
	}
}