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
#include "threaded_bin_tree.h"

int main()
{
    Threaded_treeNode_Ptr node;
    CreateTree_treaded(&node);
    InThreading(node);
    InOrderTraverse_threaded(node,visit_threaded);
    return 0;
}
