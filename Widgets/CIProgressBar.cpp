#include "CIProgressBar.h"

CIProgressBar::CIProgressBar(const std::string& rootId, CIWidget* parentWidget, CEGUI::Window* parentWindow,  float width, float height, float labelWidth)
: CIWidget(parentWidget, parentWindow)
{
	mWidth=width;
	mHeight=height;
	mLabelWidth=labelWidth;
	this->initializeComponents(rootId);
}

CIProgressBar::~CIProgressBar()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

    mRootWindow->removeChildWindow(mProgressBar);
	mRootWindow->removeChildWindow(mLabel);
	mParentWindow->removeChildWindow(mRootWindow);

	wm->destroyWindow(mProgressBar);
	wm->destroyWindow(mLabel);
	wm->destroyWindow(mRootWindow);
}

void CIProgressBar::create() 
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow=wm->createWindow(CIWidget::getGUIType("DefaultWindow"), getRootId());
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(mWidth), cegui_reldim(mHeight)));

	mLabel=static_cast<CEGUI::DefaultWindow*>(wm->createWindow(CIWidget::getGUIType("StaticText"), getUIId("Label")));
	mLabel->setSize((CEGUI::UVector2(cegui_reldim(mLabelWidth), cegui_reldim(1))));
	mLabel->setPosition((CEGUI::UVector2(cegui_reldim(0), cegui_reldim(0))));
	mLabel->setProperty((CEGUI::utf8*)"FrameEnabled", (CEGUI::utf8*)"false");
	mLabel->setProperty((CEGUI::utf8*)"BackgroundEnabled", (CEGUI::utf8*)"false");
	mRootWindow->addChildWindow(mLabel);
	
	mProgressBar=static_cast<CEGUI::ProgressBar*>(wm->createWindow(CIWidget::getGUIType("ProgressBar"), getUIId("ProgressBar")));
	mProgressBar->setSize(CEGUI::UVector2(cegui_reldim(1-mLabelWidth), cegui_reldim(0.5)));
	mProgressBar->setPosition(CEGUI::UVector2(cegui_reldim(mLabelWidth), cegui_reldim(0.25)));
	mRootWindow->addChildWindow(mProgressBar);

	mParentWindow->addChildWindow(mRootWindow);
}

void CIProgressBar::setProgress(float value)
{
	mProgressBar->setProgress(value);
}

float CIProgressBar::getProgress() const
{
	return mProgressBar->getProgress();
}

void CIProgressBar::setLabel(const std::string& label)
{
	mLabel->setText(label);
}