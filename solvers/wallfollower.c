#include "solver.h"

const char WIND_ROSE[4] =  {NORTE,OESTE,SUL,LESTE};
int windIndex=0;

char *map;
int linhas, colunas;

char charAt(int y, int x){
	if(x >= colunas || x < 0 || y >= linhas || y<0){
		return INVALID;
	}
	return map[y*colunas + x];
}

Coordinate coordinateAtRight(Coordinate c, int direction){
	if(direction == OESTE){
		c.y -= 1;
	} else if(direction == LESTE){
		c.y += 1;
	} else if(direction == NORTE){
		c.x += 1;
	} else {
		c.x -= 1;
	}
	return c;
}

Coordinate coordinateAtFront(Coordinate c, int direction){
	if(direction == OESTE){
		c.x -= 1;
	} else if(direction == LESTE){
		c.x += 1;
	} else if(direction == NORTE){
		c.y -= 1;
	} else {
		c.y += 1;
	}
	return c;
}

char charAtCoordinate(Coordinate c){
	return map[c.y*colunas + c.x];
}

SolvingInfo wallFollow(Labirinto l, Coordinate begin, void(*action)(int y, int x)){
	map=l.mapa;
	linhas=l.linhas;
	colunas=l.colunas;
	
	Coordinate position = begin;
	int direction=OESTE;	

	while(!haveMask(charAt(position.y,position.x), END)){
		Coordinate right = coordinateAtRight(position, direction);
		Coordinate front = coordinateAtFront(position, direction);
		if(haveMask(charAtCoordinate(right), WALL)){
			if(haveMask(charAtCoordinate(front), WALL)){
				direction = WIND_ROSE[(++windIndex)%4];
			} else {
				position = front;
				if(action!=NULL)action(position.y, position.x);
			}
		} else {
			direction = WIND_ROSE[(--windIndex+4)%4];
			position = right;
			if(action!=NULL)action(position.y, position.x);
		}
	}
}
