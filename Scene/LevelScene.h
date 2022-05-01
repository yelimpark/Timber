#pragma once
#include "Scene.h"
#include "../GameObject/TimeBar.h"
#include "../GameObject/CharSelectPointer.h"
using namespace sf;

class LevelScene :public Scene {
private:
	Sprite spriteBackground;

	Text textMain;
	Text textLevel1;
	Text textLevel2;
	Text textLevel3;

	TimeBar timebar;

public:
	LevelScene(SceneManager& sceneManager);

	virtual void Init();

	virtual void HanddleInput(sf::Event& event);

	virtual void Update(float dt);

	virtual void Render(sf::RenderWindow& window);

	virtual void Start();

	virtual void End();

	virtual ~LevelScene();

};

