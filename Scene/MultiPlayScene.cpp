#include"MultiPlayScene.h"
#include <sstream>
#include"../Manager/ResourceMgr.h"\

using namespace sf;
using namespace std;

MultiPlayScene::MultiPlayScene(SceneManager& sceneManager)
	:Scene(sceneManager)
{

}

bool MultiPlayScene::Init()
{
    random_device rd;
    mt19937 gen(rd());

    player1.init(sceneManager.GetGameVariables().selectedCharaIndex);
    player2.init(sceneManager.GetGameVariables().selectedCharaIndex);

    for (int i = 0; i < clouds_size; i++)
    {
        clouds[i].init(*ResourceMgr::instance()->GetTexture("MAINCLOUDTEX"));
    }
    bee.init(*ResourceMgr::instance()->GetTexture("MAINBEETEX"));
    timeBar.init(6.0f);
    spriteBackground.setTexture(*ResourceMgr::instance()->GetTexture("MAINBGTEX"));
    spriteBackground.setPosition(0, 0);

    chop.setBuffer(*ResourceMgr::instance()->GetSoundBuffer("CHOPSOUND"));
    death.setBuffer(*ResourceMgr::instance()->GetSoundBuffer("DEATHSOUND"));
    oot.setBuffer(*ResourceMgr::instance()->GetSoundBuffer("OOTSOUND"));

    textMessage.setFont(*ResourceMgr::instance()->GetFont("MAINFONT"));
    textMessage.setString("Press Enter to start!");
    textMessage.setFillColor(Color::White);
    textMessage.setCharacterSize(75);

    textRect = textMessage.getLocalBounds();
    textMessage.setOrigin(
        textRect.left + textRect.width * 0.5f,
        textRect.top + textRect.height * 0.5f
    );
    textMessage.setPosition(1920 * 0.5f, 1080 * 0.5f);

    textScore.setFont(*ResourceMgr::instance()->GetFont("MAINFONT"));
    textScore.setString("Score = 0");
    textScore.setFillColor(Color::White);
    textScore.setCharacterSize(100);
    textScore.setPosition(20, 20);

    flyingLog1P.init();
    flyingLog2P.init();

    for (int i = 0; i < countBranches; i++)
    {
        spriteBranches1P[i].setTexture(*ResourceMgr::instance()->GetTexture("MAINBRANCHTEX"));
        spriteBranches1P[i].setPosition(-2000, -2000);
        spriteBranches1P[i].setOrigin(220, 40);

        sideBranches1P[i] = sideMulti::NONE;
    }

    acceptInput1P = false;
    acceptInput2P = false;
    isPause = true;

    return true;
}

void MultiPlayScene::HanddleInput(sf::Event& event)
{
    switch (event.type)
    {
    case Event::KeyPressed:
        switch (event.key.code)
        {
        case Keyboard::Return:
        {
            isPause = false;

            score1P = 0;
            score2P = 0;
            timeBar.HanddleInput(event.key.code, score1P);
            acceptInput1P = true;
            acceptInput2P = true;

            for (int i = 0; i < countBranches; ++i)
            {
                sideBranches1P[i] = sideMulti::NONE;
            }
            for (int i = 0; i < countBranches; ++i)
            {
                sideBranches2P[i] = sideMulti::NONE;
            }
            player1.HanddleInput(event.key.code);
            player2.HanddleInput(event.key.code);
        }
        break;
        case Keyboard::A:  //1Player 哭率
        case Keyboard::D: //1Player 坷弗率
            if (acceptInput1P && !isPause)
            {
                chop.play();
                player1.HanddleInput(event.key.code);
                ++score1P;
                for (int i = countBranches - 1; i > 0; --i)
                {
                    sideBranches1P[i] = sideBranches1P[i - 1];
                }
                int rnd = gen() % 5;

                switch (rnd)
                {
                case 0:
                    sideBranches1P[0] = sideMulti::LEFT;
                    break;
                case 1:
                    sideBranches1P[0] = sideMulti::RIGHT;
                    break;
                default:
                    sideBranches1P[0] = sideMulti::NONE;
                    break;
                }
                acceptInput1P = false;
            }
            break;
        case Keyboard::Left: //2Player 哭率
        case Keyboard::Right: //2Player 坷弗率
            if (acceptInput2P && !isPause)
            {
                chop.play();
                player2.HanddleInput(event.key.code);
                ++score2P;
                for (int i = countBranches - 1; i > 0; --i)
                {
                    sideBranches2P[i] = sideBranches2P[i - 1];
                }
                int rnd = gen() % 5;

                switch (rnd)
                {
                case 0:
                    sideBranches2P[0] = sideMulti::LEFT;
                    break;
                case 1:
                    sideBranches2P[0] = sideMulti::RIGHT;
                    break;
                default:
                    sideBranches2P[0] = sideMulti::NONE;
                    break;
                }
                acceptInput2P = false;
            }
        default:
            break;
        }
        break;
    case Event::KeyReleased:
        if (event.key.code == Keyboard::Left || event.key.code == Keyboard::Right || event.key.code == Keyboard::A || event.key.code == Keyboard::D)
        {
            if (!isPause)
            {
                acceptInput1P = true;
                acceptInput2P = true;
                player1.AtKeyReleased();
                player2.AtKeyReleased();
            }
        }
        break;
    default:
        break;
    }
}

void MultiPlayScene::Update(float dt)
{
    if (!isPause)
    {

        bee.Update(dt, gen, 500);

        for (int i = 0; i < clouds_size; i++) {
            clouds[i].Update(dt, gen, 0);
        }

        timeBar.Update(dt);

        for (int i = 0; i < countBranches; i++)
        {
            float height = 150 * i;
            switch (sideBranches1P[i])
            {
            case sideMulti::LEFT:
                spriteBranches1P[i].setPosition(Vector2f(1920.f * 0.08f, height));
                spriteBranches1P[i].setRotation(180);
                break;
            case sideMulti::RIGHT:
                spriteBranches1P[i].setPosition(Vector2f(1920.f * 0.42f, height));
                spriteBranches1P[i].setRotation(0);
                break;
            default:
                spriteBranches1P[i].setPosition(-2000, -2000);
                break;
            }
        }

        for (int i = 0; i < countBranches; i++)
        {
            float height = 150 * i;
            switch (sideBranches2P[i])
            {
            case sideMulti::LEFT:
                spriteBranches2P[i].setPosition(Vector2f(1920.f * 0.58f, height));
                spriteBranches2P[i].setRotation(180);
                break;
            case sideMulti::RIGHT:
                spriteBranches2P[i].setPosition(Vector2f(1920.f * 0.92f, height));
                spriteBranches2P[i].setRotation(0);
                break;
            default:
                spriteBranches2P[i].setPosition(-2000, -2000);
                break;
            }
        }

        stringstream ss1;
        stringstream ss2;
        ss1 << "Score = " << score1P;
        ss1 << "Score = " << score2P;
        textScore.setString(ss1.str());
        textScore.setString(ss2.str());

        if (timeBar.IsEnd())
        {
            isPause = true;
            textMessage.setString("Out Of Time!!");
            FloatRect textRect = textMessage.getLocalBounds();
            textMessage.setOrigin(
                textRect.left + textRect.width * 0.5f,
                textRect.top + textRect.height * 0.5f
            );
            oot.play();
        }

        flyingLog1P.Update(dt);
        flyingLog2P.Update(dt);

        if (sideBranches1P[countBranches - 1] == player1.getSide()&&isDead1P)
        {
            isPause = true;
            acceptInput1P = false;
            player1.Dead();

            textMessage.setString("SQUISHED!");
            FloatRect textRect = textMessage.getLocalBounds();
            textMessage.setOrigin(
                textRect.left + textRect.width * 0.5f,
                textRect.top + textRect.height * 0.5f);
            textMessage.setPosition(1920 * 0.3f, 1080 * 0.5f);

            death.play();
            isDead1P = true;
        }

        if (sideBranches2P[countBranches - 1] == player2.getSide() && !isDead2P)
        {
            isPause = true;
            acceptInput2P = false;
            player2.Dead();

            textMessage.setString("SQUISHED!");
            FloatRect textRect = textMessage.getLocalBounds();
            textMessage.setOrigin(
                textRect.left + textRect.width * 0.5f,
                textRect.top + textRect.height * 0.5f);
            textMessage.setPosition(1920 * 0.3f * 2, 1080 * 0.5f);

            death.play();
            isDead2P = true;
        }
    }
}

void MultiPlayScene::render(RenderWindow* window)
{
        window->draw(spriteBackground);
        for (int i = 0; i < clouds_size; i++) {
            clouds[i].render(window);
        }
        window->draw(spriteTree1P);
        window->draw(spriteTree2P);

        flyingLog1P.render(window);
        flyingLog2P.render(window);

        for (int i = 0; i < countBranches; i++)
        {
            window->draw(spriteBranches1P[i]);
        }
        for (int i = 0; i < countBranches; i++)
        {
            window->draw(spriteBranches2P[i]);
        }
        player1.render(window);
        player2.render(window);

        bee.render(window);

        timeBar.render(window);

        window->draw(textScore);
        if (isPause)
        {
            window->draw(textMessage);
        }
}


void MultiPlayScene::Start()
{

}
void MultiPlayScene::End()
{

}
MultiPlayScene::~MultiPlayScene()
{

}