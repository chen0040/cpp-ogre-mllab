#ifndef _H_ML_LAB_WEATHER_DLG_H
#define _H_ML_LAB_WEATHER_DLG_H

#include <Ogre.h>
#include "CIWidget.h"

class WeatherDlg : public CIWidget
{
public:
	WeatherDlg(const std::string& rootId);
	virtual ~WeatherDlg();

protected:
	virtual void create();
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();	

public:
	void showModal();

protected:
	bool onClicked_Cancel(const CEGUI::EventArgs& evt);
	bool onChecked_ShowRain(const CEGUI::EventArgs& evt);
	bool onChecked_ShowSnow(const CEGUI::EventArgs& evt);

protected:
	void hide();

protected:
	CEGUI::Event::Connection mEventCancel;
	CEGUI::Event::Connection mEventClose;

protected:
	CEGUI::PushButton* mBtnCancel;
	CEGUI::Checkbox* mChkShowRain;
	CEGUI::Checkbox* mChkShowSnow;
	static size_t mNumWeatherDlgShown;

protected:
	CEGUI::Event::Connection mEventShowRain;
	CEGUI::Event::Connection mEventShowSnow;
};

#endif

