#ifndef _H_MLLAB_HYDRAX_DESIGN_TOOLKIT_H
#define _H_MLLAB_HYDRAX_DESIGN_TOOLKIT_H

#include "../../Widgets/CIWidget.h"
#include "OceanDesignToolkit.h"

class HydraxDesignToolkit : public CIWidget
{
public:
	enum HydraxDesignAction
	{
		HD_DISABLE,
		HD_HYDRAX,
		HD_OCEAN
	};
public:
	HydraxDesignToolkit(const std::string& rootId);
	virtual ~HydraxDesignToolkit();

public:
	HydraxDesignAction getDesignAction() const { return mHydraxDesignAction; }

protected:
	virtual void create();

protected:
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

private:
	CEGUI::PushButton* mBtnDisable;
	CEGUI::PushButton* mBtnHydrax;
	CEGUI::PushButton* mBtnOcean;
	std::vector<CEGUI::PushButton*> mButtons;

protected:
	bool onButtonClicked_Hydrax(const CEGUI::EventArgs& evt);
	bool onButtonClicked_Disable(const CEGUI::EventArgs& evt);
	bool onButtonClicked_Ocean(const CEGUI::EventArgs& evt);

private:
	void enableAllButtons();

private:
	CEGUI::Event::Connection mEventDisable;
	CEGUI::Event::Connection mEventHydrax;
	CEGUI::Event::Connection mEventOcean;

public:
	void show();
	void hide();

private:
	HydraxDesignAction mHydraxDesignAction;

private:
	OceanDesignToolkit* mOceanDesignToolkit;
};
#endif