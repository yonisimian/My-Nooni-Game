#pragma once

#include "Menu.h"

//A child class of Menu - for toys menu
class ToysMenu : public Menu
{
public:
	//Constructor
	ToysMenu(gameDataRef data, SoundManage* sounds, int elementsNumber);
	//Destructor
	~ToysMenu() { }

private:
	//Sets the menu's buttons
	void setButtons();
};
