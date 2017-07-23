#include "BuildingDesignToolkit.h"
#include "../../GameEngine/Application.h"
#include "../../tinyxml/tinyxml.h"
#include "../../OSEnvironment/OSEnvironment.h"
#include "../../CIAgents/StaticAgentManager.h"

BuildingDesignToolkit::BuildingDesignToolkit(const std::string& rootId)
: CIWidget(NULL, NULL)
{
	initializeComponents(rootId);
}

BuildingDesignToolkit::~BuildingDesignToolkit()
{
	
}

void BuildingDesignToolkit::subscribeEvents()
{
	mEventListSelectionChanged=mBuildingList->subscribeEvent(CEGUI::Listbox::EventSelectionChanged, CEGUI::Event::Subscriber(&BuildingDesignToolkit::onSelectionChanged_BuildingTypeUri, this));
}

void BuildingDesignToolkit::unsubscribeEvents()
{
	mEventListSelectionChanged->disconnect();
}

void BuildingDesignToolkit::create()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	const float panelHeight=0.7f;
	const float panelWidth=0.25f;

	mRootWindow=wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId());
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(panelWidth), cegui_reldim(panelHeight)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0), cegui_reldim(0.1f)));
	mRootWindow->setAlpha(0.5);
	mRootWindow->setText((CEGUI::utf8*)"Building Design Toolkit");
	mRootWindow->hide();

	const float buttonHeight=0.1f;
	const float buttonWidth=0.9f;
	const float left=0.05f;
	const float top=0.1f;
	const float vgap=0.01f;

	float x=left;
	float y=top;
	float listHeight=(1-y-0.1f);
	mBuildingList=static_cast<CEGUI::Listbox*>(wm->createWindow(CIWidget::getGUIType("Listbox"), getUIId("BuildingTypeUriList")));
	mBuildingList->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(listHeight)));
	mBuildingList->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBuildingList->setMultiselectEnabled(false);
	mRootWindow->addChildWindow(mBuildingList);

	

	const std::vector<std::string>& buildings=StaticAgentManager::getSingletonPtr()->getStaticAgentModels();
	const std::string& building=StaticAgentManager::getSingletonPtr()->getSelectedStaticAgentModel();

	std::vector<std::string>::const_iterator iter=buildings.begin();
	std::vector<std::string>::const_iterator iter_end=buildings.end();
	CEGUI::uint k=0;
	for(; iter != iter_end; ++iter)
	{
		CEGUI::ListboxTextItem* item=new CEGUI::ListboxTextItem(*iter, static_cast<CEGUI::uint>(k++));
		item->setTooltipText(*iter);
		item->setSelectionBrushImage((CEGUI::utf8*)GUIManager::getSingletonPtr()->getGUITheme().c_str(), (CEGUI::utf8*)"MultiListSelectionBrush");

		if((*iter).compare(building)==0)
		{
			item->setSelected(true);
		}
		mBuildingList->addItem(item);
	}

	y+=(listHeight+0.01f);
	mChkBuild=static_cast<CEGUI::Checkbox*>(wm->createWindow(CIWidget::getGUIType("Checkbox"), this->getUIId("chkBuild")));
	mChkBuild->setSize(CEGUI::UVector2(cegui_reldim(buttonWidth), cegui_reldim(0.05f)));
	mChkBuild->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mChkBuild->setText("Build");
	mRootWindow->addChildWindow(mChkBuild);

	mParentWindow->addChildWindow(mRootWindow);
}

void BuildingDesignToolkit::hide()
{
	CIWidget::hide();
	mChkBuild->setSelected(false);
}

bool BuildingDesignToolkit::isBuilding() const
{
	return mChkBuild->isSelected();
}

void BuildingDesignToolkit::show()
{
	updateBuildingTypeUriUI();

	CIWidget::show();
}

void BuildingDesignToolkit::updateBuildingTypeUriUI()
{
	
}

bool BuildingDesignToolkit::onSelectionChanged_BuildingTypeUri(const CEGUI::EventArgs& evt)
{
	size_t itemCount=mBuildingList->getItemCount();
	for(size_t i=0; i!=itemCount; ++i)
	{
		CEGUI::ListboxItem* item=mBuildingList->getListboxItemFromIndex(i);
		if(item->isSelected())
		{
			StaticAgentManager::getSingletonPtr()->setSelectedStaticAgentModel(item->getText().c_str());
			break;
		}
	}

	return true;
}
