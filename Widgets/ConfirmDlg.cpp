#include "ConfirmDlg.h"
#include <sstream>
#include "GUIManager.h"

size_t ConfirmDlg::mNumConfirmDlgShown=0;

ConfirmDlg::ConfirmDlg(const std::string& rootId)
: CIWidget(NULL, NULL)
{
	initializeComponents(rootId);
}

ConfirmDlg::~ConfirmDlg()
{
	mRootWindow->removeChildWindow(mEditBox);
	mParentWindow->removeChildWindow(mRootWindow);

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow->removeChildWindow(mEditBox);
	mRootWindow->removeChildWindow(mBtnOK);
	mRootWindow->removeChildWindow(mBtnCancel);
	mParentWindow->removeChildWindow(mRootWindow);

	wm->destroyWindow(mEditBox);
	wm->destroyWindow(mBtnOK);
	wm->destroyWindow(mBtnCancel);
	wm->destroyWindow(mRootWindow);
}

void ConfirmDlg::showModal(const std::string& title, const std::string& text)
{
	mRootWindow->setText(title);
	mEditBox->setText(text);
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.4f), cegui_reldim(0.3f)));

	setModalState(true);

	mRootWindow->setPosition(CEGUI::UVector2(CEGUI::UDim(0.3f, 10.0f*mNumConfirmDlgShown), CEGUI::UDim(0.35f, 10.0f * mNumConfirmDlgShown)));
	showWindow();
	mNumConfirmDlgShown++;
}

void ConfirmDlg::create()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();
	mRootWindow=wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId());
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.4f), cegui_reldim(0.3f)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0.3f), cegui_reldim(0.35f)));
	mRootWindow->setAlpha(0.8f);

	mEditBox=static_cast<CEGUI::MultiLineEditbox*>(wm->createWindow(CIWidget::getGUIType("MultiLineEditbox"), getUIId("editBox")));
	mEditBox->setSize(CEGUI::UVector2(cegui_reldim(0.9f), cegui_reldim(0.6f)));
	mEditBox->setPosition(CEGUI::UVector2(cegui_reldim(0.05f), cegui_reldim(0.15f)));
	mEditBox->setReadOnly(true);
	mRootWindow->addChildWindow(mEditBox);

	mBtnOK=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnOK")));
	mBtnOK->setSize(CEGUI::UVector2(cegui_reldim(0.3f), cegui_reldim(0.15f)));
	mBtnOK->setPosition(CEGUI::UVector2(cegui_reldim(0.2f), cegui_reldim(0.81f)));
	mBtnOK->setText((CEGUI::utf8*)"OK");
	mRootWindow->addChildWindow(mBtnOK);

	mBtnCancel=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnCancel")));
	mBtnCancel->setSize(CEGUI::UVector2(cegui_reldim(0.3f), cegui_reldim(0.15f)));
	mBtnCancel->setPosition(CEGUI::UVector2(cegui_reldim(0.51f), cegui_reldim(0.81f)));
	mBtnCancel->setText((CEGUI::utf8*)"Cancel");
	mRootWindow->addChildWindow(mBtnCancel);

	mRootWindow->setVisible(false);
	mParentWindow->addChildWindow(mRootWindow);
}

void ConfirmDlg::subscribeEvents()
{
	mEventClose=mRootWindow->subscribeEvent(CEGUI::FrameWindow::EventCloseClicked, CEGUI::Event::Subscriber(&ConfirmDlg::onClicked_Cancel, this));
	mEventCancel=mBtnCancel->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ConfirmDlg::onClicked_Cancel, this));
	mEventOK=mBtnOK->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ConfirmDlg::onClicked_OK, this));
}

void ConfirmDlg::unsubscribeEvents()
{
	mEventCancel->disconnect();
	mEventClose->disconnect();
	mEventOK->disconnect();
}

bool ConfirmDlg::onClicked_Cancel(const CEGUI::EventArgs& evt)
{
	hide();
	return true;
}

bool ConfirmDlg::onClicked_OK(const CEGUI::EventArgs& evt)
{
	hide();
	mSigConfirm();
	return true;
}

void ConfirmDlg::hide()
{
	setModalState(false);
	hideWindow();

	mNumConfirmDlgShown--;
}

boost::signals::connection ConfirmDlg::subscribeEvent_onConfirm(boost::signal<void ()>::slot_function_type subscriber)
{
	return mSigConfirm.connect(subscriber);
}