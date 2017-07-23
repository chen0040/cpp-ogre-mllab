#include "CIConfigNodeList.h"
#include <sstream>
#include "../OSEnvironment/OSEnvironment.h"

CIConfigNodeList::CIConfigNodeList(TiXmlElement* xmlElement)
{
	mName=xmlElement->Attribute("name");
	mPrefix=xmlElement->Attribute("prefix");
	mLabel=xmlElement->Attribute("label");
	xmlElement->QueryFloatAttribute("width", &mWidth);
	xmlElement->QueryFloatAttribute("height", &mHeight);
	xmlElement->QueryFloatAttribute("vgap", &mVgap);
	xmlElement->QueryFloatAttribute("label_height", &mLabelHeight);
	xmlElement->QueryFloatAttribute("button_width", &mButtonWidth);
	xmlElement->QueryFloatAttribute("button_height", &mButtonHeight);
	xmlElement->QueryFloatAttribute("detail_height", &mDetailHeight);
	
	mNodeTemplate=new CIConfigNode(xmlElement);
}

CIConfigNodeList::~CIConfigNodeList()
{
	clear();

	if(mNodeTemplate != NULL)
	{
		delete mNodeTemplate;
		mNodeTemplate=NULL;
	}
}

void CIConfigNodeList::clear()
{
	std::map<std::string, CIConfigNode*>::iterator iter=mNodes.begin();
	std::map<std::string, CIConfigNode*>::iterator iter_end=mNodes.end();
	for(; iter != iter_end; ++iter)
	{
		delete (iter->second);
	}
	mNodes.clear();
	mNodeNames.clear();
}

CIConfigNodeList* CIConfigNodeList::clone() const
{
	CIConfigNodeList* list=new CIConfigNodeList();

	list->setButtonHeight(mButtonHeight);
	list->setButtonWidth(mButtonWidth);
	list->setHeight(mHeight);
	list->setLabelHeight(mLabelHeight);
	list->setName(mName);
	list->setPrefix(mPrefix);
	list->setVgap(mVgap);
	list->setWidth(mWidth);
	list->setLabel(mLabel);
	list->setDetailHeight(mDetailHeight);

	std::map<std::string, CIConfigNode*>::const_iterator iter=mNodes.begin();
	std::map<std::string, CIConfigNode*>::const_iterator iter_end=mNodes.end();
	for(; iter != iter_end; ++iter)
	{
		list->addItem(iter->first, iter->second->clone());
	}

	list->setItemTemplate(mNodeTemplate->clone());
	return list;
}

void CIConfigNodeList::addItem(const std::string& name, CIConfigNode* item)
{
	mNodeNames.push_back(name);
	mNodes[name]=item;
}

const CIConfigNode* CIConfigNodeList::getNodeTemplate() const
{
	return mNodeTemplate;
}

const CIConfigNode* CIConfigNodeList::getConstNode(const std::string& name) const
{
	std::map<std::string, CIConfigNode*>::const_iterator fnd=mNodes.find(name);
	return fnd->second;
}
	
CIConfigNode* CIConfigNodeList::getMutableNode(const std::string& name)
{
	std::map<std::string, CIConfigNode*>::iterator fnd=mNodes.find(name);
	return fnd->second;
}

void CIConfigNodeList::setItemTemplate(CIConfigNode* item)
{
	if(mNodeTemplate != NULL)
	{
		delete mNodeTemplate;
	}
	mNodeTemplate=item;
}

const CIConfigNode* CIConfigNodeList::getConstNode(size_t index) const
{
	return getConstNode(mNodeNames[index]);
}
	
CIConfigNode* CIConfigNodeList::getMutableNode(size_t index)
{
	return getMutableNode(mNodeNames[index]);
}

CIConfigNode* CIConfigNodeList::createItem() const
{
	return mNodeTemplate->clone();
}

std::string CIConfigNodeList::getNextItemName() const
{
	size_t item_index=this->getItemCount();
	std::ostringstream oss;
	oss << this->getPrefix() << item_index;
	return oss.str();
}

size_t CIConfigNodeList::addItem(CIConfigNode* item)
{
	this->addItem(getNextItemName(), item);
	return this->getItemCount()-1;
}

void CIConfigNodeList::removeLastItem()
{
	if(this->getItemCount() <= 0)
	{
		return;
	}
	std::string itemName=mNodeNames[mNodeNames.size()-1];
	mNodeNames.pop_back();
	std::map<std::string, CIConfigNode*>::iterator fnd=mNodes.find(itemName);
	delete fnd->second;
	mNodes.erase(fnd);
}