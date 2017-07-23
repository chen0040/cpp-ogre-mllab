#include "WebBrowser.h"
#include "GUIManager.h"
#include "CITextFieldWidget.h"
#include "WebPage.h"
#include "../OSEnvironment/OSEnvironment.h"
#include "../GameEngine/Application.h"

WebBrowser::WebBrowser(const std::string& rootId, unsigned int width, unsigned int height)
: CIWidget(NULL, NULL)
, mEnabled(true)
, mBrowserWidth(width)
, mBrowserHeight(height)
, mNavi(NULL)
{
	initializeComponents(rootId);
}

void WebBrowser::create()
{
	const std::string& defaultURL=GUIManager::getSingletonPtr()->getDefaultWebPage()->getURL();
	mNavi=NaviLibrary::NaviManager::GetPointer()->createNavi(getUIId("BrowserWindow"), defaultURL, NaviLibrary::NaviPosition(10, 50), mBrowserWidth, mBrowserHeight);

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();
	mRootWindow=static_cast<CEGUI::FrameWindow*>(wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId()));
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.6f), cegui_reldim(0.15f)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0.1f), cegui_reldim(0.8f)));
	mRootWindow->setAlpha(0.7f);
	mRootWindow->setText((CEGUI::utf8*)"Browser Controller");

	mParentWindow->addChildWindow(mRootWindow);

	float height=0.25f;
	float vgap=0.05f;
	float hgap=0.005f;
	float top=0.3f;
	float left=0.05f;
	float buttonWidth=0.1f;
	float textWidth=0.78f;

	float y=top;
	float x=left;
	mURLField=new CITextFieldWidget(getUIId("URLField"), this, mRootWindow, textWidth, height, 0.1f); 
	mURLField->setPosition(x, y);
	mURLField->setLabel("URL:");
	mURLField->setText(defaultURL);

	x+=(textWidth+hgap);
	mBtnGo=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("GoButton")));
	mRootWindow->addChildWindow(mBtnGo);
	mBtnGo->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(height)));
	mBtnGo->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnGo->setText((CEGUI::utf8*)"Go");

	y+=(height+vgap);
	x=left;
	mBtnForward=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("ForwardButton")));
	mRootWindow->addChildWindow(mBtnForward);
	mBtnForward->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(height)));
	mBtnForward->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnForward->setText((CEGUI::utf8*)">>");

	x+=(hgap+buttonWidth);
	mBtnBackward=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("BackwardButton")));
	mRootWindow->addChildWindow(mBtnBackward);
	mBtnBackward->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(height)));
	mBtnBackward->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnBackward->setText((CEGUI::utf8*)"<<");

	x+=(hgap+buttonWidth);
	mBtnStop=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("StopButton")));
	mRootWindow->addChildWindow(mBtnStop);
	mBtnStop->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(height)));
	mBtnStop->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnStop->setText((CEGUI::utf8*)"X");

	float sliderWidth=0.5f;
	float sliderHeight=0.15f;
	x+=(hgap+buttonWidth);
	mAlphaScroller=static_cast<CEGUI::Scrollbar*>(wm->createWindow(CIWidget::getGUIType("HorizontalScrollbar"), getUIId("AlphaSlider")));
	mRootWindow->addChildWindow(mAlphaScroller);
	mAlphaScroller->setSize(CEGUI::UVector2(cegui_reldim(sliderWidth), cegui_reldim(sliderHeight)));
	mAlphaScroller->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y+0.05f)));
	mAlphaScroller->setScrollPosition(1.0f);
}

void WebBrowser::subscribeEvents()
{
	mEventClosed=mRootWindow->subscribeEvent(CEGUI::FrameWindow::EventCloseClicked, CEGUI::Event::Subscriber(&WebBrowser::onClicked_WindowClosed, this));
	mEventGo=mBtnGo->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&WebBrowser::onClick_GoURL, this));
	mEventForward=mBtnForward->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&WebBrowser::onClick_ForwardURL, this));
	mEventBackward=mBtnBackward->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&WebBrowser::onClick_BackwardURL, this));
	mEventStop=mBtnStop->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&WebBrowser::onClick_StopURL, this));
	mEventAlphaScroll=mAlphaScroller->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged, CEGUI::Event::Subscriber(&WebBrowser::onScroll_Alpha, this));
	mEventURLChange= mURLField->getEditbox()->subscribeEvent(CEGUI::Editbox::EventTextAccepted, CEGUI::Event::Subscriber(&WebBrowser::onTextChange_URL, this));
}

void WebBrowser::unsubscribeEvents()
{
	mEventClosed->disconnect();
	mEventGo->disconnect();
	mEventForward->disconnect();
	mEventBackward->disconnect();
	mEventStop->disconnect();
	mEventURLChange->disconnect();
}

WebBrowser::~WebBrowser()
{
	if(mURLField != NULL)
	{
		delete mURLField;
		mURLField=NULL;
	}

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow->removeChildWindow(mBtnGo);
	mRootWindow->removeChildWindow(mBtnForward);
	mRootWindow->removeChildWindow(mBtnBackward);
	mRootWindow->removeChildWindow(mBtnStop);
	mRootWindow->removeChildWindow(mAlphaScroller);
	mParentWindow->removeChildWindow(mRootWindow);

	wm->destroyWindow(mBtnGo);
	wm->destroyWindow(mBtnForward);
	wm->destroyWindow(mBtnBackward);
	wm->destroyWindow(mBtnStop);
	wm->destroyWindow(mAlphaScroller);
	wm->destroyWindow(mRootWindow);
}

void WebBrowser::show()
{
	this->enable(true);
}

void WebBrowser::resetBrowserWindow(unsigned int width, unsigned int height)
{
	if(mNavi != NULL)
	{
		NaviLibrary::NaviManager::GetPointer()->destroyNavi(mNavi);
	}
	mBrowserWidth=width;
	mBrowserHeight=height;

	const std::string& defaultURL=GUIManager::getSingletonPtr()->getDefaultWebPage()->getURL();
	mNavi=NaviLibrary::NaviManager::GetPointer()->createNavi(getUIId("Navi"), defaultURL, NaviLibrary::NaviPosition(NaviLibrary::Center), mBrowserWidth, mBrowserHeight);
	mNavi->setOpacity(mAlphaScroller->getScrollPosition());
}

void WebBrowser::hide()
{
	this->enable(false);
}

void WebBrowser::enable(bool bEnabled)
{
	mEnabled=bEnabled;
	if(mEnabled)
	{
		mRootWindow->show();
		if(mNavi != NULL)
		{
			mNavi->show();
		}
	}
	else
	{
		mRootWindow->hide();
		if(mNavi != NULL)
		{
			mNavi->hide();
		}
	}
}

bool WebBrowser::onClicked_WindowClosed(const CEGUI::EventArgs& evt)
{
	this->enable(false);
	return true;
}

bool WebBrowser::onClick_GoURL(const CEGUI::EventArgs& evt)
{
	navigateTo(mURLField->getText());
	return true;
}

bool WebBrowser::onClick_BackwardURL(const CEGUI::EventArgs& evt)
{
	mNavi->navigateBack();
	return true;
}

bool WebBrowser::onClick_ForwardURL(const CEGUI::EventArgs& evt)
{
	mNavi->navigateForward();
	return true;
}

bool WebBrowser::onClick_StopURL(const CEGUI::EventArgs& evt)
{
	mNavi->navigateStop();
	return true;
}

void WebBrowser::setAlpha(float alpha)
{
	if(alpha < 0.05)
	{
		if(mNavi->getVisibility())
		{
			mNavi->hide();
		}
	}
	else
	{
		if(!mNavi->getVisibility())
		{
			mNavi->show();
		}
		mNavi->setOpacity(alpha);
	}

	mAlphaScroller->setScrollPosition(alpha);
}

bool WebBrowser::onScroll_Alpha(const CEGUI::EventArgs& evt)
{
	float alpha=mAlphaScroller->getScrollPosition();
	if(alpha < 0.05)
	{
		if(mNavi->getVisibility())
		{
			mNavi->hide();
		}
	}
	else
	{
		if(!mNavi->getVisibility())
		{
			mNavi->show();
		}
		mNavi->setOpacity(alpha);
	}
	
	return true;
}

bool WebBrowser::onTextChange_URL(const CEGUI::EventArgs& evt)
{
	navigateTo(mURLField->getText());
	return true;
}

void WebBrowser::navigateTo(const std::string& url)
{
	WebPage* page=GUIManager::getSingletonPtr()->getWebPage(url) ;
	if(page== NULL)
	{
		mNavi->setMask("");
		mNavi->navigateTo(url.c_str());
		mURL=url;
	}
	else
	{
		mNavi->setMask(page->getMaskFile());
		mNavi->navigateTo(page->getURL());
		mURL=page->getURL();
	}
	
}

bool WebBrowser::isLoaded(const std::string& url)
{
	WebPage* page=GUIManager::getSingletonPtr()->getWebPage(url) ;
	if(page== NULL)
	{
		return mURL.compare(url)==0;
	}
	else
	{
		return mURL.compare(page->getURL())==0;
	}
}

void WebBrowser::bind(const std::string& jsEvent, const NaviLibrary::NaviDelegate& callback)
{
	mNavi->bind(jsEvent, callback);
}

void WebBrowser::unbind(const std::string& jsEvent)
{
	mNavi->unbind(jsEvent);
}