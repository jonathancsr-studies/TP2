#include "include.h"

Mix_Music *somIntro = NULL;
Mix_Music *somFundo = NULL;
Mix_Chunk *somSpell_0 = NULL;
Mix_Chunk *somSpell_1 = NULL;
Mix_Chunk *somSpell_2 = NULL;
Mix_Chunk *somSpell_3 = NULL;
Mix_Chunk *somSpell_4 = NULL;

void abrir_audio(){
  Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
    atexit(Mix_CloseAudio);
    somIntro = Mix_LoadMUS("./som/intro.mp3");

    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
      atexit(Mix_CloseAudio);
      somFundo = Mix_LoadMUS("./som/fundo.mp3");


  Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
    atexit(Mix_CloseAudio);
    somSpell_0 = Mix_LoadWAV("./som/spell_0.ogg");

  Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
    atexit(Mix_CloseAudio);
    somSpell_1 = Mix_LoadWAV("./som/spell_1.ogg3");

  Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
    atexit(Mix_CloseAudio);
    somSpell_2 = Mix_LoadWAV("./som/spell_2.ogg");

  Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
    atexit(Mix_CloseAudio);
    somSpell_3 = Mix_LoadWAV("./som/spell_3.ogg");

  Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
    atexit(Mix_CloseAudio);
    somSpell_4 = Mix_LoadWAV("./som/spell_4.ogg");

}

void audioProjetil(){

}
