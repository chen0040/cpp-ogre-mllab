#ifndef _H_ML_LAB_CI_COMBO_WIDGET_H
#define _H_ML_LAB_CI_COMBO_WIDGET_H

#include <CEGUI/CEGUI.h>
#include "CIWidget.h"
#include "../CIType/CIConfigLeafNode.h"

class CIComboWidget : public CIWidget
{
public:
	CIComboWidget(const std::string& rootId, const CIConfigLeafNode* param, CIWidget* parentWidget, CEGUI::Window* parentWindow);
	CIComboWidget(const std::string& rootId, CIWidget* parentWidget, CEGUI::Window* parentWindow,  float width, float height, float labelWidth);
	virtual ~CIComboWidget();

public:
	const CIConfigLeafNode* getConstLeafNode() const;
	CIConfigLeafNode* getMutableLeafNode();
	CEGUI::Combobox* getCombobox() { return mCombobox; }
	void setEnabled(bool enabled) { mCombobox->setEnabled(enabled); }

public:
	virtual void doPassByParam(std::vector<std::string>& lines) const;

private:
	virtual void create();

public:
	virtual void doLoad();
	virtual void doSave();
	virtual std::string toString() const;
	void setLabel(const std::string& label);
	void setText(const std::string& value);
	std::string getText() const;

protected:
	CIConfigLeafNode* mParam;
	CEGUI::Combobox* mCombobox;
	CEGUI::DefaultWindow* mLabel;
	float mWidth;
	float mHeight;
	float mLabelWidth;
};
#endif