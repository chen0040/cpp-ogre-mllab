#ifndef _H_MLLAB_CI_SUB_TYPE_CLASS_H
#define _H_MLLAB_CI_SUB_TYPE_CLASS_H

#include <string>
#include <map>
#include "../tinyxml/tinyxml.h"
#include "CIFile.h"
#include "../CIAgents/CodeDesign/ConfigDlg.h"

class CIClass
{
public:
	CIClass(TiXmlElement* xmlElement);
	virtual ~CIClass();

private:
	CIClass(const CIClass& rhs) { }
	CIClass& operator=(const CIClass& rhs) { return *this; }

public:
	void generateCode(const std::string& destinationFolder, const std::string& fileType, const ConfigDlg* config=NULL);

protected:
	std::map<std::string, CIFile*> mFiles;
};

#endif