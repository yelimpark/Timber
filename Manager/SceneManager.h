#pragma once
#include <SFML/Graphics.hpp>
#include "GameVariables.h"
#include "../Scene/MenuScene.h"
#include "../Scene/LevelScene.h"
#include "../Scene/PlayerSelectScene.h"
#include "../Scene/SetUp.h"


enum class SceneType
{
	MENU,
	SETUP,
	GAMESTART,
	LEVEL,
	PLAYER,
	CHARA,
	MAX
};

class Scene;

class SceneManager {
private:
	SceneType s_type;

	Scene* scenes[(int)SceneType::MAX];

	GameVariables gameVal;

public:
	GameVariables& GetGameVariables();

	SceneManager(SceneType s_type);

	void Init();

	void ReleaseAll();

	void ChangeScene(SceneType newScene);

	void HanddleInput(sf::Event& event);

	void Update(float dt);

	void render(sf::RenderWindow* window);

	~SceneManager();
};