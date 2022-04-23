#include "CharaSelectScene.h"
#include "../Manager/ResourceMgr.h"
#include <sstream>

using namespace std;

CharaSelectScene::CharaSelectScene(SceneManager& sceneManager)
	:Scene(sceneManager)
{
}

bool CharaSelectScene::Init()
{
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
	
	chooseChar.Init(1920, 1080);

	return true;
}

void CharaSelectScene::HanddleInput(sf::Event& event)
{
    switch (event.type)
    {
    case Event::KeyPressed:
        switch (event.key.code)
        {
        case Keyboard::Return:
            sceneManager.GetGameVariables().selectedCharaIndex = chooseChar.GetPressedItem();
            sceneManager.ChangeScene(SceneType::LEVEL);
            break;
        case Keyboard::Left:
            chooseChar.MoveLeft();
            break;

        case Keyboard::Right:
            chooseChar.MoveRight();
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

void CharaSelectScene::render(sf::RenderWindow* window)
{
    window->draw(spriteBackground);

    chooseChar.draw(*window);

    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
        window->draw(spritePlayers[i]);
    }
}

void CharaSelectScene::Start()
{
}

void CharaSelectScene::End()
{
}

CharaSelectScene::~CharaSelectScene()
{
}
