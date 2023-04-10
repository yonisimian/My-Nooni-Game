#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "SoundManage.h"

class AccessoriesWindow : public State
{
public:
	AccessoriesWindow(gameDataRef data, SoundManage *sounds, int type);
	void init();
	void handleInput(sf::Event event);
	void update(float dt);
	void draw(float dt);

private:
	sf::Sprite backButton;
	sf::Sprite background;
	std::vector <sf::Sprite> objects;

	std::vector <sf::Texture> toyTextures;
	std::vector <sf::Texture> babyFoodTextures;
	std::vector <sf::Texture> grownFoodTextures;

	int windowType;

	gameDataRef data;
	SoundManage *sounds;
};

