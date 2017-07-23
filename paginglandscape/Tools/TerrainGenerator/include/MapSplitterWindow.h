#pragma once

// OGRE
#include "Ogre.h"
// MAPSPLITTER
#include "MapUtil.h"
// NATIVE/MANAGED
#include "Marshalling.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace TerrainGenerator {

	/// <summary>
	/// Summary for MapSplitterWindow
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class MapSplitterWindow : public System::Windows::Forms::Form
	{
	public:
		MapSplitterWindow( Ogre::MapUtil* mapUtil )
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			CenterToScreen();

			mMapUtil = mapUtil;
		}

		System::Void	setOutputFolder( System::String^ OutputFolder )
		{
			mOutputFolder = OutputFolder;
			OutputFolderTextBox->Text = mOutputFolder + "<TerrainName>";
		}

		System::Void	show()
		{
			CenterToScreen();
			Show();
		}

		/*System::Void	updateOutputPath( System::String^ OutputFolder )
		{
			mOutputFolder = OutputFolder;
			OutputFolderTextBox->Text = mOutputFolder + "<TerrainName>";
		}*/

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MapSplitterWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 
		System::String^	mOutputFolder;

		Ogre::MapUtil*	mMapUtil;

	private: System::Windows::Forms::Button^  CloseWindowButton;
	private: System::Windows::Forms::TextBox^  StatusTextBox;
	private: System::Windows::Forms::GroupBox^  OutputGroupBox;
	private: System::Windows::Forms::TextBox^  OutputFolderTextBox;
	private: System::Windows::Forms::Label^  OutputFolderLabel;
	private: System::Windows::Forms::Label^  OutputLabel3;
	private: System::Windows::Forms::Label^  OutputLabel2;
	private: System::Windows::Forms::Label^  OutputLabel1;
	private: System::Windows::Forms::TextBox^  GTerrainNameTextBox;
	private: System::Windows::Forms::Label^  TerrainNameGLabel;
	private: System::Windows::Forms::GroupBox^  ImageInputGroupBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  GenLoadButton;
	private: System::Windows::Forms::Label^  GenLabel;
	private: System::Windows::Forms::GroupBox^  InfoGroupBox;
	private: System::Windows::Forms::Label^  InfoLabel2;
	private: System::Windows::Forms::Label^  InfoLabel1;
	private: System::Windows::Forms::Button^  RunButton;

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
			this->CloseWindowButton = (gcnew System::Windows::Forms::Button());
			this->StatusTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OutputGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->OutputFolderTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OutputFolderLabel = (gcnew System::Windows::Forms::Label());
			this->OutputLabel3 = (gcnew System::Windows::Forms::Label());
			this->OutputLabel2 = (gcnew System::Windows::Forms::Label());
			this->OutputLabel1 = (gcnew System::Windows::Forms::Label());
			this->GTerrainNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->TerrainNameGLabel = (gcnew System::Windows::Forms::Label());
			this->ImageInputGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->GenLoadButton = (gcnew System::Windows::Forms::Button());
			this->GenLabel = (gcnew System::Windows::Forms::Label());
			this->InfoGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->InfoLabel2 = (gcnew System::Windows::Forms::Label());
			this->InfoLabel1 = (gcnew System::Windows::Forms::Label());
			this->RunButton = (gcnew System::Windows::Forms::Button());
			this->OutputGroupBox->SuspendLayout();
			this->ImageInputGroupBox->SuspendLayout();
			this->InfoGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// CloseWindowButton
			// 
			this->CloseWindowButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->CloseWindowButton->Location = System::Drawing::Point(287, 313);
			this->CloseWindowButton->Name = L"CloseWindowButton";
			this->CloseWindowButton->Size = System::Drawing::Size(231, 23);
			this->CloseWindowButton->TabIndex = 0;
			this->CloseWindowButton->Text = L"Close Window";
			this->CloseWindowButton->UseVisualStyleBackColor = true;
			this->CloseWindowButton->Click += gcnew System::EventHandler(this, &MapSplitterWindow::CloseWindowButton_Click);
			// 
			// StatusTextBox
			// 
			this->StatusTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->StatusTextBox->Location = System::Drawing::Point(-4, 342);
			this->StatusTextBox->Name = L"StatusTextBox";
			this->StatusTextBox->ReadOnly = true;
			this->StatusTextBox->Size = System::Drawing::Size(538, 20);
			this->StatusTextBox->TabIndex = 20;
			// 
			// OutputGroupBox
			// 
			this->OutputGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->OutputGroupBox->Controls->Add(this->OutputFolderTextBox);
			this->OutputGroupBox->Controls->Add(this->OutputFolderLabel);
			this->OutputGroupBox->Controls->Add(this->OutputLabel3);
			this->OutputGroupBox->Controls->Add(this->OutputLabel2);
			this->OutputGroupBox->Controls->Add(this->OutputLabel1);
			this->OutputGroupBox->Controls->Add(this->GTerrainNameTextBox);
			this->OutputGroupBox->Controls->Add(this->TerrainNameGLabel);
			this->OutputGroupBox->Location = System::Drawing::Point(12, 174);
			this->OutputGroupBox->Name = L"OutputGroupBox";
			this->OutputGroupBox->Size = System::Drawing::Size(506, 133);
			this->OutputGroupBox->TabIndex = 19;
			this->OutputGroupBox->TabStop = false;
			this->OutputGroupBox->Text = L"Output";
			// 
			// OutputFolderTextBox
			// 
			this->OutputFolderTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->OutputFolderTextBox->Location = System::Drawing::Point(95, 102);
			this->OutputFolderTextBox->Margin = System::Windows::Forms::Padding(2);
			this->OutputFolderTextBox->Name = L"OutputFolderTextBox";
			this->OutputFolderTextBox->ReadOnly = true;
			this->OutputFolderTextBox->Size = System::Drawing::Size(405, 20);
			this->OutputFolderTextBox->TabIndex = 161;
			this->OutputFolderTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// OutputFolderLabel
			// 
			this->OutputFolderLabel->AutoSize = true;
			this->OutputFolderLabel->Location = System::Drawing::Point(16, 105);
			this->OutputFolderLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->OutputFolderLabel->Name = L"OutputFolderLabel";
			this->OutputFolderLabel->Size = System::Drawing::Size(74, 13);
			this->OutputFolderLabel->TabIndex = 160;
			this->OutputFolderLabel->Text = L"Output Folder:";
			// 
			// OutputLabel3
			// 
			this->OutputLabel3->AutoSize = true;
			this->OutputLabel3->Location = System::Drawing::Point(17, 51);
			this->OutputLabel3->Name = L"OutputLabel3";
			this->OutputLabel3->Size = System::Drawing::Size(356, 13);
			this->OutputLabel3->TabIndex = 159;
			this->OutputLabel3->Text = L"The Output folder can also be configured via the TerrainGenerator.cfg file.";
			// 
			// OutputLabel2
			// 
			this->OutputLabel2->AutoSize = true;
			this->OutputLabel2->Location = System::Drawing::Point(16, 38);
			this->OutputLabel2->Name = L"OutputLabel2";
			this->OutputLabel2->Size = System::Drawing::Size(373, 13);
			this->OutputLabel2->TabIndex = 158;
			this->OutputLabel2->Text = L"The Output folder can be configured via Tools->Properties on the Main Menu.";
			// 
			// OutputLabel1
			// 
			this->OutputLabel1->AutoSize = true;
			this->OutputLabel1->Location = System::Drawing::Point(16, 25);
			this->OutputLabel1->Name = L"OutputLabel1";
			this->OutputLabel1->Size = System::Drawing::Size(430, 13);
			this->OutputLabel1->TabIndex = 2;
			this->OutputLabel1->Text = L"The resulting images will be created in a folder called <Terrain Name> in the Out" 
				L"put folder.";
			// 
			// GTerrainNameTextBox
			// 
			this->GTerrainNameTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GTerrainNameTextBox->Location = System::Drawing::Point(95, 78);
			this->GTerrainNameTextBox->Margin = System::Windows::Forms::Padding(2);
			this->GTerrainNameTextBox->Name = L"GTerrainNameTextBox";
			this->GTerrainNameTextBox->ReadOnly = true;
			this->GTerrainNameTextBox->Size = System::Drawing::Size(405, 20);
			this->GTerrainNameTextBox->TabIndex = 157;
			this->GTerrainNameTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// TerrainNameGLabel
			// 
			this->TerrainNameGLabel->AutoSize = true;
			this->TerrainNameGLabel->Location = System::Drawing::Point(16, 81);
			this->TerrainNameGLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->TerrainNameGLabel->Name = L"TerrainNameGLabel";
			this->TerrainNameGLabel->Size = System::Drawing::Size(74, 13);
			this->TerrainNameGLabel->TabIndex = 156;
			this->TerrainNameGLabel->Text = L"Terrain Name:";
			// 
			// ImageInputGroupBox
			// 
			this->ImageInputGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->ImageInputGroupBox->Controls->Add(this->label1);
			this->ImageInputGroupBox->Controls->Add(this->GenLoadButton);
			this->ImageInputGroupBox->Controls->Add(this->GenLabel);
			this->ImageInputGroupBox->Location = System::Drawing::Point(12, 85);
			this->ImageInputGroupBox->Name = L"ImageInputGroupBox";
			this->ImageInputGroupBox->Size = System::Drawing::Size(506, 82);
			this->ImageInputGroupBox->TabIndex = 18;
			this->ImageInputGroupBox->TabStop = false;
			this->ImageInputGroupBox->Text = L"Gen Input";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(320, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Make sure the images and Gen file are in an OGRE resource path.";
			// 
			// GenLoadButton
			// 
			this->GenLoadButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GenLoadButton->Location = System::Drawing::Point(82, 48);
			this->GenLoadButton->Margin = System::Windows::Forms::Padding(2);
			this->GenLoadButton->Name = L"GenLoadButton";
			this->GenLoadButton->Size = System::Drawing::Size(418, 19);
			this->GenLoadButton->TabIndex = 163;
			this->GenLoadButton->Text = L"Load Gen File";
			this->GenLoadButton->UseVisualStyleBackColor = true;
			this->GenLoadButton->Click += gcnew System::EventHandler(this, &MapSplitterWindow::GenLoadButton_Click);
			// 
			// GenLabel
			// 
			this->GenLabel->AutoSize = true;
			this->GenLabel->Location = System::Drawing::Point(16, 51);
			this->GenLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GenLabel->Name = L"GenLabel";
			this->GenLabel->Size = System::Drawing::Size(49, 13);
			this->GenLabel->TabIndex = 165;
			this->GenLabel->Text = L"Gen File:";
			// 
			// InfoGroupBox
			// 
			this->InfoGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->InfoGroupBox->Controls->Add(this->InfoLabel2);
			this->InfoGroupBox->Controls->Add(this->InfoLabel1);
			this->InfoGroupBox->Location = System::Drawing::Point(12, 12);
			this->InfoGroupBox->Name = L"InfoGroupBox";
			this->InfoGroupBox->Size = System::Drawing::Size(506, 66);
			this->InfoGroupBox->TabIndex = 17;
			this->InfoGroupBox->TabStop = false;
			this->InfoGroupBox->Text = L"Info";
			// 
			// InfoLabel2
			// 
			this->InfoLabel2->AutoSize = true;
			this->InfoLabel2->Location = System::Drawing::Point(16, 37);
			this->InfoLabel2->Name = L"InfoLabel2";
			this->InfoLabel2->Size = System::Drawing::Size(484, 13);
			this->InfoLabel2->TabIndex = 1;
			this->InfoLabel2->Text = L"Images produced from MapSplitter are used with a Runtime configuration file to lo" 
				L"ad terrain via PLSM.";
			// 
			// InfoLabel1
			// 
			this->InfoLabel1->AutoSize = true;
			this->InfoLabel1->Location = System::Drawing::Point(16, 24);
			this->InfoLabel1->Name = L"InfoLabel1";
			this->InfoLabel1->Size = System::Drawing::Size(298, 13);
			this->InfoLabel1->TabIndex = 0;
			this->InfoLabel1->Text = L"MapSplitter uses a terrain Gen file to process and split images.";
			// 
			// RunButton
			// 
			this->RunButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->RunButton->Location = System::Drawing::Point(12, 313);
			this->RunButton->Name = L"RunButton";
			this->RunButton->Size = System::Drawing::Size(231, 23);
			this->RunButton->TabIndex = 21;
			this->RunButton->Text = L"Run Mapsplitter!";
			this->RunButton->UseVisualStyleBackColor = true;
			this->RunButton->Click += gcnew System::EventHandler(this, &MapSplitterWindow::RunButton_Click);
			// 
			// MapSplitterWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(530, 360);
			this->ControlBox = false;
			this->Controls->Add(this->RunButton);
			this->Controls->Add(this->StatusTextBox);
			this->Controls->Add(this->OutputGroupBox);
			this->Controls->Add(this->ImageInputGroupBox);
			this->Controls->Add(this->InfoGroupBox);
			this->Controls->Add(this->CloseWindowButton);
			this->Name = L"MapSplitterWindow";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"MapSplitterWindow";
			this->OutputGroupBox->ResumeLayout(false);
			this->OutputGroupBox->PerformLayout();
			this->ImageInputGroupBox->ResumeLayout(false);
			this->ImageInputGroupBox->PerformLayout();
			this->InfoGroupBox->ResumeLayout(false);
			this->InfoGroupBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void CloseWindowButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			Hide();
		}
		System::Void GenLoadButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			// backup of current working directory, which is restored
			System::String^ backupCurrentDir = Environment::CurrentDirectory;

			// find files of supported type: .png, .raw
			OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
			openFileDialog1->InitialDirectory = mOutputFolder;
			openFileDialog1->Filter = "Terrain GEN files (*.cfg)|*.cfg";
			openFileDialog1->Title = "Load Gen File";
			openFileDialog1->ShowDialog();    
			openFileDialog1->RestoreDirectory = true;

			if(openFileDialog1->FileName != "")
			{
				// I'm not sure why, but opening the file changes the current working directory!
				// This caused 2 hours of pain! The Current Directory MUST be restored for OGRE
				// to use its resources properly!
				Environment::CurrentDirectory = backupCurrentDir;

				System::String^ Temp = openFileDialog1->FileName;
				Temp = Temp->Substring(Temp->LastIndexOf("\\")+1);
				GTerrainNameTextBox->Text = Temp->Substring(0,Temp->IndexOf('.'));
			}
			else Environment::CurrentDirectory = backupCurrentDir;
		}
		System::Void RunButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if( GTerrainNameTextBox->Text == "" ) return;

			StatusTextBox->Text = "Running...";
			StatusTextBox->Refresh();

			// Run Mapsplitter
			mMapUtil->LoadSingleMap(Ogre::String((char*) Marshal::StringToHGlobalAnsi(mOutputFolder + GTerrainNameTextBox->Text).ToPointer()) + ".gen.cfg", "PLSM2");
			mMapUtil->process();

			StatusTextBox->Text = "Done";

			GTerrainNameTextBox->Text = "";
		}
};
}
