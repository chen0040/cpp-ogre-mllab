#include "GameAgentRecorder.h"
#include <sstream>
#include <ctime>
#include "../OSEnvironment/OSEnvironment.h"
#include <boost/filesystem.hpp>

GameAgentRecorder::GameAgentRecorder()
: mModified(false)
{
	load();
}

void GameAgentRecorder::load()
{
	mDoc=new TiXmlDocument();
	std::string datafilepath=OSEnvironment::getFullPath("..\\records\\data.xml");
	if(OSEnvironment::exists(datafilepath))
	{
		if(!mDoc->LoadFile(datafilepath.c_str()))
		{
			throw Exception(42, "Failed to load data.xml", "GameAgentRecorder::GameAgentRecorder()");
		}
		TiXmlElement* xmlRoot=mDoc->RootElement();
		mRecordCount=0;
		for(TiXmlElement* xmlLevel1=xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1=xmlLevel1->NextSiblingElement())
		{
			mRecordCount++;
		}
	}
	else
	{
		mDoc->LinkEndChild(new TiXmlDeclaration("1.0", "", ""));
		mDoc->LinkEndChild(new TiXmlElement("trainingdata"));
		mRecordCount=0;
	}
}

GameAgentRecorder::~GameAgentRecorder()
{
	if(mDoc != NULL)
	{
		delete mDoc;
		mDoc=NULL;
	}
}

GameAgentRecorder* GameAgentRecorder::getSingletonPtr()
{
	static GameAgentRecorder theInstance;
	return &theInstance;
}

std::string GameAgentRecorder::getGameAgentHTMLTable(const CIGameAgent* agent)
{
	std::ostringstream oss;

	oss << "<table>";
	oss << "<tr>";
	oss << "<td>Name:</td><td>" << agent->getAgentName() << "</td>";
	oss << "<td>Armor:</td><td>" << agent->getArmor() << "</td>";
	oss << "</tr>";
	oss << "<tr>";
	oss << "<td>Life:</td><td>" << agent->getLife() << "</td>";
	oss << "<td>Score:</td><td>" << agent->getScore() << "</td>";
	oss << "<td>Sense Range: </td><td>" << agent->getSenseRange() << "</td>";
	oss << "</tr>";
	oss << "<tr>";
	oss << "<td>ScriptId:</td><td>" << agent->getScriptId() << "</td>";
	oss << "<td>Tag: </td><td>" << agent->getTag() << "</td>";
	oss << "</tr>";
	oss << "<tr>";
	oss << "<td>Action: </td><td colspan=3>" << agent->getRegisteredAction() << "[" 
		<< (agent->getCurrentTarget() == NULL ? "" : agent->getCurrentTarget()->getAgentName()) << "]" << "</td>";
	oss << "</tr>";
	oss << "<tr>";
	Gun* agent_gun=agent->getGun();
	oss << "<td>Weapon:</td><td>Impact:" << agent_gun->getWeaponImpact() << "</td><td>Penetration: " 
		<< agent_gun->getWeaponPenetration() << "</td><td>Speed:" << agent_gun->getWeaponSpeed() << "</td><td>Delay:"
		<< agent->getFiringDelay() << "</td>";
	oss << "</tr>";
	oss << "</table>";

	return oss.str();
}

void GameAgentRecorder::save(const std::string& dirpath)
{
	std::ostringstream oss;
	oss << dirpath << "\\data.xml";
	mDoc->SaveFile(oss.str().c_str());

	oss.str("");
	oss << dirpath << "\\data.lua";
	std::ofstream fout;
	fout.open(oss.str().c_str());

	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );

	strftime (buffer,80,"Year: %Y Month:%m Day: %d Hour: %H Minute: %M Second: %S",timeinfo);

	fout << "--" << buffer << "\n";
		
	fout << "local userbot={};\n";
	fout << "local recordIndex=0;\n";
	fout << "local GameAgentFactory=dofile(getDefaultScriptPath() .. \"\\\\GameAgent.lua\");\n\n";

	int index=0;
	TiXmlElement* xmlRoot=mDoc->RootElement();
	for(TiXmlElement* xmlLevel1=xmlRoot->FirstChildElement(); xmlLevel1 != NULL; xmlLevel1=xmlLevel1->NextSiblingElement())
	{
		if(strcmp(xmlLevel1->Value(), "record")==0)
		{
			fout << "--recordIndex: " << ++index << "\n";
			fout << "recordIndex=recordIndex+1;\n";
			fout << "userbot[recordIndex]=GameAgentFactory.create(\"UserBot\");\n";
			
			for(TiXmlElement* xmlLevel2=xmlLevel1->FirstChildElement(); xmlLevel2 != NULL; xmlLevel2=xmlLevel2->NextSiblingElement())
			{
				if(strcmp(xmlLevel2->Value(), "state")==0 || strcmp(xmlLevel2->Value(), "output")==0)
				{
					fout << "userbot[recordIndex]:" << xmlLevel2->Attribute("luaSet") << "(" << xmlLevel2->Attribute("value") << ");\n";
				}
			}

			fout << "\n";
		}
		
	}

	fout << "return userbot;\n";
	fout.close();
}

void GameAgentRecorder::setModified(bool modified)
{
	mModified=modified;
}

bool GameAgentRecorder::isModified() const
{
	return mModified;
}

size_t GameAgentRecorder::getRecordCount() const
{
	return mRecordCount;
}

void GameAgentRecorder::clear()
{
	if(mDoc != NULL)
	{
		delete mDoc;
	}
	load();
}

void GameAgentRecorder::capture(CIGameAgent* userBot, CIGameAgentActionState action)
{
	TiXmlElement* xmlRecord=new TiXmlElement("record");
	
	TiXmlElement* state1=new TiXmlElement("state");
	state1->SetAttribute("index", 1);
	state1->SetAttribute("comment", "is my target attackable");
	state1->SetAttribute("luaGet", "isTargetAttackable");
	state1->SetAttribute("luaSet", "setTargetAttackable");
	state1->SetAttribute("value", static_cast<int>(userBot->isTargetAttackable()));
	xmlRecord->LinkEndChild(state1);

	TiXmlElement* state2=new TiXmlElement("state");
	state2->SetAttribute("index", 2);
	state2->SetAttribute("comment", "number of my attackers");
	state2->SetAttribute("luaGet", "getSightedAttackerCount");
	state2->SetAttribute("luaSet", "setSightedAttackerCount");
	state2->SetAttribute("value", static_cast<int>(userBot->getSightedAttackerCount()));
	xmlRecord->LinkEndChild(state2);

	TiXmlElement* state3=new TiXmlElement("state");
	state3->SetAttribute("index", 3);
	state3->SetAttribute("comment", "target distance divided by my shooting range");
	state3->SetAttribute("luaGet", "getTargetRelativeDistance");
	state3->SetAttribute("luaSet", "setTargetRelativeDistance");
	state3->SetDoubleAttribute("value", userBot->getTargetRelativeDistance());
	xmlRecord->LinkEndChild(state3);

	TiXmlElement* state4=new TiXmlElement("state");
	state4->SetAttribute("index", 4);
	state4->SetAttribute("comment", "target life divided by my life");
	state4->SetAttribute("luaGet", "getTargetRelativeLife");
	state4->SetAttribute("luaSet", "setTargetRelativeLife");
	state4->SetAttribute("value", userBot->getTargetRelativeLife());
	xmlRecord->LinkEndChild(state4);

	TiXmlElement* state5=new TiXmlElement("state");
	state5->SetAttribute("index", 5);
	state5->SetAttribute("comment", "my number of bullets remained");
	state5->SetAttribute("luaGet", "getGun():getBulletCount");
	state5->SetAttribute("luaSet", "getGun():setBulletCount");
	state5->SetAttribute("value", static_cast<int>(userBot->getGun()->getBulletCount()));
	xmlRecord->LinkEndChild(state5);

	TiXmlElement* state6=new TiXmlElement("state");
	state6->SetAttribute("index", 6);
	state6->SetAttribute("comment", "my health");
	state6->SetAttribute("luaGet", "getLife");
	state6->SetAttribute("luaSet", "setLife");
	state6->SetAttribute("value", userBot->getLife());
	xmlRecord->LinkEndChild(state6);

	TiXmlElement* state7=new TiXmlElement("state");
	state7->SetAttribute("index", 7);
	state7->SetAttribute("comment", "my score");
	state7->SetAttribute("luaGet", "getScore");
	state7->SetAttribute("luaSet", "setScore");
	state7->SetDoubleAttribute("value", userBot->getScore());
	xmlRecord->LinkEndChild(state7);

	TiXmlElement* output=new TiXmlElement("output");
	output->SetAttribute("index", 1);
	output->SetAttribute("comment", "my action");

	std::string comments;
	if(action==APPROACH)
	{
		comments="GameAgentAction.APPROACH";
	}
	else if(action==ATTACK)
	{
		comments="GameAgentAction.ATTACK";
	}
	else if(action==ESCAPE)
	{
		comments="GameAgentAction.ESCAPE";
	}
	else if(action==IDLE)
	{
		comments="GameAgentAction.IDLE";
	}
	else if(action==WANDER)
	{
		comments="GameAgentAction.WANDER";
	}
	output->SetAttribute("symbol", comments.c_str());
	output->SetAttribute("value", action);
	output->SetAttribute("luaSet", "setCurrentAction");
	output->SetAttribute("luaGet", "getCurrentAction");
	xmlRecord->LinkEndChild(output);


	mDoc->RootElement()->LinkEndChild(xmlRecord);
	mRecordCount++;
}