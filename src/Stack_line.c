#include "Stack_line.h"
#include <stdlib.h>
#include <stdio.h>

Stack_Seq_Ptr MakeEmpty_Stack_Seq()    //top是最高有数据存储的位置
{
    Stack_Seq_Ptr Ptr = (Stack_Seq_Ptr)malloc(sizeof(struct Stack_Seq));
    Ptr -> top = -1;
    return Ptr;
}


ElementType Pop_Seq(Stack_Seq_Ptr Ptr)
{
    if(Ptr -> top < 0)
        return -1;
    else{
        Ptr -> top --;
        return Ptr->Data[Ptr->top+1];
    }
}

void Push_Seq(Stack_Seq_Ptr Ptr, ElementType Data)
{
    if(Ptr->top >= MaxSize)
        ;
    else
        Ptr->Data[++Ptr->top] = Data;
}