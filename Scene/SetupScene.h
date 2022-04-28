#pragma once
#include "Scene.h"
#include <SFML/Audio.hpp>


using namespace sf;

class SetupScene:public Scene {
private:
	Sprite spriteBackground;

	Text textMain;

	Text textOp1;

	Text textOp2;

	Text textOn;

	Text textOff;

public:
	SetupScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void HanddleInput(sf::Event& event);

	virtual void Update(float dt);

	virtual void Render(sf::RenderWindow& window);

	virtual void Start();

	virtual void End();

	virtual ~SetupScene();
};

