#include "PlayerSelectScene.h"
#include "Scene/Scene.h"
#include "Manager/ResourceMgr.h"
#include "Manager/SceneManager.h"
#include <sstream>

PlayerSelectScene::PlayerSelectScene(SceneManager& sceneManager) :Scene(sceneManager)
{
}

bool PlayerSelectScene::Init()
{
	spriteBackground.setTexture(*ResourceMgr::instance()->GetTexture("MAINBGTEX"));
	spriteBackground.setPosition(0, 0);

	textPlayer1.setString("One Player");
	textPlayer1.setCharacterSize(110);
	textPlayer1.setFillColor(Color::Blue);
	textPlayer1.setPosition(480, 600);

	textPlayer1.setString("Two Player");
	textPlayer1.setCharacterSize(110);
	textPlayer1.setFillColor(Color::Cyan);
	textPlayer1.setPosition(480, 880);

	CircleShape triangle(30, 3);
	triangle.setPosition(450, 500);
	triangle.setFillColor(Color::White);
	triangle.setRotation(90.f);

	return true;
}

void PlayerSelectScene::HanddleInput(sf::Event& event)
{
	Vector2f triPos[] = {
		Vector2f(450, 500),
		Vector2f(450, 600),
	};

    switch (event.type)
    {
  
    case Event::KeyPressed:
        switch (event.key.code)
        {
        case Keyboard::Up:   
            menuselected--;
            if (menuselected >= 2) 
                menuselected = 1;
            break;
        case Keyboard::Down:
            menuselected++;
            if (menuselected < 0)
                menuselected = 0;
            break;
        case Keyboard::Right:

            if (menuselected == 0)
            {
                sceneManager.ChangeScene(SceneType::CHARA);
            }
            else if (menuselected == 1)
            {
                sceneManager.ChangeScene(SceneType::CHARA);
            }

            break;
        default:
            break;
        }
        break;
    }

    triangle.setPosition(triPos[menuselected]);
}

void PlayerSelectScene::Update(float dt)
{
}

void PlayerSelectScene::render(sf::RenderWindow* window)
{
    window->draw(spriteBackground);
    window->draw(textPlayer1);
    window->draw(textPlayer2);
    window->draw(triangle);
}

void PlayerSelectScene::Start()
{
}

void PlayerSelectScene::End()
{
}

PlayerSelectScene::~PlayerSelectScene()
{
}
