#ifndef _H_ML_LAB_CURL_EASY_HANDLER_H
#define _H_ML_LAB_CURL_EASY_HANDLER_H

#include "../curl/curl.h"
#include <string>
#include <map>
#include <Ogre.h>

class CURLEasyHandler 
{
public:
	CURLEasyHandler();
	virtual ~CURLEasyHandler();

public:
	bool post(const std::map<std::string, std::string>& msg, std::string& result);

public:
	const std::string& getUrl() const { return mUrl; }
	void setUrl(const std::string& url) { mUrl=url; }
	void set_min_interval_in_ms(int val) { m_min_interval_in_s=static_cast<float>(val) / 1000.0f; }
	float get_min_interval_in_seconds() const { return m_min_interval_in_s; }

protected:
	CURL* mHandler;
	float m_min_interval_in_s;
	std::string mUrl;

public:
	static size_t write_data( void *ptr, size_t size, size_t nmemb, void *stream);
};

#endif