#ifndef DICEARRAY_H
#define DICEARRAY_H

#include "dice.h"
#include "buttons.h"

const int NUM_DICES = 5;

//Stages of the game (Should probably move this elsewhere)
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

//Draw dices to screen
void drawDices(Dice diceArray[]);

//Executes first roll in turn
void firstRoll(Dice arrayOfDices[]);

//Executes second roll in turn
void secondRoll(Dice arrayOfDices[]);

//Executes third roll in turn
void thirdRoll(Dice arrayOfDices[]);

//returns if player selected a dice
bool IsADiceSelected(Dice arrayOfDices[]);

//Resets the dices back to six
void resetDices(Dice arrayOfDices[]);

//Gives a dice slot to each dice
void initializeSlots(Dice arrayOfDices[]);

//Looks at dices and returns a score based on the dices
int getPotentialScores(Outcomes outcome, Dice arrayOfDices[]);

//The following fucntions looks for each winning roll
//returns 0 if nothing found
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
//Checkers end here ^

//Turns and integer into an enum Outcomes
Outcomes intToOutcome(int i);

//Returns location of where score is going to be printed in the board
ButtonLocation intToButtonLocation(int outcome, int player);



#endif