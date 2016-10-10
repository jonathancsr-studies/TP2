CC=gcc
OPCOES_COMPILADOR=-I. -lSOIL -lGL -lGLU -lglut -lGLEW -lm -lSDL `sdl-config --cflags --libs` -lSDL -lSDL_mixer
TODOS_ARQUIVOS_PONTOH = lib/personagem.h lib/cenario.h lib/keyboard.h lib/textura.h lib/menu.h lib/music.h lib/include.h lib/escreventexto.h
TODOS_ARQUIVOS_OBJ = main.o personagem.o music.o Cenario.o keyboard.o textura.o

%.o: ../%.c $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)

all: $(TODOS_ARQUIVOS_OBJ)
	gcc -o main $^ $(OPCOES_COMPILADOR)

run: all
	./main

clean:
	rm *.o main
