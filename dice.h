#ifndef DICE_H
#define DICE_H

#include "include/raylib.h"
#include <string>
#include <iostream>
using namespace std;

class Dice
{
    private:

        //current number a dice is in
        int diceNumber;

        //slot that the dice is in
        int slot;

        bool isSelected;

        //image of the dice
        Texture2D diceImage;

        //Images of each side of a dice.
        Image test1 = LoadImage("C:/Users/prems/Desktop/Games/FirstGame/resources/dice_1.png");
        Image test2 = LoadImage("C:/Users/prems/Desktop/Games/FirstGame/resources/dice_2.png");
        Image test3 = LoadImage("C:/Users/prems/Desktop/Games/FirstGame/resources/dice_3.png");
        Image test4 = LoadImage("C:/Users/prems/Desktop/Games/FirstGame/resources/dice_4.png");
        Image test5 = LoadImage("C:/Users/prems/Desktop/Games/FirstGame/resources/dice_5.png");
        Image test6 = LoadImage("C:/Users/prems/Desktop/Games/FirstGame/resources/dice_6.png");
        Texture2D dices[6];
       

    public:
        //default constructor. In addition to the dice properties, the constructor load every
        //possible image a dice can use
        Dice();

        //Alternate contructor (Probably wont be used, but we'll see)
        Dice(int diceSlot, int diceNumber, Texture2D diceNumberImage);

        //Setters
        void SetDiceSlot (int slot);
        void SetDiceImageAndNumber (int diceNumber);
        void toggleDiceSelection();
        void SetDiceSelection(bool isSelected);

        //Getters
        int GetDiceSlot();
        int GetDiceNumber();
        bool isDiceSelected();
        
        //This method prints the dice to the screen
        void DrawDiceImage();
        
};

//Generates a random dice number from 1-6
int getRandomDiceNumber();

enum DiceSlot
{
    SLOT_ONE,
    SLOT_TWO,
    SLOT_THREE,
    SLOT_FOUR,
    SLOT_FIVE,
    
};

enum DiceNumber
{
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
};






#endif