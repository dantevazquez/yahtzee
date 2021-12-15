#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__

#include "scoreBoardButton.h"
#include <vector>

extern Font testFont;

class ScoreBoard
{
    private:
        int numPlayers;
        int gameRound;
        int gameStage;    
        ScoreBoardButton scoreBoard[NUM_OUTCOMES][NUM_PLAYERS];

    public:
        ScoreBoard();

        //Getters
        int GetNumPlayers();
        int GetGameRound();
        int GetGameStage();
        int GetPlayerTotalScore(int player);

        //Setters
        void SetGameStage(int gameStage);
        void SetNumPlayers(int numPlayers);
        //ScoreBoard Methods
        void ShowPotentialScores(int player, Dice arrayOfDices[]);
        void CheckForScoreClick(int &player, Dice arrayOfDices[]);
        void PrintScoreBoard();
        void InitScoreBoard();
        void ResetScoreBoard();
        void checkIfDiceGotClicked(Dice arrayOfDices[], int setGameStageToo);
        void DrawLeaderBoard();

};

#endif // __SCOREBOARD_H__