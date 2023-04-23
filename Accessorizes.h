#pragma once

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <vector>

//A class for room's accessorizes
class Accessorizes
{
public:
	//Constructor
	Accessorizes(gameDataRef data);
	//Destructor
	~Accessorizes() = default;
	//Set visibility of table
	void setVisibleTable();
	//Handles inout
	int handleInput(sf::Event event);
	//Draws
	void draw();
	//Stop the use of an accessory
	void stopUse();
	//Draws table
	void drawTable();

private:
	std::vector <sf::Sprite> accessorizes;

	bool visibleTable; //Is the table visible
	int typeUsed; //Which accessory is being used

	gameDataRef data;
};

