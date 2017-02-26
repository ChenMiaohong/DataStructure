#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;          /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;        /* ElemType类型根据实际情况而定，这里假设为int */

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;//定义LinkList
void visit(ElemType c)
{
    printf("%d ",c);
}
Status InitList(LinkList *L)
{
    *L=(LinkList)malloc(sizeof(Node));
    if(!(*L))
        return ERROR;
    (*L)->next=NULL;
        return OK;
}
Status ListEmpty(LinkList L)
{
    if(L->next)
        return FALSE;
    else
        return TRUE;
}
/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(LinkList *L)
{
    LinkList p,q;
    p=(*L)->next;
    while(p)
    {
        q=p->next;  /*  p指向第一个结点 */
        free(p);
        p=q;
    }
    (*L)->next=NULL; /* 头结点指针域为空 */
    return OK;
}
int ListLength(LinkList L)
{
    int i=0;
    LinkList p=L->next;;
    while(p)
    {
        i++;
        p=p->next;
    }
    return i;
}

/*
获得链表第i个数据的算法思路
1.声明一个指针p指向链表的第一个结点，初始化j从1开始
2.当j<i，就遍历链表，让p的指针向后移动，不断指向下一个结点，j累加1
3.若到链表末尾p为空，则说明第i个结点是不存在；
4.否则查找成功，返回结点p的数据
*/
/*
初始条件：顺序线性表L已存在，1<<i<<ListLength(L)
操作结果:用e返回L中第i个数据元素的值
*/
Status GetElem(LinkList L,int i,ElemType *e)
{
    int j;
    LinkList p;
    p=L->next;//让p指向链表的第一个结点
    j=1;
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)
        return ERROR;
    *e=p->data;
    return OK;
}
Status LocateElem(LinkList L,ElemType e)
{
    LinkList p;
    ElemType v;
    int i=0;
    p=L->next;
    while(p)
    {
        i++;
        if(p->data==e)
            return i;
        p=p->next;
    }
    return 0;
}
/*单链表第i个数据插入结点的算法思路
1.声明一个指针P指向链表头结点，初始化j从1开始；
2.当j<1时，就遍历链表，让p的指针向后移动，不断指向下一个结点，j累加1；
3.若到链表末尾p为空，则说明第i个结点不存在。
4.若查找成功，在系统中生成一个空结点s；
5.将数据元素e赋值给s->data
6.单链表的插入标准语句s->next=p->next,p->next=s;
7.返回成功
*/
/*
初始条件：顺序线性表L已存在，1<<i<<ListLength(L);
操作结果：在L中的第i个结点位置之前插入新的数据元素e，L的长度加1
*/
Status ListInsert(LinkList *L,int i,ElemType e)
{
    int j;
    LinkList p,s;
    p=*L;
    j=1;
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)
        return ERROR;
    s=(LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;/*将p的后继结点赋值给S的后继*/
    p->next=s;
    return  OK;
}
Status ListDelete(LinkList *L,int i,ElemType *e)
{
    int j;
    LinkList p,q;
    p=*L;
    while(p->next&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!(p->next)||j>i)
        return ERROR;
    q=p->next;
    p->next=q->next;
    *e = q->data;
    free(q);
    return OK;
}
/*初始条件：顺序线性表L存在
操作结果：依次对L的每个数据元素输出
*/
Status ListTraverse(LinkList L)
{
    LinkList p=L->next;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}
void CreateListHead(LinkList *L,int n)
{
    LinkList p;
    int i;
    srand(time(0));
    *L=(LinkList)malloc(sizeof(Node));
    (*L)->next=NULL;
    for(i=0;i<n;i++)
    {
        p=(LinkList)malloc(sizeof(Node));
        p->data=rand()%100+1;//随机生成100以内的数字
        p->next=(*L)->next;
        (*L)->next=p;//插入到表头
    }
}
void CreateListTail(LinkList *L,int n)
{
    LinkList r,p;int i;
    r=*L;
    srand(time(0));
    for(i=0;i<n;i++)
    {
        p=(LinkList)malloc(sizeof(Node));
        p->data=rand()%100+1;
        r->next=p;
        r=p;//将当前的新结点定义为表尾终端结点
    }
    r->next=NULL;
}
void clearList(LinkList *L)
{
    LinkList p,q;
    p=(*L)->next;
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;
    return OK;
}
void main()
{
    LinkList L;
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("初始化L后：ListLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
        i=ListInsert(&L,1,j);
    printf("在L的表头依次插入1~5后:L.data=");
    ListTraverse(L);
    printf("ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i=ClearList(&L);
    printf("清空L后：ListLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L);

    printf("ListLength(L)=%d \n",ListLength(L));

    ListInsert(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    ListTraverse(L);
    printf("ListLength(L)=%d \n",ListLength(L));

    GetElem(L,5,&e);
    printf("第5个元素的值为：%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("第%d个元素的值为%d\n",k,j);
            else
                    printf("没有值为%d的元素\n",j);
    }


    k=ListLength(L); /* k为表长 */
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* 删除第j个数据 */
            if(i==ERROR)
                    printf("删除第%d个数据失败\n",j);
            else
                    printf("删除第%d个的元素值为：%d\n",j,e);
    }
    printf("依次输出L的元素：");
    ListTraverse(L);

    j=5;
    ListDelete(&L,j,&e); /* 删除第5个数据 */
    printf("删除第%d个的元素值为：%d\n",j,e);

    printf("依次输出L的元素：");
    ListTraverse(L);

    i=ClearList(&L);
    printf("\n清空L后：ListLength(L)=%d\n",ListLength(L));
    CreateListHead(&L,20);
    printf("整体创建L的元素(头插法)：");
    ListTraverse(L);

    i=ClearList(&L);
    printf("\n删除L后：ListLength(L)=%d\n",ListLength(L));
    CreateListTail(&L,20);
    printf("整体创建L的元素(尾插法)：");
    ListTraverse(L);


    return 0;
}
