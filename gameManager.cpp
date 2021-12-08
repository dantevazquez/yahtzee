#include "gameManager.h"

//SCOREBOARDBUTTON CLASS
ScoreBoardButton::ScoreBoardButton()
{
    score = "";
    potentialScore = "";
    isClickable = false;
    scoreSet = false;
    location = ButtonLocation();
}

void ScoreBoardButton::DrawPotentialScore()
{
    DrawText(potentialScore.c_str(), location.GetXLow() + 46, location.GetYLow() + 30, 14, RED); 
    isClickable = true;  
}

void ScoreBoardButton::DrawScore()
{
    DrawText(score.c_str(), location.GetXLow() + 46, location.GetYLow() + 30, 14, WHITE); 
}
void ScoreBoardButton::SetScore(string score)
{
    this->score = score.c_str();
    scoreSet = true;
}
void ScoreBoardButton::SetPotentialScore(string score)
{
    potentialScore = score.c_str();
}
void ScoreBoardButton::SetClickState(bool clickState)
{
    isClickable = clickState;
}
void ScoreBoardButton::SetButtonLocation(ButtonLocation inLocation)
{
    location = inLocation;
}

string ScoreBoardButton::GetScore(){return score;}

string ScoreBoardButton::GetPotentialScore(){return potentialScore;}

bool ScoreBoardButton::GetClickState(){return isClickable;}

ButtonLocation ScoreBoardButton::GetButtonLocation(){return location;}

bool ScoreBoardButton::IsScoreSet(){return scoreSet;}

////////////////////////////////////////////////////////////////////////////////
//SCOREBOARD FUNCTIONS (A SCOREBOARD IS A 2D ARRAY OF SCOREBOARDBUTTONS)
void ConstructScoreBoard(ScoreBoardButton scoreBoard[][NUM_PLAYERS])
{
    for(int i = 0; i < NUM_OUTCOMES; i++)
    {
        for(int j = 0; j < NUM_PLAYERS; j++)
            scoreBoard[i][j].SetButtonLocation(intToButtonLocation(i,j));
    }
}

void ShowPotentialScores(int player, Dice arrayOfDices[], ScoreBoardButton scoreBoard[][NUM_PLAYERS])
{
    for (int i = 0; i < NUM_OUTCOMES; i++)
    {

        if(getPotentialScores(intToOutcome(i), arrayOfDices) >= 0 && !scoreBoard[i][player].IsScoreSet())
        {
            scoreBoard[i][player].SetPotentialScore(to_string(getPotentialScores(intToOutcome(i), arrayOfDices)));
            scoreBoard[i][player].DrawPotentialScore();
        }
    }
}

void PrintScoreBoard(ScoreBoardButton scoreBoard[][NUM_PLAYERS])
{
    for (int i = 0; i < NUM_OUTCOMES; i++)
    {
        for (int j = 0; j < NUM_PLAYERS; j++)
            scoreBoard[i][j].DrawScore();
    }
}

void CheckForScoreClick(int &player, int &gameStage, int setGameStageToo, Dice arrayOfDices[], ScoreBoardButton scoreBoard[][NUM_PLAYERS])
{
    for (int i = 0; i < NUM_OUTCOMES; i++)
    {
        if (isMouseClickingButton(scoreBoard[i][player].GetButtonLocation()) 
        && scoreBoard[i][player].GetClickState() && !scoreBoard[i][player].IsScoreSet())
        {
            scoreBoard[i][player].SetScore(to_string(getPotentialScores(intToOutcome(i), arrayOfDices)));
            scoreBoard[i][player].SetClickState(false);
            gameStage = setGameStageToo;
            drawDices(arrayOfDices);
            return;
        }
    }
}
  
int getPotentialScores(Outcomes outcome, Dice arrayOfDices[])
{
    
    if (outcome == ONES)
        return onesCheck(arrayOfDices); //finish this

    if (outcome == TWOS)
        return twosCheck(arrayOfDices); //finish this

    if (outcome == THREES)
        return threesCheck(arrayOfDices); //finish this

    if (outcome == FOURS)
        return foursCheck(arrayOfDices); //finish this
    
    if (outcome == FIVES)
        return fivesCheck(arrayOfDices);
    
    if (outcome == SIXS)
        return sixsCheck(arrayOfDices);
    
    if (outcome == THREE_OF_A_KIND)
        return threeOfAKindCheck(arrayOfDices);
    
    if (outcome == FOUR_OF_A_KIND)
        return fourOfAKindCheck(arrayOfDices);
    
    if (outcome == STAIRS)
        return stairsCheck(arrayOfDices);
    
    if (outcome == FULL_HOUSE)
        return fullHouseCheck(arrayOfDices);
    
    if (outcome == YAHTZEE)
        return yahtzeeCheck(arrayOfDices);  

    
    cout<<"FATAL ERROR";
    return -1;
}

Outcomes intToOutcome(int i)
{
    if (i == 0) return ONES;
    if (i == 1) return TWOS;
    if (i == 2) return THREES;
    if (i == 3) return FOURS;
    if (i == 4) return FIVES;
    if (i == 5) return SIXS;
    if (i == 6) return THREE_OF_A_KIND;
    if (i == 7) return FOUR_OF_A_KIND;
    if (i == 8) return STAIRS;
    if (i == 9) return FULL_HOUSE;
    if (i == 10) return YAHTZEE;

    cout<<"FATAL ERROR. INT CANNOT TRANSLATE TO OUTCOME"<<endl;
    return YAHTZEE;
}

ButtonLocation intToButtonLocation(int outcome, int player)
{
    if (player == 0)
    {
        if(outcome == 0) return ONES_BUTTON_P1;
        if(outcome == 1) return TWOS_BUTTON_P1;
        if(outcome == 2) return THREES_BUTTON_P1;
        if(outcome == 3) return FOURS_BUTTON_P1;
        if(outcome == 4) return FIVES_BUTTON_P1;
        if(outcome == 5) return SIXS_BUTTON_P1;
        if(outcome == 6) return THREE_OF_A_KIND_BUTTON_P1;
        if(outcome == 7) return FOUR_OF_A_KIND_BUTTON_P1;
        if(outcome == 8) return STAIRS_BUTTON_P1;
        if(outcome == 9) return FULL_HOUSE_BUTTON_P1;
        if(outcome == 10) return YAHTZEE_BUTTON_P1;
    }
    if (player == 1)
    {
        if(outcome == 0) return ONES_BUTTON_P2;
        if(outcome == 1) return TWOS_BUTTON_P2;
        if(outcome == 2) return THREES_BUTTON_P2;
        if(outcome == 3) return FOURS_BUTTON_P2;
        if(outcome == 4) return FIVES_BUTTON_P2;
        if(outcome == 5) return SIXS_BUTTON_P2;
        if(outcome == 6) return THREE_OF_A_KIND_BUTTON_P2;
        if(outcome == 7) return FOUR_OF_A_KIND_BUTTON_P2;
        if(outcome == 8) return STAIRS_BUTTON_P2;
        if(outcome == 9) return FULL_HOUSE_BUTTON_P2;
        if(outcome == 10) return YAHTZEE_BUTTON_P2;
    }
    if (player == 2)
    {
        if(outcome == 0) return ONES_BUTTON_P3;
        if(outcome == 1) return TWOS_BUTTON_P3;
        if(outcome == 2) return THREES_BUTTON_P3;
        if(outcome == 3) return FOURS_BUTTON_P3;
        if(outcome == 4) return FIVES_BUTTON_P3;
        if(outcome == 5) return SIXS_BUTTON_P3;
        if(outcome == 6) return THREE_OF_A_KIND_BUTTON_P3;
        if(outcome == 7) return FOUR_OF_A_KIND_BUTTON_P3;
        if(outcome == 8) return STAIRS_BUTTON_P3;
        if(outcome == 9) return FULL_HOUSE_BUTTON_P3;
        if(outcome == 10) return YAHTZEE_BUTTON_P3;
    }

    cout<<"ERROE intTOBUTTONLOCATION!"<<endl;
    return YAHTZEE_BUTTON_P1;
}

int onesCheck(Dice arrayOfDices[])
{
    int ones = 0;

    for (int i = 0; i < NUM_DICES; i++)
    {
        if(arrayOfDices[i].GetDiceNumber() == ONE)
            ones += 1;
        
    }
    return ones;
    
}

int twosCheck(Dice arrayOfDices[])
{
    int twos = 0;

    for (int i = 0; i < NUM_DICES; i++)
    {
        if(arrayOfDices[i].GetDiceNumber() == TWO)
            twos += 2;
    }
    return twos;
}
    
int threesCheck(Dice arrayOfDices[])
{
    int threes = 0;

    for (int i = 0; i < NUM_DICES; i++)
    {
        if(arrayOfDices[i].GetDiceNumber() == THREE)
            threes += 3;
    }
    return threes;


}
int foursCheck(Dice arrayOfDices[])
{
    int fours = 0;

    for (int i = 0; i < NUM_DICES; i++)
    {
        if(arrayOfDices[i].GetDiceNumber() == FOUR)
            fours += 4;
    }
    return fours;
}
int fivesCheck(Dice arrayOfDices[])
{
    int fives = 0;

    for (int i = 0; i < NUM_DICES; i++)
    {
        if(arrayOfDices[i].GetDiceNumber() == FIVE)
            fives += 5;
    }
    return fives;
}
        
int sixsCheck(Dice arrayOfDices[])
{
    int sixs = 0;

    for (int i = 0; i < NUM_DICES; i++)
    {
        if(arrayOfDices[i].GetDiceNumber() == SIX)
            sixs += 6;
    }
    return sixs;
}
int threeOfAKindCheck(Dice arrayOfDices[])
{
    return 69;

}
int fourOfAKindCheck(Dice arrayOfDices[])
{
    return 69;

}
int stairsCheck(Dice arrayOfDices[])
{
    return 69;

}
int fullHouseCheck(Dice arrayOfDices[])
{
    return 69;

}
int yahtzeeCheck(Dice arrayOfDices[])
{

    for(int i = 0; i < NUM_DICES - 1; i++)
    {
        if(arrayOfDices[i].GetDiceNumber() != arrayOfDices[i + 1].GetDiceNumber())
            return 0;
    }
    
    return 60;
}
////////////////////////////////////////////////////////////////////////////////
int getRandomDiceNumber()
{
    return rand() % 6;
}

//THE GAME MANAGER
void userTurn(Dice arrayOfDices[],int &gameStage, int &currentPlayer, ScoreBoardButton scoreBoard[][NUM_PLAYERS])
{
    
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
}



    



