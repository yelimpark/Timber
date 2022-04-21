#pragma once
#include <SFML/Graphics.hpp>

enum class side
{
    LEFT,
    RIGHT,
    NONE
};

enum class AXE_POSITION {
    LEFT = 700,
    RIGHT = 1075
};

class Player {
private:
    side p_side;

    sf::Sprite spritePlayer;

    sf::Sprite spriteAxe;

public:
    Player();

    side getSide();

    void init();

    void HanddleInput(sf::Keyboard::Key key);

    void AtKeyReleased();

    void Update();

    void Dead();

    void render(sf::RenderWindow* window);

    ~Player();
};