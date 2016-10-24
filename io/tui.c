#include "tui.h"

void printstd(Labirinto labirinto){
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
			}else {
				c = SPACE_CHAR;
			}
			putchar(c);
		}
		puts("");
	}
}
