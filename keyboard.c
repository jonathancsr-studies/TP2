#include "include.h"
extern cameraX,cameraY,cameraZ;
void teclasPressionada(unsigned char key, int x, int y){
  switch (key) {
    case 27:
        exit(0);
        break;
    default:
    break;
  }
  glutPostRedisplay();
}

void setasPressionadas(int key_special, int x, int y){

  switch (key_special) {
      case GLUT_KEY_RIGHT:
            cameraX ++;
      break;
      case GLUT_KEY_LEFT:
            cameraX --;
      break;
      case GLUT_KEY_UP:
          cameraZ ++;
      break;
      case GLUT_KEY_DOWN:
          cameraZ ++;
      break;
     default:

               glutPostRedisplay();
        break;
  }
}
