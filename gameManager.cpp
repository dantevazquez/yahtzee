#include "gameManager.h"

void drawTitle(ScoreBoard &scoreBoard, Scene &scene, Texture2D &titleScene)
{
    BeginDrawing();
    DrawTexture(titleScene, 0, 0, RAYWHITE);

    ClearBackground(DARKGRAY); //Draw Background

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

void drawGame(Dice arrayOfDices[],int &gameStage, int &currentPlayer, ScoreBoard &scoreBoard, 
                Scene &scene, Texture2D &board, Texture2D &rollButton)
{
    BeginDrawing();
    drawScoreBoard(board);
    DrawTexture(rollButton,70,520,RAYWHITE);
    ClearBackground(DARKGRAY); //Draw Background
    string playerTurn = "Player " + to_string(currentPlayer + 1) + "'s turn";
    DrawText(playerTurn.c_str(), 110, 20, 24, BLACK); 
    
    if (gameStage == PRE_ROLL)
    {
        drawDices(arrayOfDices);
    }

    //First Roll
    if (isMouseClickingButton(ROLL_BUTTON) && gameStage == PRE_ROLL)
    {
        firstRoll(arrayOfDices);
        gameStage = FIRST_ROLL;
    }

    //Look for dice clicks or score click
    if (gameStage >= FIRST_ROLL && gameStage <= FIRST_CHECK)
    {
        //show potential score
        scoreBoard.ShowPotentialScores(currentPlayer, arrayOfDices);

        //if clicked 
        scoreBoard.CheckForScoreClick(currentPlayer, gameStage, END_OF_TURN, arrayOfDices);

        checkIfDiceGotClicked(arrayOfDices, gameStage, FIRST_CHECK);
    }

    //second roll
    if (isMouseClickingButton(ROLL_BUTTON) && gameStage == FIRST_CHECK 
        && IsADiceSelected(arrayOfDices))
    {
        secondRoll(arrayOfDices);
        gameStage = SECOND_ROLL;
    }
    
    //Look for dice clicks and score click
    if (gameStage >= SECOND_ROLL && gameStage <= SECOND_CHECK)
    {
        scoreBoard.ShowPotentialScores(currentPlayer, arrayOfDices);

        scoreBoard.CheckForScoreClick(currentPlayer, gameStage, END_OF_TURN, arrayOfDices);


        checkIfDiceGotClicked(arrayOfDices, gameStage, SECOND_CHECK);
    }

    //third roll
    if (isMouseClickingButton(ROLL_BUTTON) && gameStage == SECOND_CHECK 
        && IsADiceSelected(arrayOfDices))
    {
        thirdRoll(arrayOfDices);
        gameStage = THIRD_ROLL;
    }

    if(gameStage == THIRD_ROLL)
    {
        scoreBoard.ShowPotentialScores(currentPlayer, arrayOfDices);
        scoreBoard.CheckForScoreClick(currentPlayer, gameStage, END_OF_TURN, arrayOfDices);
    }

    if(gameStage == END_OF_TURN)
    {
        currentPlayer++;
        if (currentPlayer >= scoreBoard.GetNumPlayers()) 
            currentPlayer = 0;
            
        resetDices(arrayOfDices);
        gameStage = PRE_ROLL;

    }
    scoreBoard.PrintScoreBoard();
    drawDices(arrayOfDices);
    if(scoreBoard.GetGameRound() == NUM_OUTCOMES * scoreBoard.GetNumPlayers())
    {
        scene = END;
    }
    EndDrawing();

}

void drawEnd(ScoreBoard &scoreBoard, Scene &scene, Texture2D &endScene)
{
    BeginDrawing();
    DrawTexture(endScene, 200, 200, RAYWHITE);
    ClearBackground(DARKGRAY); //Draw Background
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








    



