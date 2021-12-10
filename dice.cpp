#include "dice.h"

using namespace std;

Dice::Dice()
{
    slot = SLOT_ONE;
    diceNumber = SIX;
    isSelected = false;

    dices[0] = LoadTextureFromImage(test1);
    dices[1] = LoadTextureFromImage(test2);
    dices[2] = LoadTextureFromImage(test3);
    dices[3] = LoadTextureFromImage(test4);
    dices[4] = LoadTextureFromImage(test5);
    dices[5] = LoadTextureFromImage(test6);
    diceImage = dices[5];
    
}

Dice::Dice(int diceSlot, int diceNumber, Texture2D diceNumberImage)
{
    this->slot = diceSlot;
    this->diceNumber = diceNumber;
    this->diceImage = diceNumberImage;
}
        
void Dice::SetDiceImageAndNumber (int diceNumber)
{   
    diceImage = dices[diceNumber];
    this->diceNumber = diceNumber;
}

void Dice::SetDiceSlot(int slot)
{
    this->slot = slot;
}

void Dice::toggleDiceSelection()
{
    if(isDiceSelected())
        isSelected = false;
    else
        isSelected = true;
}
    
int Dice::GetDiceSlot()
{
    return slot;
}

int Dice::GetDiceNumber()
{
    return diceNumber;
}

bool Dice::isDiceSelected()
{
    if(isSelected == true) return true;
    return false;
}

void Dice::DrawDiceImage()
{

    switch (slot)
    {
        case SLOT_ONE:

            if(!isDiceSelected())
                DrawTexture(diceImage, 40, 304, RAYWHITE);
            else
                DrawTexture(diceImage, 40, 304, GREEN);
            break;

        case SLOT_TWO:
            
            if(!isDiceSelected())
                DrawTexture(diceImage, 168, 304, RAYWHITE);
            else 
                DrawTexture(diceImage, 168, 304, GREEN);
            break;
        
        case SLOT_THREE:

            if(!isDiceSelected())
                DrawTexture(diceImage, 296, 304, RAYWHITE);
            else
                DrawTexture(diceImage, 296, 304, GREEN);
            break;

        case SLOT_FOUR:
            if(!isDiceSelected())
                DrawTexture(diceImage, 104, 432, RAYWHITE);
            else
                DrawTexture(diceImage, 104, 432, GREEN);
            break;

        case SLOT_FIVE:
            if(!isDiceSelected())
                DrawTexture(diceImage, 232, 432, RAYWHITE);
            else
                DrawTexture(diceImage, 232, 432, GREEN);
            break;
        
        default:
            cout<<"HAY UN PROBLEMA ESSE!"<<endl;
        
    }
}

void Dice::SetDiceSelection(bool isSelected)
{
    this->isSelected = isSelected;
}

int getRandomDiceNumber()
{
    return GetRandomValue(0,5);
}

















