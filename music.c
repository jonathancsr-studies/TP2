#include "lib/include.h"


Mix_Music *somAmbiente = NULL;
Mix_Chunk *somWalk = NULL;

void abrir_audio(){
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
    atexit(Mix_CloseAudio);
    somAmbiente = Mix_LoadMUS("./song/Ambient_Song.mp3");

  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);
    atexit(Mix_CloseAudio);
    somWalk = Mix_LoadWAV("./song/somWalk.wav");

}

void somWalkfunc(){
}
