#ifndef BUTTONS_H
#define BUTTONS_H

#include "buttonLocation.h"
#include "dice.h"

bool isMouseClickingButton (ButtonLocation buttonLocation);

bool diceGotClicked(int diceSlot);

void drawRollButton();

void drawScoreBoard(Texture2D scoreBoardTexture);

#endif