#define MAXSIZE 100
#include "top.h"

struct Seq_node{
    ElementType Data[MAXSIZE];
    int Last;
};

typedef struct Seq_node Seqnode,*Seq_Ptr;

Seq_Ptr MakeEmpty_seq();
int FindPosition(ElementType X,Seq_Ptr PtrL);
void Insert_seq(ElementType X, int i, Seq_Ptr PtrL); //i表示位置而不是下标
ElementType Delete_seq(int i, Seq_Ptr PtrL);
