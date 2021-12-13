#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "dice.h"
#include "buttonLocation.h"
#include "buttons.h"
#include "diceArray.h"
#include "scoreBoardButton.h"
#include "scoreBoard.h"

extern ScoreBoard scoreBoard;
extern Font testFont;
extern Texture2D board;
extern Texture2D titleScene;
extern Texture2D endScene;
extern Texture2D rollButton;
extern int currentPlayer;
extern int scene;

//App Scenes
enum Scene
{
    TITLE,
    GAME,
    END
};

//Update Game
void updateGameFrame(Dice arrayOfDices[]);
//Title Scene
void drawTitle();
//Game Scene
void drawGame(Dice arrayOfDices[]);
//End Scene
void drawEnd();

#endif