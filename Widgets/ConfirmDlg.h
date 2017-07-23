#ifndef _H_ML_LAB_CONFIRM_DLG_H
#define _H_ML_LAB_CONFIRM_DLG_H

#include <Ogre.h>
#include "CIWidget.h"
#include <boost/bind.hpp>
#include <boost/signal.hpp>

class ConfirmDlg : public CIWidget
{
public:
	ConfirmDlg(const std::string& rootId);
	virtual ~ConfirmDlg();

protected:
	virtual void create();
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();	

public:
	void showModal(const std::string& title, const std::string& text);

protected:
	bool onClicked_Cancel(const CEGUI::EventArgs& evt);
	bool onClicked_OK(const CEGUI::EventArgs& evt);

public:
	boost::signals::connection subscribeEvent_onConfirm(boost::signal<void ()>::slot_function_type subscriber);

protected:
	void hide();

protected:
	CEGUI::Event::Connection mEventCancel;
	CEGUI::Event::Connection mEventClose;
	CEGUI::Event::Connection mEventOK;

protected:
	CEGUI::MultiLineEditbox* mEditBox;
	CEGUI::PushButton* mBtnOK;
	CEGUI::PushButton* mBtnCancel;
	static size_t mNumConfirmDlgShown;
	boost::signal<void ()> mSigConfirm;
};

#endif

