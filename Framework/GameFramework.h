#pragma once
//#include "../Manager/SceneManager.h"
#include "../Scene/StageScene.h"

class GameFramework {
private:
	//SceneManager* sceneManager;

public:
	GameFramework();

	bool Initialize();

	bool Run();

	~GameFramework();
};