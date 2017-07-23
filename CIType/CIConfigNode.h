#ifndef _H_ML_LAB_CI_CONFIG_SECTION_H
#define _H_ML_LAB_CI_CONFIG_SECTION_H

#include "../tinyxml/tinyxml.h"
#include <map>
#include <string>
#include <vector>

class CIConfigNodeList;
class CIConfigLeafNode;

class CIConfigNode
{
public:
	CIConfigNode(TiXmlElement* xmlElement);
	CIConfigNode();
	virtual ~CIConfigNode();

public:
	CIConfigNode* clone() const;
	void addLeafNode(const std::string& name, CIConfigLeafNode* param);
	void addNodeList(const std::string& name, CIConfigNodeList* list);
	CIConfigLeafNode* getMutableLeafNode(const std::string& name);
	const CIConfigLeafNode* getConstLeafNode(const std::string& name) const;
	CIConfigNodeList* getMutableNodeList(const std::string& name);
	const CIConfigNodeList* getConstNodeList(const std::string& name) const;
	const std::vector<std::string>& getLeafNodeNames() const { return mLeafNodeNames; }
	const std::vector<std::string>& getNodeListNames() const { return mNodeListNames; }

public:
	size_t getLeafNodeCount() const { return mLeafNodeNames.size(); }
	size_t getNodeListCount() const { return mNodeListNames.size(); }
	const CIConfigLeafNode* getConstLeafNode(size_t index) const;
	const CIConfigNodeList* getConstNodeList(size_t index) const;
	CIConfigLeafNode* getMutableLeafNode(size_t index);
	CIConfigNodeList* getMutableNodeList(size_t index);

public:
	void setName(const std::string& name) { mName=name; }
	const std::string& getName() const { return mName; }
	virtual std::string toString() const;

private:
	std::map<std::string, CIConfigLeafNode*> mParams;
	std::map<std::string, CIConfigNodeList*> mLists;
	std::vector<std::string> mLeafNodeNames;
	std::vector<std::string> mNodeListNames;
	std::string mName;
};
#endif