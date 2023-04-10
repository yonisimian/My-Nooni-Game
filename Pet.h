#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.h"
#include "Need.h"
#include "Heart.h"
#include "Animation.h"

//A class for pet
class Pet
{
public:
	//Constructor
	Pet(gameDataRef data, int type);
	//Destructor
	~Pet();
	//Gets pet's type
	int getType();
	//Gets current action type
	int getActionType();
	//Gets the main position of the pet
	sf::Vector2f getMainPosition();
	//Updates
	void update(float dt);
	//Draws
	void draw();
	//Handles input
	bool handleInput(sf::Event event);
	//Start action of being petted
	void beingPetted();
	//Start action of eating, can be only in baby/adult age
	void feed();
	//Start action of sleeping, can be only in baby/adult age
	void goSleep();
	//Start action of taking shower, can be only in baby/adult age
	void shower();	
	//Start action of playing, can be only in baby/adult age
	void startPlay();
	//Start action of growing, can be only in egg/baby age
	void grow();
	//Start action of talking, can be only in baby/adult age
	void startTalk();
	//Gets xp, increases the used need and stops current action
	void stopAction(int xp);
	//Restarts clock
	void restartClock();
	//Sets pet's position
	void setPosition(sf::Vector2f postion);
	//Updates current pet's mood and returns it
	int mood();

private:
	//Sets the pet's animation by different actions
	void setAnimation();

	gameDataRef data;

	Animation *animation;
	std::vector <Need*> needs; //Pet's needs
	Heart *heart; 

	sf::Vector2f mainPosition;

	int type;
	int actionType; //Current pet's action type
	std::string age;
	int needsNumber;
	int moodNumber;
};

