#pragma once
#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEMS 3
using namespace sf;

class CharSelectPointer
{
public:
	CharSelectPointer();

	void Init(float width, float height);

	void draw(RenderWindow& window);

	void MoveLeft();
	void MoveRight();
	int GetPressedItem() { return selectedItemIndex; }

	~CharSelectPointer();

private:
	int selectedItemIndex;
	RectangleShape pointCharacter[MAX_NUMBER_OF_ITEMS];
};