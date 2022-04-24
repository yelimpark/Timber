#pragma once
#include "Scene.h"
#include "../GameObject/CharSelectPointer.h"

using namespace sf;

class CharaSelectScene : public Scene {
private:
	Sprite spriteBackground;

	Sprite spritePlayers[MAX_NUMBER_OF_ITEMS];

	CharSelectPointer selectPointers[2];

	int selectPointerCount;

public:
	CharaSelectScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void HanddleInput(sf::Event& event);

	virtual void Update(float dt);

	virtual void Render(sf::RenderWindow& window);

	virtual void Start();

	virtual void End();

	virtual ~CharaSelectScene();
};