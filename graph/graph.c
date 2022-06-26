#include <stdio.h>
#include <stdlib.h>

#define WeightType int
#define DataType int
#define Vertex int
#define MaxvertexNum 10
///
typedef struct GNode *PtrToGNode;
typedef PtrToGNode MGragh;

struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxvertexNum][MaxvertexNum];
    DataType Data[MaxvertexNum];
};
///
typedef struct ENode *PtrToENode;
typedef PtrToENode Edge;

struct Enode{
   Vertex V1,V2;   //有向边
   WeightType Weight;
};
///


MGragh CreateGraph(int VertexNum){
    MGragh Graph;
    Graph = (MGragh)malloc(sizeof(struct GNode));   
    Graph -> Nv = VertexNum;
    Graph -> Ne = 0;

    for(Vertex V = 0; V < VertexNum; V++)
        for(Vertex W = 0; W < VertexNum; W++)
            Graph -> G[V][W] = 0;

    return Graph;
}

void InsertEdge(MGragh Graph, Edge E){
    Graph->G[E->V1][E->V2] = E->Weight;
    Graph->G[E->V2][E->V1] = E->Weight;
}

MGragh BuildGraph(){
    MGragh Graph;
    int Nv;
    
    scanf("%d",&Nv);
    Graph = CreateGraph(Nv);
    scanf("%d",&Graph->Ne);
    if(Graph -> Ne != 0)
    {
        Edge E = (Edge)malloc(sizeof(struct Enode));
        for(int i = 0; i< Graph->Ne; i++){
            scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
            InsertEdge(Graph,E);
        }
    }
    return Graph;
}


///
