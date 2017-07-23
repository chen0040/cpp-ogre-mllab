#ifndef _H_ML_LAB_ADD_BOT_SCRIPT_DLG_H
#define _H_ML_LAB_ADD_BOT_SCRIPT_DLG_H

#include <CEGUI/CEGUI.h>
#include "../../Widgets/CIWidget.h"
#include <boost/bind.hpp>
#include <boost/signal.hpp>

class CIAgent;
class CITextFieldWidget;

class AddBotScriptDlg : public CIWidget
{
public:
	AddBotScriptDlg(const std::string& rootId, CEGUI::Window* parentWindow=NULL);
	virtual ~AddBotScriptDlg();
	
protected:
	virtual void create();
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

protected:
	bool onCancel(const CEGUI::EventArgs& evt);
	bool onBrowseDir(const CEGUI::EventArgs& evt);
	bool onAddBot(const CEGUI::EventArgs& evt);
#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
	bool handleFileDialogOutput(const CEGUI::EventArgs& evt);
#endif

public:
	boost::signals::connection subscribeEvent_onScriptAdded(boost::signal<void ()>::slot_function_type subscriber);

protected:
	CITextFieldWidget* mCodeDir;
	CITextFieldWidget* mBotScriptId;
	CEGUI::PushButton* mBtnBrowse;
	CEGUI::PushButton* mBtnAddBot;
	
protected:
	CEGUI::Event::Connection mEventBrowse;
	CEGUI::Event::Connection mEventAddBot;
	CEGUI::Event::Connection mEventCancel;
#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
	CEGUI::Event::Connection mEventFileDialog;
#endif

public:
	virtual void showWindow();
	virtual void hideWindow();

protected:
	boost::signal<void ()> mSigScriptAdded;
};

#endif