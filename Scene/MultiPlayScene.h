#pragma once
#include <SFML/Audio.hpp>
#include "Scene.h"

#include "../GameObject/MultiPlayer.h"
#include "../GameObject/LowDynamicObj.h"
#include "../GameObject/TimeBar.h"
#include "../GameObject/FlyingLog.h"

#define clouds_size 3
#define countBranches 6

using namespace sf;
using namespace std;

class MultiPlayScene : public Scene
{
private:
	mt19937 gen;
	MultiPlayer player1;
	MultiPlayer player2;
	LowDynamicObj clouds[clouds_size];
	LowDynamicObj bee;
	TimeBar timeBar;
	Sprite spriteBackground;
	Sprite spriteTree1P;
	Sprite spriteTree2P;
	FlyingLog flyingLog1P;
	FlyingLog flyingLog2P;
	Sprite spriteBranches1P[countBranches];
	Sprite spriteBranches2P[countBranches];
	sideMulti sideBranches1P[countBranches];
	sideMulti sideBranches2P[countBranches];

	bool acceptInput1P;
	bool acceptInput2P;
	bool isDead1P;
	bool isDead2P;
	bool isPause;

	int score1P;
	int score2P;

	Sound chop;
	Sound death;
	Sound oot;

	Text textMessage;
	FloatRect textRect;

	Text textScore;
public:
	MultiPlayScene(SceneManager& sceneManager);
	virtual bool Init() override;
	virtual void HanddleInput(sf::Event& event) override;
	virtual void Update(float dt) override;
	virtual void render(sf::RenderWindow* window) override;
	virtual void Start() override;
	virtual void End() override;
	~MultiPlayScene();
};