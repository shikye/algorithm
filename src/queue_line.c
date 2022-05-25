#include <stdio.h>
#include <stdlib.h>
#include "queue_line.h"


Queue_Seq_Ptr MakeEmpty_Queue_Seq()  //循环队列
{
    Queue_Seq_Ptr Ptr = (Queue_Seq_Ptr)malloc(sizeof(struct Queue_Seq));
    Ptr -> front = 0;
    Ptr -> rear = 0;
    return Ptr;
}

void AddQ_Seq(Queue_Seq_Ptr Ptr, ElementType item)
{
    if((Ptr -> rear + 1)%MaxSize == Ptr -> front)
        printf("error addq!");
    else{
        Ptr -> rear = (Ptr -> rear + 1)% MaxSize;
        Ptr -> Data[Ptr->rear] = item;
    }
}

ElementType DeleteQ_Seq(Queue_Seq_Ptr Ptr)
{
    if(Ptr->front == Ptr->rear){
        printf("error Deleteq");
        return -1;
    }
    else{
        Ptr->front = (Ptr->front+1)%MaxSize;
        return Ptr->Data[Ptr->front];
    }
}