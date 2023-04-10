#include "Accessorizes.h"
#include "Definitions.h"

//Constructor gets a data
Accessorizes::Accessorizes(gameDataRef data) : data(data)
{
	visibleTable = false;
	typeUsed = -1;

	data->assets.loadTexture("Accessorize 0", REFRIGERATOR);
	data->assets.loadTexture("Accessorize 1", BED);
	data->assets.loadTexture("Accessorize 2", BATH);
	data->assets.loadTexture("Accessorize 3", TABLE);
	data->assets.loadTexture("Accessorize Used 0", OPENED_REFRIGERATOR);
	data->assets.loadTexture("Accessorize Used 1", USED_BED);
	

	for (int i = 0; i < ACCESSORIES_NUBER; i++)
	{
		accessorizes.push_back(sf::Sprite(data->assets.getTexture("Accessorize " + std::to_string(i))));
	}

	accessorizes.at(0).setPosition(sf::Vector2f(67, 240));
	accessorizes.at(1).setPosition(sf::Vector2f(290, 260));
	accessorizes.at(2).setPosition(sf::Vector2f(650, 295));
	accessorizes.at(3).setPosition(sf::Vector2f(400, 540));
}

//Handles input if one accessory is being touched by the mouse
int Accessorizes::handleInput(sf::Event event)
{
	for (int i = 0; i < ACCESSORIES_NUBER - 1; i++)
	{
		if (data->input.isSpriteClicked(accessorizes.at(i), sf::Mouse::Left, data->window))
		{
			if (i <= bed) //If accessory's image is changing to being used
			{
				typeUsed = i;
				accessorizes.at(typeUsed).setTexture(data->assets.getTexture("Accessorize Used " + std::to_string(typeUsed)));
			}
			return i;
		}
	}
	return -1;
}

//Draws accessorizes
void Accessorizes::draw()
{
	for (int i = 0; i < ACCESSORIES_NUBER - 1; i++)
	{
		data->window.draw(accessorizes.at(i));
	}
}

//Stops the use of accessory
void Accessorizes::stopUse()
{
	if (typeUsed >= refrigerator && typeUsed <= bed)
	{
		accessorizes.at(typeUsed).setTexture(data->assets.getTexture("Accessorize " + std::to_string(typeUsed)));
		typeUsed = -1;
	}
}

//Set visibility of table
void Accessorizes::setVisibleTable()
{
	visibleTable = !visibleTable;
}

//Draws table
void Accessorizes::drawTable()
{
	if (visibleTable)
	{
		data->window.draw(accessorizes.at(3));
	}
}