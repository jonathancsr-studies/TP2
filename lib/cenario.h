#ifndef CENARIO_H
#define CENARIO_H

typedef struct mapaCores
{
	float crgb[3]
}MAPACORES;

typedef struct coords {
  union {
      float v[4];
      struct {
          float x, y, z, w;
      };
      struct {
          float r, g, b, a;
      };
  };
} ponto, vetor, cor;

typedef struct material {
    cor ambiente;
    cor emissiva;
    cor difusa;
    cor especular;
    float brilhosidade[1];
} material;

material plasticoAzul, marromFosco;
ponto posicaoDaLuz;

void desenhaLanterna();
void plano(int larguraJanela,int alturaJanela,float r,float g,float b);
// LABIRINTO
void cubo3d(float x, float y, float z, float largura, float altura, float profundidade);
void desenhaMapaParede(float x, float y, float z, float largura, float altura, float profundidade);
void carregaMapa(MAPACORES aux[]);
void desenhaMapa(MAPACORES aux[]);

#endif // CENARIO_H
