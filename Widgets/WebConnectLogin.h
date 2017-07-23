#ifndef _H_ML_LAB_WEB_CONNECT_LOGIN_H
#define _H_ML_LAB_WEB_CONNECT_LOGIN_H

#include "CIWidget.h"
#include "CITextFieldWidget.h"

class WebConnectLogin : public CIWidget
{
public:
	WebConnectLogin(const std::string& rootId, CEGUI::Window* parentWindow=NULL);
	virtual ~WebConnectLogin();

protected:
	virtual void create();
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

protected:
	bool onLoginCanceled(const CEGUI::EventArgs& evt);
	bool onLoginOK(const CEGUI::EventArgs& evt);
	void postLogin();

public:
	void showModal();

protected:
	CEGUI::PushButton* mBtnOK;
	CEGUI::PushButton* mBtnCancel;

	CITextFieldWidget* mTxtUsername;
	CITextFieldWidget* mTxtPassword;

protected:
	CEGUI::Event::Connection mEventLoginClosed;
	CEGUI::Event::Connection mEventLoginCanceled;
	CEGUI::Event::Connection mEventLoginOK;

	std::string mUsername;
	std::string mPassword;

public:
	const std::string& getUsername() const { return mUsername; }
};
#endif