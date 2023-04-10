#include "NeedsControl.h"

NeedsControl::NeedsControl(gameDataRef data)
{
	controlAllNeeds = true;
	for (int i = 0; i < 11; i++)
	{
		data->assets.loadTexture("Need Scale " + std::to_string(i), "graphics/Needs/" + std::to_string(10 - i) + ".png");
	}
	for (int i = 0; i < 5; i++)
	{
		needs.push_back(new Need(data, i));
	}
}

void NeedsControl::grow()
{
	controlAllNeeds = true;
	for (int i = 1; i < needs.size(); i++)
	{
		needs.at(i)->restartClock();
	}
}

void NeedsControl::draw()
{
	if (!controlAllNeeds)
	{
		needs.at(0)->draw();
		return;
	}
	for (int i = 0; i < needs.size(); i++)
	{
		needs.at(i)->draw();
	}
}

void NeedsControl::update(float dt)
{
	if (!controlAllNeeds)
	{
		needs.at(0)->update(dt);
		return;
	}
	for (int i = 0; i < needs.size(); i++)
	{
		needs.at(i)->update(dt);
	}
}

void NeedsControl::handleInput()
{
	if (!controlAllNeeds)
	{
		needs.at(0)->handleInput();
		return;
	}
	for (int i = 0; i < needs.size(); i++)
	{
		needs.at(i)->handleInput();
	}
}

void NeedsControl::levelUp(int type, int amount)
{
	needs.at(type)->levelUp(amount);
}

int NeedsControl::getXp(int type)
{
	return needs.at(type)->getXp();
}

void NeedsControl::restartClock()
{
	for (int i = 0; i < needs.size(); i++)
	{
		needs.at(i)->restartClock();
	}
}


