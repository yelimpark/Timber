#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include "side.h"

class Branch {
private:
	sf::Sprite sprite;

    side b_side;

public:
	Branch();

	void Init();

	void HanddleInput(sf::Keyboard::Key key, std::mt19937& gen);

	void Update(float height);

	void Render(sf::RenderWindow& window);

	side GetSide();

	~Branch();
};