#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "linklist.h"
#include "Stack_line.h"
#include "Stack_linked.h"
#include "debug.h"
#include "queue_line.h"
#include "queue_linked.h"

int main()
{
    Quque_linked_Ptr Ptr = MakeEmpty_Queue_linked();
    AddQ_linked(Ptr,10);
    AddQ_linked(Ptr,20);
    AddQ_linked(Ptr,30);
    AddQ_linked(Ptr,40);   
    DeleteQ_linked(Ptr);
    DeleteQ_linked(Ptr);
    DeleteQ_linked(Ptr);

    int a = DeleteQ_linked(Ptr);
    printf("%d",a);
    return 0;

}
