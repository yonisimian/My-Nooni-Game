#include "Need.h"
#include "Definitions.h"

//Constructor gets a data and a need type (being petted, hungry, sleep, clean and fun)
Need::Need(gameDataRef data, int needType) : data(data), needType(needType)
{
	//Sets the position of the need's icon
	int firstY = 230;
	int xIcon = 5, yIcon = NEED_ICON_SIZE * (needType + 1) + firstY;
	std::string typeName; //Name of need's type

	xp = 10;
	mood = greenMood;
	showScale = false;

	switch (needType)
	{
	case beingPet:
		typeName = "pet";
		scaleTime = 4.5f;
		break;
	case eat:
		typeName = "hungry";
		scaleTime = 4.0f;
		break;
	case sleep:
		typeName = "sleep";
		scaleTime = 6.0f;
		break;
	case takingBath:
		typeName = "clean";
		scaleTime = 5.0f;
		break;
	default : case play:
		typeName = "fun";
		scaleTime = 3.5f;
		break;
	}
	//Loads icon's image
	data->assets.loadTexture("Need Icon " + typeName, NEED_SCALE + typeName + ".png");
	SpriteIcon.setTexture(data->assets.getTexture("Need Icon " + typeName));
	SpriteIcon.setPosition(sf::Vector2f(xIcon, yIcon));

	//Loading scale's images
	for (int i = 0; i < NEED_SCALE_FRAMES; i++)
	{
		data->assets.loadTexture("Need Scale " + std::to_string(i), NEED_SCALE + std::to_string(NEED_SCALE_FRAMES - 1 - i) + ".png");
	}
	spriteScale.setTexture(data->assets.getTexture("Need Scale " + std::to_string(0)));
	spriteScale.setPosition(sf::Vector2f(xIcon + SpriteIcon.getLocalBounds().height - 2, yIcon + SpriteIcon.getLocalBounds().height / 2));

	//Set mood circle around icon
	ShapeIcon.setRadius(SpriteIcon.getLocalBounds().height / 2 + NEEDS_CIRCLE_DISTANCE);
	ShapeIcon.setFillColor(sf::Color::Green);
	ShapeIcon.setOutlineColor(sf::Color::White);
	ShapeIcon.setOutlineThickness(NEEDS_CIRCLE_DISTANCE);
	ShapeIcon.setPosition(sf::Vector2f(xIcon - NEEDS_CIRCLE_DISTANCE, yIcon - NEEDS_CIRCLE_DISTANCE));
}

//Gets the current mood of the need
int Need::getMood()
{
	return mood;
}

//draws need's sprites
void Need::draw()
{
	if (showScale)
	{
		data->window.draw(spriteScale);
	}
	data->window.draw(ShapeIcon);
	data->window.draw(SpriteIcon);
}

//Updates need by time
void Need::update(float dt)
{
	if (xp > 0)
	{
		float time = scaleTime;
		if (xp <= redMood) //If xp smaller than redMood - time is going faster
		{
			time /= 2.0f;
		}
		if (clock.getElapsedTime().asSeconds() >= time)
		{
			restartClock();
			updateScale(xp--);
		}
	}
}

//Updates the scale and ShapeIcon's color according to the new xp
void Need::updateScale(int oldXp)
{
	int placeXp= greenMood - xp;
	spriteScale.setTexture(data->assets.getTexture("Need Scale " + std::to_string(placeXp))); //Sets the new frame of the scale
	if (!xp)
	{
		if (oldXp > 0)
		{
			ShapeIcon.setFillColor(sf::Color::Black);
			mood = blackMood;
		}
	}
	else
	{
		if (xp <= redMood)
		{
			if (oldXp > redMood || !oldXp)
			{
				ShapeIcon.setFillColor(sf::Color::Red);
				mood = redMood;
			}
		}
		else if (xp <= yellowMood)
		{
			if (oldXp > yellowMood || oldXp <= redMood)
			{
				ShapeIcon.setFillColor(sf::Color::Yellow);
				mood = yellowMood;
			}
		}
		else if (oldXp <= yellowMood)
		{
			ShapeIcon.setFillColor(sf::Color::Green);
			mood = greenMood;
		}
	}
}

//Handles input
void Need::handleInput()
{
	//If the mouse touches SpriteIcon - shows scale
	if (!showScale && SpriteIcon.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(data->window).x, sf::Mouse::getPosition(data->window).y)))
	{
		showScale = true;
	}
	//If the mouse stops touching SpriteIcon - hides scale
	if(showScale && !SpriteIcon.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(data->window).x, sf::Mouse::getPosition(data->window).y)))
	{
		showScale = false;
	}
}

//Increases need's xp
void Need::levelUp(int amount)
{
	int oldXp = xp;
	if (xp + amount >= 10)
	{
		xp = 10;
	}
	else
	{
		xp += amount;
	}
	updateScale(oldXp); //Updates the scale and shapeIcon
}

//Restarts clock
void Need::restartClock()
{
	clock.restart();
}