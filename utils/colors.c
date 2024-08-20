
#include "colors.h"

const char *colors[] = {
    "\033[1;31m", // Vermelho
    "\033[1;34m", // Azul
    "\033[1;35m", // Magenta
    "\033[1;36m", // Ciano
};
int numColors = sizeof(colors) / sizeof(colors[0]);
int colorIndex = 0;
