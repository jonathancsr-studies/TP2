#include "lib/include.h"
extern int cameradefine=0;
int modoDoJogo=0;
extern PERNA p[2];
extern BRACO b[2];
int larguraJanela,alturaJanela;
extern float angle=0.0f;
// actual vector representing the camera's direction
extern float lx=0.0f,lz=-1.0f;
// XZ position of the camera
extern float x=0.0f,z=5.0f,x1=0,z1=5;

void camera(){
    if(cameradefine == 0){
    gluLookAt(	x, 5.0f, z,
 			x+lx, 5.0f,  z+lz,
 			0.0f, 1.0f,  0.0f);
      }else{
    gluLookAt(	x1, 5.0f, z1+CAMERAPERSONAGEM,
			x1+lx, 5.0f,  z1+CAMERAPERSONAGEM+lz,
			0.0f, 1.0f,  0.0f);

    }
}

void redimensionada(int w, int h)
{
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity ();
     glViewport (0, 0, (GLsizei) w, (GLsizei) h);
     larguraJanela=w;
     alturaJanela=h;
     gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 100.0);
     glMatrixMode(GL_MODELVIEW);

}

void desenhaCena(){
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glLoadIdentity();
     camera();
      //terreno e teto
      desenhaPersonagem();
      plano(larguraJanela,0,0,1,0);
    //  plano(larguraJanela,alturaJanela,50,1,1,1);
      glColor3f(0, 0,0);
      glPushMatrix();
      // Draw Body
      glTranslatef(0.0f ,1.5f, 0.0f);
      //glutSolidSphere(0.75f,20,20);
         glutSolidCube (1.0);
      glPopMatrix();
      glPushMatrix();
      glTranslatef(3.0f ,1.5f, 0.0f);
         glutSolidCube (1.0);

      glPopMatrix();
   glutSwapBuffers();
}

void inicializa(void)
{
    glClearColor(0.0,0.3,1.0,1.0);
}
int main(int argc, char **argv) {


      glutInit(&argc, argv);
      glutInitContextVersion(1,1);
      glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
      glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE | GLUT_RGBA);
      glutInitWindowSize(LARGURA,ALTURA);
      glutInitWindowPosition(100,100);
      glutCreateWindow("JOGO");
      inicializa();

      glutDisplayFunc(desenhaCena);
      glutReshapeFunc(redimensionada);
      glutKeyboardFunc(teclasPressionada);
      glutSpecialFunc(setasPressionadas);
      glutIdleFunc(desenhaCena);
      glEnable(GL_DEPTH_TEST);
      glutMainLoop();
      return 0;
}
