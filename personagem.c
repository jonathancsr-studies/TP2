#include "./lib/include.h"

float x,z;


void desenhaPersonagem(PERSONAGEM P){


}

void desenhaBraco(BRACO B,PERSONAGEM P,int qual){

 int x1;
// se qual for 1 é o braço direito e se for 0 é o braço esquerdo
if(qual){
    x1=TAMANHOTRONCO/2;
}else{
    x1=TAMANHOTR
}
  glClear (GL_COLOR_BUFFER_BIT);
     glPushMatrix();
     glTranslatef (P.corpo.x,P.corpo.y+TAMANHOTRONCO/2,P.);
     glRotatef ((GLfloat) anguloOmbro, 0.0, 0.0, 1.0);
     glTranslatef (1.0, 0.0, 0.0);
     glPushMatrix();
     glScalef (2.0, 0.4, 1.0);
     glutWireCube (1.0);
     glPopMatrix();

     glTranslatef (1.0, 0.0, 0.0);
     glRotatef ((GLfloat) anguloCutuvelo, 0.0, 0.0, 1.0);
     glTranslatef (0.7, 0.0, 0.0);
     glPushMatrix();
     glScalef (2.0, 0.4, 1.0);
     glutWireCube (0.7);
     glPopMatrix();

     glPopMatrix();
     glutSwapBuffers();

}

void desenhaTronco(PERSONAGEM P){

  P.corpo.x=x;
  P.corpo.z=z;
  glPushMatrix();
  glTranslatef(P.corpo.x,1,P.corpo.z);
  //glutReshapeFunc();
  glutWireCube(TAMANHOTRONCO);
  glPopMatrix();

}
