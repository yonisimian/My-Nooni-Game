#include "Menu.h"

//Constructor gets a data, sounds and a menu type
Menu::Menu(gameDataRef data, SoundManage* sounds, int elementsNumber) : data(data), sounds(sounds), elementsNumber(elementsNumber)
{
	elementsNumber = 0;

	data->assets.loadTexture("Menus Background", MENU_WINDOW);
	background.setTexture(data->assets.getTexture("Menus Background"));
	background.setPosition(sf::Vector2f(data->window.getSize().x / 2 - background.getGlobalBounds().width / 2, 
		data->window.getSize().y / 2 - background.getGlobalBounds().height / 2));

	backButton.setTexture(data->assets.getTexture("Select Menu Back Button"));
	backButton.setPosition(sf::Vector2f(background.getPosition().x, 
		background.getGlobalBounds().height + background.getPosition().y - 50));
}

//Draws the menu
void Menu::draw()
{
	data->window.draw(background);
	data->window.draw(backButton);
	for (int i = 0; i < elementsNumber; i++)
	{
		data->window.draw(sprites.at(i));
	}
}

//Handles input
int Menu::handleInput()
{
	if (data->input.isSpriteClicked(backButton, sf::Mouse::Left, data->window))
	{
		sounds->playGameSound(mouseClickSound);
		return EXIT_MENU;
	}
	//Checks if one of the menu objects is being pressed and returns it
	for (int i = 0; i < elementsNumber; i++)
	{
		if (data->input.isSpriteClicked(sprites.at(i), sf::Mouse::Left, data->window))
		{
			sounds->playGameSound(mouseClickSound);
			return i;
		}
	}
	return -1;
}