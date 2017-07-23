/*
	This file is part of Navi, a library that allows developers to embed movable 
	'Navis' (Dynamic, HTML/JS/CSS-Driven GUI Overlays) within an Ogre3D application.

	Copyright (C) 2007 Adam J. Simmons
	http://www.agelessanime.com/Navi/

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "NaviUtilities.h"
#include "NaviManager.h"
#include <ctype.h>
#include <utf8.h>
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#include <direct.h>
#include <stdlib.h>
#endif

using namespace NaviLibrary;

std::string NaviUtilities::getCurrentWorkingDirectory()
{
	std::string workingDirectory = "";
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	char currentPath[_MAX_PATH];
	getcwd(currentPath, _MAX_PATH);
	workingDirectory = currentPath;
#endif

	return workingDirectory;
}

void NaviUtilities::translateLocalProtocols(std::string &strToTranslate)
{
	std::string localPath = "file:///";
	localPath += getCurrentWorkingDirectory();
	localPath += "/";

	NaviManager* naviMgr = NaviManager::GetPointer();
	if(!naviMgr)
		return;

	std::string localNaviDir = naviMgr->localNaviDirectory;
	if(localNaviDir.length())
	{
		localPath += localNaviDir;
		localPath += "/";
	}
	
	NaviUtilities::replaceAll(strToTranslate, "local://", localPath);
}

void NaviUtilities::translateResourceProtocols(std::string &strToTranslate)
{
	std::string resourceProtocol = "\"resource://";
	std::string resourceDataURI = "";
	std::string fileName = "";
	std::string groupName = "";
	size_t beginIdx = std::string::npos;
	size_t endIdx = std::string::npos;
	size_t idx = std::string::npos;
	size_t testIdx = std::string::npos;

	beginIdx = strToTranslate.find(resourceProtocol);
	while(beginIdx != std::string::npos)
	{
		// Found 'resource://' protocol prefix
		idx = beginIdx + resourceProtocol.length();
		endIdx = strToTranslate.find_first_of("\"", idx);

		// Check for malformed statements
		if(endIdx != std::string::npos)
		{
			// Sanity-check for more malformed statements
			testIdx = strToTranslate.find(">", beginIdx);
			if(testIdx > endIdx || testIdx == std::string::npos)
			{
				idx = strToTranslate.find_first_of("/", idx);

				if(idx == std::string::npos || idx > endIdx)
				{
					// Didn't find any further '/', Not specifying resource group
					std::string fileName = strToTranslate.substr(beginIdx + resourceProtocol.length(), endIdx - (beginIdx + resourceProtocol.length()));
					resourceDataURI = resourceToDataURI(fileName);
				}
				else
				{
					std::string groupName = strToTranslate.substr(beginIdx + resourceProtocol.length(), idx - (beginIdx + resourceProtocol.length()));
					std::string fileName = strToTranslate.substr(idx + 1, endIdx - (idx + 1));
					resourceDataURI = resourceToDataURI(fileName, groupName);
				}

				if(resourceDataURI.length())
				{
					resourceDataURI = "\"" + resourceDataURI;
					strToTranslate.erase(beginIdx, (endIdx - beginIdx));
					strToTranslate.insert(beginIdx, resourceDataURI);
				}

				beginIdx = strToTranslate.find(resourceProtocol, beginIdx + 1);
				resourceDataURI = "";
			}
			else // Uh oh! Malformed statement!
			{
				if(testIdx != std::string::npos)
					beginIdx = strToTranslate.find(resourceProtocol, testIdx + 1);
				else
					beginIdx = std::string::npos;
			}
		}
		else // Uh oh! Malformed statement!
			beginIdx = std::string::npos;
	}
}

std::string NaviUtilities::htmlToDataURI(std::string htmlString)
{
	translateLocalProtocols(htmlString);
	translateResourceProtocols(htmlString);
	
	std::string encodedDataURI = "data:";
	encodedDataURI += "text/html";
	encodedDataURI += ";base64,";
	encodedDataURI += encodeBase64(htmlString);

	return encodedDataURI;
}

std::string NaviUtilities::resourceToDataURI(const std::string &resFileName, const std::string &resourceGroupName)
{
	std::string resourceDataURI = "";

	if(!Ogre::ResourceGroupManager::getSingleton().resourceExists(resourceGroupName, resFileName))
	{
		Ogre::LogManager::getSingleton().logMessage("WARNING! In NaviUtilities::resourceToDataURI, the resource '" +
			resFileName + "' in resource group '" + resourceGroupName + "' does not exist!");
		return "";
	}

	Ogre::DataStreamPtr pStream = Ogre::ResourceGroupManager::getSingleton().openResource(resFileName, resourceGroupName);
	Ogre::String data = pStream->getAsString();

	size_t idx = resFileName.find_last_of(".");

	if(idx == std::string::npos)
		return "";
	else
	{
		std::string fExt = resFileName.substr(idx+1);
		std::string mimeType = "application/octet-stream";

		if(fExt == "html" || fExt == "htm" || fExt == "shtml")
			return htmlToDataURI(data);

		// This represents a long night of work
		if(fExt == "php")
		{
			translateLocalProtocols(data);
			translateResourceProtocols(data);
			mimeType = "text/php";
		}
		else if(fExt == "asp")
		{
			translateLocalProtocols(data);
			translateResourceProtocols(data);
			mimeType = "text/asp";
		}
		else if(fExt == "xhtml")
		{
			translateLocalProtocols(data);
			translateResourceProtocols(data);
			mimeType = "application/xhtml+xml";
		}
		else if(fExt == "xml")
		{
			translateLocalProtocols(data);
			translateResourceProtocols(data);
			mimeType = "text/xml";
		}
		else if(fExt == "js")
		{
			translateLocalProtocols(data);
			translateResourceProtocols(data);
			mimeType = "application/javascript";
		}
		else if(fExt == "cgi")
		{
			translateLocalProtocols(data);
			translateResourceProtocols(data);
			mimeType = "wwwserver/shellcgi";
		}
		else if(fExt == "css")
		{
			translateLocalProtocols(data);
			translateResourceProtocols(data);
			mimeType = "text/css";
		}
		else if(fExt == "swf") mimeType = "application/x-shockwave-flash";
		else if(fExt == "mml") mimeType = "application/mathml+xml";
		else if(fExt == "svg") mimeType = "image/svg+xml";
		else if(fExt == "xslt") mimeType = "application/xslt+xml";
		else if(fExt == "rss") mimeType = "application/rss+xml";
		else if(fExt == "txt") mimeType = "text/plain";
		else if(fExt == "rtf") mimeType = "text/rtf";
		else if(fExt == "doc") mimeType = "application/doc";
		else if(fExt == "gif") mimeType = "image/gif";
		else if(fExt == "jpg" || fExt == "jpeg") mimeType = "image/jpeg";
		else if(fExt == "png") mimeType = "image/png";
		else if(fExt == "tiff") mimeType = "image/tiff";
		else if(fExt == "tga" || fExt == "targa") mimeType = "image/tga";
		else if(fExt == "bmp") mimeType = "image/bmp";
		else if(fExt == "wbmp") mimeType = "image/vnd.wap.wbmp";
		else if(fExt == "pdf") mimeType = "application/pdf";
		else if(fExt == "flv") mimeType = "video/x-flv";
		else if(fExt == "mpg" || fExt == "mpeg") mimeType = "video/mpeg";
		else if(fExt == "mp4") mimeType = "video/mp4";
		else if(fExt == "mov") mimeType = "video/quicktime";
		else if(fExt == "wmv") mimeType = "video/x-ms-wmv";
		else if(fExt == "rm") mimeType = "application/vnd.rn-realmedia";
		else if(fExt == "ogg") mimeType = "application/ogg";
		else if(fExt == "mp3") mimeType = "audio/mpeg";
		else if(fExt == "wav") mimeType = "audio/wav";
		else if(fExt == "wma") mimeType = "audio/x-ms-wma";
		else if(fExt == "asf") mimeType = "application/asx";
		else if(fExt == "au") mimeType = "audio/au";
		else if(fExt == "mid" || fExt == "midi") mimeType = "audio/midi";

		resourceDataURI = "data:";
		resourceDataURI += mimeType;
		resourceDataURI += ";base64,";
		resourceDataURI += encodeBase64(data);

		return resourceDataURI;
	}

	return "";
}

std::string NaviUtilities::encodeURIComponent(std::wstring strToEncode)
{
	std::string result;
	std::vector<int> temp;
	std::back_insert_iterator<std::vector<int>> bI(temp);
	
	for(std::wstring::iterator i = strToEncode.begin(); i != strToEncode.end(); ++i)
	{
		if(!(('a' <= *i && 'z' >= *i) || ('A' <= *i && 'Z' >= *i) ||
			('0' <= *i && '9' >= *i) || (*i == '-') || (*i == '_') ||
			(*i == '.') || (*i == '!') || (*i == '~') || (*i == '*') ||
			(*i == '\'') || (*i == '(') || (*i == ')')))
		{
			try { utf8::append((int)*i, bI); } catch(...) {}

			if(temp.size())
			{
				for(std::vector<int>::iterator iter = temp.begin(); iter != temp.end(); ++iter)
				{
					char buffer[32];
					sprintf_s(buffer, 32, "%%%02lX", *iter);
					result += buffer;
				}
				temp.clear();
			}
		}
		else
			result += (char)*i;
	}

	return result;
}

std::wstring NaviUtilities::decodeURIComponent(std::string strToDecode)
{
	std::wstring result;
	std::vector<int> temp;
	char buffer[3] = {0, 0, 0};
	std::string::iterator i = strToDecode.begin();

	while(i != strToDecode.end())
	{
		if(*i == '%')
		{
			for(;i != strToDecode.end(); ++i)
			{
				if(*i == '%')
				{
					if(++i == strToDecode.end()) break;
					if(!(('a' <= *i && 'z' >= *i) || ('A' <= *i && 'Z' >= *i) || ('0' <= *i && '9' >= *i))) break;

					buffer[0] = *i;

					if(++i == strToDecode.end()) break;
					if(!(('a' <= *i && 'z' >= *i) || ('A' <= *i && 'Z' >= *i) || ('0' <= *i && '9' >= *i))) break;

					buffer[1] = *i;
					temp.push_back(static_cast<int>(strtol(buffer, 0, 16)));
				}
				else break;
			}

			if(temp.size())
			{
				std::vector<int>::iterator tI = temp.begin();
				try {
					while(utf8::distance(tI, temp.end()) > 0)
						result += (wchar_t)utf8::next(tI, temp.end());
				} catch(...) {}

				temp.clear();
			}
		}
		else
		{
			result += *i;
			++i;
		}
	}

	return result;
}

std::string NaviUtilities::lowerString(std::string strToLower)
{	
	for(unsigned int i = 0; i < strToLower.length(); i++)
		strToLower[i] = tolower(strToLower[i]);

	return strToLower;
}

bool NaviUtilities::isNumeric(const std::string &numberString)
{
	std::istringstream converter(numberString);
	int test;

	return isPrefixed(numberString, "true") || isPrefixed(numberString, "false") ? true : !(converter >> test).fail();
}

std::wstring NaviUtilities::toWide(const std::string &stringToConvert)
{
	size_t size = mbstowcs(0, stringToConvert.c_str(), 0) + 1;
	wchar_t *temp = new wchar_t[size];
	mbstowcs(temp, stringToConvert.c_str(), size);
	std::wstring result(temp);
	delete[] temp;
	return result;
}

std::string NaviUtilities::toMultibyte(const std::wstring &wstringToConvert)
{
	size_t size = wcstombs(0, wstringToConvert.c_str(), 0) + 1;
	char *temp = new char[size];
	wcstombs(temp, wstringToConvert.c_str(), size);
	std::string result(temp);
	delete[] temp;
	return result;
}

void NaviUtilities::setLocale(const std::string &localeLanguage)
{
	setlocale(LC_CTYPE, localeLanguage.c_str());
}

int NaviUtilities::replaceAll(std::string &sourceStr, const std::string &replaceWhat, const std::string &replaceWith)
{
	int count = 0;

	for(size_t i = sourceStr.find(replaceWhat); i != std::string::npos; i = sourceStr.find(replaceWhat, i + replaceWith.length()))
	{
		sourceStr.erase(i, replaceWhat.length());
		sourceStr.insert(i, replaceWith);
		++count;
	}

	return count;
}

std::vector<std::string> NaviUtilities::split(const std::string &sourceStr, const std::string &delimiter, bool ignoreEmpty)
{
	std::vector<std::string> resultVector;

	size_t idxA = 0;
	size_t idxB = sourceStr.find(delimiter);
	std::string tempStr;
	bool done = false;

	while(!done)
	{
		if(idxB != std::string::npos)
		{
			tempStr = sourceStr.substr(idxA, idxB-idxA);
			idxA = idxB + delimiter.length();
			idxB = sourceStr.find(delimiter, idxA);
		}
		else
		{
			tempStr = sourceStr.substr(idxA);
			done = true;
		}

		if(!(ignoreEmpty && tempStr.empty()))
			resultVector.push_back(tempStr);
	}

	return resultVector;
}

std::map<std::string,std::string> NaviUtilities::splitToMap(const std::string &sourceStr, const std::string &pairDelimiter, const std::string &keyValueDelimiter, bool ignoreEmpty)
{
	std::map<std::string,std::string> resultMap;

	size_t idx = 0;
	std::string strA, strB;

	std::vector<std::string> tempVector = split(sourceStr, pairDelimiter);

	for(std::vector<std::string>::const_iterator i = tempVector.begin(); i != tempVector.end(); i++)
	{
		idx = i->find(keyValueDelimiter);
		if(idx != std::string::npos)
		{
			strA = i->substr(0, idx);
			strB = i->substr(idx + keyValueDelimiter.length());

			if(!(ignoreEmpty && (strA.empty() || strB.empty())) && !resultMap.count(strA))
				resultMap[strA] = strB;
		}
	}

	return resultMap;
}

std::string NaviUtilities::join(const std::vector<std::string> &sourceVector, const std::string &delimiter, bool ignoreEmpty)
{
	std::string result = "";

	for(std::vector<std::string>::const_iterator i = sourceVector.begin(); i != sourceVector.end(); i++)
		if(!(ignoreEmpty && i->empty()))
			result += result.length() ? delimiter + (*i) : (*i);

	return result;
}

std::string NaviUtilities::joinFromMap(const std::map<std::string,std::string> &sourceMap, const std::string &pairDelimiter, const std::string &keyValueDelimiter, bool ignoreEmpty)
{
	std::string result = "";

	for(std::map<std::string,std::string>::const_iterator i = sourceMap.begin(); i != sourceMap.end(); i++)
		if(!(ignoreEmpty && (i->first.empty() || i->second.empty())))
			result += result.length() ? pairDelimiter + i->first + keyValueDelimiter + i->second : i->first + keyValueDelimiter + i->second;

	return result;
}

NaviUtilities::MultiValue::MultiValue() { }

NaviUtilities::MultiValue::MultiValue(const std::string &value) { *this = value; }

NaviUtilities::MultiValue::MultiValue(const char *value) { *this = std::string(value); }

NaviUtilities::MultiValue::MultiValue(const std::wstring &value) { *this = value; }

NaviUtilities::MultiValue::MultiValue(int value) { *this = value; }

NaviUtilities::MultiValue::MultiValue(size_t value) { *this = value; }

NaviUtilities::MultiValue::MultiValue(float value) { *this = value; }

NaviUtilities::MultiValue::MultiValue(double value) { *this = value; }

NaviUtilities::MultiValue::MultiValue(bool value) { *this = value; }

NaviUtilities::MultiValue& NaviUtilities::MultiValue::operator=(const std::string &value)
{
	this->value = toWide(value);
	isWide = false;
	return *this;
}

NaviUtilities::MultiValue& NaviUtilities::MultiValue::operator=(const std::wstring &value)
{
	this->value = value;
	isWide = true;
	return *this;
}

NaviUtilities::MultiValue& NaviUtilities::MultiValue::operator=(int value)
{
	this->value = toWide(numberToString(value));
	isWide = false;
	return *this;
}

NaviUtilities::MultiValue& NaviUtilities::MultiValue::operator=(size_t value)
{
	this->value = toWide(numberToString(value));
	isWide = false;
	return *this;
}

NaviUtilities::MultiValue& NaviUtilities::MultiValue::operator=(float value)
{
	this->value = toWide(numberToString(value));
	isWide = false;
	return *this;
}

NaviUtilities::MultiValue& NaviUtilities::MultiValue::operator=(double value)
{
	this->value = toWide(numberToString(value));
	isWide = false;
	return *this;
}

NaviUtilities::MultiValue& NaviUtilities::MultiValue::operator=(bool value)
{
	this->value = toWide(numberToString(value));
	isWide = false;
	return *this;
}

std::wstring NaviUtilities::MultiValue::wstr() const { return value; }

std::string NaviUtilities::MultiValue::str() const {return toMultibyte(value); }

bool NaviUtilities::MultiValue::isEmpty() const { return value.empty(); }

bool NaviUtilities::MultiValue::isNumber() const { return isNumeric(toMultibyte(value)); }

bool NaviUtilities::MultiValue::isWideString() const { return isWide; }

int NaviUtilities::MultiValue::toInt() const { return toNumber<int>(toMultibyte(value)); }

float NaviUtilities::MultiValue::toFloat() const { return toNumber<float>(toMultibyte(value)); }

double NaviUtilities::MultiValue::toDouble() const  { return toNumber<double>(toMultibyte(value)); }

bool NaviUtilities::MultiValue::toBool() const { return toNumber<bool>(toMultibyte(value)); }

std::string NaviUtilities::templateString(const std::string &templateStr, const NaviUtilities::Args &args)
{
	if(!(args.size() && templateStr.size()))
		return templateStr;

	std::string result;
	std::vector<std::string> temp = split(templateStr, "?", false);

	for(unsigned int i = 0; i < temp.size(); ++i)
	{
		result += temp[i];
		if(args.size() > i && i != temp.size()-1)
			result += args[i].str();			
	}

	return result;
}

void NaviUtilities::logTemplate(const std::string &templateStr, const NaviUtilities::Args &args)
{
	Ogre::LogManager::getSingleton().logMessage(templateString(templateStr, args));
}

bool NaviUtilities::hexStringToRGB(const std::string& hexString, unsigned char &R, unsigned char &G, unsigned char &B)
{
	if(hexString.length() == 7)
	{
		if(hexString.find("#") == 0 && hexString.substr(1).find_first_not_of("0123456789ABCDEFabcdef") == std::string::npos)
		{
			R = static_cast<unsigned char>(strtoul(hexString.substr(1, 2).c_str(), 0, 16));
			G = static_cast<unsigned char>(strtoul(hexString.substr(3, 2).c_str(), 0, 16));
			B = static_cast<unsigned char>(strtoul(hexString.substr(5, 2).c_str(), 0, 16));

			return true;
		}
	}

	return false;
}

/**
* The following is freely-available code by René Nyffenegger
* Obtained from: http://www.adp-gmbh.ch/cpp/common/base64.html
*/
std::string NaviUtilities::encodeBase64(const std::string &strToEncode)
{
	unsigned char const* bytes_to_encode = reinterpret_cast<const unsigned char*>(strToEncode.c_str());
	unsigned int in_len = (unsigned int)strToEncode.length();
	const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	std::string ret;
	int i = 0;
	int j = 0;
	unsigned char char_array_3[3];
	unsigned char char_array_4[4];

	while(in_len--)
	{
		char_array_3[i++] = *(bytes_to_encode++);

		if(i == 3)
		{
			char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
			char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
			char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
			char_array_4[3] = char_array_3[2] & 0x3f;

			for(i = 0; i < 4; i++)
				ret += base64_chars[char_array_4[i]];

			i = 0;
		}
	}

	if(i)
	{
		for(j = i; j < 3; j++)
			char_array_3[j] = '\0';

		char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
		char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
		char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
		char_array_4[3] = char_array_3[2] & 0x3f;

		for (j = 0; (j < i + 1); j++)
			ret += base64_chars[char_array_4[j]];

		while((i++ < 3))
			ret += '=';
	}

	return ret;
}