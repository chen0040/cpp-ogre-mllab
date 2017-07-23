# Microsoft Developer Studio Project File - Name="Demo_PagingLandScape2" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Demo_PagingLandScape2 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Demo_PagingLandScape2.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Demo_PagingLandScape2.mak" CFG="Demo_PagingLandScape2 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Demo_PagingLandScape2 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Demo_PagingLandScape2 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Demo_PagingLandScape2 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\bin\$(ConfigurationName)"
# PROP BASE Intermediate_Dir "..\obj\$(ConfigurationName)"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\bin\$(ConfigurationName)"
# PROP Intermediate_Dir "..\obj\$(ConfigurationName)"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /Gy /I "..\include" /I "..\..\Common\include" /I "..\..\..\OgreMain\include" /I "..\..\..\Plugins\PagingLandScape2\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_STLP_DEBUG" /D "_MBCS" /FR /GZ PRECOMP_VC7_TOBEREMOVED /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /Gy /I "..\include" /I "..\..\Common\include" /I "..\..\..\OgreMain\include" /I "..\..\..\Plugins\PagingLandScape2\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_STLP_DEBUG" /D "_MBCS" /FR /GZ PRECOMP_VC7_TOBEREMOVED /c
# ADD BASE MTL /nologo /win32
# ADD MTL /nologo /win32
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib OgreMain_d.lib Plugin_PagingLandScapeSceneManager2.lib /nologo /subsystem:console /debug /machine:IX86 /pdbtype:sept /libpath:""..\..\..\OgreMain\lib\$(ConfigurationName)"" /libpath:""..\..\..\plugins\PagingLandScape2\bin\$(ConfigurationName)""
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib OgreMain_d.lib Plugin_PagingLandScapeSceneManager2.lib /nologo /subsystem:windows /debug /machine:IX86 /pdbtype:sept /libpath:""..\..\..\OgreMain\lib\$(ConfigurationName)"" /libpath:""..\..\..\plugins\PagingLandScape2\bin\$(ConfigurationName)""
# SUBTRACT LINK32 /pdb:none
# Begin Special Build Tool
OutDir=.\..\bin\$(ConfigurationName)
SOURCE="$(InputPath)"
PostBuild_Cmds=copy $(OutDir)\$(TargetFileName) ..\..\Common\Bin\$(ConfigurationName)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Demo_PagingLandScape2 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "..\bin\$(ConfigurationName)"
# PROP BASE Intermediate_Dir "..\obj\$(ConfigurationName)"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\bin\Release"
# PROP Intermediate_Dir "..\obj\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Ot /Og /Oi /Ob1 /I "..\include" /I "..\..\Common\include" /I "..\..\..\OgreMain\include" /I "..\..\..\Plugins\PagingLandScape2\include" /D "WIN32" /D "_WINDOWS" /D "NDEBUG" /D "_MBCS" /GT /GA PRECOMP_VC7_TOBEREMOVED /c
# ADD CPP /nologo /MD /W3 /GX /Zi /Ot /Og /Oi /Ob1 /I "..\include" /I "..\..\Common\include" /I "..\..\..\OgreMain\include" /I "..\..\..\Plugins\PagingLandScape2\include" /D "WIN32" /D "_WINDOWS" /D "NDEBUG" /D "_MBCS" /GT /GA /Zm1000 /c
# ADD BASE MTL /nologo /win32
# ADD MTL /nologo /win32
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib OgreMain.lib Plugin_PagingLandScapeSceneManager2.lib /nologo /subsystem:windows /map:"Demo_PagingLandScape2.map" /debug /machine:IX86 /pdbtype:sept /libpath:""..\..\..\OgreMain\lib\$(ConfigurationName)"" /libpath:""..\..\..\plugins\PagingLandScape2\bin\$(ConfigurationName)"" /mapinfo:exports /opt:ref /opt:icf
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib OgreMain.lib Plugin_PagingLandScapeSceneManager2.lib /nologo /subsystem:windows /map:"Demo_PagingLandScape2.map" /debug /machine:IX86 /pdbtype:sept /libpath:"..\..\..\OgreMain\lib\release" /libpath:"..\..\..\PlugIns\PagingLandScape2\bin\Release" /libpath:""..\..\..\OgreMain\lib\$(ConfigurationName)"" /libpath:""..\..\..\plugins\PagingLandScape2\bin\$(ConfigurationName)"" /mapinfo:exports /opt:ref /opt:icf

!ENDIF 

# Begin Target

# Name "Demo_PagingLandScape2 - Win32 Debug"
# Name "Demo_PagingLandScape2 - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;def;odl;idl;hpj;bat;asm"
# Begin Source File

SOURCE=..\src\PagingLandScape.cpp
DEP_CPP_PAGIN=\
	"..\..\..\OgreMain\include\Ogre.h"\
	"..\..\..\OgreMain\include\OgreAnimation.h"\
	"..\..\..\OgreMain\include\OgreAnimationState.h"\
	"..\..\..\OgreMain\include\OgreAnimationTrack.h"\
	"..\..\..\OgreMain\include\OgreArchive.h"\
	"..\..\..\OgreMain\include\OgreArchiveManager.h"\
	"..\..\..\OgreMain\include\OgreAutoParamDataSource.h"\
	"..\..\..\OgreMain\include\OgreAxisAlignedBox.h"\
	"..\..\..\OgreMain\include\OgreBillboard.h"\
	"..\..\..\OgreMain\include\OgreBillboardSet.h"\
	"..\..\..\OgreMain\include\OgreBlendMode.h"\
	"..\..\..\OgreMain\include\OgreBone.h"\
	"..\..\..\OgreMain\include\OgreCamera.h"\
	"..\..\..\OgreMain\include\OgreColourValue.h"\
	"..\..\..\OgreMain\include\OgreCommon.h"\
	"..\..\..\OgreMain\include\OgreConfig.h"\
	"..\..\..\OgreMain\include\OgreConfigFile.h"\
	"..\..\..\OgreMain\include\OgreConfigOptionMap.h"\
	"..\..\..\OgreMain\include\OgreController.h"\
	"..\..\..\OgreMain\include\OgreControllerManager.h"\
	"..\..\..\OgreMain\include\OgreDataStream.h"\
	"..\..\..\OgreMain\include\OgreEdgeListBuilder.h"\
	"..\..\..\OgreMain\include\OgreEntity.h"\
	"..\..\..\OgreMain\include\OgreEventListeners.h"\
	"..\..\..\OgreMain\include\OgreEventProcessor.h"\
	"..\..\..\OgreMain\include\OgreEventTarget.h"\
	"..\..\..\OgreMain\include\OgreException.h"\
	"..\..\..\OgreMain\include\OgreFrameListener.h"\
	"..\..\..\OgreMain\include\OgreFrustum.h"\
	"..\..\..\OgreMain\include\OgreGpuProgram.h"\
	"..\..\..\OgreMain\include\OgreGpuProgramManager.h"\
	"..\..\..\OgreMain\include\OgreHardwareBuffer.h"\
	"..\..\..\OgreMain\include\OgreHardwareBufferManager.h"\
	"..\..\..\OgreMain\include\OgreHardwareIndexBuffer.h"\
	"..\..\..\OgreMain\include\OgreHardwareOcclusionQuery.h"\
	"..\..\..\OgreMain\include\OgreHardwarePixelBuffer.h"\
	"..\..\..\OgreMain\include\OgreHardwareVertexBuffer.h"\
	"..\..\..\OgreMain\include\OgreHighLevelGpuProgram.h"\
	"..\..\..\OgreMain\include\OgreHighLevelGpuProgramManager.h"\
	"..\..\..\OgreMain\include\OgreImage.h"\
	"..\..\..\OgreMain\include\OgreInput.h"\
	"..\..\..\OgreMain\include\OgreInputEvent.h"\
	"..\..\..\OgreMain\include\OgreIteratorWrappers.h"\
	"..\..\..\OgreMain\include\OgreKeyEvent.h"\
	"..\..\..\OgreMain\include\OgreKeyFrame.h"\
	"..\..\..\OgreMain\include\OgreKeyTarget.h"\
	"..\..\..\OgreMain\include\OgreLight.h"\
	"..\..\..\OgreMain\include\OgreLog.h"\
	"..\..\..\OgreMain\include\OgreLogManager.h"\
	"..\..\..\OgreMain\include\OgreMaterial.h"\
	"..\..\..\OgreMain\include\OgreMaterialManager.h"\
	"..\..\..\OgreMain\include\OgreMaterialSerializer.h"\
	"..\..\..\OgreMain\include\OgreMath.h"\
	"..\..\..\OgreMain\include\OgreMatrix3.h"\
	"..\..\..\OgreMain\include\OgreMatrix4.h"\
	"..\..\..\OgreMain\include\OgreMemoryMacros.h"\
	"..\..\..\OgreMain\include\OgreMemoryManager.h"\
	"..\..\..\OgreMain\include\OgreMesh.h"\
	"..\..\..\OgreMain\include\OgreMeshManager.h"\
	"..\..\..\OgreMain\include\OgreMeshSerializer.h"\
	"..\..\..\OgreMain\include\OgreMeshSerializerImpl.h"\
	"..\..\..\OgreMain\include\OgreMouseEvent.h"\
	"..\..\..\OgreMain\include\OgreMouseMotionTarget.h"\
	"..\..\..\OgreMain\include\OgreMouseTarget.h"\
	"..\..\..\OgreMain\include\OgreMovableObject.h"\
	"..\..\..\OgreMain\include\OgreMovablePlane.h"\
	"..\..\..\OgreMain\include\OgreNode.h"\
	"..\..\..\OgreMain\include\OgreOverlay.h"\
	"..\..\..\OgreMain\include\OgreOverlayContainer.h"\
	"..\..\..\OgreMain\include\OgreOverlayElement.h"\
	"..\..\..\OgreMain\include\OgreOverlayElementCommands.h"\
	"..\..\..\OgreMain\include\OgreOverlayManager.h"\
	"..\..\..\OgreMain\include\OgrePanelOverlayElement.h"\
	"..\..\..\OgreMain\include\OgreParticle.h"\
	"..\..\..\OgreMain\include\OgreParticleAffector.h"\
	"..\..\..\OgreMain\include\OgreParticleEmitter.h"\
	"..\..\..\OgreMain\include\OgreParticleEmitterCommands.h"\
	"..\..\..\OgreMain\include\OgreParticleIterator.h"\
	"..\..\..\OgreMain\include\OgreParticleSystem.h"\
	"..\..\..\OgreMain\include\OgreParticleSystemManager.h"\
	"..\..\..\OgreMain\include\OgrePass.h"\
	"..\..\..\OgreMain\include\OgrePatchMesh.h"\
	"..\..\..\OgreMain\include\OgrePatchSurface.h"\
	"..\..\..\OgreMain\include\OgrePixelFormat.h"\
	"..\..\..\OgreMain\include\OgrePlane.h"\
	"..\..\..\OgreMain\include\OgrePlaneBoundedVolume.h"\
	"..\..\..\OgreMain\include\OgrePlatform.h"\
	"..\..\..\OgreMain\include\OgrePlatformManager.h"\
	"..\..\..\OgreMain\include\OgrePositionTarget.h"\
	"..\..\..\OgreMain\include\OgrePredefinedControllers.h"\
	"..\..\..\OgreMain\include\OgrePrerequisites.h"\
	"..\..\..\OgreMain\include\OgreProfiler.h"\
	"..\..\..\OgreMain\include\OgreProgressiveMesh.h"\
	"..\..\..\OgreMain\include\OgreQuaternion.h"\
	"..\..\..\OgreMain\include\OgreRay.h"\
	"..\..\..\OgreMain\include\OgreRectangle.h"\
	"..\..\..\OgreMain\include\OgreRectangle2D.h"\
	"..\..\..\OgreMain\include\OgreRenderable.h"\
	"..\..\..\OgreMain\include\OgreRenderOperation.h"\
	"..\..\..\OgreMain\include\OgreRenderQueue.h"\
	"..\..\..\OgreMain\include\OgreRenderQueueListener.h"\
	"..\..\..\OgreMain\include\OgreRenderQueueSortingGrouping.h"\
	"..\..\..\OgreMain\include\OgreRenderSystem.h"\
	"..\..\..\OgreMain\include\OgreRenderSystemCapabilities.h"\
	"..\..\..\OgreMain\include\OgreRenderTarget.h"\
	"..\..\..\OgreMain\include\OgreRenderTargetListener.h"\
	"..\..\..\OgreMain\include\OgreRenderTexture.h"\
	"..\..\..\OgreMain\include\OgreRenderWindow.h"\
	"..\..\..\OgreMain\include\OgreResource.h"\
	"..\..\..\OgreMain\include\OgreResourceGroupManager.h"\
	"..\..\..\OgreMain\include\OgreResourceManager.h"\
	"..\..\..\OgreMain\include\OgreRoot.h"\
	"..\..\..\OgreMain\include\OgreRotationalSpline.h"\
	"..\..\..\OgreMain\include\OgreSceneManager.h"\
	"..\..\..\OgreMain\include\OgreSceneManagerEnumerator.h"\
	"..\..\..\OgreMain\include\OgreSceneNode.h"\
	"..\..\..\OgreMain\include\OgreSceneQuery.h"\
	"..\..\..\OgreMain\include\OgreScriptLoader.h"\
	"..\..\..\OgreMain\include\OgreSerializer.h"\
	"..\..\..\OgreMain\include\OgreShadowCaster.h"\
	"..\..\..\OgreMain\include\OgreSharedPtr.h"\
	"..\..\..\OgreMain\include\OgreSimpleRenderable.h"\
	"..\..\..\OgreMain\include\OgreSimpleSpline.h"\
	"..\..\..\OgreMain\include\OgreSingleton.h"\
	"..\..\..\OgreMain\include\OgreSkeleton.h"\
	"..\..\..\OgreMain\include\OgreSkeletonInstance.h"\
	"..\..\..\OgreMain\include\OgreSkeletonManager.h"\
	"..\..\..\OgreMain\include\OgreSkeletonSerializer.h"\
	"..\..\..\OgreMain\include\OgreSphere.h"\
	"..\..\..\OgreMain\include\OgreStaticGeometry.h"\
	"..\..\..\OgreMain\include\OgreStdHeaders.h"\
	"..\..\..\OgreMain\include\OgreString.h"\
	"..\..\..\OgreMain\include\OgreStringConverter.h"\
	"..\..\..\OgreMain\include\OgreStringInterface.h"\
	"..\..\..\OgreMain\include\OgreStringVector.h"\
	"..\..\..\OgreMain\include\OgreSubEntity.h"\
	"..\..\..\OgreMain\include\OgreSubMesh.h"\
	"..\..\..\OgreMain\include\OgreTechnique.h"\
	"..\..\..\OgreMain\include\OgreTexture.h"\
	"..\..\..\OgreMain\include\OgreTextureManager.h"\
	"..\..\..\OgreMain\include\OgreTextureUnitState.h"\
	"..\..\..\OgreMain\include\OgreTimer.h"\
	"..\..\..\OgreMain\include\OgreUserDefinedObject.h"\
	"..\..\..\OgreMain\include\OgreVector2.h"\
	"..\..\..\OgreMain\include\OgreVector3.h"\
	"..\..\..\OgreMain\include\OgreVector4.h"\
	"..\..\..\OgreMain\include\OgreVertexBoneAssignment.h"\
	"..\..\..\OgreMain\include\OgreVertexIndexData.h"\
	"..\..\..\OgreMain\include\OgreViewport.h"\
	"..\..\..\OgreMain\include\stl_user_config.h"\
	"..\..\Common\include\ExampleApplication.h"\
	"..\..\Common\include\ExampleFrameListener.h"\
	"..\include\OgreOctreeSceneQuery.h"\
	"..\include\OgrePagingLandScapeListener.h"\
	"..\include\OgrePagingLandScapePrerequisites.h"\
	"..\include\OgrePagingLandScapeRaySceneQuery.h"\
	"..\include\PagingLandScape.h"\
	{$(INCLUDE)}"config\_epilog.h"\
	{$(INCLUDE)}"config\_msvc_warnings_off.h"\
	{$(INCLUDE)}"config\_prolog.h"\
	{$(INCLUDE)}"config\stl_apcc.h"\
	{$(INCLUDE)}"config\stl_apple.h"\
	{$(INCLUDE)}"config\stl_as400.h"\
	{$(INCLUDE)}"config\stl_bc.h"\
	{$(INCLUDE)}"config\stl_como.h"\
	{$(INCLUDE)}"config\stl_confix.h"\
	{$(INCLUDE)}"config\stl_cray.h"\
	{$(INCLUDE)}"config\stl_dec.h"\
	{$(INCLUDE)}"config\stl_dec_vms.h"\
	{$(INCLUDE)}"config\stl_dm.h"\
	{$(INCLUDE)}"config\stl_fujitsu.h"\
	{$(INCLUDE)}"config\stl_gcc.h"\
	{$(INCLUDE)}"config\stl_hpacc.h"\
	{$(INCLUDE)}"config\stl_ibm.h"\
	{$(INCLUDE)}"config\stl_icc.h"\
	{$(INCLUDE)}"config\stl_intel.h"\
	{$(INCLUDE)}"config\stl_kai.h"\
	{$(INCLUDE)}"config\stl_msvc.h"\
	{$(INCLUDE)}"config\stl_mwerks.h"\
	{$(INCLUDE)}"config\stl_mycomp.h"\
	{$(INCLUDE)}"config\stl_sco.h"\
	{$(INCLUDE)}"config\stl_select_lib.h"\
	{$(INCLUDE)}"config\stl_sgi.h"\
	{$(INCLUDE)}"config\stl_solaris.h"\
	{$(INCLUDE)}"config\stl_sunpro.h"\
	{$(INCLUDE)}"config\stl_symantec.h"\
	{$(INCLUDE)}"config\stl_watcom.h"\
	{$(INCLUDE)}"config\stl_wince.h"\
	{$(INCLUDE)}"config\stlcomp.h"\
	{$(INCLUDE)}"config\vc_select_lib.h"\
	{$(INCLUDE)}"hash_map"\
	{$(INCLUDE)}"hash_set"\
	{$(INCLUDE)}"pthread.h"\
	{$(INCLUDE)}"stl\_abbrevs.h"\
	{$(INCLUDE)}"stl\_algobase.c"\
	{$(INCLUDE)}"stl\_algobase.h"\
	{$(INCLUDE)}"stl\_alloc.c"\
	{$(INCLUDE)}"stl\_alloc.h"\
	{$(INCLUDE)}"stl\_alloc_old.h"\
	{$(INCLUDE)}"stl\_bvector.h"\
	{$(INCLUDE)}"stl\_config.h"\
	{$(INCLUDE)}"stl\_config_compat.h"\
	{$(INCLUDE)}"stl\_config_compat_post.h"\
	{$(INCLUDE)}"stl\_construct.h"\
	{$(INCLUDE)}"stl\_cwchar.h"\
	{$(INCLUDE)}"stl\_epilog.h"\
	{$(INCLUDE)}"stl\_function_base.h"\
	{$(INCLUDE)}"stl\_hash_fun.h"\
	{$(INCLUDE)}"stl\_hash_map.h"\
	{$(INCLUDE)}"stl\_hash_set.h"\
	{$(INCLUDE)}"stl\_hashtable.c"\
	{$(INCLUDE)}"stl\_hashtable.h"\
	{$(INCLUDE)}"stl\_iterator.h"\
	{$(INCLUDE)}"stl\_iterator_base.h"\
	{$(INCLUDE)}"stl\_iterator_old.h"\
	{$(INCLUDE)}"stl\_new.h"\
	{$(INCLUDE)}"stl\_pair.h"\
	{$(INCLUDE)}"stl\_prolog.h"\
	{$(INCLUDE)}"stl\_pthread_alloc.c"\
	{$(INCLUDE)}"stl\_pthread_alloc.h"\
	{$(INCLUDE)}"stl\_ptrs_specialize.h"\
	{$(INCLUDE)}"stl\_range_errors.h"\
	{$(INCLUDE)}"stl\_relops_cont.h"\
	{$(INCLUDE)}"stl\_relops_hash_cont.h"\
	{$(INCLUDE)}"stl\_site_config.h"\
	{$(INCLUDE)}"stl\_sparc_atomic.h"\
	{$(INCLUDE)}"stl\_threads.c"\
	{$(INCLUDE)}"stl\_threads.h"\
	{$(INCLUDE)}"stl\_uninitialized.h"\
	{$(INCLUDE)}"stl\_vector.c"\
	{$(INCLUDE)}"stl\_vector.h"\
	{$(INCLUDE)}"stl\debug\_debug.c"\
	{$(INCLUDE)}"stl\debug\_debug.h"\
	{$(INCLUDE)}"stl\debug\_hashtable.h"\
	{$(INCLUDE)}"stl\debug\_iterator.h"\
	{$(INCLUDE)}"stl\debug\_relops_cont.h"\
	{$(INCLUDE)}"stl\debug\_relops_hash_cont.h"\
	{$(INCLUDE)}"stl\debug\_vector.h"\
	{$(INCLUDE)}"stl\type_traits.h"\
	{$(INCLUDE)}"stl\wrappers\_hash_map.h"\
	{$(INCLUDE)}"stl\wrappers\_hash_set.h"\
	{$(INCLUDE)}"stl\wrappers\_vector.h"\
	
NODEP_CPP_PAGIN=\
	"..\..\..\..\..\..\usr\include\pthread.h"\
	"..\..\..\OgreMain\include\config.h"\
	
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;inc"
# Begin Source File

SOURCE=..\include\PagingLandScape.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
