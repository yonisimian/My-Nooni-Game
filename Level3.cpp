#include "Level3.h"
#include "YardState.h"
#include "SpeakState.h"
#include "BigPam.h"
#include "SmallPam.h"
#include "ToysMenu.h"
#include "FoodMenu.h"

//Constructor gets a data, sounds, effects, a pet, vector of words and the type of the room
Level3::Level3(gameDataRef data, SoundManage* sounds, EffectsControl* effects, Pet* pet, std::vector <bool> blockedWords) : Level2(data, sounds, effects, pet)
{
	pam = new SmallPam(data, adultExplanation);
	
	menus[0] = new FoodMenu(data, sounds, 6); //Creates a menu for adult's food
	menus[1] = new ToysMenu(data, sounds, 3); //Creates a menu for toys

	this->blockedWords = blockedWords;
	//Adds locked words the pet doesn't learn yet into blockedWords
	for (int i = 0; i < WORDS_NUMBER; i++)
	{
		this->blockedWords.push_back(true);
	}
}

//Game over and the user is winning
void Level3::levelUp()
{
	delete pam;
	pam = new BigPam(data, win);
	actionType = intro;
	Game::gameOver();
}

//Destructor 
Level3::~Level3()
{
	delete pet;
	delete pam;
	for (int i = 0; i < 2; i++)
	{
		delete menus[i];
	}
	delete[] menus;
}