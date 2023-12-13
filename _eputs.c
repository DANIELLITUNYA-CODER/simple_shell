#include "eputs.h"
#include <stdio.h>

void _eputs(const char *str) {
    fprintf(stderr, "%s", str);
}

void _eputchar(char c) {
    fputc(c, stderr);
}

