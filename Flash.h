#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"


class Flash
{
public:
	Flash(gameDataRef data);

	void show(float dt);
	void draw();

private:
	gameDataRef data;
	sf::RectangleShape shape;
	bool isFlash;
};

