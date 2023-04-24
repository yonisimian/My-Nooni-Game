#pragma once

#include "LevelState.h"
#include "Menu.h"

//A child class of LevelState - is the second level of the game
class Level2 : public LevelState
{
public:
	//Constructor
	Level2(gameDataRef data, SoundManage* sounds, EffectsControl*effects, Pet *pet);
	//Destructor
	~Level2();
	//Handles input
	bool handleInput(sf::Event event);
	//Updates the level
	void update(float dt);
	//Draws
	void draw(float dt);
	
protected:
	//Start action of eating
	void feed();
	//Start action of sleeping
	void goSleep();
	//Start action of taking shower
	void shower();
	//Start Accessorize's action
	void useAccessorize(AccessoryType accessorizeType);
	//Stops current action
	void stopAction();
	//Choose from the menu
	virtual void menuChoice();
	//Level up the pet
	virtual void levelUp();

	Menu** menus = new Menu * [2]; //Array of two menus

	std::vector <bool> blockedWords; //Vector of the blocked words the pet doesn't know yet

	const int GROWING_TIME = 300.0f;
	const int WORDS_NUMBER = 6; //Number of words the pet can learn
};
