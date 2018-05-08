#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define MaxName 100
#define QueueSize 30

typedef struct
{
    char name[MaxName];
    char sex;
}person;
typedef struct
{
    person dancer[QueueSize];
    int front;
    int rear;
    int count;
}cirqueue, *pcirqueue;

void init(pcirqueue q)
{
    q->front = q->rear = q->count = 0;
}

int queueempty(pcirqueue q)
{
    return q->count <= 0;
}

int queuefull(pcirqueue q)
{
    return q->count >= QueueSize;
}

void enqueue(pcirqueue q, person dancer)
{
    if(queuefull(q))
    {
        printf("The queue is full!\n");
        exit(0);
    }
    q->count++;
    q->dancer[q->rear] = dancer;
    q->rear = (q->rear + 1) % QueueSize;
}

person dequeue(pcirqueue q)
{
    person tmp;
    if(queueempty(q))
    {
        printf("The queue is empty!\n");
        exit(0);
    }
    tmp = q->dancer[q->front];
    q->count--;
    q->front = (q->front + 1) % QueueSize;
    return tmp;
}

void dancepartner(person *dancer, int num)
{
    person p;
    cirqueue male, female;
    init(&male);
    init(&female);
    for(int i = 0; i < num; i++)
    {
        p = dancer[i];
        if(p.sex == 'F')
            enqueue(&female, p);
        else
            enqueue(&male, p);
    }
    int len = max(male.count, female.count);
    printf("The dancing partners are:\n");
    for(int i = 0; i < len; i++)
    {
        p = dequeue(&female);
        printf("%s ", p.name);
        enqueue(&female, p);
        p = dequeue(&male);
        printf("%s\n", p.name);
        enqueue(&male, p);
    }
}

int main()
{
    int i, j;
    person dancer[QueueSize];
    printf("Please input the number of the dancers:\n");
    scanf("%d", &j);
    while(j <= 0)
    {
        printf("Input error, please input again:\n");
        scanf("%d", &j);
    }
    while(j > QueueSize)
    {
        printf("Input error, Please input less than %d, again", QueueSize);
        scanf("%d", &j);
    }
    for(i = 1; i <= j; i++)
    {
        printf("Please input the %d person\'s name:\n", i);
        scanf("%s", &dancer[i - 1].name);
        printf("Please input the %d person\'s sex(F/M):\n", i);
        scanf("%s", &dancer[i - 1].sex);
        while(dancer[i - 1].sex != 'F' && dancer[i - 1].sex != 'M')
        {
            printf("Input error, please input again:\n");
            scanf("%s", &dancer[i - 1].sex);
        }
    }
    dancepartner(dancer, j);
    return 0;
}