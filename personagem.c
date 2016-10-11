#include "./lib/include.h"
int angulo;
int angle;
PERNA p[2];
BRACO b[2];
float x,z;
void desenhaBracoD(){

  glPushMatrix();
  glTranslatef(1.25,0.75,0.0);
  glPushMatrix();
  glTranslatef (-0.7, 0.0, 0.0);
  glRotatef ((GLfloat) b[1].angulo, 0.0, 0.0, 1.0);
  glTranslatef (0.7, 0.0, 0.0);
  glPushMatrix();
  glScalef (1.5, 0.4, 0.2);
  glutWireCube (1.0);
  glPopMatrix();
  glPopMatrix();
  glPopMatrix();

}

void desenhaBracoE(){

  glPushMatrix();
  glTranslatef(-1.25,0.75,0.0);
  glPushMatrix();
  glTranslatef (0.7, 0.0, 0.0);
  glRotatef ((GLfloat) b[0].angulo, 0.0, 0.0, 1.0);
  glTranslatef (-0.7, 0.0, 0.0);
  glPushMatrix();
  glScalef (1.5, 0.4, 0.2);
  glutWireCube (1.0);
  glPopMatrix();
  glPopMatrix();
  glPopMatrix();


}

void desenhaPernaE(){

  glPushMatrix();
  //glTranslatef (-1.0, 0.0, 0.0);
  glRotatef ((GLfloat) p[0].angulo, 1.0, 0.0, 0.0);
  glTranslatef (-0.25, -2.0, 0.0);
  glPushMatrix();
  glScalef (0.4, 2.0, 0.3);
  glutWireCube (1.0);
  glPopMatrix();
  glPopMatrix();

}

void desenhaPernaD(){

  glPushMatrix();
  //glTranslatef (-1.0, 0.0, 0.0);
  glRotatef ((GLfloat) p[1].angulo, 1.0, 0.0, 0.0);
  glTranslatef (0.25, -2.0, 0.0);
  glPushMatrix();
  glScalef (0.4, 2.0, 0.3);
  glutWireCube (1.0);
  glPopMatrix();
  glPopMatrix();
}

void desenhaCabeca(){

  glPushMatrix();
  glTranslatef(0.0,1.50,0.0);
  glScalef(0.6,0.6,0.5);
  glutWireCube(1);
  glPopMatrix();

}
void desenhaPersonagem()
{
   glClear (GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   glTranslatef(x,3.0,z-5);
   glPushMatrix();
   glRotatef ((GLfloat) angulo, 0.0, 1.0, 0.0);
   glPushMatrix();
   glScalef(1.0,2.0,0.4);
   glutWireCube(1);
   glPopMatrix();
   desenhaBracoE();
   desenhaBracoD();
   desenhaPernaE();
   desenhaPernaD();
   desenhaCabeca();
     glPopMatrix();
     glPopMatrix();
}
