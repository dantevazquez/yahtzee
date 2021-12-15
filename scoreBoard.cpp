#include "scoreBoard.h"

ScoreBoard::ScoreBoard()
{
    numPlayers = 0;
    gameRound = 0;
    gameStage = 0;

    for(int i = 0; i < NUM_OUTCOMES; i++)
    {
        for(int j = 0; j < NUM_PLAYERS; j++)
            scoreBoard[i][j].SetButtonLocation(intToButtonLocation(i,j));
    }
    
}

//Getters
int ScoreBoard::GetNumPlayers(){return numPlayers;}
int ScoreBoard::GetGameRound(){return gameRound;}
int ScoreBoard::GetGameStage(){return gameStage;}
int ScoreBoard::GetPlayerTotalScore(int player)
{
    int score = 0;

    for (int i = 0; i < NUM_OUTCOMES; i++)
    {
        if (scoreBoard[i][player].IsScoreSet())
        {
            score += stoi(scoreBoard[i][player].GetScore());
        }
    }
    return score;
}


//Setters
void ScoreBoard::SetNumPlayers(int numPlayers)
{
    this->numPlayers = numPlayers;
}
void ScoreBoard::SetGameStage(int gameStage)
{
    this->gameStage = gameStage;
}

//Scoreboard methods
void ScoreBoard::ResetScoreBoard()
{
    for (int i = 0; i < NUM_OUTCOMES; i++)
    {
        for (int j = 0; j < NUM_PLAYERS; j++)
        {
            scoreBoard[i][j].ResetButton();
        }
    }

    numPlayers = 0;
    gameRound = 0;

}

void ScoreBoard::ShowPotentialScores(int player, Dice arrayOfDices[])
{
    for (int i = 0; i < NUM_OUTCOMES; i++)
    {
        //If potential scores found, display them
        if(getPotentialScores(intToOutcome(i), arrayOfDices) >= 0 && !scoreBoard[i][player].IsScoreSet())
        {
            //Give player a 5 point bonus on special rolls
            if(getPotentialScores(intToOutcome(i), arrayOfDices) > 0 && (gameStage == FIRST_ROLL || gameStage == FIRST_CHECK) && i > 5)
            {
                scoreBoard[i][player].SetPotentialScore(to_string(getPotentialScores(intToOutcome(i), arrayOfDices) + 5));
                scoreBoard[i][player].DrawPotentialScore();
            }
            else
            {
                scoreBoard[i][player].SetPotentialScore(to_string(getPotentialScores(intToOutcome(i), arrayOfDices)));
                scoreBoard[i][player].DrawPotentialScore();
            }
  
        }
    }
}

void ScoreBoard::CheckForScoreClick(int &player, Dice arrayOfDices[])
{
    for (int i = 0; i < NUM_OUTCOMES; i++)
    {
        //Give player a 5 point bonus on special rolls
        if (isMouseClickingButton(scoreBoard[i][player].GetButtonLocation()) 
        && scoreBoard[i][player].GetClickState() && !scoreBoard[i][player].IsScoreSet())
        {
            //If player got a point on a first roll on the big boy outcomes
            if(getPotentialScores(intToOutcome(i), arrayOfDices) > 0 && (gameStage == FIRST_ROLL || gameStage == FIRST_CHECK) && i > 5)
            {
                scoreBoard[i][player].SetScore(to_string(getPotentialScores(intToOutcome(i), arrayOfDices) + 5));
                scoreBoard[i][player].SetClickState(false);
            }
            else
            {
                scoreBoard[i][player].SetScore(to_string(getPotentialScores(intToOutcome(i), arrayOfDices)));
                scoreBoard[i][player].SetClickState(false);
            }

            gameRound++;
            gameStage = END_OF_TURN;
            drawDices(arrayOfDices);
            return;
        }
    }
}

void ScoreBoard::checkIfDiceGotClicked(Dice arrayOfDices[NUM_DICES], int setGameStageToo)
{
    for (int i = 0; i < NUM_DICES; i++)
    {
        if(diceGotClicked(i))
        {
            arrayOfDices[i].toggleDiceSelection();
            gameStage = setGameStageToo;
        }
        arrayOfDices[i].DrawDiceImage();

    }
}

void ScoreBoard::PrintScoreBoard()
{
    for (int i = 0; i < NUM_OUTCOMES; i++)
    {
        for (int j = 0; j < NUM_PLAYERS; j++)
            scoreBoard[i][j].DrawScore();
    }
}

void ScoreBoard::DrawLeaderBoard()
{
    BeginDrawing();
    string playerOneScoreStr = "Player One: " + to_string(GetPlayerTotalScore(0));
    string playerTwoScoreStr = "Player Two: " + to_string(GetPlayerTotalScore(1));
    string playerThreeScoreStr = "Player Three: " + to_string(GetPlayerTotalScore(2));

    int p1 = GetPlayerTotalScore(0);
    int p2 = GetPlayerTotalScore(1);
    int p3 = GetPlayerTotalScore(2);

    if ( p1 > p2 && p1 > p3 )
    {
        DrawTextEx(testFont, playerOneScoreStr.c_str(),Vector2{320,266},16, 0, BLACK); //1st
        if(p2 > p3)
        {
            DrawTextEx(testFont, playerTwoScoreStr.c_str(),Vector2 {320,346},16, 0,BLACK);//2nd
            DrawTextEx(testFont, playerThreeScoreStr.c_str(),Vector2 {320,426},16, 0,BLACK);//3rd
        }
        else
        {
            DrawTextEx(testFont, playerThreeScoreStr.c_str(),Vector2 {320,346},16, 0,BLACK);//2nd
            DrawTextEx(testFont, playerTwoScoreStr.c_str(),Vector2 {320,426},16, 0,BLACK);//3rd
        }
    }
    else if ( p2 > p1 && p2 > p3 )
    {
        DrawTextEx(testFont, playerTwoScoreStr.c_str(),Vector2 {320,266},16, 0,BLACK);//1st
        if(p1 > p3)
        {
            DrawTextEx(testFont, playerOneScoreStr.c_str(),Vector2 {320,346},16, 0,BLACK);//2nd
            DrawTextEx(testFont, playerThreeScoreStr.c_str(),Vector2 {320,426},16, 0,BLACK);//3rd
        }
        else
        {
            DrawTextEx(testFont, playerThreeScoreStr.c_str(),Vector2 {320,346},16, 0,BLACK);//2nd
            DrawTextEx(testFont, playerOneScoreStr.c_str(),Vector2 {320,426},16, 0,BLACK);//3rd
        }


    }
    else if ( p3 > p1 && p3 > p2 )
    {
        DrawTextEx(testFont, playerThreeScoreStr.c_str(), Vector2{320, 266} ,16, 0,BLACK);//1st
        if(p1>p2)
        {
            DrawTextEx(testFont, playerOneScoreStr.c_str(),Vector2 {320, 346},16, 0,BLACK);//2nd
            DrawTextEx(testFont, playerTwoScoreStr.c_str(),Vector2 {320, 426},16, 0,BLACK);//3rd
        }
        else
        {
            DrawTextEx(testFont, playerTwoScoreStr.c_str(),Vector2 {320,346},16, 0,BLACK);//2nd
            DrawTextEx(testFont, playerOneScoreStr.c_str(),Vector2 {320,426},16, 0,BLACK);//3rd
        }

    }
    else if (p1 == p2 && p1 > p3)
    {
        DrawTextEx(testFont, playerOneScoreStr.c_str(),Vector2 {320,266},16, 0,BLACK); //1st
        DrawTextEx(testFont, playerTwoScoreStr.c_str(),Vector2 {320,346},16, 0,BLACK);//2nd
        DrawTextEx(testFont, playerThreeScoreStr.c_str(),Vector2 {320,426},16, 0,BLACK);//3rd
    }
    else if (p1 == p3 && p1 > p2)
    {
        DrawTextEx(testFont, playerOneScoreStr.c_str(),Vector2 {320,266},16, 0,BLACK); //1st
        DrawTextEx(testFont, playerThreeScoreStr.c_str(),Vector2 {320,346},16, 0,BLACK);//2nd
        DrawTextEx(testFont, playerTwoScoreStr.c_str(),Vector2 {320,426},16, 0,BLACK);//3rd
    }
    else if (p2 == p3 && p2 > p1)
    {
        DrawTextEx(testFont, playerTwoScoreStr.c_str(),Vector2 {320,266},16, 0,BLACK); //1st
        DrawTextEx(testFont, playerThreeScoreStr.c_str(),Vector2 {320,346},16, 0,BLACK);//2nd
        DrawTextEx(testFont, playerOneScoreStr.c_str(),Vector2 {320,426},16, 0,BLACK);//3rd
    }
    else
    {
        DrawTextEx(testFont, playerOneScoreStr.c_str(),Vector2 {320,266},16, 0,BLACK); //1st
        DrawTextEx(testFont, playerTwoScoreStr.c_str(),Vector2 {320,346},16, 0,BLACK);//2nd
        DrawTextEx(testFont, playerThreeScoreStr.c_str(),Vector2 {320,426},16, 0,BLACK);//3rd
    }

}


