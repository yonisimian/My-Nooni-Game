#include "Level1.h"
#include "Level2.h"
#include "SmallPam.h"
#include "BigPam.h"

//Constructor gets a data, sounds and the type of the pet
Level1::Level1(gameDataRef data, SoundManage* sounds, int type) : LevelState(data, sounds, new EffectsControl(data), new Pet(data,type))
{
	pam = new SmallPam(data, eggExplanation);
	pet->setPosition(sf::Vector2f(data->window.getSize().x / 2 - EGG_WIDTH / 2, EGG_Y_POSTION));
}

//Handles input
bool Level1::handleInput(sf::Event event)
{
	if (!LevelState::handleInput(event))
	{
		if (!isPause)
		{
			if (actionType == intro)
			{
				pam->handleInput(event);
			}
		}
	}
	return true;
}

//Updates pam, effects and checks if it's time for the egg to grow
void Level1::update(float dt)
{
	if (!isPause)
	{
		if (actionType == intro)
		{
			updatePam(); //Updates pam's speech
		}
		else
		{
			if (pet->getActionType() == stand)
			{
				if (clock.getElapsedTime().asSeconds() + exactTime > GROWING_TIME)
				{
					levelUp(); //Growing pet
				}
			}
			else
			{
				if(actionType == growing && !effects->isEffect())
				{
					stopAction();
				}
			}
			GameState::update(dt);
		}
	}
}

//Draws level
void Level1::draw(float dt)
{
	LevelState::draw(dt);
	effects->draw();
	GameState::draw(dt);
}

//Level up the pet
void Level1::levelUp()
{
	actionType = growing;
	sounds->playActionSound(growingSound);
	pet->grow();
	effects->startEffect(growingEggEffect);
}

//Stops current action
void Level1::stopAction()
{
	sounds->stop();
	if (actionType == growing)
	{
		actionType = stand;
		pet->stopAction(0);
		data->machine.addState(StateRef(new Level2(data, sounds, effects, pet)), true); //Goes to Level2
	}
}

//Destructor
Level1::~Level1()
{
	delete pam;
}