//Dante Vazquez Yahtzee!
//All arrays start at 0. You can use Enums to represent to use a 1-10 system.
#include "gameManager.h"
#include "diceArray.h"
#include "dice.h"
#include "gameManager.h"
#include "buttons.h"
#include "buttonLocation.h"
#include <string>
using namespace std;

int main(void)
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 800;
    const int GAME_FPS = 60;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Yahtzee!");
    SetTargetFPS(GAME_FPS); 

    Image emptyScoreBoard = 
    LoadImage("C:/Users/prems/Desktop/Games/FirstGame/resources/empty_scoreboard.png");
    
    Texture2D emptyScoreBoardTexture = LoadTextureFromImage(emptyScoreBoard);   
    ScoreBoardButton scoreBoard[NUM_OUTCOMES][NUM_PLAYERS];  
    ConstructScoreBoard(scoreBoard);         
    
    //Initialize the 5 dices
    Dice arrayOfDices[NUM_DICES];
    initializeSlots(arrayOfDices);
    int gameStage = PRE_ROLL;
    string playerTurn;
 

    int currentPlayer = 0;
  
    // Main game loop
    while (!WindowShouldClose())    
    {
        BeginDrawing();
        ClearBackground(DARKGRAY); //Draw Background
        drawScoreBoard(emptyScoreBoardTexture);
        drawRollButton();
        playerTurn = "Player " + to_string(currentPlayer + 1) + "'s turn";
        DrawText(playerTurn.c_str(), 0, 0, 14, RED); 
        userTurn(arrayOfDices,gameStage, currentPlayer, scoreBoard);
        PrintScoreBoard(scoreBoard);
        drawDices(arrayOfDices);
        EndDrawing();
        //cout<<"Mouse x: " << GetMouseX() <<" Mouse y: " << GetMouseY() <<endl;
        //Added a test comment

    }

    CloseWindow();        // Close window and OpenGL context
    return 0;
}