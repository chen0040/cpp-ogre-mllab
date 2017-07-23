#include "CIConfigLeafNode.h"

CIConfigLeafNode::CIConfigLeafNode(TiXmlElement* xmlElement)
{
	mName=xmlElement->Attribute("name");
	mValue=xmlElement->Attribute("value");
	mType=xmlElement->Attribute("type");
	mLowerBound=xmlElement->Attribute("lower_bound");
	mUpperBound=xmlElement->Attribute("upper_bound");
	mLabel=xmlElement->Attribute("label");
	xmlElement->QueryFloatAttribute("width", &mWidth);
	xmlElement->QueryFloatAttribute("height", &mHeight);
	xmlElement->QueryFloatAttribute("label_width", &mLabelWidth);
	xmlElement->QueryFloatAttribute("vgap", &mVgap);
}