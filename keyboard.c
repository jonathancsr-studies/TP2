#include "lib/include.h"
extern GLint cameraX,cameraY,cameraZ;
float angle;
int angulo;
// actual vector representing the camera's direction
float lx,lz;
// XZ position of the camera
float x,z;
int cameradefine,lanterna;
PERNA p[2];
BRACO b[2];
float x,z;
void teclasPressionada(unsigned char key, int a, int w){

float fraction = 0.1f;

  switch (key) {
            case' ':
                  angulo++;
                  break;
		case 'a' :
    case 'A' :
			angle -= PI/2;
			lx = sin(angle);
			lz = -cos(angle);
                  angulo+=90;

			break;
		case 'd' :
    case 'D' :
			angle += PI/2;
			lx = sin(angle);
			lz = -cos(angle);
                  angulo-=90;
			break;
		case 's' :
    case 'S' :
                  movimentacaoMembros(1);
			x -= lx * fraction;
			z -= lz * fraction;
			break;
		case 'w':
    case 'W':
                  movimentacaoMembros(0);
			x += lx * fraction;
			z += lz * fraction;
			break;
            case'c':
    case'C':
                if(cameradefine){
                      cameradefine=0;
                }else{
                      cameradefine=1;
                }
                break;

             case'v':
    case'V':
            if(lanterna){
                  lanterna=0;
                  b[1].angulo=-b[0].angulo;
            }else{
                  lanterna=1;
                  b[1].angulo=40;
            }
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
            angle -= PI/2;
            lx = sin(angle);
            lz = -cos(angle);
            angulo+=90;

                  break;
            case GLUT_KEY_RIGHT :
            angle += PI/2;
            lx = sin(angle);
            lz = -cos(angle);
            angulo-=90;
                  break;
            case GLUT_KEY_UP :
            movimentacaoMembros(0);
            x += lx * fraction;
            z += lz * fraction;
                  break;
            case GLUT_KEY_DOWN :
            movimentacaoMembros(1);
            x -= lx * fraction;
            z -= lz * fraction;
                  break;
      }
}
