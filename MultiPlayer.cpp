#include "MultiPlayer.h"
#include <sstream>
#include "Manager/ResourceMgr.h"

using namespace std;

MultiPlayer::MultiPlayer()
	:p1_side(side1::LEFT), p2_side(side2::LEFT)
{

}

side1 MultiPlayer::getSide1P()
{
	return p1_side;
}

side2 MultiPlayer::getSide2P()
{
	return p2_side;
}

void MultiPlayer::init(int playerTextureInex)
{
	stringstream ss1;
	stringstream ss2;
	ss1 << "MAINPLAYER1TEX" << playerTextureInex + 1;
	ss2 << "MAINPLAYER2TEX" << playerTextureInex + 1;
	spritePlayer1.setTexture(*ResourceMgr::instance()->GetTexture(ss1.str()));
	spritePlayer2.setTexture(*ResourceMgr::instance()->GetTexture(ss2.str()));
	spritePlayer1.setPosition(Vector2f(1920.f * 0.3f * 0.4f, 720.f));
	spritePlayer2.setPosition(Vector2f(1920.f * 0.3f * 2.1f, 720.f));
	p1_side = side1::LEFT;
	p2_side = side2::LEFT;

	spriteAxe1P.setTexture(*ResourceMgr::instance()->GetTexture("MAINAXETEX"));
	spriteAxe2P.setTexture(*ResourceMgr::instance()->GetTexture("MAINAXETEX"));
	spriteAxe1P.setPosition(Vector2f(1920.f * 0.3f, 830.f));
	spriteAxe1P.setPosition(Vector2f(1920.f * 0.3f * 0.2f, 830.f));
}

void MultiPlayer::HanddleInput(sf::Keyboard::Key key)
{
	switch (key)
	{
	case Keyboard::Return:
		spritePlayer1.setPosition(Vector2f(1920.f * 0.3f * 0.4f, 720.f));
		spritePlayer2.setPosition(Vector2f(1920.f * 0.3f * 2.1f, 720.f));
		break;
	case Keyboard::A:
		p1_side = side1::LEFT;
		spritePlayer1.setPosition(Vector2f(1920.f * 0.3f, 720.f));
		spriteAxe1P.setPosition((float)AXE1P_POSITION::LEFT, spriteAxe1P.getPosition().y);
		break;
	case Keyboard::D:
		p1_side = side1::RIGHT;
		spritePlayer1.setPosition(Vector2f(1920.f * 0.3f * 0.4f, 720.f));
		spriteAxe1P.setPosition((float)AXE2P_POSITION::RIGHT, spriteAxe1P.getPosition().y);
		break;
	case Keyboard::Left:
		p2_side = side2::LEFT;
		spritePlayer2.setPosition(Vector2f(1920.f * 0.3f * 2.1f, 720.f));
		spriteAxe2P.setPosition((float)AXE2P_POSITION::LEFT, spriteAxe2P.getPosition().y);
	case Keyboard::Right:
		p2_side = side2::RIGHT;
		spritePlayer2.setPosition(Vector2f(1920.f * 0.3f * 2.1f, 720.f));
		spriteAxe2P.setPosition((float)AXE2P_POSITION::RIGHT, spriteAxe2P.getPosition().y);
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
	spritePlayer1.setTexture(*ResourceMgr::instance()->GetTexture("MAINRIPTEX"));
	spritePlayer2.setTexture(*ResourceMgr::instance()->GetTexture("MAINRIPTEX"));

}

void MultiPlayer::render(sf::RenderWindow* window)
{
	window->draw(spritePlayer1);
	window->draw(spritePlayer2);
	window->draw(spriteAxe1P);
	window->draw(spriteAxe2P);
}

MultiPlayer::~MultiPlayer()
{

}