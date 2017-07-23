#ifndef _H_MLLAB_CI_SUBTYPE_H
#define _H_MLLAB_CI_SUBTYPE_H

#include "../tinyxml/tinyxml.h"
#include <string>
#include <map>
#include <vector>
#include "CIClass.h"
#include "CIPackage.h"
#include "../CIAgents/CodeDesign/ConfigDlg.h"
#include "../CIType/CIConfigNode.h"

class CIMethod
{
public:
	CIMethod(const std::string& name, const std::string& src);
	virtual ~CIMethod();

private:
	CIMethod(const CIMethod& rhs) { }
	CIMethod& operator=(const CIMethod& rhs) { return *this; }

public:
	const std::vector<std::string>& getSectionNames() const { return mSectionNames; }
	CIConfigNode* getSection(const std::string& name);
	const CIConfigNode* getConstSection(const std::string& name) const;

public:
	void generateCode(const std::string& destinationFolderPath, const std::string& fileType, const ConfigDlg* config=NULL);

protected:
	std::map<std::string, CIClass*> mClasses;
	std::vector<std::string> mPackageNames;
	std::map<std::string, CIConfigNode*> mConfigSections;
	std::vector<std::string> mSectionNames;
	std::string mSrc;
	std::string mName;
};
#endif