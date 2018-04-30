#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX 100

typedef struct
{
    int elem[MAX];
    int front, rear;
}queue;

void init(queue *q)
{
    q->front = q->rear = 0;
}

int isempty(queue *q)
{
    if(q->front == q->rear)
        return 1;
    return 0;
}

int isfull(queue *q)
{
    if((q->rear + 1) % MAX == q->front)
        return 1;
    return 0;
}

int enqueue(queue *q, int x)
{
    if(isfull(q))
    {
        printf("The queue is empty!\n");
        exit(0);
    }
    q->elem[q->rear] = x;
    q->rear = (q->rear + 1) % MAX;
    return 1;
}

int dequeue(queue *q, int &x)
{
    if(isempty(q))
    {
        printf("The queue is full!\n");
        exit(0);
    }
    x = q->elem[q->front];
    q->front = (q->front + 1) % MAX;
    return 1;
}

int main()
{
	queue point, bl;
	init(&point);
	init(&time);
	int n, sum = 0, tmp = 0, a, b;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		enqueue(&point, a);
		enqueue(&time, b);
	}
	int q, p;
    dequeue(&point, q);
	dequeue(&time, p);
	tmp += (p + q);
	for(int i = 0; i < n - 1; i++)
	{
		dequeue(&point, q);
		dequeue(&time, p);
		if(tmp > q)
		{
			sum += (tmp - q);
			tmp += p;
		}
		else
           tmp = p + q;
	}
	printf("The average of time is: %.2f\n", (float)sum / n);
	return 0;
}