#include "FoodMenu.h"

//Constructor gets a data, sounds and a menu type
FoodMenu::FoodMenu(gameDataRef data, SoundManage* sounds, int elementsNumber) : Menu(data, sounds, elementsNumber)
{
	setButtons();
}

//Sets the menu's buttons
void FoodMenu::setButtons()
{
	int x, startX, y;
	x = startX = background.getPosition().x + BUTTON_DIS_BACKGROUND_X;
	y = background.getPosition().y + BUTTON_DIS_BACKGROUND_Y;

	for (int i = 0; i < elementsNumber; i++)
	{
		data->assets.loadTexture("Food Menu Buttons " + std::to_string(i), FOOD_MENU + std::to_string(i) + ".png");
		sprites.push_back(sf::Sprite(data->assets.getTexture("Food Menu Buttons " + std::to_string(i))));
		sprites.at(i).setPosition(sf::Vector2f(x, y));
		if (i % 3 == 2)
		{
			x = startX;
			y += MENU_BUTTON_DIS_HEIGHT;
		}
		else
		{
			x += MENU_BUTTON_DIS_WIDTH;
		}
	}
}

//Gets the xp of chosen food from menu
int FoodMenu::getFoodXp(int index)
{
	int xp{};
	switch (index)
	{
	case Milk:
		xp = 5;
		break;
	case Strawberry:
		xp = 3;
		break;
	case Salad:
		xp = 7;
		break;
	case Burger:
		xp = 6;
		break;
	case Pizza:
		xp = 4;
		break;
	default: case Chocolate:
		xp = 2;
		break;
	}
	return xp;
}