#include "ListItemModifyDlg.h"
#include "../../Widgets/CITextFieldWidget.h"
#include "CIConfigNodeListWidget.h"

ListItemModifyDlg::ListItemModifyDlg(const std::string& rootId, CIConfigNodeList* ldata, CEGUI::Listbox* lview, CIWidget* parentWidget, CEGUI::Window* parentWindow)
: ListItemDlg(rootId, ldata, lview, parentWidget, parentWindow)
{
	
}

ListItemModifyDlg::~ListItemModifyDlg()
{

}

void ListItemModifyDlg::showModal()
{
	mRootWindow->setText((CEGUI::utf8*)"Modify Existing Item");
	
	CIConfigNode* item=static_cast<CIConfigNode*>(mListView->getFirstSelectedItem()->getUserData());
	size_t count=item->getLeafNodeCount();
	for(size_t j=0; j != count; ++j)
	{
		const CIConfigLeafNode* param=item->getConstLeafNode(j);
		mTextFieldWidgets[param->getName()]->getMutableLeafNode()->setValue(param->getValue());
		mTextFieldWidgets[param->getName()]->doLoad();
	}

	ListItemDlg::showModal();
}

bool ListItemModifyDlg::onClicked_OK(const CEGUI::EventArgs &evt)
{
	CIConfigNode* item=static_cast<CIConfigNode*>(mListView->getFirstSelectedItem()->getUserData());
	size_t count=item->getLeafNodeCount();
	for(size_t j=0; j != count; ++j)
	{
		CIConfigLeafNode* param=item->getMutableLeafNode(j);
		mTextFieldWidgets[param->getName()]->doSave();
		param->setValue(mTextFieldWidgets[param->getName()]->getConstLeafNode()->getValue());
	}
	
	return ListItemDlg::onClicked_OK(evt);
}