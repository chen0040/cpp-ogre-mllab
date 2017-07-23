#ifndef _H_ML_LAB_GAME_AGENT_RECORDER_H
#define _H_ML_LAB_GAME_AGENT_RECORDER_H

#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../tinyxml/tinyxml.h"
#include "../CIAgents/CIGameAgent.h"
#include "../CIAgents/CIGameAgentActionState.h"

class GameAgentRecorder
{
public:
	virtual ~GameAgentRecorder();

private:
	GameAgentRecorder();
	GameAgentRecorder(const GameAgentRecorder& rhs) {}
	GameAgentRecorder& operator=(const GameAgentRecorder& rhs) { return *this; }

public:
	static std::string getGameAgentHTMLTable(const CIGameAgent* agent);
	static GameAgentRecorder* getSingletonPtr();

public:
	size_t getRecordCount() const;

private: 
	void load();

private:
	TiXmlDocument* mDoc;
	bool mModified;
	size_t mRecordCount;

public:
	void save(const std::string& datafilepath);
	void capture(CIGameAgent* userBot, CIGameAgentActionState action);
	void clear();

public:
	void setModified(bool modified);
	bool isModified() const;

};
#endif