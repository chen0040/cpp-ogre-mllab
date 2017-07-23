#ifndef _H_MLLAB_SCENE_DESIGN_TOOLKIT_H
#define _H_MLLAB_SCENE_DESIGN_TOOLKIT_H

#include "../../Widgets/CIWidget.h"
#include "TerrainDesignToolkit.h"
#include "SkyDesignToolkit.h"
#include "HydraxDesignToolkit.h"
#include "ForestDesignToolkit.h"
#include "BuildingDesignToolkit.h"

class SceneDesignToolkit : public CIWidget
{
public:
	enum SceneDesignAction
	{
		SD_TERRAIN,
		SD_SKY,
		SD_HYDRAX,
		SD_FOREST, 
		SD_STATICAGENT
	};

public:
	SceneDesignToolkit(const std::string& rootId);
	virtual ~SceneDesignToolkit();

public:
	SceneDesignAction getDesignAction() const { return mSceneDesignAction; }
	TerrainDesignToolkit::TerrainDesignAction getTerrainDesignAction() const { return mTerrainDesignToolkit->getDesignAction(); }
	SkyDesignToolkit::SkyDesignAction getSkyDesignAction() const { return mSkyDesignToolkit->getDesignAction(); }
	HydraxDesignToolkit::HydraxDesignAction getHydraxDesignAction() const { return mHydraxDesignToolkit->getDesignAction(); }
	ForestDesignToolkit::ForestDesignAction getForestDesignAction() const { return mForestDesignToolkit->getDesignAction(); }

public:
	float getForestEditRadius() const { return mForestDesignToolkit->getRadius(); }
	int getForestEditCount() const { return mForestDesignToolkit->getCount(); }
	bool isForestEditAutoPopulateEnabled() const { return mForestDesignToolkit->isAutoPopulateEnabled(); }
	bool isBuilding() const { return mBuildingDesignToolkit->isBuilding(); }

protected:
	virtual void create();

protected:
	virtual void subscribeEvents();
	virtual void unsubscribeEvents();

private:
	CEGUI::PushButton* mBtnTerrain;
	CEGUI::PushButton* mBtnSky;
	CEGUI::PushButton* mBtnHydrax;
	CEGUI::PushButton* mBtnForest;
	CEGUI::PushButton* mBtnBuilding;
	std::vector<CEGUI::PushButton*> mButtons;

protected:
	bool onButtonClicked_Terrain(const CEGUI::EventArgs& evt);
	bool onButtonClicked_Sky(const CEGUI::EventArgs& evt);
	bool onButtonClicked_Hydrax(const CEGUI::EventArgs& evt);
	bool onButtonClicked_Forest(const CEGUI::EventArgs& evt);
	bool onButtonClicked_Building(const CEGUI::EventArgs& evt);

private:
	void enableAllButtons();

private:
	CEGUI::Event::Connection mEventTerrain;
	CEGUI::Event::Connection mEventSky;
	CEGUI::Event::Connection mEventHydrax;
	CEGUI::Event::Connection mEventForest;
	CEGUI::Event::Connection mEventBuilding;

private:
	TerrainDesignToolkit* mTerrainDesignToolkit;
	SkyDesignToolkit* mSkyDesignToolkit;
	HydraxDesignToolkit* mHydraxDesignToolkit;
	ForestDesignToolkit* mForestDesignToolkit;
	BuildingDesignToolkit* mBuildingDesignToolkit;

private:
	SceneDesignAction mSceneDesignAction;

public:
	virtual void show();
	virtual void hide();
};
#endif