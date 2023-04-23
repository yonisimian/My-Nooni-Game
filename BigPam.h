#pragma once

#include "Pam.h"

//A child class of Pam - is the big window showning pam's speech
class BigPam : public Pam
{
public:
	//Constructor
	BigPam(gameDataRef data, int type);
	//Destructor
	~BigPam() = default;
	//Draws the window with pam
	void draw();

protected:
	//Sets the frames of pam's speech
	void setFrames(int type);
	//Add a title if needed
	void setTitle(int type, double xAddition, double yAddition);

	sf::Sprite pamSprite; 
	sf::Sprite title;
	
	bool isTitle; //If there is a title
};

