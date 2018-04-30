#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define MAXLEN 100

typedef struct {
    int elem[MAXLEN];
    int front;
    int rear;
    int length;
}queue;

void init_queue(queue *q)
{
    q->front = q->rear = q->length = 0;
}

int isempty(queue *q)
{
    if(q->front == q->rear)
        return 1;
    return 0;
}

int isfull(queue *q)
{
    if((q->rear + 1) % MAXLEN == q->front)
        return 1;
    return 0;
}

int enqueue(queue *q, int x)
{
    if(isfull(q))
    {
        printf("The queue is full!\n");
        return 0;
    }
    q->elem[q->rear] = x;
    q->rear = (q->rear + 1) % MAXLEN;
    q->length++;
    return 1;
}

int dequeue(queue *q, int &x)
{
    if(isempty(q))
    {
        printf("The queue is empty!\n");
        return 0;
    }
    x = q->elem[q->front];
    q->length--;
    q->front = (q->front + 1) % MAXLEN;
    return 1;
}

void clear_queue(queue *q)
{
    q->rear = q->front = q->length = 0;
}

int getqueue(queue *q)
{
    return q->elem[q->front];
}

void traverse_queue(queue *q)
{
	cout << "The queue is: ";
    for(int i = q->front; i < q->front + q->length; i++)
        printf("%d ", q->elem[i % MAXLEN]);
    printf("\n");
}

int main()
{
    int a;
    queue q;
    int x, e, flag = 0;
    init_queue(&q);
    while(1)
    {
        printf("1:Enter\n2:Leave\n3:Return the Length of the queue\n4:Traverse the queue\n5:Exit\nPlease choose:\n");
        scanf("%d", &a);
        switch(a)
        {
            case 1:
                printf("Please input the number you want to enter:\n");
                scanf("%d", &x);
                if(!enqueue(&q, x))
                    printf("Enter Error!\n");
                else
                    printf("The Element %d is Entered!\n", x);
                break;
            case 2:
                if(!dequeue(&q, e))
                    printf("Delete Error!\n");
                else
                    printf("The Element %d is Deleted!\n", e);
                break;
            case 3:
                printf("The Length of queue is %d!\n", q.length);
                break;
            case 4:;
                traverse_queue(&q);
                break;
            case 5:
                return 0;
            default:
                printf("Error input!\n");
        }
    }
}