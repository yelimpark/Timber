#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

enum class sideMulti
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
    sideMulti p_side;
    Sprite spritePlayer;
    Sprite spriteAxe;
    Keyboard::Key LeftMoveKey;
    Keyboard::Key RightMoveKey;
    Vector2f position;
    Vector2f originalPos;

public:
    MultiPlayer();

    sideMulti getSide();
    void init(int playerTextureInex, int x, int y, Keyboard::Key left, Keyboard::Key right);
    void HanddleInput(Keyboard::Key key);
    void AtKeyReleased();
    void Update();
    void Dead();
    void render(sf::RenderWindow* window);

    ~MultiPlayer();
};