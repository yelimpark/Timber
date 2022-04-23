#pragma once
#include "Scene.h"
#include "../GameObject/charSelect.h"

using namespace sf;

class CharaSelectScene : public Scene {
private:
	Sprite spriteBackground;

	Sprite spritePlayers[MAX_NUMBER_OF_ITEMS];

	charSelect chooseChar;

public:
	CharaSelectScene(SceneManager& sceneManager);

	virtual bool Init();

	virtual void HanddleInput(sf::Event& event);

	virtual void Update(float dt);

	virtual void render(sf::RenderWindow* window);

	virtual void Start();

	virtual void End();

	~CharaSelectScene();
};