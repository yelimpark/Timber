#pragma once
#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3
using namespace sf;


class charSelect
{
public:
	charSelect(float width, float height);

	void draw(RenderWindow& window);
	void MoveLeft();
	void MoveRight();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	Font font;
	RectangleShape pointCharacter[MAX_NUMBER_OF_ITEMS];
};

