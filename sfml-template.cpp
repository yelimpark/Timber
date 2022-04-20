#include <SFML/Graphics.hpp>
#include <random>
#include <sstream>
#include <SFML/Audio.hpp>

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
    textMessage.setString("Press Enter to start!");
    textMessage.setFillColor(Color::White);
    textMessage.setCharacterSize(75);

    FloatRect textRect = textMessage.getLocalBounds();
    textMessage.setOrigin(
        textRect.left + textRect.width * 0.5f,
        textRect.top + textRect.height * 0.5f
    );
    textMessage.setPosition(1920 * 0.5f, 1080 * 0.5f);

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

    // Prepare the gravestone
    Texture textureRIP;
    textureRIP.loadFromFile("graphics/rip.png");
    Sprite spriteRIP;
    spriteRIP.setTexture(textureRIP);
    spriteRIP.setPosition(600, 860);

    // Prepare the axe
    Texture textureAxe;
    textureAxe.loadFromFile("graphics/axe.png");
    Sprite spriteAxe;
    spriteAxe.setTexture(textureAxe);
    spriteAxe.setPosition(700, 830);

    // Prepare the flying log
    Texture textureLog;
    textureLog.loadFromFile("graphics/log.png");
    Sprite spriteLog;
    spriteLog.setTexture(textureLog);
    spriteLog.setPosition(810, 720);

    SoundBuffer chopBuffer;
    chopBuffer.loadFromFile("sound/chop.wav");
    Sound chop;
    chop.setBuffer(chopBuffer);

    SoundBuffer deathBuffer;
    deathBuffer.loadFromFile("sound/death.wav");
    Sound death;
    death.setBuffer(deathBuffer);

    SoundBuffer ootBuffer;
    ootBuffer.loadFromFile("sound/out_of_time.wav");
    Sound oot;
    oot.setBuffer(ootBuffer);

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

    Clock clock;
    const float timeMax = 6.0f;
    float timeRemaining = timeMax;
    float timerBarWidthPerSecond = timeBarWidth / timeMax;
    bool logActive = false;
    bool acceptInput = false;
    bool beeActive = false;
    bool isPause = true;

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
                    isPause = false;

                    score = 0;
                    timeRemaining = timeMax;
                    acceptInput = true;

                    for (int i = 0; i < countBranches; ++i)
                    {
                        sideBranches[i] = side::NONE;
                    }
                    spriteRIP.setPosition(675, 2000);
                    spritePlayer.setPosition(580, 720);
                }
                break;
                case Keyboard::Left:
                    if (acceptInput && !isPause)
                    {
                        chop.play();
                        playerSide = side::LEFT;
                        ++score;
                        timeRemaining += (2 / score) + 0.15f; // 스코어가 커지면 커질수록 시간을 작게 주려고
                        if (timeRemaining > timeMax)
                        {
                            timeRemaining = timeMax;
                        }
                        spriteAxe.setPosition(AXE_POSITION_LEFT, spriteAxe.getPosition().y);
                        spritePlayer.setPosition(580, 720);

                        UpdateBranches(sideBranches, countBranches, gen);
                        spriteLog.setPosition(810, 720);
                        logSpeedX = 5000;
                        logActive = true;
                        acceptInput = false;
                    }
                    break;
                case Keyboard::Right:
                    if (acceptInput && !isPause)
                    {
                        chop.play();
                        playerSide = side::RIGHT;
                        ++score;
                        timeRemaining += (2 / score) + 0.15f; // 스코어가 커지면 커질수록 시간을 작게 주려고
                        if (timeRemaining > timeMax)
                        {
                            timeRemaining = timeMax;
                        }
                        spriteAxe.setPosition(AXE_POSITION_RIGHT, spriteAxe.getPosition().y);
                        spritePlayer.setPosition(1200, 720);

                        UpdateBranches(sideBranches, countBranches, gen);
                        spriteLog.setPosition(810, 720);
                        logSpeedX = -5000;
                        logActive = true;
                        acceptInput = false;
                    }
                    break;
                default:
                    break;
                }
                break;
            case Event::KeyReleased:
                if (event.key.code == Keyboard::Left || event.key.code == Keyboard::Right)
                {
                    if (!isPause)
                    {
                        acceptInput = true;
                        spriteAxe.setPosition(2000, spriteAxe.getPosition().y);
                    }
                }
                break;
            default:
                break;
            }
        }


        //업데이트

        if (!isPause)
        {
            if (!beeActive) //벌그리기
            {
                //벌 초기화
                beeSpeed = gen() % 200 + 200;
                beeSpeed *= -1.f;
                float y = gen() % 500 + 500;
                spriteBee.setPosition(2000, y);
                beeActive = true;
            }
            else
            {
                //벌이동, 화면밖으로 나갔는지 테스트
                float deltaX = beeSpeed * dt.asSeconds();
                Vector2f currPos = spriteBee.getPosition();
                currPos.x += deltaX;
                spriteBee.setPosition(currPos);

                if (currPos.x < -100)
                {
                    beeActive = false;
                }

            }
            if (!cloud1Active)
            {
                cloud1Speed = gen() % 200 + 10;
                cloud1Speed *= -1.f;
                float y = gen() % 1 + 10;
                spriteCloud1.setPosition(2000, y);
                cloud1Active = true;
            }
            else
            {
                float deltaX = cloud1Speed * dt.asSeconds();
                Vector2f currPos = spriteCloud1.getPosition();
                currPos.x += deltaX;
                spriteCloud1.setPosition(currPos);

                if (currPos.x < -500)
                {
                    cloud1Active = false;
                }
            }
            if (!cloud2Active)
            {
                cloud2Speed = gen() % 200 + 30;
                float y = gen() % 150 + 50;
                spriteCloud2.setPosition(-500, y);
                cloud2Active = true;
            }
            else
            {
                float deltaX = cloud2Speed * dt.asSeconds();
                Vector2f currPos = spriteCloud2.getPosition();
                currPos.x += deltaX;
                spriteCloud2.setPosition(currPos);

                if (currPos.x > 1980)
                {
                    cloud2Active = false;
                }
            }
            if (!cloud3Active)
            {
                cloud3Speed = gen() % 200 + 10;
                cloud3Speed *= -1.f;
                float y = gen() % 300 + 50;
                spriteCloud3.setPosition(2000, y);
                cloud3Active = true;
            }
            else
            {
                float deltaX = cloud3Speed * dt.asSeconds();
                Vector2f currPos = spriteCloud3.getPosition();
                currPos.x += deltaX;
                spriteCloud3.setPosition(currPos);

                if (currPos.x < -500)
                {
                    cloud3Active = false;
                }
            }

            for (int i = 0; i < countBranches; i++)
            {
                float height = 150 * i;
                switch (sideBranches[i])
                {
                case side::LEFT:
                    spriteBranches[i].setPosition(610, height);
                    spriteBranches[i].setRotation(180);
                    break;
                case side::RIGHT:
                    spriteBranches[i].setPosition(1330, height);
                    spriteBranches[i].setRotation(0);
                    break;
                default:
                    spriteBranches[i].setPosition(-2000, -2000);
                    break;
                }
            }

            stringstream ss;
            ss << "Score = " << score;
            textScore.setString(ss.str());

            timeRemaining -= dt.asSeconds();
            timerBarSize.x = timeRemaining * timerBarWidthPerSecond;
            timerBar.setSize(timerBarSize);

            if (timeRemaining < 0.f)
            {
                timerBarSize.x = 0.f;
                timerBar.setSize(timerBarSize);

                isPause = true;
                textMessage.setString("Out Of Time!!");
                FloatRect textRect = textMessage.getLocalBounds();
                textMessage.setOrigin(
                    textRect.left + textRect.width * 0.5f,
                    textRect.top + textRect.height * 0.5f
                );
                oot.play();
            }

            if (logActive)
            {
                Vector2f logPos = spriteLog.getPosition();
                logPos.x += logSpeedX * dt.asSeconds();
                logPos.y += logSpeedY * dt.asSeconds();
                spriteLog.setPosition(logPos);

                if (logPos.x < -100 || logPos.x > 2000)
                {
                    logActive = false;
                    spriteLog.setPosition(810, 720);
                }
            }

            if (sideBranches[countBranches - 1] == playerSide)
            {
                isPause = true;
                acceptInput = false;
                spritePlayer.setPosition(2000, 660);
                spriteRIP.setPosition(525, 700);

                textMessage.setString("SQUISHED!");
                FloatRect textRect = textMessage.getLocalBounds();
                textMessage.setOrigin(
                    textRect.left + textRect.width * 0.5f,
                    textRect.top + textRect.height * 0.5f);

                death.play();
            }

        }


        //그리기

        window.clear();
        window.draw(spriteBackground);
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);
        window.draw(spriteTree);
        window.draw(spriteLog);
        for (int i = 0; i < countBranches; i++)
        {
            window.draw(spriteBranches[i]);
        }
        //ui는 나중에찍어주새
        window.draw(spritePlayer);
        window.draw(spriteAxe);
        window.draw(spriteRIP);
        window.draw(spriteBee);


        window.draw(textScore);
        if (isPause)
        {
            window.draw(textMessage);
        }
        window.draw(timerBar);
        window.display();


    }

    return 0;
}