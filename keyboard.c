#include "lib/include.h"
extern GLint cameraX,cameraY,cameraZ;
PERNA p[2];
BRACO b[2];
float angle;
int angulo;
// actual vector representing the camera's direction
float lx,lz;
// XZ position of the camera
float x,z;
int cameradefine;
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
                if(p[0].angulo<=10){
                  p[0].angulo = (p[0].angulo + 5) % 360;
                  p[1].angulo = (p[1].angulo - 5) % 360;
                      }
			x += lx * fraction;
			z += lz * fraction;
			break;
		case 's':
    case 'S':
                if(p[1].angulo<=10){
                  p[0].angulo = (p[0].angulo - 5) % 360;
                  p[1].angulo = (p[1].angulo + 5) % 360;
                      }
			x -= lx * fraction;
			z -= lz * fraction;
			break;
            case'c':
    case'C':
                if(cameradefine){
                      cameradefine=0;
                }else{
                      cameradefine=1;
                }
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
                  angulo=(angulo+1)%360;
                  break;
            case GLUT_KEY_RIGHT :
                  angle += 0.01f;
                  lx = sin(angle);
                  lz = -cos(angle);
                  angulo=(angulo-1)%360;
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
