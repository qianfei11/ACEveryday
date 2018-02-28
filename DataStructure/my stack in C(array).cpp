#include<stdio.h>
#include<stdlib.h>

int *stack = NULL;
int top = 0;
int length = 0;
int max = 0;

void init(int n)
{
	max = n;
	stack = (int *)malloc(max * sizeof(int));
}

int full()
{
	if(top == max)
		return 1;
	return 0;
}

int empty()
{
	if(0 == top)
		return 1;
	return 0;
}

int push(int n)
{
	if(!full())
	{
		stack[top++] = n;
		length++;
	}
}

int pop()
{
	if(!empty())
	{
		printf("-->%d\n", stack[--top]);
		length--;
	}
}

void travel()
{
	for(int i = 0; i < top; i++)
		printf("%d\n", stack[i]);
	printf("\n");
}

void clear()
{
	top = length = 0;
}

int main()
{
//	init(3);
//	push(1);
//	push(2);
//	push(3);
//	push(4);
//	travel();
//	
//	pop();
//	pop();
//	travel();
//	
//	push(20);
//	push(40);
//	travel();
//	
//	clear();
//	travel();
	return 0;
}
