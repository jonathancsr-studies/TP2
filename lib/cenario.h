#ifndef CENARIO_H
#define CENARIO_H

void desenhaLanterna();
void plano(int larguraJanela,int alturaJanela,float r,float g,float b);
// LABIRINTO
void cubo3d(float x, float y, float z, float largura, float altura, float profundidade);
void desenhaMapaParede(float x, float y, float z, float largura, float altura, float profundidade);
void carregaMapa(MAPACORES aux[]);
void desenhaMapa(MAPACORES aux[]);

#endif // CENARIO_H
