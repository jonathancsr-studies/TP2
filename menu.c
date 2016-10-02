#include "include.h"
extern int pause;

void menu_esc(unsigned char key)
{
  switch (key) {
    case 's':
    case 'S':
              exit(0);
              break;
    case 'n':
    case 'N':
            pause = 1;
            break;
  }
}
