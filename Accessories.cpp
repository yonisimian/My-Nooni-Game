#include "Accessories.h"

Accessories::Accessories(gameDataRef data) : data(data)
{
	isWorking = false;
}

void Accessories::init()
{
	for (int i = 0; i < 5; i++)
	{
		data->assets.loadTexture("Accessory " + std::to_string(i), "graphics/Accessories/" + std::to_string(i) + ".png");
		acceessories.push_back(sf::Sprite(setTexture(data->assets.getTexture("Accessory " + std::to_string(i)))));
		bath.setPosition(sf::Vector2f(410, 390));
	}
}

void Accessories::draw()
{
	if (!isWorking)
	{
		return;
	}
	for (int i = 0; i < 5; i++)
	{
	}

	data->window.draw(bath);
	data->window.draw(apple);
	data->window.draw(sandwich);
	data->window.draw(ball);
	data->window.draw(bear);
}

void Accessories::handleInput(sf::Event event)
{
	if (!isWorking)
	{
		return;
	}
	if (data->input.isSpriteClicked(bath, sf::Mouse::Left, data->window))
	{

	}
	if (data->input.isSpriteClicked(apple, sf::Mouse::Left, data->window))
	{

	}
	if (data->input.isSpriteClicked(sandwich, sf::Mouse::Left, data->window))
	{

	}
	if (data->input.isSpriteClicked(bath, sf::Mouse::Left, data->window))
	{

	}
	if (data->input.isSpriteClicked(bath, sf::Mouse::Left, data->window))
	{

	}
}
