#include "ImgObj.h"


ImgObj::ImgObj(Texture& texture, int posX, int posY)
    :speed(0.f, 0.f), active(true)
{
    sprite.setTexture(texture);
    sprite.setPosition(posX, posY);
}


ImgObj::ImgObj(Texture& texture, int posX, int posY, bool active)
    :speed(0.f, 0.f), active(active)
{
    sprite.setTexture(texture);
    sprite.setPosition(posX, posY);
}


ImgObj::ImgObj(Texture& texture, int posX, int posY, bool active, float speedX, float speedY)
    :speed(speedX, speedY), active(active)
{
    sprite.setTexture(texture);
    sprite.setPosition(posX, posY);
}

//void ImgObj::setRotation(float angle)
//{
//    sprite.setRotation(angle);
//}
//
//void ImgObj::setOrigin(int x, int y)
//{
//    sprite.setOrigin(x, y);
//}
//
//const Vector2f& ImgObj::getPosition() const
//{
//    return sprite.getPosition();
//}
//
//void ImgObj::setSpeed(float x, float y)
//{
//    speed = Vector2f(x, y);
//}
//
//void ImgObj::setActive(bool active)
//{
//    this->active = active;
//}

bool ImgObj::getAtive() const
{
    return active;
}

const Vector2f& ImgObj::getSpeed() const
{
    return speed;
}

ImgObj::~ImgObj()
{
}
