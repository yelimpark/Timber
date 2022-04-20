#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <sstream>
#include <SFML/Audio.hpp>
#include "charSelect.h"

using namespace sf;
using namespace std;

enum class side
{
    LEFT,
    RIGHT,
    NONE
};

void UpdateBranches(side sides[], int length, mt19937& gen)
{
    for (int i = length - 1; i >= 0; --i)
    {
        sides[i] = sides[i - 1];
    }
    int rnd = gen() % 5;
    switch (rnd)
    {
    case 0:
        sides[0] = side::LEFT;
        break;
    case 1:
        sides[0] = side::RIGHT;
        break;
    default:
        sides[0] = side::NONE;
        break;
    }
}

int main()
{
    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());  // to seed mersenne twister.
    Font fontKOMIKAP;
    fontKOMIKAP.loadFromFile("fonts/KOMIKAP_.ttf");

    VideoMode vm(1920, 1080); //해상도 정보
    RenderWindow window(vm, "Timber!", Style::Default); //Fullscreen 해서 풀스크린 할 수 있는데 개발할 때는 창모드가 편하다

    Text textMessage;
    textMessage.setFont(fontKOMIKAP);
    textMessage.setString("Choose your Character!");
    textMessage.setFillColor(Color::White);
    textMessage.setCharacterSize(105);

    FloatRect textRect = textMessage.getLocalBounds();
    textMessage.setOrigin(
        textRect.left + textRect.width * 0.5f,
        textRect.top + textRect.height * 0.5f
    );
    textMessage.setPosition(1920 * 0.5f, 200);

    Text textScore;
    textScore.setFont(fontKOMIKAP);
    textScore.setString("Score = 0");
    textScore.setFillColor(Color::White);
    textScore.setCharacterSize(100);
    textScore.setPosition(20, 20);
    // Some other useful log related variables
    Texture textureBackground;
    textureBackground.loadFromFile("graphics/background.png");

    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);

    Texture textureCloud;
    textureCloud.loadFromFile("graphics/cloud.png");
    Sprite spriteCloud1;
    Sprite spriteCloud2;
    Sprite spriteCloud3;
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);
    spriteCloud1.setPosition(0, 0);
    spriteCloud2.setPosition(0, 150);
    spriteCloud3.setPosition(0, 300);

    Texture textureBee;
    textureBee.loadFromFile("graphics/bee.png");
    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0, 800);

    Texture textureTree;
    textureTree.loadFromFile("graphics/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    Texture textureBranch;
    textureBranch.loadFromFile("graphics/branch.png");
    Sprite spriteBranch;

    Texture texturePlayer;
    texturePlayer.loadFromFile("graphics/player.png");
    Sprite spritePlayer;
    spritePlayer.setTexture(texturePlayer);
    spritePlayer.setPosition(580, 720);
    // The player starts on the left
    side playerSide = side::LEFT;


    charSelect chooseChar(window.getSize().x, window.getSize().y);

    float logSpeedX = 1000;
    float logSpeedY = -1500;

    const float AXE_POSITION_LEFT = 700;
    const float AXE_POSITION_RIGHT = 1075;

    float beeSpeed = 0.f;

    bool cloud1Active = false;
    float cloud1Speed = 0.f;
    bool cloud2Active = false;
    float cloud2Speed = 0.f;
    bool cloud3Active = false;
    float cloud3Speed = 0.f;

    const int countBranches = 6;
    Sprite spriteBranches[countBranches];
    side sideBranches[countBranches];

    for (int i = 0; i < countBranches; i++)
    {
        spriteBranches[i].setTexture(textureBranch);
        spriteBranches[i].setPosition(-2000, -2000);
        spriteBranches[i].setOrigin(220, 40);

        sideBranches[i] = side::NONE;
    }

    RectangleShape timerBar;
    float timeBarWidth = 400;
    float timerBarHeight = 80;
    Vector2f timerBarSize = Vector2f(timeBarWidth, timerBarHeight);
    timerBar.setSize(timerBarSize);
    Vector2f timerPos = Vector2f(1920 * 0.5f - timeBarWidth * 0.5f, 980.f);
    timerBar.setPosition(timerPos);
    timerBar.setFillColor(Color::Red);


    Sprite spritePlayer1;
    spritePlayer1.setTexture(texturePlayer);
    FloatRect characterRect1 = spritePlayer1.getLocalBounds();
    spritePlayer1.setOrigin(
        characterRect1.left + characterRect1.width * 0.5f,
        characterRect1.top + characterRect1.height * 0.5f
    );
    spritePlayer1.setPosition(Vector2f(1920 * 0.5f - 250, 1080 * 0.5f));

    Texture texturePlayer2;
    texturePlayer2.loadFromFile("graphics/player2.png");
    Sprite spritePlayer2;
    spritePlayer2.setTexture(texturePlayer2);
    FloatRect characterRect2 = spritePlayer2.getLocalBounds();
    spritePlayer2.setOrigin(
        characterRect2.left + characterRect2.width * 0.5f,
        characterRect2.top + characterRect2.height * 0.5f
    );
    spritePlayer2.setPosition(Vector2f(1920 * 0.5f, 1080 * 0.5f));

    Texture texturePlayer3;
    texturePlayer3.loadFromFile("graphics/player3.png");
    Sprite spritePlayer3;
    spritePlayer3.setTexture(texturePlayer3);
    FloatRect characterRect3 = spritePlayer3.getLocalBounds();
    spritePlayer3.setOrigin(
        characterRect3.left + characterRect3.width * 0.5f,
        characterRect3.top + characterRect3.height * 0.5f
    );
    spritePlayer3.setPosition(Vector2f(1920 * 0.5f + 250, 1080 * 0.5f));

    Clock clock;
    const float timeMax = 6.0f;
    float timeRemaining = timeMax;
    float timerBarWidthPerSecond = timeBarWidth / timeMax;
    bool logActive = false;
    bool acceptInput = false;
    bool beeActive = false;
    bool isPause = true;
    bool isSelect = false;

    int score = 0;
    //입력처리
    while (window.isOpen())
    {
        Time dt = clock.restart();
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                switch (event.key.code)
                {
                case Keyboard::Escape:
                    window.close();
                    break;
                case Keyboard::Return:
                {
                    switch (chooseChar.GetPressedItem())
                    {
                    case 0:
                        std::cout << "Character 1 has been chosen." << std::endl;
                        break;
                    case 1:
                        std::cout << "Character 2 has been chosen." << std::endl;
                        break;
                    case 2:
                        std::cout << "Character 3 has been chosen." << std::endl;
                        break;
                    }
                }
                break;
                case Keyboard::Left:
                    chooseChar.MoveLeft();
                    break;

                case Keyboard::Right:
                    chooseChar.MoveRight();
                    break;

                }
            }
        }


        //업데이트



        //그리기

        window.clear();
        window.draw(spriteBackground);

        //ui는 나중에찍어주새
        chooseChar.draw(window);
        window.draw(spritePlayer1);
        window.draw(spritePlayer2);
        window.draw(spritePlayer3);
        window.draw(textMessage);
        window.display();


    }

    return 0;
}