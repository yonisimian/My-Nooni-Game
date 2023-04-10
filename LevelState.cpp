#include "LevelState.h"
#include <iostream>

//Constructor gets a data, sounds, effects and a pet
LevelState::LevelState(gameDataRef data, SoundManage* sounds, EffectsControl *effects, Pet *pet) : 
	GameState(data, sounds, effects, pet)
{
	xp = 0;
	moodNumber = greenMood;
	accessories = new Accessorizes(data);
}

//Init
void LevelState::init()
{
	GameState::init();
	data->assets.loadTexture("Room Title", ROOM_TITLE + std::to_string(pet->getType()) + ".png");
	roomTitle.setTexture(data->assets.getTexture("Room Title"));
	roomTitle.setPosition(sf::Vector2f(data->window.getSize().x / 2 - roomTitle.getGlobalBounds().width / 2, 25));
	data->assets.loadTexture("Room Background", ROOM_BACKGROUND);
	background.setTexture(data->assets.getTexture("Room Background"));
	data->assets.loadTexture("Speak Button", SPEAK_BUTTON);
	speakButton.setTexture(data->assets.getTexture("Speak Button"));
	speakButton.setPosition(sf::Vector2f(80, 10));
}

//Handles input if pet is being petted or not
bool LevelState::handleInput(sf::Event event)
{
	if (GameState::handleInput(event))
	{
		return true;
	}
	if (!isPause && pet->handleInput(event) && actionType == stand)
	{
		touchPet();
		return true;
	}
	else
	{
		if (actionType == beingPet && (event.type == sf::Event::MouseButtonReleased))
		{
			stopAction();
			return true;
		}
	}
	return false;
}

//Draws the level
void LevelState::draw(float dt)
{
	data->window.draw(background);
	data->window.draw(roomTitle);
	data->window.draw(speakButton);
	accessories->draw();
	pet->draw();
	accessories->drawTable();
}

//Starts an action
void LevelState::touchPet()
{
	pet->beingPetted();
	sounds->playActionSound(pettingSound);
	actionType = beingPet;
	effects->startEffect(beingPettedEffect);
	startPetTime = clock.getElapsedTime().asSeconds();		
}

//Stops current action
void LevelState::stopAction()
{
	if (actionType == beingPet)
	{
		pet->stopAction((clock.getElapsedTime().asSeconds() + exactTime - startPetTime) * 2);
		effects->stopEffect();
		actionType = stand;
	}
	sounds->stop();
}

//Destructor
LevelState::~LevelState()
{
	delete pet;
	delete effects;
	delete accessories;
}