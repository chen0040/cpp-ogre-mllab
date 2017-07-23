#include "TextOverlay.h"

TextOverlay::TextOverlay(const CEGUI::String& overlayName)
: mEnabled(true)
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();
	mOverlayName=CEGUI::String("Overlay/")+overlayName;

	if(wm->isWindowPresent(mOverlayName))
	{
		throw Ogre::Exception(42, "wm->isWindowPresent(mOverlayName)==true", "TextOverlay::TextOverlay(const CEGUI::String& overlayName)");
	}

	CEGUI::FrameWindow* frame=static_cast<CEGUI::FrameWindow*>(wm->createWindow(CIWidget::getGUIType("FrameWindow"), mOverlayName));
	mEditbox=static_cast<CEGUI::MultiLineEditbox*>(wm->createWindow(CIWidget::getGUIType("MultiLineEditbox"), mOverlayName+CEGUI::String("/Editbox")));
	mEditbox->setSize(CEGUI::UVector2(cegui_reldim(0.9f), cegui_reldim(0.8f)));
	mEditbox->setPosition(CEGUI::UVector2(cegui_reldim(0.05f), cegui_reldim(0.15f)));
	mEditbox->setReadOnly(true);

	frame->setSize(CEGUI::UVector2(cegui_reldim(0.7f), cegui_reldim(0.1f)));
	frame->setPosition(CEGUI::UVector2(cegui_reldim(0.1f), cegui_reldim(0.5f)));
	frame->addChildWindow(mEditbox);
	frame->setCloseButtonEnabled(false);
	mRootWindow=frame;

	mParentWindow=CEGUI::System::getSingletonPtr()->getGUISheet();

	mParentWindow->addChildWindow(mRootWindow);
	mRootWindow->show();
}

TextOverlay::~TextOverlay()
{
	mRootWindow->removeChildWindow(mEditbox);
	mParentWindow->removeChildWindow(mRootWindow);

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow->removeChildWindow(mEditbox);
	mParentWindow->removeChildWindow(mRootWindow);

	wm->destroyWindow(mEditbox);
	wm->destroyWindow(mRootWindow);
}

void TextOverlay::setText(const String& text)
{
	mEditbox->setText(text);
}

void TextOverlay::setTitle(const String& title)
{
	mRootWindow->setText(title);
}

void TextOverlay::setSize(Real w, Real h)
{
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(w), cegui_reldim(h)));
}

void TextOverlay::setPosition(Real x, Real y)
{
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
}

void TextOverlay::setAlpha(Real alpha)
{
	mRootWindow->setAlpha(alpha);
}

void TextOverlay::enable(bool enabled)
{
	mEnabled=true;
	if(enabled)
	{
		mRootWindow->show();
	}
	else
	{
		mRootWindow->hide();
	}
}