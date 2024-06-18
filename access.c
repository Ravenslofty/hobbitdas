// highly abbreviated /sys/src/cmd/acid/access.c

#include "u.h"
#include "mach.h"

int
get4(Map *map, ulong addr, int space, ulong *x)
{
    // get4 calls a lot of nested functions, simply to read 4 bytes.
    // - lofty
    USED(space);
    *x = map->data[addr+0] | (map->data[addr+1] << 8) | (map->data[addr+2] << 16) | ((ulong)(map->data[addr+3]) << 24);
    return 1;
}
