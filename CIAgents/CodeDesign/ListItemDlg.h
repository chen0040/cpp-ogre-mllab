#ifndef _H_ML_LAB_ITEM_DLG_H
#define _H_ML_LAB_ITEM_DLG_H

#include <CEGUI/CEGUI.h>
#include "../../Widgets/CIWidget.h"
#include "../../CIType/CIConfigNodeList.h"
#include "../../CIType/CIConfigNode.h"

class CITextFieldWidget;
class CIConfigNodeListWidget;

class ListItemDlg : public CIWidget
{
public:
	ListItemDlg(const std::string& rootId, CIConfigNodeList* ldata, CEGUI::Listbox* lview, CIWidget* parentWidget, CEGUI::Window* parentWindow=NULL);
	virtual ~ListItemDlg();

protected:
	virtual void create();
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

protected:
	CEGUI::PushButton* mBtnOK;
	CEGUI::PushButton* mBtnCancel;
	CEGUI::ScrollablePane* mScrollablePane;

public:
	virtual void showModal()=0;
	void setListView(CEGUI::Listbox* lview);
	void setListData(CIConfigNodeList* ldata);

protected:
	virtual bool onClicked_OK(const CEGUI::EventArgs& evt);
	virtual bool onClicked_Cancel(const CEGUI::EventArgs& evt);

public:
	CEGUI::Event::Connection mEventOK;
	CEGUI::Event::Connection mEventCancel;
	CEGUI::Event::Connection mEventDlgClosed;

protected:
	std::vector<std::string> mTextFieldWidgetNames;
	std::vector<std::string> mListWidgetNames;
	std::map<std::string, CITextFieldWidget*> mTextFieldWidgets;
	std::map<std::string, CIConfigNodeListWidget*> mListWidgets;

	CEGUI::Listbox* mListView;
	CIConfigNodeList* mListData;
};
#endif