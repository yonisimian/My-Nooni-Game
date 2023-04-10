#pragma once

#include "LevelState.h"

//A child class of LevelState - is the first level of the game
class Level1 : public LevelState
{
public:
	//Constructor
	Level1(gameDataRef data, SoundManage* sounds, int type);
	//Destructor 
	~Level1();
	//Handles input
	bool handleInput(sf::Event event);
	//Updates the level
	void update(float dt);
	//Draws
	void draw(float dt);

protected:
	//Stops current action
	void stopAction();
	//Level up the pet
	void levelUp();

	const int GROWING_TIME = 60.0f;
};


