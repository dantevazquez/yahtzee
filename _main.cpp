//Dante Vazquez Yahtzee!
//All arrays start at 0. You can use Enums to represent to use a 1-10 system.
#include "gameManager.h"
#include <time.h>
//dec 10
int main(void)
{
    SetRandomSeed(time(0)); //Set seed for dice roller
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 800;
    const int GAME_FPS = 30;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Yahtzee!");
    SetTargetFPS(GAME_FPS); 
    InitAudioDevice();

    //LOAD GAME IMAGES
    Texture2D board = LoadTexture("../resources/empty_scoreboard.png");
    Texture2D titleScene = LoadTexture("../resources/home_screen.png");
    Texture2D endScene = LoadTexture("../resources/leaderboard.png");  
    Texture2D rollButton = LoadTexture("../resources/roll_button.png"); 
 
    //INITALIZE GAME VARIABLES
    ScoreBoard scoreBoard;       
    Dice arrayOfDices[NUM_DICES];
    initializeSlots(arrayOfDices);
    int currentPlayer = 0;
    Scene scene = TITLE;

    // MAIN GAME LOOP
    while (!WindowShouldClose())    
    {
        
        if (scene == TITLE)
        {
            drawTitle(scoreBoard, scene, titleScene);
        }
        if(scene == GAME)
        {
            drawGame(arrayOfDices, currentPlayer, scoreBoard, scene, board, rollButton);
        }
        if(scene == END)
        {
            drawEnd(scoreBoard, scene, endScene);
        }

        //cout<<"mouse x: " << GetMouseX() <<" mouse y: " << GetMouseY()<<endl;
    }

    UnloadTexture(board);
    UnloadTexture(titleScene);
    UnloadTexture(endScene);
    UnloadTexture(rollButton);
    CloseAudioDevice();
    CloseWindow();        
    return 0;
}