#pragma once
#include <SFML/Graphics.hpp>
#include <random>

enum class SceneType {
	STAGE
};

class Scene {
protected:
	SceneType s_type;
	sf::RenderWindow * window;

public:
	Scene(SceneType s_type, sf::RenderWindow* window);

	virtual bool initialize() = 0;

	virtual void update() = 0;

	virtual void render() = 0;

	~Scene();
};