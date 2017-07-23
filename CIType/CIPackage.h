#ifndef _H_ML_LAB_CI_TYPE_PACKAGE_H
#define _H_ML_LAB_CI_TYPE_PACKAGE_H

#include "../tinyxml/tinyxml.h"
#include <string>
#include <map>
#include "CIFile.h"
#include "../CIAgents/CodeDesign/ConfigDlg.h"

class CIPackage
{
public:
	CIPackage(const std::string& name, const std::string& src);
	virtual ~CIPackage();

public:
	void generateCode(const std::string& destinationFile, const std::string& fileType, const ConfigDlg* config=NULL);

protected:
	std::map<std::string, CIFile*> mFiles;
	std::string mName;
	std::string mSrc;
};

#endif