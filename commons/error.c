#include "error.h"

void error(char *message){
	printf("error: %s\n", message);
	exit(1);	
}

void warning(char *message){
	printf("warning: %s\n", message);
}

void info(char *message){
	printf("info: %s\n", message);
}