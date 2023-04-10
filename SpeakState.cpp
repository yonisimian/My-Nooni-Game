#include "SpeakState.h"
#include "SmallPam.h"
#include "BigPam.h"
#include <iostream>

//Constructor gets a data, sounds, a pet and a vector says which word is blocked by the index of it
SpeakState::SpeakState(gameDataRef data, SoundManage* sounds, EffectsControl* effects, Pet *pet, std::vector <bool>& blockedWords) :
	GameState(data, sounds, effects, pet), blockedWords(blockedWords)
{
	isSpeaking = isLearning = false;
	wordIndex = 0;
	startPetTime = 0;
	sounds->switchBackground(LearningSound);
	//Checks if at least one of the words isn't blocked and if so - changes actionType to be stand
	for (int i = 0; i < blockedWords.size(); i++)
	{
		if (!blockedWords.at(i))
		{
			actionType = stand;
			break;
		}
	}
	if (actionType == intro)
	{
		pam = new SmallPam(data, speakExplanation);
	}
}

//Init
void SpeakState::init()
{
	GameState::init();
	data->assets.loadTexture("Speak Background", CLASS_BACKGROUND);
	background.setTexture(data->assets.getTexture("Speak Background"));
	data->assets.loadTexture("Locked Word", LOCKED_WORD);
	data->assets.loadTexture("Unlocked Word", UNLOCKED_WORD);
	data->assets.loadTexture("Learn Word", LEARNING_WORD);

	//Loads font
	if (!font.loadFromFile("fonts/retganon.ttf"))
	{
		std::cout << "couldn't open font!";
	}

	int x = 190, startsY = 100,  y = startsY;
	//Position words' buttons
	for (int i = 0; i < blockedWords.size(); i++)
	{
		wordsButtons.push_back(sf::Sprite());
		wordsButtons.at(i).setPosition(sf::Vector2f(x, y));		
		if (blockedWords.at(i))
		{
			wordsButtons.back().setTexture(data->assets.getTexture("Locked Word"));
		}
		else
		{
			wordsButtons.back().setTexture(data->assets.getTexture("Unlocked Word"));
			words.push_back(sf::Text(WORDS[i], font, 25));
			words.back().setPosition(sf::Vector2f(wordsButtons.at(i).getGlobalBounds().getSize().x / 2 - words.back().getGlobalBounds().width / 2 +
				wordsButtons.at(i).getPosition().x, wordsButtons.at(i).getGlobalBounds().getSize().y / 2 - words.back().getGlobalBounds().height / 2 +
				wordsButtons.at(i).getPosition().y));
		}
		
		y += WORD_BUTTON_DIS_HEIGHT;
		if (i % 4 == 3)
		{
			x += WORD_BUTTON_DIS_WIDTH;
			y = startsY;
		}
	}
}

//Draws
void SpeakState::draw(float dt)
{
	data->window.draw(background);
	pet->draw();
	for (int i = 0; i < wordsButtons.size(); i++)
	{
		data->window.draw(wordsButtons.at(i));
	}
	for (int i = 0; i < words.size(); i++)
	{
		data->window.draw(words.at(i));
	}
	effects->draw();
	GameState::draw(dt);
}

//Handles input of pam and words' buttons
bool SpeakState::handleInput(sf::Event event)
{
	if (GameState::handleInput(event))
	{
		return true;
	}
	if (actionType == intro)
	{
		pam->handleInput(event);
	}
	else
	{
		if (!isPause)
		{
			bool isPetTouched = pet->handleInput(event);
			if (actionType == stand)
			{			
				if (isPetTouched)
				{
					touchPet(); //Starts petting the pet
					return true;
				}
				for (int i = 0; i < wordsButtons.size(); i++)
				{
					if (data->input.isSpriteClicked(wordsButtons.at(i), sf::Mouse::Left, data->window))
					{
						sounds->playGameSound(mouseClickSound);
						speak(i); //Starts speak
						return true;
					}
				}
			}
			else
			{
				if (actionType == beingPet && (event.type == sf::Event::MouseButtonReleased))
				{
					stopAction(); //Stops current action
					return true;
				}
			}
		}
	}
	return true;
}

//Make the pet talk
void SpeakState::speak(int word)
{		
	wordIndex = word;
	pet->startTalk();
	actionType = talk;
	if (blockedWords.at(wordIndex)) //If locked word
	{
		wordsButtons.at(wordIndex).setTexture(data->assets.getTexture("Learn Word"));
		words.push_back(sf::Text(WORDS[wordIndex], font, 25));
		words.back().setPosition(sf::Vector2f(wordsButtons.at(wordIndex).getGlobalBounds().getSize().x / 2 - words.back().getGlobalBounds().width / 2 +
			wordsButtons.at(wordIndex).getPosition().x, wordsButtons.at(wordIndex).getGlobalBounds().getSize().y / 2 - words.back().getGlobalBounds().height / 2 +
			wordsButtons.at(wordIndex).getPosition().y));

		wordTime = sounds->learn(wordIndex);
		isLearning = true;
	}
	else
	{
		wordTime = sounds->speak(wordIndex);
		isSpeaking = true;
	}
	
	clock.restart();
}

//Updates
void SpeakState::update(float dt)
{
	if (!isPause)
	{
		if (actionType == intro)
		{
			updatePam(); //Updates pam's speech
		}
		else
		{
			if (actionType == talk && clock.getElapsedTime().asMicroseconds() + exactTime >= wordTime)
			{
				stopAction(); //Stops action after talking
			}
			GameState::update(dt);
		}
	}
}

//Starts petting the pet
void SpeakState::touchPet()
{
	pet->beingPetted();
	sounds->playActionSound(pettingSound);
	actionType = beingPet;
	effects->startEffect(beingPettedEffect);
	startPetTime = clock.getElapsedTime().asSeconds();
}

//Stops current action
void SpeakState::stopAction()
{
	sounds->stop();
	if (actionType == beingPet)
	{
		pet->stopAction((clock.getElapsedTime().asSeconds() + exactTime - startPetTime) * 2);
		effects->stopEffect();
		
	}
	else if (actionType == talk)
	{
		pet->stopAction(0);
		exactTime = 0;
		if (isLearning)
		{
			wordsButtons.at(wordIndex).setTexture(data->assets.getTexture("Unlocked Word")); //Change word button to unlocked
			blockedWords.at(wordIndex) = false;
			isLearning = false;
			speak(wordIndex); //Say the word again
		}
		else
		{
			isSpeaking = false;
		}
	}
	if (!isSpeaking)
	{
		actionType = stand;
	}
}

//Game over
void SpeakState::gameOver()
{
	removeState(); //Remove the state
}

//Remove state
void SpeakState::removeState()
{
	sounds->switchBackground(mainSound);
	GameState::removeState();
}

//Destructor
SpeakState::~SpeakState()
{
	delete pam;
}