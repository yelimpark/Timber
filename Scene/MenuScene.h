#pragma once
#include "Scene.h"

using namespace sf;

class MenuScene :public Scene {
private:
	Sprite spriteBackground;

	Text textMain;

	Text textMenu;

	Text textOp1;

	Text textOp2;

	Text textGuide;


public:
	MenuScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void HanddleInput(sf::Event& event);

	virtual void Update(float dt);

	virtual void Render(sf::RenderWindow& window);

	virtual void Start();

	virtual void End();

	virtual ~MenuScene();

};

