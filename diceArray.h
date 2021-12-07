#ifndef DICEARRAY_H
#define DICEARRAY_H

#include "gameManager.h"
#include "buttons.h"

const int NUM_DICES = 5;

enum GameStage
{
    PRE_ROLL,
    FIRST_ROLL,
    FIRST_CHECK,
    SECOND_ROLL,
    SECOND_CHECK,
    THIRD_ROLL,
    END_OF_TURN,
    
};

void drawDices(Dice diceArray[]);
void firstRoll(Dice arrayOfDices[]);
void secondRoll(Dice arrayOfDices[]);
void thirdRoll(Dice arrayOfDices[]);
void checkIfDiceGotClicked(Dice arrayOfDices[], int &gameStage, int setGameStageToo);
bool IsADiceSelected(Dice arrayOfDices[]);
void resetDices(Dice arrayOfDices[]);
void initializeSlots(Dice arrayOfDices[]);



#endif