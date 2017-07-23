#include "CIGameDesignWidget.h"
#include "../../ScriptEngine/ScriptManager.h"
#include "../../SoundEngine/SoundManager.h"

CIGameDesignWidget::CIGameDesignWidget(const std::string& rootId)
: CIWidget(NULL, NULL)
{
	initializeComponents(rootId);
}

CIGameDesignWidget::~CIGameDesignWidget()
{
	mRootWindow->removeChildWindow(mRadioSelect);
	mRootWindow->removeChildWindow(mRadioCreate);
	mRootWindow->removeChildWindow(mRadioSimulate);

	mParentWindow->removeChildWindow(mRootWindow);

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();
	wm->destroyWindow(mRadioSelect);
	wm->destroyWindow(mRadioCreate);
	wm->destroyWindow(mRadioSimulate);

	wm->destroyWindow(mRootWindow);
}

void CIGameDesignWidget::create()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	const float normalizedPanelWidth=0.6f;
	const float normalizedPanelHeight=0.1f;
	CEGUI::FrameWindow* frmCI=static_cast<CEGUI::FrameWindow*>(wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId()));
	frmCI->setSize(CEGUI::UVector2(cegui_reldim(normalizedPanelWidth), cegui_reldim(normalizedPanelHeight)));
	frmCI->setPosition(CEGUI::UVector2(cegui_reldim(1-normalizedPanelWidth), cegui_reldim(0)));
	frmCI->setAlpha(0.5);
	frmCI->setText((CEGUI::utf8*)"Game Design Commands");
	frmCI->setCloseButtonEnabled(false);
	mRootWindow=frmCI;
	mParentWindow->addChildWindow(mRootWindow);

	const float radioButtonWidth=0.20f; //0.15f
	const float radioButtonHeight=0.2f;
	const float hgap=0.01f;
	float x=0.1f;
	float y=0.6f;
	mRadioCreate=static_cast<CEGUI::RadioButton*>(wm->createWindow(CIWidget::getGUIType("RadioButton"), getUIId("rbtCreate")));
	mRadioCreate->setSize(CEGUI::UVector2(cegui_reldim(radioButtonWidth), cegui_reldim(radioButtonHeight)));
	mRadioCreate->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mRadioCreate->setText((CEGUI::utf8*)"Create Agent");
	mRadioCreate->setGroupID(0);
	mRadioCreate->setSelected(true);
	mRootWindow->addChildWindow(mRadioCreate);

	x+=(radioButtonWidth+hgap);
	mRadioSelect=static_cast<CEGUI::RadioButton*>(wm->createWindow(CIWidget::getGUIType("RadioButton"), getUIId("rbtSelect")));
	mRadioSelect->setSize(CEGUI::UVector2(cegui_reldim(radioButtonWidth), cegui_reldim(radioButtonHeight)));
	mRadioSelect->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mRadioSelect->setText((CEGUI::utf8*)"Select Agent");
	mRadioSelect->setGroupID(0);
	mRootWindow->addChildWindow(mRadioSelect);

	x+=(radioButtonWidth+hgap);
	mRadioSimulate=static_cast<CEGUI::RadioButton*>(wm->createWindow(CIWidget::getGUIType("RadioButton"), getUIId("rbtSimulate")));
	mRadioSimulate->setSize(CEGUI::UVector2(cegui_reldim(radioButtonWidth), cegui_reldim(radioButtonHeight)));
	mRadioSimulate->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mRadioSimulate->setText((CEGUI::utf8*)"Simulate");
	mRadioSimulate->setGroupID(0);
	mRootWindow->addChildWindow(mRadioSimulate);
}

void CIGameDesignWidget::setVisible(bool bEnabled)
{
	mEnabled=bEnabled;
	if(mEnabled)
	{
		mRootWindow->show();
		mRadioCreate->setSelected(true);
	}
	else
	{
		mRootWindow->hide();
	}
}
