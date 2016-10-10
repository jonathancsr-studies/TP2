#ifndef PERSONAGEM_H
#define PERSONAGEM_H
typedef struct posicao{

      double x,y,z;

}POSICAO;
typedef struct braco{

      POSICAO corpo[4];
      POSICAO fim[4];

}BRACO;
typedef struct perna{

      POSICAO corpo[4];
      POSICAO fim[4];

}PERNA;

typedef struct personagem{

      BRACO b[2];
      PERNA p[2];

}PERSONAGEM;


#endif
