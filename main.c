#include "include.h"


void inicializa(void)
{
    glClearColor(0, 0, 0, 0);
    glutPostRedisplay();
}

void redimensionada(int w, int h)
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, LARGURA, 0.0, ALTURA, -1.0, 1.0);

   glMatrixMode(GL_MODELVIEW);
}

void desenhaCena(){
  glutSwapBuffers();
}

void Idle(){
  glutPostRedisplay();
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
