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

#include "NaviData.h"
#include <sstream>
#include "OgreException.h"
#include "OgreStringConverter.h"


using namespace NaviLibrary;
using namespace NaviLibrary::NaviUtilities;


NaviData::NaviData(const std::string &name, const std::string &queryString)
{
	this->name = name;

	if(queryString.length())
	{
		std::map<std::string,std::string> tempMap = splitToMap(queryString, "&", "=", false);
		
		for(std::map<std::string,std::string>::iterator i = tempMap.begin(); i != tempMap.end(); ++i)
			data[i->first] = decodeURIComponent(i->second);
	}
}

bool NaviData::ensure(const std::string &key, bool throwOnFailure) const
{
	std::string keyName = key;
	bool checkNumeric = false;

	if(isPrefixed(keyName, "#"))
	{
		keyName = keyName.substr(1);
		checkNumeric = true;
	}

	std::map<std::string,MultiValue>::const_iterator iter = data.find(keyName);

	if(iter == data.end())
	{
		
		if(throwOnFailure)
		{
			std::stringstream errorMsg;
			errorMsg << "A piece of NaviData failed validation. The requested key does not exist." << std::endl
				<< "NaviData Name: " << name << std::endl
				<< "Key: " << keyName << std::endl << std::endl;

			OGRE_EXCEPT(Ogre::Exception::ERR_RT_ASSERTION_FAILED, errorMsg.str(), "NaviData::ensure");
		}

		return false;
	}

	if(checkNumeric)
	{

		if(!isNumeric(iter->second.str()))
		{
			if(throwOnFailure)
			{
				std::stringstream errorMsg;
				errorMsg << "A piece of NaviData failed validation. The value of the requested key is not numeric." << std::endl
				<< "NaviData Name: " << name << std::endl
				<< "Key: " << keyName << std::endl
				<< "Value: " << iter->second.str() << std::endl << std::endl;

				OGRE_EXCEPT(Ogre::Exception::ERR_RT_ASSERTION_FAILED, errorMsg.str(), "NaviData::ensure");
			}

			return false;
		}
	}

	return true;
}

bool NaviData::ensure(const std::vector<std::string> &keys, bool throwOnFailure) const
{
	for(std::vector<std::string>::const_iterator i = keys.begin(); i != keys.end(); ++i)
		if(!ensure(*i, throwOnFailure))
			return false;

	return true;
}

std::string NaviData::getName() const
{
	return name;
}

bool NaviData::exists(const std::string &keyName) const
{
	return data.find(keyName) != data.end();
}

const MultiValue& NaviData::operator[](const std::string &keyName) const
{
	std::map<std::string,MultiValue>::const_iterator iter = data.find(keyName);
	
	if(iter != data.end())
		return iter->second;

	static MultiValue empty;

	return empty;
}

MultiValue& NaviData::operator[](const std::string &keyName)
{
	return data[keyName];
}

int NaviData::size() const
{
	return (int)data.size();
}

std::map<std::string,std::string> NaviData::toStringMap(bool encodeVals) const
{
	std::map<std::string,std::string> stringMap;

	for(std::map<std::string,MultiValue>::const_iterator i = data.begin(); i != data.end(); ++i)
		stringMap[i->first] = encodeVals ? encodeURIComponent(i->second.wstr()) : i->second.str();

	return stringMap;
}

std::string NaviData::toQueryString() const
{
	return joinFromMap(toStringMap(true), "&", "=", false);;
}
