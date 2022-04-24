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
    sceneManager = new SceneManager();
}

void GameFramework::Init()
{
	ResourceMgr::instance()->Init();
	sceneManager->Init();
}

bool GameFramework::Run()
{
	while (window->isOpen())
	{
		Time dt = clock.restart();

		// HanddleInput
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
		}

		// Update
		sceneManager->Update(dt.asSeconds());

		// Render
		window->clear();
		sceneManager->Render(*window);
		window->display();
	}

    return 0;
}

GameFramework::~GameFramework()
{
	delete window;
    delete sceneManager;
}
