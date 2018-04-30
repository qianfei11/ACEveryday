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
}queue, *pqueue;

void init_queue(pqueue q)
{
    q->front = q->rear = q->length = 0;
}

int isempty(pqueue q)
{
    if(q->front == q->rear)
        return 1;
    return 0;
}

int isfull(pqueue q)
{
    if((q->rear + 1) % MAXLEN == q->front)
        return 1;
    return 0;
}

int enqueue(pqueue q, int x)
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

int dequeue(pqueue q, int &x)
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

void clear_queue(pqueue q)
{
    q->rear = q->front = q->length = 0;
}

int getqueue(pqueue q)
{
    return q->elem[q->front];
}

void traverse_queue(pqueue q)
{
	cout << "The queue is: ";
    for(int i = q->front; i < q->front + q->length; i++)
        printf("%d ", q->elem[i % MAXLEN]);
    printf("\n");
}

void YangHuiTriangle(int n)
{
	int s = 0, e = 0;
	pqueue q;
	init_queue(q);
	enqueue(q, 1);
    for(int i = 2; i <= n; i++)
    {
        enqueue(q, 1);
        for(int j = 0; j < n - i; j++)
    		printf(" ");
        for(int j = 1; j <= i - 2; j++)
        {
            dequeue(q, s);
            printf("%d ",s);
            e = getqueue(q);
            e += s;
            enqueue(q, e);
        }
        dequeue(q, s);
        printf("%d", s);
        printf("\n");
        enqueue(q, 1);
    }
}

int main()
{
    int n;
	printf("\n\n\t\tYangHui Triangle:\n\nplease input the lines you want! (0 to quit)\n");
	scanf("%d", &n);
	while(n)
	{
		if(n > 0 && n < 99)
			YangHuiTriangle(n);
		printf("\n\n\t\tYangHui Triangle:\n\nplease input the lines you want! (0 to quit)\n");
		scanf("%d", &n);
	}
	return 0;
}