
#include <CEGUI/Cegui.h>
#include <OgreCEGUIRenderer.h>
#include "OgreCEGUIResourceProvider.h"

#include "MapEditor.h"

//------------------------------------------------------------------------------------------------
MapEditor::MapEditor() : mMapGuiRenderer(0), 
                        mGuiSystem(0),
                        mActionBar(0),
                        mTabWindow(0),
                        mMapEditorListener(0)
{
}
//------------------------------------------------------------------------------------------------
MapEditor::~MapEditor()
{
	delete mActionBar;
	delete mTabWindow;
	delete mMapEditorListener;
    delete mGuiSystem;
    delete mMapGuiRenderer;
}
//------------------------------------------------------------------------------------------------
bool MapEditor::setup(void)
{
	mRoot = new Root("plugins.cfg", "plsm2_display.cfg", "plsm2.log");

#ifdef _DEBUG
	Root::getSingleton().loadPlugin("Plugin_PagingLandScapeSceneManager2_d");
#else
	Root::getSingleton().loadPlugin("Plugin_PagingLandScapeSceneManager2");
#endif

	setupResources();

	bool carryOn = configure();
	if (!carryOn) return false;

	chooseSceneManager();
	// Set default mipmap level (NB some APIs ignore this)
	TextureManager::getSingleton().setDefaultNumMipmaps(20);

	// Create any resource listeners (for loading screens)
	createResourceListener();
	// Load resources
	loadResources();

	assert(mSceneMgr);
	mSceneMgr->setWorldGeometry( Ogre::String("paginglandscape2.cfg") );
	createCamera();
	createViewports();

	// Create the scene
	createScene();

	createFrameListener();

	return true;

}
//------------------------------------------------------------------------------------------------
void MapEditor::setupResources(void)
{
	// Load resource paths from config file
	ConfigFile cf;
	cf.load("resources.cfg");

	// Go through all sections & settings in the file
	ConfigFile::SectionIterator seci = cf.getSectionIterator();

	String secName, typeName, archName;
	while (seci.hasMoreElements())
	{
		secName = seci.peekNextKey();
		ConfigFile::SettingsMultiMap *settings = seci.getNext();
		ConfigFile::SettingsMultiMap::iterator i;
		for (i = settings->begin(); i != settings->end(); ++i)
		{
			typeName = i->first;
			archName = i->second;
			ResourceGroupManager::getSingleton().addResourceLocation(
				archName, typeName, secName);
		}
	}

	mTerrainPath = "../../../paginglandscape/Samples/Media/paginglandscape2/terrains";

	// if folders aren't in the resources.cfg try some others as well
	ResourceGroupManager *rsm = ResourceGroupManager::getSingletonPtr();
	StringVector groups = rsm->getResourceGroups();        
	if (std::find(groups.begin(), groups.end(), String("PLSM2")) == groups.end())
	{
		FileInfoListPtr finfo =  ResourceGroupManager::getSingleton().findResourceFileInfo (
			"Bootstrap", "axes.mesh");
		const bool isSDK =  (!finfo->empty()) && 
			StringUtil::startsWith (finfo->begin()->archive->getName(), "../../media/packs/ogrecore.zip", true);



		rsm->createResourceGroup("PLSM2");
		if (isSDK)
		{
			rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2","FileSystem", "PLSM2");

			rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/models","FileSystem", "PLSM2");
			rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/overlays","FileSystem", "PLSM2");
			rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/materials","FileSystem", "PLSM2");

			rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/materials/scripts","FileSystem", "PLSM2");
			rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/materials/textures","FileSystem", "PLSM2");
			rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/materials/programs","FileSystem", "PLSM2");

			rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/datasrcs","FileSystem", "PLSM2");
			rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/terrains","FileSystem", "PLSM2");
			rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/gui","FileSystem", "PLSM2");
		}
		else
		{
			rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2","FileSystem", "PLSM2");

			rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/models","FileSystem", "PLSM2");
			rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/overlays","FileSystem", "PLSM2");
			rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/materials","FileSystem", "PLSM2");

			rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/materials/scripts","FileSystem", "PLSM2");
			rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/materials/textures","FileSystem", "PLSM2");
			rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/materials/programs","FileSystem", "PLSM2");

			rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/datasrcs","FileSystem", "PLSM2");
			rsm->addResourceLocation("../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/terrains","FileSystem", "PLSM2");

			rsm->addResourceLocation("../../../paginglandscape/Samples/Media/paginglandscape2/gui","FileSystem", "PLSM2");

			mTerrainPath = "../../../../../ogreaddons/paginglandscape/Samples/Media/paginglandscape2/terrains";
		}
	}
}
//-----------------------------------------------------------------------
/// Optional override method where you can perform resource group loading
/// Must at least do ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
void MapEditor::loadResources(void)
{
	// Initialise, parse scripts etc
	//ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
	ResourceGroupManager::getSingleton().initialiseResourceGroup(ResourceGroupManager::BOOTSTRAP_RESOURCE_GROUP_NAME);
	ResourceGroupManager::getSingleton().initialiseResourceGroup("General");
	ResourceGroupManager::getSingleton().initialiseResourceGroup("PLSM2");

}
//------------------------------------------------------------------------------------------------
void MapEditor::createScene()
{

	mSceneMgr->setAmbientLight(ColourValue(1.0, 1.0, 1.0));
	mCamera->setNearClipDistance( 1 );

	//Initialise GUI
	mMapGuiRenderer = new CEGUI::OgreCEGUIRenderer(mWindow, 
													Ogre::RENDER_QUEUE_OVERLAY, 
													false, 
													3000,
													mSceneMgr);
    mGuiSystem = new CEGUI::System(mMapGuiRenderer);
	CEGUI::Logger::getSingleton().setLoggingLevel(
		CEGUI::Informative
		//CEGUI::Insane
		//CEGUI::Standard
		);

	CEGUI::SchemeManager::getSingleton().loadScheme((CEGUI::utf8*)"Marti.scheme");
	CEGUI::MouseCursor::getSingleton().setImage((CEGUI::utf8*)"Marti", (CEGUI::utf8*)"MouseArrow");
	mGuiSystem->setDefaultMouseCursor((CEGUI::utf8*)"Marti", (CEGUI::utf8*)"MouseArrow");

	CEGUI::Font* smallfont = CEGUI::FontManager::getSingleton().createFont("bluehigh.ttf");//("BlueHighway-8", "bluehigh.ttf", 8, 0);
	CEGUI::Font* normalfont = smallfont;//CEGUI::FontManager::getSingleton().createFont("BlueHighway-10", "bluehigh.ttf", 10, 0);
	CEGUI::Font* bigfont = smallfont;//CEGUI::FontManager::getSingleton().createFont("BlueHighway-12", "bluehigh.ttf", 12, 0);
    mGuiSystem->setDefaultFont(smallfont);

	//Add GUI elements
    mMainWindow = CEGUI::WindowManager::getSingleton().loadWindowLayout((CEGUI::utf8*)"MapEditorMainWindow.layout"); 

	mGuiSystem->setGUISheet(mMainWindow);
}
//------------------------------------------------------------------------------------------------
void MapEditor::createFrameListener(void)
{
	//if(mMainWindow)
	//{
		mMapEditorListener = new MapEditorListener(mWindow, mCamera, mMapGuiRenderer, mTerrainPath, true, true);
		mRoot->addFrameListener(mMapEditorListener);

		mActionBar = new ActionBar(mMapEditorListener);
		mMainWindow->addChildWindow(mActionBar->getWindow());

		mTabWindow = new TabWindow(mMapEditorListener);
		mMainWindow->addChildWindow(mTabWindow->getWindow());

		mMainWindow->setVisible(true);
		//mTabWindow->setVisible(true);
		//mActionBar->setVisible(true);
		mSceneMgr->setSkyBox( true, "Examples/CloudyNoonSkyBox" );
	//}
}
//------------------------------------------------------------------------------------------------
void MapEditor::createViewports(void)
{
	// Entire window
	Viewport* vp = mWindow->addViewport(mCamera);
	vp->setBackgroundColour( ColourValue(0.8,0.8,0.8) );
}
//------------------------------------------------------------------------------------------------
void MapEditor::chooseSceneManager(void)
{
	mSceneMgr = mRoot->createSceneManager("PagingLandScapeSceneManager", "mapeditor");
}
//------------------------------------------------------------------------------------------------
void MapEditor::createCamera(void)
{
	mCamera = mSceneMgr->createCamera("PlayerCam" );

	Vector3 pos = Vector3(-64, -40, -64);
	mCamera->lookAt( pos );
	pos = Vector3(3085, 2000, 3085);
	mCamera->setPosition( pos );
    
}