#ifndef __SOUNDS_H__
#define __SOUNDS_H__

#include <string>
#include "raylib.h"
using namespace std;

enum GameSound
{
    YAHTZEE,
    INTRO,
};

class GameSounds
{
    private:
        Sound yahtzee;
        Sound introSong;
    
    public:
        GameSounds();
        void UnloadGameSounds();
        void PlayGameSound(GameSound gameSound);
        
    
};



#endif // __SOUNDS_H__