#ifndef BUTTONLOCATION_H
#define BUTTONLOCATION_H

#include "dice.h"

class ButtonLocation
{
private:
    Vector2 buttonCoordsLow;
    Vector2 buttonCoordsHigh;
public:
    ButtonLocation();
    ButtonLocation(float lowX, float lowY, float highX, float highY);
    ButtonLocation(float lowX, float lowY, float highX, float highY, 
                    int offsetX, int offsetY, int multiplier);

    int GetXLow();
    int GetYLow();
    int GetXHigh();
    int GetYHigh();
    Vector2 GetCoordsLow();

};

//List of locations of every button

//Game Scene
const ButtonLocation ROLL_BUTTON(70,520,330,780);
const ButtonLocation DICE_ONE_BUTTON(40,304,104,368);
const ButtonLocation DICE_TWO_BUTTON(168,304,232,368);
const ButtonLocation DICE_THREE_BUTTON(296,304,360,368);
const ButtonLocation DICE_FOUR_BUTTON(104,432,168,496);
const ButtonLocation DICE_FIVE_BUTTON(232,432,296,496);
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
const ButtonLocation ONES_BUTTON_P2(504,68,596,128,100,0,1);
const ButtonLocation TWOS_BUTTON_P2(504,134,596,194,100,0,1);
const ButtonLocation THREES_BUTTON_P2(504,200,596,260,100,0,1);
const ButtonLocation FOURS_BUTTON_P2(504,266,596,326,100,0,1);
const ButtonLocation FIVES_BUTTON_P2(504,332,596,392,100,0,1);
const ButtonLocation SIXS_BUTTON_P2(504,398,596,458,100,0,1);
const ButtonLocation THREE_OF_A_KIND_BUTTON_P2(504,464,596,524,100,0,1);
const ButtonLocation FOUR_OF_A_KIND_BUTTON_P2(504,530,596,590,100,0,1);
const ButtonLocation STAIRS_BUTTON_P2(504,596,596,656,100,0,1);
const ButtonLocation FULL_HOUSE_BUTTON_P2(504,662,596,722,100,0,1);
const ButtonLocation YAHTZEE_BUTTON_P2(504,728,596,788,100,0,1);
const ButtonLocation ONES_BUTTON_P3(504,68,596,128,100,0,2);
const ButtonLocation TWOS_BUTTON_P3(504,134,596,194,100,0,2);
const ButtonLocation THREES_BUTTON_P3(504,200,596,260,100,0,2);
const ButtonLocation FOURS_BUTTON_P3(504,266,596,326,100,0,2);
const ButtonLocation FIVES_BUTTON_P3(504,332,596,392,100,0,2);
const ButtonLocation SIXS_BUTTON_P3(504,398,596,458,100,0,2);
const ButtonLocation THREE_OF_A_KIND_BUTTON_P3(504,464,596,524,100,0,2);
const ButtonLocation FOUR_OF_A_KIND_BUTTON_P3(504,530,596,590,100,0,2);
const ButtonLocation STAIRS_BUTTON_P3(504,596,596,656,100,0,2);
const ButtonLocation FULL_HOUSE_BUTTON_P3(504,662,596,722,100,0,2);
const ButtonLocation YAHTZEE_BUTTON_P3(504,728,596,788,100,0,2);

//Winners Scene
const ButtonLocation BUTTON_PLAY_AGAIN(220,500,380,580);
const ButtonLocation BUTTON_EXIT(420,500,580,580);
const ButtonLocation BUTTON_FIRST_PLACE(240,240,560,380);
const ButtonLocation BUTTON_SECOND_PLACE(240,320,560,300);
const ButtonLocation BUTTON_THIRD_PLACE(240,400,560,460);

//Title screen
const ButtonLocation BUTTON_ONE_PLAYER(150,500,250,600);
const ButtonLocation BUTTON_TWO_PLAYER(350,500,450,600);
const ButtonLocation BUTTON_THREE_PLAYER(550,500,650,600);





#endif