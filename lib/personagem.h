#ifndef PERSONAGEM_H
#define PERSONAGEM_H
typedef struct perna{
    float angulo;
}PERNA;
typedef struct braco{
    float angulo;
}BRACO;

void desenhaPersonagem();
void desenhaCabeca();
void desenhaPernaD();
void desenhaPernaE();
void desenhaBracoE();
void desenhaBracoD();
void movimentacaoMembros(int option);

#endif
