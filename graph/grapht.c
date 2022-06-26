#include <stdio.h>
#include <stdlib.h>

#define Maxvertex 20
#define Vertex int
#define DataType int
#define WeightType int

typedef struct GNode * PtrToGNode;
typedef PtrToGNode LGraph;
struct GNode{
    int Nv;
    int Ne;
    AdjList G;  //会初始化整个数组
};

typedef struct Enode* Edge;
struct ENode{
    Vertex V1,V2;
    WeightType Weight;
};


typedef struct AdjVNode * PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV;
    WeightType Weight;
    PtrToAdjVNode Next;
};

 
typedef struct Vnode{             *******
    PtrToAdjVNode FirstEdge; 
    DataType Data;
}AdjList[Maxvertex];          //此时AdjList代表的是整个数组 而不是一个指针


LGraph CreateLGraph(){
    LGraph Graph;
    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = Maxvertex;
    Graph->Ne = 0;
    for(int i = 0; i < Graph->Nv; i++)
        Graph->G[i].FirstEdge = NULL;
    return Graph;
}

void InsertLGraph(LGraph Graph, Edge E){
    PtrToAdjVNode NewNode;
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;

    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildLGraph(){
    LGraph Graph = CreateLGraph();
    scanf("%d",&Graph->Ne);
    if(Graph->Ne != 0)
    {
        Edge = (Edge)malloc(sizeof(struct ENode));
        for(int i = 0; i < Graph->Ne; i++)
        {
            scanf("%d %d %d",&Edge->V1,&Edge->V2,&Edge->Weight);
            InsertLGraph(LGraph,E);
        }
    }
    return Graph;
}