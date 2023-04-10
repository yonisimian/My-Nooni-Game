#include "BigPam.h"
#include "Definitions.h"

//Constractor gets a data and the type of pam's speech
BigPam::BigPam(gameDataRef data, int type) : Pam(data)
{
	bool isHappy = true; //Is pam happy or sad
	double xAddition{ 70 }, yAddition{ 60 };

	data->assets.loadTexture("Pam Window", CANDY_WINDOW);
	background.setTexture(data->assets.getTexture("Pam Window"));
	background.setPosition(sf::Vector2f(data->window.getSize().x / 2 - background.getGlobalBounds().width / 2,
		data->window.getSize().y / 2 - background.getGlobalBounds().height / 2));

	if (type >= loose && type <= win)
	{
		setTitle(type, xAddition / 2, yAddition / 1.5); //Sets title for win and loose types
		yAddition += title.getGlobalBounds().height + 10;
		if (type == loose) //Pam is sad in case of loose type
		{
			isHappy = false;
		}
	}
	else
	{
		isTitle = false;
	}

	std::string pamString; //The file of pam's sprite
	if (isHappy)
	{
		pamString = HAPPY_PAM_WINDOW;
	}
	else
	{
		pamString = SAD_PAM_WINDOW;
	}
	data->assets.loadTexture("Pam", pamString);
	pamSprite.setTexture(data->assets.getTexture("Pam"));
	pamSprite.setPosition(sf::Vector2f(data->window.getSize().x / 2 - background.getGlobalBounds().width / 2,
		data->window.getSize().y / 2 - background.getGlobalBounds().height / 2));

	setFrames(type); //Sets the frames of pam's speech
	text.setString(framesStrings.at(currentFrame));
	text.setPosition(sf::Vector2f(background.getGlobalBounds().getPosition().x + xAddition,
		background.getGlobalBounds().getPosition().y + yAddition));
}

//Sets the frames of pam's speech according to the type
void BigPam::setFrames(int type)
{
	unsigned dataArraySize;
	switch (type)
	{
	case introduce:
		dataArraySize = sizeof(SELECT_PAM_ARRAY) / sizeof(std::string);
		copy(&SELECT_PAM_ARRAY[0], &SELECT_PAM_ARRAY[dataArraySize], back_inserter(framesStrings));
		break;
	case loose:
		dataArraySize = sizeof(LOOSE_PAM_ARRAY) / sizeof(std::string);
		copy(&LOOSE_PAM_ARRAY[0], &LOOSE_PAM_ARRAY[dataArraySize], back_inserter(framesStrings));
		break;
	default:
		dataArraySize = sizeof(WIN_PAM_ARRAY) / sizeof(std::string);
		copy(&WIN_PAM_ARRAY[0], &WIN_PAM_ARRAY[dataArraySize], back_inserter(framesStrings));
		break;
	}
}

//Sets the title in case the type of pam's speech is a Game Over
void BigPam::setTitle(int type, double xAddition, double yAddition)
{
	isTitle = true;
	std::string titleString; //The file of title's sprite
	if (type == loose)
	{
		titleString = LOOSE_TITLE;
	}
	else
	{
		titleString = WIN_TITLE;
		
	}
	data->assets.loadTexture("Pam Title", titleString);
	title.setTexture(data->assets.getTexture("Pam Title"));
	title.setPosition(sf::Vector2f(background.getGlobalBounds().getPosition().x + xAddition,
		background.getGlobalBounds().getPosition().y + yAddition));
}

//Draws pam and title if needed
void BigPam::draw()
{
	Pam::draw();
	data->window.draw(pamSprite);
	if (isTitle)
	{
		data->window.draw(title);
	}
}