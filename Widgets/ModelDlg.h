#ifndef _H_ML_LAB_MODEL_DLG_H
#define _H_ML_LAB_MODEL_DLG_H

#include <Ogre.h>
#include "CIWidget.h"
#include "CIComboWidget.h"

class ModelDlg : public CIWidget
{
public:
	ModelDlg(const std::string& rootId);
	virtual ~ModelDlg();

protected:
	virtual void create();
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();	

public:
	void showModal();

public:
	std::string getSelectedModel() const;

protected:
	bool onClicked_Cancel(const CEGUI::EventArgs& evt);
	bool onClicked_OK(const CEGUI::EventArgs& evt);

protected:
	void hide();

protected:
	CEGUI::Event::Connection mEventCancel;
	CEGUI::Event::Connection mEventClose;
	CEGUI::Event::Connection mEventOK;

public:
	CEGUI::PushButton* getOKButton() { return mBtnOK; }
	CEGUI::PushButton* getCancelButton() { return mBtnCancel; }

private:
	CIComboWidget* mComboModel;

protected:
	CEGUI::PushButton* mBtnCancel;
	CEGUI::PushButton* mBtnOK;
	static size_t mNumModelDlgShown;
};

#endif

