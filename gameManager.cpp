#include "gameManager.h"

//THE GAME MANAGER
void userTurn(Dice arrayOfDices[],int &gameStage, int &currentPlayer, ScoreBoard &scoreBoard, Scene &scene)
{
    string playerTurn = "Player " + to_string(currentPlayer + 1) + "'s turn";
    DrawText(playerTurn.c_str(), 0, 0, 14, RED); 
    
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

}

void drawLeaderBoard(ScoreBoard &scoreBoard)
{
    string playerOneScoreStr = "Player One: " + to_string(scoreBoard.GetPlayerScore(0));
    string playerTwoScoreStr = "Player Two: " + to_string(scoreBoard.GetPlayerScore(1));
    string playerThreeScoreStr = "Player Three: " + to_string(scoreBoard.GetPlayerScore(2));

    int p1 = scoreBoard.GetPlayerScore(0);
    int p2 = scoreBoard.GetPlayerScore(1);
    int p3 = scoreBoard.GetPlayerScore(2);

    if ( p1 > p2 && p1 > p3 )
    {
        DrawText(playerOneScoreStr.c_str(), 280,260,16,BLACK); //1st
        if(p2 > p3)
        {
            DrawText(playerTwoScoreStr.c_str(), 280,340,16,BLACK);//2nd
            DrawText(playerThreeScoreStr.c_str(),280,420,16,BLACK);//3rd
        }
        else
        {
            DrawText(playerThreeScoreStr.c_str(), 280,340,16,BLACK);//2nd
            DrawText(playerTwoScoreStr.c_str(),280,420,16,BLACK);//3rd
        }
    }
    else if ( p2 > p1 && p2 > p3 )
    {
        DrawText(playerTwoScoreStr.c_str(), 280,260,16,BLACK);
        if(p1 > p3)
        {
            DrawText(playerOneScoreStr.c_str(), 280,340,16,BLACK);//2nd
            DrawText(playerThreeScoreStr.c_str(),280,420,16,BLACK);//3rd
        }
        else
        {
            DrawText(playerThreeScoreStr.c_str(), 280,340,16,BLACK);//2nd
            DrawText(playerOneScoreStr.c_str(),280,420,16,BLACK);//3rd
        }


    }
    else if ( p3 > p1 && p3 > p2 )
    {
        DrawText(playerThreeScoreStr.c_str(), 280,260,16,BLACK);
        if(p1>p2)
        {
            DrawText(playerOneScoreStr.c_str(), 280,340,16,BLACK);//2nd
            DrawText(playerTwoScoreStr.c_str(),280,420,16,BLACK);//3rd
        }
        else
        {
            DrawText(playerTwoScoreStr.c_str(), 280,340,16,BLACK);//2nd
            DrawText(playerOneScoreStr.c_str(),280,420,16,BLACK);//3rd
        }

    }
}





    



