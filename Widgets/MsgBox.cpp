#include "MsgBox.h"
#include <sstream>
#include "GUIManager.h"
#include "../SoundEngine/SoundManager.h"
#include "../OSEnvironment/OSEnvironment.h"

size_t MsgBox::mNumMsgBoxShown=0;

MsgBox::MsgBox(const std::string& rootId)
: CIWidget(NULL, NULL)
{
	initializeComponents(rootId);
}

MsgBox::~MsgBox()
{
	mRootWindow->removeChildWindow(mEditBox);
	mParentWindow->removeChildWindow(mRootWindow);

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow->removeChildWindow(mEditBox);
	mParentWindow->removeChildWindow(mRootWindow);

	wm->destroyWindow(mEditBox);
	wm->destroyWindow(mRootWindow);
}

void MsgBox::showModal(const std::string& title, const std::string& text)
{
	mRootWindow->setText(title);
	mEditBox->setText(text);
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.4f), cegui_reldim(0.2f)));

	setModalState(true);

	mRootWindow->setPosition(CEGUI::UVector2(CEGUI::UDim(0.3f, 10.0f*mNumMsgBoxShown), CEGUI::UDim(0.4f, 10.0f * mNumMsgBoxShown)));
	showWindow();
	mNumMsgBoxShown++;

	SoundManager::getSingletonPtr()->play("msgbox");
}

void MsgBox::create()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();
	mRootWindow=wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId());
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.4f), cegui_reldim(0.2f)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0.3f), cegui_reldim(0.4f)));
	mRootWindow->setAlpha(0.8f);

	mEditBox=static_cast<CEGUI::MultiLineEditbox*>(wm->createWindow(CIWidget::getGUIType("MultiLineEditbox"), getUIId("editBox")));
	mEditBox->setSize(CEGUI::UVector2(cegui_reldim(0.9f), cegui_reldim(0.75f)));
	mEditBox->setPosition(CEGUI::UVector2(cegui_reldim(0.05f), cegui_reldim(0.2f)));
	mEditBox->setReadOnly(true);
	mRootWindow->addChildWindow(mEditBox);

	mParentWindow->addChildWindow(mRootWindow);
}

void MsgBox::subscribeEvents()
{
	mEventCancel=mRootWindow->subscribeEvent(CEGUI::FrameWindow::EventCloseClicked, CEGUI::Event::Subscriber(&MsgBox::onClicked_Cancel, this));
}

void MsgBox::unsubscribeEvents()
{
	mEventCancel->disconnect();
}

bool MsgBox::onClicked_Cancel(const CEGUI::EventArgs& evt)
{
	setModalState(false);
	hideWindow();
	GUIManager::getSingletonPtr()->hideMsgBox(this);

	mNumMsgBoxShown--;

	return true;
}
