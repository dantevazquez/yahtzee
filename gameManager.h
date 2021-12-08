#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "dice.h"
#include "buttonLocation.h"
#include "buttons.h"
#include "diceArray.h"
#include "scoreBoardButton.h"

using namespace std;

//Function generates and returns a random integer from 1-6
void userTurn(Dice arrayOfDices[], int &gameStage, int &currentPlayer, ScoreBoardButton scoreBoard[][NUM_PLAYERS]);

#endif