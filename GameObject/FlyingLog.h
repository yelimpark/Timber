#pragma once
#include <SFML/Graphics.hpp>

class FlyingLog {
private:
	sf::Sprite spriteLog;
	float logSpeedX;
	float logSpeedY;
	bool logActive;

public:
	FlyingLog();

	void init();

	void HanddleInput(sf::Keyboard::Key key);

	void Update(float dt);

	void Render(sf::RenderWindow& window);

	~FlyingLog();
};