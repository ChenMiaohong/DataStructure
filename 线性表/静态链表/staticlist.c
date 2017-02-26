#include "string.h"
#include "ctype.h"

#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000

typedef int Status;
typedef char ElemType;
typedef struct{
    ElemType data;
    int cur;
}Component,StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space)
{
    int i;
    for(i=0;i<MAXSIZE-1;i++)
        space[i].cur=i+1;
    space[MAXSIZE-1].cur=0;
    return OK;
}
int Malloc_SLL(StaticLinkList space)
{
    int i=space[0].cur;
    if(space[0].cur)
    {
        space[0].cur=space[i].cur;
    }
    return i;
}
Status ListInsert(StaticLinkList L,int i,ElemType e)
{
    int j,k,l;
    k=MAXSIZE-1;
    if(i<1||i>ListLength(L)+1)
        return ERROR;
    j=Malloc_SLL(L);
    if(j)
    {
        L[j].data=e;
        for(l=1;l<=i-1;l++)
            k=L[k].cur;
        L[j].cur=L[k].cur;
        L[k].cur=j;
         return OK;
    }
}
Status ListDelete(StaticLinkList L,int i)
{
    int j,k,l;
    k=MAXSIZE-1;
     if(i<1||i>ListLength(L))
        return ERROR;
    for(l=0;l<i-1;i++)
        k=L[k].cur;
    j=L[k].cur;
    L[k].cur=L[j].cur;
    Free_SSL(L,j);
    return OK;

}
void Free_SSL(StaticLinkList space,int k)
{
    space[k].cur=space[0].cur;
    space[0].cur=0;
}
int ListLength(StaticLinkList L)
{
    int j=0;
    int i=L[MAXSIZE-1].cur;

    while(i)
    {
        i=L[i].cur;
        j++;
    }
    return j;
}
Status visit(ElemType c)
{
    printf("%c ",c);
    return OK;
}
Status ListTraverse(StaticLinkList L)
{
    int j=0;
    int i=L[MAXSIZE-1].cur;
    while(i)
    {
        visit(L[i].data);
        i=L[i].cur;
        j++;
    }
    return j;
    printf("\n");
    return OK;
}
int main()
{
    StaticLinkList L;
    Status i;
    i=InitList(L);
    printf("初始化L后:L.length=%d\n",ListLength(L));

    i=ListInsert(L,1,'F');
    i=ListInsert(L,1,'E');
    i=ListInsert(L,1,'D');
    i=ListInsert(L,1,'B');
    i=ListInsert(L,1,'A');

    printf("\n在L的表头依次插入FEDBA后:\nL.data=");
    ListTraverse(L);
    i=ListInsert(L,3,'C');
    printf("\n在L的B与D之间插入C后:L.data");
    ListTraverse(L);
    i=ListDelete(L,1);
    printf("\n在L的删除A后：\nL.data=");
    ListTraverse(L);
    printf("\n");
    return 0;
}
