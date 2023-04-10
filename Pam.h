#pragma once

#include "Game.h"
#include <SFML/Graphics.hpp>

//A class for pam's speech
class Pam
{
public:
	//Constructor
	Pam(gameDataRef data);
	//Destructor
	~Pam() { }
	//Gets if speech is over
	bool getIsDone();
	//Draws
	virtual void draw();
	//Handles input
	void handleInput(sf::Event event);

protected:
	//Sets pam'S speech frames
	virtual void setFrames(int type) = 0;
	//Goes to the next frame
	void goNext();

	sf::Sprite background;
	sf::Font font;
	sf::Text text;

	std::vector <std::string> framesStrings; //Strings of pam's speech by frames

	int currentFrame;

	bool isDone; //If speech is over

	gameDataRef data;
};

