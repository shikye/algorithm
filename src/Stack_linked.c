#include "Stack_linked.h"
#include <stdio.h>
#include <stdlib.h>


Stack_linked_Ptr Init_Stack_Linked(Stack_linked_Ptr Ptr) //头结点
{
    if(Ptr == NULL){
        Stack_linked_Ptr Ptr = (Stack_linked_Ptr)malloc(sizeof(struct Stack_linked_node));
        Ptr -> Data = -1;
        Ptr -> Next = NULL;
    }
    else
        return Ptr;
}

void Push_linked(Stack_linked_Ptr Ptr, ElementType Data)   //初始头结点指向栈顶
{
    Stack_linked_Ptr new = (Stack_linked_Ptr)malloc(sizeof(struct Stack_linked_node));
    new -> Data = Data;
    new -> Next = Ptr -> Next;
    Ptr -> Next = new;
}

ElementType Pop_linked(Stack_linked_Ptr Ptr)
{
    if(Ptr -> Next == NULL)
        return -1;
    else{
        Stack_linked_Ptr pop = Ptr -> Next;
        ElementType swap;
        swap = pop->Data;
        Ptr -> Next = pop->Next;
        free(pop);
        return swap;
    }
}

int Stack_Empty_linked(Stack_linked_Ptr Ptr)
{
    if(Ptr -> Next == NULL)
        return 1;
    else
        return 0;
}