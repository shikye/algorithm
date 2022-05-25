#ifndef __MACRO_H__
#define __MACRO_H__

#include "assert.h"

#define Assert(cond, format, ...) \
    do { \
        if(!cond) { \
            fflush(stdout); \
            fprintf(stderr,format "\n"), \
            assert(cond); \
            } \
        }while(0)

#define panic(format) Assert(0, format, ...)

#endif
