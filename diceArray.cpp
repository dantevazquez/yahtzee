#include "diceArray.h"

void drawDices(Dice arrayOfDices[NUM_DICES])
{
    for (int i = 0; i < NUM_DICES; i++)
    {
        arrayOfDices[i].DrawDiceImage();
    }  
}

void firstRoll(Dice arrayOfDices[NUM_DICES])
{
    for (int i = 0; i < NUM_DICES; i++)
    {
        arrayOfDices[i].SetDiceImageAndNumber(getRandomDiceNumber());
        arrayOfDices[i].DrawDiceImage();
    }
}

void secondRoll(Dice arrayOfDices[NUM_DICES])
{
    for(int i = 0; i < NUM_DICES; i++)
    {
        if(arrayOfDices[i].isDiceSelected())
        {
            arrayOfDices[i].SetDiceImageAndNumber(getRandomDiceNumber());
            arrayOfDices[i].DrawDiceImage();
            arrayOfDices[i].toggleDiceSelection();
                    
        }
    }
                
}

void thirdRoll(Dice arrayOfDices[NUM_DICES])
{
    for(int i = 0; i < NUM_DICES; i++)
    {
        if(arrayOfDices[i].isDiceSelected())
        {
            arrayOfDices[i].SetDiceImageAndNumber(getRandomDiceNumber());
            arrayOfDices[i].DrawDiceImage();
            arrayOfDices[i].toggleDiceSelection();
                    
        }
    }
                
}



bool IsADiceSelected(Dice arrayOfDices[NUM_DICES])
{
    for (int i = 0; i < NUM_DICES; i++)
    {
        if(arrayOfDices[i].isDiceSelected())
        {
            return true;
        }

    }
    return false;
}


void resetDices(Dice arrayOfDices[NUM_DICES])
{
    for(int i = 0; i < NUM_DICES; i++)
    {
      
        arrayOfDices[i].SetDiceImageAndNumber(SIX);
        arrayOfDices[i].SetDiceSelection(false);
        arrayOfDices[i].DrawDiceImage();
    }
                
}

void initializeSlots(Dice arrayOfDices[])
{
    for(int i = 0; i < NUM_DICES; i++)
    {
        arrayOfDices[i].SetDiceSlot(i);
    }
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
    int numOnes = 0;
    int numTwos = 0;
    int numThrees = 0;
    int numFours = 0;
    int numFives = 0;
    int numSixs = 0;

    for (int i = 0; i < NUM_DICES; i++)
    {
        if(arrayOfDices[i].GetDiceNumber() == ONE) numOnes++;
        if(arrayOfDices[i].GetDiceNumber() == TWO) numTwos++;
        if(arrayOfDices[i].GetDiceNumber() == THREE) numThrees++;
        if(arrayOfDices[i].GetDiceNumber() == FOUR) numFours++;
        if(arrayOfDices[i].GetDiceNumber() == FIVE) numFives++;
        if(arrayOfDices[i].GetDiceNumber() == SIX) numSixs++;
    }

    if (numOnes == 3 || numTwos == 3 || numThrees == 3 || numFours == 3 
        || numFives == 3 || numSixs == 3) return 10;
         
    return 0;

}
int fourOfAKindCheck(Dice arrayOfDices[])
{
    int numOnes = 0;
    int numTwos = 0;
    int numThrees = 0;
    int numFours = 0;
    int numFives = 0;
    int numSixs = 0;

    for (int i = 0; i < NUM_DICES; i++)
    {
        if(arrayOfDices[i].GetDiceNumber() == ONE) numOnes++;
        if(arrayOfDices[i].GetDiceNumber() == TWO) numTwos++;
        if(arrayOfDices[i].GetDiceNumber() == THREE) numThrees++;
        if(arrayOfDices[i].GetDiceNumber() == FOUR) numFours++;
        if(arrayOfDices[i].GetDiceNumber() == FIVE) numFives++;
        if(arrayOfDices[i].GetDiceNumber() == SIX) numSixs++;
    }

    if (numOnes == 4 || numTwos == 4 || numThrees == 4 || numFours == 4 
        || numFives == 4 || numSixs == 4) return 40;
        
    return 0;

}
int stairsCheck(Dice arrayOfDices[])
{
    int numOnes = 0;
    int numTwos = 0;
    int numThrees = 0;
    int numFours = 0;
    int numFives = 0;
    int numSixs = 0;

    for (int i = 0; i < NUM_DICES; i++)
    {
        if(arrayOfDices[i].GetDiceNumber() == ONE) numOnes++;
        if(arrayOfDices[i].GetDiceNumber() == TWO) numTwos++;
        if(arrayOfDices[i].GetDiceNumber() == THREE) numThrees++;
        if(arrayOfDices[i].GetDiceNumber() == FOUR) numFours++;
        if(arrayOfDices[i].GetDiceNumber() == FIVE) numFives++;
        if(arrayOfDices[i].GetDiceNumber() == SIX) numSixs++;
    }

    if (numOnes == 1 && numTwos == 1 && numThrees == 1 && numFours == 1 
        && numFives == 1 && numSixs == 0) return 25;
        
    if (numOnes == 0 && numTwos == 1 && numThrees == 1 && numFours == 1 
        && numFives == 1 && numSixs == 1) return 25;
        
    if (numOnes == 1 && numTwos == 0 && numThrees == 1 && numFours == 1 
        && numFives == 1 && numSixs == 1) return 25;
        
       
    return 0;

}
int fullHouseCheck(Dice arrayOfDices[])
{
    //check for 3 of a kind
    //if a number is found 2 times return full house
    if (threeOfAKindCheck(arrayOfDices) == 10)
    {
        int numOnes = 0;
        int numTwos = 0;
        int numThrees = 0;
        int numFours = 0;
        int numFives = 0;
        int numSixs = 0;

        for (int i = 0; i < NUM_DICES; i++)
        {
            if(arrayOfDices[i].GetDiceNumber() == ONE) numOnes++;
            if(arrayOfDices[i].GetDiceNumber() == TWO) numTwos++;
            if(arrayOfDices[i].GetDiceNumber() == THREE) numThrees++;
            if(arrayOfDices[i].GetDiceNumber() == FOUR) numFours++;
            if(arrayOfDices[i].GetDiceNumber() == FIVE) numFives++;
            if(arrayOfDices[i].GetDiceNumber() == SIX) numSixs++;
        }

        if (numOnes == 2 || numTwos == 2 || numThrees == 2 || numFours == 2 
            || numFives == 2 || numSixs == 2) return 30;
    }
    return 0;

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

