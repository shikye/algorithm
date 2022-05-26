#include "top.h"


typedef struct Linked_node *Linked_Ptr,Linkednode;
struct Linked_node{
    ElementType Data;
    Linked_Ptr Next;
};


Linked_Ptr MakeEmpty_linked();
int Length(Linked_Ptr Ptr);
Linked_Ptr FindKth(int K, Linked_Ptr Ptr);
void Insert_linked(int i, Linked_Ptr Ptr, ElementType X);
ElementType Delete_linked(int i, Linked_Ptr Ptr);