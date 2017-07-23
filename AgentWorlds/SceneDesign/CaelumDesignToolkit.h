#ifndef _H_MLLAB_CAELUM_DESIGN_TOOLKIT_H
#define _H_MLLAB_CAELUM_DESIGN_TOOLKIT_H

#include "../../Widgets/CIWidget.h"
#include "../../Widgets/CITextFieldWidget.h"

class CaelumDesignToolkit : public CIWidget
{
public:
	CaelumDesignToolkit(const std::string& rootId);
	virtual ~CaelumDesignToolkit();

protected:
	virtual void create();

protected:
	void subscribeEvents();
	void unsubscribeEvents();

private:
	CITextFieldWidget* mEditTimeScale;
	CITextFieldWidget* mEditCloudSpeedX;
	CITextFieldWidget* mEditCloudSpeedY;
	CITextFieldWidget* mEditYear;
	CITextFieldWidget* mEditMonth;
	CITextFieldWidget* mEditDay;
	CITextFieldWidget* mEditHour;
	CITextFieldWidget* mEditMinute;
	CITextFieldWidget* mEditSecond;
	CEGUI::PushButton* mBtnApply;
	CEGUI::Checkbox* mChkLightingEnabled;

private:
	CEGUI::Event::Connection mEventApply;

protected:
	bool onButtonClicked_Apply(const CEGUI::EventArgs& evt);

public:
	void show();
};

#endif