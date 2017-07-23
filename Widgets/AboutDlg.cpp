#include "AboutDlg.h"
#include "GUIManager.h"
#include "../OSEnvironment/OSEnvironment.h"

AboutDlg::AboutDlg(const std::string& rootId, CEGUI::Window* parentWindow)
: CIWidget(NULL, parentWindow)
{
	initializeComponents(rootId);
}

void AboutDlg::subscribeEvents()
{
	mEventCancel=mRootWindow->subscribeEvent(CEGUI::FrameWindow::EventCloseClicked, CEGUI::Event::Subscriber(&AboutDlg::onCancel, this));
}

void AboutDlg::unsubscribeEvents()
{
	mEventCancel->disconnect();
}

void AboutDlg::showModal()
{
	setModalState(true);
	showWindow();
}

AboutDlg::~AboutDlg()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow->removeChildWindow(mScrollableText);
	wm->destroyWindow(mScrollableText);

	mParentWindow->removeChildWindow(mRootWindow);
	wm->destroyWindow(mRootWindow);
}

void AboutDlg::create()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow=wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId());
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.4f), cegui_reldim(0.4f)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0.3f), cegui_reldim(0.3f)));
	mRootWindow->setAlpha(0.5);
	mRootWindow->setText((CEGUI::utf8*)"About MLLab");
	mRootWindow->hide();

	mScrollableText=static_cast<CEGUI::MultiLineEditbox*>(wm->createWindow(CIWidget::getGUIType("MultiLineEditbox"), getUIId("scrollPane")));
	mScrollableText->setSize(CEGUI::UVector2(cegui_reldim(0.8f), cegui_reldim(0.7f)));
	mScrollableText->setPosition(CEGUI::UVector2(cegui_reldim(0.1f), cegui_reldim(0.2f)));
	mScrollableText->setText(OSEnvironment::readFile(OSEnvironment::getFullPath("..\\config\\About.txt").c_str()));
	mScrollableText->setReadOnly(true);
	mRootWindow->addChildWindow(mScrollableText);

	mParentWindow->addChildWindow(mRootWindow);
}

bool AboutDlg::onCancel(const CEGUI::EventArgs& evt)
{
	setModalState(false);
	hideWindow();
	
	return true;
}