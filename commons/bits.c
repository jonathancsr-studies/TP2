#include "bits.h"

int haveMask(char element, char mask){
	return (element & mask) == mask;
}

char setMask(char element, char mask){
	return element | mask;
}

char clearMask(char element, char mask){
	return element & mask;
}
