#ifndef _H_ML_LAB_CI_CONFIG_NODE_TAB_PANEL_WIDGET_H
#define _H_ML_LAB_CI_CONFIG_NODE_TAB_PANEL_WIDGET_H

#include <map>
#include <string>
#include "../../Widgets/CIWidget.h"
#include "../../CIType/CIConfigNode.h"
#include "CIConfigNodeListWidget.h"
#include "../../Widgets/CITextFieldWidget.h"
#include "../../tinyxml/tinyxml.h"

class CIConfigNodeTabWidget : public CIWidget
{
public:
	CIConfigNodeTabWidget(const std::string& rootId, const CIConfigNode* section, CIWidget* parentWidget, CEGUI::TabControl* parentWindow);
	virtual ~CIConfigNodeTabWidget();

protected:
	virtual void create();

public:
	void doPassByParam(std::vector<std::string>& lines) const;
	void doPassByTemplate(const std::string& destinationFile, const std::string& fileType) const;

public:
	virtual void doSave();
	virtual void doLoad();
	virtual void saveXml(TiXmlElement* xmlNode);
	virtual void loadXml(TiXmlElement* xmlNode);
	virtual std::string toString() const;

protected:
	std::map<std::string, CITextFieldWidget*> mTextFieldWidgets;
	std::map<std::string, CIConfigNodeListWidget*> mListWidgets;
	const CIConfigNode* mSection;
};
#endif