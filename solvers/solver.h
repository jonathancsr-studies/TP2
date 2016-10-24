#ifndef SOLVER_H
#define SOLVER_H

#include "../commons/coordinates.h"
#include "../commons/bits.h"
#include "../commons/labirinto.h"


#define LEFT 0
#define RIGHT 1

typedef struct{
	int nsteps;
	int nrepeatedsteps;

} SolvingInfo;


SolvingInfo wallFollow(Labirinto l, Coordinate begin, void(*action)(int y, int x));

#endif
