#include "solvers/solver.h"
#include "io/arquivador.h"
#include "io/tui.h"

Labirinto labirinto;


void printyx(int y, int x){
	printf("%d %d\n",y,x);
}

void markyx(int y, int x){
	labirinto.mapa[y*labirinto.colunas + x] ^= VISITED;
}

int main(int argc, char**argv){
	if(argc >= 2){
		labirinto = readLabirinto(argv[1]);
	} else {
		puts("caminho de um arquivo labirinto deve ser passado por parametro");
		exit(1);
	}
	
	Coordinate begin = {labirinto.beginy,labirinto.beginx};
	SolvingInfo info = wallFollow(labirinto, begin, markyx);

	int y,x;
   	for(y=0;y<labirinto.linhas;y++){
   		int offset = y*labirinto.colunas;
    	for(x=0;x<labirinto.colunas;x++){
    		char c = labirinto.mapa[offset +x];
			if(c == WALL){
				c = WALL_CHAR;
			}else if(haveMask(c,END)){
				c = END_CHAR;
			}else if(haveMask(c,BEGIN)){
				c = BEGIN_CHAR;
			}else if(haveMask(c, VISITED)){
				c = '-';
			}else {
				c = SPACE_CHAR;
			}
			putchar(c);
       	}
        puts("");
    }
}

