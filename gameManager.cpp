#include "gameManager.h"

//THE GAME MANAGER
void userTurn(Dice arrayOfDices[],int &gameStage, int &currentPlayer, ScoreBoardButton scoreBoard[][NUM_PLAYERS])
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
        ShowPotentialScores(currentPlayer, arrayOfDices, scoreBoard);

        //if clicked 
        CheckForScoreClick(currentPlayer, gameStage, END_OF_TURN, arrayOfDices, scoreBoard);

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
        ShowPotentialScores(currentPlayer, arrayOfDices, scoreBoard);

        CheckForScoreClick(currentPlayer, gameStage, END_OF_TURN, arrayOfDices, scoreBoard);


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
        ShowPotentialScores(currentPlayer, arrayOfDices, scoreBoard);
        CheckForScoreClick(currentPlayer, gameStage, END_OF_TURN, arrayOfDices, scoreBoard);
    }

    if(gameStage == END_OF_TURN)
    {
        currentPlayer++;
        if (currentPlayer >= NUM_PLAYERS) 
            currentPlayer = 0;
            
        resetDices(arrayOfDices);
        gameStage = PRE_ROLL;

    }
    PrintScoreBoard(scoreBoard);
    drawDices(arrayOfDices);
}



    



