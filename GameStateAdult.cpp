#include "GameStateAdult.h"

GameStateAdult::GameStateAdult(gameDataRef data, Pet* pet) : GameState(data)
{	
	this->pet = pet;
}

void GameStateAdult::init()
{
	GameState::init();
	data->assets.loadTexture("Bottle", "graphics/Accessories/Baby/bottle.png");
	data->assets.loadTexture("apple", "graphics/Accessories/apple.png");
	apple.setTexture(data->assets.getTexture("apple"));
	apple.setPosition(sf::Vector2f(150, 200));
	data->assets.loadTexture("sandwich", "graphics/Accessories/sandwich.png");
	sandwich.setTexture(data->assets.getTexture("sandwich"));
	sandwich.setPosition(sf::Vector2f(200, 200));
	data->assets.loadTexture("ball", "graphics/Accessories/ball.png");
	ball.setTexture(data->assets.getTexture("ball"));
	ball.setPosition(sf::Vector2f(500, 200));
	data->assets.loadTexture("bear", "graphics/Accessories/bear.png");
	bear.setTexture(data->assets.getTexture("bear"));
	bear.setPosition(sf::Vector2f(550, 200));
}


void GameStateAdult::handleInput()
{
	sf::Event event;
	while (data->window.pollEvent(event))
	{
		GameState::handleInput(event);
		if (!isPause && pet->getActionType() == 0)
		{
			if (data->input.isSpriteClicked(apple, sf::Mouse::Left, data->window))
			{
				pet->startAction(2);
			}
			if (data->input.isSpriteClicked(sandwich, sf::Mouse::Left, data->window))
			{
				pet->startAction(3);
			}
			if (data->input.isSpriteClicked(ball, sf::Mouse::Left, data->window))
			{
				pet->startAction(4);
			}
			if (data->input.isSpriteClicked(bear, sf::Mouse::Left, data->window))
			{
				pet->startAction(5);
			}
		}
	}
}

void GameStateAdult::draw(float dt)
{
	GameState::draw(dt);
	data->window.draw(apple);
	data->window.draw(sandwich);
	data->window.draw(ball);
	data->window.draw(bear);
}
