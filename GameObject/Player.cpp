#include "Player.h"

Player::Player(Texture& texture, int posX, int posY, side p_side)
	:ImgObj(texture, posX, posY), p_side(p_side)
{
}

side Player::getSide()
{
	return p_side;
}

void Player::HandleInput(Keyboard::Key key)
{
	switch (key)
	{
	case Keyboard::Return:
		sprite.setPosition(580, 720);
		break;
	case Keyboard::Left:
		p_side = side::LEFT;
		sprite.setPosition(580, 720);
		break;
	case Keyboard::Right:
		p_side = side::RIGHT;
		sprite.setPosition(1200, 720);
		break;
	default:
		break;
	}
}

void Player::Update()
{

}

void Player::Dead()
{
	sprite.setPosition(2000, 660);
}

void Player::render(sf::RenderWindow* window)
{
	window->draw(sprite);
}

Player::~Player()
{
}
