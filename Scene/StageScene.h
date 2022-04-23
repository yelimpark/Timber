#pragma once
#include "Scene.h"
#include <SFML/Audio.hpp>

#include "../GameObject/Player.h"
#include "../GameObject/LowDynamicObj.h"
#include "../GameObject/TimeBar.h"
#include "../GameObject/FlyingLog.h"

#define clouds_size 3
#define countBranches 6

using namespace sf;

class StageScene : public Scene{
private:
	std::mt19937 gen;

	Player player;

	LowDynamicObj clouds[clouds_size];

	LowDynamicObj bee;

	TimeBar timeBar;

	Sprite spriteBackground;

	Sprite spriteTree;

	FlyingLog flyingLog;

	Sprite spriteBranches[countBranches];
	side sideBranches[countBranches];

	bool acceptInput;
	bool isPause;

	int score;

	sf::Sound chop;

	sf::Sound death;

	sf::Sound oot;

	Text textMessage;

	FloatRect textRect;

	Text textScore;

public:
	StageScene(SceneManager& sceneManager);

	virtual bool Init() override;

	virtual void HanddleInput(sf::Event& event) override;

	virtual void Update(float dt) override;

	virtual void render(sf::RenderWindow* window) override;

	virtual void Start() override;

	virtual void End() override;

	~StageScene();
};