#include "SetupScene.h"
#include "../Manager/ResourceMgr.h"
#include "../Manager/SoundManager.h"
#include <sstream>

using namespace std;
using namespace sf;


SetupScene::SetupScene(SceneManager& sceneManager) :Scene(sceneManager)
{

}

void SetupScene::Init()
{
	font.loadFromFile("fonts/KOMIKAP_.ttf");

	spriteBackground.setTexture(*ResourceMgr::instance()->GetTexture("MAINBGTEX"));
	spriteBackground.setPosition(0, 0);

	textMain.setFont(font);
	textMain.setString("SET UP");
	textMain.setCharacterSize(100);
	textMain.setFillColor(Color::Cyan);
	textMain.setPosition(450, 210);

	textOp1.setFont(font);
	textOp1.setString("1. Sound On");
	textOp1.setCharacterSize(90);
	textOp1.setFillColor(Color::White);
	textOp1.setPosition(450, 400);

	textOp2.setFont(font);
	textOp2.setString("2. Sound Off");
	textOp2.setCharacterSize(90);
	textOp2.setFillColor(Color::White);
	textOp2.setPosition(450, 650);

	
}

void SetupScene::HanddleInput(sf::Event& event)
{
	
	sf::Time delayTime = sf::milliseconds(0.5);
	sf::Clock clock;
	
	FloatRect textRect = textOn.getLocalBounds();

	switch (event.type)
	{
	case Event::KeyPressed:

		switch (event.key.code)
		{
		case Keyboard::Num1:
			textOn.setFont(font);
			textOn.setString("Turn On the Sound");
			textOn.setCharacterSize(150);
			textOn.setOrigin(
				textRect.left + textRect.width * 0.5f,
				textRect.top + textRect.height * 0.5f
			);
			sf::sleep(delayTime);
			break;
		case Keyboard::Num2:
			// stop playback and rewind
			//sound.stop();
			sf::Sound sound;
			sound.stop();

			textOff.setFont(font);
			textOff.setString("Turn Off the Sound");
			textOff.setCharacterSize(150);
			textOff.setOrigin(
				textRect.left + textRect.width * 0.5f,
				textRect.top + textRect.height * 0.5f
			);
			sf::sleep(delayTime);
			break;

		
		}

		break;
	}
	if (Keyboard::isKeyPressed(Keyboard::Backspace))
	{
		sceneManager.ChangeScene(SceneType::MENU);
	}
}

void SetupScene::Update(float dt)
{
}

void SetupScene::Render(sf::RenderWindow& window)
{
	window.clear();

	window.draw(spriteBackground);
	window.draw(textMain);
	window.draw(textOp1);
	window.draw(textOp2);
	
	window.draw(textOn);
	window.draw(textOff);
}

void SetupScene::Start()
{
	Init();
}

void SetupScene::End()
{
}

SetupScene::~SetupScene()
{
}
