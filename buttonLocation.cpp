#include "buttonLocation.h"


ButtonLocation::ButtonLocation()
{
    buttonCoordsLow = {0,0};
    buttonCoordsHigh = {0,0};
}
ButtonLocation::ButtonLocation(float lowX, float lowY, float highX, float highY)
{
    buttonCoordsLow = {lowX, lowY};
    buttonCoordsHigh = {highX, highY};
}
ButtonLocation::ButtonLocation(float lowX, float lowY, float highX, float highY, int offsetX, int offsetY, int multipler)
{
    buttonCoordsLow = {lowX + (offsetX * multipler), lowY+ (offsetY * multipler)};
    buttonCoordsHigh = {highX+ (offsetX * multipler), highY+ (offsetY * multipler)};
}

int ButtonLocation:: GetXLow(){return buttonCoordsLow.x;}
    
int ButtonLocation:: GetYLow(){return buttonCoordsLow.y;}

int ButtonLocation:: GetXHigh(){return buttonCoordsHigh.x;}

int ButtonLocation:: GetYHigh(){return buttonCoordsHigh.y;}


