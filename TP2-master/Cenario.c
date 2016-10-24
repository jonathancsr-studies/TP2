#include "lib/include.h"
extern unsigned int textureWalls;
float x,z,angle,lx,lz;
int cameradefine;

void plano(float x1,float z1,int larguraJanela,int alturaJanela,float r,float g,float b){
    // teto e terreno
    glPushMatrix();
      glColor3f(r, g, b);
      glBegin(GL_TRIANGLE_FAN);
        glVertex3f(x1-larguraJanela, alturaJanela,z1 +100.0f);
        glVertex3f(x1+larguraJanela, alturaJanela,z1 +100.0f);
        glVertex3f(x1+larguraJanela, alturaJanela,z1 -100.0f);
        glVertex3f(x1-larguraJanela, alturaJanela,z1 -100.0f);
      glEnd();
    glPopMatrix();
}

void configuraIluminacao() {
    plasticoAzul.ambiente = (cor){ 0.1, 0.1, 0.1, 1 };
    plasticoAzul.emissiva = (cor){ 0, 0, 0, 1 };
    plasticoAzul.difusa = (cor){ 0.1, 0.1, 0.4, 1 };
    plasticoAzul.especular = (cor){ 1, 1, 1, 1 };
    plasticoAzul.brilhosidade[0] = 100;

    marromFosco.ambiente = (cor){ 0.1, 0.1, 0.1, 1 };
    marromFosco.emissiva = (cor){ 0, 0, 0, 1 };
    marromFosco.difusa = (cor){ .49, .22, .02, 1 };
    marromFosco.especular = (cor){ 0, 0, 0, 1 };
    marromFosco.brilhosidade[0] = 0;


    posicaoDaLuz = (ponto){ 0, 0, -1, 1 };
    cor corDaLuz = { 1.0, 1.0, 1.0, 1.0 };
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);

    glLightfv(GL_LIGHT0, GL_POSITION, posicaoDaLuz.v);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, corDaLuz.v);
    glLightfv(GL_LIGHT0, GL_SPECULAR, corDaLuz.v);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.05f);

    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

// LABIRINTO
int width=20, height=20, channels;
float posicaoX=0,posicaoZ=0;
ponto entrada,saida;
void cubo3d(float x, float y, float z, float largura, float altura, float profundidade){

	largura=largura/2;
	altura=altura/2;
	profundidade=profundidade/2;
	glPushMatrix();

   /* glMaterialfv(GL_FRONT, GL_AMBIENT, l.mat.ambiente.v);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, l.mat.difusa.v);
    glMaterialfv(GL_FRONT, GL_SPECULAR, l.mat.especular.v);
    glMaterialfv(GL_FRONT, GL_SHININESS, l.mat.brilhosidade);
*/
		glEnable(GL_TEXTURE_2D);	//habilita textura
		glBindTexture(GL_TEXTURE_2D, textureWalls);

    //cima
		glBegin(GL_TRIANGLE_FAN);
			glNormal3f(0,1,0);
			glTexCoord2f(0,0); glVertex3f(x-largura,y+altura,z-profundidade);
			glTexCoord2f(1,0); glVertex3f(x+largura,y+altura,z-profundidade);
			glTexCoord2f(1,1); glVertex3f(x+largura,y+altura,z+profundidade);
			glTexCoord2f(0,1); glVertex3f(x-largura,y+altura,z+profundidade);
		glEnd();
		//baixo
		glBegin(GL_TRIANGLE_FAN);
			glNormal3f(0,-1,0);
			glTexCoord2f(0,0); glVertex3f(x-largura,y-altura,z-profundidade);
			glTexCoord2f(1,0); glVertex3f(x+largura,y-altura,z-profundidade);
			glTexCoord2f(1,1); glVertex3f(x+largura,y-altura,z+profundidade);
			glTexCoord2f(0,1); glVertex3f(x-largura,y-altura,z+profundidade);
		glEnd();
		//frente
		glBegin(GL_TRIANGLE_FAN);
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
		glBegin(GL_TRIANGLE_FAN);
			glNormal3f(-1,0,0);
			glTexCoord2f(0,0); glVertex3f(x-largura,y+altura,z-profundidade);
			glTexCoord2f(1,0); glVertex3f(x-largura,y-altura,z-profundidade);
			glTexCoord2f(1,1); glVertex3f(x-largura,y-altura,z+profundidade);
			glTexCoord2f(0,1); glVertex3f(x-largura,y+altura,z+profundidade);
		glEnd();
	glPopMatrix();

  glDisable(GL_TEXTURE_2D);

}

void desenhaMapaParede(float x, float y, float z, float largura, float altura, float profundidade){
	glPushMatrix();
	glColor3f(0,0,0);
  glTranslatef(x,y,z);
 	  cubo3d(x,y,z,largura,altura,profundidade);
  glPopMatrix();
}

void carregaMapa(MAPACORES aux[200][200]){
	int cont=0,i,j,k;
	unsigned char *ht_map = SOIL_load_image
	(
		"./texture/maps/mapa.png",
		&width, &height, &channels,
		SOIL_LOAD_RGB

	);
	printf("w = %d h = %d c = %d\n",width,height,channels);
      for (i = 0; i < height; ++i)
	{
            for(j=0;j<width;j++)
            {
                  for (k = 0; k < 3; k++,cont++)
			{
				aux[i][j].crgb[k]=ht_map[cont];
			}

            }
	}
}
void desenhaMapa(MAPACORES aux[200][200]){
	int i,j;
	float posicaoX=0,posicaoY=0,posicaoZ=0;

      //i=x j=z
	for (i = 0; i < height;i++){
            posicaoZ=0;
            for(j=0;j<width;j++){
      		if(aux[i][j].crgb[0]==0  && aux[i][j].crgb[1]==0 && aux[i][j].crgb[2]==255){
			entrada.x =i ;
			entrada.z = j;
			posicaoZ+=4;
            }
		 if(aux[i][j].crgb[0]==255  && aux[i][j].crgb[1]==255 && aux[i][j].crgb[2]==255){
			posicaoZ+=4;
		}
             if(aux[i][j].crgb[0]==0  && aux[i][j].crgb[1]==0 && aux[i][j].crgb[2]==0){
				//desenhaMapaParede(posicaoX,1.5f,posicaoZ,8,8,8);
				posicaoZ+=4;
		}
            if(aux[i][j].crgb[0]==255  && aux[i][j].crgb[1]==0 && aux[i][j].crgb[2]==0){
			saida.x = posicaoX;
			saida.y = 0;
			saida.z = posicaoZ;
			saida.w = 0;
		}
            }
            posicaoX+=4;
      }
}
