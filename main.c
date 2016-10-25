#include "lib/include.h"
#include "generators/generator.h"
#include "io/tui.h"
#include "io/arquivador.h"

extern int pular=0;
extern int cameradefine=0;
extern int lanterna=0;
int modoDoJogo=0;
extern PERNA p[2];
extern BRACO b[2];
extern char mapLab;
// Labirinto tamanhao
int linhas=20,colunas=20;
//
int larguraJanela,alturaJanela;
extern float angle=0.0f;
// actual vector representing the camera's direction
extern float lx=0.0f,lz=-1.0f,ly= 0.0f;
// XZ position of the camera
extern float camera_x=0.0f,camera_z=5.0f,camera_y=2.0f;
extern int width, height;
extern float posicaoX,posicaoZ;
extern ponto entrada;
Labirinto lab_Master;
extern int matrizz[200][200];

void camera(){
    if(cameradefine == 0){
    gluLookAt(	camera_x, camera_y, camera_z,
 			camera_x+lx, camera_y,  camera_z+lz,
 			0.0f, 1.0f,  0.0f);
      }else{
    gluLookAt(	camera_x-CAMERAPERSONAGEM*sin(angle), camera_y+3.0f, camera_z+CAMERAPERSONAGEM*cos(angle),
			camera_x-CAMERAPERSONAGEM*sin(angle)+lx, camera_y+3.0f,  camera_z+CAMERAPERSONAGEM*cos(angle)+lz,
			0.0f, 1.0f,  0.0f);
    }
}

void redimensionada(int w, int h)
{
     glMatrixMode (GL_PROJECTION);
     glLoadIdentity ();
     glViewport (0, 0, (GLsizei) w, (GLsizei) h);
     larguraJanela=w;
     alturaJanela=h;
     gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 0.9, 100.0);
     glMatrixMode(GL_MODELVIEW);
}

void desenhaCena(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_LIGHTING);
  glShadeModel(GL_SMOOTH);
  glLoadIdentity();
	//ATIVA A CAMERA GLULOOKAT
	camera();
  //DESENHA LUZES
  //luzes();
	//DESENHA O PERSONAGEM
	desenhaPersonagem();
  //DESENHA TERRENO E TETO
	plano(camera_x,camera_z,larguraJanela,0,1,1,1);
  //DESENHA O LABIRINTO
  desenhaLabirinto(lab_Master);
  glDisable(GL_LIGHTING);
  glutSwapBuffers();
}

void inicializa(void)
{
  //carregaMapa(matriz_cores_map);
  geraLabirinto(lab_Master);
  configuraIluminacao();
  glClearColor(0.6,0.0,0.0,1.0);
  camera_x=8.0f,camera_z=8.0f,camera_y=4.0f;
  matrizmovimento(lab_Master);
}

int main(int argc, char **argv) {


      glutInit(&argc, argv);
      glutInitContextVersion(1,1);
      glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
      glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE | GLUT_RGBA);
      glutInitWindowSize(LARGURA,ALTURA);
      glutInitWindowPosition(100,100);
      glutCreateWindow("JOGO");
      inicializa();

      glutDisplayFunc(desenhaCena);
      glutReshapeFunc(redimensionada);
      glutKeyboardFunc(teclasPressionada);
      glutSpecialFunc(setasPressionadas);
      glutIdleFunc(desenhaCena);
      glEnable(GL_DEPTH_TEST);
      glutMainLoop();
      return 0;
}
