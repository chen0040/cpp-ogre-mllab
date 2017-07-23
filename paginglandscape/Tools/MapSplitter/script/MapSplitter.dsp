# Microsoft Developer Studio Project File - Name="MapSplitter" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=MapSplitter - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MapSplitter.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MapSplitter.mak" CFG="MapSplitter - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MapSplitter - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "MapSplitter - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MapSplitter - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\bin\Release"
# PROP Intermediate_Dir "..\obj\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /G6 /MD /W3 /GX /O2 /I "..\include" /I "..\..\Common\include" /I "..\..\..\PlugIns\PagingLandScape2\include" /I "../../../OgreMain/include" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "_MAPSPLITTER" /YX /FD /c
# ADD BASE RSC /l 0x1009 /d "NDEBUG"
# ADD RSC /l 0x1009 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib devil.lib OgreMain.lib Plugin_PagingLandScapeSceneManager2.lib /nologo /subsystem:console /machine:I386 /out:"..\..\..\..\ogrenew\samples\common\bin\Release/MapSplitter.exe" /libpath:".\..\..\OgreMain\lib\release" /libpath:"..\..\..\Dependencies\lib\release" /libpath:"..\..\..\PlugIns\PagingLandScape2\bin\Release"

!ELSEIF  "$(CFG)" == "MapSplitter - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\bin\Debug"
# PROP Intermediate_Dir "..\obj\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\include" /I "..\..\Common\include" /I "..\..\..\OgreMain\include" /I "..\..\..\PlugIns\PagingLandScape2\include" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "PLUGIN_PAGINGLANDSCAPE2_EXPORTS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x1009 /d "_DEBUG"
# ADD RSC /l 0x1009 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib devil.lib OgreMain_d.lib /nologo /subsystem:console /debug /machine:I386 /out:"..\..\..\..\ogrenew\samples\common\bin\Debug\MapSplitter.exe" /pdbtype:sept /libpath:"..\..\..\OgreMain\lib\debug" /libpath:"..\..\..\Dependencies\lib\Debug"

!ENDIF 

# Begin Target

# Name "MapSplitter - Win32 Release"
# Name "MapSplitter - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\..\PlugIns\PagingLandScape2\src\DRGNURBSSurface.cpp
# End Source File
# Begin Source File

SOURCE=..\src\filetutils.cpp
# End Source File
# Begin Source File

SOURCE=..\src\MapBlender.cpp
# End Source File
# Begin Source File

SOURCE=..\src\MapBlurrer.cpp
# End Source File
# Begin Source File

SOURCE=..\src\MapEqualizer.cpp
# End Source File
# Begin Source File

SOURCE=..\src\MapHorizon.cpp
# End Source File
# Begin Source File

SOURCE=..\src\MapHorizon2.cpp
# End Source File
# Begin Source File

SOURCE=..\src\MapHorizon3.cpp
# End Source File
# Begin Source File

SOURCE=..\src\MapInfinitizer.cpp
# End Source File
# Begin Source File

SOURCE=..\src\MapLighter.cpp
# End Source File
# Begin Source File

SOURCE=..\src\MapMergeModulater.cpp
# End Source File
# Begin Source File

SOURCE=..\src\MapNormaler.cpp
# End Source File
# Begin Source File

SOURCE=..\src\MapSplatter.cpp
# End Source File
# Begin Source File

SOURCE=..\src\MapSplitter.cpp
# End Source File
# Begin Source File

SOURCE=..\src\MapTool.cpp
# End Source File
# Begin Source File

SOURCE=..\src\MapUtil.cpp
# End Source File
# Begin Source File

SOURCE=..\src\MapVis.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\PlugIns\PagingLandScape2\src\OgrePagingLandScapeData2D.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\PlugIns\PagingLandScape2\src\OgrePagingLandScapeData2DManager.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\PlugIns\PagingLandScape2\src\OgrePagingLandScapeData2D_HeightField.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\PlugIns\PagingLandScape2\src\OgrePagingLandScapeData2D_HeightFieldRaw.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\PlugIns\PagingLandScape2\src\OgrePagingLandScapeData2D_HeightFieldRawTC.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\PlugIns\PagingLandScape2\src\OgrePagingLandScapeData2D_HeightFieldTC.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\PlugIns\PagingLandScape2\src\OgrePagingLandScapeData2D_Spline.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\PlugIns\PagingLandScape2\src\OgrePagingLandScapeOptions.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\..\PlugIns\PagingLandScape2\include\DRGNURBSSurface.h
# End Source File
# Begin Source File

SOURCE=..\include\fileutils.h
# End Source File
# Begin Source File

SOURCE=..\include\MapBlender.h
# End Source File
# Begin Source File

SOURCE=..\include\MapBlurrer.h
# End Source File
# Begin Source File

SOURCE=..\include\MapEqualizer.h
# End Source File
# Begin Source File

SOURCE=..\include\MapHorizon.h
# End Source File
# Begin Source File

SOURCE=..\include\MapHorizon2.h
# End Source File
# Begin Source File

SOURCE=..\include\MapHorizon3.h
# End Source File
# Begin Source File

SOURCE=..\include\MapInfinitizer.h
# End Source File
# Begin Source File

SOURCE=..\include\MapLighter.h
# End Source File
# Begin Source File

SOURCE=..\include\MapMergeModulater.h
# End Source File
# Begin Source File

SOURCE=..\include\MapNormaler.h
# End Source File
# Begin Source File

SOURCE=..\include\MapSplatter.h
# End Source File
# Begin Source File

SOURCE=..\include\MapSplitter.h
# End Source File
# Begin Source File

SOURCE=..\include\MapUtil.h
# End Source File
# Begin Source File

SOURCE=..\include\MapVis.h
# End Source File
# Begin Source File

SOURCE=..\..\..\PlugIns\PagingLandScape2\include\OgrePagingLandScapeData2D.h
# End Source File
# Begin Source File

SOURCE=..\..\..\PlugIns\PagingLandScape2\include\OgrePagingLandScapeData2D_HeightField.h
# End Source File
# Begin Source File

SOURCE=..\..\..\PlugIns\PagingLandScape2\include\OgrePagingLandScapeData2D_HeightFieldRaw.h
# End Source File
# Begin Source File

SOURCE=..\..\..\PlugIns\PagingLandScape2\include\OgrePagingLandScapeData2D_HeightFieldRawTC.h
# End Source File
# Begin Source File

SOURCE=..\..\..\PlugIns\PagingLandScape2\include\OgrePagingLandScapeData2D_HeightFieldTC.h
# End Source File
# Begin Source File

SOURCE=..\..\..\PlugIns\PagingLandScape2\include\OgrePagingLandScapeData2D_Spline.h
# End Source File
# Begin Source File

SOURCE=..\..\..\PlugIns\PagingLandScape2\include\OgrePagingLandScapeOptions.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
