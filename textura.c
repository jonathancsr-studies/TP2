#include "lib/include.h"

typedef struct mapaCores
{
	float crgb[3]
}MAPACORES;

int width, height, channels,i,j,k;
MAPACORES *matriz_cores_map;

void desenhaMapaParede(float x, float z){
	glPushMatrix();
	glColor3f(0,0,0);
	glTranslatef(x,1.5f, z);
		 glutSolidCube (1.0);
	glPopMatrix();
}

void carregaMapa(){
	int cont=0;
	float posicaoX=0,posicaoZ=0;
	unsigned char *ht_map = SOIL_load_image
	(
		"mapa.png",
		&width, &height, &channels,
		SOIL_LOAD_RGB

	);
	MAPACORES aux[width * height];
	for (i = 0; i < width * height; ++i)
	{
			for (k = 0; k < 3; k++,cont++)
			{
				matriz_cores_map[i].crgb[k]=ht_map[cont];
			}
			printf("ok\n");
	}
	matriz_cores_map = aux;
	for (i = 0, j = 1; i <width * height;j++ , i++)
		{
			if(aux[i].crgb[0]==0  && aux[i].crgb[1]==0 && aux[i].crgb[2]==255){//AZUL
				posicaoX+=2;
				printf("E");
			}else if(aux[i].crgb[0]==255  && aux[i].crgb[1]==0 && aux[i].crgb[2]==0){//VERMELHO
				posicaoX+=2;
				printf("S");
			}else if(aux[i].crgb[0]==0  && aux[i].crgb[1]==0 && aux[i].crgb[2]==0){//PRETO
				posicaoX+=2;
				printf("|");
			}else if(aux[i].crgb[0]==255  && aux[i].crgb[1]==255 && aux[i].crgb[2]==255){//BRANCO
				desenhaMapaParede(posicaoX,posicaoZ);
				posicaoX+=2;
				printf(" ");
			}
			if (j == width)
			{
				printf("\n");
				j = 0;
				posicaoZ+=2;
				posicaoX=0;
			}
			printf("ok231\n");
		}
}

/*void desenhaMapa(){
float posicaoX=0,posicaoY=0,posicaoZ=0;

	for (i = 0, j = 1; i <width * height;j++ , i++){
		if(matriz_cores_map[i].crgb[0]==0  && matriz_cores_map[i].crgb[1]==0 && matriz_cores_map[i].crgb[2]==255){
			printf("E");
		}else if(matriz_cores_map[i].crgb[0]==0  && matriz_cores_map[i].crgb[1]==0 && matriz_cores_map[i].crgb[2]==0){
			printf("|");
			posicaoX+=2;
		}else if(matriz_cores_map[i].crgb[0]==255  && matriz_cores_map[i].crgb[1]==255 && matriz_cores_map[i].crgb[2]==255){
			desenhaMapaParede(posicaoX,posicaoZ);
			posicaoX+=2;
			printf(" ");
		}else if(matriz_cores_map[i].crgb[0]==255  && matriz_cores_map[i].crgb[1]==0 && matriz_cores_map[i].crgb[2]==0){
			printf("S");
		}
		if (j == width)
		{
			posicaoX = 0;
			posicaoZ +=2;
			printf("\n");
			j = 0;
		}
	}
}
*/
