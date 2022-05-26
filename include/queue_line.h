#define MaxSize 100
#include "top.h"


typedef struct Queue_Seq *Queue_Seq_Ptr;

struct Queue_Seq{
    ElementType Data[MaxSize];
    int front;
    int rear;
};

Queue_Seq_Ptr MakeEmpty_Queue_Seq();

void AddQ_Seq(Queue_Seq_Ptr Ptr, ElementType Data);

ElementType DeleteQ_Seq(Queue_Seq_Ptr Ptr);