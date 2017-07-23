#include "CodeGenDlg.h"
#include "../../Widgets/GUIManager.h"
#include "../../OSEnvironment/OSEnvironment.h"
#include "../../CIAgents/CIAgent.h"
#include "../../CIType/CIManager.h"
#include "../../Widgets/MsgBox.h"
#include "../../Widgets/CITextFieldWidget.h"
#include "../../Widgets/CIComboWidget.h"
#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
#include "../../Widgets/FileDIalog/CEGUICommonFileDialog.h"
#endif

CodeGenDlg::CodeGenDlg(const std::string& rootId, CEGUI::Window* parentWindow)
: CIWidget(NULL, parentWindow)
{
	initializeComponents(rootId);
	mRootWindow->hide();
}

void CodeGenDlg::subscribeEvents()
{
	mEventCancel=mRootWindow->subscribeEvent(CEGUI::FrameWindow::EventCloseClicked, CEGUI::Event::Subscriber(&CodeGenDlg::onCancel, this));
	mEventBrowse=mBtnBrowse->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&CodeGenDlg::onBrowseDir, this));
	mEventGenerate=mBtnGenerate->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&CodeGenDlg::onGenerate, this));
}

void CodeGenDlg::unsubscribeEvents()
{
	mEventCancel->disconnect();
	mEventBrowse->disconnect();
	mEventGenerate->disconnect();
}

CodeGenDlg::~CodeGenDlg()
{
	if(mCodeDir != NULL)
	{
		delete mCodeDir;
		mCodeDir=NULL;
	}

	if(mCodeLang != NULL)
	{
		delete mCodeLang;
		mCodeLang=NULL;
	}

	if(mCodeName != NULL)
	{
		delete mCodeName;
		mCodeName=NULL;
	}

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow->removeChildWindow(mBtnBrowse);
	mRootWindow->removeChildWindow(mBtnGenerate);
	mParentWindow->removeChildWindow(mRootWindow);

	wm->destroyWindow(mBtnBrowse);
	wm->destroyWindow(mBtnGenerate);
	wm->destroyWindow(mRootWindow);
}

void CodeGenDlg::create()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow=static_cast<CEGUI::FrameWindow*>(wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId()));
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.5f), cegui_reldim(0.3f)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0.25f), cegui_reldim(0.4f)));
	mRootWindow->setText((CEGUI::utf8*)"Code Generation");
	mRootWindow->setAlpha(0.7f);
	CEGUI::System::getSingletonPtr()->getGUISheet()->addChildWindow(mRootWindow);

	const float height=0.15f;
	const float column1Width=0.7f;
	const float column2Width=0.2f;
	const float Vgap=0.05f;
	const float Tgap=0.3f;
	const float Lgap=0.05f;
	const float Hgap=0.01f;

	mCodeDir=new CITextFieldWidget(getUIId("Dir"), this, mRootWindow, column1Width, height, 0.25f); 
	mCodeName=new CITextFieldWidget(getUIId("CodeName"), this, mRootWindow, column1Width, height, 0.25f); 
	mCodeLang=new CIComboWidget(getUIId("Lang"), this, mRootWindow, column1Width, height, 0.25f); 
	mCodeDir->setLabel("Directory: ");
	mCodeDir->setText(OSEnvironment::getFullPath("..\\scripts"));
	mCodeName->setLabel("Code: ");
	mCodeLang->setLabel("Lang: ");

	mCodeDir->setPosition(Lgap, Tgap);
	mCodeName->setPosition(Lgap, Tgap+Vgap+height);
	mCodeLang->setPosition(Lgap, Tgap+(Vgap+height)*2);

	CEGUI::Combobox* cb=mCodeLang->getCombobox();
	const std::vector<std::string>& langs=CIManager::getSingletonPtr()->getLangs();
	size_t langCount=langs.size();
	for(size_t i=0; i != langCount; ++i)
	{
		CEGUI::ListboxTextItem* item=new CEGUI::ListboxTextItem(langs[i], static_cast<CEGUI::uint>(i));
		cb->addItem(item);
	} 
	if(!langs.empty())
	{
		cb->setText(langs[0]);
	}

	mBtnBrowse=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnBrowse")));
	mBtnBrowse->setSize(CEGUI::UVector2(cegui_reldim(column2Width), cegui_reldim(height)));
	mBtnBrowse->setPosition(CEGUI::UVector2(cegui_reldim(column1Width+Lgap+Hgap), cegui_reldim(Tgap)));
	mBtnBrowse->setText((CEGUI::utf8*)"Browse");
	mRootWindow->addChildWindow(mBtnBrowse);

	mBtnGenerate=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnGenerate")));
	mBtnGenerate->setSize(CEGUI::UVector2(cegui_reldim(column2Width), cegui_reldim(height)));
	mBtnGenerate->setPosition(CEGUI::UVector2(cegui_reldim(column1Width+Lgap+Hgap), cegui_reldim(Tgap+Vgap+height)));
	mBtnGenerate->setText((CEGUI::utf8*)"Generate");
	mRootWindow->addChildWindow(mBtnGenerate);

	mParentWindow->addChildWindow(mRootWindow);
}

bool CodeGenDlg::onCancel(const CEGUI::EventArgs& evt)
{
	clearAgents();
	hideWindow();

	return true;
}

void CodeGenDlg::showWindow()
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
		mEventFileDialog=CEGUI::CommonFileDialog::getSingleton().getWindow()->subscribeEvent (CEGUI::FrameWindow::EventHidden, CEGUI::Event::Subscriber(&CodeGenDlg::handleFileDialogOutput, this));
	}
#endif
	mCodeName->setText(OSEnvironment::getFileNameUsingCurrentTime());
	CIWidget::showWindow();
}

#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
bool CodeGenDlg::handleFileDialogOutput(const CEGUI::EventArgs& evt)
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
			mCodeDir->setText( result.getAbsolutePath().c_str());
			//Returned with ACTION_OK;
			break;

		case CEGUI::ACTION_CANCEL:
			//Returned with ACTION_CANCEL;
			break;

		case CEGUI::ACTION_WINDOW_CLOSED:
			//Returned with ACTION_WINDOW_CLOSED;
			break;
	}

	return true;
}
#endif
	
void CodeGenDlg::hideWindow()
{
#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
	if(mEventFileDialog.isValid())
	{
		mEventFileDialog->disconnect();
	}
#endif
	CIWidget::hideWindow();
}

bool CodeGenDlg::onBrowseDir(const CEGUI::EventArgs& evt)
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
	mCodeDir->setText(OSEnvironment::getWinFolderSelector());
#endif

	return true;
}

bool CodeGenDlg::onGenerate(const CEGUI::EventArgs& evt)
{
	std::string destinationFolderPath=mCodeDir->getText().c_str();
	
	if(OSEnvironment::exists(destinationFolderPath))
	{
		const std::string& lang=mCodeLang->getText();
		std::set<CIAgent*>::iterator aiter=mCurrentCIAgents.begin();
		std::set<CIAgent*>::iterator aiter_end=mCurrentCIAgents.end();
		for(; aiter != aiter_end; ++aiter)
		{
			(*aiter)->generateCode(destinationFolderPath, lang, mCodeName->getText().c_str());
		}
	}
	else
	{
		GUIManager::getSingletonPtr()->showMsgBox("Invalid Path", "The destination folder path is invalid");
	}
	
	return true;
}

