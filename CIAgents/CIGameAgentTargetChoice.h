#ifndef _H_CI_GAME_AGENT_ENEMY_CHOICE_H
#define _H_CI_GAME_AGENT_ENEMY_CHOICE_H

enum CIGameAgentTargetChoice
{
	DEFAULT_ENEMY=0,
	CLOSEST_ENEMY=1,
	RANDOM_ENEMY=2,
	STRONGEST_ENEMY=3,
	WEAKEST_ENEMY=4,
	ATTACKER_ENEMY=5,
	UNKOWN_ENEMY_CHOICE=6
};

#endif