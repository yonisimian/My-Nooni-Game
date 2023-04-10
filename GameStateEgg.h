#pragma once

#include "GameState.h"

class GameStateEgg : public GameState
{
public:
	GameStateEgg(gameDataRef data, int type);
	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt);

private:
	sf::Clock clock;
};

