#include "LowDynamicObj.h"
#include <random>

using namespace std;

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

void LowDynamicObj::Update(float dt, float defHeight)
{
    random_device rd;
    mt19937 gen(rd());

    if (!active)
    {
        speed = (-1) * gen() % 200 + 200;
        float y = gen() % 400 + defHeight;
        sprite.setPosition(2000, y);
        active = true;
    }
    else
    {
        float deltaX = speed * dt;
        sf::Vector2f currPos = sprite.getPosition();
        currPos.x -= deltaX;
        sprite.setPosition(currPos);

        if (currPos.x < -200)
        {
            active = false;
        }
    }
}

void LowDynamicObj::Render(sf::RenderWindow& window)
{
    window.draw(sprite);
}

LowDynamicObj::~LowDynamicObj()
{
}
