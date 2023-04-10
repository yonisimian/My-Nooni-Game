#include "GameStateEgg.h"
#include "GameStateAdult.h"

GameStateEgg::GameStateEgg(gameDataRef data, int type) : GameState(data)
{
	pet = new Pet(data, type);
}

void GameStateEgg::init()
{
	GameState::init();
}


void GameStateEgg::handleInput()
{
	sf::Event event;
	while (data->window.pollEvent(event))
	{
		GameState::handleInput(event);
	}
}

void GameStateEgg::update(float dt)
{
	if (clock.getElapsedTime().asSeconds() > 10.0f)
	{
		data->machine.addState(StateRef(new GameStateAdult(data, pet)), true);
	}
}

void GameStateEgg::draw(float dt)
{
	GameState::draw(dt);
	data->window.display();
}
