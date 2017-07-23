#pragma once

#define OGRE_DEBUG_MEMORY_MANAGER 0

#include "MapUtil.h"
#include "Marshalling.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Data;
using namespace System::Diagnostics;
using namespace System::Drawing;
using namespace System::Windows::Forms;


namespace TerrainGenerator {

    /// <summary>
    /// Summary for BaseForm
    ///
    /// WARNING: If you change the name of this class, you will need to change the
    ///          'Resource File Name' property for the managed resource compiler tool
    ///          associated with all .resx files this class depends on.  Otherwise,
    ///          the designers will not be able to interact properly with localized
    ///          resources associated with this form.
    /// </summary>
    public ref class BaseForm : public System::Windows::Forms::Form
    {
    public:
        BaseForm(void);

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~BaseForm();

    protected: 
		System::Void	createAndAddFolder( System::String^ FolderPath );
        System::Void	createGenFile();
        System::Void	createRunTimeFile();
        System::Void	createMapToolFile();
        // populate MapToolRichTextBox with maptool.cfg's content
        System::Void	populateMapToolData();
        System::String^ createAssignment( System::Windows::Forms::Label^ l, System::Windows::Forms::TextBox^ t );
        System::String^ createAssignment( System::Windows::Forms::Label^ l, System::Windows::Forms::ComboBox^ c );
        System::String^ createAssignment( System::Windows::Forms::CheckBox^ c );
        System::String^	createComment( System::String^ text );
        System::Void	writeRichTextBoxContents( System::IO::StreamWriter^ sw, System::Windows::Forms::RichTextBox^ rtb );
        System::String^ evaluateCheckBox( System::Windows::Forms::CheckBox^ cb );
        // Any checking of particular inputs should be done here, to prevent the file
        // from being generated incorrectly
        bool			genFileInputVerificationFailed();
        // Any checking of particular inputs should be done here, to prevent the file
        // from being generated incorrectly
        bool			runtimeFileInputVerificationFailed();
        System::Void	setGenDefaults();
        System::String^ setString (const Ogre::String &ValuetoGet,  Ogre::ConfigFile &conf );
        System::String^ setFolderPathString (const Ogre::String &ValuetoGet,  Ogre::ConfigFile &conf);
        // Reads DeafultSettings.cfg and sets options such as where to look for
        // heightmaps, colormaps, and where to output generated files
        void	setAppDefaults();

    protected:
        Ogre::MapUtil *mMapUtil;

        ToolTip^ HelpToolTip;
        // App settings set when parsing DefaultSettings.cfg file
        System::String^	HeightMapFolder;
        System::String^	ColorMapFolder;
        System::String^	OutputFolder;

    private: System::Windows::Forms::Button^  GEditCFGButton;
    private: System::Windows::Forms::TabControl^  MainTabControl;
    private: System::Windows::Forms::TabPage^  GenerationTabPage;
    private: System::Windows::Forms::TabControl^  GenerationTabControl;
    private: System::Windows::Forms::TabPage^  GGeneralTabPage;
    private: System::Windows::Forms::TabPage^  GPagingTabPage;
    private: System::Windows::Forms::TabPage^  MapSplitterTabPage;
    private: System::Windows::Forms::TabPage^  RunTimeTabPage;
    private: System::Windows::Forms::Button^  ColorMapHelp;
    private: System::Windows::Forms::Button^  HeightMapHelp;
    private: System::Windows::Forms::Button^  ImageMapLoadButton;
    private: System::Windows::Forms::Label^  ColorMapLabel;
    private: System::Windows::Forms::Button^  HeightMapLoadButton;
    private: System::Windows::Forms::Label^  HeightMapLabel;
    private: System::Windows::Forms::Label^  GenCFGLabel;
    private: System::Windows::Forms::Button^  GSetDefaultsButton;
    private: System::Windows::Forms::TextBox^  GTerrainNameTextBox;
    private: System::Windows::Forms::Label^  TerrainNameGLabel;
    private: System::Windows::Forms::TextBox^  GHeightMapExtensionTextBox;
    private: System::Windows::Forms::CheckBox^  PagedCheckBox;
    private: System::Windows::Forms::Button^  PagedHelp;
    private: System::Windows::Forms::TextBox^  OutDirectoryTextBox;
    private: System::Windows::Forms::Label^  OutDirectoryLabel;
    private: System::Windows::Forms::Button^  OutDirectoryHelp;
    private: System::Windows::Forms::TextBox^  HeightMapExportExtensionTextBox;
    private: System::Windows::Forms::Label^  HeightMapExportExtensionLabel;
    private: System::Windows::Forms::Button^  HeightMapExportExtensionHelp;
    private: System::Windows::Forms::Label^  GHeightMapExtensionLabel;
    private: System::Windows::Forms::Button^  HeightMapExtensionHelp;
    private: System::Windows::Forms::TextBox^  GHeightMapFileNameTextBox;
    private: System::Windows::Forms::Button^  HeightMapFileNameHelp;
    private: System::Windows::Forms::Label^  GHeightMapFileNameLabel;
    private: System::Windows::Forms::Button^  GroupHelp;
    private: System::Windows::Forms::TextBox^  GGroupNameTextBox;
    private: System::Windows::Forms::Label^  GGroupNameLabel;
    private: System::Windows::Forms::TabPage^  GColorMapTabPage;
    private: System::Windows::Forms::TabPage^  GHeightMapTabPage;
    private: System::Windows::Forms::TabPage^  GNormalsTabPage;
    private: System::Windows::Forms::TabPage^  GSplattingTabPage;
    private: System::Windows::Forms::TabPage^  GLightingTabPage;
    private: System::Windows::Forms::TextBox^  GTileSizeTextBox;
    private: System::Windows::Forms::Label^  GTileSizeLabel;
    private: System::Windows::Forms::Button^  TileSizeHelp;
    private: System::Windows::Forms::TextBox^  GMinValueTextBox;
    private: System::Windows::Forms::Label^  GMinValueLabel;
    private: System::Windows::Forms::Button^  MinValueHelp;
    private: System::Windows::Forms::TextBox^  GMaxValueTextBox;
    private: System::Windows::Forms::Label^  GMaxValueLabel;
    private: System::Windows::Forms::Button^  MaxValueHelp;
    private: System::Windows::Forms::ComboBox^  GData2DFormatComboBox;
    private: System::Windows::Forms::Label^  GData2DFormatLabel;
    private: System::Windows::Forms::Button^  Data2DFormatHelp;
    private: System::Windows::Forms::TextBox^  GPageSizeTextBox;
    private: System::Windows::Forms::Label^  GPageSizeLabel;
    private: System::Windows::Forms::Button^  PageSizeHelp;
    private: System::Windows::Forms::CheckBox^  LitColorMapSplitCheckBox;
    private: System::Windows::Forms::Button^  LitColorMapSplitHelp;
    private: System::Windows::Forms::CheckBox^  ColorMapSplitCheckBox;
    private: System::Windows::Forms::Button^  ColorMapSplitHelp;
    private: System::Windows::Forms::TextBox^  MiniMapHeightTextBox;
    private: System::Windows::Forms::Label^  MiniMapHeightLabel;
    private: System::Windows::Forms::Button^  MiniMapHeightHelp;
    private: System::Windows::Forms::TextBox^  MiniMapWidthTextBox;
    private: System::Windows::Forms::Label^  MiniMapWidthLabel;
    private: System::Windows::Forms::Button^  MiniMapWidthHelp;
    private: System::Windows::Forms::CheckBox^  EqualizeCheckBox;
    private: System::Windows::Forms::Button^  EqualizeHelp;
    private: System::Windows::Forms::TextBox^  HeightMapBlurFactorTextBox;
    private: System::Windows::Forms::Label^  HeightMapBlurFactorLabel;
    private: System::Windows::Forms::Button^  HeightMapBlurFactorHelp;
    private: System::Windows::Forms::CheckBox^  InfiniteMapCheckBox;
    private: System::Windows::Forms::Button^  InfiniteMapHelp;
    private: System::Windows::Forms::CheckBox^  HeightMapCheckBox;
    private: System::Windows::Forms::Button^  HeightMap_Help;
    private: System::Windows::Forms::CheckBox^  MiniMapCheckBox;
    private: System::Windows::Forms::Button^  MiniMapHelp;
    private: System::Windows::Forms::CheckBox^  HeightNormalMapCheckBox;
    private: System::Windows::Forms::Button^  HeightNormalMapHelp;
    private: System::Windows::Forms::CheckBox^  NormalMapCheckBox;
    private: System::Windows::Forms::Button^  NormalMapHelp;
    private: System::Windows::Forms::CheckBox^  LitColorMapGenerateCheckBox;
    private: System::Windows::Forms::Button^  LitColorMapGenerateHelp;
    private: System::Windows::Forms::CheckBox^  ColorMapGenerateCheckBox;
    private: System::Windows::Forms::Button^  ColorMapGenerateHelp;
    private: System::Windows::Forms::Button^  GSetSplatFileNamesHelp;
    private: System::Windows::Forms::Button^  GSetMaterialColorHelp;
    private: System::Windows::Forms::CheckBox^  RGBMapsCheckBox;
    private: System::Windows::Forms::Button^  RGBMapsHelp;
    private: System::Windows::Forms::CheckBox^  AlphaSplatLightMapsCheckBox;
    private: System::Windows::Forms::Button^  AlphaSplatLightMapsHelp;
    private: System::Windows::Forms::CheckBox^  AlphaSplatRGBAMapsCheckBox;
    private: System::Windows::Forms::Button^  AlphaSplatRGBAMapsHelp;
    private: System::Windows::Forms::CheckBox^  CoverageMapCheckBox;
    private: System::Windows::Forms::Button^  CoverageMapHelp;
    private: System::Windows::Forms::CheckBox^  LitBaseMapCheckBox;
    private: System::Windows::Forms::Button^  LitBaseMapHelp;
    private: System::Windows::Forms::CheckBox^  BaseMapCheckBox;
    private: System::Windows::Forms::Button^  BaseMapHelp;
    private: System::Windows::Forms::CheckBox^  AvgColorsExistsCheckBox;
    private: System::Windows::Forms::Button^  AvgColorsExistsHelp;
    private: System::Windows::Forms::CheckBox^  AlphaMapsCheckBox;
    private: System::Windows::Forms::Button^  AlphaMapsHelp;
    private: System::Windows::Forms::Label^  GSetSplatFileNamesLabel;
    private: System::Windows::Forms::Label^  GSetMaterialColorLabel;
    private: System::Windows::Forms::CheckBox^  PVSMapCheckBox;
    private: System::Windows::Forms::Button^  PVSMapHelp;
    private: System::Windows::Forms::Label^  VisibilityLabel;
    private: System::Windows::Forms::CheckBox^  ZHorizonCheckBox;
    private: System::Windows::Forms::Button^  ZHorizonHelp;
    private: System::Windows::Forms::CheckBox^  ElevationMapCheckBox;
    private: System::Windows::Forms::Button^  ElevationMapHelp;
    private: System::Windows::Forms::CheckBox^  HorizonMapCheckBox;
    private: System::Windows::Forms::Button^  HorizonMapHelp;
    private: System::Windows::Forms::Label^  RealTimeLightingLabel;
    private: System::Windows::Forms::TextBox^  BlurTextBox;
    private: System::Windows::Forms::Label^  BlurLabel;
    private: System::Windows::Forms::Button^  BlurHelp;
    private: System::Windows::Forms::TextBox^  DiffuseTextBox;
    private: System::Windows::Forms::Label^  DiffuseLabel;
    private: System::Windows::Forms::Button^  DiffuseHelp;
    private: System::Windows::Forms::TextBox^  AmbientTextBox;
    private: System::Windows::Forms::Label^  AmbientLabel;
    private: System::Windows::Forms::Button^  AmbientHelp;
    private: System::Windows::Forms::TextBox^  SunzTextBox;
    private: System::Windows::Forms::Label^  SunzLabel;
    private: System::Windows::Forms::Button^  SunzHelp;
    private: System::Windows::Forms::TextBox^  SunyTextBox;
    private: System::Windows::Forms::Label^  SunyLabel;
    private: System::Windows::Forms::Button^  SunyHelp;
    private: System::Windows::Forms::CheckBox^  ShadowMapCheckBox;
    private: System::Windows::Forms::Button^  ShadowMapHelp;
    private: System::Windows::Forms::CheckBox^  LightMapCheckBox;
    private: System::Windows::Forms::Button^  LightMapHelp;
    private: System::Windows::Forms::TextBox^  SunxTextBox;
    private: System::Windows::Forms::Label^  SunxLabel;
    private: System::Windows::Forms::Button^  SunxHelp;
    private: System::Windows::Forms::Label^  LightingLabel;
    private: System::Windows::Forms::TabControl^  tabControl1;
    private: System::Windows::Forms::TabPage^  RGeneralTabPage;
    private: System::Windows::Forms::TabPage^  RPagingTabPage;
    private: System::Windows::Forms::TabPage^  RPropertiesTabPage;
    private: System::Windows::Forms::Label^  RunTimeLabel;
    private: System::Windows::Forms::Button^  RSetDefaultsButton;
    private: System::Windows::Forms::TextBox^  RTerrainNameTextBox;
    private: System::Windows::Forms::Label^  TerrainNameRLabel;
    private: System::Windows::Forms::TabPage^  RLightingTabPage;
    private: System::Windows::Forms::TabPage^  RTextureTabPage;
    private: System::Windows::Forms::TabPage^  RPerformanceTabPage;
    private: System::Windows::Forms::TabPage^  RCameraTabPage;
    private: System::Windows::Forms::TextBox^  FormatTextBox;
    private: System::Windows::Forms::Label^  FormatLabel;
    private: System::Windows::Forms::ComboBox^  ResourceFormatComboBox;
    private: System::Windows::Forms::Label^  ResourceFormatLabel;
    private: System::Windows::Forms::Button^  ResourceFormatHelp;
    private: System::Windows::Forms::Button^  GroupNameRHelp;
    private: System::Windows::Forms::TextBox^  RGroupNameTextBox;
    private: System::Windows::Forms::Label^  RGroupNameLabel;
    private: System::Windows::Forms::TextBox^  RHeightMapExtensionTextBox;
    private: System::Windows::Forms::Label^  RHeightMapExtensionLabel;
    private: System::Windows::Forms::Button^  HeightMapExtensionRHelp;
    private: System::Windows::Forms::TextBox^  RHeightMapFileNameTextBox;
    private: System::Windows::Forms::Button^  HeightMapFileNameRHelp;
    private: System::Windows::Forms::Label^  RHeightMapFileNameLabel;
    private: System::Windows::Forms::TextBox^  RMinValueTextBox;
    private: System::Windows::Forms::Label^  RMinValueLabel;
    private: System::Windows::Forms::Button^  RMinValueHelp;
    private: System::Windows::Forms::TextBox^  RMaxValueTextBox;
    private: System::Windows::Forms::Label^  RMaxValueLabel;
    private: System::Windows::Forms::Button^  RMaxValueHelp;
    private: System::Windows::Forms::Label^  RData2DFormatLabel;
    private: System::Windows::Forms::Button^  RData2DFormatHelp;
    private: System::Windows::Forms::TextBox^  RPageSizeTextBox;
    private: System::Windows::Forms::TextBox^  RTileSizeTextBox;
    private: System::Windows::Forms::Label^  RTileSizeLabel;
    private: System::Windows::Forms::Button^  RTileSizeHelp;
    private: System::Windows::Forms::Label^  RPageSizeLabel;
    private: System::Windows::Forms::Button^  RPageSizeHelp;
    private: System::Windows::Forms::TextBox^  PageHeightTextBox;
    private: System::Windows::Forms::Button^  HeightHelp;
    private: System::Windows::Forms::Label^  PageHeightLabel;
    private: System::Windows::Forms::Button^  WidthHelp;
    private: System::Windows::Forms::TextBox^  PageWidthTextBox;
    private: System::Windows::Forms::Label^  PageWidthLabel;
    private: System::Windows::Forms::TextBox^  MaxPixelErrorTextBox;
    private: System::Windows::Forms::Label^  MaxPixelErrorLabel;
    private: System::Windows::Forms::Button^  MaxPixelErrorHelp;
    private: System::Windows::Forms::TextBox^  LODMorphStartTextBox;
    private: System::Windows::Forms::Label^  LODMorphStartLabel;
    private: System::Windows::Forms::CheckBox^  VertexCompressionCheckBox;
    private: System::Windows::Forms::Button^  VertexCompressionHelp;
    private: System::Windows::Forms::CheckBox^  DeformableCheckBox;
    private: System::Windows::Forms::Button^  DeformableHelp;
    private: System::Windows::Forms::Button^  LODMorphStartHelp;
    private: System::Windows::Forms::CheckBox^  VertexProgramMorphCheckBox;
    private: System::Windows::Forms::Button^  VertexProgramMorphHelp;
    private: System::Windows::Forms::TextBox^  RTerrainScaleZTextBox;
    private: System::Windows::Forms::Label^  RTerrainScaleZLabel;
    private: System::Windows::Forms::Button^  RScaleZHelp;
    private: System::Windows::Forms::TextBox^  RTerrainScaleYTextBox;
    private: System::Windows::Forms::Label^  RTerrainScaleYLabel;
    private: System::Windows::Forms::Button^  RScaleYHelp;
    private: System::Windows::Forms::TextBox^  RTerrainScaleXTextBox;
    private: System::Windows::Forms::Label^  RTerrainScaleXLabel;
    private: System::Windows::Forms::Button^  RScaleXHelp;
    private: System::Windows::Forms::CheckBox^  VertexNormalsCheckBox;
    private: System::Windows::Forms::Button^  VertexNormalsHelp;
    private: System::Windows::Forms::CheckBox^  VertexLitCheckBox;
    private: System::Windows::Forms::Button^  VertexLitHelp;
    private: System::Windows::Forms::TextBox^  RNumMatHeightSplatTextBox;
    private: System::Windows::Forms::Label^  RNumMatHeightSplatLabel;
    private: System::Windows::Forms::Button^  RNumMatHeightSplatHelp;
    private: System::Windows::Forms::CheckBox^  BaseVertexInstantColorCheckBox;
    private: System::Windows::Forms::Button^  BaseVertexInstantColorHelp;
    private: System::Windows::Forms::CheckBox^  BaseVertexShadowCheckBox;
    private: System::Windows::Forms::Button^  BaseVertexShadowHelp;
    private: System::Windows::Forms::CheckBox^  BaseVertexColorCheckBox;
    private: System::Windows::Forms::Button^  BaseVertexColorHelp;
    private: System::Windows::Forms::CheckBox^  VertexColorsCheckBox;
    private: System::Windows::Forms::Button^  VertexColorsHelp;
    private: System::Windows::Forms::CheckBox^  BigImageCheckBox;
    private: System::Windows::Forms::Button^  BigImageHelp;
    private: System::Windows::Forms::CheckBox^  CoverageVertexColorCheckBox;
    private: System::Windows::Forms::Button^  CoverageVertexColorHelp;
    private: System::Windows::Forms::TextBox^  TextureFormatTextBox;
    private: System::Windows::Forms::Label^  TextureFormatLabel;
    private: System::Windows::Forms::Button^  TextureFormatHelp;
    private: System::Windows::Forms::TextBox^  NumTextureFormatSupportedTextBox;
    private: System::Windows::Forms::Label^  NumTextureFormatSupportedLabel;
    private: System::Windows::Forms::Button^  NumTextureFormatSupportedHelp;
    private: System::Windows::Forms::TextBox^  RColorMapStretchFactorTextBox;
    private: System::Windows::Forms::Label^  RColorMapStretchFactorLabel;
    private: System::Windows::Forms::Button^  RColorMapStretchFactorHelp;
    private: System::Windows::Forms::CheckBox^  HorizonVisibilityComputingCheckBox;
    private: System::Windows::Forms::Button^  HorizonVisibilityComputingHelp;
    private: System::Windows::Forms::TextBox^  IncrementTilesTextBox;
    private: System::Windows::Forms::Label^  IncrementTilesLabel;
    private: System::Windows::Forms::Button^  IncrementTilesHelp;
    private: System::Windows::Forms::TextBox^  MaxNumRenderablesTextBox;
    private: System::Windows::Forms::TextBox^  MaxNumTilesTextBox;
    private: System::Windows::Forms::Label^  MaxNumTilesLabel;
    private: System::Windows::Forms::Button^  MaxNumTilesHelp;
    private: System::Windows::Forms::TextBox^  IncrementRenderablesTextBox;
    private: System::Windows::Forms::Label^  IncrementRenderablesLabel;
    private: System::Windows::Forms::Button^  IncrementRenderablesHelp;
    private: System::Windows::Forms::Label^  MaxNumRenderablesLabel;
    private: System::Windows::Forms::Button^  MaxNumRenderablesHelp;
    private: System::Windows::Forms::TextBox^  CameraThresholdTextBox;
    private: System::Windows::Forms::Button^  CameraThresholdHelp;
    private: System::Windows::Forms::Label^  CameraThresholdLabel;
    private: System::Windows::Forms::Button^  ChangeFactorHelp;
    private: System::Windows::Forms::TextBox^  ChangeFactorTextBox;
    private: System::Windows::Forms::Label^  ChangeFactorLabel;
    private: System::Windows::Forms::TextBox^  MaxPreloadedPagesTextBox;
    private: System::Windows::Forms::Label^  MaxPreloadedPagesLabel;
    private: System::Windows::Forms::Button^  MaxPreloadedPagesHelp;
    private: System::Windows::Forms::TextBox^  MaxRenderLevelTextBox;
    private: System::Windows::Forms::TextBox^  MaxAdjacentPagesTextBox;
    private: System::Windows::Forms::Label^  MaxAdjacentPagesLabel;
    private: System::Windows::Forms::Button^  MaxAdjacentPagesHelp;
    private: System::Windows::Forms::TextBox^  NumRenderablesLoadingTextBox;
    private: System::Windows::Forms::Label^  NumRenderablesLoadingLabel;
    private: System::Windows::Forms::Button^  NumRenderablesLoadingHelp;
    private: System::Windows::Forms::Label^  MaxRenderLevelLabel;
    private: System::Windows::Forms::Button^  MaxRenderLevelHelp;
    private: System::Windows::Forms::TextBox^  DistanceLODTextBox;
    private: System::Windows::Forms::Button^  DistanceLODHelp;
    private: System::Windows::Forms::Label^  DistanceLODLabel;
    private: System::Windows::Forms::Button^  VisibleRenderablesHelp;
    private: System::Windows::Forms::TextBox^  VisibleRenderablesTextBox;
    private: System::Windows::Forms::Label^  VisibleRenderablesLabel;
    private: System::Windows::Forms::Button^  GGenerateCFGButton;
    private: System::Windows::Forms::Button^  RunMapsplitterButton;
    private: System::Windows::Forms::TextBox^  BaselookatzTextBox;
    private: System::Windows::Forms::Label^  BaselookatzLabel;
    private: System::Windows::Forms::Button^  BaselookatzHelp;
    private: System::Windows::Forms::TextBox^  BaseCameraViewpointzTextBox;
    private: System::Windows::Forms::TextBox^  BaselookatyTextBox;
    private: System::Windows::Forms::Label^  BaselookatyLabel;
    private: System::Windows::Forms::Button^  BaselookatyHelp;
    private: System::Windows::Forms::TextBox^  BaselookatxTextBox;
    private: System::Windows::Forms::Label^  BaselookatxLabel;
    private: System::Windows::Forms::Button^  BaselookatxHelp;
    private: System::Windows::Forms::Label^  BaseCameraViewpointzLabel;
    private: System::Windows::Forms::TextBox^  BaseCameraViewpointyTextBox;
    private: System::Windows::Forms::Button^  BaseCameraViewpointyHelp;
    private: System::Windows::Forms::Label^  BaseCameraViewpointyLabel;
    private: System::Windows::Forms::Button^  BaseCameraViewpointxHelp;
    private: System::Windows::Forms::TextBox^  BaseCameraViewpointxTextBox;
    private: System::Windows::Forms::Label^  BaseCameraViewpointxLabel;
    private: System::Windows::Forms::Button^  QuitButton;
    private: System::Windows::Forms::TextBox^  NumMatHeightSplatTextBox;
    private: System::Windows::Forms::Label^  NumMatHeightSplatLabel;
    private: System::Windows::Forms::Button^  GNumMatHeightSplatHelp;
    private: System::Windows::Forms::RichTextBox^  GSetMaterialColorRichTextBox;
    private: System::Windows::Forms::RichTextBox^  GSetMaterialHeightRichTextBox;
    private: System::Windows::Forms::Label^  GSetMaterialHeightLabel;
    private: System::Windows::Forms::Button^  GSetMaterialHeightHelp;
    private: System::Windows::Forms::RichTextBox^  GSetSplatFileNamesRichTextBox;
    private: System::Windows::Forms::RichTextBox^  TextureFormatSupportedRichTextBox;
    private: System::Windows::Forms::RichTextBox^  RSetSplatFileNamesRichTextBox;
    private: System::Windows::Forms::RichTextBox^  RSetMaterialHeightRichTextBox;
    private: System::Windows::Forms::Label^  RSetMaterialHeightLabel;
    private: System::Windows::Forms::Button^  RSetMaterialHeightHelp;
    private: System::Windows::Forms::RichTextBox^  RSetMaterialColorRichTextBox;
    private: System::Windows::Forms::Label^  RSetSplatFileNamesLabel;
    private: System::Windows::Forms::Label^  RSetMaterialColorLabel;
    private: System::Windows::Forms::Button^  RSetSplatFileNamesHelp;
    private: System::Windows::Forms::Button^  RSetMaterialColorHelp;
    private: System::Windows::Forms::RichTextBox^  MapToolRichTextBox;
    private: System::Windows::Forms::TextBox^  MapSplitterStatusTextBox;
    private: System::Windows::Forms::Label^  MaptoolLabel;
    private: System::Windows::Forms::TextBox^  RColorMapTextBox;
    private: System::Windows::Forms::TextBox^  RHeightMapTextBox;
    private: System::Windows::Forms::Button^  ColorMapSourceHelp;
    private: System::Windows::Forms::Button^  HeightMapSourceHelp;
    private: System::Windows::Forms::Label^  ColorMapSourceLabel;
    private: System::Windows::Forms::Label^  HeightMapSourceLabel;
    private: System::Windows::Forms::TextBox^  RData2DFormatTextBox;
    private: System::Windows::Forms::Button^  CreateRunTimeCFGButton;
    private: System::Windows::Forms::Button^  EditRunTimeCFGButton;
    private: System::Windows::Forms::TextBox^  RColorMapFileNameTextBox;
    private: System::Windows::Forms::Label^  RColorMapFileNameLabel;
    private: System::Windows::Forms::Button^  ColorMapFileNameRHelp;
    private: System::Windows::Forms::TextBox^  RColorMapExtensionTextBox;
    private: System::Windows::Forms::Label^  RColorMapExtensionLabel;
    private: System::Windows::Forms::Button^  ColorMapExtensionRHelp;
    private: System::Windows::Forms::TextBox^  GColorMapStretchFactorTextBox;
    private: System::Windows::Forms::Label^  GColorMapStretchFactorLabel;
    private: System::Windows::Forms::Button^  ColorMapStretchFactorHelp;
    private: System::Windows::Forms::TextBox^  GColorMapExtensionTextBox;
    private: System::Windows::Forms::Label^  GColorMapExtensionLabel;
    private: System::Windows::Forms::Button^  ColorMapExtensionHelp;
    private: System::Windows::Forms::TextBox^  GColorMapFileNameTextBox;
    private: System::Windows::Forms::Label^  GColorMapFileNameLabel;
    private: System::Windows::Forms::Button^  ColorMapFileNameHelp;
    private: System::Windows::Forms::TextBox^  ColorMapExportExtensionTextBox;
    private: System::Windows::Forms::Label^  ColorMapExportExtensionLabel;
    private: System::Windows::Forms::Button^  ColorMapExportExtensionHelp;
    private: System::Windows::Forms::TextBox^  GTerrainScaleZTextBox;
    private: System::Windows::Forms::Label^  GTerrainScaleZLabel;
    private: System::Windows::Forms::Button^  ScaleZHelp;
    private: System::Windows::Forms::TextBox^  GTerrainScaleYTextBox;
    private: System::Windows::Forms::Label^  GTerrainScaleYLabel;
    private: System::Windows::Forms::Button^  ScaleYHelp;
    private: System::Windows::Forms::TextBox^  GTerrainScaleXTextBox;
    private: System::Windows::Forms::Label^  GTerrainScaleXLabel;
    private: System::Windows::Forms::Button^  ScaleXHelp;
    private: System::Windows::Forms::Button^  BaseCameraViewpointzHelp;

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
			this->GEditCFGButton = (gcnew System::Windows::Forms::Button());
			this->MainTabControl = (gcnew System::Windows::Forms::TabControl());
			this->GenerationTabPage = (gcnew System::Windows::Forms::TabPage());
			this->GGenerateCFGButton = (gcnew System::Windows::Forms::Button());
			this->ColorMapHelp = (gcnew System::Windows::Forms::Button());
			this->HeightMapHelp = (gcnew System::Windows::Forms::Button());
			this->ImageMapLoadButton = (gcnew System::Windows::Forms::Button());
			this->ColorMapLabel = (gcnew System::Windows::Forms::Label());
			this->HeightMapLoadButton = (gcnew System::Windows::Forms::Button());
			this->HeightMapLabel = (gcnew System::Windows::Forms::Label());
			this->GenCFGLabel = (gcnew System::Windows::Forms::Label());
			this->GSetDefaultsButton = (gcnew System::Windows::Forms::Button());
			this->GTerrainNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->TerrainNameGLabel = (gcnew System::Windows::Forms::Label());
			this->GenerationTabControl = (gcnew System::Windows::Forms::TabControl());
			this->GGeneralTabPage = (gcnew System::Windows::Forms::TabPage());
			this->GTerrainScaleZTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GTerrainScaleZLabel = (gcnew System::Windows::Forms::Label());
			this->ScaleZHelp = (gcnew System::Windows::Forms::Button());
			this->GTerrainScaleYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GTerrainScaleYLabel = (gcnew System::Windows::Forms::Label());
			this->ScaleYHelp = (gcnew System::Windows::Forms::Button());
			this->GTerrainScaleXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GTerrainScaleXLabel = (gcnew System::Windows::Forms::Label());
			this->ScaleXHelp = (gcnew System::Windows::Forms::Button());
			this->ColorMapExportExtensionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ColorMapExportExtensionLabel = (gcnew System::Windows::Forms::Label());
			this->ColorMapExportExtensionHelp = (gcnew System::Windows::Forms::Button());
			this->GColorMapExtensionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GColorMapExtensionLabel = (gcnew System::Windows::Forms::Label());
			this->ColorMapExtensionHelp = (gcnew System::Windows::Forms::Button());
			this->GColorMapFileNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GColorMapFileNameLabel = (gcnew System::Windows::Forms::Label());
			this->ColorMapFileNameHelp = (gcnew System::Windows::Forms::Button());
			this->GHeightMapExtensionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PagedCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->PagedHelp = (gcnew System::Windows::Forms::Button());
			this->OutDirectoryTextBox = (gcnew System::Windows::Forms::TextBox());
			this->OutDirectoryLabel = (gcnew System::Windows::Forms::Label());
			this->OutDirectoryHelp = (gcnew System::Windows::Forms::Button());
			this->HeightMapExportExtensionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->HeightMapExportExtensionLabel = (gcnew System::Windows::Forms::Label());
			this->HeightMapExportExtensionHelp = (gcnew System::Windows::Forms::Button());
			this->GHeightMapExtensionLabel = (gcnew System::Windows::Forms::Label());
			this->HeightMapExtensionHelp = (gcnew System::Windows::Forms::Button());
			this->GHeightMapFileNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->HeightMapFileNameHelp = (gcnew System::Windows::Forms::Button());
			this->GHeightMapFileNameLabel = (gcnew System::Windows::Forms::Label());
			this->GroupHelp = (gcnew System::Windows::Forms::Button());
			this->GGroupNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GGroupNameLabel = (gcnew System::Windows::Forms::Label());
			this->GPagingTabPage = (gcnew System::Windows::Forms::TabPage());
			this->GTileSizeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GTileSizeLabel = (gcnew System::Windows::Forms::Label());
			this->TileSizeHelp = (gcnew System::Windows::Forms::Button());
			this->GMinValueTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GMinValueLabel = (gcnew System::Windows::Forms::Label());
			this->MinValueHelp = (gcnew System::Windows::Forms::Button());
			this->GMaxValueTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GMaxValueLabel = (gcnew System::Windows::Forms::Label());
			this->MaxValueHelp = (gcnew System::Windows::Forms::Button());
			this->GData2DFormatComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->GData2DFormatLabel = (gcnew System::Windows::Forms::Label());
			this->Data2DFormatHelp = (gcnew System::Windows::Forms::Button());
			this->GPageSizeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GPageSizeLabel = (gcnew System::Windows::Forms::Label());
			this->PageSizeHelp = (gcnew System::Windows::Forms::Button());
			this->GHeightMapTabPage = (gcnew System::Windows::Forms::TabPage());
			this->MiniMapHeightTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MiniMapHeightLabel = (gcnew System::Windows::Forms::Label());
			this->MiniMapHeightHelp = (gcnew System::Windows::Forms::Button());
			this->MiniMapWidthTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MiniMapWidthLabel = (gcnew System::Windows::Forms::Label());
			this->MiniMapWidthHelp = (gcnew System::Windows::Forms::Button());
			this->EqualizeCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->EqualizeHelp = (gcnew System::Windows::Forms::Button());
			this->HeightMapBlurFactorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->HeightMapBlurFactorLabel = (gcnew System::Windows::Forms::Label());
			this->HeightMapBlurFactorHelp = (gcnew System::Windows::Forms::Button());
			this->InfiniteMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->InfiniteMapHelp = (gcnew System::Windows::Forms::Button());
			this->HeightMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->HeightMap_Help = (gcnew System::Windows::Forms::Button());
			this->MiniMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->MiniMapHelp = (gcnew System::Windows::Forms::Button());
			this->GColorMapTabPage = (gcnew System::Windows::Forms::TabPage());
			this->GColorMapStretchFactorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->GColorMapStretchFactorLabel = (gcnew System::Windows::Forms::Label());
			this->ColorMapStretchFactorHelp = (gcnew System::Windows::Forms::Button());
			this->LitColorMapSplitCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->LitColorMapSplitHelp = (gcnew System::Windows::Forms::Button());
			this->ColorMapSplitCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->ColorMapSplitHelp = (gcnew System::Windows::Forms::Button());
			this->GNormalsTabPage = (gcnew System::Windows::Forms::TabPage());
			this->HeightNormalMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->HeightNormalMapHelp = (gcnew System::Windows::Forms::Button());
			this->NormalMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->NormalMapHelp = (gcnew System::Windows::Forms::Button());
			this->LitColorMapGenerateCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->LitColorMapGenerateHelp = (gcnew System::Windows::Forms::Button());
			this->ColorMapGenerateCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->ColorMapGenerateHelp = (gcnew System::Windows::Forms::Button());
			this->GSplattingTabPage = (gcnew System::Windows::Forms::TabPage());
			this->GSetSplatFileNamesRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->GSetMaterialHeightRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->GSetMaterialHeightLabel = (gcnew System::Windows::Forms::Label());
			this->GSetMaterialHeightHelp = (gcnew System::Windows::Forms::Button());
			this->GSetMaterialColorRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->NumMatHeightSplatTextBox = (gcnew System::Windows::Forms::TextBox());
			this->NumMatHeightSplatLabel = (gcnew System::Windows::Forms::Label());
			this->GNumMatHeightSplatHelp = (gcnew System::Windows::Forms::Button());
			this->GSetSplatFileNamesLabel = (gcnew System::Windows::Forms::Label());
			this->GSetMaterialColorLabel = (gcnew System::Windows::Forms::Label());
			this->GSetSplatFileNamesHelp = (gcnew System::Windows::Forms::Button());
			this->GSetMaterialColorHelp = (gcnew System::Windows::Forms::Button());
			this->RGBMapsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->RGBMapsHelp = (gcnew System::Windows::Forms::Button());
			this->AlphaSplatLightMapsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->AlphaSplatLightMapsHelp = (gcnew System::Windows::Forms::Button());
			this->AlphaSplatRGBAMapsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->AlphaSplatRGBAMapsHelp = (gcnew System::Windows::Forms::Button());
			this->CoverageMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->CoverageMapHelp = (gcnew System::Windows::Forms::Button());
			this->LitBaseMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->LitBaseMapHelp = (gcnew System::Windows::Forms::Button());
			this->BaseMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->BaseMapHelp = (gcnew System::Windows::Forms::Button());
			this->AvgColorsExistsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->AvgColorsExistsHelp = (gcnew System::Windows::Forms::Button());
			this->AlphaMapsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->AlphaMapsHelp = (gcnew System::Windows::Forms::Button());
			this->GLightingTabPage = (gcnew System::Windows::Forms::TabPage());
			this->PVSMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->PVSMapHelp = (gcnew System::Windows::Forms::Button());
			this->VisibilityLabel = (gcnew System::Windows::Forms::Label());
			this->ZHorizonCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->ZHorizonHelp = (gcnew System::Windows::Forms::Button());
			this->ElevationMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->ElevationMapHelp = (gcnew System::Windows::Forms::Button());
			this->HorizonMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->HorizonMapHelp = (gcnew System::Windows::Forms::Button());
			this->RealTimeLightingLabel = (gcnew System::Windows::Forms::Label());
			this->BlurTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BlurLabel = (gcnew System::Windows::Forms::Label());
			this->BlurHelp = (gcnew System::Windows::Forms::Button());
			this->DiffuseTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DiffuseLabel = (gcnew System::Windows::Forms::Label());
			this->DiffuseHelp = (gcnew System::Windows::Forms::Button());
			this->AmbientTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AmbientLabel = (gcnew System::Windows::Forms::Label());
			this->AmbientHelp = (gcnew System::Windows::Forms::Button());
			this->SunzTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SunzLabel = (gcnew System::Windows::Forms::Label());
			this->SunzHelp = (gcnew System::Windows::Forms::Button());
			this->SunyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SunyLabel = (gcnew System::Windows::Forms::Label());
			this->SunyHelp = (gcnew System::Windows::Forms::Button());
			this->ShadowMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->ShadowMapHelp = (gcnew System::Windows::Forms::Button());
			this->LightMapCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->LightMapHelp = (gcnew System::Windows::Forms::Button());
			this->SunxTextBox = (gcnew System::Windows::Forms::TextBox());
			this->SunxLabel = (gcnew System::Windows::Forms::Label());
			this->SunxHelp = (gcnew System::Windows::Forms::Button());
			this->LightingLabel = (gcnew System::Windows::Forms::Label());
			this->MapSplitterTabPage = (gcnew System::Windows::Forms::TabPage());
			this->MapSplitterStatusTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MaptoolLabel = (gcnew System::Windows::Forms::Label());
			this->MapToolRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->RunMapsplitterButton = (gcnew System::Windows::Forms::Button());
			this->RunTimeTabPage = (gcnew System::Windows::Forms::TabPage());
			this->CreateRunTimeCFGButton = (gcnew System::Windows::Forms::Button());
			this->EditRunTimeCFGButton = (gcnew System::Windows::Forms::Button());
			this->RColorMapTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RHeightMapTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ColorMapSourceHelp = (gcnew System::Windows::Forms::Button());
			this->HeightMapSourceHelp = (gcnew System::Windows::Forms::Button());
			this->ColorMapSourceLabel = (gcnew System::Windows::Forms::Label());
			this->HeightMapSourceLabel = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->RGeneralTabPage = (gcnew System::Windows::Forms::TabPage());
			this->RColorMapFileNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RColorMapFileNameLabel = (gcnew System::Windows::Forms::Label());
			this->ColorMapFileNameRHelp = (gcnew System::Windows::Forms::Button());
			this->RColorMapExtensionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RColorMapExtensionLabel = (gcnew System::Windows::Forms::Label());
			this->ColorMapExtensionRHelp = (gcnew System::Windows::Forms::Button());
			this->RHeightMapExtensionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RHeightMapExtensionLabel = (gcnew System::Windows::Forms::Label());
			this->HeightMapExtensionRHelp = (gcnew System::Windows::Forms::Button());
			this->RHeightMapFileNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->HeightMapFileNameRHelp = (gcnew System::Windows::Forms::Button());
			this->RHeightMapFileNameLabel = (gcnew System::Windows::Forms::Label());
			this->FormatTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FormatLabel = (gcnew System::Windows::Forms::Label());
			this->ResourceFormatComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->ResourceFormatLabel = (gcnew System::Windows::Forms::Label());
			this->ResourceFormatHelp = (gcnew System::Windows::Forms::Button());
			this->GroupNameRHelp = (gcnew System::Windows::Forms::Button());
			this->RGroupNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RGroupNameLabel = (gcnew System::Windows::Forms::Label());
			this->RPagingTabPage = (gcnew System::Windows::Forms::TabPage());
			this->RData2DFormatTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RMinValueTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RMinValueLabel = (gcnew System::Windows::Forms::Label());
			this->RMinValueHelp = (gcnew System::Windows::Forms::Button());
			this->RMaxValueTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RMaxValueLabel = (gcnew System::Windows::Forms::Label());
			this->RMaxValueHelp = (gcnew System::Windows::Forms::Button());
			this->RData2DFormatLabel = (gcnew System::Windows::Forms::Label());
			this->RData2DFormatHelp = (gcnew System::Windows::Forms::Button());
			this->RPageSizeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RTileSizeTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RTileSizeLabel = (gcnew System::Windows::Forms::Label());
			this->RTileSizeHelp = (gcnew System::Windows::Forms::Button());
			this->RPageSizeLabel = (gcnew System::Windows::Forms::Label());
			this->RPageSizeHelp = (gcnew System::Windows::Forms::Button());
			this->PageHeightTextBox = (gcnew System::Windows::Forms::TextBox());
			this->HeightHelp = (gcnew System::Windows::Forms::Button());
			this->PageHeightLabel = (gcnew System::Windows::Forms::Label());
			this->WidthHelp = (gcnew System::Windows::Forms::Button());
			this->PageWidthTextBox = (gcnew System::Windows::Forms::TextBox());
			this->PageWidthLabel = (gcnew System::Windows::Forms::Label());
			this->RPropertiesTabPage = (gcnew System::Windows::Forms::TabPage());
			this->MaxPixelErrorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MaxPixelErrorLabel = (gcnew System::Windows::Forms::Label());
			this->MaxPixelErrorHelp = (gcnew System::Windows::Forms::Button());
			this->LODMorphStartTextBox = (gcnew System::Windows::Forms::TextBox());
			this->LODMorphStartLabel = (gcnew System::Windows::Forms::Label());
			this->VertexCompressionCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->VertexCompressionHelp = (gcnew System::Windows::Forms::Button());
			this->DeformableCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->DeformableHelp = (gcnew System::Windows::Forms::Button());
			this->LODMorphStartHelp = (gcnew System::Windows::Forms::Button());
			this->VertexProgramMorphCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->VertexProgramMorphHelp = (gcnew System::Windows::Forms::Button());
			this->RTerrainScaleZTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RTerrainScaleZLabel = (gcnew System::Windows::Forms::Label());
			this->RScaleZHelp = (gcnew System::Windows::Forms::Button());
			this->RTerrainScaleYTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RTerrainScaleYLabel = (gcnew System::Windows::Forms::Label());
			this->RScaleYHelp = (gcnew System::Windows::Forms::Button());
			this->RTerrainScaleXTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RTerrainScaleXLabel = (gcnew System::Windows::Forms::Label());
			this->RScaleXHelp = (gcnew System::Windows::Forms::Button());
			this->RLightingTabPage = (gcnew System::Windows::Forms::TabPage());
			this->VertexNormalsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->VertexNormalsHelp = (gcnew System::Windows::Forms::Button());
			this->VertexLitCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->VertexLitHelp = (gcnew System::Windows::Forms::Button());
			this->RTextureTabPage = (gcnew System::Windows::Forms::TabPage());
			this->RSetSplatFileNamesRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->RSetMaterialHeightRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->RSetMaterialHeightLabel = (gcnew System::Windows::Forms::Label());
			this->RSetMaterialHeightHelp = (gcnew System::Windows::Forms::Button());
			this->RSetMaterialColorRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->RSetSplatFileNamesLabel = (gcnew System::Windows::Forms::Label());
			this->RSetMaterialColorLabel = (gcnew System::Windows::Forms::Label());
			this->RSetSplatFileNamesHelp = (gcnew System::Windows::Forms::Button());
			this->RSetMaterialColorHelp = (gcnew System::Windows::Forms::Button());
			this->TextureFormatSupportedRichTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->RNumMatHeightSplatTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RNumMatHeightSplatLabel = (gcnew System::Windows::Forms::Label());
			this->RNumMatHeightSplatHelp = (gcnew System::Windows::Forms::Button());
			this->BaseVertexInstantColorCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->BaseVertexInstantColorHelp = (gcnew System::Windows::Forms::Button());
			this->BaseVertexShadowCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->BaseVertexShadowHelp = (gcnew System::Windows::Forms::Button());
			this->BaseVertexColorCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->BaseVertexColorHelp = (gcnew System::Windows::Forms::Button());
			this->VertexColorsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->VertexColorsHelp = (gcnew System::Windows::Forms::Button());
			this->BigImageCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->BigImageHelp = (gcnew System::Windows::Forms::Button());
			this->CoverageVertexColorCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->CoverageVertexColorHelp = (gcnew System::Windows::Forms::Button());
			this->TextureFormatTextBox = (gcnew System::Windows::Forms::TextBox());
			this->TextureFormatLabel = (gcnew System::Windows::Forms::Label());
			this->TextureFormatHelp = (gcnew System::Windows::Forms::Button());
			this->NumTextureFormatSupportedTextBox = (gcnew System::Windows::Forms::TextBox());
			this->NumTextureFormatSupportedLabel = (gcnew System::Windows::Forms::Label());
			this->NumTextureFormatSupportedHelp = (gcnew System::Windows::Forms::Button());
			this->RColorMapStretchFactorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RColorMapStretchFactorLabel = (gcnew System::Windows::Forms::Label());
			this->RColorMapStretchFactorHelp = (gcnew System::Windows::Forms::Button());
			this->RPerformanceTabPage = (gcnew System::Windows::Forms::TabPage());
			this->HorizonVisibilityComputingCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->HorizonVisibilityComputingHelp = (gcnew System::Windows::Forms::Button());
			this->IncrementTilesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->IncrementTilesLabel = (gcnew System::Windows::Forms::Label());
			this->IncrementTilesHelp = (gcnew System::Windows::Forms::Button());
			this->MaxNumRenderablesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MaxNumTilesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MaxNumTilesLabel = (gcnew System::Windows::Forms::Label());
			this->MaxNumTilesHelp = (gcnew System::Windows::Forms::Button());
			this->IncrementRenderablesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->IncrementRenderablesLabel = (gcnew System::Windows::Forms::Label());
			this->IncrementRenderablesHelp = (gcnew System::Windows::Forms::Button());
			this->MaxNumRenderablesLabel = (gcnew System::Windows::Forms::Label());
			this->MaxNumRenderablesHelp = (gcnew System::Windows::Forms::Button());
			this->CameraThresholdTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CameraThresholdHelp = (gcnew System::Windows::Forms::Button());
			this->CameraThresholdLabel = (gcnew System::Windows::Forms::Label());
			this->ChangeFactorHelp = (gcnew System::Windows::Forms::Button());
			this->ChangeFactorTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ChangeFactorLabel = (gcnew System::Windows::Forms::Label());
			this->MaxPreloadedPagesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MaxPreloadedPagesLabel = (gcnew System::Windows::Forms::Label());
			this->MaxPreloadedPagesHelp = (gcnew System::Windows::Forms::Button());
			this->MaxRenderLevelTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MaxAdjacentPagesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->MaxAdjacentPagesLabel = (gcnew System::Windows::Forms::Label());
			this->MaxAdjacentPagesHelp = (gcnew System::Windows::Forms::Button());
			this->NumRenderablesLoadingTextBox = (gcnew System::Windows::Forms::TextBox());
			this->NumRenderablesLoadingLabel = (gcnew System::Windows::Forms::Label());
			this->NumRenderablesLoadingHelp = (gcnew System::Windows::Forms::Button());
			this->MaxRenderLevelLabel = (gcnew System::Windows::Forms::Label());
			this->MaxRenderLevelHelp = (gcnew System::Windows::Forms::Button());
			this->DistanceLODTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DistanceLODHelp = (gcnew System::Windows::Forms::Button());
			this->DistanceLODLabel = (gcnew System::Windows::Forms::Label());
			this->VisibleRenderablesHelp = (gcnew System::Windows::Forms::Button());
			this->VisibleRenderablesTextBox = (gcnew System::Windows::Forms::TextBox());
			this->VisibleRenderablesLabel = (gcnew System::Windows::Forms::Label());
			this->RCameraTabPage = (gcnew System::Windows::Forms::TabPage());
			this->BaselookatzTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BaselookatzLabel = (gcnew System::Windows::Forms::Label());
			this->BaselookatzHelp = (gcnew System::Windows::Forms::Button());
			this->BaseCameraViewpointzTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BaselookatyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BaselookatyLabel = (gcnew System::Windows::Forms::Label());
			this->BaselookatyHelp = (gcnew System::Windows::Forms::Button());
			this->BaselookatxTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BaselookatxLabel = (gcnew System::Windows::Forms::Label());
			this->BaselookatxHelp = (gcnew System::Windows::Forms::Button());
			this->BaseCameraViewpointzLabel = (gcnew System::Windows::Forms::Label());
			this->BaseCameraViewpointzHelp = (gcnew System::Windows::Forms::Button());
			this->BaseCameraViewpointyTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BaseCameraViewpointyHelp = (gcnew System::Windows::Forms::Button());
			this->BaseCameraViewpointyLabel = (gcnew System::Windows::Forms::Label());
			this->BaseCameraViewpointxHelp = (gcnew System::Windows::Forms::Button());
			this->BaseCameraViewpointxTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BaseCameraViewpointxLabel = (gcnew System::Windows::Forms::Label());
			this->RunTimeLabel = (gcnew System::Windows::Forms::Label());
			this->RSetDefaultsButton = (gcnew System::Windows::Forms::Button());
			this->RTerrainNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->TerrainNameRLabel = (gcnew System::Windows::Forms::Label());
			this->QuitButton = (gcnew System::Windows::Forms::Button());
			this->MainTabControl->SuspendLayout();
			this->GenerationTabPage->SuspendLayout();
			this->GenerationTabControl->SuspendLayout();
			this->GGeneralTabPage->SuspendLayout();
			this->GPagingTabPage->SuspendLayout();
			this->GHeightMapTabPage->SuspendLayout();
			this->GColorMapTabPage->SuspendLayout();
			this->GNormalsTabPage->SuspendLayout();
			this->GSplattingTabPage->SuspendLayout();
			this->GLightingTabPage->SuspendLayout();
			this->MapSplitterTabPage->SuspendLayout();
			this->RunTimeTabPage->SuspendLayout();
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
			// GEditCFGButton
			// 
			this->GEditCFGButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GEditCFGButton->Enabled = false;
			this->GEditCFGButton->Location = System::Drawing::Point(4, 696);
			this->GEditCFGButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GEditCFGButton->Name = L"GEditCFGButton";
			this->GEditCFGButton->Size = System::Drawing::Size(357, 19);
			this->GEditCFGButton->TabIndex = 6;
			this->GEditCFGButton->Text = L"Edit Generation CFG File";
			this->GEditCFGButton->UseVisualStyleBackColor = true;
			this->GEditCFGButton->Click += gcnew System::EventHandler(this, &BaseForm::GEditCFGButton_Click);
			// 
			// MainTabControl
			// 
			this->MainTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->MainTabControl->Controls->Add(this->GenerationTabPage);
			this->MainTabControl->Controls->Add(this->MapSplitterTabPage);
			this->MainTabControl->Controls->Add(this->RunTimeTabPage);
			this->MainTabControl->Location = System::Drawing::Point(9, 10);
			this->MainTabControl->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MainTabControl->Name = L"MainTabControl";
			this->MainTabControl->SelectedIndex = 0;
			this->MainTabControl->Size = System::Drawing::Size(375, 743);
			this->MainTabControl->TabIndex = 8;
			// 
			// GenerationTabPage
			// 
			this->GenerationTabPage->Controls->Add(this->GGenerateCFGButton);
			this->GenerationTabPage->Controls->Add(this->GEditCFGButton);
			this->GenerationTabPage->Controls->Add(this->ColorMapHelp);
			this->GenerationTabPage->Controls->Add(this->HeightMapHelp);
			this->GenerationTabPage->Controls->Add(this->ImageMapLoadButton);
			this->GenerationTabPage->Controls->Add(this->ColorMapLabel);
			this->GenerationTabPage->Controls->Add(this->HeightMapLoadButton);
			this->GenerationTabPage->Controls->Add(this->HeightMapLabel);
			this->GenerationTabPage->Controls->Add(this->GenCFGLabel);
			this->GenerationTabPage->Controls->Add(this->GSetDefaultsButton);
			this->GenerationTabPage->Controls->Add(this->GTerrainNameTextBox);
			this->GenerationTabPage->Controls->Add(this->TerrainNameGLabel);
			this->GenerationTabPage->Controls->Add(this->GenerationTabControl);
			this->GenerationTabPage->Location = System::Drawing::Point(4, 22);
			this->GenerationTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GenerationTabPage->Name = L"GenerationTabPage";
			this->GenerationTabPage->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GenerationTabPage->Size = System::Drawing::Size(367, 717);
			this->GenerationTabPage->TabIndex = 0;
			this->GenerationTabPage->Text = L"Step 1: Terrain Generation";
			this->GenerationTabPage->UseVisualStyleBackColor = true;
			// 
			// GGenerateCFGButton
			// 
			this->GGenerateCFGButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GGenerateCFGButton->Location = System::Drawing::Point(4, 673);
			this->GGenerateCFGButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GGenerateCFGButton->Name = L"GGenerateCFGButton";
			this->GGenerateCFGButton->Size = System::Drawing::Size(357, 19);
			this->GGenerateCFGButton->TabIndex = 164;
			this->GGenerateCFGButton->Text = L"Create Terrain Generation CFG File";
			this->GGenerateCFGButton->UseVisualStyleBackColor = true;
			this->GGenerateCFGButton->Click += gcnew System::EventHandler(this, &BaseForm::GGenerateCFGButton_Click);
			// 
			// ColorMapHelp
			// 
			this->ColorMapHelp->Location = System::Drawing::Point(8, 69);
			this->ColorMapHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ColorMapHelp->Name = L"ColorMapHelp";
			this->ColorMapHelp->Size = System::Drawing::Size(17, 19);
			this->ColorMapHelp->TabIndex = 163;
			this->ColorMapHelp->Text = L"\?";
			this->ColorMapHelp->UseVisualStyleBackColor = true;
			// 
			// HeightMapHelp
			// 
			this->HeightMapHelp->Location = System::Drawing::Point(8, 46);
			this->HeightMapHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HeightMapHelp->Name = L"HeightMapHelp";
			this->HeightMapHelp->Size = System::Drawing::Size(17, 19);
			this->HeightMapHelp->TabIndex = 162;
			this->HeightMapHelp->Text = L"\?";
			this->HeightMapHelp->UseVisualStyleBackColor = true;
			this->HeightMapHelp->Click += gcnew System::EventHandler(this, &BaseForm::HeightMapHelp_Click);
			// 
			// ImageMapLoadButton
			// 
			this->ImageMapLoadButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->ImageMapLoadButton->Location = System::Drawing::Point(179, 69);
			this->ImageMapLoadButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ImageMapLoadButton->Name = L"ImageMapLoadButton";
			this->ImageMapLoadButton->Size = System::Drawing::Size(182, 19);
			this->ImageMapLoadButton->TabIndex = 159;
			this->ImageMapLoadButton->Text = L"Load";
			this->ImageMapLoadButton->UseVisualStyleBackColor = true;
			this->ImageMapLoadButton->Click += gcnew System::EventHandler(this, &BaseForm::ImageMapLoadButton_Click);
			// 
			// ColorMapLabel
			// 
			this->ColorMapLabel->AutoSize = true;
			this->ColorMapLabel->Location = System::Drawing::Point(29, 72);
			this->ColorMapLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ColorMapLabel->Name = L"ColorMapLabel";
			this->ColorMapLabel->Size = System::Drawing::Size(55, 13);
			this->ColorMapLabel->TabIndex = 161;
			this->ColorMapLabel->Text = L"ColorMap:";
			// 
			// HeightMapLoadButton
			// 
			this->HeightMapLoadButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->HeightMapLoadButton->Location = System::Drawing::Point(179, 46);
			this->HeightMapLoadButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HeightMapLoadButton->Name = L"HeightMapLoadButton";
			this->HeightMapLoadButton->Size = System::Drawing::Size(182, 19);
			this->HeightMapLoadButton->TabIndex = 158;
			this->HeightMapLoadButton->Text = L"Load";
			this->HeightMapLoadButton->UseVisualStyleBackColor = true;
			this->HeightMapLoadButton->Click += gcnew System::EventHandler(this, &BaseForm::HeightMapLoadButton_Click);
			// 
			// HeightMapLabel
			// 
			this->HeightMapLabel->AutoSize = true;
			this->HeightMapLabel->Location = System::Drawing::Point(29, 48);
			this->HeightMapLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->HeightMapLabel->Name = L"HeightMapLabel";
			this->HeightMapLabel->Size = System::Drawing::Size(62, 13);
			this->HeightMapLabel->TabIndex = 160;
			this->HeightMapLabel->Text = L"HeightMap:";
			// 
			// GenCFGLabel
			// 
			this->GenCFGLabel->AutoSize = true;
			this->GenCFGLabel->Location = System::Drawing::Point(243, 20);
			this->GenCFGLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GenCFGLabel->Name = L"GenCFGLabel";
			this->GenCFGLabel->Size = System::Drawing::Size(46, 13);
			this->GenCFGLabel->TabIndex = 157;
			this->GenCFGLabel->Text = L".gen.cfg";
			// 
			// GSetDefaultsButton
			// 
			this->GSetDefaultsButton->Location = System::Drawing::Point(292, 17);
			this->GSetDefaultsButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GSetDefaultsButton->Name = L"GSetDefaultsButton";
			this->GSetDefaultsButton->Size = System::Drawing::Size(70, 19);
			this->GSetDefaultsButton->TabIndex = 156;
			this->GSetDefaultsButton->Text = L"Set Defaults";
			this->GSetDefaultsButton->UseVisualStyleBackColor = true;
			this->GSetDefaultsButton->Click += gcnew System::EventHandler(this, &BaseForm::GSetDefaultsButton_Click);
			// 
			// GTerrainNameTextBox
			// 
			this->GTerrainNameTextBox->Location = System::Drawing::Point(84, 17);
			this->GTerrainNameTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GTerrainNameTextBox->Name = L"GTerrainNameTextBox";
			this->GTerrainNameTextBox->Size = System::Drawing::Size(156, 20);
			this->GTerrainNameTextBox->TabIndex = 155;
			this->GTerrainNameTextBox->Text = L"template.default";
			this->GTerrainNameTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// TerrainNameGLabel
			// 
			this->TerrainNameGLabel->AutoSize = true;
			this->TerrainNameGLabel->Location = System::Drawing::Point(5, 20);
			this->TerrainNameGLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->TerrainNameGLabel->Name = L"TerrainNameGLabel";
			this->TerrainNameGLabel->Size = System::Drawing::Size(71, 13);
			this->TerrainNameGLabel->TabIndex = 154;
			this->TerrainNameGLabel->Text = L"TerrainName:";
			// 
			// GenerationTabControl
			// 
			this->GenerationTabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GenerationTabControl->Controls->Add(this->GGeneralTabPage);
			this->GenerationTabControl->Controls->Add(this->GPagingTabPage);
			this->GenerationTabControl->Controls->Add(this->GHeightMapTabPage);
			this->GenerationTabControl->Controls->Add(this->GColorMapTabPage);
			this->GenerationTabControl->Controls->Add(this->GNormalsTabPage);
			this->GenerationTabControl->Controls->Add(this->GSplattingTabPage);
			this->GenerationTabControl->Controls->Add(this->GLightingTabPage);
			this->GenerationTabControl->Location = System::Drawing::Point(4, 98);
			this->GenerationTabControl->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GenerationTabControl->Name = L"GenerationTabControl";
			this->GenerationTabControl->SelectedIndex = 0;
			this->GenerationTabControl->Size = System::Drawing::Size(360, 569);
			this->GenerationTabControl->TabIndex = 0;
			// 
			// GGeneralTabPage
			// 
			this->GGeneralTabPage->Controls->Add(this->GTerrainScaleZTextBox);
			this->GGeneralTabPage->Controls->Add(this->GTerrainScaleZLabel);
			this->GGeneralTabPage->Controls->Add(this->ScaleZHelp);
			this->GGeneralTabPage->Controls->Add(this->GTerrainScaleYTextBox);
			this->GGeneralTabPage->Controls->Add(this->GTerrainScaleYLabel);
			this->GGeneralTabPage->Controls->Add(this->ScaleYHelp);
			this->GGeneralTabPage->Controls->Add(this->GTerrainScaleXTextBox);
			this->GGeneralTabPage->Controls->Add(this->GTerrainScaleXLabel);
			this->GGeneralTabPage->Controls->Add(this->ScaleXHelp);
			this->GGeneralTabPage->Controls->Add(this->ColorMapExportExtensionTextBox);
			this->GGeneralTabPage->Controls->Add(this->ColorMapExportExtensionLabel);
			this->GGeneralTabPage->Controls->Add(this->ColorMapExportExtensionHelp);
			this->GGeneralTabPage->Controls->Add(this->GColorMapExtensionTextBox);
			this->GGeneralTabPage->Controls->Add(this->GColorMapExtensionLabel);
			this->GGeneralTabPage->Controls->Add(this->ColorMapExtensionHelp);
			this->GGeneralTabPage->Controls->Add(this->GColorMapFileNameTextBox);
			this->GGeneralTabPage->Controls->Add(this->GColorMapFileNameLabel);
			this->GGeneralTabPage->Controls->Add(this->ColorMapFileNameHelp);
			this->GGeneralTabPage->Controls->Add(this->GHeightMapExtensionTextBox);
			this->GGeneralTabPage->Controls->Add(this->PagedCheckBox);
			this->GGeneralTabPage->Controls->Add(this->PagedHelp);
			this->GGeneralTabPage->Controls->Add(this->OutDirectoryTextBox);
			this->GGeneralTabPage->Controls->Add(this->OutDirectoryLabel);
			this->GGeneralTabPage->Controls->Add(this->OutDirectoryHelp);
			this->GGeneralTabPage->Controls->Add(this->HeightMapExportExtensionTextBox);
			this->GGeneralTabPage->Controls->Add(this->HeightMapExportExtensionLabel);
			this->GGeneralTabPage->Controls->Add(this->HeightMapExportExtensionHelp);
			this->GGeneralTabPage->Controls->Add(this->GHeightMapExtensionLabel);
			this->GGeneralTabPage->Controls->Add(this->HeightMapExtensionHelp);
			this->GGeneralTabPage->Controls->Add(this->GHeightMapFileNameTextBox);
			this->GGeneralTabPage->Controls->Add(this->HeightMapFileNameHelp);
			this->GGeneralTabPage->Controls->Add(this->GHeightMapFileNameLabel);
			this->GGeneralTabPage->Controls->Add(this->GroupHelp);
			this->GGeneralTabPage->Controls->Add(this->GGroupNameTextBox);
			this->GGeneralTabPage->Controls->Add(this->GGroupNameLabel);
			this->GGeneralTabPage->Location = System::Drawing::Point(4, 22);
			this->GGeneralTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GGeneralTabPage->Name = L"GGeneralTabPage";
			this->GGeneralTabPage->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GGeneralTabPage->Size = System::Drawing::Size(352, 543);
			this->GGeneralTabPage->TabIndex = 0;
			this->GGeneralTabPage->Text = L"General";
			this->GGeneralTabPage->UseVisualStyleBackColor = true;
			// 
			// GTerrainScaleZTextBox
			// 
			this->GTerrainScaleZTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GTerrainScaleZTextBox->Location = System::Drawing::Point(206, 284);
			this->GTerrainScaleZTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GTerrainScaleZTextBox->Name = L"GTerrainScaleZTextBox";
			this->GTerrainScaleZTextBox->Size = System::Drawing::Size(145, 20);
			this->GTerrainScaleZTextBox->TabIndex = 212;
			this->GTerrainScaleZTextBox->Text = L"90000";
			// 
			// GTerrainScaleZLabel
			// 
			this->GTerrainScaleZLabel->AutoSize = true;
			this->GTerrainScaleZLabel->Location = System::Drawing::Point(37, 286);
			this->GTerrainScaleZLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GTerrainScaleZLabel->Name = L"GTerrainScaleZLabel";
			this->GTerrainScaleZLabel->Size = System::Drawing::Size(44, 13);
			this->GTerrainScaleZLabel->TabIndex = 215;
			this->GTerrainScaleZLabel->Text = L"ScaleZ:";
			// 
			// ScaleZHelp
			// 
			this->ScaleZHelp->Location = System::Drawing::Point(15, 284);
			this->ScaleZHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ScaleZHelp->Name = L"ScaleZHelp";
			this->ScaleZHelp->Size = System::Drawing::Size(17, 19);
			this->ScaleZHelp->TabIndex = 218;
			this->ScaleZHelp->Text = L"\?";
			this->ScaleZHelp->UseVisualStyleBackColor = true;
			// 
			// GTerrainScaleYTextBox
			// 
			this->GTerrainScaleYTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GTerrainScaleYTextBox->Location = System::Drawing::Point(206, 260);
			this->GTerrainScaleYTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GTerrainScaleYTextBox->Name = L"GTerrainScaleYTextBox";
			this->GTerrainScaleYTextBox->Size = System::Drawing::Size(145, 20);
			this->GTerrainScaleYTextBox->TabIndex = 211;
			this->GTerrainScaleYTextBox->Text = L"15000";
			// 
			// GTerrainScaleYLabel
			// 
			this->GTerrainScaleYLabel->AutoSize = true;
			this->GTerrainScaleYLabel->Location = System::Drawing::Point(37, 262);
			this->GTerrainScaleYLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GTerrainScaleYLabel->Name = L"GTerrainScaleYLabel";
			this->GTerrainScaleYLabel->Size = System::Drawing::Size(44, 13);
			this->GTerrainScaleYLabel->TabIndex = 214;
			this->GTerrainScaleYLabel->Text = L"ScaleY:";
			// 
			// ScaleYHelp
			// 
			this->ScaleYHelp->Location = System::Drawing::Point(15, 260);
			this->ScaleYHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ScaleYHelp->Name = L"ScaleYHelp";
			this->ScaleYHelp->Size = System::Drawing::Size(17, 19);
			this->ScaleYHelp->TabIndex = 217;
			this->ScaleYHelp->Text = L"\?";
			this->ScaleYHelp->UseVisualStyleBackColor = true;
			// 
			// GTerrainScaleXTextBox
			// 
			this->GTerrainScaleXTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GTerrainScaleXTextBox->Location = System::Drawing::Point(206, 235);
			this->GTerrainScaleXTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GTerrainScaleXTextBox->Name = L"GTerrainScaleXTextBox";
			this->GTerrainScaleXTextBox->Size = System::Drawing::Size(145, 20);
			this->GTerrainScaleXTextBox->TabIndex = 210;
			this->GTerrainScaleXTextBox->Text = L"90000";
			// 
			// GTerrainScaleXLabel
			// 
			this->GTerrainScaleXLabel->AutoSize = true;
			this->GTerrainScaleXLabel->Location = System::Drawing::Point(37, 239);
			this->GTerrainScaleXLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GTerrainScaleXLabel->Name = L"GTerrainScaleXLabel";
			this->GTerrainScaleXLabel->Size = System::Drawing::Size(44, 13);
			this->GTerrainScaleXLabel->TabIndex = 213;
			this->GTerrainScaleXLabel->Text = L"ScaleX:";
			// 
			// ScaleXHelp
			// 
			this->ScaleXHelp->Location = System::Drawing::Point(15, 236);
			this->ScaleXHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ScaleXHelp->Name = L"ScaleXHelp";
			this->ScaleXHelp->Size = System::Drawing::Size(17, 19);
			this->ScaleXHelp->TabIndex = 216;
			this->ScaleXHelp->Text = L"\?";
			this->ScaleXHelp->UseVisualStyleBackColor = true;
			// 
			// ColorMapExportExtensionTextBox
			// 
			this->ColorMapExportExtensionTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->ColorMapExportExtensionTextBox->Location = System::Drawing::Point(206, 166);
			this->ColorMapExportExtensionTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ColorMapExportExtensionTextBox->Name = L"ColorMapExportExtensionTextBox";
			this->ColorMapExportExtensionTextBox->ReadOnly = true;
			this->ColorMapExportExtensionTextBox->Size = System::Drawing::Size(145, 20);
			this->ColorMapExportExtensionTextBox->TabIndex = 106;
			this->ColorMapExportExtensionTextBox->Text = L"png";
			// 
			// ColorMapExportExtensionLabel
			// 
			this->ColorMapExportExtensionLabel->AutoSize = true;
			this->ColorMapExportExtensionLabel->Location = System::Drawing::Point(37, 168);
			this->ColorMapExportExtensionLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ColorMapExportExtensionLabel->Name = L"ColorMapExportExtensionLabel";
			this->ColorMapExportExtensionLabel->Size = System::Drawing::Size(131, 13);
			this->ColorMapExportExtensionLabel->TabIndex = 107;
			this->ColorMapExportExtensionLabel->Text = L"ColorMapExportExtension:";
			// 
			// ColorMapExportExtensionHelp
			// 
			this->ColorMapExportExtensionHelp->Location = System::Drawing::Point(15, 166);
			this->ColorMapExportExtensionHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ColorMapExportExtensionHelp->Name = L"ColorMapExportExtensionHelp";
			this->ColorMapExportExtensionHelp->Size = System::Drawing::Size(17, 19);
			this->ColorMapExportExtensionHelp->TabIndex = 108;
			this->ColorMapExportExtensionHelp->Text = L"\?";
			this->ColorMapExportExtensionHelp->UseVisualStyleBackColor = true;
			// 
			// GColorMapExtensionTextBox
			// 
			this->GColorMapExtensionTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GColorMapExtensionTextBox->Location = System::Drawing::Point(206, 142);
			this->GColorMapExtensionTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GColorMapExtensionTextBox->Name = L"GColorMapExtensionTextBox";
			this->GColorMapExtensionTextBox->ReadOnly = true;
			this->GColorMapExtensionTextBox->Size = System::Drawing::Size(145, 20);
			this->GColorMapExtensionTextBox->TabIndex = 103;
			this->GColorMapExtensionTextBox->Text = L"png";
			// 
			// GColorMapExtensionLabel
			// 
			this->GColorMapExtensionLabel->AutoSize = true;
			this->GColorMapExtensionLabel->Location = System::Drawing::Point(37, 145);
			this->GColorMapExtensionLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GColorMapExtensionLabel->Name = L"GColorMapExtensionLabel";
			this->GColorMapExtensionLabel->Size = System::Drawing::Size(101, 13);
			this->GColorMapExtensionLabel->TabIndex = 104;
			this->GColorMapExtensionLabel->Text = L"ColorMapExtension:";
			// 
			// ColorMapExtensionHelp
			// 
			this->ColorMapExtensionHelp->Location = System::Drawing::Point(15, 142);
			this->ColorMapExtensionHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ColorMapExtensionHelp->Name = L"ColorMapExtensionHelp";
			this->ColorMapExtensionHelp->Size = System::Drawing::Size(17, 19);
			this->ColorMapExtensionHelp->TabIndex = 105;
			this->ColorMapExtensionHelp->Text = L"\?";
			this->ColorMapExtensionHelp->UseVisualStyleBackColor = true;
			// 
			// GColorMapFileNameTextBox
			// 
			this->GColorMapFileNameTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GColorMapFileNameTextBox->Location = System::Drawing::Point(206, 119);
			this->GColorMapFileNameTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GColorMapFileNameTextBox->Name = L"GColorMapFileNameTextBox";
			this->GColorMapFileNameTextBox->ReadOnly = true;
			this->GColorMapFileNameTextBox->Size = System::Drawing::Size(145, 20);
			this->GColorMapFileNameTextBox->TabIndex = 100;
			this->GColorMapFileNameTextBox->Text = L"ps_texture_1k.png";
			// 
			// GColorMapFileNameLabel
			// 
			this->GColorMapFileNameLabel->AutoSize = true;
			this->GColorMapFileNameLabel->Location = System::Drawing::Point(37, 121);
			this->GColorMapFileNameLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GColorMapFileNameLabel->Name = L"GColorMapFileNameLabel";
			this->GColorMapFileNameLabel->Size = System::Drawing::Size(99, 13);
			this->GColorMapFileNameLabel->TabIndex = 102;
			this->GColorMapFileNameLabel->Text = L"ColorMapFileName:";
			// 
			// ColorMapFileNameHelp
			// 
			this->ColorMapFileNameHelp->Location = System::Drawing::Point(15, 119);
			this->ColorMapFileNameHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ColorMapFileNameHelp->Name = L"ColorMapFileNameHelp";
			this->ColorMapFileNameHelp->Size = System::Drawing::Size(17, 19);
			this->ColorMapFileNameHelp->TabIndex = 101;
			this->ColorMapFileNameHelp->Text = L"\?";
			this->ColorMapFileNameHelp->UseVisualStyleBackColor = true;
			// 
			// GHeightMapExtensionTextBox
			// 
			this->GHeightMapExtensionTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GHeightMapExtensionTextBox->Location = System::Drawing::Point(206, 72);
			this->GHeightMapExtensionTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GHeightMapExtensionTextBox->Name = L"GHeightMapExtensionTextBox";
			this->GHeightMapExtensionTextBox->ReadOnly = true;
			this->GHeightMapExtensionTextBox->Size = System::Drawing::Size(145, 20);
			this->GHeightMapExtensionTextBox->TabIndex = 69;
			this->GHeightMapExtensionTextBox->Text = L"png";
			// 
			// PagedCheckBox
			// 
			this->PagedCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->PagedCheckBox->Checked = true;
			this->PagedCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->PagedCheckBox->Location = System::Drawing::Point(36, 191);
			this->PagedCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->PagedCheckBox->Name = L"PagedCheckBox";
			this->PagedCheckBox->Size = System::Drawing::Size(231, 20);
			this->PagedCheckBox->TabIndex = 73;
			this->PagedCheckBox->Text = L"Paged:";
			this->PagedCheckBox->UseVisualStyleBackColor = true;
			// 
			// PagedHelp
			// 
			this->PagedHelp->Location = System::Drawing::Point(15, 189);
			this->PagedHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->PagedHelp->Name = L"PagedHelp";
			this->PagedHelp->Size = System::Drawing::Size(17, 19);
			this->PagedHelp->TabIndex = 93;
			this->PagedHelp->Text = L"\?";
			this->PagedHelp->UseVisualStyleBackColor = true;
			// 
			// OutDirectoryTextBox
			// 
			this->OutDirectoryTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->OutDirectoryTextBox->Location = System::Drawing::Point(206, 213);
			this->OutDirectoryTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->OutDirectoryTextBox->Name = L"OutDirectoryTextBox";
			this->OutDirectoryTextBox->ReadOnly = true;
			this->OutDirectoryTextBox->Size = System::Drawing::Size(145, 20);
			this->OutDirectoryTextBox->TabIndex = 78;
			this->OutDirectoryTextBox->Text = L"\\TerrainName";
			// 
			// OutDirectoryLabel
			// 
			this->OutDirectoryLabel->AutoSize = true;
			this->OutDirectoryLabel->Location = System::Drawing::Point(37, 215);
			this->OutDirectoryLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->OutDirectoryLabel->Name = L"OutDirectoryLabel";
			this->OutDirectoryLabel->Size = System::Drawing::Size(69, 13);
			this->OutDirectoryLabel->TabIndex = 86;
			this->OutDirectoryLabel->Text = L"OutDirectory:";
			// 
			// OutDirectoryHelp
			// 
			this->OutDirectoryHelp->Location = System::Drawing::Point(15, 213);
			this->OutDirectoryHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->OutDirectoryHelp->Name = L"OutDirectoryHelp";
			this->OutDirectoryHelp->Size = System::Drawing::Size(17, 19);
			this->OutDirectoryHelp->TabIndex = 98;
			this->OutDirectoryHelp->Text = L"\?";
			this->OutDirectoryHelp->UseVisualStyleBackColor = true;
			// 
			// HeightMapExportExtensionTextBox
			// 
			this->HeightMapExportExtensionTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->HeightMapExportExtensionTextBox->Location = System::Drawing::Point(206, 95);
			this->HeightMapExportExtensionTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HeightMapExportExtensionTextBox->Name = L"HeightMapExportExtensionTextBox";
			this->HeightMapExportExtensionTextBox->ReadOnly = true;
			this->HeightMapExportExtensionTextBox->Size = System::Drawing::Size(145, 20);
			this->HeightMapExportExtensionTextBox->TabIndex = 70;
			this->HeightMapExportExtensionTextBox->Text = L"png";
			// 
			// HeightMapExportExtensionLabel
			// 
			this->HeightMapExportExtensionLabel->AutoSize = true;
			this->HeightMapExportExtensionLabel->Location = System::Drawing::Point(37, 98);
			this->HeightMapExportExtensionLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->HeightMapExportExtensionLabel->Name = L"HeightMapExportExtensionLabel";
			this->HeightMapExportExtensionLabel->Size = System::Drawing::Size(138, 13);
			this->HeightMapExportExtensionLabel->TabIndex = 81;
			this->HeightMapExportExtensionLabel->Text = L"HeightMapExportExtension:";
			// 
			// HeightMapExportExtensionHelp
			// 
			this->HeightMapExportExtensionHelp->Location = System::Drawing::Point(15, 95);
			this->HeightMapExportExtensionHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HeightMapExportExtensionHelp->Name = L"HeightMapExportExtensionHelp";
			this->HeightMapExportExtensionHelp->Size = System::Drawing::Size(17, 19);
			this->HeightMapExportExtensionHelp->TabIndex = 90;
			this->HeightMapExportExtensionHelp->Text = L"\?";
			this->HeightMapExportExtensionHelp->UseVisualStyleBackColor = true;
			// 
			// GHeightMapExtensionLabel
			// 
			this->GHeightMapExtensionLabel->AutoSize = true;
			this->GHeightMapExtensionLabel->Location = System::Drawing::Point(37, 74);
			this->GHeightMapExtensionLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GHeightMapExtensionLabel->Name = L"GHeightMapExtensionLabel";
			this->GHeightMapExtensionLabel->Size = System::Drawing::Size(108, 13);
			this->GHeightMapExtensionLabel->TabIndex = 80;
			this->GHeightMapExtensionLabel->Text = L"HeightMapExtension:";
			// 
			// HeightMapExtensionHelp
			// 
			this->HeightMapExtensionHelp->Location = System::Drawing::Point(15, 72);
			this->HeightMapExtensionHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HeightMapExtensionHelp->Name = L"HeightMapExtensionHelp";
			this->HeightMapExtensionHelp->Size = System::Drawing::Size(17, 19);
			this->HeightMapExtensionHelp->TabIndex = 89;
			this->HeightMapExtensionHelp->Text = L"\?";
			this->HeightMapExtensionHelp->UseVisualStyleBackColor = true;
			// 
			// GHeightMapFileNameTextBox
			// 
			this->GHeightMapFileNameTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GHeightMapFileNameTextBox->Location = System::Drawing::Point(206, 48);
			this->GHeightMapFileNameTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GHeightMapFileNameTextBox->Name = L"GHeightMapFileNameTextBox";
			this->GHeightMapFileNameTextBox->ReadOnly = true;
			this->GHeightMapFileNameTextBox->Size = System::Drawing::Size(145, 20);
			this->GHeightMapFileNameTextBox->TabIndex = 68;
			this->GHeightMapFileNameTextBox->Text = L"ps_height_1k";
			// 
			// HeightMapFileNameHelp
			// 
			this->HeightMapFileNameHelp->Location = System::Drawing::Point(15, 48);
			this->HeightMapFileNameHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HeightMapFileNameHelp->Name = L"HeightMapFileNameHelp";
			this->HeightMapFileNameHelp->Size = System::Drawing::Size(17, 19);
			this->HeightMapFileNameHelp->TabIndex = 88;
			this->HeightMapFileNameHelp->Text = L"\?";
			this->HeightMapFileNameHelp->UseVisualStyleBackColor = true;
			// 
			// GHeightMapFileNameLabel
			// 
			this->GHeightMapFileNameLabel->AutoSize = true;
			this->GHeightMapFileNameLabel->Location = System::Drawing::Point(37, 50);
			this->GHeightMapFileNameLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GHeightMapFileNameLabel->Name = L"GHeightMapFileNameLabel";
			this->GHeightMapFileNameLabel->Size = System::Drawing::Size(106, 13);
			this->GHeightMapFileNameLabel->TabIndex = 79;
			this->GHeightMapFileNameLabel->Text = L"HeightMapFileName:";
			// 
			// GroupHelp
			// 
			this->GroupHelp->Location = System::Drawing::Point(15, 24);
			this->GroupHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GroupHelp->Name = L"GroupHelp";
			this->GroupHelp->Size = System::Drawing::Size(17, 19);
			this->GroupHelp->TabIndex = 87;
			this->GroupHelp->Text = L"\?";
			this->GroupHelp->UseVisualStyleBackColor = true;
			// 
			// GGroupNameTextBox
			// 
			this->GGroupNameTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GGroupNameTextBox->Location = System::Drawing::Point(206, 24);
			this->GGroupNameTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GGroupNameTextBox->Name = L"GGroupNameTextBox";
			this->GGroupNameTextBox->Size = System::Drawing::Size(145, 20);
			this->GGroupNameTextBox->TabIndex = 67;
			this->GGroupNameTextBox->Text = L"PLSM2";
			// 
			// GGroupNameLabel
			// 
			this->GGroupNameLabel->AutoSize = true;
			this->GGroupNameLabel->Location = System::Drawing::Point(37, 27);
			this->GGroupNameLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GGroupNameLabel->Name = L"GGroupNameLabel";
			this->GGroupNameLabel->Size = System::Drawing::Size(67, 13);
			this->GGroupNameLabel->TabIndex = 74;
			this->GGroupNameLabel->Text = L"GroupName:";
			// 
			// GPagingTabPage
			// 
			this->GPagingTabPage->Controls->Add(this->GTileSizeTextBox);
			this->GPagingTabPage->Controls->Add(this->GTileSizeLabel);
			this->GPagingTabPage->Controls->Add(this->TileSizeHelp);
			this->GPagingTabPage->Controls->Add(this->GMinValueTextBox);
			this->GPagingTabPage->Controls->Add(this->GMinValueLabel);
			this->GPagingTabPage->Controls->Add(this->MinValueHelp);
			this->GPagingTabPage->Controls->Add(this->GMaxValueTextBox);
			this->GPagingTabPage->Controls->Add(this->GMaxValueLabel);
			this->GPagingTabPage->Controls->Add(this->MaxValueHelp);
			this->GPagingTabPage->Controls->Add(this->GData2DFormatComboBox);
			this->GPagingTabPage->Controls->Add(this->GData2DFormatLabel);
			this->GPagingTabPage->Controls->Add(this->Data2DFormatHelp);
			this->GPagingTabPage->Controls->Add(this->GPageSizeTextBox);
			this->GPagingTabPage->Controls->Add(this->GPageSizeLabel);
			this->GPagingTabPage->Controls->Add(this->PageSizeHelp);
			this->GPagingTabPage->Location = System::Drawing::Point(4, 22);
			this->GPagingTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GPagingTabPage->Name = L"GPagingTabPage";
			this->GPagingTabPage->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GPagingTabPage->Size = System::Drawing::Size(352, 543);
			this->GPagingTabPage->TabIndex = 1;
			this->GPagingTabPage->Text = L"Paging";
			this->GPagingTabPage->UseVisualStyleBackColor = true;
			// 
			// GTileSizeTextBox
			// 
			this->GTileSizeTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GTileSizeTextBox->Location = System::Drawing::Point(188, 48);
			this->GTileSizeTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GTileSizeTextBox->Name = L"GTileSizeTextBox";
			this->GTileSizeTextBox->Size = System::Drawing::Size(145, 20);
			this->GTileSizeTextBox->TabIndex = 73;
			this->GTileSizeTextBox->Text = L"65";
			// 
			// GTileSizeLabel
			// 
			this->GTileSizeLabel->AutoSize = true;
			this->GTileSizeLabel->Location = System::Drawing::Point(37, 50);
			this->GTileSizeLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GTileSizeLabel->Name = L"GTileSizeLabel";
			this->GTileSizeLabel->Size = System::Drawing::Size(47, 13);
			this->GTileSizeLabel->TabIndex = 81;
			this->GTileSizeLabel->Text = L"TileSize:";
			// 
			// TileSizeHelp
			// 
			this->TileSizeHelp->Location = System::Drawing::Point(15, 48);
			this->TileSizeHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->TileSizeHelp->Name = L"TileSizeHelp";
			this->TileSizeHelp->Size = System::Drawing::Size(17, 19);
			this->TileSizeHelp->TabIndex = 83;
			this->TileSizeHelp->Text = L"\?";
			this->TileSizeHelp->UseVisualStyleBackColor = true;
			// 
			// GMinValueTextBox
			// 
			this->GMinValueTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GMinValueTextBox->Enabled = false;
			this->GMinValueTextBox->Location = System::Drawing::Point(188, 119);
			this->GMinValueTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GMinValueTextBox->Name = L"GMinValueTextBox";
			this->GMinValueTextBox->Size = System::Drawing::Size(145, 20);
			this->GMinValueTextBox->TabIndex = 76;
			this->GMinValueTextBox->Text = L"0";
			// 
			// GMinValueLabel
			// 
			this->GMinValueLabel->AutoSize = true;
			this->GMinValueLabel->Location = System::Drawing::Point(38, 121);
			this->GMinValueLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GMinValueLabel->Name = L"GMinValueLabel";
			this->GMinValueLabel->Size = System::Drawing::Size(54, 13);
			this->GMinValueLabel->TabIndex = 80;
			this->GMinValueLabel->Text = L"MinValue:";
			// 
			// MinValueHelp
			// 
			this->MinValueHelp->Location = System::Drawing::Point(15, 119);
			this->MinValueHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MinValueHelp->Name = L"MinValueHelp";
			this->MinValueHelp->Size = System::Drawing::Size(17, 19);
			this->MinValueHelp->TabIndex = 86;
			this->MinValueHelp->Text = L"\?";
			this->MinValueHelp->UseVisualStyleBackColor = true;
			// 
			// GMaxValueTextBox
			// 
			this->GMaxValueTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GMaxValueTextBox->Enabled = false;
			this->GMaxValueTextBox->Location = System::Drawing::Point(188, 95);
			this->GMaxValueTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GMaxValueTextBox->Name = L"GMaxValueTextBox";
			this->GMaxValueTextBox->Size = System::Drawing::Size(145, 20);
			this->GMaxValueTextBox->TabIndex = 75;
			this->GMaxValueTextBox->Text = L"0";
			// 
			// GMaxValueLabel
			// 
			this->GMaxValueLabel->AutoSize = true;
			this->GMaxValueLabel->Location = System::Drawing::Point(37, 98);
			this->GMaxValueLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GMaxValueLabel->Name = L"GMaxValueLabel";
			this->GMaxValueLabel->Size = System::Drawing::Size(57, 13);
			this->GMaxValueLabel->TabIndex = 79;
			this->GMaxValueLabel->Text = L"MaxValue:";
			// 
			// MaxValueHelp
			// 
			this->MaxValueHelp->Location = System::Drawing::Point(15, 95);
			this->MaxValueHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaxValueHelp->Name = L"MaxValueHelp";
			this->MaxValueHelp->Size = System::Drawing::Size(17, 19);
			this->MaxValueHelp->TabIndex = 85;
			this->MaxValueHelp->Text = L"\?";
			this->MaxValueHelp->UseVisualStyleBackColor = true;
			// 
			// GData2DFormatComboBox
			// 
			this->GData2DFormatComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GData2DFormatComboBox->FormattingEnabled = true;
			this->GData2DFormatComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"HeightField", L"HeightFieldTC", L"SplineField"});
			this->GData2DFormatComboBox->Location = System::Drawing::Point(188, 72);
			this->GData2DFormatComboBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GData2DFormatComboBox->Name = L"GData2DFormatComboBox";
			this->GData2DFormatComboBox->Size = System::Drawing::Size(145, 21);
			this->GData2DFormatComboBox->TabIndex = 74;
			this->GData2DFormatComboBox->Text = L"HeightField";
			// 
			// GData2DFormatLabel
			// 
			this->GData2DFormatLabel->AutoSize = true;
			this->GData2DFormatLabel->Location = System::Drawing::Point(37, 74);
			this->GData2DFormatLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GData2DFormatLabel->Name = L"GData2DFormatLabel";
			this->GData2DFormatLabel->Size = System::Drawing::Size(79, 13);
			this->GData2DFormatLabel->TabIndex = 78;
			this->GData2DFormatLabel->Text = L"Data2DFormat:";
			// 
			// Data2DFormatHelp
			// 
			this->Data2DFormatHelp->Location = System::Drawing::Point(15, 72);
			this->Data2DFormatHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Data2DFormatHelp->Name = L"Data2DFormatHelp";
			this->Data2DFormatHelp->Size = System::Drawing::Size(17, 19);
			this->Data2DFormatHelp->TabIndex = 84;
			this->Data2DFormatHelp->Text = L"\?";
			this->Data2DFormatHelp->UseVisualStyleBackColor = true;
			// 
			// GPageSizeTextBox
			// 
			this->GPageSizeTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GPageSizeTextBox->Location = System::Drawing::Point(188, 24);
			this->GPageSizeTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GPageSizeTextBox->Name = L"GPageSizeTextBox";
			this->GPageSizeTextBox->Size = System::Drawing::Size(145, 20);
			this->GPageSizeTextBox->TabIndex = 72;
			this->GPageSizeTextBox->Text = L"513";
			// 
			// GPageSizeLabel
			// 
			this->GPageSizeLabel->AutoSize = true;
			this->GPageSizeLabel->Location = System::Drawing::Point(37, 27);
			this->GPageSizeLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GPageSizeLabel->Name = L"GPageSizeLabel";
			this->GPageSizeLabel->Size = System::Drawing::Size(55, 13);
			this->GPageSizeLabel->TabIndex = 77;
			this->GPageSizeLabel->Text = L"PageSize:";
			// 
			// PageSizeHelp
			// 
			this->PageSizeHelp->Location = System::Drawing::Point(15, 24);
			this->PageSizeHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->PageSizeHelp->Name = L"PageSizeHelp";
			this->PageSizeHelp->Size = System::Drawing::Size(17, 19);
			this->PageSizeHelp->TabIndex = 82;
			this->PageSizeHelp->Text = L"\?";
			this->PageSizeHelp->UseVisualStyleBackColor = true;
			// 
			// GHeightMapTabPage
			// 
			this->GHeightMapTabPage->Controls->Add(this->MiniMapHeightTextBox);
			this->GHeightMapTabPage->Controls->Add(this->MiniMapHeightLabel);
			this->GHeightMapTabPage->Controls->Add(this->MiniMapHeightHelp);
			this->GHeightMapTabPage->Controls->Add(this->MiniMapWidthTextBox);
			this->GHeightMapTabPage->Controls->Add(this->MiniMapWidthLabel);
			this->GHeightMapTabPage->Controls->Add(this->MiniMapWidthHelp);
			this->GHeightMapTabPage->Controls->Add(this->EqualizeCheckBox);
			this->GHeightMapTabPage->Controls->Add(this->EqualizeHelp);
			this->GHeightMapTabPage->Controls->Add(this->HeightMapBlurFactorTextBox);
			this->GHeightMapTabPage->Controls->Add(this->HeightMapBlurFactorLabel);
			this->GHeightMapTabPage->Controls->Add(this->HeightMapBlurFactorHelp);
			this->GHeightMapTabPage->Controls->Add(this->InfiniteMapCheckBox);
			this->GHeightMapTabPage->Controls->Add(this->InfiniteMapHelp);
			this->GHeightMapTabPage->Controls->Add(this->HeightMapCheckBox);
			this->GHeightMapTabPage->Controls->Add(this->HeightMap_Help);
			this->GHeightMapTabPage->Controls->Add(this->MiniMapCheckBox);
			this->GHeightMapTabPage->Controls->Add(this->MiniMapHelp);
			this->GHeightMapTabPage->Location = System::Drawing::Point(4, 22);
			this->GHeightMapTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GHeightMapTabPage->Name = L"GHeightMapTabPage";
			this->GHeightMapTabPage->Size = System::Drawing::Size(352, 543);
			this->GHeightMapTabPage->TabIndex = 3;
			this->GHeightMapTabPage->Text = L"Height Map";
			this->GHeightMapTabPage->UseVisualStyleBackColor = true;
			// 
			// MiniMapHeightTextBox
			// 
			this->MiniMapHeightTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->MiniMapHeightTextBox->Location = System::Drawing::Point(187, 166);
			this->MiniMapHeightTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MiniMapHeightTextBox->Name = L"MiniMapHeightTextBox";
			this->MiniMapHeightTextBox->Size = System::Drawing::Size(145, 20);
			this->MiniMapHeightTextBox->TabIndex = 96;
			this->MiniMapHeightTextBox->Text = L"512";
			// 
			// MiniMapHeightLabel
			// 
			this->MiniMapHeightLabel->AutoSize = true;
			this->MiniMapHeightLabel->Location = System::Drawing::Point(37, 168);
			this->MiniMapHeightLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->MiniMapHeightLabel->Name = L"MiniMapHeightLabel";
			this->MiniMapHeightLabel->Size = System::Drawing::Size(81, 13);
			this->MiniMapHeightLabel->TabIndex = 106;
			this->MiniMapHeightLabel->Text = L"MiniMapHeight:";
			// 
			// MiniMapHeightHelp
			// 
			this->MiniMapHeightHelp->Location = System::Drawing::Point(15, 166);
			this->MiniMapHeightHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MiniMapHeightHelp->Name = L"MiniMapHeightHelp";
			this->MiniMapHeightHelp->Size = System::Drawing::Size(17, 19);
			this->MiniMapHeightHelp->TabIndex = 103;
			this->MiniMapHeightHelp->Text = L"\?";
			this->MiniMapHeightHelp->UseVisualStyleBackColor = true;
			// 
			// MiniMapWidthTextBox
			// 
			this->MiniMapWidthTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->MiniMapWidthTextBox->Location = System::Drawing::Point(187, 142);
			this->MiniMapWidthTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MiniMapWidthTextBox->Name = L"MiniMapWidthTextBox";
			this->MiniMapWidthTextBox->Size = System::Drawing::Size(145, 20);
			this->MiniMapWidthTextBox->TabIndex = 95;
			this->MiniMapWidthTextBox->Text = L"512";
			// 
			// MiniMapWidthLabel
			// 
			this->MiniMapWidthLabel->AutoSize = true;
			this->MiniMapWidthLabel->Location = System::Drawing::Point(37, 145);
			this->MiniMapWidthLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->MiniMapWidthLabel->Name = L"MiniMapWidthLabel";
			this->MiniMapWidthLabel->Size = System::Drawing::Size(78, 13);
			this->MiniMapWidthLabel->TabIndex = 105;
			this->MiniMapWidthLabel->Text = L"MiniMapWidth:";
			// 
			// MiniMapWidthHelp
			// 
			this->MiniMapWidthHelp->Location = System::Drawing::Point(15, 142);
			this->MiniMapWidthHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MiniMapWidthHelp->Name = L"MiniMapWidthHelp";
			this->MiniMapWidthHelp->Size = System::Drawing::Size(17, 19);
			this->MiniMapWidthHelp->TabIndex = 102;
			this->MiniMapWidthHelp->Text = L"\?";
			this->MiniMapWidthHelp->UseVisualStyleBackColor = true;
			// 
			// EqualizeCheckBox
			// 
			this->EqualizeCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->EqualizeCheckBox->Location = System::Drawing::Point(36, 95);
			this->EqualizeCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->EqualizeCheckBox->Name = L"EqualizeCheckBox";
			this->EqualizeCheckBox->Size = System::Drawing::Size(231, 20);
			this->EqualizeCheckBox->TabIndex = 93;
			this->EqualizeCheckBox->Text = L"Equalize:";
			this->EqualizeCheckBox->UseVisualStyleBackColor = true;
			// 
			// EqualizeHelp
			// 
			this->EqualizeHelp->Location = System::Drawing::Point(15, 95);
			this->EqualizeHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->EqualizeHelp->Name = L"EqualizeHelp";
			this->EqualizeHelp->Size = System::Drawing::Size(17, 19);
			this->EqualizeHelp->TabIndex = 100;
			this->EqualizeHelp->Text = L"\?";
			this->EqualizeHelp->UseVisualStyleBackColor = true;
			// 
			// HeightMapBlurFactorTextBox
			// 
			this->HeightMapBlurFactorTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->HeightMapBlurFactorTextBox->Location = System::Drawing::Point(187, 72);
			this->HeightMapBlurFactorTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HeightMapBlurFactorTextBox->Name = L"HeightMapBlurFactorTextBox";
			this->HeightMapBlurFactorTextBox->Size = System::Drawing::Size(145, 20);
			this->HeightMapBlurFactorTextBox->TabIndex = 92;
			this->HeightMapBlurFactorTextBox->Text = L"0.0f";
			// 
			// HeightMapBlurFactorLabel
			// 
			this->HeightMapBlurFactorLabel->AutoSize = true;
			this->HeightMapBlurFactorLabel->Location = System::Drawing::Point(37, 74);
			this->HeightMapBlurFactorLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->HeightMapBlurFactorLabel->Name = L"HeightMapBlurFactorLabel";
			this->HeightMapBlurFactorLabel->Size = System::Drawing::Size(110, 13);
			this->HeightMapBlurFactorLabel->TabIndex = 104;
			this->HeightMapBlurFactorLabel->Text = L"HeightMapBlurFactor:";
			// 
			// HeightMapBlurFactorHelp
			// 
			this->HeightMapBlurFactorHelp->Location = System::Drawing::Point(15, 72);
			this->HeightMapBlurFactorHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HeightMapBlurFactorHelp->Name = L"HeightMapBlurFactorHelp";
			this->HeightMapBlurFactorHelp->Size = System::Drawing::Size(17, 19);
			this->HeightMapBlurFactorHelp->TabIndex = 99;
			this->HeightMapBlurFactorHelp->Text = L"\?";
			this->HeightMapBlurFactorHelp->UseVisualStyleBackColor = true;
			// 
			// InfiniteMapCheckBox
			// 
			this->InfiniteMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->InfiniteMapCheckBox->Location = System::Drawing::Point(36, 48);
			this->InfiniteMapCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->InfiniteMapCheckBox->Name = L"InfiniteMapCheckBox";
			this->InfiniteMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->InfiniteMapCheckBox->TabIndex = 91;
			this->InfiniteMapCheckBox->Text = L"InfiniteMap:";
			this->InfiniteMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// InfiniteMapHelp
			// 
			this->InfiniteMapHelp->Location = System::Drawing::Point(15, 48);
			this->InfiniteMapHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->InfiniteMapHelp->Name = L"InfiniteMapHelp";
			this->InfiniteMapHelp->Size = System::Drawing::Size(17, 19);
			this->InfiniteMapHelp->TabIndex = 98;
			this->InfiniteMapHelp->Text = L"\?";
			this->InfiniteMapHelp->UseVisualStyleBackColor = true;
			// 
			// HeightMapCheckBox
			// 
			this->HeightMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->HeightMapCheckBox->Checked = true;
			this->HeightMapCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->HeightMapCheckBox->Location = System::Drawing::Point(36, 24);
			this->HeightMapCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HeightMapCheckBox->Name = L"HeightMapCheckBox";
			this->HeightMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->HeightMapCheckBox->TabIndex = 90;
			this->HeightMapCheckBox->Text = L"HeightMap:";
			this->HeightMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// HeightMap_Help
			// 
			this->HeightMap_Help->Location = System::Drawing::Point(15, 24);
			this->HeightMap_Help->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HeightMap_Help->Name = L"HeightMap_Help";
			this->HeightMap_Help->Size = System::Drawing::Size(17, 19);
			this->HeightMap_Help->TabIndex = 97;
			this->HeightMap_Help->Text = L"\?";
			this->HeightMap_Help->UseVisualStyleBackColor = true;
			// 
			// MiniMapCheckBox
			// 
			this->MiniMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->MiniMapCheckBox->Checked = true;
			this->MiniMapCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->MiniMapCheckBox->Location = System::Drawing::Point(37, 119);
			this->MiniMapCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MiniMapCheckBox->Name = L"MiniMapCheckBox";
			this->MiniMapCheckBox->Size = System::Drawing::Size(230, 20);
			this->MiniMapCheckBox->TabIndex = 94;
			this->MiniMapCheckBox->Text = L"MiniMap:";
			this->MiniMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// MiniMapHelp
			// 
			this->MiniMapHelp->Location = System::Drawing::Point(15, 119);
			this->MiniMapHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MiniMapHelp->Name = L"MiniMapHelp";
			this->MiniMapHelp->Size = System::Drawing::Size(17, 19);
			this->MiniMapHelp->TabIndex = 101;
			this->MiniMapHelp->Text = L"\?";
			this->MiniMapHelp->UseVisualStyleBackColor = true;
			// 
			// GColorMapTabPage
			// 
			this->GColorMapTabPage->Controls->Add(this->GColorMapStretchFactorTextBox);
			this->GColorMapTabPage->Controls->Add(this->GColorMapStretchFactorLabel);
			this->GColorMapTabPage->Controls->Add(this->ColorMapStretchFactorHelp);
			this->GColorMapTabPage->Controls->Add(this->LitColorMapSplitCheckBox);
			this->GColorMapTabPage->Controls->Add(this->LitColorMapSplitHelp);
			this->GColorMapTabPage->Controls->Add(this->ColorMapSplitCheckBox);
			this->GColorMapTabPage->Controls->Add(this->ColorMapSplitHelp);
			this->GColorMapTabPage->Location = System::Drawing::Point(4, 22);
			this->GColorMapTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GColorMapTabPage->Name = L"GColorMapTabPage";
			this->GColorMapTabPage->Size = System::Drawing::Size(352, 543);
			this->GColorMapTabPage->TabIndex = 2;
			this->GColorMapTabPage->Text = L"Color Map";
			this->GColorMapTabPage->UseVisualStyleBackColor = true;
			// 
			// GColorMapStretchFactorTextBox
			// 
			this->GColorMapStretchFactorTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->GColorMapStretchFactorTextBox->Location = System::Drawing::Point(202, 24);
			this->GColorMapStretchFactorTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GColorMapStretchFactorTextBox->Name = L"GColorMapStretchFactorTextBox";
			this->GColorMapStretchFactorTextBox->Size = System::Drawing::Size(145, 20);
			this->GColorMapStretchFactorTextBox->TabIndex = 97;
			this->GColorMapStretchFactorTextBox->Text = L"1";
			// 
			// GColorMapStretchFactorLabel
			// 
			this->GColorMapStretchFactorLabel->AutoSize = true;
			this->GColorMapStretchFactorLabel->Location = System::Drawing::Point(37, 27);
			this->GColorMapStretchFactorLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GColorMapStretchFactorLabel->Name = L"GColorMapStretchFactorLabel";
			this->GColorMapStretchFactorLabel->Size = System::Drawing::Size(119, 13);
			this->GColorMapStretchFactorLabel->TabIndex = 101;
			this->GColorMapStretchFactorLabel->Text = L"ColorMapStretchFactor:";
			// 
			// ColorMapStretchFactorHelp
			// 
			this->ColorMapStretchFactorHelp->Location = System::Drawing::Point(15, 24);
			this->ColorMapStretchFactorHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ColorMapStretchFactorHelp->Name = L"ColorMapStretchFactorHelp";
			this->ColorMapStretchFactorHelp->Size = System::Drawing::Size(17, 19);
			this->ColorMapStretchFactorHelp->TabIndex = 100;
			this->ColorMapStretchFactorHelp->Text = L"\?";
			this->ColorMapStretchFactorHelp->UseVisualStyleBackColor = true;
			// 
			// LitColorMapSplitCheckBox
			// 
			this->LitColorMapSplitCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->LitColorMapSplitCheckBox->Location = System::Drawing::Point(37, 72);
			this->LitColorMapSplitCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->LitColorMapSplitCheckBox->Name = L"LitColorMapSplitCheckBox";
			this->LitColorMapSplitCheckBox->Size = System::Drawing::Size(243, 20);
			this->LitColorMapSplitCheckBox->TabIndex = 77;
			this->LitColorMapSplitCheckBox->Text = L"LitColorMapSplit:";
			this->LitColorMapSplitCheckBox->UseVisualStyleBackColor = true;
			// 
			// LitColorMapSplitHelp
			// 
			this->LitColorMapSplitHelp->Location = System::Drawing::Point(15, 72);
			this->LitColorMapSplitHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->LitColorMapSplitHelp->Name = L"LitColorMapSplitHelp";
			this->LitColorMapSplitHelp->Size = System::Drawing::Size(17, 19);
			this->LitColorMapSplitHelp->TabIndex = 81;
			this->LitColorMapSplitHelp->Text = L"\?";
			this->LitColorMapSplitHelp->UseVisualStyleBackColor = true;
			// 
			// ColorMapSplitCheckBox
			// 
			this->ColorMapSplitCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->ColorMapSplitCheckBox->Checked = true;
			this->ColorMapSplitCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->ColorMapSplitCheckBox->Location = System::Drawing::Point(36, 50);
			this->ColorMapSplitCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ColorMapSplitCheckBox->Name = L"ColorMapSplitCheckBox";
			this->ColorMapSplitCheckBox->Size = System::Drawing::Size(244, 20);
			this->ColorMapSplitCheckBox->TabIndex = 76;
			this->ColorMapSplitCheckBox->Text = L"ColorMapSplit:";
			this->ColorMapSplitCheckBox->UseVisualStyleBackColor = true;
			// 
			// ColorMapSplitHelp
			// 
			this->ColorMapSplitHelp->Location = System::Drawing::Point(15, 48);
			this->ColorMapSplitHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ColorMapSplitHelp->Name = L"ColorMapSplitHelp";
			this->ColorMapSplitHelp->Size = System::Drawing::Size(17, 19);
			this->ColorMapSplitHelp->TabIndex = 80;
			this->ColorMapSplitHelp->Text = L"\?";
			this->ColorMapSplitHelp->UseVisualStyleBackColor = true;
			// 
			// GNormalsTabPage
			// 
			this->GNormalsTabPage->Controls->Add(this->HeightNormalMapCheckBox);
			this->GNormalsTabPage->Controls->Add(this->HeightNormalMapHelp);
			this->GNormalsTabPage->Controls->Add(this->NormalMapCheckBox);
			this->GNormalsTabPage->Controls->Add(this->NormalMapHelp);
			this->GNormalsTabPage->Controls->Add(this->LitColorMapGenerateCheckBox);
			this->GNormalsTabPage->Controls->Add(this->LitColorMapGenerateHelp);
			this->GNormalsTabPage->Controls->Add(this->ColorMapGenerateCheckBox);
			this->GNormalsTabPage->Controls->Add(this->ColorMapGenerateHelp);
			this->GNormalsTabPage->Location = System::Drawing::Point(4, 22);
			this->GNormalsTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GNormalsTabPage->Name = L"GNormalsTabPage";
			this->GNormalsTabPage->Size = System::Drawing::Size(352, 543);
			this->GNormalsTabPage->TabIndex = 4;
			this->GNormalsTabPage->Text = L"Normals";
			this->GNormalsTabPage->UseVisualStyleBackColor = true;
			// 
			// HeightNormalMapCheckBox
			// 
			this->HeightNormalMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->HeightNormalMapCheckBox->Location = System::Drawing::Point(37, 48);
			this->HeightNormalMapCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HeightNormalMapCheckBox->Name = L"HeightNormalMapCheckBox";
			this->HeightNormalMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->HeightNormalMapCheckBox->TabIndex = 87;
			this->HeightNormalMapCheckBox->Text = L"HeightNormalMap:";
			this->HeightNormalMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// HeightNormalMapHelp
			// 
			this->HeightNormalMapHelp->Location = System::Drawing::Point(15, 48);
			this->HeightNormalMapHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HeightNormalMapHelp->Name = L"HeightNormalMapHelp";
			this->HeightNormalMapHelp->Size = System::Drawing::Size(17, 19);
			this->HeightNormalMapHelp->TabIndex = 91;
			this->HeightNormalMapHelp->Text = L"\?";
			this->HeightNormalMapHelp->UseVisualStyleBackColor = true;
			// 
			// NormalMapCheckBox
			// 
			this->NormalMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->NormalMapCheckBox->Location = System::Drawing::Point(37, 24);
			this->NormalMapCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->NormalMapCheckBox->Name = L"NormalMapCheckBox";
			this->NormalMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->NormalMapCheckBox->TabIndex = 86;
			this->NormalMapCheckBox->Text = L"NormalMap:";
			this->NormalMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// NormalMapHelp
			// 
			this->NormalMapHelp->Location = System::Drawing::Point(15, 24);
			this->NormalMapHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->NormalMapHelp->Name = L"NormalMapHelp";
			this->NormalMapHelp->Size = System::Drawing::Size(17, 19);
			this->NormalMapHelp->TabIndex = 90;
			this->NormalMapHelp->Text = L"\?";
			this->NormalMapHelp->UseVisualStyleBackColor = true;
			// 
			// LitColorMapGenerateCheckBox
			// 
			this->LitColorMapGenerateCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->LitColorMapGenerateCheckBox->Location = System::Drawing::Point(37, 95);
			this->LitColorMapGenerateCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->LitColorMapGenerateCheckBox->Name = L"LitColorMapGenerateCheckBox";
			this->LitColorMapGenerateCheckBox->Size = System::Drawing::Size(231, 20);
			this->LitColorMapGenerateCheckBox->TabIndex = 89;
			this->LitColorMapGenerateCheckBox->Text = L"LitColorMapGenerate:";
			this->LitColorMapGenerateCheckBox->UseVisualStyleBackColor = true;
			// 
			// LitColorMapGenerateHelp
			// 
			this->LitColorMapGenerateHelp->Location = System::Drawing::Point(15, 95);
			this->LitColorMapGenerateHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->LitColorMapGenerateHelp->Name = L"LitColorMapGenerateHelp";
			this->LitColorMapGenerateHelp->Size = System::Drawing::Size(17, 19);
			this->LitColorMapGenerateHelp->TabIndex = 93;
			this->LitColorMapGenerateHelp->Text = L"\?";
			this->LitColorMapGenerateHelp->UseVisualStyleBackColor = true;
			// 
			// ColorMapGenerateCheckBox
			// 
			this->ColorMapGenerateCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->ColorMapGenerateCheckBox->Location = System::Drawing::Point(37, 72);
			this->ColorMapGenerateCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ColorMapGenerateCheckBox->Name = L"ColorMapGenerateCheckBox";
			this->ColorMapGenerateCheckBox->Size = System::Drawing::Size(231, 20);
			this->ColorMapGenerateCheckBox->TabIndex = 88;
			this->ColorMapGenerateCheckBox->Text = L"ColorMapGenerate:";
			this->ColorMapGenerateCheckBox->UseVisualStyleBackColor = true;
			// 
			// ColorMapGenerateHelp
			// 
			this->ColorMapGenerateHelp->Location = System::Drawing::Point(15, 72);
			this->ColorMapGenerateHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ColorMapGenerateHelp->Name = L"ColorMapGenerateHelp";
			this->ColorMapGenerateHelp->Size = System::Drawing::Size(17, 19);
			this->ColorMapGenerateHelp->TabIndex = 92;
			this->ColorMapGenerateHelp->Text = L"\?";
			this->ColorMapGenerateHelp->UseVisualStyleBackColor = true;
			// 
			// GSplattingTabPage
			// 
			this->GSplattingTabPage->Controls->Add(this->GSetSplatFileNamesRichTextBox);
			this->GSplattingTabPage->Controls->Add(this->GSetMaterialHeightRichTextBox);
			this->GSplattingTabPage->Controls->Add(this->GSetMaterialHeightLabel);
			this->GSplattingTabPage->Controls->Add(this->GSetMaterialHeightHelp);
			this->GSplattingTabPage->Controls->Add(this->GSetMaterialColorRichTextBox);
			this->GSplattingTabPage->Controls->Add(this->NumMatHeightSplatTextBox);
			this->GSplattingTabPage->Controls->Add(this->NumMatHeightSplatLabel);
			this->GSplattingTabPage->Controls->Add(this->GNumMatHeightSplatHelp);
			this->GSplattingTabPage->Controls->Add(this->GSetSplatFileNamesLabel);
			this->GSplattingTabPage->Controls->Add(this->GSetMaterialColorLabel);
			this->GSplattingTabPage->Controls->Add(this->GSetSplatFileNamesHelp);
			this->GSplattingTabPage->Controls->Add(this->GSetMaterialColorHelp);
			this->GSplattingTabPage->Controls->Add(this->RGBMapsCheckBox);
			this->GSplattingTabPage->Controls->Add(this->RGBMapsHelp);
			this->GSplattingTabPage->Controls->Add(this->AlphaSplatLightMapsCheckBox);
			this->GSplattingTabPage->Controls->Add(this->AlphaSplatLightMapsHelp);
			this->GSplattingTabPage->Controls->Add(this->AlphaSplatRGBAMapsCheckBox);
			this->GSplattingTabPage->Controls->Add(this->AlphaSplatRGBAMapsHelp);
			this->GSplattingTabPage->Controls->Add(this->CoverageMapCheckBox);
			this->GSplattingTabPage->Controls->Add(this->CoverageMapHelp);
			this->GSplattingTabPage->Controls->Add(this->LitBaseMapCheckBox);
			this->GSplattingTabPage->Controls->Add(this->LitBaseMapHelp);
			this->GSplattingTabPage->Controls->Add(this->BaseMapCheckBox);
			this->GSplattingTabPage->Controls->Add(this->BaseMapHelp);
			this->GSplattingTabPage->Controls->Add(this->AvgColorsExistsCheckBox);
			this->GSplattingTabPage->Controls->Add(this->AvgColorsExistsHelp);
			this->GSplattingTabPage->Controls->Add(this->AlphaMapsCheckBox);
			this->GSplattingTabPage->Controls->Add(this->AlphaMapsHelp);
			this->GSplattingTabPage->Location = System::Drawing::Point(4, 22);
			this->GSplattingTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GSplattingTabPage->Name = L"GSplattingTabPage";
			this->GSplattingTabPage->Size = System::Drawing::Size(352, 543);
			this->GSplattingTabPage->TabIndex = 5;
			this->GSplattingTabPage->Text = L"Splatting";
			this->GSplattingTabPage->UseVisualStyleBackColor = true;
			// 
			// GSetSplatFileNamesRichTextBox
			// 
			this->GSetSplatFileNamesRichTextBox->Location = System::Drawing::Point(15, 266);
			this->GSetSplatFileNamesRichTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GSetSplatFileNamesRichTextBox->Name = L"GSetSplatFileNamesRichTextBox";
			this->GSetSplatFileNamesRichTextBox->Size = System::Drawing::Size(326, 58);
			this->GSetSplatFileNamesRichTextBox->TabIndex = 188;
			this->GSetSplatFileNamesRichTextBox->Text = L"#needs to be in maptool directory\nSplatFilename0=splatting_sand.png\nSplatFilename" 
				L"1=splatting_grass.png\nSplatFilename2=splatting_rock.png\nSplatFilename3=splatting" 
				L"_snow.png";
			this->GSetSplatFileNamesRichTextBox->WordWrap = false;
			// 
			// GSetMaterialHeightRichTextBox
			// 
			this->GSetMaterialHeightRichTextBox->Location = System::Drawing::Point(15, 95);
			this->GSetMaterialHeightRichTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GSetMaterialHeightRichTextBox->Name = L"GSetMaterialHeightRichTextBox";
			this->GSetMaterialHeightRichTextBox->Size = System::Drawing::Size(326, 58);
			this->GSetMaterialHeightRichTextBox->TabIndex = 187;
			this->GSetMaterialHeightRichTextBox->Text = L"MaterialHeight0=0\nMaterialHeight1=12\nMaterialHeight2=60\nMaterialHeight3=75";
			this->GSetMaterialHeightRichTextBox->WordWrap = false;
			// 
			// GSetMaterialHeightLabel
			// 
			this->GSetMaterialHeightLabel->AutoSize = true;
			this->GSetMaterialHeightLabel->Location = System::Drawing::Point(37, 74);
			this->GSetMaterialHeightLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GSetMaterialHeightLabel->Name = L"GSetMaterialHeightLabel";
			this->GSetMaterialHeightLabel->Size = System::Drawing::Size(97, 13);
			this->GSetMaterialHeightLabel->TabIndex = 186;
			this->GSetMaterialHeightLabel->Text = L"Set Material Height";
			// 
			// GSetMaterialHeightHelp
			// 
			this->GSetMaterialHeightHelp->Location = System::Drawing::Point(15, 72);
			this->GSetMaterialHeightHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GSetMaterialHeightHelp->Name = L"GSetMaterialHeightHelp";
			this->GSetMaterialHeightHelp->Size = System::Drawing::Size(17, 19);
			this->GSetMaterialHeightHelp->TabIndex = 185;
			this->GSetMaterialHeightHelp->Text = L"\?";
			this->GSetMaterialHeightHelp->UseVisualStyleBackColor = true;
			// 
			// GSetMaterialColorRichTextBox
			// 
			this->GSetMaterialColorRichTextBox->Location = System::Drawing::Point(15, 180);
			this->GSetMaterialColorRichTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GSetMaterialColorRichTextBox->Name = L"GSetMaterialColorRichTextBox";
			this->GSetMaterialColorRichTextBox->Size = System::Drawing::Size(326, 58);
			this->GSetMaterialColorRichTextBox->TabIndex = 184;
			this->GSetMaterialColorRichTextBox->Text = L"#Sand\nMaterialColor0=1.0f 1.0f 0.0f 1.0f\n#Grass\nMaterialColor1=0.13f 0.545f 0.13f" 
				L" 1.0f\n#Rock\nMaterialColor2=0.411764f 0.411764f 0.411764f 1.0f\n#Snow\nMaterialColo" 
				L"r3=1.0f 0.98f 0.98f 1.0f";
			this->GSetMaterialColorRichTextBox->WordWrap = false;
			// 
			// NumMatHeightSplatTextBox
			// 
			this->NumMatHeightSplatTextBox->Location = System::Drawing::Point(183, 48);
			this->NumMatHeightSplatTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->NumMatHeightSplatTextBox->Name = L"NumMatHeightSplatTextBox";
			this->NumMatHeightSplatTextBox->Size = System::Drawing::Size(158, 20);
			this->NumMatHeightSplatTextBox->TabIndex = 183;
			this->NumMatHeightSplatTextBox->Text = L"4";
			// 
			// NumMatHeightSplatLabel
			// 
			this->NumMatHeightSplatLabel->AutoSize = true;
			this->NumMatHeightSplatLabel->Location = System::Drawing::Point(37, 50);
			this->NumMatHeightSplatLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->NumMatHeightSplatLabel->Name = L"NumMatHeightSplatLabel";
			this->NumMatHeightSplatLabel->Size = System::Drawing::Size(105, 13);
			this->NumMatHeightSplatLabel->TabIndex = 182;
			this->NumMatHeightSplatLabel->Text = L"NumMatHeightSplat:";
			// 
			// GNumMatHeightSplatHelp
			// 
			this->GNumMatHeightSplatHelp->Location = System::Drawing::Point(15, 48);
			this->GNumMatHeightSplatHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GNumMatHeightSplatHelp->Name = L"GNumMatHeightSplatHelp";
			this->GNumMatHeightSplatHelp->Size = System::Drawing::Size(17, 19);
			this->GNumMatHeightSplatHelp->TabIndex = 181;
			this->GNumMatHeightSplatHelp->Text = L"\?";
			this->GNumMatHeightSplatHelp->UseVisualStyleBackColor = true;
			// 
			// GSetSplatFileNamesLabel
			// 
			this->GSetSplatFileNamesLabel->AutoSize = true;
			this->GSetSplatFileNamesLabel->Location = System::Drawing::Point(37, 245);
			this->GSetSplatFileNamesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GSetSplatFileNamesLabel->Name = L"GSetSplatFileNamesLabel";
			this->GSetSplatFileNamesLabel->Size = System::Drawing::Size(105, 13);
			this->GSetSplatFileNamesLabel->TabIndex = 180;
			this->GSetSplatFileNamesLabel->Text = L"Set Splat File Names";
			// 
			// GSetMaterialColorLabel
			// 
			this->GSetMaterialColorLabel->AutoSize = true;
			this->GSetMaterialColorLabel->Location = System::Drawing::Point(37, 159);
			this->GSetMaterialColorLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->GSetMaterialColorLabel->Name = L"GSetMaterialColorLabel";
			this->GSetMaterialColorLabel->Size = System::Drawing::Size(90, 13);
			this->GSetMaterialColorLabel->TabIndex = 179;
			this->GSetMaterialColorLabel->Text = L"Set Material Color";
			// 
			// GSetSplatFileNamesHelp
			// 
			this->GSetSplatFileNamesHelp->Location = System::Drawing::Point(15, 242);
			this->GSetSplatFileNamesHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GSetSplatFileNamesHelp->Name = L"GSetSplatFileNamesHelp";
			this->GSetSplatFileNamesHelp->Size = System::Drawing::Size(17, 19);
			this->GSetSplatFileNamesHelp->TabIndex = 176;
			this->GSetSplatFileNamesHelp->Text = L"\?";
			this->GSetSplatFileNamesHelp->UseVisualStyleBackColor = true;
			// 
			// GSetMaterialColorHelp
			// 
			this->GSetMaterialColorHelp->Location = System::Drawing::Point(15, 157);
			this->GSetMaterialColorHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GSetMaterialColorHelp->Name = L"GSetMaterialColorHelp";
			this->GSetMaterialColorHelp->Size = System::Drawing::Size(17, 19);
			this->GSetMaterialColorHelp->TabIndex = 175;
			this->GSetMaterialColorHelp->Text = L"\?";
			this->GSetMaterialColorHelp->UseVisualStyleBackColor = true;
			// 
			// RGBMapsCheckBox
			// 
			this->RGBMapsCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->RGBMapsCheckBox->Location = System::Drawing::Point(37, 469);
			this->RGBMapsCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RGBMapsCheckBox->Name = L"RGBMapsCheckBox";
			this->RGBMapsCheckBox->Size = System::Drawing::Size(231, 20);
			this->RGBMapsCheckBox->TabIndex = 162;
			this->RGBMapsCheckBox->Text = L"RGBMaps:";
			this->RGBMapsCheckBox->UseVisualStyleBackColor = true;
			// 
			// RGBMapsHelp
			// 
			this->RGBMapsHelp->Location = System::Drawing::Point(14, 469);
			this->RGBMapsHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RGBMapsHelp->Name = L"RGBMapsHelp";
			this->RGBMapsHelp->Size = System::Drawing::Size(17, 19);
			this->RGBMapsHelp->TabIndex = 172;
			this->RGBMapsHelp->Text = L"\?";
			this->RGBMapsHelp->UseVisualStyleBackColor = true;
			// 
			// AlphaSplatLightMapsCheckBox
			// 
			this->AlphaSplatLightMapsCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->AlphaSplatLightMapsCheckBox->Location = System::Drawing::Point(37, 446);
			this->AlphaSplatLightMapsCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->AlphaSplatLightMapsCheckBox->Name = L"AlphaSplatLightMapsCheckBox";
			this->AlphaSplatLightMapsCheckBox->Size = System::Drawing::Size(231, 20);
			this->AlphaSplatLightMapsCheckBox->TabIndex = 161;
			this->AlphaSplatLightMapsCheckBox->Text = L"AlphaSplatLightMaps:";
			this->AlphaSplatLightMapsCheckBox->UseVisualStyleBackColor = true;
			// 
			// AlphaSplatLightMapsHelp
			// 
			this->AlphaSplatLightMapsHelp->Location = System::Drawing::Point(14, 445);
			this->AlphaSplatLightMapsHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->AlphaSplatLightMapsHelp->Name = L"AlphaSplatLightMapsHelp";
			this->AlphaSplatLightMapsHelp->Size = System::Drawing::Size(17, 19);
			this->AlphaSplatLightMapsHelp->TabIndex = 171;
			this->AlphaSplatLightMapsHelp->Text = L"\?";
			this->AlphaSplatLightMapsHelp->UseVisualStyleBackColor = true;
			// 
			// AlphaSplatRGBAMapsCheckBox
			// 
			this->AlphaSplatRGBAMapsCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->AlphaSplatRGBAMapsCheckBox->Location = System::Drawing::Point(37, 422);
			this->AlphaSplatRGBAMapsCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->AlphaSplatRGBAMapsCheckBox->Name = L"AlphaSplatRGBAMapsCheckBox";
			this->AlphaSplatRGBAMapsCheckBox->Size = System::Drawing::Size(231, 20);
			this->AlphaSplatRGBAMapsCheckBox->TabIndex = 160;
			this->AlphaSplatRGBAMapsCheckBox->Text = L"AlphaSplatRGBAMaps:";
			this->AlphaSplatRGBAMapsCheckBox->UseVisualStyleBackColor = true;
			// 
			// AlphaSplatRGBAMapsHelp
			// 
			this->AlphaSplatRGBAMapsHelp->Location = System::Drawing::Point(14, 422);
			this->AlphaSplatRGBAMapsHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->AlphaSplatRGBAMapsHelp->Name = L"AlphaSplatRGBAMapsHelp";
			this->AlphaSplatRGBAMapsHelp->Size = System::Drawing::Size(17, 19);
			this->AlphaSplatRGBAMapsHelp->TabIndex = 170;
			this->AlphaSplatRGBAMapsHelp->Text = L"\?";
			this->AlphaSplatRGBAMapsHelp->UseVisualStyleBackColor = true;
			// 
			// CoverageMapCheckBox
			// 
			this->CoverageMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->CoverageMapCheckBox->Location = System::Drawing::Point(37, 375);
			this->CoverageMapCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->CoverageMapCheckBox->Name = L"CoverageMapCheckBox";
			this->CoverageMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->CoverageMapCheckBox->TabIndex = 158;
			this->CoverageMapCheckBox->Text = L"CoverageMap:";
			this->CoverageMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// CoverageMapHelp
			// 
			this->CoverageMapHelp->Location = System::Drawing::Point(15, 375);
			this->CoverageMapHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->CoverageMapHelp->Name = L"CoverageMapHelp";
			this->CoverageMapHelp->Size = System::Drawing::Size(17, 19);
			this->CoverageMapHelp->TabIndex = 168;
			this->CoverageMapHelp->Text = L"\?";
			this->CoverageMapHelp->UseVisualStyleBackColor = true;
			// 
			// LitBaseMapCheckBox
			// 
			this->LitBaseMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->LitBaseMapCheckBox->Location = System::Drawing::Point(37, 351);
			this->LitBaseMapCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->LitBaseMapCheckBox->Name = L"LitBaseMapCheckBox";
			this->LitBaseMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->LitBaseMapCheckBox->TabIndex = 157;
			this->LitBaseMapCheckBox->Text = L"LitBaseMap:";
			this->LitBaseMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// LitBaseMapHelp
			// 
			this->LitBaseMapHelp->Location = System::Drawing::Point(15, 351);
			this->LitBaseMapHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->LitBaseMapHelp->Name = L"LitBaseMapHelp";
			this->LitBaseMapHelp->Size = System::Drawing::Size(17, 19);
			this->LitBaseMapHelp->TabIndex = 167;
			this->LitBaseMapHelp->Text = L"\?";
			this->LitBaseMapHelp->UseVisualStyleBackColor = true;
			// 
			// BaseMapCheckBox
			// 
			this->BaseMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->BaseMapCheckBox->Location = System::Drawing::Point(37, 327);
			this->BaseMapCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaseMapCheckBox->Name = L"BaseMapCheckBox";
			this->BaseMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->BaseMapCheckBox->TabIndex = 156;
			this->BaseMapCheckBox->Text = L"BaseMap:";
			this->BaseMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// BaseMapHelp
			// 
			this->BaseMapHelp->Location = System::Drawing::Point(15, 327);
			this->BaseMapHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaseMapHelp->Name = L"BaseMapHelp";
			this->BaseMapHelp->Size = System::Drawing::Size(17, 19);
			this->BaseMapHelp->TabIndex = 166;
			this->BaseMapHelp->Text = L"\?";
			this->BaseMapHelp->UseVisualStyleBackColor = true;
			// 
			// AvgColorsExistsCheckBox
			// 
			this->AvgColorsExistsCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->AvgColorsExistsCheckBox->Checked = true;
			this->AvgColorsExistsCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->AvgColorsExistsCheckBox->Location = System::Drawing::Point(37, 24);
			this->AvgColorsExistsCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->AvgColorsExistsCheckBox->Name = L"AvgColorsExistsCheckBox";
			this->AvgColorsExistsCheckBox->Size = System::Drawing::Size(231, 20);
			this->AvgColorsExistsCheckBox->TabIndex = 155;
			this->AvgColorsExistsCheckBox->Text = L"AvgColorsExists:";
			this->AvgColorsExistsCheckBox->UseVisualStyleBackColor = true;
			// 
			// AvgColorsExistsHelp
			// 
			this->AvgColorsExistsHelp->Location = System::Drawing::Point(15, 24);
			this->AvgColorsExistsHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->AvgColorsExistsHelp->Name = L"AvgColorsExistsHelp";
			this->AvgColorsExistsHelp->Size = System::Drawing::Size(17, 19);
			this->AvgColorsExistsHelp->TabIndex = 165;
			this->AvgColorsExistsHelp->Text = L"\?";
			this->AvgColorsExistsHelp->UseVisualStyleBackColor = true;
			// 
			// AlphaMapsCheckBox
			// 
			this->AlphaMapsCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->AlphaMapsCheckBox->Location = System::Drawing::Point(37, 398);
			this->AlphaMapsCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->AlphaMapsCheckBox->Name = L"AlphaMapsCheckBox";
			this->AlphaMapsCheckBox->Size = System::Drawing::Size(231, 20);
			this->AlphaMapsCheckBox->TabIndex = 159;
			this->AlphaMapsCheckBox->Text = L"AlphaMaps:";
			this->AlphaMapsCheckBox->UseVisualStyleBackColor = true;
			// 
			// AlphaMapsHelp
			// 
			this->AlphaMapsHelp->Location = System::Drawing::Point(15, 398);
			this->AlphaMapsHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->AlphaMapsHelp->Name = L"AlphaMapsHelp";
			this->AlphaMapsHelp->Size = System::Drawing::Size(17, 19);
			this->AlphaMapsHelp->TabIndex = 169;
			this->AlphaMapsHelp->Text = L"\?";
			this->AlphaMapsHelp->UseVisualStyleBackColor = true;
			// 
			// GLightingTabPage
			// 
			this->GLightingTabPage->Controls->Add(this->PVSMapCheckBox);
			this->GLightingTabPage->Controls->Add(this->PVSMapHelp);
			this->GLightingTabPage->Controls->Add(this->VisibilityLabel);
			this->GLightingTabPage->Controls->Add(this->ZHorizonCheckBox);
			this->GLightingTabPage->Controls->Add(this->ZHorizonHelp);
			this->GLightingTabPage->Controls->Add(this->ElevationMapCheckBox);
			this->GLightingTabPage->Controls->Add(this->ElevationMapHelp);
			this->GLightingTabPage->Controls->Add(this->HorizonMapCheckBox);
			this->GLightingTabPage->Controls->Add(this->HorizonMapHelp);
			this->GLightingTabPage->Controls->Add(this->RealTimeLightingLabel);
			this->GLightingTabPage->Controls->Add(this->BlurTextBox);
			this->GLightingTabPage->Controls->Add(this->BlurLabel);
			this->GLightingTabPage->Controls->Add(this->BlurHelp);
			this->GLightingTabPage->Controls->Add(this->DiffuseTextBox);
			this->GLightingTabPage->Controls->Add(this->DiffuseLabel);
			this->GLightingTabPage->Controls->Add(this->DiffuseHelp);
			this->GLightingTabPage->Controls->Add(this->AmbientTextBox);
			this->GLightingTabPage->Controls->Add(this->AmbientLabel);
			this->GLightingTabPage->Controls->Add(this->AmbientHelp);
			this->GLightingTabPage->Controls->Add(this->SunzTextBox);
			this->GLightingTabPage->Controls->Add(this->SunzLabel);
			this->GLightingTabPage->Controls->Add(this->SunzHelp);
			this->GLightingTabPage->Controls->Add(this->SunyTextBox);
			this->GLightingTabPage->Controls->Add(this->SunyLabel);
			this->GLightingTabPage->Controls->Add(this->SunyHelp);
			this->GLightingTabPage->Controls->Add(this->ShadowMapCheckBox);
			this->GLightingTabPage->Controls->Add(this->ShadowMapHelp);
			this->GLightingTabPage->Controls->Add(this->LightMapCheckBox);
			this->GLightingTabPage->Controls->Add(this->LightMapHelp);
			this->GLightingTabPage->Controls->Add(this->SunxTextBox);
			this->GLightingTabPage->Controls->Add(this->SunxLabel);
			this->GLightingTabPage->Controls->Add(this->SunxHelp);
			this->GLightingTabPage->Controls->Add(this->LightingLabel);
			this->GLightingTabPage->Location = System::Drawing::Point(4, 22);
			this->GLightingTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GLightingTabPage->Name = L"GLightingTabPage";
			this->GLightingTabPage->Size = System::Drawing::Size(352, 543);
			this->GLightingTabPage->TabIndex = 6;
			this->GLightingTabPage->Text = L"Lighting";
			this->GLightingTabPage->UseVisualStyleBackColor = true;
			// 
			// PVSMapCheckBox
			// 
			this->PVSMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->PVSMapCheckBox->Location = System::Drawing::Point(35, 332);
			this->PVSMapCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->PVSMapCheckBox->Name = L"PVSMapCheckBox";
			this->PVSMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->PVSMapCheckBox->TabIndex = 158;
			this->PVSMapCheckBox->Text = L"PVSMap:";
			this->PVSMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// PVSMapHelp
			// 
			this->PVSMapHelp->Location = System::Drawing::Point(14, 332);
			this->PVSMapHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->PVSMapHelp->Name = L"PVSMapHelp";
			this->PVSMapHelp->Size = System::Drawing::Size(17, 19);
			this->PVSMapHelp->TabIndex = 170;
			this->PVSMapHelp->Text = L"\?";
			this->PVSMapHelp->UseVisualStyleBackColor = true;
			// 
			// VisibilityLabel
			// 
			this->VisibilityLabel->AutoSize = true;
			this->VisibilityLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->VisibilityLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->VisibilityLabel->Location = System::Drawing::Point(14, 314);
			this->VisibilityLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->VisibilityLabel->Name = L"VisibilityLabel";
			this->VisibilityLabel->Size = System::Drawing::Size(45, 15);
			this->VisibilityLabel->TabIndex = 179;
			this->VisibilityLabel->Text = L"Visibility";
			// 
			// ZHorizonCheckBox
			// 
			this->ZHorizonCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->ZHorizonCheckBox->Location = System::Drawing::Point(35, 293);
			this->ZHorizonCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ZHorizonCheckBox->Name = L"ZHorizonCheckBox";
			this->ZHorizonCheckBox->Size = System::Drawing::Size(231, 20);
			this->ZHorizonCheckBox->TabIndex = 157;
			this->ZHorizonCheckBox->Text = L"ZHorizon:";
			this->ZHorizonCheckBox->UseVisualStyleBackColor = true;
			// 
			// ZHorizonHelp
			// 
			this->ZHorizonHelp->Location = System::Drawing::Point(14, 293);
			this->ZHorizonHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ZHorizonHelp->Name = L"ZHorizonHelp";
			this->ZHorizonHelp->Size = System::Drawing::Size(17, 19);
			this->ZHorizonHelp->TabIndex = 169;
			this->ZHorizonHelp->Text = L"\?";
			this->ZHorizonHelp->UseVisualStyleBackColor = true;
			// 
			// ElevationMapCheckBox
			// 
			this->ElevationMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->ElevationMapCheckBox->Location = System::Drawing::Point(35, 270);
			this->ElevationMapCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ElevationMapCheckBox->Name = L"ElevationMapCheckBox";
			this->ElevationMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->ElevationMapCheckBox->TabIndex = 156;
			this->ElevationMapCheckBox->Text = L"ElevationMap:";
			this->ElevationMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// ElevationMapHelp
			// 
			this->ElevationMapHelp->Location = System::Drawing::Point(14, 270);
			this->ElevationMapHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ElevationMapHelp->Name = L"ElevationMapHelp";
			this->ElevationMapHelp->Size = System::Drawing::Size(17, 19);
			this->ElevationMapHelp->TabIndex = 168;
			this->ElevationMapHelp->Text = L"\?";
			this->ElevationMapHelp->UseVisualStyleBackColor = true;
			// 
			// HorizonMapCheckBox
			// 
			this->HorizonMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->HorizonMapCheckBox->Location = System::Drawing::Point(35, 246);
			this->HorizonMapCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HorizonMapCheckBox->Name = L"HorizonMapCheckBox";
			this->HorizonMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->HorizonMapCheckBox->TabIndex = 155;
			this->HorizonMapCheckBox->Text = L"HorizonMap:";
			this->HorizonMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// HorizonMapHelp
			// 
			this->HorizonMapHelp->Location = System::Drawing::Point(14, 246);
			this->HorizonMapHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HorizonMapHelp->Name = L"HorizonMapHelp";
			this->HorizonMapHelp->Size = System::Drawing::Size(17, 19);
			this->HorizonMapHelp->TabIndex = 167;
			this->HorizonMapHelp->Text = L"\?";
			this->HorizonMapHelp->UseVisualStyleBackColor = true;
			// 
			// RealTimeLightingLabel
			// 
			this->RealTimeLightingLabel->AutoSize = true;
			this->RealTimeLightingLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->RealTimeLightingLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->RealTimeLightingLabel->Location = System::Drawing::Point(14, 228);
			this->RealTimeLightingLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RealTimeLightingLabel->Name = L"RealTimeLightingLabel";
			this->RealTimeLightingLabel->Size = System::Drawing::Size(97, 15);
			this->RealTimeLightingLabel->TabIndex = 178;
			this->RealTimeLightingLabel->Text = L"Real-Time Lighting";
			// 
			// BlurTextBox
			// 
			this->BlurTextBox->Location = System::Drawing::Point(182, 207);
			this->BlurTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BlurTextBox->Name = L"BlurTextBox";
			this->BlurTextBox->Size = System::Drawing::Size(159, 20);
			this->BlurTextBox->TabIndex = 154;
			this->BlurTextBox->Text = L"0.5f";
			// 
			// BlurLabel
			// 
			this->BlurLabel->AutoSize = true;
			this->BlurLabel->Location = System::Drawing::Point(36, 210);
			this->BlurLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->BlurLabel->Name = L"BlurLabel";
			this->BlurLabel->Size = System::Drawing::Size(28, 13);
			this->BlurLabel->TabIndex = 177;
			this->BlurLabel->Text = L"Blur:";
			// 
			// BlurHelp
			// 
			this->BlurHelp->Location = System::Drawing::Point(14, 207);
			this->BlurHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BlurHelp->Name = L"BlurHelp";
			this->BlurHelp->Size = System::Drawing::Size(17, 19);
			this->BlurHelp->TabIndex = 166;
			this->BlurHelp->Text = L"\?";
			this->BlurHelp->UseVisualStyleBackColor = true;
			// 
			// DiffuseTextBox
			// 
			this->DiffuseTextBox->Location = System::Drawing::Point(182, 184);
			this->DiffuseTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->DiffuseTextBox->Name = L"DiffuseTextBox";
			this->DiffuseTextBox->Size = System::Drawing::Size(159, 20);
			this->DiffuseTextBox->TabIndex = 153;
			this->DiffuseTextBox->Text = L"0.5f";
			// 
			// DiffuseLabel
			// 
			this->DiffuseLabel->AutoSize = true;
			this->DiffuseLabel->Location = System::Drawing::Point(36, 186);
			this->DiffuseLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->DiffuseLabel->Name = L"DiffuseLabel";
			this->DiffuseLabel->Size = System::Drawing::Size(43, 13);
			this->DiffuseLabel->TabIndex = 176;
			this->DiffuseLabel->Text = L"Diffuse:";
			// 
			// DiffuseHelp
			// 
			this->DiffuseHelp->Location = System::Drawing::Point(14, 184);
			this->DiffuseHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->DiffuseHelp->Name = L"DiffuseHelp";
			this->DiffuseHelp->Size = System::Drawing::Size(17, 19);
			this->DiffuseHelp->TabIndex = 165;
			this->DiffuseHelp->Text = L"\?";
			this->DiffuseHelp->UseVisualStyleBackColor = true;
			// 
			// AmbientTextBox
			// 
			this->AmbientTextBox->Location = System::Drawing::Point(183, 160);
			this->AmbientTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->AmbientTextBox->Name = L"AmbientTextBox";
			this->AmbientTextBox->Size = System::Drawing::Size(159, 20);
			this->AmbientTextBox->TabIndex = 152;
			this->AmbientTextBox->Text = L"0.5f";
			// 
			// AmbientLabel
			// 
			this->AmbientLabel->AutoSize = true;
			this->AmbientLabel->Location = System::Drawing::Point(37, 162);
			this->AmbientLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->AmbientLabel->Name = L"AmbientLabel";
			this->AmbientLabel->Size = System::Drawing::Size(48, 13);
			this->AmbientLabel->TabIndex = 175;
			this->AmbientLabel->Text = L"Ambient:";
			// 
			// AmbientHelp
			// 
			this->AmbientHelp->Location = System::Drawing::Point(15, 160);
			this->AmbientHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->AmbientHelp->Name = L"AmbientHelp";
			this->AmbientHelp->Size = System::Drawing::Size(17, 19);
			this->AmbientHelp->TabIndex = 164;
			this->AmbientHelp->Text = L"\?";
			this->AmbientHelp->UseVisualStyleBackColor = true;
			// 
			// SunzTextBox
			// 
			this->SunzTextBox->Location = System::Drawing::Point(182, 136);
			this->SunzTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->SunzTextBox->Name = L"SunzTextBox";
			this->SunzTextBox->Size = System::Drawing::Size(159, 20);
			this->SunzTextBox->TabIndex = 151;
			this->SunzTextBox->Text = L"0.47f";
			// 
			// SunzLabel
			// 
			this->SunzLabel->AutoSize = true;
			this->SunzLabel->Location = System::Drawing::Point(36, 139);
			this->SunzLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->SunzLabel->Name = L"SunzLabel";
			this->SunzLabel->Size = System::Drawing::Size(34, 13);
			this->SunzLabel->TabIndex = 174;
			this->SunzLabel->Text = L"Sunz:";
			// 
			// SunzHelp
			// 
			this->SunzHelp->Location = System::Drawing::Point(14, 136);
			this->SunzHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->SunzHelp->Name = L"SunzHelp";
			this->SunzHelp->Size = System::Drawing::Size(17, 19);
			this->SunzHelp->TabIndex = 163;
			this->SunzHelp->Text = L"\?";
			this->SunzHelp->UseVisualStyleBackColor = true;
			// 
			// SunyTextBox
			// 
			this->SunyTextBox->Location = System::Drawing::Point(182, 113);
			this->SunyTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->SunyTextBox->Name = L"SunyTextBox";
			this->SunyTextBox->Size = System::Drawing::Size(159, 20);
			this->SunyTextBox->TabIndex = 150;
			this->SunyTextBox->Text = L"0.88f";
			// 
			// SunyLabel
			// 
			this->SunyLabel->AutoSize = true;
			this->SunyLabel->Location = System::Drawing::Point(36, 115);
			this->SunyLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->SunyLabel->Name = L"SunyLabel";
			this->SunyLabel->Size = System::Drawing::Size(34, 13);
			this->SunyLabel->TabIndex = 173;
			this->SunyLabel->Text = L"Suny:";
			// 
			// SunyHelp
			// 
			this->SunyHelp->Location = System::Drawing::Point(14, 113);
			this->SunyHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->SunyHelp->Name = L"SunyHelp";
			this->SunyHelp->Size = System::Drawing::Size(17, 19);
			this->SunyHelp->TabIndex = 162;
			this->SunyHelp->Text = L"\?";
			this->SunyHelp->UseVisualStyleBackColor = true;
			// 
			// ShadowMapCheckBox
			// 
			this->ShadowMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->ShadowMapCheckBox->Location = System::Drawing::Point(35, 66);
			this->ShadowMapCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ShadowMapCheckBox->Name = L"ShadowMapCheckBox";
			this->ShadowMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->ShadowMapCheckBox->TabIndex = 148;
			this->ShadowMapCheckBox->Text = L"ShadowMap:";
			this->ShadowMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// ShadowMapHelp
			// 
			this->ShadowMapHelp->Location = System::Drawing::Point(14, 66);
			this->ShadowMapHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ShadowMapHelp->Name = L"ShadowMapHelp";
			this->ShadowMapHelp->Size = System::Drawing::Size(17, 19);
			this->ShadowMapHelp->TabIndex = 160;
			this->ShadowMapHelp->Text = L"\?";
			this->ShadowMapHelp->UseVisualStyleBackColor = true;
			// 
			// LightMapCheckBox
			// 
			this->LightMapCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->LightMapCheckBox->Location = System::Drawing::Point(35, 42);
			this->LightMapCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->LightMapCheckBox->Name = L"LightMapCheckBox";
			this->LightMapCheckBox->Size = System::Drawing::Size(231, 20);
			this->LightMapCheckBox->TabIndex = 147;
			this->LightMapCheckBox->Text = L"LightMap:";
			this->LightMapCheckBox->UseVisualStyleBackColor = true;
			// 
			// LightMapHelp
			// 
			this->LightMapHelp->Location = System::Drawing::Point(14, 42);
			this->LightMapHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->LightMapHelp->Name = L"LightMapHelp";
			this->LightMapHelp->Size = System::Drawing::Size(17, 19);
			this->LightMapHelp->TabIndex = 159;
			this->LightMapHelp->Text = L"\?";
			this->LightMapHelp->UseVisualStyleBackColor = true;
			// 
			// SunxTextBox
			// 
			this->SunxTextBox->Location = System::Drawing::Point(182, 89);
			this->SunxTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->SunxTextBox->Name = L"SunxTextBox";
			this->SunxTextBox->Size = System::Drawing::Size(159, 20);
			this->SunxTextBox->TabIndex = 149;
			this->SunxTextBox->Text = L"0.0f";
			// 
			// SunxLabel
			// 
			this->SunxLabel->AutoSize = true;
			this->SunxLabel->Location = System::Drawing::Point(36, 92);
			this->SunxLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->SunxLabel->Name = L"SunxLabel";
			this->SunxLabel->Size = System::Drawing::Size(34, 13);
			this->SunxLabel->TabIndex = 172;
			this->SunxLabel->Text = L"Sunx:";
			// 
			// SunxHelp
			// 
			this->SunxHelp->Location = System::Drawing::Point(14, 89);
			this->SunxHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->SunxHelp->Name = L"SunxHelp";
			this->SunxHelp->Size = System::Drawing::Size(17, 19);
			this->SunxHelp->TabIndex = 161;
			this->SunxHelp->Text = L"\?";
			this->SunxHelp->UseVisualStyleBackColor = true;
			// 
			// LightingLabel
			// 
			this->LightingLabel->AutoSize = true;
			this->LightingLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LightingLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->LightingLabel->Location = System::Drawing::Point(15, 24);
			this->LightingLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->LightingLabel->Name = L"LightingLabel";
			this->LightingLabel->Size = System::Drawing::Size(46, 15);
			this->LightingLabel->TabIndex = 171;
			this->LightingLabel->Text = L"Lighting";
			// 
			// MapSplitterTabPage
			// 
			this->MapSplitterTabPage->Controls->Add(this->MapSplitterStatusTextBox);
			this->MapSplitterTabPage->Controls->Add(this->MaptoolLabel);
			this->MapSplitterTabPage->Controls->Add(this->MapToolRichTextBox);
			this->MapSplitterTabPage->Controls->Add(this->RunMapsplitterButton);
			this->MapSplitterTabPage->Location = System::Drawing::Point(4, 22);
			this->MapSplitterTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MapSplitterTabPage->Name = L"MapSplitterTabPage";
			this->MapSplitterTabPage->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MapSplitterTabPage->Size = System::Drawing::Size(367, 717);
			this->MapSplitterTabPage->TabIndex = 1;
			this->MapSplitterTabPage->Text = L"Step 2: Map Splitter";
			this->MapSplitterTabPage->UseVisualStyleBackColor = true;
			// 
			// MapSplitterStatusTextBox
			// 
			this->MapSplitterStatusTextBox->Location = System::Drawing::Point(4, 697);
			this->MapSplitterStatusTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MapSplitterStatusTextBox->Name = L"MapSplitterStatusTextBox";
			this->MapSplitterStatusTextBox->ReadOnly = true;
			this->MapSplitterStatusTextBox->Size = System::Drawing::Size(361, 20);
			this->MapSplitterStatusTextBox->TabIndex = 7;
			// 
			// MaptoolLabel
			// 
			this->MaptoolLabel->AutoSize = true;
			this->MaptoolLabel->Location = System::Drawing::Point(5, 36);
			this->MaptoolLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->MaptoolLabel->Name = L"MaptoolLabel";
			this->MaptoolLabel->Size = System::Drawing::Size(118, 13);
			this->MaptoolLabel->TabIndex = 6;
			this->MaptoolLabel->Text = L"Generated maptool.cfg:";
			// 
			// MapToolRichTextBox
			// 
			this->MapToolRichTextBox->Location = System::Drawing::Point(4, 54);
			this->MapToolRichTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MapToolRichTextBox->Name = L"MapToolRichTextBox";
			this->MapToolRichTextBox->Size = System::Drawing::Size(361, 615);
			this->MapToolRichTextBox->TabIndex = 5;
			this->MapToolRichTextBox->Text = L"";
			// 
			// RunMapsplitterButton
			// 
			this->RunMapsplitterButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->RunMapsplitterButton->Location = System::Drawing::Point(4, 674);
			this->RunMapsplitterButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RunMapsplitterButton->Name = L"RunMapsplitterButton";
			this->RunMapsplitterButton->Size = System::Drawing::Size(360, 19);
			this->RunMapsplitterButton->TabIndex = 4;
			this->RunMapsplitterButton->Text = L"Run Mapsplitter";
			this->RunMapsplitterButton->UseVisualStyleBackColor = true;
			this->RunMapsplitterButton->Click += gcnew System::EventHandler(this, &BaseForm::RunMapsplitterButton_Click);
			// 
			// RunTimeTabPage
			// 
			this->RunTimeTabPage->Controls->Add(this->CreateRunTimeCFGButton);
			this->RunTimeTabPage->Controls->Add(this->EditRunTimeCFGButton);
			this->RunTimeTabPage->Controls->Add(this->RColorMapTextBox);
			this->RunTimeTabPage->Controls->Add(this->RHeightMapTextBox);
			this->RunTimeTabPage->Controls->Add(this->ColorMapSourceHelp);
			this->RunTimeTabPage->Controls->Add(this->HeightMapSourceHelp);
			this->RunTimeTabPage->Controls->Add(this->ColorMapSourceLabel);
			this->RunTimeTabPage->Controls->Add(this->HeightMapSourceLabel);
			this->RunTimeTabPage->Controls->Add(this->tabControl1);
			this->RunTimeTabPage->Controls->Add(this->RunTimeLabel);
			this->RunTimeTabPage->Controls->Add(this->RSetDefaultsButton);
			this->RunTimeTabPage->Controls->Add(this->RTerrainNameTextBox);
			this->RunTimeTabPage->Controls->Add(this->TerrainNameRLabel);
			this->RunTimeTabPage->Location = System::Drawing::Point(4, 22);
			this->RunTimeTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RunTimeTabPage->Name = L"RunTimeTabPage";
			this->RunTimeTabPage->Size = System::Drawing::Size(367, 717);
			this->RunTimeTabPage->TabIndex = 2;
			this->RunTimeTabPage->Text = L"Step 3: Terrain Run Time";
			this->RunTimeTabPage->UseVisualStyleBackColor = true;
			// 
			// CreateRunTimeCFGButton
			// 
			this->CreateRunTimeCFGButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->CreateRunTimeCFGButton->Location = System::Drawing::Point(4, 671);
			this->CreateRunTimeCFGButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->CreateRunTimeCFGButton->Name = L"CreateRunTimeCFGButton";
			this->CreateRunTimeCFGButton->Size = System::Drawing::Size(357, 19);
			this->CreateRunTimeCFGButton->TabIndex = 173;
			this->CreateRunTimeCFGButton->Text = L"Create Terrain Run Time CFG File";
			this->CreateRunTimeCFGButton->UseVisualStyleBackColor = true;
			this->CreateRunTimeCFGButton->Click += gcnew System::EventHandler(this, &BaseForm::CreateRunTimeCFGButton_Click);
			// 
			// EditRunTimeCFGButton
			// 
			this->EditRunTimeCFGButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->EditRunTimeCFGButton->Enabled = false;
			this->EditRunTimeCFGButton->Location = System::Drawing::Point(4, 695);
			this->EditRunTimeCFGButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->EditRunTimeCFGButton->Name = L"EditRunTimeCFGButton";
			this->EditRunTimeCFGButton->Size = System::Drawing::Size(357, 19);
			this->EditRunTimeCFGButton->TabIndex = 172;
			this->EditRunTimeCFGButton->Text = L"Edit Run Time CFG File";
			this->EditRunTimeCFGButton->UseVisualStyleBackColor = true;
			this->EditRunTimeCFGButton->Click += gcnew System::EventHandler(this, &BaseForm::EditRunTimeCFGButton_Click);
			// 
			// RColorMapTextBox
			// 
			this->RColorMapTextBox->Location = System::Drawing::Point(179, 69);
			this->RColorMapTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RColorMapTextBox->Name = L"RColorMapTextBox";
			this->RColorMapTextBox->ReadOnly = true;
			this->RColorMapTextBox->Size = System::Drawing::Size(182, 20);
			this->RColorMapTextBox->TabIndex = 171;
			// 
			// RHeightMapTextBox
			// 
			this->RHeightMapTextBox->Location = System::Drawing::Point(179, 46);
			this->RHeightMapTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RHeightMapTextBox->Name = L"RHeightMapTextBox";
			this->RHeightMapTextBox->ReadOnly = true;
			this->RHeightMapTextBox->Size = System::Drawing::Size(182, 20);
			this->RHeightMapTextBox->TabIndex = 170;
			// 
			// ColorMapSourceHelp
			// 
			this->ColorMapSourceHelp->Location = System::Drawing::Point(8, 69);
			this->ColorMapSourceHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ColorMapSourceHelp->Name = L"ColorMapSourceHelp";
			this->ColorMapSourceHelp->Size = System::Drawing::Size(17, 19);
			this->ColorMapSourceHelp->TabIndex = 169;
			this->ColorMapSourceHelp->Text = L"\?";
			this->ColorMapSourceHelp->UseVisualStyleBackColor = true;
			// 
			// HeightMapSourceHelp
			// 
			this->HeightMapSourceHelp->Location = System::Drawing::Point(8, 46);
			this->HeightMapSourceHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HeightMapSourceHelp->Name = L"HeightMapSourceHelp";
			this->HeightMapSourceHelp->Size = System::Drawing::Size(17, 19);
			this->HeightMapSourceHelp->TabIndex = 168;
			this->HeightMapSourceHelp->Text = L"\?";
			this->HeightMapSourceHelp->UseVisualStyleBackColor = true;
			// 
			// ColorMapSourceLabel
			// 
			this->ColorMapSourceLabel->AutoSize = true;
			this->ColorMapSourceLabel->Location = System::Drawing::Point(29, 72);
			this->ColorMapSourceLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ColorMapSourceLabel->Name = L"ColorMapSourceLabel";
			this->ColorMapSourceLabel->Size = System::Drawing::Size(92, 13);
			this->ColorMapSourceLabel->TabIndex = 167;
			this->ColorMapSourceLabel->Text = L"ColorMap Source:";
			// 
			// HeightMapSourceLabel
			// 
			this->HeightMapSourceLabel->AutoSize = true;
			this->HeightMapSourceLabel->Location = System::Drawing::Point(29, 48);
			this->HeightMapSourceLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->HeightMapSourceLabel->Name = L"HeightMapSourceLabel";
			this->HeightMapSourceLabel->Size = System::Drawing::Size(99, 13);
			this->HeightMapSourceLabel->TabIndex = 166;
			this->HeightMapSourceLabel->Text = L"HeightMap Source:";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->RGeneralTabPage);
			this->tabControl1->Controls->Add(this->RPagingTabPage);
			this->tabControl1->Controls->Add(this->RPropertiesTabPage);
			this->tabControl1->Controls->Add(this->RLightingTabPage);
			this->tabControl1->Controls->Add(this->RTextureTabPage);
			this->tabControl1->Controls->Add(this->RPerformanceTabPage);
			this->tabControl1->Controls->Add(this->RCameraTabPage);
			this->tabControl1->Location = System::Drawing::Point(4, 98);
			this->tabControl1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(360, 569);
			this->tabControl1->TabIndex = 162;
			// 
			// RGeneralTabPage
			// 
			this->RGeneralTabPage->Controls->Add(this->RColorMapFileNameTextBox);
			this->RGeneralTabPage->Controls->Add(this->RColorMapFileNameLabel);
			this->RGeneralTabPage->Controls->Add(this->ColorMapFileNameRHelp);
			this->RGeneralTabPage->Controls->Add(this->RColorMapExtensionTextBox);
			this->RGeneralTabPage->Controls->Add(this->RColorMapExtensionLabel);
			this->RGeneralTabPage->Controls->Add(this->ColorMapExtensionRHelp);
			this->RGeneralTabPage->Controls->Add(this->RHeightMapExtensionTextBox);
			this->RGeneralTabPage->Controls->Add(this->RHeightMapExtensionLabel);
			this->RGeneralTabPage->Controls->Add(this->HeightMapExtensionRHelp);
			this->RGeneralTabPage->Controls->Add(this->RHeightMapFileNameTextBox);
			this->RGeneralTabPage->Controls->Add(this->HeightMapFileNameRHelp);
			this->RGeneralTabPage->Controls->Add(this->RHeightMapFileNameLabel);
			this->RGeneralTabPage->Controls->Add(this->FormatTextBox);
			this->RGeneralTabPage->Controls->Add(this->FormatLabel);
			this->RGeneralTabPage->Controls->Add(this->ResourceFormatComboBox);
			this->RGeneralTabPage->Controls->Add(this->ResourceFormatLabel);
			this->RGeneralTabPage->Controls->Add(this->ResourceFormatHelp);
			this->RGeneralTabPage->Controls->Add(this->GroupNameRHelp);
			this->RGeneralTabPage->Controls->Add(this->RGroupNameTextBox);
			this->RGeneralTabPage->Controls->Add(this->RGroupNameLabel);
			this->RGeneralTabPage->Location = System::Drawing::Point(3, 20);
			this->RGeneralTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RGeneralTabPage->Name = L"RGeneralTabPage";
			this->RGeneralTabPage->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RGeneralTabPage->Size = System::Drawing::Size(354, 545);
			this->RGeneralTabPage->TabIndex = 0;
			this->RGeneralTabPage->Text = L"General";
			this->RGeneralTabPage->UseVisualStyleBackColor = true;
			// 
			// RColorMapFileNameTextBox
			// 
			this->RColorMapFileNameTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->RColorMapFileNameTextBox->Location = System::Drawing::Point(188, 142);
			this->RColorMapFileNameTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RColorMapFileNameTextBox->Name = L"RColorMapFileNameTextBox";
			this->RColorMapFileNameTextBox->ReadOnly = true;
			this->RColorMapFileNameTextBox->Size = System::Drawing::Size(145, 20);
			this->RColorMapFileNameTextBox->TabIndex = 351;
			this->RColorMapFileNameTextBox->Text = L"ps_texture_1k";
			// 
			// RColorMapFileNameLabel
			// 
			this->RColorMapFileNameLabel->AutoSize = true;
			this->RColorMapFileNameLabel->Location = System::Drawing::Point(38, 145);
			this->RColorMapFileNameLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RColorMapFileNameLabel->Name = L"RColorMapFileNameLabel";
			this->RColorMapFileNameLabel->Size = System::Drawing::Size(99, 13);
			this->RColorMapFileNameLabel->TabIndex = 350;
			this->RColorMapFileNameLabel->Text = L"ColorMapFileName:";
			// 
			// ColorMapFileNameRHelp
			// 
			this->ColorMapFileNameRHelp->Location = System::Drawing::Point(16, 142);
			this->ColorMapFileNameRHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ColorMapFileNameRHelp->Name = L"ColorMapFileNameRHelp";
			this->ColorMapFileNameRHelp->Size = System::Drawing::Size(17, 19);
			this->ColorMapFileNameRHelp->TabIndex = 349;
			this->ColorMapFileNameRHelp->Text = L"\?";
			this->ColorMapFileNameRHelp->UseVisualStyleBackColor = true;
			// 
			// RColorMapExtensionTextBox
			// 
			this->RColorMapExtensionTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->RColorMapExtensionTextBox->Location = System::Drawing::Point(188, 164);
			this->RColorMapExtensionTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RColorMapExtensionTextBox->Name = L"RColorMapExtensionTextBox";
			this->RColorMapExtensionTextBox->ReadOnly = true;
			this->RColorMapExtensionTextBox->Size = System::Drawing::Size(144, 20);
			this->RColorMapExtensionTextBox->TabIndex = 346;
			this->RColorMapExtensionTextBox->Text = L"png";
			// 
			// RColorMapExtensionLabel
			// 
			this->RColorMapExtensionLabel->AutoSize = true;
			this->RColorMapExtensionLabel->Location = System::Drawing::Point(38, 168);
			this->RColorMapExtensionLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RColorMapExtensionLabel->Name = L"RColorMapExtensionLabel";
			this->RColorMapExtensionLabel->Size = System::Drawing::Size(101, 13);
			this->RColorMapExtensionLabel->TabIndex = 347;
			this->RColorMapExtensionLabel->Text = L"ColorMapExtension:";
			// 
			// ColorMapExtensionRHelp
			// 
			this->ColorMapExtensionRHelp->Location = System::Drawing::Point(16, 166);
			this->ColorMapExtensionRHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ColorMapExtensionRHelp->Name = L"ColorMapExtensionRHelp";
			this->ColorMapExtensionRHelp->Size = System::Drawing::Size(17, 19);
			this->ColorMapExtensionRHelp->TabIndex = 348;
			this->ColorMapExtensionRHelp->Text = L"\?";
			this->ColorMapExtensionRHelp->UseVisualStyleBackColor = true;
			// 
			// RHeightMapExtensionTextBox
			// 
			this->RHeightMapExtensionTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->RHeightMapExtensionTextBox->Location = System::Drawing::Point(188, 119);
			this->RHeightMapExtensionTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RHeightMapExtensionTextBox->Name = L"RHeightMapExtensionTextBox";
			this->RHeightMapExtensionTextBox->ReadOnly = true;
			this->RHeightMapExtensionTextBox->Size = System::Drawing::Size(145, 20);
			this->RHeightMapExtensionTextBox->TabIndex = 177;
			this->RHeightMapExtensionTextBox->Text = L"png";
			// 
			// RHeightMapExtensionLabel
			// 
			this->RHeightMapExtensionLabel->AutoSize = true;
			this->RHeightMapExtensionLabel->Location = System::Drawing::Point(38, 121);
			this->RHeightMapExtensionLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RHeightMapExtensionLabel->Name = L"RHeightMapExtensionLabel";
			this->RHeightMapExtensionLabel->Size = System::Drawing::Size(108, 13);
			this->RHeightMapExtensionLabel->TabIndex = 179;
			this->RHeightMapExtensionLabel->Text = L"HeightMapExtension:";
			// 
			// HeightMapExtensionRHelp
			// 
			this->HeightMapExtensionRHelp->Location = System::Drawing::Point(16, 119);
			this->HeightMapExtensionRHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HeightMapExtensionRHelp->Name = L"HeightMapExtensionRHelp";
			this->HeightMapExtensionRHelp->Size = System::Drawing::Size(17, 19);
			this->HeightMapExtensionRHelp->TabIndex = 181;
			this->HeightMapExtensionRHelp->Text = L"\?";
			this->HeightMapExtensionRHelp->UseVisualStyleBackColor = true;
			// 
			// RHeightMapFileNameTextBox
			// 
			this->RHeightMapFileNameTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->RHeightMapFileNameTextBox->Location = System::Drawing::Point(188, 95);
			this->RHeightMapFileNameTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RHeightMapFileNameTextBox->Name = L"RHeightMapFileNameTextBox";
			this->RHeightMapFileNameTextBox->ReadOnly = true;
			this->RHeightMapFileNameTextBox->Size = System::Drawing::Size(145, 20);
			this->RHeightMapFileNameTextBox->TabIndex = 176;
			this->RHeightMapFileNameTextBox->Text = L"ps_height_1k";
			// 
			// HeightMapFileNameRHelp
			// 
			this->HeightMapFileNameRHelp->Location = System::Drawing::Point(16, 95);
			this->HeightMapFileNameRHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HeightMapFileNameRHelp->Name = L"HeightMapFileNameRHelp";
			this->HeightMapFileNameRHelp->Size = System::Drawing::Size(17, 19);
			this->HeightMapFileNameRHelp->TabIndex = 180;
			this->HeightMapFileNameRHelp->Text = L"\?";
			this->HeightMapFileNameRHelp->UseVisualStyleBackColor = true;
			// 
			// RHeightMapFileNameLabel
			// 
			this->RHeightMapFileNameLabel->AutoSize = true;
			this->RHeightMapFileNameLabel->Location = System::Drawing::Point(38, 98);
			this->RHeightMapFileNameLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RHeightMapFileNameLabel->Name = L"RHeightMapFileNameLabel";
			this->RHeightMapFileNameLabel->Size = System::Drawing::Size(106, 13);
			this->RHeightMapFileNameLabel->TabIndex = 178;
			this->RHeightMapFileNameLabel->Text = L"HeightMapFileName:";
			// 
			// FormatTextBox
			// 
			this->FormatTextBox->Location = System::Drawing::Point(89, 72);
			this->FormatTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->FormatTextBox->Name = L"FormatTextBox";
			this->FormatTextBox->Size = System::Drawing::Size(243, 20);
			this->FormatTextBox->TabIndex = 170;
			// 
			// FormatLabel
			// 
			this->FormatLabel->Location = System::Drawing::Point(14, 72);
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
			this->ResourceFormatComboBox->Location = System::Drawing::Point(188, 47);
			this->ResourceFormatComboBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ResourceFormatComboBox->Name = L"ResourceFormatComboBox";
			this->ResourceFormatComboBox->Size = System::Drawing::Size(145, 21);
			this->ResourceFormatComboBox->TabIndex = 166;
			this->ResourceFormatComboBox->Text = L"Already in Path";
			this->ResourceFormatComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &BaseForm::ResourceFormatComboBox_SelectedIndexChanged);
			// 
			// ResourceFormatLabel
			// 
			this->ResourceFormatLabel->AutoSize = true;
			this->ResourceFormatLabel->Location = System::Drawing::Point(37, 50);
			this->ResourceFormatLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->ResourceFormatLabel->Name = L"ResourceFormatLabel";
			this->ResourceFormatLabel->Size = System::Drawing::Size(91, 13);
			this->ResourceFormatLabel->TabIndex = 167;
			this->ResourceFormatLabel->Text = L"Resource Format:";
			// 
			// ResourceFormatHelp
			// 
			this->ResourceFormatHelp->Location = System::Drawing::Point(15, 48);
			this->ResourceFormatHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ResourceFormatHelp->Name = L"ResourceFormatHelp";
			this->ResourceFormatHelp->Size = System::Drawing::Size(17, 19);
			this->ResourceFormatHelp->TabIndex = 168;
			this->ResourceFormatHelp->Text = L"\?";
			this->ResourceFormatHelp->UseVisualStyleBackColor = true;
			// 
			// GroupNameRHelp
			// 
			this->GroupNameRHelp->Location = System::Drawing::Point(15, 24);
			this->GroupNameRHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->GroupNameRHelp->Name = L"GroupNameRHelp";
			this->GroupNameRHelp->Size = System::Drawing::Size(17, 19);
			this->GroupNameRHelp->TabIndex = 165;
			this->GroupNameRHelp->Text = L"\?";
			this->GroupNameRHelp->UseVisualStyleBackColor = true;
			// 
			// RGroupNameTextBox
			// 
			this->RGroupNameTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->RGroupNameTextBox->Location = System::Drawing::Point(188, 24);
			this->RGroupNameTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RGroupNameTextBox->Name = L"RGroupNameTextBox";
			this->RGroupNameTextBox->ReadOnly = true;
			this->RGroupNameTextBox->Size = System::Drawing::Size(145, 20);
			this->RGroupNameTextBox->TabIndex = 163;
			this->RGroupNameTextBox->Text = L"PLSM2";
			// 
			// RGroupNameLabel
			// 
			this->RGroupNameLabel->AutoSize = true;
			this->RGroupNameLabel->Location = System::Drawing::Point(37, 27);
			this->RGroupNameLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RGroupNameLabel->Name = L"RGroupNameLabel";
			this->RGroupNameLabel->Size = System::Drawing::Size(67, 13);
			this->RGroupNameLabel->TabIndex = 164;
			this->RGroupNameLabel->Text = L"GroupName:";
			// 
			// RPagingTabPage
			// 
			this->RPagingTabPage->Controls->Add(this->RData2DFormatTextBox);
			this->RPagingTabPage->Controls->Add(this->RMinValueTextBox);
			this->RPagingTabPage->Controls->Add(this->RMinValueLabel);
			this->RPagingTabPage->Controls->Add(this->RMinValueHelp);
			this->RPagingTabPage->Controls->Add(this->RMaxValueTextBox);
			this->RPagingTabPage->Controls->Add(this->RMaxValueLabel);
			this->RPagingTabPage->Controls->Add(this->RMaxValueHelp);
			this->RPagingTabPage->Controls->Add(this->RData2DFormatLabel);
			this->RPagingTabPage->Controls->Add(this->RData2DFormatHelp);
			this->RPagingTabPage->Controls->Add(this->RPageSizeTextBox);
			this->RPagingTabPage->Controls->Add(this->RTileSizeTextBox);
			this->RPagingTabPage->Controls->Add(this->RTileSizeLabel);
			this->RPagingTabPage->Controls->Add(this->RTileSizeHelp);
			this->RPagingTabPage->Controls->Add(this->RPageSizeLabel);
			this->RPagingTabPage->Controls->Add(this->RPageSizeHelp);
			this->RPagingTabPage->Controls->Add(this->PageHeightTextBox);
			this->RPagingTabPage->Controls->Add(this->HeightHelp);
			this->RPagingTabPage->Controls->Add(this->PageHeightLabel);
			this->RPagingTabPage->Controls->Add(this->WidthHelp);
			this->RPagingTabPage->Controls->Add(this->PageWidthTextBox);
			this->RPagingTabPage->Controls->Add(this->PageWidthLabel);
			this->RPagingTabPage->Location = System::Drawing::Point(3, 20);
			this->RPagingTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RPagingTabPage->Name = L"RPagingTabPage";
			this->RPagingTabPage->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RPagingTabPage->Size = System::Drawing::Size(354, 545);
			this->RPagingTabPage->TabIndex = 1;
			this->RPagingTabPage->Text = L"Paging";
			this->RPagingTabPage->UseVisualStyleBackColor = true;
			// 
			// RData2DFormatTextBox
			// 
			this->RData2DFormatTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->RData2DFormatTextBox->Location = System::Drawing::Point(187, 119);
			this->RData2DFormatTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RData2DFormatTextBox->Name = L"RData2DFormatTextBox";
			this->RData2DFormatTextBox->ReadOnly = true;
			this->RData2DFormatTextBox->Size = System::Drawing::Size(145, 20);
			this->RData2DFormatTextBox->TabIndex = 213;
			// 
			// RMinValueTextBox
			// 
			this->RMinValueTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->RMinValueTextBox->Location = System::Drawing::Point(187, 166);
			this->RMinValueTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RMinValueTextBox->Name = L"RMinValueTextBox";
			this->RMinValueTextBox->ReadOnly = true;
			this->RMinValueTextBox->Size = System::Drawing::Size(145, 20);
			this->RMinValueTextBox->TabIndex = 206;
			this->RMinValueTextBox->Text = L"0";
			// 
			// RMinValueLabel
			// 
			this->RMinValueLabel->AutoSize = true;
			this->RMinValueLabel->Location = System::Drawing::Point(37, 168);
			this->RMinValueLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RMinValueLabel->Name = L"RMinValueLabel";
			this->RMinValueLabel->Size = System::Drawing::Size(54, 13);
			this->RMinValueLabel->TabIndex = 209;
			this->RMinValueLabel->Text = L"MinValue:";
			// 
			// RMinValueHelp
			// 
			this->RMinValueHelp->Location = System::Drawing::Point(15, 166);
			this->RMinValueHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RMinValueHelp->Name = L"RMinValueHelp";
			this->RMinValueHelp->Size = System::Drawing::Size(17, 19);
			this->RMinValueHelp->TabIndex = 212;
			this->RMinValueHelp->Text = L"\?";
			this->RMinValueHelp->UseVisualStyleBackColor = true;
			// 
			// RMaxValueTextBox
			// 
			this->RMaxValueTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->RMaxValueTextBox->Location = System::Drawing::Point(187, 142);
			this->RMaxValueTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RMaxValueTextBox->Name = L"RMaxValueTextBox";
			this->RMaxValueTextBox->ReadOnly = true;
			this->RMaxValueTextBox->Size = System::Drawing::Size(145, 20);
			this->RMaxValueTextBox->TabIndex = 205;
			this->RMaxValueTextBox->Text = L"0";
			// 
			// RMaxValueLabel
			// 
			this->RMaxValueLabel->AutoSize = true;
			this->RMaxValueLabel->Location = System::Drawing::Point(37, 145);
			this->RMaxValueLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RMaxValueLabel->Name = L"RMaxValueLabel";
			this->RMaxValueLabel->Size = System::Drawing::Size(57, 13);
			this->RMaxValueLabel->TabIndex = 208;
			this->RMaxValueLabel->Text = L"MaxValue:";
			// 
			// RMaxValueHelp
			// 
			this->RMaxValueHelp->Location = System::Drawing::Point(15, 142);
			this->RMaxValueHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RMaxValueHelp->Name = L"RMaxValueHelp";
			this->RMaxValueHelp->Size = System::Drawing::Size(17, 19);
			this->RMaxValueHelp->TabIndex = 211;
			this->RMaxValueHelp->Text = L"\?";
			this->RMaxValueHelp->UseVisualStyleBackColor = true;
			// 
			// RData2DFormatLabel
			// 
			this->RData2DFormatLabel->AutoSize = true;
			this->RData2DFormatLabel->Location = System::Drawing::Point(37, 121);
			this->RData2DFormatLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RData2DFormatLabel->Name = L"RData2DFormatLabel";
			this->RData2DFormatLabel->Size = System::Drawing::Size(79, 13);
			this->RData2DFormatLabel->TabIndex = 207;
			this->RData2DFormatLabel->Text = L"Data2DFormat:";
			// 
			// RData2DFormatHelp
			// 
			this->RData2DFormatHelp->Location = System::Drawing::Point(15, 119);
			this->RData2DFormatHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RData2DFormatHelp->Name = L"RData2DFormatHelp";
			this->RData2DFormatHelp->Size = System::Drawing::Size(17, 19);
			this->RData2DFormatHelp->TabIndex = 210;
			this->RData2DFormatHelp->Text = L"\?";
			this->RData2DFormatHelp->UseVisualStyleBackColor = true;
			// 
			// RPageSizeTextBox
			// 
			this->RPageSizeTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->RPageSizeTextBox->Location = System::Drawing::Point(187, 72);
			this->RPageSizeTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RPageSizeTextBox->Name = L"RPageSizeTextBox";
			this->RPageSizeTextBox->ReadOnly = true;
			this->RPageSizeTextBox->Size = System::Drawing::Size(145, 20);
			this->RPageSizeTextBox->TabIndex = 194;
			this->RPageSizeTextBox->Text = L"513";
			// 
			// RTileSizeTextBox
			// 
			this->RTileSizeTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->RTileSizeTextBox->Location = System::Drawing::Point(187, 95);
			this->RTileSizeTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RTileSizeTextBox->Name = L"RTileSizeTextBox";
			this->RTileSizeTextBox->ReadOnly = true;
			this->RTileSizeTextBox->Size = System::Drawing::Size(145, 20);
			this->RTileSizeTextBox->TabIndex = 195;
			this->RTileSizeTextBox->Text = L"65";
			// 
			// RTileSizeLabel
			// 
			this->RTileSizeLabel->AutoSize = true;
			this->RTileSizeLabel->Location = System::Drawing::Point(37, 98);
			this->RTileSizeLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RTileSizeLabel->Name = L"RTileSizeLabel";
			this->RTileSizeLabel->Size = System::Drawing::Size(47, 13);
			this->RTileSizeLabel->TabIndex = 199;
			this->RTileSizeLabel->Text = L"TileSize:";
			// 
			// RTileSizeHelp
			// 
			this->RTileSizeHelp->Location = System::Drawing::Point(15, 95);
			this->RTileSizeHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RTileSizeHelp->Name = L"RTileSizeHelp";
			this->RTileSizeHelp->Size = System::Drawing::Size(17, 19);
			this->RTileSizeHelp->TabIndex = 203;
			this->RTileSizeHelp->Text = L"\?";
			this->RTileSizeHelp->UseVisualStyleBackColor = true;
			// 
			// RPageSizeLabel
			// 
			this->RPageSizeLabel->AutoSize = true;
			this->RPageSizeLabel->Location = System::Drawing::Point(37, 74);
			this->RPageSizeLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RPageSizeLabel->Name = L"RPageSizeLabel";
			this->RPageSizeLabel->Size = System::Drawing::Size(55, 13);
			this->RPageSizeLabel->TabIndex = 198;
			this->RPageSizeLabel->Text = L"PageSize:";
			// 
			// RPageSizeHelp
			// 
			this->RPageSizeHelp->Location = System::Drawing::Point(15, 72);
			this->RPageSizeHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RPageSizeHelp->Name = L"RPageSizeHelp";
			this->RPageSizeHelp->Size = System::Drawing::Size(17, 19);
			this->RPageSizeHelp->TabIndex = 202;
			this->RPageSizeHelp->Text = L"\?";
			this->RPageSizeHelp->UseVisualStyleBackColor = true;
			// 
			// PageHeightTextBox
			// 
			this->PageHeightTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->PageHeightTextBox->Location = System::Drawing::Point(187, 48);
			this->PageHeightTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->PageHeightTextBox->Name = L"PageHeightTextBox";
			this->PageHeightTextBox->Size = System::Drawing::Size(145, 20);
			this->PageHeightTextBox->TabIndex = 193;
			this->PageHeightTextBox->Text = L"2";
			// 
			// HeightHelp
			// 
			this->HeightHelp->Location = System::Drawing::Point(15, 48);
			this->HeightHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HeightHelp->Name = L"HeightHelp";
			this->HeightHelp->Size = System::Drawing::Size(17, 19);
			this->HeightHelp->TabIndex = 201;
			this->HeightHelp->Text = L"\?";
			this->HeightHelp->UseVisualStyleBackColor = true;
			// 
			// PageHeightLabel
			// 
			this->PageHeightLabel->AutoSize = true;
			this->PageHeightLabel->Location = System::Drawing::Point(37, 50);
			this->PageHeightLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->PageHeightLabel->Name = L"PageHeightLabel";
			this->PageHeightLabel->Size = System::Drawing::Size(41, 13);
			this->PageHeightLabel->TabIndex = 197;
			this->PageHeightLabel->Text = L"Height:";
			// 
			// WidthHelp
			// 
			this->WidthHelp->Location = System::Drawing::Point(15, 24);
			this->WidthHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->WidthHelp->Name = L"WidthHelp";
			this->WidthHelp->Size = System::Drawing::Size(17, 19);
			this->WidthHelp->TabIndex = 200;
			this->WidthHelp->Text = L"\?";
			this->WidthHelp->UseVisualStyleBackColor = true;
			// 
			// PageWidthTextBox
			// 
			this->PageWidthTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->PageWidthTextBox->Location = System::Drawing::Point(187, 24);
			this->PageWidthTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->PageWidthTextBox->Name = L"PageWidthTextBox";
			this->PageWidthTextBox->Size = System::Drawing::Size(145, 20);
			this->PageWidthTextBox->TabIndex = 192;
			this->PageWidthTextBox->Text = L"2";
			// 
			// PageWidthLabel
			// 
			this->PageWidthLabel->AutoSize = true;
			this->PageWidthLabel->Location = System::Drawing::Point(37, 27);
			this->PageWidthLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->PageWidthLabel->Name = L"PageWidthLabel";
			this->PageWidthLabel->Size = System::Drawing::Size(38, 13);
			this->PageWidthLabel->TabIndex = 196;
			this->PageWidthLabel->Text = L"Width:";
			// 
			// RPropertiesTabPage
			// 
			this->RPropertiesTabPage->Controls->Add(this->MaxPixelErrorTextBox);
			this->RPropertiesTabPage->Controls->Add(this->MaxPixelErrorLabel);
			this->RPropertiesTabPage->Controls->Add(this->MaxPixelErrorHelp);
			this->RPropertiesTabPage->Controls->Add(this->LODMorphStartTextBox);
			this->RPropertiesTabPage->Controls->Add(this->LODMorphStartLabel);
			this->RPropertiesTabPage->Controls->Add(this->VertexCompressionCheckBox);
			this->RPropertiesTabPage->Controls->Add(this->VertexCompressionHelp);
			this->RPropertiesTabPage->Controls->Add(this->DeformableCheckBox);
			this->RPropertiesTabPage->Controls->Add(this->DeformableHelp);
			this->RPropertiesTabPage->Controls->Add(this->LODMorphStartHelp);
			this->RPropertiesTabPage->Controls->Add(this->VertexProgramMorphCheckBox);
			this->RPropertiesTabPage->Controls->Add(this->VertexProgramMorphHelp);
			this->RPropertiesTabPage->Controls->Add(this->RTerrainScaleZTextBox);
			this->RPropertiesTabPage->Controls->Add(this->RTerrainScaleZLabel);
			this->RPropertiesTabPage->Controls->Add(this->RScaleZHelp);
			this->RPropertiesTabPage->Controls->Add(this->RTerrainScaleYTextBox);
			this->RPropertiesTabPage->Controls->Add(this->RTerrainScaleYLabel);
			this->RPropertiesTabPage->Controls->Add(this->RScaleYHelp);
			this->RPropertiesTabPage->Controls->Add(this->RTerrainScaleXTextBox);
			this->RPropertiesTabPage->Controls->Add(this->RTerrainScaleXLabel);
			this->RPropertiesTabPage->Controls->Add(this->RScaleXHelp);
			this->RPropertiesTabPage->Location = System::Drawing::Point(3, 20);
			this->RPropertiesTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RPropertiesTabPage->Name = L"RPropertiesTabPage";
			this->RPropertiesTabPage->Size = System::Drawing::Size(354, 545);
			this->RPropertiesTabPage->TabIndex = 2;
			this->RPropertiesTabPage->Text = L"Properties";
			this->RPropertiesTabPage->UseVisualStyleBackColor = true;
			// 
			// MaxPixelErrorTextBox
			// 
			this->MaxPixelErrorTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->MaxPixelErrorTextBox->Location = System::Drawing::Point(187, 189);
			this->MaxPixelErrorTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaxPixelErrorTextBox->Name = L"MaxPixelErrorTextBox";
			this->MaxPixelErrorTextBox->Size = System::Drawing::Size(145, 20);
			this->MaxPixelErrorTextBox->TabIndex = 229;
			this->MaxPixelErrorTextBox->Text = L"3";
			// 
			// MaxPixelErrorLabel
			// 
			this->MaxPixelErrorLabel->AutoSize = true;
			this->MaxPixelErrorLabel->Location = System::Drawing::Point(37, 192);
			this->MaxPixelErrorLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->MaxPixelErrorLabel->Name = L"MaxPixelErrorLabel";
			this->MaxPixelErrorLabel->Size = System::Drawing::Size(74, 13);
			this->MaxPixelErrorLabel->TabIndex = 230;
			this->MaxPixelErrorLabel->Text = L"MaxPixelError:";
			// 
			// MaxPixelErrorHelp
			// 
			this->MaxPixelErrorHelp->Location = System::Drawing::Point(15, 189);
			this->MaxPixelErrorHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaxPixelErrorHelp->Name = L"MaxPixelErrorHelp";
			this->MaxPixelErrorHelp->Size = System::Drawing::Size(17, 19);
			this->MaxPixelErrorHelp->TabIndex = 228;
			this->MaxPixelErrorHelp->Text = L"\?";
			this->MaxPixelErrorHelp->UseVisualStyleBackColor = true;
			// 
			// LODMorphStartTextBox
			// 
			this->LODMorphStartTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->LODMorphStartTextBox->Location = System::Drawing::Point(187, 166);
			this->LODMorphStartTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->LODMorphStartTextBox->Name = L"LODMorphStartTextBox";
			this->LODMorphStartTextBox->Size = System::Drawing::Size(145, 20);
			this->LODMorphStartTextBox->TabIndex = 226;
			this->LODMorphStartTextBox->Text = L"0.2";
			// 
			// LODMorphStartLabel
			// 
			this->LODMorphStartLabel->AutoSize = true;
			this->LODMorphStartLabel->Location = System::Drawing::Point(37, 168);
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
			this->VertexCompressionCheckBox->Location = System::Drawing::Point(36, 119);
			this->VertexCompressionCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->VertexCompressionCheckBox->Name = L"VertexCompressionCheckBox";
			this->VertexCompressionCheckBox->Size = System::Drawing::Size(231, 20);
			this->VertexCompressionCheckBox->TabIndex = 220;
			this->VertexCompressionCheckBox->Text = L"VertexCompression:";
			this->VertexCompressionCheckBox->UseVisualStyleBackColor = true;
			// 
			// VertexCompressionHelp
			// 
			this->VertexCompressionHelp->Location = System::Drawing::Point(15, 119);
			this->VertexCompressionHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->VertexCompressionHelp->Name = L"VertexCompressionHelp";
			this->VertexCompressionHelp->Size = System::Drawing::Size(17, 19);
			this->VertexCompressionHelp->TabIndex = 223;
			this->VertexCompressionHelp->Text = L"\?";
			this->VertexCompressionHelp->UseVisualStyleBackColor = true;
			// 
			// DeformableCheckBox
			// 
			this->DeformableCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->DeformableCheckBox->Checked = true;
			this->DeformableCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->DeformableCheckBox->Location = System::Drawing::Point(36, 95);
			this->DeformableCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->DeformableCheckBox->Name = L"DeformableCheckBox";
			this->DeformableCheckBox->Size = System::Drawing::Size(231, 20);
			this->DeformableCheckBox->TabIndex = 219;
			this->DeformableCheckBox->Text = L"Deformable:";
			this->DeformableCheckBox->UseVisualStyleBackColor = true;
			// 
			// DeformableHelp
			// 
			this->DeformableHelp->Location = System::Drawing::Point(15, 95);
			this->DeformableHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->DeformableHelp->Name = L"DeformableHelp";
			this->DeformableHelp->Size = System::Drawing::Size(17, 19);
			this->DeformableHelp->TabIndex = 222;
			this->DeformableHelp->Text = L"\?";
			this->DeformableHelp->UseVisualStyleBackColor = true;
			// 
			// LODMorphStartHelp
			// 
			this->LODMorphStartHelp->Location = System::Drawing::Point(15, 166);
			this->LODMorphStartHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->LODMorphStartHelp->Name = L"LODMorphStartHelp";
			this->LODMorphStartHelp->Size = System::Drawing::Size(17, 19);
			this->LODMorphStartHelp->TabIndex = 225;
			this->LODMorphStartHelp->Text = L"\?";
			this->LODMorphStartHelp->UseVisualStyleBackColor = true;
			// 
			// VertexProgramMorphCheckBox
			// 
			this->VertexProgramMorphCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->VertexProgramMorphCheckBox->Checked = true;
			this->VertexProgramMorphCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->VertexProgramMorphCheckBox->Location = System::Drawing::Point(36, 142);
			this->VertexProgramMorphCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->VertexProgramMorphCheckBox->Name = L"VertexProgramMorphCheckBox";
			this->VertexProgramMorphCheckBox->Size = System::Drawing::Size(231, 20);
			this->VertexProgramMorphCheckBox->TabIndex = 221;
			this->VertexProgramMorphCheckBox->Text = L"VertexProgramMorph:";
			this->VertexProgramMorphCheckBox->UseVisualStyleBackColor = true;
			// 
			// VertexProgramMorphHelp
			// 
			this->VertexProgramMorphHelp->Location = System::Drawing::Point(15, 142);
			this->VertexProgramMorphHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->VertexProgramMorphHelp->Name = L"VertexProgramMorphHelp";
			this->VertexProgramMorphHelp->Size = System::Drawing::Size(17, 19);
			this->VertexProgramMorphHelp->TabIndex = 224;
			this->VertexProgramMorphHelp->Text = L"\?";
			this->VertexProgramMorphHelp->UseVisualStyleBackColor = true;
			// 
			// RTerrainScaleZTextBox
			// 
			this->RTerrainScaleZTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->RTerrainScaleZTextBox->Location = System::Drawing::Point(187, 72);
			this->RTerrainScaleZTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RTerrainScaleZTextBox->Name = L"RTerrainScaleZTextBox";
			this->RTerrainScaleZTextBox->ReadOnly = true;
			this->RTerrainScaleZTextBox->Size = System::Drawing::Size(145, 20);
			this->RTerrainScaleZTextBox->TabIndex = 203;
			this->RTerrainScaleZTextBox->Text = L"90000";
			// 
			// RTerrainScaleZLabel
			// 
			this->RTerrainScaleZLabel->AutoSize = true;
			this->RTerrainScaleZLabel->Location = System::Drawing::Point(37, 74);
			this->RTerrainScaleZLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RTerrainScaleZLabel->Name = L"RTerrainScaleZLabel";
			this->RTerrainScaleZLabel->Size = System::Drawing::Size(44, 13);
			this->RTerrainScaleZLabel->TabIndex = 206;
			this->RTerrainScaleZLabel->Text = L"ScaleZ:";
			// 
			// RScaleZHelp
			// 
			this->RScaleZHelp->Location = System::Drawing::Point(15, 72);
			this->RScaleZHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RScaleZHelp->Name = L"RScaleZHelp";
			this->RScaleZHelp->Size = System::Drawing::Size(17, 19);
			this->RScaleZHelp->TabIndex = 209;
			this->RScaleZHelp->Text = L"\?";
			this->RScaleZHelp->UseVisualStyleBackColor = true;
			// 
			// RTerrainScaleYTextBox
			// 
			this->RTerrainScaleYTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->RTerrainScaleYTextBox->Location = System::Drawing::Point(187, 48);
			this->RTerrainScaleYTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RTerrainScaleYTextBox->Name = L"RTerrainScaleYTextBox";
			this->RTerrainScaleYTextBox->ReadOnly = true;
			this->RTerrainScaleYTextBox->Size = System::Drawing::Size(145, 20);
			this->RTerrainScaleYTextBox->TabIndex = 202;
			this->RTerrainScaleYTextBox->Text = L"15000";
			// 
			// RTerrainScaleYLabel
			// 
			this->RTerrainScaleYLabel->AutoSize = true;
			this->RTerrainScaleYLabel->Location = System::Drawing::Point(37, 50);
			this->RTerrainScaleYLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RTerrainScaleYLabel->Name = L"RTerrainScaleYLabel";
			this->RTerrainScaleYLabel->Size = System::Drawing::Size(44, 13);
			this->RTerrainScaleYLabel->TabIndex = 205;
			this->RTerrainScaleYLabel->Text = L"ScaleY:";
			// 
			// RScaleYHelp
			// 
			this->RScaleYHelp->Location = System::Drawing::Point(15, 48);
			this->RScaleYHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RScaleYHelp->Name = L"RScaleYHelp";
			this->RScaleYHelp->Size = System::Drawing::Size(17, 19);
			this->RScaleYHelp->TabIndex = 208;
			this->RScaleYHelp->Text = L"\?";
			this->RScaleYHelp->UseVisualStyleBackColor = true;
			// 
			// RTerrainScaleXTextBox
			// 
			this->RTerrainScaleXTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->RTerrainScaleXTextBox->Location = System::Drawing::Point(187, 23);
			this->RTerrainScaleXTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RTerrainScaleXTextBox->Name = L"RTerrainScaleXTextBox";
			this->RTerrainScaleXTextBox->ReadOnly = true;
			this->RTerrainScaleXTextBox->Size = System::Drawing::Size(145, 20);
			this->RTerrainScaleXTextBox->TabIndex = 201;
			this->RTerrainScaleXTextBox->Text = L"90000";
			// 
			// RTerrainScaleXLabel
			// 
			this->RTerrainScaleXLabel->AutoSize = true;
			this->RTerrainScaleXLabel->Location = System::Drawing::Point(37, 27);
			this->RTerrainScaleXLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RTerrainScaleXLabel->Name = L"RTerrainScaleXLabel";
			this->RTerrainScaleXLabel->Size = System::Drawing::Size(44, 13);
			this->RTerrainScaleXLabel->TabIndex = 204;
			this->RTerrainScaleXLabel->Text = L"ScaleX:";
			// 
			// RScaleXHelp
			// 
			this->RScaleXHelp->Location = System::Drawing::Point(15, 24);
			this->RScaleXHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RScaleXHelp->Name = L"RScaleXHelp";
			this->RScaleXHelp->Size = System::Drawing::Size(17, 19);
			this->RScaleXHelp->TabIndex = 207;
			this->RScaleXHelp->Text = L"\?";
			this->RScaleXHelp->UseVisualStyleBackColor = true;
			// 
			// RLightingTabPage
			// 
			this->RLightingTabPage->Controls->Add(this->VertexNormalsCheckBox);
			this->RLightingTabPage->Controls->Add(this->VertexNormalsHelp);
			this->RLightingTabPage->Controls->Add(this->VertexLitCheckBox);
			this->RLightingTabPage->Controls->Add(this->VertexLitHelp);
			this->RLightingTabPage->Location = System::Drawing::Point(3, 20);
			this->RLightingTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RLightingTabPage->Name = L"RLightingTabPage";
			this->RLightingTabPage->Size = System::Drawing::Size(354, 545);
			this->RLightingTabPage->TabIndex = 3;
			this->RLightingTabPage->Text = L"Lighting";
			this->RLightingTabPage->UseVisualStyleBackColor = true;
			// 
			// VertexNormalsCheckBox
			// 
			this->VertexNormalsCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->VertexNormalsCheckBox->Location = System::Drawing::Point(36, 24);
			this->VertexNormalsCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->VertexNormalsCheckBox->Name = L"VertexNormalsCheckBox";
			this->VertexNormalsCheckBox->Size = System::Drawing::Size(231, 20);
			this->VertexNormalsCheckBox->TabIndex = 224;
			this->VertexNormalsCheckBox->Text = L"VertexNormals:";
			this->VertexNormalsCheckBox->UseVisualStyleBackColor = true;
			// 
			// VertexNormalsHelp
			// 
			this->VertexNormalsHelp->Location = System::Drawing::Point(15, 24);
			this->VertexNormalsHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->VertexNormalsHelp->Name = L"VertexNormalsHelp";
			this->VertexNormalsHelp->Size = System::Drawing::Size(17, 19);
			this->VertexNormalsHelp->TabIndex = 226;
			this->VertexNormalsHelp->Text = L"\?";
			this->VertexNormalsHelp->UseVisualStyleBackColor = true;
			// 
			// VertexLitCheckBox
			// 
			this->VertexLitCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->VertexLitCheckBox->Location = System::Drawing::Point(36, 48);
			this->VertexLitCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->VertexLitCheckBox->Name = L"VertexLitCheckBox";
			this->VertexLitCheckBox->Size = System::Drawing::Size(231, 20);
			this->VertexLitCheckBox->TabIndex = 225;
			this->VertexLitCheckBox->Text = L"VertexLit:";
			this->VertexLitCheckBox->UseVisualStyleBackColor = true;
			// 
			// VertexLitHelp
			// 
			this->VertexLitHelp->Location = System::Drawing::Point(15, 48);
			this->VertexLitHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->VertexLitHelp->Name = L"VertexLitHelp";
			this->VertexLitHelp->Size = System::Drawing::Size(17, 19);
			this->VertexLitHelp->TabIndex = 227;
			this->VertexLitHelp->Text = L"\?";
			this->VertexLitHelp->UseVisualStyleBackColor = true;
			// 
			// RTextureTabPage
			// 
			this->RTextureTabPage->AutoScroll = true;
			this->RTextureTabPage->Controls->Add(this->RSetSplatFileNamesRichTextBox);
			this->RTextureTabPage->Controls->Add(this->RSetMaterialHeightRichTextBox);
			this->RTextureTabPage->Controls->Add(this->RSetMaterialHeightLabel);
			this->RTextureTabPage->Controls->Add(this->RSetMaterialHeightHelp);
			this->RTextureTabPage->Controls->Add(this->RSetMaterialColorRichTextBox);
			this->RTextureTabPage->Controls->Add(this->RSetSplatFileNamesLabel);
			this->RTextureTabPage->Controls->Add(this->RSetMaterialColorLabel);
			this->RTextureTabPage->Controls->Add(this->RSetSplatFileNamesHelp);
			this->RTextureTabPage->Controls->Add(this->RSetMaterialColorHelp);
			this->RTextureTabPage->Controls->Add(this->TextureFormatSupportedRichTextBox);
			this->RTextureTabPage->Controls->Add(this->RNumMatHeightSplatTextBox);
			this->RTextureTabPage->Controls->Add(this->RNumMatHeightSplatLabel);
			this->RTextureTabPage->Controls->Add(this->RNumMatHeightSplatHelp);
			this->RTextureTabPage->Controls->Add(this->BaseVertexInstantColorCheckBox);
			this->RTextureTabPage->Controls->Add(this->BaseVertexInstantColorHelp);
			this->RTextureTabPage->Controls->Add(this->BaseVertexShadowCheckBox);
			this->RTextureTabPage->Controls->Add(this->BaseVertexShadowHelp);
			this->RTextureTabPage->Controls->Add(this->BaseVertexColorCheckBox);
			this->RTextureTabPage->Controls->Add(this->BaseVertexColorHelp);
			this->RTextureTabPage->Controls->Add(this->VertexColorsCheckBox);
			this->RTextureTabPage->Controls->Add(this->VertexColorsHelp);
			this->RTextureTabPage->Controls->Add(this->BigImageCheckBox);
			this->RTextureTabPage->Controls->Add(this->BigImageHelp);
			this->RTextureTabPage->Controls->Add(this->CoverageVertexColorCheckBox);
			this->RTextureTabPage->Controls->Add(this->CoverageVertexColorHelp);
			this->RTextureTabPage->Controls->Add(this->TextureFormatTextBox);
			this->RTextureTabPage->Controls->Add(this->TextureFormatLabel);
			this->RTextureTabPage->Controls->Add(this->TextureFormatHelp);
			this->RTextureTabPage->Controls->Add(this->NumTextureFormatSupportedTextBox);
			this->RTextureTabPage->Controls->Add(this->NumTextureFormatSupportedLabel);
			this->RTextureTabPage->Controls->Add(this->NumTextureFormatSupportedHelp);
			this->RTextureTabPage->Controls->Add(this->RColorMapStretchFactorTextBox);
			this->RTextureTabPage->Controls->Add(this->RColorMapStretchFactorLabel);
			this->RTextureTabPage->Controls->Add(this->RColorMapStretchFactorHelp);
			this->RTextureTabPage->Location = System::Drawing::Point(3, 20);
			this->RTextureTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RTextureTabPage->Name = L"RTextureTabPage";
			this->RTextureTabPage->Size = System::Drawing::Size(354, 545);
			this->RTextureTabPage->TabIndex = 4;
			this->RTextureTabPage->Text = L"Texture";
			this->RTextureTabPage->UseVisualStyleBackColor = true;
			// 
			// RSetSplatFileNamesRichTextBox
			// 
			this->RSetSplatFileNamesRichTextBox->Location = System::Drawing::Point(15, 375);
			this->RSetSplatFileNamesRichTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RSetSplatFileNamesRichTextBox->Name = L"RSetSplatFileNamesRichTextBox";
			this->RSetSplatFileNamesRichTextBox->ReadOnly = true;
			this->RSetSplatFileNamesRichTextBox->Size = System::Drawing::Size(312, 58);
			this->RSetSplatFileNamesRichTextBox->TabIndex = 368;
			this->RSetSplatFileNamesRichTextBox->Text = L"#needs to be in maptool directory\nSplatFilename0=splatting_sand.png\nSplatFilename" 
				L"1=splatting_grass.png\nSplatFilename2=splatting_rock.png\nSplatFilename3=splatting" 
				L"_snow.png";
			this->RSetSplatFileNamesRichTextBox->WordWrap = false;
			// 
			// RSetMaterialHeightRichTextBox
			// 
			this->RSetMaterialHeightRichTextBox->Location = System::Drawing::Point(15, 204);
			this->RSetMaterialHeightRichTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RSetMaterialHeightRichTextBox->Name = L"RSetMaterialHeightRichTextBox";
			this->RSetMaterialHeightRichTextBox->ReadOnly = true;
			this->RSetMaterialHeightRichTextBox->Size = System::Drawing::Size(312, 58);
			this->RSetMaterialHeightRichTextBox->TabIndex = 367;
			this->RSetMaterialHeightRichTextBox->Text = L"MaterialHeight0=0\nMaterialHeight1=12\nMaterialHeight2=60\nMaterialHeight3=75";
			this->RSetMaterialHeightRichTextBox->WordWrap = false;
			// 
			// RSetMaterialHeightLabel
			// 
			this->RSetMaterialHeightLabel->AutoSize = true;
			this->RSetMaterialHeightLabel->Location = System::Drawing::Point(37, 183);
			this->RSetMaterialHeightLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RSetMaterialHeightLabel->Name = L"RSetMaterialHeightLabel";
			this->RSetMaterialHeightLabel->Size = System::Drawing::Size(97, 13);
			this->RSetMaterialHeightLabel->TabIndex = 366;
			this->RSetMaterialHeightLabel->Text = L"Set Material Height";
			// 
			// RSetMaterialHeightHelp
			// 
			this->RSetMaterialHeightHelp->Location = System::Drawing::Point(15, 180);
			this->RSetMaterialHeightHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RSetMaterialHeightHelp->Name = L"RSetMaterialHeightHelp";
			this->RSetMaterialHeightHelp->Size = System::Drawing::Size(17, 19);
			this->RSetMaterialHeightHelp->TabIndex = 365;
			this->RSetMaterialHeightHelp->Text = L"\?";
			this->RSetMaterialHeightHelp->UseVisualStyleBackColor = true;
			// 
			// RSetMaterialColorRichTextBox
			// 
			this->RSetMaterialColorRichTextBox->Location = System::Drawing::Point(15, 289);
			this->RSetMaterialColorRichTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RSetMaterialColorRichTextBox->Name = L"RSetMaterialColorRichTextBox";
			this->RSetMaterialColorRichTextBox->ReadOnly = true;
			this->RSetMaterialColorRichTextBox->Size = System::Drawing::Size(312, 58);
			this->RSetMaterialColorRichTextBox->TabIndex = 364;
			this->RSetMaterialColorRichTextBox->Text = L"#Sand\nMaterialColor0=1.0f 1.0f 0.0f 1.0f\n#Grass\nMaterialColor1=0.13f 0.545f 0.13f" 
				L" 1.0f\n#Rock\nMaterialColor2=0.411764f 0.411764f 0.411764f 1.0f\n#Snow\nMaterialColo" 
				L"r3=1.0f 0.98f 0.98f 1.0f";
			this->RSetMaterialColorRichTextBox->WordWrap = false;
			// 
			// RSetSplatFileNamesLabel
			// 
			this->RSetSplatFileNamesLabel->AutoSize = true;
			this->RSetSplatFileNamesLabel->Location = System::Drawing::Point(37, 353);
			this->RSetSplatFileNamesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RSetSplatFileNamesLabel->Name = L"RSetSplatFileNamesLabel";
			this->RSetSplatFileNamesLabel->Size = System::Drawing::Size(105, 13);
			this->RSetSplatFileNamesLabel->TabIndex = 363;
			this->RSetSplatFileNamesLabel->Text = L"Set Splat File Names";
			// 
			// RSetMaterialColorLabel
			// 
			this->RSetMaterialColorLabel->AutoSize = true;
			this->RSetMaterialColorLabel->Location = System::Drawing::Point(37, 268);
			this->RSetMaterialColorLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RSetMaterialColorLabel->Name = L"RSetMaterialColorLabel";
			this->RSetMaterialColorLabel->Size = System::Drawing::Size(90, 13);
			this->RSetMaterialColorLabel->TabIndex = 362;
			this->RSetMaterialColorLabel->Text = L"Set Material Color";
			// 
			// RSetSplatFileNamesHelp
			// 
			this->RSetSplatFileNamesHelp->Location = System::Drawing::Point(15, 351);
			this->RSetSplatFileNamesHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RSetSplatFileNamesHelp->Name = L"RSetSplatFileNamesHelp";
			this->RSetSplatFileNamesHelp->Size = System::Drawing::Size(17, 19);
			this->RSetSplatFileNamesHelp->TabIndex = 361;
			this->RSetSplatFileNamesHelp->Text = L"\?";
			this->RSetSplatFileNamesHelp->UseVisualStyleBackColor = true;
			// 
			// RSetMaterialColorHelp
			// 
			this->RSetMaterialColorHelp->Location = System::Drawing::Point(15, 266);
			this->RSetMaterialColorHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RSetMaterialColorHelp->Name = L"RSetMaterialColorHelp";
			this->RSetMaterialColorHelp->Size = System::Drawing::Size(17, 19);
			this->RSetMaterialColorHelp->TabIndex = 360;
			this->RSetMaterialColorHelp->Text = L"\?";
			this->RSetMaterialColorHelp->UseVisualStyleBackColor = true;
			// 
			// TextureFormatSupportedRichTextBox
			// 
			this->TextureFormatSupportedRichTextBox->Location = System::Drawing::Point(15, 72);
			this->TextureFormatSupportedRichTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->TextureFormatSupportedRichTextBox->Name = L"TextureFormatSupportedRichTextBox";
			this->TextureFormatSupportedRichTextBox->Size = System::Drawing::Size(312, 58);
			this->TextureFormatSupportedRichTextBox->TabIndex = 359;
			this->TextureFormatSupportedRichTextBox->Text = L"";
			this->TextureFormatSupportedRichTextBox->WordWrap = false;
			// 
			// RNumMatHeightSplatTextBox
			// 
			this->RNumMatHeightSplatTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->RNumMatHeightSplatTextBox->Location = System::Drawing::Point(202, 157);
			this->RNumMatHeightSplatTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RNumMatHeightSplatTextBox->MinimumSize = System::Drawing::Size(126, 22);
			this->RNumMatHeightSplatTextBox->Name = L"RNumMatHeightSplatTextBox";
			this->RNumMatHeightSplatTextBox->ReadOnly = true;
			this->RNumMatHeightSplatTextBox->Size = System::Drawing::Size(126, 22);
			this->RNumMatHeightSplatTextBox->TabIndex = 352;
			this->RNumMatHeightSplatTextBox->Text = L"4";
			// 
			// RNumMatHeightSplatLabel
			// 
			this->RNumMatHeightSplatLabel->AutoSize = true;
			this->RNumMatHeightSplatLabel->Location = System::Drawing::Point(37, 159);
			this->RNumMatHeightSplatLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RNumMatHeightSplatLabel->Name = L"RNumMatHeightSplatLabel";
			this->RNumMatHeightSplatLabel->Size = System::Drawing::Size(105, 13);
			this->RNumMatHeightSplatLabel->TabIndex = 351;
			this->RNumMatHeightSplatLabel->Text = L"NumMatHeightSplat:";
			// 
			// RNumMatHeightSplatHelp
			// 
			this->RNumMatHeightSplatHelp->Location = System::Drawing::Point(15, 157);
			this->RNumMatHeightSplatHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RNumMatHeightSplatHelp->Name = L"RNumMatHeightSplatHelp";
			this->RNumMatHeightSplatHelp->Size = System::Drawing::Size(17, 19);
			this->RNumMatHeightSplatHelp->TabIndex = 350;
			this->RNumMatHeightSplatHelp->Text = L"\?";
			this->RNumMatHeightSplatHelp->UseVisualStyleBackColor = true;
			// 
			// BaseVertexInstantColorCheckBox
			// 
			this->BaseVertexInstantColorCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->BaseVertexInstantColorCheckBox->Location = System::Drawing::Point(36, 554);
			this->BaseVertexInstantColorCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaseVertexInstantColorCheckBox->Name = L"BaseVertexInstantColorCheckBox";
			this->BaseVertexInstantColorCheckBox->Size = System::Drawing::Size(231, 20);
			this->BaseVertexInstantColorCheckBox->TabIndex = 347;
			this->BaseVertexInstantColorCheckBox->Text = L"BaseVertexInstantColor:";
			this->BaseVertexInstantColorCheckBox->UseVisualStyleBackColor = true;
			// 
			// BaseVertexInstantColorHelp
			// 
			this->BaseVertexInstantColorHelp->Location = System::Drawing::Point(15, 554);
			this->BaseVertexInstantColorHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaseVertexInstantColorHelp->Name = L"BaseVertexInstantColorHelp";
			this->BaseVertexInstantColorHelp->Size = System::Drawing::Size(17, 19);
			this->BaseVertexInstantColorHelp->TabIndex = 349;
			this->BaseVertexInstantColorHelp->Text = L"\?";
			this->BaseVertexInstantColorHelp->UseVisualStyleBackColor = true;
			// 
			// BaseVertexShadowCheckBox
			// 
			this->BaseVertexShadowCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->BaseVertexShadowCheckBox->Location = System::Drawing::Point(36, 531);
			this->BaseVertexShadowCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaseVertexShadowCheckBox->Name = L"BaseVertexShadowCheckBox";
			this->BaseVertexShadowCheckBox->Size = System::Drawing::Size(231, 20);
			this->BaseVertexShadowCheckBox->TabIndex = 346;
			this->BaseVertexShadowCheckBox->Text = L"BaseVertexShadow:";
			this->BaseVertexShadowCheckBox->UseVisualStyleBackColor = true;
			// 
			// BaseVertexShadowHelp
			// 
			this->BaseVertexShadowHelp->Location = System::Drawing::Point(15, 531);
			this->BaseVertexShadowHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaseVertexShadowHelp->Name = L"BaseVertexShadowHelp";
			this->BaseVertexShadowHelp->Size = System::Drawing::Size(17, 19);
			this->BaseVertexShadowHelp->TabIndex = 348;
			this->BaseVertexShadowHelp->Text = L"\?";
			this->BaseVertexShadowHelp->UseVisualStyleBackColor = true;
			// 
			// BaseVertexColorCheckBox
			// 
			this->BaseVertexColorCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->BaseVertexColorCheckBox->Location = System::Drawing::Point(36, 506);
			this->BaseVertexColorCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaseVertexColorCheckBox->Name = L"BaseVertexColorCheckBox";
			this->BaseVertexColorCheckBox->Size = System::Drawing::Size(231, 20);
			this->BaseVertexColorCheckBox->TabIndex = 338;
			this->BaseVertexColorCheckBox->Text = L"BaseVertexColor:";
			this->BaseVertexColorCheckBox->UseVisualStyleBackColor = true;
			// 
			// BaseVertexColorHelp
			// 
			this->BaseVertexColorHelp->Location = System::Drawing::Point(15, 507);
			this->BaseVertexColorHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaseVertexColorHelp->Name = L"BaseVertexColorHelp";
			this->BaseVertexColorHelp->Size = System::Drawing::Size(17, 19);
			this->BaseVertexColorHelp->TabIndex = 343;
			this->BaseVertexColorHelp->Text = L"\?";
			this->BaseVertexColorHelp->UseVisualStyleBackColor = true;
			// 
			// VertexColorsCheckBox
			// 
			this->VertexColorsCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->VertexColorsCheckBox->Location = System::Drawing::Point(36, 460);
			this->VertexColorsCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->VertexColorsCheckBox->Name = L"VertexColorsCheckBox";
			this->VertexColorsCheckBox->Size = System::Drawing::Size(231, 20);
			this->VertexColorsCheckBox->TabIndex = 336;
			this->VertexColorsCheckBox->Text = L"VertexColors:";
			this->VertexColorsCheckBox->UseVisualStyleBackColor = true;
			// 
			// VertexColorsHelp
			// 
			this->VertexColorsHelp->Location = System::Drawing::Point(15, 460);
			this->VertexColorsHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->VertexColorsHelp->Name = L"VertexColorsHelp";
			this->VertexColorsHelp->Size = System::Drawing::Size(17, 19);
			this->VertexColorsHelp->TabIndex = 341;
			this->VertexColorsHelp->Text = L"\?";
			this->VertexColorsHelp->UseVisualStyleBackColor = true;
			// 
			// BigImageCheckBox
			// 
			this->BigImageCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->BigImageCheckBox->Location = System::Drawing::Point(36, 436);
			this->BigImageCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BigImageCheckBox->Name = L"BigImageCheckBox";
			this->BigImageCheckBox->Size = System::Drawing::Size(231, 20);
			this->BigImageCheckBox->TabIndex = 335;
			this->BigImageCheckBox->Text = L"BigImage:";
			this->BigImageCheckBox->UseVisualStyleBackColor = true;
			// 
			// BigImageHelp
			// 
			this->BigImageHelp->Location = System::Drawing::Point(15, 436);
			this->BigImageHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BigImageHelp->Name = L"BigImageHelp";
			this->BigImageHelp->Size = System::Drawing::Size(17, 19);
			this->BigImageHelp->TabIndex = 340;
			this->BigImageHelp->Text = L"\?";
			this->BigImageHelp->UseVisualStyleBackColor = true;
			// 
			// CoverageVertexColorCheckBox
			// 
			this->CoverageVertexColorCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->CoverageVertexColorCheckBox->Location = System::Drawing::Point(36, 483);
			this->CoverageVertexColorCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->CoverageVertexColorCheckBox->Name = L"CoverageVertexColorCheckBox";
			this->CoverageVertexColorCheckBox->Size = System::Drawing::Size(231, 20);
			this->CoverageVertexColorCheckBox->TabIndex = 337;
			this->CoverageVertexColorCheckBox->Text = L"CoverageVertexColor:";
			this->CoverageVertexColorCheckBox->UseVisualStyleBackColor = true;
			// 
			// CoverageVertexColorHelp
			// 
			this->CoverageVertexColorHelp->Location = System::Drawing::Point(15, 483);
			this->CoverageVertexColorHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->CoverageVertexColorHelp->Name = L"CoverageVertexColorHelp";
			this->CoverageVertexColorHelp->Size = System::Drawing::Size(17, 19);
			this->CoverageVertexColorHelp->TabIndex = 342;
			this->CoverageVertexColorHelp->Text = L"\?";
			this->CoverageVertexColorHelp->UseVisualStyleBackColor = true;
			// 
			// TextureFormatTextBox
			// 
			this->TextureFormatTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->TextureFormatTextBox->Location = System::Drawing::Point(202, 133);
			this->TextureFormatTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->TextureFormatTextBox->MinimumSize = System::Drawing::Size(126, 22);
			this->TextureFormatTextBox->Name = L"TextureFormatTextBox";
			this->TextureFormatTextBox->Size = System::Drawing::Size(126, 22);
			this->TextureFormatTextBox->TabIndex = 332;
			this->TextureFormatTextBox->Text = L"ImagePaging";
			// 
			// TextureFormatLabel
			// 
			this->TextureFormatLabel->AutoSize = true;
			this->TextureFormatLabel->Location = System::Drawing::Point(37, 136);
			this->TextureFormatLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->TextureFormatLabel->Name = L"TextureFormatLabel";
			this->TextureFormatLabel->Size = System::Drawing::Size(78, 13);
			this->TextureFormatLabel->TabIndex = 334;
			this->TextureFormatLabel->Text = L"TextureFormat:";
			// 
			// TextureFormatHelp
			// 
			this->TextureFormatHelp->Location = System::Drawing::Point(15, 133);
			this->TextureFormatHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->TextureFormatHelp->Name = L"TextureFormatHelp";
			this->TextureFormatHelp->Size = System::Drawing::Size(17, 19);
			this->TextureFormatHelp->TabIndex = 333;
			this->TextureFormatHelp->Text = L"\?";
			this->TextureFormatHelp->UseVisualStyleBackColor = true;
			// 
			// NumTextureFormatSupportedTextBox
			// 
			this->NumTextureFormatSupportedTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->NumTextureFormatSupportedTextBox->Location = System::Drawing::Point(202, 48);
			this->NumTextureFormatSupportedTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->NumTextureFormatSupportedTextBox->MinimumSize = System::Drawing::Size(126, 22);
			this->NumTextureFormatSupportedTextBox->Name = L"NumTextureFormatSupportedTextBox";
			this->NumTextureFormatSupportedTextBox->Size = System::Drawing::Size(126, 22);
			this->NumTextureFormatSupportedTextBox->TabIndex = 329;
			this->NumTextureFormatSupportedTextBox->Text = L"16";
			// 
			// NumTextureFormatSupportedLabel
			// 
			this->NumTextureFormatSupportedLabel->AutoSize = true;
			this->NumTextureFormatSupportedLabel->Location = System::Drawing::Point(37, 50);
			this->NumTextureFormatSupportedLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->NumTextureFormatSupportedLabel->Name = L"NumTextureFormatSupportedLabel";
			this->NumTextureFormatSupportedLabel->Size = System::Drawing::Size(149, 13);
			this->NumTextureFormatSupportedLabel->TabIndex = 331;
			this->NumTextureFormatSupportedLabel->Text = L"NumTextureFormatSupported:";
			// 
			// NumTextureFormatSupportedHelp
			// 
			this->NumTextureFormatSupportedHelp->Location = System::Drawing::Point(15, 48);
			this->NumTextureFormatSupportedHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->NumTextureFormatSupportedHelp->Name = L"NumTextureFormatSupportedHelp";
			this->NumTextureFormatSupportedHelp->Size = System::Drawing::Size(17, 19);
			this->NumTextureFormatSupportedHelp->TabIndex = 330;
			this->NumTextureFormatSupportedHelp->Text = L"\?";
			this->NumTextureFormatSupportedHelp->UseVisualStyleBackColor = true;
			// 
			// RColorMapStretchFactorTextBox
			// 
			this->RColorMapStretchFactorTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->RColorMapStretchFactorTextBox->Location = System::Drawing::Point(202, 24);
			this->RColorMapStretchFactorTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RColorMapStretchFactorTextBox->MinimumSize = System::Drawing::Size(126, 22);
			this->RColorMapStretchFactorTextBox->Name = L"RColorMapStretchFactorTextBox";
			this->RColorMapStretchFactorTextBox->ReadOnly = true;
			this->RColorMapStretchFactorTextBox->Size = System::Drawing::Size(126, 22);
			this->RColorMapStretchFactorTextBox->TabIndex = 324;
			this->RColorMapStretchFactorTextBox->Text = L"2";
			// 
			// RColorMapStretchFactorLabel
			// 
			this->RColorMapStretchFactorLabel->AutoSize = true;
			this->RColorMapStretchFactorLabel->Location = System::Drawing::Point(37, 27);
			this->RColorMapStretchFactorLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RColorMapStretchFactorLabel->Name = L"RColorMapStretchFactorLabel";
			this->RColorMapStretchFactorLabel->Size = System::Drawing::Size(119, 13);
			this->RColorMapStretchFactorLabel->TabIndex = 328;
			this->RColorMapStretchFactorLabel->Text = L"ColorMapStretchFactor:";
			// 
			// RColorMapStretchFactorHelp
			// 
			this->RColorMapStretchFactorHelp->Location = System::Drawing::Point(15, 24);
			this->RColorMapStretchFactorHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RColorMapStretchFactorHelp->Name = L"RColorMapStretchFactorHelp";
			this->RColorMapStretchFactorHelp->Size = System::Drawing::Size(17, 19);
			this->RColorMapStretchFactorHelp->TabIndex = 327;
			this->RColorMapStretchFactorHelp->Text = L"\?";
			this->RColorMapStretchFactorHelp->UseVisualStyleBackColor = true;
			// 
			// RPerformanceTabPage
			// 
			this->RPerformanceTabPage->Controls->Add(this->HorizonVisibilityComputingCheckBox);
			this->RPerformanceTabPage->Controls->Add(this->HorizonVisibilityComputingHelp);
			this->RPerformanceTabPage->Controls->Add(this->IncrementTilesTextBox);
			this->RPerformanceTabPage->Controls->Add(this->IncrementTilesLabel);
			this->RPerformanceTabPage->Controls->Add(this->IncrementTilesHelp);
			this->RPerformanceTabPage->Controls->Add(this->MaxNumRenderablesTextBox);
			this->RPerformanceTabPage->Controls->Add(this->MaxNumTilesTextBox);
			this->RPerformanceTabPage->Controls->Add(this->MaxNumTilesLabel);
			this->RPerformanceTabPage->Controls->Add(this->MaxNumTilesHelp);
			this->RPerformanceTabPage->Controls->Add(this->IncrementRenderablesTextBox);
			this->RPerformanceTabPage->Controls->Add(this->IncrementRenderablesLabel);
			this->RPerformanceTabPage->Controls->Add(this->IncrementRenderablesHelp);
			this->RPerformanceTabPage->Controls->Add(this->MaxNumRenderablesLabel);
			this->RPerformanceTabPage->Controls->Add(this->MaxNumRenderablesHelp);
			this->RPerformanceTabPage->Controls->Add(this->CameraThresholdTextBox);
			this->RPerformanceTabPage->Controls->Add(this->CameraThresholdHelp);
			this->RPerformanceTabPage->Controls->Add(this->CameraThresholdLabel);
			this->RPerformanceTabPage->Controls->Add(this->ChangeFactorHelp);
			this->RPerformanceTabPage->Controls->Add(this->ChangeFactorTextBox);
			this->RPerformanceTabPage->Controls->Add(this->ChangeFactorLabel);
			this->RPerformanceTabPage->Controls->Add(this->MaxPreloadedPagesTextBox);
			this->RPerformanceTabPage->Controls->Add(this->MaxPreloadedPagesLabel);
			this->RPerformanceTabPage->Controls->Add(this->MaxPreloadedPagesHelp);
			this->RPerformanceTabPage->Controls->Add(this->MaxRenderLevelTextBox);
			this->RPerformanceTabPage->Controls->Add(this->MaxAdjacentPagesTextBox);
			this->RPerformanceTabPage->Controls->Add(this->MaxAdjacentPagesLabel);
			this->RPerformanceTabPage->Controls->Add(this->MaxAdjacentPagesHelp);
			this->RPerformanceTabPage->Controls->Add(this->NumRenderablesLoadingTextBox);
			this->RPerformanceTabPage->Controls->Add(this->NumRenderablesLoadingLabel);
			this->RPerformanceTabPage->Controls->Add(this->NumRenderablesLoadingHelp);
			this->RPerformanceTabPage->Controls->Add(this->MaxRenderLevelLabel);
			this->RPerformanceTabPage->Controls->Add(this->MaxRenderLevelHelp);
			this->RPerformanceTabPage->Controls->Add(this->DistanceLODTextBox);
			this->RPerformanceTabPage->Controls->Add(this->DistanceLODHelp);
			this->RPerformanceTabPage->Controls->Add(this->DistanceLODLabel);
			this->RPerformanceTabPage->Controls->Add(this->VisibleRenderablesHelp);
			this->RPerformanceTabPage->Controls->Add(this->VisibleRenderablesTextBox);
			this->RPerformanceTabPage->Controls->Add(this->VisibleRenderablesLabel);
			this->RPerformanceTabPage->Location = System::Drawing::Point(3, 20);
			this->RPerformanceTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RPerformanceTabPage->Name = L"RPerformanceTabPage";
			this->RPerformanceTabPage->Size = System::Drawing::Size(354, 545);
			this->RPerformanceTabPage->TabIndex = 5;
			this->RPerformanceTabPage->Text = L"Performance";
			this->RPerformanceTabPage->UseVisualStyleBackColor = true;
			// 
			// HorizonVisibilityComputingCheckBox
			// 
			this->HorizonVisibilityComputingCheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->HorizonVisibilityComputingCheckBox->Checked = true;
			this->HorizonVisibilityComputingCheckBox->CheckState = System::Windows::Forms::CheckState::Checked;
			this->HorizonVisibilityComputingCheckBox->Location = System::Drawing::Point(36, 310);
			this->HorizonVisibilityComputingCheckBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HorizonVisibilityComputingCheckBox->Name = L"HorizonVisibilityComputingCheckBox";
			this->HorizonVisibilityComputingCheckBox->Size = System::Drawing::Size(231, 20);
			this->HorizonVisibilityComputingCheckBox->TabIndex = 340;
			this->HorizonVisibilityComputingCheckBox->Text = L"HorizonVisibilityComputing:";
			this->HorizonVisibilityComputingCheckBox->UseVisualStyleBackColor = true;
			// 
			// HorizonVisibilityComputingHelp
			// 
			this->HorizonVisibilityComputingHelp->Location = System::Drawing::Point(15, 310);
			this->HorizonVisibilityComputingHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->HorizonVisibilityComputingHelp->Name = L"HorizonVisibilityComputingHelp";
			this->HorizonVisibilityComputingHelp->Size = System::Drawing::Size(17, 19);
			this->HorizonVisibilityComputingHelp->TabIndex = 339;
			this->HorizonVisibilityComputingHelp->Text = L"\?";
			this->HorizonVisibilityComputingHelp->UseVisualStyleBackColor = true;
			// 
			// IncrementTilesTextBox
			// 
			this->IncrementTilesTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->IncrementTilesTextBox->Location = System::Drawing::Point(187, 284);
			this->IncrementTilesTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->IncrementTilesTextBox->Name = L"IncrementTilesTextBox";
			this->IncrementTilesTextBox->Size = System::Drawing::Size(145, 20);
			this->IncrementTilesTextBox->TabIndex = 326;
			this->IncrementTilesTextBox->Text = L"256";
			// 
			// IncrementTilesLabel
			// 
			this->IncrementTilesLabel->AutoSize = true;
			this->IncrementTilesLabel->Location = System::Drawing::Point(37, 286);
			this->IncrementTilesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->IncrementTilesLabel->Name = L"IncrementTilesLabel";
			this->IncrementTilesLabel->Size = System::Drawing::Size(79, 13);
			this->IncrementTilesLabel->TabIndex = 338;
			this->IncrementTilesLabel->Text = L"IncrementTiles:";
			// 
			// IncrementTilesHelp
			// 
			this->IncrementTilesHelp->Location = System::Drawing::Point(15, 284);
			this->IncrementTilesHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->IncrementTilesHelp->Name = L"IncrementTilesHelp";
			this->IncrementTilesHelp->Size = System::Drawing::Size(17, 19);
			this->IncrementTilesHelp->TabIndex = 337;
			this->IncrementTilesHelp->Text = L"\?";
			this->IncrementTilesHelp->UseVisualStyleBackColor = true;
			// 
			// MaxNumRenderablesTextBox
			// 
			this->MaxNumRenderablesTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->MaxNumRenderablesTextBox->Location = System::Drawing::Point(187, 213);
			this->MaxNumRenderablesTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaxNumRenderablesTextBox->Name = L"MaxNumRenderablesTextBox";
			this->MaxNumRenderablesTextBox->Size = System::Drawing::Size(145, 20);
			this->MaxNumRenderablesTextBox->TabIndex = 323;
			this->MaxNumRenderablesTextBox->Text = L"256";
			// 
			// MaxNumTilesTextBox
			// 
			this->MaxNumTilesTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->MaxNumTilesTextBox->Location = System::Drawing::Point(187, 260);
			this->MaxNumTilesTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaxNumTilesTextBox->Name = L"MaxNumTilesTextBox";
			this->MaxNumTilesTextBox->Size = System::Drawing::Size(145, 20);
			this->MaxNumTilesTextBox->TabIndex = 325;
			this->MaxNumTilesTextBox->Text = L"256";
			// 
			// MaxNumTilesLabel
			// 
			this->MaxNumTilesLabel->AutoSize = true;
			this->MaxNumTilesLabel->Location = System::Drawing::Point(37, 262);
			this->MaxNumTilesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->MaxNumTilesLabel->Name = L"MaxNumTilesLabel";
			this->MaxNumTilesLabel->Size = System::Drawing::Size(74, 13);
			this->MaxNumTilesLabel->TabIndex = 331;
			this->MaxNumTilesLabel->Text = L"MaxNumTiles:";
			// 
			// MaxNumTilesHelp
			// 
			this->MaxNumTilesHelp->Location = System::Drawing::Point(15, 260);
			this->MaxNumTilesHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaxNumTilesHelp->Name = L"MaxNumTilesHelp";
			this->MaxNumTilesHelp->Size = System::Drawing::Size(17, 19);
			this->MaxNumTilesHelp->TabIndex = 336;
			this->MaxNumTilesHelp->Text = L"\?";
			this->MaxNumTilesHelp->UseVisualStyleBackColor = true;
			// 
			// IncrementRenderablesTextBox
			// 
			this->IncrementRenderablesTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->IncrementRenderablesTextBox->Location = System::Drawing::Point(187, 236);
			this->IncrementRenderablesTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->IncrementRenderablesTextBox->Name = L"IncrementRenderablesTextBox";
			this->IncrementRenderablesTextBox->Size = System::Drawing::Size(145, 20);
			this->IncrementRenderablesTextBox->TabIndex = 324;
			this->IncrementRenderablesTextBox->Text = L"256";
			// 
			// IncrementRenderablesLabel
			// 
			this->IncrementRenderablesLabel->AutoSize = true;
			this->IncrementRenderablesLabel->Location = System::Drawing::Point(37, 239);
			this->IncrementRenderablesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->IncrementRenderablesLabel->Name = L"IncrementRenderablesLabel";
			this->IncrementRenderablesLabel->Size = System::Drawing::Size(117, 13);
			this->IncrementRenderablesLabel->TabIndex = 330;
			this->IncrementRenderablesLabel->Text = L"IncrementRenderables:";
			// 
			// IncrementRenderablesHelp
			// 
			this->IncrementRenderablesHelp->Location = System::Drawing::Point(15, 236);
			this->IncrementRenderablesHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->IncrementRenderablesHelp->Name = L"IncrementRenderablesHelp";
			this->IncrementRenderablesHelp->Size = System::Drawing::Size(17, 19);
			this->IncrementRenderablesHelp->TabIndex = 335;
			this->IncrementRenderablesHelp->Text = L"\?";
			this->IncrementRenderablesHelp->UseVisualStyleBackColor = true;
			// 
			// MaxNumRenderablesLabel
			// 
			this->MaxNumRenderablesLabel->AutoSize = true;
			this->MaxNumRenderablesLabel->Location = System::Drawing::Point(37, 215);
			this->MaxNumRenderablesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->MaxNumRenderablesLabel->Name = L"MaxNumRenderablesLabel";
			this->MaxNumRenderablesLabel->Size = System::Drawing::Size(112, 13);
			this->MaxNumRenderablesLabel->TabIndex = 329;
			this->MaxNumRenderablesLabel->Text = L"MaxNumRenderables:";
			// 
			// MaxNumRenderablesHelp
			// 
			this->MaxNumRenderablesHelp->Location = System::Drawing::Point(15, 213);
			this->MaxNumRenderablesHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaxNumRenderablesHelp->Name = L"MaxNumRenderablesHelp";
			this->MaxNumRenderablesHelp->Size = System::Drawing::Size(17, 19);
			this->MaxNumRenderablesHelp->TabIndex = 334;
			this->MaxNumRenderablesHelp->Text = L"\?";
			this->MaxNumRenderablesHelp->UseVisualStyleBackColor = true;
			// 
			// CameraThresholdTextBox
			// 
			this->CameraThresholdTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->CameraThresholdTextBox->Location = System::Drawing::Point(187, 189);
			this->CameraThresholdTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->CameraThresholdTextBox->Name = L"CameraThresholdTextBox";
			this->CameraThresholdTextBox->Size = System::Drawing::Size(145, 20);
			this->CameraThresholdTextBox->TabIndex = 322;
			this->CameraThresholdTextBox->Text = L"5";
			// 
			// CameraThresholdHelp
			// 
			this->CameraThresholdHelp->Location = System::Drawing::Point(15, 189);
			this->CameraThresholdHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->CameraThresholdHelp->Name = L"CameraThresholdHelp";
			this->CameraThresholdHelp->Size = System::Drawing::Size(17, 19);
			this->CameraThresholdHelp->TabIndex = 333;
			this->CameraThresholdHelp->Text = L"\?";
			this->CameraThresholdHelp->UseVisualStyleBackColor = true;
			// 
			// CameraThresholdLabel
			// 
			this->CameraThresholdLabel->AutoSize = true;
			this->CameraThresholdLabel->Location = System::Drawing::Point(37, 192);
			this->CameraThresholdLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->CameraThresholdLabel->Name = L"CameraThresholdLabel";
			this->CameraThresholdLabel->Size = System::Drawing::Size(93, 13);
			this->CameraThresholdLabel->TabIndex = 328;
			this->CameraThresholdLabel->Text = L"CameraThreshold:";
			// 
			// ChangeFactorHelp
			// 
			this->ChangeFactorHelp->Location = System::Drawing::Point(15, 166);
			this->ChangeFactorHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ChangeFactorHelp->Name = L"ChangeFactorHelp";
			this->ChangeFactorHelp->Size = System::Drawing::Size(17, 19);
			this->ChangeFactorHelp->TabIndex = 332;
			this->ChangeFactorHelp->Text = L"\?";
			this->ChangeFactorHelp->UseVisualStyleBackColor = true;
			// 
			// ChangeFactorTextBox
			// 
			this->ChangeFactorTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->ChangeFactorTextBox->Location = System::Drawing::Point(187, 166);
			this->ChangeFactorTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->ChangeFactorTextBox->Name = L"ChangeFactorTextBox";
			this->ChangeFactorTextBox->Size = System::Drawing::Size(145, 20);
			this->ChangeFactorTextBox->TabIndex = 321;
			this->ChangeFactorTextBox->Text = L"1.5";
			// 
			// ChangeFactorLabel
			// 
			this->ChangeFactorLabel->AutoSize = true;
			this->ChangeFactorLabel->Location = System::Drawing::Point(37, 171);
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
			this->MaxPreloadedPagesTextBox->Location = System::Drawing::Point(187, 142);
			this->MaxPreloadedPagesTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaxPreloadedPagesTextBox->Name = L"MaxPreloadedPagesTextBox";
			this->MaxPreloadedPagesTextBox->Size = System::Drawing::Size(145, 20);
			this->MaxPreloadedPagesTextBox->TabIndex = 308;
			this->MaxPreloadedPagesTextBox->Text = L"3";
			// 
			// MaxPreloadedPagesLabel
			// 
			this->MaxPreloadedPagesLabel->AutoSize = true;
			this->MaxPreloadedPagesLabel->Location = System::Drawing::Point(37, 145);
			this->MaxPreloadedPagesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->MaxPreloadedPagesLabel->Name = L"MaxPreloadedPagesLabel";
			this->MaxPreloadedPagesLabel->Size = System::Drawing::Size(108, 13);
			this->MaxPreloadedPagesLabel->TabIndex = 320;
			this->MaxPreloadedPagesLabel->Text = L"MaxPreloadedPages:";
			// 
			// MaxPreloadedPagesHelp
			// 
			this->MaxPreloadedPagesHelp->Location = System::Drawing::Point(15, 142);
			this->MaxPreloadedPagesHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaxPreloadedPagesHelp->Name = L"MaxPreloadedPagesHelp";
			this->MaxPreloadedPagesHelp->Size = System::Drawing::Size(17, 19);
			this->MaxPreloadedPagesHelp->TabIndex = 319;
			this->MaxPreloadedPagesHelp->Text = L"\?";
			this->MaxPreloadedPagesHelp->UseVisualStyleBackColor = true;
			// 
			// MaxRenderLevelTextBox
			// 
			this->MaxRenderLevelTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->MaxRenderLevelTextBox->Location = System::Drawing::Point(187, 72);
			this->MaxRenderLevelTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaxRenderLevelTextBox->Name = L"MaxRenderLevelTextBox";
			this->MaxRenderLevelTextBox->Size = System::Drawing::Size(145, 20);
			this->MaxRenderLevelTextBox->TabIndex = 305;
			this->MaxRenderLevelTextBox->Text = L"5";
			// 
			// MaxAdjacentPagesTextBox
			// 
			this->MaxAdjacentPagesTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->MaxAdjacentPagesTextBox->Location = System::Drawing::Point(187, 119);
			this->MaxAdjacentPagesTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaxAdjacentPagesTextBox->Name = L"MaxAdjacentPagesTextBox";
			this->MaxAdjacentPagesTextBox->Size = System::Drawing::Size(145, 20);
			this->MaxAdjacentPagesTextBox->TabIndex = 307;
			this->MaxAdjacentPagesTextBox->Text = L"2";
			// 
			// MaxAdjacentPagesLabel
			// 
			this->MaxAdjacentPagesLabel->AutoSize = true;
			this->MaxAdjacentPagesLabel->Location = System::Drawing::Point(37, 121);
			this->MaxAdjacentPagesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->MaxAdjacentPagesLabel->Name = L"MaxAdjacentPagesLabel";
			this->MaxAdjacentPagesLabel->Size = System::Drawing::Size(102, 13);
			this->MaxAdjacentPagesLabel->TabIndex = 313;
			this->MaxAdjacentPagesLabel->Text = L"MaxAdjacentPages:";
			// 
			// MaxAdjacentPagesHelp
			// 
			this->MaxAdjacentPagesHelp->Location = System::Drawing::Point(15, 119);
			this->MaxAdjacentPagesHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaxAdjacentPagesHelp->Name = L"MaxAdjacentPagesHelp";
			this->MaxAdjacentPagesHelp->Size = System::Drawing::Size(17, 19);
			this->MaxAdjacentPagesHelp->TabIndex = 318;
			this->MaxAdjacentPagesHelp->Text = L"\?";
			this->MaxAdjacentPagesHelp->UseVisualStyleBackColor = true;
			// 
			// NumRenderablesLoadingTextBox
			// 
			this->NumRenderablesLoadingTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->NumRenderablesLoadingTextBox->Location = System::Drawing::Point(187, 95);
			this->NumRenderablesLoadingTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->NumRenderablesLoadingTextBox->Name = L"NumRenderablesLoadingTextBox";
			this->NumRenderablesLoadingTextBox->Size = System::Drawing::Size(145, 20);
			this->NumRenderablesLoadingTextBox->TabIndex = 306;
			this->NumRenderablesLoadingTextBox->Text = L"50";
			// 
			// NumRenderablesLoadingLabel
			// 
			this->NumRenderablesLoadingLabel->AutoSize = true;
			this->NumRenderablesLoadingLabel->Location = System::Drawing::Point(37, 98);
			this->NumRenderablesLoadingLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->NumRenderablesLoadingLabel->Name = L"NumRenderablesLoadingLabel";
			this->NumRenderablesLoadingLabel->Size = System::Drawing::Size(130, 13);
			this->NumRenderablesLoadingLabel->TabIndex = 312;
			this->NumRenderablesLoadingLabel->Text = L"NumRenderablesLoading:";
			// 
			// NumRenderablesLoadingHelp
			// 
			this->NumRenderablesLoadingHelp->Location = System::Drawing::Point(15, 95);
			this->NumRenderablesLoadingHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->NumRenderablesLoadingHelp->Name = L"NumRenderablesLoadingHelp";
			this->NumRenderablesLoadingHelp->Size = System::Drawing::Size(17, 19);
			this->NumRenderablesLoadingHelp->TabIndex = 317;
			this->NumRenderablesLoadingHelp->Text = L"\?";
			this->NumRenderablesLoadingHelp->UseVisualStyleBackColor = true;
			// 
			// MaxRenderLevelLabel
			// 
			this->MaxRenderLevelLabel->AutoSize = true;
			this->MaxRenderLevelLabel->Location = System::Drawing::Point(37, 74);
			this->MaxRenderLevelLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->MaxRenderLevelLabel->Name = L"MaxRenderLevelLabel";
			this->MaxRenderLevelLabel->Size = System::Drawing::Size(91, 13);
			this->MaxRenderLevelLabel->TabIndex = 311;
			this->MaxRenderLevelLabel->Text = L"MaxRenderLevel:";
			// 
			// MaxRenderLevelHelp
			// 
			this->MaxRenderLevelHelp->Location = System::Drawing::Point(15, 72);
			this->MaxRenderLevelHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaxRenderLevelHelp->Name = L"MaxRenderLevelHelp";
			this->MaxRenderLevelHelp->Size = System::Drawing::Size(17, 19);
			this->MaxRenderLevelHelp->TabIndex = 316;
			this->MaxRenderLevelHelp->Text = L"\?";
			this->MaxRenderLevelHelp->UseVisualStyleBackColor = true;
			// 
			// DistanceLODTextBox
			// 
			this->DistanceLODTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->DistanceLODTextBox->Location = System::Drawing::Point(187, 48);
			this->DistanceLODTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->DistanceLODTextBox->Name = L"DistanceLODTextBox";
			this->DistanceLODTextBox->Size = System::Drawing::Size(145, 20);
			this->DistanceLODTextBox->TabIndex = 304;
			this->DistanceLODTextBox->Text = L"5";
			// 
			// DistanceLODHelp
			// 
			this->DistanceLODHelp->Location = System::Drawing::Point(15, 48);
			this->DistanceLODHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->DistanceLODHelp->Name = L"DistanceLODHelp";
			this->DistanceLODHelp->Size = System::Drawing::Size(17, 19);
			this->DistanceLODHelp->TabIndex = 315;
			this->DistanceLODHelp->Text = L"\?";
			this->DistanceLODHelp->UseVisualStyleBackColor = true;
			// 
			// DistanceLODLabel
			// 
			this->DistanceLODLabel->AutoSize = true;
			this->DistanceLODLabel->Location = System::Drawing::Point(37, 50);
			this->DistanceLODLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->DistanceLODLabel->Name = L"DistanceLODLabel";
			this->DistanceLODLabel->Size = System::Drawing::Size(74, 13);
			this->DistanceLODLabel->TabIndex = 310;
			this->DistanceLODLabel->Text = L"DistanceLOD:";
			// 
			// VisibleRenderablesHelp
			// 
			this->VisibleRenderablesHelp->Location = System::Drawing::Point(15, 24);
			this->VisibleRenderablesHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->VisibleRenderablesHelp->Name = L"VisibleRenderablesHelp";
			this->VisibleRenderablesHelp->Size = System::Drawing::Size(17, 19);
			this->VisibleRenderablesHelp->TabIndex = 314;
			this->VisibleRenderablesHelp->Text = L"\?";
			this->VisibleRenderablesHelp->UseVisualStyleBackColor = true;
			// 
			// VisibleRenderablesTextBox
			// 
			this->VisibleRenderablesTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->VisibleRenderablesTextBox->Location = System::Drawing::Point(187, 24);
			this->VisibleRenderablesTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->VisibleRenderablesTextBox->Name = L"VisibleRenderablesTextBox";
			this->VisibleRenderablesTextBox->Size = System::Drawing::Size(145, 20);
			this->VisibleRenderablesTextBox->TabIndex = 303;
			this->VisibleRenderablesTextBox->Text = L"200";
			// 
			// VisibleRenderablesLabel
			// 
			this->VisibleRenderablesLabel->AutoSize = true;
			this->VisibleRenderablesLabel->Location = System::Drawing::Point(37, 27);
			this->VisibleRenderablesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->VisibleRenderablesLabel->Name = L"VisibleRenderablesLabel";
			this->VisibleRenderablesLabel->Size = System::Drawing::Size(100, 13);
			this->VisibleRenderablesLabel->TabIndex = 309;
			this->VisibleRenderablesLabel->Text = L"VisibleRenderables:";
			// 
			// RCameraTabPage
			// 
			this->RCameraTabPage->Controls->Add(this->BaselookatzTextBox);
			this->RCameraTabPage->Controls->Add(this->BaselookatzLabel);
			this->RCameraTabPage->Controls->Add(this->BaselookatzHelp);
			this->RCameraTabPage->Controls->Add(this->BaseCameraViewpointzTextBox);
			this->RCameraTabPage->Controls->Add(this->BaselookatyTextBox);
			this->RCameraTabPage->Controls->Add(this->BaselookatyLabel);
			this->RCameraTabPage->Controls->Add(this->BaselookatyHelp);
			this->RCameraTabPage->Controls->Add(this->BaselookatxTextBox);
			this->RCameraTabPage->Controls->Add(this->BaselookatxLabel);
			this->RCameraTabPage->Controls->Add(this->BaselookatxHelp);
			this->RCameraTabPage->Controls->Add(this->BaseCameraViewpointzLabel);
			this->RCameraTabPage->Controls->Add(this->BaseCameraViewpointzHelp);
			this->RCameraTabPage->Controls->Add(this->BaseCameraViewpointyTextBox);
			this->RCameraTabPage->Controls->Add(this->BaseCameraViewpointyHelp);
			this->RCameraTabPage->Controls->Add(this->BaseCameraViewpointyLabel);
			this->RCameraTabPage->Controls->Add(this->BaseCameraViewpointxHelp);
			this->RCameraTabPage->Controls->Add(this->BaseCameraViewpointxTextBox);
			this->RCameraTabPage->Controls->Add(this->BaseCameraViewpointxLabel);
			this->RCameraTabPage->Location = System::Drawing::Point(3, 20);
			this->RCameraTabPage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RCameraTabPage->Name = L"RCameraTabPage";
			this->RCameraTabPage->Size = System::Drawing::Size(354, 545);
			this->RCameraTabPage->TabIndex = 6;
			this->RCameraTabPage->Text = L"Camera";
			this->RCameraTabPage->UseVisualStyleBackColor = true;
			// 
			// BaselookatzTextBox
			// 
			this->BaselookatzTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->BaselookatzTextBox->Location = System::Drawing::Point(187, 142);
			this->BaselookatzTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaselookatzTextBox->Name = L"BaselookatzTextBox";
			this->BaselookatzTextBox->Size = System::Drawing::Size(145, 20);
			this->BaselookatzTextBox->TabIndex = 326;
			this->BaselookatzTextBox->Text = L"0.0f";
			// 
			// BaselookatzLabel
			// 
			this->BaselookatzLabel->AutoSize = true;
			this->BaselookatzLabel->Location = System::Drawing::Point(37, 145);
			this->BaselookatzLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->BaselookatzLabel->Name = L"BaselookatzLabel";
			this->BaselookatzLabel->Size = System::Drawing::Size(71, 13);
			this->BaselookatzLabel->TabIndex = 338;
			this->BaselookatzLabel->Text = L"Baselookat.z:";
			// 
			// BaselookatzHelp
			// 
			this->BaselookatzHelp->Location = System::Drawing::Point(15, 142);
			this->BaselookatzHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaselookatzHelp->Name = L"BaselookatzHelp";
			this->BaselookatzHelp->Size = System::Drawing::Size(17, 19);
			this->BaselookatzHelp->TabIndex = 337;
			this->BaselookatzHelp->Text = L"\?";
			this->BaselookatzHelp->UseVisualStyleBackColor = true;
			// 
			// BaseCameraViewpointzTextBox
			// 
			this->BaseCameraViewpointzTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->BaseCameraViewpointzTextBox->Location = System::Drawing::Point(187, 72);
			this->BaseCameraViewpointzTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaseCameraViewpointzTextBox->Name = L"BaseCameraViewpointzTextBox";
			this->BaseCameraViewpointzTextBox->Size = System::Drawing::Size(145, 20);
			this->BaseCameraViewpointzTextBox->TabIndex = 323;
			this->BaseCameraViewpointzTextBox->Text = L"0.0f";
			// 
			// BaselookatyTextBox
			// 
			this->BaselookatyTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->BaselookatyTextBox->Location = System::Drawing::Point(187, 119);
			this->BaselookatyTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaselookatyTextBox->Name = L"BaselookatyTextBox";
			this->BaselookatyTextBox->Size = System::Drawing::Size(145, 20);
			this->BaselookatyTextBox->TabIndex = 325;
			this->BaselookatyTextBox->Text = L"0.0f";
			// 
			// BaselookatyLabel
			// 
			this->BaselookatyLabel->AutoSize = true;
			this->BaselookatyLabel->Location = System::Drawing::Point(37, 121);
			this->BaselookatyLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->BaselookatyLabel->Name = L"BaselookatyLabel";
			this->BaselookatyLabel->Size = System::Drawing::Size(71, 13);
			this->BaselookatyLabel->TabIndex = 331;
			this->BaselookatyLabel->Text = L"Baselookat.y:";
			// 
			// BaselookatyHelp
			// 
			this->BaselookatyHelp->Location = System::Drawing::Point(15, 119);
			this->BaselookatyHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaselookatyHelp->Name = L"BaselookatyHelp";
			this->BaselookatyHelp->Size = System::Drawing::Size(17, 19);
			this->BaselookatyHelp->TabIndex = 336;
			this->BaselookatyHelp->Text = L"\?";
			this->BaselookatyHelp->UseVisualStyleBackColor = true;
			// 
			// BaselookatxTextBox
			// 
			this->BaselookatxTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->BaselookatxTextBox->Location = System::Drawing::Point(187, 95);
			this->BaselookatxTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaselookatxTextBox->Name = L"BaselookatxTextBox";
			this->BaselookatxTextBox->Size = System::Drawing::Size(145, 20);
			this->BaselookatxTextBox->TabIndex = 324;
			this->BaselookatxTextBox->Text = L"0.0f";
			// 
			// BaselookatxLabel
			// 
			this->BaselookatxLabel->AutoSize = true;
			this->BaselookatxLabel->Location = System::Drawing::Point(37, 98);
			this->BaselookatxLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->BaselookatxLabel->Name = L"BaselookatxLabel";
			this->BaselookatxLabel->Size = System::Drawing::Size(71, 13);
			this->BaselookatxLabel->TabIndex = 330;
			this->BaselookatxLabel->Text = L"Baselookat.x:";
			// 
			// BaselookatxHelp
			// 
			this->BaselookatxHelp->Location = System::Drawing::Point(15, 95);
			this->BaselookatxHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaselookatxHelp->Name = L"BaselookatxHelp";
			this->BaselookatxHelp->Size = System::Drawing::Size(17, 19);
			this->BaselookatxHelp->TabIndex = 335;
			this->BaselookatxHelp->Text = L"\?";
			this->BaselookatxHelp->UseVisualStyleBackColor = true;
			// 
			// BaseCameraViewpointzLabel
			// 
			this->BaseCameraViewpointzLabel->AutoSize = true;
			this->BaseCameraViewpointzLabel->Location = System::Drawing::Point(37, 74);
			this->BaseCameraViewpointzLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->BaseCameraViewpointzLabel->Name = L"BaseCameraViewpointzLabel";
			this->BaseCameraViewpointzLabel->Size = System::Drawing::Size(124, 13);
			this->BaseCameraViewpointzLabel->TabIndex = 329;
			this->BaseCameraViewpointzLabel->Text = L"BaseCameraViewpoint.z:";
			// 
			// BaseCameraViewpointzHelp
			// 
			this->BaseCameraViewpointzHelp->Location = System::Drawing::Point(15, 72);
			this->BaseCameraViewpointzHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaseCameraViewpointzHelp->Name = L"BaseCameraViewpointzHelp";
			this->BaseCameraViewpointzHelp->Size = System::Drawing::Size(17, 19);
			this->BaseCameraViewpointzHelp->TabIndex = 334;
			this->BaseCameraViewpointzHelp->Text = L"\?";
			this->BaseCameraViewpointzHelp->UseVisualStyleBackColor = true;
			// 
			// BaseCameraViewpointyTextBox
			// 
			this->BaseCameraViewpointyTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->BaseCameraViewpointyTextBox->Location = System::Drawing::Point(187, 48);
			this->BaseCameraViewpointyTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaseCameraViewpointyTextBox->Name = L"BaseCameraViewpointyTextBox";
			this->BaseCameraViewpointyTextBox->Size = System::Drawing::Size(145, 20);
			this->BaseCameraViewpointyTextBox->TabIndex = 322;
			this->BaseCameraViewpointyTextBox->Text = L"0.0f";
			// 
			// BaseCameraViewpointyHelp
			// 
			this->BaseCameraViewpointyHelp->Location = System::Drawing::Point(15, 48);
			this->BaseCameraViewpointyHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaseCameraViewpointyHelp->Name = L"BaseCameraViewpointyHelp";
			this->BaseCameraViewpointyHelp->Size = System::Drawing::Size(17, 19);
			this->BaseCameraViewpointyHelp->TabIndex = 333;
			this->BaseCameraViewpointyHelp->Text = L"\?";
			this->BaseCameraViewpointyHelp->UseVisualStyleBackColor = true;
			// 
			// BaseCameraViewpointyLabel
			// 
			this->BaseCameraViewpointyLabel->AutoSize = true;
			this->BaseCameraViewpointyLabel->Location = System::Drawing::Point(37, 50);
			this->BaseCameraViewpointyLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->BaseCameraViewpointyLabel->Name = L"BaseCameraViewpointyLabel";
			this->BaseCameraViewpointyLabel->Size = System::Drawing::Size(124, 13);
			this->BaseCameraViewpointyLabel->TabIndex = 328;
			this->BaseCameraViewpointyLabel->Text = L"BaseCameraViewpoint.y:";
			// 
			// BaseCameraViewpointxHelp
			// 
			this->BaseCameraViewpointxHelp->Location = System::Drawing::Point(15, 24);
			this->BaseCameraViewpointxHelp->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaseCameraViewpointxHelp->Name = L"BaseCameraViewpointxHelp";
			this->BaseCameraViewpointxHelp->Size = System::Drawing::Size(17, 19);
			this->BaseCameraViewpointxHelp->TabIndex = 332;
			this->BaseCameraViewpointxHelp->Text = L"\?";
			this->BaseCameraViewpointxHelp->UseVisualStyleBackColor = true;
			// 
			// BaseCameraViewpointxTextBox
			// 
			this->BaseCameraViewpointxTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->BaseCameraViewpointxTextBox->Location = System::Drawing::Point(187, 24);
			this->BaseCameraViewpointxTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->BaseCameraViewpointxTextBox->Name = L"BaseCameraViewpointxTextBox";
			this->BaseCameraViewpointxTextBox->Size = System::Drawing::Size(145, 20);
			this->BaseCameraViewpointxTextBox->TabIndex = 321;
			this->BaseCameraViewpointxTextBox->Text = L"0.0f";
			// 
			// BaseCameraViewpointxLabel
			// 
			this->BaseCameraViewpointxLabel->AutoSize = true;
			this->BaseCameraViewpointxLabel->Location = System::Drawing::Point(37, 27);
			this->BaseCameraViewpointxLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->BaseCameraViewpointxLabel->Name = L"BaseCameraViewpointxLabel";
			this->BaseCameraViewpointxLabel->Size = System::Drawing::Size(124, 13);
			this->BaseCameraViewpointxLabel->TabIndex = 327;
			this->BaseCameraViewpointxLabel->Text = L"BaseCameraViewpoint.x:";
			// 
			// RunTimeLabel
			// 
			this->RunTimeLabel->AutoSize = true;
			this->RunTimeLabel->Location = System::Drawing::Point(242, 20);
			this->RunTimeLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->RunTimeLabel->Name = L"RunTimeLabel";
			this->RunTimeLabel->Size = System::Drawing::Size(25, 13);
			this->RunTimeLabel->TabIndex = 161;
			this->RunTimeLabel->Text = L".cfg";
			// 
			// RSetDefaultsButton
			// 
			this->RSetDefaultsButton->Location = System::Drawing::Point(291, 17);
			this->RSetDefaultsButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RSetDefaultsButton->Name = L"RSetDefaultsButton";
			this->RSetDefaultsButton->Size = System::Drawing::Size(70, 19);
			this->RSetDefaultsButton->TabIndex = 160;
			this->RSetDefaultsButton->Text = L"Set Defaults";
			this->RSetDefaultsButton->UseVisualStyleBackColor = true;
			// 
			// RTerrainNameTextBox
			// 
			this->RTerrainNameTextBox->Location = System::Drawing::Point(84, 17);
			this->RTerrainNameTextBox->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->RTerrainNameTextBox->Name = L"RTerrainNameTextBox";
			this->RTerrainNameTextBox->ReadOnly = true;
			this->RTerrainNameTextBox->Size = System::Drawing::Size(155, 20);
			this->RTerrainNameTextBox->TabIndex = 159;
			this->RTerrainNameTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// TerrainNameRLabel
			// 
			this->TerrainNameRLabel->AutoSize = true;
			this->TerrainNameRLabel->Location = System::Drawing::Point(5, 20);
			this->TerrainNameRLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->TerrainNameRLabel->Name = L"TerrainNameRLabel";
			this->TerrainNameRLabel->Size = System::Drawing::Size(71, 13);
			this->TerrainNameRLabel->TabIndex = 158;
			this->TerrainNameRLabel->Text = L"TerrainName:";
			// 
			// QuitButton
			// 
			this->QuitButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->QuitButton->Location = System::Drawing::Point(9, 756);
			this->QuitButton->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->QuitButton->Name = L"QuitButton";
			this->QuitButton->Size = System::Drawing::Size(375, 19);
			this->QuitButton->TabIndex = 165;
			this->QuitButton->Text = L"Quit";
			this->QuitButton->UseVisualStyleBackColor = true;
			this->QuitButton->Click += gcnew System::EventHandler(this, &BaseForm::QuitButton_Click);
			// 
			// BaseForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(392, 780);
			this->Controls->Add(this->QuitButton);
			this->Controls->Add(this->MainTabControl);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"BaseForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Terrain Generator";
			this->MainTabControl->ResumeLayout(false);
			this->GenerationTabPage->ResumeLayout(false);
			this->GenerationTabPage->PerformLayout();
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
			this->MapSplitterTabPage->ResumeLayout(false);
			this->MapSplitterTabPage->PerformLayout();
			this->RunTimeTabPage->ResumeLayout(false);
			this->RunTimeTabPage->PerformLayout();
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

		}
#pragma endregion
    private: 
        System::Void RunMapsplitterButton_Click(System::Object^  sender, System::EventArgs^  e);
        System::Void GGenerateCFGButton_Click(System::Object^  sender, System::EventArgs^  e);
        System::Void GEditCFGButton_Click(System::Object^  sender, System::EventArgs^  e);
        System::Void QuitButton_Click(System::Object^  sender, System::EventArgs^  e);
        System::Void HeightMapLoadButton_Click(System::Object^  sender, System::EventArgs^  e);
        System::Void ImageMapLoadButton_Click(System::Object^  sender, System::EventArgs^  e);
        System::Void PagedCheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) ;
        System::Void CreateRunTimeCFGButton_Click(System::Object^  sender, System::EventArgs^  e);
        System::Void EditRunTimeCFGButton_Click(System::Object^  sender, System::EventArgs^  e) ;
        System::Void ResourceFormatComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
        System::Void GSetDefaultsButton_Click(System::Object^  sender, System::EventArgs^  e) ;
        System::Void HeightMapHelp_Click(System::Object^  sender, System::EventArgs^  e);
    };
}
