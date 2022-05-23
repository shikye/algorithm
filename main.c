#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "linklist.h"
#include "debug.h"

int main()
{
    Linked_Ptr head = MakeEmpty_linked();

    Insert_linked(1,head,10);
    Insert_linked(1,head,20);
    int a = Delete_linked(1,head);
    printf("%d\n",a);
    a = FindKth(1,head) -> Data;
    printf("%d\n",a);
    return 0;

}
