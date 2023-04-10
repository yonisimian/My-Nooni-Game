#pragma once

#include "Game.h"
#include "SoundManage.h"
#include "Definitions.h"
#include <vector>
#include <SFML/Graphics.hpp>

//A class for menu
class Menu
{
public:
	//Constructor
	Menu(gameDataRef data, SoundManage* sounds, int elementsNumber);
	//Destructor
	~Menu() { }
	//Draws the menu
	void draw();
	//Handles input
	int handleInput();

protected:
	//Sets the menu's buttons
	virtual void setButtons() = 0;

	sf::Sprite background;
	sf::Sprite backButton;
	std::vector <sf::Sprite> sprites; //Menu's objects

	SoundManage* sounds;
	gameDataRef data;

	int elementsNumber;

	//Distance between two buttons
	const int MENU_BUTTON_DIS_HEIGHT = 100;
	const int MENU_BUTTON_DIS_WIDTH = 110;
	//Distance between first button and background
	const int BUTTON_DIS_BACKGROUND_X = 58;
	const int BUTTON_DIS_BACKGROUND_Y = 60;
};