#include "SoundManage.h"
#include "Definitions.h"
#include <iostream>

//Constructor getss a data
SoundManage::SoundManage(gameDataRef data) : data(data)
{
	isSound = true;
	actionSoundPlaying = speakSoundPlaying = -1;

	loadSounds();
	//Sets background sound
	backgroundSound.setBuffer(backgroundBuffer.at(mainSound));
	backgroundSound.play();
	//Sets volume for each sound
	backgroundSound.setVolume(BACKGROUND_VOLUME);
	gameSound.setVolume(GAME_VOLUME);
	speakSound.setPitch(1.5);

	backgroundSound.setLoop(true);
	actionSound.setLoop(true);
}

//Loads all sounds
void SoundManage::loadSounds()
{
	for (int i = 0; i < 2; i++)
	{
		data->assets.loadSoundBuffer("Background Sound " + std::to_string(i), BACKGROUND_SOUND + std::to_string(i) + ".mp3");
		backgroundBuffer.push_back(data->assets.getSoundBuffer("Background Sound " + std::to_string(i)));
	}

	for (int i = 0; i < 2; i++)
	{
		data->assets.loadSoundBuffer("Game Sound " + std::to_string(i), GAME_SOUND + std::to_string(i) + ".wav");
		gameSoundBuffer.push_back(data->assets.getSoundBuffer("Game Sound " + std::to_string(i)));
	}

	for (int i = 0; i < 6; i++)
	{
		data->assets.loadSoundBuffer("Action Sound " + std::to_string(i), ACTION_SOUND + std::to_string(i) + ".wav");
		actionsSoundBuffer.push_back(data->assets.getSoundBuffer("Action Sound " + std::to_string(i)));
	}

	for (int i = 0; i < 12; i++)
	{
		data->assets.loadSoundBuffer("Speak Sound " + std::to_string(i), SPEAK_SOUNDS + std::to_string(i) + ".mp3");
		speakBuffer.push_back(data->assets.getSoundBuffer("Speak Sound " + std::to_string(i)));
	}

	for (int i = 0; i < 12; i++)
	{
		data->assets.loadSoundBuffer("Learn Sound " + std::to_string(i), LEARN_SOUND + std::to_string(i) + ".mp3");
		learnBuffer.push_back(data->assets.getSoundBuffer("Learn Sound " + std::to_string(i)));
	}
}

//Gets if sound is on or not
bool SoundManage::getIsSound()
{
	return isSound;
}

//Sets sounds volume - off or on
void SoundManage::setSound()
{
	isSound = !isSound;
	if (!isSound)
	{
		backgroundSound.setVolume(0);
		actionSound.setVolume(0);
		gameSound.setVolume(0);
	}
	else
	{
		backgroundSound.setVolume(BACKGROUND_VOLUME);
		actionSound.setVolume(ACTION_VOLUME);
		gameSound.setVolume(GAME_VOLUME);
	}
}

//Gets a sound number and switches the background sound 
void SoundManage::switchBackground(int sound)
{
	if (sound < backgroundBuffer.size())
	{
		backgroundSound.setBuffer(backgroundBuffer.at(sound));
		backgroundSound.play();
	}
}

//Gets a game sound number and plays it 
void SoundManage::playGameSound(int sound)
{
	if (sound < gameSoundBuffer.size())
	{
		gameSound.setBuffer(gameSoundBuffer.at(sound));
		gameSound.play();
	}
}

//Gets an action sound number and plays it 
void SoundManage::playActionSound(int sound)
{
	if (sound < actionsSoundBuffer.size())
	{
		actionSound.setBuffer(actionsSoundBuffer.at(sound));
		actionSound.play();
		actionSoundPlaying = sound;
		if (actionSoundPlaying == playingSound)
		{
			actionSound.setPitch(1.5);
		}
	}
}

//Gets a word number, plays it and returns it's time
float SoundManage::speak(int word)
{
	if (word < speakBuffer.size())
	{
		speakSound.setBuffer(speakBuffer.at(word));
		speakSound.play();
		speakSoundPlaying = word;
		return speakBuffer.at(word).getDuration().asMicroseconds() - 800000;
	}
	return -1;
}

//Gets a word number to learn, plays it and returns it's time
float SoundManage::learn(int word)
{
	if (word < learnBuffer.size())
	{
		speakSound.setBuffer(learnBuffer.at(word));
		speakSound.play();
		speakSoundPlaying = word;
		return learnBuffer.at(word).getDuration().asMicroseconds() - 1000000;
	}
	return -1;
}

//Stops action and speaking sounds
void SoundManage::stop()
{
	if (actionSoundPlaying > -1)
	{
		if (actionSound.getStatus() == sf::Sound::Paused)
		{
			actionSound.play();
		}
		actionSound.stop();
		if (actionSoundPlaying == playingSound)
		{
			actionSound.setPitch(1);
		}
		else
		{
			playGameSound(happyPetSound);
		}
		actionSoundPlaying = -1;
	}
	if (speakSoundPlaying > -1)
	{
		if (speakSound.getStatus() == sf::Sound::Paused)
		{
			speakSound.play();
		}
		speakSound.stop();
		speakSoundPlaying = -1;
	}
}

//Pauses all played sounds
void SoundManage::pause()
{
	backgroundSound.pause();
	if (actionSoundPlaying > -1)
	{
		actionSound.pause();
	}
	if (speakSoundPlaying > -1)
	{
		speakSound.pause();
	}
}

//Resume all paused sounds
void SoundManage::resume()
{
	if (backgroundSound.getStatus() == sf::Sound::Paused)
	{
		backgroundSound.play();
	}
	if (actionSoundPlaying > -1)
	{
		actionSound.play();
	}
	if (speakSoundPlaying > -1)
	{
		speakSound.play();
	}
}