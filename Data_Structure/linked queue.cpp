#include<cstdio>
#include<cstdlib>

typedef int ElemType;
typedef struct QNode
{
    ElemType data;
    struct QNode *next;
}QNode, *QueuePtr;
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

void initQueue(LinkQueue *q)
{
    q->front=q->rear=(QueuePtr)malloc(sizeof(QNode));
    if(!q->front)
        exit(0);
    q->front->next=NULL;
}

void InserQueue(LinkQueue *q,ElemType e)
{
    QueuePtr p;
    p=(QueuePtr)malloc(sizeof(QNode));
    if(p==NULL)
        exit(0);
    p->data=e;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
}

void DeleteQueue(LinkQueue *q,ElemType *e)
{
    QueuePtr p;
    if(q->front==q->rear)
        return;
    p=q->front->next;
    *e=p->data;
    q->front->next=p->next;
    if(q->rear==p)
        q->rear=q->front;
    free(p);
}

void DestroyQueue(LinkQueue *q)
{
    while(q->front)
    {
        q->rear=q->front->next;
        free(q->front);
        q->front=q->rear;
    }
}

int main()
{
    LinkQueue *q;
    initQueue(q);
    ElemType n;
    printf("Please input the numbers you want to enter(input 0 to break the loop):\n");
    while(scanf("%d", &n), n)
        InserQueue(q, n);
    printf("If you want to quit a number input a number except 0:\n");
    int e;
    while(scanf("%d", &n), n)
    {
        DeleteQueue(q, &e);
        printf("%d has been quited!\n", e);
    }
    DestroyQueue(q);
    return 0;
}
