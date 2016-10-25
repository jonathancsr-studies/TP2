#include "lib/include.h"
ponto posicaoDaLuz;
material Parede,objetos;

void configuraIluminacao_Textura() {
    objetos.ambiente = (cor){ 0.1, 0.1, 0.1, 1 };
    objetos.emissiva = (cor){ 0, 0, 0, 1 };
    objetos.difusa = (cor){ 0.1, 0.1, 0.4, 1 };
    objetos.especular = (cor){ 1, 1, 1, 1 };
    objetos.brilhosidade[0] = 100;

    Parede.ambiente = (cor){ 0.1, 0.1, 0.1, 1 };
    Parede.emissiva = (cor){ 0, 0, 0, 1 };
    Parede.difusa = (cor){ .62, .62, .62, 1 };
    Parede.especular = (cor){ 0.02, 0.02, 0.02, 1 };
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
