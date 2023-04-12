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
	//Handles input
	Accessorizes::AccessoryType handleInput(sf::Event event);
	/// NOTE: I'd change the function's name... "handleInput" suggest a void return. Maybe "getInput" or "getAccessoryInput"
	//Draws
	void draw();
	//Stop the use of an accessory
	void stopUse();
	//Draws table
	void drawTable();

public:
	enum class AccessoryType
	{
		NO_ACCESSORY = -1,
		REFRIGERATOR,
		BED,
		BATH,
		TABLE,
		TOY_BOX
	}

private:
	std::vector <sf::Sprite> accessorizes;

	bool visibleTable; //Is the table visible
	AccessoryType typeUsed; //Which accessory is being used

	gameDataRef data;
};

