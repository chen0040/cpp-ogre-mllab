#include "WebConnectLogin.h"
#include "../HTTPEngine/HTTPManager.h"
#include "../Widgets/GUIManager.h"
#include "../OSEnvironment/OSEnvironment.h"

WebConnectLogin::WebConnectLogin(const std::string& rootId, CEGUI::Window* parentWindow)
: CIWidget(NULL, parentWindow)
{
	this->initializeComponents(rootId);
}

WebConnectLogin::~WebConnectLogin()
{
	mRootWindow->removeChildWindow(mBtnOK);
	mRootWindow->removeChildWindow(mBtnCancel);

	mParentWindow->removeChildWindow(mRootWindow);

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();
	wm->destroyWindow(mBtnOK);
	wm->destroyWindow(mBtnCancel);
	wm->destroyWindow(mRootWindow);
}

void WebConnectLogin::create()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	CEGUI::FrameWindow* frame=static_cast<CEGUI::FrameWindow*>(wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId()));
	mRootWindow=frame;
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.4f), cegui_reldim(0.3f)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0.3f), cegui_reldim(0.33f)));
	mRootWindow->setAlpha(0.6f);
	mRootWindow->setText((CEGUI::utf8*)"Web Connect Login");

	const float btnWidth=0.2f;
	const float btnHeight=0.15f;
	const float txtHeight=0.15f;
	const float txtWidth=0.9f;
	const float vgap=0.01f;
	const float hgap=0.01f;
	const float left=0.05f;
	const float top=0.2f;
	float x=left;
	float y=top;

	mTxtUsername=new CITextFieldWidget(getUIId("txtUsername"), this, mRootWindow, txtWidth, txtHeight, 0.3f);
	mTxtUsername->setLabel("Username: ");
	mTxtUsername->setPosition(x,  y);

	y+=(txtHeight+vgap);
	mTxtPassword=new CITextFieldWidget(getUIId("txtPassWorld"), this, mRootWindow, txtWidth, txtHeight, 0.3f);
	mTxtPassword->setLabel("Password: ");
	mTxtPassword->getEditbox()->setTextMasked(true);
	mTxtPassword->setPosition(x,  y);

	y+=(txtHeight+vgap);
	x=0.5f;
	mBtnOK=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnOK")));
	mBtnOK->setSize(CEGUI::UVector2(cegui_reldim(btnWidth), cegui_reldim(btnHeight)));
	mBtnOK->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnOK->setText((CEGUI::utf8*)" Login ");
	mRootWindow->addChildWindow(mBtnOK);

	x+=(btnWidth+hgap);
	mBtnCancel=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnCancel")));
	mBtnCancel->setSize(CEGUI::UVector2(cegui_reldim(btnWidth), cegui_reldim(btnHeight)));
	mBtnCancel->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnCancel->setText((CEGUI::utf8*)" Cancel ");
	mRootWindow->addChildWindow(mBtnCancel);

	mRootWindow->hide();

	mParentWindow->addChildWindow(mRootWindow);
}

void WebConnectLogin::subscribeEvents()
{
	mEventLoginClosed=mRootWindow->subscribeEvent(CEGUI::FrameWindow::EventCloseClicked, CEGUI::Event::Subscriber(&WebConnectLogin::onLoginCanceled, this));
	mEventLoginOK=mBtnOK->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&WebConnectLogin::onLoginOK, this));
	mEventLoginCanceled=mBtnCancel->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&WebConnectLogin::onLoginCanceled, this));
}

void WebConnectLogin::unsubscribeEvents()
{
	mEventLoginClosed->disconnect();
	mEventLoginOK->disconnect();
	mEventLoginCanceled->disconnect();
}

bool WebConnectLogin::onLoginCanceled(const CEGUI::EventArgs& evt)
{
	this->setModalState(false);
	this->hideWindow();
	HTTPManager::getSingletonPtr()->enable(false);

	return true;
}

bool WebConnectLogin::onLoginOK(const CEGUI::EventArgs &evt)
{
	HTTPManager::getSingletonPtr()->enable(true);
	postLogin();
	return true;
}

void WebConnectLogin::postLogin()
{
	std::map<std::string, std::string> msg;
	std::string result;

	mUsername=mTxtUsername->getText();
	mPassword=mTxtPassword->getText();

	msg["username"]=mUsername;
	msg["password"]=mPassword;
	
	if(HTTPManager::getSingletonPtr()->post("login", msg, result))
	{
		if(result.compare("LOGIN SUCCESSFUL")!=0)
		{
			HTTPManager::getSingletonPtr()->enable(false);
			GUIManager::getSingletonPtr()->showMsgBox("Login Failed", result.c_str());
		}
		else
		{
			this->setModalState(false);
			this->hideWindow();
			GUIManager::getSingletonPtr()->showMsgBox("Login", result.c_str());
		}
	}
}

void WebConnectLogin::showModal()
{
	setModalState(true);
	showWindow();
}

