#ifndef _H_MLLAB_SKY_DESIGN_TOOLKIT_H
#define _H_MLLAB_SKY_DESIGN_TOOLKIT_H

#include "../../Widgets/CIWidget.h"
#include "CaelumDesignToolkit.h"

class SkyDesignToolkit : public CIWidget
{
public:
	enum SkyDesignAction
	{
		SKYD_BOX,
		SKYD_PLANE,
		SKYD_DOME,
		SKYD_CAELUM,
		SKYD_DISABLE,
	};
public:
	SkyDesignToolkit(const std::string& rootId);
	virtual ~SkyDesignToolkit();

public:
	SkyDesignAction getDesignAction() const { return mSkyDesignAction; }

protected:
	virtual void create();

protected:
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

private:
	CEGUI::PushButton* mBtnSkyBox;
	CEGUI::PushButton* mBtnSkyPlane;
	CEGUI::PushButton* mBtnSkyDome;
	CEGUI::PushButton* mBtnSkyCaelum;
	CEGUI::PushButton* mBtnSkyDisable;
	std::vector<CEGUI::PushButton*> mButtons;
	CEGUI::Listbox* mSkyTypeUriListBox;

protected:
	bool onButtonClicked_SkyBox(const CEGUI::EventArgs& evt);
	bool onButtonClicked_SkyPlane(const CEGUI::EventArgs& evt);
	bool onButtonClicked_SkyDome(const CEGUI::EventArgs& evt);
	bool onButtonClicked_SkyCaelum(const CEGUI::EventArgs& evt);
	bool onButtonClicked_SkyDisable(const CEGUI::EventArgs& evt);

private:
	void enableAllButtons();

private:
	CEGUI::Event::Connection mEventSkyBox;
	CEGUI::Event::Connection mEventSkyPlane;
	CEGUI::Event::Connection mEventSkyDome;
	CEGUI::Event::Connection mEventSkyCaelum;
	CEGUI::Event::Connection mEventSkyDisable;

private:
	CEGUI::Event::Connection mEventListSelectionChanged;
protected:
	bool onSelectionChanged_SkyTypeUri(const CEGUI::EventArgs& evt);

public:
	void show();
	void hide();

private:
	void updateSkyTypeUriUI();

private:
	SkyDesignAction mSkyDesignAction;

private:
	CaelumDesignToolkit* mCaelumDesignToolkit;

private:
	std::vector<std::string> mSkyBoxes;
	std::vector<std::string> mSkyPlanes;
	std::vector<std::string> mSkyDomes;
};
#endif