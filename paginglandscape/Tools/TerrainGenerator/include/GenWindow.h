#pragma once

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
	/// Summary for GenWindow
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class GenWindow : public System::Windows::Forms::Form
	{
	public:
		GenWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			CenterToScreen();
		}

		System::Void	setHeightMapFolder( System::String^ HeightMapFolder )
		{
			mHeightMapFolder = HeightMapFolder;
		}

		System::Void	setColorMapFolder( System::String^ ColorMapFolder )
		{
			mColorMapFolder = ColorMapFolder;
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

		// Um... removing these statements creates an error when loading form in design view... thanks MS.
		/*System::Void	updateOutputPath( System::String^ OutputFolder )
		{
			mOutputFolder = OutputFolder;
			OutputFolderTextBox->Text = mOutputFolder + "<TerrainName>";
		}*/

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GenWindow()
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
		System::String^	mHeightMapFolder;
		System::String^	mColorMapFolder;
		System::String^	mOutputFolder;

	private: System::Windows::Forms::Label^  InfoLabel1;
	private: System::Windows::Forms::Label^  InfoLabel2;
	private: System::Windows::Forms::GroupBox^  InfoGroupBox;
	private: System::Windows::Forms::GroupBox^  ImageInputGroupBox;
	private: System::Windows::Forms::Button^  ColorMapLoadButton;
	private: System::Windows::Forms::Label^  ColorMapLabel;
	private: System::Windows::Forms::Button^  HeightMapLoadButton;
	private: System::Windows::Forms::Label^  HeightMapLabel;
	private: System::Windows::Forms::GroupBox^  OutputGroupBox;
	private: System::Windows::Forms::Label^  OutputLabel1;
	private: System::Windows::Forms::TextBox^  GTerrainNameTextBox;
	private: System::Windows::Forms::Label^  TerrainNameGLabel;
	private: System::Windows::Forms::Label^  OutputLabel3;
	private: System::Windows::Forms::Label^  OutputLabel2;
	private: System::Windows::Forms::GroupBox^  GenConfigGroupBox;
	private: System::Windows::Forms::Button^  CreateButton;
	private: System::Windows::Forms::Button^  EditButton;
	private: System::Windows::Forms::Button^  CloseWindowButton;
	private: System::Windows::Forms::TextBox^  StatusTextBox;
	private: System::Windows::Forms::TextBox^  OutputFolderTextBox;
	private: System::Windows::Forms::Label^  OutputFolderLabel;
	private: System::Windows::Forms::TabControl^  GenerationTabControl;
	private: System::Windows::Forms::TabPage^  GGeneralTabPage;
	private: System::Windows::Forms::TextBox^  GTerrainScaleZTextBox;
	private: System::Windows::Forms::Label^  GTerrainScaleZLabel;
	private: System::Windows::Forms::TextBox^  GTerrainScaleYTextBox;
	private: System::Windows::Forms::Label^  GTerrainScaleYLabel;
	private: System::Windows::Forms::TextBox^  GTerrainScaleXTextBox;
	private: System::Windows::Forms::Label^  GTerrainScaleXLabel;
	private: System::Windows::Forms::TextBox^  ColorMapExportExtensionTextBox;
	private: System::Windows::Forms::Label^  ColorMapExportExtensionLabel;
	private: System::Windows::Forms::TextBox^  GColorMapExtensionTextBox;
	private: System::Windows::Forms::Label^  GColorMapExtensionLabel;
	private: System::Windows::Forms::TextBox^  GColorMapFileNameTextBox;
	private: System::Windows::Forms::Label^  GColorMapFileNameLabel;
	private: System::Windows::Forms::TextBox^  GHeightMapExtensionTextBox;
	private: System::Windows::Forms::CheckBox^  PagedCheckBox;
	private: System::Windows::Forms::TextBox^  HeightMapExportExtensionTextBox;
	private: System::Windows::Forms::Label^  HeightMapExportExtensionLabel;
	private: System::Windows::Forms::Label^  GHeightMapExtensionLabel;
	private: System::Windows::Forms::TextBox^  GHeightMapFileNameTextBox;
	private: System::Windows::Forms::Label^  GHeightMapFileNameLabel;
	private: System::Windows::Forms::TextBox^  GGroupNameTextBox;
	private: System::Windows::Forms::Label^  GGroupNameLabel;
	private: System::Windows::Forms::TabPage^  GPagingTabPage;
	private: System::Windows::Forms::TextBox^  GTileSizeTextBox;
	private: System::Windows::Forms::Label^  GTileSizeLabel;
	private: System::Windows::Forms::TextBox^  GMinValueTextBox;
	private: System::Windows::Forms::Label^  GMinValueLabel;
	private: System::Windows::Forms::TextBox^  GMaxValueTextBox;
	private: System::Windows::Forms::Label^  GMaxValueLabel;
	private: System::Windows::Forms::ComboBox^  GData2DFormatComboBox;
	private: System::Windows::Forms::Label^  GData2DFormatLabel;
	private: System::Windows::Forms::TextBox^  GPageSizeTextBox;
	private: System::Windows::Forms::Label^  GPageSizeLabel;
	private: System::Windows::Forms::TabPage^  GHeightMapTabPage;
	private: System::Windows::Forms::TextBox^  MiniMapHeightTextBox;
	private: System::Windows::Forms::Label^  MiniMapHeightLabel;
	private: System::Windows::Forms::TextBox^  MiniMapWidthTextBox;
	private: System::Windows::Forms::Label^  MiniMapWidthLabel;
	private: System::Windows::Forms::CheckBox^  EqualizeCheckBox;
	private: System::Windows::Forms::TextBox^  HeightMapBlurFactorTextBox;
	private: System::Windows::Forms::Label^  HeightMapBlurFactorLabel;
	private: System::Windows::Forms::CheckBox^  InfiniteMapCheckBox;
	private: System::Windows::Forms::CheckBox^  HeightMapCheckBox;
	private: System::Windows::Forms::CheckBox^  MiniMapCheckBox;
	private: System::Windows::Forms::TabPage^  GColorMapTabPage;
	private: System::Windows::Forms::TextBox^  GColorMapStretchFactorTextBox;
	private: System::Windows::Forms::Label^  GColorMapStretchFactorLabel;
	private: System::Windows::Forms::CheckBox^  LitColorMapSplitCheckBox;
	private: System::Windows::Forms::CheckBox^  ColorMapSplitCheckBox;
	private: System::Windows::Forms::TabPage^  GNormalsTabPage;
	private: System::Windows::Forms::CheckBox^  HeightNormalMapCheckBox;
	private: System::Windows::Forms::CheckBox^  NormalMapCheckBox;
	private: System::Windows::Forms::CheckBox^  LitColorMapGenerateCheckBox;
	private: System::Windows::Forms::CheckBox^  ColorMapGenerateCheckBox;
	private: System::Windows::Forms::TabPage^  GSplattingTabPage;
	private: System::Windows::Forms::RichTextBox^  GSetSplatFileNamesRichTextBox;
	private: System::Windows::Forms::RichTextBox^  GSetMaterialHeightRichTextBox;
	private: System::Windows::Forms::Label^  GSetMaterialHeightLabel;
	private: System::Windows::Forms::RichTextBox^  GSetMaterialColorRichTextBox;
	private: System::Windows::Forms::TextBox^  NumMatHeightSplatTextBox;
	private: System::Windows::Forms::Label^  NumMatHeightSplatLabel;
	private: System::Windows::Forms::Label^  GSetSplatFileNamesLabel;
	private: System::Windows::Forms::Label^  GSetMaterialColorLabel;
	private: System::Windows::Forms::CheckBox^  RGBMapsCheckBox;
	private: System::Windows::Forms::CheckBox^  AlphaSplatLightMapsCheckBox;
	private: System::Windows::Forms::CheckBox^  AlphaSplatRGBAMapsCheckBox;
	private: System::Windows::Forms::CheckBox^  CoverageMapCheckBox;
	private: System::Windows::Forms::CheckBox^  LitBaseMapCheckBox;
	private: System::Windows::Forms::CheckBox^  BaseMapCheckBox;
	private: System::Windows::Forms::CheckBox^  AvgColorsExistsCheckBox;
	private: System::Windows::Forms::CheckBox^  AlphaMapsCheckBox;
	private: System::Windows::Forms::TabPage^  GLightingTabPage;
	private: System::Windows::Forms::CheckBox^  PVSMapCheckBox;
	private: System::Windows::Forms::Label^  VisibilityLabel;
	private: System::Windows::Forms::CheckBox^  ZHorizonCheckBox;
	private: System::Windows::Forms::CheckBox^  ElevationMapCheckBox;
	private: System::Windows::Forms::CheckBox^  HorizonMapCheckBox;
	private: System::Windows::Forms::Label^  RealTimeLightingLabel;
	private: System::Windows::Forms::TextBox^  BlurTextBox;
	private: System::Windows::Forms::Label^  BlurLabel;
	private: System::Windows::Forms::TextBox^  DiffuseTextBox;
	private: System::Windows::Forms::Label^  DiffuseLabel;
	private: System::Windows::Forms::TextBox^  AmbientTextBox;
	private: System::Windows::Forms::Label^  AmbientLabel;
	private: System::Windows::Forms::TextBox^  SunzTextBox;
	private: System::Windows::Forms::Label^  SunzLabel;
	private: System::Windows::Forms::TextBox^  SunyTextBox;
	private: System::Windows::Forms::Label^  SunyLabel;
	private: System::Windows::Forms::CheckBox^  ShadowMapCheckBox;
	private: System::Windows::Forms::CheckBox^  LightMapCheckBox;
	private: System::Windows::Forms::TextBox^  SunxTextBox;
	private: System::Windows::Forms::Label^  SunxLabel;

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
			this->InfoLabel1 = (gcnew System::Windows::Forms::Label());
			this->InfoLabel2 = (gcnew System::Windows::Forms::Label());
			this->InfoGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->ImageInputGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->ColorMapLoadButton = (gcnew System::Windows::Forms::Button());
			this->ColorMapLabel = (gcnew System::Windows::Forms::Label());
			this->HeightMapLoadButton = (gcnew System::Windows::Forms::Button());
			this->HeightMapLabel = (gcnew System::Windows::Forms::Label());
			this->OutputGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->OutputFolderTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OutputFolderLabel = (gcnew System::Windows::Forms::Label());
			this->OutputLabel3 = (gcnew System::Windows::Forms::Label());
			this->OutputLabel2 = (gcnew System::Windows::Forms::Label());
			this->OutputLabel1 = (gcnew System::Windows::Forms::Label());
			this->GTerrainNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->TerrainNameGLabel = (gcnew System::Windows::Forms::Label());
			this->GenConfigGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->GenerationTabControl = (gcnew System::Windows::Forms::TabControl());
			this->GGeneralTabPage = (gcnew System::Windows::Forms::TabPage());
			this->GTerrainScaleZTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GTerrainScaleZLabel = (gcnew System::Windows::Forms::Label());
			this->GTerrainScaleYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GTerrainScaleYLabel = (gcnew System::Windows::Forms::Label());
			this->GTerrainScaleXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GTerrainScaleXLabel = (gcnew System::Windows::Forms::Label());
			this->ColorMapExportExtensionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ColorMapExportExtensionLabel = (gcnew System::Windows::Forms::Label());
			this->GColorMapExtensionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GColorMapExtensionLabel = (gcnew System::Windows::Forms::Label());
			this->GColorMapFileNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GColorMapFileNameLabel = (gcnew System::Windows::Forms::Label());
			this->GHeightMapExtensionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PagedCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->HeightMapExportExtensionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->HeightMapExportExtensionLabel = (gcnew System::Windows::Forms::Label());
			this->GHeightMapExtensionLabel = (gcnew System::Windows::Forms::Label());
			this->GHeightMapFileNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GHeightMapFileNameLabel = (gcnew System::Windows::Forms::Label());
			this->GGroupNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GGroupNameLabel = (gcnew System::Windows::Forms::Label());
			this->GPagingTabPage = (gcnew System::Windows::Forms::TabPage());
			this->GTileSizeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GTileSizeLabel = (gcnew System::Windows::Forms::Label());
			this->GMinValueTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GMinValueLabel = (gcnew System::Windows::Forms::Label());
			this->GMaxValueTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GMaxValueLabel = (gcnew System::Windows::Forms::Label());
			this->GData2DFormatComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->GData2DFormatLabel = (gcnew System::Windows::Forms::Label());
			this->GPageSizeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GPageSizeLabel = (gcnew System::Windows::Forms::Label());
			this->GHeightMapTabPage = (gcnew System::Windows::Forms::TabPage());
			this->MiniMapHeightTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MiniMapHeightLabel = (gcnew System::Windows::Forms::Label());
			this->MiniMapWidthTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MiniMapWidthLabel = (gcnew System::Windows::Forms::Label());
			this->EqualizeCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->HeightMapBlurFactorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->HeightMapBlurFactorLabel = (gcnew System::Windows::Forms::Label());
			this->InfiniteMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->HeightMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->MiniMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->GColorMapTabPage = (gcnew System::Windows::Forms::TabPage());
			this->GColorMapStretchFactorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GColorMapStretchFactorLabel = (gcnew System::Windows::Forms::Label());
			this->LitColorMapSplitCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->ColorMapSplitCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->GNormalsTabPage = (gcnew System::Windows::Forms::TabPage());
			this->HeightNormalMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->NormalMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->LitColorMapGenerateCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->ColorMapGenerateCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->GSplattingTabPage = (gcnew System::Windows::Forms::TabPage());
			this->GSetSplatFileNamesRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->GSetMaterialHeightRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->GSetMaterialHeightLabel = (gcnew System::Windows::Forms::Label());
			this->GSetMaterialColorRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->NumMatHeightSplatTextBox = (gcnew System::Windows::Forms::TextBox());
			this->NumMatHeightSplatLabel = (gcnew System::Windows::Forms::Label());
			this->GSetSplatFileNamesLabel = (gcnew System::Windows::Forms::Label());
			this->GSetMaterialColorLabel = (gcnew System::Windows::Forms::Label());
			this->RGBMapsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->AlphaSplatLightMapsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->AlphaSplatRGBAMapsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->CoverageMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->LitBaseMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->BaseMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->AvgColorsExistsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->AlphaMapsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->GLightingTabPage = (gcnew System::Windows::Forms::TabPage());
			this->PVSMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->VisibilityLabel = (gcnew System::Windows::Forms::Label());
			this->ZHorizonCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->ElevationMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->HorizonMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->RealTimeLightingLabel = (gcnew System::Windows::Forms::Label());
			this->BlurTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BlurLabel = (gcnew System::Windows::Forms::Label());
			this->DiffuseTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DiffuseLabel = (gcnew System::Windows::Forms::Label());
			this->AmbientTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AmbientLabel = (gcnew System::Windows::Forms::Label());
			this->SunzTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SunzLabel = (gcnew System::Windows::Forms::Label());
			this->SunyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SunyLabel = (gcnew System::Windows::Forms::Label());
			this->ShadowMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->LightMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->SunxTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SunxLabel = (gcnew System::Windows::Forms::Label());
			this->CreateButton = (gcnew System::Windows::Forms::Button());
			this->EditButton = (gcnew System::Windows::Forms::Button());
			this->CloseWindowButton = (gcnew System::Windows::Forms::Button());
			this->StatusTextBox = (gcnew System::Windows::Forms::TextBox());
			this->InfoGroupBox->SuspendLayout();
			this->ImageInputGroupBox->SuspendLayout();
			this->OutputGroupBox->SuspendLayout();
			this->GenConfigGroupBox->SuspendLayout();
			this->GenerationTabControl->SuspendLayout();
			this->GGeneralTabPage->SuspendLayout();
			this->GPagingTabPage->SuspendLayout();
			this->GHeightMapTabPage->SuspendLayout();
			this->GColorMapTabPage->SuspendLayout();
			this->GNormalsTabPage->SuspendLayout();
			this->GSplattingTabPage->SuspendLayout();
			this->GLightingTabPage->SuspendLayout();
			this->SuspendLayout();
			// 
			// InfoLabel1
			// 
			this->InfoLabel1->AutoSize = true;
			this->InfoLabel1->Location = System::Drawing::Point(16, 24);
			this->InfoLabel1->Name = L"InfoLabel1";
			this->InfoLabel1->Size = System::Drawing::Size(323, 13);
			this->InfoLabel1->TabIndex = 0;
			this->InfoLabel1->Text = L"A *.gen.cfg file can be thought of as a Mapsplitter configuration file.";
			// 
			// InfoLabel2
			// 
			this->InfoLabel2->AutoSize = true;
			this->InfoLabel2->Location = System::Drawing::Point(16, 37);
			this->InfoLabel2->Name = L"InfoLabel2";
			this->InfoLabel2->Size = System::Drawing::Size(374, 13);
			this->InfoLabel2->TabIndex = 1;
			this->InfoLabel2->Text = L"It tells Mapsplitter how to process and break up the HeightMap and ColorMap.";
			// 
			// InfoGroupBox
			// 
			this->InfoGroupBox->Controls->Add(this->InfoLabel2);
			this->InfoGroupBox->Controls->Add(this->InfoLabel1);
			this->InfoGroupBox->Location = System::Drawing::Point(13, 13);
			this->InfoGroupBox->Name = L"InfoGroupBox";
			this->InfoGroupBox->Size = System::Drawing::Size(413, 66);
			this->InfoGroupBox->TabIndex = 2;
			this->InfoGroupBox->TabStop = false;
			this->InfoGroupBox->Text = L"Info";
			// 
			// ImageInputGroupBox
			// 
			this->ImageInputGroupBox->Controls->Add(this->ColorMapLoadButton);
			this->ImageInputGroupBox->Controls->Add(this->ColorMapLabel);
			this->ImageInputGroupBox->Controls->Add(this->HeightMapLoadButton);
			this->ImageInputGroupBox->Controls->Add(this->HeightMapLabel);
			this->ImageInputGroupBox->Location = System::Drawing::Point(13, 86);
			this->ImageInputGroupBox->Name = L"ImageInputGroupBox";
			this->ImageInputGroupBox->Size = System::Drawing::Size(413, 82);
			this->ImageInputGroupBox->TabIndex = 3;
			this->ImageInputGroupBox->TabStop = false;
			this->ImageInputGroupBox->Text = L"Image Input";
			// 
			// ColorMapLoadButton
			// 
			this->ColorMapLoadButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->ColorMapLoadButton->Location = System::Drawing::Point(82, 48);
			this->ColorMapLoadButton->Margin = System::Windows::Forms::Padding(2);
			this->ColorMapLoadButton->Name = L"ColorMapLoadButton";
			this->ColorMapLoadButton->Size = System::Drawing::Size(325, 21);
			this->ColorMapLoadButton->TabIndex = 163;
			this->ColorMapLoadButton->Text = L"Load ColorMap";
			this->ColorMapLoadButton->UseVisualStyleBackColor = true;
			this->ColorMapLoadButton->Click += gcnew System::EventHandler(this, &GenWindow::ColorMapLoadButton_Click);
			// 
			// ColorMapLabel
			// 
			this->ColorMapLabel->AutoSize = true;
			this->ColorMapLabel->Location = System::Drawing::Point(16, 51);
			this->ColorMapLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ColorMapLabel->Name = L"ColorMapLabel";
			this->ColorMapLabel->Size = System::Drawing::Size(55, 13);
			this->ColorMapLabel->TabIndex = 165;
			this->ColorMapLabel->Text = L"ColorMap:";
			// 
			// HeightMapLoadButton
			// 
			this->HeightMapLoadButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->HeightMapLoadButton->Location = System::Drawing::Point(82, 25);
			this->HeightMapLoadButton->Margin = System::Windows::Forms::Padding(2);
			this->HeightMapLoadButton->Name = L"HeightMapLoadButton";
			this->HeightMapLoadButton->Size = System::Drawing::Size(325, 21);
			this->HeightMapLoadButton->TabIndex = 162;
			this->HeightMapLoadButton->Text = L"Load HeightMap";
			this->HeightMapLoadButton->UseVisualStyleBackColor = true;
			this->HeightMapLoadButton->Click += gcnew System::EventHandler(this, &GenWindow::HeightMapLoadButton_Click);
			// 
			// HeightMapLabel
			// 
			this->HeightMapLabel->AutoSize = true;
			this->HeightMapLabel->Location = System::Drawing::Point(16, 27);
			this->HeightMapLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->HeightMapLabel->Name = L"HeightMapLabel";
			this->HeightMapLabel->Size = System::Drawing::Size(62, 13);
			this->HeightMapLabel->TabIndex = 164;
			this->HeightMapLabel->Text = L"HeightMap:";
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
			this->OutputGroupBox->TabIndex = 4;
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
			this->OutputLabel1->Size = System::Drawing::Size(364, 13);
			this->OutputLabel1->TabIndex = 2;
			this->OutputLabel1->Text = L"The Gen file will be created as <Terrain Name>.gen.cfg in the Output folder.";
			// 
			// GTerrainNameTextBox
			// 
			this->GTerrainNameTextBox->Location = System::Drawing::Point(95, 78);
			this->GTerrainNameTextBox->Margin = System::Windows::Forms::Padding(2);
			this->GTerrainNameTextBox->Name = L"GTerrainNameTextBox";
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
			// GenConfigGroupBox
			// 
			this->GenConfigGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GenConfigGroupBox->Controls->Add(this->GenerationTabControl);
			this->GenConfigGroupBox->Location = System::Drawing::Point(432, 12);
			this->GenConfigGroupBox->Name = L"GenConfigGroupBox";
			this->GenConfigGroupBox->Size = System::Drawing::Size(429, 296);
			this->GenConfigGroupBox->TabIndex = 5;
			this->GenConfigGroupBox->TabStop = false;
			this->GenConfigGroupBox->Text = L"Gen Configuration";
			// 
			// GenerationTabControl
			// 
			this->GenerationTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GenerationTabControl->Controls->Add(this->GGeneralTabPage);
			this->GenerationTabControl->Controls->Add(this->GPagingTabPage);
			this->GenerationTabControl->Controls->Add(this->GHeightMapTabPage);
			this->GenerationTabControl->Controls->Add(this->GColorMapTabPage);
			this->GenerationTabControl->Controls->Add(this->GNormalsTabPage);
			this->GenerationTabControl->Controls->Add(this->GSplattingTabPage);
			this->GenerationTabControl->Controls->Add(this->GLightingTabPage);
			this->GenerationTabControl->Location = System::Drawing::Point(15, 18);
			this->GenerationTabControl->Margin = System::Windows::Forms::Padding(2);
			this->GenerationTabControl->Name = L"GenerationTabControl";
			this->GenerationTabControl->SelectedIndex = 0;
			this->GenerationTabControl->Size = System::Drawing::Size(409, 267);
			this->GenerationTabControl->TabIndex = 1;
			// 
			// GGeneralTabPage
			// 
			this->GGeneralTabPage->AutoScroll = true;
			this->GGeneralTabPage->Controls->Add(this->GTerrainScaleZTextBox);
			this->GGeneralTabPage->Controls->Add(this->GTerrainScaleZLabel);
			this->GGeneralTabPage->Controls->Add(this->GTerrainScaleYTextBox);
			this->GGeneralTabPage->Controls->Add(this->GTerrainScaleYLabel);
			this->GGeneralTabPage->Controls->Add(this->GTerrainScaleXTextBox);
			this->GGeneralTabPage->Controls->Add(this->GTerrainScaleXLabel);
			this->GGeneralTabPage->Controls->Add(this->ColorMapExportExtensionTextBox);
			this->GGeneralTabPage->Controls->Add(this->ColorMapExportExtensionLabel);
			this->GGeneralTabPage->Controls->Add(this->GColorMapExtensionTextBox);
			this->GGeneralTabPage->Controls->Add(this->GColorMapExtensionLabel);
			this->GGeneralTabPage->Controls->Add(this->GColorMapFileNameTextBox);
			this->GGeneralTabPage->Controls->Add(this->GColorMapFileNameLabel);
			this->GGeneralTabPage->Controls->Add(this->GHeightMapExtensionTextBox);
			this->GGeneralTabPage->Controls->Add(this->PagedCheckBox);
			this->GGeneralTabPage->Controls->Add(this->HeightMapExportExtensionTextBox);
			this->GGeneralTabPage->Controls->Add(this->HeightMapExportExtensionLabel);
			this->GGeneralTabPage->Controls->Add(this->GHeightMapExtensionLabel);
			this->GGeneralTabPage->Controls->Add(this->GHeightMapFileNameTextBox);
			this->GGeneralTabPage->Controls->Add(this->GHeightMapFileNameLabel);
			this->GGeneralTabPage->Controls->Add(this->GGroupNameTextBox);
			this->GGeneralTabPage->Controls->Add(this->GGroupNameLabel);
			this->GGeneralTabPage->Location = System::Drawing::Point(4, 22);
			this->GGeneralTabPage->Margin = System::Windows::Forms::Padding(2);
			this->GGeneralTabPage->Name = L"GGeneralTabPage";
			this->GGeneralTabPage->Padding = System::Windows::Forms::Padding(2);
			this->GGeneralTabPage->Size = System::Drawing::Size(401, 241);
			this->GGeneralTabPage->TabIndex = 0;
			this->GGeneralTabPage->Text = L"General";
			this->GGeneralTabPage->UseVisualStyleBackColor = true;
			// 
			// GTerrainScaleZTextBox
			// 
			this->GTerrainScaleZTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GTerrainScaleZTextBox->Location = System::Drawing::Point(187, 250);
			this->GTerrainScaleZTextBox->Margin = System::Windows::Forms::Padding(2);
			this->GTerrainScaleZTextBox->Name = L"GTerrainScaleZTextBox";
			this->GTerrainScaleZTextBox->Size = System::Drawing::Size(177, 20);
			this->GTerrainScaleZTextBox->TabIndex = 212;
			this->GTerrainScaleZTextBox->Text = L"90000";
			// 
			// GTerrainScaleZLabel
			// 
			this->GTerrainScaleZLabel->AutoSize = true;
			this->GTerrainScaleZLabel->Location = System::Drawing::Point(18, 252);
			this->GTerrainScaleZLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GTerrainScaleZLabel->Name = L"GTerrainScaleZLabel";
			this->GTerrainScaleZLabel->Size = System::Drawing::Size(44, 13);
			this->GTerrainScaleZLabel->TabIndex = 215;
			this->GTerrainScaleZLabel->Text = L"ScaleZ:";
			// 
			// GTerrainScaleYTextBox
			// 
			this->GTerrainScaleYTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GTerrainScaleYTextBox->Location = System::Drawing::Point(187, 226);
			this->GTerrainScaleYTextBox->Margin = System::Windows::Forms::Padding(2);
			this->GTerrainScaleYTextBox->Name = L"GTerrainScaleYTextBox";
			this->GTerrainScaleYTextBox->Size = System::Drawing::Size(177, 20);
			this->GTerrainScaleYTextBox->TabIndex = 211;
			this->GTerrainScaleYTextBox->Text = L"15000";
			// 
			// GTerrainScaleYLabel
			// 
			this->GTerrainScaleYLabel->AutoSize = true;
			this->GTerrainScaleYLabel->Location = System::Drawing::Point(18, 228);
			this->GTerrainScaleYLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GTerrainScaleYLabel->Name = L"GTerrainScaleYLabel";
			this->GTerrainScaleYLabel->Size = System::Drawing::Size(44, 13);
			this->GTerrainScaleYLabel->TabIndex = 214;
			this->GTerrainScaleYLabel->Text = L"ScaleY:";
			// 
			// GTerrainScaleXTextBox
			// 
			this->GTerrainScaleXTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GTerrainScaleXTextBox->Location = System::Drawing::Point(187, 202);
			this->GTerrainScaleXTextBox->Margin = System::Windows::Forms::Padding(2);
			this->GTerrainScaleXTextBox->Name = L"GTerrainScaleXTextBox";
			this->GTerrainScaleXTextBox->Size = System::Drawing::Size(177, 20);
			this->GTerrainScaleXTextBox->TabIndex = 210;
			this->GTerrainScaleXTextBox->Text = L"90000";
			// 
			// GTerrainScaleXLabel
			// 
			this->GTerrainScaleXLabel->AutoSize = true;
			this->GTerrainScaleXLabel->Location = System::Drawing::Point(18, 206);
			this->GTerrainScaleXLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GTerrainScaleXLabel->Name = L"GTerrainScaleXLabel";
			this->GTerrainScaleXLabel->Size = System::Drawing::Size(44, 13);
			this->GTerrainScaleXLabel->TabIndex = 213;
			this->GTerrainScaleXLabel->Text = L"ScaleX:";
			// 
			// ColorMapExportExtensionTextBox
			// 
			this->ColorMapExportExtensionTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->ColorMapExportExtensionTextBox->Location = System::Drawing::Point(187, 153);
			this->ColorMapExportExtensionTextBox->Margin = System::Windows::Forms::Padding(2);
			this->ColorMapExportExtensionTextBox->Name = L"ColorMapExportExtensionTextBox";
			this->ColorMapExportExtensionTextBox->ReadOnly = true;
			this->ColorMapExportExtensionTextBox->Size = System::Drawing::Size(177, 20);
			this->ColorMapExportExtensionTextBox->TabIndex = 106;
			this->ColorMapExportExtensionTextBox->Text = L"png";
			// 
			// ColorMapExportExtensionLabel
			// 
			this->ColorMapExportExtensionLabel->AutoSize = true;
			this->ColorMapExportExtensionLabel->Location = System::Drawing::Point(18, 155);
			this->ColorMapExportExtensionLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ColorMapExportExtensionLabel->Name = L"ColorMapExportExtensionLabel";
			this->ColorMapExportExtensionLabel->Size = System::Drawing::Size(131, 13);
			this->ColorMapExportExtensionLabel->TabIndex = 107;
			this->ColorMapExportExtensionLabel->Text = L"ColorMapExportExtension:";
			// 
			// GColorMapExtensionTextBox
			// 
			this->GColorMapExtensionTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GColorMapExtensionTextBox->Location = System::Drawing::Point(187, 129);
			this->GColorMapExtensionTextBox->Margin = System::Windows::Forms::Padding(2);
			this->GColorMapExtensionTextBox->Name = L"GColorMapExtensionTextBox";
			this->GColorMapExtensionTextBox->ReadOnly = true;
			this->GColorMapExtensionTextBox->Size = System::Drawing::Size(177, 20);
			this->GColorMapExtensionTextBox->TabIndex = 103;
			this->GColorMapExtensionTextBox->Text = L"png";
			// 
			// GColorMapExtensionLabel
			// 
			this->GColorMapExtensionLabel->AutoSize = true;
			this->GColorMapExtensionLabel->Location = System::Drawing::Point(18, 132);
			this->GColorMapExtensionLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GColorMapExtensionLabel->Name = L"GColorMapExtensionLabel";
			this->GColorMapExtensionLabel->Size = System::Drawing::Size(101, 13);
			this->GColorMapExtensionLabel->TabIndex = 104;
			this->GColorMapExtensionLabel->Text = L"ColorMapExtension:";
			// 
			// GColorMapFileNameTextBox
			// 
			this->GColorMapFileNameTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GColorMapFileNameTextBox->Location = System::Drawing::Point(187, 106);
			this->GColorMapFileNameTextBox->Margin = System::Windows::Forms::Padding(2);
			this->GColorMapFileNameTextBox->Name = L"GColorMapFileNameTextBox";
			this->GColorMapFileNameTextBox->ReadOnly = true;
			this->GColorMapFileNameTextBox->Size = System::Drawing::Size(177, 20);
			this->GColorMapFileNameTextBox->TabIndex = 100;
			this->GColorMapFileNameTextBox->Text = L"ps_texture_1k.png";
			// 
			// GColorMapFileNameLabel
			// 
			this->GColorMapFileNameLabel->AutoSize = true;
			this->GColorMapFileNameLabel->Location = System::Drawing::Point(18, 108);
			this->GColorMapFileNameLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GColorMapFileNameLabel->Name = L"GColorMapFileNameLabel";
			this->GColorMapFileNameLabel->Size = System::Drawing::Size(99, 13);
			this->GColorMapFileNameLabel->TabIndex = 102;
			this->GColorMapFileNameLabel->Text = L"ColorMapFileName:";
			// 
			// GHeightMapExtensionTextBox
			// 
			this->GHeightMapExtensionTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GHeightMapExtensionTextBox->Location = System::Drawing::Point(187, 59);
			this->GHeightMapExtensionTextBox->Margin = System::Windows::Forms::Padding(2);
			this->GHeightMapExtensionTextBox->Name = L"GHeightMapExtensionTextBox";
			this->GHeightMapExtensionTextBox->ReadOnly = true;
			this->GHeightMapExtensionTextBox->Size = System::Drawing::Size(177, 20);
			this->GHeightMapExtensionTextBox->TabIndex = 69;
			this->GHeightMapExtensionTextBox->Text = L"png";
			// 
			// PagedCheckBox
			// 
			this->PagedCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->PagedCheckBox->Checked = true;
			this->PagedCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->PagedCheckBox->Location = System::Drawing::Point(18, 177);
			this->PagedCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->PagedCheckBox->Name = L"PagedCheckBox";
			this->PagedCheckBox->Size = System::Drawing::Size(231, 20);
			this->PagedCheckBox->TabIndex = 73;
			this->PagedCheckBox->Text = L"Paged:";
			this->PagedCheckBox->UseVisualStyleBackColor = true;
			// 
			// HeightMapExportExtensionTextBox
			// 
			this->HeightMapExportExtensionTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->HeightMapExportExtensionTextBox->Location = System::Drawing::Point(187, 82);
			this->HeightMapExportExtensionTextBox->Margin = System::Windows::Forms::Padding(2);
			this->HeightMapExportExtensionTextBox->Name = L"HeightMapExportExtensionTextBox";
			this->HeightMapExportExtensionTextBox->ReadOnly = true;
			this->HeightMapExportExtensionTextBox->Size = System::Drawing::Size(177, 20);
			this->HeightMapExportExtensionTextBox->TabIndex = 70;
			this->HeightMapExportExtensionTextBox->Text = L"png";
			// 
			// HeightMapExportExtensionLabel
			// 
			this->HeightMapExportExtensionLabel->AutoSize = true;
			this->HeightMapExportExtensionLabel->Location = System::Drawing::Point(18, 85);
			this->HeightMapExportExtensionLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->HeightMapExportExtensionLabel->Name = L"HeightMapExportExtensionLabel";
			this->HeightMapExportExtensionLabel->Size = System::Drawing::Size(138, 13);
			this->HeightMapExportExtensionLabel->TabIndex = 81;
			this->HeightMapExportExtensionLabel->Text = L"HeightMapExportExtension:";
			// 
			// GHeightMapExtensionLabel
			// 
			this->GHeightMapExtensionLabel->AutoSize = true;
			this->GHeightMapExtensionLabel->Location = System::Drawing::Point(18, 61);
			this->GHeightMapExtensionLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GHeightMapExtensionLabel->Name = L"GHeightMapExtensionLabel";
			this->GHeightMapExtensionLabel->Size = System::Drawing::Size(108, 13);
			this->GHeightMapExtensionLabel->TabIndex = 80;
			this->GHeightMapExtensionLabel->Text = L"HeightMapExtension:";
			// 
			// GHeightMapFileNameTextBox
			// 
			this->GHeightMapFileNameTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GHeightMapFileNameTextBox->Location = System::Drawing::Point(187, 35);
			this->GHeightMapFileNameTextBox->Margin = System::Windows::Forms::Padding(2);
			this->GHeightMapFileNameTextBox->Name = L"GHeightMapFileNameTextBox";
			this->GHeightMapFileNameTextBox->ReadOnly = true;
			this->GHeightMapFileNameTextBox->Size = System::Drawing::Size(177, 20);
			this->GHeightMapFileNameTextBox->TabIndex = 68;
			this->GHeightMapFileNameTextBox->Text = L"ps_height_1k";
			// 
			// GHeightMapFileNameLabel
			// 
			this->GHeightMapFileNameLabel->AutoSize = true;
			this->GHeightMapFileNameLabel->Location = System::Drawing::Point(18, 37);
			this->GHeightMapFileNameLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GHeightMapFileNameLabel->Name = L"GHeightMapFileNameLabel";
			this->GHeightMapFileNameLabel->Size = System::Drawing::Size(106, 13);
			this->GHeightMapFileNameLabel->TabIndex = 79;
			this->GHeightMapFileNameLabel->Text = L"HeightMapFileName:";
			// 
			// GGroupNameTextBox
			// 
			this->GGroupNameTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GGroupNameTextBox->Location = System::Drawing::Point(187, 11);
			this->GGroupNameTextBox->Margin = System::Windows::Forms::Padding(2);
			this->GGroupNameTextBox->Name = L"GGroupNameTextBox";
			this->GGroupNameTextBox->Size = System::Drawing::Size(177, 20);
			this->GGroupNameTextBox->TabIndex = 67;
			this->GGroupNameTextBox->Text = L"PLSM2";
			// 
			// GGroupNameLabel
			// 
			this->GGroupNameLabel->AutoSize = true;
			this->GGroupNameLabel->Location = System::Drawing::Point(18, 14);
			this->GGroupNameLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GGroupNameLabel->Name = L"GGroupNameLabel";
			this->GGroupNameLabel->Size = System::Drawing::Size(67, 13);
			this->GGroupNameLabel->TabIndex = 74;
			this->GGroupNameLabel->Text = L"GroupName:";
			// 
			// GPagingTabPage
			// 
			this->GPagingTabPage->AutoScroll = true;
			this->GPagingTabPage->Controls->Add(this->GTileSizeTextBox);
			this->GPagingTabPage->Controls->Add(this->GTileSizeLabel);
			this->GPagingTabPage->Controls->Add(this->GMinValueTextBox);
			this->GPagingTabPage->Controls->Add(this->GMinValueLabel);
			this->GPagingTabPage->Controls->Add(this->GMaxValueTextBox);
			this->GPagingTabPage->Controls->Add(this->GMaxValueLabel);
			this->GPagingTabPage->Controls->Add(this->GData2DFormatComboBox);
			this->GPagingTabPage->Controls->Add(this->GData2DFormatLabel);
			this->GPagingTabPage->Controls->Add(this->GPageSizeTextBox);
			this->GPagingTabPage->Controls->Add(this->GPageSizeLabel);
			this->GPagingTabPage->Location = System::Drawing::Point(4, 22);
			this->GPagingTabPage->Margin = System::Windows::Forms::Padding(2);
			this->GPagingTabPage->Name = L"GPagingTabPage";
			this->GPagingTabPage->Padding = System::Windows::Forms::Padding(2);
			this->GPagingTabPage->Size = System::Drawing::Size(401, 241);
			this->GPagingTabPage->TabIndex = 1;
			this->GPagingTabPage->Text = L"Paging";
			this->GPagingTabPage->UseVisualStyleBackColor = true;
			// 
			// GTileSizeTextBox
			// 
			this->GTileSizeTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GTileSizeTextBox->Location = System::Drawing::Point(169, 35);
			this->GTileSizeTextBox->Margin = System::Windows::Forms::Padding(2);
			this->GTileSizeTextBox->Name = L"GTileSizeTextBox";
			this->GTileSizeTextBox->Size = System::Drawing::Size(194, 20);
			this->GTileSizeTextBox->TabIndex = 73;
			this->GTileSizeTextBox->Text = L"65";
			// 
			// GTileSizeLabel
			// 
			this->GTileSizeLabel->AutoSize = true;
			this->GTileSizeLabel->Location = System::Drawing::Point(18, 37);
			this->GTileSizeLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GTileSizeLabel->Name = L"GTileSizeLabel";
			this->GTileSizeLabel->Size = System::Drawing::Size(47, 13);
			this->GTileSizeLabel->TabIndex = 81;
			this->GTileSizeLabel->Text = L"TileSize:";
			// 
			// GMinValueTextBox
			// 
			this->GMinValueTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GMinValueTextBox->Enabled = false;
			this->GMinValueTextBox->Location = System::Drawing::Point(169, 106);
			this->GMinValueTextBox->Margin = System::Windows::Forms::Padding(2);
			this->GMinValueTextBox->Name = L"GMinValueTextBox";
			this->GMinValueTextBox->Size = System::Drawing::Size(194, 20);
			this->GMinValueTextBox->TabIndex = 76;
			this->GMinValueTextBox->Text = L"0";
			// 
			// GMinValueLabel
			// 
			this->GMinValueLabel->AutoSize = true;
			this->GMinValueLabel->Location = System::Drawing::Point(19, 108);
			this->GMinValueLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GMinValueLabel->Name = L"GMinValueLabel";
			this->GMinValueLabel->Size = System::Drawing::Size(54, 13);
			this->GMinValueLabel->TabIndex = 80;
			this->GMinValueLabel->Text = L"MinValue:";
			// 
			// GMaxValueTextBox
			// 
			this->GMaxValueTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GMaxValueTextBox->Enabled = false;
			this->GMaxValueTextBox->Location = System::Drawing::Point(169, 82);
			this->GMaxValueTextBox->Margin = System::Windows::Forms::Padding(2);
			this->GMaxValueTextBox->Name = L"GMaxValueTextBox";
			this->GMaxValueTextBox->Size = System::Drawing::Size(194, 20);
			this->GMaxValueTextBox->TabIndex = 75;
			this->GMaxValueTextBox->Text = L"0";
			// 
			// GMaxValueLabel
			// 
			this->GMaxValueLabel->AutoSize = true;
			this->GMaxValueLabel->Location = System::Drawing::Point(18, 85);
			this->GMaxValueLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GMaxValueLabel->Name = L"GMaxValueLabel";
			this->GMaxValueLabel->Size = System::Drawing::Size(57, 13);
			this->GMaxValueLabel->TabIndex = 79;
			this->GMaxValueLabel->Text = L"MaxValue:";
			// 
			// GData2DFormatComboBox
			// 
			this->GData2DFormatComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GData2DFormatComboBox->FormattingEnabled = true;
			this->GData2DFormatComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"HeightField", L"HeightFieldTC", L"SplineField"});
			this->GData2DFormatComboBox->Location = System::Drawing::Point(169, 59);
			this->GData2DFormatComboBox->Margin = System::Windows::Forms::Padding(2);
			this->GData2DFormatComboBox->Name = L"GData2DFormatComboBox";
			this->GData2DFormatComboBox->Size = System::Drawing::Size(194, 21);
			this->GData2DFormatComboBox->TabIndex = 74;
			this->GData2DFormatComboBox->Text = L"HeightField";
			// 
			// GData2DFormatLabel
			// 
			this->GData2DFormatLabel->AutoSize = true;
			this->GData2DFormatLabel->Location = System::Drawing::Point(18, 61);
			this->GData2DFormatLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GData2DFormatLabel->Name = L"GData2DFormatLabel";
			this->GData2DFormatLabel->Size = System::Drawing::Size(79, 13);
			this->GData2DFormatLabel->TabIndex = 78;
			this->GData2DFormatLabel->Text = L"Data2DFormat:";
			// 
			// GPageSizeTextBox
			// 
			this->GPageSizeTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GPageSizeTextBox->Location = System::Drawing::Point(169, 11);
			this->GPageSizeTextBox->Margin = System::Windows::Forms::Padding(2);
			this->GPageSizeTextBox->Name = L"GPageSizeTextBox";
			this->GPageSizeTextBox->Size = System::Drawing::Size(194, 20);
			this->GPageSizeTextBox->TabIndex = 72;
			this->GPageSizeTextBox->Text = L"513";
			// 
			// GPageSizeLabel
			// 
			this->GPageSizeLabel->AutoSize = true;
			this->GPageSizeLabel->Location = System::Drawing::Point(18, 14);
			this->GPageSizeLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GPageSizeLabel->Name = L"GPageSizeLabel";
			this->GPageSizeLabel->Size = System::Drawing::Size(55, 13);
			this->GPageSizeLabel->TabIndex = 77;
			this->GPageSizeLabel->Text = L"PageSize:";
			// 
			// GHeightMapTabPage
			// 
			this->GHeightMapTabPage->AutoScroll = true;
			this->GHeightMapTabPage->Controls->Add(this->MiniMapHeightTextBox);
			this->GHeightMapTabPage->Controls->Add(this->MiniMapHeightLabel);
			this->GHeightMapTabPage->Controls->Add(this->MiniMapWidthTextBox);
			this->GHeightMapTabPage->Controls->Add(this->MiniMapWidthLabel);
			this->GHeightMapTabPage->Controls->Add(this->EqualizeCheckBox);
			this->GHeightMapTabPage->Controls->Add(this->HeightMapBlurFactorTextBox);
			this->GHeightMapTabPage->Controls->Add(this->HeightMapBlurFactorLabel);
			this->GHeightMapTabPage->Controls->Add(this->InfiniteMapCheckBox);
			this->GHeightMapTabPage->Controls->Add(this->HeightMapCheckBox);
			this->GHeightMapTabPage->Controls->Add(this->MiniMapCheckBox);
			this->GHeightMapTabPage->Location = System::Drawing::Point(4, 22);
			this->GHeightMapTabPage->Margin = System::Windows::Forms::Padding(2);
			this->GHeightMapTabPage->Name = L"GHeightMapTabPage";
			this->GHeightMapTabPage->Size = System::Drawing::Size(401, 241);
			this->GHeightMapTabPage->TabIndex = 3;
			this->GHeightMapTabPage->Text = L"Height Map";
			this->GHeightMapTabPage->UseVisualStyleBackColor = true;
			// 
			// MiniMapHeightTextBox
			// 
			this->MiniMapHeightTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->MiniMapHeightTextBox->Location = System::Drawing::Point(169, 149);
			this->MiniMapHeightTextBox->Margin = System::Windows::Forms::Padding(2);
			this->MiniMapHeightTextBox->Name = L"MiniMapHeightTextBox";
			this->MiniMapHeightTextBox->Size = System::Drawing::Size(194, 20);
			this->MiniMapHeightTextBox->TabIndex = 96;
			this->MiniMapHeightTextBox->Text = L"512";
			// 
			// MiniMapHeightLabel
			// 
			this->MiniMapHeightLabel->AutoSize = true;
			this->MiniMapHeightLabel->Location = System::Drawing::Point(19, 151);
			this->MiniMapHeightLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->MiniMapHeightLabel->Name = L"MiniMapHeightLabel";
			this->MiniMapHeightLabel->Size = System::Drawing::Size(81, 13);
			this->MiniMapHeightLabel->TabIndex = 106;
			this->MiniMapHeightLabel->Text = L"MiniMapHeight:";
			// 
			// MiniMapWidthTextBox
			// 
			this->MiniMapWidthTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->MiniMapWidthTextBox->Location = System::Drawing::Point(169, 125);
			this->MiniMapWidthTextBox->Margin = System::Windows::Forms::Padding(2);
			this->MiniMapWidthTextBox->Name = L"MiniMapWidthTextBox";
			this->MiniMapWidthTextBox->Size = System::Drawing::Size(194, 20);
			this->MiniMapWidthTextBox->TabIndex = 95;
			this->MiniMapWidthTextBox->Text = L"512";
			// 
			// MiniMapWidthLabel
			// 
			this->MiniMapWidthLabel->AutoSize = true;
			this->MiniMapWidthLabel->Location = System::Drawing::Point(19, 128);
			this->MiniMapWidthLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->MiniMapWidthLabel->Name = L"MiniMapWidthLabel";
			this->MiniMapWidthLabel->Size = System::Drawing::Size(78, 13);
			this->MiniMapWidthLabel->TabIndex = 105;
			this->MiniMapWidthLabel->Text = L"MiniMapWidth:";
			// 
			// EqualizeCheckBox
			// 
			this->EqualizeCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->EqualizeCheckBox->Location = System::Drawing::Point(18, 78);
			this->EqualizeCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->EqualizeCheckBox->Name = L"EqualizeCheckBox";
			this->EqualizeCheckBox->Size = System::Drawing::Size(231, 20);
			this->EqualizeCheckBox->TabIndex = 93;
			this->EqualizeCheckBox->Text = L"Equalize:";
			this->EqualizeCheckBox->UseVisualStyleBackColor = true;
			// 
			// HeightMapBlurFactorTextBox
			// 
			this->HeightMapBlurFactorTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->HeightMapBlurFactorTextBox->Location = System::Drawing::Point(169, 55);
			this->HeightMapBlurFactorTextBox->Margin = System::Windows::Forms::Padding(2);
			this->HeightMapBlurFactorTextBox->Name = L"HeightMapBlurFactorTextBox";
			this->HeightMapBlurFactorTextBox->Size = System::Drawing::Size(194, 20);
			this->HeightMapBlurFactorTextBox->TabIndex = 92;
			this->HeightMapBlurFactorTextBox->Text = L"0.0f";
			// 
			// HeightMapBlurFactorLabel
			// 
			this->HeightMapBlurFactorLabel->AutoSize = true;
			this->HeightMapBlurFactorLabel->Location = System::Drawing::Point(19, 57);
			this->HeightMapBlurFactorLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->HeightMapBlurFactorLabel->Name = L"HeightMapBlurFactorLabel";
			this->HeightMapBlurFactorLabel->Size = System::Drawing::Size(110, 13);
			this->HeightMapBlurFactorLabel->TabIndex = 104;
			this->HeightMapBlurFactorLabel->Text = L"HeightMapBlurFactor:";
			// 
			// InfiniteMapCheckBox
			// 
			this->InfiniteMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->InfiniteMapCheckBox->Location = System::Drawing::Point(18, 31);
			this->InfiniteMapCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->InfiniteMapCheckBox->Name = L"InfiniteMapCheckBox";
			this->InfiniteMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->InfiniteMapCheckBox->TabIndex = 91;
			this->InfiniteMapCheckBox->Text = L"InfiniteMap:";
			this->InfiniteMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// HeightMapCheckBox
			// 
			this->HeightMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->HeightMapCheckBox->Checked = true;
			this->HeightMapCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->HeightMapCheckBox->Location = System::Drawing::Point(18, 7);
			this->HeightMapCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->HeightMapCheckBox->Name = L"HeightMapCheckBox";
			this->HeightMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->HeightMapCheckBox->TabIndex = 90;
			this->HeightMapCheckBox->Text = L"HeightMap:";
			this->HeightMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// MiniMapCheckBox
			// 
			this->MiniMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->MiniMapCheckBox->Checked = true;
			this->MiniMapCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->MiniMapCheckBox->Location = System::Drawing::Point(19, 102);
			this->MiniMapCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->MiniMapCheckBox->Name = L"MiniMapCheckBox";
			this->MiniMapCheckBox->Size = System::Drawing::Size(230, 20);
			this->MiniMapCheckBox->TabIndex = 94;
			this->MiniMapCheckBox->Text = L"MiniMap:";
			this->MiniMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// GColorMapTabPage
			// 
			this->GColorMapTabPage->AutoScroll = true;
			this->GColorMapTabPage->Controls->Add(this->GColorMapStretchFactorTextBox);
			this->GColorMapTabPage->Controls->Add(this->GColorMapStretchFactorLabel);
			this->GColorMapTabPage->Controls->Add(this->LitColorMapSplitCheckBox);
			this->GColorMapTabPage->Controls->Add(this->ColorMapSplitCheckBox);
			this->GColorMapTabPage->Location = System::Drawing::Point(4, 22);
			this->GColorMapTabPage->Margin = System::Windows::Forms::Padding(2);
			this->GColorMapTabPage->Name = L"GColorMapTabPage";
			this->GColorMapTabPage->Size = System::Drawing::Size(401, 241);
			this->GColorMapTabPage->TabIndex = 2;
			this->GColorMapTabPage->Text = L"Color Map";
			this->GColorMapTabPage->UseVisualStyleBackColor = true;
			// 
			// GColorMapStretchFactorTextBox
			// 
			this->GColorMapStretchFactorTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GColorMapStretchFactorTextBox->Location = System::Drawing::Point(183, 11);
			this->GColorMapStretchFactorTextBox->Margin = System::Windows::Forms::Padding(2);
			this->GColorMapStretchFactorTextBox->Name = L"GColorMapStretchFactorTextBox";
			this->GColorMapStretchFactorTextBox->Size = System::Drawing::Size(194, 20);
			this->GColorMapStretchFactorTextBox->TabIndex = 97;
			this->GColorMapStretchFactorTextBox->Text = L"1";
			// 
			// GColorMapStretchFactorLabel
			// 
			this->GColorMapStretchFactorLabel->AutoSize = true;
			this->GColorMapStretchFactorLabel->Location = System::Drawing::Point(18, 14);
			this->GColorMapStretchFactorLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GColorMapStretchFactorLabel->Name = L"GColorMapStretchFactorLabel";
			this->GColorMapStretchFactorLabel->Size = System::Drawing::Size(119, 13);
			this->GColorMapStretchFactorLabel->TabIndex = 101;
			this->GColorMapStretchFactorLabel->Text = L"ColorMapStretchFactor:";
			// 
			// LitColorMapSplitCheckBox
			// 
			this->LitColorMapSplitCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->LitColorMapSplitCheckBox->Location = System::Drawing::Point(18, 59);
			this->LitColorMapSplitCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->LitColorMapSplitCheckBox->Name = L"LitColorMapSplitCheckBox";
			this->LitColorMapSplitCheckBox->Size = System::Drawing::Size(243, 20);
			this->LitColorMapSplitCheckBox->TabIndex = 77;
			this->LitColorMapSplitCheckBox->Text = L"LitColorMapSplit:";
			this->LitColorMapSplitCheckBox->UseVisualStyleBackColor = true;
			// 
			// ColorMapSplitCheckBox
			// 
			this->ColorMapSplitCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->ColorMapSplitCheckBox->Checked = true;
			this->ColorMapSplitCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->ColorMapSplitCheckBox->Location = System::Drawing::Point(17, 37);
			this->ColorMapSplitCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->ColorMapSplitCheckBox->Name = L"ColorMapSplitCheckBox";
			this->ColorMapSplitCheckBox->Size = System::Drawing::Size(244, 20);
			this->ColorMapSplitCheckBox->TabIndex = 76;
			this->ColorMapSplitCheckBox->Text = L"ColorMapSplit:";
			this->ColorMapSplitCheckBox->UseVisualStyleBackColor = true;
			// 
			// GNormalsTabPage
			// 
			this->GNormalsTabPage->AutoScroll = true;
			this->GNormalsTabPage->Controls->Add(this->HeightNormalMapCheckBox);
			this->GNormalsTabPage->Controls->Add(this->NormalMapCheckBox);
			this->GNormalsTabPage->Controls->Add(this->LitColorMapGenerateCheckBox);
			this->GNormalsTabPage->Controls->Add(this->ColorMapGenerateCheckBox);
			this->GNormalsTabPage->Location = System::Drawing::Point(4, 22);
			this->GNormalsTabPage->Margin = System::Windows::Forms::Padding(2);
			this->GNormalsTabPage->Name = L"GNormalsTabPage";
			this->GNormalsTabPage->Size = System::Drawing::Size(401, 241);
			this->GNormalsTabPage->TabIndex = 4;
			this->GNormalsTabPage->Text = L"Normals";
			this->GNormalsTabPage->UseVisualStyleBackColor = true;
			// 
			// HeightNormalMapCheckBox
			// 
			this->HeightNormalMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->HeightNormalMapCheckBox->Location = System::Drawing::Point(18, 31);
			this->HeightNormalMapCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->HeightNormalMapCheckBox->Name = L"HeightNormalMapCheckBox";
			this->HeightNormalMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->HeightNormalMapCheckBox->TabIndex = 87;
			this->HeightNormalMapCheckBox->Text = L"HeightNormalMap:";
			this->HeightNormalMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// NormalMapCheckBox
			// 
			this->NormalMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->NormalMapCheckBox->Location = System::Drawing::Point(18, 7);
			this->NormalMapCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->NormalMapCheckBox->Name = L"NormalMapCheckBox";
			this->NormalMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->NormalMapCheckBox->TabIndex = 86;
			this->NormalMapCheckBox->Text = L"NormalMap:";
			this->NormalMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// LitColorMapGenerateCheckBox
			// 
			this->LitColorMapGenerateCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->LitColorMapGenerateCheckBox->Location = System::Drawing::Point(18, 78);
			this->LitColorMapGenerateCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->LitColorMapGenerateCheckBox->Name = L"LitColorMapGenerateCheckBox";
			this->LitColorMapGenerateCheckBox->Size = System::Drawing::Size(231, 20);
			this->LitColorMapGenerateCheckBox->TabIndex = 89;
			this->LitColorMapGenerateCheckBox->Text = L"LitColorMapGenerate:";
			this->LitColorMapGenerateCheckBox->UseVisualStyleBackColor = true;
			// 
			// ColorMapGenerateCheckBox
			// 
			this->ColorMapGenerateCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->ColorMapGenerateCheckBox->Location = System::Drawing::Point(18, 55);
			this->ColorMapGenerateCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->ColorMapGenerateCheckBox->Name = L"ColorMapGenerateCheckBox";
			this->ColorMapGenerateCheckBox->Size = System::Drawing::Size(231, 20);
			this->ColorMapGenerateCheckBox->TabIndex = 88;
			this->ColorMapGenerateCheckBox->Text = L"ColorMapGenerate:";
			this->ColorMapGenerateCheckBox->UseVisualStyleBackColor = true;
			// 
			// GSplattingTabPage
			// 
			this->GSplattingTabPage->AutoScroll = true;
			this->GSplattingTabPage->Controls->Add(this->GSetSplatFileNamesRichTextBox);
			this->GSplattingTabPage->Controls->Add(this->GSetMaterialHeightRichTextBox);
			this->GSplattingTabPage->Controls->Add(this->GSetMaterialHeightLabel);
			this->GSplattingTabPage->Controls->Add(this->GSetMaterialColorRichTextBox);
			this->GSplattingTabPage->Controls->Add(this->NumMatHeightSplatTextBox);
			this->GSplattingTabPage->Controls->Add(this->NumMatHeightSplatLabel);
			this->GSplattingTabPage->Controls->Add(this->GSetSplatFileNamesLabel);
			this->GSplattingTabPage->Controls->Add(this->GSetMaterialColorLabel);
			this->GSplattingTabPage->Controls->Add(this->RGBMapsCheckBox);
			this->GSplattingTabPage->Controls->Add(this->AlphaSplatLightMapsCheckBox);
			this->GSplattingTabPage->Controls->Add(this->AlphaSplatRGBAMapsCheckBox);
			this->GSplattingTabPage->Controls->Add(this->CoverageMapCheckBox);
			this->GSplattingTabPage->Controls->Add(this->LitBaseMapCheckBox);
			this->GSplattingTabPage->Controls->Add(this->BaseMapCheckBox);
			this->GSplattingTabPage->Controls->Add(this->AvgColorsExistsCheckBox);
			this->GSplattingTabPage->Controls->Add(this->AlphaMapsCheckBox);
			this->GSplattingTabPage->Location = System::Drawing::Point(4, 22);
			this->GSplattingTabPage->Margin = System::Windows::Forms::Padding(2);
			this->GSplattingTabPage->Name = L"GSplattingTabPage";
			this->GSplattingTabPage->Size = System::Drawing::Size(401, 241);
			this->GSplattingTabPage->TabIndex = 5;
			this->GSplattingTabPage->Text = L"Splatting";
			this->GSplattingTabPage->UseVisualStyleBackColor = true;
			// 
			// GSetSplatFileNamesRichTextBox
			// 
			this->GSetSplatFileNamesRichTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GSetSplatFileNamesRichTextBox->Location = System::Drawing::Point(21, 248);
			this->GSetSplatFileNamesRichTextBox->Margin = System::Windows::Forms::Padding(2);
			this->GSetSplatFileNamesRichTextBox->Name = L"GSetSplatFileNamesRichTextBox";
			this->GSetSplatFileNamesRichTextBox->Size = System::Drawing::Size(339, 70);
			this->GSetSplatFileNamesRichTextBox->TabIndex = 188;
			this->GSetSplatFileNamesRichTextBox->Text = L"#needs to be in maptool directory\nSplatFilename0=splatting_sand.png\nSplatFilename" 
				L"1=splatting_grass.png\nSplatFilename2=splatting_rock.png\nSplatFilename3=splatting" 
				L"_snow.png";
			this->GSetSplatFileNamesRichTextBox->WordWrap = false;
			// 
			// GSetMaterialHeightRichTextBox
			// 
			this->GSetMaterialHeightRichTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GSetMaterialHeightRichTextBox->Location = System::Drawing::Point(21, 74);
			this->GSetMaterialHeightRichTextBox->Margin = System::Windows::Forms::Padding(2);
			this->GSetMaterialHeightRichTextBox->Name = L"GSetMaterialHeightRichTextBox";
			this->GSetMaterialHeightRichTextBox->Size = System::Drawing::Size(339, 70);
			this->GSetMaterialHeightRichTextBox->TabIndex = 187;
			this->GSetMaterialHeightRichTextBox->Text = L"MaterialHeight0=0\nMaterialHeight1=12\nMaterialHeight2=60\nMaterialHeight3=75";
			this->GSetMaterialHeightRichTextBox->WordWrap = false;
			// 
			// GSetMaterialHeightLabel
			// 
			this->GSetMaterialHeightLabel->AutoSize = true;
			this->GSetMaterialHeightLabel->Location = System::Drawing::Point(18, 59);
			this->GSetMaterialHeightLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GSetMaterialHeightLabel->Name = L"GSetMaterialHeightLabel";
			this->GSetMaterialHeightLabel->Size = System::Drawing::Size(97, 13);
			this->GSetMaterialHeightLabel->TabIndex = 186;
			this->GSetMaterialHeightLabel->Text = L"Set Material Height";
			// 
			// GSetMaterialColorRichTextBox
			// 
			this->GSetMaterialColorRichTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GSetMaterialColorRichTextBox->Location = System::Drawing::Point(21, 161);
			this->GSetMaterialColorRichTextBox->Margin = System::Windows::Forms::Padding(2);
			this->GSetMaterialColorRichTextBox->Name = L"GSetMaterialColorRichTextBox";
			this->GSetMaterialColorRichTextBox->Size = System::Drawing::Size(339, 70);
			this->GSetMaterialColorRichTextBox->TabIndex = 184;
			this->GSetMaterialColorRichTextBox->Text = L"#Sand\nMaterialColor0=1.0f 1.0f 0.0f 1.0f\n#Grass\nMaterialColor1=0.13f 0.545f 0.13f" 
				L" 1.0f\n#Rock\nMaterialColor2=0.411764f 0.411764f 0.411764f 1.0f\n#Snow\nMaterialColo" 
				L"r3=1.0f 0.98f 0.98f 1.0f";
			this->GSetMaterialColorRichTextBox->WordWrap = false;
			// 
			// NumMatHeightSplatTextBox
			// 
			this->NumMatHeightSplatTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->NumMatHeightSplatTextBox->Location = System::Drawing::Point(164, 31);
			this->NumMatHeightSplatTextBox->Margin = System::Windows::Forms::Padding(2);
			this->NumMatHeightSplatTextBox->Name = L"NumMatHeightSplatTextBox";
			this->NumMatHeightSplatTextBox->Size = System::Drawing::Size(196, 20);
			this->NumMatHeightSplatTextBox->TabIndex = 183;
			this->NumMatHeightSplatTextBox->Text = L"4";
			// 
			// NumMatHeightSplatLabel
			// 
			this->NumMatHeightSplatLabel->AutoSize = true;
			this->NumMatHeightSplatLabel->Location = System::Drawing::Point(18, 33);
			this->NumMatHeightSplatLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->NumMatHeightSplatLabel->Name = L"NumMatHeightSplatLabel";
			this->NumMatHeightSplatLabel->Size = System::Drawing::Size(105, 13);
			this->NumMatHeightSplatLabel->TabIndex = 182;
			this->NumMatHeightSplatLabel->Text = L"NumMatHeightSplat:";
			// 
			// GSetSplatFileNamesLabel
			// 
			this->GSetSplatFileNamesLabel->AutoSize = true;
			this->GSetSplatFileNamesLabel->Location = System::Drawing::Point(18, 233);
			this->GSetSplatFileNamesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GSetSplatFileNamesLabel->Name = L"GSetSplatFileNamesLabel";
			this->GSetSplatFileNamesLabel->Size = System::Drawing::Size(105, 13);
			this->GSetSplatFileNamesLabel->TabIndex = 180;
			this->GSetSplatFileNamesLabel->Text = L"Set Splat File Names";
			// 
			// GSetMaterialColorLabel
			// 
			this->GSetMaterialColorLabel->AutoSize = true;
			this->GSetMaterialColorLabel->Location = System::Drawing::Point(18, 146);
			this->GSetMaterialColorLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GSetMaterialColorLabel->Name = L"GSetMaterialColorLabel";
			this->GSetMaterialColorLabel->Size = System::Drawing::Size(90, 13);
			this->GSetMaterialColorLabel->TabIndex = 179;
			this->GSetMaterialColorLabel->Text = L"Set Material Color";
			// 
			// RGBMapsCheckBox
			// 
			this->RGBMapsCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->RGBMapsCheckBox->Location = System::Drawing::Point(21, 464);
			this->RGBMapsCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->RGBMapsCheckBox->Name = L"RGBMapsCheckBox";
			this->RGBMapsCheckBox->Size = System::Drawing::Size(231, 20);
			this->RGBMapsCheckBox->TabIndex = 162;
			this->RGBMapsCheckBox->Text = L"RGBMaps:";
			this->RGBMapsCheckBox->UseVisualStyleBackColor = true;
			// 
			// AlphaSplatLightMapsCheckBox
			// 
			this->AlphaSplatLightMapsCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->AlphaSplatLightMapsCheckBox->Location = System::Drawing::Point(21, 441);
			this->AlphaSplatLightMapsCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->AlphaSplatLightMapsCheckBox->Name = L"AlphaSplatLightMapsCheckBox";
			this->AlphaSplatLightMapsCheckBox->Size = System::Drawing::Size(231, 20);
			this->AlphaSplatLightMapsCheckBox->TabIndex = 161;
			this->AlphaSplatLightMapsCheckBox->Text = L"AlphaSplatLightMaps:";
			this->AlphaSplatLightMapsCheckBox->UseVisualStyleBackColor = true;
			// 
			// AlphaSplatRGBAMapsCheckBox
			// 
			this->AlphaSplatRGBAMapsCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->AlphaSplatRGBAMapsCheckBox->Location = System::Drawing::Point(21, 417);
			this->AlphaSplatRGBAMapsCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->AlphaSplatRGBAMapsCheckBox->Name = L"AlphaSplatRGBAMapsCheckBox";
			this->AlphaSplatRGBAMapsCheckBox->Size = System::Drawing::Size(231, 20);
			this->AlphaSplatRGBAMapsCheckBox->TabIndex = 160;
			this->AlphaSplatRGBAMapsCheckBox->Text = L"AlphaSplatRGBAMaps:";
			this->AlphaSplatRGBAMapsCheckBox->UseVisualStyleBackColor = true;
			// 
			// CoverageMapCheckBox
			// 
			this->CoverageMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->CoverageMapCheckBox->Location = System::Drawing::Point(21, 370);
			this->CoverageMapCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->CoverageMapCheckBox->Name = L"CoverageMapCheckBox";
			this->CoverageMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->CoverageMapCheckBox->TabIndex = 158;
			this->CoverageMapCheckBox->Text = L"CoverageMap:";
			this->CoverageMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// LitBaseMapCheckBox
			// 
			this->LitBaseMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->LitBaseMapCheckBox->Location = System::Drawing::Point(21, 346);
			this->LitBaseMapCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->LitBaseMapCheckBox->Name = L"LitBaseMapCheckBox";
			this->LitBaseMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->LitBaseMapCheckBox->TabIndex = 157;
			this->LitBaseMapCheckBox->Text = L"LitBaseMap:";
			this->LitBaseMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// BaseMapCheckBox
			// 
			this->BaseMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->BaseMapCheckBox->Location = System::Drawing::Point(21, 322);
			this->BaseMapCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->BaseMapCheckBox->Name = L"BaseMapCheckBox";
			this->BaseMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->BaseMapCheckBox->TabIndex = 156;
			this->BaseMapCheckBox->Text = L"BaseMap:";
			this->BaseMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// AvgColorsExistsCheckBox
			// 
			this->AvgColorsExistsCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->AvgColorsExistsCheckBox->Checked = true;
			this->AvgColorsExistsCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->AvgColorsExistsCheckBox->Location = System::Drawing::Point(18, 7);
			this->AvgColorsExistsCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->AvgColorsExistsCheckBox->Name = L"AvgColorsExistsCheckBox";
			this->AvgColorsExistsCheckBox->Size = System::Drawing::Size(231, 20);
			this->AvgColorsExistsCheckBox->TabIndex = 155;
			this->AvgColorsExistsCheckBox->Text = L"AvgColorsExists:";
			this->AvgColorsExistsCheckBox->UseVisualStyleBackColor = true;
			// 
			// AlphaMapsCheckBox
			// 
			this->AlphaMapsCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->AlphaMapsCheckBox->Location = System::Drawing::Point(21, 393);
			this->AlphaMapsCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->AlphaMapsCheckBox->Name = L"AlphaMapsCheckBox";
			this->AlphaMapsCheckBox->Size = System::Drawing::Size(231, 20);
			this->AlphaMapsCheckBox->TabIndex = 159;
			this->AlphaMapsCheckBox->Text = L"AlphaMaps:";
			this->AlphaMapsCheckBox->UseVisualStyleBackColor = true;
			// 
			// GLightingTabPage
			// 
			this->GLightingTabPage->AutoScroll = true;
			this->GLightingTabPage->Controls->Add(this->PVSMapCheckBox);
			this->GLightingTabPage->Controls->Add(this->VisibilityLabel);
			this->GLightingTabPage->Controls->Add(this->ZHorizonCheckBox);
			this->GLightingTabPage->Controls->Add(this->ElevationMapCheckBox);
			this->GLightingTabPage->Controls->Add(this->HorizonMapCheckBox);
			this->GLightingTabPage->Controls->Add(this->RealTimeLightingLabel);
			this->GLightingTabPage->Controls->Add(this->BlurTextBox);
			this->GLightingTabPage->Controls->Add(this->BlurLabel);
			this->GLightingTabPage->Controls->Add(this->DiffuseTextBox);
			this->GLightingTabPage->Controls->Add(this->DiffuseLabel);
			this->GLightingTabPage->Controls->Add(this->AmbientTextBox);
			this->GLightingTabPage->Controls->Add(this->AmbientLabel);
			this->GLightingTabPage->Controls->Add(this->SunzTextBox);
			this->GLightingTabPage->Controls->Add(this->SunzLabel);
			this->GLightingTabPage->Controls->Add(this->SunyTextBox);
			this->GLightingTabPage->Controls->Add(this->SunyLabel);
			this->GLightingTabPage->Controls->Add(this->ShadowMapCheckBox);
			this->GLightingTabPage->Controls->Add(this->LightMapCheckBox);
			this->GLightingTabPage->Controls->Add(this->SunxTextBox);
			this->GLightingTabPage->Controls->Add(this->SunxLabel);
			this->GLightingTabPage->Location = System::Drawing::Point(4, 22);
			this->GLightingTabPage->Margin = System::Windows::Forms::Padding(2);
			this->GLightingTabPage->Name = L"GLightingTabPage";
			this->GLightingTabPage->Size = System::Drawing::Size(401, 241);
			this->GLightingTabPage->TabIndex = 6;
			this->GLightingTabPage->Text = L"Lighting";
			this->GLightingTabPage->UseVisualStyleBackColor = true;
			// 
			// PVSMapCheckBox
			// 
			this->PVSMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->PVSMapCheckBox->Location = System::Drawing::Point(30, 301);
			this->PVSMapCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->PVSMapCheckBox->Name = L"PVSMapCheckBox";
			this->PVSMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->PVSMapCheckBox->TabIndex = 158;
			this->PVSMapCheckBox->Text = L"PVSMap:";
			this->PVSMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// VisibilityLabel
			// 
			this->VisibilityLabel->AutoSize = true;
			this->VisibilityLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->VisibilityLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->VisibilityLabel->Location = System::Drawing::Point(9, 283);
			this->VisibilityLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->VisibilityLabel->Name = L"VisibilityLabel";
			this->VisibilityLabel->Size = System::Drawing::Size(45, 15);
			this->VisibilityLabel->TabIndex = 179;
			this->VisibilityLabel->Text = L"Visibility";
			// 
			// ZHorizonCheckBox
			// 
			this->ZHorizonCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->ZHorizonCheckBox->Location = System::Drawing::Point(30, 262);
			this->ZHorizonCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->ZHorizonCheckBox->Name = L"ZHorizonCheckBox";
			this->ZHorizonCheckBox->Size = System::Drawing::Size(231, 20);
			this->ZHorizonCheckBox->TabIndex = 157;
			this->ZHorizonCheckBox->Text = L"ZHorizon:";
			this->ZHorizonCheckBox->UseVisualStyleBackColor = true;
			// 
			// ElevationMapCheckBox
			// 
			this->ElevationMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->ElevationMapCheckBox->Location = System::Drawing::Point(30, 239);
			this->ElevationMapCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->ElevationMapCheckBox->Name = L"ElevationMapCheckBox";
			this->ElevationMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->ElevationMapCheckBox->TabIndex = 156;
			this->ElevationMapCheckBox->Text = L"ElevationMap:";
			this->ElevationMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// HorizonMapCheckBox
			// 
			this->HorizonMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->HorizonMapCheckBox->Location = System::Drawing::Point(30, 215);
			this->HorizonMapCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->HorizonMapCheckBox->Name = L"HorizonMapCheckBox";
			this->HorizonMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->HorizonMapCheckBox->TabIndex = 155;
			this->HorizonMapCheckBox->Text = L"HorizonMap:";
			this->HorizonMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// RealTimeLightingLabel
			// 
			this->RealTimeLightingLabel->AutoSize = true;
			this->RealTimeLightingLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->RealTimeLightingLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->RealTimeLightingLabel->Location = System::Drawing::Point(9, 197);
			this->RealTimeLightingLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RealTimeLightingLabel->Name = L"RealTimeLightingLabel";
			this->RealTimeLightingLabel->Size = System::Drawing::Size(97, 15);
			this->RealTimeLightingLabel->TabIndex = 178;
			this->RealTimeLightingLabel->Text = L"Real-Time Lighting";
			// 
			// BlurTextBox
			// 
			this->BlurTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->BlurTextBox->Location = System::Drawing::Point(165, 172);
			this->BlurTextBox->Margin = System::Windows::Forms::Padding(2);
			this->BlurTextBox->Name = L"BlurTextBox";
			this->BlurTextBox->Size = System::Drawing::Size(196, 20);
			this->BlurTextBox->TabIndex = 154;
			this->BlurTextBox->Text = L"0.5f";
			// 
			// BlurLabel
			// 
			this->BlurLabel->AutoSize = true;
			this->BlurLabel->Location = System::Drawing::Point(19, 175);
			this->BlurLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->BlurLabel->Name = L"BlurLabel";
			this->BlurLabel->Size = System::Drawing::Size(28, 13);
			this->BlurLabel->TabIndex = 177;
			this->BlurLabel->Text = L"Blur:";
			// 
			// DiffuseTextBox
			// 
			this->DiffuseTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->DiffuseTextBox->Location = System::Drawing::Point(165, 149);
			this->DiffuseTextBox->Margin = System::Windows::Forms::Padding(2);
			this->DiffuseTextBox->Name = L"DiffuseTextBox";
			this->DiffuseTextBox->Size = System::Drawing::Size(196, 20);
			this->DiffuseTextBox->TabIndex = 153;
			this->DiffuseTextBox->Text = L"0.5f";
			// 
			// DiffuseLabel
			// 
			this->DiffuseLabel->AutoSize = true;
			this->DiffuseLabel->Location = System::Drawing::Point(19, 151);
			this->DiffuseLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->DiffuseLabel->Name = L"DiffuseLabel";
			this->DiffuseLabel->Size = System::Drawing::Size(43, 13);
			this->DiffuseLabel->TabIndex = 176;
			this->DiffuseLabel->Text = L"Diffuse:";
			// 
			// AmbientTextBox
			// 
			this->AmbientTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->AmbientTextBox->Location = System::Drawing::Point(166, 125);
			this->AmbientTextBox->Margin = System::Windows::Forms::Padding(2);
			this->AmbientTextBox->Name = L"AmbientTextBox";
			this->AmbientTextBox->Size = System::Drawing::Size(196, 20);
			this->AmbientTextBox->TabIndex = 152;
			this->AmbientTextBox->Text = L"0.5f";
			// 
			// AmbientLabel
			// 
			this->AmbientLabel->AutoSize = true;
			this->AmbientLabel->Location = System::Drawing::Point(20, 127);
			this->AmbientLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->AmbientLabel->Name = L"AmbientLabel";
			this->AmbientLabel->Size = System::Drawing::Size(48, 13);
			this->AmbientLabel->TabIndex = 175;
			this->AmbientLabel->Text = L"Ambient:";
			// 
			// SunzTextBox
			// 
			this->SunzTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->SunzTextBox->Location = System::Drawing::Point(165, 101);
			this->SunzTextBox->Margin = System::Windows::Forms::Padding(2);
			this->SunzTextBox->Name = L"SunzTextBox";
			this->SunzTextBox->Size = System::Drawing::Size(196, 20);
			this->SunzTextBox->TabIndex = 151;
			this->SunzTextBox->Text = L"0.47f";
			// 
			// SunzLabel
			// 
			this->SunzLabel->AutoSize = true;
			this->SunzLabel->Location = System::Drawing::Point(19, 104);
			this->SunzLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->SunzLabel->Name = L"SunzLabel";
			this->SunzLabel->Size = System::Drawing::Size(34, 13);
			this->SunzLabel->TabIndex = 174;
			this->SunzLabel->Text = L"Sunz:";
			// 
			// SunyTextBox
			// 
			this->SunyTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->SunyTextBox->Location = System::Drawing::Point(165, 78);
			this->SunyTextBox->Margin = System::Windows::Forms::Padding(2);
			this->SunyTextBox->Name = L"SunyTextBox";
			this->SunyTextBox->Size = System::Drawing::Size(196, 20);
			this->SunyTextBox->TabIndex = 150;
			this->SunyTextBox->Text = L"0.88f";
			// 
			// SunyLabel
			// 
			this->SunyLabel->AutoSize = true;
			this->SunyLabel->Location = System::Drawing::Point(19, 80);
			this->SunyLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->SunyLabel->Name = L"SunyLabel";
			this->SunyLabel->Size = System::Drawing::Size(34, 13);
			this->SunyLabel->TabIndex = 173;
			this->SunyLabel->Text = L"Suny:";
			// 
			// ShadowMapCheckBox
			// 
			this->ShadowMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->ShadowMapCheckBox->Location = System::Drawing::Point(18, 31);
			this->ShadowMapCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->ShadowMapCheckBox->Name = L"ShadowMapCheckBox";
			this->ShadowMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->ShadowMapCheckBox->TabIndex = 148;
			this->ShadowMapCheckBox->Text = L"ShadowMap:";
			this->ShadowMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// LightMapCheckBox
			// 
			this->LightMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->LightMapCheckBox->Location = System::Drawing::Point(18, 7);
			this->LightMapCheckBox->Margin = System::Windows::Forms::Padding(2);
			this->LightMapCheckBox->Name = L"LightMapCheckBox";
			this->LightMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->LightMapCheckBox->TabIndex = 147;
			this->LightMapCheckBox->Text = L"LightMap:";
			this->LightMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// SunxTextBox
			// 
			this->SunxTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->SunxTextBox->Location = System::Drawing::Point(165, 54);
			this->SunxTextBox->Margin = System::Windows::Forms::Padding(2);
			this->SunxTextBox->Name = L"SunxTextBox";
			this->SunxTextBox->Size = System::Drawing::Size(196, 20);
			this->SunxTextBox->TabIndex = 149;
			this->SunxTextBox->Text = L"0.0f";
			// 
			// SunxLabel
			// 
			this->SunxLabel->AutoSize = true;
			this->SunxLabel->Location = System::Drawing::Point(19, 57);
			this->SunxLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->SunxLabel->Name = L"SunxLabel";
			this->SunxLabel->Size = System::Drawing::Size(34, 13);
			this->SunxLabel->TabIndex = 172;
			this->SunxLabel->Text = L"Sunx:";
			// 
			// CreateButton
			// 
			this->CreateButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->CreateButton->Location = System::Drawing::Point(13, 314);
			this->CreateButton->Name = L"CreateButton";
			this->CreateButton->Size = System::Drawing::Size(231, 23);
			this->CreateButton->TabIndex = 6;
			this->CreateButton->Text = L"Create Gen File";
			this->CreateButton->UseVisualStyleBackColor = true;
			this->CreateButton->Click += gcnew System::EventHandler(this, &GenWindow::CreateButton_Click);
			// 
			// EditButton
			// 
			this->EditButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->EditButton->Location = System::Drawing::Point(322, 314);
			this->EditButton->Name = L"EditButton";
			this->EditButton->Size = System::Drawing::Size(231, 23);
			this->EditButton->TabIndex = 7;
			this->EditButton->Text = L"Edit Gen File";
			this->EditButton->UseVisualStyleBackColor = true;
			this->EditButton->Click += gcnew System::EventHandler(this, &GenWindow::EditButton_Click);
			// 
			// CloseWindowButton
			// 
			this->CloseWindowButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->CloseWindowButton->Location = System::Drawing::Point(630, 314);
			this->CloseWindowButton->Name = L"CloseWindowButton";
			this->CloseWindowButton->Size = System::Drawing::Size(231, 23);
			this->CloseWindowButton->TabIndex = 8;
			this->CloseWindowButton->Text = L"Close Window";
			this->CloseWindowButton->UseVisualStyleBackColor = true;
			this->CloseWindowButton->Click += gcnew System::EventHandler(this, &GenWindow::CloseWindowButton_Click);
			// 
			// StatusTextBox
			// 
			this->StatusTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->StatusTextBox->Location = System::Drawing::Point(-4, 343);
			this->StatusTextBox->Name = L"StatusTextBox";
			this->StatusTextBox->ReadOnly = true;
			this->StatusTextBox->Size = System::Drawing::Size(882, 20);
			this->StatusTextBox->TabIndex = 9;
			// 
			// GenWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(873, 363);
			this->ControlBox = false;
			this->Controls->Add(this->StatusTextBox);
			this->Controls->Add(this->CloseWindowButton);
			this->Controls->Add(this->EditButton);
			this->Controls->Add(this->CreateButton);
			this->Controls->Add(this->GenConfigGroupBox);
			this->Controls->Add(this->OutputGroupBox);
			this->Controls->Add(this->ImageInputGroupBox);
			this->Controls->Add(this->InfoGroupBox);
			this->Name = L"GenWindow";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"Gen File Creation";
			this->InfoGroupBox->ResumeLayout(false);
			this->InfoGroupBox->PerformLayout();
			this->ImageInputGroupBox->ResumeLayout(false);
			this->ImageInputGroupBox->PerformLayout();
			this->OutputGroupBox->ResumeLayout(false);
			this->OutputGroupBox->PerformLayout();
			this->GenConfigGroupBox->ResumeLayout(false);
			this->GenerationTabControl->ResumeLayout(false);
			this->GGeneralTabPage->ResumeLayout(false);
			this->GGeneralTabPage->PerformLayout();
			this->GPagingTabPage->ResumeLayout(false);
			this->GPagingTabPage->PerformLayout();
			this->GHeightMapTabPage->ResumeLayout(false);
			this->GHeightMapTabPage->PerformLayout();
			this->GColorMapTabPage->ResumeLayout(false);
			this->GColorMapTabPage->PerformLayout();
			this->GNormalsTabPage->ResumeLayout(false);
			this->GSplattingTabPage->ResumeLayout(false);
			this->GSplattingTabPage->PerformLayout();
			this->GLightingTabPage->ResumeLayout(false);
			this->GLightingTabPage->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void CloseWindowButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			Hide();
		}
		System::Void HeightMapLoadButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			// backup of current working directory, which is restored
			System::String^ backupCurrentDir = Environment::CurrentDirectory;

			// find files of supported type: .png, .raw
			OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
			openFileDialog1->InitialDirectory = mHeightMapFolder;
			openFileDialog1->Filter = "Greyscale PNG files (*.png)|*.png|Greyscale RAW files (*.raw)|*.raw";
			openFileDialog1->Title = "Load HeightMap";
			openFileDialog1->ShowDialog();    
			openFileDialog1->RestoreDirectory = true;

			if(openFileDialog1->FileName != "")
			{
				// I'm not sure why, but opening the file changes the current working directory!
				// This caused 2 hours of pain! The Current Directory MUST be restored for OGRE
				// to use its resources properly!
				Environment::CurrentDirectory = backupCurrentDir;

				// Autofilled values:
				/*
				HeightMapFileName - both CFGs
				HeightMapExtension - both CFGs
				HeightMapExportExtension - .gen.cfg
				*/
				System::String^ HeightMapFileFullName = openFileDialog1->FileName->Substring(openFileDialog1->FileName->LastIndexOf("\\")+1);
				System::String^ HeightMapFileName = HeightMapFileFullName->Substring(0,HeightMapFileFullName->IndexOf('.'));
				System::String^ HeightMapExtension = HeightMapFileFullName->Substring(HeightMapFileFullName->IndexOf('.')+1);

				GHeightMapFileNameTextBox->Text = HeightMapFileName;

				GHeightMapExtensionTextBox->Text = HeightMapExtension;
				HeightMapExportExtensionTextBox->Text = HeightMapExtension;
			}
			else Environment::CurrentDirectory = backupCurrentDir;
		}
		System::Void ColorMapLoadButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			// backup of current working directory, which is restored
			System::String^ backupCurrentDir = Environment::CurrentDirectory;

			// find files of supported type: .png, .raw
			OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
			openFileDialog1->InitialDirectory = mColorMapFolder;
			openFileDialog1->Filter = "Image Files(*.BMP;*.JPG;*.PNG)|*.BMP;*.JPG;*.PNG|All files (*.*)|*.*"; 
			openFileDialog1->Title = "Load Image";
			openFileDialog1->ShowDialog();
			openFileDialog1->RestoreDirectory = true;

			if(openFileDialog1->FileName != "")
			{
				// I'm not sure why, but opening the file changes the current working directory!
				// This caused 2 hours of pain! The Current Directory MUST be restored for OGRE
				// to use its resources properly!
				Environment::CurrentDirectory = backupCurrentDir;

				// Autofilled values:
				/*
				ImageFileName - both CFGs
				ImageExtension - both CFGs
				*/
				System::String^ ImageFileFullName = openFileDialog1->FileName->Substring(openFileDialog1->FileName->LastIndexOf("\\")+1);
				System::String^ ImageFileName = ImageFileFullName->Substring(0,ImageFileFullName->IndexOf('.'));
				System::String^ ImageExtension = ImageFileFullName->Substring(ImageFileFullName->IndexOf('.')+1);

				GColorMapFileNameTextBox->Text = ImageFileName;

				GColorMapExtensionTextBox->Text = ImageExtension;
				ColorMapExportExtensionTextBox->Text = ImageExtension;
			}
			else Environment::CurrentDirectory = backupCurrentDir;
		}
		System::Void CreateButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if( GTerrainNameTextBox->Text == "" ) return;

			// Duplicating layout of template.default.gen.cfg

			System::IO::FileStream^ fs = System::IO::File::Create( 
				mOutputFolder +
				GTerrainNameTextBox->Text + 
				".gen.cfg"); 
			System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(fs);

			sw->WriteLine("####### Generated by Terrain Generator #######");
			sw->WriteLine("####### FileName: " + GTerrainNameTextBox->Text + ".gen.cfg ######");
			sw->WriteLine("####### GEN FILE: This file tells mapsplitter how to process the heightmap and colormap ######");
			sw->WriteLine("");

			sw->WriteLine("TerrainName=" + GTerrainNameTextBox->Text);
			sw->WriteLine("");

			sw->WriteLine(createComment("General Options"));
			sw->WriteLine(createAssignment(GGroupNameLabel,GGroupNameTextBox));
			sw->WriteLine(createAssignment(GHeightMapFileNameLabel,GHeightMapFileNameTextBox));
			sw->WriteLine(createAssignment(GHeightMapExtensionLabel,GHeightMapExtensionTextBox));
			sw->WriteLine(createAssignment(HeightMapExportExtensionLabel,HeightMapExportExtensionTextBox));
			sw->WriteLine(createAssignment(GColorMapFileNameLabel,GColorMapFileNameTextBox));
			sw->WriteLine(createAssignment(GColorMapExtensionLabel,GColorMapExtensionTextBox));
			sw->WriteLine(createAssignment(ColorMapExportExtensionLabel,ColorMapExportExtensionTextBox));
			sw->WriteLine(createAssignment(PagedCheckBox));
			sw->WriteLine("OutDirectory=" + mOutputFolder + GTerrainNameTextBox->Text);
			sw->WriteLine(createAssignment(GTerrainScaleXLabel,GTerrainScaleXTextBox));
			sw->WriteLine(createAssignment(GTerrainScaleYLabel,GTerrainScaleYTextBox));
			sw->WriteLine(createAssignment(GTerrainScaleZLabel,GTerrainScaleZTextBox));
			sw->WriteLine("");

			sw->WriteLine(createComment("Paging Related Options (no effect if Paged=no)"));
			sw->WriteLine(createAssignment(GPageSizeLabel,GPageSizeTextBox));
			sw->WriteLine(createAssignment(GTileSizeLabel,GTileSizeTextBox));
			sw->WriteLine(createAssignment(GData2DFormatLabel,GData2DFormatComboBox));
			sw->WriteLine(createAssignment(GMaxValueLabel,GMaxValueTextBox));
			sw->WriteLine(createAssignment(GMinValueLabel,GMinValueTextBox));
			sw->WriteLine("");

			sw->WriteLine(createComment("Color Map Options"));
			sw->WriteLine(createAssignment(GColorMapStretchFactorLabel,GColorMapStretchFactorTextBox));
			sw->WriteLine(createAssignment(ColorMapSplitCheckBox));
			sw->WriteLine(createAssignment(LitColorMapSplitCheckBox));
			sw->WriteLine("");

			sw->WriteLine(createComment("Height Map Options"));
			sw->WriteLine(createAssignment(HeightMapCheckBox));
			sw->WriteLine(createAssignment(InfiniteMapCheckBox));
			sw->WriteLine(createAssignment(HeightMapBlurFactorLabel,HeightMapBlurFactorTextBox));
			sw->WriteLine(createAssignment(EqualizeCheckBox));
			sw->WriteLine(createAssignment(MiniMapCheckBox));
			sw->WriteLine(createAssignment(MiniMapWidthLabel,MiniMapWidthTextBox));
			sw->WriteLine(createAssignment(MiniMapHeightLabel,MiniMapHeightTextBox));
			sw->WriteLine("");

			sw->WriteLine(createComment("Normals Options"));
			sw->WriteLine(createAssignment(NormalMapCheckBox));
			sw->WriteLine(createAssignment(HeightNormalMapCheckBox));
			sw->WriteLine(createAssignment(ColorMapGenerateCheckBox));
			sw->WriteLine(createAssignment(LitColorMapGenerateCheckBox));
			sw->WriteLine("");

			sw->WriteLine(createComment("Splatting Options"));
			sw->WriteLine(createAssignment(NumMatHeightSplatLabel,NumMatHeightSplatTextBox));
			writeRichTextBoxContents(sw,GSetMaterialHeightRichTextBox);
			writeRichTextBoxContents(sw,GSetMaterialColorRichTextBox);
			writeRichTextBoxContents(sw,GSetSplatFileNamesRichTextBox);
			sw->WriteLine(createAssignment(AvgColorsExistsCheckBox));
			sw->WriteLine(createAssignment(BaseMapCheckBox));
			sw->WriteLine(createAssignment(LitBaseMapCheckBox));
			sw->WriteLine("");

			sw->WriteLine(createComment("Maps used for Splatting"));
			sw->WriteLine(createAssignment(CoverageMapCheckBox));
			sw->WriteLine(createAssignment(AlphaMapsCheckBox));
			sw->WriteLine(createAssignment(AlphaSplatRGBAMapsCheckBox));
			sw->WriteLine(createAssignment(AlphaSplatLightMapsCheckBox));
			sw->WriteLine(createAssignment(RGBMapsCheckBox));
			sw->WriteLine("");

			sw->WriteLine(createComment("Lighting Options"));
			sw->WriteLine(createAssignment(HorizonMapCheckBox));
			sw->WriteLine(createAssignment(ElevationMapCheckBox));
			sw->WriteLine(createAssignment(ZHorizonCheckBox));
			sw->WriteLine("");

			sw->WriteLine(createComment("Visibility Options"));
			sw->WriteLine(createAssignment(PVSMapCheckBox));
			sw->WriteLine("");

			sw->Close();
			fs->Close();
		}
		System::Void EditButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if( !File::Exists(mOutputFolder + GTerrainNameTextBox->Text + ".gen.cfg") ) return;

			Process^ notePad = gcnew Process();

			notePad->StartInfo->FileName = "notepad.exe";
			notePad->StartInfo->Arguments = mOutputFolder + GTerrainNameTextBox->Text + ".gen.cfg";

			notePad->Start();
		}
};
}
