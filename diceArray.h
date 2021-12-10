#ifndef DICEARRAY_H
#define DICEARRAY_H

#include "dice.h"
#include "buttons.h"

const int NUM_DICES = 5;

enum GameStage
{
    PRE_ROLL,
    FIRST_ROLL,
    FIRST_CHECK,
    SECOND_ROLL,
    SECOND_CHECK,
    THIRD_ROLL,
    END_OF_TURN,
    
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


void drawDices(Dice diceArray[]);
void firstRoll(Dice arrayOfDices[]);
void secondRoll(Dice arrayOfDices[]);
void thirdRoll(Dice arrayOfDices[]);

bool IsADiceSelected(Dice arrayOfDices[]);
void resetDices(Dice arrayOfDices[]);
void initializeSlots(Dice arrayOfDices[]);
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



#endif