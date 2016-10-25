#include "lib/include.h"
extern GLint cameraX,cameraY,cameraZ;
float angle;
int angulo;
// actual vector representing the camera's direction
float lx,lz,ly;
// XZ position of the camera
float camera_x,camera_z,camera_y;
int cameradefine,lanterna;
PERNA p[2];
BRACO b[2];
int pular;
int matrizz[200][200];

void teclasPressionada(unsigned char key, int a, int w){

float fraction = 0.7f;
int x,z;
x=(camera_x/4)-1;
z=(camera_z/4)-1;
  switch (key) {
            case' ':

            if(pular==0){
            pular=1;
            puloPersonagem();
      }
                  break;
		case 'a' :
    case 'A' :
			angle -= (5*PI)/180;
			lx = sin(angle);
			lz = -cos(angle);
                  angulo+=5;

			break;
		case 'd' :
    case 'D' :
			angle += (5*PI)/180;
			lx = sin(angle);
			lz = -cos(angle);
                  angulo-=5;
			break;
		case 's' :
    case 'S' :
                  movimentacaoMembros(1);
			camera_x -= lx * fraction;
			camera_z -= lz * fraction;
			break;
		case 'w':
    case 'W':
                  movimentacaoMembros(0);
			camera_x += lx * fraction;
			camera_z += lz * fraction;
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
          camera_y++;
          break;
          case'm':
          printf("0-%f %f \n",camera_x,camera_z);
          printf("1-%d %d \n",x,z);
          printf("p-%d\n",matrizz[x][z]);
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
      int x,z,lx1=lx+0.6,lz1=lz+0.6;
      x=(camera_x/4)-1;
      z=(camera_z/4)-1;
      switch (key) {
            case GLUT_KEY_LEFT :
            angle -= (5*PI)/180;
            lx = sin(angle);
            lz = -cos(angle);
            angulo+=5;
                  break;
            case GLUT_KEY_RIGHT :
            angle += (5*PI)/180;
            lx = sin(angle);
            lz = -cos(angle);
            angulo-=5;
                  break;
            case GLUT_KEY_UP :
            if(matrizz[x][z]==0){
            movimentacaoMembros(0);
            camera_x += lx * fraction;
            camera_z += lz * fraction;
      }
                  break;
            case GLUT_KEY_DOWN :
            movimentacaoMembros(1);
            camera_x -= lx * fraction;
            camera_z -= lz * fraction;
                  break;
      }
}
