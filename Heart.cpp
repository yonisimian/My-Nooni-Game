#include "Heart.h"
#include "Definitions.h"

//Constructor gets a data
Heart::Heart(gameDataRef data) : data(data)
{
	mood = "green mood";

	animation = new Animation(data, HEART, 7);
	//Creates actions for the heart
	animation->addAction("green mood", 0, 0, 0, false);
	animation->addAction("yellow mood", 1, 1, 0, false);
	animation->addAction("red mood", 2, 2, 0, false);
	animation->addAction("pink mood", 3, 6, 0.2f, false);

	animation->startAction("green mood");
}

//Gets a vector2f and sets the position of the heart according
void Heart::setPosition(sf::Vector2f position)
{
	animation->setPosition(position);
}

//Gets isSpinning and set heart's spinning according
void Heart::setIsSpinning(bool isSpinning)
{
	if (isSpinning)
	{
		if (animation->getCurrentAction() != "pink mood")
		{
			animation->startAction("pink mood");
		}
	}
	else
	{
		if (animation->getCurrentAction() == "pink mood")
		{
			animation->startAction(mood);
		}
	}
}

//Gets a color type and changes the heart according
void Heart::setColor(int color)
{
	if (color == greenMood)
	{
		mood = "green mood";
	}
	else if (color == yellowMood)
	{
		mood = "yellow mood";
	}
	else
	{
		mood = "red mood";
	}
	if (animation->getCurrentAction() != "pink mood")
	{
		animation->startAction(mood);
	}
}

//Updates heart's animation
void Heart::update()
{
	animation->animation();
}

//Draws heart
void Heart::draw()
{
	animation->draw();
}

//Restart clock
void Heart::restartClock()
{
	animation->restartClock();
}

//Destructor 
Heart::~Heart()
{
	delete animation;
}
