#ifndef _H_ML_LAB_CODE_GEN_DLG_H
#define _H_ML_LAB_CODE_GEN_DLG_H

#include <CEGUI/CEGUI.h>
#include "../../Widgets/CIWidget.h"

class CIAgent;
class CITextFieldWidget;
class CIComboWidget;

class CodeGenDlg : public CIWidget
{
public:
	CodeGenDlg(const std::string& rootId, CEGUI::Window* parentWindow=NULL);
	virtual ~CodeGenDlg();
	
protected:
	virtual void create();
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

protected:
	bool onCancel(const CEGUI::EventArgs& evt);
	bool onBrowseDir(const CEGUI::EventArgs& evt);
	bool onGenerate(const CEGUI::EventArgs& evt);
#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
	bool handleFileDialogOutput(const CEGUI::EventArgs& evt);
#endif

public:
	virtual void showWindow();
	virtual void hideWindow();

public:
	void clearAgents() { mCurrentCIAgents.clear(); }
	void addAgent(CIAgent* agent) { mCurrentCIAgents.insert(agent); }

protected:
	CITextFieldWidget* mCodeDir;
	CITextFieldWidget* mCodeName;
	CIComboWidget* mCodeLang;
	CEGUI::PushButton* mBtnBrowse;
	CEGUI::PushButton* mBtnGenerate;
	
protected:
	CEGUI::Event::Connection mEventBrowse;
	CEGUI::Event::Connection mEventGenerate;
	CEGUI::Event::Connection mEventCancel;
#if GUI_FILEDIALOG == GUI_FILEDIALOG_CEGUI
	CEGUI::Event::Connection mEventFileDialog;
#endif

protected:
	std::set<CIAgent*> mCurrentCIAgents;
};
#endif