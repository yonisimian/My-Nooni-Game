#include "SmallPam.h"
#include "Definitions.h"

//Constractor gets a data and the type of pam's speech
SmallPam::SmallPam(gameDataRef data, int type) : Pam(data)
{
	data->assets.loadTexture("Pam Window", SMALL_PAM_WINDOW);
	background.setTexture(data->assets.getTexture("Pam Window"));
	background.setPosition(sf::Vector2f(data->window.getSize().x / 2 - background.getGlobalBounds().width / 2,
		data->window.getSize().y / 2 - background.getGlobalBounds().height / 2));

	setFrames(type);

	text.setString(framesStrings.at(0));
	text.setPosition(sf::Vector2f(background.getGlobalBounds().getPosition().x + DIST_TEXT_BACKGROUND_X,
		background.getGlobalBounds().getPosition().y + DIST_TEXT_BACKGROUND_Y));
}

//Sets the frames of pam's speech according to the type
void SmallPam::setFrames(int type)
{
	unsigned dataArraySize;
	switch (type)
	{
	case eggExplanation:
		dataArraySize = sizeof(EGG_PAM_ARRAY) / sizeof(std::string);
		copy(&EGG_PAM_ARRAY[0], &EGG_PAM_ARRAY[dataArraySize], back_inserter(framesStrings));
		break;
	case babyExplanation:
		dataArraySize = sizeof(BABY_PAM_ARRAY) / sizeof(std::string);
		copy(&BABY_PAM_ARRAY[0], &BABY_PAM_ARRAY[dataArraySize], back_inserter(framesStrings));
		break;
	case adultExplanation:
		dataArraySize = sizeof(ADULT_PAM_ARRAY) / sizeof(std::string);
		copy(&ADULT_PAM_ARRAY[0], &ADULT_PAM_ARRAY[dataArraySize], back_inserter(framesStrings));
		break;
	default:
		dataArraySize = sizeof(SPEAK_PAM_ARRAY) / sizeof(std::string);
		copy(&SPEAK_PAM_ARRAY[0], &SPEAK_PAM_ARRAY[dataArraySize], back_inserter(framesStrings));
		break;
	}
}