#include "Pam.h"
#include <iostream>

//Constructor gets a data
Pam::Pam(gameDataRef data) : data(data)
{
	currentFrame = 0;
	isDone = false;

	//Loads font for the text
	if (!font.loadFromFile("fonts/retganon.ttf"))
	{
		std::cout << "couldn't open font!";
	}
	else
	{
		text.setFont(font);
		text.setCharacterSize(26);
		text.setLineSpacing(1.2);
		text.setFillColor(sf::Color{ 249, 85, 162, 255 }); //Color pink
	}
}

//Gets if speech is over
bool Pam::getIsDone()
{
	return isDone;
}

//Draws pam's background and text
void Pam::draw()
{
	data->window.draw(background);
	data->window.draw(text);
}

//Handles input
void Pam::handleInput(sf::Event event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		goNext(); //Go next frame
	}
}

//Goes to the next frame and is speech is over - sets isDone to be true
void Pam::goNext()
{
	if (++currentFrame < framesStrings.size())
	{
		text.setString(framesStrings.at(currentFrame));
	}
	else
	{
		isDone = true;
	}
}