#pragma once
#include "Scene/Scene.h"
#include "GameObject/charSelect.h"
#include "Manager/SceneManager.h"

using namespace sf;

class MenuScene : public Scene
{
private:
	Sprite spriteBackground;

	Text textMain;

	Text textMenu;

	Text textOp1;

	Text textOp2;

	Text textGuide;

	CircleShape triangle;

	int menuselected = 0;


public:
	MenuScene(SceneManager& sceneManager);

	virtual bool Init();

	virtual void HanddleInput(sf::Event& event);

	virtual void Update(float dt);

	virtual void render(sf::RenderWindow* window);

	virtual void Start();

	virtual void End();

	//씬을 들고오는

	~MenuScene();

};