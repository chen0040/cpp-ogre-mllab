#pragma once

#include "Ogre.h"
#include "Marshalling.h"
#include "FrameListener.h"


using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace TerrainGenerator {

	/// <summary>
	/// Summary for TerrainViewerWindow
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class TerrainViewerWindow : public System::Windows::Forms::Form, public IFrameListener
	{
	public:
		TerrainViewerWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			CenterToScreen();

			RenderPanel->SendToBack();

			// Initialize variables
			mKeepRendering = false;
			mWKey = mAKey = mSKey = mDKey = mEKey = mCKey = mUArrow = mDArrow = mLArrow = mRArrow = false;
			mCamMoveSpeed = 1000.0;

			initializeRenderer();
			setupRenderPanel();

			mProxy = new FrameListener_Proxy(this);
			//proxy is the bridge between the native FrameListener and BaseForm
			mRoot->addFrameListener(mProxy);

			// Load resources 
			Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
/* ------------------ IMPORTANT --------------------------------------- */
			// Create a Ninja to show Tuan the app is rendering, and to encourage him to help me finish this app off
			Ogre::Entity* e = mSceneManager->createEntity("RemoveMeWhenTerrainsCanLoad","ninja.mesh");
			mSceneManager->getRootSceneNode()->createChildSceneNode()->attachObject(e);
/* ------------------ IMPORTANT --------------------------------------- */
		}

		virtual bool FrameStarted( ::FrameEvent^ evt )
		{
			handleCameraMovement( evt->timeSinceLastFrame );

			return true;
		}

		virtual bool FrameEnded( ::FrameEvent^ evt )
		{
		   return true;
		}

		System::Void	setOutputFolder( System::String^ OutputFolder )
		{
			mOutputFolder = OutputFolder;
		}

		System::Void	show()
		{
			// Enable All/Most key events should be sent to Base Form Handlers
			KeyPreview = true;

			// Add all subdirectories found in Output Folder to resource path (remove then add)

			mCamYawNode->setPosition(0,0,100);

			Show();

			startRendering();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TerrainViewerWindow()
		{
			if (components)
			{
				delete components;
			}
		}

		System::Void	initializeRenderer()
		{
			// Root was setup by MapUtil->Init function, so we should just get a pointer to it
			mRoot = Ogre::Root::getSingletonPtr();

			Ogre::RenderSystem * renderSystem;

			// initialize the direct3d 9 rendering system
			Ogre::String renderSystemName = "Direct3D9 Rendering Subsystem"; 

			// loop through all the available rendering systems until we find the one with the name we want
			for( Ogre::RenderSystemList::iterator renderSystemsIterator = mRoot->getAvailableRenderers()->begin(); renderSystemsIterator != mRoot->getAvailableRenderers()->end(); ++renderSystemsIterator )
			{
				// check if the current rendering system has the name of the one we want
				if( renderSystemName ==  (*renderSystemsIterator)->getName())
				{
					// if so copy it over
					renderSystem = *renderSystemsIterator;
					
					// tell the root node that this is now our rendering system
					mRoot->setRenderSystem( renderSystem );

					// leave the for loop
					break;
				}
			}

			// set rendering device to first auto detected device
			Ogre::ConfigOptionMap& CurrentRendererOptions = renderSystem->getConfigOptions();
			Ogre::ConfigOptionMap::iterator configItr = CurrentRendererOptions.begin();

			while( configItr != CurrentRendererOptions.end() ) 
			{
				if( (configItr)->first == "Rendering Device" ) 
				{
					renderSystem->setConfigOption( "Rendering Device", (*((configItr)->second.possibleValues).begin()) );
					break;
				}
				configItr++;
			}

			// hard-code parameters on the rendering system
			{
				renderSystem->setConfigOption( "Allow NVPerfHUD", "No" );
				renderSystem->setConfigOption( "Anti aliasing", "None" ); 
				renderSystem->setConfigOption( "Floating-point mode", "Fastest" ); 
				renderSystem->setConfigOption( "Full Screen", "No" ); 
				renderSystem->setConfigOption( "VSync", "No" ); 
				renderSystem->setConfigOption( "Video Mode", "800 x 600 @ 32-bit colour" ); 
				renderSystem->validateConfigOptions(); 
			}

			// start the render system, but don't create a window for us
			mRoot->initialise(false);
		}

		void handleCameraMovement( Ogre::Real time )
		{
			const Ogre::Quaternion q = mCamPitchNode->_getDerivedOrientation();
			double Distance = mCamMoveSpeed * time;

			if( mWKey ) mCamYawNode->translate( q * Ogre::Vector3::NEGATIVE_UNIT_Z * Distance );
			if( mSKey ) mCamYawNode->translate( q * Ogre::Vector3::UNIT_Z * Distance );
			if( mAKey ) mCamYawNode->translate( q * Ogre::Vector3::NEGATIVE_UNIT_X * Distance );
			if( mDKey ) mCamYawNode->translate( q * Ogre::Vector3::UNIT_X * Distance );
			if( mEKey ) mCamYawNode->translate( q * Ogre::Vector3::UNIT_Y * Distance );
			if( mCKey ) mCamYawNode->translate( q * Ogre::Vector3::NEGATIVE_UNIT_Y * Distance );
			if( mUArrow ) mCamYawNode->translate( q * Ogre::Vector3::NEGATIVE_UNIT_Z * Distance );
			if( mDArrow ) mCamYawNode->translate( q * Ogre::Vector3::UNIT_Z * Distance );
			if( mLArrow ) mCamYawNode->translate( q * Ogre::Vector3::NEGATIVE_UNIT_X * Distance );
			if( mRArrow ) mCamYawNode->translate( q * Ogre::Vector3::UNIT_X * Distance );
		}

		System::Void	setupRenderPanel()
		{
			// Setup main RenderPanel
			Ogre::NameValuePairList list2;
			DECLARE_OGRE_STRING(RenderPanelHandleStr, this->RenderPanel->Handle.ToString()) 
			list2["externalWindowHandle"] = RenderPanelHandleStr; 
			mRenderWindow = mRoot->createRenderWindow("SceneRenderer", 800, 600, false, &list2); 

			// PLSM
			mSceneManager = mRoot->createSceneManager(Ogre::ST_EXTERIOR_REAL_FAR,"TerrainViewerSceneManager");
			// This function creates all the various managers behind PLSM2, so this call is required
			mSceneManager->setWorldGeometry("");
			// TSM
			//mSceneManager = mRoot->createSceneManager(Ogre::ST_EXTERIOR_CLOSE,"SceneCreatorSceneManager");

			// Setup camera to be used in application
			mCamera = mSceneManager->createCamera("TerrainViewerCamera");
			mCamera->setAutoAspectRatio(true);
			mCamYawNode = mSceneManager->getRootSceneNode()->createChildSceneNode("CamYawNode");
			mCamPitchNode = mCamYawNode->createChildSceneNode("CamPitchNode");
			mCamPitchNode->attachObject(mCamera);

            mSceneManager->setAmbientLight( Ogre::ColourValue (0.7f, 0.7f, 0.7f));//g_DayColor );

			Ogre::Viewport* v = mRenderWindow->addViewport(mCamera);
			v->setBackgroundColour(Ogre::ColourValue(0,0,0,1.0));
		}

		System::Void startRendering()
		{
			// safety check, in case startRendering is called more then once
			if(mKeepRendering) return;

			this->Focus();

			mKeepRendering = true;
			while(mKeepRendering)
			{
				// render the frame
				mRoot->renderOneFrame();

				// update render panels
				mRenderWindow->update();

				// Allow the form to process events
				System::Windows::Forms::Application::DoEvents();
			}
		}

	protected: 
		System::String^ mOutputFolder;

		Ogre::Root*				mRoot;
		FrameListener_Proxy*	mProxy;
		bool					mKeepRendering;

		Ogre::RenderWindow*		mRenderWindow;

		Ogre::SceneManager*		mSceneManager;

		// Camera System
		Ogre::Camera*			mCamera;
		Ogre::SceneNode*		mCamYawNode;
		Ogre::SceneNode*		mCamPitchNode;
		double					mCamMoveSpeed;
		// Input
		bool					mWKey;
		bool					mSKey;
		bool					mAKey;
		bool					mDKey;
		bool					mEKey;
		bool					mCKey;
		bool					mUArrow;
		bool					mDArrow;
		bool					mLArrow;
		bool					mRArrow;

		bool					mMouseRightDown;
		int						mXRef;
		int						mYRef;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadTerrainToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  closeToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  StatusTextBox;
	private: System::Windows::Forms::Panel^  RenderPanel;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadTerrainToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->StatusTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RenderPanel = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(792, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->loadTerrainToolStripMenuItem, 
				this->closeToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadTerrainToolStripMenuItem
			// 
			this->loadTerrainToolStripMenuItem->Name = L"loadTerrainToolStripMenuItem";
			this->loadTerrainToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->loadTerrainToolStripMenuItem->Text = L"Load Terrain...";
			this->loadTerrainToolStripMenuItem->Click += gcnew System::EventHandler(this, &TerrainViewerWindow::loadTerrainToolStripMenuItem_Click);
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->closeToolStripMenuItem->Text = L"Close";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &TerrainViewerWindow::closeToolStripMenuItem_Click);
			// 
			// StatusTextBox
			// 
			this->StatusTextBox->Location = System::Drawing::Point(0, 546);
			this->StatusTextBox->Name = L"StatusTextBox";
			this->StatusTextBox->ReadOnly = true;
			this->StatusTextBox->Size = System::Drawing::Size(792, 20);
			this->StatusTextBox->TabIndex = 1;
			// 
			// RenderPanel
			// 
			this->RenderPanel->BackColor = System::Drawing::SystemColors::ControlText;
			this->RenderPanel->Location = System::Drawing::Point(-5, -25);
			this->RenderPanel->Name = L"RenderPanel";
			this->RenderPanel->Size = System::Drawing::Size(800, 600);
			this->RenderPanel->TabIndex = 2;
			this->RenderPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &TerrainViewerWindow::RenderPanel_MouseDown);
			this->RenderPanel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &TerrainViewerWindow::RenderPanel_MouseMove);
			this->RenderPanel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &TerrainViewerWindow::RenderPanel_MouseUp);
			// 
			// TerrainViewerWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(792, 566);
			this->ControlBox = false;
			this->Controls->Add(this->RenderPanel);
			this->Controls->Add(this->StatusTextBox);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"TerrainViewerWindow";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"Terrain Viewer";
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &TerrainViewerWindow::TerrainViewerWindow_KeyUp);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &TerrainViewerWindow::TerrainViewerWindow_KeyDown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void closeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			// Disable All/Most key events should be sent to Base Form Handlers
			KeyPreview = false;

			// clear terrain, but not scene, as camera uses scene nodes

			Hide();
		}
		System::Void loadTerrainToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			// backup of current working directory, which is restored
			System::String^ backupCurrentDir = Environment::CurrentDirectory;

			// find files of supported type: .png, .raw
			OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
			openFileDialog1->InitialDirectory = mOutputFolder;
			openFileDialog1->Filter = "Terrain Runtime files (*.cfg)|*.cfg";
			openFileDialog1->Title = "Load Terrain";
			openFileDialog1->ShowDialog();    
			openFileDialog1->RestoreDirectory = true;

			if(openFileDialog1->FileName != "")
			{
				// I'm not sure why, but opening the file changes the current working directory!
				// This caused 2 hours of pain! The Current Directory MUST be restored for OGRE
				// to use its resources properly!
				Environment::CurrentDirectory = backupCurrentDir;

				System::String^ FullPathAndFileName = openFileDialog1->FileName;
				System::String^ FileName = FullPathAndFileName->Substring(FullPathAndFileName->LastIndexOf("\\")+1);

				DECLARE_OGRE_STRING(CFGFile,FileName);
				// reset the world geometry
                Ogre::String cfgGroupName = "PLSM2";
                mSceneManager->setOption("ConfigGroupName", &cfgGroupName);

                // load the world geometry
                mSceneManager->clearScene();
				mSceneManager->setWorldGeometry(CFGFile);

                if (!mCamera)
			        mCamera = mSceneManager->createCamera("TerrainViewerCamera");

			    mCamera->setAutoAspectRatio(true);
			    mCamYawNode = mSceneManager->getRootSceneNode()->createChildSceneNode("CamYawNode");
			    mCamPitchNode = mCamYawNode->createChildSceneNode("CamPitchNode");
			    mCamPitchNode->attachObject(mCamera);

                mSceneManager->setAmbientLight( Ogre::ColourValue (0.7f, 0.7f, 0.7f));//g_DayColor );

			    Ogre::Viewport* v = mRenderWindow->addViewport(mCamera);
                v->setBackgroundColour(Ogre::ColourValue(0,0,0,1.0));


                Ogre::Vector3 cameraParams;
                mSceneManager->getOption ( "BaseCameraViewpoint", &cameraParams);
                mCamera->setPosition (cameraParams);
                mSceneManager->getOption ("Baselookat", &cameraParams);
                mCamera->lookAt (cameraParams);
                mSceneManager->setOption ("LoadNow", mCamera);

			} 
			else Environment::CurrentDirectory = backupCurrentDir;
		}
		System::Void RenderPanel_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
			if( e->Button == System::Windows::Forms::MouseButtons::Right )
			{
				mMouseRightDown = true;
			}

			mXRef = e->X;
			mYRef = e->Y;
		}
		System::Void RenderPanel_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
			if( mMouseRightDown )
			{
				mCamYawNode->yaw(Ogre::Radian((Ogre::Real)-0.005 * (Ogre::Real)(e->X - this->mXRef)));
				mCamPitchNode->pitch(Ogre::Radian((Ogre::Real)-0.005 * (Ogre::Real)(e->Y - this->mYRef)));
			}

			mXRef = e->X;
			mYRef = e->Y;
		}
		System::Void RenderPanel_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		{
			if( e->Button == System::Windows::Forms::MouseButtons::Right )
			{
				mMouseRightDown = false;
			}
		}
		System::Void TerrainViewerWindow_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
		{
			if( e->KeyCode == Keys::W )			mWKey = true;
			if( e->KeyCode == Keys::S )			mSKey = true;
			if( e->KeyCode == Keys::A )			mAKey = true;
			if( e->KeyCode == Keys::D )			mDKey = true;
			if( e->KeyCode == Keys::E )			mEKey = true;
			if( e->KeyCode == Keys::C )			mCKey = true;
			if( e->KeyCode == Keys::Up )		mUArrow = true;
			if( e->KeyCode == Keys::Down )		mDArrow = true;
			if( e->KeyCode == Keys::Left )		mLArrow = true;
			if( e->KeyCode == Keys::Right )		mRArrow = true;
		}
		System::Void TerrainViewerWindow_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
		{
			if( e->KeyCode == Keys::W )			mWKey = false;
			if( e->KeyCode == Keys::S )			mSKey = false;
			if( e->KeyCode == Keys::A )			mAKey = false;
			if( e->KeyCode == Keys::D )			mDKey = false;
			if( e->KeyCode == Keys::E )			mEKey = false;
			if( e->KeyCode == Keys::C )			mCKey = false;
			if( e->KeyCode == Keys::Up )		mUArrow = false;
			if( e->KeyCode == Keys::Down )		mDArrow = false;
			if( e->KeyCode == Keys::Left )		mLArrow = false;
			if( e->KeyCode == Keys::Right )		mRArrow = false;
		}
};
}
