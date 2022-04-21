#include "charSelect.h"

charSelect::charSelect()
	:selectedItemIndex(0)
{
}

void charSelect::Init(float width, float height)
{
	pointCharacter[0].setFillColor(Color::Yellow);
	pointCharacter[0].setSize(Vector2f(250, 400));
	FloatRect selectRect1 = pointCharacter[0].getLocalBounds();
	pointCharacter[0].setOrigin(
		selectRect1.left + selectRect1.width * 0.5f,
		selectRect1.top + selectRect1.height * 0.5f
	);
	pointCharacter[0].setPosition(Vector2f(width * 0.5f - 250, height / 2));

	pointCharacter[1].setFillColor(Color::Transparent);
	pointCharacter[1].setSize(Vector2f(250, 400));
	FloatRect selectRect2 = pointCharacter[1].getLocalBounds();
	pointCharacter[1].setOrigin(
		selectRect2.left + selectRect2.width * 0.5f,
		selectRect2.top + selectRect2.height * 0.5f
	);
	pointCharacter[1].setPosition(Vector2f(width * 0.5f, height / 2));

	pointCharacter[2].setFillColor(Color::Transparent);
	pointCharacter[2].setSize(Vector2f(250, 400));
	FloatRect selectRect3 = pointCharacter[2].getLocalBounds();
	pointCharacter[2].setOrigin(
		selectRect3.left + selectRect3.width * 0.5f,
		selectRect3.top + selectRect3.height * 0.5f
	);
	pointCharacter[2].setPosition(Vector2f(width * 0.5f + 250, height / 2));

	selectedItemIndex = 0;
}

void charSelect::draw(RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(pointCharacter[i]);
	}
}

void charSelect::MoveLeft()
{
	if (selectedItemIndex - 1 >= 0)
	{
		pointCharacter[selectedItemIndex].setFillColor(Color::Transparent);
		selectedItemIndex--;
		pointCharacter[selectedItemIndex].setFillColor(Color::Yellow);
	}
}

void charSelect::MoveRight()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		pointCharacter[selectedItemIndex].setFillColor(Color::Transparent);
		selectedItemIndex++;
		pointCharacter[selectedItemIndex].setFillColor(Color::Yellow);
	}
}