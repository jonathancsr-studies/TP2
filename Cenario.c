#include "lib/include.h"
extern GLint terrenoLargura= 20,terrenoProfundidade = 20;

void terreno(){

  glPushMatrix();
  glColor3f(0,1,0);
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(0,0,0);
  glVertex3f(10,0,0);
  glVertex3f(10,10,0);
  glVertex3f(0,10,0);

  glEnd();
  glPopMatrix();
}


void luzes(){
  float lightAmb[] = { 0.0, 0.0, 0.0, 1.0 };
  float lightDif0[] = { 0.5, 0.5, 0.5, 1.0 };
  float lightSpec0[] = { 0.6, 0.6, 0.6, 1.0 };
  float lightPos0[] = { 0.0, 0.0, 3.0, 5 };
  float lightDifAndSpec1[] = { 0.0, 1.0, 0.0, 1.0 };
  float lightPos1[] = { 1.0, 2.0, 0.0, 1.0 };
  float globAmb[] = { 0.7, 0.7, 0.7, 1.0 };

  glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif0);
  glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec0);
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb);
  //glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, localViewer);

}
