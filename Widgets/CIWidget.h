#ifndef _H_ML_LAB_CI_WIDGET_H
#define _H_ML_LAB_CI_WIDGET_H

#define GUI_FILEDIALOG_WIN32 1
#define GUI_FILEDIALOG_CEGUI 2

#define GUI_FILEDIALOG GUI_FILEDIALOG_WIN32

#include <string>
#include <CEGUI/CEGUI.h>

class CIWidget
{
public:
	CIWidget(CIWidget* ParentWidget, CEGUI::Window* parentWindow);
	virtual ~CIWidget();

protected:
	virtual void initializeComponents(const std::string& rootId);
	virtual void create()=0;
	virtual void subscribeEvents() { }
	virtual void unsubscribeEvents() { }

protected:
	std::string getUIId(const std::string& localUIId) const;

public:
	const std::string& getRootId() const { return mRootId; }	
	CEGUI::Window* getRootWindow() { return mRootWindow; }
	void setModalState(bool modal);

public:
	static CEGUI::String getGUIType(const char* type);

protected:
	CIWidget* getModalWidget();

public:
	virtual void showWindow();
	virtual void hideWindow();

public:
	void setPosition(float x, float y);

protected:
	CEGUI::Window* mRootWindow;
	CEGUI::Window* mParentWindow;
	CIWidget* mParentWidget; 

public:
	virtual void hide();
	virtual void show();

private:
	std::string mRootId;
};
#endif