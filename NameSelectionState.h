#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

class NameSelectionState : public State
{
public:
	NameSelectionState(gameDataRef data);
	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt);

private:
	sf::Sprite background;
	std::string text;
	sf::Text name;
	sf::Sprite backButton;
	gameDataRef data;
};

