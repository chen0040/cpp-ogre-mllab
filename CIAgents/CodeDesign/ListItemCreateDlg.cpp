#include "ListItemCreateDlg.h"
#include "../../Widgets/MsgBox.h"
#include "../../Widgets/CITextFieldWidget.h"
#include "CIConfigNodeListWidget.h"
#include "../../Widgets/GUIManager.h"

ListItemCreateDlg::ListItemCreateDlg(const std::string& rootId, CIConfigNodeList* ldata, CEGUI::Listbox* lview, CIWidget* parentWidget, CEGUI::Window* parentWindow)
: ListItemDlg(rootId, ldata, lview, parentWidget, parentWindow)
{
	
}

ListItemCreateDlg::~ListItemCreateDlg()
{

}

void ListItemCreateDlg::showModal()
{
	mRootWindow->setText((CEGUI::utf8*)"Create New Item");
	ListItemDlg::showModal();
}

bool ListItemCreateDlg::onClicked_OK(const CEGUI::EventArgs &evt)
{
	CIConfigNode* item=mListData->createItem();
	size_t itemCount=item->getLeafNodeCount();
	for(size_t j=0; j != itemCount; ++j)
	{
		mTextFieldWidgets[mTextFieldWidgetNames[j]]->doSave();
		item->getMutableLeafNode(j)->setValue(mTextFieldWidgets[mTextFieldWidgetNames[j]]->getConstLeafNode()->getValue());
	}

	size_t item_index=mListData->addItem(item);

	CEGUI::ListboxTextItem* vitem=new CEGUI::ListboxTextItem(mListData->getItemName(item_index), static_cast<CEGUI::uint>(item_index));
	vitem->setSelectionBrushImage((CEGUI::utf8*)GUIManager::getSingletonPtr()->getGUITheme().c_str(), (CEGUI::utf8*)"MultiListSelectionBrush");
	vitem->setUserData(item);
	mListView->addItem(vitem);
	
	return ListItemDlg::onClicked_OK(evt);
}