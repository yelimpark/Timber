#include "MenuScene.h"
#include "SetupScene.h"
#include "../Manager/ResourceMgr.h"
#include <sstream>

using namespace std;

MenuScene::MenuScene(SceneManager& sceneManager) :Scene(sceneManager)
{
}

void MenuScene::Init()
{
    spriteBackground.setTexture(*ResourceMgr::instance()->GetTexture("MAINBGTEX"));
    spriteBackground.setPosition(0, 0);

    textMain.setFont(*ResourceMgr::instance()->GetFont("MAINFONT"));
    textMain.setString("TIMBERMAN GAME");
    textMain.setCharacterSize(110);
    textMain.setFillColor(Color::Cyan);
    textMain.setPosition(450, 210);

    textMenu.setFont(*ResourceMgr::instance()->GetFont("MAINFONT"));
    textMenu.setString("Menu");
    textMenu.setCharacterSize(80);
    textMenu.setFillColor(Color::Cyan);
    textMenu.setPosition(480, 350);

    textOp1.setFont(*ResourceMgr::instance()->GetFont("MAINFONT"));
    textOp1.setString("1. Setup");
    textOp1.setCharacterSize(60);
    textOp1.setFillColor(Color::White);
    textOp1.setPosition(480, 550);

    textOp2.setFont(*ResourceMgr::instance()->GetFont("MAINFONT"));
    textOp2.setString("2. Game Start");
    textOp2.setCharacterSize(60);
    textOp2.setFillColor(Color::White);
    textOp2.setPosition(480, 700);

    textGuide.setFont(*ResourceMgr::instance()->GetFont("MAINFONT"));
    textGuide.setString("Selectand press the right arrow key");
    textGuide.setCharacterSize(25);
    textGuide.setFillColor(Color::Cyan);
    textGuide.setPosition(480, 790);


}

void MenuScene::HanddleInput(sf::Event& event)
{

 

    switch (event.type)
    {
    case Event::KeyPressed:
        switch (event.key.code)
        {
        case Keyboard::Num1:   
            sceneManager.ChangeScene(SceneType::SETUP);
            break;
        case Keyboard::Num2:
            sceneManager.ChangeScene(SceneType::LEVEL);
            break;
    
        default:
            break;
        }
        break;
    }

  
}

void MenuScene::Update(float dt)
{
}

void MenuScene::Render(sf::RenderWindow& window)
{

    window.clear();

    window.draw(spriteBackground);

    window.draw(textMain);
    window.draw(textMenu);
    window.draw(textOp1);
    window.draw(textOp2);
    window.draw(textGuide);


}

void MenuScene::Start()
{
    Init();
}

void MenuScene::End()
{
}

MenuScene::~MenuScene()
{
}
