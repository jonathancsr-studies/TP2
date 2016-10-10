#ifndef CENARIO_H
#define CENARIO_H

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
void plano(int larguraJanela,int alturaJanela,int x,float r,float g,float b);
#endif // CENARIO_H
