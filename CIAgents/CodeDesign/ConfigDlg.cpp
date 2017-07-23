#include "ConfigDlg.h"
#include "../../CIType/CIMethod.h"
#include "../../OSEnvironment/OSEnvironment.h"
#include "../../CIType/CIManager.h"
#include "../../Widgets/GUIManager.h"
#include "boost/regex.hpp"
#include "../../Widgets/MsgBox.h"
#include "CIConfigNodeTabWidget.h"
#include "../../CIType/CIMethod.h"
#include "../../SoundEngine/SoundManager.h"

size_t ConfigDlg::mNumConfigDlgShown=0;

ConfigDlg::ConfigDlg(const std::string& rootId,  const std::string& citype, const std::string& cimethod, CEGUI::Window* parentWindow)
: CIWidget(NULL, parentWindow)
{
	mCITypeName=citype;
	mCIMethodName=cimethod;

	initializeComponents(rootId);
}

void ConfigDlg::subscribeEvents()
{
	mEventClickedOK=mBtnOK->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ConfigDlg::onOK, this));
	mEventClickedCancel=mBtnCancel->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ConfigDlg::onCancel, this));
	mEventCloseClicked=mRootWindow->subscribeEvent(CEGUI::FrameWindow::EventCloseClicked, CEGUI::Event::Subscriber(&ConfigDlg::onCancel, this));
}

void ConfigDlg::unsubscribeEvents()
{
	mEventClickedOK->disconnect();
	mEventClickedCancel->disconnect();
	mEventCloseClicked->disconnect();
}

ConfigDlg::~ConfigDlg()
{
	std::map<std::string, CIConfigNodeTabWidget*>::iterator iter=mTabPanels.begin();
	std::map<std::string, CIConfigNodeTabWidget*>::iterator iter_end=mTabPanels.end();
	for(; iter != iter_end;++iter)
	{
		delete (iter->second);
	}
	mTabPanels.clear();

	mRootWindow->removeChildWindow(mTabControl);
	mRootWindow->removeChildWindow(mBtnOK);
	mRootWindow->removeChildWindow(mBtnCancel);
	mParentWindow->removeChildWindow(mRootWindow);

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();
	wm->destroyWindow(mTabControl);
	wm->destroyWindow(mBtnOK);
	wm->destroyWindow(mBtnCancel);
	wm->destroyWindow(mRootWindow);
}

void ConfigDlg::showModal()
{
	doLoad();
	setModalState(true);

	mRootWindow->setPosition(CEGUI::UVector2(cegui_absdim(10.0f+mNumConfigDlgShown*10.0f), CEGUI::UDim(0.1f, mNumConfigDlgShown*10.0f)));
	showWindow();
	mNumConfigDlgShown++;

	SoundManager::getSingletonPtr()->play("chimes");
}

void ConfigDlg::saveXml(TiXmlElement* xmlConfig)
{
	CIConfigNodeTabWidget* tab=NULL;
	std::map<std::string, CIConfigNodeTabWidget*>::iterator iter=mTabPanels.begin();
	std::map<std::string, CIConfigNodeTabWidget*>::iterator iter_end=mTabPanels.end();
	for(; iter != iter_end;++iter)
	{
		const std::string& tabName=iter->first;
		tab=iter->second;
		
		TiXmlElement* xmlNode=new TiXmlElement("section");
		xmlNode->SetAttribute("name", tabName.c_str());

		tab->saveXml(xmlNode);
		xmlConfig->LinkEndChild(xmlNode);
	}
}

void ConfigDlg::loadXml(TiXmlElement* xmlConfig)
{
	CIConfigNodeTabWidget* tab=NULL;
	for(TiXmlElement* xmlNode=xmlConfig->FirstChildElement(); xmlNode != NULL; xmlNode=xmlNode->NextSiblingElement())
	{
		if(strcmp(xmlNode->Value(), "section")==0)
		{
			std::string tabName=xmlNode->Attribute("name");
			std::map<std::string, CIConfigNodeTabWidget*>::iterator fnd=mTabPanels.find(tabName);
			if(fnd!=mTabPanels.end())
			{
				tab=fnd->second;
				tab->loadXml(xmlNode);
			}
		}
	}
}

void ConfigDlg::create()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow=wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId());
	mRootWindow->setAlpha(0.5);
	mRootWindow->setText(mCITypeName+std::string(":")+mCIMethodName);
	mRootWindow->setModalState(false);
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.6f), cegui_reldim(0.65f)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_absdim(10.0f), cegui_reldim(0.1f)));
	mRootWindow->hide();

	const float normalizedButtonHeight=0.08f;

	mBtnOK=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), this->getUIId("OK")));
	mBtnOK->setText((CEGUI::utf8*)"OK");
	mBtnOK->setSize(CEGUI::UVector2(cegui_reldim(0.15f), cegui_reldim(normalizedButtonHeight)));
	mBtnOK->setPosition(CEGUI::UVector2(cegui_reldim(0.6f), cegui_reldim(0.9f)));
	mRootWindow->addChildWindow(mBtnOK);

	mBtnCancel=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), this->getUIId("Cancel")));
	mBtnCancel->setText((CEGUI::utf8*)"Cancel");
	mBtnCancel->setSize(CEGUI::UVector2(cegui_reldim(0.195f), cegui_reldim(normalizedButtonHeight)));
	mBtnCancel->setPosition(CEGUI::UVector2(cegui_reldim(0.755f), cegui_reldim(0.9f)));
	mRootWindow->addChildWindow(mBtnCancel);

	mTabControl=static_cast<CEGUI::TabControl*>(wm->createWindow(CIWidget::getGUIType("TabControl"), this->getUIId("tc")));
	mTabControl->setSize(CEGUI::UVector2(cegui_reldim(0.9f), cegui_reldim(0.82f)));
	mTabControl->setPosition(CEGUI::UVector2(cegui_reldim(0.05f), cegui_reldim(0.07f)));
	mRootWindow->addChildWindow(mTabControl);

	const CIMethod* const method=CIManager::getSingletonPtr()->getCIType(mCITypeName)->getConstMethod(mCIMethodName);
	const std::vector<std::string>& sectionNames=method->getSectionNames();

	size_t sectionCount=sectionNames.size();
	//sectionCount=0;
	for(size_t k=0; k != sectionCount; k++)
	{
		const std::string& sectionName=sectionNames[k];
		const CIConfigNode* section=method->getConstSection(sectionName);

		CIConfigNodeTabWidget* tabPanel=new CIConfigNodeTabWidget(getUIId(sectionName), section, this, mTabControl);
		mTabPanels[sectionName]=tabPanel;
	}

	//mTabControl->setTabHeight(cegui_reldim(0.1f));
	
	/*CEGUI::Window* win=wm->createWindow(CIWidget::getGUIType("TabContentPane"), getUIId("test"));
	win->setText("shit");
	CEGUI::Window* win2=wm->createWindow(CIWidget::getGUIType("TabContentPane"), getUIId("test2"));
	win2->setText("shit2");
	mTabControl->addTab(win);
	mTabControl->addTab(win2);*/

	mParentWindow->addChildWindow(mRootWindow);
}

void ConfigDlg::processFile(const std::string& destinationFile, const std::string& fileType) const
{
	doPassByParam(destinationFile, fileType);
	doPassByRepeat(destinationFile, fileType);
	doPassByTemplate(destinationFile, fileType);
	doPassByArray(destinationFile, fileType);
}

void ConfigDlg::doPassByTemplate(const std::string& destinationFile, const std::string& fileType) const
{
	std::map<std::string, CIConfigNodeTabWidget*>::const_iterator citer=mTabPanels.begin();
	std::map<std::string, CIConfigNodeTabWidget*>::const_iterator citer_end=mTabPanels.end();
	for(; citer != citer_end; ++citer)
	{
		(citer->second)->doPassByTemplate(destinationFile, fileType);
	}
}

void ConfigDlg::doPassByRepeat(const std::string& destinationFile, const std::string& fileType) const
{
	boost::regex reg("\\\\begin\\{repeat\\}\\[(\\d+)\\]");
	std::vector<std::string> lines;

	std::ifstream infile;
	infile.open(destinationFile.c_str());

	std::string line;
	int repeat_count=0;
	bool inRZone=false;
	std::vector<std::string> rlines;
	while(std::getline(infile, line))
	{
		std::string::const_iterator it=line.begin(); 
		std::string::const_iterator end=line.end();
		boost::smatch m;
		if(boost::regex_search(it, end, m, reg))
		{
			repeat_count=OSEnvironment::parseInt(m[1].str());
			inRZone=true;
			rlines.clear();
		}
		else
		{
			if(line.find("\\end{repeat}") == std::string::npos)
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
				size_t rlineCount=0;
				for(int j=0; j<repeat_count; ++j)
				{
					rlineCount=rlines.size();
					for(size_t k=0; k<rlineCount; ++k)
					{
						lines.push_back(rlines[k]);
					}
				}
				inRZone=false;
			}
		}
		
	}

	infile.close();

	OSEnvironment::writeLines(destinationFile, fileType, lines);
}

void ConfigDlg::doPassByArray(const std::string& destinationFile, const std::string& fileType) const
{
	boost::regex reg("\\\\array\\[(\\w+)\\]\\[(\\d+)\\]\\{([^\\}]+)\\}");
	boost::regex reg2("[^\\,]+");

	std::vector<std::string> outlines;

	std::ifstream infile;
	infile.open(destinationFile.c_str());

	std::string line;
	while(std::getline(infile, line))
	{
		bool done=false;
		while(!done)
		{
			boost::smatch m;
			std::string::const_iterator it=line.begin();
			std::string::const_iterator end=line.end();
			if(boost::regex_search(it, end, m, reg))
			{
				const std::string& permutationType=m[1].str();
				int permutationLength=OSEnvironment::parseInt(m[2].str());
				const std::string& alleles=m[3].str();
				std::vector<std::string> ts;
				boost::smatch m2;
				std::string::const_iterator it2=alleles.begin();
				std::string::const_iterator end2=alleles.end();
				while(boost::regex_search(it2, end2, m2, reg2))
				{
					ts.push_back(m2[0].str());
					it2=m2[0].second;
				}
				it=m[0].second;

				std::ostringstream oss;
				if(permutationType.compare("discrete")==0)
				{
					for(int i=0; i<permutationLength; i++)
					{
						size_t index=rand() % ts.size(); 
						oss << ts[index];
						if(i != permutationLength-1)
						{
							oss << ", ";
						}
					}
				}
				else if(permutationType.compare("continuous")==0)
				{
					float lowerbound=OSEnvironment::parseFloat(ts[0]);
					float upperbound=OSEnvironment::parseFloat(ts[1]);

					for(int i=0; i<permutationLength; i++)
					{
						oss << Ogre::Math::RangeRandom(lowerbound, upperbound);
						if(i != permutationLength-1)
						{
							oss << ", ";
						}
					}
				}
				std::string reduciable=m[0].str();
				size_t fnd=line.find(reduciable);
				if(fnd != std::string::npos)
				{
					line.replace(fnd, reduciable.length(), oss.str());
				}
			}
			else
			{
				done=true;
			}
		}
		outlines.push_back(line);
	}

	OSEnvironment::writeLines(destinationFile, fileType, outlines);
}

void ConfigDlg::doPassByParam(const std::string& destinationFile, const std::string& fileType) const
{
	std::vector<std::string> lines;

	std::ifstream infile;
	infile.open(destinationFile.c_str());

	std::string line;
	while(std::getline(infile, line))
	{
		lines.push_back(line);
	}

	infile.close();

	std::map<std::string, CIConfigNodeTabWidget*>::const_iterator citer=mTabPanels.begin();
	std::map<std::string, CIConfigNodeTabWidget*>::const_iterator citer_end=mTabPanels.end();
	for(; citer != citer_end; ++citer)
	{
		(citer->second)->doPassByParam(lines);
	}

	OSEnvironment::writeLines(destinationFile, fileType, lines);
}


bool ConfigDlg::onCancel(const CEGUI::EventArgs& evt)
{
	setModalState(false);	
	hideWindow();
	mNumConfigDlgShown--;

	return true; 
}

bool ConfigDlg::onOK(const CEGUI::EventArgs& evt)
{
	doSave();
	setModalState(false);
	hideWindow();
	mNumConfigDlgShown--;

	return true; 
}

void ConfigDlg::doLoad()
{
	std::map<std::string, CIConfigNodeTabWidget*>::iterator iter=mTabPanels.begin();
	std::map<std::string, CIConfigNodeTabWidget*>::iterator iter_end=mTabPanels.end();
	for(; iter != iter_end;++iter)
	{
		(iter->second)->doLoad();
	}
}

void ConfigDlg::doSave()
{
	std::map<std::string, CIConfigNodeTabWidget*>::iterator iter=mTabPanels.begin();
	std::map<std::string, CIConfigNodeTabWidget*>::iterator iter_end=mTabPanels.end();
	for(; iter != iter_end;++iter)
	{
		(iter->second)->doSave();
	}
}

std::string ConfigDlg::toString() const
{
	std::ostringstream oss;
	std::map<std::string, CIConfigNodeTabWidget*>::const_iterator iter_begin=mTabPanels.begin();
	std::map<std::string, CIConfigNodeTabWidget*>::const_iterator iter_end=mTabPanels.end();
	std::map<std::string, CIConfigNodeTabWidget*>::const_iterator iter=iter_begin;
	
	for(; iter !=iter_end;++iter)
	{
		if(iter != iter_begin)
		{
			oss << "\n";
		}
		oss << (iter->second)->toString();
	}
	return oss.str();
}

