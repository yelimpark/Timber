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
    VideoMode vm(1920, 1080); //�ػ� ����
    RenderWindow window(vm, "Timber!", Style::Default); //Fullscreen �ؼ� Ǯ��ũ�� �� �� �ִµ� ������ ���� â��尡 ���ϴ�

    //sceneManager.update(scene);

    //sceneManager.render(scene);

    //���α׷� ���Ḧ ���� ����


    // testing...
    StageScene stageScene(SceneType::STAGE, &window);

    stageScene.render();

    return false;
}

GameFramework::~GameFramework()
{
    //delete sceneManager;
}
