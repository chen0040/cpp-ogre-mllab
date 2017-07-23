
#include <CEGUI/Cegui.h>
#include <OgreCEGUIRenderer.h>
#include "OgreCEGUIResourceProvider.h"

#include "OgrePagingLandscapeOptions.h"
#include "OgrePagingLandscapeSceneManager.h"
#include "NewTerrainWindow.h"


NewTerrainWindow::NewTerrainWindow(FrameListener* listener)
{
	//Random position for window
	Real posX = Math::RangeRandom(0, 100); 
    Real posY = Math::RangeRandom(0, 100); 

	mListener=static_cast<MapEditorListener*>(listener);

	mWindow = 
		CEGUI::WindowManager::getSingleton().loadWindowLayout(
		(CEGUI::utf8*)"MapEditorNewTerrainWindow.layout"
		//(CEGUI::utf8*)"NewTerrainWindow.layout"
		);
	mWindow->setPosition(CEGUI::UVector2(CEGUI::UDim(1.0f, posX), CEGUI::UDim(1.0f, posY)));
	mWindow->deactivate();
	mWindow->hide();
	mWindow->setWidth(CEGUI::UDim(1.0f, 150));

	m256WidthRadioButton = (CEGUI::RadioButton*)mWindow->getChild("256WidthRadioButton"); 
	m512WidthRadioButton = (CEGUI::RadioButton*)mWindow->getChild("512WidthRadioButton"); 
	m1024WidthRadioButton = (CEGUI::RadioButton*)mWindow->getChild("1024WidthRadioButton"); 
	m2048WidthRadioButton = (CEGUI::RadioButton*)mWindow->getChild("2048WidthRadioButton"); 
	m4096WidthRadioButton = (CEGUI::RadioButton*)mWindow->getChild("4096WidthRadioButton"); 

	m256HeightRadioButton = (CEGUI::RadioButton*)mWindow->getChild("256HeightRadioButton"); 
	m512HeightRadioButton = (CEGUI::RadioButton*)mWindow->getChild("512HeightRadioButton"); 
	m1024HeightRadioButton = (CEGUI::RadioButton*)mWindow->getChild("1024HeightRadioButton"); 
	m2048HeightRadioButton = (CEGUI::RadioButton*)mWindow->getChild("2048HeightRadioButton"); 
	m4096HeightRadioButton = (CEGUI::RadioButton*)mWindow->getChild("4096HeightRadioButton");

	mGenerateTerrainBlankRadioButton = (CEGUI::RadioButton*)mWindow->getChild("GenerateBlankTerrain"); 
	mGenerateTerrainPlasmaRadioButton = (CEGUI::RadioButton*)mWindow->getChild("GenerateTerrainPlasma"); 
	mGenerateTerrainFaultRadioButton = (CEGUI::RadioButton*)mWindow->getChild("GenerateTerrainFault"); 
	mGenerateTerrainParticleRadioButton = (CEGUI::RadioButton*)mWindow->getChild("GenerateTerrainParticle");
	mGenerateTerrainLibnoiseRadioButton = (CEGUI::RadioButton*)mWindow->getChild("GenerateTerrainLibnoise");

	mOkButton = (CEGUI::PushButton*)mWindow->getChild("OkButton");
	mCancelButton = (CEGUI::PushButton*)mWindow->getChild("CancelButton");

	mMapNameEditbox = (CEGUI::Editbox*)mWindow->getChild("NewTerrainNameEditbox");

	mOkButton->subscribeEvent(CEGUI::PushButton::EventMouseClick, CEGUI::Event::Subscriber(&NewTerrainWindow::handleOkClicked, this));
	mCancelButton->subscribeEvent(CEGUI::PushButton::EventMouseClick, CEGUI::Event::Subscriber(&NewTerrainWindow::handleCancelClicked, this));

	//Radiobutton listeners
	mGenerateTerrainLibnoiseRadioButton->subscribeEvent(CEGUI::RadioButton::EventSelectStateChanged, CEGUI::Event::Subscriber(&NewTerrainWindow::handleRadiobuttonSelectionChanged, this));

    m256WidthRadioButton->setSelected(true);
    
    mMapTool = new MapUtil ();
    mMapCreate = new ErodeFault();

	mLibnoiseWindow = new LibnoiseWindow(mListener);
	mLibnoise = new LibnoiseGenerator();

	mLibnoiseWindow->hideWindow();
	CEGUI::WindowManager::getSingleton().getWindow("GenerateWindow")->addChildWindow(mLibnoiseWindow->getWindow());
}
//------------------------------------------------------------------------------------------------
NewTerrainWindow::~NewTerrainWindow(void)
{
	mWindow=NULL;
    delete mMapTool;
    delete mMapCreate;
	delete mLibnoise;

	delete mLibnoiseWindow;
}
//------------------------------------------------------------------------------------------------
bool NewTerrainWindow::handleRadiobuttonSelectionChanged(const CEGUI::EventArgs& e)
{
	if(mGenerateTerrainLibnoiseRadioButton->isSelected())
	{
		CEGUI::WindowManager::getSingleton().getWindow("RadioButtonBackground")->setVisible(true);
		CEGUI::WindowManager::getSingleton().getWindow("RadioButtonBackground")->setPosition(
			CEGUI::UVector2(mGenerateTerrainLibnoiseRadioButton->getPosition().d_x - CEGUI::UDim(1.0f, 5), 
							mGenerateTerrainLibnoiseRadioButton->getPosition().d_y - CEGUI::UDim(1.0f, 5)));
		mLibnoiseWindow->showWindow();
		mWindow->setWidth(CEGUI::UDim(1.0f, 510));
	}
	else
	{
		CEGUI::WindowManager::getSingleton().getWindow("RadioButtonBackground")->setVisible(false);
		mLibnoiseWindow->hideWindow();
		mWindow->setWidth(CEGUI::UDim(1.0f, 150));
	}

	return true;
}
//------------------------------------------------------------------------------------------------
bool NewTerrainWindow::handleOkClicked(const CEGUI::EventArgs& e)
{

	int mapWidth, mapHeight, pagesX, pagesZ, pageSize, tileSize;

	hideWindow();
	
	if(m256WidthRadioButton->isSelected())
		mapWidth=257;
	else if(m512WidthRadioButton->isSelected())
		mapWidth=513;
	else if(m1024WidthRadioButton->isSelected())
		mapWidth=1025;
	else if(m2048WidthRadioButton->isSelected())
		mapWidth=2049;
	else if(m4096WidthRadioButton->isSelected())
		mapWidth=4097;

	if(m256HeightRadioButton->isSelected())
		mapHeight=257;
	else if(m512HeightRadioButton->isSelected())
		mapHeight=513;
	else if(m1024HeightRadioButton->isSelected())
		mapHeight=1025;
	else if(m2048HeightRadioButton->isSelected())
		mapHeight=2049;
	else if(m4096HeightRadioButton->isSelected())
		mapHeight=4097;

	pageSize=257;
	tileSize=65;

	pagesX = (mapWidth - 1) / (pageSize - 1);
	pagesZ = (mapHeight - 1) / (pageSize - 1);

    String mapName=  mMapNameEditbox->getText().c_str();
    
    String groupname;
    mListener->getSceneManager()->getOption("GroupName", &groupname);

    String MapDirFile = mListener->mTerrainPath + "/" + mapName;

    mListener->getSceneManager()->getOption("GroupName", &groupname);

    mMapTool->setMap (mapName, 
                    "raw", 
                    "png", 
                    pageSize, 
                    MapDirFile, groupname,
                    2.0f);//texture scale factor (if heightmap is 257, generated color texture becomes 512)


    Real *heightData = new Real[mapHeight*mapWidth];

    
    const Real yscale = 1.0;

    // until someone contribute those map creation function to do something else
    // than squares..
    const Real smallestSide = (mapWidth > mapHeight)?mapHeight:mapWidth;

	/*if (mGenerateTerrainBlankRadioButton->isSelected())
	{
		mMapCreate->MakeTerrainFlat(heightData, mapWidth, mapHeight, yscale);
	}
	else*/ if (mGenerateTerrainPlasmaRadioButton->isSelected())
        mMapCreate->MakeTerrainPlasma(heightData, smallestSide,
                                            0.8f,//rough
                                            yscale);
     else if(mGenerateTerrainFaultRadioButton->isSelected())
        mMapCreate->MakeTerrainDeposition(heightData,
                                            smallestSide,
                                            10,//jumps,
                                            100,//peakWalk, 
                                            10,//minParticlesPerJump, 
                                            100,//maxParticlesPerJump,
                                            0.5f, //caldera
                                            yscale);
     else if(mGenerateTerrainParticleRadioButton->isSelected())
        mMapCreate->MakeTerrainFault(heightData,
                                    smallestSide,
                                    100,//iteration
                                    100, //maxdelta
                                    0,//mindelta
                                    4,//iterations Per Erosion Filter  (3 means each 3 filter erosion occurs)
                                    0.2f,// erosion roughness
                                    yscale);

	 else if(mGenerateTerrainLibnoiseRadioButton->isSelected())
	 {
		double x = mLibnoiseWindow->getLocX();
		double y = mLibnoiseWindow->getLocY();
		double w = mLibnoiseWindow->getSizeWidth();
		double h = mLibnoiseWindow->getSizeHeight();

		double freq = mLibnoiseWindow->getFrequency();
		double lac = mLibnoiseWindow->getLacunarity();
		double oc = mLibnoiseWindow->getOctaveCount();
		double pers = mLibnoiseWindow->getPersistance();
		double seed = mLibnoiseWindow->getSeed();

		const unsigned int mapSize = mapWidth*mapHeight;
		double * hMap = new  double[mapSize];
		for (unsigned int i = 0; i < mapSize; i++)
		{
			hMap[i] = heightData[i];
		}
		if(mLibnoiseWindow->getGeneratorType() == 0)
			mLibnoise->MakeTerrainBillow(hMap, mapWidth, mapHeight, x, y, w, h, freq, lac, oc, pers, seed, yscale);
		else if(mLibnoiseWindow->getGeneratorType() == 1)
			mLibnoise->MakeTerrainCheckerboard(hMap, mapWidth, mapHeight, x, y, w, h, freq, lac, oc, pers, seed, yscale);
		else if(mLibnoiseWindow->getGeneratorType() == 2)
			mLibnoise->MakeTerrainPerlin(hMap, mapWidth, mapHeight, x, y, w, h, freq, lac, oc, pers, seed, yscale);
		else if(mLibnoiseWindow->getGeneratorType() == 3)
			mLibnoise->MakeTerrainRidgedMulti(hMap, mapWidth, mapHeight, x, y, w, h, freq, lac, oc, pers, seed, yscale);
		else if(mLibnoiseWindow->getGeneratorType() == 4)
			mLibnoise->MakeTerrainVoronoi(hMap, mapWidth, mapHeight, x, y, w, h, freq, lac, oc, pers, seed, yscale);
		
		for (unsigned int i = 0; i < mapSize; i++)
		{
			heightData[i] = hMap[i];
		}
		delete [] hMap;
	 }


    mMapTool->LoadDataFromMemory (mapWidth, 
								mapHeight, 
                                heightData, 
                                yscale);

    ColourValue colors[4];
    
    colors[0] =  ColourValue(1.0f, 1.0f, 0.0f); //Sand
    colors[1] =  ColourValue(0.13f, 0.545f, 0.13f); //Grass
    colors[2] =  ColourValue(0.411764f, 0.411764f, 0.411764f); //Rock
    colors[3] =  ColourValue(1.0f, 0.98f, 0.98f); //Snow

    Real heights[4];

    heights[0] = 0.0f;
    heights[1] = 0.33f;
    heights[2] = 0.66f;
    heights[3] = 1.0f;

    mMapTool->setMapColoring (colors, heights, 4);

	writeCfgFile(mapName.c_str(), pagesX, pagesZ, pageSize, tileSize);
	//Save and split the map
    mMapTool->processOneMap();	
	

    // add it to the current resources so that plsm2 can find the data.
    ResourceGroupManager::getSingleton().addResourceLocation (MapDirFile, 
        "FileSystem", 
        groupname);

	mListener->getSceneManager()->setOption("InsertNewMap", &mapName);
	mListener->getSceneManager()->setOption("CurrentMap", &mapName);

    delete [] heightData;
	return true;
}
//------------------------------------------------------------------------------------------------
bool NewTerrainWindow::handleCancelClicked(const CEGUI::EventArgs& e)
{
	hideWindow();
	return true;
}
//------------------------------------------------------------------------------------------------
void NewTerrainWindow::writeCfgFile(const char* name, int w, int h, int pageSize, int tileSize)
{
	FILE *OutputFile;
	
	String fileName (mListener->mTerrainPath + "/" + name + ".cfg");	
	if((OutputFile = fopen(fileName.c_str(), "w")) != NULL)
	{
		fprintf(OutputFile, "%s", "GroupName=PLSM2\n");
		fprintf(OutputFile, "%s", "LandScapeFileName=");
		fprintf(OutputFile, "%s", name);
		fprintf(OutputFile, "%s", "\nFileSystem=LandScapeFileName");
		fprintf(OutputFile, "%s", "\nWidth=");
		fprintf(OutputFile, "%i", w);
		fprintf(OutputFile, "%s", "\nHeight=");
		fprintf(OutputFile, "%i", h);
		fprintf(OutputFile, "%s", "\nPageSize=");
		fprintf(OutputFile, "%i", pageSize);
		fprintf(OutputFile, "%s", "\nTileSize=");
		fprintf(OutputFile, "%i", tileSize);
		fprintf(OutputFile, "%s", "\nData2DFormat=HeightField\n");
		fprintf(OutputFile, "%s", "ScaleX=2000\n");
		fprintf(OutputFile, "%s", "ScaleY=2000\n");
		fprintf(OutputFile, "%s", "ScaleZ=2000\n");

		fprintf(OutputFile, "%s", "Deformable=yes\n");
		fprintf(OutputFile, "%s", "VertexCompression=yes\n");
		fprintf(OutputFile, "%s", "VertexProgramMorph=yes\n");
		fprintf(OutputFile, "%s", "LODMorphStart=0.2\n");
		fprintf(OutputFile, "%s", "MaxPixelError=10\n");
		fprintf(OutputFile, "%s", "VertexNormals=no\n");

		fprintf(OutputFile, "%s", "NumTextureFormatSupported=14\n");
		fprintf(OutputFile, "%s", "TextureFormatSupported0=Base\n");
		fprintf(OutputFile, "%s", "TextureFormatSupported1=Base2\n");
		fprintf(OutputFile, "%s", "TextureFormatSupported2=InstantBase\n");
		fprintf(OutputFile, "%s", "TextureFormatSupported3=Splatting\n");
		fprintf(OutputFile, "%s", "TextureFormatSupported4=Splatting2\n");
		fprintf(OutputFile, "%s", "TextureFormatSupported5=Splatting4\n");
		fprintf(OutputFile, "%s", "TextureFormatSupported6=Splatting6\n");
		fprintf(OutputFile, "%s", "TextureFormatSupported7=Splatting7\n");
		fprintf(OutputFile, "%s", "TextureFormatSupported8=Base\n");
		fprintf(OutputFile, "%s", "TextureFormatSupported9=Base2\n");
		fprintf(OutputFile, "%s", "TextureFormatSupported10=InstantBase\n");
		fprintf(OutputFile, "%s", "TextureFormatSupported11=Splatting3\n");
		fprintf(OutputFile, "%s", "TextureFormatSupported12=Splatting5\n");
		fprintf(OutputFile, "%s", "TextureFormatSupported13=SplattingShader\n");


		fprintf(OutputFile, "%s", "TextureFormat=Base\n");
		fprintf(OutputFile, "%s", "TextureStretchFactor=2\n");

		fprintf(OutputFile, "%s", "MaterialHeight1=33\n");
		fprintf(OutputFile, "%s", "MaterialHeight2=66\n");
		fprintf(OutputFile, "%s", "NumMatHeightSplat=4\n");

		fprintf(OutputFile, "%s", "SplatFilename0=splatting_sand.png\n");
		fprintf(OutputFile, "%s", "SplatFilename1=splatting_grass.png\n");
		fprintf(OutputFile, "%s", "SplatFilename2=splatting_rock.png\n");
		fprintf(OutputFile, "%s", "SplatFilename3=splatting_snow.png\n");

		fprintf(OutputFile, "%s", "HorizonVisibilityComputing=no\n");

		fclose(OutputFile);
	}
}
//------------------------------------------------------------------------------------------------
void NewTerrainWindow::showWindow()
{
	mWindow->activate(); 
	mWindow->show(); 
}
//------------------------------------------------------------------------------------------------
void NewTerrainWindow::hideWindow() 
{ 
	mWindow->deactivate(); 
	mWindow->hide(); 
}

