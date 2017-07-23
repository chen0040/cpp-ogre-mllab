#include "OSEnvironment.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <io.h>
#include <vector>
#include <iomanip>
#include <shlobj.h>   
#include <boost/filesystem.hpp>
#include <atlstr.h>
#include "../GameEngine/Application.h"
#include <ctime>

std::string OSEnvironment::getApplicationDir()
{
	TCHAR appPath1[_MAX_PATH];

	::GetModuleFileName(NULL, appPath1, _MAX_PATH);
	std::string path=CT2CA(appPath1);
	size_t end_index=path.rfind("\\");

	return path.substr(0, end_index);
}

bool OSEnvironment::copyFile2Folder(const std::string& filename, const std::string& sourceFolderPath, const std::string& destinationFolderPath) 
{
	std::ostringstream oss1;
	oss1 << sourceFolderPath << "\\" << filename;

	std::string sourceFile=oss1.str();
	if(!OSEnvironment::exists(sourceFile))
	{
		return false;
	}
	std::ostringstream oss2;
	oss2 << destinationFolderPath << "\\" << filename;
	OSEnvironment::copyFile(sourceFile, oss2.str());
	return true;
}

std::string OSEnvironment::getFullPath(std::string relPath)
{
	TCHAR appPath1[_MAX_PATH];

	::GetModuleFileName(NULL, appPath1, _MAX_PATH);
	std::string path=CT2CA(appPath1);
	size_t end_index=path.rfind("\\");

	path.replace(end_index+1, path.length()-end_index, relPath);
	return path;
}

void OSEnvironment::showWinMsgBox(const char* msg, const char* title, UINT uType)
{
	Application::getSingletonPtr()->showWindowMouse(true);
	MessageBox(NULL, CA2CT(msg), CA2CT(title), uType);
	Application::getSingletonPtr()->showWindowMouse(false);
}

std::string OSEnvironment::append(const std::string& str1, const std::string& str2)
{
	std::ostringstream oss;
	oss << str1 << str2;
	return oss.str();
}

bool OSEnvironment::replaceFileContent(const std::string& destinationFile, const std::map<std::string, std::string>& dic, bool onceOnly)
{
	std::vector<std::string> outlines;
	std::ifstream infile;
	infile.open(destinationFile.c_str());

	std::string line;
	bool found=false;
	while(std::getline(infile, line))
	{
		if((!found) || (!onceOnly))
		{
			std::map<std::string, std::string>::const_iterator miter=dic.begin();
			std::map<std::string, std::string>::const_iterator miter_end=dic.end();
			for(; miter != miter_end; ++miter)
			{
				const std::string& paramName=miter->first;
				const std::string& paramValue=miter->second;
				size_t fnd=line.find(paramName);
				if(onceOnly)
				{
					if(fnd != std::string::npos)
					{
						line.replace(fnd, paramName.length(), paramValue);
						found=true;
						break;
					}
				}
				else
				{
					while(fnd != std::string::npos)
					{
						found=true;
						line.replace(fnd, paramName.length(), paramValue);
						fnd=line.find(paramName);
					}
				}
			}
		}
		outlines.push_back(line);
	}

	infile.close();

	std::ofstream outfile;
	outfile.open(destinationFile.c_str());

	size_t outfileCount=outlines.size();
	for(size_t i=0; i != outfileCount; ++i)
	{
		outfile << outlines[i] << "\n";
	}
	
	outfile.close();

	return found;
}

std::string OSEnvironment::readFile(std::string fileName)
{
	if(!exists(fileName))
	{
		std::ostringstream oss;
		oss << fileName << " does not exists";
		throw Exception(42, oss.str().c_str(), "OSEnvironment::readFile(std::string filename)");
	}
	std::ostringstream oss;

	std::ifstream ifs;
	ifs.open(fileName.c_str());

	std::string line;
	while(!ifs.eof())
	{
		std::getline(ifs, line);
		oss << line;
	}
	ifs.close();

	return oss.str();
}

bool OSEnvironment::copyFile(const std::string& sourceFile, const std::string& destinationFile, bool FailedIfExists)
{
	if(!exists(sourceFile))
	{
		return false;
	}

	std::string destinationFileDir=getParentDirectory(destinationFile);
	if(!exists(destinationFileDir))
	{
		createDirectory(destinationFileDir);
	}

	BOOL bFailedIfExists=FailedIfExists ? TRUE : FALSE;
	if(::CopyFile(CA2CT(sourceFile.c_str()), CA2CT(destinationFile.c_str()), bFailedIfExists) == TRUE)
	{
		return true;
	}
	else
	{
		return false; 
	}
}

bool OSEnvironment::copyFolder(const std::string& sourceFolder, const std::string& destinationFolder)
{
	if(!exists(sourceFolder))
	{
		return false;
	}

	if(!exists(destinationFolder))
	{
		createDirectory(destinationFolder);
	}

	using namespace boost::filesystem;

	directory_iterator end_iterator;
	path dir_path(sourceFolder);
	for(boost::filesystem::directory_iterator iter(dir_path); iter != end_iterator; ++iter)
	{
		std::ostringstream oss1;
		oss1 << sourceFolder << "\\" << iter->leaf();
		std::ostringstream oss2;
		oss2 << destinationFolder << "\\" << iter->leaf();
		if(boost::filesystem::is_directory(iter->status()))
		{
			copyFolder(oss1.str(), oss2.str());
		}
		else
		{
			copyFile(oss1.str(), oss2.str());
		}
	}

	return true;
}

bool OSEnvironment::exists(const std::string& fileName)
{
	if(_access(fileName.c_str(), 0)==-1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

std::string OSEnvironment::getWinFolderSelector()
{
	Application::getSingletonPtr()->showWindowMouse(true);

	TCHAR path[MAX_PATH];
    BROWSEINFO bi = { 0 };
	bi.ulFlags |= BIF_NEWDIALOGSTYLE;
    bi.lpszTitle = _T("Browse Folder");
	LPITEMIDLIST pidl = ::SHBrowseForFolder(&bi);

	std::string folderName="";
    if(pidl != 0)
    {
        // get the name of the folder and put it in path
		::SHGetPathFromIDList (pidl, path);

		folderName=CT2CA(path);

        IMalloc * imalloc = 0;
        if ( SUCCEEDED( SHGetMalloc ( &imalloc )) )
        {
            imalloc->Free (pidl);
            imalloc->Release( );
        }
    }

	Application::getSingletonPtr()->showWindowMouse(false);

	return folderName;
}

std::string OSEnvironment::getWinSaveFileDialog(const char* filtertype, const char* filterextension)
{
	Application::getSingletonPtr()->showWindowMouse(true);

	OPENFILENAME sfn;
	TCHAR szFile[MAX_PATH];
	TCHAR currentDir[MAX_PATH];
	TCHAR* szTitle=_T("Save File Dialog");
	szFile[0]='\0';

	::GetCurrentDirectory(MAX_PATH, currentDir);

	size_t ftLen=strlen(filtertype);
	size_t feLen=strlen(filterextension);
	CA2CT szFilterType(filtertype);
	CA2CT szFilterExtension(filterextension);

	size_t index=0;
	TCHAR szFilter[MAX_PATH];
	for(size_t i=0; i != ftLen; ++i)
	{
		szFilter[index++]=szFilterType[i];
	}
	szFilter[index++]='\0';
	szFilter[index++]='*';
	szFilter[index++]='.';
	for(size_t i=0; i != feLen; ++i)
	{
		szFilter[index++]=szFilterExtension[i];
	}
	szFilter[index++]='\0';
	szFilter[index++]='\0';

	::ZeroMemory(&sfn, sizeof(OPENFILENAME));
	sfn.lStructSize = sizeof(OPENFILENAME);
	sfn.lpstrFilter = szFilter;
	sfn.nFilterIndex = 0;
	sfn.lpstrFile = szFile;
	sfn.nMaxFile = sizeof(szFile) / sizeof(*szFile);
	sfn.lpstrInitialDir = currentDir;
	sfn.lpstrTitle = szTitle;
	sfn.nMaxFileTitle=sizeof(szTitle);
	sfn.Flags = OFN_CREATEPROMPT | OFN_OVERWRITEPROMPT; //OFN_NOREADONLYRETURN

	if(GetSaveFileName(&sfn) == TRUE)
	{
		::SetCurrentDirectory(currentDir);
		Application::getSingletonPtr()->showWindowMouse(false);
		return std::string(CT2CA(szFile));
	}
	else
	{
		::SetCurrentDirectory(currentDir);
		Application::getSingletonPtr()->showWindowMouse(false);
		return "";
	}
}

std::string OSEnvironment::getWinOpenFileDialog(const char* filtertype, const char* filterextension)
{
	Application::getSingletonPtr()->showWindowMouse(true);

	OPENFILENAME ofn;
	TCHAR szFile[MAX_PATH];
	TCHAR currentDir[MAX_PATH];
	TCHAR* szTitle=_T("Open File Dialog");
	szFile[0] = '\0';
	::GetCurrentDirectory(MAX_PATH, currentDir);

	size_t ftLen=strlen(filtertype);
	size_t feLen=strlen(filterextension);
	CA2CT szFilterType(filtertype);
	CA2CT szFilterExtension(filterextension);

	size_t index=0;
	TCHAR szFilter[MAX_PATH];
	for(size_t i=0; i != ftLen; ++i)
	{
		szFilter[index++]=szFilterType[i];
	}
	szFilter[index++]='\0';
	szFilter[index++]='*';
	szFilter[index++]='.';
	for(size_t i=0; i != feLen; ++i)
	{
		szFilter[index++]=szFilterExtension[i];
	}
	szFilter[index++]='\0';
	szFilter[index++]='\0';

	::ZeroMemory(&ofn, sizeof(OPENFILENAME));

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.lpstrFilter =szFilter;
	ofn.lpstrFile = szFile;
	ofn.nMaxFile = sizeof(szFile) / sizeof(*szFile);
	ofn.nFilterIndex = 0;
	ofn.lpstrInitialDir = currentDir;
	ofn.lpstrTitle =szTitle; 
	ofn.nMaxFileTitle=sizeof(szTitle);
	ofn.Flags =  OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if(::GetOpenFileName(&ofn) == TRUE)
	{
		::SetCurrentDirectory(currentDir);
		Application::getSingletonPtr()->showWindowMouse(false);
		return std::string(CT2CA(szFile));
	}
	else
	{
		::SetCurrentDirectory(currentDir);
		Application::getSingletonPtr()->showWindowMouse(false);
		return "";
	}
}

bool OSEnvironment::createDirectory(const std::string& dir)
{
	
	if(exists(dir))
	{
		return true;
	}

	std::string parentDirectory=getParentDirectory(dir);
	if(!exists(parentDirectory))
	{
		createDirectory(parentDirectory);	
	}

	::CreateDirectory(CA2CT(dir.c_str()), NULL);

	return true;
}

std::string OSEnvironment::getParentDirectory(const std::string& path)
{
	size_t fnd=path.rfind("\\");
	if(fnd != std::string::npos)
	{
		return path.substr(0, fnd);
	}
	return "";
}

int OSEnvironment::parseInt(const std::string& strVal)
{
	std::istringstream iss(strVal);
	int val;
	iss >> val;
	return val;
}

double OSEnvironment::parseDouble(const std::string& strVal)
{
	std::istringstream iss(strVal);
	double val;
	iss >> val;
	return val;
}

float OSEnvironment::parseFloat(const std::string& strVal)
{
	std::istringstream iss(strVal);
	float val;
	iss >> val;
	return val;
}


void OSEnvironment::writeLines(const std::string& destinationFile, const std::string& fileType, const std::vector<std::string>& lines)
{
	std::ofstream outfile;
	outfile.open(destinationFile.c_str());

	size_t lineCount=lines.size();
	for(size_t i=0; i != lineCount; ++i)
	{
		outfile << lines[i] << "\n";
	}
	
	outfile.close();
}

std::string OSEnvironment::toString(float val)
{
	std::ostringstream oss;
	oss << val;
	return oss.str();
}

std::string OSEnvironment::toString(int val)
{
	std::ostringstream oss;
	oss << val;
	return oss.str();
}

std::string OSEnvironment::toString(size_t val)
{
	std::ostringstream oss;
	oss << val;
	return oss.str();
}

void OSEnvironment::setCurrentDir2ExecutableDir()
{
	std::string appDir=OSEnvironment::getApplicationDir();
	::SetCurrentDirectory(CA2CT(appDir.c_str()));
}

std::string OSEnvironment::createSQLDateTimeString(std::string& ms)
{
	std::ostringstream oss;
	SYSTEMTIME st;
	::GetSystemTime(&st);

	oss << st.wYear << "-";
	oss << st.wMonth << "-";
	oss << st.wDay << " ";
	oss << std::setfill('0') << std::setw(2) << st.wHour << ":";
	oss << std::setfill('0') << std::setw(2) << st.wMinute << ":";
	oss << std::setfill('0') << std::setw(2) << st.wSecond;

	std::ostringstream oss2;
	oss2 << st.wMilliseconds;
	ms=oss2.str();
	//1776-7-4 04:13:54

	return oss.str();
}

std::string OSEnvironment::getCurrentTime()
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );

	strftime (buffer,80,"Year: %Y Month:%m Day: %d Hour: %H Minute: %M Second: %S",timeinfo);

	return std::string(buffer);
}

std::string OSEnvironment::getFileNameUsingCurrentTime()
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );

	strftime (buffer,80,"%Y_%m_%d_%H_%M_%S",timeinfo);

	return std::string(buffer);
}