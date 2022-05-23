#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "debug.h"

int main()
{
    List P;
    P = MakeEmpty();
    Insert(1, 1, P);
    Insert(1, 2, P);
    return 0;

}
