#include "OceanDesignToolkit.h"
#include "../../SceneAssets/HydraxManager.h"
#include "../../OSEnvironment/OSEnvironment.h"

OceanDesignToolkit::OceanDesignToolkit(const std::string& rootId)
: CIWidget(NULL, NULL)
{
	this->initializeComponents(rootId);
}
	
OceanDesignToolkit::~OceanDesignToolkit()
{
	if(mEditHeight != NULL)
	{
		delete mEditHeight;
		mEditHeight=NULL;
	}
	if(mEditSizeX != NULL)
	{
		delete mEditSizeX;
		mEditSizeX=NULL;
	}
	if(mEditSizeZ != NULL)
	{
		delete mEditSizeZ;
		mEditSizeZ=NULL;
	}
}

void OceanDesignToolkit::create()
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
	mRootWindow->setText((CEGUI::utf8*)"Ocean Design Toolkit");
	mRootWindow->hide();

	const float height=0.08f;
	const float width=0.9f;
	const float left=0.05f;
	const float top=0.1f;
	const float vgap=0.008f;

	float x=left;
	float y=top;
	
	mEditHeight=new CITextFieldWidget(getUIId("EditHeight"), this, mRootWindow, width, height, 0.35f);
	mEditHeight->setLabel("height: ");
	mEditHeight->setPosition(x, y);

	y+=(height+vgap);
	mEditSizeX=new CITextFieldWidget(getUIId("EditSizeX"), this, mRootWindow, width, height, 0.35f);
	mEditSizeX->setLabel("sizeX: ");
	mEditSizeX->setPosition(x, y);

	y+=(height+vgap);
	mEditSizeZ=new CITextFieldWidget(getUIId("EditSizeZ"), this, mRootWindow, width, height, 0.35f);
	mEditSizeZ->setLabel("sizeZ: ");
	mEditSizeZ->setPosition(x, y);

	y+=(height+vgap);
	mBtnApply=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnApply")));
	mBtnApply->setSize(CEGUI::UVector2(cegui_reldim(0.2f), cegui_reldim(height)));
	mBtnApply->setPosition(CEGUI::UVector2(cegui_reldim(0.75f), cegui_reldim(y)));
	mBtnApply->setText((CEGUI::utf8*)"Apply");
	mRootWindow->addChildWindow(mBtnApply);

	mParentWindow->addChildWindow(mRootWindow);
}

void OceanDesignToolkit::subscribeEvents()
{
	mEventApply=mBtnApply->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&OceanDesignToolkit::onButtonClicked_Apply, this));
}

void OceanDesignToolkit::unsubscribeEvents()
{
	mEventApply->disconnect();
}

bool OceanDesignToolkit::onButtonClicked_Apply(const CEGUI::EventArgs& evt)
{
	HydraxManager* cm=HydraxManager::getSingletonPtr();

	int height, sizeX, sizeZ;
	height=OSEnvironment::parseInt(mEditHeight->getText());
	sizeX=OSEnvironment::parseInt(mEditSizeX->getText());
	sizeZ=OSEnvironment::parseInt(mEditSizeZ->getText());
	
	cm->setOgreOceanSize(sizeX, sizeZ);
	cm->setOgreOceanHeight(height);
	
	return true;
}

void OceanDesignToolkit::show()
{
	HydraxManager* cm=HydraxManager::getSingletonPtr();

	int height, sizeX, sizeZ;
	height=cm->getOgreOceanHeight();
	sizeX=cm->getOgreOceanSizeX();
	sizeZ=cm->getOgreOceanSizeZ();

	mEditHeight->setText(OSEnvironment::toString(height));
	mEditSizeX->setText(OSEnvironment::toString(sizeX));
	mEditSizeZ->setText(OSEnvironment::toString(sizeZ));

	CIWidget::show();
}