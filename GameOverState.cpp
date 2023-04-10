#include "GameOverState.h"
#include <sstream>

GameOverState::GameOverState(gameDataRef data) : data(data)
{

}
void GameOverState::init()
{
	data->assets.loadTexture("Game Background", "graphics/Game/background.png");
	background.setTexture(data->assets.getTexture("Game Background"));
}
void GameOverState::handleInput()
{
	sf::Event event;
	while (data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			data->window.close();
		}
	}
}

void GameOverState::update(float dt)
{
}

void GameOverState::draw(float dt)
{
	data->window.clear();
	data->window.draw(background);
	data->window.display();
}
