#include "lib/include.h"

int width=20, height=20, channels;
float posicaoX=0,posicaoZ=0;
ponto entrada,saida;
void cubo3d(float x, float y, float z, float largura, float altura, float profundidade){
	
	largura=largura/2;
	altura=altura/2;
	profundidade=profundidade/2;
	//glPushMatrix();

		glEnable(GL_TEXTURE_2D);	//habilita textura
		//glBindTexture(GL_TEXTURE_2D, texture[1]);
		//cima
		glBegin(GL_QUADS);			
			glNormal3f(0,1,0);
			glTexCoord2f(0,0); glVertex3f(x-largura,y+altura,z-profundidade);
			glTexCoord2f(1,0); glVertex3f(x+largura,y+altura,z-profundidade);
			glTexCoord2f(1,1); glVertex3f(x+largura,y+altura,z+profundidade);
			glTexCoord2f(0,1); glVertex3f(x-largura,y+altura,z+profundidade);
		glEnd();
		//baixo
		glBegin(GL_QUADS);
			glNormal3f(0,-1,0);
			glTexCoord2f(0,0); glVertex3f(x-largura,y-altura,z-profundidade);
			glTexCoord2f(1,0); glVertex3f(x+largura,y-altura,z-profundidade);
			glTexCoord2f(1,1); glVertex3f(x+largura,y-altura,z+profundidade);
			glTexCoord2f(0,1); glVertex3f(x-largura,y-altura,z+profundidade);
		glEnd();
		//frente
		glBegin(GL_QUADS);
			glNormal3f(0,0,-1);
			glTexCoord2f(0,0); glVertex3f(x-largura,y+altura,z-profundidade);
			glTexCoord2f(1,0); glVertex3f(x+largura,y+altura,z-profundidade);
			glTexCoord2f(1,1); glVertex3f(x+largura,y-altura,z-profundidade);
			glTexCoord2f(0,1); glVertex3f(x-largura,y-altura,z-profundidade);
		glEnd();
		//atraz
		glBegin(GL_QUADS);
			glNormal3f(0,0,1);
			glTexCoord2f(0,0); glVertex3f(x-largura,y+altura,z+profundidade);
			glTexCoord2f(1,0); glVertex3f(x+largura,y+altura,z+profundidade);
			glTexCoord2f(1,1); glVertex3f(x+largura,y-altura,z+profundidade);
			glTexCoord2f(0,1); glVertex3f(x-largura,y-altura,z+profundidade);
		glEnd();
		//direita
		glBegin(GL_QUADS);
			glNormal3f(1,0,0);
			glTexCoord2f(0,0); glVertex3f(x+largura,y+altura,z-profundidade);
			glTexCoord2f(1,0); glVertex3f(x+largura,y-altura,z-profundidade);
			glTexCoord2f(1,1); glVertex3f(x+largura,y-altura,z+profundidade);
			glTexCoord2f(0,1); glVertex3f(x+largura,y+altura,z+profundidade);
		glEnd();
		//esquerda
		glBegin(GL_QUADS);
			glNormal3f(-1,0,0);
			glTexCoord2f(0,0); glVertex3f(x-largura,y+altura,z-profundidade);
			glTexCoord2f(1,0); glVertex3f(x-largura,y-altura,z-profundidade);
			glTexCoord2f(1,1); glVertex3f(x-largura,y-altura,z+profundidade);
			glTexCoord2f(0,1); glVertex3f(x-largura,y+altura,z+profundidade);
		glEnd();
	//glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers();

}

void desenhaMapaParede(float x, float z){
	glPushMatrix();
	glColor3f(0,0,0);
	glTranslatef(x,1.5f, z);
		 cubo3d();
	glPopMatrix();
}

void carregaMapa(MAPACORES aux[]){
	int cont=0,i,k;
	unsigned char *ht_map = SOIL_load_image
	(
		"./texture/maps/mapa.png",
		&width, &height, &channels,
		SOIL_LOAD_RGB

	);
	printf("w = %d h = %d c = %d\n",width,height,channels);
	for (i = 0; i < width * height; ++i)
	{
			for (k = 0; k < 3; k++,cont++)
			{
				aux[i].crgb[k]=ht_map[cont];
			}

	}
}

void desenhaMapa(MAPACORES aux[]){
	int i,j;
	float posicaoX=0,posicaoY=0,posicaoZ=0;

	for (i = 0, j = 1; i < width * height;j++ , i++){
		if(aux[i].crgb[0]==0  && aux[i].crgb[1]==0 && aux[i].crgb[2]==255){
			entrada.x = posicaoX;
			entrada.y = 0;
			entrada.z = posicaoZ;
			entrada.w = 0;
			posicaoX+=4;
		}else if(aux[i].crgb[0]==0  && aux[i].crgb[1]==0 && aux[i].crgb[2]==0){
			posicaoX+=4;
		}else if(aux[i].crgb[0]==255  && aux[i].crgb[1]==255 && aux[i].crgb[2]==255){
			desenhaMapaParede(posicaoX,posicaoZ);
			posicaoX+=4;
		}else if(aux[i].crgb[0]==255  && aux[i].crgb[1]==0 && aux[i].crgb[2]==0){
			saida.x = posicaoX;
			saida.y = 0;
			saida.z = posicaoZ;
			saida.w = 0;
		}
		if (j == width)
		{
			posicaoX = 0;
			posicaoZ +=4;
			j = 0;
		}
	}
}

