#pragma once

#include "Need.h"
#include <vector>

class NeedsControl
{
public:
	NeedsControl(gameDataRef data);
	void grow();
	void draw();
	void update(float dt);
	void handleInput();
	void levelUp(int type, int amount);
	int getXp(int type);
	void restartClock();

private:
	std::vector <Need*> needs;
	bool controlAllNeeds;
	gameDataRef data;
};

