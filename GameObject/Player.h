#pragma once
#include "ImgObj.h"

enum class side
{
    LEFT,
    RIGHT,
    NONE
};

class Player : public ImgObj {
private:
    side p_side;

public:
    Player(Texture& texture, int posX, int posY, side p_side);

    side getSide();

    void HandleInput(Keyboard::Key key);

    void Update();

    void Dead();

    void render(sf::RenderWindow* window);

    ~Player();
};