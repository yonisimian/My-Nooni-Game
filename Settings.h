#pragma once

#include <SFML/Audio.hpp>

class Settings
{
private:
	sf::SoundBuffer menuBuffer;
	sf::SoundBuffer clickBuffer;
	sf::SoundBuffer happyBuffer;

	sf::Sound menuSound;
	sf::Sound clickSound;
	sf::Sound happySound;

	int nextSound = 1;

public:
	Settings();
	void playClick();
	void playHappy();
};

