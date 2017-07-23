#ifndef _H_ML_LAB_WEB_BROWSER_WIDGET_H
#define _H_ML_LAB_WEB_BROWSER_WIDGET_H

#include <string>
#include <Ogre.h>
#include <CEGUI/CEGUI.h>
#include "Navi.h"
#include "CIWidget.h"

using namespace Ogre;

class CITextFieldWidget;

class WebBrowser : public CIWidget
{
public:
	WebBrowser(const std::string& rootId, unsigned int width, unsigned int height);
	virtual ~WebBrowser();

public:
	virtual void enable(bool bEnabled);
public:
	virtual void show();
	virtual void hide();
	bool isVisible() const { return mEnabled; }
	
public:
	void resetBrowserWindow(unsigned int width, unsigned int height);
	CEGUI::Window* getBrowserController() { return mRootWindow; }
	NaviLibrary::Navi* getBrowserWindow() { return mNavi; }
	void navigateTo(const std::string& url);
	void bind(const std::string& jsEvent, const NaviLibrary::NaviDelegate& callback);
	void unbind(const std::string& jsEvent);
	bool isLoaded(const std::string& url);
	void setAlpha(float alpha);

protected:
	virtual void create();
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

protected:
	bool onClicked_WindowClosed(const CEGUI::EventArgs& evt);
	bool onClick_GoURL(const CEGUI::EventArgs& evt);
	bool onClick_ForwardURL(const CEGUI::EventArgs& evt);
	bool onClick_BackwardURL(const CEGUI::EventArgs& evt);
	bool onClick_StopURL(const CEGUI::EventArgs& evt);
	bool onScroll_Alpha(const CEGUI::EventArgs& evt);
	bool onTextChange_URL(const CEGUI::EventArgs& evt);

protected:
	bool mEnabled;

protected:
	unsigned int mBrowserWidth;
	unsigned int mBrowserHeight;
	
protected:
	CEGUI::Event::Connection mEventClosed;
	CEGUI::Event::Connection mEventGo;
	CEGUI::Event::Connection mEventForward;
	CEGUI::Event::Connection mEventBackward;
	CEGUI::Event::Connection mEventStop;
	CEGUI::Event::Connection mEventAlphaScroll;
	CEGUI::Event::Connection mEventURLChange;

protected:
	NaviLibrary::Navi* mNavi;
	CITextFieldWidget* mURLField;
	CEGUI::PushButton* mBtnGo;
	CEGUI::PushButton* mBtnForward;
	CEGUI::PushButton* mBtnBackward;
	CEGUI::PushButton* mBtnStop;
	CEGUI::Scrollbar* mAlphaScroller;
	std::string mURL;
};
#endif