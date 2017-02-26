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
/* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
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
    printf("ջ��Ԫ������Ϊ: ");
    StackTraverse(s);
    Pop(&s,&e);
    printf("������ջ��Ԫ��e=%d\n",e);
    GetTop(s,&e);
    printf("ջ��Ԫ��e=%dջ�ĳ���Ϊ%d\n",e,StackLength(s));
    ClearStack(&s);
    printf("���ջ��,ջ�շ�:%d(1:��0:��)\n",StackEmpty(s));
}

