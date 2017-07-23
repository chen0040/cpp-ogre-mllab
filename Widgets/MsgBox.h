#ifndef _H_ML_LAB_MSG_BOX_H
#define _H_ML_LAB_MSG_BOX_H

#include <Ogre.h>
#include "CIWidget.h"

class MsgBox : public CIWidget
{
public:
	MsgBox(const std::string& rootId);
	virtual ~MsgBox();

protected:
	virtual void create();
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();	

public:
	void showModal(const std::string& title, const std::string& text);

protected:
	bool onClicked_Cancel(const CEGUI::EventArgs& evt);

protected:
	CEGUI::Event::Connection mEventCancel;

protected:
	CEGUI::MultiLineEditbox* mEditBox;
	static size_t mNumMsgBoxShown;
};
#endif