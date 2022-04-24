#include "FlyingLog.h"
#include "../Manager/ResourceMgr.h"

FlyingLog::FlyingLog()
	:logSpeedX(0), logSpeedY(0), logActive(false)
{
}

void FlyingLog::init()
{
    spriteLog.setTexture(*ResourceMgr::instance()->GetTexture("MAINLOGTEX"));
    spriteLog.setPosition(810, 720);

    logSpeedX = 1000;
    logSpeedY = -1500;

    logActive = false;
}

void FlyingLog::HanddleInput(sf::Keyboard::Key key)
{
	switch (key)
	{
	case Keyboard::Left:
		spriteLog.setPosition(810, 720);
		logSpeedX = 5000;
		logActive = true;
		break;

	case Keyboard::Right:
		spriteLog.setPosition(810, 720);
		logSpeedX = -5000;
		logActive = true;
		break;

	default:
		break;
	}
}

void FlyingLog::Update(float dt)
{
	if (logActive)
	{
		Vector2f logPos = spriteLog.getPosition();
		logPos.x += logSpeedX * dt;
		logPos.y += logSpeedY * dt;
		spriteLog.setPosition(logPos);

		if (logPos.x < -100 || logPos.x > 2000)
		{
			logActive = false;
			spriteLog.setPosition(810, 720);
		}
	}
}

void FlyingLog::Render(sf::RenderWindow& window)
{
	window.draw(spriteLog);
}

FlyingLog::~FlyingLog()
{
}
