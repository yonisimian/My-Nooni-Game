#pragma once

#include "SpeakState.h"

class LearnWordsState : public State
{
public:
	LearnWordsState(gameDataRef data, SoundManage* sounds);
	~LearnWordsState() {}
	void init();
	void draw();
	void handleInput(sf::Event event);
	void learn();

private:
	sf::Sprite background;
	sf::Sprite emptyTitle;
	sf::Sprite backButton;
	sf::Sprite wordButton;

	SpeakState* speakState;

	int word;

	gameDataRef data;
	SoundManage* sounds;
};

