#pragma once

// OGRE
#include "Ogre.h"
// MAPSPLITTER
#include "MapUtil.h"
// NATIVE/MANAGED
#include "Marshalling.h"

#include <vector>

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Diagnostics;
using namespace System::Drawing;


namespace TerrainGenerator {

	/// <summary>
	/// Summary for RuntimeWindow
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class RuntimeWindow : public System::Windows::Forms::Form
	{
	public:
		RuntimeWindow( Ogre::MapUtil* mapUtil )
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

		System::Void show()
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
		~RuntimeWindow()
		{
			if (components)
			{
				delete components;
			}
		}

		System::String^ createAssignment( System::Windows::Forms::Label^ l, System::Windows::Forms::TextBox^ t )
		{
			// turn the label's trailing ':' into '='
			System::String^ Label = l->Text;
			Label = Label->Substring(0,Label->IndexOf(':')) + "=";
			return Label + t->Text;
		}
		
		System::String^ createAssignment( System::Windows::Forms::Label^ l, System::Windows::Forms::ComboBox^ c )
		{
			// turn the label's trailing ':' into '='
			System::String^ Label = l->Text;
			Label = Label->Substring(0,Label->IndexOf(':')) + "=";
			return Label + c->Text;
		}

		System::String^ createAssignment( System::Windows::Forms::CheckBox^ c )
		{
			// turn the label's trailing ':' into '='
			System::String^ Label = c->Text;
			Label = Label->Substring(0,Label->IndexOf(':')) + "=";
			return Label + evaluateCheckBox(c);
		}

		System::String^	createComment( System::String^ text )
		{
			return "## " + text + " ##";
		}

		System::String^ evaluateCheckBox( System::Windows::Forms::CheckBox^ cb )
		{
			if( cb->Checked ) return "yes";
			else return "no";
		}
		
		System::Void writeRichTextBoxContents( System::IO::StreamWriter^ sw, System::Windows::Forms::RichTextBox^ rtb )
		{
			System::String^ FullText = rtb->Text;
			System::String^ Line;

			int index;
			while( FullText->Length >= 0 )
			{
				index = FullText->IndexOf('\n');
				if( index < 0 )
				{
					Line = FullText->Substring(0,FullText->Length);
					sw->WriteLine(Line);
					break;
				}
				else Line = FullText->Substring(0,FullText->IndexOf('\n'));

				FullText = FullText->Substring(FullText->IndexOf('\n') + 1);
				sw->WriteLine(Line);
			}

			sw->WriteLine("");
		}
	
	protected: 
		System::String^	mOutputFolder;

		Ogre::MapUtil* mMapUtil;

	private: System::Windows::Forms::TextBox^  StatusTextBox;
	private: System::Windows::Forms::Button^  CloseWindowButton;
	private: System::Windows::Forms::Button^  EditButton;
	private: System::Windows::Forms::Button^  CreateButton;
	private: System::Windows::Forms::GroupBox^  OutputGroupBox;
	private: System::Windows::Forms::TextBox^  OutputFolderTextBox;
	private: System::Windows::Forms::Label^  OutputFolderLabel;
	private: System::Windows::Forms::Label^  OutputLabel3;
	private: System::Windows::Forms::Label^  OutputLabel2;
	private: System::Windows::Forms::Label^  OutputLabel1;
	private: System::Windows::Forms::TextBox^  GTerrainNameTextBox;
	private: System::Windows::Forms::Label^  TerrainNameGLabel;
	private: System::Windows::Forms::GroupBox^  ImageInputGroupBox;
	private: System::Windows::Forms::Button^  ColorMapLoadButton;
	private: System::Windows::Forms::Label^  ColorMapLabel;
	private: System::Windows::Forms::GroupBox^  InfoGroupBox;
	private: System::Windows::Forms::Label^  InfoLabel2;
	private: System::Windows::Forms::Label^  InfoLabel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  RuntimeGroupBox;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  RGeneralTabPage;
	private: System::Windows::Forms::TextBox^  RColorMapFileNameTextBox;
	private: System::Windows::Forms::Label^  RColorMapFileNameLabel;
	private: System::Windows::Forms::TextBox^  RColorMapExtensionTextBox;
	private: System::Windows::Forms::Label^  RColorMapExtensionLabel;
	private: System::Windows::Forms::TextBox^  RHeightMapExtensionTextBox;
	private: System::Windows::Forms::Label^  RHeightMapExtensionLabel;
	private: System::Windows::Forms::TextBox^  RHeightMapFileNameTextBox;
	private: System::Windows::Forms::Label^  RHeightMapFileNameLabel;
	private: System::Windows::Forms::TextBox^  FormatTextBox;
	private: System::Windows::Forms::Label^  FormatLabel;
	private: System::Windows::Forms::ComboBox^  ResourceFormatComboBox;
	private: System::Windows::Forms::Label^  ResourceFormatLabel;
	private: System::Windows::Forms::TextBox^  RGroupNameTextBox;
	private: System::Windows::Forms::Label^  RGroupNameLabel;
	private: System::Windows::Forms::TabPage^  RPagingTabPage;
	private: System::Windows::Forms::TextBox^  RData2DFormatTextBox;
	private: System::Windows::Forms::TextBox^  RMinValueTextBox;
	private: System::Windows::Forms::Label^  RMinValueLabel;
	private: System::Windows::Forms::TextBox^  RMaxValueTextBox;
	private: System::Windows::Forms::Label^  RMaxValueLabel;
	private: System::Windows::Forms::Label^  RData2DFormatLabel;
	private: System::Windows::Forms::TextBox^  RPageSizeTextBox;
	private: System::Windows::Forms::TextBox^  RTileSizeTextBox;
	private: System::Windows::Forms::Label^  RTileSizeLabel;
	private: System::Windows::Forms::Label^  RPageSizeLabel;
	private: System::Windows::Forms::TextBox^  PageHeightTextBox;
	private: System::Windows::Forms::Label^  PageHeightLabel;
	private: System::Windows::Forms::TextBox^  PageWidthTextBox;
	private: System::Windows::Forms::Label^  PageWidthLabel;
	private: System::Windows::Forms::TabPage^  RPropertiesTabPage;
	private: System::Windows::Forms::TextBox^  MaxPixelErrorTextBox;
	private: System::Windows::Forms::Label^  MaxPixelErrorLabel;
	private: System::Windows::Forms::TextBox^  LODMorphStartTextBox;
	private: System::Windows::Forms::Label^  LODMorphStartLabel;
	private: System::Windows::Forms::CheckBox^  VertexCompressionCheckBox;
	private: System::Windows::Forms::CheckBox^  DeformableCheckBox;
	private: System::Windows::Forms::CheckBox^  VertexProgramMorphCheckBox;
	private: System::Windows::Forms::TextBox^  RTerrainScaleZTextBox;
	private: System::Windows::Forms::Label^  RTerrainScaleZLabel;
	private: System::Windows::Forms::TextBox^  RTerrainScaleYTextBox;
	private: System::Windows::Forms::Label^  RTerrainScaleYLabel;
	private: System::Windows::Forms::TextBox^  RTerrainScaleXTextBox;
	private: System::Windows::Forms::Label^  RTerrainScaleXLabel;
	private: System::Windows::Forms::TabPage^  RLightingTabPage;
	private: System::Windows::Forms::CheckBox^  VertexNormalsCheckBox;
	private: System::Windows::Forms::CheckBox^  VertexLitCheckBox;
	private: System::Windows::Forms::TabPage^  RTextureTabPage;
	private: System::Windows::Forms::RichTextBox^  RSetSplatFileNamesRichTextBox;
	private: System::Windows::Forms::RichTextBox^  RSetMaterialHeightRichTextBox;
	private: System::Windows::Forms::Label^  RSetMaterialHeightLabel;
	private: System::Windows::Forms::RichTextBox^  RSetMaterialColorRichTextBox;
	private: System::Windows::Forms::Label^  RSetSplatFileNamesLabel;
	private: System::Windows::Forms::Label^  RSetMaterialColorLabel;
	private: System::Windows::Forms::RichTextBox^  TextureFormatSupportedRichTextBox;
	private: System::Windows::Forms::TextBox^  RNumMatHeightSplatTextBox;
	private: System::Windows::Forms::Label^  RNumMatHeightSplatLabel;
	private: System::Windows::Forms::CheckBox^  BaseVertexInstantColorCheckBox;
	private: System::Windows::Forms::CheckBox^  BaseVertexShadowCheckBox;
	private: System::Windows::Forms::CheckBox^  BaseVertexColorCheckBox;
	private: System::Windows::Forms::CheckBox^  VertexColorsCheckBox;
	private: System::Windows::Forms::CheckBox^  BigImageCheckBox;
	private: System::Windows::Forms::CheckBox^  CoverageVertexColorCheckBox;
	private: System::Windows::Forms::TextBox^  TextureFormatTextBox;
	private: System::Windows::Forms::Label^  TextureFormatLabel;
	private: System::Windows::Forms::TextBox^  NumTextureFormatSupportedTextBox;
	private: System::Windows::Forms::Label^  NumTextureFormatSupportedLabel;
	private: System::Windows::Forms::TextBox^  RColorMapStretchFactorTextBox;
	private: System::Windows::Forms::Label^  RColorMapStretchFactorLabel;
	private: System::Windows::Forms::TabPage^  RPerformanceTabPage;
	private: System::Windows::Forms::CheckBox^  HorizonVisibilityComputingCheckBox;
	private: System::Windows::Forms::TextBox^  IncrementTilesTextBox;
	private: System::Windows::Forms::Label^  IncrementTilesLabel;
	private: System::Windows::Forms::TextBox^  MaxNumRenderablesTextBox;
	private: System::Windows::Forms::TextBox^  MaxNumTilesTextBox;
	private: System::Windows::Forms::Label^  MaxNumTilesLabel;
	private: System::Windows::Forms::TextBox^  IncrementRenderablesTextBox;
	private: System::Windows::Forms::Label^  IncrementRenderablesLabel;
	private: System::Windows::Forms::Label^  MaxNumRenderablesLabel;
	private: System::Windows::Forms::TextBox^  CameraThresholdTextBox;
	private: System::Windows::Forms::Label^  CameraThresholdLabel;
	private: System::Windows::Forms::TextBox^  ChangeFactorTextBox;
	private: System::Windows::Forms::Label^  ChangeFactorLabel;
	private: System::Windows::Forms::TextBox^  MaxPreloadedPagesTextBox;
	private: System::Windows::Forms::Label^  MaxPreloadedPagesLabel;
	private: System::Windows::Forms::TextBox^  MaxRenderLevelTextBox;
	private: System::Windows::Forms::TextBox^  MaxAdjacentPagesTextBox;
	private: System::Windows::Forms::Label^  MaxAdjacentPagesLabel;
	private: System::Windows::Forms::TextBox^  NumRenderablesLoadingTextBox;
	private: System::Windows::Forms::Label^  NumRenderablesLoadingLabel;
	private: System::Windows::Forms::Label^  MaxRenderLevelLabel;
	private: System::Windows::Forms::TextBox^  DistanceLODTextBox;
	private: System::Windows::Forms::Label^  DistanceLODLabel;
	private: System::Windows::Forms::TextBox^  VisibleRenderablesTextBox;
	private: System::Windows::Forms::Label^  VisibleRenderablesLabel;
	private: System::Windows::Forms::TabPage^  RCameraTabPage;
	private: System::Windows::Forms::TextBox^  BaselookatzTextBox;
	private: System::Windows::Forms::Label^  BaselookatzLabel;
	private: System::Windows::Forms::TextBox^  BaseCameraViewpointzTextBox;
	private: System::Windows::Forms::TextBox^  BaselookatyTextBox;
	private: System::Windows::Forms::Label^  BaselookatyLabel;
	private: System::Windows::Forms::TextBox^  BaselookatxTextBox;
	private: System::Windows::Forms::Label^  BaselookatxLabel;
	private: System::Windows::Forms::Label^  BaseCameraViewpointzLabel;
	private: System::Windows::Forms::TextBox^  BaseCameraViewpointyTextBox;
	private: System::Windows::Forms::Label^  BaseCameraViewpointyLabel;
	private: System::Windows::Forms::TextBox^  BaseCameraViewpointxTextBox;
	private: System::Windows::Forms::Label^  BaseCameraViewpointxLabel;

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
            this->StatusTextBox = (gcnew System::Windows::Forms::TextBox());
            this->CloseWindowButton = (gcnew System::Windows::Forms::Button());
            this->EditButton = (gcnew System::Windows::Forms::Button());
            this->CreateButton = (gcnew System::Windows::Forms::Button());
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
            this->ColorMapLoadButton = (gcnew System::Windows::Forms::Button());
            this->ColorMapLabel = (gcnew System::Windows::Forms::Label());
            this->InfoGroupBox = (gcnew System::Windows::Forms::GroupBox());
            this->InfoLabel2 = (gcnew System::Windows::Forms::Label());
            this->InfoLabel1 = (gcnew System::Windows::Forms::Label());
            this->RuntimeGroupBox = (gcnew System::Windows::Forms::GroupBox());
            this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
            this->RGeneralTabPage = (gcnew System::Windows::Forms::TabPage());
            this->RColorMapFileNameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->RColorMapFileNameLabel = (gcnew System::Windows::Forms::Label());
            this->RColorMapExtensionTextBox = (gcnew System::Windows::Forms::TextBox());
            this->RColorMapExtensionLabel = (gcnew System::Windows::Forms::Label());
            this->RHeightMapExtensionTextBox = (gcnew System::Windows::Forms::TextBox());
            this->RHeightMapExtensionLabel = (gcnew System::Windows::Forms::Label());
            this->RHeightMapFileNameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->RHeightMapFileNameLabel = (gcnew System::Windows::Forms::Label());
            this->FormatTextBox = (gcnew System::Windows::Forms::TextBox());
            this->FormatLabel = (gcnew System::Windows::Forms::Label());
            this->ResourceFormatComboBox = (gcnew System::Windows::Forms::ComboBox());
            this->ResourceFormatLabel = (gcnew System::Windows::Forms::Label());
            this->RGroupNameTextBox = (gcnew System::Windows::Forms::TextBox());
            this->RGroupNameLabel = (gcnew System::Windows::Forms::Label());
            this->RPagingTabPage = (gcnew System::Windows::Forms::TabPage());
            this->RData2DFormatTextBox = (gcnew System::Windows::Forms::TextBox());
            this->RMinValueTextBox = (gcnew System::Windows::Forms::TextBox());
            this->RMinValueLabel = (gcnew System::Windows::Forms::Label());
            this->RMaxValueTextBox = (gcnew System::Windows::Forms::TextBox());
            this->RMaxValueLabel = (gcnew System::Windows::Forms::Label());
            this->RData2DFormatLabel = (gcnew System::Windows::Forms::Label());
            this->RPageSizeTextBox = (gcnew System::Windows::Forms::TextBox());
            this->RTileSizeTextBox = (gcnew System::Windows::Forms::TextBox());
            this->RTileSizeLabel = (gcnew System::Windows::Forms::Label());
            this->RPageSizeLabel = (gcnew System::Windows::Forms::Label());
            this->PageHeightTextBox = (gcnew System::Windows::Forms::TextBox());
            this->PageHeightLabel = (gcnew System::Windows::Forms::Label());
            this->PageWidthTextBox = (gcnew System::Windows::Forms::TextBox());
            this->PageWidthLabel = (gcnew System::Windows::Forms::Label());
            this->RPropertiesTabPage = (gcnew System::Windows::Forms::TabPage());
            this->MaxPixelErrorTextBox = (gcnew System::Windows::Forms::TextBox());
            this->MaxPixelErrorLabel = (gcnew System::Windows::Forms::Label());
            this->LODMorphStartTextBox = (gcnew System::Windows::Forms::TextBox());
            this->LODMorphStartLabel = (gcnew System::Windows::Forms::Label());
            this->VertexCompressionCheckBox = (gcnew System::Windows::Forms::CheckBox());
            this->DeformableCheckBox = (gcnew System::Windows::Forms::CheckBox());
            this->VertexProgramMorphCheckBox = (gcnew System::Windows::Forms::CheckBox());
            this->RTerrainScaleZTextBox = (gcnew System::Windows::Forms::TextBox());
            this->RTerrainScaleZLabel = (gcnew System::Windows::Forms::Label());
            this->RTerrainScaleYTextBox = (gcnew System::Windows::Forms::TextBox());
            this->RTerrainScaleYLabel = (gcnew System::Windows::Forms::Label());
            this->RTerrainScaleXTextBox = (gcnew System::Windows::Forms::TextBox());
            this->RTerrainScaleXLabel = (gcnew System::Windows::Forms::Label());
            this->RLightingTabPage = (gcnew System::Windows::Forms::TabPage());
            this->VertexNormalsCheckBox = (gcnew System::Windows::Forms::CheckBox());
            this->VertexLitCheckBox = (gcnew System::Windows::Forms::CheckBox());
            this->RTextureTabPage = (gcnew System::Windows::Forms::TabPage());
            this->RSetSplatFileNamesRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
            this->RSetMaterialHeightRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
            this->RSetMaterialHeightLabel = (gcnew System::Windows::Forms::Label());
            this->RSetMaterialColorRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
            this->RSetSplatFileNamesLabel = (gcnew System::Windows::Forms::Label());
            this->RSetMaterialColorLabel = (gcnew System::Windows::Forms::Label());
            this->TextureFormatSupportedRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
            this->RNumMatHeightSplatTextBox = (gcnew System::Windows::Forms::TextBox());
            this->RNumMatHeightSplatLabel = (gcnew System::Windows::Forms::Label());
            this->BaseVertexInstantColorCheckBox = (gcnew System::Windows::Forms::CheckBox());
            this->BaseVertexShadowCheckBox = (gcnew System::Windows::Forms::CheckBox());
            this->BaseVertexColorCheckBox = (gcnew System::Windows::Forms::CheckBox());
            this->VertexColorsCheckBox = (gcnew System::Windows::Forms::CheckBox());
            this->BigImageCheckBox = (gcnew System::Windows::Forms::CheckBox());
            this->CoverageVertexColorCheckBox = (gcnew System::Windows::Forms::CheckBox());
            this->TextureFormatTextBox = (gcnew System::Windows::Forms::TextBox());
            this->TextureFormatLabel = (gcnew System::Windows::Forms::Label());
            this->NumTextureFormatSupportedTextBox = (gcnew System::Windows::Forms::TextBox());
            this->NumTextureFormatSupportedLabel = (gcnew System::Windows::Forms::Label());
            this->RColorMapStretchFactorTextBox = (gcnew System::Windows::Forms::TextBox());
            this->RColorMapStretchFactorLabel = (gcnew System::Windows::Forms::Label());
            this->RPerformanceTabPage = (gcnew System::Windows::Forms::TabPage());
            this->HorizonVisibilityComputingCheckBox = (gcnew System::Windows::Forms::CheckBox());
            this->IncrementTilesTextBox = (gcnew System::Windows::Forms::TextBox());
            this->IncrementTilesLabel = (gcnew System::Windows::Forms::Label());
            this->MaxNumRenderablesTextBox = (gcnew System::Windows::Forms::TextBox());
            this->MaxNumTilesTextBox = (gcnew System::Windows::Forms::TextBox());
            this->MaxNumTilesLabel = (gcnew System::Windows::Forms::Label());
            this->IncrementRenderablesTextBox = (gcnew System::Windows::Forms::TextBox());
            this->IncrementRenderablesLabel = (gcnew System::Windows::Forms::Label());
            this->MaxNumRenderablesLabel = (gcnew System::Windows::Forms::Label());
            this->CameraThresholdTextBox = (gcnew System::Windows::Forms::TextBox());
            this->CameraThresholdLabel = (gcnew System::Windows::Forms::Label());
            this->ChangeFactorTextBox = (gcnew System::Windows::Forms::TextBox());
            this->ChangeFactorLabel = (gcnew System::Windows::Forms::Label());
            this->MaxPreloadedPagesTextBox = (gcnew System::Windows::Forms::TextBox());
            this->MaxPreloadedPagesLabel = (gcnew System::Windows::Forms::Label());
            this->MaxRenderLevelTextBox = (gcnew System::Windows::Forms::TextBox());
            this->MaxAdjacentPagesTextBox = (gcnew System::Windows::Forms::TextBox());
            this->MaxAdjacentPagesLabel = (gcnew System::Windows::Forms::Label());
            this->NumRenderablesLoadingTextBox = (gcnew System::Windows::Forms::TextBox());
            this->NumRenderablesLoadingLabel = (gcnew System::Windows::Forms::Label());
            this->MaxRenderLevelLabel = (gcnew System::Windows::Forms::Label());
            this->DistanceLODTextBox = (gcnew System::Windows::Forms::TextBox());
            this->DistanceLODLabel = (gcnew System::Windows::Forms::Label());
            this->VisibleRenderablesTextBox = (gcnew System::Windows::Forms::TextBox());
            this->VisibleRenderablesLabel = (gcnew System::Windows::Forms::Label());
            this->RCameraTabPage = (gcnew System::Windows::Forms::TabPage());
            this->BaselookatzTextBox = (gcnew System::Windows::Forms::TextBox());
            this->BaselookatzLabel = (gcnew System::Windows::Forms::Label());
            this->BaseCameraViewpointzTextBox = (gcnew System::Windows::Forms::TextBox());
            this->BaselookatyTextBox = (gcnew System::Windows::Forms::TextBox());
            this->BaselookatyLabel = (gcnew System::Windows::Forms::Label());
            this->BaselookatxTextBox = (gcnew System::Windows::Forms::TextBox());
            this->BaselookatxLabel = (gcnew System::Windows::Forms::Label());
            this->BaseCameraViewpointzLabel = (gcnew System::Windows::Forms::Label());
            this->BaseCameraViewpointyTextBox = (gcnew System::Windows::Forms::TextBox());
            this->BaseCameraViewpointyLabel = (gcnew System::Windows::Forms::Label());
            this->BaseCameraViewpointxTextBox = (gcnew System::Windows::Forms::TextBox());
            this->BaseCameraViewpointxLabel = (gcnew System::Windows::Forms::Label());
            this->OutputGroupBox->SuspendLayout();
            this->ImageInputGroupBox->SuspendLayout();
            this->InfoGroupBox->SuspendLayout();
            this->RuntimeGroupBox->SuspendLayout();
            this->tabControl1->SuspendLayout();
            this->RGeneralTabPage->SuspendLayout();
            this->RPagingTabPage->SuspendLayout();
            this->RPropertiesTabPage->SuspendLayout();
            this->RLightingTabPage->SuspendLayout();
            this->RTextureTabPage->SuspendLayout();
            this->RPerformanceTabPage->SuspendLayout();
            this->RCameraTabPage->SuspendLayout();
            this->SuspendLayout();
            // 
            // StatusTextBox
            // 
            this->StatusTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->StatusTextBox->Location = System::Drawing::Point(4, 343);
            this->StatusTextBox->Name = L"StatusTextBox";
            this->StatusTextBox->ReadOnly = true;
            this->StatusTextBox->Size = System::Drawing::Size(882, 20);
            this->StatusTextBox->TabIndex = 16;
            // 
            // CloseWindowButton
            // 
            this->CloseWindowButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->CloseWindowButton->Location = System::Drawing::Point(629, 314);
            this->CloseWindowButton->Name = L"CloseWindowButton";
            this->CloseWindowButton->Size = System::Drawing::Size(231, 23);
            this->CloseWindowButton->TabIndex = 15;
            this->CloseWindowButton->Text = L"Close Window";
            this->CloseWindowButton->UseVisualStyleBackColor = true;
            this->CloseWindowButton->Click += gcnew System::EventHandler(this, &RuntimeWindow::CloseWindowButton_Click);
            // 
            // EditButton
            // 
            this->EditButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->EditButton->Location = System::Drawing::Point(321, 314);
            this->EditButton->Name = L"EditButton";
            this->EditButton->Size = System::Drawing::Size(231, 23);
            this->EditButton->TabIndex = 14;
            this->EditButton->Text = L"Edit Runtime File";
            this->EditButton->UseVisualStyleBackColor = true;
            this->EditButton->Click += gcnew System::EventHandler(this, &RuntimeWindow::EditButton_Click);
            // 
            // CreateButton
            // 
            this->CreateButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
            this->CreateButton->Location = System::Drawing::Point(12, 314);
            this->CreateButton->Name = L"CreateButton";
            this->CreateButton->Size = System::Drawing::Size(231, 23);
            this->CreateButton->TabIndex = 13;
            this->CreateButton->Text = L"Create Runtime File";
            this->CreateButton->UseVisualStyleBackColor = true;
            this->CreateButton->Click += gcnew System::EventHandler(this, &RuntimeWindow::CreateButton_Click);
            // 
            // OutputGroupBox
            // 
            this->OutputGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
                | System::Windows::Forms::AnchorStyles::Left));
            this->OutputGroupBox->Controls->Add(this->OutputFolderTextBox);
            this->OutputGroupBox->Controls->Add(this->OutputFolderLabel);
            this->OutputGroupBox->Controls->Add(this->OutputLabel3);
            this->OutputGroupBox->Controls->Add(this->OutputLabel2);
            this->OutputGroupBox->Controls->Add(this->OutputLabel1);
            this->OutputGroupBox->Controls->Add(this->GTerrainNameTextBox);
            this->OutputGroupBox->Controls->Add(this->TerrainNameGLabel);
            this->OutputGroupBox->Location = System::Drawing::Point(13, 175);
            this->OutputGroupBox->Name = L"OutputGroupBox";
            this->OutputGroupBox->Size = System::Drawing::Size(416, 133);
            this->OutputGroupBox->TabIndex = 12;
            this->OutputGroupBox->TabStop = false;
            this->OutputGroupBox->Text = L"Output";
            // 
            // OutputFolderTextBox
            // 
            this->OutputFolderTextBox->Location = System::Drawing::Point(95, 102);
            this->OutputFolderTextBox->Margin = System::Windows::Forms::Padding(2);
            this->OutputFolderTextBox->Name = L"OutputFolderTextBox";
            this->OutputFolderTextBox->ReadOnly = true;
            this->OutputFolderTextBox->Size = System::Drawing::Size(312, 20);
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
            this->OutputLabel1->Size = System::Drawing::Size(362, 13);
            this->OutputLabel1->TabIndex = 2;
            this->OutputLabel1->Text = L"The Runtime file will be created as <Terrain Name>.cfg in the Output folder.";
            // 
            // GTerrainNameTextBox
            // 
            this->GTerrainNameTextBox->Location = System::Drawing::Point(95, 78);
            this->GTerrainNameTextBox->Margin = System::Windows::Forms::Padding(2);
            this->GTerrainNameTextBox->Name = L"GTerrainNameTextBox";
            this->GTerrainNameTextBox->ReadOnly = true;
            this->GTerrainNameTextBox->Size = System::Drawing::Size(312, 20);
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
            this->ImageInputGroupBox->Controls->Add(this->label1);
            this->ImageInputGroupBox->Controls->Add(this->ColorMapLoadButton);
            this->ImageInputGroupBox->Controls->Add(this->ColorMapLabel);
            this->ImageInputGroupBox->Location = System::Drawing::Point(13, 86);
            this->ImageInputGroupBox->Name = L"ImageInputGroupBox";
            this->ImageInputGroupBox->Size = System::Drawing::Size(413, 82);
            this->ImageInputGroupBox->TabIndex = 11;
            this->ImageInputGroupBox->TabStop = false;
            this->ImageInputGroupBox->Text = L"Gen Input";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(16, 24);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(355, 13);
            this->label1->TabIndex = 2;
            this->label1->Text = L"Several properties between the Gen and Runtime files must be consistent.";
            // 
            // ColorMapLoadButton
            // 
            this->ColorMapLoadButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->ColorMapLoadButton->Location = System::Drawing::Point(82, 48);
            this->ColorMapLoadButton->Margin = System::Windows::Forms::Padding(2);
            this->ColorMapLoadButton->Name = L"ColorMapLoadButton";
            this->ColorMapLoadButton->Size = System::Drawing::Size(325, 19);
            this->ColorMapLoadButton->TabIndex = 163;
            this->ColorMapLoadButton->Text = L"Load Gen File";
            this->ColorMapLoadButton->UseVisualStyleBackColor = true;
            this->ColorMapLoadButton->Click += gcnew System::EventHandler(this, &RuntimeWindow::GenFileLoadButton_Click);
            // 
            // ColorMapLabel
            // 
            this->ColorMapLabel->AutoSize = true;
            this->ColorMapLabel->Location = System::Drawing::Point(16, 51);
            this->ColorMapLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->ColorMapLabel->Name = L"ColorMapLabel";
            this->ColorMapLabel->Size = System::Drawing::Size(49, 13);
            this->ColorMapLabel->TabIndex = 165;
            this->ColorMapLabel->Text = L"Gen File:";
            // 
            // InfoGroupBox
            // 
            this->InfoGroupBox->Controls->Add(this->InfoLabel2);
            this->InfoGroupBox->Controls->Add(this->InfoLabel1);
            this->InfoGroupBox->Location = System::Drawing::Point(13, 13);
            this->InfoGroupBox->Name = L"InfoGroupBox";
            this->InfoGroupBox->Size = System::Drawing::Size(413, 66);
            this->InfoGroupBox->TabIndex = 10;
            this->InfoGroupBox->TabStop = false;
            this->InfoGroupBox->Text = L"Info";
            // 
            // InfoLabel2
            // 
            this->InfoLabel2->AutoSize = true;
            this->InfoLabel2->Location = System::Drawing::Point(16, 37);
            this->InfoLabel2->Name = L"InfoLabel2";
            this->InfoLabel2->Size = System::Drawing::Size(341, 13);
            this->InfoLabel2->TabIndex = 1;
            this->InfoLabel2->Text = L"The Images produced from MapSplitter are also required to load terrain.";
            // 
            // InfoLabel1
            // 
            this->InfoLabel1->AutoSize = true;
            this->InfoLabel1->Location = System::Drawing::Point(16, 24);
            this->InfoLabel1->Name = L"InfoLabel1";
            this->InfoLabel1->Size = System::Drawing::Size(308, 13);
            this->InfoLabel1->TabIndex = 0;
            this->InfoLabel1->Text = L"Runtime Files are used with PLSM to load terrain into the scene.";
            // 
            // RuntimeGroupBox
            // 
            this->RuntimeGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
                | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->RuntimeGroupBox->Controls->Add(this->tabControl1);
            this->RuntimeGroupBox->Location = System::Drawing::Point(433, 13);
            this->RuntimeGroupBox->Name = L"RuntimeGroupBox";
            this->RuntimeGroupBox->Size = System::Drawing::Size(427, 295);
            this->RuntimeGroupBox->TabIndex = 17;
            this->RuntimeGroupBox->TabStop = false;
            this->RuntimeGroupBox->Text = L"Runtime Configuration";
            // 
            // tabControl1
            // 
            this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
                | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->tabControl1->Controls->Add(this->RGeneralTabPage);
            this->tabControl1->Controls->Add(this->RPagingTabPage);
            this->tabControl1->Controls->Add(this->RPropertiesTabPage);
            this->tabControl1->Controls->Add(this->RLightingTabPage);
            this->tabControl1->Controls->Add(this->RTextureTabPage);
            this->tabControl1->Controls->Add(this->RPerformanceTabPage);
            this->tabControl1->Controls->Add(this->RCameraTabPage);
            this->tabControl1->Location = System::Drawing::Point(5, 18);
            this->tabControl1->Margin = System::Windows::Forms::Padding(2);
            this->tabControl1->Name = L"tabControl1";
            this->tabControl1->SelectedIndex = 0;
            this->tabControl1->Size = System::Drawing::Size(409, 267);
            this->tabControl1->TabIndex = 163;
            // 
            // RGeneralTabPage
            // 
            this->RGeneralTabPage->AutoScroll = true;
            this->RGeneralTabPage->Controls->Add(this->RColorMapFileNameTextBox);
            this->RGeneralTabPage->Controls->Add(this->RColorMapFileNameLabel);
            this->RGeneralTabPage->Controls->Add(this->RColorMapExtensionTextBox);
            this->RGeneralTabPage->Controls->Add(this->RColorMapExtensionLabel);
            this->RGeneralTabPage->Controls->Add(this->RHeightMapExtensionTextBox);
            this->RGeneralTabPage->Controls->Add(this->RHeightMapExtensionLabel);
            this->RGeneralTabPage->Controls->Add(this->RHeightMapFileNameTextBox);
            this->RGeneralTabPage->Controls->Add(this->RHeightMapFileNameLabel);
            this->RGeneralTabPage->Controls->Add(this->FormatTextBox);
            this->RGeneralTabPage->Controls->Add(this->FormatLabel);
            this->RGeneralTabPage->Controls->Add(this->ResourceFormatComboBox);
            this->RGeneralTabPage->Controls->Add(this->ResourceFormatLabel);
            this->RGeneralTabPage->Controls->Add(this->RGroupNameTextBox);
            this->RGeneralTabPage->Controls->Add(this->RGroupNameLabel);
            this->RGeneralTabPage->Location = System::Drawing::Point(4, 22);
            this->RGeneralTabPage->Margin = System::Windows::Forms::Padding(2);
            this->RGeneralTabPage->Name = L"RGeneralTabPage";
            this->RGeneralTabPage->Padding = System::Windows::Forms::Padding(2);
            this->RGeneralTabPage->Size = System::Drawing::Size(401, 241);
            this->RGeneralTabPage->TabIndex = 0;
            this->RGeneralTabPage->Text = L"General";
            this->RGeneralTabPage->UseVisualStyleBackColor = true;
            // 
            // RColorMapFileNameTextBox
            // 
            this->RColorMapFileNameTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->RColorMapFileNameTextBox->Location = System::Drawing::Point(169, 128);
            this->RColorMapFileNameTextBox->Margin = System::Windows::Forms::Padding(2);
            this->RColorMapFileNameTextBox->Name = L"RColorMapFileNameTextBox";
            this->RColorMapFileNameTextBox->ReadOnly = true;
            this->RColorMapFileNameTextBox->Size = System::Drawing::Size(192, 20);
            this->RColorMapFileNameTextBox->TabIndex = 351;
            this->RColorMapFileNameTextBox->Text = L"ps_texture_1k";
            // 
            // RColorMapFileNameLabel
            // 
            this->RColorMapFileNameLabel->AutoSize = true;
            this->RColorMapFileNameLabel->Location = System::Drawing::Point(19, 131);
            this->RColorMapFileNameLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->RColorMapFileNameLabel->Name = L"RColorMapFileNameLabel";
            this->RColorMapFileNameLabel->Size = System::Drawing::Size(99, 13);
            this->RColorMapFileNameLabel->TabIndex = 350;
            this->RColorMapFileNameLabel->Text = L"ColorMapFileName:";
            // 
            // RColorMapExtensionTextBox
            // 
            this->RColorMapExtensionTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->RColorMapExtensionTextBox->Location = System::Drawing::Point(169, 150);
            this->RColorMapExtensionTextBox->Margin = System::Windows::Forms::Padding(2);
            this->RColorMapExtensionTextBox->Name = L"RColorMapExtensionTextBox";
            this->RColorMapExtensionTextBox->ReadOnly = true;
            this->RColorMapExtensionTextBox->Size = System::Drawing::Size(191, 20);
            this->RColorMapExtensionTextBox->TabIndex = 346;
            this->RColorMapExtensionTextBox->Text = L"png";
            // 
            // RColorMapExtensionLabel
            // 
            this->RColorMapExtensionLabel->AutoSize = true;
            this->RColorMapExtensionLabel->Location = System::Drawing::Point(19, 154);
            this->RColorMapExtensionLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->RColorMapExtensionLabel->Name = L"RColorMapExtensionLabel";
            this->RColorMapExtensionLabel->Size = System::Drawing::Size(101, 13);
            this->RColorMapExtensionLabel->TabIndex = 347;
            this->RColorMapExtensionLabel->Text = L"ColorMapExtension:";
            // 
            // RHeightMapExtensionTextBox
            // 
            this->RHeightMapExtensionTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->RHeightMapExtensionTextBox->Location = System::Drawing::Point(169, 105);
            this->RHeightMapExtensionTextBox->Margin = System::Windows::Forms::Padding(2);
            this->RHeightMapExtensionTextBox->Name = L"RHeightMapExtensionTextBox";
            this->RHeightMapExtensionTextBox->ReadOnly = true;
            this->RHeightMapExtensionTextBox->Size = System::Drawing::Size(192, 20);
            this->RHeightMapExtensionTextBox->TabIndex = 177;
            this->RHeightMapExtensionTextBox->Text = L"png";
            // 
            // RHeightMapExtensionLabel
            // 
            this->RHeightMapExtensionLabel->AutoSize = true;
            this->RHeightMapExtensionLabel->Location = System::Drawing::Point(19, 107);
            this->RHeightMapExtensionLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->RHeightMapExtensionLabel->Name = L"RHeightMapExtensionLabel";
            this->RHeightMapExtensionLabel->Size = System::Drawing::Size(108, 13);
            this->RHeightMapExtensionLabel->TabIndex = 179;
            this->RHeightMapExtensionLabel->Text = L"HeightMapExtension:";
            // 
            // RHeightMapFileNameTextBox
            // 
            this->RHeightMapFileNameTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->RHeightMapFileNameTextBox->Location = System::Drawing::Point(169, 81);
            this->RHeightMapFileNameTextBox->Margin = System::Windows::Forms::Padding(2);
            this->RHeightMapFileNameTextBox->Name = L"RHeightMapFileNameTextBox";
            this->RHeightMapFileNameTextBox->ReadOnly = true;
            this->RHeightMapFileNameTextBox->Size = System::Drawing::Size(192, 20);
            this->RHeightMapFileNameTextBox->TabIndex = 176;
            this->RHeightMapFileNameTextBox->Text = L"ps_height_1k";
            // 
            // RHeightMapFileNameLabel
            // 
            this->RHeightMapFileNameLabel->AutoSize = true;
            this->RHeightMapFileNameLabel->Location = System::Drawing::Point(19, 84);
            this->RHeightMapFileNameLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->RHeightMapFileNameLabel->Name = L"RHeightMapFileNameLabel";
            this->RHeightMapFileNameLabel->Size = System::Drawing::Size(106, 13);
            this->RHeightMapFileNameLabel->TabIndex = 178;
            this->RHeightMapFileNameLabel->Text = L"HeightMapFileName:";
            // 
            // FormatTextBox
            // 
            this->FormatTextBox->Location = System::Drawing::Point(87, 57);
            this->FormatTextBox->Margin = System::Windows::Forms::Padding(2);
            this->FormatTextBox->Name = L"FormatTextBox";
            this->FormatTextBox->Size = System::Drawing::Size(243, 20);
            this->FormatTextBox->TabIndex = 170;
            // 
            // FormatLabel
            // 
            this->FormatLabel->Location = System::Drawing::Point(12, 57);
            this->FormatLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->FormatLabel->Name = L"FormatLabel";
            this->FormatLabel->Size = System::Drawing::Size(71, 19);
            this->FormatLabel->TabIndex = 169;
            this->FormatLabel->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            // 
            // ResourceFormatComboBox
            // 
            this->ResourceFormatComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->ResourceFormatComboBox->FormattingEnabled = true;
            this->ResourceFormatComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Already in Path", L"FileSystem", 
                L"Zip"});
            this->ResourceFormatComboBox->Location = System::Drawing::Point(169, 33);
            this->ResourceFormatComboBox->Margin = System::Windows::Forms::Padding(2);
            this->ResourceFormatComboBox->Name = L"ResourceFormatComboBox";
            this->ResourceFormatComboBox->Size = System::Drawing::Size(192, 21);
            this->ResourceFormatComboBox->TabIndex = 166;
            this->ResourceFormatComboBox->Text = L"Already in Path";
            // 
            // ResourceFormatLabel
            // 
            this->ResourceFormatLabel->AutoSize = true;
            this->ResourceFormatLabel->Location = System::Drawing::Point(18, 36);
            this->ResourceFormatLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->ResourceFormatLabel->Name = L"ResourceFormatLabel";
            this->ResourceFormatLabel->Size = System::Drawing::Size(91, 13);
            this->ResourceFormatLabel->TabIndex = 167;
            this->ResourceFormatLabel->Text = L"Resource Format:";
            // 
            // RGroupNameTextBox
            // 
            this->RGroupNameTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->RGroupNameTextBox->Location = System::Drawing::Point(169, 10);
            this->RGroupNameTextBox->Margin = System::Windows::Forms::Padding(2);
            this->RGroupNameTextBox->Name = L"RGroupNameTextBox";
            this->RGroupNameTextBox->ReadOnly = true;
            this->RGroupNameTextBox->Size = System::Drawing::Size(192, 20);
            this->RGroupNameTextBox->TabIndex = 163;
            this->RGroupNameTextBox->Text = L"PLSM2";
            // 
            // RGroupNameLabel
            // 
            this->RGroupNameLabel->AutoSize = true;
            this->RGroupNameLabel->Location = System::Drawing::Point(18, 13);
            this->RGroupNameLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->RGroupNameLabel->Name = L"RGroupNameLabel";
            this->RGroupNameLabel->Size = System::Drawing::Size(67, 13);
            this->RGroupNameLabel->TabIndex = 164;
            this->RGroupNameLabel->Text = L"GroupName:";
            // 
            // RPagingTabPage
            // 
            this->RPagingTabPage->AutoScroll = true;
            this->RPagingTabPage->Controls->Add(this->RData2DFormatTextBox);
            this->RPagingTabPage->Controls->Add(this->RMinValueTextBox);
            this->RPagingTabPage->Controls->Add(this->RMinValueLabel);
            this->RPagingTabPage->Controls->Add(this->RMaxValueTextBox);
            this->RPagingTabPage->Controls->Add(this->RMaxValueLabel);
            this->RPagingTabPage->Controls->Add(this->RData2DFormatLabel);
            this->RPagingTabPage->Controls->Add(this->RPageSizeTextBox);
            this->RPagingTabPage->Controls->Add(this->RTileSizeTextBox);
            this->RPagingTabPage->Controls->Add(this->RTileSizeLabel);
            this->RPagingTabPage->Controls->Add(this->RPageSizeLabel);
            this->RPagingTabPage->Controls->Add(this->PageHeightTextBox);
            this->RPagingTabPage->Controls->Add(this->PageHeightLabel);
            this->RPagingTabPage->Controls->Add(this->PageWidthTextBox);
            this->RPagingTabPage->Controls->Add(this->PageWidthLabel);
            this->RPagingTabPage->Location = System::Drawing::Point(4, 22);
            this->RPagingTabPage->Margin = System::Windows::Forms::Padding(2);
            this->RPagingTabPage->Name = L"RPagingTabPage";
            this->RPagingTabPage->Padding = System::Windows::Forms::Padding(2);
            this->RPagingTabPage->Size = System::Drawing::Size(401, 241);
            this->RPagingTabPage->TabIndex = 1;
            this->RPagingTabPage->Text = L"Paging";
            this->RPagingTabPage->UseVisualStyleBackColor = true;
            // 
            // RData2DFormatTextBox
            // 
            this->RData2DFormatTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->RData2DFormatTextBox->Location = System::Drawing::Point(168, 105);
            this->RData2DFormatTextBox->Margin = System::Windows::Forms::Padding(2);
            this->RData2DFormatTextBox->Name = L"RData2DFormatTextBox";
            this->RData2DFormatTextBox->ReadOnly = true;
            this->RData2DFormatTextBox->Size = System::Drawing::Size(192, 20);
            this->RData2DFormatTextBox->TabIndex = 213;
            // 
            // RMinValueTextBox
            // 
            this->RMinValueTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->RMinValueTextBox->Location = System::Drawing::Point(168, 152);
            this->RMinValueTextBox->Margin = System::Windows::Forms::Padding(2);
            this->RMinValueTextBox->Name = L"RMinValueTextBox";
            this->RMinValueTextBox->ReadOnly = true;
            this->RMinValueTextBox->Size = System::Drawing::Size(192, 20);
            this->RMinValueTextBox->TabIndex = 206;
            this->RMinValueTextBox->Text = L"0";
            // 
            // RMinValueLabel
            // 
            this->RMinValueLabel->AutoSize = true;
            this->RMinValueLabel->Location = System::Drawing::Point(18, 154);
            this->RMinValueLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->RMinValueLabel->Name = L"RMinValueLabel";
            this->RMinValueLabel->Size = System::Drawing::Size(54, 13);
            this->RMinValueLabel->TabIndex = 209;
            this->RMinValueLabel->Text = L"MinValue:";
            // 
            // RMaxValueTextBox
            // 
            this->RMaxValueTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->RMaxValueTextBox->Location = System::Drawing::Point(168, 128);
            this->RMaxValueTextBox->Margin = System::Windows::Forms::Padding(2);
            this->RMaxValueTextBox->Name = L"RMaxValueTextBox";
            this->RMaxValueTextBox->ReadOnly = true;
            this->RMaxValueTextBox->Size = System::Drawing::Size(192, 20);
            this->RMaxValueTextBox->TabIndex = 205;
            this->RMaxValueTextBox->Text = L"0";
            // 
            // RMaxValueLabel
            // 
            this->RMaxValueLabel->AutoSize = true;
            this->RMaxValueLabel->Location = System::Drawing::Point(18, 131);
            this->RMaxValueLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->RMaxValueLabel->Name = L"RMaxValueLabel";
            this->RMaxValueLabel->Size = System::Drawing::Size(57, 13);
            this->RMaxValueLabel->TabIndex = 208;
            this->RMaxValueLabel->Text = L"MaxValue:";
            // 
            // RData2DFormatLabel
            // 
            this->RData2DFormatLabel->AutoSize = true;
            this->RData2DFormatLabel->Location = System::Drawing::Point(18, 107);
            this->RData2DFormatLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->RData2DFormatLabel->Name = L"RData2DFormatLabel";
            this->RData2DFormatLabel->Size = System::Drawing::Size(79, 13);
            this->RData2DFormatLabel->TabIndex = 207;
            this->RData2DFormatLabel->Text = L"Data2DFormat:";
            // 
            // RPageSizeTextBox
            // 
            this->RPageSizeTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->RPageSizeTextBox->Location = System::Drawing::Point(168, 58);
            this->RPageSizeTextBox->Margin = System::Windows::Forms::Padding(2);
            this->RPageSizeTextBox->Name = L"RPageSizeTextBox";
            this->RPageSizeTextBox->ReadOnly = true;
            this->RPageSizeTextBox->Size = System::Drawing::Size(192, 20);
            this->RPageSizeTextBox->TabIndex = 194;
            this->RPageSizeTextBox->Text = L"513";
            // 
            // RTileSizeTextBox
            // 
            this->RTileSizeTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->RTileSizeTextBox->Location = System::Drawing::Point(168, 81);
            this->RTileSizeTextBox->Margin = System::Windows::Forms::Padding(2);
            this->RTileSizeTextBox->Name = L"RTileSizeTextBox";
            this->RTileSizeTextBox->ReadOnly = true;
            this->RTileSizeTextBox->Size = System::Drawing::Size(192, 20);
            this->RTileSizeTextBox->TabIndex = 195;
            this->RTileSizeTextBox->Text = L"65";
            // 
            // RTileSizeLabel
            // 
            this->RTileSizeLabel->AutoSize = true;
            this->RTileSizeLabel->Location = System::Drawing::Point(18, 84);
            this->RTileSizeLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->RTileSizeLabel->Name = L"RTileSizeLabel";
            this->RTileSizeLabel->Size = System::Drawing::Size(47, 13);
            this->RTileSizeLabel->TabIndex = 199;
            this->RTileSizeLabel->Text = L"TileSize:";
            // 
            // RPageSizeLabel
            // 
            this->RPageSizeLabel->AutoSize = true;
            this->RPageSizeLabel->Location = System::Drawing::Point(18, 60);
            this->RPageSizeLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->RPageSizeLabel->Name = L"RPageSizeLabel";
            this->RPageSizeLabel->Size = System::Drawing::Size(55, 13);
            this->RPageSizeLabel->TabIndex = 198;
            this->RPageSizeLabel->Text = L"PageSize:";
            // 
            // PageHeightTextBox
            // 
            this->PageHeightTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->PageHeightTextBox->Location = System::Drawing::Point(168, 34);
            this->PageHeightTextBox->Margin = System::Windows::Forms::Padding(2);
            this->PageHeightTextBox->Name = L"PageHeightTextBox";
            this->PageHeightTextBox->Size = System::Drawing::Size(192, 20);
            this->PageHeightTextBox->TabIndex = 193;
            this->PageHeightTextBox->Text = L"2";
            // 
            // PageHeightLabel
            // 
            this->PageHeightLabel->AutoSize = true;
            this->PageHeightLabel->Location = System::Drawing::Point(18, 36);
            this->PageHeightLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->PageHeightLabel->Name = L"PageHeightLabel";
            this->PageHeightLabel->Size = System::Drawing::Size(41, 13);
            this->PageHeightLabel->TabIndex = 197;
            this->PageHeightLabel->Text = L"Height:";
            // 
            // PageWidthTextBox
            // 
            this->PageWidthTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->PageWidthTextBox->Location = System::Drawing::Point(168, 10);
            this->PageWidthTextBox->Margin = System::Windows::Forms::Padding(2);
            this->PageWidthTextBox->Name = L"PageWidthTextBox";
            this->PageWidthTextBox->Size = System::Drawing::Size(192, 20);
            this->PageWidthTextBox->TabIndex = 192;
            this->PageWidthTextBox->Text = L"2";
            // 
            // PageWidthLabel
            // 
            this->PageWidthLabel->AutoSize = true;
            this->PageWidthLabel->Location = System::Drawing::Point(18, 13);
            this->PageWidthLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->PageWidthLabel->Name = L"PageWidthLabel";
            this->PageWidthLabel->Size = System::Drawing::Size(38, 13);
            this->PageWidthLabel->TabIndex = 196;
            this->PageWidthLabel->Text = L"Width:";
            // 
            // RPropertiesTabPage
            // 
            this->RPropertiesTabPage->AutoScroll = true;
            this->RPropertiesTabPage->Controls->Add(this->MaxPixelErrorTextBox);
            this->RPropertiesTabPage->Controls->Add(this->MaxPixelErrorLabel);
            this->RPropertiesTabPage->Controls->Add(this->LODMorphStartTextBox);
            this->RPropertiesTabPage->Controls->Add(this->LODMorphStartLabel);
            this->RPropertiesTabPage->Controls->Add(this->VertexCompressionCheckBox);
            this->RPropertiesTabPage->Controls->Add(this->DeformableCheckBox);
            this->RPropertiesTabPage->Controls->Add(this->VertexProgramMorphCheckBox);
            this->RPropertiesTabPage->Controls->Add(this->RTerrainScaleZTextBox);
            this->RPropertiesTabPage->Controls->Add(this->RTerrainScaleZLabel);
            this->RPropertiesTabPage->Controls->Add(this->RTerrainScaleYTextBox);
            this->RPropertiesTabPage->Controls->Add(this->RTerrainScaleYLabel);
            this->RPropertiesTabPage->Controls->Add(this->RTerrainScaleXTextBox);
            this->RPropertiesTabPage->Controls->Add(this->RTerrainScaleXLabel);
            this->RPropertiesTabPage->Location = System::Drawing::Point(4, 22);
            this->RPropertiesTabPage->Margin = System::Windows::Forms::Padding(2);
            this->RPropertiesTabPage->Name = L"RPropertiesTabPage";
            this->RPropertiesTabPage->Size = System::Drawing::Size(401, 241);
            this->RPropertiesTabPage->TabIndex = 2;
            this->RPropertiesTabPage->Text = L"Properties";
            this->RPropertiesTabPage->UseVisualStyleBackColor = true;
            // 
            // MaxPixelErrorTextBox
            // 
            this->MaxPixelErrorTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->MaxPixelErrorTextBox->Location = System::Drawing::Point(168, 175);
            this->MaxPixelErrorTextBox->Margin = System::Windows::Forms::Padding(2);
            this->MaxPixelErrorTextBox->Name = L"MaxPixelErrorTextBox";
            this->MaxPixelErrorTextBox->Size = System::Drawing::Size(192, 20);
            this->MaxPixelErrorTextBox->TabIndex = 229;
            this->MaxPixelErrorTextBox->Text = L"3";
            // 
            // MaxPixelErrorLabel
            // 
            this->MaxPixelErrorLabel->AutoSize = true;
            this->MaxPixelErrorLabel->Location = System::Drawing::Point(18, 178);
            this->MaxPixelErrorLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->MaxPixelErrorLabel->Name = L"MaxPixelErrorLabel";
            this->MaxPixelErrorLabel->Size = System::Drawing::Size(74, 13);
            this->MaxPixelErrorLabel->TabIndex = 230;
            this->MaxPixelErrorLabel->Text = L"MaxPixelError:";
            // 
            // LODMorphStartTextBox
            // 
            this->LODMorphStartTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->LODMorphStartTextBox->Location = System::Drawing::Point(168, 152);
            this->LODMorphStartTextBox->Margin = System::Windows::Forms::Padding(2);
            this->LODMorphStartTextBox->Name = L"LODMorphStartTextBox";
            this->LODMorphStartTextBox->Size = System::Drawing::Size(192, 20);
            this->LODMorphStartTextBox->TabIndex = 226;
            this->LODMorphStartTextBox->Text = L"0.2";
            // 
            // LODMorphStartLabel
            // 
            this->LODMorphStartLabel->AutoSize = true;
            this->LODMorphStartLabel->Location = System::Drawing::Point(18, 154);
            this->LODMorphStartLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->LODMorphStartLabel->Name = L"LODMorphStartLabel";
            this->LODMorphStartLabel->Size = System::Drawing::Size(84, 13);
            this->LODMorphStartLabel->TabIndex = 227;
            this->LODMorphStartLabel->Text = L"LODMorphStart:";
            // 
            // VertexCompressionCheckBox
            // 
            this->VertexCompressionCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->VertexCompressionCheckBox->Checked = true;
            this->VertexCompressionCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
            this->VertexCompressionCheckBox->Location = System::Drawing::Point(17, 105);
            this->VertexCompressionCheckBox->Margin = System::Windows::Forms::Padding(2);
            this->VertexCompressionCheckBox->Name = L"VertexCompressionCheckBox";
            this->VertexCompressionCheckBox->Size = System::Drawing::Size(231, 20);
            this->VertexCompressionCheckBox->TabIndex = 220;
            this->VertexCompressionCheckBox->Text = L"VertexCompression:";
            this->VertexCompressionCheckBox->UseVisualStyleBackColor = true;
            // 
            // DeformableCheckBox
            // 
            this->DeformableCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->DeformableCheckBox->Checked = true;
            this->DeformableCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
            this->DeformableCheckBox->Location = System::Drawing::Point(17, 81);
            this->DeformableCheckBox->Margin = System::Windows::Forms::Padding(2);
            this->DeformableCheckBox->Name = L"DeformableCheckBox";
            this->DeformableCheckBox->Size = System::Drawing::Size(231, 20);
            this->DeformableCheckBox->TabIndex = 219;
            this->DeformableCheckBox->Text = L"Deformable:";
            this->DeformableCheckBox->UseVisualStyleBackColor = true;
            // 
            // VertexProgramMorphCheckBox
            // 
            this->VertexProgramMorphCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->VertexProgramMorphCheckBox->Checked = true;
            this->VertexProgramMorphCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
            this->VertexProgramMorphCheckBox->Location = System::Drawing::Point(17, 128);
            this->VertexProgramMorphCheckBox->Margin = System::Windows::Forms::Padding(2);
            this->VertexProgramMorphCheckBox->Name = L"VertexProgramMorphCheckBox";
            this->VertexProgramMorphCheckBox->Size = System::Drawing::Size(231, 20);
            this->VertexProgramMorphCheckBox->TabIndex = 221;
            this->VertexProgramMorphCheckBox->Text = L"VertexProgramMorph:";
            this->VertexProgramMorphCheckBox->UseVisualStyleBackColor = true;
            // 
            // RTerrainScaleZTextBox
            // 
            this->RTerrainScaleZTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->RTerrainScaleZTextBox->Location = System::Drawing::Point(168, 58);
            this->RTerrainScaleZTextBox->Margin = System::Windows::Forms::Padding(2);
            this->RTerrainScaleZTextBox->Name = L"RTerrainScaleZTextBox";
            this->RTerrainScaleZTextBox->ReadOnly = true;
            this->RTerrainScaleZTextBox->Size = System::Drawing::Size(192, 20);
            this->RTerrainScaleZTextBox->TabIndex = 203;
            this->RTerrainScaleZTextBox->Text = L"90000";
            // 
            // RTerrainScaleZLabel
            // 
            this->RTerrainScaleZLabel->AutoSize = true;
            this->RTerrainScaleZLabel->Location = System::Drawing::Point(18, 60);
            this->RTerrainScaleZLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->RTerrainScaleZLabel->Name = L"RTerrainScaleZLabel";
            this->RTerrainScaleZLabel->Size = System::Drawing::Size(44, 13);
            this->RTerrainScaleZLabel->TabIndex = 206;
            this->RTerrainScaleZLabel->Text = L"ScaleZ:";
            // 
            // RTerrainScaleYTextBox
            // 
            this->RTerrainScaleYTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->RTerrainScaleYTextBox->Location = System::Drawing::Point(168, 34);
            this->RTerrainScaleYTextBox->Margin = System::Windows::Forms::Padding(2);
            this->RTerrainScaleYTextBox->Name = L"RTerrainScaleYTextBox";
            this->RTerrainScaleYTextBox->ReadOnly = true;
            this->RTerrainScaleYTextBox->Size = System::Drawing::Size(192, 20);
            this->RTerrainScaleYTextBox->TabIndex = 202;
            this->RTerrainScaleYTextBox->Text = L"15000";
            // 
            // RTerrainScaleYLabel
            // 
            this->RTerrainScaleYLabel->AutoSize = true;
            this->RTerrainScaleYLabel->Location = System::Drawing::Point(18, 36);
            this->RTerrainScaleYLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->RTerrainScaleYLabel->Name = L"RTerrainScaleYLabel";
            this->RTerrainScaleYLabel->Size = System::Drawing::Size(44, 13);
            this->RTerrainScaleYLabel->TabIndex = 205;
            this->RTerrainScaleYLabel->Text = L"ScaleY:";
            // 
            // RTerrainScaleXTextBox
            // 
            this->RTerrainScaleXTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->RTerrainScaleXTextBox->Location = System::Drawing::Point(168, 9);
            this->RTerrainScaleXTextBox->Margin = System::Windows::Forms::Padding(2);
            this->RTerrainScaleXTextBox->Name = L"RTerrainScaleXTextBox";
            this->RTerrainScaleXTextBox->ReadOnly = true;
            this->RTerrainScaleXTextBox->Size = System::Drawing::Size(192, 20);
            this->RTerrainScaleXTextBox->TabIndex = 201;
            this->RTerrainScaleXTextBox->Text = L"90000";
            // 
            // RTerrainScaleXLabel
            // 
            this->RTerrainScaleXLabel->AutoSize = true;
            this->RTerrainScaleXLabel->Location = System::Drawing::Point(18, 13);
            this->RTerrainScaleXLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->RTerrainScaleXLabel->Name = L"RTerrainScaleXLabel";
            this->RTerrainScaleXLabel->Size = System::Drawing::Size(44, 13);
            this->RTerrainScaleXLabel->TabIndex = 204;
            this->RTerrainScaleXLabel->Text = L"ScaleX:";
            // 
            // RLightingTabPage
            // 
            this->RLightingTabPage->Controls->Add(this->VertexNormalsCheckBox);
            this->RLightingTabPage->Controls->Add(this->VertexLitCheckBox);
            this->RLightingTabPage->Location = System::Drawing::Point(4, 22);
            this->RLightingTabPage->Margin = System::Windows::Forms::Padding(2);
            this->RLightingTabPage->Name = L"RLightingTabPage";
            this->RLightingTabPage->Size = System::Drawing::Size(401, 241);
            this->RLightingTabPage->TabIndex = 3;
            this->RLightingTabPage->Text = L"Lighting";
            this->RLightingTabPage->UseVisualStyleBackColor = true;
            // 
            // VertexNormalsCheckBox
            // 
            this->VertexNormalsCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->VertexNormalsCheckBox->Location = System::Drawing::Point(18, 6);
            this->VertexNormalsCheckBox->Margin = System::Windows::Forms::Padding(2);
            this->VertexNormalsCheckBox->Name = L"VertexNormalsCheckBox";
            this->VertexNormalsCheckBox->Size = System::Drawing::Size(231, 20);
            this->VertexNormalsCheckBox->TabIndex = 224;
            this->VertexNormalsCheckBox->Text = L"VertexNormals:";
            this->VertexNormalsCheckBox->UseVisualStyleBackColor = true;
            // 
            // VertexLitCheckBox
            // 
            this->VertexLitCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->VertexLitCheckBox->Location = System::Drawing::Point(18, 30);
            this->VertexLitCheckBox->Margin = System::Windows::Forms::Padding(2);
            this->VertexLitCheckBox->Name = L"VertexLitCheckBox";
            this->VertexLitCheckBox->Size = System::Drawing::Size(231, 20);
            this->VertexLitCheckBox->TabIndex = 225;
            this->VertexLitCheckBox->Text = L"VertexLit:";
            this->VertexLitCheckBox->UseVisualStyleBackColor = true;
            // 
            // RTextureTabPage
            // 
            this->RTextureTabPage->AutoScroll = true;
            this->RTextureTabPage->Controls->Add(this->RSetSplatFileNamesRichTextBox);
            this->RTextureTabPage->Controls->Add(this->RSetMaterialHeightRichTextBox);
            this->RTextureTabPage->Controls->Add(this->RSetMaterialHeightLabel);
            this->RTextureTabPage->Controls->Add(this->RSetMaterialColorRichTextBox);
            this->RTextureTabPage->Controls->Add(this->RSetSplatFileNamesLabel);
            this->RTextureTabPage->Controls->Add(this->RSetMaterialColorLabel);
            this->RTextureTabPage->Controls->Add(this->TextureFormatSupportedRichTextBox);
            this->RTextureTabPage->Controls->Add(this->RNumMatHeightSplatTextBox);
            this->RTextureTabPage->Controls->Add(this->RNumMatHeightSplatLabel);
            this->RTextureTabPage->Controls->Add(this->BaseVertexInstantColorCheckBox);
            this->RTextureTabPage->Controls->Add(this->BaseVertexShadowCheckBox);
            this->RTextureTabPage->Controls->Add(this->BaseVertexColorCheckBox);
            this->RTextureTabPage->Controls->Add(this->VertexColorsCheckBox);
            this->RTextureTabPage->Controls->Add(this->BigImageCheckBox);
            this->RTextureTabPage->Controls->Add(this->CoverageVertexColorCheckBox);
            this->RTextureTabPage->Controls->Add(this->TextureFormatTextBox);
            this->RTextureTabPage->Controls->Add(this->TextureFormatLabel);
            this->RTextureTabPage->Controls->Add(this->NumTextureFormatSupportedTextBox);
            this->RTextureTabPage->Controls->Add(this->NumTextureFormatSupportedLabel);
            this->RTextureTabPage->Controls->Add(this->RColorMapStretchFactorTextBox);
            this->RTextureTabPage->Controls->Add(this->RColorMapStretchFactorLabel);
            this->RTextureTabPage->Location = System::Drawing::Point(4, 22);
            this->RTextureTabPage->Margin = System::Windows::Forms::Padding(2);
            this->RTextureTabPage->Name = L"RTextureTabPage";
            this->RTextureTabPage->Size = System::Drawing::Size(401, 241);
            this->RTextureTabPage->TabIndex = 4;
            this->RTextureTabPage->Text = L"Texture";
            this->RTextureTabPage->UseVisualStyleBackColor = true;
            // 
            // RSetSplatFileNamesRichTextBox
            // 
            this->RSetSplatFileNamesRichTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->RSetSplatFileNamesRichTextBox->Location = System::Drawing::Point(21, 372);
            this->RSetSplatFileNamesRichTextBox->Margin = System::Windows::Forms::Padding(2);
            this->RSetSplatFileNamesRichTextBox->Name = L"RSetSplatFileNamesRichTextBox";
            this->RSetSplatFileNamesRichTextBox->ReadOnly = true;
            this->RSetSplatFileNamesRichTextBox->Size = System::Drawing::Size(326, 70);
            this->RSetSplatFileNamesRichTextBox->TabIndex = 368;
            this->RSetSplatFileNamesRichTextBox->Text = L"#needs to be in maptool directory\nSplatFilename0=splatting_sand.png\nSplatFilename" 
                L"1=splatting_grass.png\nSplatFilename2=splatting_rock.png\nSplatFilename3=splatting" 
                L"_snow.png";
            this->RSetSplatFileNamesRichTextBox->WordWrap = false;
            // 
            // RSetMaterialHeightRichTextBox
            // 
            this->RSetMaterialHeightRichTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->RSetMaterialHeightRichTextBox->Location = System::Drawing::Point(21, 198);
            this->RSetMaterialHeightRichTextBox->Margin = System::Windows::Forms::Padding(2);
            this->RSetMaterialHeightRichTextBox->Name = L"RSetMaterialHeightRichTextBox";
            this->RSetMaterialHeightRichTextBox->ReadOnly = true;
            this->RSetMaterialHeightRichTextBox->Size = System::Drawing::Size(326, 70);
            this->RSetMaterialHeightRichTextBox->TabIndex = 367;
            this->RSetMaterialHeightRichTextBox->Text = L"MaterialHeight0=0\nMaterialHeight1=12\nMaterialHeight2=60\nMaterialHeight3=75";
            this->RSetMaterialHeightRichTextBox->WordWrap = false;
            // 
            // RSetMaterialHeightLabel
            // 
            this->RSetMaterialHeightLabel->AutoSize = true;
            this->RSetMaterialHeightLabel->Location = System::Drawing::Point(18, 185);
            this->RSetMaterialHeightLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->RSetMaterialHeightLabel->Name = L"RSetMaterialHeightLabel";
            this->RSetMaterialHeightLabel->Size = System::Drawing::Size(97, 13);
            this->RSetMaterialHeightLabel->TabIndex = 366;
            this->RSetMaterialHeightLabel->Text = L"Set Material Height";
            // 
            // RSetMaterialColorRichTextBox
            // 
            this->RSetMaterialColorRichTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->RSetMaterialColorRichTextBox->Location = System::Drawing::Point(21, 285);
            this->RSetMaterialColorRichTextBox->Margin = System::Windows::Forms::Padding(2);
            this->RSetMaterialColorRichTextBox->Name = L"RSetMaterialColorRichTextBox";
            this->RSetMaterialColorRichTextBox->ReadOnly = true;
            this->RSetMaterialColorRichTextBox->Size = System::Drawing::Size(326, 70);
            this->RSetMaterialColorRichTextBox->TabIndex = 364;
            this->RSetMaterialColorRichTextBox->Text = L"#Sand\nMaterialColor0=1.0f 1.0f 0.0f 1.0f\n#Grass\nMaterialColor1=0.13f 0.545f 0.13f" 
                L" 1.0f\n#Rock\nMaterialColor2=0.411764f 0.411764f 0.411764f 1.0f\n#Snow\nMaterialColo" 
                L"r3=1.0f 0.98f 0.98f 1.0f";
            this->RSetMaterialColorRichTextBox->WordWrap = false;
            // 
            // RSetSplatFileNamesLabel
            // 
            this->RSetSplatFileNamesLabel->AutoSize = true;
            this->RSetSplatFileNamesLabel->Location = System::Drawing::Point(18, 357);
            this->RSetSplatFileNamesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->RSetSplatFileNamesLabel->Name = L"RSetSplatFileNamesLabel";
            this->RSetSplatFileNamesLabel->Size = System::Drawing::Size(105, 13);
            this->RSetSplatFileNamesLabel->TabIndex = 363;
            this->RSetSplatFileNamesLabel->Text = L"Set Splat File Names";
            // 
            // RSetMaterialColorLabel
            // 
            this->RSetMaterialColorLabel->AutoSize = true;
            this->RSetMaterialColorLabel->Location = System::Drawing::Point(18, 270);
            this->RSetMaterialColorLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->RSetMaterialColorLabel->Name = L"RSetMaterialColorLabel";
            this->RSetMaterialColorLabel->Size = System::Drawing::Size(90, 13);
            this->RSetMaterialColorLabel->TabIndex = 362;
            this->RSetMaterialColorLabel->Text = L"Set Material Color";
            // 
            // TextureFormatSupportedRichTextBox
            // 
            this->TextureFormatSupportedRichTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->TextureFormatSupportedRichTextBox->Location = System::Drawing::Point(21, 62);
            this->TextureFormatSupportedRichTextBox->Margin = System::Windows::Forms::Padding(2);
            this->TextureFormatSupportedRichTextBox->Name = L"TextureFormatSupportedRichTextBox";
            this->TextureFormatSupportedRichTextBox->Size = System::Drawing::Size(326, 70);
            this->TextureFormatSupportedRichTextBox->TabIndex = 359;
            this->TextureFormatSupportedRichTextBox->Text = L"";
            this->TextureFormatSupportedRichTextBox->WordWrap = false;
            // 
            // RNumMatHeightSplatTextBox
            // 
            this->RNumMatHeightSplatTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->RNumMatHeightSplatTextBox->Location = System::Drawing::Point(183, 160);
            this->RNumMatHeightSplatTextBox->Margin = System::Windows::Forms::Padding(2);
            this->RNumMatHeightSplatTextBox->MinimumSize = System::Drawing::Size(126, 22);
            this->RNumMatHeightSplatTextBox->Name = L"RNumMatHeightSplatTextBox";
            this->RNumMatHeightSplatTextBox->ReadOnly = true;
            this->RNumMatHeightSplatTextBox->Size = System::Drawing::Size(164, 22);
            this->RNumMatHeightSplatTextBox->TabIndex = 352;
            this->RNumMatHeightSplatTextBox->Text = L"4";
            // 
            // RNumMatHeightSplatLabel
            // 
            this->RNumMatHeightSplatLabel->AutoSize = true;
            this->RNumMatHeightSplatLabel->Location = System::Drawing::Point(18, 162);
            this->RNumMatHeightSplatLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->RNumMatHeightSplatLabel->Name = L"RNumMatHeightSplatLabel";
            this->RNumMatHeightSplatLabel->Size = System::Drawing::Size(105, 13);
            this->RNumMatHeightSplatLabel->TabIndex = 351;
            this->RNumMatHeightSplatLabel->Text = L"NumMatHeightSplat:";
            // 
            // BaseVertexInstantColorCheckBox
            // 
            this->BaseVertexInstantColorCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->BaseVertexInstantColorCheckBox->Location = System::Drawing::Point(21, 564);
            this->BaseVertexInstantColorCheckBox->Margin = System::Windows::Forms::Padding(2);
            this->BaseVertexInstantColorCheckBox->Name = L"BaseVertexInstantColorCheckBox";
            this->BaseVertexInstantColorCheckBox->Size = System::Drawing::Size(231, 20);
            this->BaseVertexInstantColorCheckBox->TabIndex = 347;
            this->BaseVertexInstantColorCheckBox->Text = L"BaseVertexInstantColor:";
            this->BaseVertexInstantColorCheckBox->UseVisualStyleBackColor = true;
            // 
            // BaseVertexShadowCheckBox
            // 
            this->BaseVertexShadowCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->BaseVertexShadowCheckBox->Location = System::Drawing::Point(21, 541);
            this->BaseVertexShadowCheckBox->Margin = System::Windows::Forms::Padding(2);
            this->BaseVertexShadowCheckBox->Name = L"BaseVertexShadowCheckBox";
            this->BaseVertexShadowCheckBox->Size = System::Drawing::Size(231, 20);
            this->BaseVertexShadowCheckBox->TabIndex = 346;
            this->BaseVertexShadowCheckBox->Text = L"BaseVertexShadow:";
            this->BaseVertexShadowCheckBox->UseVisualStyleBackColor = true;
            // 
            // BaseVertexColorCheckBox
            // 
            this->BaseVertexColorCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->BaseVertexColorCheckBox->Location = System::Drawing::Point(21, 516);
            this->BaseVertexColorCheckBox->Margin = System::Windows::Forms::Padding(2);
            this->BaseVertexColorCheckBox->Name = L"BaseVertexColorCheckBox";
            this->BaseVertexColorCheckBox->Size = System::Drawing::Size(231, 20);
            this->BaseVertexColorCheckBox->TabIndex = 338;
            this->BaseVertexColorCheckBox->Text = L"BaseVertexColor:";
            this->BaseVertexColorCheckBox->UseVisualStyleBackColor = true;
            // 
            // VertexColorsCheckBox
            // 
            this->VertexColorsCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->VertexColorsCheckBox->Location = System::Drawing::Point(21, 470);
            this->VertexColorsCheckBox->Margin = System::Windows::Forms::Padding(2);
            this->VertexColorsCheckBox->Name = L"VertexColorsCheckBox";
            this->VertexColorsCheckBox->Size = System::Drawing::Size(231, 20);
            this->VertexColorsCheckBox->TabIndex = 336;
            this->VertexColorsCheckBox->Text = L"VertexColors:";
            this->VertexColorsCheckBox->UseVisualStyleBackColor = true;
            // 
            // BigImageCheckBox
            // 
            this->BigImageCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->BigImageCheckBox->Location = System::Drawing::Point(21, 446);
            this->BigImageCheckBox->Margin = System::Windows::Forms::Padding(2);
            this->BigImageCheckBox->Name = L"BigImageCheckBox";
            this->BigImageCheckBox->Size = System::Drawing::Size(231, 20);
            this->BigImageCheckBox->TabIndex = 335;
            this->BigImageCheckBox->Text = L"BigImage:";
            this->BigImageCheckBox->UseVisualStyleBackColor = true;
            // 
            // CoverageVertexColorCheckBox
            // 
            this->CoverageVertexColorCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->CoverageVertexColorCheckBox->Location = System::Drawing::Point(21, 493);
            this->CoverageVertexColorCheckBox->Margin = System::Windows::Forms::Padding(2);
            this->CoverageVertexColorCheckBox->Name = L"CoverageVertexColorCheckBox";
            this->CoverageVertexColorCheckBox->Size = System::Drawing::Size(231, 20);
            this->CoverageVertexColorCheckBox->TabIndex = 337;
            this->CoverageVertexColorCheckBox->Text = L"CoverageVertexColor:";
            this->CoverageVertexColorCheckBox->UseVisualStyleBackColor = true;
            // 
            // TextureFormatTextBox
            // 
            this->TextureFormatTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->TextureFormatTextBox->Location = System::Drawing::Point(183, 136);
            this->TextureFormatTextBox->Margin = System::Windows::Forms::Padding(2);
            this->TextureFormatTextBox->MinimumSize = System::Drawing::Size(126, 22);
            this->TextureFormatTextBox->Name = L"TextureFormatTextBox";
            this->TextureFormatTextBox->Size = System::Drawing::Size(164, 22);
            this->TextureFormatTextBox->TabIndex = 332;
            this->TextureFormatTextBox->Text = L"ImagePaging";
            // 
            // TextureFormatLabel
            // 
            this->TextureFormatLabel->AutoSize = true;
            this->TextureFormatLabel->Location = System::Drawing::Point(18, 139);
            this->TextureFormatLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->TextureFormatLabel->Name = L"TextureFormatLabel";
            this->TextureFormatLabel->Size = System::Drawing::Size(78, 13);
            this->TextureFormatLabel->TabIndex = 334;
            this->TextureFormatLabel->Text = L"TextureFormat:";
            // 
            // NumTextureFormatSupportedTextBox
            // 
            this->NumTextureFormatSupportedTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->NumTextureFormatSupportedTextBox->Location = System::Drawing::Point(183, 36);
            this->NumTextureFormatSupportedTextBox->Margin = System::Windows::Forms::Padding(2);
            this->NumTextureFormatSupportedTextBox->MinimumSize = System::Drawing::Size(126, 22);
            this->NumTextureFormatSupportedTextBox->Name = L"NumTextureFormatSupportedTextBox";
            this->NumTextureFormatSupportedTextBox->Size = System::Drawing::Size(164, 22);
            this->NumTextureFormatSupportedTextBox->TabIndex = 329;
            this->NumTextureFormatSupportedTextBox->Text = L"16";
            // 
            // NumTextureFormatSupportedLabel
            // 
            this->NumTextureFormatSupportedLabel->AutoSize = true;
            this->NumTextureFormatSupportedLabel->Location = System::Drawing::Point(18, 38);
            this->NumTextureFormatSupportedLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->NumTextureFormatSupportedLabel->Name = L"NumTextureFormatSupportedLabel";
            this->NumTextureFormatSupportedLabel->Size = System::Drawing::Size(149, 13);
            this->NumTextureFormatSupportedLabel->TabIndex = 331;
            this->NumTextureFormatSupportedLabel->Text = L"NumTextureFormatSupported:";
            // 
            // RColorMapStretchFactorTextBox
            // 
            this->RColorMapStretchFactorTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->RColorMapStretchFactorTextBox->Location = System::Drawing::Point(183, 10);
            this->RColorMapStretchFactorTextBox->Margin = System::Windows::Forms::Padding(2);
            this->RColorMapStretchFactorTextBox->MinimumSize = System::Drawing::Size(126, 22);
            this->RColorMapStretchFactorTextBox->Name = L"RColorMapStretchFactorTextBox";
            this->RColorMapStretchFactorTextBox->ReadOnly = true;
            this->RColorMapStretchFactorTextBox->Size = System::Drawing::Size(164, 22);
            this->RColorMapStretchFactorTextBox->TabIndex = 324;
            this->RColorMapStretchFactorTextBox->Text = L"2";
            // 
            // RColorMapStretchFactorLabel
            // 
            this->RColorMapStretchFactorLabel->AutoSize = true;
            this->RColorMapStretchFactorLabel->Location = System::Drawing::Point(18, 13);
            this->RColorMapStretchFactorLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->RColorMapStretchFactorLabel->Name = L"RColorMapStretchFactorLabel";
            this->RColorMapStretchFactorLabel->Size = System::Drawing::Size(119, 13);
            this->RColorMapStretchFactorLabel->TabIndex = 328;
            this->RColorMapStretchFactorLabel->Text = L"ColorMapStretchFactor:";
            // 
            // RPerformanceTabPage
            // 
            this->RPerformanceTabPage->AutoScroll = true;
            this->RPerformanceTabPage->Controls->Add(this->HorizonVisibilityComputingCheckBox);
            this->RPerformanceTabPage->Controls->Add(this->IncrementTilesTextBox);
            this->RPerformanceTabPage->Controls->Add(this->IncrementTilesLabel);
            this->RPerformanceTabPage->Controls->Add(this->MaxNumRenderablesTextBox);
            this->RPerformanceTabPage->Controls->Add(this->MaxNumTilesTextBox);
            this->RPerformanceTabPage->Controls->Add(this->MaxNumTilesLabel);
            this->RPerformanceTabPage->Controls->Add(this->IncrementRenderablesTextBox);
            this->RPerformanceTabPage->Controls->Add(this->IncrementRenderablesLabel);
            this->RPerformanceTabPage->Controls->Add(this->MaxNumRenderablesLabel);
            this->RPerformanceTabPage->Controls->Add(this->CameraThresholdTextBox);
            this->RPerformanceTabPage->Controls->Add(this->CameraThresholdLabel);
            this->RPerformanceTabPage->Controls->Add(this->ChangeFactorTextBox);
            this->RPerformanceTabPage->Controls->Add(this->ChangeFactorLabel);
            this->RPerformanceTabPage->Controls->Add(this->MaxPreloadedPagesTextBox);
            this->RPerformanceTabPage->Controls->Add(this->MaxPreloadedPagesLabel);
            this->RPerformanceTabPage->Controls->Add(this->MaxRenderLevelTextBox);
            this->RPerformanceTabPage->Controls->Add(this->MaxAdjacentPagesTextBox);
            this->RPerformanceTabPage->Controls->Add(this->MaxAdjacentPagesLabel);
            this->RPerformanceTabPage->Controls->Add(this->NumRenderablesLoadingTextBox);
            this->RPerformanceTabPage->Controls->Add(this->NumRenderablesLoadingLabel);
            this->RPerformanceTabPage->Controls->Add(this->MaxRenderLevelLabel);
            this->RPerformanceTabPage->Controls->Add(this->DistanceLODTextBox);
            this->RPerformanceTabPage->Controls->Add(this->DistanceLODLabel);
            this->RPerformanceTabPage->Controls->Add(this->VisibleRenderablesTextBox);
            this->RPerformanceTabPage->Controls->Add(this->VisibleRenderablesLabel);
            this->RPerformanceTabPage->Location = System::Drawing::Point(4, 22);
            this->RPerformanceTabPage->Margin = System::Windows::Forms::Padding(2);
            this->RPerformanceTabPage->Name = L"RPerformanceTabPage";
            this->RPerformanceTabPage->Size = System::Drawing::Size(401, 241);
            this->RPerformanceTabPage->TabIndex = 5;
            this->RPerformanceTabPage->Text = L"Performance";
            this->RPerformanceTabPage->UseVisualStyleBackColor = true;
            // 
            // HorizonVisibilityComputingCheckBox
            // 
            this->HorizonVisibilityComputingCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->HorizonVisibilityComputingCheckBox->Checked = true;
            this->HorizonVisibilityComputingCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
            this->HorizonVisibilityComputingCheckBox->Location = System::Drawing::Point(17, 297);
            this->HorizonVisibilityComputingCheckBox->Margin = System::Windows::Forms::Padding(2);
            this->HorizonVisibilityComputingCheckBox->Name = L"HorizonVisibilityComputingCheckBox";
            this->HorizonVisibilityComputingCheckBox->Size = System::Drawing::Size(231, 20);
            this->HorizonVisibilityComputingCheckBox->TabIndex = 340;
            this->HorizonVisibilityComputingCheckBox->Text = L"HorizonVisibilityComputing:";
            this->HorizonVisibilityComputingCheckBox->UseVisualStyleBackColor = true;
            // 
            // IncrementTilesTextBox
            // 
            this->IncrementTilesTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->IncrementTilesTextBox->Location = System::Drawing::Point(168, 271);
            this->IncrementTilesTextBox->Margin = System::Windows::Forms::Padding(2);
            this->IncrementTilesTextBox->Name = L"IncrementTilesTextBox";
            this->IncrementTilesTextBox->Size = System::Drawing::Size(0, 20);
            this->IncrementTilesTextBox->TabIndex = 326;
            this->IncrementTilesTextBox->Text = L"256";
            // 
            // IncrementTilesLabel
            // 
            this->IncrementTilesLabel->AutoSize = true;
            this->IncrementTilesLabel->Location = System::Drawing::Point(18, 273);
            this->IncrementTilesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->IncrementTilesLabel->Name = L"IncrementTilesLabel";
            this->IncrementTilesLabel->Size = System::Drawing::Size(79, 13);
            this->IncrementTilesLabel->TabIndex = 338;
            this->IncrementTilesLabel->Text = L"IncrementTiles:";
            // 
            // MaxNumRenderablesTextBox
            // 
            this->MaxNumRenderablesTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->MaxNumRenderablesTextBox->Location = System::Drawing::Point(168, 199);
            this->MaxNumRenderablesTextBox->Margin = System::Windows::Forms::Padding(2);
            this->MaxNumRenderablesTextBox->Name = L"MaxNumRenderablesTextBox";
            this->MaxNumRenderablesTextBox->Size = System::Drawing::Size(0, 20);
            this->MaxNumRenderablesTextBox->TabIndex = 323;
            this->MaxNumRenderablesTextBox->Text = L"256";
            // 
            // MaxNumTilesTextBox
            // 
            this->MaxNumTilesTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->MaxNumTilesTextBox->Location = System::Drawing::Point(168, 247);
            this->MaxNumTilesTextBox->Margin = System::Windows::Forms::Padding(2);
            this->MaxNumTilesTextBox->Name = L"MaxNumTilesTextBox";
            this->MaxNumTilesTextBox->Size = System::Drawing::Size(0, 20);
            this->MaxNumTilesTextBox->TabIndex = 325;
            this->MaxNumTilesTextBox->Text = L"256";
            // 
            // MaxNumTilesLabel
            // 
            this->MaxNumTilesLabel->AutoSize = true;
            this->MaxNumTilesLabel->Location = System::Drawing::Point(18, 249);
            this->MaxNumTilesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->MaxNumTilesLabel->Name = L"MaxNumTilesLabel";
            this->MaxNumTilesLabel->Size = System::Drawing::Size(74, 13);
            this->MaxNumTilesLabel->TabIndex = 331;
            this->MaxNumTilesLabel->Text = L"MaxNumTiles:";
            // 
            // IncrementRenderablesTextBox
            // 
            this->IncrementRenderablesTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->IncrementRenderablesTextBox->Location = System::Drawing::Point(168, 223);
            this->IncrementRenderablesTextBox->Margin = System::Windows::Forms::Padding(2);
            this->IncrementRenderablesTextBox->Name = L"IncrementRenderablesTextBox";
            this->IncrementRenderablesTextBox->Size = System::Drawing::Size(0, 20);
            this->IncrementRenderablesTextBox->TabIndex = 324;
            this->IncrementRenderablesTextBox->Text = L"256";
            // 
            // IncrementRenderablesLabel
            // 
            this->IncrementRenderablesLabel->AutoSize = true;
            this->IncrementRenderablesLabel->Location = System::Drawing::Point(18, 226);
            this->IncrementRenderablesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->IncrementRenderablesLabel->Name = L"IncrementRenderablesLabel";
            this->IncrementRenderablesLabel->Size = System::Drawing::Size(117, 13);
            this->IncrementRenderablesLabel->TabIndex = 330;
            this->IncrementRenderablesLabel->Text = L"IncrementRenderables:";
            // 
            // MaxNumRenderablesLabel
            // 
            this->MaxNumRenderablesLabel->AutoSize = true;
            this->MaxNumRenderablesLabel->Location = System::Drawing::Point(18, 201);
            this->MaxNumRenderablesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->MaxNumRenderablesLabel->Name = L"MaxNumRenderablesLabel";
            this->MaxNumRenderablesLabel->Size = System::Drawing::Size(112, 13);
            this->MaxNumRenderablesLabel->TabIndex = 329;
            this->MaxNumRenderablesLabel->Text = L"MaxNumRenderables:";
            // 
            // CameraThresholdTextBox
            // 
            this->CameraThresholdTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->CameraThresholdTextBox->Location = System::Drawing::Point(168, 175);
            this->CameraThresholdTextBox->Margin = System::Windows::Forms::Padding(2);
            this->CameraThresholdTextBox->Name = L"CameraThresholdTextBox";
            this->CameraThresholdTextBox->Size = System::Drawing::Size(0, 20);
            this->CameraThresholdTextBox->TabIndex = 322;
            this->CameraThresholdTextBox->Text = L"5";
            // 
            // CameraThresholdLabel
            // 
            this->CameraThresholdLabel->AutoSize = true;
            this->CameraThresholdLabel->Location = System::Drawing::Point(18, 178);
            this->CameraThresholdLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->CameraThresholdLabel->Name = L"CameraThresholdLabel";
            this->CameraThresholdLabel->Size = System::Drawing::Size(93, 13);
            this->CameraThresholdLabel->TabIndex = 328;
            this->CameraThresholdLabel->Text = L"CameraThreshold:";
            // 
            // ChangeFactorTextBox
            // 
            this->ChangeFactorTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->ChangeFactorTextBox->Location = System::Drawing::Point(168, 152);
            this->ChangeFactorTextBox->Margin = System::Windows::Forms::Padding(2);
            this->ChangeFactorTextBox->Name = L"ChangeFactorTextBox";
            this->ChangeFactorTextBox->Size = System::Drawing::Size(0, 20);
            this->ChangeFactorTextBox->TabIndex = 321;
            this->ChangeFactorTextBox->Text = L"1.5";
            // 
            // ChangeFactorLabel
            // 
            this->ChangeFactorLabel->AutoSize = true;
            this->ChangeFactorLabel->Location = System::Drawing::Point(18, 157);
            this->ChangeFactorLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->ChangeFactorLabel->Name = L"ChangeFactorLabel";
            this->ChangeFactorLabel->Size = System::Drawing::Size(77, 13);
            this->ChangeFactorLabel->TabIndex = 327;
            this->ChangeFactorLabel->Text = L"ChangeFactor:";
            // 
            // MaxPreloadedPagesTextBox
            // 
            this->MaxPreloadedPagesTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->MaxPreloadedPagesTextBox->Location = System::Drawing::Point(168, 128);
            this->MaxPreloadedPagesTextBox->Margin = System::Windows::Forms::Padding(2);
            this->MaxPreloadedPagesTextBox->Name = L"MaxPreloadedPagesTextBox";
            this->MaxPreloadedPagesTextBox->Size = System::Drawing::Size(0, 20);
            this->MaxPreloadedPagesTextBox->TabIndex = 308;
            this->MaxPreloadedPagesTextBox->Text = L"3";
            // 
            // MaxPreloadedPagesLabel
            // 
            this->MaxPreloadedPagesLabel->AutoSize = true;
            this->MaxPreloadedPagesLabel->Location = System::Drawing::Point(18, 131);
            this->MaxPreloadedPagesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->MaxPreloadedPagesLabel->Name = L"MaxPreloadedPagesLabel";
            this->MaxPreloadedPagesLabel->Size = System::Drawing::Size(108, 13);
            this->MaxPreloadedPagesLabel->TabIndex = 320;
            this->MaxPreloadedPagesLabel->Text = L"MaxPreloadedPages:";
            // 
            // MaxRenderLevelTextBox
            // 
            this->MaxRenderLevelTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->MaxRenderLevelTextBox->Location = System::Drawing::Point(168, 58);
            this->MaxRenderLevelTextBox->Margin = System::Windows::Forms::Padding(2);
            this->MaxRenderLevelTextBox->Name = L"MaxRenderLevelTextBox";
            this->MaxRenderLevelTextBox->Size = System::Drawing::Size(0, 20);
            this->MaxRenderLevelTextBox->TabIndex = 305;
            this->MaxRenderLevelTextBox->Text = L"5";
            // 
            // MaxAdjacentPagesTextBox
            // 
            this->MaxAdjacentPagesTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->MaxAdjacentPagesTextBox->Location = System::Drawing::Point(168, 105);
            this->MaxAdjacentPagesTextBox->Margin = System::Windows::Forms::Padding(2);
            this->MaxAdjacentPagesTextBox->Name = L"MaxAdjacentPagesTextBox";
            this->MaxAdjacentPagesTextBox->Size = System::Drawing::Size(0, 20);
            this->MaxAdjacentPagesTextBox->TabIndex = 307;
            this->MaxAdjacentPagesTextBox->Text = L"2";
            // 
            // MaxAdjacentPagesLabel
            // 
            this->MaxAdjacentPagesLabel->AutoSize = true;
            this->MaxAdjacentPagesLabel->Location = System::Drawing::Point(18, 107);
            this->MaxAdjacentPagesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->MaxAdjacentPagesLabel->Name = L"MaxAdjacentPagesLabel";
            this->MaxAdjacentPagesLabel->Size = System::Drawing::Size(102, 13);
            this->MaxAdjacentPagesLabel->TabIndex = 313;
            this->MaxAdjacentPagesLabel->Text = L"MaxAdjacentPages:";
            // 
            // NumRenderablesLoadingTextBox
            // 
            this->NumRenderablesLoadingTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->NumRenderablesLoadingTextBox->Location = System::Drawing::Point(168, 81);
            this->NumRenderablesLoadingTextBox->Margin = System::Windows::Forms::Padding(2);
            this->NumRenderablesLoadingTextBox->Name = L"NumRenderablesLoadingTextBox";
            this->NumRenderablesLoadingTextBox->Size = System::Drawing::Size(0, 20);
            this->NumRenderablesLoadingTextBox->TabIndex = 306;
            this->NumRenderablesLoadingTextBox->Text = L"50";
            // 
            // NumRenderablesLoadingLabel
            // 
            this->NumRenderablesLoadingLabel->AutoSize = true;
            this->NumRenderablesLoadingLabel->Location = System::Drawing::Point(18, 84);
            this->NumRenderablesLoadingLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->NumRenderablesLoadingLabel->Name = L"NumRenderablesLoadingLabel";
            this->NumRenderablesLoadingLabel->Size = System::Drawing::Size(130, 13);
            this->NumRenderablesLoadingLabel->TabIndex = 312;
            this->NumRenderablesLoadingLabel->Text = L"NumRenderablesLoading:";
            // 
            // MaxRenderLevelLabel
            // 
            this->MaxRenderLevelLabel->AutoSize = true;
            this->MaxRenderLevelLabel->Location = System::Drawing::Point(18, 60);
            this->MaxRenderLevelLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->MaxRenderLevelLabel->Name = L"MaxRenderLevelLabel";
            this->MaxRenderLevelLabel->Size = System::Drawing::Size(91, 13);
            this->MaxRenderLevelLabel->TabIndex = 311;
            this->MaxRenderLevelLabel->Text = L"MaxRenderLevel:";
            // 
            // DistanceLODTextBox
            // 
            this->DistanceLODTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->DistanceLODTextBox->Location = System::Drawing::Point(168, 34);
            this->DistanceLODTextBox->Margin = System::Windows::Forms::Padding(2);
            this->DistanceLODTextBox->Name = L"DistanceLODTextBox";
            this->DistanceLODTextBox->Size = System::Drawing::Size(0, 20);
            this->DistanceLODTextBox->TabIndex = 304;
            this->DistanceLODTextBox->Text = L"5";
            // 
            // DistanceLODLabel
            // 
            this->DistanceLODLabel->AutoSize = true;
            this->DistanceLODLabel->Location = System::Drawing::Point(18, 36);
            this->DistanceLODLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->DistanceLODLabel->Name = L"DistanceLODLabel";
            this->DistanceLODLabel->Size = System::Drawing::Size(74, 13);
            this->DistanceLODLabel->TabIndex = 310;
            this->DistanceLODLabel->Text = L"DistanceLOD:";
            // 
            // VisibleRenderablesTextBox
            // 
            this->VisibleRenderablesTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->VisibleRenderablesTextBox->Location = System::Drawing::Point(168, 10);
            this->VisibleRenderablesTextBox->Margin = System::Windows::Forms::Padding(2);
            this->VisibleRenderablesTextBox->Name = L"VisibleRenderablesTextBox";
            this->VisibleRenderablesTextBox->Size = System::Drawing::Size(0, 20);
            this->VisibleRenderablesTextBox->TabIndex = 303;
            this->VisibleRenderablesTextBox->Text = L"200";
            // 
            // VisibleRenderablesLabel
            // 
            this->VisibleRenderablesLabel->AutoSize = true;
            this->VisibleRenderablesLabel->Location = System::Drawing::Point(18, 13);
            this->VisibleRenderablesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->VisibleRenderablesLabel->Name = L"VisibleRenderablesLabel";
            this->VisibleRenderablesLabel->Size = System::Drawing::Size(100, 13);
            this->VisibleRenderablesLabel->TabIndex = 309;
            this->VisibleRenderablesLabel->Text = L"VisibleRenderables:";
            // 
            // RCameraTabPage
            // 
            this->RCameraTabPage->AutoScroll = true;
            this->RCameraTabPage->Controls->Add(this->BaselookatzTextBox);
            this->RCameraTabPage->Controls->Add(this->BaselookatzLabel);
            this->RCameraTabPage->Controls->Add(this->BaseCameraViewpointzTextBox);
            this->RCameraTabPage->Controls->Add(this->BaselookatyTextBox);
            this->RCameraTabPage->Controls->Add(this->BaselookatyLabel);
            this->RCameraTabPage->Controls->Add(this->BaselookatxTextBox);
            this->RCameraTabPage->Controls->Add(this->BaselookatxLabel);
            this->RCameraTabPage->Controls->Add(this->BaseCameraViewpointzLabel);
            this->RCameraTabPage->Controls->Add(this->BaseCameraViewpointyTextBox);
            this->RCameraTabPage->Controls->Add(this->BaseCameraViewpointyLabel);
            this->RCameraTabPage->Controls->Add(this->BaseCameraViewpointxTextBox);
            this->RCameraTabPage->Controls->Add(this->BaseCameraViewpointxLabel);
            this->RCameraTabPage->Location = System::Drawing::Point(4, 22);
            this->RCameraTabPage->Margin = System::Windows::Forms::Padding(2);
            this->RCameraTabPage->Name = L"RCameraTabPage";
            this->RCameraTabPage->Size = System::Drawing::Size(401, 241);
            this->RCameraTabPage->TabIndex = 6;
            this->RCameraTabPage->Text = L"Camera";
            this->RCameraTabPage->UseVisualStyleBackColor = true;
            // 
            // BaselookatzTextBox
            // 
            this->BaselookatzTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->BaselookatzTextBox->Location = System::Drawing::Point(168, 128);
            this->BaselookatzTextBox->Margin = System::Windows::Forms::Padding(2);
            this->BaselookatzTextBox->Name = L"BaselookatzTextBox";
            this->BaselookatzTextBox->Size = System::Drawing::Size(192, 20);
            this->BaselookatzTextBox->TabIndex = 326;
            this->BaselookatzTextBox->Text = L"0.0f";
            // 
            // BaselookatzLabel
            // 
            this->BaselookatzLabel->AutoSize = true;
            this->BaselookatzLabel->Location = System::Drawing::Point(18, 131);
            this->BaselookatzLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->BaselookatzLabel->Name = L"BaselookatzLabel";
            this->BaselookatzLabel->Size = System::Drawing::Size(71, 13);
            this->BaselookatzLabel->TabIndex = 338;
            this->BaselookatzLabel->Text = L"Baselookat.z:";
            // 
            // BaseCameraViewpointzTextBox
            // 
            this->BaseCameraViewpointzTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->BaseCameraViewpointzTextBox->Location = System::Drawing::Point(168, 58);
            this->BaseCameraViewpointzTextBox->Margin = System::Windows::Forms::Padding(2);
            this->BaseCameraViewpointzTextBox->Name = L"BaseCameraViewpointzTextBox";
            this->BaseCameraViewpointzTextBox->Size = System::Drawing::Size(192, 20);
            this->BaseCameraViewpointzTextBox->TabIndex = 323;
            this->BaseCameraViewpointzTextBox->Text = L"0.0f";
            // 
            // BaselookatyTextBox
            // 
            this->BaselookatyTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->BaselookatyTextBox->Location = System::Drawing::Point(168, 105);
            this->BaselookatyTextBox->Margin = System::Windows::Forms::Padding(2);
            this->BaselookatyTextBox->Name = L"BaselookatyTextBox";
            this->BaselookatyTextBox->Size = System::Drawing::Size(192, 20);
            this->BaselookatyTextBox->TabIndex = 325;
            this->BaselookatyTextBox->Text = L"0.0f";
            // 
            // BaselookatyLabel
            // 
            this->BaselookatyLabel->AutoSize = true;
            this->BaselookatyLabel->Location = System::Drawing::Point(18, 107);
            this->BaselookatyLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->BaselookatyLabel->Name = L"BaselookatyLabel";
            this->BaselookatyLabel->Size = System::Drawing::Size(71, 13);
            this->BaselookatyLabel->TabIndex = 331;
            this->BaselookatyLabel->Text = L"Baselookat.y:";
            // 
            // BaselookatxTextBox
            // 
            this->BaselookatxTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->BaselookatxTextBox->Location = System::Drawing::Point(168, 81);
            this->BaselookatxTextBox->Margin = System::Windows::Forms::Padding(2);
            this->BaselookatxTextBox->Name = L"BaselookatxTextBox";
            this->BaselookatxTextBox->Size = System::Drawing::Size(192, 20);
            this->BaselookatxTextBox->TabIndex = 324;
            this->BaselookatxTextBox->Text = L"0.0f";
            // 
            // BaselookatxLabel
            // 
            this->BaselookatxLabel->AutoSize = true;
            this->BaselookatxLabel->Location = System::Drawing::Point(18, 84);
            this->BaselookatxLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->BaselookatxLabel->Name = L"BaselookatxLabel";
            this->BaselookatxLabel->Size = System::Drawing::Size(71, 13);
            this->BaselookatxLabel->TabIndex = 330;
            this->BaselookatxLabel->Text = L"Baselookat.x:";
            // 
            // BaseCameraViewpointzLabel
            // 
            this->BaseCameraViewpointzLabel->AutoSize = true;
            this->BaseCameraViewpointzLabel->Location = System::Drawing::Point(18, 60);
            this->BaseCameraViewpointzLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->BaseCameraViewpointzLabel->Name = L"BaseCameraViewpointzLabel";
            this->BaseCameraViewpointzLabel->Size = System::Drawing::Size(124, 13);
            this->BaseCameraViewpointzLabel->TabIndex = 329;
            this->BaseCameraViewpointzLabel->Text = L"BaseCameraViewpoint.z:";
            // 
            // BaseCameraViewpointyTextBox
            // 
            this->BaseCameraViewpointyTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->BaseCameraViewpointyTextBox->Location = System::Drawing::Point(168, 34);
            this->BaseCameraViewpointyTextBox->Margin = System::Windows::Forms::Padding(2);
            this->BaseCameraViewpointyTextBox->Name = L"BaseCameraViewpointyTextBox";
            this->BaseCameraViewpointyTextBox->Size = System::Drawing::Size(192, 20);
            this->BaseCameraViewpointyTextBox->TabIndex = 322;
            this->BaseCameraViewpointyTextBox->Text = L"0.0f";
            // 
            // BaseCameraViewpointyLabel
            // 
            this->BaseCameraViewpointyLabel->AutoSize = true;
            this->BaseCameraViewpointyLabel->Location = System::Drawing::Point(18, 36);
            this->BaseCameraViewpointyLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->BaseCameraViewpointyLabel->Name = L"BaseCameraViewpointyLabel";
            this->BaseCameraViewpointyLabel->Size = System::Drawing::Size(124, 13);
            this->BaseCameraViewpointyLabel->TabIndex = 328;
            this->BaseCameraViewpointyLabel->Text = L"BaseCameraViewpoint.y:";
            // 
            // BaseCameraViewpointxTextBox
            // 
            this->BaseCameraViewpointxTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
                | System::Windows::Forms::AnchorStyles::Right));
            this->BaseCameraViewpointxTextBox->Location = System::Drawing::Point(168, 10);
            this->BaseCameraViewpointxTextBox->Margin = System::Windows::Forms::Padding(2);
            this->BaseCameraViewpointxTextBox->Name = L"BaseCameraViewpointxTextBox";
            this->BaseCameraViewpointxTextBox->Size = System::Drawing::Size(192, 20);
            this->BaseCameraViewpointxTextBox->TabIndex = 321;
            this->BaseCameraViewpointxTextBox->Text = L"0.0f";
            // 
            // BaseCameraViewpointxLabel
            // 
            this->BaseCameraViewpointxLabel->AutoSize = true;
            this->BaseCameraViewpointxLabel->Location = System::Drawing::Point(18, 13);
            this->BaseCameraViewpointxLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->BaseCameraViewpointxLabel->Name = L"BaseCameraViewpointxLabel";
            this->BaseCameraViewpointxLabel->Size = System::Drawing::Size(124, 13);
            this->BaseCameraViewpointxLabel->TabIndex = 327;
            this->BaseCameraViewpointxLabel->Text = L"BaseCameraViewpoint.x:";
            // 
            // RuntimeWindow
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(873, 363);
            this->ControlBox = false;
            this->Controls->Add(this->RuntimeGroupBox);
            this->Controls->Add(this->StatusTextBox);
            this->Controls->Add(this->CloseWindowButton);
            this->Controls->Add(this->EditButton);
            this->Controls->Add(this->CreateButton);
            this->Controls->Add(this->OutputGroupBox);
            this->Controls->Add(this->ImageInputGroupBox);
            this->Controls->Add(this->InfoGroupBox);
            this->Name = L"RuntimeWindow";
            this->ShowIcon = false;
            this->ShowInTaskbar = false;
            this->Text = L"Runtime File Creation";
            this->OutputGroupBox->ResumeLayout(false);
            this->OutputGroupBox->PerformLayout();
            this->ImageInputGroupBox->ResumeLayout(false);
            this->ImageInputGroupBox->PerformLayout();
            this->InfoGroupBox->ResumeLayout(false);
            this->InfoGroupBox->PerformLayout();
            this->RuntimeGroupBox->ResumeLayout(false);
            this->tabControl1->ResumeLayout(false);
            this->RGeneralTabPage->ResumeLayout(false);
            this->RGeneralTabPage->PerformLayout();
            this->RPagingTabPage->ResumeLayout(false);
            this->RPagingTabPage->PerformLayout();
            this->RPropertiesTabPage->ResumeLayout(false);
            this->RPropertiesTabPage->PerformLayout();
            this->RLightingTabPage->ResumeLayout(false);
            this->RTextureTabPage->ResumeLayout(false);
            this->RTextureTabPage->PerformLayout();
            this->RPerformanceTabPage->ResumeLayout(false);
            this->RPerformanceTabPage->PerformLayout();
            this->RCameraTabPage->ResumeLayout(false);
            this->RCameraTabPage->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
	private: 
		System::Void CloseWindowButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			Hide();
		}
		System::Void GenFileLoadButton_Click(System::Object^  sender, System::EventArgs^  e) 
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

				// Load file and fill in the proper values
				mMapUtil->LoadSingleMap(Ogre::String((char*) Marshal::StringToHGlobalAnsi(mOutputFolder + GTerrainNameTextBox->Text).ToPointer()) + ".gen.cfg", "PLSM2");

				/* The following values are for convenience only, not used to generate the runtime cfg
				HeightMapFileName
				HeightMapExtension
				ColorMapFileName
				ColorMapExtension
				*/

				/* The following values must be consistent between the gen cfg and runtime cfg
				GroupName
				ScaleX
				ScaleY
				ScaleZ
				PageSize
				TileSize
				Data2DFormat
				MaxValue
				MinValue
				ImageStretchFactor
				MaterialHeight
				MaterialColor
				SplatFilename
				*/

				Ogre::String GroupName = mMapUtil->mOptions->groupName;
				RGroupNameTextBox->Text = TO_CLR_STRING(GroupName);

				Ogre::Vector3 Scale = mMapUtil->mOptions->scale;
				RTerrainScaleXTextBox->Text = Scale.x.ToString();
				RTerrainScaleYTextBox->Text = Scale.y.ToString();
				RTerrainScaleZTextBox->Text = Scale.z.ToString();

				int PageSize = mMapUtil->mOptions->PageSize;
				RPageSizeTextBox->Text = PageSize.ToString();

				int TileSize = mMapUtil->mOptions->TileSize;
				RTileSizeTextBox->Text = TileSize.ToString();

				Ogre::String Data2DFormat = mMapUtil->mOptions->data2DFormat;
				RData2DFormatTextBox->Text = TO_CLR_STRING(Data2DFormat);

				int MaxValue = mMapUtil->mOptions->maxValue;
				RMaxValueTextBox->Text = MaxValue.ToString();

				int MinValue = mMapUtil->mOptions->minValue;
				RMinValueTextBox->Text = MinValue.ToString();

				Ogre::Real ImageStretchFactor = mMapUtil->mOptions->TextureStretchFactor;
				RColorMapStretchFactorTextBox->Text = ImageStretchFactor.ToString();

				std::vector<Ogre::ColourValue> MaterialColor = mMapUtil->mOptions->matColor;

				std::vector<Ogre::Real> MaterialHeight = mMapUtil->mOptions->matHeight;

				std::vector<Ogre::String> SplatFilename = mMapUtil->mOptions->SplatDetailMapNames;
			}
			else Environment::CurrentDirectory = backupCurrentDir;
		}
		System::Void CreateButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if( GTerrainNameTextBox->Text == "" ) return;

			// Duplicating layout of template.default.gen.cfg

			System::IO::FileStream^ fs = System::IO::File::Create(
				mOutputFolder + GTerrainNameTextBox->Text + ".cfg");
			System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(fs);

			sw->WriteLine("####### Generated by Terrain Generator #######");
			sw->WriteLine("####### FileName: " + GTerrainNameTextBox->Text + ".cfg ######");
			sw->WriteLine("####### RUNTIME FILE: This is the run-time file used to load the terrain into the scene ######");
			sw->WriteLine("");

			sw->WriteLine("TerrainName=" + GTerrainNameTextBox->Text);
			sw->WriteLine("");

			sw->WriteLine(createComment("General Options"));
			sw->WriteLine(createAssignment(RGroupNameLabel,RGroupNameTextBox));

			if( ResourceFormatComboBox->Text != "Already in Path" )
			{
				sw->WriteLine(FormatLabel->Text + FormatTextBox->Text);
			}

			sw->WriteLine(createAssignment(RHeightMapFileNameLabel,RHeightMapFileNameTextBox));
			sw->WriteLine(createAssignment(RHeightMapExtensionLabel,RHeightMapExtensionTextBox));
			sw->WriteLine(createAssignment(RColorMapFileNameLabel,RColorMapFileNameTextBox));
			sw->WriteLine(createAssignment(RColorMapExtensionLabel,RColorMapExtensionTextBox));
			sw->WriteLine("");

			sw->WriteLine(createComment("Paging Related Options (no effect if Paged=no)"));
			sw->WriteLine(createAssignment(PageWidthLabel,PageWidthTextBox));
			sw->WriteLine(createAssignment(PageHeightLabel,PageHeightTextBox));
			sw->WriteLine(createAssignment(RPageSizeLabel,RPageSizeTextBox));
			sw->WriteLine(createAssignment(RTileSizeLabel,RTileSizeTextBox));
			sw->WriteLine(createAssignment(RData2DFormatLabel,RData2DFormatTextBox));
			sw->WriteLine(createAssignment(RMaxValueLabel,RMaxValueTextBox));
			sw->WriteLine(createAssignment(RMinValueLabel,RMinValueTextBox));
			sw->WriteLine("");

			sw->WriteLine(createComment("Terrain Properties"));
			sw->WriteLine(createAssignment(RTerrainScaleXLabel,RTerrainScaleXTextBox));
			sw->WriteLine(createAssignment(RTerrainScaleYLabel,RTerrainScaleYTextBox));
			sw->WriteLine(createAssignment(RTerrainScaleZLabel,RTerrainScaleZTextBox));
			sw->WriteLine(createAssignment(DeformableCheckBox));
			sw->WriteLine(createAssignment(VertexCompressionCheckBox));
			sw->WriteLine(createAssignment(VertexProgramMorphCheckBox));
			sw->WriteLine(createAssignment(LODMorphStartLabel,LODMorphStartTextBox));
			sw->WriteLine(createAssignment(MaxPixelErrorLabel,MaxPixelErrorTextBox));
			sw->WriteLine("");

			sw->WriteLine(createComment("Lighting Options"));
			sw->WriteLine(createAssignment(VertexNormalsCheckBox));
			sw->WriteLine(createAssignment(VertexLitCheckBox));
			sw->WriteLine("");

			sw->WriteLine(createComment("Texture Properties"));
			sw->WriteLine(createAssignment(RColorMapStretchFactorLabel,RColorMapStretchFactorTextBox));
			sw->WriteLine(createAssignment(NumTextureFormatSupportedLabel,NumTextureFormatSupportedTextBox));
			writeRichTextBoxContents(sw,TextureFormatSupportedRichTextBox);
			sw->WriteLine(createAssignment(TextureFormatLabel,TextureFormatTextBox));
			sw->WriteLine(createAssignment(RNumMatHeightSplatLabel,RNumMatHeightSplatTextBox));
			sw->WriteLine("");
			writeRichTextBoxContents(sw,RSetMaterialHeightRichTextBox);
			writeRichTextBoxContents(sw,RSetMaterialColorRichTextBox);
			writeRichTextBoxContents(sw,RSetSplatFileNamesRichTextBox);
			sw->WriteLine(createAssignment(BigImageCheckBox));
			sw->WriteLine(createAssignment(VertexColorsCheckBox));
			sw->WriteLine(createAssignment(CoverageVertexColorCheckBox));
			sw->WriteLine(createAssignment(BaseVertexColorCheckBox));
			sw->WriteLine(createAssignment(BaseVertexShadowCheckBox));
			sw->WriteLine(createAssignment(BaseVertexInstantColorCheckBox));
			sw->WriteLine("");

			sw->WriteLine(createComment("Performance Options"));
			sw->WriteLine(createAssignment(VisibleRenderablesLabel,VisibleRenderablesTextBox));
			sw->WriteLine(createAssignment(DistanceLODLabel,DistanceLODTextBox));
			sw->WriteLine(createAssignment(MaxRenderLevelLabel,MaxRenderLevelTextBox));
			sw->WriteLine(createAssignment(NumRenderablesLoadingLabel,NumRenderablesLoadingTextBox));
			sw->WriteLine(createAssignment(MaxAdjacentPagesLabel,MaxAdjacentPagesTextBox));
			sw->WriteLine(createAssignment(MaxPreloadedPagesLabel,MaxPreloadedPagesTextBox));
			sw->WriteLine(createAssignment(ChangeFactorLabel,ChangeFactorTextBox));
			sw->WriteLine(createAssignment(CameraThresholdLabel,CameraThresholdTextBox));
			sw->WriteLine(createAssignment(MaxNumRenderablesLabel,MaxNumRenderablesTextBox));
			sw->WriteLine(createAssignment(IncrementRenderablesLabel,IncrementRenderablesTextBox));
			sw->WriteLine(createAssignment(MaxNumTilesLabel,MaxNumTilesTextBox));
			sw->WriteLine(createAssignment(IncrementTilesLabel,IncrementTilesTextBox));
			sw->WriteLine(createAssignment(HorizonVisibilityComputingCheckBox));
			sw->WriteLine("");

			sw->WriteLine(createComment("Camera Properties (on Terrain Load)"));
			sw->WriteLine(createAssignment(BaseCameraViewpointxLabel,BaseCameraViewpointxTextBox));
			sw->WriteLine(createAssignment(BaseCameraViewpointyLabel,BaseCameraViewpointyTextBox));
			sw->WriteLine(createAssignment(BaseCameraViewpointzLabel,BaseCameraViewpointzTextBox));
			sw->WriteLine(createAssignment(BaselookatxLabel,BaselookatxTextBox));
			sw->WriteLine(createAssignment(BaselookatyLabel,BaselookatyTextBox));
			sw->WriteLine(createAssignment(BaselookatzLabel,BaselookatzTextBox));
			sw->WriteLine("");

			sw->Close();
			fs->Close();
		}
		System::Void EditButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if( !File::Exists(mOutputFolder + GTerrainNameTextBox->Text + ".cfg") ) return;

			Process^ notePad = gcnew Process();

			notePad->StartInfo->FileName = "notepad.exe";
			notePad->StartInfo->Arguments = mOutputFolder + GTerrainNameTextBox->Text + ".cfg";

			notePad->Start();
		}
};
}
