#include "YardState.h"
#include <iostream>

//Constructor get a data, sounds, effects, a pet and a type of game to play with the pet
YardState::YardState(gameDataRef data, SoundManage* sounds, EffectsControl *effects, Pet* pet, int gameType) :
      GameState(data, sounds, effects, pet) , gameType(gameType)
{
    actionType = stand;
    if (gameType == tic_tac_toe)
    {
        isPlayed = true;
        ticTacToe = new TicTacToe(data);
    }
    else
    {
      if (gameType < ball && gameType > tic_tac_toe) //Checks if gameType has a valid value
       {
            this->gameType = ball;
       }
        isPlayed = false;
    }
}

//Init
void YardState::init()
{
    GameState::init();
    data->assets.loadTexture("Yard Background", YARD_BACKGROUND);
    background.setTexture(data->assets.getTexture("Yard Background"));
}

//Handles input of the games
bool YardState::handleInput(sf::Event event)
{
    if (!GameState::handleInput(event))
    {
        if (!isPause)
        {
            if (actionType == intro)
            { 
                  pam->handleInput(event);
            }
            else
            {
                  bool isPetTouched = pet->handleInput(event);
                  if ((gameType == tic_tac_toe))
                  {
                        if (isPlayed)
                        {
                              ticTacToe->handleInput(event);
                        }
                  }
                  else
                  {
                        if (isPetTouched && !isPlayed)
                        {
                              touchPet();
                        }
                  }
            }
        }
     }
     return true;
}

//Updates pam and pet
void YardState::update(float dt)
{
    if (!isPause)
    {
        if (actionType == intro)
        {
            if (pam->getIsDone())
            {
                removeState();
            }
        }
        else
        {
            if ((gameType == tic_tac_toe))
            {
                if (isPlayed)
                {
                    if (ticTacToe->update(dt)) //Game is over
                    {
                        isPlayed = false;
                        //Ends tic tac toe game with the pet playing
                        pet->startPlay();
                        stopAction(PLAYING_PET_XP * 3);
                        pet->startPlay();
                        sounds->playGameSound(happyPetSound);
                    }
                    else
                    {
                        float currentTime = clock.getElapsedTime().asSeconds();
                        if (pet->getActionType() == play)
                        {
                            if (currentTime >= PET_PLAYS_TIME / 1.6)
                            {
                                stopAction(PLAYING_PET_XP); //Stops pet playing action
                            }
                        }
                        else
                        {
                            if (currentTime >= PET_PLAYS_TIME)
                            {
                                startPlay(); //Make the pet start playing
                            }
                        }
                    }
                }
            }
            else
            {
                if (isPlayed && !effects->isEffect())
                {
                    stopAction(PLAYING_PET_XP); //Stops pet playing action
                }
            }
        GameState::update(dt);
        }
    }
}

//draws 
void YardState::draw(float dt)
{
    data->window.draw(background);
    pet->draw();
    if (gameType == tic_tac_toe)
    {
        ticTacToe->draw(dt);
    }
    else
    {
        effects->draw();
    }
    GameState::draw(dt);
}

//Make pet start playing
void YardState::startPlay()
{
    pet->startPlay();
    sounds->playActionSound(playingSound);
    clock.restart();
}

//Start playing when pet is being touched
void YardState::touchPet()
{
    effects->startEffect(gameType + FIRST_TOY_EFFECT);
    startPlay(); //Make the pet start playing
    isPlayed = true;
}

//Stops current action
void YardState::stopAction(int xp)
{
    if (gameType != tic_tac_toe)
    {
        isPlayed = false;
    }
    else
    {
        clock.restart();
    }
    pet->stopAction(xp);
    sounds->stop();
}

//Game over
void YardState::gameOver()
{
    removeState(); //Removes the state
}
