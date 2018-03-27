#include<stdio.h>
#include<stdlib.h>

int length = 0;
int head = 0;
int tail = 0;
int max = 0;
int *q = NULL;

void init(int n)
{
	max = n;
	q = (int *)malloc(max * sizeof(int));
	if(q == NULL)
	{
		printf("Memory allocation failed!\n");
		exit(0);
	}
}

int full()
{
	if((tail + 1) % max == head)
		return 1;
	else
		return 0;
}

int empty()
{
	if(head == tail)
		return 1;
	else
		return 0;
}

void enter(int n)
{
	if(!full())
	{
		q[tail++] = n;
		tail %= max;
		length++;
	}
}

void quit()
{
	if(!empty())
	{
		printf("-->%d\n", q[head++]);
		length--;
		head %= max;
	}
}

void clear()
{
	head = tail = length = 0;
}

void travel()
{
	for(int i = head; i < head + length; i++)
		printf("%d\n", q[i % max]);
	printf("\n");
}

int main()
{
//	init(5);
//	
//	enter(2);
//	enter(8);
//	enter(12);
//	enter(16);
//	travel();
//	
//	quit();
//	quit();
//	enter(20);
//	travel();
//	
//	quit();
//	quit();
//	quit();
//	travel();
//	
//	enter(1);
//	enter(2);
//	enter(3);
//	enter(4);
//	travel();
//	
//	clear();
//	travel();
	return 0;
}
