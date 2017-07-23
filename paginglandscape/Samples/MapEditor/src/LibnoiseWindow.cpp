
#include <CEGUI/Cegui.h>
#include <OgreCEGUIRenderer.h>
#include "OgreCEGUIResourceProvider.h"

#include "LibnoiseWindow.h"
#include "MapEditorListener.h"
#include "fileutils.h"

//------------------------------------------------------------------------------------------------
LibnoiseWindow::LibnoiseWindow(FrameListener* listener)
{
	mListener=static_cast<MapEditorListener*>(listener);

	mWindow = CEGUI::WindowManager::getSingleton().loadWindowLayout((CEGUI::utf8*)"MapEditorLibnoiseWindow.layout");

	mLibnoise = new LibnoiseGenerator();

	mPreviewButton = (CEGUI::PushButton*)mWindow->getChild("LibnoisePreviewButton");
	mPreviewImage = (CEGUI::Window*)mWindow->getChild("PreviewWindow");

	mBillow = (CEGUI::RadioButton*)mWindow->getChild("BillowRadioButton");
	mCheckerboard = (CEGUI::RadioButton*)mWindow->getChild("CheckerboardRadioButton");
	mPerlin = (CEGUI::RadioButton*)mWindow->getChild("PerlinRadioButton");
	mRidgedMulti = (CEGUI::RadioButton*)mWindow->getChild("RidgedRadioButton");
	mVoronoi = (CEGUI::RadioButton*)mWindow->getChild("VoronoiRadioButton");

	mFrequencyEditbox = (CEGUI::Editbox*)mWindow->getChild("FrequencyEditbox");
	mFrequencyEditbox->setText("1.0");
	mLacunarityEditbox = (CEGUI::Editbox*)mWindow->getChild("LacunarityEditbox");
	mLacunarityEditbox->setText("2.0");
	mOctaveCountEditbox = (CEGUI::Editbox*)mWindow->getChild("OctaveCountEditbox");
	mOctaveCountEditbox->setText("6");
	mPersistanceEditbox = (CEGUI::Editbox*)mWindow->getChild("PersistanceEditbox");
	mPersistanceEditbox->setText("0.5");
	mSeedEditbox = (CEGUI::Editbox*)mWindow->getChild("SeedEditbox");
	mSeedEditbox->setText("0");

	mLocationXEditbox = (CEGUI::Editbox*)mWindow->getChild("LocationXEditbox");
	mLocationXEditbox->setText("2.0");
	mLocationYEditbox = (CEGUI::Editbox*)mWindow->getChild("LocationYEditbox");
	mLocationYEditbox->setText("1.0");
	mWidthEditbox = (CEGUI::Editbox*)mWindow->getChild("SizeWEditbox");
	mWidthEditbox->setText("4.0");
	mHeightEditbox = (CEGUI::Editbox*)mWindow->getChild("SizeHEditbox");
	mHeightEditbox->setText("4.0");

	mPreviewButton->subscribeEvent(CEGUI::PushButton::EventMouseClick, CEGUI::Event::Subscriber(&LibnoiseWindow::handlePreviewClicked, this));

	mGUIRenderer = CEGUI::System::getSingleton().getRenderer();
}
//------------------------------------------------------------------------------------------------
LibnoiseWindow::~LibnoiseWindow()
{
	delete mLibnoise;
	CEGUI::ImagesetManager::getSingleton().destroyAllImagesets();
}
//------------------------------------------------------------------------------------------------
bool LibnoiseWindow::handlePreviewClicked(const CEGUI::EventArgs& e)
{
	noise::module::Billow bollowModule;
	noise::module::Checkerboard checkerboardModule;
	noise::module::Perlin perlinModule;
	noise::module::RidgedMulti ridgedMultiModule;
	noise::module::Voronoi voronoiModule;

	static int counter = 0;
	static char buffer[16];
	static char buffer2[16];

	//Generate preview
	if(mBillow->isSelected())
	{
		heightMapBuilder.SetSourceModule(bollowModule);
		bollowModule.SetFrequency(getFrequency());
		bollowModule.SetLacunarity(getLacunarity());
		bollowModule.SetOctaveCount(getOctaveCount());
		bollowModule.SetSeed(getSeed());
	}
	else if(mCheckerboard->isSelected()) 
	{
		heightMapBuilder.SetSourceModule(checkerboardModule);
	}
	else if(mPerlin->isSelected())
	{
		heightMapBuilder.SetSourceModule(perlinModule);
		perlinModule.SetFrequency(getFrequency());
		perlinModule.SetLacunarity(getLacunarity());
		perlinModule.SetOctaveCount(getOctaveCount());
		perlinModule.SetSeed(getSeed());
	}
	else if(mRidgedMulti->isSelected())
	{
		heightMapBuilder.SetSourceModule(ridgedMultiModule);
		ridgedMultiModule.SetFrequency(getFrequency());
		ridgedMultiModule.SetLacunarity(getLacunarity());
		ridgedMultiModule.SetOctaveCount(getOctaveCount());
		ridgedMultiModule.SetSeed(getSeed());
	}
	else if(mVoronoi->isSelected())
	{
		heightMapBuilder.SetSourceModule(voronoiModule);
		voronoiModule.SetFrequency(getFrequency());
		voronoiModule.SetSeed(getSeed());
	}

	heightMapBuilder.SetDestNoiseMap (heightMap);

	heightMapBuilder.SetDestSize (128, 128);

	heightMapBuilder.SetBounds (getLocX(), getLocX() + getSizeWidth(), getLocY(), getLocY() + getSizeHeight());
	heightMapBuilder.Build ();

	noise::utils::RendererImage renderer;
	noise::utils::Image image;
	renderer.SetSourceNoiseMap (heightMap);
	renderer.SetDestImage (image);
	renderer.Render ();

	noise::utils::WriterBMP writer;
	writer.SetSourceImage (image);
	writer.SetDestFilename ("..\\..\\..\\Media\\materials\\textures\\preview.bmp");
	writer.WriteDestFile ();
	
	//Render to texture
	//
	
	try
	{
		CEGUI::Imageset *tempimg = CEGUI::ImagesetManager::getSingleton().getImageset( buffer );
		tempimg->undefineImage( buffer2 );
		CEGUI::ImagesetManager::getSingleton().destroyImageset( buffer );
		delete imageSet;
		//delete tex;
	}catch(...) {}
	
	//tex = mGUIRenderer->createTexture((CEGUI::utf8*)"preview.bmp", "General");
	
	sprintf(buffer, "pre%i", counter);
	sprintf(buffer2, "image%i", counter++);

	tex = mGUIRenderer->createTexture((CEGUI::utf8*)"preview.bmp", "General");
	imageSet = CEGUI::ImagesetManager::getSingleton().createImageset(buffer, tex);
	imageSet->setAutoScalingEnabled (true);
	imageSet->defineImage (buffer2, CEGUI::Point(0, 0), CEGUI::Size(128, 128), CEGUI::Point(0, 0));	

	//mPreviewImage->setImage(&(imageSet->getImage(buffer2)));
	mPreviewImage->setProperty("Image", 
		"set:" + imageSet->getName() + " image:" + imageSet->getImage((CEGUI::utf8*)buffer2).getName());

	return true;
}
//------------------------------------------------------------------------------------------------
void LibnoiseWindow::showWindow()
{
	mWindow->activate(); 
	mWindow->show(); 
}
//------------------------------------------------------------------------------------------------
void LibnoiseWindow::hideWindow() 
{ 
	mWindow->deactivate(); 
	mWindow->hide(); 
}
//------------------------------------------------------------------------------------------------
double LibnoiseWindow::getLocX() 
{
	return atof(mLocationXEditbox->getText().c_str()); 
}
//------------------------------------------------------------------------------------------------
double LibnoiseWindow::getLocY() 
{ 
	return atof(mLocationYEditbox->getText().c_str()); 
}
//------------------------------------------------------------------------------------------------
double LibnoiseWindow::getSizeWidth() 
{ 
	return atof(mLocationXEditbox->getText().c_str()) + atof(mWidthEditbox->getText().c_str()); 
}
//------------------------------------------------------------------------------------------------
double LibnoiseWindow::getSizeHeight() 
{ 
	return atof(mLocationYEditbox->getText().c_str()) + atof(mHeightEditbox->getText().c_str()); 
}
//------------------------------------------------------------------------------------------------
double LibnoiseWindow::getFrequency()
{
	return atof(mFrequencyEditbox->getText().c_str()); 
}
//------------------------------------------------------------------------------------------------
double LibnoiseWindow::getLacunarity()
{
	return atof(mLacunarityEditbox->getText().c_str()); 
}
//------------------------------------------------------------------------------------------------
double LibnoiseWindow::getOctaveCount()
{
	return atof(mOctaveCountEditbox->getText().c_str()); 
}
//------------------------------------------------------------------------------------------------
double LibnoiseWindow::getPersistance()
{
	return atof(mPersistanceEditbox->getText().c_str()); 
}
//------------------------------------------------------------------------------------------------
double LibnoiseWindow::getSeed()
{
	return atof(mSeedEditbox->getText().c_str()); 
}
//------------------------------------------------------------------------------------------------
int LibnoiseWindow::getGeneratorType()
{
	if(mBillow->isSelected())
	{
		return 0;
	}
	else if(mCheckerboard->isSelected()) 
	{
		return 1;
	}
	else if(mPerlin->isSelected())
	{
		return 2;
	}
	else if(mRidgedMulti->isSelected())
	{
		return 3;
	}
	else if(mVoronoi->isSelected())
	{
		return 4;
	}
	return 0;
}

