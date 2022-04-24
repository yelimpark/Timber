#pragma once
#include "../Manager/SceneManager.h"

class Scene {
protected:
	SceneManager& sceneManager;

public:
	Scene(SceneManager& sceneManager);

	virtual void Init() = 0;

	virtual void HanddleInput(sf::Event& event) = 0;

	virtual void Update(float dt) = 0;

	virtual void Render(sf::RenderWindow& window) = 0;

	virtual void Start() = 0;

	virtual void End() = 0;

	virtual ~Scene();
};