#ifndef _H_GAME_AGENT_ACTION_STATE_H
#define _H_GAME_AGENT_ACTION_STATE_H

#include <iostream>

enum CIGameAgentActionState
{
	ATTACK=0,
	IDLE=1,
	APPROACH=2,
	WANDER=3,
	ESCAPE=4,
	DIE=5,
	SHOOT=6,
	WALK=7,
	SLUMP=8,
	DEAD=9,
	UNKNOWN_ACTION_STATE=10
};



#endif