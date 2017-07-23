#ifndef _H_MLLAB_GAMELOADER_SAVEAS_H
#define _H_MLLAB_GAMELOADER_SAVEAS_H

#include "../../Widgets/CIWidget.h"
#include "../../Widgets/CITextFieldWidget.h"

class GameLoaderSaveAsDlg : public CIWidget
{
public:
	GameLoaderSaveAsDlg(const std::string& rootId);
	virtual ~GameLoaderSaveAsDlg();

protected:
	void create();

protected:
	void subscribeEvents();
	void unsubscribeEvents();

private:
	CEGUI::PushButton* mBtnSave;
	CEGUI::PushButton* mBtnCancel;
public:
	CEGUI::PushButton* getBtnSave() { return mBtnSave; }
	CEGUI::PushButton* getBtnCancel() { return mBtnCancel; }

protected:
	bool onButtonClicked_Cancel(const CEGUI::EventArgs& evt);
	bool onCloseClicked_Close(const CEGUI::EventArgs& evt);

public:
	std::string getGameLoaderName() const;

private:
	CITextFieldWidget* mEditGameLoaderName;

private:
	CEGUI::Event::Connection mEventClose;
	CEGUI::Event::Connection mEventCancel;
};
#endif