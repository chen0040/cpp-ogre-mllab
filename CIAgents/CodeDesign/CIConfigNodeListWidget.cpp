#include "CIConfigNodeListWidget.h"
#include "../../Widgets/MsgBox.h"
#include <fstream>
#include <iostream>
#include "boost/regex.hpp"
#include "../../OSEnvironment/OSEnvironment.h"
#include "ListItemCreateDlg.h"
#include "ListItemModifyDlg.h"
#include "../../CIType/CIConfigLeafNode.h"
#include "../../Widgets/GUIManager.h"

CIConfigNodeListWidget::CIConfigNodeListWidget(const std::string& rootId, const CIConfigNodeList* const list, CIWidget* parentWidget, CEGUI::Window* parentWindow)
: CIWidget(parentWidget, parentWindow)
{
	mListData=list->clone();
	mTLData=list->clone();
	initializeComponents(rootId);

	mListItemCreateDlg=new ListItemCreateDlg(getUIId("ListItemModifyDlg"), mTLData, mListView, this);
	mListItemModifyDlg=new ListItemModifyDlg(getUIId("ListItemCreateDlg"), mTLData, mListView, this);
}

CIConfigNodeListWidget::~CIConfigNodeListWidget()
{
	if(mListItemCreateDlg != NULL)
	{
		delete mListItemCreateDlg;
		mListItemCreateDlg=NULL;
	}
	if(mListItemModifyDlg != NULL)
	{
		delete mListItemModifyDlg;
		mListItemModifyDlg=NULL;
	}

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow->removeChildWindow(mListView);
	mRootWindow->removeChildWindow(mBtnCreate);
	mRootWindow->removeChildWindow(mBtnDelete);
	mRootWindow->removeChildWindow(mBtnModify);
	mRootWindow->removeChildWindow(mEditbox);
	mRootWindow->removeChildWindow(mLabel);
	mParentWindow->removeChildWindow(mRootWindow);

	wm->destroyWindow(mListView);
	wm->destroyWindow(mBtnCreate);
	wm->destroyWindow(mBtnDelete);
	wm->destroyWindow(mBtnModify);
	wm->destroyWindow(mEditbox);
	wm->destroyWindow(mLabel);
	wm->destroyWindow(mRootWindow);

	if(mTLData != NULL)
	{
		delete mTLData;
		mTLData=NULL;
	}

	if(mListData != NULL)
	{
		delete mListData;
		mListData=NULL;
	}
}

void CIConfigNodeListWidget::create()
{
	float button_width=mListData->getButtonWidth();
	float button_height=mListData->getButtonHeight();
	float label_height=mListData->getLabelHeight();

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow=static_cast<CEGUI::DefaultWindow*>(wm->createWindow(CIWidget::getGUIType("DefaultWindow"), getRootId()));
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(mListData->getHeight()), cegui_reldim(mListData->getHeight())));

	mLabel=static_cast<CEGUI::DefaultWindow*>(wm->createWindow(CIWidget::getGUIType("StaticText"), getUIId("ListboxLabel")));
	mLabel->setSize(CEGUI::UVector2(cegui_reldim(1), cegui_reldim(label_height)));
	mLabel->setPosition(CEGUI::UVector2(cegui_reldim(0), cegui_reldim(0)));
	mLabel->setText(mListData->getLabel());
	mLabel->setProperty((CEGUI::utf8*)"FrameEnabled", (CEGUI::utf8*)"false");
	mLabel->setProperty((CEGUI::utf8*)"BackgroundEnabled", (CEGUI::utf8*)"false");
	mRootWindow->addChildWindow(mLabel);
	
	mListView=static_cast<CEGUI::Listbox*>(wm->createWindow(CIWidget::getGUIType("Listbox"), getUIId("Listbox")));
	mListView->setSize(CEGUI::UVector2(cegui_reldim(1-button_width), cegui_reldim(1-label_height-mListData->getDetailHeight())));
	mListView->setPosition(CEGUI::UVector2(cegui_reldim(0), cegui_reldim(label_height)));
	mRootWindow->addChildWindow(mListView);

	float x=1-button_width;
	float y=label_height;
	mBtnCreate=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnCreate")));
	mBtnCreate->setSize(CEGUI::UVector2(cegui_reldim(button_width), cegui_reldim(button_height)));
	mBtnCreate->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnCreate->setText((CEGUI::utf8*)"Add");
	mRootWindow->addChildWindow(mBtnCreate);

	y+=button_height;
	mBtnDelete=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnDelete")));
	mBtnDelete->setSize(CEGUI::UVector2(cegui_reldim(button_width), cegui_reldim(button_height)));
	mBtnDelete->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnDelete->setText((CEGUI::utf8*)"Delete");
	mRootWindow->addChildWindow(mBtnDelete);

	y+=button_height;
	mBtnModify=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnModify")));
	mBtnModify->setSize(CEGUI::UVector2(cegui_reldim(button_width), cegui_reldim(button_height)));
	mBtnModify->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnModify->setText((CEGUI::utf8*)"Modify");
	mRootWindow->addChildWindow(mBtnModify);

	mEditbox=static_cast<CEGUI::MultiLineEditbox*>(wm->createWindow(CIWidget::getGUIType("MultiLineEditbox"), getUIId("editBox")));
	mEditbox->setSize(CEGUI::UVector2(cegui_reldim(1), cegui_reldim(mListData->getDetailHeight())));
	mEditbox->setPosition(CEGUI::UVector2(cegui_reldim(0), cegui_reldim(1-mListData->getDetailHeight())));
	mEditbox->setReadOnly(true);
	mRootWindow->addChildWindow(mEditbox);

	mParentWindow->addChildWindow(mRootWindow);
}

void CIConfigNodeListWidget::subscribeEvents()
{
	mEventCreate=mBtnCreate->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&CIConfigNodeListWidget::onClicked_Create, this));
	mEventDelete=mBtnDelete->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&CIConfigNodeListWidget::onClicked_Delete, this));
	mEventModify=mBtnModify->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&CIConfigNodeListWidget::onClicked_Modify, this));
	mEventSelectionChange=mListView->subscribeEvent(CEGUI::Listbox::EventSelectionChanged, CEGUI::Event::Subscriber(&CIConfigNodeListWidget::onItemChanged_List, this));
}

void CIConfigNodeListWidget::unsubscribeEvents()
{
	mEventCreate->disconnect();
	mEventDelete->disconnect();
	mEventModify->disconnect();
	mEventSelectionChange->disconnect();
}

bool CIConfigNodeListWidget::onClicked_Create(const CEGUI::EventArgs& evt)
{
	mListItemCreateDlg->setListData(mTLData);
	mListItemCreateDlg->showModal();

	return true;
}
	
bool CIConfigNodeListWidget::onClicked_Delete(const CEGUI::EventArgs& evt)
{
	if(mListView->getItemCount() > 0)
	{
		mListView->removeItem(mListView->getListboxItemFromIndex(mTLData->getItemCount()-1));
	}
	mTLData->removeLastItem();

	return true;
}

bool CIConfigNodeListWidget::onClicked_Modify(const CEGUI::EventArgs& evt)
{
	if(mListView->getSelectedCount() > 0)
	{
		mListItemModifyDlg->setListData(mTLData);
		mListItemModifyDlg->showModal();
	}
	else
	{
		GUIManager::getSingletonPtr()->showMsgBox("No Item Selected", "Please select an item to modify");
	}

	return true;
}

void CIConfigNodeListWidget::doLoad()
{
	delete mTLData;
	mTLData=mListData->clone();

	mListView->resetList();
	size_t count=mListData->getItemCount();
	for(size_t j=0; j != count; ++j)
	{
		CEGUI::ListboxTextItem* item=new CEGUI::ListboxTextItem(mTLData->getItemName(j), static_cast<CEGUI::uint>(j));
		item->setSelectionBrushImage((CEGUI::utf8*)GUIManager::getSingletonPtr()->getGUITheme().c_str(), (CEGUI::utf8*)"MultiListSelectionBrush");
		item->setUserData(mTLData->getMutableNode(j));
		mListView->addItem(item);
	}
	
}

bool CIConfigNodeListWidget::onItemChanged_List(const CEGUI::EventArgs& evt)
{
	if(mListView->getSelectedCount() > 0)
	{
		CEGUI::ListboxItem* vitem=mListView->getFirstSelectedItem();
		CIConfigNode* citem=static_cast<CIConfigNode*>(vitem->getUserData());
		mEditbox->setText(citem->toString());
	}
	else
	{
		mEditbox->setText((CEGUI::utf8*)"");
	}

	return true;
}

void CIConfigNodeListWidget::doSave()
{
	delete mListData;
	mListData=mTLData->clone();
}
	
void CIConfigNodeListWidget::doPassByTemplate(const std::string& destinationFile, const std::string& fileType) const
{
	std::ostringstream oss;
	oss << "\\\\begin\\{template\\}\\[";
	oss << mListData->getName();
	oss << "\\]";
	boost::regex reg(oss.str());
	std::vector<std::string> lines;

	std::ifstream infile;
	infile.open(destinationFile.c_str());

	std::string line;
	bool inRZone=false;
	std::vector<std::string> rlines;
	while(std::getline(infile, line))
	{
		std::string::const_iterator it=line.begin(); 
		std::string::const_iterator end=line.end();
		boost::smatch m;
		if(boost::regex_search(it, end, m, reg))
		{
			inRZone=true;
			rlines.clear();
		}
		else
		{
			if(line.find("\\end{template}") == std::string::npos)
			{
				if(inRZone)
				{
					rlines.push_back(line);
				}
				else
				{
					lines.push_back(line);
				}
			}
			else
			{
				std::string tagParamName;
				size_t count=mListData->getItemCount();
				for(size_t j1=0; j1 != count; ++j1)
				{
					const CIConfigNode* item=mListData->getConstNode(j1);

					std::vector<std::string> tlines;
					size_t rlineCount=rlines.size();
					for(size_t j2=0; j2 != rlineCount; ++j2)
					{
						tlines.push_back(rlines[j2]);
					}

					size_t tlineCount=0;
					size_t leafNodeCount=item->getLeafNodeCount();
					for(size_t j2=0; j2 != leafNodeCount; ++j2)
					{
						const CIConfigLeafNode* param=item->getConstLeafNode(j2);
						
						tlineCount=tlines.size();
						for(size_t l=0; l != tlineCount; ++l)
						{
							std::string& tline=tlines[l];
							tagParamName=std::string("\\param{")+param->getName()+std::string("}");
							const std::string& paramValue=param->getValue();
							size_t fnd=tline.find(tagParamName);
							while(fnd != std::string::npos)
							{
								tline.replace(fnd, tagParamName.length(), paramValue);
								fnd=tline.find(tagParamName);
							}
						}
					}
					
					tlineCount=tlines.size();
					for(size_t j2=0; j2 != tlineCount; ++j2)
					{
						lines.push_back(tlines[j2]);
					}
				}
				inRZone=false;
			}
		}
		
	}

	infile.close();

	OSEnvironment::writeLines(destinationFile, fileType, lines);
}

void CIConfigNodeListWidget::loadXml(TiXmlElement *xmlList)
{	
	mListData->clear();

	CIConfigNode* item=NULL;
	for(TiXmlElement* xmlListItem=xmlList->FirstChildElement(); xmlListItem != NULL; xmlListItem = xmlListItem->NextSiblingElement())
	{
		
		if(strcmp(xmlListItem->Value(), "list_item_template")==0)
		{
			item=mListData->createItem();
			std::string listItemName=xmlListItem->Attribute("name");
			for(TiXmlElement* xmlListItemParam=xmlListItem->FirstChildElement(); xmlListItemParam != NULL; xmlListItemParam=xmlListItemParam->NextSiblingElement())
			{
				if(strcmp(xmlListItemParam->Value(), "param")==0)
				{
					std::string listItemParamName=xmlListItemParam->Attribute("name");
					std::string listItemParamValue=xmlListItemParam->Attribute("value");
					item->getMutableLeafNode(listItemParamName)->setValue(listItemParamValue);
				}
			}
			mListData->addItem(listItemName, item);
		}
	}

	doLoad();
}

void CIConfigNodeListWidget::saveXml(TiXmlElement *xmlNode)
{
	doSave();
	
	const std::vector<std::string>& nodeNames=mListData->getNodeNames();
	size_t nodeCount=nodeNames.size();
	size_t leafNodeCount=0;
	for(size_t j=0; j != nodeCount; ++j)
	{
		const CIConfigNode* node=mListData->getConstNode(nodeNames[j]);
		TiXmlElement* xmlListItem=new TiXmlElement("list_item_template");
		xmlListItem->SetAttribute("name", nodeNames[j].c_str());

		leafNodeCount=node->getLeafNodeCount();
		for(size_t k=0; k != leafNodeCount; ++k)
		{
			const CIConfigLeafNode* leaf=node->getConstLeafNode(k);
			TiXmlElement* xmlListItemParam=new TiXmlElement("param");
			xmlListItemParam->SetAttribute("name", leaf->getName().c_str());
			xmlListItemParam->SetAttribute("value", leaf->getValue().c_str());

			xmlListItem->LinkEndChild(xmlListItemParam);
		}

		xmlNode->LinkEndChild(xmlListItem);
	}
}

