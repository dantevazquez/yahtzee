#include "diceArray.h"

void drawDices(Dice arrayOfDices[NUM_DICES])
{
    for (int i = 0; i < 6; i++)
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

void checkIfDiceGotClicked(Dice arrayOfDices[NUM_DICES], int &gameStage, int setGameStageToo)
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
