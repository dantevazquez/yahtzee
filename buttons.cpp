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
   if(diceSlot == SLOT_ONE)
    {
        if(isMouseClickingButton(DICE_ONE_BUTTON))
        {
            return true;
        }
        return false;
    }

    if(diceSlot == SLOT_TWO)
    {
        if(isMouseClickingButton(DICE_TWO_BUTTON))
        {
            return true;
        }
        return false;
    }

    if(diceSlot == SLOT_THREE)
    {
        if(isMouseClickingButton(DICE_THREE_BUTTON))
        {
            return true;
        }
        return false;
    }   

    if(diceSlot == SLOT_FOUR)
    {
        if(isMouseClickingButton(DICE_FOUR_BUTTON))
        {
            return true;
        }
        return false;
    }

    if(diceSlot == SLOT_FIVE)
    {
        if(isMouseClickingButton(DICE_FIVE_BUTTON))
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
