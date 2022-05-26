#define ElementType int


typedef struct TreeNode *TreeNode_Ptr;
struct TreeNode{
    TreeNode_Ptr ltree;
    TreeNode_Ptr rtree;
    ElementType Data;
};


void CreateTree_Bin(TreeNode_Ptr *Ptr);   //二级指针指向根结点