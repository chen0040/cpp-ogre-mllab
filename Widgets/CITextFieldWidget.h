#ifndef _H_ML_LAB_CI_TEXT_FIELD_WIDGET_H
#define _H_ML_LAB_CI_TEXT_FIELD_WIDGET_H

#include <CEGUI/CEGUI.h>
#include "CIWidget.h"
#include "../CIType/CIConfigLeafNode.h"
#include "../tinyxml/tinyxml.h"

class CITextFieldWidget : public CIWidget
{
public:
	CITextFieldWidget(const std::string& rootId, const CIConfigLeafNode* param, CIWidget* parentWidget, CEGUI::Window* parentWindow);
	CITextFieldWidget(const std::string& rootId, CIWidget* parentWidget, CEGUI::Window* parentWindow,  float width, float height, float labelWidth);
	virtual ~CITextFieldWidget();

public:
	const CIConfigLeafNode* getConstLeafNode() const;
	CIConfigLeafNode* getMutableLeafNode();

public:
	virtual void doPassByParam(std::vector<std::string>& lines) const;
	virtual void loadXml(TiXmlElement* xmlNode);
	virtual void saveXml(TiXmlElement* xmlNode);

private:
	virtual void create();

public:
	virtual void doLoad();
	virtual void doSave();
	virtual std::string toString() const;
	void setLabel(const std::string& label);
	void setText(const std::string& value);
	void setText(float value);
	std::string getText() const;
	CEGUI::Editbox* getEditbox() { return mEditbox; }

protected:
	CIConfigLeafNode* mParam;
	CEGUI::Editbox* mEditbox;
	CEGUI::DefaultWindow* mLabel;
	float mWidth;
	float mHeight;
	float mLabelWidth;
};
#endif