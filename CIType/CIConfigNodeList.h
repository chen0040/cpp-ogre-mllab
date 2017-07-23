#ifndef _H_ML_LAB_CI_CONFIG_LIST_H
#define _H_ML_LAB_CI_CONFIG_LIST_H

#include <string>
#include <map>
#include <vector>
#include "../tinyxml/tinyxml.h"
#include "CIConfigNode.h"

class CIConfigNodeList 
{
public:
	CIConfigNodeList(TiXmlElement* xmlElement);
	CIConfigNodeList(): mNodeTemplate(NULL) { }
	virtual ~CIConfigNodeList();

private:
	CIConfigNodeList(const CIConfigNodeList& rhs) { }
	CIConfigNodeList& operator=(const CIConfigNodeList& rhs) { return *this; }

public:
	virtual CIConfigNodeList* clone() const;
	void addItem(const std::string& name, CIConfigNode* item);
	const CIConfigNode* getConstNode(const std::string& name) const;
	CIConfigNode* getMutableNode(const std::string& name);
	const CIConfigNode* getNodeTemplate() const;
	const std::vector<std::string>& getNodeNames() const { return mNodeNames; }

public:
	size_t getItemCount() const { return mNodeNames.size(); }
	const CIConfigNode* getConstNode(size_t index) const;
	CIConfigNode* getMutableNode(size_t index);
	void clear();

public:
	void setPrefix(const std::string& prefix) { mPrefix=prefix; }
	const std::string& getPrefix() const { return mPrefix; }
	void setName(const std::string& name) { mName=name; }
	const std::string& getName() const { return mName; }
	void setButtonHeight(float height) { mButtonHeight=height; }
	float getButtonHeight() const { return mButtonHeight; }
	void setButtonWidth(float width) { mButtonWidth=width; }
	float getButtonWidth() const { return mButtonWidth; }
	void setWidth(float width) { mWidth=width; }
	float getWidth() const { return mWidth; }
	void setHeight(float height) { mHeight=height; }
	float getHeight() const { return mHeight; }
	void setLabelHeight(float height) { mLabelHeight=height; }
	float getLabelHeight() const { return mLabelHeight; }
	void setVgap(float vgap) { mVgap=vgap; }
	float getVgap() const { return mVgap; }
	void setLabel(const std::string& label) { mLabel=label; }
	const std::string& getLabel() const { return mLabel; }
	void setDetailHeight(float height) { mDetailHeight=height; }
	float getDetailHeight() const { return mDetailHeight; }
	void setItemTemplate(CIConfigNode* item);
	void removeLastItem();

public:
	virtual size_t addItem(CIConfigNode* item);
	virtual CIConfigNode* createItem() const;
	virtual const std::string& getItemName(size_t index) const { return mNodeNames[index]; }

protected:
	virtual std::string getNextItemName() const;

private:
	std::string mPrefix;
	std::string mName;
	std::string mLabel;
	std::vector<std::string> mNodeNames;
	std::map<std::string, CIConfigNode*> mNodes;
	float mButtonHeight;
	float mButtonWidth;
	float mWidth;
	float mHeight;
	float mLabelHeight;
	float mVgap;
	float mDetailHeight;
	CIConfigNode* mNodeTemplate;
};

#endif