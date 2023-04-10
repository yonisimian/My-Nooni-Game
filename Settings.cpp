#include "Settings.h"

Settings::Settings()
{
	menuBuffer.loadFromFile("sounds/happy.mp3");
	clickBuffer.loadFromFile("sounds/select.wav");
	happyBuffer.loadFromFile("sounds/GoodFeelings.wav");

	menuSound.setBuffer(menuBuffer);
	clickSound.setBuffer(clickBuffer);
	happySound.setBuffer(happyBuffer);

	menuSound.setLoop(true);
	menuSound.play();
}

void Settings::playClick()
{
	clickSound.setRelativeToListener(true);
	clickSound.play();
}

void Settings::playHappy()
{
	happySound.setRelativeToListener(true);
	happySound.play();
}


