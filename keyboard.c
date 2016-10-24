#include "lib/include.h"
extern GLint cameraX,cameraY,cameraZ;
float angle;
int angulo;
// actual vector representing the camera's direction
float lx,lz,ly;
// XZ position of the camera
float x,z,y;
int cameradefine,lanterna;
PERNA p[2];
BRACO b[2];
MAPACORES matriz_cores_map[200][200];
//float x,z;
void teclasPressionada(unsigned char key, int a, int w){

float fraction = 0.1f;

  switch (key) {
            case' ':
                  y++;
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
     case'q':
     		y++;
    		break;
     case'Q':
 		     y--;
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

      float fraction = 1.0f;
      int x1=x/6,z1=z/6,lx1=lx/6,lz1=lz/6;

      if(x<0){
            x1=-x/6;
      }
      if(z<0){
            z1=-z/6;
      }
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
            printf("\n %d %d",x1,z1);
            printf("\n %f %f",x,z);
            printf("\n %f %f  %f",matriz_cores_map[x1+lx1][z1+lz1].crgb[0],matriz_cores_map[x1+lx1][z1+lz1].crgb[1],matriz_cores_map[x1+lx1][z1+lz1].crgb[2]);
            if(matriz_cores_map[x1+lx1][z1+lz1].crgb[0]!=0  || matriz_cores_map[x1+lx1][z1+lz1].crgb[1]!=0 || matriz_cores_map[x1+lx1][z1+lz1].crgb[2]!=0){

            movimentacaoMembros(0);
            x += lx * fraction;
            z += lz * fraction;
      }
                  break;
            case GLUT_KEY_DOWN :
            if(matriz_cores_map[x1][z1].crgb[0]!=0  || matriz_cores_map[x1][z1].crgb[1]!=0 || matriz_cores_map[x1][z1].crgb[2]!=0){
            movimentacaoMembros(1);
            x -= lx * fraction;
            z -= lz * fraction;
                  break;
            }
      }
}
