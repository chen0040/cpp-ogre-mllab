#ifndef _H_MLLAB_CITYPE_MANAGER_H
#define _H_MLLAB_CITYPE_MANAGER_H

#include <string>
#include <map>
#include <vector>
#include "CIType.h"
#include "CIPackage.h"

typedef std::vector<std::string> CITypeNameList;

class CIManager
{
public:
	virtual ~CIManager();

private:
	CIManager();
	CIManager(const CIManager& rhs) { }
	CIManager& operator=(const CIManager& rhs) { return *this; }

public:
	static CIManager* getSingletonPtr();

public:
	CIType* getCIType(std::string type);
	CIPackage* getCIPackage(const std::string& packName);
	const CITypeNameList& getCITypeNames() const;
	const std::vector<std::string>& getLangs() const { return mLangs; }

private:
	std::map<std::string, CIType*> mCITypes;
	std::map<std::string, CIPackage*> mCIPackages;
	std::vector<std::string> mLangs;
	CITypeNameList mCITypeNames;
};
#endif