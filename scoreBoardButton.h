#ifndef __SCOREBOARDBUTTON_H__
#define __SCOREBOARDBUTTON_H__

#include "diceArray.h"

const int NUM_PLAYERS = 3;
const int NUM_OUTCOMES = 11;

class ScoreBoardButton
{
    private:
        string score;
        string potentialScore;
        bool isClickable;
        bool scoreSet;
        ButtonLocation location;
        
    public:
        ScoreBoardButton();
        void DrawPotentialScore();
        void DrawScore();
        void SetScore(string score);
        void SetPotentialScore(string score);
        void SetClickState(bool clickState);
        void SetButtonLocation(ButtonLocation inLocation);
        string GetScore();
        string GetPotentialScore();
        bool GetClickState();
        ButtonLocation GetButtonLocation();
        bool IsScoreSet();
};





#endif // __SCOREBOARDBUTTON_H__