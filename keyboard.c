#include "include.h"

void teclasPressionada(unsigned char key, int x, int y){
  switch (key) {
    case 'q':
            break;
    default:
    break;
  }
  glutPostRedisplay();
}

void setasPressionadas(int key_special, int x, int y){

  switch (key_special) {
      case GLUT_KEY_RIGHT:
      break;
      case GLUT_KEY_LEFT:
      break;
      case GLUT_KEY_UP:
      break;
      case GLUT_KEY_DOWN:
      break;
     default:

               glutPostRedisplay();
        break;
  }
}
