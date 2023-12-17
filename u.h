// highly abbreviated /hobbit/include/u.h

typedef unsigned short  ushort;
typedef unsigned long   ulong;

// USED is a builtin on the Plan 9 compiler; replace it with the standard C
// equivalent.
// - lofty

#define USED(x) (void)(x)
