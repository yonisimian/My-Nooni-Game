#pragma once

#include "Game.h"
#include "Animation.h"
#include <SFML/Graphics.hpp>

//A class for the heart above the pet
class Heart
{
public:
	//Constructor
	Heart(gameDataRef data);
	//Destructor 
	~Heart() {}
	//Sets the position of the heart
	void setPosition(sf::Vector2f position);
	//Gets isSpinning and set heart's spinning according
	void setIsSpinning(bool isSpinning);
	//Changes the color of the heart
	void setColor(int color);
	//Updates heart's frames
	void update();
	//Draws heart
	void draw();
	//Restarts clock
	void restartClock();


private:
	Animation *animation;

	gameDataRef data;

	std::string mood; //Mood of the heart
};

