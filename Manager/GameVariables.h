#pragma once
#include "Singleton.h"

enum class GAME_MOD {
	SINGLE = 1,
	MULTI = 2,
	
};

class GameVariables : public Singleton<GameVariables> {
public:
	GAME_MOD Mode = GAME_MOD::MULTI;
	int selectedCharaIndex1p = 0;
	int selectedCharaIndex2p = 0;
};