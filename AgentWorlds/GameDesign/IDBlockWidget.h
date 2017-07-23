#ifndef _H_ID_BLOCK_WIDGET_H
#define _H_ID_BLOCK_WIDGET_H

#include "../../Widgets/CIWidget.h"
#include "../../Widgets/CITextFieldWidget.h"
#include "../../Widgets/CIProgressBar.h"
#include "../../Widgets/ModelDlg.h"

class IDBlockWidget : public CIWidget
{
public:
	IDBlockWidget(const std::string& rootId, CEGUI::Window* parentWindow=NULL);
	virtual ~IDBlockWidget();

protected:
	virtual void create();
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

public:
	bool isVisible() const { return mRootWindow->isVisible(); }

public:
	void setBlockIDEntity(const std::string& id) { mRootWindow->setText(id); }
	void setBlockIDTag(const std::string& id) { mCaptureTagID->setText(id); }
	void setBlockIDScript(const std::string& id);
	void setBlockIDLife(float life) { mLifeBar->setProgress(life); }
	void setBlockIDWeaponGrade(float weaponRate) { mWeaponBar->setProgress(weaponRate); }
	void setBlockIDAction(const std::string& action) { mEntityAction->setText(action); }

public:
	CEGUI::PushButton* getTrainingButton() { return mBtnTraining; }
	CEGUI::PushButton* getModelButton() { return mBtnModel; }
	CEGUI::PushButton* getUploadConfigButton() { return mBtnPostConfig; }
	ModelDlg* getModelDlg() { return mModelDlg; }

protected:
	bool onCloseClicked(const CEGUI::EventArgs& evt);
	bool onBtnModelClicked(const CEGUI::EventArgs& evt);

protected:
	CEGUI::Event::Connection mEventClosedClicked;
	CEGUI::Event::Connection mEventBtnModel;

protected:
	CITextFieldWidget* mCaptureTagID;
	CITextFieldWidget* mEntityAction;
	CITextFieldWidget* mCaptureScriptID;
	CIProgressBar* mLifeBar;
	CIProgressBar* mWeaponBar;
	CEGUI::PushButton* mBtnTraining;
	CEGUI::PushButton* mBtnPostConfig;
	CEGUI::PushButton* mBtnModel;
	ModelDlg* mModelDlg;
};
#endif