#include "buttons.h"

bool isMouseClickingButton (ButtonLocation buttonLocation)
{
    int xLow = buttonLocation.GetXLow();
    int xHigh = buttonLocation.GetXHigh();
    int yLow = buttonLocation.GetYLow();
    int yHigh = buttonLocation.GetYHigh();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        if(GetMouseX() >= xLow && GetMouseX() <= xHigh && GetMouseY() >= yLow && GetMouseY() <=yHigh)
        {
            return true;
        }
    }

    return false;
}

bool diceGotClicked(int diceSlot)
{
   if(diceSlot == ONE)
    {
        if(isMouseClickingButton(DICE_ONE))
        {
            return true;
        }
        return false;
    }

    if(diceSlot == TWO)
    {
        if(isMouseClickingButton(DICE_TWO))
        {
            return true;
        }
        return false;
    }

    if(diceSlot == THREE)
    {
        if(isMouseClickingButton(DICE_THREE))
        {
            return true;
        }
        return false;
    }   

    if(diceSlot == FOUR)
    {
        if(isMouseClickingButton(DICE_FOUR))
        {
            return true;
        }
        return false;
    }

    if(diceSlot == FIVE)
    {
        if(isMouseClickingButton(DICE_FIVE))
        {
            return true;
        }
        return false;
    }

    cout<<"HUGE ERROR!"<<endl;
    return false;
}

void drawRollButton()
{
    DrawEllipse(200, 700, 120, 80, MAROON);
}

void drawScoreBoard(Texture2D scoreBoardtexture)
{
    DrawTexture(scoreBoardtexture, 400, 0, RAYWHITE);
}
