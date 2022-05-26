#include "top.h"


typedef struct Threaded_treeNode *Threaded_treeNode_Ptr;
struct Threaded_treeNode{
    ElementType Data;
    int ltag,rtag;
    Threaded_treeNode_Ptr ltree;
    Threaded_treeNode_Ptr rtree;
};

void CreateTree_treaded(Threaded_treeNode_Ptr *Ptr);   //二级指针指向根结点
void InThreading(Threaded_treeNode_Ptr Ptr);  //中序遍历，建立tag


void InOrderTraverse_threaded(Threaded_treeNode_Ptr Ptr, void (*visit)(Threaded_treeNode_Ptr));

void visit_threaded(Threaded_treeNode_Ptr Ptr);