//Dante Vazquez Yahtzee!
//All arrays start at 0. You can use Enums to represent to use a 1-10 system.
#include "gameManager.h"

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
    //ScoreBoardButton scoreBoard[NUM_OUTCOMES][NUM_PLAYERS];  
    //ConstructScoreBoard(scoreBoard);  
    ScoreBoard scoreBoard(3);       
    
    //Initialize the 5 dices
    Dice arrayOfDices[NUM_DICES];
    initializeSlots(arrayOfDices);
    int gameStage = PRE_ROLL;
 

    int currentPlayer = 0;
  
    // Main game loop
    while (!WindowShouldClose())    
    {
        BeginDrawing();
        ClearBackground(DARKGRAY); //Draw Background
        drawScoreBoard(emptyScoreBoardTexture);
        drawRollButton();
        userTurn(arrayOfDices,gameStage, currentPlayer, scoreBoard);
        EndDrawing();
        //cout<<"Mouse x: " << GetMouseX() <<" Mouse y: " << GetMouseY() <<endl

    }

    CloseWindow();        // Close window and OpenGL context
    return 0;
}