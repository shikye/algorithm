#define ElementType int


typedef struct Queue_linked_node *Queue_node_Ptr;
typedef struct Queue_linked_manage *Quque_linked_Ptr;


struct Queue_linked_node{
    ElementType Data;
    Queue_node_Ptr Next;
};

struct Queue_linked_manage{
    Queue_node_Ptr front;
    Queue_node_Ptr rear;
};

Quque_linked_Ptr MakeEmpty_Queue_linked();

void AddQ_linked(Quque_linked_Ptr Ptr, ElementType Data);

ElementType DeleteQ_linked(Quque_linked_Ptr Ptr);