#pragma once

#include "Animation.h"

class PetAnimation : public Animation
{
public:
	PetAnimation(gameDataRef data, const std::string& textureFileName, float time, int numFrames, sf::Vector2f position);
	~PetAnimation() {}
	bool animation();
	void draw();
	void update();

private:

	sf::Sprite sprite;
	std::vector <sf::Texture> animationFrames;

	int animationIterator;
	int firstFrame;
	int lastFrame;
	int numFrames;
	float time;

	gameDataRef data;
	sf::Clock clock;
};

