#include "top.h"


typedef struct TreeNode *TreeNode_Ptr;
struct TreeNode{
    TreeNode_Ptr ltree;
    TreeNode_Ptr rtree;
    ElementType Data;
};


void CreateTree_Bin(TreeNode_Ptr *Ptr);   //二级指针指向根结点

void PreOrderTravserse_recursion(TreeNode_Ptr Ptr,void (*visit)(TreeNode_Ptr));
void PreOrderTravserse_Stack(TreeNode_Ptr Ptr,void (*visit)(TreeNode_Ptr));

void InOrderTravserse_recursion(TreeNode_Ptr Ptr,void (*visit)(TreeNode_Ptr));
void InOrderTravserse_Stack(TreeNode_Ptr Ptr,void (*visit)(TreeNode_Ptr));

void PostOrderTravserse_recursion(TreeNode_Ptr Ptr,void (*visit)(TreeNode_Ptr));

void PrintData(TreeNode_Ptr Ptr);