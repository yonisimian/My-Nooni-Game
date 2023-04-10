#include "ToysMenu.h"

//Constructor gets a data, sounds and a menu type
ToysMenu::ToysMenu(gameDataRef data, SoundManage* sounds, int elementsNumber) : Menu(data, sounds, elementsNumber)
{
	setButtons();
}

//Sets the menu's buttons
void ToysMenu::setButtons()
{
	int x, startX, y;
	x = startX = background.getPosition().x + BUTTON_DIS_BACKGROUND_X;
	y = background.getPosition().y + BUTTON_DIS_BACKGROUND_Y;

	for (int i = 0; i < elementsNumber; i++)
	{
		data->assets.loadTexture("Toys Menu Buttons " + std::to_string(i), TOY_MENU + std::to_string(i) + ".png");
		sprites.push_back(sf::Sprite(data->assets.getTexture("Toys Menu Buttons " + std::to_string(i))));
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