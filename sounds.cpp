#include "sounds.h"
GameSounds::GameSounds()
{
    yahtzee = LoadSound("C:/Users/prems/Desktop/Games/FirstGame/resources/yahtzee_sound.wav");
    introSong = LoadSound("C:/Users/prems/Desktop/Games/FirstGame/resources/intro_sound.wav");

}
void GameSounds::UnloadGameSounds()
{
    UnloadSound(yahtzee);
    UnloadSound(introSong);
}
void GameSounds::PlayGameSound(GameSound gameSound)
{
    if (gameSound == YAHTZEE) PlaySound(yahtzee);
    if (gameSound == INTRO) PlaySound(introSong);
}