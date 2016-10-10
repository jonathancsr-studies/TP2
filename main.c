#include "lib/include.h"
 cameradefine=0;
int modoDoJogo=0;
GLint terrenoLargura,terrenoProfundidade0;


void camera(){
    if(cameradefine == 0){
    }else{
    }
}

void redimensionada(int w, int h)
{/*

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    glFrustum(1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    ;*/
    glViewport(0,0,(GLsizei) w ,(GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(0,100,0,100,0,1);
    glOrtho()
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef (0.0, 0.0, -5.0);
   	//gluLookAt(, LARGURA/2, 0, 5, 0, 0, 0, 1, 0);
   	// glTranslatef(0.0,0.0,headZ);
}

void desenhaCena(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  camera();
  luzes();
  terreno();
  glColor3f(1.0,1.0,1);
  glPushMatrix();
  glScalef(10,10,10);
  glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0,0,0);
    glVertex3f(1,0,0);
    glVertex3f(1,1,0);
    glVertex3f(0,1,0);
  glEnd();
  glPopMatrix();
  glutSwapBuffers();
}

void Idle(){

  glutPostRedisplay();
}

void inicializa(void)
{
    luzes();
    camera();
    glClearColor(0,0,0,1.0);
}
int main(int argc, char **argv) {


      glutInit(&argc, argv);
      glutInitContextVersion(1,1);
      glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
      glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
      glutInitWindowSize(LARGURA,ALTURA);
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
