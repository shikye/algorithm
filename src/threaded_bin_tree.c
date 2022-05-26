#include "threaded_bin_tree.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *string_threaded_tree = "12##3##";


void CreateTree_treaded(Threaded_treeNode_Ptr *Ptr)
{
    char data[2];
    Threaded_treeNode_Ptr root;
    strncpy(data,string_threaded_tree,1);
    string_threaded_tree = string_threaded_tree + 1;
    if(data[0] == '#')
    {
        *Ptr = NULL;
    }
    else{
        *Ptr = (Threaded_treeNode_Ptr)malloc(sizeof(struct Threaded_treeNode));
        //*Ptr -> Data = data[0];  表达式里不能带指针？
        root = *Ptr;
        root->Data = data[0];
        CreateTree_treaded(&(root->ltree));
        CreateTree_treaded(&(root->rtree));
    }
}


Threaded_treeNode_Ptr pre = NULL; //前驱应为全局变量，否则根节点不能给左子树的最后一个元素找到后继
void InThreading(Threaded_treeNode_Ptr Ptr) //pre是直接前驱，初始应该是头结点，没头节点则空  加tag
{
    if(Ptr){
        //左
        InThreading(Ptr->ltree);     //Ptr为上一个根节点，是根节点下左子树的第一个结点的直接前驱                             //左
        //当前 -- 确定当前结点和上一结点的链接                                                                           //根
        if(!Ptr->ltree)                  //若此结点没有左子树，则左链域指向直接前驱
        {
            Ptr->ltag = 1;
            Ptr->ltree = pre;
        }
        if(pre == NULL)
            ;
        else{
            if(!pre->rtree)                  //若上一个节点没有右子树，则右链域指向直接后继
            {                                //左右一起确定一次链接
                pre->rtag = 1;
                pre->rtree = Ptr;
            }
        }
        //右
        pre = Ptr;     //右子树中第一个结点的直接前驱是当前结点，左子树最后一个结点的后续是根节点
        InThreading(Ptr->rtree);
    }
}

void InOrderTraverse_threaded(Threaded_treeNode_Ptr Ptr, void (*visit)(Threaded_treeNode_Ptr)) //非递归使用while
{
    while(Ptr)
    {
        while(Ptr->ltag != 1) Ptr = Ptr->ltree;  //找到起始
        visit_threaded(Ptr);
        while(Ptr->rtag == 1 && Ptr->rtree != NULL) //叶子结点找到根结点
        {
            Ptr = Ptr->rtree;
            visit_threaded(Ptr);
        }
        Ptr = Ptr->rtree;          //没有右tag 则有右子树，对右子树执行操作     或右链域为空，即为最后一个结点
    }
}

void visit_threaded(Threaded_treeNode_Ptr Ptr)
{
    printf("%c\n",Ptr->Data);
    return ;
}