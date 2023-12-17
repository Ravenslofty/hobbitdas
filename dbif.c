// highly abbreviated /sys/src/cmd/acid/dbif.c

#include "u.h"
#include <stdio.h>

void
psymoff(ulong ival, int t, char* append)
{
        // psymoff resolves symbols within `acid`, but as a standalone
        // disassembler, I decided to just print the raw address.
        // - lofty
        printf("0x%lx%s", ival, append);
}
