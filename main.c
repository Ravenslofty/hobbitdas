#include "u.h"
#include "mach.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern void hobbitprintins(Map *, char, int);

// unused, but exist to preserve `hobbitdas.c`.
ulong dot;
ulong dotinc;

const char isqrt[0x1a + 2] = {
    0x00, 0x00, // padding because hobbitdas looks backwards for a CPU instruction
    0x0b, 0xfc,
    0x40, 0x04,
    0x60, 0x8c,
    0x18, 0x09,
    0x60, 0x88,
    0xb7, 0xdd, 0x00, 0x04, 0x00, 0x0c,
    0x59, 0x04,
    0x7c, 0x24,
    0x4c, 0x88,
    0x17, 0xf9,
    0x08, 0x06
};

int main() {
    Map map;
    map.data = malloc(0x1a + 2);
    memcpy(map.data, &isqrt, 0x1a + 2);
    dot = 2;
    dotinc = 0;
    do {
        printf("%8lx: ", dot);
        hobbitprintins(&map, 0, 0x00000000);
        printf("\n");
        dot += dotinc;
    } while (dot != 0x1a + 4);
    free(map.data);
}
