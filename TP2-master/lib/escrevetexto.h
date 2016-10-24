#ifndef ESCREVERTEXTO_H
#define ESCREVERTEXTO_H

// Função que recebe a fonte e um texto por parâmetro para ser exibido na
// tela usando caracteres bitmap
void DesenhaTexto(void *font, char *string)
{
	// Exibe caractere a caractere
	while(*string)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,*string++);
}

// Função que recebe a fonte e um texto por parâmetro para ser exibido na
// tela usando fonte de linhas
void DesenhaTextoStroke(void *font, char *string)
{
	// Exibe caractere a caractere
	while(*string)
		glutStrokeCharacter(GLUT_STROKE_ROMAN,*string++);
}

// Função callback de redesenho da janela de visualização
void Desenha(void)
{
	// Limpa a janela de visualização com a cor de fundo definida
	glClear(GL_COLOR_BUFFER_BIT);

	// Define a cor para os textos: preto
	glColor3f(1,0,0);

	// Posiciona o texto stroke usando transformações geométricas
	glPushMatrix();
	glTranslatef(-50,0,0);
	glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
	//glRotatef(15, 0,0,1); // rotaciona o texto
	glLineWidth(2); // define a espessura da linha
	DesenhaTextoStroke(GLUT_STROKE_ROMAN,"Teste");
	glPopMatrix();

	// Posição no universo onde o texto bitmap será colocado
	glColor3f(0,0,1);
	//glScalef(0.1, 0.1, 0.1); // diminui o tamanho do fonte
	//glRotatef(15, 0,0,1); // rotaciona o texto
    glRasterPos2f(-20,-20);
	DesenhaTexto(GLUT_BITMAP_9_BY_15,"OpenGl");
	// Exibe o desenha na janela
	glutSwapBuffers();
}


#endif
