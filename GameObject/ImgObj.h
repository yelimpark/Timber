#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class ImgObj {
protected:
    Sprite sprite;

    Vector2f speed;

    bool active;

public:
    ImgObj(Texture& texture, int posX, int posY);

    ImgObj(Texture& texture, int posX, int posY, bool active);

    ImgObj(Texture& texture, int posX, int posY, bool active, float speedX, float speedY);

    const Vector2f& getPosition() const;

    bool getAtive() const;

    const Vector2f& getSpeed() const;

    ~ImgObj();
};