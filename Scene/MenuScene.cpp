#include "MenuScene.h"
#include "Scene/MenuScene.h"
#include "Scene/Scene.h"
#include "Manager/ResourceMgr.h"
#include "Manager/SceneManager.h"
#include <sstream>

using namespace std;


MenuScene::MenuScene(SceneManager& sceneManager) :Scene(sceneManager)
{

}

bool MenuScene::Init()
{
    spriteBackground.setTexture(*ResourceMgr::instance()->GetTexture("MAINBGTEX"));
    spriteBackground.setPosition(0, 0);

    textMain.setString("TIMBERMAN GAME");
    textMain.setCharacterSize(110);
    textMain.setFillColor(Color::Blue);
    textMain.setPosition(20, 20);

    textMenu.setString("Menu");
    textMenu.setCharacterSize(110);
    textMenu.setFillColor(Color::Blue);
    textMenu.setPosition(20, 20);

    textOp1.setString("1. Setup");
    textOp1.setCharacterSize(110);
    textOp1.setFillColor(Color::Blue);
    textOp1.setPosition(20, 20);

    textOp2.setString("1. Game Start");
    textOp2.setCharacterSize(110);
    textOp2.setFillColor(Color::Blue);
    textOp2.setPosition(20, 20);

    textGuide.setString("Selectand press the right arrow key");
    textGuide.setCharacterSize(110);
    textGuide.setFillColor(Color::Blue);
    textGuide.setPosition(20, 20);


    CircleShape triangle(30, 3);
    triangle.setPosition(450, 500);
    triangle.setFillColor(Color::White);
    triangle.setRotation(90.f);



    return false;
}

void MenuScene::HanddleInput(sf::Event& event)
{

    Vector2f triPos[] = {
        Vector2f(450, 500),
        Vector2f(450, 600),
    };

    switch (event.type)
    {
        /*   case Event::Closed:
               window.close();
               break;*/
    case Event::KeyPressed:
        switch (event.key.code)
        {
        case Keyboard::Up:   // ȭ��ǥ �̵�
            menuselected--;
            if (menuselected >= 2) //Ű �ִ밪(�޴� ��4��)
                menuselected = 1;
            break;
        case Keyboard::Down:
            menuselected++;
            if (menuselected < 0)
                menuselected = 0;
            break;
        case Keyboard::Right:
            /*sceneManager.ChangeScene = (SceneType)(menuselected + 1);*/

            if (menuselected == 0)
            {
                sceneManager.ChangeScene(SceneType::SETUP);
            }
            else if (menuselected == 1)
            {
                sceneManager.ChangeScene(SceneType::GAMESTART);
            }

            break;
        default:
            break;
        }
        break;
    }

    triangle.setPosition(triPos[menuselected]);



}

void MenuScene::Update(float dt)
{
}

void MenuScene::render(sf::RenderWindow* window)
{
    window->draw(spriteBackground);
    window->draw(textMain);
    window->draw(textMenu);
    window->draw(textOp1);
    window->draw(textGuide);
    window->draw(triangle);
}

void MenuScene::Start()
{
}

void MenuScene::End()
{
}

MenuScene::~MenuScene()
{
}