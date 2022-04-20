#include "GameFramework.h"

#include <SFML/Graphics.hpp>
#include <random>
#include <sstream>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

GameFramework::GameFramework()
{
    //sceneManager = new SceneManager(SceneType::STAGE);
}

bool GameFramework::Initialize()
{
    return true;
}

bool GameFramework::Run()
{
    VideoMode vm(1920, 1080); //해상도 정보
    RenderWindow window(vm, "Timber!", Style::Default); //Fullscreen 해서 풀스크린 할 수 있는데 개발할 때는 창모드가 편하다

    //sceneManager.update(scene);

    //sceneManager.render(scene);

    //프로그램 종료를 위한 내용


    // testing...
    StageScene stageScene(SceneType::STAGE, &window);

    stageScene.render();

    return false;
}

GameFramework::~GameFramework()
{
    //delete sceneManager;
}
