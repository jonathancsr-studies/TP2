#include "lib/include.h"
extern unsigned int textureWalls;
float x,z,angle,lx,lz;
int cameradefine;
extern Labirinto lab_Master;
extern int linhas,colunas;

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
float posicaoX=0,posicaoZ=0;
ponto entrada,saida;

void cubo3d(float x, float y, float z, float largura, float altura, float profundidade){

	largura=largura/2;
	altura=altura/2;
	profundidade=profundidade/2;
	glPushMatrix();


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
/* glMaterialfv(GL_FRONT, GL_AMBIENT, l.mat.ambiente.v);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, l.mat.difusa.v);
  glMaterialfv(GL_FRONT, GL_SPECULAR, l.mat.especular.v);
  glMaterialfv(GL_FRONT, GL_SHININESS, l.mat.brilhosidade);
*/
void desenhaMapaParede(float x, float y, float z, float largura, float altura, float profundidade){
	glPushMatrix();
	glColor3f(0,0,0);
  glTranslatef(x,y,z);
 	  cubo3d(x,y,z,largura,altura,profundidade);
  glPopMatrix();
}
void geraLabirinto() {
  int metodo;

  lab_Master = novoLabirinto(linhas,colunas);

  srand (time(NULL));

  if(metodo == 0){
    dfsGenerate(lab_Master);
  printf("ok1\n");
  } else if(metodo == 1){
    btreeGenerate(lab_Master);
  }
  printstd(lab_Master);
}

void desenhaLabirinto(Labirinto labirinto){
  int y,x;
//  printf("entrei\n" );
  float posicaoX=0,posicaoY=0,posicaoZ=0;
  for(y=0;y<labirinto.linhas;y++){
		int offset = y*labirinto.colunas;
		for(x=0;x<labirinto.colunas;x++){
			char c = labirinto.mapa[offset +x];
			if(c == WALL){
				c = WALL_CHAR;
        desenhaMapaParede(posicaoX,2,posicaoZ,8,8,8);
        posicaoZ+=4;
        //printf("Wall\n");
  		}else if(haveMask(c,END)){
				c = END_CHAR;
        //printf("End\n");
        saida.x = posicaoX+2;
        saida.z = posicaoZ+2;
			}else if(haveMask(c,BEGIN)){
				c = BEGIN_CHAR;
        //printf("Begin\n");
        entrada.x = posicaoX+1;
        entrada.z = posicaoZ+1;
			}else {
				c = SPACE_CHAR;
        //printf("vazio\n");
        posicaoZ+=4;
			}
		}
    posicaoX+=4;
    posicaoZ=0;
	}
}
