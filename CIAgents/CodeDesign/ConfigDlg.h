#ifndef _H_MLLAB_CI_CONFIG_H
#define _H_MLLAB_CI_CONFIG_H

#include <Ogre.h>
#include <CEGUI/CEGUI.h>
#include <string>
#include <vector>
#include <map>
#include "../../Widgets/CIWidget.h"
#include "../../tinyxml/tinyxml.h"

using namespace Ogre;

class CIConfigNodeTabWidget;

class ConfigDlg : public CIWidget
{
public:
	ConfigDlg(const std::string& rootId, const std::string& citype, const std::string& cimethod, CEGUI::Window* parentWindow=NULL);
	virtual ~ConfigDlg();

public:
	virtual void showModal();
	virtual void saveXml(TiXmlElement* xmlConfig);
	virtual void loadXml(TiXmlElement* xmlConfig);

protected:
	virtual void create();
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

protected:
	virtual bool onCancel(const CEGUI::EventArgs& evt);
	virtual bool onOK(const CEGUI::EventArgs& evt);
	virtual void doSave();
	virtual void doLoad();

public:
	virtual void processFile(const std::string& destinationFile, const std::string& fileType) const;
	virtual std::string toString() const;
protected:
	virtual void doPassByParam(const std::string& destinationFile, const std::string& fileTpe) const;
	virtual void doPassByArray(const std::string& destinationFile, const std::string& fileType) const;
	virtual void doPassByRepeat(const std::string& destinationFile, const std::string& fileType) const;
	virtual void doPassByTemplate(const std::string& destinationFile, const std::string& fileType) const;

private:
	CEGUI::Event::Connection mEventClickedOK;
	CEGUI::Event::Connection mEventClickedCancel;
	CEGUI::Event::Connection mEventCloseClicked;

protected:
	CEGUI::TabControl* mTabControl;
	CEGUI::PushButton* mBtnOK;
	CEGUI::PushButton* mBtnCancel;
	std::map<std::string, CIConfigNodeTabWidget*> mTabPanels;

protected:
	std::string mCITypeName;
	std::string mCIMethodName;
	static size_t mNumConfigDlgShown;
};
#endif