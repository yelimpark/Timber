#pragma once
#include <SFML/Graphics.hpp>
#include "GameVariables.h"

enum class SceneType {
	MENU,
	SETUP,
	LEVEL,
	PLAYER,
	CHARA,
	STAGE, 
	MAX
};

class Scene;

class SceneManager {
private:
	SceneType currScene;

	Scene* scenes[(int)SceneType::MAX];

	GameVariables gameVal;

public:
	GameVariables& GetGameVariables();

	SceneManager();

	void Init();

	void ReleaseAll();

	void ChangeScene(SceneType newScene);

	void HanddleInput(sf::Event& event);

	void Update(float dt);

	void Render(sf::RenderWindow& window);

	~SceneManager();
};