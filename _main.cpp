//Dante Vazquez Yahtzee!
//All arrays start at 0. You can use Enums to represent to use a 1-10 system.
#include "gameManager.h"
#include <time.h>

int main(void)
{
    SetRandomSeed(time(0));
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 800;
    const int GAME_FPS = 60;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Yahtzee!");
    SetTargetFPS(GAME_FPS); 
    InitAudioDevice();

    //LOAD GAME IMAGES
    Texture2D board = LoadTexture("C:/Users/prems/Desktop/Games/FirstGame/resources/empty_scoreboard.png");
    Texture2D titleScene = LoadTexture("C:/Users/prems/Desktop/Games/FirstGame/resources/home_screen.png");
    Texture2D endScene = LoadTexture("C:/Users/prems/Desktop/Games/FirstGame/resources/leaderboard.png");  
    Texture2D rollButton = LoadTexture("C:/Users/prems/Desktop/Games/FirstGame/resources/roll_button.png"); 
 
    //INITALIZE GAME VARIABLES
    ScoreBoard scoreBoard;       
    Dice arrayOfDices[NUM_DICES];
    initializeSlots(arrayOfDices);
    //int gameStage = PRE_ROLL;
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
            drawGame(arrayOfDices,currentPlayer, scoreBoard, scene, board, rollButton);
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