#define ElementType int


typedef struct Stack_linked_node *Stack_linked_Ptr;

struct Stack_linked_node{
    Stack_linked_Ptr Next;
    ElementType Data;
};

Stack_linked_Ptr MakeEmpty_Stack_Linked();

void Push_linked(Stack_linked_Ptr Ptr, ElementType Data);

ElementType Pop_linked(Stack_linked_Ptr Ptr);