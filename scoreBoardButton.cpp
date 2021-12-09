#include "scoreBoardButton.h"

//SCOREBOARDBUTTON CLASS
ScoreBoardButton::ScoreBoardButton()
{
    score = "";
    potentialScore = "";
    isClickable = false;
    scoreSet = false;
    location = ButtonLocation();
}

void ScoreBoardButton::DrawPotentialScore()
{
    DrawText(potentialScore.c_str(), location.GetXLow() + 46, location.GetYLow() + 30, 16, RED); 
    isClickable = true;  
}

void ScoreBoardButton::DrawScore()
{
    DrawText(score.c_str(), location.GetXLow() + 46, location.GetYLow() + 30, 16, WHITE); 
}
void ScoreBoardButton::SetScore(string score)
{
    this->score = score.c_str();
    scoreSet = true;
}
void ScoreBoardButton::SetPotentialScore(string score)
{
    potentialScore = score.c_str();
}
void ScoreBoardButton::SetClickState(bool clickState)
{
    isClickable = clickState;
}
void ScoreBoardButton::SetButtonLocation(ButtonLocation inLocation)
{
    location = inLocation;
}

void ScoreBoardButton::ResetButton()
{
    score = "";
    potentialScore = "";
    isClickable = false;
    scoreSet = false;
    
}

string ScoreBoardButton::GetScore(){return score;}

string ScoreBoardButton::GetPotentialScore(){return potentialScore;}

bool ScoreBoardButton::GetClickState(){return isClickable;}

ButtonLocation ScoreBoardButton::GetButtonLocation(){return location;}

bool ScoreBoardButton::IsScoreSet(){return scoreSet;}

////////////////////////////////////////////////////////////////////////////////
