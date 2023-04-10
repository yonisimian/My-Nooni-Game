#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Pet.h"
#include "SoundManage.h"
#include "EffectsControl.h"
#include "Pam.h"
#include <vector>

//A child class of State - a state for the game
class GameState : public State
{
public:
	//Constructor
	GameState(gameDataRef data, SoundManage* sounds, EffectsControl* effects, Pet* pet);
	//Destructor
	~GameState() { }
	//Init method
	void init();
	//Handles input
	bool handleInput(sf::Event event);
	//Pauses the game
	void pause();
	//Resumes the game
	void resume();
	//Draws game buttons
	void draw(float dt);
	//Updates the game
	void update(float dt);
	//Restart clock
	void restartClock();

protected:	
	//Removes the state
	virtual void removeState();
	//Starts an action after touching pet
	virtual void touchPet() = 0;
	//Game over
	virtual void gameOver();
	//Checks pet's mood
	void petMood();
	//Updates pam
	void updatePam();

	sf::Sprite pauseButton;
	sf::Sprite backButton;
	sf::Sprite playButton;
	sf::Sprite darkScreen;

	sf::Clock clock;

	Pet* pet;
	EffectsControl* effects = NULL;
	Pam* pam = NULL;

	gameDataRef data;
	SoundManage* sounds;

	bool isPause;
	int moodNumber; //Pet's mood
	int actionType = intro;
	
	double exactTime; //
};

