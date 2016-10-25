#ifndef INCLUDE_H
#define INCLUDE_H

#include "../solvers/solver.h"
#include "../io/tui.h"
#include "../io/arquivador.h"
#include "../generators/generator.h"
#include "../commons/labirinto.h"
#include "../commons/bits.h"
#include "../commons/error.h"
#include "../commons/coordinates.h"
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <SOIL/SOIL.h>
#include <SDL/SDL.h>
#include <SDL/SDL_audio.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "personagem.h"
#include "cenario.h"
#include "keyboard.h"
#include "textura.h"
#include "music.h"
#include "iluminacao.h"



#define ALTURA 720
#define LARGURA 720
#define PI 3.14
#define CAMERAPERSONAGEM 10
#define VELOCIDADEPERNAS 0.5
#define VELOCIDADEBRACOS 1.0


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


#endif
