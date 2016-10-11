#include "lib/include.h"
extern GLint cameraX,cameraY,cameraZ;
float angle;
int angulo;
int andar=1;
// actual vector representing the camera's direction
float lx,lz;
// XZ position of the camera
float x,z;
int cameradefine;
PERNA p[2];
BRACO b[2];
float x,z,x1,z1;
void teclasPressionada(unsigned char key, int a, int w){

float fraction = 0.1f;

  switch (key) {
		case 'a' :
    case 'A' :
                  if(cameradefine==0){
			angle -= PI/2;
			lx = sin(angle);
			lz = -cos(angle);
                  angulo=(angulo-90)%360;
            }else{
                  angle -= PI/2;
                  lx = sin(angle);
                  lz = -cos(angle);
                  angulo=(angulo-90)%360;
                  x1=x*-sin(angle);
                  z1=z*cos(angle);

            }
			break;
		case 'd' :
    case 'D' :
                  if(cameradefine==0){
			angle += PI/2;
			lx = sin(angle);
			lz = -cos(angle);
                  angulo=(angulo+90)%360;
            }
			break;
		case 'w' :
    case 'W' :
            if(andar){
                if(p[0].angulo<=10){
                  p[0].angulo = (p[0].angulo + 1) % 360;
                  p[1].angulo = (p[1].angulo - 1) % 360;
            }
                if(p[0].angulo==11)
                  andar=0;
            }else{
                  if(p[1].angulo<=10){
                    p[0].angulo = (p[0].angulo - 1) % 360;
                    p[1].angulo = (p[1].angulo + 1) % 360;
                        }
                if(p[1].angulo==11)
                  andar=1;
            }
			x += lx * fraction;
			z += lz * fraction;
			break;
		case 's':
    case 'S':
          if(andar==0){
              if(p[1].angulo<=10){
                p[0].angulo = (p[0].angulo - 1) % 360;
                p[1].angulo = (p[1].angulo + 1) % 360;
         }
              if(p[1].angulo==11)
                andar=1;
         }else{
                if(p[0].angulo<=10){
                  p[0].angulo = (p[0].angulo + 1) % 360;
                  p[1].angulo = (p[1].angulo - 1) % 360;
                      }
              if(p[0].angulo==11)
                andar=0;
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
                break;
      case'e':
      if(b[0].angulo<=85)
         b[0].angulo = (b[0].angulo + 5) % 360;
       break;
      case'q':
      if(b[0].angulo>=-75)
         b[0].angulo = (b[0].angulo - 5) % 360;
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
