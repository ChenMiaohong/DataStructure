#include<stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int Status;
typedef int SElemType;
typedef struct{
    SElemType data[MAXSIZE];
    int top;
}SqStack;
Status visit(SElemType c)
{
    printf("%d ",c);
    return OK;
}
Status InitStack(SqStack *s)
{
    s->top=-1;
    return OK;
}
Status ClearStack(SqStack *s)
{
    s->top=-1;
    return OK;
}
Status StackEmpty(SqStack S)
{
    if(S.top==-1)
        return OK;
    else
        return FALSE;
}
int StackLength(SqStack S)
{
    int l=++S.top;
    return l;
}
/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
Status GetTop(SqStack S,SElemType *e)
{
    if(S.top==-1)
        return ERROR;

    else
        *e=S.data[S.top];
    return OK;
}
Status Push(SqStack *S,SElemType e)
{
    if(S->top==MAXSIZE-1)
        return ERROR;
    S->data[++S->top]=e;
        return OK;
}
Status Pop(SqStack *S,SElemType *e)
{
    if(S->top==-1)
        return ERROR;
    *e=S->data[S->top--];
    return OK;
}
Status StackTraverse(SqStack S)
{
    int i;
    i=0;
    while(i<=S.top)
    {
        visit(S.data[i++]);
    }
    return OK;
}
int main()
{
    int j,e;
    SqStack s;
    if(InitStack(&s)==OK)
        for(j=1;j<=10;j++)
            Push(&s,j);
    printf("栈中元素依次为: ");
    StackTraverse(s);
    Pop(&s,&e);
    printf("弹出的栈顶元素e=%d\n",e);
    GetTop(s,&e);
    printf("栈顶元素e=%d栈的长度为%d\n",e,StackLength(s));
    ClearStack(&s);
    printf("清空栈后,栈空否:%d(1:空0:否)\n",StackEmpty(s));
}

