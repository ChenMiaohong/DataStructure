#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;          /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;        /* ElemType���͸���ʵ������������������Ϊint */

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList;//����LinkList
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
/* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
Status ClearList(LinkList *L)
{
    LinkList p,q;
    p=(*L)->next;
    while(p)
    {
        q=p->next;  /*  pָ���һ����� */
        free(p);
        p=q;
    }
    (*L)->next=NULL; /* ͷ���ָ����Ϊ�� */
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
��������i�����ݵ��㷨˼·
1.����һ��ָ��pָ������ĵ�һ����㣬��ʼ��j��1��ʼ
2.��j<i���ͱ���������p��ָ������ƶ�������ָ����һ����㣬j�ۼ�1
3.��������ĩβpΪ�գ���˵����i������ǲ����ڣ�
4.������ҳɹ������ؽ��p������
*/
/*
��ʼ������˳�����Ա�L�Ѵ��ڣ�1<<i<<ListLength(L)
�������:��e����L�е�i������Ԫ�ص�ֵ
*/
Status GetElem(LinkList L,int i,ElemType *e)
{
    int j;
    LinkList p;
    p=L->next;//��pָ������ĵ�һ�����
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
/*�������i�����ݲ�������㷨˼·
1.����һ��ָ��Pָ������ͷ��㣬��ʼ��j��1��ʼ��
2.��j<1ʱ���ͱ���������p��ָ������ƶ�������ָ����һ����㣬j�ۼ�1��
3.��������ĩβpΪ�գ���˵����i����㲻���ڡ�
4.�����ҳɹ�����ϵͳ������һ���ս��s��
5.������Ԫ��e��ֵ��s->data
6.������Ĳ����׼���s->next=p->next,p->next=s;
7.���سɹ�
*/
/*
��ʼ������˳�����Ա�L�Ѵ��ڣ�1<<i<<ListLength(L);
�����������L�еĵ�i�����λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
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
    s->next = p->next;/*��p�ĺ�̽�㸳ֵ��S�ĺ��*/
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
/*��ʼ������˳�����Ա�L����
������������ζ�L��ÿ������Ԫ�����
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
        p->data=rand()%100+1;//�������100���ڵ�����
        p->next=(*L)->next;
        (*L)->next=p;//���뵽��ͷ
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
        r=p;//����ǰ���½�㶨��Ϊ��β�ն˽��
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
    printf("��ʼ��L��ListLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
        i=ListInsert(&L,1,j);
    printf("��L�ı�ͷ���β���1~5��:L.data=");
    ListTraverse(L);
    printf("ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);

    i=ClearList(&L);
    printf("���L��ListLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("��L�ı�β���β���1��10��L.data=");
    ListTraverse(L);

    printf("ListLength(L)=%d \n",ListLength(L));

    ListInsert(&L,1,0);
    printf("��L�ı�ͷ����0��L.data=");
    ListTraverse(L);
    printf("ListLength(L)=%d \n",ListLength(L));

    GetElem(L,5,&e);
    printf("��5��Ԫ�ص�ֵΪ��%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("��%d��Ԫ�ص�ֵΪ%d\n",k,j);
            else
                    printf("û��ֵΪ%d��Ԫ��\n",j);
    }


    k=ListLength(L); /* kΪ�� */
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* ɾ����j������ */
            if(i==ERROR)
                    printf("ɾ����%d������ʧ��\n",j);
            else
                    printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);
    }
    printf("�������L��Ԫ�أ�");
    ListTraverse(L);

    j=5;
    ListDelete(&L,j,&e); /* ɾ����5������ */
    printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);

    printf("�������L��Ԫ�أ�");
    ListTraverse(L);

    i=ClearList(&L);
    printf("\n���L��ListLength(L)=%d\n",ListLength(L));
    CreateListHead(&L,20);
    printf("���崴��L��Ԫ��(ͷ�巨)��");
    ListTraverse(L);

    i=ClearList(&L);
    printf("\nɾ��L��ListLength(L)=%d\n",ListLength(L));
    CreateListTail(&L,20);
    printf("���崴��L��Ԫ��(β�巨)��");
    ListTraverse(L);


    return 0;
}
