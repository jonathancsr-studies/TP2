#ifndef GENERATOR_H
#define GENERATOR_H

#include "../commons/coordinates.h"
#include "../commons/labirinto.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>



void dfsGenerate(Labirinto l);
void btreeGenerate(Labirinto l);

#endif
