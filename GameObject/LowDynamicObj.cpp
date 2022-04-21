#include "LowDynamicObj.h"

LowDynamicObj::LowDynamicObj()
	:speed(0.f), active(false)
{
 
}

void LowDynamicObj::init(sf::Texture& texture)
{
    sprite.setTexture(texture);
    sprite.setPosition(2000, 2000);
    speed = 0.f;
    active = false;
}

void LowDynamicObj::Update(float dt, std::mt19937& gen)
{
    if (!active)
    {
        speed = (-1) * gen() % 200 + 200;
        float y = gen() % 500 + 500;
        sprite.setPosition(2000, y);
        active = true;
    }
    else
    {
        float deltaX = speed * dt;
        sf::Vector2f currPos = sprite.getPosition();
        currPos.x += deltaX;
        sprite.setPosition(currPos);

        if (currPos.x < -200)
        {
            active = false;
        }
    }
}

void LowDynamicObj::render(sf::RenderWindow* window)
{
    window->draw(sprite);
}

LowDynamicObj::~LowDynamicObj()
{
}
