#include "lib/include.h"
int angulo;
int angle;
PERNA p[2];
BRACO b[2];
int andar=1,braco=1,lanterna;
float x,z;
void desenhaBracoD(){

  glPushMatrix();
  glTranslatef(1.25,0.75,0.0);
  glPushMatrix();
  glTranslatef (-0.7, 0.0, 0.0);
  glRotatef ((GLfloat) b[1].angulo, 1.0, 0.0, 0.0);
  glRotatef (-75, 0.0, 0.0, 1.0);
  glTranslatef (0.7, 0.0, 0.0);
  glPushMatrix();
  glScalef (1.5, 0.4, 0.2);
  glutSolidCube (1.0);
  glPopMatrix();
  glTranslatef(0.75,0,0);
  if(lanterna){
  desenhaLanterna();
 }
    glColor3f(0.5,0.5,0.5);
  glPopMatrix();
  glPopMatrix();

}

void desenhaBracoE(){

  glPushMatrix();
  glTranslatef(-1.25,0.75,0.0);
  glPushMatrix();
  glTranslatef (0.7, 0.0, 0.0);
  glRotatef ((GLfloat) b[0].angulo, 1.0, 0.0, 0.0);
  glRotatef (75, 0.0, 0.0, 1.0);
  glTranslatef (-0.7, 0.0, 0.0);
  glPushMatrix();
  glScalef (1.5, 0.4, 0.2);
  glutSolidCube (1.0);
  glPopMatrix();
  glPopMatrix();
  glPopMatrix();
}

void desenhaPernaE(){

  glPushMatrix();
  //glTranslatef (-1.0, 0.0, 0.0);
  glRotatef ((GLfloat) p[0].angulo, 1.0, 0.0, 0.0);
  glTranslatef (-0.25, -2.0, 0.0);
  glPushMatrix();
  glScalef (0.4, 2.0, 0.3);
  glutSolidCube (1.0);
  glPopMatrix();
  glPopMatrix();

}

void desenhaPernaD(){

  glPushMatrix();
  //glTranslatef (-1.0, 0.0, 0.0);
  glRotatef ((GLfloat) p[1].angulo, 1.0, 0.0, 0.0);
  glTranslatef (0.25, -2.0, 0.0);
  glPushMatrix();
  glScalef (0.4, 2.0, 0.3);
  glutSolidCube (1.0);
  glPopMatrix();
  glPopMatrix();
}

void desenhaCabeca(){

  glPushMatrix();
  glTranslatef(0.0,1.50,0.0);
  glScalef(0.6,0.6,0.5);
  glutSolidCube(1);
  glPopMatrix();

}
void desenhaPersonagem()
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f(0.5,0.5,0.5);
   glPushMatrix();
   glTranslatef(x,3.0,z);
   glPushMatrix();
   glRotatef ((GLfloat) angulo, 0.0, 1.0, 0.0);
   glPushMatrix();
   glScalef(1.0,2.0,0.4);
   glutSolidCube(1);
   glPopMatrix();
   desenhaBracoE();
   desenhaBracoD();
   desenhaPernaE();
   desenhaPernaD();
   desenhaCabeca();
     glPopMatrix();
     glPopMatrix();
}

void movimentacaoMembros(int option){


      if(option){
            if(andar){
                if(p[0].angulo<=10){
                  p[0].angulo +=VELOCIDADEPERNAS;
                  p[1].angulo -=VELOCIDADEPERNAS;
            }
            if(p[0].angulo==10+VELOCIDADEPERNAS)
                  andar=0;
            }else{
                  if(p[1].angulo<=10){
                    p[0].angulo -=VELOCIDADEPERNAS;
                    p[1].angulo +=VELOCIDADEPERNAS;
                        }
                        if(p[1].angulo==10+VELOCIDADEPERNAS)
                  andar=1;
            }
            if(braco){
                if(b[0].angulo<=20){
                  b[0].angulo +=VELOCIDADEBRACOS;
             if(lanterna==0)
                  b[1].angulo -=VELOCIDADEBRACOS;
            }
                if(b[0].angulo==20+VELOCIDADEBRACOS)
                  braco=0;
            }else{
                  if(b[0].angulo>=-20){
                    b[0].angulo -=VELOCIDADEBRACOS;
             if(lanterna==0)
                    b[1].angulo +=VELOCIDADEBRACOS;
                        }
                if(b[0].angulo==-(20+VELOCIDADEBRACOS))
                  braco=1;
            }
      }else{
            if(andar==0){
               if(p[1].angulo<=10){
                 p[0].angulo -=VELOCIDADEPERNAS;
                 p[1].angulo +=VELOCIDADEPERNAS;
          }
          if(p[1].angulo==10+VELOCIDADEPERNAS)
                 andar=1;
          }else{
                 if(p[0].angulo<=10){
                   p[0].angulo +=VELOCIDADEPERNAS;
                   p[1].angulo -=VELOCIDADEPERNAS;
                       }
                       if(p[0].angulo==10+VELOCIDADEPERNAS)
                 andar=0;
          }
          if(braco==0){
              if(b[0].angulo<=20){
                b[0].angulo +=VELOCIDADEBRACOS;
              if(lanterna==0)
                b[1].angulo -=VELOCIDADEBRACOS;
          }
              if(b[0].angulo==20+VELOCIDADEBRACOS)
                braco=1;
          }else{
                if(b[0].angulo>=-20){
                  b[0].angulo -=VELOCIDADEBRACOS;
              if(lanterna==0)
                  b[1].angulo +=VELOCIDADEBRACOS;
                      }
              if(b[0].angulo==-(20+VELOCIDADEBRACOS))
                braco=0;
          }
      }
}
