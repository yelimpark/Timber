#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

enum class side1
{
    LEFT,
    RIGHT,
    NONE,
};

enum class side2
{
    LEFT,
    RIGHT,
    NONE,
};

enum class AXE1P_POSITION
{
    LEFT = 300,
    RIGHT = 480
};

enum class AXE2P_POSITION
{
    LEFT = 1300,
    RIGHT = 1440
};

class MultiPlayer {
private:
    side1 p1_side;
    side2 p2_side;
    Sprite spritePlayer1;
    Sprite spritePlayer2;
    Sprite spriteAxe1P;
    Sprite spriteAxe2P;

public:
    MultiPlayer();

    side1 getSide1P();
    side2 getSide2P();
    void init(int playerTextureInex);
    void HanddleInput(sf::Keyboard::Key key);
    void AtKeyReleased();
    void Update();
    void Dead();
    void render(sf::RenderWindow* window);

    ~MultiPlayer();
};