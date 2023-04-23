#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.h"

//A class for the pet's need
class Need
{
public:
	//Constructor
	Need(gameDataRef data, int needType);
	//Destructor
	~Need() = default;
	//Gets the current mood of the need
	int getMood();
	//Draws
	void draw();
	//Updates the need
	void update(float dt);
	//Handles input
	void handleInput();
	//Increases need's xp
	void levelUp(int amount);
	//Restarts clock
	void restartClock();

private:	
	//Updates the scale's sprites
	void updateScale(int oldXp);

	sf::Clock clock;

	int xp;
	int mood;
	int needType;
	float scaleTime;
	bool showScale; //Is the scalse should be displayed

	gameDataRef data;

	sf::CircleShape ShapeIcon; //Circle represents need's mood

	sf::Sprite SpriteIcon;
	sf::Sprite spriteScale;
};
