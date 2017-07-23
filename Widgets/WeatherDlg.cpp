#include "WeatherDlg.h"
#include <sstream>
#include "GUIManager.h"
#include "../WeatherEngine/WeatherManager.h"

size_t WeatherDlg::mNumWeatherDlgShown=0;

WeatherDlg::WeatherDlg(const std::string& rootId)
: CIWidget(NULL, NULL)
{
	initializeComponents(rootId);
}

WeatherDlg::~WeatherDlg()
{
	mParentWindow->removeChildWindow(mRootWindow);

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow->removeChildWindow(mChkShowSnow);
	mRootWindow->removeChildWindow(mChkShowRain);
	mRootWindow->removeChildWindow(mBtnCancel);
	mParentWindow->removeChildWindow(mRootWindow);

	wm->destroyWindow(mChkShowSnow);
	wm->destroyWindow(mChkShowRain);
	wm->destroyWindow(mBtnCancel);
	wm->destroyWindow(mRootWindow);
}

void WeatherDlg::showModal()
{
	mRootWindow->setText("Weather");
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.4f), cegui_reldim(0.3f)));

	setModalState(true);

	mRootWindow->setPosition(CEGUI::UVector2(CEGUI::UDim(0.3f, 10.0f*mNumWeatherDlgShown), CEGUI::UDim(0.35f, 10.0f * mNumWeatherDlgShown)));
	showWindow();
	mNumWeatherDlgShown++;
}

void WeatherDlg::create()
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
	mChkShowRain=static_cast<CEGUI::Checkbox*>(wm->createWindow(CIWidget::getGUIType("Checkbox"), getUIId("chkShowRain")));
	mChkShowRain->setSize(CEGUI::UVector2(cegui_reldim(width), cegui_reldim(height)));
	mChkShowRain->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mChkShowRain->setText((CEGUI::utf8*)"Start Rain");
	mRootWindow->addChildWindow(mChkShowRain);

	y+=(height+hgap);
	mChkShowSnow=static_cast<CEGUI::Checkbox*>(wm->createWindow(CIWidget::getGUIType("Checkbox"), getUIId("chkShowSnow")));
	mChkShowSnow->setSize(CEGUI::UVector2(cegui_reldim(width), cegui_reldim(height)));
	mChkShowSnow->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mChkShowSnow->setText((CEGUI::utf8*)"Start Snow");
	mRootWindow->addChildWindow(mChkShowSnow);

	mBtnCancel=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnCancel")));
	mBtnCancel->setSize(CEGUI::UVector2(cegui_reldim(0.3f), cegui_reldim(0.15f)));
	mBtnCancel->setPosition(CEGUI::UVector2(cegui_reldim(0.65f), cegui_reldim(0.81f)));
	mBtnCancel->setText((CEGUI::utf8*)"Close");
	mRootWindow->addChildWindow(mBtnCancel);

	mRootWindow->setVisible(false);
	mParentWindow->addChildWindow(mRootWindow);
}

void WeatherDlg::subscribeEvents()
{
	mEventClose=mRootWindow->subscribeEvent(CEGUI::FrameWindow::EventCloseClicked, CEGUI::Event::Subscriber(&WeatherDlg::onClicked_Cancel, this));
	mEventCancel=mBtnCancel->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&WeatherDlg::onClicked_Cancel, this));

	mEventShowSnow=mChkShowSnow->subscribeEvent(CEGUI::Checkbox::EventCheckStateChanged, CEGUI::Event::Subscriber(&WeatherDlg::onChecked_ShowSnow, this));
	mEventShowRain=mChkShowRain->subscribeEvent(CEGUI::Checkbox::EventCheckStateChanged, CEGUI::Event::Subscriber(&WeatherDlg::onChecked_ShowRain, this));
}

bool WeatherDlg::onChecked_ShowRain(const CEGUI::EventArgs& evt)
{
	WeatherManager::getSingletonPtr()->showRain(mChkShowRain->isSelected());
	return true;
}

bool WeatherDlg::onChecked_ShowSnow(const CEGUI::EventArgs& evt)
{
	WeatherManager::getSingletonPtr()->showSnow(mChkShowSnow->isSelected());
	return true;
}

void WeatherDlg::unsubscribeEvents()
{
	mEventCancel->disconnect();
	mEventClose->disconnect();

	mEventShowSnow->disconnect();
	mEventShowRain->disconnect();
}

bool WeatherDlg::onClicked_Cancel(const CEGUI::EventArgs& evt)
{
	hide();
	return true;
}

void WeatherDlg::hide()
{
	setModalState(false);
	hideWindow();

	mNumWeatherDlgShown--;
}
