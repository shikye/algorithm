

#define MAXSIZE 100
#define ElementType int

struct Lnode{
    ElementType Data[MAXSIZE];
    int Last;
};

typedef struct Lnode seqnode,*List;

List MakeEmpty();
int FindPosition(ElementType X,List PtrL);
void Insert(ElementType X, int i, List PtrL); //i表示位置而不是下标
ElementType Delete(int i, List PtrL);
