#pragma once
#include "Scene.h"
#include "../GameObject/Player.h"

class StageScene : public Scene{
private:
	Player * player;

public:
	StageScene(SceneType s_type, sf::RenderWindow* window);

	bool initialize();

	void update();

	void render();

	~StageScene();
};