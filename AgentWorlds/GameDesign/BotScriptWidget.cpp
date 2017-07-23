#include "BotScriptWidget.h"
#include "../../OSEnvironment/OSEnvironment.h"
#include "../../ScriptEngine/ScriptManager.h"
#include "../../Widgets/GUIManager.h"
#include "../../tinyxml/tinyxml.h"
#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
#include "../../Widgets/FileDIalog/CEGUICommonFileDialog.h"
#endif

BotScriptWidget::BotScriptWidget(const std::string& rootId, CEGUI::Window* parentWindow)
: CIWidget(NULL, parentWindow)
, mTagField(NULL)
{
	this->initializeComponents(rootId);
}

BotScriptWidget::~BotScriptWidget()
{
	if(mTagField != NULL)
	{
		delete mTagField;
		mTagField=NULL;
	}

	if(mDeleteBotScriptConfirmDlg != NULL)
	{
		delete mDeleteBotScriptConfirmDlg;
		mDeleteBotScriptConfirmDlg=NULL;
	}

	if(mAddBotScriptDlg != NULL)
	{
		delete mAddBotScriptDlg;
		mAddBotScriptDlg=NULL;
	}

	mRootWindow->removeChildWindow(mScriptListing);

	mRootWindow->removeChildWindow(mBtnDeleteBotScript);
	mRootWindow->removeChildWindow(mBtnAddBotScript);
	mRootWindow->removeChildWindow(mBtnExportBotScript);
	mRootWindow->removeChildWindow(mBtnAboutBotScript);
	mRootWindow->removeChildWindow(mBtnRefreshBotScripts);

	mParentWindow->removeChildWindow(mRootWindow);

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();
	wm->destroyWindow(mBtnDeleteBotScript);
	wm->destroyWindow(mBtnAddBotScript);
	wm->destroyWindow(mBtnAboutBotScript);
	wm->destroyWindow(mBtnExportBotScript);
	wm->destroyWindow(mBtnRefreshBotScripts);
	wm->destroyWindow(mScriptListing);
}

void BotScriptWidget::create()
{
	mDeleteBotScriptConfirmDlg=new ConfirmDlg(getUIId("DeleteBotScriptConfirmDlg"));
	mAddBotScriptDlg=new AddBotScriptDlg(getUIId("AddBotScriptDlg"));

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	CEGUI::FrameWindow* frame=static_cast<CEGUI::FrameWindow*>(wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId()));
	mRootWindow=frame;
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.4f), cegui_reldim(0.45f)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0.0f), cegui_reldim(0.05f)));
	mRootWindow->setAlpha(0.6f);
	frame->setCloseButtonEnabled(false);
	mRootWindow->setText((CEGUI::utf8*)"Bots Loaded");

	const Real vgap=0.01f;
	const Real top=0.1f;
	const Real left=0.05f;
	Real y=top;
	Real x=left;
	const Real listHeight=0.6f;
	const Real listWidth=0.9f;
	mScriptListing=static_cast<CEGUI::Listbox*>(wm->createWindow(CIWidget::getGUIType("Listbox"), getUIId("ScriptListing")));
	mScriptListing->setSize(CEGUI::UVector2(cegui_reldim(listWidth), cegui_reldim(listHeight)));
	mScriptListing->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mRootWindow->addChildWindow(mScriptListing);

	ScriptManager* sm=ScriptManager::getSingletonPtr();
	const std::vector<std::string>& scriptListings=sm->getScriptListings();
	size_t scriptListingCount=scriptListings.size();
	for(size_t k=0; k != scriptListingCount; k++)
	{
		CEGUI::ListboxTextItem* item=new CEGUI::ListboxTextItem(sm->getNickname(scriptListings[k]), static_cast<CEGUI::uint>(k));
		item->setTooltipText(scriptListings[k]);
		item->setSelectionBrushImage((CEGUI::utf8*)GUIManager::getSingletonPtr()->getGUITheme().c_str(), (CEGUI::utf8*)"MultiListSelectionBrush");

		if(k==0)
		{
			item->setSelected(true);
		}
		mScriptListing->addItem(item);
	}

	const Real btnWidth=0.3f;
	const Real btnHeight=0.08f;
	const Real hgap=0.01f;
	x=left;
	y+=(listHeight+hgap);
	mBtnExportBotScript=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnExportBotScripts")));
	mBtnExportBotScript->setSize(CEGUI::UVector2(cegui_reldim(btnWidth), cegui_reldim(btnHeight)));
	mBtnExportBotScript->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnExportBotScript->setText((CEGUI::utf8*)"Export Script");
	mRootWindow->addChildWindow(mBtnExportBotScript);

	x+=(btnWidth+hgap);
	mBtnDeleteBotScript=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnDeleteBotScript")));
	mBtnDeleteBotScript->setSize(CEGUI::UVector2(cegui_reldim(btnWidth), cegui_reldim(btnHeight)));
	mBtnDeleteBotScript->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnDeleteBotScript->setText((CEGUI::utf8*)"Remove Script");
	mRootWindow->addChildWindow(mBtnDeleteBotScript);

	x+=(btnWidth+hgap);
	mBtnAboutBotScript=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnAboutBotScript")));
	mBtnAboutBotScript->setSize(CEGUI::UVector2(cegui_reldim(btnWidth), cegui_reldim(btnHeight)));
	mBtnAboutBotScript->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnAboutBotScript->setText((CEGUI::utf8*)"About Script");
	mRootWindow->addChildWindow(mBtnAboutBotScript);

	y+=(btnHeight+vgap);
	x=left;
	mTagField=new CITextFieldWidget(getUIId("TagField"), this, mRootWindow, 0.9f, btnHeight, 0.2f);
	mTagField->setLabel("Tag: ");
	mTagField->setPosition(x,  y);

	y+=vgap+btnHeight;
	mBtnAddBotScript=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnAddBotScript")));
	mBtnAddBotScript->setSize(CEGUI::UVector2(cegui_reldim(0.45f), cegui_reldim(btnHeight)));
	mBtnAddBotScript->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnAddBotScript->setText((CEGUI::utf8*)"Import Script");
	mRootWindow->addChildWindow(mBtnAddBotScript);

	x+=(0.45f+hgap);
	mBtnRefreshBotScripts=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnRefreshBotScripts")));
	mBtnRefreshBotScripts->setSize(CEGUI::UVector2(cegui_reldim(0.45f), cegui_reldim(btnHeight)));
	mBtnRefreshBotScripts->setPosition(CEGUI::UVector2(cegui_reldim(x), cegui_reldim(y)));
	mBtnRefreshBotScripts->setText((CEGUI::utf8*)"Refresh Scripts");
	mRootWindow->addChildWindow(mBtnRefreshBotScripts);

	mParentWindow->addChildWindow(mRootWindow);
}
	
void BotScriptWidget::subscribeEvents()
{
	mEventListSelectionChanged=mScriptListing->subscribeEvent(CEGUI::Listbox::EventSelectionChanged, CEGUI::Event::Subscriber(&BotScriptWidget::onSelectionChanged_ScriptListing, this));

	mEventAddBotScript=mBtnAddBotScript->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&BotScriptWidget::onClicked_AddBotScript, this));
	mEventDeleteBotScript=mBtnDeleteBotScript->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&BotScriptWidget::onClicked_DeleteBotScript, this));
	mEventAboutBotScript=mBtnAboutBotScript->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&BotScriptWidget::onClicked_AboutBotScript, this));
	mEventExportBotScript=mBtnExportBotScript->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&BotScriptWidget::onClicked_ExportBotScript, this));
	mEventRefreshBotScripts=mBtnRefreshBotScripts->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&BotScriptWidget::onClicked_RefreshBotScripts, this));

	mEventDeleteBotScriptConfirmed=mDeleteBotScriptConfirmDlg->subscribeEvent_onConfirm(boost::bind(&BotScriptWidget::onClicked_DeleteBotScriptConfirmed, this));
	mEventAddBotScriptConfirmed=mAddBotScriptDlg->subscribeEvent_onScriptAdded(boost::bind(&BotScriptWidget::onClicked_AddBotScriptConfirmed, this));
}

void BotScriptWidget::onClicked_AddBotScriptConfirmed()
{
	refreshScripts();
}

void BotScriptWidget::onClicked_DeleteBotScriptConfirmed()
{
	ScriptManager::getSingletonPtr()->removeScript(getScriptId());
	refreshScripts();
	mSigScriptDeleted();
}
	
void BotScriptWidget::unsubscribeEvents()
{
	mEventListSelectionChanged->disconnect();

	mEventAddBotScript->disconnect();
	mEventDeleteBotScript->disconnect();
	mEventAboutBotScript->disconnect();
	mEventExportBotScript->disconnect();
	mEventRefreshBotScripts->disconnect();

	mEventDeleteBotScriptConfirmed.disconnect();
	mEventAddBotScriptConfirmed.disconnect();
}

void BotScriptWidget::showWindow()
{
#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
	/****************************************************************************************************
	Step 2: Register the function that must be called in case the common file dialog has been closed by:
	        - the Ok button
			- the Cancel button
			- the Window close button ('X')
			Use the FrameWindow::EventHidden event
	*****************************************************************************************************/
	if(!mEventFileDialog.isValid())
	{
		mEventFileDialog=CEGUI::CommonFileDialog::getSingleton().getWindow()->subscribeEvent (CEGUI::FrameWindow::EventHidden, CEGUI::Event::Subscriber(&BotScriptWidget::handleFileDialogOutput, this));
	}
#endif
	ScriptManager::getSingletonPtr()->refreshScripts();
	refreshScripts();
	
	mSigScriptsRefreshed();

	CIWidget::showWindow();
}

#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
bool BotScriptWidget::handleFileDialogOutput(const CEGUI::EventArgs& evt)
{
	/****************************************************************************************************
	Step 4: Handle the returned output
	*****************************************************************************************************/
	CEGUI::CommonFileDialogOutput result = CEGUI::CommonFileDialog::getSingleton().getResult();

	//_mlstListbox->addItem(new CEGUI::ListboxTextItem ((CEGUI::utf8*)"Drive: " + result.getDrive()));
	//_mlstListbox->addItem(new CEGUI::ListboxTextItem ((CEGUI::utf8*)"Full qualified name: " + result.getFullQualifiedFileName()));
	//_mlstListbox->addItem(new CEGUI::ListboxTextItem ((CEGUI::utf8*)"Absolute path: " + result.getAbsolutePath()));
	//_mlstListbox->addItem(new CEGUI::ListboxTextItem ((CEGUI::utf8*)"Relative path: " + result.getRelativePath()));
	//_mlstListbox->addItem(new CEGUI::ListboxTextItem ((CEGUI::utf8*)"Filename: " + result.getFileName()));

	switch (result.getAction())
	{
		case CEGUI::ACTION_OK:
			/*std::string winFolder=OSEnvironment::getWinFolderSelector();

			if(winFolder.compare("")==0)
			{
				return true;
			}*/

			OSEnvironment::copyFolder(OSEnvironment::getFullPath(OSEnvironment::append("..\\scripts\\", getScriptId())), result.getAbsolutePath().c_str());
			
			break;

		case CEGUI::ACTION_CANCEL:
			break;

		case CEGUI::ACTION_WINDOW_CLOSED:
			break;
	}

	return true;
}
#endif

void BotScriptWidget::hideWindow()
{
#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
	if(mEventFileDialog.isValid())
	{
		mEventFileDialog->disconnect();
	}
#endif
	CIWidget::hideWindow();
}

void BotScriptWidget::show()
{ 
	refreshScripts();
	this->showWindow(); 
}

void BotScriptWidget::refreshScripts()
{
	mScriptListing->resetList();
	ScriptManager* sm=ScriptManager::getSingletonPtr();
	const std::vector<std::string>& scriptListings=sm->getScriptListings();
	size_t scriptListingCount=scriptListings.size();
	for(size_t k=0; k != scriptListingCount; k++)
	{
		CEGUI::ListboxTextItem* item=new CEGUI::ListboxTextItem(sm->getNickname(scriptListings[k]), static_cast<CEGUI::uint>(k));
		item->setTooltipText(scriptListings[k]);
		item->setSelectionBrushImage((CEGUI::utf8*)GUIManager::getSingletonPtr()->getGUITheme().c_str(), (CEGUI::utf8*)"MultiListSelectionBrush");

		if(k==0)
		{
			item->setSelected(true);
		}
		mScriptListing->addItem(item);
	}
}

std::string BotScriptWidget::getTag() const
{
	return mTagField->getText();
}

std::string BotScriptWidget::getScriptId() const
{
	return mScriptListing->getFirstSelectedItem()->getTooltipText().c_str();
}

bool BotScriptWidget::onSelectionChanged_ScriptListing(const CEGUI::EventArgs& evt)
{
	if(mScriptListing->getSelectedCount() == 0 && mScriptListing->getItemCount() > 0)
	{
		mScriptListing->getListboxItemFromIndex(0)->setSelected(true);
	}
	return true;
}

bool BotScriptWidget::onClicked_DeleteBotScript(const CEGUI::EventArgs& evt)
{
	mDeleteBotScriptConfirmDlg->showModal("Irreversible Deletion", "Delete action is not reversible (code will be transferred to recycled_scripts folder). Are you sure you want to continue?");
	return true;
}

bool BotScriptWidget::onClicked_AddBotScript(const CEGUI::EventArgs& evt)
{
	mAddBotScriptDlg->showWindow();
	return true;
}

bool BotScriptWidget::onClicked_AboutBotScript(const CEGUI::EventArgs& evt)
{
	std::string scriptId=getScriptId();
	Scriptlet* script=ScriptManager::getSingletonPtr()->getScriptlet(scriptId);

	std::ostringstream oss;
	oss << "About " << scriptId;
	GUIManager::getSingletonPtr()->showMsgBox(oss.str(), script->toString());

	return true;
}

bool BotScriptWidget::onClicked_RefreshBotScripts(const CEGUI::EventArgs& evt)
{
	ScriptManager::getSingletonPtr()->refreshScripts();
	refreshScripts();
	
	mSigScriptsRefreshed();

	return true;
}

bool BotScriptWidget::onClicked_ExportBotScript(const CEGUI::EventArgs& evt)
{
#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
	/****************************************************************************************************
	Step 3b: Call the file dialog with the input data
	*****************************************************************************************************/
	CEGUI::CommonFileDialogInput input;
	input.setHandle (2);										// Set the handle to determine the originator
	input.setFilter ("XML File (*.xml)|*.xml|Lua File (*.lua)|*.lua|Text File (*.txt)|*.txt|");
	input.setOpenFileDialog (false);							// Save mode
	input.setDefaultExtension ("*.xml");						// .png is the preferred extension
	input.setFileName ("config.xml");								// Set default filename
	CEGUI::CommonFileDialog::getSingleton().openDialog(input);	// Open the common file dialog
#elif GUI_FILEDIALOG == GUI_FILEDIALOG_WIN32
	OSEnvironment::copyFolder(OSEnvironment::getFullPath(OSEnvironment::append("..\\scripts\\", getScriptId())), OSEnvironment::getWinFolderSelector());
#endif

	return true;
}

boost::signals::connection BotScriptWidget::subscribeEvent_onScriptDeleted(boost::signal<void ()>::slot_function_type subscriber)
{
	return mSigScriptDeleted.connect(subscriber);
}

boost::signals::connection BotScriptWidget::subscribeEvent_onScriptsRefreshed(boost::signal<void ()>::slot_function_type subscriber)
{
	return mSigScriptsRefreshed.connect(subscriber);
}

