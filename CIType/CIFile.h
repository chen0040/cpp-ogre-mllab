#ifndef _H_MLLAB_CI_SUBTYPE_CLASS_FILE_H
#define _H_MLLAB_CI_SUBTYPE_CLASS_FILE_H

#include <string>
#include "../CIAgents/CodeDesign/ConfigDlg.h"
#include "../tinyxml/tinyxml.h"

class CIFile
{
public:
	CIFile(TiXmlElement* xmlElement);
	virtual ~CIFile();

public:
	void generateCode(const std::string& destinationFodler, const std::string& fileType, const ConfigDlg* config=NULL);
	bool isConfig() const { return mConfig; }

protected:
	std::string mSrc;
	std::string mName;
	std::string mType;
	bool mConfig;
};
#endif