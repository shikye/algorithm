#include <stdio.h>
#include <malloc.h>

#define ElementType int

typedef struct BinTree{
    ElementType data;
    struct BinTree * pLchild;
    struct BinTree * pRchild;
}BT,*PBT;




PBT initial__bin_tree(void);
void pre_traversal(PBT);


PBT initial__bin_tree()
{
    PBT T = (PBT)malloc(sizeof(BT));
    scanf("%d",&T->data);
    T -> pLchild = NULL;
    T -> pRchild = NULL;
    return T;
}

PBT Insert(ElementType x, PBT T)
{
    if(!T)
    {
        T = (PBT)malloc(sizeof(BT));
        T -> data = x;
        T -> pLchild = NULL;
        T -> pRchild = NULL;
    }
    else if(x < T -> data)
        T->pLchild = Insert(x,T->pLchild);
    else if(x > T -> data)
        T->pRchild = Insert(x,T->pRchild);
   
    return T;
}


int main(){
    PBT Tree = initial__bin_tree();
    Insert(20,Tree);
    Insert(30,Tree);
    return 0;

}


