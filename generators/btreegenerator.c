#include "generator.h"

void btreeGenerate(Labirinto l){
	int y,x;
	for(x=1;x<l.colunas-1;x+=1){
		l.mapa[1*l.colunas + x] = SPACE;
	}
	for(y=1;y<l.linhas-1;y+=1){
		l.mapa[y*l.colunas + 1] = SPACE;
	}
	for(y=2;y<l.linhas-1;y+=2){
		for(x=2;x<l.colunas-1;x+=2){
			l.mapa[y*l.colunas + x] = SPACE;
			if(rand() % 2){
				l.mapa[y*l.colunas + x-1] = SPACE;
			} else {
				l.mapa[(y-1)*l.colunas +x] = SPACE;	
			}
		}
	}
}
