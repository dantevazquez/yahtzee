#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__

#include "scoreBoardButton.h"
#include <vector>

class ScoreBoard
{
    private:
        int numPlayers;
        int gameRound;    
        ScoreBoardButton scoreBoard[NUM_OUTCOMES][NUM_PLAYERS];

    public:
        ScoreBoard();
        //ScoreBoard(int numPlayers);
        int GetNumPlayers();
        void SetNumPlayers(int numPlayers);

        int GetGameRound();
        void incrementGameRound();

        void ShowPotentialScores(int player, Dice arrayOfDices[]);
        void CheckForScoreClick(int &player, int &gameStage, int setGameStageToo, Dice arrayOfDices[]);
        void PrintScoreBoard();
        int GetPlayerScore(int player);

        void InitScoreBoard();
        void ResetScoreBoard();

};

void drawLeaderBoard(ScoreBoard &scoreBoard);

#endif // __SCOREBOARD_H__