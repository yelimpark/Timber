#include "Player.h"
#include "../Manager/ResourceMgr.h"
#include <sstream>

using namespace std;

Player::Player()
	:p_side(side::LEFT)
{

}

side Player::getSide()
{
	return p_side;
}

void Player::init(int playerTextureInex)
{
	stringstream ss;
	ss << "MAINPLAYERTEX" << playerTextureInex + 1;
	spritePlayer.setTexture(*ResourceMgr::instance()->GetTexture(ss.str()));
	spritePlayer.setPosition(580, 720);
	p_side = side::LEFT;

	spriteAxe.setTexture(*ResourceMgr::instance()->GetTexture("MAINAXETEX"));
	spriteAxe.setPosition(700, 830);
}

void Player::HanddleInput(sf::Keyboard::Key key)
{
	switch (key)
	{
	case Keyboard::Return:
		spritePlayer.setPosition(580, 720);
		break;
	case Keyboard::Left:
		p_side = side::LEFT;
		spritePlayer.setPosition(580, 720);
		spriteAxe.setPosition((float)AXE_POSITION::LEFT, spriteAxe.getPosition().y);
		break;
	case Keyboard::Right:
		p_side = side::RIGHT;
		spritePlayer.setPosition(1200, 720);
		spriteAxe.setPosition((float)AXE_POSITION::RIGHT, spriteAxe.getPosition().y);
		break;
	default:
		break;
	}
}

void Player::AtKeyReleased()
{
	spriteAxe.setPosition(2000, spriteAxe.getPosition().y);
}



void Player::Update()
{

}

void Player::Dead()
{
	spritePlayer.setTexture(*ResourceMgr::instance()->GetTexture("MAINRIPTEX"));
}

void Player::Render(sf::RenderWindow& window)
{
	window.draw(spritePlayer);
	window.draw(spriteAxe);
}

Player::~Player()
{
}
