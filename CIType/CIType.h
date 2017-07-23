#ifndef _H_MLLAB_CI_TYPE_H
#define _H_MLLAB_CI_TYPE_H

#include <string>
#include <map>
#include <vector>
#include "CIMethod.h"
#include "CIClass.h"
#include "../CIAgents/CodeDesign/ConfigDlg.h"

class CIType 
{
public:
	CIType(TiXmlElement* xmlElement);
	virtual ~CIType();

public:
	const std::vector<std::string>& getMethodNames() const;
	CIMethod* getMethod(const std::string& methodName);
	const CIMethod* getConstMethod(const std::string& methodName) const;

protected:
	std::map<std::string, CIMethod*> mMethods;
	std::vector<std::string> mMethodNames;
};

#endif