#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

class GameOverState : public State
{
public:
	GameOverState(gameDataRef data);
	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt);

private:
	sf::Sprite background;
	gameDataRef data;
};