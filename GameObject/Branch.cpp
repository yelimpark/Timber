#include "Branch.h"
#include "../Manager/ResourceMgr.h"

Branch::Branch()
	:b_side(side::NONE)
{
}

void Branch::Init()
{
    sprite.setTexture(*ResourceMgr::instance()->GetTexture("MAINBRANCHTEX"));
    sprite.setPosition(-2000, -2000);
    sprite.setOrigin(220, 40);
    b_side = side::NONE;
}

void Branch::HanddleInput(sf::Keyboard::Key key, std::mt19937& gen)
{
	switch (key)
	{
	case Keyboard::Return:
		b_side = side::NONE;
		break;

	case Keyboard::Left:
	case Keyboard::Right:
    {
        int rnd = gen() % 5;
        switch (rnd)
        {
        case 0:
            b_side = side::LEFT;
            break;
        case 1:
            b_side = side::RIGHT;
            break;
        default:
            b_side = side::NONE;
            break;
        }
        break;
    }

	default:
		break;
	}
}

void Branch::Update(float height)
{
    switch (b_side)
    {
    case side::LEFT:
        sprite.setPosition(610, height);
        sprite.setRotation(180);
        break;
    case side::RIGHT:
        sprite.setPosition(1330, height);
        sprite.setRotation(0);
        break;
    default:
        sprite.setPosition(-2000, -2000);
        break;
    }
}

void Branch::Render(sf::RenderWindow& window)
{
    window.draw(sprite);
}

side Branch::GetSide()
{
    return b_side;
}

Branch::~Branch()
{
}
