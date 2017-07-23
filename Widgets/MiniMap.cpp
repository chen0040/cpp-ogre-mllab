#include "MiniMap.h"

MiniMap::MiniMap(const std::string& id, RenderWindow* rw, SceneManager* sm, CEGUI::OgreCEGUIRenderer* renderer)
: mSceneMgr(sm)
, mWindow(rw)
, mGUIRenderer(renderer)
{
	mId=id;
	mRootId=std::string("Minimap/")+mId;
	mParentWindow=CEGUI::System::getSingletonPtr()->getGUISheet();

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();
	if(wm->isWindowPresent(mRootId))
	{
		throw Exception(42, "Attempt to duplicate CEGUI window with same id", "MiniMap::MiniMap(const std::string& id, SceneManager* sm)");
	}

	TexturePtr pText=TextureManager::getSingletonPtr()->createManual(getUIId("R2Tex"), ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, TEX_TYPE_2D, 512, 512, 0, PF_R8G8B8, TU_RENDERTARGET);
	RenderTarget* rt=pText->getBuffer()->getRenderTarget();

	mCam=mSceneMgr->createCamera(getUIId("Camera"));
	
	mSceneMgr->getRootSceneNode()->createChildSceneNode(Vector3(750, 0, 750))->attachObject(mCam);
	mCam->setNearClipDistance(5.0f);
	mCam->setPosition(0.0,0.0,0.0);
    mCam->setOrientation(Ogre::Quaternion::IDENTITY);
    mCam->yaw(Ogre::Degree(0));
    mCam->pitch(Ogre::Degree(-90));
	mCam->roll(Ogre::Degree(-90));
    mCam->moveRelative(Ogre::Vector3(0.0,0.0,700));

	Viewport* vp=rt->addViewport(mCam);
	vp->setBackgroundColour(ColourValue::Black);
	vp->setOverlaysEnabled(false);
	vp->setClearEveryFrame(true);

	CEGUI::Texture* tex=mGUIRenderer->createTexture(pText);
	CEGUI::Imageset* is=CEGUI::ImagesetManager::getSingletonPtr()->createImageset(getUIId("R2tImageSet"), tex);
	is->defineImage(getUIId("R2tImage"), CEGUI::Point(0, 0), CEGUI::Size(pText->getWidth(), pText->getHeight()), CEGUI::Point(0, 0));

	mRootWindow=static_cast<CEGUI::FrameWindow*>(wm->createWindow(CIWidget::getGUIType("FrameWindow"), mRootId));
	mRootWindow->setSize((CEGUI::UVector2(cegui_reldim(0.25f), cegui_reldim(mWindow->getWidth() * 0.25f / mWindow->getHeight()))));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0.75f), cegui_reldim(0.25f)));
	mRootWindow->setText((CEGUI::utf8*)"MiniMap");
	//mRootWindow->setCloseButtonEnabled(false);

	mMap=static_cast<CEGUI::DefaultWindow*>(wm->createWindow(CIWidget::getGUIType("StaticImage"), getUIId("StaticIMage")));
	mMap->setSize(CEGUI::UVector2(cegui_reldim(0.8f), cegui_reldim(0.7f)));
	mMap->setPosition(CEGUI::UVector2(cegui_reldim(0.1f), cegui_reldim(0.1f)));
	mMap->setProperty((CEGUI::utf8*)"Image", CEGUI::PropertyHelper::imageToString(&(is->getImage(getUIId("R2tImage")))));
	mRootWindow->addChildWindow(mMap);

	mAlphaScroller=static_cast<CEGUI::Scrollbar*>(wm->createWindow(CIWidget::getGUIType("HorizontalScrollbar"), getUIId("AlphaScroller")));
	mAlphaScroller->setSize(CEGUI::UVector2(cegui_reldim(0.9f), cegui_reldim(0.07f)));
	mAlphaScroller->setPosition(CEGUI::UVector2(cegui_reldim(0.05f), cegui_reldim(0.80f)));
	mAlphaScroller->setMaxSize(CEGUI::UVector2(cegui_reldim(0.9f), cegui_absdim(20)));
	mAlphaScroller->setAlpha(0.5f);
	mRootWindow->addChildWindow(mAlphaScroller);

	mHeightScroller=static_cast<CEGUI::Scrollbar*>(wm->createWindow(CIWidget::getGUIType("HorizontalScrollbar"), getUIId("HeightScroller")));
	mHeightScroller->setSize(CEGUI::UVector2(cegui_reldim(0.9f), cegui_reldim(0.07f)));
	mHeightScroller->setPosition(CEGUI::UVector2(cegui_reldim(0.05f), cegui_reldim(0.90f)));
	mHeightScroller->setMaxSize(CEGUI::UVector2(cegui_reldim(0.9f), cegui_absdim(20)));
	mRootWindow->addChildWindow(mHeightScroller);

	mEventAlphaScroll=mAlphaScroller->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged, CEGUI::Event::Subscriber(&MiniMap::onScroll_Alpha, this));
	mEventHeightScroll=mHeightScroller->subscribeEvent(CEGUI::Scrollbar::EventScrollPositionChanged, CEGUI::Event::Subscriber(&MiniMap::onScroll_Height, this));

	mParentWindow->addChildWindow(mRootWindow);
}

MiniMap::~MiniMap()
{
	mEventAlphaScroll->disconnect();
	mEventHeightScroll->disconnect();

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow->removeChildWindow(mAlphaScroller);
	mRootWindow->removeChildWindow(mHeightScroller);
	mRootWindow->removeChildWindow(mMap);
	mParentWindow->removeChildWindow(mRootWindow);

	wm->destroyWindow(mHeightScroller);
	wm->destroyWindow(mAlphaScroller);
	wm->destroyWindow(mMap);
	wm->destroyWindow(mRootWindow);
}

void MiniMap::setAlpha(float alpha)
{
	if(alpha > 0.1f)
	{
		mRootWindow->setAlpha(alpha);
		mAlphaScroller->setScrollPosition(alpha);
	}
}

void MiniMap::setPosition(float x, float y)
{
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
}
	
void MiniMap::setSize(float w, float h)
{
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(w), cegui_reldim(h)));
}

void MiniMap::hide()
{
	enable(false);
}

bool MiniMap::onScroll_Alpha(const CEGUI::EventArgs& evt)
{
	float alpha=mAlphaScroller->getScrollPosition();
	float ms=0.3f;
	if(alpha > ms)
	{
		mRootWindow->setAlpha(alpha);
	}
	else
	{
		mAlphaScroller->setScrollPosition(ms);
	}

	return true;
}

bool MiniMap::onScroll_Height(const CEGUI::EventArgs& evt)
{
	const float MIN_HEIGHT=100;
	const float MAX_HEIGHT=10000;
	float ratio=mHeightScroller->getScrollPosition();
	float height=MIN_HEIGHT+(MAX_HEIGHT - MIN_HEIGHT) * ratio;

	mCam->setPosition(0.0,0.0,0.0);
    mCam->setOrientation(Ogre::Quaternion::IDENTITY);
    mCam->yaw(Ogre::Degree(0));
    mCam->pitch(Ogre::Degree(-90));
	mCam->roll(Ogre::Degree(-90));
    mCam->moveRelative(Ogre::Vector3(0.0,0.0,height));

	return true;
}

void MiniMap::show()
{
	enable(true);
}

void MiniMap::enable(bool enabled)
{
	mEnabled=enabled;
	if(mEnabled)
	{
		mRootWindow->show();
	}
	else
	{
		mRootWindow->hide();
	}
}

std::string MiniMap::getUIId(const std::string localId)
{
	return mRootId+std::string("/")+localId;
}

CEGUI::Point MiniMap::getMapDim() const
{
	float mwWidth=mRootWindow->getWidth().d_scale;
	float mwHeight=mRootWindow->getHeight().d_scale;

	float mapWidth=mMap->getXPosition().d_scale;
	float mapHeight=mMap->getYPosition().d_scale;

	return CEGUI::Point(mapWidth * mwWidth, mapHeight * mwHeight);
}

CEGUI::Point MiniMap::getMapTopLeft() const
{
	float mwWidth=mRootWindow->getWidth().d_scale;
	float mwHeight=mRootWindow->getHeight().d_scale;

	float mwX=mRootWindow->getXPosition().d_scale;
	float mwY=mRootWindow->getYPosition().d_scale;

	float mapX=mMap->getXPosition().d_scale;
	float mapY=mMap->getYPosition().d_scale;

	return CEGUI::Point(mwX + mwWidth * mapX, mwY + mwHeight * mapY);
}

CEGUI::Point MiniMap::PtInMap(const float& mx, const float& my) const
{
	float mwX=mRootWindow->getXPosition().d_scale;
	float mwY=mRootWindow->getYPosition().d_scale;

	float mwWidth=mRootWindow->getWidth().d_scale;
	float mwHeight=mRootWindow->getHeight().d_scale;

	float mapX=mMap->getXPosition().d_scale;
	float mapY=mMap->getYPosition().d_scale;

	float mapWidth=mMap->getWidth().d_scale;
	float mapHeight=mMap->getHeight().d_scale;

	float mwXX=(mx - mwX) / mwWidth;
	float mwYY=(my - mwY) / mwHeight;

	float mwXXX=(mwXX  - mapX) / mapWidth;
	float mwYYY=(mwYY - mapY) / mapHeight;

	return CEGUI::Point(mwXXX, mwYYY);
}