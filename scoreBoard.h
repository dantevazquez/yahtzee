#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__

#include "scoreBoardButton.h"

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



#endif // __SCOREBOARD_H__