
#include <CEGUI/Cegui.h>
#include <OgreCEGUIRenderer.h>
#include "OgreCEGUIResourceProvider.h"

#include "OgrePagingLandscapeOptions.h"
#include "OgrePagingLandscapeSceneManager.h"
#include "LoadTerrainWindow.h"

using namespace std;

LoadTerrainWindow::LoadTerrainWindow(FrameListener* listener)
{
	//Random position for window
	Real posX = Math::RangeRandom(0, 800); 
    Real posY = Math::RangeRandom(0, 500); 

	mListener=static_cast<MapEditorListener*>(listener);

	mWindow = CEGUI::WindowManager::getSingleton().loadWindowLayout((CEGUI::utf8*)"MapEditorLoadTerrainWindow.layout");
	mWindow->setPosition(CEGUI::UVector2(CEGUI::UDim(1.0f, posX), CEGUI::UDim(1.0f, posY)));
	mWindow->deactivate();
	mWindow->hide();

	mCfgOkButton = (CEGUI::PushButton*)mWindow->getChild("LoadTerrainCfgOkButton");
	mRawOkButton = (CEGUI::PushButton*)mWindow->getChild("LoadTerrainRawOkButton");
	mCloseButton = (CEGUI::PushButton*)mWindow->getChild("LoadTerrainCloseButton");

	mCfgEditbox = (CEGUI::Editbox*)mWindow->getChild("LoadTerrainCfgEditbox");
	mRawEditbox = (CEGUI::Editbox*)mWindow->getChild("LoadTerrainRawEditbox");

	mCfgOkButton->subscribeEvent(CEGUI::PushButton::EventMouseClick, CEGUI::Event::Subscriber(&LoadTerrainWindow::handleCfgOkClicked, this));
	mRawOkButton->subscribeEvent(CEGUI::PushButton::EventMouseClick, CEGUI::Event::Subscriber(&LoadTerrainWindow::handleRawOkClicked, this));
	mCloseButton->subscribeEvent(CEGUI::PushButton::EventMouseClick, CEGUI::Event::Subscriber(&LoadTerrainWindow::handleCloseClicked, this));

	mMapTool = MapUtil::getSingletonPtr();
}
//------------------------------------------------------------------------------------------------
LoadTerrainWindow::~LoadTerrainWindow(void)
{
	mWindow=NULL;
	//delete mMapTool;
}
//------------------------------------------------------------------------------------------------
void LoadTerrainWindow::showWindow()
{
	mWindow->activate(); 
	mWindow->show(); 
}
//------------------------------------------------------------------------------------------------
void LoadTerrainWindow::hideWindow() 
{ 
	mWindow->deactivate(); 
	mWindow->hide(); 
}
//------------------------------------------------------------------------------------------------
bool LoadTerrainWindow::handleCfgOkClicked(const CEGUI::EventArgs& e)
{
	if(mCfgEditbox->getText()!="")
	{
		//Convert CEGUI::String to an Ogre::String. Ugly, but it works.		
		String text = mCfgEditbox->getText().c_str();

     
        if (StringUtil::endsWith (text, ".cfg", true))
        {    
            // removed .cfg part of name.
            text.assign (text.begin(), text.end() - 4);
//            std::vector< String > partofname = StringUtil::split (text, ".");
//            const uint numExtension = partofname.size();
//            ext_name = extension;
//            for (uint i = 0; i < numExtension - 1; i++)
//                pure_file_name += partofname[i] + ".";
        }


		mListener->getSceneManager()->setOption("InsertNewMap", &text);

        String groupname;
        mListener->getSceneManager()->getOption("GroupName", &groupname);
        // add it to the current resources so that plsm2 can find the data.
        String MapDirFile = mListener->mTerrainPath + "/" + text;
        try {
            ResourceGroupManager::getSingleton().addResourceLocation (MapDirFile, 
                                                                    "FileSystem", 
                                                                    groupname);
        }
        catch(...)
        {
            // ignore but should create an info window in CEGUI
			Ogre::LogManager::getSingleton ().logMessage (LML_CRITICAL, 
				String("Cannot add resource path : ") +  MapDirFile);
        }
		try {
			mListener->getSceneManager()->setOption("CurrentMap", &text);
			mListener->getSceneManager()->setOption( "LoadMap", 0 );
        }
        catch(...)
        {
			// ignore but should create an info window in CEGUI
			Ogre::LogManager::getSingleton ().logMessage (LML_CRITICAL, 
				String("Cannot LoadMap : ") +  text);
        }
		hideWindow();
	}

	return true;
}
//------------------------------------------------------------------------------------------------
bool LoadTerrainWindow::handleRawOkClicked(const CEGUI::EventArgs& e)
{
	if(mRawEditbox->getText()!="")
	{
			
		//Just messing around. Doesn't work yet.

		FILE* file;
		file = fopen("test.0.0.raw", "rb");

		Real* value = 0;
		fread(value, 2, 256*256, file);

		String mapName = "test";
		String groupname;
		mListener->getSceneManager()->getOption("GroupName", &groupname);
		mMapTool->LoadDataFromMemory (256, 256, value, 1.0);
		
		ColourValue colors[4];
		colors[0] =  ColourValue(1.0f, 1.0f, 0.0f); //Sand
		colors[1] =  ColourValue(0.13f, 0.545f, 0.13f); //Grass
		colors[2] = ColourValue(0.411764f, 0.411764f, 0.411764f); //Rock
		colors[3] =  ColourValue(1.0f, 0.98f, 0.98f); //Snow

		Real heights[4];
		heights[0] = 0.0f;
		heights[1] = 0.33f;
		heights[2] = 0.66f;
		heights[3] = 1.0f;

		mMapTool->setMapColoring (colors, heights, 4);

		//writeCfgFile(mapName.c_str(), pagesX, pagesZ, pageSize, tileSize);
		//Save and split the map
		mMapTool->processOneMap();	
		

		// add it to the current resources so that plsm2 can find the data.
		ResourceGroupManager::getSingleton().addResourceLocation ("", 
			"FileSystem", 
			groupname);

		mListener->getSceneManager()->setOption("InsertNewMap", &mapName);
		mListener->getSceneManager()->setOption("CurrentMap", &mapName);

	/*if(mRawEditbox->getText()!="")
	{
		//Convert CEGUI::String to an Ogre::String. Ugly, but it works.
		String text = mRawEditbox->getText().c_str();
		mListener->getSceneManager()->setOption("CurrentMap", &text);
		hideWindow();

		fclose(file);
		delete[] value;
	}*/
	}

	return true;
}
//------------------------------------------------------------------------------------------------
bool LoadTerrainWindow::handleCloseClicked(const CEGUI::EventArgs& e)
{
	hideWindow();
	return true;
}