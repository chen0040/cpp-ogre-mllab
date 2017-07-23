#include "CITextFieldWidget.h"
#include "GUIManager.h"
#include "../OSEnvironment/OSEnvironment.h"
#include <sstream>

CITextFieldWidget::CITextFieldWidget(const std::string& rootId, CIWidget* parentWidget, CEGUI::Window* parentWindow,  float width, float height, float labelWidth)
: CIWidget(parentWidget, parentWindow)
{
	mParam=NULL;
	mWidth=width;
	mHeight=height;
	mLabelWidth=labelWidth;

	initializeComponents(rootId);
}

CITextFieldWidget::CITextFieldWidget(const std::string& rootId, const CIConfigLeafNode* param, CIWidget* parentWidget, CEGUI::Window* parentWindow)
: CIWidget(parentWidget, parentWindow)
{
	mParam=param->clone();
	mWidth=mParam->getWidth();
	mHeight=mParam->getHeight();
	mLabelWidth=mParam->getLabelWidth();

	initializeComponents(rootId);	
}

const CIConfigLeafNode* CITextFieldWidget::getConstLeafNode() const
{
	return mParam;
}
	
CIConfigLeafNode* CITextFieldWidget::getMutableLeafNode()
{
	return mParam;
}

void CITextFieldWidget::doLoad()
{
	mEditbox->setText(mParam->getValue());
}

void CITextFieldWidget::doSave()
{
	mParam->setValue(mEditbox->getText().c_str());
}

CITextFieldWidget::~CITextFieldWidget()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

    mRootWindow->removeChildWindow(mEditbox);
	mRootWindow->removeChildWindow(mLabel);
	mParentWindow->removeChildWindow(mRootWindow);

	wm->destroyWindow(mEditbox);
	wm->destroyWindow(mLabel);
	wm->destroyWindow(mRootWindow);

	if(mParam != NULL)
	{
		delete mParam;
		mParam=NULL;
	}
}

void CITextFieldWidget::create()
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
	
	mEditbox=static_cast<CEGUI::Editbox*>(wm->createWindow(CIWidget::getGUIType("Editbox"), getUIId("Edit")));
	mEditbox->setSize(CEGUI::UVector2(cegui_reldim(1-mLabelWidth), cegui_reldim(1)));
	mEditbox->setPosition(CEGUI::UVector2(cegui_reldim(mLabelWidth), cegui_reldim(0)));
	if(mParam != NULL)	mEditbox->setText(mParam->getValue());
	mRootWindow->addChildWindow(mEditbox);

	mParentWindow->addChildWindow(mRootWindow);
}

void CITextFieldWidget::doPassByParam(std::vector<std::string>& lines) const
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

void CITextFieldWidget::loadXml(TiXmlElement* xmlParam)
{
	std::string value=xmlParam->Attribute("value");
	mParam->setValue(value);
	doLoad();
}

void CITextFieldWidget::saveXml(TiXmlElement* xmlParam)
{
	doSave();
	xmlParam->SetAttribute("value", mParam->getValue().c_str());
}

std::string CITextFieldWidget::toString() const
{
	std::ostringstream oss;
	oss << mParam->getLabel() << ": " << mParam->getValue();
	return oss.str();
}

void CITextFieldWidget::setLabel(const std::string& label)
{
	mLabel->setText(label);
}

void CITextFieldWidget::setText(const std::string& value)
{
	mEditbox->setText(value);
}

void CITextFieldWidget::setText(float value)
{
	std::ostringstream oss;
	oss << value;
	mEditbox->setText(oss.str());
}

std::string CITextFieldWidget::getText() const
{
	return mEditbox->getText().c_str();
}