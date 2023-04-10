#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.h"
#include "Animation.h"

//A class of all effects of the game
class EffectsControl
{
public:
	//Constructor
	EffectsControl(gameDataRef data);
	//Destructor
	~EffectsControl() {}
	//Draws the effects
	void draw();
	//Updates the effect animation
	void update();
	//Playes effect
	void startEffect(int effectNumber);
	//Sends if some effects is being played
	bool isEffect();
	//Stops the effect is being played
	void stopEffect();
	//Restarts clock
	void restartClock();

private:
	//Adds effects into effects
	void addEffects();
	
	int countAnimation = 0; //Counter of how many time effect is being animated
	int maxAnimation; //Max time of effect to being animated
	int currentEffect;

	std::vector<std::unique_ptr<Animation>> effects; //vector of effects

	gameDataRef data;
};

