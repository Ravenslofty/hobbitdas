// highly abbreviated /sys/src/cmd/acid/acid.h

Extern Map   *cormap;
Extern ulong  dot;
Extern ulong  dotinc;

// following functions marked extern to comply with GCC's strictness.
// - lofty
#define dprint printf // much easier than dealing with variadic functions to call printf
Extern int    get4(Map*, ulong, int, long*);
Extern void   psymoff(ulong, int, char*);
