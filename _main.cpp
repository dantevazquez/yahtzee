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

    Image titleScene = 
    LoadImage("C:/Users/prems/Desktop/Games/FirstGame/resources/home_screen.png");
    
    Texture2D titleSceneTexture = LoadTextureFromImage(titleScene);

    Image endScene = 
    LoadImage("C:/Users/prems/Desktop/Games/FirstGame/resources/leaderboard.png");
    
    Texture2D endSceneTexture = LoadTextureFromImage(endScene);       
 
    ScoreBoard scoreBoard;       
    
    //Initialize the 5 dices
    Dice arrayOfDices[NUM_DICES];
    initializeSlots(arrayOfDices);
    int gameStage = PRE_ROLL;
 

    int currentPlayer = 0;

    Scene scene = TITLE;
  
    // Main game loop
    while (!WindowShouldClose())    
    {

        if (scene == TITLE)
        {
            BeginDrawing();
            ClearBackground(DARKGRAY); //Draw Background
            DrawTexture(titleSceneTexture, 0, 0, RAYWHITE);

            if(isMouseClickingButton(BUTTON_ONE_PLAYER))
            {
                scoreBoard.SetNumPlayers(1);
                scene = GAME;
                

            }
            
            if(isMouseClickingButton(BUTTON_TWO_PLAYER))
            {
                scoreBoard.SetNumPlayers(2);
                scene = GAME;
                
            }
            
            if(isMouseClickingButton(BUTTON_THREE_PLAYER))
            {
                scoreBoard.SetNumPlayers(3);
                scene = GAME;
                
            }

            
            EndDrawing();
        }
    


        if(scene == GAME)
        {
            BeginDrawing();
            ClearBackground(DARKGRAY); //Draw Background
            drawScoreBoard(emptyScoreBoardTexture);
            drawRollButton();
            userTurn(arrayOfDices,gameStage, currentPlayer, scoreBoard, scene);
            EndDrawing();
            //cout<<"Mouse x: " << GetMouseX() <<" Mouse y: " << GetMouseY() <<endl
        }

        if(scene == END)
        {
            BeginDrawing();

            ClearBackground(DARKGRAY); //Draw Background

            DrawTexture(endSceneTexture, 200, 200, RAYWHITE);
            drawLeaderBoard(scoreBoard);
            if(isMouseClickingButton(BUTTON_EXIT))
            {
                CloseWindow();
            }

            if(isMouseClickingButton(BUTTON_PLAY_AGAIN))
            {
                scoreBoard.ResetScoreBoard();
                scene = TITLE;

            }
            EndDrawing();


        }


    }

    CloseWindow();        // Close window and OpenGL context
    return 0;
}