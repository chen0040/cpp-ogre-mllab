#ifndef _H_ML_LAB_CI_CONFIG_NODE_LIST_WIDGET_H
#define _H_ML_LAB_CI_CONFIG_NODE_LIST_WIDGET_H

#include <CEGUI/CEGUI.h>
#include <string>
#include "../../CIType/CIConfigNodeList.h"
#include "../../Widgets/CIWidget.h"
#include "../../tinyxml/tinyxml.h"

class ListItemCreateDlg;
class ListItemModifyDlg;

class CIConfigNodeListWidget : public CIWidget
{
public:
	CIConfigNodeListWidget(const std::string& rootId, const CIConfigNodeList* const list, CIWidget* parentWidget, CEGUI::Window* parentWindow);
	virtual ~CIConfigNodeListWidget();

protected:
	virtual void create();
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

protected:
	bool onClicked_Create(const CEGUI::EventArgs& evt);
	bool onClicked_Delete(const CEGUI::EventArgs& evt);
	bool onClicked_Modify(const CEGUI::EventArgs& evt);
	bool onItemChanged_List(const CEGUI::EventArgs& evt);

protected:
	CEGUI::Listbox* mListView;
	CEGUI::PushButton* mBtnCreate;
	CEGUI::PushButton* mBtnDelete;
	CEGUI::PushButton* mBtnModify;
	CEGUI::MultiLineEditbox* mEditbox;
	CEGUI::DefaultWindow* mLabel;

public:
	virtual void doPassByTemplate(const std::string& destinationFile, const std::string& fileType) const;
	virtual void loadXml(TiXmlElement* xmlNode);
	virtual void saveXml(TiXmlElement* xmlNode);

public:
	virtual void doLoad();
	virtual void doSave();

protected:
	CEGUI::Event::Connection mEventCreate;
	CEGUI::Event::Connection mEventDelete;
	CEGUI::Event::Connection mEventModify;
	CEGUI::Event::Connection mEventSelectionChange;

protected:
	CIConfigNodeList* mListData;
	CIConfigNodeList* mTLData;
	ListItemCreateDlg* mListItemCreateDlg;
	ListItemModifyDlg* mListItemModifyDlg;
};
#endif