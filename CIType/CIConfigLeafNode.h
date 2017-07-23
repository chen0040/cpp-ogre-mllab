#ifndef _H_ML_LAB_CI_CONFIG_PARAM_H
#define _H_ML_LAB_CI_CONFIG_PARAM_H

#include "../tinyxml/tinyxml.h"
#include <string>

class CIConfigLeafNode
{
public:
	CIConfigLeafNode(TiXmlElement* xmlElement);
	CIConfigLeafNode(std::string name, 
		std::string value,
		std::string type,
		std::string lowerBound,
		std::string upperBound,
		std::string label,
		float width,
		float height,
		float Vgap,
		float labelWidth)
		: mName(name)
		, mValue(value)
		, mType(type)
		, mLowerBound(lowerBound)
		, mUpperBound(upperBound)
		, mLabel(label)
		, mWidth(width)
		, mHeight(height)
		, mVgap(Vgap)
		, mLabelWidth(labelWidth)
	{

	}
	virtual ~CIConfigLeafNode() { }

private:
	CIConfigLeafNode(const CIConfigLeafNode& rhs) { }
	CIConfigLeafNode& operator=(const CIConfigLeafNode& rhs) { return *this; }

public:
	const std::string& getValue() const { return mValue; }
	const std::string& getLowerBound() const { return mLowerBound; }
	const std::string& getUpperBound() const { return mUpperBound; }
	const std::string& getType() const { return mType; }
	const std::string& getLabel() const { return mLabel; }
	const std::string& getName() const { return mName; }
	bool hasLowerBound() const { return mLowerBound.compare("INFINITE") != 0; }
	bool hasUpperBound() const { return mUpperBound.compare("INFINITE") != 0; }
	float getWidth() const { return mWidth; }
	float getHeight() const { return mHeight; }
	float getLabelWidth() const { return mLabelWidth; }
	float getVgap() const { return mVgap; }

public:
	void setValue(const std::string& value) { mValue=value; }

public:
	virtual CIConfigLeafNode* clone() const
	{
		return new CIConfigLeafNode(mName, mValue, mType, mLowerBound, mUpperBound, mLabel, mWidth, mHeight, mVgap, mLabelWidth);
	}

private:
	std::string mValue;
	std::string mType;
	std::string mLowerBound;
	std::string mUpperBound;
	std::string mLabel;
	std::string mName;
	float mWidth;
	float mHeight;
	float mVgap;
	float mLabelWidth;
};
#endif