#pragma once
#include <SFML/Graphics.hpp>
#include <random>

class LowDynamicObj {
private:
	sf::Sprite sprite;

	float speed;

	bool active;

public:
	LowDynamicObj();

	void init(sf::Texture& texture);

	void Update(float dt, std::mt19937& gen, float defHeight);

	void Render(sf::RenderWindow& window);

	~LowDynamicObj();
};