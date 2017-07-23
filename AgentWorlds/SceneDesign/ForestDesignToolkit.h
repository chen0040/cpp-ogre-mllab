#ifndef _H_MLLAB_FOREST_DESIGN_TOOLKIT_H
#define _H_MLLAB_FOREST_DESIGN_TOOLKIT_H

#include "../../Widgets/CIWidget.h"
#include "../../Widgets/CITextFieldWidget.h"

class ForestDesignToolkit : public CIWidget
{
public:
	enum ForestDesignAction
	{
		FD_CLEARBUSH,
		FD_POPULATEBUSH,
		FD_CLEARTREE,
		FD_POPULATETREE,
		FD_CLEARGRASS,
		FD_POPULATEGRASS
	};
public:
	ForestDesignToolkit(const std::string& rootId);
	virtual ~ForestDesignToolkit();

public:
	ForestDesignAction getDesignAction() const { return mForestDesignAction; }

protected:
	virtual void create();

protected:
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

private:
	CEGUI::PushButton* mBtnPopulateGrass;
	CEGUI::PushButton* mBtnPopulateTree;
	CEGUI::PushButton* mBtnPopulateBush;
	CEGUI::PushButton* mBtnClearGrass;
	CEGUI::PushButton* mBtnClearTree;
	CEGUI::PushButton* mBtnClearBush;
	std::vector<CEGUI::PushButton*> mButtons;

private:
	CITextFieldWidget* mRadius;
	CITextFieldWidget* mCount;
	CEGUI::Checkbox* mChkAutoPopulate;

public:
	float getRadius() const;
	int getCount() const;
	bool isAutoPopulateEnabled() const { return mChkAutoPopulate->isSelected(); }

protected:
	bool onButtonClicked_PopulateTree(const CEGUI::EventArgs& evt);
	bool onButtonClicked_PopulateGrass(const CEGUI::EventArgs& evt);
	bool onButtonClicked_PopulateBush(const CEGUI::EventArgs& evt);
	bool onButtonClicked_ClearTree(const CEGUI::EventArgs& evt);
	bool onButtonClicked_ClearGrass(const CEGUI::EventArgs& evt);
	bool onButtonClicked_ClearBush(const CEGUI::EventArgs& evt);

private:
	void enableAllButtons();

private:
	CEGUI::Event::Connection mEventPopulateGrass;
	CEGUI::Event::Connection mEventPopulateTree;
	CEGUI::Event::Connection mEventPopulateBush;
	CEGUI::Event::Connection mEventClearGrass;
	CEGUI::Event::Connection mEventClearTree;
	CEGUI::Event::Connection mEventClearBush;

public:
	void show();
	void hide();

private:
	ForestDesignAction mForestDesignAction;
};
#endif