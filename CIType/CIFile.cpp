#include "CIFile.h"

#include "../OSEnvironment/OSEnvironment.h"

CIFile::CIFile(TiXmlElement* xmlElement)
{
	mType=xmlElement->Attribute("type");
	mSrc=xmlElement->Attribute("src");
	mName=xmlElement->Attribute("name");
	if(strcmp(xmlElement->Attribute("config"), "true")==0)
	{
		mConfig=true;
	}
	else
	{
		mConfig=false;
	}
}

CIFile::~CIFile()
{

}

void CIFile::generateCode(const std::string& destinationFolder, const std::string& fileType, const ConfigDlg* config)
{
	if(mType.compare(fileType) != 0)
	{
		return;
	}
	std::string destinationFile=destinationFolder+"\\"+mName;
	std::string sourceFile=OSEnvironment::getFullPath(mSrc);

	OSEnvironment::copyFile(sourceFile, destinationFile, false);

	if(mConfig && config != NULL)
	{
		config->processFile(destinationFile, fileType);
	}
}