#include "CaelumDesignToolkit.h"
#include "../../SceneAssets/CaelumManager.h"
#include "../../OSEnvironment/OSEnvironment.h"

CaelumDesignToolkit::CaelumDesignToolkit(const std::string& rootId)
: CIWidget(NULL, NULL)
{
	this->initializeComponents(rootId);
}
	
CaelumDesignToolkit::~CaelumDesignToolkit()
{
	if(mEditTimeScale != NULL)
	{
		delete mEditTimeScale;
		mEditTimeScale=NULL;
	}
	if(mEditCloudSpeedX != NULL)
	{
		delete mEditCloudSpeedX;
		mEditCloudSpeedX=NULL;
	}
	if(mEditCloudSpeedY != NULL)
	{
		delete mEditCloudSpeedY;
		mEditCloudSpeedY=NULL;
	}
	if(mEditYear != NULL)
	{
		delete mEditYear;
		mEditYear=NULL;
	}
	if(mEditMonth != NULL)
	{
		delete mEditMonth;
		mEditMonth=NULL;
	}
	if(mEditDay != NULL)
	{
		delete mEditDay;
		mEditDay=NULL;
	}
	if(mEditHour != NULL)
	{
		delete mEditHour;
		mEditHour=NULL;
	}
	if(mEditMinute != NULL)
	{
		delete mEditMinute;
		mEditMinute=NULL;
	}
	if(mEditSecond != NULL)
	{
		delete mEditSecond;
		mEditSecond=NULL;
	}
}

void CaelumDesignToolkit::create()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	const float panelHeight=0.5f;
	const float panelWidth=0.4f;

	CEGUI::FrameWindow* frame=static_cast<CEGUI::FrameWindow*>(wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId()));
	frame->setCloseButtonEnabled(false);
	mRootWindow=frame;
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(panelWidth), cegui_reldim(panelHeight)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0.25f), cegui_reldim(0.3f)));
	mRootWindow->setAlpha(0.5);
	mRootWindow->setText((CEGUI::utf8*)"Caelum Design Toolkit");
	mRootWindow->hide();

	const float height=0.08f;
	const float width=0.9f;
	const float left=0.05f;
	const float top=0.1f;
	const float vgap=0.008f;

	float x=left;
	float y=top;
	mEditTimeScale=new CITextFieldWidget(getUIId("EditTimeScale"), this, mRootWindow, width, height, 0.35f);
	mEditTimeScale->setLabel("time scale: ");
	mEditTimeScale->setPosition(x, y);

	y+=(height+vgap);
	mEditCloudSpeedX=new CITextFieldWidget(getUIId("EditCloudSpeedX"), this, mRootWindow, width, height, 0.35f);
	mEditCloudSpeedX->setLabel("cloud speed(x): ");
	mEditCloudSpeedX->setPosition(x, y);

	y+=(height+vgap);
	mEditCloudSpeedY=new CITextFieldWidget(getUIId("EditCloudSpeedY"), this, mRootWindow, width, height, 0.35f);
	mEditCloudSpeedY->setLabel("cloud speed(y): ");
	mEditCloudSpeedY->setPosition(x, y);

	y+=(height+vgap);
	mEditYear=new CITextFieldWidget(getUIId("EditYear"), this, mRootWindow, width, height, 0.35f);
	mEditYear->setLabel("year: ");
	mEditYear->setPosition(x, y);

	y+=(height+vgap);
	mEditMonth=new CITextFieldWidget(getUIId("EditMonth"), this, mRootWindow, width, height, 0.35f);
	mEditMonth->setLabel("month: ");
	mEditMonth->setPosition(x, y);

	y+=(height+vgap);
	mEditDay=new CITextFieldWidget(getUIId("EditDay"), this, mRootWindow, width, height, 0.35f);
	mEditDay->setLabel("day: ");
	mEditDay->setPosition(x, y);

	y+=(height+vgap);
	mEditHour=new CITextFieldWidget(getUIId("EditHour"), this, mRootWindow, width, height, 0.35f);
	mEditHour->setLabel("hour: ");
	mEditHour->setPosition(x, y);

	y+=(height+vgap);
	mEditMinute=new CITextFieldWidget(getUIId("EditMinute"), this, mRootWindow, width, height, 0.35f);
	mEditMinute->setLabel("minute: ");
	mEditMinute->setPosition(x, y);

	y+=(height+vgap);
	mEditSecond=new CITextFieldWidget(getUIId("EditSecond"), this, mRootWindow, width, height, 0.35f);
	mEditSecond->setLabel("second: ");
	mEditSecond->setPosition(x, y);

	y+=(height+vgap);
	mBtnApply=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnApply")));
	mBtnApply->setSize(CEGUI::UVector2(cegui_reldim(0.2f), cegui_reldim(height)));
	mBtnApply->setPosition(CEGUI::UVector2(cegui_reldim(0.75f), cegui_reldim(y)));
	mBtnApply->setText((CEGUI::utf8*)"Apply");
	mRootWindow->addChildWindow(mBtnApply);

	mChkLightingEnabled=static_cast<CEGUI::Checkbox*>(wm->createWindow(CIWidget::getGUIType("Checkbox"), getUIId("chkLightingEnabled")));
	mChkLightingEnabled->setSize(CEGUI::UVector2(cegui_reldim(0.6f), cegui_reldim(height)));
	mChkLightingEnabled->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mChkLightingEnabled->setText((CEGUI::utf8*)"Enable Caelum Lighting");
	mRootWindow->addChildWindow(mChkLightingEnabled);

	mParentWindow->addChildWindow(mRootWindow);
}

void CaelumDesignToolkit::subscribeEvents()
{
	mEventApply=mBtnApply->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&CaelumDesignToolkit::onButtonClicked_Apply, this));
}

void CaelumDesignToolkit::unsubscribeEvents()
{
	mEventApply->disconnect();
}

bool CaelumDesignToolkit::onButtonClicked_Apply(const CEGUI::EventArgs& evt)
{
	CaelumManager* cm=CaelumManager::getSingletonPtr();

	int year, month, day, hour, minute, second;
	year=OSEnvironment::parseInt(mEditYear->getText());
	month=OSEnvironment::parseInt(mEditMonth->getText());
	day=OSEnvironment::parseInt(mEditDay->getText());
	hour=OSEnvironment::parseInt(mEditHour->getText());
	minute=OSEnvironment::parseInt(mEditMinute->getText());
	second=OSEnvironment::parseInt(mEditSecond->getText());
	
	cm->setDateTime(year, month, day, hour, minute, second);

	float timeScale=OSEnvironment::parseFloat(mEditTimeScale->getText());
	cm->setTimeScale(timeScale);

	float cloudSpeedX=OSEnvironment::parseFloat(mEditCloudSpeedX->getText());
	float cloudSpeedY=OSEnvironment::parseFloat(mEditCloudSpeedY->getText());

	cm->setCloudSpeed(Ogre::Vector2(cloudSpeedX, cloudSpeedY));

	if(mChkLightingEnabled->isSelected())
	{
		cm->enableLighting();
	}
	else
	{
		cm->disableLighting();
	}

	return true;
}

void CaelumDesignToolkit::show()
{
	CaelumManager* cm=CaelumManager::getSingletonPtr();

	int year, month, day, hour, minute, second;
	cm->getDateTime(year, month, day, hour, minute, second);

	float timeScale=cm->getTimeScale();

	float cloudSpeedX=cm->getCloudSpeedX();
	float cloudSpeedY=cm->getCloudSpeedY();

	mEditTimeScale->setText(OSEnvironment::toString(timeScale));
	mEditCloudSpeedX->setText(OSEnvironment::toString(cloudSpeedX));
	mEditCloudSpeedY->setText(OSEnvironment::toString(cloudSpeedY));
	mEditHour->setText(OSEnvironment::toString(hour));
	mEditMinute->setText(OSEnvironment::toString(minute));
	mEditSecond->setText(OSEnvironment::toString(second));
	mEditYear->setText(OSEnvironment::toString(year));
	mEditMonth->setText(OSEnvironment::toString(month));
	mEditDay->setText(OSEnvironment::toString(day));

	mChkLightingEnabled->setSelected(cm->isLightingEnabled());

	CIWidget::show();
}