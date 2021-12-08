#ifndef __SCOREBOARDBUTTON_H__
#define __SCOREBOARDBUTTON_H__

#include "dice.h"
#include "buttonLocation.h"
#include "buttons.h"
#include "diceArray.h"

const int NUM_PLAYERS = 3;
const int NUM_OUTCOMES = 11;

class ScoreBoardButton
{
    private:
        string score;
        string potentialScore;
        bool isClickable;
        bool scoreSet;
        ButtonLocation location;
        
    public:
        ScoreBoardButton();
        void DrawPotentialScore();
        void DrawScore();
        void SetScore(string score);
        void SetPotentialScore(string score);
        void SetClickState(bool clickState);
        void SetButtonLocation(ButtonLocation inLocation);
        string GetScore();
        string GetPotentialScore();
        bool GetClickState();
        ButtonLocation GetButtonLocation();
        bool IsScoreSet();
};

enum Outcomes
{
    ONES,
    TWOS,
    THREES,
    FOURS,
    FIVES,
    SIXS,
    THREE_OF_A_KIND,
    FOUR_OF_A_KIND,
    STAIRS,
    FULL_HOUSE,
    YAHTZEE,

};

//SCOREBOARD FUNCTIONS
void ConstructScoreBoard(ScoreBoardButton scoreBoard[][NUM_PLAYERS]);
void ShowPotentialScores(int player, Dice arrayOfDices[], ScoreBoardButton scoreBoard[][NUM_PLAYERS]);
void CheckForScoreClick(int &player, int &gameStage, int setGameStageToo, Dice arrayOfDices[], ScoreBoardButton scoreBoard[][NUM_PLAYERS]);
void PrintScoreBoard(ScoreBoardButton scoreBoard[][NUM_PLAYERS]);
int getPotentialScores(Outcomes outcome, Dice arrayOfDices[]);
int onesCheck(Dice arrayOfDices[]);
int twosCheck(Dice arrayOfDices[]);
int threesCheck(Dice arrayOfDices[]);
int foursCheck(Dice arrayOfDices[]);
int fivesCheck(Dice arrayOfDices[]);
int sixsCheck(Dice arrayOfDices[]);
int threeOfAKindCheck(Dice arrayOfDices[]);
int fourOfAKindCheck(Dice arrayOfDices[]);
int stairsCheck(Dice arrayOfDices[]);
int fullHouseCheck(Dice arrayOfDices[]);
int yahtzeeCheck(Dice arrayOfDices[]);
Outcomes intToOutcome(int i);
ButtonLocation intToButtonLocation(int outcome, int player);

#endif // __SCOREBOARDBUTTON_H__