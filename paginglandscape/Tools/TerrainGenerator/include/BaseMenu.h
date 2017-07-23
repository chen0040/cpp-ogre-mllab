#pragma once

// OGRE
#include "Ogre.h"
// MAPSPLITTER
#include "MapUtil.h"
// NATIVE/MANAGED
#include "Marshalling.h"
// WINDOW FORMS
#include "GenWindow.h"
#include "MapSplitterWindow.h"
#include "RuntimeWindow.h"
#include "TerrainViewerWindow.h"

namespace TerrainGenerator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BaseMenu
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class BaseMenu : public System::Windows::Forms::Form
	{
	public:
		BaseMenu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			CenterToScreen();

			// Create Mapsplitter object
			mMapUtil = new Ogre::MapUtil();
			// Creates OGRE root and sets up defined resource locations
			mMapUtil->init();

			// Create windows
			mGenWindow = gcnew GenWindow();
			this->AddOwnedForm(mGenWindow);

			mMapSplitterWindow = gcnew MapSplitterWindow(mMapUtil);
			this->AddOwnedForm(mMapSplitterWindow);

			mRuntimeWindow = gcnew RuntimeWindow(mMapUtil);
			this->AddOwnedForm(mRuntimeWindow);

			mTerrainViewerWindow = gcnew TerrainViewerWindow();
			this->AddOwnedForm(mTerrainViewerWindow);

			// Set defaults
			setToolDefaults();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BaseMenu()
		{
			if (components)
			{
				delete components;
			}

			delete mMapUtil;
		}

		System::Void createAndAddFolder( System::String^ FolderPath )
		{
			Ogre::ResourceGroupManager* rgm = Ogre::ResourceGroupManager::getSingletonPtr();

			// Make sure output folder exists!
			if( !System::IO::Directory::Exists(FolderPath) )
			{
				// If directory does not exist, create it!
				System::IO::Directory::CreateDirectory(FolderPath);
			}

			// Add output folder to resource path, to use produced gen and runtime cfg files
			DECLARE_OGRE_STRING(folder,FolderPath);
			// removing a location that doesn't exist does nothing, so remove then add works well here
			rgm->removeResourceLocation(folder,"PLSM2");
			rgm->addResourceLocation(
				folder,
				"FileSystem",
				"PLSM2"
				);

		}

		System::Void	setToolDefaults()
		{
			//default values
			HeightMapFolder = ".";
			ColorMapFolder = ".";
			OutputFolder = ".";

			/*
			Code for loading and parsing file gotten from OgrePagingLandScapeOptions.cpp
			function PagingLandScapeOptions::load(...)
			*/

			std::ifstream fs;
			Ogre::String filename = "TerrainGenerator.cfg";
			fs.open(filename.c_str(), std::ios::in | std::ios::binary);

			/* Set up the options : List of map associated with map names.*/
			Ogre::ConfigFile config;

			if (fs)
			{
				// Wrap as a stream
				Ogre::DataStreamPtr stream(
					new Ogre::FileStreamDataStream(filename, &fs, false));
				config.load(stream);

				//get values from config file
				HeightMapFolder = setString ("HeightMapFolder",  config );
				ColorMapFolder = setString ("ColorMapFolder",  config );
				OutputFolder = setString ("OutputFolder",  config );
			}
			else
			{
				try
				{
					// otherwise try resource system
					Ogre::DataStreamPtr stream = 
						Ogre::ResourceGroupManager::getSingleton().openResource(filename);
					config.load(stream);

					//get values from config file
					// get complete folder path
					HeightMapFolder = setFolderPathString ("HeightMapFolder",  config );
					ColorMapFolder = setFolderPathString ("ColorMapFolder",  config );
					OutputFolder= setFolderPathString ("OutputFolder",  config );
				}
				// If there is no file at all, just use current directory
				catch(...) {}
			}

			HeightMapFolder = HeightMapFolder->Replace("/", "\\");
			ColorMapFolder = ColorMapFolder->Replace("/", "\\");
			OutputFolder = OutputFolder->Replace("/", "\\");

			HeightMapFolder = Environment::CurrentDirectory->Replace("\\", "\\") + "\\" + HeightMapFolder + "\\";
			ColorMapFolder = Environment::CurrentDirectory->Replace("\\", "\\") + "\\" + ColorMapFolder + "\\";
			OutputFolder = Environment::CurrentDirectory->Replace("\\", "\\") + "\\" + OutputFolder + "\\";

			// update Other windows Input/Output Folders
			mGenWindow->setHeightMapFolder(HeightMapFolder);
			mGenWindow->setColorMapFolder(ColorMapFolder);
			mGenWindow->setOutputFolder(OutputFolder);

			mMapSplitterWindow->setOutputFolder(OutputFolder);

			mRuntimeWindow->setOutputFolder(OutputFolder);

			mTerrainViewerWindow->setOutputFolder(OutputFolder);

			createAndAddFolder(HeightMapFolder);
			createAndAddFolder(ColorMapFolder);
			createAndAddFolder(OutputFolder);
		}

		System::String^ setString (const Ogre::String &ValuetoGet,  Ogre::ConfigFile &conf )
		{
			const Ogre::String val = conf.getSetting (ValuetoGet);
			if (!val.empty())
			{
				return gcnew System::String((val).c_str());
			}
			return gcnew System::String("");
		}
	    
		System::String^ setFolderPathString (const Ogre::String &ValuetoGet,  Ogre::ConfigFile &conf)
		{
			const Ogre::String FolderPath = conf.getSetting (ValuetoGet);
			if (!FolderPath.empty())
			{
				Ogre::String OutDirectory (FolderPath);

				Ogre::String BasePath, FilePath;
				Ogre::StringUtil::splitFilename(OutDirectory, BasePath, FilePath);
				if (FilePath.empty())
				{
					//Get cfg current Directory
					Ogre::FileInfoListPtr finfo =  Ogre::ResourceGroupManager::getSingleton().findResourceFileInfo (
						"PLSM2",  "TerrainGenerator.cfg");
					Ogre::FileInfoList::iterator it = finfo->begin();
					if (it != finfo->end())
					{
						FilePath = (it)->archive->getName();
					}
				}
				if (Ogre::StringUtil::endsWith  (FilePath, "/", true))
				{
					FilePath.resize (FilePath.size() - 1);
				}
				OutDirectory = FilePath + "/" +  BasePath; 

				return gcnew System::String((OutDirectory).c_str());//TO_CLR_STRING(OutDirectory);
			}
			return gcnew System::String("");
		}

	protected:
		Ogre::MapUtil *mMapUtil;

		// Tool settings set when parsing TerrainGenerator.cfg file
        System::String^	HeightMapFolder;
        System::String^	ColorMapFolder;
        System::String^	OutputFolder;

		GenWindow^ mGenWindow;
		RuntimeWindow^ mRuntimeWindow;
		MapSplitterWindow^ mMapSplitterWindow;
		TerrainViewerWindow^ mTerrainViewerWindow;

	private: System::Windows::Forms::Button^  GenButton;
	private: System::Windows::Forms::Button^  MapsplitterButton;
	private: System::Windows::Forms::Button^  RuntimeButton;
	private: System::Windows::Forms::Button^  ViewerButton;
	private: System::Windows::Forms::Button^  ExitButton;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  propertiesToolStripMenuItem;

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
			this->GenButton = (gcnew System::Windows::Forms::Button());
			this->MapsplitterButton = (gcnew System::Windows::Forms::Button());
			this->RuntimeButton = (gcnew System::Windows::Forms::Button());
			this->ViewerButton = (gcnew System::Windows::Forms::Button());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->propertiesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// GenButton
			// 
			this->GenButton->Location = System::Drawing::Point(13, 27);
			this->GenButton->Name = L"GenButton";
			this->GenButton->Size = System::Drawing::Size(267, 23);
			this->GenButton->TabIndex = 0;
			this->GenButton->Text = L"Create Terrain Gen File";
			this->GenButton->UseVisualStyleBackColor = true;
			this->GenButton->Click += gcnew System::EventHandler(this, &BaseMenu::GenButton_Click);
			// 
			// MapsplitterButton
			// 
			this->MapsplitterButton->Location = System::Drawing::Point(13, 56);
			this->MapsplitterButton->Name = L"MapsplitterButton";
			this->MapsplitterButton->Size = System::Drawing::Size(267, 23);
			this->MapsplitterButton->TabIndex = 1;
			this->MapsplitterButton->Text = L"Run Mapsplitter";
			this->MapsplitterButton->UseVisualStyleBackColor = true;
			this->MapsplitterButton->Click += gcnew System::EventHandler(this, &BaseMenu::MapsplitterButton_Click);
			// 
			// RuntimeButton
			// 
			this->RuntimeButton->Location = System::Drawing::Point(13, 85);
			this->RuntimeButton->Name = L"RuntimeButton";
			this->RuntimeButton->Size = System::Drawing::Size(267, 23);
			this->RuntimeButton->TabIndex = 2;
			this->RuntimeButton->Text = L"Create Terrain Runtime File";
			this->RuntimeButton->UseVisualStyleBackColor = true;
			this->RuntimeButton->Click += gcnew System::EventHandler(this, &BaseMenu::RuntimeButton_Click);
			// 
			// ViewerButton
			// 
			this->ViewerButton->Location = System::Drawing::Point(13, 114);
			this->ViewerButton->Name = L"ViewerButton";
			this->ViewerButton->Size = System::Drawing::Size(267, 23);
			this->ViewerButton->TabIndex = 3;
			this->ViewerButton->Text = L"Terrain Viewer";
			this->ViewerButton->UseVisualStyleBackColor = true;
			this->ViewerButton->Click += gcnew System::EventHandler(this, &BaseMenu::ViewerButton_Click);
			// 
			// ExitButton
			// 
			this->ExitButton->Location = System::Drawing::Point(12, 173);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(267, 23);
			this->ExitButton->TabIndex = 4;
			this->ExitButton->Text = L"Exit";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &BaseMenu::ExitButton_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->fileToolStripMenuItem, 
				this->toolToolStripMenuItem, this->helpToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(292, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &BaseMenu::exitToolStripMenuItem_Click);
			// 
			// toolToolStripMenuItem
			// 
			this->toolToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->propertiesToolStripMenuItem});
			this->toolToolStripMenuItem->Name = L"toolToolStripMenuItem";
			this->toolToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->toolToolStripMenuItem->Text = L"Tool";
			// 
			// propertiesToolStripMenuItem
			// 
			this->propertiesToolStripMenuItem->Name = L"propertiesToolStripMenuItem";
			this->propertiesToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->propertiesToolStripMenuItem->Text = L"Properties";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->aboutToolStripMenuItem});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(40, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(203, 22);
			this->aboutToolStripMenuItem->Text = L"About Terrain Generator";
			// 
			// BaseMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 208);
			this->ControlBox = false;
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->ViewerButton);
			this->Controls->Add(this->RuntimeButton);
			this->Controls->Add(this->MapsplitterButton);
			this->Controls->Add(this->GenButton);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"BaseMenu";
			this->Text = L"Terrain Generator - Main Menu";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void ExitButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			Close();
		}
		System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			Close();
		}
		System::Void GenButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			mGenWindow->show();
		}
		System::Void RuntimeButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			mRuntimeWindow->show();
		}
		System::Void MapsplitterButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			mMapSplitterWindow->show();
		}
		System::Void ViewerButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			mTerrainViewerWindow->show();
		}
};
}

