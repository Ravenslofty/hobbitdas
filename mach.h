// highly abbreviated /sys/include/mach.h

// this was originally an enum in the source, but modern C doesn't allow
// using enums as constexprs.
// - lofty

#define MAXSEGS 4

enum {
        /* file map segment names */
        SEGDATA = 1,            /* index into seg array of map */

        CTEXT  = 4,             /* symbol table classes */
        CDATA  = 5,
        CANY   = 6,             /* to look for any class */
};

/*
 *      Structure to map a segment to a position in a file
 */
typedef struct map Map;

struct map {
        // hobbitdas doesn't look inside map, so use it to store data.
        unsigned char* data;
};

/*
 *      Internal structure describing a symbol table entry
 */
typedef struct symbol Symbol;

struct symbol {
        void    *handle;                /* used internally - owning func */
        struct {
                char    *name;
                long    value;          /* address or stack offset */
                char    type;           /* as in a.out.h */
                char    class;          /* as above */
        };
};

// we don't have any symbols to find...
#define findsym(w, type, s) 0
