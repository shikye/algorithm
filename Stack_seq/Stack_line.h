#define MaxSize 100
#define ElementType int


typedef struct Stack_Seq *Stack_Seq_Ptr;

struct Stack_Seq{
    ElementType Data[MaxSize];
    int top;
};

Stack_Seq_Ptr MakeEmpty_Stack_Seq();

ElementType Pop_Seq(Stack_Seq_Ptr Ptr);

void Push_Seq(Stack_Seq_Ptr Ptr, ElementType data);
