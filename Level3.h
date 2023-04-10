#pragma once

#include "Level2.h"
#include "Menu.h"

//A child class of Level2 - is the third level of the game
class Level3 : public Level2
{
public:
	//Constructor
	Level3(gameDataRef data, SoundManage* sounds, EffectsControl* effects, Pet* pet, std::vector <bool> blockedWords);
	//Destructor 
	~Level3();

protected:
	//Game over and the user is winning
	virtual void levelUp();

	const int GROWING_TIME = 600.0f;
};

