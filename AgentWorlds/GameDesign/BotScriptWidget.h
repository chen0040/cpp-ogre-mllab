#ifndef _H_ML_LAB_BOT_SCRIPT_WIDGET_H
#define _H_ML_LAB_BOT_SCRIPT_WIDGET_H

#include "../../Widgets/CIWidget.h"
#include <boost/bind.hpp>
#include <boost/signal.hpp>
#include "../../Widgets/CITextFieldWidget.h"
#include "../../Widgets/ConfirmDlg.h"
#include "AddBotScriptDlg.h"

class BotScriptWidget : public CIWidget
{
public:
	BotScriptWidget(const std::string& rootId, CEGUI::Window* parentWindow=NULL);
	virtual ~BotScriptWidget();

public:
	virtual void create();
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

public:
	void show();
	void hide() { this->hideWindow(); }

public:
	virtual void showWindow();
	virtual void hideWindow();

public:
	std::string getScriptId() const;
	std::string getTag() const;
	bool hasScripts() const { return mScriptListing->getItemCount() > 0; }
	void refreshScripts();

protected:
	bool onSelectionChanged_ScriptListing(const CEGUI::EventArgs& evt);

protected:
	CEGUI::Listbox* mScriptListing;
	CITextFieldWidget* mTagField;

protected:
	CEGUI::PushButton* mBtnDeleteBotScript;
	CEGUI::PushButton* mBtnAddBotScript;
	CEGUI::PushButton* mBtnAboutBotScript;
	CEGUI::PushButton* mBtnRefreshBotScripts;
	CEGUI::PushButton* mBtnExportBotScript;

protected:
	CEGUI::Event::Connection mEventDeleteBotScript;
	CEGUI::Event::Connection mEventAddBotScript;
	CEGUI::Event::Connection mEventAboutBotScript;
	CEGUI::Event::Connection mEventRefreshBotScripts;
	CEGUI::Event::Connection mEventExportBotScript;
	CEGUI::Event::Connection mEventListSelectionChanged;
#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
	CEGUI::Event::Connection mEventFileDialog;
#endif

protected:
	ConfirmDlg* mDeleteBotScriptConfirmDlg;
	AddBotScriptDlg* mAddBotScriptDlg;

protected:
	bool onClicked_DeleteBotScript(const CEGUI::EventArgs& evt);
	bool onClicked_AddBotScript(const CEGUI::EventArgs& evt);
	bool onClicked_AboutBotScript(const CEGUI::EventArgs& evt);
	bool onClicked_RefreshBotScripts(const CEGUI::EventArgs& evt);
	bool onClicked_ExportBotScript(const CEGUI::EventArgs& evt);
#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
	bool handleFileDialogOutput(const CEGUI::EventArgs& evt);
#endif

protected:
	boost::signals::connection mEventDeleteBotScriptConfirmed;
	boost::signals::connection mEventAddBotScriptConfirmed;

protected:
	void onClicked_DeleteBotScriptConfirmed();
	void onClicked_AddBotScriptConfirmed();

protected:
	boost::signal<void ()> mSigScriptDeleted;
	boost::signal<void ()> mSigScriptsRefreshed;

public:
	boost::signals::connection subscribeEvent_onScriptDeleted(boost::signal<void ()>::slot_function_type subscriber);
	boost::signals::connection subscribeEvent_onScriptsRefreshed(boost::signal<void ()>::slot_function_type subscriber);
};
#endif