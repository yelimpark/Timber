#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include <sstream>

#include "ImageObj.h"

using namespace sf;

Game::Game()
{
}

bool Game::Initialize()
{


    return false;
}

bool Game::Run()
{
    std::random_device rd;   // non-deterministic generator
    std::mt19937 gen(rd());  // to seed mersenne twister.

    Clock clock;

    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Timber!", Style::Default);

    return false;
}

Game::~Game()
{
}
