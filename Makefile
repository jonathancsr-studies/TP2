CC=gcc
CFLAGS=-lSOIL -lGL -lglut -lGLEW -lm -lSDL `sdl-config --cflags --libs` -lSDL -lSDL_mixer
DEPS=personagem.h cenario.h keyboard.h textura.h

%.o:%.c $(DEPS)
	$(CC) -c -o %@ $< $(CFLAGS)

aplicacao: main.c personagem.c music.c Cenario.c keyboard.c textura.c
	$(CC) -o execut.exe main.c personagem.c music.c Cenario.c keyboard.c textura.c $(CFLAGS)
