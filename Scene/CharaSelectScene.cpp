#include "CharaSelectScene.h"
#include "../Manager/ResourceMgr.h"
#include <sstream>

using namespace std;

CharaSelectScene::CharaSelectScene(SceneManager& sceneManager)
    :Scene(sceneManager), selectPointerCount(0)
{
}

void CharaSelectScene::Init()
{    
    textMain.setFont(*ResourceMgr::instance()->GetFont("MAINFONT"));
    textMain.setString("Character select");
    textMain.setCharacterSize(100);
    textMain.setFillColor(Color::White);
    textMain.setPosition(450, 210);

    selectPointers[0].Init(1920, 1080, Color::Yellow);

    if (GameVariables::Mode == GAME_MOD::MULTI) {
        selectPointers[1].Init(1920, 1080, Color::Magenta);
    }
  
	spriteBackground.setTexture(*ResourceMgr::instance()->GetTexture("MAINBGTEX"));
	spriteBackground.setPosition(0, 0);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		stringstream ss;
		ss << "MAINPLAYERTEX" << i+1;
		spritePlayers[i].setTexture(*ResourceMgr::instance()->GetTexture(ss.str()));

        FloatRect characterRect = spritePlayers[i].getLocalBounds();
        spritePlayers[i].setOrigin(
            characterRect.left + characterRect.width * 0.5f,
            characterRect.top + characterRect.height * 0.5f
        );
        spritePlayers[i].setPosition(Vector2f(1920 * 0.5f + 250 * (i - 1) , 1080 * 0.5f));
	}	
}

void CharaSelectScene::HanddleInput(sf::Event& event)
{
    switch (event.type)
    {
    case Event::KeyPressed:
        switch (event.key.code)
        {
        case Keyboard::Return:
            GameVariables::selectedCharaIndex1p = selectPointers[0].GetPressedItem();
            GameVariables::selectedCharaIndex2p = selectPointers[1].GetPressedItem();
            sceneManager.ChangeScene(SceneType::STAGE);
            break;

        case Keyboard::Left:
            selectPointers[0].MoveLeft();
            break;

        case Keyboard::Right:
            selectPointers[0].MoveRight();
            break;

        case Keyboard::A:
            selectPointers[1].MoveLeft();
            break;

        case Keyboard::D:
            selectPointers[1].MoveRight();
            break;
        }
        break;
    default:
        break;
    }
}

void CharaSelectScene::Update(float dt)
{
}

void CharaSelectScene::Render(sf::RenderWindow& window)
{
    window.draw(spriteBackground);

    if (GameVariables::Mode == GAME_MOD::MULTI) {
        selectPointers[1].draw(window);
    }

    selectPointers[0].draw(window);

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
        window.draw(spritePlayers[i]);
    }
    window.draw(textMain);
}

void CharaSelectScene::Start()
{
    Init();
}

void CharaSelectScene::End()
{

}

CharaSelectScene::~CharaSelectScene()
{
}
