#ifndef _H_ML_LAB_CI_ALGORITHM_WIDGET_H
#define _H_ML_LAB_CI_ALGORITHM_WIDGET_H

#include "../../Widgets/CIWidget.h"

class CIComboWidget;

class CICodeDesignWidget : public CIWidget
{
public:
	CICodeDesignWidget(const std::string& rootId);
	virtual ~CICodeDesignWidget();

protected:
	void enable(bool bEnabled);
	virtual void create();
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

public:
	void show();
	void hide();
	bool isCreating() const;
	bool isSelecting() const;
	bool isAgentPSVisible() const;
	CEGUI::Checkbox* getChkShowPS() { return mChkShowPS; }
	std::string getType() const;
	std::string getMethod() const;
	void setType(const std::string& type);
	void setMethod(const std::string& method);
	void enableTypeSelection(bool enabled);
	void enableMethodSelection(bool enabled);

protected:
	CIComboWidget* mComboType;
	CIComboWidget* mComboMethod;
	CEGUI::RadioButton* mRadioCreate;
	CEGUI::RadioButton* mRadioSelect;
	CEGUI::Checkbox* mChkShowPS;

protected:
	bool mEnabled;

protected:
	bool onClicked_onCreateChecked(const CEGUI::EventArgs& evt);
	bool onItemChanged_CIType(const CEGUI::EventArgs& evt);

protected:
	CEGUI::Event::Connection mEventTypeChange;
	CEGUI::Event::Connection mEventStateChange;
};
#endif