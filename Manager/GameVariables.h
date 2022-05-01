#pragma once
#include "Singleton.h"

class GameVariables : public Singleton<GameVariables> {
public:
	int selectedCharaIndex = 0;
};