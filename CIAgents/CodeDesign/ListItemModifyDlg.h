#ifndef _H_ML_LAB_LIST_ITEM_MODIFY_DLG_H
#define _H_ML_LAB_LIST_ITEM_MODIFY_DLG_H

#include "ListItemDlg.h"

class ListItemModifyDlg : public ListItemDlg
{
public:
	ListItemModifyDlg(const std::string& rootId, CIConfigNodeList* ldata, CEGUI::Listbox* lview, CIWidget* parentWidget, CEGUI::Window* parentWindow=NULL);
	virtual ~ListItemModifyDlg();

public:
	virtual void showModal();

protected:
	virtual bool onClicked_OK(const CEGUI::EventArgs& evt);
};
#endif