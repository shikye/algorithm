#include <stdio.h>
#include <stdlib.h>
#include "queue_linked.h"

Quque_linked_Ptr MakeEmpty_Queue_linked()
{
    Quque_linked_Ptr Ptr = (Quque_linked_Ptr)malloc(sizeof(struct Queue_linked_manage));
    Ptr -> front = NULL;
    Ptr -> rear = NULL;
    return Ptr;
}

void AddQ_linked(Quque_linked_Ptr Ptr, ElementType item)
{
    if(Ptr->front == NULL && Ptr->rear == NULL)
    {
        Queue_node_Ptr node = (Queue_node_Ptr)malloc(sizeof(struct Queue_linked_node));
        Ptr->front = node;
        Ptr->rear = node;
        node -> Next = NULL;
        node -> Data = item;
    }
    else{
        Queue_node_Ptr node = (Queue_node_Ptr)malloc(sizeof(struct Queue_linked_node));
        (Ptr->rear)->Next = node;
        node -> Next = NULL;
        node -> Data = item;
        Ptr->rear = node;
    }
}

ElementType DeleteQ_linked(Quque_linked_Ptr Ptr)
{

    ElementType swap = 0;
    Queue_node_Ptr delete;
    if(Ptr->front == NULL && Ptr->rear == NULL)
    {
        printf("wrong DEleteqlinked!\n");
        return -1;
    }
    else if(Ptr->front == Ptr->rear){
        swap = (Ptr->front)->Data;
        free(Ptr->front); //这时值是多少？
        Ptr->front = NULL;
        Ptr->rear = NULL;
    }
    else{
        swap = (Ptr->front)->Data;
        delete = Ptr->front;
        Ptr->front = Ptr->front->Next;
        free(delete);
        return swap;
    }
}