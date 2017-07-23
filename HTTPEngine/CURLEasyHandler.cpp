#include "CURLEasyHandler.h"
#include <sstream>
#include "../Widgets/GUIManager.h"

CURLEasyHandler::CURLEasyHandler()
{
	mHandler=curl_easy_init();
}

CURLEasyHandler::~CURLEasyHandler()
{
	curl_easy_cleanup(mHandler);
}

size_t CURLEasyHandler::write_data( void *ptr, size_t size, size_t nmemb, void *stream)
{
	size_t msgLength=size * nmemb;

	std::string* ptrMsg=static_cast<std::string*>(stream);
	std::string& msg=*ptrMsg;

	msg=static_cast<char*>(ptr);

	return msgLength;
}

bool CURLEasyHandler::post(const std::map<std::string, std::string>& pairs, std::string& result)
{
	std::ostringstream oss;
	std::map<std::string, std::string>::const_iterator iter=pairs.begin();
	std::map<std::string, std::string>::const_iterator iter_end=pairs.end();
	for(; iter != iter_end; ++iter)
	{
		if(iter != pairs.begin())
		{
			oss << "&";
		}
		oss << iter->first << "=" << iter->second;
	}

	std::string msg=oss.str();

	const char* data=msg.c_str();
	const char* url=mUrl.c_str();

	char errorBuffer[CURL_ERROR_SIZE];
	memset(errorBuffer, 0, CURL_ERROR_SIZE);

	curl_easy_setopt(mHandler, CURLOPT_POSTFIELDS, data);
	curl_easy_setopt(mHandler, CURLOPT_WRITEFUNCTION, CURLEasyHandler::write_data);
	curl_easy_setopt(mHandler, CURLOPT_WRITEDATA, &result);
	curl_easy_setopt(mHandler, CURLOPT_URL, url);
	curl_easy_setopt(mHandler, CURLOPT_ERRORBUFFER, errorBuffer);
	curl_easy_setopt(mHandler, CURLOPT_FAILONERROR, 1);

	CURLcode code=curl_easy_perform(mHandler);

	if(code != 0)
	{
		std::ostringstream oss;
		oss << "Failed to connect to " << mUrl << "\n";
		oss << "Error: " << errorBuffer << "\n";
		oss << "Please activate Web Connect from main menu to try to post data again";
		GUIManager::getSingletonPtr()->showMsgBox("HTTP Post Error", oss.str().c_str());
		return false;
	}
	return true;
}