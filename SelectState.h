#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "BigPam.h"
#include "SoundManage.h"
#include <vector>
#include "Definitions.h"

//A child class of State - for user to select an egg
class SelectState : public State
{
public:
	//Constructor
	SelectState(gameDataRef data, SoundManage* sounds);
	//Destructor
	~SelectState();
	//Init
	void init();
	//Handles input
	bool handleInput(sf::Event event);
	//Updates
	void update(float dt);
	//Draws
	void draw(float dt);

private:
	sf::Sprite background;
	sf::Sprite windowSprite;

	sf::Sprite backButton;
	sf::Sprite effect; //Effect of mouse touches an egg

	sf::Font font;
	sf::Text text[4]; //Array of eggs' names

	sf::Sprite animalButtons[NUMBER_EGG];

	gameDataRef data;
	SoundManage* sounds;
	BigPam* pam;

	bool isInstruction;
	bool isEffect;
	int effectTouch; //Which egg has the effect

	const int DIST_EGG_WIDTH = 190;
	const int DIST_EGG_HEIGHT = 140;
};

