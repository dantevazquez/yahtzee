#ifndef BUTTONLOCATION_H
#define BUTTONLOCATION_H

#include "include/raylib.h"
#include <iostream>

class ButtonLocation
{
private:
    Vector2 buttonCoordsLow;
    Vector2 buttonCoordsHigh;
public:
    ButtonLocation();
    ButtonLocation(float lowX, float lowY, float highX, float highY);
    ButtonLocation(float lowX, float lowY, float highX, float highY, int offsetX, int offsetY, int multiplier);

    int GetXLow();
    int GetYLow();
    int GetXHigh();
    int GetYHigh();

};

//List of locations of every button
const ButtonLocation ROLL_BUTTON(80,620,320,780);
const ButtonLocation DICE_ONE(40,304,104,368);
const ButtonLocation DICE_TWO(168,304,232,368);
const ButtonLocation DICE_THREE(296,304,360,368);
const ButtonLocation DICE_FOUR(104,432,168,496);
const ButtonLocation DICE_FIVE(232,432,296,496);
const ButtonLocation ONES_BUTTON_P1(504,68,596,128);
const ButtonLocation TWOS_BUTTON_P1(504,134,596,194);
const ButtonLocation THREES_BUTTON_P1(504,200,596,260);
const ButtonLocation FOURS_BUTTON_P1(504,266,596,326);
const ButtonLocation FIVES_BUTTON_P1(504,332,596,392);
const ButtonLocation SIXS_BUTTON_P1(504,398,596,458);
const ButtonLocation THREE_OF_A_KIND_BUTTON_P1(504,464,596,524);
const ButtonLocation FOUR_OF_A_KIND_BUTTON_P1(504,530,596,590);
const ButtonLocation STAIRS_BUTTON_P1(504,596,596,656);
const ButtonLocation FULL_HOUSE_BUTTON_P1(504,662,596,722);
const ButtonLocation YAHTZEE_BUTTON_P1(504,728,596,788);
const ButtonLocation ONES_BUTTON_P2(504,68,596,128,92,0,1);
const ButtonLocation TWOS_BUTTON_P2(504,134,596,194,92,0,1);
const ButtonLocation THREES_BUTTON_P2(504,200,596,260,92,0,1);
const ButtonLocation FOURS_BUTTON_P2(504,266,596,326,92,0,1);
const ButtonLocation FIVES_BUTTON_P2(504,332,596,392,92,0,1);
const ButtonLocation SIXS_BUTTON_P2(504,398,596,458,92,0,1);
const ButtonLocation THREE_OF_A_KIND_BUTTON_P2(504,464,596,524,92,0,1);
const ButtonLocation FOUR_OF_A_KIND_BUTTON_P2(504,530,596,590,92,0,1);
const ButtonLocation STAIRS_BUTTON_P2(504,596,596,656,92,0,1);
const ButtonLocation FULL_HOUSE_BUTTON_P2(504,662,596,722,92,0,1);
const ButtonLocation YAHTZEE_BUTTON_P2(504,728,596,788,92,0,1);
const ButtonLocation ONES_BUTTON_P3(504,68,596,128,92,0,2);
const ButtonLocation TWOS_BUTTON_P3(504,134,596,194,92,0,2);
const ButtonLocation THREES_BUTTON_P3(504,200,596,260,92,0,2);
const ButtonLocation FOURS_BUTTON_P3(504,266,596,326,92,0,2);
const ButtonLocation FIVES_BUTTON_P3(504,332,596,392,92,0,2);
const ButtonLocation SIXS_BUTTON_P3(504,398,596,458,92,0,2);
const ButtonLocation THREE_OF_A_KIND_BUTTON_P3(504,464,596,524,92,0,2);
const ButtonLocation FOUR_OF_A_KIND_BUTTON_P3(504,530,596,590,92,0,2);
const ButtonLocation STAIRS_BUTTON_P3(504,596,596,656,92,0,2);
const ButtonLocation FULL_HOUSE_BUTTON_P3(504,662,596,722,92,0,2);
const ButtonLocation YAHTZEE_BUTTON_P3(504,728,596,788,92,0,2);


#endif