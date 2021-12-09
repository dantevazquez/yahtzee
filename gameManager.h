#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "dice.h"
#include "buttonLocation.h"
#include "buttons.h"
#include "diceArray.h"
#include "scoreBoardButton.h"
#include "scoreBoard.h"

enum Scene
{
    TITLE,
    GAME,
    END
};

//Function generates and returns a random integer from 1-6
void userTurn(Dice arrayOfDices[], int &gameStage, int &currentPlayer, ScoreBoard &scoreBoard, Scene &scene);

void drawLeaderBoard(ScoreBoard &scoreBoard);

#endif