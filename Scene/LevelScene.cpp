#include "LevelScene.h"
#include "../Manager/ResourceMgr.h"
#include "../GameObject/TimeBar.h"
#include <sstream>



LevelScene::LevelScene(SceneManager& sceneManager) :Scene(sceneManager)
{
}

void LevelScene::Init()
{
	spriteBackground.setTexture(*ResourceMgr::instance()->GetTexture("MAINBGTEX"));
	spriteBackground.setPosition(0, 0);

	textMain.setFont(*ResourceMgr::instance()->GetFont("MAINFONT"));
	textMain.setString("Level select");
	textMain.setCharacterSize(100);
	textMain.setFillColor(Color::White);
	textMain.setPosition(450, 210);

	textLevel1.setFont(*ResourceMgr::instance()->GetFont("MAINFONT"));
	textLevel1.setString("1. EASY level");
	textLevel1.setCharacterSize(80);
	textLevel1.setFillColor(Color::Green);
	textLevel1.setPosition(450, 350);

	textLevel2.setFont(*ResourceMgr::instance()->GetFont("MAINFONT"));
	textLevel2.setString("2. MEDIUM level");
	textLevel2.setCharacterSize(80);
	textLevel2.setFillColor(Color::Yellow);
	textLevel2.setPosition(450, 520);

	textLevel3.setFont(*ResourceMgr::instance()->GetFont("MAINFONT"));
	textLevel3.setString("3. HARD level");
	textLevel3.setCharacterSize(80);
	textLevel3.setFillColor(Color::Red);
	textLevel3.setPosition(450, 690);

}

void LevelScene::HanddleInput(sf::Event& event)
{
	switch (event.type)
	{
	case Event::KeyPressed:
		switch (event.key.code)
		{
		case Keyboard::Num1:
			timebar.Update(0.5f);
			sceneManager.ChangeScene(SceneType::CHARA);
			
			break;
		case Keyboard::Num2:
			
			sceneManager.ChangeScene(SceneType::CHARA);
			break;
		case Keyboard::Num3:
			timebar.Update(5.f);
			sceneManager.ChangeScene(SceneType::CHARA);
			break;

		default:
			break;
		}
		break;
	}
	if (Keyboard::isKeyPressed(Keyboard::Backspace))
	{
		sceneManager.ChangeScene(SceneType::MENU);
	}
}

void LevelScene::Update(float dt)
{
}

void LevelScene::Render(sf::RenderWindow& window)
{
	window.clear();

	window.draw(spriteBackground);

	window.draw(textMain);
	window.draw(textLevel1);
	window.draw(textLevel2);
	window.draw(textLevel3);
}

void LevelScene::Start()
{
	Init();
}

void LevelScene::End()
{
}

LevelScene::~LevelScene()
{
}
