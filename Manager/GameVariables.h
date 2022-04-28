#pragma once
#include "Singleton.h"

enum class GAME_MOD {
	SINGLE = 1,
	MULTI = 2,
	
};

class GameVariables : public Singleton<GameVariables> {
public:
	static GAME_MOD Mode;
	static int selectedCharaIndex1p;
	static int selectedCharaIndex2p;
};