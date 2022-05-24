#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "linklist.h"
#include "Stack_line.h"
#include "Stack_linked.h"
#include "debug.h"

int main()
{
    Stack_linked_Ptr Ptr = MakeEmpty_Stack_Linked();
    Push_linked(Ptr,10);
    Push_linked(Ptr,20);
    Push_linked(Ptr,30);    
    int a = Pop_linked(Ptr);
    printf("%d",a);
    return 0;

}
