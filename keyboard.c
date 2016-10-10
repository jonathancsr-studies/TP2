#include "lib/include.h"
extern GLint cameraX,cameraY,cameraZ;
float angle;
// actual vector representing the camera's direction
float lx,lz;
// XZ position of the camera
float x,z;
void teclasPressionada(unsigned char key, int a, int b){

float fraction = 0.1f;

  switch (key) {
		case 'a' :
    case 'A' :
			angle -= PI/2;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case 'd' :
    case 'D' :
			angle += PI/2;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case 'w' :
    case 'W' :
			x += lx * fraction;
			z += lz * fraction;
			break;
		case 's':
    case 'S':
			x -= lx * fraction;
			z -= lz * fraction;
			break;
    case 27:
        exit(0);
        break;
    default:
    break;
  }
  glutPostRedisplay();
}

void setasPressionadas(int key, int a, int b){


float fraction = 0.1f;

switch (key) {
case GLUT_KEY_LEFT :
angle -= 0.01f;
lx = sin(angle);
lz = -cos(angle);
break;
case GLUT_KEY_RIGHT :
angle += 0.01f;
lx = sin(angle);
lz = -cos(angle);
break;
case GLUT_KEY_UP :
x += lx * fraction;
z += lz * fraction;
break;
case GLUT_KEY_DOWN :
x -= lx * fraction;
z -= lz * fraction;
break;
}
}
