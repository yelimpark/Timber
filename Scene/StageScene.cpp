#include "StageScene.h"
#include <sstream>
#include "../Manager/ResourceMgr.h"

using namespace sf;
using namespace std;

StageScene::StageScene(SceneManager& sceneManager)
    :Scene(sceneManager)
{

}

void StageScene::Init()
{
    player.init(sceneManager.GetGameVariables().selectedCharaIndex1p);

    for (int i = 0; i < clouds_size; i++) {
        clouds[i].init(*ResourceMgr::instance()->GetTexture("MAINCLOUDTEX"));
    }

    bee.init(*ResourceMgr::instance()->GetTexture("MAINBEETEX"));

    timeBar.init(6.0f);

    spriteBackground.setTexture(*ResourceMgr::instance()->GetTexture("MAINBGTEX"));
    spriteBackground.setPosition(0, 0);

    spriteTree.setTexture(*ResourceMgr::instance()->GetTexture("MAINTREETEX"));
    spriteTree.setPosition(810, 0);

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

    flyingLog.init();

    for (int i = 0; i < countBranches; i++)
    {
        branches[i].Init();
    }

    acceptInput = false;
    isPause = true;
}

void StageScene::HanddleInput(sf::Event& event)
{
    switch (event.type)
    {
    case Event::KeyPressed:
        switch (event.key.code)
        {
        case Keyboard::Return:
        {
            isPause = false;

            score = 0;
            timeBar.HanddleInput(event.key.code, score);
            acceptInput = true;

            for (int i = 0; i < countBranches; ++i)
            {
                branches[i].HanddleInput(event.key.code);
            }
            player.HanddleInput(event.key.code);
        }
        break;
        case Keyboard::Left:
        case Keyboard::Right:
            if (acceptInput && !isPause)
            {
                chop.play();

                player.HanddleInput(event.key.code);

                ++score;

                timeBar.HanddleInput(event.key.code, score);


                for (int i = countBranches - 1; i > 0 ; --i)
                {
                    branches[i] = branches[i - 1];
                }
                branches[0].HanddleInput(event.key.code);

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
                player.AtKeyReleased();
            }
        }
        break;
    default:
        break;
    }
}

void StageScene::Update(float dt)
{
    if (!isPause)
    {

        bee.Update(dt, 500);

        for (int i = 0; i < clouds_size; i++) {
            clouds[i].Update(dt, 0);
        }

        timeBar.Update(dt);

        for (int i = 0; i < countBranches; i++)
        {
            float height = 150 * i;
            branches[i].Update(height);
        }

        stringstream ss;
        ss << "Score = " << score;
        textScore.setString(ss.str());

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

        flyingLog.Update(dt);

        if (branches[countBranches - 1].GetSide() == player.getSide())
        {
            isPause = true;
            acceptInput = false;
            player.Dead();

            textMessage.setString("SQUISHED!");
            FloatRect textRect = textMessage.getLocalBounds();
            textMessage.setOrigin(
                textRect.left + textRect.width * 0.5f,
                textRect.top + textRect.height * 0.5f);

            death.play();
        }

    }
}

void StageScene::Render(sf::RenderWindow& window)
{
        window.draw(spriteBackground);
        for (int i = 0; i < clouds_size; i++) {
            clouds[i].Render(window);
        }
        window.draw(spriteTree);

        flyingLog.Render(window);

        for (int i = 0; i < countBranches; i++)
        {
            branches[i].Render(window);
        }
        player.Render(window);

        bee.Render(window);

        timeBar.Render(window);

        window.draw(textScore);
        if (isPause)
        {
            window.draw(textMessage);
        }

}

void StageScene::Start()
{
    Init();
}

void StageScene::End()
{

}

StageScene::~StageScene()
{
    
}
