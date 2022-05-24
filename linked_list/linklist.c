#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

Linked_Ptr MakeEmpty_linked() //返回头结点指针
{
    Linked_Ptr head = (Linked_Ptr)malloc(sizeof(Linkednode));
    head -> Data = -1;
    head -> Next = NULL;
    return head;
}
 
int Length(Linked_Ptr Ptr) //Ptr为头节点
{
    Linked_Ptr L = Ptr;
    int j = 0;
    if(!L->Next){
        j ++;
        L = L->Next;
    }
    return j;
}

Linked_Ptr FindKth(int K, Linked_Ptr Ptr)
{
    Linked_Ptr L = Ptr;
    if(K < 1)
        ;
    while(K>0){
        if(L->Next == NULL){;
            return NULL;
        }
        L = L->Next;
        K --;
    }
    return L;
}

void Insert_linked(int i, Linked_Ptr Ptr, ElementType X) //Ptr是头结点
{
    
    if(i == 1){
        Linked_Ptr top = (Linked_Ptr)malloc(sizeof(Linkednode));
        top -> Next = Ptr -> Next;
        top -> Data = X;
        Ptr -> Next = top;
        return;
    }

    Linked_Ptr loc = FindKth(i-1,Ptr);
    if(!loc){
        ;
    }
    Linked_Ptr new = (Linked_Ptr)malloc(sizeof(Linkednode));
    new -> Next = loc ->Next;
    new -> Data = X;
    loc -> Next = new;
    return;
}

ElementType Delete_linked(int i, Linked_Ptr Ptr)
{
    ElementType swap;
    Linked_Ptr p = FindKth(i,Ptr);
    if(i == 1){
        Ptr -> Next = p -> Next;
        swap = p -> Data;
        free(p);
        return swap;
    }

    Linked_Ptr p_pre = FindKth(i-1,Ptr);
    if(!p_pre)
        ;
    else{
        p_pre -> Next = p -> Next;
        swap = p -> Data;
        free(p);
        return swap;
    }
}