#include "IDBlockWidget.h"
#include "../../ScriptEngine/ScriptManager.h"

IDBlockWidget::IDBlockWidget(const std::string& rootId, CEGUI::Window* parentWindow)
: CIWidget(NULL, parentWindow)
{
	this->initializeComponents(rootId);
	mModelDlg=new ModelDlg(getUIId("ModelDlg"));
}

IDBlockWidget::~IDBlockWidget()
{
	if(mCaptureTagID != NULL)
	{
		delete mCaptureTagID;
		mCaptureTagID=NULL;
	}

	if(mEntityAction != NULL)
	{
		delete mEntityAction;
		mEntityAction=NULL;
	}

	if(mCaptureScriptID != NULL)
	{
		delete mCaptureScriptID;
		mCaptureScriptID=NULL;
	}

	if(mLifeBar != NULL)
	{
		delete mLifeBar;
		mLifeBar=NULL;
	}

	if(mWeaponBar != NULL)
	{
		delete mWeaponBar;
		mWeaponBar=NULL;
	}

	if(mModelDlg != NULL)
	{
		delete mModelDlg;
		mModelDlg=NULL;
	}

	mRootWindow->removeChildWindow(mBtnTraining);
	mRootWindow->removeChildWindow(mBtnPostConfig);
	mRootWindow->removeChildWindow(mBtnModel);

	mParentWindow->removeChildWindow(mRootWindow);

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();
	wm->destroyWindow(mBtnTraining);
	wm->destroyWindow(mBtnPostConfig);
	wm->destroyWindow(mBtnModel);
	wm->destroyWindow(mRootWindow);
	
}

void IDBlockWidget::create()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	CEGUI::FrameWindow* frame=static_cast<CEGUI::FrameWindow*>(wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId()));
	//frame->toggleRollup();
	mRootWindow=frame;
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.3f), cegui_reldim(0.3f)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0.0f), cegui_reldim(0.1f)));
	mRootWindow->setAlpha(0.6f);
	mRootWindow->setText((CEGUI::utf8*)"ID Block");

	const float vgap=0.02f;
	const float hgap=0.01f;
	const float left=0.05f;
	const float top=0.15f;
	const float height=0.15f;
	const float width=0.9f;
	float x=left;
	float y=top;

	mCaptureTagID=new CITextFieldWidget(getUIId("CaptureTagID"), this, mRootWindow, 0.45f, height, 0.25f);
	mCaptureTagID->setLabel("Tag: ");
	mCaptureTagID->setPosition(x, y);
	mCaptureTagID->getRootWindow()->setClippedByParent(false);

	x+=(0.45f+hgap);
	mCaptureScriptID=new CITextFieldWidget(getUIId("CaptureScriptID"), this, mRootWindow, 0.45f, height, 0.35f);
	mCaptureScriptID->setLabel("Script: ");
	mCaptureScriptID->setPosition(x, y);
	mCaptureScriptID->getRootWindow()->setClippedByParent(false);

	x=left;
	y+=(height+vgap);
	mLifeBar=new CIProgressBar(getUIId("LifeBar"), this, mRootWindow, width, height, 0.2f);
	mLifeBar->setLabel("Life: ");
	mLifeBar->setPosition(x, y);
	mLifeBar->getRootWindow()->setClippedByParent(false);

	y+=(height+vgap);
	mWeaponBar=new CIProgressBar(getUIId("WeaponBar"), this, mRootWindow, width, height, 0.2f);
	mWeaponBar->setLabel("Bullets: ");
	mWeaponBar->setPosition(x, y);
	mWeaponBar->getRootWindow()->setClippedByParent(false);

	y+=(height+vgap);
	mEntityAction=new CITextFieldWidget(getUIId("EntityAction"), this, mRootWindow, width, height, 0.3f);
	mEntityAction->setLabel("Action: ");
	mEntityAction->setPosition(x, y);

	y+=(height+vgap);
	mBtnTraining=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("TrainingButton")));
	mBtnTraining->setText("Train");
	mBtnTraining->setSize(CEGUI::UVector2(cegui_reldim(0.25f), cegui_reldim(height)));
	mBtnTraining->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mRootWindow->addChildWindow(mBtnTraining);

	x+=(0.25f+hgap);
	mBtnModel=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("ModelButton")));
	mBtnModel->setText("Model");
	mBtnModel->setSize(CEGUI::UVector2(cegui_reldim(0.25f), cegui_reldim(height)));
	mBtnModel->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mRootWindow->addChildWindow(mBtnModel);

	x+=(0.25f+hgap);
	mBtnPostConfig=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("UploadConfigButton")));
	mBtnPostConfig->setText("Upload Config");
	mBtnPostConfig->setSize(CEGUI::UVector2(cegui_reldim(0.45f), cegui_reldim(height)));
	mBtnPostConfig->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mRootWindow->addChildWindow(mBtnPostConfig);

	mParentWindow->addChildWindow(mRootWindow);
	mRootWindow->hide();
}

void IDBlockWidget::subscribeEvents()
{
	mEventClosedClicked=mRootWindow->subscribeEvent(CEGUI::FrameWindow::EventCloseClicked, CEGUI::Event::Subscriber(&IDBlockWidget::onCloseClicked, this));
	mEventBtnModel=mBtnModel->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&IDBlockWidget::onBtnModelClicked, this));
}

void IDBlockWidget::unsubscribeEvents()
{
	mEventClosedClicked->disconnect();
	mEventBtnModel->disconnect();
}

bool IDBlockWidget::onCloseClicked(const CEGUI::EventArgs& evt)
{
	this->hide();
	return true;
}

bool IDBlockWidget::onBtnModelClicked(const CEGUI::EventArgs& evt)
{
	mModelDlg->showModal();
	return true;
}

void IDBlockWidget::setBlockIDScript(const std::string &id)
{
	 ScriptManager* sm=ScriptManager::getSingletonPtr();
	 mCaptureScriptID->setText(sm->getNickname(id)); 
}