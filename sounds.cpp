#include "sounds.h"
GameSounds::GameSounds()
{
    yahtzee = LoadSound("../resources/yahtzee_sound.wav");
    introSong = LoadSound("../resources/intro_sound.wav");

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