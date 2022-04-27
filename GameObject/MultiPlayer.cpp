#include "MultiPlayer.h"
#include <sstream>
#include "../Manager/ResourceMgr.h"

using namespace std;

MultiPlayer::MultiPlayer()
	:p_side(sideMulti::LEFT), LeftMoveKey(Keyboard::A), RightMoveKey(Keyboard::D)
{

}

sideMulti MultiPlayer::getSide()
{
	return p_side;
}

void MultiPlayer::init(int playerTextureInex, int x, int y, Keyboard::Key left, Keyboard::Key right)
{
	stringstream ss;
	ss << "MAINPLAYER1TEX" << playerTextureInex + 1;
	spritePlayer.setTexture(*ResourceMgr::instance()->GetTexture(ss.str()));
	position.x = x;
	position.y = y;
	spritePlayer.setPosition(position);
	originalPos = position;
	spriteAxe.setTexture(*ResourceMgr::instance()->GetTexture("MAINAXETEX"));
	p_side = sideMulti::LEFT;
	LeftMoveKey = left;
	RightMoveKey = right;
}

void MultiPlayer::HanddleInput(sf::Keyboard::Key key)
{
	//switch (key)
	//{
	//case Keyboard::Return:
	//	spritePlayer.setPosition(originalPos);
	//	break;
	//case this->LeftMoveKey:
	//	p_side = sideMulti::LEFT;
	//	spritePlayer1.setPosition(Vector2f(1920.f * 0.3f, 720.f));
	//	spriteAxe1P.setPosition((float)AXE1P_POSITION::LEFT, spriteAxe1P.getPosition().y);
	//	break;
	//case RightMoveKey:
	//	p_side = sideMulti::RIGHT;
	//	spritePlayer1.setPosition(Vector2f(1920.f * 0.3f * 0.4f, 720.f));
	//	spriteAxe1P.setPosition((float)AXE2P_POSITION::RIGHT, spriteAxe1P.getPosition().y);
	//	break;
	//case Keyboard::Left:
	//	p_side = sideMulti::LEFT;
	//	spritePlayer2.setPosition(Vector2f(1920.f * 0.3f * 2.1f, 720.f));
	//	spriteAxe2P.setPosition((float)AXE2P_POSITION::LEFT, spriteAxe2P.getPosition().y);
	//case Keyboard::Right:
	//	p_side = sideMulti::RIGHT;
	//	spritePlayer2.setPosition(Vector2f(1920.f * 0.3f * 2.1f, 720.f));
	//	spriteAxe2P.setPosition((float)AXE2P_POSITION::RIGHT, spriteAxe2P.getPosition().y);
	//}

	if (key == LeftMoveKey) {
		p_side = sideMulti::LEFT;
		position = originalPos;
		spritePlayer.setPosition(position);
		spriteAxe.setPosition((float)AXE1P_POSITION::LEFT, spriteAxe.getPosition().y);
	}
}

void MultiPlayer::AtKeyReleased()
{

}

void MultiPlayer::Update()
{

}

void MultiPlayer::Dead()
{
	spritePlayer.setTexture(*ResourceMgr::instance()->GetTexture("MAINRIPTEX"));
}

void MultiPlayer::render(sf::RenderWindow* window)
{
	window->draw(spritePlayer);
	window->draw(spriteAxe);
}

MultiPlayer::~MultiPlayer()
{

}