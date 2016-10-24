#ifndef COORDINATE_H
#define COORDINATE_H

#define DEAD_END 0
#define NORTE 1
#define SUL 2
#define OESTE 4
#define LESTE 8

typedef struct {
	int y,x;
} Coordinate;

#endif
