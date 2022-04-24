#pragma once
#include <SFML/Graphics.hpp>
#include "side.h"

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

    void init(int playerTextureInex);

    void HanddleInput(sf::Keyboard::Key key);

    void AtKeyReleased();

    void Update();

    void Dead();

    void Render(sf::RenderWindow& window);

    ~Player();
};