#ifndef _H_ML_LAB_HTTP_MANAGER_H
#define _H_ML_LAB_HTTP_MANAGER_H

#include "CURLEasyHandler.h"
#include <map>
#include <string>
#include <boost/bind.hpp>
#include <boost/signal.hpp>

class HTTPManager
{
public:
	HTTPManager();
	virtual ~HTTPManager();

public:
	CURLEasyHandler* createHandler(const std::string& name);
	CURLEasyHandler* getHandler(const std::string& name);
	void removeHandler(const std::string& name);
	bool handlerExists(const std::string& name);
	void enable(bool enabled);
	bool enabled() const;

public:
	void clearBuffer() { mSimpleBuffer.clear(); }
	void add2Buffer(const std::string& name, const std::string& value) { mSimpleBuffer[name]=value; }

protected:
	static HTTPManager* mSingleton;
	bool mEnabled;

public:
	static HTTPManager* getSingletonPtr() { return mSingleton; }
	static HTTPManager& getSingleton() { return *mSingleton; }

public:
	bool post(const std::string& handlerName, const std::map<std::string, std::string>& msg, std::string& result);
	bool post(const std::string& handlerName, std::string& result);
	bool post(const std::string& handlerName, const std::map<std::string, std::string>& msg);
	bool post(const std::string& handlerName);
	bool postBuffer(const std::string& handlerName, std::string&result);

protected:
	std::map<std::string, CURLEasyHandler*> mHandlers;
	std::map<std::string, std::string> mSimpleBuffer;

protected:
	boost::signal<void (bool)> mEnableNotified;
public:
	boost::signals::connection subscribeEvent_onEnabled(boost::signal<void (bool)>::slot_function_type subscriber);
};

#endif