#include "lib/include.h"

void plano(int larguraJanela,int alturaJanela,int x,float r,float g,float b){
    // teto e terreno
    glPushMatrix();
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(-larguraJanela, alturaJanela, 100.0f);
    glVertex3f(larguraJanela, alturaJanela, 100.0f);
    glVertex3f(larguraJanela, alturaJanela-x, -100.0f);
    glVertex3f(-larguraJanela, alturaJanela-x, -100.0f);
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
