#include "CICodeDesignWidget.h"
#include "../../CIType/CIManager.h"
#include "../../Widgets/CIComboWidget.h"

CICodeDesignWidget::CICodeDesignWidget(const std::string& rootId)
: CIWidget(NULL, NULL)
, mEnabled(false)
{
	initializeComponents(rootId);
}

CICodeDesignWidget::~CICodeDesignWidget()
{
	if(mComboType != NULL)
	{
		delete mComboType;
		mComboType=NULL;
	}

	if(mComboMethod != NULL)
	{
		delete mComboMethod;
		mComboMethod=NULL;
	}

	mRootWindow->removeChildWindow(mRadioSelect);
	mRootWindow->removeChildWindow(mRadioCreate);
	mRootWindow->removeChildWindow(mChkShowPS);
	mParentWindow->removeChildWindow(mRootWindow);

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	wm->destroyWindow(mRadioSelect);
	wm->destroyWindow(mRadioCreate);
	wm->destroyWindow(mChkShowPS);
	wm->destroyWindow(mRootWindow);
}

void CICodeDesignWidget::show()
{
	enable(true);
}

void CICodeDesignWidget::hide()
{
	enable(false);
}

void CICodeDesignWidget::enable(bool bEnabled)
{
	mEnabled=bEnabled;
	if(mEnabled)
	{
		mRootWindow->show();
	}
	else
	{
		mRootWindow->hide();
	}
}

void CICodeDesignWidget::create()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	const float normalizedPanelWidth=0.375f;
	const float normalizedPanelHeight=0.25f;
	CEGUI::FrameWindow* frmCI=static_cast<CEGUI::FrameWindow*>(wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId()));
	frmCI->setSize(CEGUI::UVector2(cegui_reldim(normalizedPanelWidth), cegui_reldim(normalizedPanelHeight)));
	frmCI->setPosition(CEGUI::UVector2(cegui_reldim(1-normalizedPanelWidth), cegui_reldim(0)));
	frmCI->setAlpha(0.5);
	frmCI->setText((CEGUI::utf8*)"Computational Intelligence");
	frmCI->setCloseButtonEnabled(false);
	//frmCI->setDragMovingEnabled(false);
	mRootWindow=frmCI;
	mParentWindow->addChildWindow(mRootWindow);

	mComboType=new CIComboWidget(getUIId("dlCI"), this, mRootWindow, 0.8f, 0.15f, 0.2f); //static_cast<CEGUI::Combobox*>(wm->createWindow(CIWidget::getGUIType("Combobox"), getUIId("dlCI")));
	mComboType->setLabel("Type: ");
	mComboType->setPosition(0.1f, 0.18f);
	CEGUI::Combobox* comboTypeCtrl=mComboType->getCombobox();
	const CITypeNameList& typeNameList=CIManager::getSingletonPtr()->getCITypeNames();
	CITypeNameList::const_iterator iter;
	 size_t typeNameListCount=typeNameList.size();
	for(uint index=0; index != typeNameListCount; ++index)
	{
		CEGUI::ListboxTextItem* lti=new CEGUI::ListboxTextItem(CIWidget::getGUIType("FrameWindow"), index);
		lti->setText(((CEGUI::utf8*)(typeNameList[index].c_str())));
		comboTypeCtrl->addItem(lti);

		if(index==0)
		{
			mComboType->setText(typeNameList[index]);
		}
	}	

	mComboMethod=new CIComboWidget(getUIId("dlCISub"), this, mRootWindow, 0.8f, 0.15f, 0.2f); 
	mComboMethod->setPosition(0.1f, 0.38f);
	mComboMethod->setLabel("Method: ");
	CEGUI::Combobox* comboMethodCtrl=mComboMethod->getCombobox();
	const std::string& typeName=mComboType->getText();
	const std::vector<std::string>& lst=CIManager::getSingletonPtr()->getCIType(typeName)->getMethodNames();
	size_t indexCount=lst.size();
	for(uint index=0; index != indexCount; ++index)
	{
		CEGUI::ListboxTextItem* lti=new CEGUI::ListboxTextItem(CIWidget::getGUIType("FrameWindow"), index);
		lti->setText(((CEGUI::utf8*)(lst[index].c_str())));
		comboMethodCtrl->addItem(lti);

		if(index==0)
		{
			mComboMethod->setText(lst[0]);
		}
	}

	const float radioButtonWidth=0.5f;
	const float radioButtonHeight=0.1f;
	mRadioCreate=static_cast<CEGUI::RadioButton*>(wm->createWindow(CIWidget::getGUIType("RadioButton"), getUIId("rbtCreateCI")));
	mRadioCreate->setSize(CEGUI::UVector2(cegui_reldim(radioButtonWidth), cegui_reldim(radioButtonHeight)));
	mRadioCreate->setPosition(CEGUI::UVector2(cegui_reldim(0.1), cegui_reldim(0.65)));
	mRadioCreate->setText((CEGUI::utf8*)"Create Agent");
	mRadioCreate->setGroupID(0);
	mRadioCreate->setSelected(true);
	mRootWindow->addChildWindow(mRadioCreate);

	mRadioSelect=static_cast<CEGUI::RadioButton*>(wm->createWindow(CIWidget::getGUIType("RadioButton"), getUIId("rbtSelectCI")));
	mRadioSelect->setSize(CEGUI::UVector2(cegui_reldim(radioButtonWidth), cegui_reldim(radioButtonHeight)));
	mRadioSelect->setPosition(CEGUI::UVector2(cegui_reldim(0.1), cegui_reldim(0.8)));
	mRadioSelect->setText((CEGUI::utf8*)"Select Agent");
	mRadioSelect->setGroupID(0);
	mRootWindow->addChildWindow(mRadioSelect);

	mChkShowPS=static_cast<CEGUI::Checkbox*>(wm->createWindow(CIWidget::getGUIType("Checkbox"), getUIId("chkShowPS")));
	mChkShowPS->setSize(CEGUI::UVector2(cegui_reldim(radioButtonWidth), cegui_reldim(radioButtonHeight)));
	mChkShowPS->setPosition(CEGUI::UVector2(cegui_reldim(0.5), cegui_reldim(0.65)));
	mChkShowPS->setSelected(false);
	mChkShowPS->setText((CEGUI::utf8*)"Agent Flare");
	mRootWindow->addChildWindow(mChkShowPS);
}

void CICodeDesignWidget::subscribeEvents()
{
	mEventTypeChange=mComboType->getCombobox()->subscribeEvent(CEGUI::Combobox::EventListSelectionAccepted, 
		CEGUI::Event::Subscriber(&CICodeDesignWidget::onItemChanged_CIType, this));
	mEventStateChange=mRadioCreate->subscribeEvent(CEGUI::RadioButton::EventSelectStateChanged, CEGUI::Event::Subscriber(&CICodeDesignWidget::onClicked_onCreateChecked, this));
}

void CICodeDesignWidget::unsubscribeEvents()
{
	mEventTypeChange->disconnect();
	mEventStateChange->disconnect();
}

bool CICodeDesignWidget::isCreating() const
{
	return mRadioCreate->isSelected();
}

bool CICodeDesignWidget::isSelecting() const
{
	return mRadioSelect->isSelected();
}

bool CICodeDesignWidget::isAgentPSVisible() const
{
	return mChkShowPS->isSelected();
}

std::string CICodeDesignWidget::getType() const
{
	return mComboType->getText(); 
}

std::string CICodeDesignWidget::getMethod() const
{
	return mComboMethod->getText();
}

void CICodeDesignWidget::setType(const std::string& type) 
{
	mComboType->setText(type);
}

void CICodeDesignWidget::setMethod(const std::string& method)
{
	mComboMethod->setText(method);
}

void CICodeDesignWidget::enableMethodSelection(bool enabled)
{
	mComboMethod->setEnabled(enabled);
}

void CICodeDesignWidget::enableTypeSelection(bool enabled)
{
	mComboType->setEnabled(enabled);
}
	
bool CICodeDesignWidget::onClicked_onCreateChecked(const CEGUI::EventArgs& evt)
{
	if(isCreating())
	{
		mComboType->setEnabled(true);
		mComboMethod->setEnabled(true);
	}
	else
	{
		mComboType->setEnabled(false);
		mComboMethod->setEnabled(false);
	}
	return true;
}

bool CICodeDesignWidget::onItemChanged_CIType(const CEGUI::EventArgs& evt)
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	CEGUI::Combobox* cdl=mComboType->getCombobox();
	CEGUI::Combobox* cdlsub=mComboMethod->getCombobox();

	size_t index=0;
	cdlsub->resetList();

	std::string typeName=cdl->getText().c_str();
	const std::vector<std::string>& lst=CIManager::getSingletonPtr()->getCIType(typeName)->getMethodNames();
	
	size_t lstSize=lst.size();
	for(index=0; index != lstSize; ++index)
	{
		CEGUI::ListboxTextItem* lti=new CEGUI::ListboxTextItem(CIWidget::getGUIType("FrameWindow"), 0);
		lti->setText(((CEGUI::utf8*)(lst[index].c_str())));
		cdlsub->addItem(lti);

		if(index==0)
		{
			cdlsub->setText(((CEGUI::utf8*)(lst[0].c_str())));
		}
	}

	return true;
}