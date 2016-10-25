

void matrizmovimento(Labirinto labirinto){

	int y,x,z,k,K;
	for(y=0,K=0;K<labirinto.linhas;K++,y+=4){
		int offset = K*labirinto.colunas;
            for(z=0;z<4;z++){
		for(x=0,k=0;k<labirinto.colunas;k++,x+=4){
			char c = labirinto.mapa[offset +k];
			if(c == WALL){
				matrizz[y+z][x]=1;
                        matrizz[y+z][x+1]=1;
                        matrizz[y+z][x+2]=1;
                        matrizz[y+z][x+3]=1;
			}else {
                        matrizz[y+z][x]=0;
                        matrizz[y+z][x+1]=0;
                        matrizz[y+z][x+2]=0;
                        matrizz[y+z][x+3]=0;
			}
            }
      }
}
for(y=0;K<(labirinto.linhas)*4;K++){
      for(k=0;k<(labirinto.colunas)*4;k++){
            printf("%d",matrizz[K][k]);
            }
            printf("\n");
      }
}
