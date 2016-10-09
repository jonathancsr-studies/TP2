#include "include.h"
int cameradefine=0;
int modoDoJogo=0;
double cameraX=5,cameraY=5,cameraZ=5;


void camera(){
    if(cameradefine == 0){
        gluLookAt(cameraX,cameraY,cameraZ,1,1,1,2,2,2);
    }else{

    }
}

void redimensionada(int w, int h)
{
   glViewport(0,0,(GLsizei) w ,(GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -5.0);
}

void desenhaCena(){

  glColor3f(0.501, 0.501, 0.501);
  glutSolidSphere(0.5,100,100);
  glutSwapBuffers();
}

void Idle(){

  glutPostRedisplay();
}

void inicializa(void)
{
    camera();
    glClearColor(1, 1, 1, 1);
}
int main(int argc, char **argv) {


      glutInit(&argc, argv);
      glutInitContextVersion(1,1);
      glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
      glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
      glutInitWindowSize(ALTURA,LARGURA);
      glutInitWindowPosition(0,0);
      glutCreateWindow("JOGO");
      inicializa();

      glutDisplayFunc(desenhaCena);
      glutReshapeFunc(redimensionada);
      glutKeyboardFunc(teclasPressionada);
      glutSpecialFunc(setasPressionadas);
      glutIdleFunc(Idle);
      glutMainLoop();
      return 0;
}
