#include "GameLoaderSaveAsDlg.h"

GameLoaderSaveAsDlg::GameLoaderSaveAsDlg(const std::string& rootId)
: CIWidget(NULL, NULL)
{
	this->initializeComponents(rootId);
}

GameLoaderSaveAsDlg::~GameLoaderSaveAsDlg()
{
	if(mEditGameLoaderName != NULL)
	{
		delete mEditGameLoaderName;
		mEditGameLoaderName=NULL;
	}
}

void GameLoaderSaveAsDlg::subscribeEvents()
{
	mEventClose=mRootWindow->subscribeEvent(CEGUI::FrameWindow::EventCloseClicked, CEGUI::Event::Subscriber(&GameLoaderSaveAsDlg::onCloseClicked_Close, this));
	mEventCancel=mBtnCancel->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GameLoaderSaveAsDlg::onButtonClicked_Cancel, this));
}

void GameLoaderSaveAsDlg::unsubscribeEvents()
{
	mEventClose->disconnect();
	mEventCancel->disconnect();
}

bool GameLoaderSaveAsDlg::onButtonClicked_Cancel(const CEGUI::EventArgs& evt)
{
	hide();
	return true;
}

bool GameLoaderSaveAsDlg::onCloseClicked_Close(const CEGUI::EventArgs& evt)
{
	hide();
	return true;
}

std::string GameLoaderSaveAsDlg::getGameLoaderName() const
{
	return mEditGameLoaderName->getText();
}

void GameLoaderSaveAsDlg::create()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	const float panelHeight=0.2f;
	const float panelWidth=0.4f;
	float panelLeft=(1-panelWidth) / 2;
	float panelTop=(1-panelHeight) / 2;

	mRootWindow=wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId());
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(panelWidth), cegui_reldim(panelHeight)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(panelLeft), cegui_reldim(panelTop)));
	mRootWindow->setAlpha(0.5);
	mRootWindow->setText((CEGUI::utf8*)"GameLoader SaveAs");
	mRootWindow->hide();

	const float buttonWidth=0.4f;
	const float buttonHeight=0.2f;

	const float left=0.05f;
	const float top=0.25f;

	const float hgap=0.01f;
	const float vgap=0.05f;

	float x=left;
	float y=top;

	mEditGameLoaderName=new CITextFieldWidget(getUIId("GameLoaderName"), this, mRootWindow, 0.9f, buttonHeight, 0.3f);
	mEditGameLoaderName->setLabel("Name:");
	mEditGameLoaderName->setPosition(x, y);

	y+=(buttonHeight+vgap);
	x=1- (buttonWidth+hgap) * 2-left;
	mBtnSave=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnSave")));
	mBtnSave->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnSave->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnSave->setText("Save");
	mRootWindow->addChildWindow(mBtnSave);

	x+=(buttonWidth+hgap);
	mBtnCancel=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnCancel")));
	mBtnCancel->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(buttonHeight)));
	mBtnCancel->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnCancel->setText("Cancel");
	mRootWindow->addChildWindow(mBtnCancel);

	mParentWindow->addChildWindow(mRootWindow);
}