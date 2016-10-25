#include "lib/include.h"


unsigned int loadFileTexture(char nometextura[]){
    glClearColor (1, 1, 1, 0);

    GLuint tex = SOIL_load_OGL_texture(
        nometextura,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
      );

    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );


    if (tex == 0) {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
    return tex;
}

void loadTexture(){
	textureWalls = loadFileTexture("./texture/texture_wall/wall.png");
}
