#pragma once
#include <SFML/Graphics.hpp>

class TimeBar {
private:
	sf::RectangleShape rs;

	sf::Vector2f timerBarSize;

	float timerBarWidthPerSecond;

	float timeMax;

	float timeRemaining;

public:
	TimeBar();

	void init(float timeMax);

	void HanddleInput(sf::Keyboard::Key key, int score);

	void Update(float dt);

	void Render(sf::RenderWindow& window);

	bool IsEnd();

	~TimeBar();
};