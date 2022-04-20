#include "ImageObj.h"

ImageObj::ImageObj(Texture& texture, int posX, int posY)
    :speed(0.f, 0.f), active(true)
{
    sprite.setTexture(texture);
    sprite.setPosition(posX, posY);
}


ImageObj::ImageObj(Texture& texture, int posX, int posY, bool active)
    :speed(0.f, 0.f), active(active)
{
    sprite.setTexture(texture);
    sprite.setPosition(posX, posY);
}


ImageObj::ImageObj(Texture& texture, int posX, int posY, bool active, float speedX, float speedY)
    :speed(speedX, speedY), active(active)
{
    sprite.setTexture(texture);
    sprite.setPosition(posX, posY);
}

void ImageObj::setPosition(int x, int y)
{
    sprite.setPosition(x, y);
}

void ImageObj::setPosition(Vector2f pos)
{
    sprite.setPosition(pos);
}

void ImageObj::setRotation(float angle)
{
    sprite.setRotation(angle);
}

void ImageObj::setOrigin(int x, int y)
{
    sprite.setOrigin(x, y);
}

const Vector2f& ImageObj::getPosition() const
{
    return sprite.getPosition();
}

void ImageObj::setSpeed(float x, float y)
{
    speed = Vector2f(x, y);
}

void ImageObj::setActive(bool active)
{
    this->active = active;
}

bool ImageObj::getAtive() const
{
    return active;
}

const Vector2f& ImageObj::getSpeed() const
{
    return speed;
}

const Sprite& ImageObj::getSprite() const
{
    return sprite;
}

ImageObj::~ImageObj()
{
}
