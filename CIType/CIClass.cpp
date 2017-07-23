#include "CIClass.h"

CIClass::CIClass(TiXmlElement* xmlElement)
{
	for(TiXmlElement* xmlLevel1=xmlElement->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1=xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "file")==0)
		{
			std::string name=xmlLevel1->Attribute("name");
			CIFile* stcf=new CIFile(xmlLevel1);
			mFiles[name]=stcf;
		}
	}
}

CIClass::~CIClass()
{
	std::map<std::string, CIFile*>::iterator iter=mFiles.begin();
	std::map<std::string, CIFile*>::iterator iter_end=mFiles.end();
	for(; iter != iter_end; ++iter)
	{
		delete (iter->second);
	}
	mFiles.clear();
}

void CIClass::generateCode(const std::string& destinationFolder, const std::string& fileType, const ConfigDlg* config)
{
	std::map<std::string, CIFile*>::iterator iter=mFiles.begin();
	std::map<std::string, CIFile*>::iterator iter_end=mFiles.end();
	CIFile* file;
	for(; iter != iter_end; ++iter)
	{
		file=iter->second;
		file->generateCode(destinationFolder, fileType, config);
	}
}