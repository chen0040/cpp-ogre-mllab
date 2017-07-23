#ifndef _H_ML_LAB_ABOUT_DLG_H
#define _H_ML_LAB_ABOUT_DLG_H

#include "CIWidget.h"

class AboutDlg : public CIWidget
{
public:
	AboutDlg(const std::string& rootId, CEGUI::Window* parentWindow=NULL);
	virtual ~AboutDlg();

public:
	void showModal();

protected:
	virtual void create();
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

public:
	CEGUI::MultiLineEditbox* mScrollableText;

protected:
	bool onCancel(const CEGUI::EventArgs& evt);

public:
	CEGUI::Event::Connection mEventCancel;
};
#endif