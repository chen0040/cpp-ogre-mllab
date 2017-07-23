#include "../GameEngine/Application.h"
#include "../OSEnvironment/OSEnvironment.h"
#include "../CIAgents/CIAgentManager.h"
#include "../ScriptEngine/ScriptManager.h"
#include "../AgentWorlds/AppDocFrame.h"
#include "../AgentWorlds/GameDesignFrame.h"
#include "../AgentWorlds/GameSimulationFrame.h"
#include "../AgentWorlds/SceneDesignFrame.h"
#include "../AgentWorlds/MainMenuFrame.h"
#include "../GameLoader/GameLoaderManager.h"

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32 || OGRE_PLATFORM == PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
#else
#include <iostream>
int main(int argc, char** argc)
#endif
{
	try{
		Application app;

		app.init("MLLab");

		CIAgentManager* agentMgr=new CIAgentManager(&app, 1);
		ScriptManager* scriptManager=new ScriptManager();

		GameLoaderManager::getSingletonPtr()->setDefaultCurrentGameLoader();

		MainMenuFrame* main_menu_frame = new MainMenuFrame(&app, "MainMenu");
		AppDocFrame* code_design_frame = new AppDocFrame(&app, "CodeDesign");
		GameDesignFrame* game_design_frame = new GameDesignFrame(&app, "GameDesign");
		GameSimulationFrame* game_simulation_frame=new GameSimulationFrame(&app, "GameSimulation");
		SceneDesignFrame* scene_design_frame=new SceneDesignFrame(&app, "SceneDesign");

		main_menu_frame->addFrame("Code Design", "CodeDesign");
		main_menu_frame->addFrame("Game Design", "GameDesign");
		main_menu_frame->addFrame("Game Simulation", "GameSimulation");
		main_menu_frame->addFrame("Scene Design", "SceneDesign");

		app.addFrame("Main Menu", main_menu_frame);
		app.addFrame("Code Design", code_design_frame);
		app.addFrame("Game Design", game_design_frame);
		app.addFrame("Scene Design", scene_design_frame);
		app.addFrame("Game Simulation", game_simulation_frame);

		app.setCurrentFrame("MainMenu");

		app.startRenderLoop();

		//cleanup
		if(agentMgr != NULL)
		{
			delete agentMgr;
			agentMgr=NULL;
		}

		if(scriptManager != NULL)
		{
			delete scriptManager;
			scriptManager=NULL;
		}

		app.cleanup();
	}catch(Ogre::Exception& e)
	{
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32 || OGRE_PLATFORM == PLATFORM_WIN32
		MessageBoxA(NULL, e.getFullDescription().c_str(), "An Ogre exception has occurred", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
		std::cout << e.getFullDescription().c_str() << std::endl;
#endif
	}
}