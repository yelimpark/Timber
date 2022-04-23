#include "LevelScene.h"
#include "Manager/ResourceMgr.h"
#include "Manager/SceneManager.h"
#include <sstream>

using namespace std;

LevelScene::LevelScene(SceneManager& sceneManager) :Scene(sceneManager)
{
}

bool LevelScene::Init()
{
	spriteBackground.setTexture(*ResourceMgr::instance()->GetTexture("MAINBGTEX"));
	spriteBackground.setPosition(0, 0);

	
	textLevel1.setString("Easy Level");
	textLevel1.setCharacterSize(100);
	textLevel1.setFillColor(Color::Green);
	textLevel1.setPosition(500, 290);

	textLevel2.setString("Midium Level");
	textLevel2.setCharacterSize(100);
	textLevel2.setFillColor(Color::Yellow);
	textLevel2.setPosition(500, 490);

	textLevel3.setString("Easy Level");
	textLevel3.setCharacterSize(100);
	textLevel3.setFillColor(Color::Red);
	textLevel3.setPosition(500, 690);

	CircleShape triangle(30, 3);
	triangle.setPosition(450, 500);
	triangle.setFillColor(Color::White);
	triangle.setRotation(90.f);

	//CircleShape triangle;

	return true;
}

void LevelScene::HanddleInput(sf::Event& event)
{
	Vector2f ttriPos[] = {
	Vector2f(450, 320),
	Vector2f(450, 520),
	Vector2f(450, 720),
	};

    switch (event.type)
    {
        /*   case Event::Closed:
               window.close();
               break;*/
    case Event::KeyPressed:
        switch (event.key.code)
        {
        case Keyboard::Up:  
            menuselected--;
            if (menuselected >= 3)
                menuselected = 2;
            break;
        case Keyboard::Down:
            menuselected++;
            if (menuselected < 0)
                menuselected = 0;
            break;
        case Keyboard::Right:
         
            if (menuselected == 0)
            {
                sceneManager.ChangeScene(SceneType::PLAYER);
            }
            else if (menuselected == 1)
            {
                sceneManager.ChangeScene(SceneType::PLAYER);
            }
            else if (menuselected == 2)
            {
                sceneManager.ChangeScene(SceneType::PLAYER);
            }
           
          
   /* ********************************************************************
        정보들을 다음 스텝으로 넘어갈때 가져가야하는데 어떻게..?
    *********************************************************************/

            break;
        default:
            break;
        }
        break;
    }

    triangle.setPosition(ttriPos[menuselected]);
}

void LevelScene::Update(float dt)
{
}

void LevelScene::render(sf::RenderWindow* window)
{
    window->draw(spriteBackground);
    window->draw(textLevel1);
    window->draw(textLevel2);
    window->draw(textLevel3);
    window->draw(triangle);
}

void LevelScene::Start()
{
}

void LevelScene::End()
{
}

LevelScene::~LevelScene()
{
}
