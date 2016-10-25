#include "lib/include.h"
ponto posicaoDaLuz;
material Parede,objetos,objetoSaida;

void configuraIluminacao_Textura() {
    objetos.ambiente = (cor){ 0.1, 0.1, 0.1, 1 };
    objetos.emissiva = (cor){ 0, 0, 0, 1 };
    objetos.difusa = (cor){ 0.1, 0.1, 0.4, 1 };
    objetos.especular = (cor){ 1, 1, 1, 1 };
    objetos.brilhosidade[0] = 100;

    objetoSaida.ambiente = (cor){ 0.1, 0.1, 0.1, 1 };
    objetoSaida.emissiva = (cor){ 0, 0, 0, 1 };
    objetoSaida.difusa = (cor){ 0.7, 0.0, 0.0, 1 };
    objetoSaida.especular = (cor){ 0.6, 0.6, 0.6, 1 };
    objetoSaida.brilhosidade[0] = 50;

    Parede.ambiente = (cor){ 0.1, 0.1, 0.1, 1 };
    Parede.emissiva = (cor){ 0, 0, 0, 1 };
    Parede.difusa = (cor){ .62, .62, .62, 1 };
    Parede.especular = (cor){ 0.2, 0.2, 0.2, 1 };
    Parede.brilhosidade[0] = 0.005;


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

void materialObjetoSaida(){
  glMaterialfv(GL_FRONT, GL_AMBIENT,  objetoSaida.ambiente.v);
  glMaterialfv(GL_FRONT, GL_DIFFUSE,  objetoSaida.difusa.v);
  glMaterialfv(GL_FRONT, GL_SPECULAR, objetoSaida.especular.v);
  glMaterialfv(GL_FRONT, GL_SHININESS,objetoSaida.brilhosidade);
}
void materialaobjetos(){
  glMaterialfv(GL_FRONT, GL_AMBIENT,  objetos.ambiente.v);
  glMaterialfv(GL_FRONT, GL_DIFFUSE,  objetos.difusa.v);
  glMaterialfv(GL_FRONT, GL_SPECULAR, objetos.especular.v);
  glMaterialfv(GL_FRONT, GL_SHININESS,objetos.brilhosidade);
}
