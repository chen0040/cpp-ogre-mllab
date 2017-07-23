#include "CIComboWidget.h"
#include "GUIManager.h"
#include <sstream>

CIComboWidget::CIComboWidget(const std::string& rootId, CIWidget* parentWidget, CEGUI::Window* parentWindow,  float width, float height, float labelWidth)
: CIWidget(parentWidget, parentWindow)
{
	mParam=NULL;
	mWidth=width;
	mHeight=height;
	mLabelWidth=labelWidth;
	initializeComponents(rootId);
}

CIComboWidget::CIComboWidget(const std::string& rootId, const CIConfigLeafNode* param, CIWidget* parentWidget, CEGUI::Window* parentWindow)
: CIWidget(parentWidget, parentWindow)
{
	mParam=param->clone();
	mWidth=mParam->getWidth();
	mHeight=mParam->getHeight();
	mLabelWidth=mParam->getLabelWidth();
	initializeComponents(rootId);	
}

const CIConfigLeafNode* CIComboWidget::getConstLeafNode() const
{
	return mParam;
}
	
CIConfigLeafNode* CIComboWidget::getMutableLeafNode()
{
	return mParam;
}

void CIComboWidget::doLoad()
{
	mCombobox->setText(mParam->getValue());
}

void CIComboWidget::doSave()
{
	mParam->setValue(mCombobox->getText().c_str());
}

CIComboWidget::~CIComboWidget()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow->removeChildWindow(mCombobox);
	mRootWindow->removeChildWindow(mLabel);
	mParentWindow->removeChildWindow(mRootWindow);

	wm->destroyWindow(mCombobox);
	wm->destroyWindow(mLabel);
	wm->destroyWindow(mRootWindow);

	if(mParam != NULL)
	{
		delete mParam;
		mParam=NULL;
	}
}

void CIComboWidget::create()
{	
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow=wm->createWindow(CIWidget::getGUIType("DefaultWindow"), getRootId());
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(mWidth), cegui_reldim(mHeight)));

	mLabel=static_cast<CEGUI::DefaultWindow*>(wm->createWindow(CIWidget::getGUIType("StaticText"), getUIId("Label")));
	mLabel->setSize((CEGUI::UVector2(cegui_reldim(mLabelWidth), cegui_reldim(1))));
	mLabel->setPosition((CEGUI::UVector2(cegui_reldim(0), cegui_reldim(0))));
	if(mParam != NULL) mLabel->setText(mParam->getLabel());
	mLabel->setProperty((CEGUI::utf8*)"FrameEnabled", (CEGUI::utf8*)"false");
	mLabel->setProperty((CEGUI::utf8*)"BackgroundEnabled", (CEGUI::utf8*)"false");
	mRootWindow->addChildWindow(mLabel);
	
	mCombobox=static_cast<CEGUI::Combobox*>(wm->createWindow(CIWidget::getGUIType("Combobox"), getUIId("Combo")));
	mCombobox->setSize(CEGUI::UVector2(cegui_reldim(1-mLabelWidth), cegui_reldim(5)));
	mCombobox->setPosition(CEGUI::UVector2(cegui_reldim(mLabelWidth), cegui_reldim(0)));
	mCombobox->setClippedByParent(false);
	mCombobox->setShowVertScrollbar(true);
	mRootWindow->addChildWindow(mCombobox);

	mParentWindow->addChildWindow(mRootWindow);
}

void CIComboWidget::doPassByParam(std::vector<std::string>& lines) const
{
	std::string tagParamName;
	size_t lineCount=lines.size();
	for(size_t k=0; k != lineCount; ++k)
	{
		std::string& line=lines[k];
		tagParamName=std::string("\\param{")+mParam->getName()+std::string("}");
		const std::string& paramValue=mParam->getValue();
		size_t fnd=line.find(tagParamName);
		while(fnd != std::string::npos)
		{
			line.replace(fnd, tagParamName.length(), paramValue);
			fnd=line.find(tagParamName);
		}
	}
}

std::string CIComboWidget::toString() const
{
	std::ostringstream oss;
	oss << mParam->getLabel() << ": " << mParam->getValue();
	return oss.str();
}

void CIComboWidget::setLabel(const std::string& label)
{
	mLabel->setText(label);
}

void CIComboWidget::setText(const std::string& value)
{
	mCombobox->setText(value.c_str());
}
	
std::string CIComboWidget::getText() const
{
	return mCombobox->getText().c_str();
}
