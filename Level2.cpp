#include "Level2.h"
#include "Level3.h"
#include "SpeakState.h"
#include "YardState.h"
#include "SmallPam.h"
#include "BigPam.h"
#include "ToysMenu.h"
#include "FoodMenu.h"
#include <iostream>

//Constructor gets a data, sounds, effects and a pet
Level2::Level2(gameDataRef data, SoundManage* sounds, EffectsControl *effects, Pet *pet) :
	LevelState(data, sounds, effects, pet)
{
	menus[0] = new FoodMenu(data, sounds, 2); //Creates a menu for baby's food
	menus[1] = new ToysMenu(data, sounds, 3); //Creates a menu for toys

	pam = new SmallPam(data, babyExplanation);

	//Adds locked words the pet doesn't learn yet into blockedWords
	for (int i = 0; i < WORDS_NUMBER; i++)
	{
		blockedWords.push_back(true);
	}
}

//Handles input
bool Level2::handleInput(sf::Event event)
{
	if (LevelState::handleInput(event))
	{
		return true;
	}
	if (!isPause)
	{
		if (actionType == intro)
		{
			pam->handleInput(event);
		}
		else
		{
			if (actionType == openRefrigerator || actionType == openBox)
			{
				menuChoice(); //Select from menu
			}
			else
			{
				if (actionType == stand)
				{
					int choice{};
					if ((choice = accessories->handleInput(event)) != -1)
					{
						useAccessorize(choice); //Use chosen accessory
					}
					else
					{
						if (data->input.isSpriteClicked(speakButton, sf::Mouse::Left, data->window))
						{
							sounds->playGameSound(mouseClickSound);
							actionType = GoOtherState;
							data->machine.addState(StateRef(new SpeakState(data, sounds, effects, pet, blockedWords)), false);
						}
						else
						{
							sf::Vector2i mousePosition = data->input.getMousePosition(data->window);
							if (data->input.isSpriteClicked(background, sf::Mouse::Left, data->window))
							{	
								if ((mousePosition.x >= TOYBOX_LEFT_X && mousePosition.x <= TOYBOX_RIGHT_X) &&
									(mousePosition.y >= TOYBOX_LEFT_Y && mousePosition.y <= TOYBOX_RIGHT_Y))
								{
									useAccessorize(AccessoryType::TOY_BOX);
								}
							}
						}

					}

				}
			}
		}
	}
	return true;
}

//Updates pam, effects, pet and checks if it's time for the egg to grow
void Level2::update(float dt)
{
	if (!isPause)
	{
		if (actionType == intro)
		{
			updatePam(); //Updates pam's speech
		}
		else
		{
			if (actionType != stand)
			{
				if (!effects->isEffect() && actionType >= eat && actionType <= growing) //If it's a pet's action stop it
				{
					stopAction();
				}
			}
			else
			{
				if (clock.getElapsedTime().asSeconds() + exactTime >= GROWING_TIME)
				{
					levelUp(); //Growing pet
				}
			}
			GameState::update(dt);
		}
	}
}

//Draws level
void Level2::draw(float dt)
{
	LevelState::draw(dt);
	if (actionType == openRefrigerator)
	{
		menus[0]->draw();
	}
	else if(actionType == openBox)
	{
		menus[1]->draw();
	}
	if (actionType == sleep)
	{
		data->window.draw(darkScreen);
	}
	effects->draw();	
	GameState::draw(dt);
}

//Start action of eating
void Level2::feed()
{
	pet->feed();
	accessories->setVisibleTable(); //Show table to eat on
	sounds->playActionSound(eatingSound);
	actionType = eat;
}

//Start action of sleeping
void Level2::goSleep()
{
	pet->setPosition(sf::Vector2f(310, 300));
	pet->goSleep();
	sounds->playActionSound(sleepingSound);
	effects->startEffect(sleepEffect);
	actionType = sleep;
	xp = 10;
}

//Start action of taking shower
void Level2::shower()
{
	pet->setPosition(sf::Vector2f(680, 248));
	pet->shower();
	sounds->playActionSound(showerSound);
	effects->startEffect(bathEffect);
	actionType = takingBath;
	xp = 10;
}

//Start Accessorize's action
void Level2::useAccessorize(AccessoryType accessorizeType)
{
	switch (static_cast<int>(accessorizeType))
	{
	case REFRIGERATOR:
		actionType = openRefrigerator;
		break;
	case BED:
		goSleep();
		break;
	case BATH:
		shower();
		break;
	case TOY_BOX:
		actionType = openBox;
		break;
	default:
		break;
	}
}

//Stops current action
void Level2::stopAction()
{
	pet->stopAction(xp);
	sounds->stop();
	if (actionType == growing)
	{
		data->machine.addState(StateRef(new Level3(data, sounds, effects, pet, blockedWords)), true);
	}
	else
	{
		if (actionType == sleep || actionType == takingBath)
		{
			pet->setPosition(pet->getMainPosition()); //Returns pet to it's main position
			if (actionType == sleep)
			{
				accessories->stopUse();
			}
		}
		else if (actionType == eat)
		{
			accessories->setVisibleTable();
		}
		actionType = stand;
		xp = 0;
	}
}

//Checks if user selected from menu
void Level2::menuChoice()
{
	int choice{};
	if (actionType == openRefrigerator)
	{
		choice = menus[0]->handleInput();
	}
	else
	{
		choice = menus[1]->handleInput();
	}
	if (choice > -1)
	{
		if (choice == EXIT_MENU)
		{
			actionType = stand;
		}
		else
		{
			if (actionType == openRefrigerator)
			{
				effects->startEffect(choice + milkEffect);
				xp = ((FoodMenu *)menus[0])->getFoodXp(choice * 2); //Gets xp of chosen food
				feed();
			}
			else
			{
				actionType = GoOtherState;
				data->machine.addState(StateRef(new YardState(data, sounds, effects, pet, choice)), false);
			}
		}
		accessories->stopUse();
	}
}

//Level up the pet
void Level2::levelUp()
{
	actionType = growing;
	sounds->playActionSound(growingSound);
	pet->grow();
	effects->startEffect(growingBabyEffect);
}

//Destructor
Level2::~Level2()
{
	delete pam;
	for (int i = 0; i < 2; i++)
	{
		delete menus[i];
	}
	delete[] menus;
}
