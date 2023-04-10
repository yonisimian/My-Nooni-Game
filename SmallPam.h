#pragma once

#include "Pam.h"

//A child class of Pam - is the small window showning pam's speech
class SmallPam : public Pam
{
public:
	//Constructor
	SmallPam(gameDataRef data, int type);
	//Destructor
	~SmallPam() { }

protected:
	//Sets the frames of pam's speech
	void setFrames(int type);

	//Distance between text and background's frame
	const int DIST_TEXT_BACKGROUND_X = 120;
	const int DIST_TEXT_BACKGROUND_Y = 100;
};

