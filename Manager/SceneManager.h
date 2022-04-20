#pragma once
#include "../Scene/Scene.h"

class SceneManager {
private:
	SceneType s_type;



public:
	SceneManager(SceneType s_type);

	~SceneManager();
};