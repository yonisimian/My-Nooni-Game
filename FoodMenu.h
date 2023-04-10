#pragma once

#include "Menu.h"

//A child class of Menu - for food menu
class FoodMenu : public Menu
{
public:
	//Constructor
	FoodMenu(gameDataRef data, SoundManage* sounds, int elementsNumber);
	//Destructor
	~FoodMenu() { }
	//Gets the xp of chosen food from menu
	int getFoodXp(int index);

private:
	//Sets the menu's buttons
	void setButtons();
};
