#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin_tree.h"

char *string = "11###";

void CreateTree_Bin(TreeNode_Ptr *Ptr) //传二级指针，因为int型指针能改变外部int的值，类似的，指针的指针能改变指针的值，
                                        //即，若想改变一级指针的值，则应该传二级指针。
{
    char data[2];
    strncpy(data,string,1);
    string = string + 1;
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