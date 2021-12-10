#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "dice.h"
#include "buttonLocation.h"
#include "buttons.h"
#include "diceArray.h"
#include "scoreBoardButton.h"
#include "scoreBoard.h"

//App Scenes
enum Scene
{
    TITLE,
    GAME,
    END
};

//Title Scene
void drawTitle(ScoreBoard &scoreBoard, Scene &scene, Texture2D &title);

//Game Scene
void drawGame(Dice arrayOfDices[], int &currentPlayer, 
                ScoreBoard &scoreBoard, Scene &scene, Texture2D &board, Texture2D &roll);

//End Scene
void drawEnd(ScoreBoard &ScoreBoard, Scene &scene, Texture2D &end);

#endif