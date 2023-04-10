#pragma once
#include "State.h"
#include "Game.h"
#include "SoundManage.h"
#include <SFML/Graphics.hpp>

class SettingsState : public State
{
public:
	SettingsState(gameDataRef data, SoundManage *sounds);
	void draw();
	void handleInput();

private:
	sf::Sprite background;
	sf::Sprite backButton;
	sf::Sprite musicPlus;
	sf::Sprite musicMinus;
	sf::Sprite actionsPlus;
	sf::Sprite actionsMinus;

	SoundManage* sounds;
};

