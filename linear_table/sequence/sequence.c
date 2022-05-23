#include <stdio.h>
#include <stdlib.h>
#include "debug.h"
#include "sequence.h"





List MakeEmpty()
{
    List PtrL;
    PtrL = (List)malloc(sizeof(seqnode));
    PtrL -> Last = -1;
    return PtrL;
}

int FindPosition(ElementType X,List PtrL)
{
    int i = 0;
    while(i <= PtrL -> Last && X != PtrL -> Data[i]){
        i++;
    }
    if(i > PtrL -> Last){
        return -1;
        panic("FindPosition Error");
    }
        
    else 
        return i;
}

void Insert(ElementType X, int i, List PtrL) //i表示位置而不是下标
{
    int j;
    if(PtrL -> Last == MAXSIZE - 1)
        panic("Insert Full");
    else if(i<1 || i>PtrL->Last + 2)
        panic("Insert Place Wrong");
    
    for(j = PtrL -> Last; j>=i-1;j--)
        PtrL->Data[j+1] = PtrL->Data[j];
    PtrL->Data[i-1] = X; 
    PtrL->Last++;
}

ElementType Delete(int i, List PtrL)
{
    int j;
    ElementType swap;
    if(i<1 || i>PtrL->Last + 1)
    {
        panic("Delete Wrong Place");
        return -1;
    }
    swap = PtrL->Data[i-1];
    PtrL->Last --;
    for(j = i-1; j < PtrL->Last ; j++)
        PtrL->Data[j] = PtrL->Data[j+1];
    return swap;
}