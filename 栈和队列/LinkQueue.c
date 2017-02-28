#include<stdio.h>
#include<stdlib.h>
#include<io.h>


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status;

typedef int QElemType; /* QElemType���͸���ʵ������������������Ϊint */
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;
typedef struct{

    QueuePtr front,rear;
}LinkQueue;
Status visit(QElemType c)
{
    printf("%d",c);
    return OK;
}
Status InitQueue(LinkQueue *Q)
{
    Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
    if(!Q->front)
        return ERROR;
    Q->front->next=NULL;
    return OK;
}
Status DestroyQueue(LinkQueue *Q)
{
    while(Q->front)
    {
        Q->rear=Q->front->next;
        free(Q->front);
        Q->front=Q->rear;
    }
    return OK;
}
Status ClearQueue(LinkQueue *Q)
{
    QueuePtr p,q;
    Q->rear=Q->front;
    p=Q->front->next;
    Q->front->next=NULL;
    while(p)
    {
        q=p;
        p=p->next;
        free(q);
    }
    return OK;
}
Status QueueEmpty(LinkQueue Q)
{
    if(Q.front==Q.rear)
        return TRUE;
    else
        return FALSE;
}
int QueueLength(LinkQueue Q)
{
    QueuePtr p,q;
    int i=0;
    p=Q.front;
    while(Q.rear!=p)
    {
        i++;
        p=p->next;
    }
    return i;
}
Status GetHead(LinkQueue Q,QElemType *e)
{
    QueuePtr p;
    if(Q.front==Q.rear)
        return ERROR;
    p=Q.front->next;
    *e=p->data;
    return OK;
}
Status EnQueue(LinkQueue *Q,QElemType e)
{
    QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
    if(!s)
        return ERROR;
    s->data=e;
    s->next=NULL;
    Q->rear->next=s;
    Q->rear=s;
    return OK;
}
Status DeQueue(LinkQueue *Q,QElemType *e)
{
    QueuePtr p;
    if(Q->front==Q->rear)
        return ERROR;
    p=Q->front->next;
    *e=p->data;
    Q->front->next=p->next;
    if(Q->rear==p)
        Q->rear=Q->front;
    free(p);
    return OK;
}
Status QueueTraverse(LinkQueue Q)
{
    QueuePtr p;
    p=Q.front->next;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}
int main()
{
    int i;
    QElemType d;
    LinkQueue q;
    i=InitQueue(&q);
    if(i)
        printf("�ɹ��ص�����һ���ն��У�\n");
    printf("�Ƿ�ն���?%d(1����0����)",QueueEmpty(q));
    printf("���еĳ���Ϊ%d\n",QueueLength(q));
    EnQueue(&q,-5);
    EnQueue(&q,5);
    EnQueue(&q,10);
    printf("����3��Ԫ��(-5,5,10)��,���еĳ���Ϊ%d\n",QueueLength(q));
    printf("�Ƿ�ն���?%d(1:��0:��)",QueueEmpty(q));
    printf("���е�Ԫ������Ϊ: ");
    QueueTraverse(q);
    i=GetHead(q,&d);
    if(i==OK)
        printf("��ͷԪ����:%d\n",d);
    DeQueue(&q,&d);
        printf("ɾ���˶���Ԫ��%d\n",d);
    i=GetHead(q,&d);
    if(i==OK)
        printf("�µ�ͷ����Ԫ���ǣ�%d\n",d);
    ClearQueue(&q);
    printf("��ն��к�q.front=%u q.front=%u q.front->next=%u\n",q.front,q.rear,q.front->next);
    DestroyQueue(&q);
    printf("���ٶ���,q.front=%u q.rear=%u\n",q.front,q.rear);
    return 0;
}

