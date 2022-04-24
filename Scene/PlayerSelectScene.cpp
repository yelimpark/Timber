#include "PlayerSelectScene.h"
#include "../Manager/ResourceMgr.h"
#include "LevelScene.h"
#include <sstream>

using namespace std;

PlayerSelectScene::PlayerSelectScene(SceneManager& sceneManager) :Scene(sceneManager)
{
}

void PlayerSelectScene::Init()
{
	spriteBackground.setTexture(*ResourceMgr::instance()->GetTexture("MAINBGTEX"));
	spriteBackground.setPosition(0, 0);

	textMain.setFont(*ResourceMgr::instance()->GetFont("MAINFONT"));
	textMain.setString("Player select");
	textMain.setCharacterSize(100);
	textMain.setFillColor(Color::White);
	textMain.setPosition(450, 210);

	textPlayer1.setFont(*ResourceMgr::instance()->GetFont("MAINFONT"));
	textPlayer1.setString("1. One player");
	textPlayer1.setCharacterSize(90);
	textPlayer1.setFillColor(Color::Yellow);
	textPlayer1.setPosition(450, 400);

	textPlayer2.setFont(*ResourceMgr::instance()->GetFont("MAINFONT"));
	textPlayer2.setString("2. One player");
	textPlayer2.setCharacterSize(90);
	textPlayer2.setFillColor(Color::Cyan);
	textPlayer2.setPosition(450, 650);
}

void PlayerSelectScene::HanddleInput(sf::Event& event)
{

	switch (event.type)
	{
	case Event::KeyPressed:
		switch (event.key.code)
		{
		case Keyboard::Num1:
			sceneManager.ChangeScene(SceneType::CHARA);
			break;
		case Keyboard::Num2:
			sceneManager.ChangeScene(SceneType::CHARA);
			break;
		case Keyboard::Num3:
			sceneManager.ChangeScene(SceneType::CHARA);
			break;

		default:
			break;
		}
		break;
	}
}

void PlayerSelectScene::Update(float dt)
{
	if (Keyboard::isKeyPressed(Keyboard::Backspace))
	{
		sceneManager.ChangeScene(SceneType::LEVEL);
	}
}

void PlayerSelectScene::Render(sf::RenderWindow& window)
{
	window.clear();

	window.draw(spriteBackground);
	window.draw(textMain);
	window.draw(textPlayer1);
	window.draw(textPlayer2);

}

void PlayerSelectScene::Start()
{
	Init();
}

void PlayerSelectScene::End()
{
}

PlayerSelectScene::~PlayerSelectScene()
{
}
