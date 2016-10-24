/*
 * algoritmo de geracao por busca em profundidade. O algoritimo "cava" o labirinto ate chegar numa deadend, e entao faz um backtrack ate ser possivel cavar novamente. Neste codigo utiliza-se recursao como pilha para o backtrack.
 */

#include "generator.h"

char *map;
int LINHAS, COLUNAS;

char mapAt(int y, int x){
	if(x < 0 || x >= COLUNAS || y < 0 || y >= LINHAS){
		return INVALID;
	}
	return map[y*COLUNAS +x];
}

char getRandDirection(int y, int x){	
	int size = 0;
	char directions[4];
	if(mapAt(y+1,x) == WALL && mapAt(y+2,x) == WALL && mapAt(y+1,x+1) == WALL && mapAt(y+1,x-1) == WALL){
		directions[size] = SUL;
		size += 1;
	}
	if(mapAt(y-1,x) == WALL && mapAt(y-2,x) == WALL && mapAt(y-1,x+1) == WALL && mapAt(y-1,x-1) == WALL){
		directions[size] = NORTE;
		size += 1;
	}
	if(mapAt(y,x-1) == WALL && mapAt(y,x-2) == WALL && mapAt(y+1,x-1) == WALL && mapAt(y-1,x-1) == WALL){
		directions[size] = OESTE;
		size += 1;
	}
	if(mapAt(y,x+1) == WALL && mapAt(y,x+2) == WALL && mapAt(y-1,x+1) == WALL && mapAt(y+1,x+1) == WALL){
		directions[size] = LESTE;
		size += 1;
	}
	
	if(size == 0)return DEAD_END;
	else {
		return directions[rand()%size];
	}
}

void dig(int y, int x){
	int i;
	map[y*COLUNAS +x] = SPACE;
	for(i=0;i<4;i++){
		int direction = getRandDirection(y,x);
		if(direction == NORTE){
			dig(y-1,x);
		} else if(direction == SUL){
			dig(y+1,x);
		} else if(direction == LESTE){
			dig(y,x+1);
		} else if(direction == OESTE){
			dig(y,x-1);
		} else return;
	}
}

void dfsGenerate(Labirinto l){
	LINHAS = l.linhas;
	COLUNAS = l.colunas;
	map = l.mapa;
	dig(1,1);
}
