#include "ModelDlg.h"
#include <sstream>
#include "GUIManager.h"
#include "../CIAgents/ModelManager.h"

size_t ModelDlg::mNumModelDlgShown=0;

ModelDlg::ModelDlg(const std::string& rootId)
: CIWidget(NULL, NULL)
{
	initializeComponents(rootId);
}

ModelDlg::~ModelDlg()
{
	if(mComboModel != NULL)
	{
		delete mComboModel;
		mComboModel=NULL;
	}
	mParentWindow->removeChildWindow(mRootWindow);

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow->removeChildWindow(mBtnOK);
	mRootWindow->removeChildWindow(mBtnCancel);
	mParentWindow->removeChildWindow(mRootWindow);

	wm->destroyWindow(mBtnOK);
	wm->destroyWindow(mBtnCancel);
	wm->destroyWindow(mRootWindow);
}

void ModelDlg::showModal()
{
	mRootWindow->setText("Model");
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.4f), cegui_reldim(0.3f)));

	setModalState(true);

	mRootWindow->setPosition(CEGUI::UVector2(CEGUI::UDim(0.3f, 10.0f*mNumModelDlgShown), CEGUI::UDim(0.35f, 10.0f * mNumModelDlgShown)));
	showWindow();
	mNumModelDlgShown++;
}

std::string ModelDlg::getSelectedModel() const
{
	return mComboModel->getText();
}

void ModelDlg::create()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();
	mRootWindow=wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId());
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.4f), cegui_reldim(0.3f)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0.3f), cegui_reldim(0.35f)));
	mRootWindow->setAlpha(0.8f);

	const Real top=0.2f;
	const Real left=0.05f;
	const Real hgap=0.05f;
	Real x=left;
	Real y=top;
	Real height=0.1f;
	Real width=0.5f;
	
	mBtnOK=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnOK")));
	mBtnOK->setSize(CEGUI::UVector2(cegui_reldim(0.3f), cegui_reldim(0.15f)));
	mBtnOK->setPosition(CEGUI::UVector2(cegui_reldim(0.30f), cegui_reldim(0.81f)));
	mBtnOK->setText((CEGUI::utf8*)"OK");
	mRootWindow->addChildWindow(mBtnOK);

	mBtnCancel=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnCancel")));
	mBtnCancel->setSize(CEGUI::UVector2(cegui_reldim(0.3f), cegui_reldim(0.15f)));
	mBtnCancel->setPosition(CEGUI::UVector2(cegui_reldim(0.65f), cegui_reldim(0.81f)));
	mBtnCancel->setText((CEGUI::utf8*)"Cancel");
	mRootWindow->addChildWindow(mBtnCancel);

	mComboModel=new CIComboWidget(getUIId("ModelCombo"), this, mRootWindow, 0.9f, 0.2f, 0.2f);
	mComboModel->setLabel("Models");
	mComboModel->setPosition(0.05f, 0.2f);

	CEGUI::Combobox* comboModelCtrl=mComboModel->getCombobox();
	const std::vector<std::string>& models=ModelManager::getSingletonPtr()->getConstModelNames();
	uint modelCount=static_cast<uint>(models.size());
	for(uint index=0; index != modelCount; ++index)
	{
		CEGUI::ListboxTextItem* lti=new CEGUI::ListboxTextItem(CIWidget::getGUIType("FrameWindow"), index);
		lti->setText(((CEGUI::utf8*)(models[index].c_str())));
		comboModelCtrl->addItem(lti);

		if(index==0)
		{
			comboModelCtrl->setText(models[index]);
		}
	}	


	mRootWindow->setVisible(false);
	mParentWindow->addChildWindow(mRootWindow);
}

void ModelDlg::subscribeEvents()
{
	mEventClose=mRootWindow->subscribeEvent(CEGUI::FrameWindow::EventCloseClicked, CEGUI::Event::Subscriber(&ModelDlg::onClicked_Cancel, this));
	mEventCancel=mBtnCancel->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ModelDlg::onClicked_Cancel, this));
	mEventOK=mBtnOK->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ModelDlg::onClicked_OK, this));
}

void ModelDlg::unsubscribeEvents()
{
	mEventCancel->disconnect();
	mEventClose->disconnect();
	mEventOK->disconnect();
}

bool ModelDlg::onClicked_Cancel(const CEGUI::EventArgs& evt)
{
	hide();
	return true;
}

bool ModelDlg::onClicked_OK(const CEGUI::EventArgs &evt)
{
	hide();
	return true;
}

void ModelDlg::hide()
{
	setModalState(false);
	hideWindow();

	mNumModelDlgShown--;
}
