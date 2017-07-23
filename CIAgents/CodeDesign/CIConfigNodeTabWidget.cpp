#include "CIConfigNodeTabWidget.h"
#include "../../OSEnvironment/OSEnvironment.h"

CIConfigNodeTabWidget::CIConfigNodeTabWidget(const std::string& rootId, const CIConfigNode* section, CIWidget* parentWidget, CEGUI::TabControl* parentWindow)
: CIWidget(parentWidget, parentWindow)
, mSection(section)
{
	initializeComponents(rootId);
}

CIConfigNodeTabWidget::~CIConfigNodeTabWidget()
{
	std::map<std::string, CITextFieldWidget*>::iterator siter=mTextFieldWidgets.begin();
	std::map<std::string, CITextFieldWidget*>::iterator siter_end=mTextFieldWidgets.end();
	for(; siter != siter_end; ++siter)
	{
		delete siter->second;
	}
	mTextFieldWidgets.clear();

	std::map<std::string, CIConfigNodeListWidget*>::iterator witer=mListWidgets.begin();
	std::map<std::string, CIConfigNodeListWidget*>::iterator witer_end=mListWidgets.end();
	for(; witer != witer_end; ++witer)
	{
		delete (witer->second);
	}
	mListWidgets.clear();

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mParentWindow->removeChildWindow(mRootWindow);
	wm->destroyWindow(mRootWindow);
}

void CIConfigNodeTabWidget::create()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow=wm->createWindow(CIWidget::getGUIType("ScrollablePane"), getRootId());
	mRootWindow->setText(mSection->getName());
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0.05f), cegui_reldim(0.05f)));
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.9f), cegui_reldim(0.95f)));
	//mRootWindow->setProperty((CEGUI::utf8*)"Font", (CEGUI::utf8*)"Commonwealth-8");

	static_cast<CEGUI::TabControl*>(mParentWindow)->addTab(mRootWindow);

	float x=0;
	float y=0;
	size_t leafNodeCount=mSection->getLeafNodeCount();
	for(size_t j=0; j != leafNodeCount; ++j)
	{
		const CIConfigLeafNode* const param=mSection->getConstLeafNode(j);
		CITextFieldWidget* widget=new CITextFieldWidget(getUIId(param->getName()), param, this, mRootWindow);
		widget->setPosition(x, y);

		mTextFieldWidgets[param->getName()]=widget;
		y+=(param->getHeight()+param->getVgap());
	}

	size_t nodeListCount=mSection->getNodeListCount();
	for(size_t j=0; j != nodeListCount; ++j)
	{
		const CIConfigNodeList* const lst=mSection->getConstNodeList(j);
		CIConfigNodeListWidget* widget=new CIConfigNodeListWidget(getUIId(lst->getName()), lst, this, mRootWindow);
		widget->setPosition(x, y);
		
		mListWidgets[lst->getName()]=widget;
		y+=(lst->getHeight()+lst->getVgap());
	}
}

void CIConfigNodeTabWidget::doPassByParam(std::vector<std::string>& lines) const
{
	std::map<std::string, CITextFieldWidget*>::const_iterator citer=mTextFieldWidgets.begin();
	std::map<std::string, CITextFieldWidget*>::const_iterator citer_end=mTextFieldWidgets.end();

	for(; citer != citer_end; ++citer)
	{
		(citer->second)->doPassByParam(lines);
	}
}

void CIConfigNodeTabWidget::doSave()
{
	std::map<std::string, CITextFieldWidget*>::iterator iter=mTextFieldWidgets.begin();
	std::map<std::string, CITextFieldWidget*>::iterator iter_end=mTextFieldWidgets.end();
	for(; iter != iter_end; ++iter)
	{
		(iter->second)->doSave();
	}

	std::map<std::string, CIConfigNodeListWidget*>::iterator liter=mListWidgets.begin();
	std::map<std::string, CIConfigNodeListWidget*>::iterator liter_end=mListWidgets.end();
	for(; liter != liter_end; ++liter)
	{
		(liter->second)->doSave();
	}
}

void CIConfigNodeTabWidget::doLoad()
{
	std::map<std::string, CITextFieldWidget*>::const_iterator iter=mTextFieldWidgets.begin();
	std::map<std::string, CITextFieldWidget*>::const_iterator iter_end=mTextFieldWidgets.end();
	for(; iter != iter_end; ++iter)
	{
		(iter->second)->doLoad();
	}

	std::map<std::string, CIConfigNodeListWidget*>::const_iterator liter=mListWidgets.begin();
	std::map<std::string, CIConfigNodeListWidget*>::const_iterator liter_end=mListWidgets.end();
	for(; liter != liter_end; ++liter)
	{
		(liter->second)->doLoad();
	}
}

void CIConfigNodeTabWidget::saveXml(TiXmlElement* xmlTab)
{
	CITextFieldWidget* textField=NULL;
	std::map<std::string, CITextFieldWidget*>::const_iterator iter=mTextFieldWidgets.begin();
	std::map<std::string, CITextFieldWidget*>::const_iterator iter_end=mTextFieldWidgets.end();
	for(; iter != iter_end; ++iter)
	{
		const std::string& paramName=iter->first;
		textField=iter->second;

		TiXmlElement* xmlNode=new TiXmlElement("param");
		xmlNode->SetAttribute("name", paramName.c_str());
		textField->saveXml(xmlNode);
		xmlTab->LinkEndChild(xmlNode);
	}

	CIConfigNodeListWidget* listWidget=NULL;
	std::map<std::string, CIConfigNodeListWidget*>::iterator liter=mListWidgets.begin();
	std::map<std::string, CIConfigNodeListWidget*>::iterator liter_end=mListWidgets.end();
	for(; liter != liter_end; ++liter)
	{
		const std::string& paramName=liter->first;
		listWidget=liter->second;

		TiXmlElement* xmlNode=new TiXmlElement("list_template");
		xmlNode->SetAttribute("name", paramName.c_str());
		listWidget->saveXml(xmlNode);
		xmlTab->LinkEndChild(xmlNode);
	}
}

void CIConfigNodeTabWidget::loadXml(TiXmlElement* xmlTab)
{
	std::map<std::string, CITextFieldWidget*>::iterator fnd1;
	std::map<std::string, CIConfigNodeListWidget*>::iterator fnd2;
	for(TiXmlElement* xmlNode=xmlTab->FirstChildElement(); xmlNode != NULL; xmlNode=xmlNode->NextSiblingElement())
	{
		if(strcmp(xmlNode->Value(), "param")==0)
		{
			std::string name=xmlNode->Attribute("name");
			fnd1=mTextFieldWidgets.find(name);
			if(fnd1 != mTextFieldWidgets.end())
			{
				fnd1->second->loadXml(xmlNode);
			}
		}
		else if(strcmp(xmlNode->Value(), "list_template")==0)
		{
			std::string name=xmlNode->Attribute("name");
			fnd2=mListWidgets.find(name);
			if(fnd2 != mListWidgets.end())
			{
				fnd2->second->loadXml(xmlNode);
			}
		}
	}
}

std::string CIConfigNodeTabWidget::toString() const
{
	std::ostringstream oss;
	
	std::map<std::string, CITextFieldWidget*>::const_iterator iter=mTextFieldWidgets.begin();
	std::map<std::string, CITextFieldWidget*>::const_iterator iter_end=mTextFieldWidgets.end();
	for(; iter != iter_end; ++iter)
	{
		if(iter!=mTextFieldWidgets.begin())
		{
			oss << "\n";
		}
		oss  << (iter->second)->toString();
	}

	return oss.str();
}

void CIConfigNodeTabWidget::doPassByTemplate(const std::string& destinationFile, const std::string& fileType) const
{
	std::map<std::string, CIConfigNodeListWidget*>::const_iterator liter=mListWidgets.begin();
	std::map<std::string, CIConfigNodeListWidget*>::const_iterator liter_end=mListWidgets.end();
	for(; liter != liter_end; ++liter)
	{
		(liter->second)->doPassByTemplate(destinationFile, fileType);
	}
}
