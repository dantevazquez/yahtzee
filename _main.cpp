//Dante Vazquez Yahtzee!
//All arrays start at 0. You can use Enums to represent to use a 1-10 system.
#include "gameManager.h"
#include <time.h>

//global vars
ScoreBoard scoreBoard;
Texture2D board = {0};
Texture2D titleScene = {0};
Texture2D endScene = {0};
Texture2D rollButton = {0};
Font testFont = {0};
int currentPlayer = 0;
int scene = TITLE;

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
    board = LoadTexture("C:/Users/prems/Desktop/Games/FirstGame/resources/empty_scoreboard.png");
    titleScene = LoadTexture("C:/Users/prems/Desktop/Games/FirstGame/resources/home_screen.png");
    endScene = LoadTexture("C:/Users/prems/Desktop/Games/FirstGame/resources/leaderboard.png");  
    rollButton = LoadTexture("C:/Users/prems/Desktop/Games/FirstGame/resources/roll_button.png"); 
    testFont = LoadFont("C:/Users/prems/Desktop/Games/FirstGame/resources/Heavitas.ttf");

    //INITALIZE GAME VARIABLES  
    Dice arrayOfDices[NUM_DICES];     
    initializeSlots(arrayOfDices);
    
    // MAIN GAME LOOP
    while (!WindowShouldClose())    
    {
        updateGameFrame(arrayOfDices);
    }

    UnloadTexture(board);
    UnloadTexture(titleScene);
    UnloadTexture(endScene);
    UnloadTexture(rollButton);
    UnloadFont(testFont);
    CloseAudioDevice();
    CloseWindow();        
    return 0;
}

//cout<<"mouse x: " << GetMouseX() <<" mouse y: " << GetMouseY()<<endl;
