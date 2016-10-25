#include "lib/include.h"
extern unsigned int textureWalls;
float camera_x,camera_z,angle,lx,lz;
int cameradefine;
extern Labirinto lab_Master;
extern int linhas,colunas;
extern int posicaoX,posicaoZ;
int contItens=0,saidaPosicaoX,saidaPosicaoZ;
extern material Parede;
char matriz_map[200][200];

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

// LABIRINTO
void comecarJogoNovo() {
  camera_x=8,camera_z=8;
  contItens=0;
  inicializa();
}

void cubo3d(float x, float y, float z, float largura, float altura, float profundidade){

	largura=largura/2;
	altura=altura/2;
	profundidade=profundidade/2;
  glColor3f(0.5f,0.5f,0.5f);
	glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT,  Parede.ambiente.v);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,  Parede.difusa.v);
    glMaterialfv(GL_FRONT, GL_SPECULAR, Parede.especular.v);
    glMaterialfv(GL_FRONT, GL_SHININESS,Parede.brilhosidade);
  	glEnable(GL_TEXTURE_2D);	//habilita textura
		glBindTexture(GL_TEXTURE_2D, textureWalls);

    //cima
    //baixo
		glBegin(GL_TRIANGLE_FAN);
			glNormal3f(0,1,0);
			glTexCoord2f(0,0); glVertex3f(x-largura,y+altura,z-profundidade);
			glTexCoord2f(1,0); glVertex3f(x+largura,y+altura,z-profundidade);
			glTexCoord2f(1,1); glVertex3f(x+largura,y+altura,z+profundidade);
			glTexCoord2f(0,1); glVertex3f(x-largura,y+altura,z+profundidade);
		glEnd();
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
  } else if(metodo == 1){
    btreeGenerate(lab_Master);
  }
  printstd(lab_Master);
}

void itenAleatorio() {
  int x = rand()%10000;
  float cor[3];
  cor[0] = (rand()%100)/100;
  cor[1] = (rand()%100)/100;
  cor[2] = (rand()%100)/100;
if(contItens<10){
    if(x>0 && x <60){
      materialaobjetos();
      glPushMatrix();
        glTranslatef(posicaoX,1.5f,posicaoZ);
        glutSolidSphere(1.5,20,20);
      glPopMatrix();
      contItens++;
    }else if(x>90 && x <150){
      materialaobjetos();
      glPushMatrix();
        glTranslatef(posicaoX,1.5f,posicaoZ);
        glutSolidTetrahedron();
      glPopMatrix();
      contItens++;
    }else if(x>1480 && x <1560){
      materialaobjetos();
      glPushMatrix();
        glTranslatef(posicaoX,1.5f,posicaoZ);
        glutSolidOctahedron();
      glPopMatrix();
      contItens++;
    }else if(x>400 && x <570){
      materialaobjetos();
      glPushMatrix();
        glTranslatef(posicaoX,1.5f,posicaoZ);
      glutSolidDodecahedron();
      glPopMatrix();
      contItens++;
    }else if(x>1200 && x <1375){
      materialaobjetos();
      glPushMatrix();
        glTranslatef(posicaoX,1.5f,posicaoZ);
      glutSolidIcosahedron();
      glPopMatrix();
      contItens++;
    }else if(x>5200 && x<5575){
      materialaobjetos();
      glPushMatrix();
        glTranslatef(posicaoX,1.5f,posicaoZ);
      glutSolidTeapot(2);
      glPopMatrix();
      contItens++;
    }
  }
}

void desenhaLabirinto(Labirinto labirinto){
  int y,x;
  char aux;
  float posicaoX=0,posicaoY=0,posicaoZ=0;
  for(y=0;y<labirinto.linhas;y++){
    int offset = y*labirinto.colunas;
    for(x=0;x<labirinto.colunas;x++){
	  			char c = labirinto.mapa[offset +x];
      if(c == WALL){
				c = WALL_CHAR;
        matriz_map[y][x]=c;
  		}else {
				c = SPACE_CHAR;
        matriz_map[y][x]=c;
    	}
		}
	}
  for (y = 0; y<linhas ; y++) {
      for (x = 0; x < colunas; x++) {
          if(matriz_map[y][x] == 'X'){
            desenhaMapaParede(posicaoX,2.0f,posicaoZ,8,12,8);
          }
          posicaoX += 4;
      }
      posicaoZ += 4;
      posicaoX = 0;
  }
  saidaPosicaoX = ((colunas-1)*4)+4;
  saidaPosicaoZ = ((linhas-1)*4)+4;
  glPushMatrix();
    materialObjetoSaida();
    glTranslatef(saidaPosicaoX,3.0f,saidaPosicaoZ);
    glColor3f(0.8f,0.0f,0.0f);
    glutSolidSphere(1,50,50);
  glPopMatrix();
}
void desenhaFog(){
  float cor[3] = { 0.2f, 0.6f, 1.0f };
  glClearColor(cor[0], cor[1], cor[2], 1.0f);
  glFogi(GL_FOG_MODE, GL_EXP);        // Linear, exp. ou exp²
  glFogfv(GL_FOG_COLOR, cor);         // Cor
  glFogf(GL_FOG_DENSITY, 0.01f);      // Densidade
  glHint(GL_FOG_HINT, GL_DONT_CARE);  // Não aplicar se não puder
  glFogf(GL_FOG_START, 9000000000*900000000.0f);         // Profundidade inicial
  glFogf(GL_FOG_END, 9000000000*90000000000.0f);           // Profundidade final
  glEnable(GL_FOG);
}
