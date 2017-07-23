#ifndef _H_MLLAB_NICKNAME_DLG_H
#define _H_MLLAB_NICKNAME_DLG_H

#include "CIWidget.h"
#include "CITextFieldWidget.h"

class NicknameDlg : public CIWidget
{
public:
	NicknameDlg(const std::string& rootId, CEGUI::Window* parentWindow=NULL);
	virtual ~NicknameDlg();

public:
	void showModal();

protected:
	virtual void create();
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

protected:
	bool onCancel(const CEGUI::EventArgs& evt);

protected:
	void updateData(bool validateAndSaved=true);

private:
	CEGUI::ListboxItem* getSelectedListboxItem();

private:
	CEGUI::Listbox* mScriptListing;
	CITextFieldWidget* mNicknameField;
	CEGUI::PushButton* mBtnGenerateNickname;
	CEGUI::PushButton* mBtnSetNickname;
	CEGUI::PushButton* mBtnRemoveNickname;

private:
	CEGUI::Event::Connection mEventGenerateNickname;
	CEGUI::Event::Connection mEventSetNickname;
	CEGUI::Event::Connection mEventRemoveNickname;

private:
	bool onClicked_GenerateNickname(const CEGUI::EventArgs& evt);
	bool onClicked_SetNickname(const CEGUI::EventArgs& evt);
	bool onClicked_RemoveNickname(const CEGUI::EventArgs& evt);

private:
	CEGUI::Event::Connection mEventListSelectionChanged;
protected:
	bool onSelectionChanged_ScriptListing(const CEGUI::EventArgs& evt);

public:
	CEGUI::Event::Connection mEventCancel;
};
#endif