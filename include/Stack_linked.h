#include "top.h"


typedef struct Stack_linked_node *Stack_linked_Ptr;

struct Stack_linked_node{
    Stack_linked_Ptr Next;
    ElementType Data;
};

Stack_linked_Ptr Init_Stack_Linked(Stack_linked_Ptr Ptr);

void Push_linked(Stack_linked_Ptr Ptr, ElementType Data);

ElementType Pop_linked(Stack_linked_Ptr Ptr);

int Stack_Empty_linked(Stack_linked_Ptr Ptr);