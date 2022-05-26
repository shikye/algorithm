#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "linklist.h"
#include "Stack_line.h"
#include "Stack_linked.h"
#include "debug.h"
#include "queue_line.h"
#include "queue_linked.h"
#include "bin_tree.h"

int main()
{
    TreeNode_Ptr node;
    CreateTree_Bin(&node);
    PreOrderTravserse_Stack(node,PrintData);
    return 0;
}
