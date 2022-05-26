#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin_tree.h"
#include "Stack_linked.h"

char *string_bin_tree = "11##2##";

void CreateTree_Bin(TreeNode_Ptr *Ptr) //传二级指针，因为int型指针能改变外部int的值，类似的，指针的指针能改变指针的值，
                                        //即，若想改变一级指针的值，则应该传二级指针。
{
    char data[2];
    strncpy(data,string_bin_tree,1);
    string_bin_tree = string_bin_tree + 1;
    TreeNode_Ptr root;
    if(data[0] == '#')
    {
        *Ptr = NULL;
    }
    else{
        *Ptr = (TreeNode_Ptr)malloc(sizeof(struct TreeNode));
        root = *Ptr;
        root -> Data = data[0]; 
        CreateTree_Bin(&(root->ltree));
        CreateTree_Bin(&(root->rtree));
    }
}

void PreOrderTravserse_recursion(TreeNode_Ptr Ptr,void (*visit)(TreeNode_Ptr))
{
    if(Ptr){
        visit(Ptr);
        PreOrderTravserse_recursion(Ptr->ltree,visit);
        PreOrderTravserse_recursion(Ptr->rtree,visit);
        return ;
    }
    else
    {
        return ;
    }
}

void PreOrderTravserse_Stack(TreeNode_Ptr Ptr,void (*visit)(TreeNode_Ptr))
{
    Stack_linked_Ptr Stack = NULL;
    Stack = Init_Stack_Linked(Stack);
    TreeNode_Ptr root = Ptr;
    while(root || !Stack_Empty_linked(Stack))             //一种访问情况
    {
        if(root)
        {
            visit(root);
            Push_linked(Stack,root);
            root = root->ltree;
        }
        else{
            root = Pop_linked(Stack);
            root = root->rtree;
        }
    }
    free(Stack);
}

void InOrderTravserse_recursion(TreeNode_Ptr Ptr,void (*visit)(TreeNode_Ptr))
{
    if(Ptr){
        InOrderTravserse_recursion(Ptr->ltree,visit);
        visit(Ptr);
        InOrderTravserse_recursion(Ptr->rtree,visit);
        return ;
    }
    else
    {
        return ;
    }
}

void InOrderTravserse_Stack(TreeNode_Ptr Ptr,void (*visit)(TreeNode_Ptr))
{
    Stack_linked_Ptr Stack = NULL;
    Stack = Init_Stack_Linked(Stack);
    TreeNode_Ptr root = Ptr;
    while(root || !Stack_Empty_linked(Stack))
    {
        if(root)
        {
            Push_linked(Stack,root);
            root = root->ltree;
        }
        else{
            root = Pop_linked(Stack);
            visit(root);
            root = root->rtree;
        }
    }
    free(Stack);
}


void PostOrderTravserse_recursion(TreeNode_Ptr Ptr,void (*visit)(TreeNode_Ptr))
{
    if(Ptr){
        PostOrderTravserse_recursion(Ptr->ltree,visit);
        PostOrderTravserse_recursion(Ptr->rtree,visit);
        visit(Ptr);
        return ;
    }
    else
    {
        return ;
    }
}

void PrintData(TreeNode_Ptr Ptr)
{
    printf("%c\n",Ptr->Data);
    return ;
}