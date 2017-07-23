#include "OgreCEGUIRenderer.h"
#include "OgreCEGUIResourceProvider.h"
#include "ExampleApplication.h"
#include "CEGUICommonFileDialog.h"

CEGUI::MouseButton convertOgreButtonToCegui(int buttonID)
{
    switch (buttonID)
    {
    case MouseEvent::BUTTON0_MASK:
        return CEGUI::LeftButton;
    case MouseEvent::BUTTON1_MASK:
        return CEGUI::RightButton;
    case MouseEvent::BUTTON2_MASK:
        return CEGUI::MiddleButton;
    case MouseEvent::BUTTON3_MASK:
        return CEGUI::X1Button;
    default:
        return CEGUI::LeftButton;
    }
}

class GuiFrameListener : public ExampleFrameListener, public MouseMotionListener, public MouseListener
{
private:
    CEGUI::Renderer* mGUIRenderer;
    bool mShutdownRequested;

public:
    // NB using buffered input, this is the only change
    GuiFrameListener(RenderWindow* win, Camera* cam, CEGUI::Renderer* renderer)
        : ExampleFrameListener(win, cam, true, true), 
          mGUIRenderer(renderer),
          mShutdownRequested(false)
    {
        mEventProcessor->addMouseMotionListener(this);
        mEventProcessor->addMouseListener(this);
		mEventProcessor->addKeyListener(this);
    }

    // Tell the frame listener to exit at the end of the next frame
    void requestShutdown(void)
    {
        mShutdownRequested = true;
    }

    bool frameEnded(const FrameEvent& evt)
    {
        if (mShutdownRequested)
            return false;
        else
            return ExampleFrameListener::frameEnded(evt);
    }

    void mouseMoved (MouseEvent *e)
    {
        CEGUI::System::getSingleton().injectMouseMove(
                e->getRelX() * mGUIRenderer->getWidth(), 
                e->getRelY() * mGUIRenderer->getHeight());
        e->consume();
    }

    void mouseDragged (MouseEvent *e) 
    { 
        mouseMoved(e);
    }

    void mousePressed (MouseEvent *e)
    {
        CEGUI::System::getSingleton().injectMouseButtonDown(
          convertOgreButtonToCegui(e->getButtonID()));
        e->consume();
    }

    void mouseReleased (MouseEvent *e)
    {
        CEGUI::System::getSingleton().injectMouseButtonUp(
          convertOgreButtonToCegui(e->getButtonID()));
        e->consume();
    }

	void mouseClicked(MouseEvent* e) {}
	void mouseEntered(MouseEvent* e) {}
	void mouseExited(MouseEvent* e) {}

    void keyPressed(KeyEvent* e)
    {
        if(e->getKey() == KC_ESCAPE)
        {
            mShutdownRequested = true;
            e->consume();
            return;
        }

        CEGUI::System::getSingleton().injectKeyDown(e->getKey());
		CEGUI::System::getSingleton().injectChar(e->getKeyChar());
        e->consume();
    }

	void keyReleased(KeyEvent* e)
	{
		CEGUI::System::getSingleton().injectKeyUp(e->getKey());
		e->consume();
	}
	void keyClicked(KeyEvent* e) 
	{
		// Do nothing
		e->consume();
	}
};

class GuiApplication : public ExampleApplication
{
private:
    CEGUI::Window* mEditorGuiSheet;
    CEGUI::OgreCEGUIRenderer* mGUIRenderer;
    CEGUI::System* mGUISystem;
	CEGUI::Listbox* _mlstListbox;
	CEGUI::Window* mainWindow;
public:
    GuiApplication()
      : mGUIRenderer(0),
	    mGUISystem(0),
		mEditorGuiSheet(0){}

    ~GuiApplication()
    {
		_mlstListbox->resetList();

		if (mEditorGuiSheet)
			CEGUI::WindowManager::getSingleton().destroyWindow(mEditorGuiSheet);

	    if(mGUISystem)
        {
            delete mGUISystem;
            mGUISystem = 0;
        }
        if(mGUIRenderer)
        {
            delete mGUIRenderer;
            mGUIRenderer = 0;
        }
    }

protected:
    // Just override the mandatory create scene method
    void createScene(void)
    {
        // Set ambient light
        mSceneMgr->setAmbientLight(ColourValue(0.5, 0.5, 0.5));

        // Create a light
        Light* l = mSceneMgr->createLight("MainLight");
        l->setPosition(20,80,50);

        // setup GUI system
        mGUIRenderer = new CEGUI::OgreCEGUIRenderer(mWindow, 
            Ogre::RENDER_QUEUE_OVERLAY, false, 3000);

        mGUISystem = new CEGUI::System(mGUIRenderer);
        CEGUI::Logger::getSingleton().setLoggingLevel(CEGUI::Informative);
		

        // load scheme and set up defaults
        CEGUI::SchemeManager::getSingleton().loadScheme(
                (CEGUI::utf8*)"TaharezLook2.scheme");
        mGUISystem->setDefaultMouseCursor(
                (CEGUI::utf8*)"TaharezLook", (CEGUI::utf8*)"MouseArrow");

        mGUISystem->setDefaultFont((CEGUI::utf8*)"Tahoma");

        mEditorGuiSheet = CEGUI::WindowManager::getSingleton().loadWindowLayout(
                (CEGUI::utf8*)"ogregui2.layout"); 
        mGUISystem->setGUISheet(mEditorGuiSheet);

		CEGUI::PushButton* _mBtnLoad = (CEGUI::PushButton*)CEGUI::WindowManager::getSingleton().getWindow((CEGUI::utf8*)"Root/Load/LoadButton");
		CEGUI::PushButton* _mBtnSave = (CEGUI::PushButton*)CEGUI::WindowManager::getSingleton().getWindow((CEGUI::utf8*)"Root/Save/SaveButton");
		_mlstListbox = (CEGUI::Listbox*)CEGUI::WindowManager::getSingleton().getWindow((CEGUI::utf8*)"Root/List/Listbox");
		_mBtnLoad->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GuiApplication::handleLoad, this));
		_mBtnSave->subscribeEvent(CEGUI::PushButton::EventClicked, CEGUI::Event::Subscriber(&GuiApplication::handleSave, this));

		/****************************************************************************************************
		Step 1: Add the common file dialog window to the main window
		        Calling CommonFileDialog::getSingleton() instantiates the common file dialog
		*****************************************************************************************************/
		mainWindow = CEGUI::WindowManager::getSingleton().getWindow((CEGUI::utf8*)"Root");
		mainWindow->addChildWindow(CEGUI::CommonFileDialog::getSingleton().getWindow());

		/****************************************************************************************************
		Step 2: Register the function that must be called in case the common file dialog has been closed by:
		        - the Ok button
				- the Cancel button
				- the Window close button ('X')
				Use the FrameWindow::EventHidden event
		*****************************************************************************************************/
		CEGUI::CommonFileDialog::getSingleton().getWindow()->subscribeEvent (CEGUI::FrameWindow::EventHidden, CEGUI::Event::Subscriber(&GuiApplication::handleFileDialogOutput, this));
    }

	bool handleLoad(const CEGUI::EventArgs& e)
	{
		/****************************************************************************************************
		Step 3a: Call the file dialog with the input data
		*****************************************************************************************************/
		CEGUI::CommonFileDialogInput input;
		input.setHandle (1);										// Set the handle to determine the originator
		input.setFilter ("Archive (*.zip)|*.zip|All files|*.*|");	// Extensions
		input.setOpenFileDialog (true);								// Load mode
		input.setDefaultExtension ("*.zip");						// Zip is the first one to display
		CEGUI::CommonFileDialog::getSingleton().openDialog(input);	// Open the common file dialog
		return true;
	}

	bool handleSave(const CEGUI::EventArgs& e)
	{
		/****************************************************************************************************
		Step 3b: Call the file dialog with the input data
		*****************************************************************************************************/
		CEGUI::CommonFileDialogInput input;
		input.setHandle (2);										// Set the handle to determine the originator
		input.setFilter ("JPEG (*.jpg)|*.jpg|Portable Network Graphics (*.png)|*.png|Truevision Targa (*.tga)|*.tga|");
		input.setOpenFileDialog (false);							// Save mode
		input.setDefaultExtension ("*.png");						// .png is the preferred extension
		input.setFileName ("test.png");								// Set default filename
		CEGUI::CommonFileDialog::getSingleton().openDialog(input);	// Open the common file dialog
		return true;
	}

	bool handleFileDialogOutput(const CEGUI::EventArgs& e)
	{
		/****************************************************************************************************
		Step 4: Handle the returned output
		*****************************************************************************************************/
		CEGUI::CommonFileDialogOutput result = CEGUI::CommonFileDialog::getSingleton().getResult();
		switch (result.getHandle())
		{
			case 1:
				_mlstListbox->addItem(new CEGUI::ListboxTextItem ((CEGUI::utf8*)"Load button pressed"));
			break;

			case 2:
				_mlstListbox->addItem(new CEGUI::ListboxTextItem ((CEGUI::utf8*)"Save button pressed"));
			break;
		}
		
		switch (result.getAction())
		{
			case CEGUI::ACTION_OK:
				_mlstListbox->addItem(new CEGUI::ListboxTextItem ((CEGUI::utf8*)"Returned with ACTION_OK"));
			break;

			case CEGUI::ACTION_CANCEL:
				_mlstListbox->addItem(new CEGUI::ListboxTextItem ((CEGUI::utf8*)"Returned with ACTION_CANCEL"));
			break;

			case CEGUI::ACTION_WINDOW_CLOSED:
				_mlstListbox->addItem(new CEGUI::ListboxTextItem ((CEGUI::utf8*)"Returned with ACTION_WINDOW_CLOSED"));
			break;
		}
		_mlstListbox->addItem(new CEGUI::ListboxTextItem ((CEGUI::utf8*)"Drive: " + result.getDrive()));
		_mlstListbox->addItem(new CEGUI::ListboxTextItem ((CEGUI::utf8*)"Full qualified name: " + result.getFullQualifiedFileName()));
		_mlstListbox->addItem(new CEGUI::ListboxTextItem ((CEGUI::utf8*)"Absolute path: " + result.getAbsolutePath()));
		_mlstListbox->addItem(new CEGUI::ListboxTextItem ((CEGUI::utf8*)"Relative path: " + result.getRelativePath()));
		_mlstListbox->addItem(new CEGUI::ListboxTextItem ((CEGUI::utf8*)"Filename: " + result.getFileName()));
		String fileExists = result.isFileExisting()? "TRUE" : "FALSE";
		_mlstListbox->addItem(new CEGUI::ListboxTextItem ((CEGUI::utf8*)fileExists.c_str()));
		_mlstListbox->addItem(new CEGUI::ListboxTextItem ((CEGUI::utf8*)"-------------------------------------------------------------------------------"));
		return true;
	}

    // Create new frame listener
    void createFrameListener(void)
    {
        mFrameListener = new GuiFrameListener(mWindow, mCamera, mGUIRenderer);
        mRoot->addFrameListener(mFrameListener);
    }
};

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"

INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
int main(int argc, char *argv[])
#endif
{

    // Create application object
    GuiApplication app;

    try {
        app.go();
    } catch( Ogre::Exception& e ) {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
        MessageBox( NULL, e.getFullDescription().c_str(), "An exception has occured!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
        std::cerr << "An exception has occured: " <<
            e.getFullDescription().c_str() << std::endl;
#endif
    }


    return 0;
}
