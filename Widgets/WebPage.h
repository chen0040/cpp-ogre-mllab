#ifndef _H_ML_LAB_WEB_PAGE_H
#define _H_ML_LAB_WEB_PAGE_H

#include <string>
#include "../tinyxml/tinyxml.h"

class WebPage
{
public:
	WebPage(TiXmlElement* xmlElement);
	virtual ~WebPage();

public:
	const std::string& getURL() const { return mURL; }
	const std::string& getTransparentColor() const { return mTransparentColor; }
	const std::string& getMaskFile() const { return mMaskFile; }

protected:
	std::string mURL;
	std::string mTransparentColor;
	std::string mMaskFile;
};
#endif
