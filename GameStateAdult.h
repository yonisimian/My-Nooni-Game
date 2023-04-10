#pragma once

#include "GameState.h"

class GameStateAdult : public GameState
{
public:
	GameStateAdult(gameDataRef data, Pet *pet);
	void init();
	void handleInput();
	void draw(float dt);

private:
	sf::Sprite apple;
	sf::Sprite sandwich;
	sf::Sprite ball;
	sf::Sprite bear;
};

