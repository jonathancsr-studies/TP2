#ifndef ARQUIVADOR_H
#define ARQUIVADOR_H

#include "../commons/labirinto.h"
#include <stdio.h>

#define WALL_CHAR 'X'
#define SPACE_CHAR ' '
#define BEGIN_CHAR 'B'
#define END_CHAR 'E'

Labirinto readLabirinto(char* pathToFile);
void saveLabirinto(char* pathToFile, Labirinto labirinto);

#endif
