#include "EffectsControl.h"
#include <iostream>
#include "Definitions.h"

//Constructor gets a data
EffectsControl::EffectsControl(gameDataRef data) : currentEffect(NO_EFFECT), data(data)
{
	addEffects();
}

//Adds effects into effects
void EffectsControl::addEffects()
{
	//Sleep effect
	effects.push_back(std::make_unique <Animation>(data, SLEEP_ANIMATION, 23, sf::Vector2f(220, 230)));
	//Bath effect
	effects.push_back(std::make_unique <Animation>(data, BATH_ANIMATION, 26, sf::Vector2f(650, 295)));
	//Food effects
	effects.push_back(std::make_unique <Animation>(data, MILK_ANIMATION, 4, sf::Vector2f(410, 500)));
	effects.push_back(std::make_unique <Animation>(data, STRAWBERRY_ANIMATION, 4, sf::Vector2f(410, 500)));
	effects.push_back(std::make_unique <Animation>(data, SALAD_ANIMATION, 4, sf::Vector2f(410, 500)));
	effects.push_back(std::make_unique <Animation>(data, BURGER_ANIMATION, 4, sf::Vector2f(410, 500)));
	effects.push_back(std::make_unique <Animation>(data, PIZZA_ANIMATION, 4, sf::Vector2f(410, 500)));
	effects.push_back(std::make_unique <Animation>(data, CHOCOLATE_ANIMATION, 4, sf::Vector2f(410, 500)));
	//Games effects
	effects.push_back(std::make_unique <Animation>(data, BALL_ANIMATION, 10, sf::Vector2f(0, 0)));
	effects.push_back(std::make_unique <Animation>(data, CAR_ANIMATION, 10, sf::Vector2f(0, 0)));
	//Being pet effect
	effects.push_back(std::make_unique <Animation>(data, BEING_PET_ANIMATION, 8, sf::Vector2f(data->window.getSize().x / 2 - 192 / 2, 400)));
	//Growing pet effect
	effects.push_back(std::make_unique <Animation>(data, EGG_GROWING_ANIMATION, 10, sf::Vector2f(data->window.getSize().x / 2 - 96, 370)));
	effects.push_back(std::make_unique <Animation>(data, BABY_GROWING_ANIMATION, 10, sf::Vector2f(data->window.getSize().x / 2 - 96, 370)));

	//Addings actions
	effects.at(sleepEffect)->addAction("effect", 0, 22, 0.04, false);
	effects.at(bathEffect)->addAction("effect", 0, 25, 0.09, false);

	for (int i = milkEffect; i <= chocolateEffect; i++)
	{
		effects.at(i)->addAction("effect", 0, 3, 2.0f, false);
	}

	for (int i = ballEffect; i <= carEffect; i++)
	{
		effects.at(i)->addAction("effect", 0, 9, 0.05f, true);
	}

	effects.at(beingPettedEffect)->addAction("effect", 0, 7, 0.09f, false);

	for (int i = growingEggEffect; i <= growingBabyEffect; i++)
	{
		effects.at(i)->addAction("effect", 0, 9, 0.2f, false);
	}
}

//Draws current effect
void EffectsControl::draw()
{
	if (currentEffect > NO_EFFECT)
	{
		effects.at(currentEffect)->draw();
	}
}

//Updates current effect frames
void EffectsControl::update()
{
	if (currentEffect > NO_EFFECT)
	{
		if(effects.at(currentEffect)->animation() && currentEffect != beingPettedEffect)
		{
			countAnimation++;
			if (countAnimation == maxAnimation) //If current effect is animated maxAnimation times - stop effect
			{
				currentEffect = NO_EFFECT;
			}
		}
	}
}

//Playes effect
void EffectsControl::startEffect(int effectNumber)
{
	if (effectNumber >= sleepEffect && effectNumber < effects.size())
	{
		currentEffect = effectNumber;
		//Changes maxAnimation accordding to type of the effect
		if (effectNumber == sleepEffect)
		{
			maxAnimation = 5;
		}
		else
		{
			if (effectNumber == bathEffect)
			{
				maxAnimation = 2;
			}
			else
			{
				maxAnimation = 1;
			}
		}
		effects.at(currentEffect)->startAction("effect");
		countAnimation = 0;
	}
}

//Sends if effects is being played
bool EffectsControl::isEffect()
{
	return (currentEffect > NO_EFFECT);
}

//Stops current effect
void EffectsControl::stopEffect()
{
	if (currentEffect > NO_EFFECT)
	{
		currentEffect = NO_EFFECT;
	}
}

//Restarts clock of current effect
void EffectsControl::restartClock()
{
	if (currentEffect > NO_EFFECT)
	{
		effects.at(currentEffect)->restartClock();
	}
}
