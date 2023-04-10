#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>

class Accessories
{
public:
	Accessories(gameDataRef data);
	void init();
	void draw();
	void handleInput(sf::Event event);
	void levelUp();

private:
	std::vector <sf::Sprite> acceessories;

	gameDataRef data;
	bool isWorking;
};

