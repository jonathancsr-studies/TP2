#ifndef CENARIO_H
#define CENARIO_H

void plano(float x1,float z1,int larguraJanela,int alturaJanela,float r,float g,float b);
// LABIRINTO
void cubo3d(float x, float y, float z, float largura, float altura, float profundidade);
void desenhaMapaParede(float x, float y, float z, float largura, float altura, float profundidade);
void geraLabirinto();
void itenAleatorio();
void desenhaFinal();
void desenhaLabirinto(Labirinto labirinto);
void printyx(int y, int x);
void markyx(int y, int x);
void resolveLab();
void desenhaFog();
#endif // CENARIO_H
