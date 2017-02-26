#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */
typedef int Status;
typedef int SElemType;
typedef struct{
    SElemType data[MAXSIZE];
    int top1;
    int top2;
}SqDoubleStack;
Status visit(SElemType c)
{
    printf("%d ",c);
    return OK;
}
Status InitStack(SqDoubleStack *S)
{
    S->top1=-1;
    S->top2=MAXSIZE;
    return OK;
}
Status ClearStack(SqDoubleStack *s)
{
    s->top1=-1;
    s->top2=MAXSIZE;
}
Status StackEmpty(SqDoubleStack S)
{
    if(S.top1==-1&&S.top2==MAXSIZE)
        return TRUE;
    else
        return FALSE;
}
int StackLength(SqDoubleStack S)
{
    return (S.top1+1)+(MAXSIZE-S.top2);
}
Status Push(SqDoubleStack *S,SElemType e,int stackNumber)
{
    if(S->top1+1==S->top2)
        return ERROR;
    if(stackNumber==1)
        S->data[++S->top1]=e;
    else if(stackNumber==2)
        S->data[--S->top2]=e;
    return OK;
}
Status Pop(SqDoubleStack *S,SElemType *e,int stackNumber)
{
    if(stackNumber==1)
    {
        if(S->top1==-1)
            return ERROR;
        *e=S->data[S->top1--];
    }
    else if(stackNumber==2)
    {
        if(S->top2==MAXSIZE)
            return ERROR;
        *e=S->data[S->top2++];
    }
    return OK;
}
Status StackTraverse(SqDoubleStack S)
{
        int i;
        i=0;
        while(i<=S.top1)
        {
                visit(S.data[i++]);
        }
        i=S.top2;
        while(i<MAXSIZE)
        {
                visit(S.data[i++]);
        }
        printf("\n");
        return OK;
}
int main()
{
    SqDoubleStack s;
    int e,j;
    if(InitStack(&s)==OK)
    {
        for(j=1;j<=5;j++)
            Push(&s,j,1);
        for(j=MAXSIZE;j>=MAXSIZE-2;j--)
            Push(&s,j,2);
    }
    printf("栈中元素依次为:");
    StackTraverse(s);
    printf("当前栈的元素由: %d \n",StackLength(s));
    Pop(&s,&e,2);
    printf("弹出栈的栈顶元素e=%d\n",e);
    printf("栈是否为空:%d（1：空0：否）\n",StackEmpty(s));
    for(j=6;j<=MAXSIZE-2;j++)
        Push(&s,j,1);
    printf("栈中的元素依次为：");
    StackTraverse(s);
    printf("栈满否:%d(1:否0：满\n",Push(&s,100,1));
    ClearStack(&s);
    printf("清空栈后,栈空否:%d(1:空0：否)\n",StackEmpty(s));
    return 0;
}
