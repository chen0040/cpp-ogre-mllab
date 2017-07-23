#ifndef _H_ML_LAB_CI_CONFIG_LIST_ITEM_H
#define _H_ML_LAB_CI_CONFIG_LIST_ITEM_H

#include "CIConfigSection.h"

class CIConfigListItem : public CIConfigSection
{
public:
	CIConfigListItem(TiXmlElement* xmlElement);
	CIConfigListItem();
	virtual ~CIConfigListItem();
};
#endif