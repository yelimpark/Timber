#pragma once
#include <SFML/Graphics.hpp>

enum class SceneType {
	STAGE, MAX
};

class Scene;

class SceneManager {
private:
	SceneType s_type;

	Scene* scenes[(int)SceneType::MAX];

public:
	SceneManager(SceneType s_type);

	void Init();

	void ReleaseAll();

	void ChangeScene(SceneType newScene);

	void HanddleInput(sf::Event& event);

	void Update(float dt);

	void render(sf::RenderWindow* window);

	~SceneManager();
};