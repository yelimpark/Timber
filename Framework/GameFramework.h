#pragma once
#include "../Manager/SceneManager.h"

class GameFramework {
private:
	SceneManager* sceneManager;

	sf::RenderWindow* window;

	sf::Clock clock;

public:
	GameFramework();

	bool Init();

	bool Run();

	~GameFramework();
};