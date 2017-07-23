#ifndef _H_MLLAB_OCEAN_DESIGN_TOOLKIT_H
#define _H_MLLAB_OCEAN_DESIGN_TOOLKIT_H

#include "../../Widgets/CIWidget.h"
#include "../../Widgets/CITextFieldWidget.h"

class OceanDesignToolkit : public CIWidget
{
public:
	OceanDesignToolkit(const std::string& rootId);
	virtual ~OceanDesignToolkit();

protected:
	virtual void create();

protected:
	void subscribeEvents();
	void unsubscribeEvents();

private:
	CITextFieldWidget* mEditHeight;
	CITextFieldWidget* mEditSizeX;
	CITextFieldWidget* mEditSizeZ;
	CEGUI::PushButton* mBtnApply;

private:
	CEGUI::Event::Connection mEventApply;

protected:
	bool onButtonClicked_Apply(const CEGUI::EventArgs& evt);

public:
	void show();
};

#endif