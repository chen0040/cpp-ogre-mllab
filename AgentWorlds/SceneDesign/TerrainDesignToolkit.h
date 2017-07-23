#ifndef _H_MLLAB_TERRAIN_DESIGN_TOOLKIT_H
#define _H_MLLAB_TERRAIN_DESIGN_TOOLKIT_H

#include "../../Widgets/CIWidget.h"

class TerrainDesignToolkit : public CIWidget
{
public:
	enum TerrainDesignAction
	{
		TD_DIG,
		TD_ELEVATE,
		TD_PAINT0,
		TD_PAINT1,
		TD_PAINT2,
		TD_PAINT3,
		TD_PAINT4,
		TD_PAINT5
	};
public:
	TerrainDesignToolkit(const std::string& rootId);
	virtual ~TerrainDesignToolkit();

public:
	TerrainDesignAction getDesignAction() const { return mTerrainDesignAction; }

protected:
	virtual void create();

protected:
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

private:
	CEGUI::PushButton* mBtnDig;
	CEGUI::PushButton* mBtnElevate;
	CEGUI::PushButton* mBtnPaint0;
	CEGUI::PushButton* mBtnPaint1;
	CEGUI::PushButton* mBtnPaint2;
	CEGUI::PushButton* mBtnPaint3;
	CEGUI::PushButton* mBtnPaint4;
	CEGUI::PushButton* mBtnPaint5;
	std::vector<CEGUI::PushButton*> mButtons;

protected:
	bool onButtonClicked_Dig(const CEGUI::EventArgs& evt);
	bool onButtonClicked_Elevate(const CEGUI::EventArgs& evt);
	bool onButtonClicked_Paint0(const CEGUI::EventArgs& evt);
	bool onButtonClicked_Paint1(const CEGUI::EventArgs& evt);
	bool onButtonClicked_Paint2(const CEGUI::EventArgs& evt);
	bool onButtonClicked_Paint3(const CEGUI::EventArgs& evt);
	bool onButtonClicked_Paint4(const CEGUI::EventArgs& evt);
	bool onButtonClicked_Paint5(const CEGUI::EventArgs& evt);

private:
	void enableAllButtons();

private:
	CEGUI::Event::Connection mEventDig;
	CEGUI::Event::Connection mEventElevate;
	CEGUI::Event::Connection mEventPaint0;
	CEGUI::Event::Connection mEventPaint1;
	CEGUI::Event::Connection mEventPaint2;
	CEGUI::Event::Connection mEventPaint3;
	CEGUI::Event::Connection mEventPaint4;
	CEGUI::Event::Connection mEventPaint5;

private:
	TerrainDesignAction mTerrainDesignAction;
};
#endif