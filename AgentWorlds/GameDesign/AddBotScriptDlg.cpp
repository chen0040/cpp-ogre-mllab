#include "AddBotScriptDlg.h"
#include "../../Widgets/GUIManager.h"
#include "../../OSEnvironment/OSEnvironment.h"
#include "../../CIAgents/CIAgent.h"
#include "../../CIType/CIManager.h"
#include "../../Widgets/MsgBox.h"
#include "../../Widgets/CITextFieldWidget.h"
#include "../../Widgets/CIComboWidget.h"
#include "../../ScriptEngine/ScriptManager.h"
#include "../../tinyxml/tinyxml.h"
#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
#include "../../Widgets/FileDIalog/CEGUICommonFileDialog.h"
#endif

AddBotScriptDlg::AddBotScriptDlg(const std::string& rootId, CEGUI::Window* parentWindow)
: CIWidget(NULL, parentWindow)
{
	initializeComponents(rootId);
	mRootWindow->hide();
}

void AddBotScriptDlg::subscribeEvents()
{
	mEventCancel=mRootWindow->subscribeEvent(CEGUI::FrameWindow::EventCloseClicked, CEGUI::Event::Subscriber(&AddBotScriptDlg::onCancel, this));
	mEventBrowse=mBtnBrowse->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&AddBotScriptDlg::onBrowseDir, this));
	mEventAddBot=mBtnAddBot->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&AddBotScriptDlg::onAddBot, this));
}

#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
bool AddBotScriptDlg::handleFileDialogOutput(const CEGUI::EventArgs& evt)
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
			break;

		case CEGUI::ACTION_CANCEL:
			break;

		case CEGUI::ACTION_WINDOW_CLOSED:
			break;
	}

	return true;
}
#endif

void AddBotScriptDlg::unsubscribeEvents()
{
	mEventCancel->disconnect();
	mEventBrowse->disconnect();
	mEventAddBot->disconnect();
}

AddBotScriptDlg::~AddBotScriptDlg()
{
	if(mCodeDir != NULL)
	{
		delete mCodeDir;
		mCodeDir=NULL;
	}

	if(mBotScriptId != NULL)
	{
		delete mBotScriptId;
		mBotScriptId=NULL;
	}

	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow->removeChildWindow(mBtnBrowse);
	mRootWindow->removeChildWindow(mBtnAddBot);
	mParentWindow->removeChildWindow(mRootWindow);

	wm->destroyWindow(mBtnBrowse);
	wm->destroyWindow(mBtnAddBot);
	wm->destroyWindow(mRootWindow);
}

boost::signals::connection AddBotScriptDlg::subscribeEvent_onScriptAdded(boost::signal<void ()>::slot_function_type subscriber)
{
	return mSigScriptAdded.connect(subscriber);
}

void AddBotScriptDlg::create()
{
	CEGUI::WindowManager* wm=CEGUI::WindowManager::getSingletonPtr();

	mRootWindow=static_cast<CEGUI::FrameWindow*>(wm->createWindow(CIWidget::getGUIType("FrameWindow"), getRootId()));
	mRootWindow->setSize(CEGUI::UVector2(cegui_reldim(0.5f), cegui_reldim(0.2f)));
	mRootWindow->setPosition(CEGUI::UVector2(cegui_reldim(0.25f), cegui_reldim(0.4f)));
	mRootWindow->setText((CEGUI::utf8*)"Code Generation");
	mRootWindow->setAlpha(0.7f);
	CEGUI::System::getSingletonPtr()->getGUISheet()->addChildWindow(mRootWindow);

	const float height=0.2f;
	const float column1Width=0.7f;
	const float column2Width=0.2f;
	const float Vgap=0.05f;
	const float Tgap=0.3f;
	const float Lgap=0.05f;
	const float Hgap=0.01f;

	mCodeDir=new CITextFieldWidget(getUIId("Dir"), this, mRootWindow, column1Width, height, 0.25f); 
	mBotScriptId=new CITextFieldWidget(getUIId("Lang"), this, mRootWindow, column1Width, height, 0.25f); 
	mCodeDir->setLabel("Directory: ");
	mBotScriptId->setLabel("Script Id: ");

	mCodeDir->setPosition(Lgap, Tgap);
	mBotScriptId->setPosition(Lgap, Tgap+Vgap+height);

	mBtnBrowse=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnBrowse")));
	mBtnBrowse->setSize(CEGUI::UVector2(cegui_reldim(column2Width), cegui_reldim(height)));
	mBtnBrowse->setPosition(CEGUI::UVector2(cegui_reldim(column1Width+Lgap+Hgap), cegui_reldim(Tgap)));
	mBtnBrowse->setText((CEGUI::utf8*)"Browse");
	mRootWindow->addChildWindow(mBtnBrowse);

	mBtnAddBot=static_cast<CEGUI::PushButton*>(wm->createWindow(CIWidget::getGUIType("Button"), getUIId("btnAddBot")));
	mBtnAddBot->setSize(CEGUI::UVector2(cegui_reldim(column2Width), cegui_reldim(height)));
	mBtnAddBot->setPosition(CEGUI::UVector2(cegui_reldim(column1Width+Lgap+Hgap), cegui_reldim(Tgap+Vgap+height)));
	mBtnAddBot->setText((CEGUI::utf8*)"AddBot");
	mRootWindow->addChildWindow(mBtnAddBot);

	mParentWindow->addChildWindow(mRootWindow);
}

bool AddBotScriptDlg::onCancel(const CEGUI::EventArgs& evt)
{
	hideWindow();

	return true;
}

bool AddBotScriptDlg::onBrowseDir(const CEGUI::EventArgs& evt)
{
#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
	/****************************************************************************************************
	Step 3a: Call the file dialog with the input data
	*****************************************************************************************************/
	CEGUI::CommonFileDialogInput input;
	input.setHandle (1);										// Set the handle to determine the originator
	input.setFilter ("XML File (*.xml)|*.xml|All files|*.*|");	// Extensions
	input.setOpenFileDialog (true);								// Load mode
	input.setDefaultExtension ("*.xml");						// Zip is the first one to display
	CEGUI::CommonFileDialog::getSingleton().openDialog(input);	// Open the common file dialog
#elif GUI_FILEDIALOG == GUI_FILEDIALOG_WIN32
	mCodeDir->setText(OSEnvironment::getWinFolderSelector());
#endif

	return true;
}

void AddBotScriptDlg::showWindow()
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
		mEventFileDialog=CEGUI::CommonFileDialog::getSingleton().getWindow()->subscribeEvent (CEGUI::FrameWindow::EventHidden, CEGUI::Event::Subscriber(&AddBotScriptDlg::handleFileDialogOutput, this));
	}
#elif GUI_FILEDIALOG == GUI_FILEDIALOG_WIN32

#endif

	CIWidget::showWindow();
}

void AddBotScriptDlg::hideWindow()
{
#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
	if(mEventFileDialog.isValid())
	{
		mEventFileDialog->disconnect();
	}
#endif
	CIWidget::hideWindow();
}

bool AddBotScriptDlg::onAddBot(const CEGUI::EventArgs& evt)
{
	std::string sourceFolderPath=mCodeDir->getText().c_str();
	
	if(!OSEnvironment::exists(sourceFolderPath))
	{
		GUIManager::getSingletonPtr()->showMsgBox("Invalid Path", "The source folder path is invalid");
		return true;
	}

	const std::string& scriptId=mBotScriptId->getText();
	if(scriptId.compare("")==0)
	{
		GUIManager::getSingletonPtr()->showMsgBox("Invalid Script Id", "The Script Id is empty");
		return true;
	}

	Scriptlet* script=ScriptManager::getSingletonPtr()->getScriptlet(scriptId);

	if(script != NULL)
	{
		GUIManager::getSingletonPtr()->showMsgBox("Invalid Script Id", "The Script Id already exists!");
		return true;
	}

	std::string destinationFolderPath=OSEnvironment::getFullPath(OSEnvironment::append("..\\scripts\\", scriptId));


	std::string botScriptFilePath=OSEnvironment::append(sourceFolderPath, "\\bot.lua");
	if(!OSEnvironment::exists(botScriptFilePath))
	{
		GUIManager::getSingletonPtr()->showMsgBox("Missing bot script file", "The bot.lua is missing!");
		return true;
	}
	
	std::string aboutFilePath=OSEnvironment::append(sourceFolderPath, "\\About.txt");
	if(!OSEnvironment::exists(aboutFilePath))
	{
		GUIManager::getSingletonPtr()->showMsgBox("Missing About file", "The About.txt is missing!");
		return true;
	}

	OSEnvironment::copyFolder(sourceFolderPath, destinationFolderPath);

	ScriptManager::getSingletonPtr()->addScriptlet(scriptId);

	hideWindow();

	mSigScriptAdded();
	
	return true;
}

