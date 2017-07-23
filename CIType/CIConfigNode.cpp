#include "CIConfigNode.h"
#include "CIConfigNodeList.h"
#include "CIConfigLeafNode.h"
#include <sstream>

CIConfigNode::CIConfigNode()
{

}

CIConfigNode::CIConfigNode(TiXmlElement* xmlElement)
{
	mName=xmlElement->Attribute("name");

	for(TiXmlElement* xmlLevel1=xmlElement->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1=xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "param")==0)
		{
			std::string name=xmlLevel1->Attribute("name");
			mLeafNodeNames.push_back(name);
			mParams[name]=new CIConfigLeafNode(xmlLevel1);
		}
		else if(strcmp(xmlLevel1->Value(), "list_template")==0)
		{
			std::string name=xmlLevel1->Attribute("name");
			mNodeListNames.push_back(name);
			mLists[name]=new CIConfigNodeList(xmlLevel1);
		}
	}
}

CIConfigNode::~CIConfigNode()
{
	std::map<std::string, CIConfigLeafNode*>::iterator iter=mParams.begin();
	std::map<std::string, CIConfigLeafNode*>::iterator iter_end=mParams.end();
	for(; iter != iter_end; ++iter)
	{
		delete (iter->second);
	}
	mParams.clear();
	mLeafNodeNames.clear();

	std::map<std::string, CIConfigNodeList*>::iterator liter=mLists.begin();
	std::map<std::string, CIConfigNodeList*>::iterator liter_end=mLists.end();
	for(; liter != liter_end; ++liter)
	{
		delete (liter->second);
	}
	mLists.clear();
	mNodeListNames.clear();
}

CIConfigNode* CIConfigNode::clone() const
{
	CIConfigNode* c=new CIConfigNode();
	c->setName(mName);
	size_t leafNodeCount=mLeafNodeNames.size();
	for(size_t k=0; k != leafNodeCount; ++k)
	{
		c->addLeafNode(mLeafNodeNames[k], mParams.find(mLeafNodeNames[k])->second->clone());
	}
	size_t nodeListCount=mNodeListNames.size();
	for(size_t k=0; k != nodeListCount; ++k)
	{
		c->addNodeList(mNodeListNames[k], mLists.find(mNodeListNames[k])->second->clone());
	}
	return c;
}

void CIConfigNode::addLeafNode(const std::string& name, CIConfigLeafNode* param)
{
	mLeafNodeNames.push_back(name);
	mParams[name]=param;
}

void CIConfigNode::addNodeList(const std::string& name, CIConfigNodeList* list)
{
	mNodeListNames.push_back(name);
	mLists[name]=list;
}

CIConfigLeafNode* CIConfigNode::getMutableLeafNode(const std::string& name)
{
	std::map<std::string, CIConfigLeafNode*>::iterator fnd=mParams.find(name);
	return fnd->second;
}

const CIConfigLeafNode* CIConfigNode::getConstLeafNode(const std::string& name) const
{
	std::map<std::string, CIConfigLeafNode*>::const_iterator fnd=mParams.find(name);
	return fnd->second;
}

CIConfigNodeList* CIConfigNode::getMutableNodeList(const std::string& name)
{
	std::map<std::string, CIConfigNodeList*>::iterator fnd=mLists.find(name);
	return fnd->second;
}

const CIConfigNodeList* CIConfigNode::getConstNodeList(const std::string& name) const
{
	std::map<std::string, CIConfigNodeList*>::const_iterator fnd=mLists.find(name);
	return fnd->second;
}

const CIConfigLeafNode* CIConfigNode::getConstLeafNode(size_t index) const
{
	return getConstLeafNode(mLeafNodeNames[index]);
}
	
const CIConfigNodeList* CIConfigNode::getConstNodeList(size_t index) const
{
	return getConstNodeList(mNodeListNames[index]);
}
	
CIConfigLeafNode* CIConfigNode::getMutableLeafNode(size_t index)
{
	return getMutableLeafNode(mLeafNodeNames[index]);
}
	
CIConfigNodeList* CIConfigNode::getMutableNodeList(size_t index)
{
	return getMutableNodeList(mNodeListNames[index]);
}


std::string CIConfigNode::toString() const
{
	std::ostringstream oss;

	size_t count=this->getLeafNodeCount();
	for(size_t j=0; j<count; j++)
	{
		const CIConfigLeafNode* param=this->getConstLeafNode(j);
		oss << param->getLabel() << ": " << param->getValue();
	}

	return oss.str();
}