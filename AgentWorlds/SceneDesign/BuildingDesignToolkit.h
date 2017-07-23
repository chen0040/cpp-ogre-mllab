#ifndef _H_MLLAB_Building_DESIGN_TOOLKIT_H
#define _H_MLLAB_Building_DESIGN_TOOLKIT_H

#include <Ogre.h>
#include "../../Widgets/CIWidget.h"

using namespace Ogre;

class BuildingDesignToolkit : public CIWidget
{
public:
	BuildingDesignToolkit(const std::string& rootId);
	virtual ~BuildingDesignToolkit();

protected:
	virtual void create();

protected:
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

private:
	CEGUI::Listbox* mBuildingList;
	CEGUI::Checkbox* mChkBuild;

private:
	CEGUI::Event::Connection mEventListSelectionChanged;
protected:
	bool onSelectionChanged_BuildingTypeUri(const CEGUI::EventArgs& evt);

public:
	void show();
	void hide();

public:
	bool isBuilding() const;

private:
	void updateBuildingTypeUriUI();
};
#endif