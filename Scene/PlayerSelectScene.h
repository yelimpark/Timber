#pragma once
#include "Scene.h"

using namespace sf;


class PlayerSelectScene :public Scene {
private:
	Sprite spriteBackground;

	Text textMain;

	Text textPlayer1;

	Text textPlayer2;
public:
	PlayerSelectScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void HanddleInput(sf::Event& event);

	virtual void Update(float dt);

	virtual void Render(sf::RenderWindow& window);

	virtual void Start();

	virtual void End();

	virtual ~PlayerSelectScene();
};

