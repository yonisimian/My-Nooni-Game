#pragma once

#include "GameState.h"
#include "Game.h"
#include "SoundManage.h"
#include "Pam.h"
#include "Pet.h"
#include <vector>
#include <SFML/Graphics.hpp>

//A subclass of GameState - Speak class for teaching a pet how to talk
class SpeakState : public GameState
{
public:
	//Constructor
	SpeakState(gameDataRef data, SoundManage* sounds, EffectsControl* effects, Pet *pet, std::vector <bool> & blockedWords);
	//Destructor
	~SpeakState();
	//Init
	void init();
	//Draws
	void draw(float dt);
	//Handles input
	bool handleInput(sf::Event event);
	//Update
	void update(float dt);

private:
	//Make the pet say word
	void speak(int word);
	//Pet the pet
	void touchPet();
	//Stops current action
	void stopAction();
	//Game over
	void gameOver();
	//Remove this state
	void removeState();

	sf::Sprite background;

	std::vector <sf::Sprite> wordsButtons;
	std::vector <sf::Text> words;
	std::vector <bool>& blockedWords; //Tells if the word is blocked or not

	sf::Font font;

	float wordTime; //How long the word is taking to say
	bool isSpeaking;
	bool isLearning;
	int wordIndex; //Current word
	float startPetTime;

	const int WORD_BUTTON_DIS_HEIGHT = 60;
	const int WORD_BUTTON_DIS_WIDTH = 175;
};

