#ifndef _H_ML_LAB_GAME_DESIGN_WIDGET_H
#define _H_ML_LAB_GAME_DESIGN_WIDGET_H

#include "../../Widgets/CIWidget.h"

class CIGameDesignWidget : public CIWidget
{
public:
	CIGameDesignWidget(const std::string& rootId);
	virtual ~CIGameDesignWidget();

public:
	virtual void show() { setVisible(true); }
	virtual void hide() { setVisible(false); }
	bool isVisible() const { return mEnabled; }
	bool isSelecting() const { return mRadioSelect->isSelected(); }
	bool isCreating() const { return mRadioCreate->isSelected(); }
	bool isSimulating() const { return mRadioSimulate->isSelected(); }

protected:
	virtual void setVisible(bool bEnabled);

protected:
	virtual void create();

protected:
	bool mEnabled;

protected:
	CEGUI::RadioButton* mRadioCreate;
	CEGUI::RadioButton* mRadioSelect;
	CEGUI::RadioButton* mRadioSimulate;

protected:
	bool onSelectionChanged_Create(const CEGUI::EventArgs& evt);
	bool onSelectionChanged_Select(const CEGUI::EventArgs& evt);
	bool onSelectionChanged_Simulate(const CEGUI::EventArgs& evt);
};
#endif