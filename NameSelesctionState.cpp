#include "NameSelectionState.h"
#include "GameState.h"
#include <sstream>
#include <iostream>

NameSelectionState::NameSelectionState(gameDataRef data) : data(data)
{

}
void NameSelectionState::init()
{
	data->assets.loadTexture("Name Background", "graphics/Name/background.png");
	background.setTexture(data->assets.getTexture("Name Background"));
	data->assets.loadTexture("Back Button", "graphics/Name/back.png");
	backButton.setTexture(data->assets.getTexture("Back Button"));
	backButton.setPosition(sf::Vector2f(50, 400));
	sf::Font font;
	font.loadFromFile("fonts/Chewy.ttf");
	name.setFont(font);
	name.setString("cde ");
	name.setCharacterSize(24);
	name.setFillColor(sf::Color::White);
	name.setPosition(sf::Vector2f(200, 100));
	
}
void NameSelectionState::handleInput()
{
	sf::Event event;
	while (data->window.pollEvent(event))
	{
		/*if (event.type == sf::Event::TextEntered)
		{
			if (event.key.code == sf::Keyboard::Backspace && !text.empty())
			{
				text.erase(text.length() - 1);
			}
			else 
			{
				if (event.text.unicode < 128 && text.length() < 6)
				{
					text += static_cast<char>(event.text.unicode);
					name.setString(text);
				}
				if (event.key.code == sf::Keyboard::Enter && !text.empty())
				{
					data->machine.addState(StateRef(new GameState(data)), true);
				}

			}
			
		}
		if (data->input.isSpriteClicked(backButton, sf::Mouse::Left, data->window))
		{
			data->window.close();
		}*/
	}
}
void NameSelectionState::update(float dt)
{
}
void NameSelectionState::draw(float dt)
{
	data->window.clear();
	data->window.draw(background);
	data->window.draw(backButton);
	data->window.draw(name);
	data->window.display();
}
