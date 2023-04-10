#include "Pet.h"
#include <iostream>

//Constructor gets a data, sounds and animal type and creates the pet according
Pet::Pet(gameDataRef data, int type) : data(data), type(type)
{
	actionType = stand;
	age = "egg";
	moodNumber = greenMood;
	needsNumber = 1;

	std::string animalFile{}; //String of the folder name of the chosen pet
	switch (type)
	{
	case Angel:
		animalFile = ANGEL;
		break;
	case Coco:
		animalFile = COCO;
		break;
	case Fifi:
		animalFile = FIFI;
		break;
	default: case Boo:
		animalFile = BOO;
		break;
	}

	animation = new Animation(data, animalFile, 29); //Sets animation
	setAnimation();

	heart = new Heart(data);

	//Sets pet's needs
	for (int i = 0; i < MAX_NEEDS; i++)
	{
		needs.push_back(new Need(data, i));
	}
	
}

//Sets the pet's animation by different actions
void Pet::setAnimation()
{
	//Pet's regular mood
	animation->addAction("egg", 0, 0, 0, false);
	animation->addAction("baby", 1, 2, 1.2f, false);
	animation->addAction("adult", 3, 4, 1.2f, false);
	//Changes the time of the blinking frame
	animation->changeFrameTime("baby", 2, 0.2f);
	animation->changeFrameTime("adult", 4, 0.2f);
	//Pet is being petted
	animation->addAction("baby_pet", 15, 16, 0.2f, false);
	animation->addAction("adult_pet", 9, 10, 0.2f, false);
	//Pet is taking shower
	animation->addAction("baby_shower", 5, 5,0, false);
	animation->addAction("adult_shower", 6, 6, 0, false);
	//Pet is playing
	animation->addAction("baby_play", 13, 18, 0.1f, false);
	animation->addAction("adult_play", 7, 12, 0.1f, false);
	//Pet is eating
	animation->addAction("baby_eat", 16, 17, 0.5f, false);
	animation->addAction("adult_eat", 10, 11, 0.5f, false);
	//Pet is talking
	animation->addAction("baby_talk", 24, 28, 0.2, false);
	animation->addAction("adult_talk", 19, 23, 0.2, false);

	animation->startAction("egg");
}

//Gets pet's type
int Pet::getType()
{
	return type;
}

//Gets current action
int Pet::getActionType()
{
	return actionType;
}

//Gets the main position of the pet
sf::Vector2f Pet::getMainPosition()
{
	return mainPosition;
}

//Updates animation, needs and heart
void Pet::update(float dt)
{
	if (actionType != growing)
	{
		for (int i = 0; i < needsNumber; i++)
		{
			if (actionType != i)
			{
				needs.at(i)->update(dt);
			}
		}
		animation->animation();
	}
	heart->update();
}

//Draws
void Pet::draw()
{
	if (actionType != sleep)
	{
		animation->draw();
	}
	heart->draw();
	for (int i = 0; i < needsNumber; i++)
	{
		needs.at(i)->draw();
	}
}

//Handles input, return true if pet is being touched, else false
bool Pet::handleInput(sf::Event event)
{
	for (int i = 0; i < needsNumber; i++)
	{
		needs.at(i)->handleInput();
	}
	return animation->handleInput(event);
}

//Start action of being petted
void Pet::beingPetted()
{
	actionType = beingPet;
	heart->setIsSpinning(true);
	if (age != "egg")
	{
		animation->startAction(age + "_pet");
	}
}

//Start action of eating, can be only in baby/adult age
void Pet::feed()
{
	if (age != "egg")
	{
		animation->startAction(age + "_eat");
		actionType = eat;
		heart->setIsSpinning(true);
	}
}

//Start action of sleeping, can be only in baby/adult age
void Pet::goSleep()
{
	if (age != "egg")
	{
		actionType = sleep;
		heart->setIsSpinning(true);
	}
}

//Start action of taking shower, can be only in baby/adult age
void Pet::shower()
{
	if (age != "egg")
	{
		animation->startAction(age + "_shower");
		actionType = takingBath;
		heart->setIsSpinning(true);
	}
}

//Start action of playing, can be only in baby/adult age
void Pet::startPlay()
{
	if (age != "egg")
	{
		animation->startAction(age + "_play");
		actionType = play;
		heart->setIsSpinning(true);
	}
}

//Start action of growing, can be only in egg/baby age
void Pet::grow()
{
	if (age != "adult")
	{
		animation->setColor(sf::Color::Black);
		actionType = growing;
		heart->setIsSpinning(true);
		if (age == "egg")
		{
			needsNumber = needs.size();
			age = "baby";
		}
		else
		{
			age = "adult";
		}
	}
}

//Start action of talking, can be only in baby/adult age
void Pet::startTalk()
{
	if (age != "egg")
	{
		animation->startAction(age + "_talk");
		actionType = talk;
		heart->setIsSpinning(true);
	}
}

//Gets xp, increases the used need and stops current action
void Pet::stopAction(int xp)
{
	if (actionType != stand)
	{
		if (age != "egg")
		{
			if (actionType != sleep)
			{
				animation->startAction(age); //Sets action to standing action
				if (actionType == growing)
				{
					animation->setColor(sf::Color::White);
					mainPosition = sf::Vector2f(data->window.getSize().x / 2 - animation->getSpriteWidth() / 2,
						EGG_Y_POSTION - (animation->getSpriteHeigth() - EGG_HEIGHT)); //Changes the main position according to new size
					setPosition(mainPosition);
					restartClock();
				}
			}
		}
		if (actionType >= beingPet && actionType <= play)
		{
			needs.at(actionType)->levelUp(xp); //Increases xp
			needs.at(actionType)->restartClock();
		}
		heart->setIsSpinning(false);
		actionType = stand;
	}
}

//Restarts clock
void Pet::restartClock()
{
	animation->restartClock();
	for (int i = 0; i < needsNumber; i++)
	{
		needs.at(i)->restartClock();
	}
	heart->restartClock();
}

//Sets pet's position
void Pet::setPosition(sf::Vector2f postion)
{
	animation->setPosition(postion);
	heart->setPosition(sf::Vector2f(animation->getSpriteWidth() / 2 + postion.x - HEART_WIDTH / 2, postion.y - (HEART_DIST_PET + HEART_WIDTH)));
}

//Updates current pet's mood and returns it
int Pet::mood()
{
	int lowest = greenMood, countBlackMood = 0, xp{};
	for (int i = 0; i < needsNumber ; i++)
	{
		if ((xp = needs.at(i)->getMood()) <= lowest)
		{
			if (!xp)
			{
				countBlackMood++;
			}
			if (xp != lowest)
			{
				lowest = xp;
			}
		}
	}
	if (countBlackMood == needsNumber)
	{
		moodNumber = -1;
	}
	else
	{
		if (lowest != moodNumber)
		{
			moodNumber = lowest;
		}
	}
	heart->setColor(moodNumber);
	return moodNumber;
}

//Destructor
Pet::~Pet()
{ 
	delete heart; 
	delete animation;
	needs.clear(); 
}
