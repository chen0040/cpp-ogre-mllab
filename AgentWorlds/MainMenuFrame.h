#ifndef _H_MLLAB_MAIN_MENU_FRAME_H
#define _H_MLLAB_MAIN_MENU_FRAME_H

#include "../Frames/AppFrame.h"

class MainMenuFrame : public AppFrame
{
public:
	MainMenuFrame(Application* app, std::string frameName);
	virtual ~MainMenuFrame();

public:
	virtual bool frameStarted(const FrameEvent& evt);
	virtual bool frameEntered();
	virtual bool frameExited(); 
	
public:
	void addFrame(const std::string& display_name, const std::string& frame_name);

protected:
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

private:
	CEGUI::Listbox* mGameListing;
	CEGUI::Listbox* mSceneListing;
	CEGUI::DefaultWindow* mMenuBackground;
	CEGUI::PushButton* mBtnActivate;
	CEGUI::MultiLineEditbox* mGameAbstract;
	CEGUI::DefaultWindow* mMap;

private:
	CEGUI::Event::Connection mEventActivate;
	std::map<std::string, std::string> mFrameNames;
	CEGUI::Event::Connection mEventGameSelectionChanged;

protected:
	bool onSelectionChanged_Games(const CEGUI::EventArgs& evt);
	bool onButtonClicked_Activate(const CEGUI::EventArgs& evt);

private:
	Camera* mCamera;
};

#endif
