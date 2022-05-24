#include "Stack_linked.h"
#include "debug.h"
#include <stdio.h>
#include <stdlib.h>


Stack_linked_Ptr MakeEmpty_Stack_Linked() //头结点
{
    Stack_linked_Ptr Ptr = (Stack_linked_Ptr)malloc(sizeof(struct Stack_linked_node));
    Ptr -> Data = -1;
    Ptr -> Next = NULL;
}

void Push_linked(Stack_linked_Ptr Ptr, ElementType Data)
{
    Stack_linked_Ptr new = (Stack_linked_Ptr)malloc(sizeof(struct Stack_linked_node));
    new -> Data = Data;
    new -> Next = Ptr -> Next;
    Ptr -> Next = new;
}

ElementType Pop_linked(Stack_linked_Ptr Ptr)
{
    if(Ptr -> Next == NULL)
        panic("Pop_linked Wrong");
    else{
        Stack_linked_Ptr pop = Ptr -> Next;
        ElementType swap;
        swap = pop->Data;
        Ptr -> Next = pop->Next;
        free(pop);
        return swap;
    }
}