#include "CharSelectPointer.h"
#include "../Manager/ResourceMgr.h"
#include <sstream>

CharSelectPointer::CharSelectPointer()
	:selectedItemIndex(0)
{
}

void CharSelectPointer::Init(float width, float height, Color color)
{
	float PosX = width * 0.5f - 250;

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		pointCharacter[i].setFillColor(Color::Transparent);
		pointCharacter[i].setSize(Vector2f(250, 400));
		FloatRect selectRect2 = pointCharacter[i].getLocalBounds();
		pointCharacter[i].setOrigin(
			selectRect2.left + selectRect2.width * 0.5f,
			selectRect2.top + selectRect2.height * 0.5f
		);
		pointCharacter[i].setPosition(Vector2f(PosX + 250 * i, height / 2));
	}
	this->color = color;
	selectedItemIndex = 0;
	pointCharacter[selectedItemIndex].setFillColor(color);
}

void CharSelectPointer::draw(RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(pointCharacter[i]);
	}
}

void CharSelectPointer::MoveLeft()
{
	if (selectedItemIndex - 1 >= 0)
	{
		pointCharacter[selectedItemIndex].setFillColor(Color::Transparent);
		selectedItemIndex--;
		pointCharacter[selectedItemIndex].setFillColor(color);
	}
}

void CharSelectPointer::MoveRight()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		pointCharacter[selectedItemIndex].setFillColor(Color::Transparent);
		selectedItemIndex++;
		pointCharacter[selectedItemIndex].setFillColor(color);
	}
}

CharSelectPointer::~CharSelectPointer()
{
}
