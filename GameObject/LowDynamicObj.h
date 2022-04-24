#pragma once
#include <SFML/Graphics.hpp>

class LowDynamicObj {
private:
	sf::Sprite sprite;

	float speed;

	bool active;

public:
	LowDynamicObj();

	void init(sf::Texture& texture);

	void Update(float dt, float defHeight);

	void Render(sf::RenderWindow& window);

	~LowDynamicObj();
};