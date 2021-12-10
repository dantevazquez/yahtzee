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

void drawTitle(ScoreBoard &scoreBoard, Scene &scene, Texture2D &title);
void drawGame(Dice arrayOfDices[], int &gameStage, int &currentPlayer, 
                ScoreBoard &scoreBoard, Scene &scene, Texture2D &board, Texture2D &roll);
void drawEnd(ScoreBoard &ScoreBoard, Scene &scene, Texture2D &end);

#endif