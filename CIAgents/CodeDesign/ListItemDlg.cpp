#include "ListItemDlg.h"
#include "CIConfigNodeListWidget.h"
#include "../../Widgets/CITextFieldWidget.h"

ListItemDlg::ListItemDlg(const std::string& rootId, CIConfigNodeList* ldata, CEGUI::Listbox* lview, CIWidget* parentWidget, CEGUI::Window* parentWindow)
: CIWidget(parentWidget, parentWindow)
, mListView(lview)
, mListData(ldata)
{
	initializeComponents(rootId);
}

ListItemDlg::~ListItemDlg()
{
	std::map<std::string, CITextFieldWidget*>::iterator iter=mTextFieldWidgets.begin();
	std::map<std::string, CITextFieldWidget*>::iterator iter_end=mTextFieldWidgets.end();
	for(; iter != iter_end; ++iter)
	{
		delete (iter->second);
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

	mRootWindow->removeChildWindow(mScrollablePane);
	mRootWindow->removeChildWindow(mBtnOK);
	mRootWindow->removeChildWindow(mBtnCancel);
	mParentWindow->removeChildWindow(mRootWindow);

	wm->destroyWindow(mScrollablePane);
	wm->destroyWindow(mBtnOK);
	wm->destroyWindow(mBtnCancel);
	wm->destroyWindow(mRootWindow);
}

void ListItemDlg::create()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();
	mRootWindow=wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId());
	mRootWindow->setText((CEGUI::utf8*)"List Item Dialog");
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.5f), cegui_reldim(0.5f)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0.25f), cegui_reldim(0.25f)));
	mRootWindow->setAlpha(0.7f);
	mRootWindow->hide();

	mScrollablePane=static_cast<CEGUI::ScrollablePane*>(wm->createWindow(CIWidget::getGUIType("ScrollablePane"), getUIId("ScrollablePane")));
	mScrollablePane->setSize((CEGUI::UVector2(cegui_reldim(0.9f), cegui_reldim(0.75f))));
	mScrollablePane->setPosition(CEGUI::UVector2(cegui_reldim(0.05f), cegui_reldim(0.1f)));
	mRootWindow->addChildWindow(mScrollablePane);

	mBtnOK=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("OK")));
	mBtnOK->setSize(CEGUI::UVector2(cegui_reldim(0.2f), cegui_reldim(0.1f)));
	mBtnOK->setPosition(CEGUI::UVector2(cegui_reldim(0.55f), cegui_reldim(0.85f)));
	mBtnOK->setText((CEGUI::utf8*)"OK");
	mRootWindow->addChildWindow(mBtnOK);

	mBtnCancel=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("Cancel")));
	mBtnCancel->setSize(CEGUI::UVector2(cegui_reldim(0.2f), cegui_reldim(0.1f)));
	mBtnCancel->setPosition(CEGUI::UVector2(cegui_reldim(0.75f), cegui_reldim(0.85f)));
	mBtnCancel->setText((CEGUI::utf8*)"Cancel");
	mRootWindow->addChildWindow(mBtnCancel);

	mParentWindow->addChildWindow(mRootWindow);

	const CIConfigNode* nt=mListData->getNodeTemplate();
	const std::vector<std::string>& paramNames=nt->getLeafNodeNames();
	float x=0;
	float y=0;
	float height=0;
	size_t count=nt->getLeafNodeCount();
	for(size_t k=0; k != count; ++k)
	{
		const CIConfigLeafNode* param=nt->getConstLeafNode(k);
		CITextFieldWidget* widget=new CITextFieldWidget(getUIId(param->getName()), param, this, mScrollablePane);

		y+=param->getVgap();
		widget->setPosition(x, y);
		y+=(param->getHeight());

		mTextFieldWidgetNames.push_back(param->getName());
		mTextFieldWidgets[param->getName()]=widget;
	}

	count=nt->getNodeListCount();
	for(size_t j=0; j != count; ++j)
	{
		const CIConfigNodeList* const lst=nt->getConstNodeList(j);
		CIConfigNodeListWidget* widget=new CIConfigNodeListWidget(getUIId(lst->getName()), lst, this, mScrollablePane);

		y+=lst->getVgap();
		widget->setPosition(x, y);
		y+=lst->getHeight();
		
		mListWidgetNames.push_back(lst->getName());
		mListWidgets[lst->getName()]=widget;
	}
}

void ListItemDlg::subscribeEvents()
{
	mEventOK=mBtnOK->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ListItemDlg::onClicked_OK, this));
	mEventCancel=mBtnCancel->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&ListItemDlg::onClicked_Cancel, this));
	mEventDlgClosed=mRootWindow->subscribeEvent(CEGUI::FrameWindow::EventCloseClicked, CEGUI::Event::Subscriber(&ListItemDlg::onClicked_Cancel, this));
}

void ListItemDlg::unsubscribeEvents()
{
	mEventOK->disconnect();
	mEventCancel->disconnect();
	mEventDlgClosed->disconnect();
}

bool ListItemDlg::onClicked_Cancel(const CEGUI::EventArgs &evt)
{
	setModalState(false);
	hideWindow();

	return true;
}

bool ListItemDlg::onClicked_OK(const CEGUI::EventArgs &evt)
{
	setModalState(false);
	hideWindow();

	return true;
}

void ListItemDlg::showModal()
{
	setModalState(true);
	showWindow();
}

void ListItemDlg::setListView(CEGUI::Listbox* lview)
{
	mListView=lview;
}

void ListItemDlg::setListData(CIConfigNodeList* ldata)
{
	mListData=ldata;
}
