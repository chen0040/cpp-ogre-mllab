#include "HTTPManager.h"
#include <Ogre.h>
#include "../OSEnvironment/OSEnvironment.h"
#include "../tinyxml/tinyxml.h"

HTTPManager* HTTPManager::mSingleton=NULL;

HTTPManager::HTTPManager()
: mEnabled(false)
{
	if(mSingleton==NULL)
	{
		mSingleton=this;
	}
	else
	{
		throw Ogre::Exception(42, "Multiple instances not allowed!", "HTTPManager::HTTPManager()");
	}

	curl_global_init(CURL_GLOBAL_ALL);

	TiXmlDocument doc;
	std::string filename=OSEnvironment::getFullPath("..\\config\\curl.xml");
	if(!doc.LoadFile(filename.c_str()))
	{
		throw Ogre::Exception(42, OSEnvironment::append("Failed to parse ", filename).c_str(), "HTTPManager::HTTPManager()");
	}

	TiXmlElement* xmlRoot=doc.RootElement();
	for(TiXmlElement* xmlLevel1=xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1=xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "easyhandler")==0)
		{
			std::string handlerName=xmlLevel1->Attribute("name");
			int min_interval_in_ms=0;
			xmlLevel1->QueryIntAttribute("min_interval_in_ms", &min_interval_in_ms);

			CURLEasyHandler* handler=createHandler(handlerName);
			handler->setUrl(xmlLevel1->Attribute("url"));
			handler->set_min_interval_in_ms(min_interval_in_ms);
		}
	}
	
}

HTTPManager::~HTTPManager()
{
	std::map<std::string, CURLEasyHandler*>::iterator iter=mHandlers.begin();
	std::map<std::string, CURLEasyHandler*>::iterator iter_end=mHandlers.end();
	for(; iter != iter_end; ++iter)
	{
		delete iter->second;
	}
	mHandlers.clear();
}

CURLEasyHandler* HTTPManager::createHandler(const std::string &name)
{
	CURLEasyHandler* handler=getHandler(name);
	if(handler  != NULL) 
	{
		return handler;
	}
	handler=new CURLEasyHandler();
	mHandlers[name]=handler;
	return handler;
}

bool HTTPManager::post(const std::string& handlerName, const std::map<std::string, std::string>& msg, std::string& result)
{
	if(!mEnabled) return false;

	CURLEasyHandler* handler=getHandler(handlerName);
	if(handler==NULL)
	{	
		throw Ogre::Exception(42, "getHandler(name) return NULL!", "HTTPManager::post(const std::string& handlerName, const std::map<std::string, std::string>& msg)");
	}
	if(handler->post(msg, result)==false)
	{
		enable(false);
		return false;
	}
	return true;
}

bool HTTPManager::post(const std::string& handlerName, std::string& result)
{
	std::map<std::string, std::string> msg;
	return this->post(handlerName, msg, result);
}

CURLEasyHandler* HTTPManager::getHandler(const std::string &name)
{
	std::map<std::string, CURLEasyHandler*>::iterator fnd=mHandlers.find(name);
	if(fnd != mHandlers.end())
	{
		return fnd->second;
	}
	return NULL;
}

bool HTTPManager::handlerExists(const std::string& name)
{
	return getHandler(name) != NULL;
}

void HTTPManager::removeHandler(const std::string &name)
{
	std::map<std::string, CURLEasyHandler*>::iterator fnd=mHandlers.find(name);
	if(fnd != mHandlers.end())
	{
		delete fnd->second;
		mHandlers.erase(fnd);
	}
}

void HTTPManager::enable(bool enabled)
{
	mEnabled=enabled;
	mEnableNotified(enabled);
}

bool HTTPManager::enabled() const
{
	return mEnabled;
}

boost::signals::connection HTTPManager::subscribeEvent_onEnabled(boost::signal<void (bool)>::slot_function_type subscriber)
{
	return mEnableNotified.connect(subscriber);
}

bool HTTPManager::post(const std::string& handlerName, const std::map<std::string, std::string>& msg)
{
	std::string result;
	return this->post(handlerName, msg, result);
}

bool HTTPManager::post(const std::string& handlerName)
{
	std::string result;
	return this->post(handlerName, result);
}

bool HTTPManager::postBuffer(const std::string& handlerName, std::string& result)
{
	bool r=this->post(handlerName, mSimpleBuffer, result);	
	return r;
}