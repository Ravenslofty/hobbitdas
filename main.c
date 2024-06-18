#include "u.h"
#include "mach.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

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

int main(int argc, char **argv) {
    int fd = -1;

    if (argc != 3) {
        printf("usage: %s file-to-disassemble offset\n", argv[0]);
        return -1;
    }
    
    int offset;
    if ((offset = atoi(argv[2])) < 2) {
        printf("offset must be at least 2, because the disassembler looks backwards one instruction\n");
        return -1;
    }

    if ((fd = open(argv[1], O_RDONLY, 0)) == -1) {
        perror("open failed");
        return -1;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat failed");
        return -1;
    }

    Map map;
    if ((map.data = (char*)mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0)) == MAP_FAILED) {
        perror("mmap failed");
        return -1;
    }

    dot = 2;
    dotinc = 0;
    do {
        printf("%8lx: ", dot);
        hobbitprintins(&map, 0, 0x00000000);
        printf("\n");
        dot += dotinc;
    } while (dot != st.st_size);

    return 0;
}
