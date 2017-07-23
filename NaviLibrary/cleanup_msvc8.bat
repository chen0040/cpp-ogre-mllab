@echo This will clean up all intermediate/user-specific files for NaviLibrary. 
@echo ** You must close Visual C++ before running this file! **
@pause

@echo ========== Cleaning up... ==========
@del Navi.ncb
@del Navi.suo /AH
@del Navi\*.user
@rmdir Navi\Objects\Release\ /S /Q
@rmdir Navi\Objects\Debug\ /S /Q
@rmdir "Navi\Objects\Release DLL\" /S /Q
@rmdir "Navi\Objects\Debug DLL\" /S /Q
@rmdir Navi\Docs\html\ /S /Q
@del Navi\Lib\*.lib
@del Navi\Lib\*.dll
@del Navi\Lib\*.ilk
@del Navi\Lib\*.exp
@del Navi\Lib\*.pdb
@del NaviDemo\*.user
@rmdir NaviDemo\Objects\Release\ /S /Q
@rmdir NaviDemo\Objects\Debug\ /S /Q
@rmdir "NaviDemo\Objects\Release DLL\" /S /Q
@rmdir "NaviDemo\Objects\Debug DLL\" /S /Q
@rmdir NaviDemo\Bin\release\ /S /Q
@rmdir NaviDemo\Bin\debug\ /S /Q
@rmdir "NaviDemo\Bin\release dll\" /S /Q
@rmdir "NaviDemo\Bin\debug dll\" /S /Q
@del NaviDemo\Bin\Media\Navi.js
@echo ============== Done! ===============
