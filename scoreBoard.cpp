#include "scoreBoard.h"

ScoreBoard::ScoreBoard()
{
    numPlayers = 0;
    gameRound = 0;

    for(int i = 0; i < NUM_OUTCOMES; i++)
    {
        for(int j = 0; j < NUM_PLAYERS; j++)
            scoreBoard[i][j].SetButtonLocation(intToButtonLocation(i,j));
    }
    
}


int ScoreBoard::GetNumPlayers()
{
    return numPlayers;
}
void ScoreBoard::SetNumPlayers(int numPlayers)
{
    this->numPlayers = numPlayers;
}

int ScoreBoard::GetGameRound()
{
    return gameRound;
}

void ScoreBoard::ShowPotentialScores(int player, Dice arrayOfDices[])
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

void ScoreBoard::PrintScoreBoard()
{
    for (int i = 0; i < NUM_OUTCOMES; i++)
    {
        for (int j = 0; j < NUM_PLAYERS; j++)
            scoreBoard[i][j].DrawScore();
    }
}

void ScoreBoard::CheckForScoreClick(int &player, int &gameStage, int setGameStageToo, Dice arrayOfDices[])
{
    for (int i = 0; i < NUM_OUTCOMES; i++)
    {
        if (isMouseClickingButton(scoreBoard[i][player].GetButtonLocation()) 
        && scoreBoard[i][player].GetClickState() && !scoreBoard[i][player].IsScoreSet())
        {
            scoreBoard[i][player].SetScore(to_string(getPotentialScores(intToOutcome(i), arrayOfDices)));
            scoreBoard[i][player].SetClickState(false);

            gameRound++;
            gameStage = setGameStageToo;
            drawDices(arrayOfDices);
            return;
        }
    }
}

int ScoreBoard::GetPlayerScore(int player)
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

void drawLeaderBoard(ScoreBoard &scoreBoard)
{
    BeginDrawing();
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
        DrawText(playerTwoScoreStr.c_str(), 280,260,16,BLACK);//1st
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
        DrawText(playerThreeScoreStr.c_str(), 280,260,16,BLACK);//1st
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
    else if (p1 == p2 && p1 > p3)
    {
        DrawText(playerOneScoreStr.c_str(), 280,260,16,BLACK); //1st
        DrawText(playerTwoScoreStr.c_str(), 280,340,16,BLACK);//2nd
        DrawText(playerThreeScoreStr.c_str(),280,420,16,BLACK);//3rd
    }
    else if (p1 == p3 && p1 > p2)
    {
        DrawText(playerOneScoreStr.c_str(), 280,260,16,BLACK); //1st
        DrawText(playerThreeScoreStr.c_str(), 280,340,16,BLACK);//2nd
        DrawText(playerTwoScoreStr.c_str(),280,420,16,BLACK);//3rd
    }
    else if (p2 == p3 && p2 > p1)
    {
        DrawText(playerTwoScoreStr.c_str(), 280,260,16,BLACK); //1st
        DrawText(playerThreeScoreStr.c_str(), 280,340,16,BLACK);//2nd
        DrawText(playerOneScoreStr.c_str(),280,420,16,BLACK);//3rd
    }
    else
    {
        DrawText(playerOneScoreStr.c_str(), 280,260,16,BLACK); //1st
        DrawText(playerTwoScoreStr.c_str(), 280,340,16,BLACK);//2nd
        DrawText(playerThreeScoreStr.c_str(),280,420,16,BLACK);//3rd
    }

}


