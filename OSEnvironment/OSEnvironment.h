#ifndef _H_MLLAB_OS_ENVIRONMENT_H
#define _H_MLLAB_OS_ENVIRONMENT_H

#include <string>
#include <map>
#include <vector>
#include <windows.h>

class OSEnvironment
{
public:
	virtual ~OSEnvironment();

private:
	OSEnvironment() { }
	OSEnvironment(const OSEnvironment& rhs) { }
	OSEnvironment& operator=(const OSEnvironment& rhs) { return *this; }

public:
	static std::string getApplicationDir();
	static std::string getFullPath(std::string relPath);
	static void showWinMsgBox(const char* msg, const char* title="", UINT uType=MB_OK);
	static std::string append(const std::string& str1, const std::string& str2);
	static std::string readFile(std::string fileName);
	static bool copyFile(const std::string& sourceFile, const std::string& destinationFile, bool FailedIfExists=false);
	static bool exists(const std::string& sourceFile);
	static std::string getWinFolderSelector();
	static std::string getWinOpenFileDialog(const char* filetype, const char* fileextension);
	static std::string getWinSaveFileDialog(const char* filetype, const char* fileextension);
	static bool createDirectory(const std::string& dir);
	static std::string getParentDirectory(const std::string& path);
	static int parseInt(const std::string& strVal);
	static double parseDouble(const std::string& strVal);
	static float parseFloat(const std::string& strVal);
	static bool replaceFileContent(const std::string& destinationFile, const std::map<std::string, std::string>& dic, bool onceOnly=false);
	static void writeLines(const std::string& destinationFile, const std::string& fileType, const std::vector<std::string>& lines);
	static std::string toString(float val);
	static std::string toString(int val);
	static std::string toString(size_t val);
	static bool copyFolder(const std::string& sourceFolder, const std::string& destinationFolder);
	static bool copyFile2Folder(const std::string& filename, const std::string& sourceFolderPath, const std::string& destinationFolderPath);
	static void setCurrentDir2ExecutableDir();
	static std::string createSQLDateTimeString(std::string& milliseconds);
	static std::string getCurrentTime();
	static std::string getFileNameUsingCurrentTime();
};
#endif