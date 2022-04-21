#include "GameFramework.h"
#include "../Manager/ResourceMgr.h"

#include <random>
#include <sstream>
#include <SFML/Audio.hpp>

using namespace sf;

GameFramework::GameFramework()
{
    VideoMode vm(1920, 1080);
	window = new RenderWindow(vm, "Timber!", Style::Default);
    sceneManager = new SceneManager(SceneType::STAGE);
}

bool GameFramework::Init()
{
	ResourceMgr::instance()->Init();
	sceneManager->Init();
    return true;
}

bool GameFramework::Run()
{
	while (window->isOpen())
	{
		Time dt = clock.restart();

		Event event;
		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window->close();
				break;
			default:
				sceneManager->HanddleInput(event);
				break;
			}
			break;
		}

		sceneManager->Update(dt.asSeconds());

		window->clear();
		sceneManager->render(window);
		window->display();
	}

    return 0;
}

GameFramework::~GameFramework()
{
    delete sceneManager;
}
