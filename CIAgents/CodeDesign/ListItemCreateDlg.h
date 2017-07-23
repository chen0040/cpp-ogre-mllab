#ifndef _H_ML_LAB_LIST_ITEM_CREATE_DLG_H
#define _H_ML_LAB_LIST_ITEM_CREATE_DLG_H

#include "ListItemDlg.h"

class ListItemCreateDlg : public ListItemDlg
{
public:
	ListItemCreateDlg(const std::string& rootId, CIConfigNodeList* ldata, CEGUI::Listbox* lview, CIWidget* parentWidget, CEGUI::Window* parentWindow=NULL);
	virtual ~ListItemCreateDlg();

public:
	virtual void showModal();

protected:
	virtual bool onClicked_OK(const CEGUI::EventArgs& evt);
};
#endif