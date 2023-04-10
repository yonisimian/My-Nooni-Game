#include "Flash.h"

Flash::Flash(gameDataRef data) : data(data)
{
	shape = sf::RectangleShape(sf::Vector2f(data->window.getSize()));
	shape.setFillColor(sf::Color(255,255,255,0));
	isFlash = true;
}

void Flash::show(float dt)
{
	if (isFlash)
	{
		int alpha = (int)shape.getFillColor().a + (1500.0f * dt);
		if (alpha >= 255.0f)
		{
			alpha = 255.0f;
			isFlash = false;
		}
		shape.setFillColor(sf::Color(255, 255, 255, alpha));
	}
	else
	{
		int alpha = (int)shape.getFillColor().a - (1500.0f * dt);
		if (alpha <= 0.0f)
		{
			alpha = 0.0f;
			isFlash = false;
		}
		shape.setFillColor(sf::Color(255, 255, 255, alpha));
	}
}

void Flash::draw()
{
	data->window.draw(shape);
}

