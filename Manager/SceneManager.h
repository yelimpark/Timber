#pragma once
#include <SFML/Graphics.hpp>
#include "GameVariables.h"

enum class SceneType {
	CHARA,
	STAGE, 
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